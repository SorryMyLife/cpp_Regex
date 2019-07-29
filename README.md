这是基于c++编写的一个Linux正则工具

程序实现比较简单，只提供三个参数

-f file Patter removeString //这里是需要你指定一个文件，然后自己输入正则匹配数据，removeString则是需要移除的字符串，也可以为空

-f file --printHTML //这里需要指定一个文件，然后直接输出所有HTML结尾的文件链接

-f file --printIMG //这里需要指定一个文件，然后直接输出所有图片文件链接

调试环境：
-

centos7(x86_64)

kali(armhf)

Android7.1.2(armv8l)


已知问题：
-
1、必须要用支持c++11特性的编译器进行编译

2、gcc4.x及以下版本编译会出现问题

3、termux的clang8.0.0-3编译任何c/c++程序都会出现段错误(time：2019年7月27-29日)


发布时间：2019年7月29日
-
