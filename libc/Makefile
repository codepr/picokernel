
CC=i686-elf-gcc
AR=i686-elf-ar

CFLAGS?=-O2 -g
LIBS?=
ARCHDIR=arch/i386

CFLAGS:=$(CFLAGS) -ffreestanding -Wall -Wextra -Iinclude -I../include
LIBS:=$(LIBS) -nostdlib -lgcc
LIBC_OBJS=\
string/strlen.o \

.SUFFIXES: .o .c

all: libc.a

libc.a: $(LIBC_OBJS)
	$(AR) rcs $@ $(LIBC_OBJS)

.c.o:
	$(CC) -MD -c $< -o $@ -std=gnu11 $(CFLAGS)

clean:
	rm ./*.o ./*.bin ./*.iso ../isodir/boot/*.bin
