/**
 *
 */
#include <generic/isr.h>
#include <generic/idt.h>
#include <lib/io.h>

/* Assembler ISR stubs (will call isr_handler) */
extern void isr_stub0(void);
extern void isr_stub1(void);
extern void isr2_stub(void);
extern void isr3_stub(void);
extern void isr4_stub(void);
extern void isr5_stub(void);
extern void isr6_stub(void);
extern void isr7_stub(void);
extern void isr8_stub(void);
extern void isr9_stub(void);
extern void isr10_stub(void);
extern void isr11_stub(void);
extern void isr12_stub(void);
extern void isr13_stub(void);
extern void isr14_stub(void);
extern void isr15_stub(void);
extern void isr16_stub(void);
extern void isr17_stub(void);
extern void isr18_stub(void);
extern void isr19_stub(void);
extern void isr20_stub(void);
extern void isr21_stub(void);
extern void isr22_stub(void);
extern void isr23_stub(void);
extern void isr24_stub(void);
extern void isr25_stub(void);
extern void isr26_stub(void);
extern void isr27_stub(void);
extern void isr28_stub(void);
extern void isr29_stub(void);
extern void isr30_stub(void);
extern void isr31_stub(void);

/*
 * Common ISR interrupt handler.
 */
void
isr_handler(intr_regs_t *regs)
{
  print("isr_handler\n");
  /* TODO */
}


void
isr_install_handler(uint8_t n, intr_handler_t handler)
{
  /* TODO */
}

void
isr_uninstall_handler(uint8_t n)
{
  /* TODO */
}

/*
 * Setup default exception handlers.
 */
void
isr_init()
{
  /* setup ISR stubs in the IDT */
  idt_set_desc(0, (uint32_t) isr_stub0, 0x08, 0x8e);
  idt_set_desc(1, (uint32_t) isr_stub1, 0x08, 0x8e);
  /* ... */
}
