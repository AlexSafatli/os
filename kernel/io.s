global outb ; makes label outb available outside this file

; outb - send some byte to an I/O port
; stack: [esp + 8] - data byte
; 		 [esp + 4] - I/O port
;        [esp    ] return address
outb:
	mov al, [esp + 8] ; moves data to be sent into al register
	mov dx, [esp + 4] ; move address of port into dx register
	out dx, al        ; send data to I/O port
	ret               ; return to calling function