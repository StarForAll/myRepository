#include "1.h"
void sort(int *,int);
void writeData(int *,int,char[]);
void readData(int *,int,char[]);
void sort(int *a,int num){
     for(int i=0;i<num;i++){
          int t = 0;
          for(int j=i+1;j<num;j++){
               if(a[i]>a[j]){
                t=a[j];
                a[j]=a[i];
                a[i]=t;
               }
               
          }
     }
}
void writeData(int *a,int num,char str[]){
  int count = 0;
  const char *pathname = str;
  printf("%s\n", pathname);
  int fd;
  char data[SIZE];
  if ((fd = open(pathname, FLAGS)) == -1) {
     printf("open file fail\n");
     return 0;
  }
  printf("open file success\n");
  //printf("请输入字符串\n");scanf("%s", data);printf("show data:%s\n", data);
  for(int i=0;i<num;i++){
  //sprintf(str, "%d", rand());
  sprintf(data, "%d", a[i]);
  //itoa(a[i],data,10);
  count = strlen(data);
  data[count] = '\n';//结尾增加换行符。
  data[count+1] = '\0';//赋值新的结束符。
  //data+="\n";
  count = strlen(data);
  //printf("data length is %d\n", count);
  if (write(fd, data, count) == -1) {
     printf("write data fail\n");
     return 0;
     }
  }
  printf("write data success\n");
  close(fd);
  
  return 0; 
}
void readData(int *a,int num,char str[]){
  int count = 0;
  const char *pathname = str;
  printf("%s", pathname);
  int fd;
  char data[SIZE];
  if ((fd = open(pathname, FLAGS)) == -1) {
     printf("open file fail\n");
     return 0;
  }
  printf("open file success\n");
  fd = open(pathname, O_RDONLY);
  char content[100];
  read(fd, content, sizeof(content));
  printf("data %s\n", content);
  close(fd);
}
