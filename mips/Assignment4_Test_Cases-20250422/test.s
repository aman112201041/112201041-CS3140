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
	.globl	key
	.align	2
	.type	key, @object
	.size	key, 4
key:
	.space	4
	.globl	found
	.align	2
	.type	found, @object
	.size	found, 4
found:
	.space	4
	.globl	index
	.align	2
	.type	index, @object
	.size	index, 4
index:
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
	la	$5,key
	la	$4,$LC0
	jal	__isoc99_scanf
	li	$t0,0
	la $2, found
	sw $t0, 0($2)
	li	$t0,0
	la $2, index
	sw $t0, 0($2)
	j L2
L3:
	la	$t2,index
	lw	$t2,0($t2)
	la	$t1, array
	sll	$t2, $t2, 2
	add	$t3, $t1, $t2
	lw	$t3, 0($t3)
	la	$t1,key
	lw	$t1,0($t1)

xor $t0, $t3, $t1
	sltiu $t0, $t0, 1
	beq $t0, $zero, L5
	li	$t1,1
	la $2, found
	sw $t1, 0($2)
	L5:
	la	$t1,index
	lw	$t1,0($t1)
	li	$t2,1
	addu $t0, $t1, $t2
	la $2, index
	sw $t0, 0($2)
L2:
	la	$t1,index
	lw	$t1,0($t1)
	li	$t2,4
	slt $t0, $t1, $t2
	bne $t0, $zero, L3
L4:
	la	$t1,found
	lw	$t1,0($t1)
	li	$t2,1

xor $t0, $t1, $t2
	sltiu $t0, $t0, 1
	beq $t0, $zero, L6
	li	$t1,1
	move	$5,$t1
	la	$4,$LC1
	jal	printf
	j L7
	L6:
	li	$t1,0
	move	$5,$t1
	la	$4,$LC1
	jal	printf
	L7:
	move	$sp,$fp
	lw	$31,28($sp)
	lw	$fp,24($sp)
	addiu	$sp,$sp,32
	j	$31
	.end	main
	.size	main, .-main
	.ident	"GCC: (Ubuntu 12.3.0-17ubuntu1) 12.3.0"
	.section	.note.GNU-stack,"",@progbits
