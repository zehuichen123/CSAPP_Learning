	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_scale
	.p2align	4, 0x90
_scale:                                 ## @scale
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
# x in %rdi, y in %rsi, z in %rdx
# leaq S,D : D<- &S
	leaq	(%rdi,%rsi,4), %rax # %rax=x+4*y
	leaq	(%rdx,%rdx,2), %rcx # %rcx=z+2*z
	leaq	(%rax,%rcx,4), %rax # %rax=x+4*y+3*z*4
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
