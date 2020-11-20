#ifndef TTY_H
#define TTY_H

#include <ukernel/types.h>

void terminal_initialize();
void terminal_putchar_at(i8 c, u8 color, usize x, usize y);
void terminal_putchar(char c);
void terminal_write(const char *data, usize size);
void terminal_writestring(const char *data);

#endif
