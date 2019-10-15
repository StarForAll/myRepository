#include "viruses.h"
char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";
int main(){
    int i;
    printf("------call.c-------\n");
    int fd;
     if((fd = creat("file.hole",644))<0){
         perror("creat error!\n");//perror
     }
     if(write(fd,buf1,10)!=10){
        perror("buf1 write error!");
     }
    
    i=system("./viruses");//正常结束的进程value值是0
    
    if(lseek(fd,40,SEEK_SET) == -1){
        perror("lseek error!");
     }
     if(write(fd,buf2,10)!=10){
        perror("buf2 write error!");
      }
    printf("-----end call.c ----\n");
    printf("value is %d\n",i);
    return 0;
}
