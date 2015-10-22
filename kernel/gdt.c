/* gdt.c
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

#include "gdt.h"

void gdt_init() {
  // Do stuff.
  gdt_reload(); // Reload segment registers.
}