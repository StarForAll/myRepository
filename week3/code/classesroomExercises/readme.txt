使用系统库中的函数:
creat(创建文件,现在不使用,使用open函数替代);
write(将字符数组写入文件);
lseek(定位文件对应的文件位置):
   lseek(fd,40,SEEK_SET):将对于的文件指针放于距离开头40个字节出的地方开始输入write/fwrite写入的内容.
perror(将产生的错误信息传递到其中)
