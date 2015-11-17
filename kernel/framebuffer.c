#include "framebuffer.h"

// Pointer to framebuffer, current color, cursor index.
static struct framebuffer *fb;
static unsigned char curr_color = FB_BLACK | FB_WHITE;
static unsigned short cursor_pos = 0;

// Initialize the framebuffer.
void fb_init() {
	fb = (struct framebuffer*) FB_BUFFER;
}

// Clear the framebuffer.
void fb_clear() {
	int i;
	for (i = 0; i < FB_NUM_CELLS; ++i) fb_putc(0x20);
}

// Write a character with a foreground and background at position pos in buffer.
void fb_write_cell(unsigned int pos, char c, unsigned char fg, 
	unsigned char bg) {
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

// Write a single character to the screen from wherever the cursor is.
void fb_putc(char c) {
	fb_write_cell(cursor_pos, c, curr_color & 0xF0, curr_color & 0x0F);
	cursor_pos = (cursor_pos + 1) % FB_NUM_CELLS;
	fb_move_cursor(cursor_pos);
}

// Write the contents of a buffer of length len to the screen. Should 
// automatically advance the cursor after a character has been written, and 
// scroll if necessary.
void fb_puts(char *buf, unsigned int len) {
	unsigned int i;
	for (i = 0; i < len; ++i) {
		fb_write_cell(cursor_pos, buf[i], curr_color & 0xF0, curr_color & 0x0F);
		cursor_pos = (cursor_pos + 1) % FB_NUM_CELLS;
	}
	fb_move_cursor(cursor_pos);
}

// Write a positive decimal integer to the screen.
void fb_putui(unsigned int i) {
	if (i == 0) {
		fb_putc('0');
		return;
	}
	int k = 0;
	int n = i;
	char c[32];
	while (n > 0) { 
		c[k] = '0' + n % 10;
		n /= 10;
		++k;
	}
	c[k] = 0;
	char w[32];
	w[k--] = 0;
	int j = 0;
	while (k >= 0) w[k--] = c[j++];
	fb_write(w);
}

// Write a null-terminated string to the monitor.
void fb_write(char *str) {
	unsigned int i;
	i = 0;
	while (str[i] != '\0') {
		fb_write_cell(cursor_pos, str[i++], curr_color & 0xF0, curr_color & 0x0F);
		cursor_pos = (cursor_pos + 1) % FB_NUM_CELLS;
	}
	fb_move_cursor(cursor_pos);
}