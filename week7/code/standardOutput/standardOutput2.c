#include<stdio.h>
int main(){
        //方式2：将缓冲区内容清空波那个输出.
        printf("HELLO WORLD!");
	fflush(stdout);
        while(1);
        return 0;
}
