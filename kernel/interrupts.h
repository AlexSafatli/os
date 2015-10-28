#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include "x86.h"

void interrupt_handler(cpu_state_t cpu, stack_state_t stack, unsigned int interrupt);
void lidt(unsigned int ptr);

#endif