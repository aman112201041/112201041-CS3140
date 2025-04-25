	.file	1 "plain.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=32
	.module	nooddspreg
	.module	arch=r2000
	.abicalls
	.text
	.globl	a
	.section	.bss,"aw",@nobits
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
	.globl	c
	.align	2
	.type	c, @object
	.size	c, 4
c:
	.space	4
	.globl	d
	.align	2
	.type	d, @object
	.size	d, 4
d:
	.space	4
	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$25
	.set	reorder
	addiu	$sp,$sp,-8
	sw	$fp,4($sp)
	move	$fp,$sp
	la	$2,a
	li	$3,10			# 0xa
	sw	$3,0($2)
	la	$2,b
	li	$3,20			# 0x14
	sw	$3,0($2)
	la	$2,c
	li	$3,30			# 0x1e
	sw	$3,0($2)
	la	$2,a
	lw	$3,0($2)
	la	$2,b
	lw	$2,0($2)
	#nop
	addu	$3,$3,$2
	la	$2,c
	lw	$2,0($2)
	#nop
	addu	$3,$3,$2
	la	$2,d
	sw	$3,0($2)
	move	$2,$0
	move	$sp,$fp
	lw	$fp,4($sp)
	addiu	$sp,$sp,8
	j	$31
	.end	main
	.size	main, .-main
	.ident	"GCC: (Ubuntu 12.3.0-17ubuntu1) 12.3.0"
	.section	.note.GNU-stack,"",@progbits
