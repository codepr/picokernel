CC=i686-elf-gcc

CFLAGS?=-O2 -g
LIBS?=
ARCHDIR=arch/i386

CFLAGS:=$(CFLAGS) -ffreestanding -Wall -Wextra -Iinclude -I../include
LIBS:=$(LIBS) -nostdlib -lgcc
KERNEL_OBJS=\
$(ARCHDIR)/boot.o \
$(ARCHDIR)/tty.o \
kernel/kernel.o \

all: ukernel.os

ukernel.os: $(KERNEL_OBJS) $(ARCHDIR)/linker.ld
	$(CC) -T $(ARCHDIR)/linker.ld -o $@ $(CFLAGS) $(LIBS) $(KERNEL_OBJS)
	cp ukernel.os ../isodir/boot/ukernel.bin

clean:
	rm ./*.o ./*.bin ./*.iso ../isodir/boot/*.bin
