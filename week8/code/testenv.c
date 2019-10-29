#include<stdio.h>
int main(int argc,char *argv[],char *env[]){
	//char *env[]:用于存储环境变量
	for(int i=0;env[i]!=NULL;i++){
		printf("%s\n",env[i]);
	}
	return 0;
}
