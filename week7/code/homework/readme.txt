本部分是作业相关,书写的是创建/写/读/查看文件权限/修改文件权限...
其中包括使用系统I/O(open,write,read),使用标准库IO函数(fopen,fread,fwrite..).

生成动态库/静态库以及相关的可执行文件：
ar crs -o libstatic.a IOFunction1.o //生成静态块文件
gcc test.c -o statictest -L. -lstatic -I./

gcc -fpic -shared -o libIOFunction1.so IOFunction1.c      //生成动态库文件
gcc -o dytest test.c ./libIOFunction1.so -I./
