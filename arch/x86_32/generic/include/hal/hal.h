/**
 * Interface for basic a hardware abstraction layer.
 */
#ifndef __APEFISH_HAL__
#define __APEFISH_HAL__

#include <generic/serial.h>



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
