/**
 * Kernel main file.
 */
#include <lib/io.h>

/*
 * Kernel entry point.
 */
void
main(void)
{
  print("Apefish OS!\n");

  /* ISR test */
  asm volatile ("int $0x1");

  print("Back on track\n");

  /* TODO: scheduling */
  
  /* TODO: replace with process scheduler and idle process */
  while(1);

  /* should never end up here */
}
