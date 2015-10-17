ENTRY(loader) /* name of entry label */
SECTIONS {
	. = 0x00100000; /* load at 1 MB */
	.text ALIGN (0x1000) : /* align at 4KB */
	{
		*(.text) /* text section from file(s) */
	}
	.rodata ALIGN (0x1000) :
	{
		*(.rodata*) /* all read-only data sections */
	}
	.data ALIGN (0x1000) :
	{
		*(.data) /* data sections */
	}
	.bss ALIGN (0x1000) :
	{
		*(COMMON)
		*(.bss)
	}
}