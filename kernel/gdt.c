/* gdt.c
* Author: Alex Safatli
* A GDT is an array of 8-byte segment descriptors.
*/

#include "gdt.h"

gdt_entry_t gdt_entries[GDT_NUM_ENTRIES];
gdt_ptr_t   gdt;

void gdt_init() {
  
  // Set table entries.
  gdt_set_entry(0, 0, 0,             0,    0   ); // Null entry.
  gdt_set_entry(1, 0, GDT_MAX_RANGE, 0x9A, 0xCF); // Code segment.
  gdt_set_entry(2, 0, GDT_MAX_RANGE, 0x92, 0xCF); // Data segment.

  // Set GDT Metadata.
  gdt.address = (unsigned int)&gdt_entries;
  gdt.size = (sizeof(gdt_entry_t) * GDT_NUM_ENTRIES) - 1;
  
  // Load the table.
  lgdt(&gdt);

}

void gdt_set_entry(int pos, unsigned int base, 
  unsigned int limit, unsigned short access, unsigned short flags) {
  
  // Set base.
  gdt_entries[pos].base_0_15  = (base & 0xFFFF);
  gdt_entries[pos].base_16_23 = (base >> 16) & 0xFF;
  gdt_entries[pos].base_24_31 = (base >> 24) & 0xFF;

  // Set limit, flags.
  gdt_entries[pos].limit_0_15 = (limit & 0xFFFF);
  gdt_entries[pos].limit_16_19_and_flags = ((limit >> 16) & 0x0F) | 
                                           (flags & 0xF0);

  // Access
  gdt_entries[pos].access_byte = access;

}