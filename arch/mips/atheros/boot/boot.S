/*
 * FOO!
 */


.global _boot
_boot:

	/* TODO: disable interrupts */

	/* TODO: clear uninitialized data (?) */
	
	/* setup stack pointer */
	la	$sp, _sp

	/* call kernel C entry point */
	la	$t0, main
	jal	$t0
	
	/* turn on the wlan led for debugging */
/*	lui $t0, 0xB100
	ori $t1, $t0,0x98 # gpio data output
	ori $t0, $t0,0x90 # gpio ctrl
	li $t2, 36        # wlan + reset high/out
	sw $t2, 0($t0)
	sw $t2, 0($t1)*/
	/*j foo*/

	/* jump to redboot code (PC after cpu reset execption)
	   (will work while we don't overwrite it in memory) */
	la	$t0, 0xbfc00000
	jr	$t0
	/* should not end up here */
	dead:
	j	dead

	



	