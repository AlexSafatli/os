#include "kernel.h"

void clear() {
	int i;
	char s[] = " ";
	for (i = 0; i < FB_NUM_CELLS; ++i) fb_write(s, 1);
}

void kernel_init() {
	fb_init();
  serial_init(SERIAL_COM1);
  //gdt_init();
	clear();
	char s[] = "Fear is freedom! Subjugation is liberation! Contradiction is truth! Those are the facts of this world, and you will all surrender to them.";
	fb_write(s, sizeof(s) - 1);
  serial_write(SERIAL_COM1, s, 12);
}