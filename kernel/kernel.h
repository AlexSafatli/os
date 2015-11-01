/* kernel.h 
* Author: Alex Safatli
* Entry point to kernel.
*/

#ifndef KERNEL_H
#define KERNEL_H

#include "framebuffer.h"
#include "serial.h"
#include "gdt.h"
#include "idt.h"

void kernel_init();

#endif