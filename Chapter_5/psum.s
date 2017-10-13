	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3
LCPI0_0:
	.quad	4696837146684686336     ## double 1.0E+6
	.section	__TEXT,__literal16,16byte_literals
	.p2align	4
LCPI0_1:
	.long	1127219200              ## 0x43300000
	.long	1160773632              ## 0x45300000
	.long	0                       ## 0x0
	.long	0                       ## 0x0
LCPI0_2:
	.quad	4841369599423283200     ## double 4503599627370496
	.quad	4985484787499139072     ## double 1.9342813113834067E+25
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
	subq	$96, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	callq	_clock
	movq	%rax, -32(%rbp)
	movq	-8(%rbp), %rax
	movss	(%rax), %xmm0           ## xmm0 = mem[0],zero,zero,zero
	movq	-16(%rbp), %rax
	movss	%xmm0, (%rax)
	movl	$0, -52(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movslq	-52(%rbp), %rax
	cmpq	-24(%rbp), %rax
	jge	LBB0_4
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	movq	-16(%rbp), %rax
	movl	-52(%rbp), %ecx
	subl	$1, %ecx
	movslq	%ecx, %rdx
	movss	(%rax,%rdx,4), %xmm0    ## xmm0 = mem[0],zero,zero,zero
	movq	-8(%rbp), %rax
	movslq	-52(%rbp), %rdx
	addss	(%rax,%rdx,4), %xmm0
	movq	-16(%rbp), %rax
	movslq	-52(%rbp), %rdx
	movss	%xmm0, (%rax,%rdx,4)
## BB#3:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	-52(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -52(%rbp)
	jmp	LBB0_1
LBB0_4:
	leaq	L_.str(%rip), %rdi
	movsd	LCPI0_0(%rip), %xmm0    ## xmm0 = mem[0],zero
	movq	%rdi, -72(%rbp)         ## 8-byte Spill
	movsd	%xmm0, -80(%rbp)        ## 8-byte Spill
	callq	_clock
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	-32(%rbp), %rdi
	subq	%rdi, %rax
	movd	%rax, %xmm0
	movaps	LCPI0_1(%rip), %xmm1    ## xmm1 = [1127219200,1160773632,0,0]
	punpckldq	%xmm1, %xmm0    ## xmm0 = xmm0[0],xmm1[0],xmm0[1],xmm1[1]
	movapd	LCPI0_2(%rip), %xmm1    ## xmm1 = [4.503600e+15,1.934281e+25]
	subpd	%xmm1, %xmm0
	haddpd	%xmm0, %xmm0
	movsd	-80(%rbp), %xmm1        ## 8-byte Reload
                                        ## xmm1 = mem[0],zero
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -64(%rbp)
	movsd	-64(%rbp), %xmm0        ## xmm0 = mem[0],zero
	movq	-72(%rbp), %rdi         ## 8-byte Reload
	movb	$1, %al
	callq	_printf
	movl	%eax, -84(%rbp)         ## 4-byte Spill
	addq	$96, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__literal8,8byte_literals
	.p2align	3
LCPI1_0:
	.quad	4696837146684686336     ## double 1.0E+6
	.section	__TEXT,__literal16,16byte_literals
	.p2align	4
LCPI1_1:
	.long	1127219200              ## 0x43300000
	.long	1160773632              ## 0x45300000
	.long	0                       ## 0x0
	.long	0                       ## 0x0
LCPI1_2:
	.quad	4841369599423283200     ## double 4503599627370496
	.quad	4985484787499139072     ## double 1.9342813113834067E+25
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_psum2
	.p2align	4, 0x90
_psum2:                                 ## @psum2
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi3:
	.cfi_def_cfa_offset 16
Lcfi4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi5:
	.cfi_def_cfa_register %rbp
	subq	$96, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	callq	_clock
	movq	%rax, -32(%rbp)
	movq	-8(%rbp), %rax
	movss	(%rax), %xmm0           ## xmm0 = mem[0],zero,zero,zero
	movq	-16(%rbp), %rax
	movss	%xmm0, (%rax)
	movl	$1, -52(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	movslq	-52(%rbp), %rax
	movq	-24(%rbp), %rcx
	subq	$1, %rcx
	cmpq	%rcx, %rax
	jge	LBB1_4
## BB#2:                                ##   in Loop: Header=BB1_1 Depth=1
	movq	-16(%rbp), %rax
	movl	-52(%rbp), %ecx
	subl	$1, %ecx
	movslq	%ecx, %rdx
	movss	(%rax,%rdx,4), %xmm0    ## xmm0 = mem[0],zero,zero,zero
	movq	-8(%rbp), %rax
	movslq	-52(%rbp), %rdx
	addss	(%rax,%rdx,4), %xmm0
	movss	%xmm0, -56(%rbp)
	movss	-56(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	movq	-16(%rbp), %rax
	movslq	-52(%rbp), %rdx
	movss	%xmm0, (%rax,%rdx,4)
	movq	-8(%rbp), %rax
	movl	-52(%rbp), %ecx
	addl	$1, %ecx
	movslq	%ecx, %rdx
	movss	(%rax,%rdx,4), %xmm0    ## xmm0 = mem[0],zero,zero,zero
	addss	-56(%rbp), %xmm0
	movq	-16(%rbp), %rax
	movl	-52(%rbp), %ecx
	addl	$1, %ecx
	movslq	%ecx, %rdx
	movss	%xmm0, (%rax,%rdx,4)
## BB#3:                                ##   in Loop: Header=BB1_1 Depth=1
	movl	-52(%rbp), %eax
	addl	$2, %eax
	movl	%eax, -52(%rbp)
	jmp	LBB1_1
LBB1_4:
	movq	-48(%rbp), %rax
	cmpq	-24(%rbp), %rax
	jge	LBB1_6
## BB#5:
	movq	-16(%rbp), %rax
	movq	-48(%rbp), %rcx
	subq	$1, %rcx
	movss	(%rax,%rcx,4), %xmm0    ## xmm0 = mem[0],zero,zero,zero
	movq	-8(%rbp), %rax
	movq	-48(%rbp), %rcx
	addss	(%rax,%rcx,4), %xmm0
	movq	-16(%rbp), %rax
	movq	-48(%rbp), %rcx
	movss	%xmm0, (%rax,%rcx,4)
LBB1_6:
	leaq	L_.str.1(%rip), %rdi
	movsd	LCPI1_0(%rip), %xmm0    ## xmm0 = mem[0],zero
	movq	%rdi, -72(%rbp)         ## 8-byte Spill
	movsd	%xmm0, -80(%rbp)        ## 8-byte Spill
	callq	_clock
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	-32(%rbp), %rdi
	subq	%rdi, %rax
	movd	%rax, %xmm0
	movaps	LCPI1_1(%rip), %xmm1    ## xmm1 = [1127219200,1160773632,0,0]
	punpckldq	%xmm1, %xmm0    ## xmm0 = xmm0[0],xmm1[0],xmm0[1],xmm1[1]
	movapd	LCPI1_2(%rip), %xmm1    ## xmm1 = [4.503600e+15,1.934281e+25]
	subpd	%xmm1, %xmm0
	haddpd	%xmm0, %xmm0
	movsd	-80(%rbp), %xmm1        ## 8-byte Reload
                                        ## xmm1 = mem[0],zero
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -64(%rbp)
	movsd	-64(%rbp), %xmm0        ## xmm0 = mem[0],zero
	movq	-72(%rbp), %rdi         ## 8-byte Reload
	movb	$1, %al
	callq	_printf
	movl	%eax, -84(%rbp)         ## 4-byte Spill
	addq	$96, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi6:
	.cfi_def_cfa_offset 16
Lcfi7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi8:
	.cfi_def_cfa_register %rbp
	movq	_a1@GOTPCREL(%rip), %rdi
	movq	_p1@GOTPCREL(%rip), %rsi
	movl	$100000000, %eax        ## imm = 0x5F5E100
	movl	%eax, %edx
	callq	_psum1
	movq	_a@GOTPCREL(%rip), %rdi
	movq	_p@GOTPCREL(%rip), %rsi
	movl	$100000000, %eax        ## imm = 0x5F5E100
	movl	%eax, %edx
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
