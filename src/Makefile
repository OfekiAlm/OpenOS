CC:=i686-elf-gcc
CFLAGS:=-c -Wall -m32 -march=i686
LD:=ld
LDFLAGS:=-T linker.ld -m elf_i386 -o kernel.bin
ASM:=nasm
ASMFLAGS:=-f elf

all: kernel.o boot.o
	$(LD) $(LDFLAGS) kernel.o boot.o screen.o gdt.o descriptors.o

kernel.o: screen.o descriptors.o
	$(CC) $(CFLAGS) kernel/kernel.c

boot.o: kernel.o
	$(ASM) $(ASMFLAGS) -o boot.o boot/boot.asm

gdt.o:
	$(ASM) $(ASMFLAGS) -o gdt.o kernel/gdt.asm

descriptors.o: gdt.o
	$(CC) $(CFLAGS) kernel/descriptors.c

screen.o:
	$(CC) $(CFLAGS) kernel/screen.c

clean:
	$(shell rm -rf *.o kernel.bin)
