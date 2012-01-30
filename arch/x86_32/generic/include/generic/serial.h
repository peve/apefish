/**
 *
 */
#ifndef __APEFISH_X86_GENERIC_SERIAL__
#define __APEFISH_X86_GENERIC_SERIAL__

#include <types.h>

/* TODO: cleanup this */
#define PORT 0x3f8   /* COM1 */

#define UART_BASE           0x3f8 /* COM1 */
#define UART_THR            (UART_BASE + 0x0)        /* transmit hold register */
#define UART_LSR            (UART_BASE + 0x5)        /* line status register */
#define UART_LSR_THRE       0x20                     /* transmit hold register empty flag */


void serial_init(void);
void serial_tx(char ch);
char serial_rx(void);

#endif /* __APEFISH_X86_GENERIC_SERIAL__ */
