#ifndef STRING_H
#define STRING_H

#include <ukernel/types.h>

int memcmp(const void*, const void*, size_t);
void* memcpy(void* __restrict, const void* __restrict, size_t);
void* memmove(void*, const void*, size_t);
void* memset(void*, int, size_t);
usize strlen(const char*);

#endif
