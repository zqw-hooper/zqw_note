# NTP

## 1.Linux时间
* 软件时间：linux系统时间，1970-01-01开始记录.
    > 查询指令：`data MMDDhhmmYYYY`
* 硬件时间：计算机系统在BIOS中记录的时间.
    > 查询指令：`hwclock -r(读取BIOS内的时间参数)/-w(将系统时间写入BIOS中)`

## 2.NTP
### 2.1NTP服务器阶层
* NTP时间服务采用阶层(stratum)架构来处理时间的同步化，因此使用的是server/client的主从架构.(层数最多可达15层)
* 在设定NTP服务器时选择多部时间服务器，原因是可以避免某时间服务器突然挂点时，其他服务器任然可以提供NTP时间同步.

### 2.2NTP设置
#### 2.2.1配置文件`/etc/ntp.conf`
* `restrict`管理权限控制: `restrict [IP] mast [netmask_IP] [parameter]`
> 其中parameter参数:
> `ignore`:拒绝所有类型的NTP联机
> `nomodify`:客户端不能修改服务器时间，但是客户端仍可以透过主机进行网络校时.
> `noquery`:客户端不能查询服务器时间，等于不提供NTP网络校时.
> `notrust`:拒绝没有认证的客户端.
> `notrap`:不提供trap这个远程时间登录的功能.

* 利用`server`设定上层NTP服务器:`server [IP or hostname] [prefer]`
> 选择接入的服务器`IP`或域名，`prefer`表示优先使用的服务器.

* `driftfile`记录时间差异:`driftfile [可以被ntpd写入的目录或档案]`
> 记录自己主机和上层服务器频率误差.