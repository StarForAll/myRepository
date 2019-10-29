#include<stdio.h>
int main(int argc,char *argv[]){
	//全局变量,定义在c库中,储存着系统的环境变量.
	extern char **environ;
	for(int i=0;environ[i];i++){
		printf("%s\n",environ[i]);
	}
	return 0;
}
