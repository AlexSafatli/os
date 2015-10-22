#ifndef KERNEL_H
#define KERNEL_H

#include "framebuffer.h"
#include "serial.h"
#include "gdt.h"

void clear();
void kernel_init();

#endif