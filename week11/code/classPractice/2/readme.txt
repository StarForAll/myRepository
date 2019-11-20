这是第11周(2)linux上课学习时的代码.
fork()产生多个子进程并进行写文件,父进程读该文件(注意父进程读取信息时要将文件描述符放到开头).
fork()产生一个子进程,该子进程是从这个fork()处进行程序继续执行,如果后面还有fork(),子进程也会创建其子进程
fread(void  *buffer,size_t size,size_t count,FILE *stream):
       buffer是读取出来的数据存放的数组/空间
       size是一次要读取的长度
       count是需要读取的次数
gcc -fpic -shared -o function.so function.c
gcc -o 1 1.c ./function.so -I./
守护进程:
修改/etc/rc.d:系统开启时启动这个守护进程.
