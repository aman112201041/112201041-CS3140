	.file	1 "s1.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=32
	.module	nooddspreg
	.module	arch=r2000
	.abicalls
	.text
	.section	.bss,"aw",@nobits
	.globl	a
	.align	2
	.type	a, @object
	.size	a, 4
a:
	.space	4
	.globl	b
	.align	2
	.type	b, @object
	.size	b, 4
b:
	.space	4
	.rdata
	.align	2
$LC0:
	.ascii	"%d\000"
	.align	2
$LC1:
	.ascii	"%d\012\000"
	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp,32,$31		# vars= 0, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$25
	.set	reorder
	addiu	$sp,$sp,-32
	sw	$31,28($sp)
	sw	$fp,24($sp)
	move	$fp,$sp
	.cprestore	16
	la	$5,a
	la	$4,$LC0
	jal	__isoc99_scanf
	la	$5,b
	la	$4,$LC0
	jal	__isoc99_scanf
	la	$t0,a
	lw	$t0,0($t0)
	move	$5,$t0
	la	$4,$LC1
	jal	printf
	la	$t0,b
	lw	$t0,0($t0)
	move	$5,$t0
	la	$4,$LC1
	jal	printf
	la	$5,a
	la	$4,$LC0
	jal	__isoc99_scanf
	la	$t0,a
	lw	$t0,0($t0)
	move	$5,$t0
	la	$4,$LC1
	jal	printf
	la	$t0,b
	lw	$t0,0($t0)
	move	$5,$t0
	la	$4,$LC1
	jal	printf
	la	$5,b
	la	$4,$LC0
	jal	__isoc99_scanf
	la	$t0,a
	lw	$t0,0($t0)
	move	$5,$t0
	la	$4,$LC1
	jal	printf
	la	$t0,b
	lw	$t0,0($t0)
	move	$5,$t0
	la	$4,$LC1
	jal	printf
	move	$sp,$fp
	lw	$31,28($sp)
	lw	$fp,24($sp)
	addiu	$sp,$sp,32
	j	$31
	.end	main
	.size	main, .-main
	.ident	"GCC: (Ubuntu 12.3.0-17ubuntu1) 12.3.0"
	.section	.note.GNU-stack,"",@progbits
