#include"../include/type.h"
#include"../include/asm.h"

/* 从端口读一个字节 */
inline uint8_t inb (uint16_t port){
    uint8_t result;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (result) : "dN" (port));
    return result;
}

/* 向端口写一个字节 */
inline void outb (uint16_t port, uint8_t data){
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (port), "a" (data));
}

/* 从端口读一个字（两个字节） */
inline uint16_t inw (uint16_t port){
    uint16_t result;
    __asm__ __volatile__ ("inw %1, %0" : "=a" (result) : "dN" (port));
    return result;
}

/* 向端口写一个字（两个字节） */
inline void outw (uint16_t port, uint16_t data){
    __asm__ __volatile__ ("outw %1, %0" : : "dN" (port), "a" (data));
}