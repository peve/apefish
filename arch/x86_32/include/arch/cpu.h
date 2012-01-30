/**
 *
 */
#ifndef __APEFISH_X86_CPU__
#define  __APEFISH_X86_CPU__


/* TODO: move to more appropriate file */
/* TODO: implement as macros or in asm */
unsigned char inb (unsigned short _port)
{
    unsigned char rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

void outb (unsigned short _port, unsigned char _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}




#endif /* __APEFISH_X86_CPU__ */
