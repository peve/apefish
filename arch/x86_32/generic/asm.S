/**
 *
 */
#ifndef __APEFISH_X86_GENERIC_ASM__
#define __APEFISH_X86_GENERIC_ASM__

/* TODO: move port io to an arch asm.S?*/
/* TODO: rename this to descriptors.S? or keep all asm in single file? */
	
/*** Port I/O *****************************************************************/
/* TODO */

/*** Global Descriptor Table **************************************************/
.global gdt_load
.extern gdt_ptr

/*
 * Loads GDT and the data segment registers.
 */
gdt_load:
	lgdt gdt_ptr

	/* code segment is second entry in gdt => offset 0x08
	   data segment is third entry in gdt  => offset 0x10 */
	
	/* do far jump to reload CS register */
	ljmp $0x08, $gdt_load_complete

gdt_load_complete:
	/* also, reload data segment registers */
	mov $0x10, %ax
	mov %ax, %ds
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs
	mov %ax, %ss
	
	ret

/*** Interrupt Descriptor Table ***********************************************/
.global idt_load
.extern idt_ptr
	
/*
 * Loads IDT
 */
idt_load:
	lidt idt_ptr
	ret

/*** Interrupt Service Routines ***********************************************/

/*
 * Macros for defining ISR stubs.
 */
.macro ISR_NO_ERR num
	.global isr_stub\num
	isr_stub\num:
		cli        /* disable interrupts asap */
		push $0    /* dummy error code */
	        push $\num /* interrupt no */
		jmp isr_stub_common
.endm

.macro ISR_ERR num
	.global isr_stub\num
	isr_stub\num:
		cli        /* disable interrupts asap */
		push $\num /* interrupt no */
		jmp isr_stub_common
.endm

/*
 * Common ISR handler, pushes the context and calls the c handler.
 */
.extern isr_handler
isr_stub_common:
	pusha

	push %ds
	push %es
	push %fs
	push %gs

	/* load kernel data segment descriptor */
	mov $0x10, %ax
	mov %ax, %ds
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs

	/* call c interrupt handler */
	mov %esp, %eax
	push %eax

	call isr_handler
	
	pop %eax

	pop %gs
	pop %fs
	pop %es
	pop %ds
	
	popa

	/* also pop int no and err code */
	add $8, %esp
	
	sti
	iret

/*
 * ISR stubs for processor interrupts (exceptions, faults and traps)
 */
ISR_NO_ERR 0
ISR_NO_ERR 1
ISR_NO_ERR 2
ISR_NO_ERR 3
ISR_NO_ERR 4
ISR_NO_ERR 5
ISR_NO_ERR 6
ISR_NO_ERR 7
ISR_ERR    8
ISR_NO_ERR 9
ISR_ERR    10
ISR_ERR    11
ISR_ERR    12
ISR_ERR    13
ISR_ERR    14
ISR_NO_ERR 15
ISR_NO_ERR 16
ISR_ERR    17
ISR_NO_ERR 18
ISR_NO_ERR 19
ISR_NO_ERR 20
ISR_NO_ERR 21
ISR_NO_ERR 22
ISR_NO_ERR 23
ISR_NO_ERR 24
ISR_NO_ERR 25
ISR_NO_ERR 26
ISR_NO_ERR 27
ISR_NO_ERR 28
ISR_NO_ERR 29
ISR_NO_ERR 30
ISR_NO_ERR 31
	
#endif /* __APEFISH_X86_GENERIC_ASM__ */
