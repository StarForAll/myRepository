//û���ⲿ���ļ���ʹ��:Ч����ͬ�ڱ�׼��Hello World!�����ʾ.
/**
   *ָ��:
   *1. gcc -c -fno-builtin TinyHelloWorld.c  ����.o�ļ�,-fno-builtin :�ر�gcc�����ú�������
   *2. ld -static -e nomain -o TinyHelloWorld TinyHelloWorld.o  
   *   ld -static -T TinyHelloWorld.lds -o TinyHelloWorld TinyHelloWorld.o
   * -static:��̬���ӷ�ʽ;-e nomain:��ں�����nomain
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