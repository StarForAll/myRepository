#include"../my.h"
void init_daemon(){
	pid_t p;
	p = fork();
	if(p>0){
		exit(0);
	}else if(p <0 ){
		perror("failed fork!\n");
		exit(1);
	}
	setsid();
	chdir("/tmp");
	umask(0);
	for(int i=0;i<NOFILE;i++){
		close(i);
	}
}
