/**
 *
 */
#include <generic/gdt.h>

/*
 * GDT descriptor.
 */
typedef struct gdt_descr
{
  uint16_t limit_low;
  uint16_t base_low;
  uint8_t  base_middle;
  uint8_t  access;
  uint8_t  granularity;
  uint8_t  base_high;
} __attribute__((packed)) gdt_descr_t;


/*
 * GDT pointer.
 */
typedef struct gdt_ptr
{
  uint16_t limit;
  uint32_t base;
} __attribute__((packed)) gdt_ptr_t;

/*
 * GDT and its pointer.
 */
#define NUM_GDT_DESCRS 3
gdt_descr_t gdt[NUM_GDT_DESCRS];
gdt_ptr_t   gdt_ptr;

/* 
 * Assembler function that loads the GDT.
 */
extern void gdt_load(void);

/*
 * Sets a descriptor in the GDT.
 */
void
gdt_set_descr(uint32_t i, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran)
{
  gdt[i].limit_low   = (limit & 0xffff);

  gdt[i].base_low    = (base & 0xffff);
  gdt[i].base_middle = (base >> 16) & 0xff;
  gdt[i].base_high   = (base >> 24) & 0xff;

  gdt[i].access      = access;

  gdt[i].granularity = (limit >> 16) & 0x0f;
  gdt[i].granularity |= (gran & 0xf0);
}

/*
 * Setup and loads the GDT, using a flat memory model.
 */
void
gdt_init(void)
{
  /* setup segments */
  gdt_set_descr(0, 0, 0, 0, 0);                 /* NULL descriptor */
  gdt_set_descr(1, 0, 0xffffffff, 0x9a, 0xcf);  /* code segment */
  gdt_set_descr(2, 0, 0xffffffff, 0x92, 0xcf);  /* data segment */

  /* load GDT */
  gdt_ptr.limit = (sizeof(gdt_descr_t) * NUM_GDT_DESCRS) - 1;
  gdt_ptr.base  = (uint32_t) &gdt;
  gdt_load();
}
