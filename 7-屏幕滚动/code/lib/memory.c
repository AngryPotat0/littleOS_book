#include "../include/type.h"

void memcpy(void *src, void *dest,uint32_t len)
{
    uint8_t *s = (uint8_t*)src;
    uint8_t *d = (uint8_t*)dest;
    for(uint32_t i = 0;i < len;i++){
        d[i] = s[i];
    }
}

void *memset(void *src,uint8_t val,uint32_t len)
{
    uint8_t *s = (uint8_t*)src;
    for(uint32_t i = 0;i < len;i++){
        s[i] = val;
    }
    return src;
}