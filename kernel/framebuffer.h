/* framebuffer.h
* Author: Alex Safatli
* Driver for writing to framebuffer (buffer of memory on screen).
* Part of toy operating system wrote while reading LOS.
* See LOS4.2.1.
*/

#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include "io.h"

// VGA Text Mode Buffer
#define FB_BUFFER 0xB8000

// Dimensions
#define FB_TERMINAL_HEIGHT 24
#define FB_TERMINAL_WIDTH 80
#define FB_NUM_CELLS (FB_TERMINAL_HEIGHT*FB_TERMINAL_WIDTH)

// Colors
#define FB_BLACK 0
#define FB_BLUE 1
#define FB_GREEN 2
#define FB_CYAN 3
#define FB_RED 4
#define FB_MAGENTA 5
#define FB_BROWN 6
#define FB_LIGHT_GREY 7
#define FB_DARK_GREY 8
#define FB_LIGHT_BLUE 9
#define FB_LIGHT_GREEN 10
#define FB_LIGHT_CYAN 11
#define FB_LIGHT_RED 12
#define FB_LIGHT_MAGENTA 13
#define FB_LIGHT_BROWN 14
#define FB_WHITE 15

// I/O Ports
#define FB_CMD_PORT 0x3D4
#define FB_DATA_PORT 0x3D5

// I/O Port Commands
#define FB_HIGH_BYTE_CMD 14
#define FB_LOW_BYTE_CMD 15

/* Framebuffer Struct */
struct framebuffer {
	char c;
	unsigned char colors;
} __attribute__((packed));

void fb_init();
void fb_write_cell(unsigned int pos, char c, unsigned char fg, unsigned char bg);
void fb_move_cursor(unsigned short pos);
void fb_write(char *buf, unsigned int len);

#endif