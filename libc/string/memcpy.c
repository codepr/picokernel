#include <string.h>

void *memcpy(void *__restrict dst, const void *__restrict src, size_t size) {
        unsigned char *dstptr = dst;
        const unsigned char *srcptr = src;
        for (size_t i = 0; i < size; ++i)
                dstptr[i] = srcptr[i];
        return dst;
}
