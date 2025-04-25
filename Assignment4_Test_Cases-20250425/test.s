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
	.globl	arr
	.align	2
	.type	arr, @object
	.size	arr, 64
arr:
	.space	64
	.globl	len
	.align	2
	.type	len, @object
	.size	len, 4
len:
	.space	4
	.globl	i
	.align	2
	.type	i, @object
	.size	i, 4
i:
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
	la	$5,len
	la	$4,$LC0
	jal	__isoc99_scanf
	li	$t0,0
	la $2, i
	sw $t0, 0($2)
	j L2
L3:
	la	$t0,i
	lw	$t0,0($t0)
	la $2, arr
	sll $t0, $t0, 2
	add $5, $2, $t0
	la $4, $LC0
	jal __isoc99_scanf
	la	$t1,i
	lw	$t1,0($t1)
	li	$t2,1
	addu $t0, $t1, $t2
	la $2, i
	sw $t0, 0($2)
L2:
	la	$t1,i
	lw	$t1,0($t1)
	la	$t2,len
	lw	$t2,0($t2)
	slt $t0, $t1, $t2
	bne $t0, $zero, L3
L4:
	li	$t0,0
	la $2, i
	sw $t0, 0($2)
	j L5
L6:
	la	$t2,i
	lw	$t2,0($t2)
	la	$t1, arr
	sll	$t2, $t2, 2
	add	$t3, $t1, $t2
	lw	$t3, 0($t3)
	la	$t1,i
	lw	$t1,0($t1)

xor $t0, $t3, $t1
	sltu $t0, $zero, $t0
	beq $t0, $zero, L8
	j L7
	L8:
	la	$t1,i
	lw	$t1,0($t1)
	li	$t2,1
	addu $t0, $t1, $t2
	la $2, i
	sw $t0, 0($2)
L5:
	la	$t1,i
	lw	$t1,0($t1)
	la	$t2,len
	lw	$t2,0($t2)
	slt $t0, $t1, $t2
	bne $t0, $zero, L6
L7:
	la	$t0,i
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
