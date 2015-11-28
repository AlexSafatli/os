#include "kernel.h"
#include "framebuffer.h"
#include "serial.h"
#include "gdt.h"
#include "idt.h"
#include "timer.h"

void kernel_init() {
  fb_init();
  fb_clear();
  serial_init(SERIAL_COM1);
  gdt_init();
  idt_init();
  fb_write("Fear is freedom! Subjugation is liberation! Contradiction is truth! Those are the facts of this world, and you will all surrender to them.");
  timer_init(50);
}