#include "2.h"
int main(){
    int i;
    printf("------call.c-------\n");
    sleep(3);
    printf("------%d is running--\n",getpid());
    sleep(3);
    i=system("./2");//正常结束的进程value值是0
    printf("-----end call.c ----\n");
    printf("value is %d\n",i);
    return 0;
}
