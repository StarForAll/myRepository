#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void initialArray(int*m,int length){
      for(int i=0;i<length;i++){
          m[i]=0;
      }
}
void getRandomArray(int*m,int length){
      printf("开始产生随机数!\n");
    srand((unsigned int)time(NULL));//随机数rand
    for(int i=0;i<length;i++){
        int n = rand()%999+1; //产生1~1000的随机数
        m[i] = n;
    }
    printf("已获得随机元素数组.\n");
}
void showArray(int*m,int length){
     for(int i=0;i<length;i++){
        printf("第%d个元素 :%d\n",i,m[i]);
     }
}
