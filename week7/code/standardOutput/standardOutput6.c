#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
 
int main(void)
{
    int fd = open("temp.txt",O_RDWR|O_CREAT|O_TRUNC,0664);
    char temp[1024]={0};
    dup2(fd,STDOUT_FILENO);
    //文件重定向后，往终端输出的数据，会写入的文件中
    //先写4096B试试，看看能写入磁盘不
    int i=0;
    while(1)
    {
        printf("%d",i);
	i++;
    }
    close(fd);
    return 0;
}

