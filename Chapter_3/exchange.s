	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_exchange
	.p2align	4, 0x90
_exchange:                              ## @exchange
	.cfi_startproc
## BB#0:
# xp in %rdi,y in %rsi
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	movq	(%rdi), %rax # get x at xp.Set as return value
	movq	%rsi, (%rdi) # store y at xp
	popq	%rbp
	retq				# return
	.cfi_endproc


.subsections_via_symbols
