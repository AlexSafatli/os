#include "timer.h"
#include "io.h"

static void timer(cpu_state_t cpu, stack_state_t stack) {

  (void) cpu; (void) stack;
  // @todo Implement

}

void timer_init(unsigned int freq) {
  
  interrupt_install(PIC1_START, &timer);
  unsigned int divisor = PIT_CLOCK_SPEED / freq;
  outb(PIT_CMD_PORT, PIT_REPEAT);
  outb(PIT_DATA_PORT1, divisor & 0xFF);
  outb(PIT_DATA_PORT1, (divisor >> 8) & 0xFF);

}