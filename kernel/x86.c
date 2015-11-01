#include "x86.h"

void pic_send_eoi(unsigned char irq) {
  if (irq >= 8) outb(PIC2_CMD, PIC_EOI);
  outb(PIC1_CMD, PIC_EOI);
}

void pic_init() {
  outb(PIC1_CMD,  0x11);
  outb(PIC2_CMD,  0x11);
  outb(PIC1_DATA, 0x20); // ISR 32 - 39
  outb(PIC2_DATA, 0x28); // ISR 40 - 47
  outb(PIC1_DATA, 0x04);
  outb(PIC2_DATA, 0x02);
  outb(PIC1_DATA, 0x01);
  outb(PIC2_DATA, 0x01);
  outb(PIC1_DATA, 0x00);
  outb(PIC2_DATA, 0x00);
}