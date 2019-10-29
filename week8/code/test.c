#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	printf("ppid =%d,pid =%d.\n",getppid(),getpid());
	return 0;
}
