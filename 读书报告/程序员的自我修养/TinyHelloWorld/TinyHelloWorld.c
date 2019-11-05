//没有外部库文件的使用:效果等同于标准的Hello World!输出显示.
/**
   *指令:
   *1. gcc -c -fno-builtin TinyHelloWorld.c  生成.o文件,-fno-builtin :关闭gcc的内置函数功能
   *2. ld -static -e nomain -o TinyHelloWorld TinyHelloWorld.o  
   *   ld -static -T TinyHelloWorld.lds -o TinyHelloWorld TinyHelloWorld.o
   * -static:静态链接方式;-e nomain:入口函数是nomain
   */
char *str = "Hello World!\n";
void print(){
         asm("mov1 $13,%%edx \n\t"
                "mov1 %0,%%ecx   \n\t"  
                "mov1 %0,%%ebx   \n\t"
                "mov1 $4,%%eax     \n\t"
                "int $0x80                 \n\t"
                ::"r"(str):"edx","ecx","ebx","eax");
}
void exit(){
        asm("mov1 $42,%ebx  \n\t"
                 "mov1 $1,%eax   \n\t"
                  "int $0x80           \n\t");
}
void nomain(){
        print();
        exit();
}