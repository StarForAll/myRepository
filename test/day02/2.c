#include "2.h"
int main(){
    int i;
    printf("----- 2.c  ----\n");
    printf("parent pid=%d\n",getppid());
    sleep(2);
    for(int i = 0;i<10;i++){
        printf("%d is running%d\n",getpid(),i);
    }
    printf("-----end 2.c ----\n");
    return 0;
}
