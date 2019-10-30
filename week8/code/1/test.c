#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	//父进程:   本进程号:
	printf("ppid =%d,pid =%d.\n",getppid(),getpid());
	return 0;
}
