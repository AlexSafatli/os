# os

## Kernel

The **kernel** is the part of the operating system that remains loaded at all 
times in memory. This is abstracted as an entry point function (`kernel_init`) 
that loads a series of subsequent drivers that allow abstraction between the
operating system and a number of basic hardware components.

## Drivers

Drivers are defined for the following hardware components.

  - The **framebuffer** (`framebuffer.h` - LOS3),
  - **Serial ports** (`serial.h` - LOS4)

## Segmentation

Segmentation allows accessing memory through **segments** (i.e., portions of 
the address space, that may overlap, specified by a *base address* and some
*limit*). As suggested in LOS, segmentation is enabled in this kernel by the
description of a **Global Descriptor Table** (GDT) that is shared by all 
possible processes. This table is defined in `gdt.h` and implemented in `gdt.c`.