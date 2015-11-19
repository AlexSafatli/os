/* x86.h 
* Author: Alex Safatli
* x86-specific Structure Definitions. These include those for CPU and Stack 
* states, and for the programmable interrupt controller (PIC).
*/

#ifndef X86_H
#define X86_H

#include "io.h"

// CPU State (Registers, Data Segment)
typedef struct cpu_state {
  unsigned int ds;
  unsigned int edi, esi, ebp, esp;
  unsigned int ebx, edx, ecx, eax;
} cpu_state_t;

// Stack State
typedef struct stack_state {
  unsigned int interrupt;
  unsigned int error_code;
  unsigned int eip;
  unsigned int cs;
  unsigned int eflags;
} stack_state_t;

// PIC x86-specific Definitions
#define PIC1 0x20          /* IO Base Address for Master */
#define PIC2 0xA0          /* IO Base Address for Slave  */
#define PIC1_CMD PIC1
#define PIC2_CMD PIC2
#define PIC1_DATA (PIC1 + 1)
#define PIC2_DATA (PIC2 + 1)
#define PIC1_START 0x20                  /* Start at 32 */
#define PIC2_START 0x28                  /* Start at 40 */
#define PIC2_END  (PIC2_START + 7)         /* End at 47 */
#define PIC_EOI 0x20   /* End of Interrupt Command, ACK */

/* Acknowledges an interrupt from either PIC1 or PIC2. */
void pic_send_eoi(unsigned char irq);
/* Initializes the PICs by remapping them to another interval (LOS 6.6). */
void pic_init();

#endif