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
	.globl	array
	.align	2
	.type	array, @object
	.size	array, 20
array:
	.space	20
	.globl	filter
	.align	2
	.type	filter, @object
	.size	filter, 12
filter:
	.space	12
	.globl	convolution
	.align	2
	.type	convolution, @object
	.size	convolution, 12
convolution:
	.space	12
	.globl	sum
	.align	2
	.type	sum, @object
	.size	sum, 4
sum:
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
	li	$t0,0
	li	$t2,1
	sub $t1, $zero, $t2
	la $2, filter
	sll $t0, $t0, 2
	add $2, $2, $t0
	sw $t1, 0($2)
	li	$t0,1
	li	$t1,0
	la $2, filter
	sll $t0, $t0, 2
	add $2, $2, $t0
	sw $t1, 0($2)
	li	$t0,2
	li	$t1,1
	la $2, filter
	sll $t0, $t0, 2
	add $2, $2, $t0
	sw $t1, 0($2)
	li	$t0,0
	la $2, array
	sll $t0, $t0, 2
	add $5, $2, $t0
	la $4, $LC0
	jal __isoc99_scanf
	li	$t0,1
	la $2, array
	sll $t0, $t0, 2
	add $5, $2, $t0
	la $4, $LC0
	jal __isoc99_scanf
	li	$t0,2
	la $2, array
	sll $t0, $t0, 2
	add $5, $2, $t0
	la $4, $LC0
	jal __isoc99_scanf
	li	$t0,3
	la $2, array
	sll $t0, $t0, 2
	add $5, $2, $t0
	la $4, $LC0
	jal __isoc99_scanf
	li	$t0,4
	la $2, array
	sll $t0, $t0, 2
	add $5, $2, $t0
	la $4, $LC0
	jal __isoc99_scanf
	li	$t0,0
	li	$t5,0
	la	$t4, array
	sll	$t5, $t5, 2
	add	$t6, $t4, $t5
	lw	$t6, 0($t6)
	li	$t5,0
	la	$t4, filter
	sll	$t5, $t5, 2
	add	$t7, $t4, $t5
	lw	$t7, 0($t7)
	mult $t6, $t7
	mflo $t3
	li	$t6,1
	la	$t5, array
	sll	$t6, $t6, 2
	add	$t7, $t5, $t6
	lw	$t7, 0($t7)
	li	$t6,1
	la	$t5, filter
	sll	$t6, $t6, 2
	add	$t8, $t5, $t6
	lw	$t8, 0($t8)
	mult $t7, $t8
	mflo $t4
	addu $t2, $t3, $t4
	li	$t5,2
	la	$t4, array
	sll	$t5, $t5, 2
	add	$t6, $t4, $t5
	lw	$t6, 0($t6)
	li	$t5,2
	la	$t4, filter
	sll	$t5, $t5, 2
	add	$t7, $t4, $t5
	lw	$t7, 0($t7)
	mult $t6, $t7
	mflo $t3
	addu $t1, $t2, $t3
	la $2, convolution
	sll $t0, $t0, 2
	add $2, $2, $t0
	sw $t1, 0($2)
	li	$t0,1
	li	$t5,1
	la	$t4, array
	sll	$t5, $t5, 2
	add	$t6, $t4, $t5
	lw	$t6, 0($t6)
	li	$t5,0
	la	$t4, filter
	sll	$t5, $t5, 2
	add	$t7, $t4, $t5
	lw	$t7, 0($t7)
	mult $t6, $t7
	mflo $t3
	li	$t6,2
	la	$t5, array
	sll	$t6, $t6, 2
	add	$t7, $t5, $t6
	lw	$t7, 0($t7)
	li	$t6,1
	la	$t5, filter
	sll	$t6, $t6, 2
	add	$t8, $t5, $t6
	lw	$t8, 0($t8)
	mult $t7, $t8
	mflo $t4
	addu $t2, $t3, $t4
	li	$t5,3
	la	$t4, array
	sll	$t5, $t5, 2
	add	$t6, $t4, $t5
	lw	$t6, 0($t6)
	li	$t5,2
	la	$t4, filter
	sll	$t5, $t5, 2
	add	$t7, $t4, $t5
	lw	$t7, 0($t7)
	mult $t6, $t7
	mflo $t3
	addu $t1, $t2, $t3
	la $2, convolution
	sll $t0, $t0, 2
	add $2, $2, $t0
	sw $t1, 0($2)
	li	$t0,2
	li	$t5,2
	la	$t4, array
	sll	$t5, $t5, 2
	add	$t6, $t4, $t5
	lw	$t6, 0($t6)
	li	$t5,0
	la	$t4, filter
	sll	$t5, $t5, 2
	add	$t7, $t4, $t5
	lw	$t7, 0($t7)
	mult $t6, $t7
	mflo $t3
	li	$t6,3
	la	$t5, array
	sll	$t6, $t6, 2
	add	$t7, $t5, $t6
	lw	$t7, 0($t7)
	li	$t6,1
	la	$t5, filter
	sll	$t6, $t6, 2
	add	$t8, $t5, $t6
	lw	$t8, 0($t8)
	mult $t7, $t8
	mflo $t4
	addu $t2, $t3, $t4
	li	$t5,4
	la	$t4, array
	sll	$t5, $t5, 2
	add	$t6, $t4, $t5
	lw	$t6, 0($t6)
	li	$t5,2
	la	$t4, filter
	sll	$t5, $t5, 2
	add	$t7, $t4, $t5
	lw	$t7, 0($t7)
	mult $t6, $t7
	mflo $t3
	addu $t1, $t2, $t3
	la $2, convolution
	sll $t0, $t0, 2
	add $2, $2, $t0
	sw $t1, 0($2)
	li	$t3,0
	la	$t2, convolution
	sll	$t3, $t3, 2
	add	$t4, $t2, $t3
	lw	$t4, 0($t4)
	li	$t3,1
	la	$t2, convolution
	sll	$t3, $t3, 2
	add	$t5, $t2, $t3
	lw	$t5, 0($t5)
	addu $t1, $t4, $t5
	li	$t3,2
	la	$t2, convolution
	sll	$t3, $t3, 2
	add	$t4, $t2, $t3
	lw	$t4, 0($t4)
	addu $t0, $t1, $t4
	la $2, sum
	sw $t0, 0($2)
	li	$t2,0
	la	$t1, convolution
	sll	$t2, $t2, 2
	add	$t3, $t1, $t2
	lw	$t3, 0($t3)
	la	$t1,sum
	lw	$t1,0($t1)
	div $t3, $t1
	bne	$t1,$0,1f
	nop
	break	7
1:
	mflo $t0
	move	$5,$t0
	la	$4,$LC1
	jal	printf
	li	$t2,1
	la	$t1, convolution
	sll	$t2, $t2, 2
	add	$t3, $t1, $t2
	lw	$t3, 0($t3)
	la	$t1,sum
	lw	$t1,0($t1)
	div $t3, $t1
	bne	$t1,$0,1f
	nop
	break	7
1:
	mflo $t0
	move	$5,$t0
	la	$4,$LC1
	jal	printf
	li	$t2,2
	la	$t1, convolution
	sll	$t2, $t2, 2
	add	$t3, $t1, $t2
	lw	$t3, 0($t3)
	la	$t1,sum
	lw	$t1,0($t1)
	div $t3, $t1
	bne	$t1,$0,1f
	nop
	break	7
1:
	mflo $t0
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
