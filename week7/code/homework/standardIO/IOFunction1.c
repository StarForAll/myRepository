#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//1. 创建新文件
int createNewFile_2(){
	FILE *fp;
	printf("请输入新文件名以及对应路径：\n");
	char str[20];
	scanf("%s",str);
        if(str==NULL){
           printf("input fileName is NULL!\n");
           return -1;
        }
        //打开或者创建文件读写文件
        fp=fopen(str,"w");
        if(fp==NULL){
		printf("create file fail!\n");
	       	return -1;
	}
	if(fp!=NULL){
        fclose(fp);
        }
        
	printf("create file %s is successed!\n",str);
	return 0;
}
//2. 写文件
int writeFile_2(){
	printf("请输入文件名以及对应路径：\n");
        char str[20];
        scanf("%s",str);
	FILE *fp;
	char data[1024];
	int count;
        printf("str:%s\n",str);
        if(str==NULL){
           printf("input fileName is NULL!\n");
           return -1;
        }
        
	//在文件末尾最佳内容：
	fp=fopen(str,"a+");
        if(fp==NULL){
                printf("open file %s fail.\n",str);
                return -1;
        }
	printf("open file success.\n");
	
	printf("please writing...,Enter exit to exit.\n");
	while(1){
	scanf("%s",str);
	if(strcmp(str,"exit") == 0){
	break;
	}
	sprintf(data,"%s",str);
	
	strcat(data, "\r\n");

	count = strlen(data);
	fwrite(data,count,1,fp);

	}
	
        if(fp!=NULL){
        fclose(fp);
        }
	printf("End of input.\n");
	return 0;
}
//3. 读文件
int readFile_2(){
	printf("请输入文件名以及对应路径：\n");
        char str[20];
	FILE *fp;
        scanf("%s",str);
        char data[1024];
        
        if(str==NULL){
           printf("input fileName is NULL!\n");
           return -1;
        }

	fp=fopen(str,"r");
        if(fp==NULL){
                printf("open file fail!\n");
                return -1;
        }
        printf("open file success\n");
        
	while(!feof(fp)){
          fread(data,sizeof(char),1024,fp);
          printf("%s\n", data);
         }
        if(fp!=NULL){
        fclose(fp);
        }
	return 0;
}
//4. 修改文件权限
char* updateFilePower(){
	printf("请输入文件名以及对应路径：\n");
        static char str[20];
        scanf("%s",str);
        //所有的用户都可以进行查看，修改，执行.
	if(chmod( str, 0777)==-1){
		printf("Permission modification failed!\n");
	}else{
            printf("Permission modified successfully!\n");
        }
	return str;
}
//5. 查看当前文件的权限修改文件权限
void seekFilePower(char*fileName){
        /*printf("stdlen:%ld\n",strlen(fileName));
       
        printf("fileName:%s\n",fileName);*/
        //ascll:1->标题开始
        int c=(int)(fileName[0]);
	if(strlen(fileName)==1&&c==1){
		printf("没有进行权限修改,无文件查看.\n");
	}else{
		printf("查看那个修改权限之后的文件权限\n");
                char sysInstructions[20]="ls -l ";
                //printf("sysInstructions:%s\n",sysInstructions);
                strcat(sysInstructions,fileName);
                //printf("sysInstructions1:%s\n",sysInstructions);
                system(sysInstructions);
	}
}

