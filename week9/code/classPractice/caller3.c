#include"my.h"
int main(){
	char *argv[]={"./test2","hello","World",NULL};
	printf("caller3:ppid=%d,pid=%d.\n",getppid(),getpid());
	execv("/home/linuxprogram/week9/code/classPractice/test2",argv);
	printf("after using execv.\n");
}
