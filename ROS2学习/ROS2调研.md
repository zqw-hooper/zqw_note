

# ROS1与ROS2:
## ROS1与ROS2简单对比:
| ROS2发行版本 | 发布时间 | 停止支持时间 | 支持Linux版本 | Ubuntu停止支持时间 | 
| :-: | :-: | :-: | :-: | :-: |
| ardent | 2017-12 | 2018-12 | xenial(16.04) / bionic(18.04) | 2021-4 / 2028-11|
| bouncy | 2018-7 | 2019-7 | xenial(16.04) / bionic(18.04) | 2021-4 / 2028-11 |
| crystal | 2018-12 | 2019-12 | xenial(16.04) / bionic(18.04) | 2021-4 / 2028-11 |
| **dashing** | **2019-5** | **2021-5** | **bionic(18.04)** | **2028-11** |
> ROS-kinetic主要针对Ubuntu 16.04，而在ROS-melodic主要针对Ubuntu 18.04
---
| **对比项** | **ROS1** | **ROS2** | **说明** |
| :-: | :-: | :-: | :-: |
| **通讯机理** | TCP/UDP | DDS | 
| **master** | 强依赖 | 不依赖 | 
| **python版本** | 2 | 3.5 | 
| **C++** | 04  11 | 11  14  17 |
| **操作系统** | Linux | Linux Mac Win |
| **单进程运行多节点** | 不支持 | 支持 | 
| **编译系统** | cmake | ament/colcon | 
| **QoS** | 无 | 有 |

## ROS2优势：
1. 支持多机器人系统：ROS2增加了对多机器人系统的支持，提高了多机器人之间通信的网络性能。
2. 铲除原型和产品之间的鸿沟：ROS2不仅针对科研领域，还关注机器人从研究到应用之间的过渡，可以让更多机器人直接搭载ROS2系统走向市场。
3. 支持微控制器：ROS2不仅可以运行在现有的X86和ARM系统上，还将支持MCU等嵌入式微控制器。
4. 支持实时控制：ROS2还加入了实时控制的支持，可以提高控制的时效性和整体机器人的性能。
5. 跨系统平台支持：ROS2不止能运行在Linux系统之上，还增加了对Windows、MacOS、RTOS等系统的支持，让开发者的选择更加自由。

## ROS2性能提升:
> - 持续性增强：ROS1尽管存在数据队列的概念，但是还有很大的局限，订阅者无法接收到加入网络之前的数据；DDS可以为ROS提供数据历史的服务，就算新加入的节点，也可以获取发布的所有历史数据;
> - 可靠性增强：通过DDS配置可靠性原则，用户可以根据需求选择性能模式（BEST_EFFORT）或者稳定模式（RELIABLE);
> - 实时性增强：数据必须在deadline之前完成更新.
  
## DDS介绍:
**简介**:
> Data Distribution Service(数据分发服务)，是一个专门为分布式实时系统中数据发布/订阅的标准解决方案。

**原理**:
> - DDS 的技术核心是以数据为核心的发布订阅模型（Data-Centric Publish-Subscribe ，DCPS），这种DCPS模型创建了一个“全局数据空间”（global data space）的概念，所有独立的应用都可以去访问。
> - DDS 不仅有发布者、订阅者和话题，还有参与者、datawriter和datareader，并且均拥有各自的QoS属性，并影响着数据传输和数据生命周期。

**QoS(Quality of Service)**:创建发布，订阅, 服务等任务时，可以通过QoS配置结构指定历史记录，深度，可靠性和持久性, 也可以通过默认配置委托DDS配置QoS.

**为什么使用ROS2而不是DDS？**
> - DDS应用领域非常广泛，军工、航天、汽车、医疗等等，ROS2更专注于机器人应用。
> - DDS基本掌握在少数的几家公司并且没有开源版本。
> - DDS的配置和使用较为复杂。而ROS2提供了高抽象的DDS版本，应用更方便使用DDS，但是却不包含所有的DDS功能。
> - ROS提供了更多的工具包，减少大量的基础工作。
> - catkin/ament/colcon编译系统可以方便轻松的构建功能包和依赖关系。
> - launch启动系统可以轻松运行多个程序以及实现参数修改等功能。
> - ROS2提供仿真模型和实时监测工具。

## ament/colcon与catkin编译系统：
**ament是一种元编译系统,是catkin编译系统进一步演化的版本.**
- catkin系统以CMake为中心，所以只包含python代码的功能包也需要由CMake进行处理，但是CMake并不支持Python setuptools中的所有功能.
- 在catkin系统构QoS(Quality of Service)：建完成后，会在工作目录下生成一个devel文件夹，里边是编译好的功能包，以及环境变量的设置等等，基本上等同于ROS安装完成后的目录结构和作用;**ament系统则取消devel目录,由install代替.**
- catkin会将编译多个工作区的前缀存储到环境变量CMAKE_PREFIX_PATH 中，但是这种方法会干扰变量中的其他值，在ament中，不同工作区的前缀会放到不同的环境变量中。
- catkin_simple是一个用于改善用户catkin体验的工具包，可以减少复杂的CMake代码，但是会存在不稳定的情况。ament也是实现了类似的功能，但是可靠性更强。


## 不同版本ROS2比较:
**ROS工具及功能包**:
> **ROS2-ardent < ROS2-dashing < ROS1-kinetic**
> 因为低版本的ROS2维护时间即将到期或已经到期，缺少很多功能包，类似rclcpp和rclpy就缺少一些类或者函数(declare_parameter/ParameterValue/SensorDataQoS/SystemDefaultsQoS...)，推荐使用最新版本的ROS2(目前最新版本为ROS2-dashing, 维护时间到2021年).

**ROS2-dashing中部分功能或节点无法直接在ROS2-ardent中直接运行**.

## ROS1与ROS2之间的通讯：
通过ros-bridge实现两者的通讯(ros2 run ros1_bridge dynamic_bridge)




## ROS2 
RCLCPP_INFO
RCLCPP_WARN
RCLCPP_DEBUG
RCLCPP_ERROR
RCLCPP_FATAL

