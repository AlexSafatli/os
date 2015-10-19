#ifndef SERIAL_H
#define SERIAL_H

#include "io.h"

// I/O Ports
/* All I/O ports are calculated relative to data port. This is because all
* serial ports (COM1, COM2, COM3, COM4) have their ports in same order, but
* they all start at different values.
*/

#define SERIAL_COM1_BASE 0x3F8 /* COM1 Base Port */
#define SERIAL_COM2_BASE 0x2F8 /* COM2 Base Port */
#define SERIAL_COM3_BASE 0x3E8 /* COM3 Base Port (Less Reliable) */
#define SERIAL_COM4_BASE 0x2E8 /* COM4 Base Port (Less Reliable) */

#define SERIAL_DATA_PORT(base) (base)
#define SERIAL_FIFO_COMMAND_PORT(base) (base+2)
#define SERIAL_LINE_COMMAND_PORT(base) (base+3)
#define SERIAL_MODEM_COMMAND_PORT(base) (base+4)
#define SERIAL_LINE_STATUS_PORT(base) (base+5)

/* Buffer Configuration (LOSB 4.3.3)
* Bit     | 7 6 | 5  | 4 | 3   | 2   | 1   | 0 |
* Content | lvl | bs | r | dma | clt | clr | e |

| lvl | How many bytes should be stored in the FIFO buffers
| bs  | If the buffers should be 16 or 64 bytes large
| r   | Reserved for future use
| dma | How the serial port data should be accessed
| clt | Clear the transmission FIFO buffer
| clr | Clear the receiver FIFO buffer
| e   | If the FIFO buffer should be enabled or not
*/

// I/O Port Commands

#define SERIAL_LINE_ENABLE_DLAB 0x80 /* Tells port to expect highest 8 bits. */

/* Sets speed of data being sent to serial port. Default speed is 115200 bits/s.
*  The argument is a divisor of that number, hence the resulting speed becomes
*  (115200 / divisor) bit/s.
*/
void serial_config_bit_rate(unsigned short com, unsigned short divisor);

#endif