#include "1.h"
void show(int *,int);
void urand(int *,int);

void urand(int * a,int num){
    struct timeval tv1,tv2;
    struct timezone tz;
    gettimeofday(&tv1,&tz);
    printf("开始产生随机数!\n");
    srand((unsigned int)time(NULL));//随机数rand
    for(int i=0;i<num;i++){
        int n = rand()%999+1; //产生1~1000的随机数
        a[i] = n;
    }
    gettimeofday(&tv2,&tz);
    printf("产生随机数的时间(微秒):%d\n",tv2.tv_usec-tv1.tv_usec);
} 
void show(int *a,int num){
     for(int i=0;i<num;i++){
        printf("a[%d]=%d\n",i,a[i]);
     }
}

