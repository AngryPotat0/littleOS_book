#include"../include/kprintf.h"

void kmain()
{
    clearScreen();
    char *str = "Lisp";
    int a = 1200;
    kprintf("Hello,%s,num=%d",str,a);
    return;
}