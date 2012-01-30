/**
 *
 */
#ifndef __APEFISH_X86_GENERIC_IDT__
#define __APEFISH_X86_GENERIC_IDT__

#include <types.h>

/*
 * Struct passed to interrupt handlers, containing cpu context.
 */
typedef struct intr_regs
{
  uint32_t ds;                                     /* data segment selector */
  uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax; /* pushed by pusha */
  uint32_t int_no, err_code;                       /* interrupt number and error code (if applicable) */
  uint32_t eip, cs, eflags, useresp, ss;           /* pushed by cpu automatically on intr */
} intr_regs_t;

/*
 * Function prototype for interrupt handlers (IRQs and ISRs).
 */
typedef void (*intr_handler_t) (intr_regs_t *);

void idt_init(void);
void idt_set_desc(uint8_t i, uint32_t base, uint16_t sel, uint8_t flags);

#endif /* __APEFISH_X86_GENERIC_IDT__ */
