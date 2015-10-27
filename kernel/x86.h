#ifndef X86_H
#define X86_H

typedef struct cpu_state {
	unsigned int eax, ebx, ecx, edx;
	unsigned int edi, esi, ebp, esp;
} cpu_state_t;

typedef struct stack_state {
  unsigned int error_code;
  unsigned int eip;
  unsigned int cs;
  unsigned int eflags;
} stack_state_t;

#endif