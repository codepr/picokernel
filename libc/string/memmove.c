#include <string.h>

void *memmove(void *dst, const void *src, size_t size) {
        unsigned char *dstptr = dst;
        const unsigned char *srcptr = src;
        if (dstptr < srcptr) {
                for (size_t i = 0; i < size; ++i)
                        dstptr[i] = srcptr[i];
        } else {
                for (size_t i = size; i != 0; --i)
                        dstptr[i - 1] = srcptr[i - 1];
        }
        return dstptr;
}
