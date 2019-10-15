#include"ourhdr.h"
//一个文件描述符打开一个或者多个文件状态标志
void set_f1(int fd,int flags){
        int val;
        if((var=fcntl(fd,F_GETFL,0))<0){
          perror("fcntl F_GETFL error!\n");
        }
        val |=flags;
        if(fcntl(fd,F_SETFL,val)<0){
          perror("fcntl F_SETFL error!\n");
        }
}
