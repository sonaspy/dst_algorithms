.section	__TEXT,__text,regular,pure_instructions
.macosx_version_min 10, 12
.globl	_main
.p2align	4, 0x90
_main:
## @main
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
subq	$32, %rsp
leaq	L_.str(%rip), %rdi
xorl	%eax, %eax
movl	%eax, %ecx
movq	%rcx, %rdx
addq	$12, %rdx
movl	%edx, %eax
movq	%rcx, %rdx
addq	$8, %rdx
movl	%edx, %esi
addq	$4, %rcx
movl	%ecx, %r8d
movl	$0, -4(%rbp)
movl	%r8d, -8(%rbp)
movl	%esi, -12(%rbp)
movl	%eax, -16(%rbp)
movl	-4(%rbp), %esi
movb	$0, %al
callq	_printf
leaq	L_.str.1(%rip), %rdi
movl	-8(%rbp), %esi
movl	%eax, -20(%rbp)         ## 4-byte Spill
movb	$0, %al
callq	_printf
leaq	L_.str.2(%rip), %rdi
movl	-12(%rbp), %esi
movl	%eax, -24(%rbp)         ## 4-byte Spill
movb	$0, %al
callq	_printf
leaq	L_.str.3(%rip), %rdi
movl	-16(%rbp), %esi
movl	%eax, -28(%rbp)         ## 4-byte Spill
movb	$0, %al
callq	_printf
xorl	%esi, %esi
movl	%eax, -32(%rbp)         ## 4-byte Spill
movl	%esi, %eax
addq	$32, %rsp
popq	%rbp
retq
.cfi_endproc

.section	__TEXT,__cstring,cstring_literals
L_.str:
## @.str
.asciz	"gender_offset = %d\n"

L_.str.1:
## @.str.1
.asciz	"id_offset = %d\n"

L_.str.2:
## @.str.2
.asciz	"age_offset = %d\n"

L_.str.3:
## @.str.3
.asciz	"name_offset = %d\n"


.subsections_via_symbols
