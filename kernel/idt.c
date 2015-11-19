#include "idt.h"
#include <string.h>
#include "framebuffer.h"
interrupt_callback interrupt_vector[IDT_NUM_ENTRIES];
idt_entry_t             idt_entries[IDT_NUM_ENTRIES];
idt_ptr_t                                        idt;

void idt_init() {

  // Clear table entries.
  memset(&interrupt_vector, 0, sizeof(interrupt_callback) * IDT_NUM_ENTRIES);
  memset(&idt_entries,      0, sizeof(idt_entry_t) *        IDT_NUM_ENTRIES);

  // Initialize the PIC.
  pic_init();

  // Set table entries.
  idt_set_entry(0 ,(unsigned int) isr0 , 0x08, 0x8E);
  idt_set_entry(1 ,(unsigned int) isr1 , 0x08, 0x8E);
  idt_set_entry(2 ,(unsigned int) isr2 , 0x08, 0x8E);
  idt_set_entry(3 ,(unsigned int) isr3 , 0x08, 0x8E);
  idt_set_entry(4 ,(unsigned int) isr4 , 0x08, 0x8E);
  idt_set_entry(5 ,(unsigned int) isr5 , 0x08, 0x8E);
  idt_set_entry(6 ,(unsigned int) isr6 , 0x08, 0x8E);
  idt_set_entry(7 ,(unsigned int) isr7 , 0x08, 0x8E);
  idt_set_entry(8 ,(unsigned int) isr8 , 0x08, 0x8E);
  idt_set_entry(9 ,(unsigned int) isr9 , 0x08, 0x8E);
  idt_set_entry(10,(unsigned int) isr10, 0x08, 0x8E);
  idt_set_entry(11,(unsigned int) isr11, 0x08, 0x8E);
  idt_set_entry(12,(unsigned int) isr12, 0x08, 0x8E);
  idt_set_entry(13,(unsigned int) isr13, 0x08, 0x8E);
  idt_set_entry(14,(unsigned int) isr14, 0x08, 0x8E);
  idt_set_entry(15,(unsigned int) isr15, 0x08, 0x8E);
  idt_set_entry(16,(unsigned int) isr16, 0x08, 0x8E);
  idt_set_entry(17,(unsigned int) isr17, 0x08, 0x8E);
  idt_set_entry(18,(unsigned int) isr18, 0x08, 0x8E);
  idt_set_entry(19,(unsigned int) isr19, 0x08, 0x8E);
  idt_set_entry(20,(unsigned int) isr20, 0x08, 0x8E);
  idt_set_entry(21,(unsigned int) isr21, 0x08, 0x8E);
  idt_set_entry(22,(unsigned int) isr22, 0x08, 0x8E);
  idt_set_entry(23,(unsigned int) isr23, 0x08, 0x8E);
  idt_set_entry(24,(unsigned int) isr24, 0x08, 0x8E);
  idt_set_entry(25,(unsigned int) isr25, 0x08, 0x8E);
  idt_set_entry(26,(unsigned int) isr26, 0x08, 0x8E);
  idt_set_entry(27,(unsigned int) isr27, 0x08, 0x8E);
  idt_set_entry(28,(unsigned int) isr28, 0x08, 0x8E);
  idt_set_entry(29,(unsigned int) isr29, 0x08, 0x8E);
  idt_set_entry(30,(unsigned int) isr30, 0x08, 0x8E);
  idt_set_entry(31,(unsigned int) isr31, 0x08, 0x8E);
  idt_set_entry(32,(unsigned int) irq0,  0x08, 0x8E);
  idt_set_entry(33,(unsigned int) irq1,  0x08, 0x8E);
  idt_set_entry(34,(unsigned int) irq2,  0x08, 0x8E);
  idt_set_entry(35,(unsigned int) irq3,  0x08, 0x8E);
  idt_set_entry(36,(unsigned int) irq4,  0x08, 0x8E);
  idt_set_entry(37,(unsigned int) irq5,  0x08, 0x8E);
  idt_set_entry(38,(unsigned int) irq6,  0x08, 0x8E);
  idt_set_entry(39,(unsigned int) irq7,  0x08, 0x8E);
  idt_set_entry(40,(unsigned int) irq8,  0x08, 0x8E);
  idt_set_entry(41,(unsigned int) irq9,  0x08, 0x8E);
  idt_set_entry(42,(unsigned int) irq10, 0x08, 0x8E);
  idt_set_entry(43,(unsigned int) irq11, 0x08, 0x8E);
  idt_set_entry(44,(unsigned int) irq12, 0x08, 0x8E);
  idt_set_entry(45,(unsigned int) irq13, 0x08, 0x8E);
  idt_set_entry(46,(unsigned int) irq14, 0x08, 0x8E);
  idt_set_entry(47,(unsigned int) irq15, 0x08, 0x8E);

  // Set IDT Metadata.
  idt.limit   = (sizeof(idt_entry_t) * IDT_NUM_ENTRIES) - 1;
  idt.address = (unsigned int)&idt_entries;

  // Load the table.
  lidt((unsigned int)&idt);

}

void idt_set_entry(int pos, unsigned int offset, unsigned short selector, 
  unsigned char flags) {

  idt_entries[pos].offset_0_15  = offset & 0xFFFF;
  idt_entries[pos].offset_16_31 = (offset >> 16) & 0xFFFF;
  idt_entries[pos].selector     = selector;
  idt_entries[pos].reserved     = 0;
  // @todo Uncomment OR below when we get to user-mode.
  // It sets the interrupt gate's level to 3.
  idt_entries[pos].flags        = flags /* | 0x60 */;

}

void interrupt_install(int pos, interrupt_callback handler) {

  interrupt_vector[pos] = handler;

}

void interrupt_handler(cpu_state_t cpu, stack_state_t stack,
  unsigned int interrupt) {

  (void)cpu; (void)stack;
  fb_putui(interrupt);
  if (interrupt_vector[interrupt]) interrupt_vector[interrupt](cpu, stack);

}

void interrupt_ack(cpu_state_t cpu, stack_state_t stack,
  unsigned int interrupt) {

  (void)cpu; (void)stack;
  pic_send_eoi(interrupt - PIC1_START);

}