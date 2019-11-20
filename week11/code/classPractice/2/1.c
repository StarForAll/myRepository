#include "my.h"
int main(){
	pid_t pids[3]={-1,-1,-1};
	FILE *fp;
	fp = openFile();
	/*for(int i = 0;i<3;i++){
		pids[i] = fork();
		//如果是子进程,停止fork使用.
		if(pids[i] ==0||pids[i]==-1){
			break;
		}
		//printf("%d\n",pids[i]);
	}*/
	pids[0] = fork();
	if(pids[0]<0){
		perror("pid1 failed to fork!\n");
	}else if(pids[0]==0){
		printf("child1 pid :%d.begin to writing.\n",getpid());
		writeFile(fp);
		exit(1);
	}else{
		pids[1] = fork();
		if(pids[1]<0){
                        perror("pid2 failed to fork!\n");
                }else if(pids[1]==0){
                        printf("child2 pid :%d.begin to writing.\n",getpid());
			writeFile(fp);
			exit(2);
                }else{
			pids[2] = fork();
			if(pids[2]<0){
				perror("pid3 failed to fork!\n");
			}else if(pids[2]==0){
				printf("child3 pid :%d.begin to writing.\n",getpid());
				writeFile(fp);
				exit(3);
			}else{
				//等待所以的子进程结束
                                while(wait(NULL)!=-1);
                                printf("this is parent process,pid:%d.\n",getpid());
				readFile(fp);
				fclose(fp);
				return 0;
			}
		}
	}
}
