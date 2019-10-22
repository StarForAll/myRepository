#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

char buf[] = {"write to stdout\n"};

int main(){
pid_t id;

if(write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)

perror("can't write");
//行缓冲方式：
printf("printf\n");
//子进程使用父进程缓冲区,行缓冲方式下已经将缓冲区刷新.
id = fork();

if(id < 0)

perror("fork error");

 

exit(0);

}
