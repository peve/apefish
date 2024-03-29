/**
 * Interface for basic a hardware abstraction layer.
 */
#ifndef __APEFISH_HAL__
#define __APEFISH_HAL__

#include <generic/serial.h>

/*void
hal_interrupt_install_handler(uint8_t n, intr_handler_t handler)
{
  isr_install_handler(n, handler);
}*/

/*
 * Transmits character on serial line.
 */
void
hal_serial_tx(char ch)
{
  serial_tx(ch);
}

/*
 * Receive character from serial line.
 */
char
hal_serial_rx(void)
{
  return serial_rx();
}

#endif /* __APEFISH_HAL__ */
