#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//1. 创建新文件
int createNewFile(){
	printf("请输入新文件名以及对应路径：\n");
	char str[20];
	scanf("%s",str);
	int fd = 0;
        if(str==NULL){
           printf("input fileName is NULL!\n");
           return -1;
        }
	// 创建一个新的文件
        fd = open(str,O_CREAT,0644);
	if( fd == -1 ){
		perror("create file:");
		return -1;
	}
	close(fd);
	printf("create file %s is successed!\n",str);
	return 0;
}
//2. 写文件
int writeFile(){
	printf("请输入文件名以及对应路径：\n");
        char str[20];
        scanf("%s",str);
	char data[1024];
	int count;
	int fd;
        printf("str:%s\n",str);
        if(str==NULL){
           printf("input fileName is NULL!\n");
           return -1;
        }
        
	if((fd=open(str,O_RDWR))==-1){
			printf("open file %s fail.\n",str);
			return -1;
	}
	printf("open file success.\n");
	lseek(fd,0,SEEK_END);
	printf("please writing...,Enter exit to exit.\n");
	while(1){
	scanf("%s",str);
	if(strcmp(str,"exit") == 0){
	break;
	}
	sprintf(data,"%s",str);
	count = strlen(data);
        data[count] = '\n';//结尾增加换行符。
        data[count+1] = '\0';//赋值新的结束符。
	count = strlen(data);
	if (write(fd, data, count) == -1) {
           printf("write data fail!\n");
            break;
           }
	}
	close(fd);
	printf("End of input.\n");
	return 0;
}
//3. 读文件
int readFile(){
	printf("请输入文件名以及对应路径：\n");
        char str[20];
        scanf("%s",str);
        char data[1024];
        int fd;
        if(str==NULL){
           printf("input fileName is NULL!\n");
           return -1;
        }
	if ((fd = open(str, O_RDONLY)) == -1) {
         printf("open file fail\n");
         return -1;
        }
        printf("open file success\n");
        read(fd, data, sizeof(data));
        printf("%s\n", data);
        close(fd);
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
	}
	printf("Permission modified successfully!\n");
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

