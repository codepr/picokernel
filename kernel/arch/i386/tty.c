#include "vga.h"
#include <string.h>
#include <kernel/tty.h>

static usize terminal_row;
static usize terminal_column;
static u8 terminal_color;
static u16* terminal_buffer;
static const usize VGA_WIDTH = 80;
static const usize VGA_HEIGHT = 25;

void terminal_initialize(void) {
        terminal_row = 0;
        terminal_column = 0;
        terminal_color = vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_DARK_GREY);
        terminal_buffer = (u16 *) 0xB8000;
        for(usize y = 0; y < VGA_HEIGHT; y++) {
                for(usize x = 0; x < VGA_WIDTH; x++) {
                        const usize idx = y * VGA_WIDTH + x;
                        terminal_buffer[idx] = vga_entry(' ', terminal_color);
                }
        }
}

void terminal_putchar_at(i8 c, u8 color, usize x, usize y) {
        const usize index = y * VGA_WIDTH + x;
        terminal_buffer[index] = vga_entry(c, color);
}

void terminal_putchar(char c) {
        terminal_putchar_at(c, terminal_color, terminal_column, terminal_row);
        if (++terminal_column == VGA_WIDTH) {
                terminal_column = 0;
                if (++terminal_row == VGA_HEIGHT)
                    terminal_row = 0;
        }
}

void terminal_write(const char *data, usize size) {
    for (usize i = 0; i < size; i++)
        terminal_putchar(data[i]);
}

void terminal_writestring(const char *data) {
    terminal_write(data, strlen(data));
}
