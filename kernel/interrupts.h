/* interrupts.h 
* Author: Alex Safatli
* Interrupt handler prototypes and definitions necessary for interfacing with 
* the programmable interrupt controller (PIC) in the architecture. As this is 
* architecture dependent, some of the definitions for the PIC are found in the
* appropriate architecture header file (x86.h).
*/

#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include "x86.h"
#include "io.h"

// General Interrupt Handler and Interrupt Request Handler
void interrupt_handler(cpu_state_t cpu, stack_state_t stack, 
  unsigned int interrupt);
void interrupt_request_handler(cpu_state_t cpu, stack_state_t stack, 
  unsigned int interrupt);

// Load IDT Instruction
void lidt(unsigned int ptr);

// Specific Interrupt Handlers
void isr0();
void isr1();
void isr2();
void isr3();
void isr4();
void isr5();
void isr6();
void isr7();
void isr8();
void isr9();
void isr10();
void isr11();
void isr12();
void isr13();
void isr14();
void isr15();
void isr16();
void isr17();
void isr18();
void isr19();
void isr20();
void isr21();
void isr22();
void isr23();
void isr24();
void isr25();
void isr26();
void isr27();
void isr28();
void isr29();
void isr30();
void isr31();

// Specific IRQ Handlers for PIC
void irq0();
void irq1();
void irq2();
void irq3();
void irq4();
void irq5();
void irq6();
void irq7();
void irq8();
void irq9();
void irq10();
void irq11();
void irq12();
void irq13();
void irq14();
void irq15();

#endif