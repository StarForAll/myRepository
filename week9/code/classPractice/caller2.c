#include"my.h"
int main(){
	printf("caller2:ppid=%d,pid=%d.\n",getppid(),getpid());
	execl("/home/linuxprogram/week9/code/classPractice/test2","./test2","hello","World",NULL);
	printf("after using execl.\n");
}
