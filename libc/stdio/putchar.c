#include <stdio.h>

#if defined(__is_libk)
#include <kernel/tty.h>
#endif

int putchar(int ic) {
#if defined(__is_libk)
        char c = ic;
        terminal_write(&c, sizeof(c));
#else
        // TODO need write syscall
#endif
        return ic;
}
