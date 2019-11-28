#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
int pipefds[2];
pipe(pipefds);

char buf[4096];
 for (int i = 0; i < sizeof(buf); ++i)
 {
 buf[i] = 0x7f;
}

ssize_t ret = -1;

int loop = 100;
 if (argc > 1){
loop = atoi(argv[1]);
}

 for (int i = 0; i < loop; ++i){
 printf("loop: %d\n", i);
 ret = write(pipefds[1], buf, sizeof(buf));
 if (ret < 0){
 perror(NULL);
 }else{
 printf("%ld\n", ret);
 }
 }// 当i=16的时候会阻塞，可知管道大小为64k
 close(pipefds[0]);
 close(pipefds[1]);
return 0;
}

