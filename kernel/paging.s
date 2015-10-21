global lgdt ; makes label lgdt available outside this file
global gdt_reload ; makes label gdt_reload available outside this file

; lgdt - load the global descriptor table (GDT)
; stack: [esp + 4] GDT descriptor
;        [esp    ] The return address
lgdt:
  mov eax, [esp + 4] ; get GDT descriptor
  lgdt [eax]         ; load the table - tells computer where GDT lives
  ret                ; return to calling function

; gdt_reload - reload segment selector registers
gdt_reload:
  mov ax, 0x10
  mov ds, ax
  mov ss, ax
  mov es, ax
  mov gs, ax
  mov fs, ax
  jmp 0x08:.flush_cs
  .flush_cs
    ret