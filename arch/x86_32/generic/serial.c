/**
 *
 */
#include <arch/cpu.h>
#include <generic/serial.h>

/*
 * TODO
 */
void
serial_tx(char ch)
{
  /* wait for transmit register to be ready */
  while ((inb(UART_LSR) & UART_LSR_THRE) == 0x0);

  /* write character */
  outb(UART_THR, ch);
}

/*
 * TODO
 */
char
serial_rx(void)
{
  /* TODO */
  return 0;
}

/*
 * TODO
 */ 
void
serial_init()
{
  outb(PORT + 1, 0x00);    /* disable all interrupts */
  outb(PORT + 3, 0x80);    // Enable DLAB (set baud rate divisor)
  outb(PORT + 0, 0x03);    // Set divisor to 3 (lo byte) 38400 baud
  outb(PORT + 1, 0x00);    //                  (hi byte)
  outb(PORT + 3, 0x03);    // 8 bits, no parity, one stop bit
  outb(PORT + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
  outb(PORT + 4, 0x0B);    // IRQs enabled, RTS/DSR set
}
