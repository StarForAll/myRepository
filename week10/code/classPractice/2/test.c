#include"my.h"
int nums[10]={0};
int main(){
	for(int i=0;i<10;i++){
		printf("testPid:%d &nums[%d]=%16p.\n",getpid(),i,&nums[i]);
	}
	return 0;
}
