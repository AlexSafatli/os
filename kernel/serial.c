#include "serial.h"

void serial_init(unsigned short com) {
  serial_config_bit_rate(com, 1);
  serial_config_line(com);
  serial_config_buffer(com);
  serial_config_modem(com);
}

void serial_config_bit_rate(unsigned short com, unsigned short divisor) {
  outb(SERIAL_LINE_COMMAND_PORT(com),SERIAL_LINE_ENABLE_DLAB); // Enable DLAB.
  outb(SERIAL_DATA_PORT(com), (divisor >> 8) & 0x00FF); // Highest 8 bits first.
  outb(SERIAL_DATA_PORT(com), (divisor) & 0x00FF); // Lowest 8 bits next.
}

void serial_config_line(unsigned short com) {
  /* Default will be 8 bits length (1 byte), no parity, 1 stop bit, 
  * break control disabled. This is 0x03. */
  outb(SERIAL_LINE_CMD_PORT(com), SERIAL_LINE_DEFAULT);
}

void serial_config_buffer(unsigned short com) {
  /* The default value by convention, for now, will be
  * one which enables the FIFO, clears both buffers and
  * uses 14 bytes of size, i.e. 0xC7.
  */
  outb(SERIAL_FIFO_CMD_PORT(com), SERIAL_BUFFER_DEFAULT);
}

void serial_config_modem(unsigned short com) {
  /* Default will be (RTS = 1 and DTS = 1). */
  outb(SERIAL_MODEM_CMD_PORT(com), SERIAL_MODEM_DEFAULT);
}

int serial_is_transmit_fifo_empty(unsigned short com) {
  return inb(SERIAL_LINE_STATUS_PORT(com)) & 0x20; // 0x20 = 0010 0000
}