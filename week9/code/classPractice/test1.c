#include"my.h"
static void __attribute__((constructor)) function1(){
	printf("function1 is running!\n");
}
static void function2(void){
	printf("function2 is running!\n");
}
static void function3(void){
        printf("function3 is running!\n");
}
int main(int argc,char *argv[]){
	printf("test1'main is starting....\n");
	printf("test1:pid=%d,ppid=%d.\n",getpid(),getppid());
	atexit(function2);
	atexit(function3);
	for(int i=0;i<argc;i++){
		printf("test1:%d %s.\n",i,argv[i]);
	}
	printf("test1'main is end.\n");
	return 0;
}
