#include<stdio.h>
#include<stdlib.h>
void prin(int n){
     printf("this is a int , = %d.",n);
}
void prin(double n){
     printf("this is a folat , = %f.",n);
}
int main(){
    prin(1);
    prin(1.1);
    return 0;
}
