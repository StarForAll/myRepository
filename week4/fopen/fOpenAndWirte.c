#include"fOpenAndWrite.h"
int main(){
     //源文件和目的文件都必须存在;
     int nread = 0;
     char buff[READ_BUFF]={0};
     FILE *fp_read,*fp_write;
     char fileName[20];
     char fileName1[20];
     printf("请输入源文件名:\n");
     scanf("%s",fileName);
     if((fp_read=fopen(fileName,"rb"))==NULL){
         printf("Cann't open %s !",fileName);
         return 1;
       }
     printf("请输入目的文件名:\n");
     scanf("%s",fileName1);
     if((fp_write=fopen(fileName1,"wb"))==NULL){
        printf("Cann't open %s !",fileName1);
        return 1;
        }
     while((nread=fread(buff,sizeof(char),READ_BUFF,fp_read))>0)
     fwrite(buff,sizeof(char),nread,fp_write);
     fclose(fp_read);
     fclose(fp_write);
     printf("文件拷贝完毕!\n");
     return 0;
}
