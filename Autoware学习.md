# Autoware 学习

## Autoware->ros->src->actuation:

> ### vehicles->packages->ymc:

> > **从 can 总线上获取车速信息，并且向 can 总线发送档位、模式、目标车速、目标转角、制动信号和心跳信息，核心函数封装成。**

> ### vehicles->packages->as:

> > **message_filters::Synchronizer 同步订阅曲率、节气门开度、制动反馈、档位反馈、车速加速度反馈等信息；订阅车辆控制指令信息并进行一些处理发布出去给 SSC 模块，没有找到接受节点，初步认定 SSC 是等同于 Autoware 的另一个平台或系统。**

## Autoware->ros->src->vehicle:

> ### vehicle_description:

> > **通过 ROS 的 URDF(Unified Robot Description Format，统一机器人描述格式)，URDF 文件使用 XML 格式描述机器人模型。在 Autoware 中则是通过 urdf 文件调用 mesh 中的相应数据文件来进行车辆模型（车辆的三维立体图）的加载，包括 lexus、vehicle_model 等多种不同车的三维立体图。首先运行相应的.launch 文件，然后在 rviz 中添加 add->RobotModel 既可以看到相应的车辆模型。**

## Autoware->ros->src->util:

> ### packages->runtime_manager:

> > **gui 显示界面，显示 Autoware 系统的状态、文件选择选项、车辆控制指令下发、IPC 负载率内存、rostopic echo / list 等界面显示功能。**

> ### packages->sound_player:

> > **从运动规划模块订阅信息进行语音提示的控制，包括红绿灯、行人、减速、启动和停止等提示信息，通过 yaml 文件实现。**

> ### packages->data_preprocessor:

> > **以 topic 形式存储数据到相应目录，对 image、depth 和 pcd 数据进行存储。**
