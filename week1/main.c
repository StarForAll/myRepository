#include "1.h"

int main(){
    struct arg getShow;
    int a[length];
    urand(a,length);
    printf("显示产生的数组:\n");
    show(a,length);
    printf("显示产生的数组:\n");
    //getResult(a,length);
    getShow = getResult(a,length);
    printf("获得数组元素之和%d,平均数%f.\n",getShow.sum,getShow.average);
    printf("进行系统sort功能使用:\n");
    sysSort(a,length);
    show(a,length);
    printf("系统sort功能使用完毕!\n");
    printf("进行冒泡sort功能使用:\n");
    sort(a,length);
    show(a,length);
    printf("冒泡sort功能使用完毕!\n");
    printf("将数组元素写入文本:\n");
    writeData(a,length,randData);
    printf("读出文本数据:\n");
    readData(a,length,randData);
    printf("操作结束!\n");
    //return 0;
}
