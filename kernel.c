#include "kernel.h"





typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef uint32_t size_t;

extern char __bss[],__bss_end[],__stack_top[];



struct sbiret sbi_call(long arg0,long arg1,long arg2,long arg3,long arg4,long arg5,long fid,long eid){
    register long a0 __asm__("a0")=arg0;
    register long a0 __asm__("a5")=arg5;
    register long a1 __asm__("a1")=arg1;
    register long a2 __asm__("a2")=arg2;
    register long a3 __asm__("a3")=arg3;
    register long a4 __asm__("a4")=arg4;    

}


void *memset(void *buf,char c,size_t n){
    uint8_t *p=(uint8_t *) buf;
    while(n--){
        *p++=c;

    }
    return buf;
}


void kernel_main(void){
    memset(__bss,0,(size_t)__bss_end-(size_t)__bss);
    for(;;);
}

__attribute__((section(".text.book")))
__attribute__((naked))
void boot(void){
    __asm__ __volatile__(
        "mv sp, %[stack_top]\n" 
        "j kernel_main\n"       
        :
        : [stack_top] "r" (__stack_top) 
    );
}