#include "gdt.h"

void gdt_init() {
  // Do stuff.
  gdt_reload(); // Reload segment registers.
}