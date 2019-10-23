#include<stdio.h>
//#include<unistd.h>
#include"IOlib.h"
int main(){
	int choice=-1;
do{
     printf("********************************\n");
     printf(" 0. 退出\n 1. 创建新文件\n 2. 写文件\n 3. 读文件\n 4. 修改文件权限\n 5. 查看当前文件的权限修改文件权限\n");
     printf("********************************\n");
     printf("Please input your choice(0-5):\n");
     char *str1;
     scanf("%d",&choice);
     /*choice=getchar();
     if(choice<'0' || choice>'9' ){
           printf("input chioce is NULL!\n");
           return -1;
        }
     choice=choice-48;*/
     //printf("choice :%d\n",choice);
     switch(choice){
               case 0:
               printf("已退出本程序.\n");
               break;
               case 1:
	       createNewFile();
               break;
               case 2:
	       writeFile();
               break;
               case 3:
	       readFile();
               break;
               case 4:
	       str1=updateFilePower();
               break;
               case 5:
               //printf("str1:%s\n",str1);
	       seekFilePower(str1);
               break;
               default:
               printf("输入选项不正确,请重新输入!\n");
            }
       //sleep(3);
      }while(choice!=0);
}
