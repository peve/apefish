/**
 * Diagnostic functions such support for early printing.
 */

#include <types.h>

#define UART_BASE           0xB1100003
#define UART_THR            (UART_BASE + 0x0)        /* transmit hold register */
#define UART_LSR            (UART_BASE + 0x5*4)      /* line status register */
#define UART_LSR_THRE       0x20                     /* transmit hold register empty flag */

static void
serial_put(char c)
{
  volatile uint8_t* uart_lsr = (volatile uint8_t*) UART_LSR;
  volatile uint8_t* uart_tx = (volatile uint8_t*) UART_THR;

  while ((*uart_lsr & UART_LSR_THRE) == 0x0);
  *uart_tx = c;
}

static void
serial_puts(char *str)
{
  for (; *str != '\0'; str++)
  {
    if (*str == '\n')
      serial_put('\r');

    serial_put(*str);
  }
}

void
diag_puts(char *str)
{
  serial_puts(str);
}

void
diag_init(void)
{
  /* for now we assume that the boot loader (eg RedBoot)
     left the serial device in a sanestate */

  /* TODO: basic serial device init */
}
