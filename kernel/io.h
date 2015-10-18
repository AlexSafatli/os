#ifndef IO_H
#define IO_H

// Send given data to given I/O port. Defined in io.s.
void outb(unsigned short port, unsigned char data);

#endif