	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_proc
	.p2align	4, 0x90
_proc:                                  ## @proc
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	#%rsp here is stack pointer
Ltmp2:
#a1 in %rdi
#a1p in %rsi
#a2 in %edx
#a2p in %rcx
#a3 in %r8w
#a3p in %r9
#a4 in %rbp+16
#a4p in %rbp+24
	.cfi_def_cfa_register %rbp
	#fetch a4 to %r10b
	movb	16(%rbp), %r10b
	#fetch a4p to %rax
	movq	24(%rbp), %rax
	#*a1p+=a1
	addq	%rdi, (%rsi)
	addl	%edx, (%rcx)
	addw	%r8w, (%r9)
	addb	%r10b, (%rax)
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
