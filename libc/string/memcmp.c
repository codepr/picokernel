#include <string.h>

int memcmp(const void *a, const void *b, size_t size) {
        const unsigned char *aptr = a;
        const unsigned char *bptr = b;
        for (size_t i = 0; i < size; ++i) {
                if (aptr[i] < bptr[i])
                        return -1;
                if (bptr[i] < aptr[i])
                        return 1;
        }
        return 0;
}
