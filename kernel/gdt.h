/* A GDT (or LDT) is an array of 8-byte segment descriptors. The first one in
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

// Table Data Structure
struct gdt {
  unsigned int address;
  unsigned short size; // of the table
} __attribute__((packed));

// Privilege Levels
#define GDT_PL0 0x0
#define GDT_PL1 0x3

/* Initialize all logic for managing the GDT. */
void gdt_init();

/* Reload all segment registers. */
void gdt_reload();

/* Grab the GDT from the architecture. */
void lgdt(struct gdt g);

#endif