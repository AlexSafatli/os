/* gdt.c
* Author: Alex Safatli
* A GDT is an array of 8-byte segment descriptors.
*/

#include "gdt.h"

static struct gdt_entry gdt_entries[NUM_GDT_ENTRIES];
static struct gdt gdt_table;

void gdt_init() {
  
  // Set table entries.
  gdt_entries[1].limit_0_15 = GDT_MAX_RANGE & 0xFFFF;
  gdt_entries[1].base_0_15 = GDT_MIN_RANGE & 0xFFFF;
  gdt_entries[1].base_16_23 = (GDT_MIN_RANGE >> 16) & 0xFF;
  gdt_entries[1].access_byte = 0x02 /* Readable */ | 0x8 /* Code */ | 
                              ((GDT_PL0 & 0x3) << 5) | (0x1 << 4) | (0x1 << 7);
  gdt_entries[1].limit_16_19_and_flags = 0;
  gdt_entries[1].base_24_31 = 0;

  gdt_entries[2].limit_0_15 = GDT_MAX_RANGE & 0xFFFF;
  gdt_entries[2].base_0_15 = GDT_MIN_RANGE & 0xFFFF;
  gdt_entries[2].base_16_23 = (GDT_MIN_RANGE >> 16) & 0xFF;
  gdt_entries[2].access_byte = 0x02 /* Readable */ |
                              ((GDT_PL0 & 0x3) << 5) | (0x1 << 4) | (0x1 << 7);
  gdt_entries[2].limit_16_19_and_flags = 0;
  gdt_entries[2].base_24_31 = 0;

  // Set GDT Metadata.  
  gdt.size = (sizeof(struct gdt_entry) * NUM_GDT_ENTRIES) - 1;
  gdt.address = &gdt_entries;
  lgdt(gdt_table); // Load the table.
  gdt_reload(); // Reload segment registers.

}