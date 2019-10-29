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
	xorl	%eax, %eax
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$1, -20(%rbp)
	movl	$1, -24(%rbp)
	movl	$1, -28(%rbp)
	movl	$1, -32(%rbp)
	movl	$1, -36(%rbp)
	movl	$1, -40(%rbp)
	movl	$1, -44(%rbp)
	cmpl	$1, -20(%rbp)
	sete	%cl
	andb	$1, %cl
	movb	%cl, -45(%rbp)
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
