	.data
	.align 4
	.globl global
	.type global,@object
	.size global,4
global:
	.long 8150
	.text
	.align 4
	.globl sum
	.type sum,@function
sum:
	enter $8,$0
.L461:
.L465:
	movl $451,-4(%ebp)
	movl 8(%ebp),%eax
	addl 12(%ebp),%eax
	movl %eax,-4(%ebp)
	movl -4(%ebp),%eax
	movl %eax,-8(%ebp)
	jmp .L463
.L463:
	movl -8(%ebp),%eax
	leave
	ret
	.size sum,.-sum
	.align 4
	.globl main
	.type main,@function
main:
	enter $8,$0
.L469:
.L473:
	movl $4711,-4(%ebp)
	pushl -4(%ebp)
	pushl global
	pushl $.L475
	call printf
	addl $12, %esp
	pushl -4(%ebp)
	pushl global
	call sum
	addl $8, %esp
	movl %eax,-4(%ebp)
	movl -4(%ebp),%eax
	movl %eax,-8(%ebp)
	jmp .L471
.L471:
	movl -8(%ebp),%eax
	leave
	ret
	.size main,.-main
	.section .rodata
	.size .L475,34
.L475:
	.ascii "Hello, world!\012global=%d local=%d\012\0"
	.ident "PCC: Portable C Compiler 1.2.0.DEVEL 20160115 for i686-pc-linux-gnu"
