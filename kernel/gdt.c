#include "gdt.h"

void gdt_init() {
  // Do stuff.
  rlsr(); // Reload segment registers.
}