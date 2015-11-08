#include "timer.h"
#include "io.h"

static void timer(cpu_state_t cpu, stack_state_t stack) {

  (void) cpu; (void) stack;
  // @todo Implement

}

void timer_init(unsigned int freq) {
  
  interrupt_register(PIC1_START, &timer);
  unsigned int divisor = PIT_CLOCK_SPEED / freq;
  outb(PIT_CMD_PORT, PIT_REPEAT);
  unsigned char low = (unsigned char) (divisor & 0xFF),
                hi  = (unsigned char) ((divisor >> 8) & 0xFF);
  outb(PIT_DATA_PORT1, low);
  outb(PIT_DATA_PORT1, hi);

}