#include "screen.h"
#include "descriptors.h"


int kmain(void *mbd,unsigned int magic){
	screen_clear();
	if (magic!=0x2BADB002){
		screen_print("Invalid multiboot header.");
		return -1;
	}
	screen_print("Hello World!\n");
	screen_print("Setting up the GDT.\n");
	gdt_setup();
	screen_print("GDT is set.\n");
	return 0;
}

