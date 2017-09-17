	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_arith2
	.p2align	4, 0x90
_arith2:                                ## @arith2
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	orq	%rsi, %rdi
	sarq	$3, %rdi
	notq	%rdi
	subq	%rdi, %rdx
	movq	%rdx, %rax
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
