#include<stdio.h>
 
void func_int(void * a)
{
    printf("%d\n",*(int*)a);  //���int���ͣ�ע�� void * ת��Ϊint
}
 
void func_double(void * b)
{
    printf("%.2f\n",*(double*)b);
}
 
typedef void (*ptr)(void *);  //typedef����һ������ָ��
 
void c_func(ptr p,void *param)
{
     p(param);                //���ö�Ӧ����
}
 
int main()
{
    int a = 23;
    double b = 23.23;
    c_func(func_int,&a);
    c_func(func_double,&b);
    return 0;
}
