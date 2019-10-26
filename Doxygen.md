# Doxygen

## Doxygen 介绍

Doxygen 是一个程序的文档产生工具，可以将程序中的注释转换成说明文档或者说是 API 参考手册，从而减少程序员整理文档的时间。

## Doxygen 使用范围

目前 Doxygen 可处理的程序语言包含 C/C++、Java、Objective-C、IDL 等，可产生出来的文档格式有 HTML、XML、LaTeX、RTF 等。

## Doxygen 安装

sudo apt-get install doxygen
sudo apt-get install graphviz

## Doxygen 使用

doxygen -g // 在当前目录下生成名为 Doxygen 的配置文件模板，默认生成的配置文件名为 Doxyfile

在配置文件中修改如下几项：

> - DOXYFILE_ENCODING = UTF-8
> - PROJECT_NAME = "项目名称"
> - PROJECT_NUMBER = "项目版本号"
> - OUTPUT_DIRECTORY = "输出文档的目录"，最好写上本工程的目录名称
> - OUTPUT_LANGUAGE = English，文档语言，可以指定为 Chinese
> - OPTIMIZE_OUTPUT_FOR_C 针对 C 的信息输出优化
> - FILE_PATTERNS 选入 Doxygen 的范围，不选就是默认的 C 和 C++的文件类型
> - RECURSIVE 递归遍历当前目录的子目录，寻找被文档化的程序源文件
> - GENERATE_HTML 和 GENERATE_LATEX
> - IMAGE_PATH = image_dir，指定图片存放的目录，将图片放到当前目录下的 image_dir 目录中，因为文档可能会出现测试图片示例
> - HTML_OUTPUT= . ，html 输出目录名称，默认为 html 目录，如果为“.”则表明为上述 OUTPUT_DIRECTORY 目录
> - INPUT = xxx，代码文件或目录，多个文件(目录)需要以空格隔开，如果不指定，表示当前目录，但是，如果指定目录且当前目录有代码文件的话，需要使用点号(“.”)表示当前目录
