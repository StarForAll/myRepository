#include"memoryAllocation.h"
int main(){
   struct co *p;
   char ch;
   printf("是否需要增加手机通讯录用户?(Y/N)\n");
   ch=getchar();
   if(ch=='Y'||ch=='y'){
      p=(struct co *)malloc(sizeof(struct co));
      p->index=++x;
      printf("用户名:");
      scanf("%s\n",p->name);
      printf("移动电话号码:");
      scanf("%s\n",p->MTel);
      printf("固定电话号码:");
      scanf("%s\n",p->Tel);
      printf("序号:%d\n姓名:%d\n移动电话号码:%d\n固定电话号码:%d\n",p->index,p->name,p->MTel,p->Tel);
   }
      printf("页面大小%d\n",getpagesize());
    return 0;
}
