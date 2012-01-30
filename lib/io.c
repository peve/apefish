/**
 *
 */
#include <lib/io.h>
#include <hal/hal.h>

void
print(char *str)
{
  for (; *str != '\0'; str++)
  {
    if (*str == '\n')
      hal_serial_tx('\r');

    hal_serial_tx(*str);
  }
}
