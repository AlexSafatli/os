#ifndef INTERRUPTS_H
#define INTERRUPTS_H

void interrupt_handler(cpu_state_t cpu, stack_state_t stack, unsigned int interrupt);

#endif