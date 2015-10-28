#include "kernel.h"

void kernel_init() {
  fb_init();
  fb_clear();
  serial_init(SERIAL_COM1);
  gdt_init();
  idt_init();
  char s[] = "Fear is freedom! Subjugation is liberation! Contradiction is truth! Those are the facts of this world, and you will all surrender to them.";
  fb_write(s, sizeof(s) - 1);
  serial_write(SERIAL_COM1, s, 12);
}