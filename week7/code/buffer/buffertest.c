#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
char buf[] = {"1234 stdout\n"};

int main(){
pid_t id;
//使用write函数将字符串输出到终端中,是无缓冲方式.
if(write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1){
perror("can't write");
}
//行缓冲方式.
printf("ABCDEF\n");
id = fork();
if(id < 0){
perror("fork error");
}
return 0;
}
