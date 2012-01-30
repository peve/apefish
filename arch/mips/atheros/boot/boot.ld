/*
 * FOO!
 */

/*OUTPUT(kernel.elf)*/
OUTPUT_ARCH(mips)
ENTRY(_boot)

SECTIONS
{
	/*** text segment ***/
	. = 0x80050000;				/* load kernel here */

	.text : 
	{
		_ftext = .;			/* start of code and RO data */
	      	/*boot.o (.text)*/			/* place kernel entry point object file first */
	      	*(.text)			/* rest of the object files */
		_ecode = . ;			/* end of code */
      
		*(.rodata)			/* place all RO data */
      		. = ALIGN(8);
		_etext = .;			/* end of text segment */
	} = 0

	/*** initialized data segment ***/
	.data :
	{
		_fdata = .;			/* start of initialized data */
		*(.data)
	
		. = ALIGN(8);
		*(.lit8)			/* 8-byte constants */
		*(.lit4)			/* 4-byte constants */
		*(.sdata)			/* subsequent data */
		. = ALIGN(8);
		_edata = .;			/* end of initialized data*/
	}

	/*** uninitialized data segment ***/
	_fbss = .;				/* start of uninitialized data */

	.sbss :
	{
		*(.dynsbss)
		*(.sbss)
		*(.sbss.*)
		*(.scommon)
	}

	.bss :
	{
		*(.dynbss)
		*(.bss)	
		*(.bss.*)
		*(COMMON)

		_sp_end = .;			/* end of stack */
		. = ALIGN(8);
		. += 0x100000;			/* stack space */
		_sp = . -16;			/* start of stack */
	}

	_end = .;				/* end of uninitialized data*/


	.gptab.sdata :
	{
		*(.gptab.data)
		*(.gptab.sdata)
	}

	.gptab.sbss :
	{
		*(.gptab.bss)
		*(.gptab.sbss)
	}

	PROVIDE(etext = _etext);
	PROVIDE(edata = .);
	PROVIDE(end = .);
}
