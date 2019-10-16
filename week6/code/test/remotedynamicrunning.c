#include<stdlib.h>
#include<dlfcn.h>
#include"dylib.h"
#include<stdio.h>
int main(){
     void*hd;
     void (*f1)(),(*f4)(),(*f5)();
     int (*f2)(),(*f3)();
     char *error;
     hd=dlopen("../dynamiclib/libdynamiclib.so",RTLD_LAZY);//在使用的时候才会解析对应的符号.
     if(!hd){
        fprintf(stderr,"%s\n",dlerror());
	exit(1);
     }
     f1 = dlsym(hd,"initialArray");
     if((error=dlerror())!=NULL){
        fprintf(stderr,"%s\n",dlerror());
        exit(1);
     }
     f4 = dlsym(hd,"getRandomArray");
     if((error=dlerror())!=NULL){
        fprintf(stderr,"%s\n",dlerror());
        exit(1);
     }
     f5 = dlsym(hd,"showArray");
     if((error=dlerror())!=NULL){
        fprintf(stderr,"%s\n",dlerror());
        exit(1);
     }
     f2 = dlsym(hd,"max");
     if((error=dlerror())!=NULL){
        fprintf(stderr,"%s\n",dlerror());
        exit(1);
     }
     f3 = dlsym(hd,"sum");
     if((error=dlerror())!=NULL){
        fprintf(stderr,"%s\n",dlerror());
        exit(1);
     }
     int a[5];
     f1(a,5);
     f4(a,5);
     printf("获得数组中最大值:%d.\n",f2(a,5));
     printf("获得数组之和:%d.\n",f3(a,5));
     f5(a,5);
     if(dlclose(hd)<0){
        fprintf(stderr,"%s\n",dlerror());
        exit(1);
     }
     return 0;
}
