/* idt.c
* Author: Alex Safatli
*/

#include "idt.h"

idt_entry_t idt_entries[IDT_NUM_ENTRIES];
idt_ptr_t   idt;

void idt_init() {
  
  // Set table entries.
  memset(&idt_entries, 0, sizeof(idt_entry_t) * IDT_NUM_ENTRIES);  

  // Set IDT Metadata.
  idt.limit   = (sizeof(idt_entry_t) * IDT_NUM_ENTRIES) - 1;
  idt.address = (unsigned int)&idt_entries;

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