# CC = i686-elf-gcc
#
# main: kernel.c linker.ld boot.asm
# 	nasm -felf32 boot.asm -o boot.o
# 	$(CC) -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -Wall -Wextra
# 	$(CC) -T linker.ld -o ukernel.bin -ffreestanding -nostdlib boot.o kernel.o -lgcc
# 	cp ukernel.bin isodir/boot/ukernel.bin
# 	grub2-mkrescue -o ukernel.iso isodir
#
# clean:
# 	rm ./*.o ./*.bin ./*.iso ./isodir/boot/*.bin

SUBDIRS := $(libc/ kernel/)

all: kernel iso

kernel: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@

iso:
	grub2-mkrescue -o ukernel.iso isodir

.PHONY: all $(SUBDIRS)
