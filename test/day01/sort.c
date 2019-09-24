#include<stdio.h>
void sort(int *a,int num){
     for(int i=0;i<num;i++){
          int t = 0;
          for(int j=i+1;j<num;j++){
               if(a[i]>a[j]){
                t=a[j];
                a[j]=a[i];
                a[i]=t;
               }
               
          }
     }
}
