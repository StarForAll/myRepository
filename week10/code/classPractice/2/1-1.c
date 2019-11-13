#include"my.h"
void function1(){
	printf("-------------function1---------------\n");
}
void function2(){
        printf("-------------function2---------------\n");
}
static void __attribute__((constructor)) function3(){
        printf("-------------function3---------------\n");
}
static void __attribute__((destructor)) function4(){
        printf("-------------function4---------------\n");
}
int main(){
	printf("main start\n");
	atexit(function1);
	atexit(function2);
	FILE *fp;
	char buf[] = {"fputs use full buffer!"};
	if((fp=fopen("test.dat","w+"))==NULL){
		perror("failed to create file!\n");
		return -1;
	}
	if(fputs(buf,fp)==EOF){
		perror("failed to fput file!\n");
		return -1;
	}
	printf("running in main.\n");
	printf("main end");
	//while(1);
	//exit(0);
	_exit(0);
	//return 0;
}
