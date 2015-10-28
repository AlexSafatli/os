/* idt.h 
* Author: Alex Safatli
* An interrupt descriptor table (IDT) is a table telling the processor where
* defined handler functions are located in memory that will handle respective
* interrupts.
*
*/

#ifndef IDT_H
#define IDT_H

#include <string.h>
#include "interrupts.h"

// Table Pointer Structure
typedef struct idt_ptr {
  unsigned short limit;
  unsigned int address; // address of IDT entries
} __attribute__((packed)) idt_ptr_t;

// Table Entry
typedef struct idt_entry {
  unsigned short offset_0_15;
  unsigned short selector;
  unsigned char reserved; // always 0
  unsigned char flags;
  unsigned short offset_16_31;
} __attribute__((packed)) idt_entry_t;

// Entry Definitions
#define IDT_NUM_ENTRIES 256

/* Initialize all logic for managing the GDT. */
void idt_init();

/* Set an entry in the GDT. */
void idt_set_entry(int pos, unsigned int offset, unsigned short selector, 
  unsigned char flags);

#endif