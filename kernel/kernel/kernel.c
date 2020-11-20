#include <kernel/tty.h>

void kernel_main(void) {
    terminal_initialize();
    terminal_putchar('A');
    terminal_putchar('B');
    terminal_putchar('C');
}

