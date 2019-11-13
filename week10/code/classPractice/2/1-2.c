#include"my.h"
int g = 10;
int main(){
	int t = 20;
	static int s = 30;
	int status;
	pid_t pid;
	pid = fork();
	if(pid<0){
		perror("vfork failed!\n");
		exit(-1);
	}else if(pid==0){
		int p = 40;
		printf("child:pid=%d,&g=%16p,&t=%16p,&s=%16p,&p=%16p.\n",getpid(),&g,&t,&s,&p);
		g = 100;
		t = 200;
		s = 300;
		p = 400;
		printf("output child value:\n");
		printf("g=%d,t=%d,s=%d,p=%d.\n",g,t,s,p);
		//return(0);
		exit(199);
		//_exit(0);
	}else{
		wait(&status);
		printf("child exit value:%d.\n",WEXITSTATUS(status));
		printf("parent pid=%d,g=%16p,t=%16p,s=%16p.\n",getpid(),&g,&t,&s);
		printf("g=%d,t=%d,s=%d.\n",g,t,s);
		return 0;
	}
}
