#include<stdlib.h>
int main(){
     char *p;
     //getenv("USER"):对应内容中的指针
     if((p=getenv("USER")))
       printf("USER=%s\n",p);
     return 0;
}
