// framebuffer.c
// Author: Alex Safatli
// Driver for writing to framebuffer (buffer of memory on screen).
// Part of toy operating system wrote while reading littleosbook.
// See 4.2.1 of littleosbook for more information.

#include "framebuffer.h"

// Pointer to framebuffer, current color, cursor index.
static struct framebuffer *fb = {0};
static unsigned char curr_color = FB_BLACK | FB_WHITE;
static unsigned short cursor_pos = 0;

// Initialize the framebuffer.
void fb_init() {
	fb = (struct framebuffer*) 0x000B8000;
}

// Write a character with a foreground and background at position pos in framebuffer.
void fb_write_cell(unsigned int pos, char c, unsigned char fg, unsigned char bg) {
	fb[pos].c = c;
	fb[pos].colors = ((fg & 0x0F) << 4) | (bg & 0x0F);
}

// Move the cursor to a new position in the framebuffer.
void fb_move_cursor(unsigned short pos) {
	outb(FB_CMD_PORT, FB_HIGH_BYTE_CMD);
	outb(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
	outb(FB_CMD_PORT, FB_LOW_BYTE_CMD);
	outb(FB_DATA_PORT, pos & 0x00FF);
}

// Write the contents of a buffer of length len to the screen. Should automatically
// advance the cursor after a character has been written, and scroll if necessary.
void fb_write(char *buf, unsigned int len) {
	unsigned int i;
	unsigned char fg = curr_color & 0xF0, bg = curr_color & 0x0F;
	for (i = 0; i < len; ++i) {
		fb_write_cell(cursor_pos, buf[i], fg, bg);
		cursor_pos = (cursor_pos + 1) % FB_NUM_CELLS;
	}
	fb_move_cursor(cursor_pos);
}