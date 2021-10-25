#include "memory_operations.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void *my_memcpy(void *dst, const void *src, size_t len) {
    memcpy(dst, src, len);
}

void *my_memmove(void *dst, const void *src, size_t len) {
    memmove(dst, src, len);
}

int is_little_endian() {
    int n = 0x1;
    return (*(char *)&n);
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
