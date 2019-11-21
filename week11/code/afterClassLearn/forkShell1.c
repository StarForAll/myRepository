#include"my.h"
int argc;
char *argv[32];
int param_parse(char *buff){
	if(buff==NULL){
		return -1;
	}
	char *ptr = buff;
	char *tmp=ptr;
	argc = 0;
	while((*ptr)!='\0'){
		if((*ptr)==' '&&*(ptr+1)!=' '){
			*ptr = '\0';
			argv[argc] = tmp;
			tmp = ptr +1;
			argc++;
		}
		ptr++;
	}
	argv[argc++] = tmp;
	argv[argc] = NULL;
	return 0;
}
int do_exec(){
	int pid = 0;
	int status;
	pid = fork();
	if(pid<0){
		perror("fork failed!\n");
		return -1;
	}else if(pid == 0){
		execvp(argv[0],argv);
		exit(0);
	}else{
		wait(&status);
		if(WIFEXITED(status)){
			printf("%s",strerror(WEXITSTATUS(status)));
		}
		return 0;
	}
}
int main(){
	while(1){
		printf("shell>");
		char buff[1024] ={0};
		//遇到换行符停止,清空缓冲器
		scanf("%[^\n]%*c",buff);
		printf("%s\n",buff);
		if(strcmp("exit",buff)==0){
			break;
		}
		param_parse(buff);
		do_exec();
	}
	return 0;
}

