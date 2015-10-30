global lgdt          ; makes label lgdt available outside this file

; lgdt - load the global descriptor table (GDT)
; stack: [esp + 4] GDT descriptor
;        [esp    ] The return address
lgdt:
  mov eax, [esp + 4] ; get GDT descriptor
  lgdt [eax]         ; load the table - tells computer where GDT lives
  mov ax, 0x10       ; reload segment selector registers
  mov ds, ax         ;
  mov ss, ax         ;
  mov es, ax         ;
  mov gs, ax         ;
  mov fs, ax         ;
  jmp 0x08:.flush    ; code segment needs to be reloaded with far jump
.flush:              ;
  ret                ; return to calling function