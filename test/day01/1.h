#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include <fcntl.h>
#include<sys/time.h>
#define length 10 
#define randData "/myRepository/test/day01/rand.dat"
#define sortData "/myRepository/test/day01/sort.dat"
#define SIZE 10
#define FLAGS O_RDWR|O_CREAT|O_TRUNC
#define ONLYREAD O_RDWR
struct arg{
   float average;
   int sum;
};
void show(int *,int);
void urand(int *,int);
void sort(int *,int);
void sysSort(int *,int);
void writeData(int *,int,char[]);
void readData(int *,int,char[]);
struct arg getResult(int *,int);
