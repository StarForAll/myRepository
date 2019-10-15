#include "ourhdr.h"
int main(){
     int fd = -1;
    int ret = -1;
    int size = -1;
    char read_buf[1024] = {0};
    char write_buf[32] = "hello world";

    /* lseek后，读取文件 */
    printf("-------------READ--------------------\n");
    fd = open(filePath, O_RDWR | O_APPEND);
    if (fd == -1)
    {
        printf("open failed\n");
        return 0;
    }

    //将文件指针设置在文件开头
    ret = lseek(fd, 0, SEEK_SET);
    if (ret == -1)
    {
        printf("lseek function failed.\n");
        close(fd);
        return 0;
    }
    printf("After lseek position is:%d\n", ret);

    //读取文件
    size = read(fd, read_buf, sizeof(read_buf));
    if (size == -1)
    {
        printf("read failed\n");
        close(fd);
        return 0;
    }
    printf("read number of character == %d\n", size);
    printf("read_buf:%s\n", read_buf);
    close(fd);


    /* lseek后，写入文件 */
    printf("-------------WRITE-----------------\n");
    fd = open(filePath, O_RDWR | O_APPEND);
    if (fd == -1)
    {
        printf("open failed\n");
        return 0;
    }

    //将文件指针设置在文件开头
    ret = lseek(fd, 0, SEEK_SET);
    if (ret == -1)
    {
        printf("lseek failed.\n");
        close(fd);
        return 0;
    }
    printf("After lseek position is:%d\n", ret);

    //读取文件
    size = write(fd, write_buf, strlen(write_buf));
    if (size == -1)
    {
        printf("write failed\n");
        close(fd);
        return 0;

    }
    printf("write number of character == %d\n", size);
    close(fd);
    return 0;
}
