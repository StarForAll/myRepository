#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<wait.h>
#include<fcntl.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
#include<errno.h>
//2中2.c中的函数声明
void signalhandler(int signo);
