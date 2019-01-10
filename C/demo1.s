	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
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
	leaq	L_.str(%rip), %rsi
	movl	$20, %eax
	movl	%eax, %edx
	leaq	-40(%rbp), %rcx
	movq	___stack_chk_guard@GOTPCREL(%rip), %rdi
	movq	(%rdi), %rdi
	movq	%rdi, -8(%rbp)
	movb	$49, -40(%rbp)
	movl	$9527, -36(%rbp)        ## imm = 0x2537
	movl	$24, -32(%rbp)
	addq	$12, %rcx
	movq	%rcx, %rdi
	callq	___strcpy_chk
	leaq	L_.str.1(%rip), %rdi
	xorl	%r8d, %r8d
	movl	%r8d, %ecx
	movq	%rcx, %rdx
	addq	$4, %rdx
	subq	%rdx, %rcx
	leaq	-40(%rbp), %rdx
	addq	$4, %rdx
	movq	%rdx, -56(%rbp)
	movq	-56(%rbp), %rdx
	addq	%rcx, %rdx
	movq	%rdx, -64(%rbp)
	movq	-64(%rbp), %rcx
	movq	%rcx, -48(%rbp)
	movq	-48(%rbp), %rcx
	movsbl	(%rcx), %esi
	movq	%rax, -72(%rbp)         ## 8-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.2(%rip), %rdi
	movq	-48(%rbp), %rcx
	movl	8(%rcx), %esi
	movl	%eax, -76(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.3(%rip), %rdi
	movq	-48(%rbp), %rcx
	addq	$12, %rcx
	movq	%rcx, %rsi
	movl	%eax, -80(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rcx
	movl	%eax, -84(%rbp)         ## 4-byte Spill
	jne	LBB0_2
## BB#1:                                ## %SP_return
	xorl	%eax, %eax
	addq	$96, %rsp
	popq	%rbp
	retq
LBB0_2:                                 ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"zhouxingxing"

L_.str.1:                               ## @.str.1
	.asciz	"gender= %c\n"

L_.str.2:                               ## @.str.2
	.asciz	"age= %d\n"

L_.str.3:                               ## @.str.3
	.asciz	"name= %s\n"


.subsections_via_symbols
