#include<stdio.h>
int main(){
        //方式3：进行说明,明确输出缓冲类型为行缓冲.
	setvbuf(stdout,NULL,_IONBF,0);
        printf("HELLO WORLD!");
        while(1);
        return 0;
}
