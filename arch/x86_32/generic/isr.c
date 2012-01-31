/**
 *
 */
#include <generic/isr.h>
#include <generic/idt.h>
#include <lib/io.h>

/*
Documentation:
Intel 64 and IA-32 Architectures
Software Developer's Manual
Volume 3A: System Programming Guide, Part 1
*/

/* Assembler ISR stubs (will call isr_handler) */
extern void isr_stub0(void);
extern void isr_stub1(void);
extern void isr_stub2(void);
extern void isr_stub3(void);
extern void isr_stub4(void);
extern void isr_stub5(void);
extern void isr_stub6(void);
extern void isr_stub7(void);
extern void isr_stub8(void);
extern void isr_stub9(void);
extern void isr_stub10(void);
extern void isr_stub11(void);
extern void isr_stub12(void);
extern void isr_stub13(void);
extern void isr_stub14(void);
extern void isr_stub15(void);
extern void isr_stub16(void);
extern void isr_stub17(void);
extern void isr_stub18(void);
extern void isr_stub19(void);
extern void isr_stub20(void);
extern void isr_stub21(void);
extern void isr_stub22(void);
extern void isr_stub23(void);
extern void isr_stub24(void);
extern void isr_stub25(void);
extern void isr_stub26(void);
extern void isr_stub27(void);
extern void isr_stub28(void);
extern void isr_stub29(void);
extern void isr_stub30(void);
extern void isr_stub31(void);


char *cpu_interrupts[] =
{
  "Divide Error",
  "Reserved",
  "NMI Interrupt",
  "Breakpoint",
  "Overflow",
  "BOUND Range Exceeded",
  "Invalid Opcode",
  "Device Not Available (No Math Coprocessor)",
  "Double Fault",
  "Coprocessor Segment Overrun",
  "Invalid TSS",
  "Segment Not Present",
  "Stack-Segment Fault",
  "General Protection Fault",
  "Page Fault",
  "Reserved",
  "x87 FPU Floating-Point Error (Math Fault)",
  "Alignment Check",
  "Machine Check",
  "SIMD Floating-Point Exception",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved"
};

/*
 * Common ISR interrupt handler.
 */
void
isr_handler(intr_regs_t *regs)
{
  print("Interrupt received: ");
  print(cpu_interrupts[regs->int_no]);
  print("\n");

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
  idt_set_desc(0,  (uint32_t) isr_stub0, 0x08, 0x8e);
  idt_set_desc(1,  (uint32_t) isr_stub1, 0x08, 0x8e);
  idt_set_desc(2,  (uint32_t) isr_stub2, 0x08, 0x8e);
  idt_set_desc(3,  (uint32_t) isr_stub3, 0x08, 0x8e);
  idt_set_desc(4,  (uint32_t) isr_stub4, 0x08, 0x8e);
  idt_set_desc(5,  (uint32_t) isr_stub5, 0x08, 0x8e);
  idt_set_desc(6,  (uint32_t) isr_stub6, 0x08, 0x8e);
  idt_set_desc(7,  (uint32_t) isr_stub7, 0x08, 0x8e);
  idt_set_desc(8,  (uint32_t) isr_stub8, 0x08, 0x8e);
  idt_set_desc(9,  (uint32_t) isr_stub9, 0x08, 0x8e);
  idt_set_desc(10, (uint32_t) isr_stub10, 0x08, 0x8e);
  idt_set_desc(11, (uint32_t) isr_stub11, 0x08, 0x8e);
  idt_set_desc(12, (uint32_t) isr_stub12, 0x08, 0x8e);
  idt_set_desc(13, (uint32_t) isr_stub13, 0x08, 0x8e);
  idt_set_desc(14, (uint32_t) isr_stub14, 0x08, 0x8e);
  idt_set_desc(15, (uint32_t) isr_stub15, 0x08, 0x8e);
  idt_set_desc(16, (uint32_t) isr_stub16, 0x08, 0x8e);
  idt_set_desc(17, (uint32_t) isr_stub17, 0x08, 0x8e);
  idt_set_desc(18, (uint32_t) isr_stub18, 0x08, 0x8e);
  idt_set_desc(19, (uint32_t) isr_stub19, 0x08, 0x8e);
  idt_set_desc(20, (uint32_t) isr_stub20, 0x08, 0x8e);
  idt_set_desc(21, (uint32_t) isr_stub21, 0x08, 0x8e);
  idt_set_desc(22, (uint32_t) isr_stub22, 0x08, 0x8e);
  idt_set_desc(23, (uint32_t) isr_stub23, 0x08, 0x8e);
  idt_set_desc(24, (uint32_t) isr_stub24, 0x08, 0x8e);
  idt_set_desc(25, (uint32_t) isr_stub25, 0x08, 0x8e);
  idt_set_desc(26, (uint32_t) isr_stub26, 0x08, 0x8e);
  idt_set_desc(27, (uint32_t) isr_stub27, 0x08, 0x8e);
  idt_set_desc(28, (uint32_t) isr_stub28, 0x08, 0x8e);
  idt_set_desc(29, (uint32_t) isr_stub29, 0x08, 0x8e);
  idt_set_desc(30, (uint32_t) isr_stub30, 0x08, 0x8e);
  idt_set_desc(31, (uint32_t) isr_stub31, 0x08, 0x8e);
}
