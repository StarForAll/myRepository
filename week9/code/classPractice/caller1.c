#include"my.h"
int main(){
	int ret ;
	printf("caller1:pid=%d,ppid=%d.\n",getpid(),getppid());
	ret = system("./test1 helloWorld 123 abc");
	printf("caller1 is ending,ret = %d.\n",ret);
	return 0;
}
