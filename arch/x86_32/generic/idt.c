/**
 *
 */
#include <generic/idt.h>

/* TODO: Merge this file with gdt.[h|c] and call it descriptors.[h|c]? */

/*
 * IDT descriptor.
 */
typedef struct idt_descr
{
  uint16_t base_low;
  uint16_t sel;
  uint8_t  zero;
  uint8_t  flags;
  uint16_t base_high;
} __attribute__((packed)) idt_descr_t;

/*
 * IDT pointer.
 */
typedef struct idt_ptr
{
  uint16_t limit;
  uint32_t base;
} __attribute__((packed)) idt_ptr_t;

/*
 * IDT and its pointer.
 */
#define NUM_IDT_DESCRS 256
idt_descr_t idt[NUM_IDT_DESCRS];
idt_ptr_t idt_ptr;

/* 
 * Assembler function that loads the IDT.
 */
extern void idt_load(void);

/*
 * Sets a descriptor in the IDT.
 */
void
idt_set_desc(uint8_t i, uint32_t base, uint16_t sel, uint8_t flags)
{
  idt[i].base_low  = (base & 0xffff);
  idt[i].base_high = (base >> 16) & 0xffff;
  idt[i].sel       = sel;
  idt[i].zero      = 0;
  idt[i].flags     = flags; /* | 0x60; TODO: enable when supporting user mode! */
}

/*
 * Setup and loads the IDT.
 */
void
idt_init(void)
{
  /* TODO: memset */
  /*memset(&idt, 0, sizeof(idt_descr_t) * NUM_IDT_DESCR);*/

  /* load IDT */
  idt_ptr.limit = (sizeof(idt_descr_t) * NUM_IDT_DESCRS) - 1;
  idt_ptr.base  = (uint32_t) &idt;
  idt_load();
}
