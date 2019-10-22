#include<unistd.h>
#include<iostream>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
using namespace std;

int main(){
	int fd;
	FILE *file;
	char *s="HELLO WORLD\n";
	//系统I/O操作
	if((fd=open("test1.txt",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR))==-1){
		cout<<"Error open file!"<<endl;
		return -1;
	}
	//标准I/O操作
	if((file=fopen("test2.txt","w+"))==NULL){
		cout<<"Error open file."<<endl;
		return -1;
	}
	cout<<"File has been opened."<<endl;
	//查看两个文件是否创建成功
	sleep(15);
	if(write(fd,s,strlen(s))<strlen(s)){
		cout<<"Write Error."<<endl;
		return -1;
	}
	//标准方式下的默认方式：全缓冲方式.
	if(fwrite(s,sizeof(char),strlen(s),file)<strlen(s)){
		cout<<"Write Error in 2."<<endl;
		return -1;
	}
	cout<<"After write"<<endl;
	sleep(15);
	cout<<"After sleep"<<endl;
	close(fd);
	return 0;
}
