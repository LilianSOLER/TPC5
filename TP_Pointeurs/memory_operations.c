#include "memory_operations.h"
#include <stdlib.h>
#include <stdint.h>

void *my_memcpy(void *dst, const void *src, size_t len) {
    for(int i = 0; i < len-1; i++){
        dst[i] = src[i];
    }
}

void *my_memmove(void *dst, const void *src, size_t len) {
    my_memcpy(*dst, *src, len);
}

int is_little_endian() {
    unsigned int x = 1;
    return (int) (((char*)&x)[0]);
}

int reverse_endianess(int value) {
    int *ptrValue = &value;
    int j = sizeof(value)-1;
    for (int i = 0, i < j, i++){
        char tmp = ptrValue[i];
        ptrValue[i] = ptrValue[j];
        ptrValue[j] = tmp;
        j--;
    }
    return value;
}
