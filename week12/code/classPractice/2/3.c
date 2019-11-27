#include"../1/my.h"
#define BUF_4K 4*1024
#define BUF_8K 8*1024
#define BUF_12K 12*1024
int main(){
	char a[BUF_4K];
	char b[BUF_8K];
	char c[BUF_12K];
	int pfd[2];
	int ret;
	pid_t pid;
	memset(a,'A',sizeof(a));
	memset(b,'B',sizeof(b));
	memset(c,'C',sizeof(c));
	ret=pipe(pfd);
	if(ret==-1){
		fprintf(stderr,"create pipe error.reason:%s.\n",strerror(errno));
		return -1;
	}
	pid=fork();
	if(pid<0){
		fprintf(stderr,"create child error.reason:%s.\n",strerror(errno));
		return -2;
	}else if(pid==0){
		close(pfd[0]);
		int loop=0;
		while(loop++<10){
			ret=write(pfd[1],a,sizeof(a));
			printf("a pid=%d,write %d bytes topipe.\n",getpid(),ret);
		}
		exit(0);
	}else{
		pid=fork();
		if(pid<0){
			fprintf(stderr,"create child error.reason:%s.\n",strerror(errno));
			return -2;
		}else if(pid==0){
			close(pfd[0]);
			int loop=0;
			while(loop++<10){
				ret=write(pfd[1],b,sizeof(b));
				printf("b pid=%d,write %d bytes topipe.\n",getpid(),ret);
			}
			exit(0);
		}else{
			pid=fork();
			if(pid<0){
				fprintf(stderr,"create child error.reason:%s.\n",strerror(errno));
				return -2;
			}else if(pid==0){
				close(pfd[0]);
				int loop=0;
				while(loop++<10){
					ret=write(pfd[1],a,sizeof(a));
					printf("c pid=%d,write %d bytes topipe.\n",getpid(),ret);
				}
				exit(0);
			}else{
				//等待所以的子进程结束
                                //while(wait(NULL)!=-1);
				close(pfd[1]);
				int fd=open("./data.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
				char buf[1024];
				int n=1;
				while(1){
					ret=read(pfd[0],buf,sizeof(buf));
					if(ret==0){
						break;
					}
	printf("n=%02d,pid=%d,read %d bytes from pipe buf[4095]=%c\n",n++,getpid(),ret,buf[4095]);
	                        write(fd,buf,ret);
				}
				return 0;
			}
		}
	}
}
