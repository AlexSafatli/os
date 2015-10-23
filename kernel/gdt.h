/* gdt.h 
* Author: Alex Safatli
* A GDT (or LDT) is an array of 8-byte segment descriptors. The first one in
* a GDT is a null descriptor (and can never be used to access any sort of
* memory). Segment descriptors have a number of important fields.
*
*  - Base
*  - Limit
*  - Type
*  - DPL (Privilege Levels or PL - x86 allows for 4); DPL=0 is kernel mode.
*      The current privilege level (CPL) is determined by the selector in cs.
*
*/

#ifndef GDT_H
#define GDT_H

// Table Pointer Structure
typedef struct gdt_ptr {
  unsigned int address;
  unsigned short size; // of the table
} __attribute__((packed)) gdt_ptr_t;

// Table Entry (GDT#Structure)
typedef struct gdt_entry { // 8 byte entry
  unsigned short limit_0_15;
  unsigned short base_0_15;
  unsigned char base_16_23;
  unsigned char access_byte;
  unsigned char limit_16_19_and_flags;
  unsigned char base_24_31;
} __attribute__((packed)) gdt_entry_t;

// Privilege Levels
#define GDT_PL0 0x0 /* Kernel Mode */
#define GDT_PL1 0x3

// Entry Definitions
#define GDT_NUM_ENTRIES 3
#define GDT_MAX_RANGE 0xFFFFFFFF

/* Initialize all logic for managing the GDT. */
void gdt_init();

/* Set an entry in the GDT. */
void gdt_set_entry(int pos, unsigned int base, 
  unsigned int limit, unsigned short access, unsigned short flags);

/* Tell the computer where our GDT will be (load it). */
void lgdt(gdt_ptr_t *ptr);

#endif