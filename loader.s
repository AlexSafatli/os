global loader                        ; entry symbol for ELF file
MAGIC_NUMBER equ 0x1BADB002          ; magic number constant
FLAGS equ 0x0                        ; multiboot flags
CHECKSUM equ -(MAGIC_NUMBER + FLAGS) ; calculate checksum
                                     ; (magic number + checksum + flags should = 0)
KERNEL_STACK_SIZE equ 4096           ; size of the stack for the kernel in bytes (~4MB)

extern kernel_init                   ; entry point to kernel initialization in C

section .text:                       ; start of text (code)
align 4                              ; code must be 4 byte aligned
  dd MAGIC_NUMBER                    ; write magic number
  dd FLAGS                           ; write flags
  dd CHECKSUM                        ; checksum

loader:                              ; loader label, entry point in linker script
  mov eax, 0xCAFEBABE                ; place number 0xCAFEBABE into eax register
  mov esp, kernel_stack + KERNEL_STACK_SIZE
                                     ; make stack register point to stack
  call kernel_init                   ; initialize kernel
.loop:
  jmp .loop                          ; loop forever

section .bss                         ; start of bss (block started by symbol - statically allocated variables)
align 4                              ; code must be 4 byte aligned
kernel_stack:                        ; label points to beginning of memory
  resb KERNEL_STACK_SIZE             ; reserve the stack