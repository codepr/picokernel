#include <kernel/tty.h>
#include <kernel/io.h>

void kernel_main(void) {
    terminal_initialize();
    kprint("Hello\n");
}

