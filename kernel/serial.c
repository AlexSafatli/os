#include "serial.h"

void serial_config_bit_rate(unsigned short com, unsigned short divisor) {
  outb(SERIAL_LINE_COMMAND_PORT(com),SERIAL_LINE_ENABLE_DLAB); // Enable DLAB.
  outb(SERIAL_DATA_PORT(com), (divisor >> 8) & 0x00FF); // Highest 8 bits first.
  outb(SERIAL_DATA_PORT(com), (divisor) & 0x00FF); // Lowest 8 bits next.
}