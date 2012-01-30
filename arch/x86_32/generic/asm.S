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
		cli     /* disable interrupts asap */
		push $0 /* dummy error code */
	        push \num /* interrupt no */
		jmp isr_stub_common
.endm

.macro ISR_ERR n
.global isr\n_stub
	isr\n_stub:
		cli     /* disable interrupts asap */
		push \n /* interrupt no */
		jmp isr_stub_common
.endm

/*
 * Common ISR handler, pushes the context and calls the c handler.
 */
.extern isr_handler
isr_stub_common:
	pusha

	/* TODO: some documentation */
	mov %ds, %ax
	push %eax

	mov $0x10, %ax
	mov %ax, %ds
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs

	call isr_handler

	pop %eax
	mov %eax, %ds
	mov %eax, %es
	mov %eax, %fs
	mov %eax, %gs
	
	popa
	
	add $8, %esp
	sti
	iret

ISR_NO_ERR 0
ISR_NO_ERR 1
/* ... */


	
#endif /* __APEFISH_X86_GENERIC_ASM__ */
