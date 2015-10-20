global lgdt ; makes label lgdt available outside this file
global rlsr ; makes label rlsr available outside this file

; lgdt - load the global descriptor table (GDT)
; stack: [esp + 4] GDT descriptor
;        [esp    ] The return address
lgdt:
  mov eax, [esp + 4] ; get GDT descriptor
  lgdt [eax]         ; load the table
  ret                ; return to calling function

; rlsr - reload segment selector registers
rlsr:
  jmp 0x08:.flush_cs
  .flush_cs
    mov ax, 0x10
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov gs, ax
    mov fs, ax
    ret