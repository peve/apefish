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
  asm volatile ("int $0x4");

  int a = 2;
  int b = 0;
  int c = a/b;

  print("Back on track\n");


  /* TODO: replace with process scheduler and idle process */
  while(1);

  /* should never end up here */
}
