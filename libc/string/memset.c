#include <string.h>

void *memset(void *buffer, int value, size_t size) {
        unsigned char *bufptr = buffer;
        for (size_t i = 0; i < size; ++i)
                bufptr[i] = value;
        return buffer;
}
