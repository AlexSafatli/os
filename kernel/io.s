; =============================================================================
; os
; AlexSafatli
;
; Oct 2015
;
; I/O Port Functions
; =============================================================================

global outb ; makes label outb available outside this file
global inb  ; make label inb available outside this file

; outb - send some byte to an I/O port
; stack: [esp + 8] Data byte
; 		   [esp + 4] The address of I/O port
;        [esp    ] The return address
outb:
	mov al, [esp + 8] ; moves data to be sent into al register
	mov dx, [esp + 4] ; move address of port into dx register
	out dx, al        ; send data to I/O port
	ret               ; return to calling function

; inb - returns a byte from the given I/O port
; stack: [esp + 4] The address of the I/O port
;        [esp    ] The return address
inb:
  mov dx, [esp + 4] ; move address of I/O port into dx register
  in al, dx         ; read byte from I/O port and store into al register
  ret               ; return the read byte