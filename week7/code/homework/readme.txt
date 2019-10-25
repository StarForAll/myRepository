本部分是作业相关,书写的是创建/写/读/查看文件权限/修改文件权限...
其中包括使用系统I/O(open,write,read),使用标准库IO函数(fopen,fread,fwrite..).
菜单功能:
********************************
0. 退出
1. 创建新文件
2. 写文件
3. 读文件
4. 修改文件权限
5. 查看当前文件的权限修改文件权限
********************************

在功能文件中完成对单独功能模块的编写.

其中的standardIO目录的功能模块是使用标准IO库函数编写.
sysIO目录的功能模块是使用系统IO函数编写的.

生成动态库/静态库以及相关的可执行文件：
ar crs -o libstatic.a IOFunction1.o //生成静态块文件
gcc test.c -o statictest -L. -lstatic -I./

gcc -fpic -shared -o libIOFunction1.so IOFunction1.c      //生成动态库文件
gcc -o dytest test.c ./libIOFunction1.so -I./
