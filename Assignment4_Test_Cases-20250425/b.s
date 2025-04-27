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
	.size	a, 16
a:
	.space	16
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
	li	$t0,0
	la $2, a
	sll $t0, $t0, 2
	add $5, $2, $t0
	la $4, $LC0
	jal __isoc99_scanf
	li	$t0,1
	la $2, a
	sll $t0, $t0, 2
	add $5, $2, $t0
	la $4, $LC0
	jal __isoc99_scanf
	li	$t0,2
	la $2, a
	sll $t0, $t0, 2
	add $5, $2, $t0
	la $4, $LC0
	jal __isoc99_scanf
	li	$t0,3
	li	$t4,0
	la	$t3, a
	sll	$t4, $t4, 2
	add	$t5, $t3, $t4
	lw	$t5, 0($t5)
	li	$t4,1
	la	$t3, a
	sll	$t4, $t4, 2
	add	$t6, $t3, $t4
	lw	$t6, 0($t6)
	addu $t2, $t5, $t6
	li	$t4,2
	la	$t3, a
	sll	$t4, $t4, 2
	add	$t5, $t3, $t4
	lw	$t5, 0($t5)
	addu $t1, $t2, $t5
	la $2, a
	sll $t0, $t0, 2
	add $2, $2, $t0
	sw $t1, 0($2)
	li	$t1,3
	la	$t0, a
	sll	$t1, $t1, 2
	add	$t2, $t0, $t1
	lw	$t2, 0($t2)
	move	$5,$t2
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
