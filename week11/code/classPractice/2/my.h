#include<stdio.h>
#include<stdlib.h>
#include<wait.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/param.h>
#include<time.h>
#include"string.h"
FILE* openFile();
int writeFile(FILE* fd);
int readFile(FILE* fd);
void init_daemon();
