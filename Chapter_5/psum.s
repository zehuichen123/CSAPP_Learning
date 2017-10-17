	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.section	__TEXT,__literal16,16byte_literals
	.p2align	4
LCPI0_0:
	.long	1127219200              ## 0x43300000
	.long	1160773632              ## 0x45300000
	.long	0                       ## 0x0
	.long	0                       ## 0x0
LCPI0_1:
	.quad	4841369599423283200     ## double 4503599627370496
	.quad	4985484787499139072     ## double 1.9342813113834067E+25
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3
LCPI0_2:
	.quad	4696837146684686336     ## double 1.0E+6
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_psum1
	.p2align	4, 0x90
_psum1:                                 ## @psum1
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi2:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r12
	pushq	%rbx
Lcfi3:
	.cfi_offset %rbx, -48
Lcfi4:
	.cfi_offset %r12, -40
Lcfi5:
	.cfi_offset %r14, -32
Lcfi6:
	.cfi_offset %r15, -24
	movq	%rdx, %r15
	movq	%rsi, %r12
	movq	%rdi, %rbx
	callq	_clock
	movq	%rax, %r14
	movl	(%rbx), %eax
	movl	%eax, (%r12)
	testq	%r15, %r15
	jle	LBB0_3
## BB#1:
	movss	-4(%r12), %xmm0         ## xmm0 = mem[0],zero,zero,zero
	.p2align	4, 0x90
LBB0_2:                                 ## =>This Inner Loop Header: Depth=1
	addss	(%rbx), %xmm0
	movss	%xmm0, (%r12)
	addq	$4, %r12
	addq	$4, %rbx
	decq	%r15
	jne	LBB0_2
LBB0_3:
	callq	_clock
	subq	%r14, %rax
	movd	%rax, %xmm0
	punpckldq	LCPI0_0(%rip), %xmm0 ## xmm0 = xmm0[0],mem[0],xmm0[1],mem[1]
	subpd	LCPI0_1(%rip), %xmm0
	haddpd	%xmm0, %xmm0
	divsd	LCPI0_2(%rip), %xmm0
	leaq	L_.str(%rip), %rdi
	movb	$1, %al
	popq	%rbx
	popq	%r12
	popq	%r14
	popq	%r15
	popq	%rbp
	jmp	_printf                 ## TAILCALL
	.cfi_endproc

	.section	__TEXT,__literal16,16byte_literals
	.p2align	4
LCPI1_0:
	.long	1127219200              ## 0x43300000
	.long	1160773632              ## 0x45300000
	.long	0                       ## 0x0
	.long	0                       ## 0x0
LCPI1_1:
	.quad	4841369599423283200     ## double 4503599627370496
	.quad	4985484787499139072     ## double 1.9342813113834067E+25
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3
LCPI1_2:
	.quad	4696837146684686336     ## double 1.0E+6
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_psum2
	.p2align	4, 0x90
_psum2:                                 ## @psum2
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi7:
	.cfi_def_cfa_offset 16
Lcfi8:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi9:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r12
	pushq	%rbx
Lcfi10:
	.cfi_offset %rbx, -48
Lcfi11:
	.cfi_offset %r12, -40
Lcfi12:
	.cfi_offset %r14, -32
Lcfi13:
	.cfi_offset %r15, -24
	movq	%rdx, %r15
	movq	%rsi, %rbx
	movq	%rdi, %r12
	callq	_clock
	movq	%rax, %r14
	movl	(%r12), %eax
	movl	%eax, (%rbx)
	decq	%r15
	cmpq	$2, %r15
	jl	LBB1_3
## BB#1:
	movl	$1, %eax
	.p2align	4, 0x90
LBB1_2:                                 ## =>This Inner Loop Header: Depth=1
	movss	-4(%rbx,%rax,4), %xmm0  ## xmm0 = mem[0],zero,zero,zero
	addss	(%r12,%rax,4), %xmm0
	movss	%xmm0, (%rbx,%rax,4)
	addss	4(%r12,%rax,4), %xmm0
	movss	%xmm0, 4(%rbx,%rax,4)
	addq	$2, %rax
	cmpq	%r15, %rax
	jl	LBB1_2
LBB1_3:
	callq	_clock
	subq	%r14, %rax
	movd	%rax, %xmm0
	punpckldq	LCPI1_0(%rip), %xmm0 ## xmm0 = xmm0[0],mem[0],xmm0[1],mem[1]
	subpd	LCPI1_1(%rip), %xmm0
	haddpd	%xmm0, %xmm0
	divsd	LCPI1_2(%rip), %xmm0
	leaq	L_.str.1(%rip), %rdi
	movb	$1, %al
	popq	%rbx
	popq	%r12
	popq	%r14
	popq	%r15
	popq	%rbp
	jmp	_printf                 ## TAILCALL
	.cfi_endproc

	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi14:
	.cfi_def_cfa_offset 16
Lcfi15:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi16:
	.cfi_def_cfa_register %rbp
	movq	_a1@GOTPCREL(%rip), %rdi
	movq	_p1@GOTPCREL(%rip), %rsi
	movl	$100000000, %edx        ## imm = 0x5F5E100
	callq	_psum1
	movq	_a@GOTPCREL(%rip), %rdi
	movq	_p@GOTPCREL(%rip), %rsi
	movl	$100000000, %edx        ## imm = 0x5F5E100
	callq	_psum2
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"psum1 is %lf\n"

L_.str.1:                               ## @.str.1
	.asciz	"psum2 is %lf\n"

	.comm	_a1,400000000,4         ## @a1
	.comm	_p1,400000000,4         ## @p1
	.comm	_a,400000000,4          ## @a
	.comm	_p,400000000,4          ## @p

.subsections_via_symbols
