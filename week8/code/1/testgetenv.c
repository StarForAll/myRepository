#include<stdio.h>
#include<stdlib.h>
int main(){
	//根据对应的字符串获取对应的环境变量.
	printf("%s\n",getenv("PATH"));
	return 0;
}
