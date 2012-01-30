/**
 *
 */
#include <generic/serial.h>
#include <generic/gdt.h>
#include <generic/idt.h>
#include <generic/isr.h>
#include <generic/pic.h>
#include <kernel/main.h>

/*
 * Initializes platform hardware and passes control to the kernel.
 * Function is called at boot, after the initial assembler code.
 */
void
platform_init(void)
{
  /* setup basic serial communication */
  serial_init();

  /* setup memory */
  gdt_init();

  /* setup interrupts */
  idt_init();

  isr_init();

  pic_init();

  /* TODO: other important init stuff... */

  /* start the kernel */
  main();
}
