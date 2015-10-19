#ifndef SERIAL_H
#define SERIAL_H

#include "io.h"

// I/O Ports
/* All I/O ports are calculated relative to data port. This is because all
* serial ports (COM1, COM2, COM3, COM4) have their ports in same order, but
* they all start at different values.
*/

#define SERIAL_COM1 0x3F8 /* COM1 Base Port */
#define SERIAL_COM2 0x2F8 /* COM2 Base Port */
#define SERIAL_COM3 0x3E8 /* COM3 Base Port (Less Reliable) */
#define SERIAL_COM4 0x2E8 /* COM4 Base Port (Less Reliable) */

#define SERIAL_DATA_PORT(base) (base)
#define SERIAL_FIFO_CMD_PORT(base) (base+2)
#define SERIAL_LINE_CMD_PORT(base) (base+3)
#define SERIAL_MODEM_CMD_PORT(base) (base+4)
#define SERIAL_LINE_STATUS_PORT(base) (base+5)

// I/O Port Commands

#define SERIAL_LINE_ENABLE_DLAB 0x80 /* Tells port to expect highest 8 bits. */
#define SERIAL_LINE_DEFAULT 0x03 /* Default value for line config. */
#define SERIAL_BUFFER_DEFAULT 0xC7 /* Default value for buffer config. */
#define SERIAL_MODEM_DEFAULT 0x03 /* Default value for modem config. */

/* Initializes a serial port, performing all default configurations. */
void serial_init(unsigned short com);

/* Sets speed of data being sent to serial port. Default speed is 115200 bits/s.
*  The argument is a divisor of that number, hence the resulting speed becomes
*  (115200 / divisor) bit/s.
*/
void serial_config_bit_rate(unsigned short com, unsigned short divisor);

/* Line Configuration (LOSB 4.3.2)
* Bit     | 7 | 6 | 5 4 3 | 2 | 1 0 |
* Content | d | b | prty  | s | dl  |

| d    | Enables (d = 1) or disables (d = 0) DLAB
| b    | If break control is enabled (b = 1) or disabled (b = 0)
| prty | The number of parity bits to use
| s    | The number of stop bits to use (s = 0 equals 1, s = 1 equals 1.5 or 2)
| dl   | Describes the length of the data
*/
void serial_config_line(unsigned short com);

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
void serial_config_buffer(unsigned short com);

/* Modem Configuration (LOSB 4.3.4)
* Bit     | 7 | 6 | 5  | 4  | 3   | 2   | 1   | 0   |
* Content | r | r | af | lb | ao2 | ao1 | rts | dtr |

| r   | Reserved
| af  | Autoflow control enabled
| lb  | Loopback mode (used for debugging serial ports)
| ao2 | Auxiliary output 2, used for receiving interrupts
| ao1 | Auxiliary output 1
| rts | Ready To Transmit
| dtr | Data Terminal Ready
*/
void serial_config_modem(unsigned short com);

/* Returns whether transmit FIFO queue is empty or not for a COM port. */
int serial_is_transmit_fifo_empty(unsigned short com);

#endif