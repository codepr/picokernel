#include <kernel/tty.h>
#include <kernel/io.h>

void kernel_main(void) {
        terminal_initialize();
        printlnk("Hello, World!");
}

