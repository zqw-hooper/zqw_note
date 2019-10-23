# Linux 开机自启动相关

## 自启动服务配置

- 自启动文件路径：/lib/systemd/system/csvw-setup.service
- 添加可执行脚本路径：/home/master/test_ws/scripts/setup.sh
- systemctl enable csvw-setup.service 使能服务
- systemctl daemon-reload 可以重新加载 systemd 程序的配置文件，重新生成依赖树。

## systemctl enable 和 disable

- systemctl enable csvw-setup.service 使能指令所谓 enable 就是在/lib/systemd/system/multi-user.target.wants 下面创建一个链接文件，这是由 csvw-setup.service 文件中的配置信息决定的

## systemctl list-uints

- 能够列出当前已经启动的 uint,如果添加 -all 选项会同时列出没有启动的 unit。

* systemct list-unit-files：根据 /lib/systemd/system/ 目录内的文件列出所有的 unit，可查看安装的 unit 和使能状态。

## systemctl

- systemctl --failed 可查看是否有 unit 加载失败
- 相关的目录和文件
  在不同的发行版中与 systemd 相关的文件路径可能会不太一样，强调一下，这里使用 ubuntu 16.04 。
  /lib/systemd/system/ 大多数 unit 的配置文件都放在这个目录下。
  /run/systemd/system/ 系统运行过程中产生的脚本，比如用户相关的脚本和会话相关的脚本。
  /etc/systemd/system/ 这个目录中主要的文件都是指向 /lib/systemd/system/ 目录中的链接文件。
  > 在我们自己创建 unit 配置文件时，既可以把配置文件放在 /lib/systemd/system/ 目录下，也可以放在 /etc/systemd/system/ 目录下。
  > /etc/default/ 这个目录中放置很多服务默认的配置文件。
  > /var/lib/ 一些会产生数据的服务都会将他的数据写入到 /var/lib/ 目录中，比如 docker 相关的数据文件就放在这个目录下。
  > /run/ 这个目录放置了好多服务运行时的临时数据，比如 lock file 以及 PID file 等等。
