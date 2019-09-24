#include "1.h"
struct arg getResult(int *,int);
struct arg getResult(int *a,int num){
    struct arg getShow;
    int sum = 0;
    float average = 0;
    for(int i = 0;i<num;i++){
       sum += a[i];
    }
    average = sum/num;
    getShow.sum = sum;
    getShow.average =average;
    return getShow;
}

