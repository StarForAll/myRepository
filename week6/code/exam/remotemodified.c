#include"/home/week6/code/staticlib/staticlib.h"
#include<stdio.h>
int main(){
     int a[5];
     initialArray(a,5);
     getRandomArray(a,5);
     printf("获得数组中最大值:%d.\n",max(a,5));
     printf("获得数组之和:%d.\n",sum(a,5));
     showArray(a,5);
     return 0;
}
