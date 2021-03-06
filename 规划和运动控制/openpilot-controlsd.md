# controlsd ?
## 知识点：
### python-gc
- **介绍**：gc (garbage collection):python垃圾回收机制通过回收和释放未使用的数据来回收内存。
- **背景**：因为python不会对已经销毁的对象所占据的内存做自动的释放内存空间的工作。
- **原理**：为每一个内存对象进行引用计数，通过引用计数来跟踪和回收内存空间。
>**优点**：释放销毁的内存空间，避免程序可能出现大量的内存占用和内存不足现象
>**缺点**：当有大量的对象新建或删除时，必须要进行大量修改引用计数的操作，影响了程序的性能。

- **解决方法**：为避免这种情况的发生，可以在大量的对象新建或删除之前，把gc禁用`gc.disable()`

### linux-chrt
- **介绍**：chrt可以更改进程的调度策略和优先级。
- **分类**：进程主要分为实时进程和非实时进程两种。因此chrt的调度策略也是针对这两种进程的，对于实时进程使用的调度策略：SCHED_FIFO、SCHED_RR，对于非实时进程的调度策略：SCHED_OTHER、SCHED_BATCH、SCHED_IDLE。优先级范围：0-99
> SCHED_FIFO:以先进先出的队列方式进行调度，在优先级一样的情况下，谁先执行的就先调度谁，除非它退出或者主动释放CPU。
> SCHED_RR:以时间片轮转的方式对相同优先级的多个进程进行处理。时间片长度为100ms。

### python-zmq
- **简介**：zeromq(zmq)zero代表零拷贝,提供了三个基本的通信模型，包括pub-sub、client-server、push-pull。通过socket实现不同节点间的通讯，还可以实现进程间的通讯。
- >补充：localhost = 127.0.0.1被称为本地回环地址，区别：localhost是域名，127.0.0.1是IP地址。主要作用有两个：一是测试本机的网络配置，能PING通127.0.0.1说明本机的网卡和IP协议安装都没有问题；另一个作用是某些SERVER/CLIENT的应用程序在运行时需调用服务器上的资源，一般要指定SERVER的IP地址，但当该程序要在同一台机器上运行而没有别的SERVER时就可以把SERVER的资源装在本机，SERVER的IP地址设为127.0.0.1也同样可以运行。

### capnp
**一种高性能的编码方案，性能见下图，几乎秒杀google protobuf**  （[capnp介绍](https://www.jianshu.com/p/f1110b22cb5c)）
![capnp对比protobuff对比](../zqw_note/image/capnp.png)