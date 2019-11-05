#include"my.h"
int main(int argc,char *argv[]){
	printf("test2:pid=%d,ppid=%d.\n",getpid(),getppid());
	for(int i=0;i<argc;i++){
		printf("test2:%d %s.\n",i,argv[i]);
	}
	return 0;
}
