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