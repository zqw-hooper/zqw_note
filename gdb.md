# gdb
**gdb是linux下非常好用的一个调试工具，虽然它是命令行模式的调试工具，但是它的功能非常强大.**

**gdb使用步骤:**
1. g++/gcc -g test.c -o test（-g选项告诉gcc在编译程序时加入调试信息)
2. gdb (进入gdb调试环境)
3. file xxx.o  (加载相应可执行文件)
4. run  (代码执行)

**gdb快捷指令:**
1. shell clear  (清屏)
2. break n  (设置断点, n为程序运行停止行, 本质是暂停程序)
3. info breakpoints  (查看设置的断点信息)
4. next (继续执行下一行程序,但不进入函数内部)
5. next n (继续执行下n行程序)
6. step (继续执行下一行程序,且进入函数内部)
7. continue (继续执行暂停的程序直到下一个暂停或程序结束)
8. delete (删除所有断点)
9. delete n (删除编号为n的断点)
10. quit (退出gdb调试)