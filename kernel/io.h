/* io.h 
* Author: Alex Safatli
* I/O Port Function Prototypes
* @see io.s
*/

#ifndef IO_H
#define IO_H

// Send given data to given I/O port.
void outb(unsigned short port, unsigned char data);

// Read a byte from a given I/O port.
unsigned char inb(unsigned short port);

#endif