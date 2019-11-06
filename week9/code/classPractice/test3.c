#include"my.h"
static void __attribute((destructor)) destructorFunction(){
	printf("-----------DeconstructionFunction!------\n");
}
static void fun(){
	printf("----------fun()-------------\n");
}
int main(){
	atexit(fun);
	printf("main end.\n");
	return 0;
}
