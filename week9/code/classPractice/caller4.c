#include"my.h"
int main(){
	printf("caller4:ppid=%d,pid=%d.\n",getppid(),getpid());
	execlp("test2","./test2","hello","World",NULL);
	printf("after using execlp.\n");
}
