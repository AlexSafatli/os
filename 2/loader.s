global loader ; entry symbol for ELF file
MAGIC_NUMBER equ 0x1BADB002 ; magic number constant
FLAGS equ 0x0 ; multiboot flags
CHECKSUM equ -MAGIC_NUMBER ; calculate checksum
                           ; (magic number + checksum + flags should = 0)

section .text: ; start of text (code)
align 4 ; code must be 4 byte aligned
	dd MAGIC_NUMBER ; write magic number
	dd FLAGS ; write flags
	dd CHECKSUM ; checksum

loader: ; loader label, entry point in linker script
	mov eax, 0xCAFEBABE ; place number 0xCAFEBABE into eax register
.loop:
	jmp .loop ; loop forever