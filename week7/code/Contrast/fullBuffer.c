#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

char buf[] = {"write to stdout\n"};

int main(){
pid_t id;

if(write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)

perror("can't write");
//全缓冲方式：
printf("printf  ");
//子进程使用父进程缓冲区,全缓冲方式下不刷新缓冲区.
id = fork();

if(id < 0)

perror("fork error");

 

exit(0);

}
