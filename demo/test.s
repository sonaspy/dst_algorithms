	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception0
## BB#0:
	pushq	%rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi2:
	.cfi_def_cfa_register %rbp
	subq	$128, %rsp
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	leaq	-96(%rbp), %rdi
	leaq	-104(%rbp), %rsi
	callq	__ZN3dsa5dequeIiNS_24__default_alloc_templateILb0ELi0EEEEC1ERKS2_
Ltmp0:
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	movb	%al, %cl
	movb	%cl, %al
	callq	_printf
Ltmp1:
	movl	%eax, -120(%rbp)        ## 4-byte Spill
	jmp	LBB0_1
LBB0_1:
	leaq	-96(%rbp), %rdi
	movl	$0, -4(%rbp)
	callq	__ZN3dsa5dequeIiNS_24__default_alloc_templateILb0ELi0EEEED1Ev
	movl	-4(%rbp), %eax
	addq	$128, %rsp
	popq	%rbp
	retq
LBB0_2:
Ltmp2:
	leaq	-96(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -112(%rbp)
	movl	%ecx, -116(%rbp)
	callq	__ZN3dsa5dequeIiNS_24__default_alloc_templateILb0ELi0EEEED1Ev
## BB#3:
	movq	-112(%rbp), %rdi
	callq	__Unwind_Resume
Lfunc_end0:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table0:
Lexception0:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset0 = Lfunc_begin0-Lfunc_begin0       ## >> Call Site 1 <<
	.long	Lset0
Lset1 = Ltmp0-Lfunc_begin0              ##   Call between Lfunc_begin0 and Ltmp0
	.long	Lset1
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset2 = Ltmp0-Lfunc_begin0              ## >> Call Site 2 <<
	.long	Lset2
Lset3 = Ltmp1-Ltmp0                     ##   Call between Ltmp0 and Ltmp1
	.long	Lset3
Lset4 = Ltmp2-Lfunc_begin0              ##     jumps to Ltmp2
	.long	Lset4
	.byte	0                       ##   On action: cleanup
Lset5 = Ltmp1-Lfunc_begin0              ## >> Call Site 3 <<
	.long	Lset5
Lset6 = Lfunc_end0-Ltmp1                ##   Call between Ltmp1 and Lfunc_end0
	.long	Lset6
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN3dsa5dequeIiNS_24__default_alloc_templateILb0ELi0EEEEC1ERKS2_
	.weak_def_can_be_hidden	__ZN3dsa5dequeIiNS_24__default_alloc_templateILb0ELi0EEEEC1ERKS2_
	.p2align	4, 0x90
__ZN3dsa5dequeIiNS_24__default_alloc_templateILb0ELi0EEEEC1ERKS2_: ## @_ZN3dsa5dequeIiNS_24__default_alloc_templateILb0ELi0EEEEC1ERKS2_
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
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	callq	__ZN3dsa5dequeIiNS_24__default_alloc_templateILb0ELi0EEEEC2ERKS2_
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa5dequeIiNS_24__default_alloc_templateILb0ELi0EEEED1Ev
	.weak_def_can_be_hidden	__ZN3dsa5dequeIiNS_24__default_alloc_templateILb0ELi0EEEED1Ev
	.p2align	4, 0x90
__ZN3dsa5dequeIiNS_24__default_alloc_templateILb0ELi0EEEED1Ev: ## @_ZN3dsa5dequeIiNS_24__default_alloc_templateILb0ELi0EEEED1Ev
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
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZN3dsa5dequeIiNS_24__default_alloc_templateILb0ELi0EEEED2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa5dequeIiNS_24__default_alloc_templateILb0ELi0EEEEC2ERKS2_
	.weak_def_can_be_hidden	__ZN3dsa5dequeIiNS_24__default_alloc_templateILb0ELi0EEEEC2ERKS2_
	.p2align	4, 0x90
__ZN3dsa5dequeIiNS_24__default_alloc_templateILb0ELi0EEEEC2ERKS2_: ## @_ZN3dsa5dequeIiNS_24__default_alloc_templateILb0ELi0EEEEC2ERKS2_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi9:
	.cfi_def_cfa_offset 16
Lcfi10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi11:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	xorl	%eax, %eax
	movl	%eax, %edx
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rsi
	movq	-16(%rbp), %rdi
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
	movq	%rsi, %rdi
	movq	-24(%rbp), %rsi         ## 8-byte Reload
	callq	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEEC2ERKS2_m
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEEC2ERKS2_m
	.weak_def_can_be_hidden	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEEC2ERKS2_m
	.p2align	4, 0x90
__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEEC2ERKS2_m: ## @_ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEEC2ERKS2_m
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi12:
	.cfi_def_cfa_offset 16
Lcfi13:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi14:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rdx
	movq	$0, (%rdx)
	movq	$0, 8(%rdx)
	movq	%rdx, %rsi
	addq	$16, %rsi
	movq	%rsi, %rdi
	movq	%rdx, -32(%rbp)         ## 8-byte Spill
	callq	__ZN3dsa16__deque_iteratorIiRiPiEC1Ev
	movq	-32(%rbp), %rdx         ## 8-byte Reload
	addq	$48, %rdx
	movq	%rdx, %rdi
	callq	__ZN3dsa16__deque_iteratorIiRiPiEC1Ev
	movq	-24(%rbp), %rsi
	movq	-32(%rbp), %rdi         ## 8-byte Reload
	callq	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE18__m_initialize_mapEm
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa16__deque_iteratorIiRiPiEC1Ev
	.weak_def_can_be_hidden	__ZN3dsa16__deque_iteratorIiRiPiEC1Ev
	.p2align	4, 0x90
__ZN3dsa16__deque_iteratorIiRiPiEC1Ev:  ## @_ZN3dsa16__deque_iteratorIiRiPiEC1Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi15:
	.cfi_def_cfa_offset 16
Lcfi16:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi17:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZN3dsa16__deque_iteratorIiRiPiEC2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE18__m_initialize_mapEm
	.weak_definition	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE18__m_initialize_mapEm
	.p2align	4, 0x90
__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE18__m_initialize_mapEm: ## @_ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE18__m_initialize_mapEm
Lfunc_begin1:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception1
## BB#0:
	pushq	%rbp
Lcfi18:
	.cfi_def_cfa_offset 16
Lcfi19:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi20:
	.cfi_def_cfa_register %rbp
	subq	$144, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rsi
	movq	-16(%rbp), %rax
	movl	$4, %ecx
	movl	%ecx, %edi
	movq	%rsi, -80(%rbp)         ## 8-byte Spill
	movq	%rax, -88(%rbp)         ## 8-byte Spill
	callq	__ZN3dsaL16__deque_buf_sizeEm
	xorl	%ecx, %ecx
	movl	%ecx, %edx
	movq	-88(%rbp), %rsi         ## 8-byte Reload
	movq	%rax, -96(%rbp)         ## 8-byte Spill
	movq	%rsi, %rax
	movq	-96(%rbp), %rdi         ## 8-byte Reload
	divq	%rdi
	incq	%rax
	movq	%rax, -24(%rbp)
	movq	$8, -32(%rbp)
	movq	-24(%rbp), %rax
	addq	$2, %rax
	movq	%rax, -40(%rbp)
	leaq	-32(%rbp), %rdi
	leaq	-40(%rbp), %rsi
	callq	__ZN3dsa3maxImEERKT_S3_S3_
	movq	(%rax), %rax
	movq	-80(%rbp), %rdx         ## 8-byte Reload
	movq	%rax, 8(%rdx)
	movq	8(%rdx), %rsi
	movq	%rdx, %rdi
	callq	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE16__m_allocate_mapEm
	movq	-80(%rbp), %rdx         ## 8-byte Reload
	movq	%rax, (%rdx)
	movq	(%rdx), %rax
	movq	8(%rdx), %rsi
	movq	-24(%rbp), %rdi
	subq	%rdi, %rsi
	movabsq	$4611686018427387902, %rdi ## imm = 0x3FFFFFFFFFFFFFFE
	andq	%rdi, %rsi
	leaq	(%rax,%rsi,4), %rax
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	-24(%rbp), %rsi
	leaq	(%rax,%rsi,8), %rax
	movq	%rax, -56(%rbp)
	movq	-48(%rbp), %rsi
	movq	-56(%rbp), %rdx
Ltmp3:
	movq	-80(%rbp), %rdi         ## 8-byte Reload
	callq	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE16__m_create_nodesEPPiS5_
Ltmp4:
	jmp	LBB6_1
LBB6_1:
	jmp	LBB6_7
LBB6_2:
Ltmp5:
	movl	%edx, %ecx
	movq	%rax, -64(%rbp)
	movl	%ecx, -68(%rbp)
## BB#3:
	movq	-64(%rbp), %rdi
	callq	___cxa_begin_catch
	movq	-80(%rbp), %rdi         ## 8-byte Reload
	movq	(%rdi), %rsi
	movq	8(%rdi), %rdx
Ltmp6:
	movq	%rax, -104(%rbp)        ## 8-byte Spill
	callq	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE18__m_deallocate_mapEPPim
Ltmp7:
	jmp	LBB6_4
LBB6_4:
	movq	-80(%rbp), %rax         ## 8-byte Reload
	movq	$0, (%rax)
	movq	$0, 8(%rax)
Ltmp8:
	callq	___cxa_rethrow
Ltmp9:
	jmp	LBB6_10
LBB6_5:
Ltmp10:
	movl	%edx, %ecx
	movq	%rax, -64(%rbp)
	movl	%ecx, -68(%rbp)
Ltmp11:
	callq	___cxa_end_catch
Ltmp12:
	jmp	LBB6_6
LBB6_6:
	jmp	LBB6_8
LBB6_7:
	movq	-80(%rbp), %rax         ## 8-byte Reload
	addq	$16, %rax
	movq	-48(%rbp), %rsi
	movq	%rax, %rdi
	callq	__ZN3dsa16__deque_iteratorIiRiPiE12__m_set_nodeEPS2_
	movq	-80(%rbp), %rax         ## 8-byte Reload
	addq	$48, %rax
	movq	-56(%rbp), %rsi
	addq	$-8, %rsi
	movq	%rax, %rdi
	callq	__ZN3dsa16__deque_iteratorIiRiPiE12__m_set_nodeEPS2_
	movl	$4, %ecx
	movl	%ecx, %edi
	movq	-80(%rbp), %rax         ## 8-byte Reload
	movq	24(%rax), %rsi
	movq	%rsi, 16(%rax)
	movq	56(%rax), %rsi
	movq	-16(%rbp), %rax
	movq	%rsi, -112(%rbp)        ## 8-byte Spill
	movq	%rax, -120(%rbp)        ## 8-byte Spill
	callq	__ZN3dsaL16__deque_buf_sizeEm
	movq	-120(%rbp), %rsi        ## 8-byte Reload
	movq	%rax, -128(%rbp)        ## 8-byte Spill
	movq	%rsi, %rax
	xorl	%ecx, %ecx
	movl	%ecx, %edx
	movq	-128(%rbp), %rdi        ## 8-byte Reload
	divq	%rdi
	shlq	$2, %rdx
	movq	-112(%rbp), %r8         ## 8-byte Reload
	addq	%rdx, %r8
	movq	-80(%rbp), %rdx         ## 8-byte Reload
	movq	%r8, 48(%rdx)
	addq	$144, %rsp
	popq	%rbp
	retq
LBB6_8:
	movq	-64(%rbp), %rdi
	callq	__Unwind_Resume
LBB6_9:
Ltmp13:
	movl	%edx, %ecx
	movq	%rax, %rdi
	movl	%ecx, -132(%rbp)        ## 4-byte Spill
	callq	___clang_call_terminate
LBB6_10:
Lfunc_end1:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table6:
Lexception1:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.asciz	"\326\200\200"          ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	78                      ## Call site table length
Lset7 = Lfunc_begin1-Lfunc_begin1       ## >> Call Site 1 <<
	.long	Lset7
Lset8 = Ltmp3-Lfunc_begin1              ##   Call between Lfunc_begin1 and Ltmp3
	.long	Lset8
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset9 = Ltmp3-Lfunc_begin1              ## >> Call Site 2 <<
	.long	Lset9
Lset10 = Ltmp4-Ltmp3                    ##   Call between Ltmp3 and Ltmp4
	.long	Lset10
Lset11 = Ltmp5-Lfunc_begin1             ##     jumps to Ltmp5
	.long	Lset11
	.byte	1                       ##   On action: 1
Lset12 = Ltmp4-Lfunc_begin1             ## >> Call Site 3 <<
	.long	Lset12
Lset13 = Ltmp6-Ltmp4                    ##   Call between Ltmp4 and Ltmp6
	.long	Lset13
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset14 = Ltmp6-Lfunc_begin1             ## >> Call Site 4 <<
	.long	Lset14
Lset15 = Ltmp9-Ltmp6                    ##   Call between Ltmp6 and Ltmp9
	.long	Lset15
Lset16 = Ltmp10-Lfunc_begin1            ##     jumps to Ltmp10
	.long	Lset16
	.byte	0                       ##   On action: cleanup
Lset17 = Ltmp11-Lfunc_begin1            ## >> Call Site 5 <<
	.long	Lset17
Lset18 = Ltmp12-Ltmp11                  ##   Call between Ltmp11 and Ltmp12
	.long	Lset18
Lset19 = Ltmp13-Lfunc_begin1            ##     jumps to Ltmp13
	.long	Lset19
	.byte	1                       ##   On action: 1
Lset20 = Ltmp12-Lfunc_begin1            ## >> Call Site 6 <<
	.long	Lset20
Lset21 = Lfunc_end1-Ltmp12              ##   Call between Ltmp12 and Lfunc_end1
	.long	Lset21
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.byte	1                       ## >> Action Record 1 <<
                                        ##   Catch TypeInfo 1
	.byte	0                       ##   No further actions
                                        ## >> Catch TypeInfos <<
	.long	0                       ## TypeInfo 1
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN3dsa16__deque_iteratorIiRiPiEC2Ev
	.weak_def_can_be_hidden	__ZN3dsa16__deque_iteratorIiRiPiEC2Ev
	.p2align	4, 0x90
__ZN3dsa16__deque_iteratorIiRiPiEC2Ev:  ## @_ZN3dsa16__deque_iteratorIiRiPiEC2Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi21:
	.cfi_def_cfa_offset 16
Lcfi22:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi23:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	$0, (%rdi)
	movq	$0, 8(%rdi)
	movq	$0, 16(%rdi)
	movq	$0, 24(%rdi)
	popq	%rbp
	retq
	.cfi_endproc

	.p2align	4, 0x90
__ZN3dsaL16__deque_buf_sizeEm:          ## @_ZN3dsaL16__deque_buf_sizeEm
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi24:
	.cfi_def_cfa_offset 16
Lcfi25:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi26:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	cmpq	$512, -8(%rbp)          ## imm = 0x200
	jae	LBB8_2
## BB#1:
	movl	$512, %eax              ## imm = 0x200
                                        ## kill: %RAX<def> %EAX<kill>
	xorl	%ecx, %ecx
	movl	%ecx, %edx
	divq	-8(%rbp)
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	jmp	LBB8_3
LBB8_2:
	movl	$1, %eax
	movl	%eax, %ecx
	movq	%rcx, -16(%rbp)         ## 8-byte Spill
	jmp	LBB8_3
LBB8_3:
	movq	-16(%rbp), %rax         ## 8-byte Reload
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa3maxImEERKT_S3_S3_
	.weak_definition	__ZN3dsa3maxImEERKT_S3_S3_
	.p2align	4, 0x90
__ZN3dsa3maxImEERKT_S3_S3_:             ## @_ZN3dsa3maxImEERKT_S3_S3_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi27:
	.cfi_def_cfa_offset 16
Lcfi28:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi29:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
## BB#1:
	jmp	LBB9_2
LBB9_2:
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	-16(%rbp), %rcx
	cmpq	(%rcx), %rax
	jae	LBB9_4
## BB#3:
	movq	-16(%rbp), %rax
	movq	%rax, -24(%rbp)         ## 8-byte Spill
	jmp	LBB9_5
LBB9_4:
	movq	-8(%rbp), %rax
	movq	%rax, -24(%rbp)         ## 8-byte Spill
LBB9_5:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE16__m_allocate_mapEm
	.weak_definition	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE16__m_allocate_mapEm
	.p2align	4, 0x90
__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE16__m_allocate_mapEm: ## @_ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE16__m_allocate_mapEm
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi30:
	.cfi_def_cfa_offset 16
Lcfi31:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi32:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdi
	callq	__ZN3dsa12simple_allocIPiNS_24__default_alloc_templateILb0ELi0EEEE8allocateEm
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE16__m_create_nodesEPPiS5_
	.weak_definition	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE16__m_create_nodesEPPiS5_
	.p2align	4, 0x90
__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE16__m_create_nodesEPPiS5_: ## @_ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE16__m_create_nodesEPPiS5_
Lfunc_begin2:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception2
## BB#0:
	pushq	%rbp
Lcfi33:
	.cfi_def_cfa_offset 16
Lcfi34:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi35:
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rdx
	movq	-16(%rbp), %rsi
	movq	%rsi, -32(%rbp)
	movq	%rdx, -56(%rbp)         ## 8-byte Spill
LBB11_1:                                ## =>This Inner Loop Header: Depth=1
	movq	-32(%rbp), %rax
	cmpq	-24(%rbp), %rax
	jae	LBB11_8
## BB#2:                                ##   in Loop: Header=BB11_1 Depth=1
Ltmp14:
	movq	-56(%rbp), %rdi         ## 8-byte Reload
	callq	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE17__m_allocate_nodeEv
Ltmp15:
	movq	%rax, -64(%rbp)         ## 8-byte Spill
	jmp	LBB11_3
LBB11_3:                                ##   in Loop: Header=BB11_1 Depth=1
	movq	-32(%rbp), %rax
	movq	-64(%rbp), %rcx         ## 8-byte Reload
	movq	%rcx, (%rax)
## BB#4:                                ##   in Loop: Header=BB11_1 Depth=1
	movq	-32(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -32(%rbp)
	jmp	LBB11_1
LBB11_5:
Ltmp16:
	movl	%edx, %ecx
	movq	%rax, -40(%rbp)
	movl	%ecx, -44(%rbp)
## BB#6:
	movq	-40(%rbp), %rdi
	callq	___cxa_begin_catch
	movq	-16(%rbp), %rsi
	movq	-32(%rbp), %rdx
Ltmp17:
	movq	-56(%rbp), %rdi         ## 8-byte Reload
	movq	%rax, -72(%rbp)         ## 8-byte Spill
	callq	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE17__m_destroy_nodesEPPiS5_
Ltmp18:
	jmp	LBB11_7
LBB11_7:
Ltmp19:
	callq	___cxa_rethrow
Ltmp20:
	jmp	LBB11_14
LBB11_8:
	jmp	LBB11_11
LBB11_9:
Ltmp21:
	movl	%edx, %ecx
	movq	%rax, -40(%rbp)
	movl	%ecx, -44(%rbp)
Ltmp22:
	callq	___cxa_end_catch
Ltmp23:
	jmp	LBB11_10
LBB11_10:
	jmp	LBB11_12
LBB11_11:
	addq	$80, %rsp
	popq	%rbp
	retq
LBB11_12:
	movq	-40(%rbp), %rdi
	callq	__Unwind_Resume
LBB11_13:
Ltmp24:
	movl	%edx, %ecx
	movq	%rax, %rdi
	movl	%ecx, -76(%rbp)         ## 4-byte Spill
	callq	___clang_call_terminate
LBB11_14:
Lfunc_end2:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table11:
Lexception2:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	73                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	65                      ## Call site table length
Lset22 = Ltmp14-Lfunc_begin2            ## >> Call Site 1 <<
	.long	Lset22
Lset23 = Ltmp15-Ltmp14                  ##   Call between Ltmp14 and Ltmp15
	.long	Lset23
Lset24 = Ltmp16-Lfunc_begin2            ##     jumps to Ltmp16
	.long	Lset24
	.byte	1                       ##   On action: 1
Lset25 = Ltmp15-Lfunc_begin2            ## >> Call Site 2 <<
	.long	Lset25
Lset26 = Ltmp17-Ltmp15                  ##   Call between Ltmp15 and Ltmp17
	.long	Lset26
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset27 = Ltmp17-Lfunc_begin2            ## >> Call Site 3 <<
	.long	Lset27
Lset28 = Ltmp20-Ltmp17                  ##   Call between Ltmp17 and Ltmp20
	.long	Lset28
Lset29 = Ltmp21-Lfunc_begin2            ##     jumps to Ltmp21
	.long	Lset29
	.byte	0                       ##   On action: cleanup
Lset30 = Ltmp22-Lfunc_begin2            ## >> Call Site 4 <<
	.long	Lset30
Lset31 = Ltmp23-Ltmp22                  ##   Call between Ltmp22 and Ltmp23
	.long	Lset31
Lset32 = Ltmp24-Lfunc_begin2            ##     jumps to Ltmp24
	.long	Lset32
	.byte	1                       ##   On action: 1
Lset33 = Ltmp23-Lfunc_begin2            ## >> Call Site 5 <<
	.long	Lset33
Lset34 = Lfunc_end2-Ltmp23              ##   Call between Ltmp23 and Lfunc_end2
	.long	Lset34
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.byte	1                       ## >> Action Record 1 <<
                                        ##   Catch TypeInfo 1
	.byte	0                       ##   No further actions
                                        ## >> Catch TypeInfos <<
	.long	0                       ## TypeInfo 1
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE18__m_deallocate_mapEPPim
	.weak_definition	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE18__m_deallocate_mapEPPim
	.p2align	4, 0x90
__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE18__m_deallocate_mapEPPim: ## @_ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE18__m_deallocate_mapEPPim
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi36:
	.cfi_def_cfa_offset 16
Lcfi37:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi38:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rdi
	movq	-24(%rbp), %rsi
	callq	__ZN3dsa12simple_allocIPiNS_24__default_alloc_templateILb0ELi0EEEE10deallocateEPS1_m
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.private_extern	___clang_call_terminate
	.globl	___clang_call_terminate
	.weak_definition	___clang_call_terminate
	.p2align	4, 0x90
___clang_call_terminate:                ## @__clang_call_terminate
## BB#0:
	pushq	%rax
	callq	___cxa_begin_catch
	movq	%rax, (%rsp)            ## 8-byte Spill
	callq	__ZSt9terminatev

	.globl	__ZN3dsa16__deque_iteratorIiRiPiE12__m_set_nodeEPS2_
	.weak_definition	__ZN3dsa16__deque_iteratorIiRiPiE12__m_set_nodeEPS2_
	.p2align	4, 0x90
__ZN3dsa16__deque_iteratorIiRiPiE12__m_set_nodeEPS2_: ## @_ZN3dsa16__deque_iteratorIiRiPiE12__m_set_nodeEPS2_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi39:
	.cfi_def_cfa_offset 16
Lcfi40:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi41:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rsi
	movq	-16(%rbp), %rdi
	movq	%rdi, 24(%rsi)
	movq	-16(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rdi, 8(%rsi)
	movq	8(%rsi), %rdi
	movq	%rsi, -24(%rbp)         ## 8-byte Spill
	movq	%rdi, -32(%rbp)         ## 8-byte Spill
	callq	__ZN3dsa16__deque_iteratorIiRiPiE15__s_buffer_sizeEv
	shlq	$2, %rax
	movq	-32(%rbp), %rsi         ## 8-byte Reload
	addq	%rax, %rsi
	movq	-24(%rbp), %rax         ## 8-byte Reload
	movq	%rsi, 16(%rax)
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa12simple_allocIPiNS_24__default_alloc_templateILb0ELi0EEEE8allocateEm
	.weak_definition	__ZN3dsa12simple_allocIPiNS_24__default_alloc_templateILb0ELi0EEEE8allocateEm
	.p2align	4, 0x90
__ZN3dsa12simple_allocIPiNS_24__default_alloc_templateILb0ELi0EEEE8allocateEm: ## @_ZN3dsa12simple_allocIPiNS_24__default_alloc_templateILb0ELi0EEEE8allocateEm
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi42:
	.cfi_def_cfa_offset 16
Lcfi43:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi44:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rdi, -8(%rbp)
	cmpq	-8(%rbp), %rcx
	jne	LBB15_2
## BB#1:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rcx, -16(%rbp)         ## 8-byte Spill
	jmp	LBB15_3
LBB15_2:
	movq	-8(%rbp), %rax
	shlq	$3, %rax
	movq	%rax, %rdi
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE8allocateEm
	movq	%rax, -16(%rbp)         ## 8-byte Spill
LBB15_3:
	movq	-16(%rbp), %rax         ## 8-byte Reload
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa24__default_alloc_templateILb0ELi0EE8allocateEm
	.weak_definition	__ZN3dsa24__default_alloc_templateILb0ELi0EE8allocateEm
	.p2align	4, 0x90
__ZN3dsa24__default_alloc_templateILb0ELi0EE8allocateEm: ## @_ZN3dsa24__default_alloc_templateILb0ELi0EE8allocateEm
Lfunc_begin3:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception3
## BB#0:
	pushq	%rbp
Lcfi45:
	.cfi_def_cfa_offset 16
Lcfi46:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi47:
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movq	%rdi, -8(%rbp)
	movq	$0, -16(%rbp)
	cmpq	$128, -8(%rbp)
	jbe	LBB16_2
## BB#1:
	movq	-8(%rbp), %rdi
	callq	__ZN3dsa23__malloc_alloc_templateILi0EE8allocateEm
	movq	%rax, -16(%rbp)
	jmp	LBB16_9
LBB16_2:
	movq	-8(%rbp), %rdi
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE17_S_freelist_indexEm
	leaq	-32(%rbp), %rdi
	movq	__ZN3dsa24__default_alloc_templateILb0ELi0EE12_S_free_listE@GOTPCREL(%rip), %rcx
	shlq	$3, %rax
	addq	%rax, %rcx
	movq	%rcx, -24(%rbp)
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockC1Ev
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -40(%rbp)
	cmpq	$0, -40(%rbp)
	jne	LBB16_7
## BB#3:
	movq	-8(%rbp), %rdi
Ltmp25:
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE11_S_round_upEm
Ltmp26:
	movq	%rax, -64(%rbp)         ## 8-byte Spill
	jmp	LBB16_4
LBB16_4:
Ltmp27:
	movq	-64(%rbp), %rdi         ## 8-byte Reload
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE9_S_refillEm
Ltmp28:
	movq	%rax, -72(%rbp)         ## 8-byte Spill
	jmp	LBB16_5
LBB16_5:
	movq	-72(%rbp), %rax         ## 8-byte Reload
	movq	%rax, -16(%rbp)
	jmp	LBB16_8
LBB16_6:
Ltmp29:
	leaq	-32(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -48(%rbp)
	movl	%ecx, -52(%rbp)
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockD1Ev
	jmp	LBB16_10
LBB16_7:
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	-24(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-40(%rbp), %rax
	movq	%rax, -16(%rbp)
LBB16_8:
	leaq	-32(%rbp), %rdi
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockD1Ev
LBB16_9:
	movq	-16(%rbp), %rax
	addq	$80, %rsp
	popq	%rbp
	retq
LBB16_10:
	movq	-48(%rbp), %rdi
	callq	__Unwind_Resume
Lfunc_end3:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table16:
Lexception3:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset35 = Lfunc_begin3-Lfunc_begin3      ## >> Call Site 1 <<
	.long	Lset35
Lset36 = Ltmp25-Lfunc_begin3            ##   Call between Lfunc_begin3 and Ltmp25
	.long	Lset36
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset37 = Ltmp25-Lfunc_begin3            ## >> Call Site 2 <<
	.long	Lset37
Lset38 = Ltmp28-Ltmp25                  ##   Call between Ltmp25 and Ltmp28
	.long	Lset38
Lset39 = Ltmp29-Lfunc_begin3            ##     jumps to Ltmp29
	.long	Lset39
	.byte	0                       ##   On action: cleanup
Lset40 = Ltmp28-Lfunc_begin3            ## >> Call Site 3 <<
	.long	Lset40
Lset41 = Lfunc_end3-Ltmp28              ##   Call between Ltmp28 and Lfunc_end3
	.long	Lset41
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN3dsa23__malloc_alloc_templateILi0EE8allocateEm
	.weak_definition	__ZN3dsa23__malloc_alloc_templateILi0EE8allocateEm
	.p2align	4, 0x90
__ZN3dsa23__malloc_alloc_templateILi0EE8allocateEm: ## @_ZN3dsa23__malloc_alloc_templateILi0EE8allocateEm
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi48:
	.cfi_def_cfa_offset 16
Lcfi49:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi50:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	_malloc
	xorl	%ecx, %ecx
	movl	%ecx, %edi
	movq	%rax, -16(%rbp)
	cmpq	-16(%rbp), %rdi
	jne	LBB17_2
## BB#1:
	movq	-8(%rbp), %rdi
	callq	__ZN3dsa23__malloc_alloc_templateILi0EE13_S_oom_mallocEm
	movq	%rax, -16(%rbp)
LBB17_2:
	movq	-16(%rbp), %rax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa24__default_alloc_templateILb0ELi0EE17_S_freelist_indexEm
	.weak_definition	__ZN3dsa24__default_alloc_templateILb0ELi0EE17_S_freelist_indexEm
	.p2align	4, 0x90
__ZN3dsa24__default_alloc_templateILb0ELi0EE17_S_freelist_indexEm: ## @_ZN3dsa24__default_alloc_templateILb0ELi0EE17_S_freelist_indexEm
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi51:
	.cfi_def_cfa_offset 16
Lcfi52:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi53:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	addq	$8, %rdi
	subq	$1, %rdi
	shrq	$3, %rdi
	subq	$1, %rdi
	movq	%rdi, %rax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockC1Ev
	.weak_def_can_be_hidden	__ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockC1Ev
	.p2align	4, 0x90
__ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockC1Ev: ## @_ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockC1Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi54:
	.cfi_def_cfa_offset 16
Lcfi55:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi56:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockC2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa24__default_alloc_templateILb0ELi0EE9_S_refillEm
	.weak_definition	__ZN3dsa24__default_alloc_templateILb0ELi0EE9_S_refillEm
	.p2align	4, 0x90
__ZN3dsa24__default_alloc_templateILb0ELi0EE9_S_refillEm: ## @_ZN3dsa24__default_alloc_templateILb0ELi0EE9_S_refillEm
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi57:
	.cfi_def_cfa_offset 16
Lcfi58:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi59:
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	leaq	-20(%rbp), %rsi
	movq	%rdi, -16(%rbp)
	movl	$20, -20(%rbp)
	movq	-16(%rbp), %rdi
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE14_S_chunk_allocEmRi
	movl	$1, %ecx
	movq	%rax, -32(%rbp)
	cmpl	-20(%rbp), %ecx
	jne	LBB20_2
## BB#1:
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	LBB20_9
LBB20_2:
	movq	-16(%rbp), %rdi
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE17_S_freelist_indexEm
	movq	__ZN3dsa24__default_alloc_templateILb0ELi0EE12_S_free_listE@GOTPCREL(%rip), %rdi
	shlq	$3, %rax
	addq	%rax, %rdi
	movq	%rdi, -40(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -48(%rbp)
	movq	-32(%rbp), %rax
	addq	-16(%rbp), %rax
	movq	%rax, -64(%rbp)
	movq	-40(%rbp), %rdi
	movq	%rax, (%rdi)
	movl	$2, -68(%rbp)
LBB20_3:                                ## =>This Inner Loop Header: Depth=1
	movq	-64(%rbp), %rax
	movq	%rax, -56(%rbp)
	movq	-64(%rbp), %rax
	addq	-16(%rbp), %rax
	movq	%rax, -64(%rbp)
	movl	-20(%rbp), %ecx
	cmpl	-68(%rbp), %ecx
	jne	LBB20_5
## BB#4:
	movq	-56(%rbp), %rax
	movq	$0, (%rax)
	jmp	LBB20_8
LBB20_5:                                ##   in Loop: Header=BB20_3 Depth=1
	movq	-64(%rbp), %rax
	movq	-56(%rbp), %rcx
	movq	%rax, (%rcx)
## BB#6:                                ##   in Loop: Header=BB20_3 Depth=1
	jmp	LBB20_7
LBB20_7:                                ##   in Loop: Header=BB20_3 Depth=1
	movl	-68(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -68(%rbp)
	jmp	LBB20_3
LBB20_8:
	movq	-48(%rbp), %rax
	movq	%rax, -8(%rbp)
LBB20_9:
	movq	-8(%rbp), %rax
	addq	$80, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa24__default_alloc_templateILb0ELi0EE11_S_round_upEm
	.weak_definition	__ZN3dsa24__default_alloc_templateILb0ELi0EE11_S_round_upEm
	.p2align	4, 0x90
__ZN3dsa24__default_alloc_templateILb0ELi0EE11_S_round_upEm: ## @_ZN3dsa24__default_alloc_templateILb0ELi0EE11_S_round_upEm
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi60:
	.cfi_def_cfa_offset 16
Lcfi61:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi62:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	addq	$8, %rdi
	subq	$1, %rdi
	andq	$-8, %rdi
	movq	%rdi, %rax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockD1Ev
	.weak_def_can_be_hidden	__ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockD1Ev
	.p2align	4, 0x90
__ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockD1Ev: ## @_ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockD1Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi63:
	.cfi_def_cfa_offset 16
Lcfi64:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi65:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockD2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa23__malloc_alloc_templateILi0EE13_S_oom_mallocEm
	.weak_definition	__ZN3dsa23__malloc_alloc_templateILi0EE13_S_oom_mallocEm
	.p2align	4, 0x90
__ZN3dsa23__malloc_alloc_templateILi0EE13_S_oom_mallocEm: ## @_ZN3dsa23__malloc_alloc_templateILi0EE13_S_oom_mallocEm
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi66:
	.cfi_def_cfa_offset 16
Lcfi67:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi68:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
LBB23_1:                                ## =>This Inner Loop Header: Depth=1
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	__ZN3dsa23__malloc_alloc_templateILi0EE26__malloc_alloc_oom_handlerE@GOTPCREL(%rip), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, -16(%rbp)
	cmpq	-16(%rbp), %rcx
	jne	LBB23_3
## BB#2:
	movl	$8, %eax
	movl	%eax, %edi
	callq	___cxa_allocate_exception
	movq	%rax, %rdi
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	callq	__ZNSt9bad_allocC1Ev
	movq	__ZTISt9bad_alloc@GOTPCREL(%rip), %rax
	movq	__ZNSt9bad_allocD1Ev@GOTPCREL(%rip), %rdi
	movq	-32(%rbp), %rcx         ## 8-byte Reload
	movq	%rdi, -40(%rbp)         ## 8-byte Spill
	movq	%rcx, %rdi
	movq	%rax, %rsi
	movq	-40(%rbp), %rdx         ## 8-byte Reload
	callq	___cxa_throw
LBB23_3:                                ##   in Loop: Header=BB23_1 Depth=1
	callq	*-16(%rbp)
	movq	-8(%rbp), %rdi
	callq	_malloc
	movq	%rax, -24(%rbp)
	cmpq	$0, -24(%rbp)
	je	LBB23_5
## BB#4:
	movq	-24(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	retq
LBB23_5:                                ##   in Loop: Header=BB23_1 Depth=1
	jmp	LBB23_1
	.cfi_endproc

	.globl	__ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockC2Ev
	.weak_def_can_be_hidden	__ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockC2Ev
	.p2align	4, 0x90
__ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockC2Ev: ## @_ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockC2Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi69:
	.cfi_def_cfa_offset 16
Lcfi70:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi71:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa24__default_alloc_templateILb0ELi0EE14_S_chunk_allocEmRi
	.weak_definition	__ZN3dsa24__default_alloc_templateILb0ELi0EE14_S_chunk_allocEmRi
	.p2align	4, 0x90
__ZN3dsa24__default_alloc_templateILb0ELi0EE14_S_chunk_allocEmRi: ## @_ZN3dsa24__default_alloc_templateILb0ELi0EE14_S_chunk_allocEmRi
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi72:
	.cfi_def_cfa_offset 16
Lcfi73:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi74:
	.cfi_def_cfa_register %rbp
	subq	$112, %rsp
	movq	__ZN3dsa24__default_alloc_templateILb0ELi0EE13_S_start_freeE@GOTPCREL(%rip), %rax
	movq	__ZN3dsa24__default_alloc_templateILb0ELi0EE11_S_end_freeE@GOTPCREL(%rip), %rcx
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	-16(%rbp), %rsi
	movq	-24(%rbp), %rdi
	movslq	(%rdi), %rdi
	imulq	%rdi, %rsi
	movq	%rsi, -40(%rbp)
	movq	(%rcx), %rcx
	movq	(%rax), %rax
	subq	%rax, %rcx
	movq	%rcx, -48(%rbp)
	movq	-40(%rbp), %rax
	cmpq	-48(%rbp), %rax
	ja	LBB25_2
## BB#1:
	movq	__ZN3dsa24__default_alloc_templateILb0ELi0EE13_S_start_freeE@GOTPCREL(%rip), %rax
	movq	(%rax), %rcx
	movq	%rcx, -32(%rbp)
	movq	-40(%rbp), %rcx
	addq	(%rax), %rcx
	movq	%rcx, (%rax)
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	LBB25_16
LBB25_2:
	movq	-16(%rbp), %rax
	cmpq	-48(%rbp), %rax
	ja	LBB25_4
## BB#3:
	movq	__ZN3dsa24__default_alloc_templateILb0ELi0EE13_S_start_freeE@GOTPCREL(%rip), %rax
	movq	-48(%rbp), %rcx
	movq	%rax, -96(%rbp)         ## 8-byte Spill
	movq	%rcx, %rax
	xorl	%edx, %edx
                                        ## kill: %RDX<def> %EDX<kill>
	divq	-16(%rbp)
	movl	%eax, %esi
	movq	-24(%rbp), %rax
	movl	%esi, (%rax)
	movq	-16(%rbp), %rax
	movq	-24(%rbp), %rcx
	movslq	(%rcx), %rcx
	imulq	%rcx, %rax
	movq	%rax, -40(%rbp)
	movq	-96(%rbp), %rax         ## 8-byte Reload
	movq	(%rax), %rcx
	movq	%rcx, -32(%rbp)
	movq	-40(%rbp), %rcx
	addq	(%rax), %rcx
	movq	%rcx, (%rax)
	movq	-32(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	jmp	LBB25_16
LBB25_4:
	jmp	LBB25_5
LBB25_5:
	movq	__ZN3dsa24__default_alloc_templateILb0ELi0EE12_S_heap_sizeE@GOTPCREL(%rip), %rax
	movq	-40(%rbp), %rcx
	shlq	$1, %rcx
	movq	(%rax), %rax
	shrq	$4, %rax
	movq	%rax, %rdi
	movq	%rcx, -104(%rbp)        ## 8-byte Spill
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE11_S_round_upEm
	movq	-104(%rbp), %rcx        ## 8-byte Reload
	addq	%rax, %rcx
	movq	%rcx, -56(%rbp)
	cmpq	$0, -48(%rbp)
	jbe	LBB25_7
## BB#6:
	movq	-48(%rbp), %rdi
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE17_S_freelist_indexEm
	movq	__ZN3dsa24__default_alloc_templateILb0ELi0EE13_S_start_freeE@GOTPCREL(%rip), %rdi
	movq	__ZN3dsa24__default_alloc_templateILb0ELi0EE12_S_free_listE@GOTPCREL(%rip), %rcx
	shlq	$3, %rax
	addq	%rax, %rcx
	movq	%rcx, -64(%rbp)
	movq	-64(%rbp), %rax
	movq	(%rax), %rax
	movq	(%rdi), %rcx
	movq	%rax, (%rcx)
	movq	(%rdi), %rax
	movq	-64(%rbp), %rcx
	movq	%rax, (%rcx)
LBB25_7:
	movq	-56(%rbp), %rdi
	callq	_malloc
	xorl	%ecx, %ecx
	movl	%ecx, %edi
	movq	__ZN3dsa24__default_alloc_templateILb0ELi0EE13_S_start_freeE@GOTPCREL(%rip), %rdx
	movq	%rax, (%rdx)
	cmpq	(%rdx), %rdi
	jne	LBB25_15
## BB#8:
	movq	-16(%rbp), %rax
	movq	%rax, -72(%rbp)
LBB25_9:                                ## =>This Inner Loop Header: Depth=1
	cmpq	$128, -72(%rbp)
	ja	LBB25_14
## BB#10:                               ##   in Loop: Header=BB25_9 Depth=1
	movq	-72(%rbp), %rdi
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE17_S_freelist_indexEm
	xorl	%ecx, %ecx
	movl	%ecx, %edi
	movq	__ZN3dsa24__default_alloc_templateILb0ELi0EE12_S_free_listE@GOTPCREL(%rip), %rdx
	shlq	$3, %rax
	addq	%rax, %rdx
	movq	%rdx, -80(%rbp)
	movq	-80(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -88(%rbp)
	cmpq	-88(%rbp), %rdi
	je	LBB25_12
## BB#11:
	movq	__ZN3dsa24__default_alloc_templateILb0ELi0EE11_S_end_freeE@GOTPCREL(%rip), %rax
	movq	__ZN3dsa24__default_alloc_templateILb0ELi0EE13_S_start_freeE@GOTPCREL(%rip), %rcx
	movq	-88(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-80(%rbp), %rsi
	movq	%rdx, (%rsi)
	movq	-88(%rbp), %rdx
	movq	%rdx, (%rcx)
	movq	(%rcx), %rcx
	addq	-72(%rbp), %rcx
	movq	%rcx, (%rax)
	movq	-16(%rbp), %rdi
	movq	-24(%rbp), %rsi
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE14_S_chunk_allocEmRi
	movq	%rax, -8(%rbp)
	jmp	LBB25_16
LBB25_12:                               ##   in Loop: Header=BB25_9 Depth=1
	jmp	LBB25_13
LBB25_13:                               ##   in Loop: Header=BB25_9 Depth=1
	movq	-72(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -72(%rbp)
	jmp	LBB25_9
LBB25_14:
	movq	__ZN3dsa24__default_alloc_templateILb0ELi0EE11_S_end_freeE@GOTPCREL(%rip), %rax
	movq	$0, (%rax)
	movq	-56(%rbp), %rdi
	callq	__ZN3dsa23__malloc_alloc_templateILi0EE8allocateEm
	movq	__ZN3dsa24__default_alloc_templateILb0ELi0EE13_S_start_freeE@GOTPCREL(%rip), %rdi
	movq	%rax, (%rdi)
LBB25_15:
	movq	__ZN3dsa24__default_alloc_templateILb0ELi0EE11_S_end_freeE@GOTPCREL(%rip), %rax
	movq	__ZN3dsa24__default_alloc_templateILb0ELi0EE13_S_start_freeE@GOTPCREL(%rip), %rcx
	movq	__ZN3dsa24__default_alloc_templateILb0ELi0EE12_S_heap_sizeE@GOTPCREL(%rip), %rdx
	movq	-56(%rbp), %rsi
	addq	(%rdx), %rsi
	movq	%rsi, (%rdx)
	movq	(%rcx), %rcx
	addq	-56(%rbp), %rcx
	movq	%rcx, (%rax)
	movq	-16(%rbp), %rdi
	movq	-24(%rbp), %rsi
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE14_S_chunk_allocEmRi
	movq	%rax, -8(%rbp)
LBB25_16:
	movq	-8(%rbp), %rax
	addq	$112, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockD2Ev
	.weak_def_can_be_hidden	__ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockD2Ev
	.p2align	4, 0x90
__ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockD2Ev: ## @_ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockD2Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi75:
	.cfi_def_cfa_offset 16
Lcfi76:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi77:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE17__m_allocate_nodeEv
	.weak_definition	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE17__m_allocate_nodeEv
	.p2align	4, 0x90
__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE17__m_allocate_nodeEv: ## @_ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE17__m_allocate_nodeEv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi78:
	.cfi_def_cfa_offset 16
Lcfi79:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi80:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$4, %eax
	movl	%eax, %ecx
	movq	%rdi, -8(%rbp)
	movq	%rcx, %rdi
	callq	__ZN3dsaL16__deque_buf_sizeEm
	movq	%rax, %rdi
	callq	__ZN3dsa12simple_allocIiNS_24__default_alloc_templateILb0ELi0EEEE8allocateEm
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE17__m_destroy_nodesEPPiS5_
	.weak_definition	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE17__m_destroy_nodesEPPiS5_
	.p2align	4, 0x90
__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE17__m_destroy_nodesEPPiS5_: ## @_ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE17__m_destroy_nodesEPPiS5_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi81:
	.cfi_def_cfa_offset 16
Lcfi82:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi83:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rdx
	movq	%rdx, -32(%rbp)
	movq	%rdi, -40(%rbp)         ## 8-byte Spill
LBB28_1:                                ## =>This Inner Loop Header: Depth=1
	movq	-32(%rbp), %rax
	cmpq	-24(%rbp), %rax
	jae	LBB28_4
## BB#2:                                ##   in Loop: Header=BB28_1 Depth=1
	movq	-32(%rbp), %rax
	movq	(%rax), %rsi
	movq	-40(%rbp), %rdi         ## 8-byte Reload
	callq	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE19__m_deallocate_nodeEPi
## BB#3:                                ##   in Loop: Header=BB28_1 Depth=1
	movq	-32(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -32(%rbp)
	jmp	LBB28_1
LBB28_4:
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa12simple_allocIiNS_24__default_alloc_templateILb0ELi0EEEE8allocateEm
	.weak_definition	__ZN3dsa12simple_allocIiNS_24__default_alloc_templateILb0ELi0EEEE8allocateEm
	.p2align	4, 0x90
__ZN3dsa12simple_allocIiNS_24__default_alloc_templateILb0ELi0EEEE8allocateEm: ## @_ZN3dsa12simple_allocIiNS_24__default_alloc_templateILb0ELi0EEEE8allocateEm
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi84:
	.cfi_def_cfa_offset 16
Lcfi85:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi86:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rdi, -8(%rbp)
	cmpq	-8(%rbp), %rcx
	jne	LBB29_2
## BB#1:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rcx, -16(%rbp)         ## 8-byte Spill
	jmp	LBB29_3
LBB29_2:
	movq	-8(%rbp), %rax
	shlq	$2, %rax
	movq	%rax, %rdi
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE8allocateEm
	movq	%rax, -16(%rbp)         ## 8-byte Spill
LBB29_3:
	movq	-16(%rbp), %rax         ## 8-byte Reload
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE19__m_deallocate_nodeEPi
	.weak_definition	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE19__m_deallocate_nodeEPi
	.p2align	4, 0x90
__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE19__m_deallocate_nodeEPi: ## @_ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE19__m_deallocate_nodeEPi
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi87:
	.cfi_def_cfa_offset 16
Lcfi88:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi89:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$4, %eax
	movl	%eax, %ecx
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdi
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
	movq	%rcx, %rdi
	callq	__ZN3dsaL16__deque_buf_sizeEm
	movq	-24(%rbp), %rdi         ## 8-byte Reload
	movq	%rax, %rsi
	callq	__ZN3dsa12simple_allocIiNS_24__default_alloc_templateILb0ELi0EEEE10deallocateEPim
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa12simple_allocIiNS_24__default_alloc_templateILb0ELi0EEEE10deallocateEPim
	.weak_definition	__ZN3dsa12simple_allocIiNS_24__default_alloc_templateILb0ELi0EEEE10deallocateEPim
	.p2align	4, 0x90
__ZN3dsa12simple_allocIiNS_24__default_alloc_templateILb0ELi0EEEE10deallocateEPim: ## @_ZN3dsa12simple_allocIiNS_24__default_alloc_templateILb0ELi0EEEE10deallocateEPim
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi90:
	.cfi_def_cfa_offset 16
Lcfi91:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi92:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	-16(%rbp), %rcx
	je	LBB31_2
## BB#1:
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rcx
	shlq	$2, %rcx
	movq	%rax, %rdi
	movq	%rcx, %rsi
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE10deallocateEPvm
LBB31_2:
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa24__default_alloc_templateILb0ELi0EE10deallocateEPvm
	.weak_definition	__ZN3dsa24__default_alloc_templateILb0ELi0EE10deallocateEPvm
	.p2align	4, 0x90
__ZN3dsa24__default_alloc_templateILb0ELi0EE10deallocateEPvm: ## @_ZN3dsa24__default_alloc_templateILb0ELi0EE10deallocateEPvm
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi93:
	.cfi_def_cfa_offset 16
Lcfi94:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi95:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	$128, -16(%rbp)
	jbe	LBB32_2
## BB#1:
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	callq	__ZN3dsa23__malloc_alloc_templateILi0EE10deallocateEPvm
	jmp	LBB32_3
LBB32_2:
	movq	-16(%rbp), %rdi
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE17_S_freelist_indexEm
	leaq	-40(%rbp), %rdi
	movq	__ZN3dsa24__default_alloc_templateILb0ELi0EE12_S_free_listE@GOTPCREL(%rip), %rcx
	shlq	$3, %rax
	addq	%rax, %rcx
	movq	%rcx, -24(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, -32(%rbp)
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockC1Ev
	leaq	-40(%rbp), %rdi
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	-32(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rcx
	movq	%rax, (%rcx)
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockD1Ev
LBB32_3:
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa23__malloc_alloc_templateILi0EE10deallocateEPvm
	.weak_definition	__ZN3dsa23__malloc_alloc_templateILi0EE10deallocateEPvm
	.p2align	4, 0x90
__ZN3dsa23__malloc_alloc_templateILi0EE10deallocateEPvm: ## @_ZN3dsa23__malloc_alloc_templateILi0EE10deallocateEPvm
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi96:
	.cfi_def_cfa_offset 16
Lcfi97:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi98:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rdi
	callq	_free
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa12simple_allocIPiNS_24__default_alloc_templateILb0ELi0EEEE10deallocateEPS1_m
	.weak_definition	__ZN3dsa12simple_allocIPiNS_24__default_alloc_templateILb0ELi0EEEE10deallocateEPS1_m
	.p2align	4, 0x90
__ZN3dsa12simple_allocIPiNS_24__default_alloc_templateILb0ELi0EEEE10deallocateEPS1_m: ## @_ZN3dsa12simple_allocIPiNS_24__default_alloc_templateILb0ELi0EEEE10deallocateEPS1_m
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi99:
	.cfi_def_cfa_offset 16
Lcfi100:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi101:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	-16(%rbp), %rcx
	je	LBB34_2
## BB#1:
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rcx
	shlq	$3, %rcx
	movq	%rax, %rdi
	movq	%rcx, %rsi
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE10deallocateEPvm
LBB34_2:
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa16__deque_iteratorIiRiPiE15__s_buffer_sizeEv
	.weak_definition	__ZN3dsa16__deque_iteratorIiRiPiE15__s_buffer_sizeEv
	.p2align	4, 0x90
__ZN3dsa16__deque_iteratorIiRiPiE15__s_buffer_sizeEv: ## @_ZN3dsa16__deque_iteratorIiRiPiE15__s_buffer_sizeEv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi102:
	.cfi_def_cfa_offset 16
Lcfi103:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi104:
	.cfi_def_cfa_register %rbp
	movl	$4, %eax
	movl	%eax, %edi
	callq	__ZN3dsaL16__deque_buf_sizeEm
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa5dequeIiNS_24__default_alloc_templateILb0ELi0EEEED2Ev
	.weak_def_can_be_hidden	__ZN3dsa5dequeIiNS_24__default_alloc_templateILb0ELi0EEEED2Ev
	.p2align	4, 0x90
__ZN3dsa5dequeIiNS_24__default_alloc_templateILb0ELi0EEEED2Ev: ## @_ZN3dsa5dequeIiNS_24__default_alloc_templateILb0ELi0EEEED2Ev
Lfunc_begin4:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception4
## BB#0:
	pushq	%rbp
Lcfi105:
	.cfi_def_cfa_offset 16
Lcfi106:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi107:
	.cfi_def_cfa_register %rbp
	subq	$96, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	%rdi, %rax
	addq	$16, %rax
Ltmp30:
	leaq	-40(%rbp), %rcx
	movq	%rdi, -96(%rbp)         ## 8-byte Spill
	movq	%rcx, %rdi
	movq	%rax, %rsi
	callq	__ZN3dsa16__deque_iteratorIiRiPiEC1ERKS3_
Ltmp31:
	jmp	LBB36_1
LBB36_1:
	movq	-96(%rbp), %rax         ## 8-byte Reload
	addq	$48, %rax
Ltmp32:
	leaq	-88(%rbp), %rdi
	movq	%rax, %rsi
	callq	__ZN3dsa16__deque_iteratorIiRiPiEC1ERKS3_
Ltmp33:
	jmp	LBB36_2
LBB36_2:
Ltmp34:
	leaq	-40(%rbp), %rdi
	leaq	-88(%rbp), %rsi
	callq	__ZN3dsa7destroyINS_16__deque_iteratorIiRiPiEEEEvT_S5_
Ltmp35:
	jmp	LBB36_3
LBB36_3:
	movq	-96(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEED2Ev
	addq	$96, %rsp
	popq	%rbp
	retq
LBB36_4:
Ltmp36:
	movl	%edx, %ecx
	movq	%rax, -48(%rbp)
	movl	%ecx, -52(%rbp)
	movq	-96(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEED2Ev
## BB#5:
	movq	-48(%rbp), %rdi
	callq	___clang_call_terminate
Lfunc_end4:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table36:
Lexception4:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	21                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	13                      ## Call site table length
Lset42 = Ltmp30-Lfunc_begin4            ## >> Call Site 1 <<
	.long	Lset42
Lset43 = Ltmp35-Ltmp30                  ##   Call between Ltmp30 and Ltmp35
	.long	Lset43
Lset44 = Ltmp36-Lfunc_begin4            ##     jumps to Ltmp36
	.long	Lset44
	.byte	1                       ##   On action: 1
	.byte	1                       ## >> Action Record 1 <<
                                        ##   Catch TypeInfo 1
	.byte	0                       ##   No further actions
                                        ## >> Catch TypeInfos <<
	.long	0                       ## TypeInfo 1
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN3dsa7destroyINS_16__deque_iteratorIiRiPiEEEEvT_S5_
	.weak_definition	__ZN3dsa7destroyINS_16__deque_iteratorIiRiPiEEEEvT_S5_
	.p2align	4, 0x90
__ZN3dsa7destroyINS_16__deque_iteratorIiRiPiEEEEvT_S5_: ## @_ZN3dsa7destroyINS_16__deque_iteratorIiRiPiEEEEvT_S5_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi108:
	.cfi_def_cfa_offset 16
Lcfi109:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi110:
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	leaq	-32(%rbp), %rax
	movq	%rdi, -72(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	-72(%rbp), %rax         ## 8-byte Reload
	movq	%rsi, -80(%rbp)         ## 8-byte Spill
	movq	%rax, %rsi
	callq	__ZN3dsa16__deque_iteratorIiRiPiEC1ERKS3_
	leaq	-64(%rbp), %rdi
	movq	-80(%rbp), %rsi         ## 8-byte Reload
	callq	__ZN3dsa16__deque_iteratorIiRiPiEC1ERKS3_
	leaq	-32(%rbp), %rdi
	leaq	-64(%rbp), %rsi
	callq	__ZN3dsa9__destroyINS_16__deque_iteratorIiRiPiEEEEvT_S5_
	addq	$80, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa16__deque_iteratorIiRiPiEC1ERKS3_
	.weak_def_can_be_hidden	__ZN3dsa16__deque_iteratorIiRiPiEC1ERKS3_
	.p2align	4, 0x90
__ZN3dsa16__deque_iteratorIiRiPiEC1ERKS3_: ## @_ZN3dsa16__deque_iteratorIiRiPiEC1ERKS3_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi111:
	.cfi_def_cfa_offset 16
Lcfi112:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi113:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	callq	__ZN3dsa16__deque_iteratorIiRiPiEC2ERKS3_
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEED2Ev
	.weak_def_can_be_hidden	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEED2Ev
	.p2align	4, 0x90
__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEED2Ev: ## @_ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEED2Ev
Lfunc_begin5:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception5
## BB#0:
	pushq	%rbp
Lcfi114:
	.cfi_def_cfa_offset 16
Lcfi115:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi116:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	cmpq	$0, (%rdi)
	movq	%rdi, -16(%rbp)         ## 8-byte Spill
	je	LBB39_4
## BB#1:
	movq	-16(%rbp), %rax         ## 8-byte Reload
	movq	40(%rax), %rsi
	movq	72(%rax), %rcx
	addq	$8, %rcx
Ltmp37:
	movq	%rax, %rdi
	movq	%rcx, %rdx
	callq	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE17__m_destroy_nodesEPPiS5_
Ltmp38:
	jmp	LBB39_2
LBB39_2:
	movq	-16(%rbp), %rax         ## 8-byte Reload
	movq	(%rax), %rsi
	movq	8(%rax), %rdx
Ltmp39:
	movq	%rax, %rdi
	callq	__ZN3dsa12__deque_baseIiNS_24__default_alloc_templateILb0ELi0EEEE18__m_deallocate_mapEPPim
Ltmp40:
	jmp	LBB39_3
LBB39_3:
	jmp	LBB39_4
LBB39_4:
	addq	$32, %rsp
	popq	%rbp
	retq
LBB39_5:
Ltmp41:
	movl	%edx, %ecx
	movq	%rax, %rdi
	movl	%ecx, -20(%rbp)         ## 4-byte Spill
	callq	___clang_call_terminate
Lfunc_end5:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table39:
Lexception5:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	21                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	13                      ## Call site table length
Lset45 = Ltmp37-Lfunc_begin5            ## >> Call Site 1 <<
	.long	Lset45
Lset46 = Ltmp40-Ltmp37                  ##   Call between Ltmp37 and Ltmp40
	.long	Lset46
Lset47 = Ltmp41-Lfunc_begin5            ##     jumps to Ltmp41
	.long	Lset47
	.byte	1                       ##   On action: 1
	.byte	1                       ## >> Action Record 1 <<
                                        ##   Catch TypeInfo 1
	.byte	0                       ##   No further actions
                                        ## >> Catch TypeInfos <<
	.long	0                       ## TypeInfo 1
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN3dsa9__destroyINS_16__deque_iteratorIiRiPiEEEEvT_S5_
	.weak_definition	__ZN3dsa9__destroyINS_16__deque_iteratorIiRiPiEEEEvT_S5_
	.p2align	4, 0x90
__ZN3dsa9__destroyINS_16__deque_iteratorIiRiPiEEEEvT_S5_: ## @_ZN3dsa9__destroyINS_16__deque_iteratorIiRiPiEEEEvT_S5_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi117:
	.cfi_def_cfa_offset 16
Lcfi118:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi119:
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	leaq	-32(%rbp), %rax
	movq	%rdi, -72(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	-72(%rbp), %rax         ## 8-byte Reload
	movq	%rsi, -80(%rbp)         ## 8-byte Spill
	movq	%rax, %rsi
	callq	__ZN3dsa16__deque_iteratorIiRiPiEC1ERKS3_
	leaq	-64(%rbp), %rdi
	movq	-80(%rbp), %rsi         ## 8-byte Reload
	callq	__ZN3dsa16__deque_iteratorIiRiPiEC1ERKS3_
	movq	-72(%rbp), %rdi         ## 8-byte Reload
	callq	__ZN3dsa10value_typeIiRiPiEEPT_RKNS_16__deque_iteratorIS3_T0_T1_EE
	leaq	-32(%rbp), %rdi
	leaq	-64(%rbp), %rsi
	movq	%rax, %rdx
	callq	__ZN3dsa9__destroyINS_16__deque_iteratorIiRiPiEEiEEvT_S5_PT0_
	addq	$80, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa9__destroyINS_16__deque_iteratorIiRiPiEEiEEvT_S5_PT0_
	.weak_definition	__ZN3dsa9__destroyINS_16__deque_iteratorIiRiPiEEiEEvT_S5_PT0_
	.p2align	4, 0x90
__ZN3dsa9__destroyINS_16__deque_iteratorIiRiPiEEiEEvT_S5_PT0_: ## @_ZN3dsa9__destroyINS_16__deque_iteratorIiRiPiEEiEEvT_S5_PT0_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi120:
	.cfi_def_cfa_offset 16
Lcfi121:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi122:
	.cfi_def_cfa_register %rbp
	subq	$96, %rsp
	leaq	-40(%rbp), %rax
	movq	%rdx, -8(%rbp)
	movq	%rdi, -88(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	-88(%rbp), %rax         ## 8-byte Reload
	movq	%rsi, -96(%rbp)         ## 8-byte Spill
	movq	%rax, %rsi
	callq	__ZN3dsa16__deque_iteratorIiRiPiEC1ERKS3_
	leaq	-72(%rbp), %rdi
	movq	-96(%rbp), %rsi         ## 8-byte Reload
	callq	__ZN3dsa16__deque_iteratorIiRiPiEC1ERKS3_
	leaq	-40(%rbp), %rdi
	leaq	-72(%rbp), %rsi
	callq	__ZN3dsa13__destroy_auxINS_16__deque_iteratorIiRiPiEEEEvT_S5_11__true_type
	addq	$96, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa10value_typeIiRiPiEEPT_RKNS_16__deque_iteratorIS3_T0_T1_EE
	.weak_definition	__ZN3dsa10value_typeIiRiPiEEPT_RKNS_16__deque_iteratorIS3_T0_T1_EE
	.p2align	4, 0x90
__ZN3dsa10value_typeIiRiPiEEPT_RKNS_16__deque_iteratorIS3_T0_T1_EE: ## @_ZN3dsa10value_typeIiRiPiEEPT_RKNS_16__deque_iteratorIS3_T0_T1_EE
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi123:
	.cfi_def_cfa_offset 16
Lcfi124:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi125:
	.cfi_def_cfa_register %rbp
	xorl	%eax, %eax
                                        ## kill: %RAX<def> %EAX<kill>
	movq	%rdi, -8(%rbp)
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa13__destroy_auxINS_16__deque_iteratorIiRiPiEEEEvT_S5_11__true_type
	.weak_definition	__ZN3dsa13__destroy_auxINS_16__deque_iteratorIiRiPiEEEEvT_S5_11__true_type
	.p2align	4, 0x90
__ZN3dsa13__destroy_auxINS_16__deque_iteratorIiRiPiEEEEvT_S5_11__true_type: ## @_ZN3dsa13__destroy_auxINS_16__deque_iteratorIiRiPiEEEEvT_S5_11__true_type
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi126:
	.cfi_def_cfa_offset 16
Lcfi127:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi128:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -16(%rbp)         ## 8-byte Spill
	movq	%rsi, -24(%rbp)         ## 8-byte Spill
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa16__deque_iteratorIiRiPiEC2ERKS3_
	.weak_def_can_be_hidden	__ZN3dsa16__deque_iteratorIiRiPiEC2ERKS3_
	.p2align	4, 0x90
__ZN3dsa16__deque_iteratorIiRiPiEC2ERKS3_: ## @_ZN3dsa16__deque_iteratorIiRiPiEC2ERKS3_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi129:
	.cfi_def_cfa_offset 16
Lcfi130:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi131:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rsi
	movq	-16(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rdi, (%rsi)
	movq	-16(%rbp), %rdi
	movq	8(%rdi), %rdi
	movq	%rdi, 8(%rsi)
	movq	-16(%rbp), %rdi
	movq	16(%rdi), %rdi
	movq	%rdi, 16(%rsi)
	movq	-16(%rbp), %rdi
	movq	24(%rdi), %rdi
	movq	%rdi, 24(%rsi)
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"hello world\n"

	.section	__DATA,__data
	.globl	__ZN3dsa23__malloc_alloc_templateILi0EE26__malloc_alloc_oom_handlerE ## @_ZN3dsa23__malloc_alloc_templateILi0EE26__malloc_alloc_oom_handlerE
	.weak_definition	__ZN3dsa23__malloc_alloc_templateILi0EE26__malloc_alloc_oom_handlerE
	.p2align	3
__ZN3dsa23__malloc_alloc_templateILi0EE26__malloc_alloc_oom_handlerE:
	.quad	0

	.globl	__ZN3dsa24__default_alloc_templateILb0ELi0EE12_S_free_listE ## @_ZN3dsa24__default_alloc_templateILb0ELi0EE12_S_free_listE
	.weak_definition	__ZN3dsa24__default_alloc_templateILb0ELi0EE12_S_free_listE
	.p2align	4
__ZN3dsa24__default_alloc_templateILb0ELi0EE12_S_free_listE:
	.space	128

	.globl	__ZN3dsa24__default_alloc_templateILb0ELi0EE11_S_end_freeE ## @_ZN3dsa24__default_alloc_templateILb0ELi0EE11_S_end_freeE
	.weak_definition	__ZN3dsa24__default_alloc_templateILb0ELi0EE11_S_end_freeE
	.p2align	3
__ZN3dsa24__default_alloc_templateILb0ELi0EE11_S_end_freeE:
	.quad	0

	.globl	__ZN3dsa24__default_alloc_templateILb0ELi0EE13_S_start_freeE ## @_ZN3dsa24__default_alloc_templateILb0ELi0EE13_S_start_freeE
	.weak_definition	__ZN3dsa24__default_alloc_templateILb0ELi0EE13_S_start_freeE
	.p2align	3
__ZN3dsa24__default_alloc_templateILb0ELi0EE13_S_start_freeE:
	.quad	0

	.globl	__ZN3dsa24__default_alloc_templateILb0ELi0EE12_S_heap_sizeE ## @_ZN3dsa24__default_alloc_templateILb0ELi0EE12_S_heap_sizeE
	.weak_definition	__ZN3dsa24__default_alloc_templateILb0ELi0EE12_S_heap_sizeE
	.p2align	3
__ZN3dsa24__default_alloc_templateILb0ELi0EE12_S_heap_sizeE:
	.quad	0                       ## 0x0


.subsections_via_symbols
