/**
 * 
 */

.global boot

/* multiboot header, see GRUB docs for details */
.set MB_ALIGN,    1<<0                     /* align loaded modules on page boundaries */
.set MB_MEMINFO,  1<<1                     /* provide memory map */
.set MB_FLAGS,    MB_ALIGN | MB_MEMINFO    /* this is the Multiboot 'flag' field */
.set MB_MAGIC,    0x1BADB002               /* 'magic number' lets bootloader find the header */
.set MB_CHECKSUM, -(MB_MAGIC + MB_FLAGS)   /* checksum required */
	
.align 4
.long MB_MAGIC
.long MB_FLAGS
.long MB_CHECKSUM

/* reserve initial kernel stack space */
.set STACKSIZE, 0x4000			   /* 16k */
.comm stack, STACKSIZE, 32		   /* reserve stack space */
 
boot:

    mov $(stack + STACKSIZE), %esp         /* setup the stack */

    cli

    /* call c main */
    /* TODO: params */
    #push %eax				   /* pass Multiboot magic number */
    #push %ebx				   /* pass Multiboot info structure */

    call platform_init
	
    dead:
        hlt
        jmp dead
