	.file	1 "ex.c"
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
	.globl	arr
	.align	2
	.type	arr, @object
	.size	arr, 40
arr:
	.space	40
	.globl	i
	.align	2
	.type	i, @object
	.size	i, 4
i:
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
	la	$2,i
	sw	$0,0($2)
	b	$L2
$L3:
	la	$2,i
	lw	$2,0($2)
	la	$3,i
	lw	$3,0($3)
	la	$4,arr
	sll	$2,$2,2
	addu	$2,$4,$2
	sw	$3,0($2)
	la	$2,i
	lw	$2,0($2)
	#nop
	addiu	$3,$2,1
	la	$2,i
	sw	$3,0($2)
$L2:
	la	$2,i
	lw	$2,0($2)
	#nop
	slt	$2,$2,10
	bne	$2,$0,$L3
	move	$2,$0
	move	$sp,$fp
	lw	$fp,4($sp)
	addiu	$sp,$sp,8
	j	$31
	.end	main
	.size	main, .-main
	.ident	"GCC: (Ubuntu 12.3.0-17ubuntu1) 12.3.0"
	.section	.note.GNU-stack,"",@progbits
