#include<stdio.h>
int main(){
        //方式3：关闭缓冲区,在关闭时会执行对应的I/O操作.
        printf("HELLO WORLD!");
	fclose(stdout);
        while(1);
        return 0;
}
