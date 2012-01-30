/**
 *
 */
#ifndef __APEFISH_X86_GENERIC_ISR__
#define __APEFISH_X86_GENERIC_ISR__

#include <types.h>
#include <generic/idt.h> /* for intr_handler_t */

void isr_init(void);
void isr_install_handler(uint8_t n, intr_handler_t handler);
void isr_uninstall_handler(uint8_t n);

#endif /* __APEFISH_X86_GENERIC_ISR__ */
