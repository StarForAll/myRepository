#include"my.h"
int k=9;
int main(){
	//静态局部变量,存放在数据段中.
	static int r=9;
	pid_t pid;
	//栈中数据
	int y=9;
	//进程私有段:栈区.
	pid=fork();
	if(pid<0){
		perror("fork failed!\n");
		exit(1);
	}else if(pid==0){
		printf("child:pid=%d,ppid=%d,ret=%d.\n",getpid(),getppid(),pid);
		printf("child:&k=%p,&r=%p,&y=%p.\n",&k,&r,&y);
		k=10;
		r=10;
		y=10;
		printf("child:k=%d,r=%d,y=%d.\n",k,r,y);
		exit(100);
	}else{
		sleep(1);
		printf("parent:pid=%d,ppid=%d,ret=%d.\n",getpid(),getppid(),pid);
                printf("parent:&k=%p,&r=%p,&y=%p.\n",&k,&r,&y);
                printf("parent:k=%d,r=%d,y=%d.\n",k,r,y);
		return 0;
	}
	return 0;
}
