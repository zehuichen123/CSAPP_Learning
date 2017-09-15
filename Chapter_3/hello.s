	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_multstore
	.p2align	4, 0x90
_multstore:                             ## @multstore
	.cfi_startproc
## BB#0:
## x in %rdi, y in %rsi, dest in %rdx
	pushq	%rbp	
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	# %rsp is stack pointer,
	# it is used to mark the end position
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	pushq	%rbx		# save %rbx
	pushq	%rax
Ltmp3:
	.cfi_offset %rbx, -24
	movq	%rdx, %rbx	# copy dest to %rbx
	callq	_mult2
	movq	%rax, (%rbx)	# store result at *dest
	addq	$8, %rsp
	popq	%rbx	# restore %rbx
	popq	%rbp
	retq			# return
	.cfi_endproc


.subsections_via_symbols
