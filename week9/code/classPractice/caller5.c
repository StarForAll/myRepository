#include"my.h"
int main(){
	char *parameters[]={"test2","abc","def"};
	printf("caller5:ppid=%d,pid=%d.\n",getppid(),getpid());
	execvp("test2",parameters);
	printf("after using execvp.\n");
	return 0;
}
