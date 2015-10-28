/* idt.c
* Author: Alex Safatli
*/

#include "idt.h"

idt_entry_t idt_entries[IDT_NUM_ENTRIES];
idt_ptr_t   idt;

void idt_init() {
  
  // Set table entries.
  memset(&idt_entries, 0, sizeof(idt_entry_t) * IDT_NUM_ENTRIES);  
  idt_set_entry(0 ,(unsigned int) isr0 , 0x08, 0x8E);
  idt_set_entry(1 ,(unsigned int) isr1 , 0x08, 0x8E);
  idt_set_entry(2 ,(unsigned int) isr2 , 0x08, 0x8E);
  idt_set_entry(3 ,(unsigned int) isr3 , 0x08, 0x8E);
  idt_set_entry(4 ,(unsigned int) isr4 , 0x08, 0x8E);
  idt_set_entry(5 ,(unsigned int) isr5 , 0x08, 0x8E);
  idt_set_entry(6 ,(unsigned int) isr6 , 0x08, 0x8E);
  idt_set_entry(7 ,(unsigned int) isr7 , 0x08, 0x8E);
  idt_set_entry(8 ,(unsigned int) isr8 , 0x08, 0x8E);
  idt_set_entry(9 ,(unsigned int) isr9 , 0x08, 0x8E);
  idt_set_entry(10,(unsigned int) isr10, 0x08, 0x8E);
  idt_set_entry(11,(unsigned int) isr11, 0x08, 0x8E);
  idt_set_entry(12,(unsigned int) isr12, 0x08, 0x8E);
  idt_set_entry(13,(unsigned int) isr13, 0x08, 0x8E);
  idt_set_entry(14,(unsigned int) isr14, 0x08, 0x8E);
  idt_set_entry(15,(unsigned int) isr15, 0x08, 0x8E);
  idt_set_entry(16,(unsigned int) isr16, 0x08, 0x8E);
  idt_set_entry(17,(unsigned int) isr17, 0x08, 0x8E);
  idt_set_entry(18,(unsigned int) isr18, 0x08, 0x8E);
  idt_set_entry(19,(unsigned int) isr19, 0x08, 0x8E);
  idt_set_entry(20,(unsigned int) isr20, 0x08, 0x8E);
  idt_set_entry(21,(unsigned int) isr21, 0x08, 0x8E);
  idt_set_entry(22,(unsigned int) isr22, 0x08, 0x8E);
  idt_set_entry(23,(unsigned int) isr23, 0x08, 0x8E);
  idt_set_entry(24,(unsigned int) isr24, 0x08, 0x8E);
  idt_set_entry(25,(unsigned int) isr25, 0x08, 0x8E);
  idt_set_entry(26,(unsigned int) isr26, 0x08, 0x8E);
  idt_set_entry(27,(unsigned int) isr27, 0x08, 0x8E);
  idt_set_entry(28,(unsigned int) isr28, 0x08, 0x8E);
  idt_set_entry(29,(unsigned int) isr29, 0x08, 0x8E);
  idt_set_entry(30,(unsigned int) isr30, 0x08, 0x8E);
  idt_set_entry(31,(unsigned int) isr31, 0x08, 0x8E);

  // Set IDT Metadata.
  idt.limit   = (sizeof(idt_entry_t) * IDT_NUM_ENTRIES) - 1;
  idt.address = (unsigned int)&idt_entries;

  // Load the table.
  lidt((unsigned int)&idt);

}

void idt_set_entry(int pos, unsigned int offset, unsigned short selector, 
  unsigned char flags) {

  idt_entries[pos].offset_0_15  = offset & 0xFFFF;
  idt_entries[pos].offset_16_31 = (offset >> 16) & 0xFFFF;
  idt_entries[pos].selector     = selector;
  idt_entries[pos].reserved     = 0;
  // @todo Uncomment OR below when we get to user-mode.
  // It sets the interrupt gate's level to 3.
  idt_entries[pos].flags        = flags /* | 0x60 */;

}

void interrupt_handler(cpu_state_t cpu, stack_state_t stack,
  unsigned int interrupt) {

  char s[] = "\nReceived Interrupt";
  fb_write(s, sizeof(s) - 1);

}