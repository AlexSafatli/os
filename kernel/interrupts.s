extern interrupt_handler                  ; C function to handle interrupt
extern interrupt_ack                      ; C function to handle requests

global lidt
; lidt - load the interrupt descriptor table (IDT)
; stack: [esp + 4] Address of firsty entry in IDT
;        [esp    ] The return address
lidt:
  mov eax, [esp + 4]                      ; get first entry address
  lidt [eax]                              ; load the table
  ret                                     ; return to calling function

%macro no_error_code_interrupt_handler 1
global isr%1
isr%1:
  cli
  push dword 0                            ; unsigned integer error code 0
  push dword %1                           ;                  interrupt number
  jmp isr_common                          ; common interrupt handler code
%endmacro

%macro error_code_interrupt_handler 1
global isr%1
isr%1:
  cli
  push dword %1                           ; unsigned integer interrupt number
  jmp isr_common                          ; common interrupt handler code
%endmacro

%macro interrupt_request 2
global irq%2
irq%2:
  cli
  push dword 0                            ; unsigned integer error code 0
  push dword %1                           ; unsigned integer interrupt number
  jmp irq_common                          ; common interrupt request code
%endmacro

isr_common:                               ;
  pusha                                   ; save registers
  mov ax, ds                              ; lower 16 bits of eax = ds
  push eax                                ; save data segment descriptor
  mov ax, 0x10                            ; load kernel data segment descriptor
  mov ds, ax                              ;
  mov es, ax                              ;
  mov fs, ax                              ;
  mov gs, ax                              ;
  call interrupt_handler                  ; call C function to handle interrupt
  pop ebx                                 ; reload original ds descriptor
  mov ds, bx                              ; 
  mov es, bx                              ;
  mov fs, bx                              ;
  mov gs, bx                              ;
  popa                                    ; reload registers
  add esp, 8                              ; restore esp
  sti                                     ;
  iret                                    ; return to interrupted code

irq_common:                               ;
  pusha                                   ; save registers
  mov ax, ds                              ; lower 16 bits of eax = ds
  push eax                                ; save data segment descriptor
  mov ax, 0x10                            ; load kernel data segment descriptor
  mov ds, ax                              ;
  mov es, ax                              ;
  mov fs, ax                              ;
  mov gs, ax                              ;
  call interrupt_handler                  ; call C function to handle interrupt
  call interrupt_ack                      ; call C function to acknowledge irq
  pop ebx                                 ; reload original ds descriptor
  mov ds, bx                              ; 
  mov es, bx                              ;
  mov fs, bx                              ;
  mov gs, bx                              ;
  popa                                    ; reload registers
  add esp, 8                              ; restore esp
  sti                                     ;
  iret                                    ; return to interrupted code 

no_error_code_interrupt_handler 0
no_error_code_interrupt_handler 1
no_error_code_interrupt_handler 2
no_error_code_interrupt_handler 3
no_error_code_interrupt_handler 4
no_error_code_interrupt_handler 5
no_error_code_interrupt_handler 6
no_error_code_interrupt_handler 7
error_code_interrupt_handler    8
no_error_code_interrupt_handler 9
error_code_interrupt_handler    10
error_code_interrupt_handler    11
error_code_interrupt_handler    12
error_code_interrupt_handler    13
error_code_interrupt_handler    14
no_error_code_interrupt_handler 15
no_error_code_interrupt_handler 16
no_error_code_interrupt_handler 17
no_error_code_interrupt_handler 18
no_error_code_interrupt_handler 19
no_error_code_interrupt_handler 20
no_error_code_interrupt_handler 21
no_error_code_interrupt_handler 22
no_error_code_interrupt_handler 23
no_error_code_interrupt_handler 24
no_error_code_interrupt_handler 25
no_error_code_interrupt_handler 26
no_error_code_interrupt_handler 27
no_error_code_interrupt_handler 28
no_error_code_interrupt_handler 29
no_error_code_interrupt_handler 30
no_error_code_interrupt_handler 31
interrupt_request               32, 0
interrupt_request               33, 1
interrupt_request               34, 2
interrupt_request               35, 3
interrupt_request               36, 4
interrupt_request               37, 5
interrupt_request               38, 6
interrupt_request               39, 7
interrupt_request               40, 8
interrupt_request               41, 9
interrupt_request               42, 10
interrupt_request               43, 11
interrupt_request               44, 12
interrupt_request               45, 13
interrupt_request               46, 14
interrupt_request               47, 15