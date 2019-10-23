#include<stdlib.h>
#define m 70
//定义了一个指针a，a可以指向任意类型的值，但它指向的值必须是常量
int compar(const void *a,const void *b){
      int *aa=(int *)a,*bb=(int *)b;//变量a的存储地址
      if(*aa>*bb)return 1;
      if(*aa==*bb)return 0;
      if(*aa<*bb)return -1;
}
main(){
       int base[m],n;
       int i;
       printf("input n(n<50)\n");
       scanf("%d\n",&n);
       qsort(base,n,sizeof(int),compar);
        for(int i=0;i<n;i++){
           printf("%d\n",base[i]);
        }
}

