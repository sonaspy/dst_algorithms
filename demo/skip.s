	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.section	__TEXT,__StaticInit,regular,pure_instructions
	.p2align	4, 0x90
___cxx_global_var_init:                 ## @__cxx_global_var_init
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
	subq	$16, %rsp
	leaq	_sk(%rip), %rdi
	movl	$2147483647, %esi       ## imm = 0x7FFFFFFF
	movl	$10000000, %eax         ## imm = 0x989680
	movl	%eax, %edx
	callq	__ZN3dsa8skiplistIiiEC1Eim
	movq	__ZN3dsa8skiplistIiiED1Ev@GOTPCREL(%rip), %rdx
	leaq	_sk(%rip), %rdi
	movq	___dso_handle@GOTPCREL(%rip), %rcx
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	movq	%rdx, %rdi
	movq	-8(%rbp), %rsi          ## 8-byte Reload
	movq	%rcx, %rdx
	callq	___cxa_atexit
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN3dsa8skiplistIiiEC1Eim
	.weak_def_can_be_hidden	__ZN3dsa8skiplistIiiEC1Eim
	.p2align	4, 0x90
__ZN3dsa8skiplistIiiEC1Eim:             ## @_ZN3dsa8skiplistIiiEC1Eim
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
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movq	-24(%rbp), %rdx
	callq	__ZN3dsa8skiplistIiiEC2Eim
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa8skiplistIiiED1Ev
	.weak_def_can_be_hidden	__ZN3dsa8skiplistIiiED1Ev
	.p2align	4, 0x90
__ZN3dsa8skiplistIiiED1Ev:              ## @_ZN3dsa8skiplistIiiED1Ev
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
	callq	__ZN3dsa8skiplistIiiED2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__StaticInit,regular,pure_instructions
	.p2align	4, 0x90
___cxx_global_var_init.1:               ## @__cxx_global_var_init.1
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
	leaq	-16(%rbp), %rsi
	leaq	_st(%rip), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEEC1ERKS2_
	movq	__ZNSt3__13setIiNS_4lessIiEENS_9allocatorIiEEED1Ev@GOTPCREL(%rip), %rax
	leaq	_st(%rip), %rsi
	movq	___dso_handle@GOTPCREL(%rip), %rdx
	movq	%rax, %rdi
	callq	___cxa_atexit
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__13setIiNS_4lessIiEENS_9allocatorIiEEED1Ev
	.weak_def_can_be_hidden	__ZNSt3__13setIiNS_4lessIiEENS_9allocatorIiEEED1Ev
	.p2align	4, 0x90
__ZNSt3__13setIiNS_4lessIiEENS_9allocatorIiEEED1Ev: ## @_ZNSt3__13setIiNS_4lessIiEENS_9allocatorIiEEED1Ev
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
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZNSt3__13setIiNS_4lessIiEENS_9allocatorIiEEED2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__StaticInit,regular,pure_instructions
	.p2align	4, 0x90
___cxx_global_var_init.2:               ## @__cxx_global_var_init.2
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
	leaq	_p(%rip), %rdi
	callq	__ZN3dsa4pairIiiEC1Ev
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN3dsa4pairIiiEC1Ev
	.weak_def_can_be_hidden	__ZN3dsa4pairIiiEC1Ev
	.p2align	4, 0x90
__ZN3dsa4pairIiiEC1Ev:                  ## @_ZN3dsa4pairIiiEC1Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi18:
	.cfi_def_cfa_offset 16
Lcfi19:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi20:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZN3dsa4pairIiiEC2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__literal16,16byte_literals
	.p2align	4
LCPI7_0:
	.long	1127219200              ## 0x43300000
	.long	1160773632              ## 0x45300000
	.long	0                       ## 0x0
	.long	0                       ## 0x0
LCPI7_1:
	.quad	4841369599423283200     ## double 4503599627370496
	.quad	4985484787499139072     ## double 1.9342813113834067E+25
	.section	__TEXT,__text,regular,pure_instructions
	.globl	__Z19performance_comparei
	.p2align	4, 0x90
__Z19performance_comparei:              ## @_Z19performance_comparei
Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception0
## BB#0:
	pushq	%rbp
Lcfi21:
	.cfi_def_cfa_offset 16
Lcfi22:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi23:
	.cfi_def_cfa_register %rbp
	subq	$1184, %rsp             ## imm = 0x4A0
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rax
	leaq	L_.str(%rip), %rsi
	movl	%edi, -436(%rbp)
	movb	$0, -437(%rbp)
	movq	%rax, %rdi
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	movl	-436(%rbp), %esi
	movq	%rax, %rdi
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEi
	leaq	L_.str.3(%rip), %rsi
	movq	%rax, %rdi
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	testb	$1, -437(%rbp)
	movq	%rax, -632(%rbp)        ## 8-byte Spill
	je	LBB7_2
## BB#1:
	leaq	L_.str.4(%rip), %rax
	movq	%rax, -640(%rbp)        ## 8-byte Spill
	jmp	LBB7_3
LBB7_2:
	leaq	L_.str.5(%rip), %rax
	movq	%rax, -640(%rbp)        ## 8-byte Spill
	jmp	LBB7_3
LBB7_3:
	movq	-640(%rbp), %rax        ## 8-byte Reload
	movq	-632(%rbp), %rdi        ## 8-byte Reload
	movq	%rax, %rsi
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	movq	%rax, -424(%rbp)
	leaq	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_(%rip), %rax
	movq	%rax, -432(%rbp)
	movq	-424(%rbp), %rdi
	movq	-432(%rbp), %rax
	callq	*%rax
	movslq	-436(%rbp), %rsi
	leaq	-464(%rbp), %rdi
	movq	%rdi, -648(%rbp)        ## 8-byte Spill
	movq	%rax, -656(%rbp)        ## 8-byte Spill
	callq	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEEC1Em
Ltmp0:
	movq	-648(%rbp), %rdi        ## 8-byte Reload
	callq	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEE5beginEv
Ltmp1:
	movq	%rax, -664(%rbp)        ## 8-byte Spill
	jmp	LBB7_4
LBB7_4:
Ltmp2:
	leaq	-464(%rbp), %rdi
	callq	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEE3endEv
Ltmp3:
	movq	%rax, -672(%rbp)        ## 8-byte Spill
	jmp	LBB7_5
LBB7_5:
Ltmp4:
	xorl	%edx, %edx
	movq	-664(%rbp), %rdi        ## 8-byte Reload
	movq	-672(%rbp), %rsi        ## 8-byte Reload
	callq	__ZN3dsa4iotaIPiiEEvT_S2_T0_
Ltmp5:
	jmp	LBB7_6
LBB7_6:
	callq	__ZNSt3__16chrono12system_clock3nowEv
	leaq	-496(%rbp), %rcx
	movq	%rax, -496(%rbp)
	movq	%rcx, -416(%rbp)
	movq	-416(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -408(%rbp)
	movq	-408(%rbp), %rax
	movq	%rax, -680(%rbp)        ## 8-byte Spill
## BB#7:
	leaq	-488(%rbp), %rax
	movq	-680(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -488(%rbp)
	movq	%rax, -400(%rbp)
	movq	-400(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -688(%rbp)        ## 8-byte Spill
## BB#8:
	movq	-688(%rbp), %rax        ## 8-byte Reload
	movl	%eax, %ecx
	movl	%ecx, -480(%rbp)
Ltmp6:
	leaq	-464(%rbp), %rdi
	callq	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEE5beginEv
Ltmp7:
	movq	%rax, -696(%rbp)        ## 8-byte Spill
	jmp	LBB7_9
LBB7_9:
Ltmp8:
	leaq	-464(%rbp), %rdi
	callq	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEE3endEv
Ltmp9:
	movq	%rax, -704(%rbp)        ## 8-byte Spill
	jmp	LBB7_10
LBB7_10:
	movl	$2147483647, %eax       ## imm = 0x7FFFFFFF
	leaq	-504(%rbp), %rcx
	movl	-480(%rbp), %edx
	movq	%rcx, -368(%rbp)
	movl	%edx, -372(%rbp)
	movq	-368(%rbp), %rcx
	movl	-372(%rbp), %edx
	movq	%rcx, -352(%rbp)
	movl	%edx, -356(%rbp)
	movq	-352(%rbp), %rcx
	movl	-356(%rbp), %edx
	movq	%rcx, -328(%rbp)
	movl	%edx, -332(%rbp)
	movq	-328(%rbp), %rcx
	movl	-332(%rbp), %edx
	movq	%rcx, -312(%rbp)
	movl	%edx, -316(%rbp)
	movq	-312(%rbp), %rcx
	movl	-316(%rbp), %edx
	movl	%eax, -708(%rbp)        ## 4-byte Spill
	movl	%edx, %eax
	xorl	%edx, %edx
	movl	-708(%rbp), %esi        ## 4-byte Reload
	divl	%esi
	cmpl	$0, %edx
	movq	%rcx, -720(%rbp)        ## 8-byte Spill
	jne	LBB7_12
## BB#11:
	movl	$1, %eax
	movl	%eax, -724(%rbp)        ## 4-byte Spill
	jmp	LBB7_13
LBB7_12:
	movl	$2147483647, %eax       ## imm = 0x7FFFFFFF
	movl	-316(%rbp), %ecx
	movl	%eax, -728(%rbp)        ## 4-byte Spill
	movl	%ecx, %eax
	xorl	%edx, %edx
	movl	-728(%rbp), %ecx        ## 4-byte Reload
	divl	%ecx
	movl	%edx, -724(%rbp)        ## 4-byte Spill
LBB7_13:
	movl	-724(%rbp), %eax        ## 4-byte Reload
	movq	-720(%rbp), %rcx        ## 8-byte Reload
	movl	%eax, (%rcx)
## BB#14:
Ltmp10:
	leaq	-504(%rbp), %rdx
	movq	-696(%rbp), %rdi        ## 8-byte Reload
	movq	-704(%rbp), %rsi        ## 8-byte Reload
	callq	__ZNSt3__17shuffleIPiNS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEEEvT_S4_OT0_
Ltmp11:
	jmp	LBB7_15
LBB7_15:
	movq	$0, -512(%rbp)
	movq	$0, -520(%rbp)
	movq	$0, -528(%rbp)
	movl	$5, -532(%rbp)
	movl	$1, -536(%rbp)
	movl	-532(%rbp), %eax
	movl	%eax, -540(%rbp)
Ltmp12:
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rdi
	leaq	L_.str.6(%rip), %rsi
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
Ltmp13:
	movq	%rax, -736(%rbp)        ## 8-byte Spill
	jmp	LBB7_16
LBB7_16:
	movl	-532(%rbp), %esi
Ltmp14:
	movq	-736(%rbp), %rdi        ## 8-byte Reload
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEi
Ltmp15:
	movq	%rax, -744(%rbp)        ## 8-byte Spill
	jmp	LBB7_17
LBB7_17:
	movq	-744(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -296(%rbp)
	leaq	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_(%rip), %rcx
	movq	%rcx, -304(%rbp)
	movq	-296(%rbp), %rdi
	movq	-304(%rbp), %rcx
Ltmp16:
	callq	*%rcx
Ltmp17:
	movq	%rax, -752(%rbp)        ## 8-byte Spill
	jmp	LBB7_18
LBB7_18:
	jmp	LBB7_19
LBB7_19:
	jmp	LBB7_20
LBB7_20:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB7_23 Depth 2
                                        ##     Child Loop BB7_35 Depth 2
                                        ##     Child Loop BB7_43 Depth 2
	movl	-532(%rbp), %eax
	movl	%eax, %ecx
	addl	$-1, %ecx
	movl	%ecx, -532(%rbp)
	cmpl	$0, %eax
	je	LBB7_51
## BB#21:                               ##   in Loop: Header=BB7_20 Depth=1
Ltmp92:
	callq	_clock
Ltmp93:
	movq	%rax, -760(%rbp)        ## 8-byte Spill
	jmp	LBB7_22
LBB7_22:                                ##   in Loop: Header=BB7_20 Depth=1
	movq	-760(%rbp), %rax        ## 8-byte Reload
	movq	%rax, _startTime(%rip)
	movl	$0, -544(%rbp)
LBB7_23:                                ##   Parent Loop BB7_20 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpl	$100000, -544(%rbp)     ## imm = 0x186A0
	jge	LBB7_32
## BB#24:                               ##   in Loop: Header=BB7_23 Depth=2
	movslq	-544(%rbp), %rsi
Ltmp110:
	leaq	-464(%rbp), %rdi
	callq	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEEixEm
Ltmp111:
	movq	%rax, -768(%rbp)        ## 8-byte Spill
	jmp	LBB7_25
LBB7_25:                                ##   in Loop: Header=BB7_23 Depth=2
	movl	$0, -556(%rbp)
Ltmp112:
	leaq	-556(%rbp), %rsi
	movq	-768(%rbp), %rdi        ## 8-byte Reload
	callq	__ZN3dsa9make_pairIiiEENS_4pairIT_T0_EERKS2_RKS3_
Ltmp113:
	movq	%rax, -776(%rbp)        ## 8-byte Spill
	jmp	LBB7_26
LBB7_26:                                ##   in Loop: Header=BB7_23 Depth=2
	movq	-776(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -552(%rbp)
	movq	-552(%rbp), %rcx
	movq	%rcx, _p(%rip)
	movslq	-544(%rbp), %rsi
Ltmp114:
	leaq	-464(%rbp), %rdi
	callq	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEEixEm
Ltmp115:
	movq	%rax, -784(%rbp)        ## 8-byte Spill
	jmp	LBB7_27
LBB7_27:                                ##   in Loop: Header=BB7_23 Depth=2
	leaq	_st(%rip), %rax
	movq	%rax, -264(%rbp)
	movq	-784(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -272(%rbp)
	movq	-264(%rbp), %rcx
	movq	-272(%rbp), %rdx
	movq	%rcx, -232(%rbp)
	movq	%rdx, -240(%rbp)
	movq	-232(%rbp), %rdi
	movq	-240(%rbp), %rcx
	movq	%rcx, -208(%rbp)
	movq	-208(%rbp), %rsi
	movq	-240(%rbp), %rdx
Ltmp116:
	callq	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE25__emplace_unique_key_argsIiJRKiEEENS_4pairINS_15__tree_iteratorIiPNS_11__tree_nodeIiPvEElEEbEERKT_DpOT0_
Ltmp117:
	movb	%dl, -785(%rbp)         ## 1-byte Spill
	movq	%rax, -800(%rbp)        ## 8-byte Spill
	jmp	LBB7_28
LBB7_28:                                ##   in Loop: Header=BB7_23 Depth=2
	movq	-800(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -224(%rbp)
	movb	-785(%rbp), %cl         ## 1-byte Reload
	movb	%cl, -216(%rbp)
	movb	-216(%rbp), %dl
	movq	-224(%rbp), %rsi
	movq	%rsi, -288(%rbp)
	movb	%dl, -280(%rbp)
	leaq	-256(%rbp), %rsi
	movq	%rsi, -192(%rbp)
	leaq	-288(%rbp), %rsi
	movq	%rsi, -200(%rbp)
	movq	-192(%rbp), %rsi
	movq	-200(%rbp), %rdi
	movq	%rsi, -168(%rbp)
	movq	%rdi, -176(%rbp)
	movq	-168(%rbp), %rsi
	movq	-176(%rbp), %rdi
	movq	%rdi, -160(%rbp)
	movq	-160(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rdi, -184(%rbp)
	movq	-184(%rbp), %rdi
	movq	%rdi, -136(%rbp)
	movq	%rsi, -144(%rbp)
	movq	-144(%rbp), %rdi
	movq	-136(%rbp), %r8
	movq	%r8, -120(%rbp)
	movq	%rdi, -128(%rbp)
	movq	-128(%rbp), %rdi
	movq	-120(%rbp), %r8
	movq	%r8, (%rdi)
	movq	-176(%rbp), %rdi
	addq	$8, %rdi
	movq	%rdi, -152(%rbp)
	movq	-152(%rbp), %rdi
	movb	(%rdi), %dl
	andb	$1, %dl
	movb	%dl, 8(%rsi)
	movb	-248(%rbp), %dl
	movq	-256(%rbp), %rsi
	movb	%dl, -801(%rbp)         ## 1-byte Spill
	movq	%rsi, -816(%rbp)        ## 8-byte Spill
## BB#29:                               ##   in Loop: Header=BB7_23 Depth=2
	movq	-816(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -576(%rbp)
	movb	-801(%rbp), %cl         ## 1-byte Reload
	movb	%cl, -568(%rbp)
## BB#30:                               ##   in Loop: Header=BB7_23 Depth=2
	movl	-544(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -544(%rbp)
	jmp	LBB7_23
LBB7_31:
Ltmp118:
	leaq	-464(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -472(%rbp)
	movl	%ecx, -476(%rbp)
	callq	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEED1Ev
	jmp	LBB7_116
LBB7_32:                                ##   in Loop: Header=BB7_20 Depth=1
Ltmp94:
	callq	_clock
Ltmp95:
	movq	%rax, -824(%rbp)        ## 8-byte Spill
	jmp	LBB7_33
LBB7_33:                                ##   in Loop: Header=BB7_20 Depth=1
	movq	-824(%rbp), %rax        ## 8-byte Reload
	movq	%rax, _endTime(%rip)
	movq	_endTime(%rip), %rcx
	movq	_startTime(%rip), %rdx
	subq	%rdx, %rcx
	movd	%rcx, %xmm0
	movaps	LCPI7_0(%rip), %xmm1    ## xmm1 = [1127219200,1160773632,0,0]
	punpckldq	%xmm1, %xmm0    ## xmm0 = xmm0[0],xmm1[0],xmm0[1],xmm1[1]
	movapd	LCPI7_1(%rip), %xmm1    ## xmm1 = [4.503600e+15,1.934281e+25]
	subpd	%xmm1, %xmm0
	haddpd	%xmm0, %xmm0
	movsd	-520(%rbp), %xmm1       ## xmm1 = mem[0],zero
	addsd	%xmm0, %xmm1
	movsd	%xmm1, -520(%rbp)
Ltmp96:
	callq	_clock
Ltmp97:
	movq	%rax, -832(%rbp)        ## 8-byte Spill
	jmp	LBB7_34
LBB7_34:                                ##   in Loop: Header=BB7_20 Depth=1
	movq	-832(%rbp), %rax        ## 8-byte Reload
	movq	%rax, _startTime(%rip)
	movl	$0, -580(%rbp)
LBB7_35:                                ##   Parent Loop BB7_20 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpl	$100000, -580(%rbp)     ## imm = 0x186A0
	jge	LBB7_40
## BB#36:                               ##   in Loop: Header=BB7_35 Depth=2
	movslq	-580(%rbp), %rsi
Ltmp108:
	leaq	-464(%rbp), %rdi
	callq	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEEixEm
Ltmp109:
	movq	%rax, -840(%rbp)        ## 8-byte Spill
	jmp	LBB7_37
LBB7_37:                                ##   in Loop: Header=BB7_35 Depth=2
	leaq	_st(%rip), %rax
	movq	%rax, -104(%rbp)
	movq	-840(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -112(%rbp)
	movq	-104(%rbp), %rdi
	movq	-112(%rbp), %rsi
	callq	__ZNKSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE14__count_uniqueIiEEmRKT_
	movq	%rax, -848(%rbp)        ## 8-byte Spill
## BB#38:                               ##   in Loop: Header=BB7_35 Depth=2
	jmp	LBB7_39
LBB7_39:                                ##   in Loop: Header=BB7_35 Depth=2
	movl	-580(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -580(%rbp)
	jmp	LBB7_35
LBB7_40:                                ##   in Loop: Header=BB7_20 Depth=1
Ltmp98:
	callq	_clock
Ltmp99:
	movq	%rax, -856(%rbp)        ## 8-byte Spill
	jmp	LBB7_41
LBB7_41:                                ##   in Loop: Header=BB7_20 Depth=1
	movq	-856(%rbp), %rax        ## 8-byte Reload
	movq	%rax, _endTime(%rip)
	movq	_endTime(%rip), %rcx
	movq	_startTime(%rip), %rdx
	subq	%rdx, %rcx
	movd	%rcx, %xmm0
	movaps	LCPI7_0(%rip), %xmm1    ## xmm1 = [1127219200,1160773632,0,0]
	punpckldq	%xmm1, %xmm0    ## xmm0 = xmm0[0],xmm1[0],xmm0[1],xmm1[1]
	movapd	LCPI7_1(%rip), %xmm1    ## xmm1 = [4.503600e+15,1.934281e+25]
	subpd	%xmm1, %xmm0
	haddpd	%xmm0, %xmm0
	movsd	-528(%rbp), %xmm1       ## xmm1 = mem[0],zero
	addsd	%xmm0, %xmm1
	movsd	%xmm1, -528(%rbp)
Ltmp100:
	callq	_clock
Ltmp101:
	movq	%rax, -864(%rbp)        ## 8-byte Spill
	jmp	LBB7_42
LBB7_42:                                ##   in Loop: Header=BB7_20 Depth=1
	movq	-864(%rbp), %rax        ## 8-byte Reload
	movq	%rax, _startTime(%rip)
	movl	$0, -584(%rbp)
LBB7_43:                                ##   Parent Loop BB7_20 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpl	$100000, -584(%rbp)     ## imm = 0x186A0
	jge	LBB7_49
## BB#44:                               ##   in Loop: Header=BB7_43 Depth=2
	movslq	-584(%rbp), %rsi
Ltmp104:
	leaq	-464(%rbp), %rdi
	callq	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEEixEm
Ltmp105:
	movq	%rax, -872(%rbp)        ## 8-byte Spill
	jmp	LBB7_45
LBB7_45:                                ##   in Loop: Header=BB7_43 Depth=2
	leaq	_st(%rip), %rax
	movq	%rax, -88(%rbp)
	movq	-872(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -96(%rbp)
	movq	-88(%rbp), %rdi
	movq	-96(%rbp), %rsi
Ltmp106:
	callq	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE14__erase_uniqueIiEEmRKT_
Ltmp107:
	movq	%rax, -880(%rbp)        ## 8-byte Spill
	jmp	LBB7_46
LBB7_46:                                ##   in Loop: Header=BB7_43 Depth=2
	jmp	LBB7_47
LBB7_47:                                ##   in Loop: Header=BB7_43 Depth=2
	jmp	LBB7_48
LBB7_48:                                ##   in Loop: Header=BB7_43 Depth=2
	movl	-584(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -584(%rbp)
	jmp	LBB7_43
LBB7_49:                                ##   in Loop: Header=BB7_20 Depth=1
Ltmp102:
	callq	_clock
Ltmp103:
	movq	%rax, -888(%rbp)        ## 8-byte Spill
	jmp	LBB7_50
LBB7_50:                                ##   in Loop: Header=BB7_20 Depth=1
	movq	-888(%rbp), %rax        ## 8-byte Reload
	movq	%rax, _endTime(%rip)
	movq	_endTime(%rip), %rcx
	movq	_startTime(%rip), %rdx
	subq	%rdx, %rcx
	movd	%rcx, %xmm0
	movaps	LCPI7_0(%rip), %xmm1    ## xmm1 = [1127219200,1160773632,0,0]
	punpckldq	%xmm1, %xmm0    ## xmm0 = xmm0[0],xmm1[0],xmm0[1],xmm1[1]
	movapd	LCPI7_1(%rip), %xmm1    ## xmm1 = [4.503600e+15,1.934281e+25]
	subpd	%xmm1, %xmm0
	haddpd	%xmm0, %xmm0
	addsd	-512(%rbp), %xmm0
	movsd	%xmm0, -512(%rbp)
	jmp	LBB7_20
LBB7_51:
Ltmp18:
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rdi
	leaq	L_.str.7(%rip), %rsi
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
Ltmp19:
	movq	%rax, -896(%rbp)        ## 8-byte Spill
	jmp	LBB7_52
LBB7_52:
	movsd	-520(%rbp), %xmm0       ## xmm0 = mem[0],zero
	movl	-540(%rbp), %eax
	imull	$1000, %eax, %eax       ## imm = 0x3E8
	cvtsi2sdl	%eax, %xmm1
	divsd	%xmm1, %xmm0
Ltmp20:
	movq	-896(%rbp), %rdi        ## 8-byte Reload
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEd
Ltmp21:
	movq	%rax, -904(%rbp)        ## 8-byte Spill
	jmp	LBB7_53
LBB7_53:
Ltmp22:
	leaq	L_.str.8(%rip), %rsi
	movq	-904(%rbp), %rdi        ## 8-byte Reload
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
Ltmp23:
	movq	%rax, -912(%rbp)        ## 8-byte Spill
	jmp	LBB7_54
LBB7_54:
	movq	-912(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -72(%rbp)
	leaq	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_(%rip), %rcx
	movq	%rcx, -80(%rbp)
	movq	-72(%rbp), %rdi
	movq	-80(%rbp), %rcx
Ltmp24:
	callq	*%rcx
Ltmp25:
	movq	%rax, -920(%rbp)        ## 8-byte Spill
	jmp	LBB7_55
LBB7_55:
	jmp	LBB7_56
LBB7_56:
Ltmp26:
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rdi
	leaq	L_.str.9(%rip), %rsi
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
Ltmp27:
	movq	%rax, -928(%rbp)        ## 8-byte Spill
	jmp	LBB7_57
LBB7_57:
	cmpl	$0, -536(%rbp)
	je	LBB7_59
## BB#58:
	movsd	-528(%rbp), %xmm0       ## xmm0 = mem[0],zero
	imull	$1000, -540(%rbp), %eax ## imm = 0x3E8
	cvtsi2sdl	%eax, %xmm1
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -936(%rbp)       ## 8-byte Spill
	jmp	LBB7_60
LBB7_59:
	xorps	%xmm0, %xmm0
	movsd	%xmm0, -936(%rbp)       ## 8-byte Spill
	jmp	LBB7_60
LBB7_60:
Ltmp28:
	movsd	-936(%rbp), %xmm0       ## 8-byte Reload
                                        ## xmm0 = mem[0],zero
	movq	-928(%rbp), %rdi        ## 8-byte Reload
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEd
Ltmp29:
	movq	%rax, -944(%rbp)        ## 8-byte Spill
	jmp	LBB7_61
LBB7_61:
Ltmp30:
	leaq	L_.str.8(%rip), %rsi
	movq	-944(%rbp), %rdi        ## 8-byte Reload
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
Ltmp31:
	movq	%rax, -952(%rbp)        ## 8-byte Spill
	jmp	LBB7_62
LBB7_62:
	movq	-952(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -56(%rbp)
	leaq	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_(%rip), %rcx
	movq	%rcx, -64(%rbp)
	movq	-56(%rbp), %rdi
	movq	-64(%rbp), %rcx
Ltmp32:
	callq	*%rcx
Ltmp33:
	movq	%rax, -960(%rbp)        ## 8-byte Spill
	jmp	LBB7_63
LBB7_63:
	jmp	LBB7_64
LBB7_64:
Ltmp34:
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rdi
	leaq	L_.str.10(%rip), %rsi
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
Ltmp35:
	movq	%rax, -968(%rbp)        ## 8-byte Spill
	jmp	LBB7_65
LBB7_65:
	movsd	-512(%rbp), %xmm0       ## xmm0 = mem[0],zero
	movl	-540(%rbp), %eax
	imull	$1000, %eax, %eax       ## imm = 0x3E8
	cvtsi2sdl	%eax, %xmm1
	divsd	%xmm1, %xmm0
Ltmp36:
	movq	-968(%rbp), %rdi        ## 8-byte Reload
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEd
Ltmp37:
	movq	%rax, -976(%rbp)        ## 8-byte Spill
	jmp	LBB7_66
LBB7_66:
Ltmp38:
	leaq	L_.str.8(%rip), %rsi
	movq	-976(%rbp), %rdi        ## 8-byte Reload
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
Ltmp39:
	movq	%rax, -984(%rbp)        ## 8-byte Spill
	jmp	LBB7_67
LBB7_67:
	movq	-984(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -40(%rbp)
	leaq	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_(%rip), %rcx
	movq	%rcx, -48(%rbp)
	movq	-40(%rbp), %rdi
	movq	-48(%rbp), %rcx
Ltmp40:
	callq	*%rcx
Ltmp41:
	movq	%rax, -992(%rbp)        ## 8-byte Spill
	jmp	LBB7_68
LBB7_68:
	jmp	LBB7_69
LBB7_69:
	xorps	%xmm0, %xmm0
	movl	-540(%rbp), %eax
	movl	%eax, -532(%rbp)
	movsd	%xmm0, -512(%rbp)
	movsd	%xmm0, -520(%rbp)
	movsd	%xmm0, -528(%rbp)
	movl	$1, -536(%rbp)
LBB7_70:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB7_73 Depth 2
                                        ##     Child Loop BB7_82 Depth 2
                                        ##     Child Loop BB7_90 Depth 2
	movl	-532(%rbp), %eax
	movl	%eax, %ecx
	addl	$-1, %ecx
	movl	%ecx, -532(%rbp)
	cmpl	$0, %eax
	je	LBB7_97
## BB#71:                               ##   in Loop: Header=BB7_70 Depth=1
Ltmp66:
	callq	_clock
Ltmp67:
	movq	%rax, -1000(%rbp)       ## 8-byte Spill
	jmp	LBB7_72
LBB7_72:                                ##   in Loop: Header=BB7_70 Depth=1
	movq	-1000(%rbp), %rax       ## 8-byte Reload
	movq	%rax, _startTime(%rip)
	movl	$0, -588(%rbp)
LBB7_73:                                ##   Parent Loop BB7_70 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpl	$100000, -588(%rbp)     ## imm = 0x186A0
	jge	LBB7_79
## BB#74:                               ##   in Loop: Header=BB7_73 Depth=2
	movslq	-588(%rbp), %rsi
Ltmp86:
	leaq	-464(%rbp), %rdi
	callq	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEEixEm
Ltmp87:
	movq	%rax, -1008(%rbp)       ## 8-byte Spill
	jmp	LBB7_75
LBB7_75:                                ##   in Loop: Header=BB7_73 Depth=2
	movl	$0, -604(%rbp)
Ltmp88:
	leaq	-604(%rbp), %rsi
	movq	-1008(%rbp), %rdi       ## 8-byte Reload
	callq	__ZN3dsa9make_pairIiiEENS_4pairIT_T0_EERKS2_RKS3_
Ltmp89:
	movq	%rax, -1016(%rbp)       ## 8-byte Spill
	jmp	LBB7_76
LBB7_76:                                ##   in Loop: Header=BB7_73 Depth=2
	movq	-1016(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -600(%rbp)
	movq	-600(%rbp), %rcx
	movq	%rcx, _p(%rip)
	movq	_p(%rip), %rcx
	movq	%rcx, -616(%rbp)
	movq	-616(%rbp), %rsi
Ltmp90:
	leaq	_sk(%rip), %rdi
	callq	__ZN3dsa8skiplistIiiE6insertENS_4pairIiiEE
Ltmp91:
	jmp	LBB7_77
LBB7_77:                                ##   in Loop: Header=BB7_73 Depth=2
	jmp	LBB7_78
LBB7_78:                                ##   in Loop: Header=BB7_73 Depth=2
	movl	-588(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -588(%rbp)
	jmp	LBB7_73
LBB7_79:                                ##   in Loop: Header=BB7_70 Depth=1
Ltmp68:
	callq	_clock
Ltmp69:
	movq	%rax, -1024(%rbp)       ## 8-byte Spill
	jmp	LBB7_80
LBB7_80:                                ##   in Loop: Header=BB7_70 Depth=1
	movq	-1024(%rbp), %rax       ## 8-byte Reload
	movq	%rax, _endTime(%rip)
	movq	_endTime(%rip), %rcx
	movq	_startTime(%rip), %rdx
	subq	%rdx, %rcx
	movd	%rcx, %xmm0
	movaps	LCPI7_0(%rip), %xmm1    ## xmm1 = [1127219200,1160773632,0,0]
	punpckldq	%xmm1, %xmm0    ## xmm0 = xmm0[0],xmm1[0],xmm0[1],xmm1[1]
	movapd	LCPI7_1(%rip), %xmm1    ## xmm1 = [4.503600e+15,1.934281e+25]
	subpd	%xmm1, %xmm0
	haddpd	%xmm0, %xmm0
	movsd	-520(%rbp), %xmm1       ## xmm1 = mem[0],zero
	addsd	%xmm0, %xmm1
	movsd	%xmm1, -520(%rbp)
Ltmp70:
	callq	_clock
Ltmp71:
	movq	%rax, -1032(%rbp)       ## 8-byte Spill
	jmp	LBB7_81
LBB7_81:                                ##   in Loop: Header=BB7_70 Depth=1
	movq	-1032(%rbp), %rax       ## 8-byte Reload
	movq	%rax, _startTime(%rip)
	movl	$0, -620(%rbp)
LBB7_82:                                ##   Parent Loop BB7_70 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpl	$100000, -620(%rbp)     ## imm = 0x186A0
	jge	LBB7_87
## BB#83:                               ##   in Loop: Header=BB7_82 Depth=2
	movslq	-620(%rbp), %rsi
Ltmp82:
	leaq	-464(%rbp), %rdi
	callq	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEEixEm
Ltmp83:
	movq	%rax, -1040(%rbp)       ## 8-byte Spill
	jmp	LBB7_84
LBB7_84:                                ##   in Loop: Header=BB7_82 Depth=2
Ltmp84:
	leaq	_sk(%rip), %rdi
	movq	-1040(%rbp), %rsi       ## 8-byte Reload
	callq	__ZN3dsa8skiplistIiiE5countERi
Ltmp85:
	movb	%al, -1041(%rbp)        ## 1-byte Spill
	jmp	LBB7_85
LBB7_85:                                ##   in Loop: Header=BB7_82 Depth=2
	jmp	LBB7_86
LBB7_86:                                ##   in Loop: Header=BB7_82 Depth=2
	movl	-620(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -620(%rbp)
	jmp	LBB7_82
LBB7_87:                                ##   in Loop: Header=BB7_70 Depth=1
Ltmp72:
	callq	_clock
Ltmp73:
	movq	%rax, -1056(%rbp)       ## 8-byte Spill
	jmp	LBB7_88
LBB7_88:                                ##   in Loop: Header=BB7_70 Depth=1
	movq	-1056(%rbp), %rax       ## 8-byte Reload
	movq	%rax, _endTime(%rip)
	movq	_endTime(%rip), %rcx
	movq	_startTime(%rip), %rdx
	subq	%rdx, %rcx
	movd	%rcx, %xmm0
	movaps	LCPI7_0(%rip), %xmm1    ## xmm1 = [1127219200,1160773632,0,0]
	punpckldq	%xmm1, %xmm0    ## xmm0 = xmm0[0],xmm1[0],xmm0[1],xmm1[1]
	movapd	LCPI7_1(%rip), %xmm1    ## xmm1 = [4.503600e+15,1.934281e+25]
	subpd	%xmm1, %xmm0
	haddpd	%xmm0, %xmm0
	movsd	-528(%rbp), %xmm1       ## xmm1 = mem[0],zero
	addsd	%xmm0, %xmm1
	movsd	%xmm1, -528(%rbp)
Ltmp74:
	callq	_clock
Ltmp75:
	movq	%rax, -1064(%rbp)       ## 8-byte Spill
	jmp	LBB7_89
LBB7_89:                                ##   in Loop: Header=BB7_70 Depth=1
	movq	-1064(%rbp), %rax       ## 8-byte Reload
	movq	%rax, _startTime(%rip)
	movl	$0, -624(%rbp)
LBB7_90:                                ##   Parent Loop BB7_70 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpl	$100000, -624(%rbp)     ## imm = 0x186A0
	jge	LBB7_95
## BB#91:                               ##   in Loop: Header=BB7_90 Depth=2
	movslq	-624(%rbp), %rsi
Ltmp78:
	leaq	-464(%rbp), %rdi
	callq	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEEixEm
Ltmp79:
	movq	%rax, -1072(%rbp)       ## 8-byte Spill
	jmp	LBB7_92
LBB7_92:                                ##   in Loop: Header=BB7_90 Depth=2
Ltmp80:
	leaq	_sk(%rip), %rdi
	movq	-1072(%rbp), %rsi       ## 8-byte Reload
	callq	__ZN3dsa8skiplistIiiE5eraseERi
Ltmp81:
	jmp	LBB7_93
LBB7_93:                                ##   in Loop: Header=BB7_90 Depth=2
	jmp	LBB7_94
LBB7_94:                                ##   in Loop: Header=BB7_90 Depth=2
	movl	-624(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -624(%rbp)
	jmp	LBB7_90
LBB7_95:                                ##   in Loop: Header=BB7_70 Depth=1
Ltmp76:
	callq	_clock
Ltmp77:
	movq	%rax, -1080(%rbp)       ## 8-byte Spill
	jmp	LBB7_96
LBB7_96:                                ##   in Loop: Header=BB7_70 Depth=1
	movq	-1080(%rbp), %rax       ## 8-byte Reload
	movq	%rax, _endTime(%rip)
	movq	_endTime(%rip), %rcx
	movq	_startTime(%rip), %rdx
	subq	%rdx, %rcx
	movd	%rcx, %xmm0
	movaps	LCPI7_0(%rip), %xmm1    ## xmm1 = [1127219200,1160773632,0,0]
	punpckldq	%xmm1, %xmm0    ## xmm0 = xmm0[0],xmm1[0],xmm0[1],xmm1[1]
	movapd	LCPI7_1(%rip), %xmm1    ## xmm1 = [4.503600e+15,1.934281e+25]
	subpd	%xmm1, %xmm0
	haddpd	%xmm0, %xmm0
	addsd	-512(%rbp), %xmm0
	movsd	%xmm0, -512(%rbp)
	jmp	LBB7_70
LBB7_97:
Ltmp42:
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rdi
	leaq	L_.str.11(%rip), %rsi
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
Ltmp43:
	movq	%rax, -1088(%rbp)       ## 8-byte Spill
	jmp	LBB7_98
LBB7_98:
	movsd	-520(%rbp), %xmm0       ## xmm0 = mem[0],zero
	movl	-540(%rbp), %eax
	imull	$1000, %eax, %eax       ## imm = 0x3E8
	cvtsi2sdl	%eax, %xmm1
	divsd	%xmm1, %xmm0
Ltmp44:
	movq	-1088(%rbp), %rdi       ## 8-byte Reload
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEd
Ltmp45:
	movq	%rax, -1096(%rbp)       ## 8-byte Spill
	jmp	LBB7_99
LBB7_99:
Ltmp46:
	leaq	L_.str.8(%rip), %rsi
	movq	-1096(%rbp), %rdi       ## 8-byte Reload
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
Ltmp47:
	movq	%rax, -1104(%rbp)       ## 8-byte Spill
	jmp	LBB7_100
LBB7_100:
	movq	-1104(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -24(%rbp)
	leaq	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_(%rip), %rcx
	movq	%rcx, -32(%rbp)
	movq	-24(%rbp), %rdi
	movq	-32(%rbp), %rcx
Ltmp48:
	callq	*%rcx
Ltmp49:
	movq	%rax, -1112(%rbp)       ## 8-byte Spill
	jmp	LBB7_101
LBB7_101:
	jmp	LBB7_102
LBB7_102:
Ltmp50:
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rdi
	leaq	L_.str.12(%rip), %rsi
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
Ltmp51:
	movq	%rax, -1120(%rbp)       ## 8-byte Spill
	jmp	LBB7_103
LBB7_103:
	cmpl	$0, -536(%rbp)
	je	LBB7_105
## BB#104:
	movsd	-528(%rbp), %xmm0       ## xmm0 = mem[0],zero
	imull	$1000, -540(%rbp), %eax ## imm = 0x3E8
	cvtsi2sdl	%eax, %xmm1
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -1128(%rbp)      ## 8-byte Spill
	jmp	LBB7_106
LBB7_105:
	xorps	%xmm0, %xmm0
	movsd	%xmm0, -1128(%rbp)      ## 8-byte Spill
	jmp	LBB7_106
LBB7_106:
Ltmp52:
	movsd	-1128(%rbp), %xmm0      ## 8-byte Reload
                                        ## xmm0 = mem[0],zero
	movq	-1120(%rbp), %rdi       ## 8-byte Reload
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEd
Ltmp53:
	movq	%rax, -1136(%rbp)       ## 8-byte Spill
	jmp	LBB7_107
LBB7_107:
Ltmp54:
	leaq	L_.str.8(%rip), %rsi
	movq	-1136(%rbp), %rdi       ## 8-byte Reload
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
Ltmp55:
	movq	%rax, -1144(%rbp)       ## 8-byte Spill
	jmp	LBB7_108
LBB7_108:
	movq	-1144(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -8(%rbp)
	leaq	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_(%rip), %rcx
	movq	%rcx, -16(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rcx
Ltmp56:
	callq	*%rcx
Ltmp57:
	movq	%rax, -1152(%rbp)       ## 8-byte Spill
	jmp	LBB7_109
LBB7_109:
	jmp	LBB7_110
LBB7_110:
Ltmp58:
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rdi
	leaq	L_.str.13(%rip), %rsi
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
Ltmp59:
	movq	%rax, -1160(%rbp)       ## 8-byte Spill
	jmp	LBB7_111
LBB7_111:
	movsd	-512(%rbp), %xmm0       ## xmm0 = mem[0],zero
	movl	-540(%rbp), %eax
	imull	$1000, %eax, %eax       ## imm = 0x3E8
	cvtsi2sdl	%eax, %xmm1
	divsd	%xmm1, %xmm0
Ltmp60:
	movq	-1160(%rbp), %rdi       ## 8-byte Reload
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEd
Ltmp61:
	movq	%rax, -1168(%rbp)       ## 8-byte Spill
	jmp	LBB7_112
LBB7_112:
Ltmp62:
	leaq	L_.str.8(%rip), %rsi
	movq	-1168(%rbp), %rdi       ## 8-byte Reload
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
Ltmp63:
	movq	%rax, -1176(%rbp)       ## 8-byte Spill
	jmp	LBB7_113
LBB7_113:
	movq	-1176(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -384(%rbp)
	leaq	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_(%rip), %rcx
	movq	%rcx, -392(%rbp)
	movq	-384(%rbp), %rdi
	movq	-392(%rbp), %rcx
Ltmp64:
	callq	*%rcx
Ltmp65:
	movq	%rax, -1184(%rbp)       ## 8-byte Spill
	jmp	LBB7_114
LBB7_114:
	jmp	LBB7_115
LBB7_115:
	leaq	-464(%rbp), %rdi
	callq	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEED1Ev
	addq	$1184, %rsp             ## imm = 0x4A0
	popq	%rbp
	retq
LBB7_116:
	movq	-472(%rbp), %rdi
	callq	__Unwind_Resume
Lfunc_end0:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table7:
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
Lset3 = Ltmp65-Ltmp0                    ##   Call between Ltmp0 and Ltmp65
	.long	Lset3
Lset4 = Ltmp118-Lfunc_begin0            ##     jumps to Ltmp118
	.long	Lset4
	.byte	0                       ##   On action: cleanup
Lset5 = Ltmp65-Lfunc_begin0             ## >> Call Site 3 <<
	.long	Lset5
Lset6 = Lfunc_end0-Ltmp65               ##   Call between Ltmp65 and Lfunc_end0
	.long	Lset6
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	.weak_definition	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	.p2align	4, 0x90
__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc: ## @_ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
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
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	movq	-16(%rbp), %rax
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rsi, -32(%rbp)         ## 8-byte Spill
	callq	__ZNSt3__111char_traitsIcE6lengthEPKc
	movq	-24(%rbp), %rdi         ## 8-byte Reload
	movq	-32(%rbp), %rsi         ## 8-byte Reload
	movq	%rax, %rdx
	callq	__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.private_extern	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
	.globl	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
	.weak_definition	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
	.p2align	4, 0x90
__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_: ## @_ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
Lfunc_begin1:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception1
## BB#0:
	pushq	%rbp
Lcfi27:
	.cfi_def_cfa_offset 16
Lcfi28:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi29:
	.cfi_def_cfa_register %rbp
	subq	$144, %rsp
	movq	%rdi, -72(%rbp)
	movq	-72(%rbp), %rdi
	movq	(%rdi), %rax
	movq	-24(%rax), %rax
	movq	%rdi, %rcx
	addq	%rax, %rcx
	movq	%rcx, -32(%rbp)
	movb	$10, -33(%rbp)
	movq	-32(%rbp), %rsi
	leaq	-48(%rbp), %rax
	movq	%rdi, -80(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rax, -88(%rbp)         ## 8-byte Spill
	callq	__ZNKSt3__18ios_base6getlocEv
	movq	-88(%rbp), %rax         ## 8-byte Reload
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rdi
Ltmp119:
	movq	__ZNSt3__15ctypeIcE2idE@GOTPCREL(%rip), %rsi
	callq	__ZNKSt3__16locale9use_facetERNS0_2idE
Ltmp120:
	movq	%rax, -96(%rbp)         ## 8-byte Spill
	jmp	LBB9_1
LBB9_1:
	movb	-33(%rbp), %al
	movq	-96(%rbp), %rcx         ## 8-byte Reload
	movq	%rcx, -8(%rbp)
	movb	%al, -9(%rbp)
	movq	-8(%rbp), %rdx
	movq	(%rdx), %rsi
	movq	56(%rsi), %rsi
	movsbl	-9(%rbp), %edi
Ltmp121:
	movl	%edi, -100(%rbp)        ## 4-byte Spill
	movq	%rdx, %rdi
	movl	-100(%rbp), %r8d        ## 4-byte Reload
	movq	%rsi, -112(%rbp)        ## 8-byte Spill
	movl	%r8d, %esi
	movq	-112(%rbp), %rdx        ## 8-byte Reload
	callq	*%rdx
Ltmp122:
	movb	%al, -113(%rbp)         ## 1-byte Spill
	jmp	LBB9_3
LBB9_2:
Ltmp123:
	leaq	-48(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -56(%rbp)
	movl	%ecx, -60(%rbp)
	callq	__ZNSt3__16localeD1Ev
	movq	-56(%rbp), %rdi
	callq	__Unwind_Resume
LBB9_3:
	leaq	-48(%rbp), %rdi
	callq	__ZNSt3__16localeD1Ev
	movq	-80(%rbp), %rdi         ## 8-byte Reload
	movb	-113(%rbp), %al         ## 1-byte Reload
	movsbl	%al, %esi
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE3putEc
	movq	-72(%rbp), %rdi
	movq	%rax, -128(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE5flushEv
	movq	-72(%rbp), %rdi
	movq	%rax, -136(%rbp)        ## 8-byte Spill
	movq	%rdi, %rax
	addq	$144, %rsp
	popq	%rbp
	retq
Lfunc_end1:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table9:
Lexception1:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset7 = Lfunc_begin1-Lfunc_begin1       ## >> Call Site 1 <<
	.long	Lset7
Lset8 = Ltmp119-Lfunc_begin1            ##   Call between Lfunc_begin1 and Ltmp119
	.long	Lset8
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset9 = Ltmp119-Lfunc_begin1            ## >> Call Site 2 <<
	.long	Lset9
Lset10 = Ltmp122-Ltmp119                ##   Call between Ltmp119 and Ltmp122
	.long	Lset10
Lset11 = Ltmp123-Lfunc_begin1           ##     jumps to Ltmp123
	.long	Lset11
	.byte	0                       ##   On action: cleanup
Lset12 = Ltmp122-Lfunc_begin1           ## >> Call Site 3 <<
	.long	Lset12
Lset13 = Lfunc_end1-Ltmp122             ##   Call between Ltmp122 and Lfunc_end1
	.long	Lset13
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEEC1Em
	.weak_def_can_be_hidden	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEEC1Em
	.p2align	4, 0x90
__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEEC1Em: ## @_ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEEC1Em
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
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	callq	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEEC2Em
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa4iotaIPiiEEvT_S2_T0_
	.weak_definition	__ZN3dsa4iotaIPiiEEvT_S2_T0_
	.p2align	4, 0x90
__ZN3dsa4iotaIPiiEEvT_S2_T0_:           ## @_ZN3dsa4iotaIPiiEEvT_S2_T0_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi33:
	.cfi_def_cfa_offset 16
Lcfi34:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi35:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
## BB#1:
	jmp	LBB11_2
LBB11_2:
	jmp	LBB11_3
LBB11_3:
	jmp	LBB11_4
LBB11_4:
	jmp	LBB11_5
LBB11_5:                                ## =>This Inner Loop Header: Depth=1
	movq	-8(%rbp), %rax
	cmpq	-16(%rbp), %rax
	je	LBB11_7
## BB#6:                                ##   in Loop: Header=BB11_5 Depth=1
	movl	-20(%rbp), %eax
	movl	%eax, %ecx
	addl	$1, %ecx
	movl	%ecx, -20(%rbp)
	movq	-8(%rbp), %rdx
	movq	%rdx, %rsi
	addq	$4, %rsi
	movq	%rsi, -8(%rbp)
	movl	%eax, (%rdx)
	jmp	LBB11_5
LBB11_7:
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEE5beginEv
	.weak_definition	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEE5beginEv
	.p2align	4, 0x90
__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEE5beginEv: ## @_ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEE5beginEv
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
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	(%rdi), %rax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEE3endEv
	.weak_definition	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEE3endEv
	.p2align	4, 0x90
__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEE3endEv: ## @_ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEE3endEv
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
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	8(%rdi), %rax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__17shuffleIPiNS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEEEvT_S4_OT0_
	.weak_definition	__ZNSt3__17shuffleIPiNS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEEEvT_S4_OT0_
	.p2align	4, 0x90
__ZNSt3__17shuffleIPiNS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEEEvT_S4_OT0_: ## @_ZNSt3__17shuffleIPiNS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEEEvT_S4_OT0_
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
	subq	$128, %rsp
	movq	%rdi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	-64(%rbp), %rdx
	movq	-56(%rbp), %rsi
	subq	%rsi, %rdx
	sarq	$2, %rdx
	movq	%rdx, -80(%rbp)
	cmpq	$1, -80(%rbp)
	jle	LBB14_8
## BB#1:
	leaq	-96(%rbp), %rdi
	xorl	%eax, %eax
	movl	%eax, %esi
	movabsq	$9223372036854775807, %rdx ## imm = 0x7FFFFFFFFFFFFFFF
	callq	__ZNSt3__124uniform_int_distributionIlEC1Ell
	movq	-64(%rbp), %rdx
	addq	$-4, %rdx
	movq	%rdx, -64(%rbp)
	movq	-80(%rbp), %rdx
	addq	$-1, %rdx
	movq	%rdx, -80(%rbp)
LBB14_2:                                ## =>This Inner Loop Header: Depth=1
	movq	-56(%rbp), %rax
	cmpq	-64(%rbp), %rax
	jae	LBB14_7
## BB#3:                                ##   in Loop: Header=BB14_2 Depth=1
	leaq	-120(%rbp), %rdi
	xorl	%eax, %eax
	movl	%eax, %esi
	movq	-72(%rbp), %rcx
	movq	-80(%rbp), %rdx
	movq	%rcx, -128(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__124uniform_int_distributionIlE10param_typeC1Ell
	leaq	-96(%rbp), %rdi
	leaq	-120(%rbp), %rdx
	movq	-128(%rbp), %rsi        ## 8-byte Reload
	callq	__ZNSt3__124uniform_int_distributionIlEclINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEEElRT_RKNS1_10param_typeE
	movq	%rax, -104(%rbp)
	cmpq	$0, -104(%rbp)
	je	LBB14_5
## BB#4:                                ##   in Loop: Header=BB14_2 Depth=1
	leaq	-44(%rbp), %rax
	movq	-56(%rbp), %rcx
	movq	-56(%rbp), %rdx
	movq	-104(%rbp), %rsi
	shlq	$2, %rsi
	addq	%rsi, %rdx
	movq	%rcx, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-32(%rbp), %rcx
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, -44(%rbp)
	movq	-40(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movl	(%rcx), %edi
	movq	-32(%rbp), %rcx
	movl	%edi, (%rcx)
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	(%rax), %edi
	movq	-40(%rbp), %rax
	movl	%edi, (%rax)
LBB14_5:                                ##   in Loop: Header=BB14_2 Depth=1
	jmp	LBB14_6
LBB14_6:                                ##   in Loop: Header=BB14_2 Depth=1
	movq	-56(%rbp), %rax
	addq	$4, %rax
	movq	%rax, -56(%rbp)
	movq	-80(%rbp), %rax
	addq	$-1, %rax
	movq	%rax, -80(%rbp)
	jmp	LBB14_2
LBB14_7:
	jmp	LBB14_8
LBB14_8:
	addq	$128, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa9make_pairIiiEENS_4pairIT_T0_EERKS2_RKS3_
	.weak_definition	__ZN3dsa9make_pairIiiEENS_4pairIT_T0_EERKS2_RKS3_
	.p2align	4, 0x90
__ZN3dsa9make_pairIiiEENS_4pairIT_T0_EERKS2_RKS3_: ## @_ZN3dsa9make_pairIiiEENS_4pairIT_T0_EERKS2_RKS3_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi45:
	.cfi_def_cfa_offset 16
Lcfi46:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi47:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	leaq	-8(%rbp), %rax
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	-16(%rbp), %rsi
	movq	-24(%rbp), %rdx
	movq	%rax, %rdi
	callq	__ZN3dsa4pairIiiEC1ERKiS3_
	movq	-8(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEEixEm
	.weak_definition	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEEixEm
	.p2align	4, 0x90
__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEEixEm: ## @_ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEEixEm
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
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEE5beginEv
	movq	-16(%rbp), %rsi
	shlq	$2, %rsi
	addq	%rsi, %rax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa8skiplistIiiE6insertENS_4pairIiiEE
	.weak_definition	__ZN3dsa8skiplistIiiE6insertENS_4pairIiiEE
	.p2align	4, 0x90
__ZN3dsa8skiplistIiiE6insertENS_4pairIiiEE: ## @_ZN3dsa8skiplistIiiE6insertENS_4pairIiiEE
Lfunc_begin2:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception2
## BB#0:
	pushq	%rbp
Lcfi51:
	.cfi_def_cfa_offset 16
Lcfi52:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi53:
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movq	%rsi, -8(%rbp)
	movq	%rdi, -16(%rbp)
	movq	-16(%rbp), %rsi
	movl	-8(%rbp), %eax
	cmpl	24(%rsi), %eax
	movq	%rsi, -64(%rbp)         ## 8-byte Spill
	jl	LBB17_2
## BB#1:
	jmp	LBB17_12
LBB17_2:
	leaq	-8(%rbp), %rsi
	movq	-64(%rbp), %rdi         ## 8-byte Reload
	callq	__ZN3dsa8skiplistIiiE8__searchERi
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %ecx
	cmpl	-8(%rbp), %ecx
	jne	LBB17_4
## BB#3:
	movl	-4(%rbp), %eax
	movq	-24(%rbp), %rcx
	movl	%eax, 4(%rcx)
	jmp	LBB17_12
LBB17_4:
	movq	-64(%rbp), %rdi         ## 8-byte Reload
	callq	__ZN3dsa8skiplistIiiE14__decide_levelEv
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	-64(%rbp), %rdi         ## 8-byte Reload
	cmpq	(%rdi), %rax
	jbe	LBB17_6
## BB#5:
	movq	-64(%rbp), %rax         ## 8-byte Reload
	movq	(%rax), %rcx
	addq	$1, %rcx
	movq	%rcx, (%rax)
	movq	%rcx, -32(%rbp)
	movq	32(%rax), %rcx
	movq	56(%rax), %rdx
	movq	-32(%rbp), %rsi
	movq	%rcx, (%rdx,%rsi,8)
LBB17_6:
	movl	$24, %eax
	movl	%eax, %edi
	callq	__Znwm
	movq	%rax, %rdi
	movq	%rax, %rcx
	movl	-32(%rbp), %edx
	incl	%edx
Ltmp124:
	leaq	-8(%rbp), %rsi
	movq	%rdi, -72(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rcx, -80(%rbp)         ## 8-byte Spill
	callq	__ZN3dsa15__skiplist_nodeIiiEC1ERNS_4pairIiiEEi
Ltmp125:
	jmp	LBB17_7
LBB17_7:
	movq	-80(%rbp), %rax         ## 8-byte Reload
	movq	%rax, -40(%rbp)
	movq	-64(%rbp), %rcx         ## 8-byte Reload
	movq	8(%rcx), %rdx
	addq	$1, %rdx
	movq	%rdx, 8(%rcx)
	movl	$0, -56(%rbp)
LBB17_8:                                ## =>This Inner Loop Header: Depth=1
	movslq	-56(%rbp), %rax
	cmpq	-32(%rbp), %rax
	ja	LBB17_12
## BB#9:                                ##   in Loop: Header=BB17_8 Depth=1
	movq	-64(%rbp), %rax         ## 8-byte Reload
	movq	56(%rax), %rcx
	movslq	-56(%rbp), %rdx
	movq	(%rcx,%rdx,8), %rcx
	movq	16(%rcx), %rcx
	movslq	-56(%rbp), %rdx
	movq	(%rcx,%rdx,8), %rcx
	movq	-40(%rbp), %rdx
	movq	16(%rdx), %rdx
	movslq	-56(%rbp), %rsi
	movq	%rcx, (%rdx,%rsi,8)
	movq	-40(%rbp), %rcx
	movq	56(%rax), %rdx
	movslq	-56(%rbp), %rsi
	movq	(%rdx,%rsi,8), %rdx
	movq	16(%rdx), %rdx
	movslq	-56(%rbp), %rsi
	movq	%rcx, (%rdx,%rsi,8)
## BB#10:                               ##   in Loop: Header=BB17_8 Depth=1
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	jmp	LBB17_8
LBB17_11:
Ltmp126:
	movl	%edx, %ecx
	movq	%rax, -48(%rbp)
	movl	%ecx, -52(%rbp)
	movq	-72(%rbp), %rdi         ## 8-byte Reload
	callq	__ZdlPv
	jmp	LBB17_13
LBB17_12:
	addq	$80, %rsp
	popq	%rbp
	retq
LBB17_13:
	movq	-48(%rbp), %rdi
	callq	__Unwind_Resume
Lfunc_end2:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table17:
Lexception2:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset14 = Lfunc_begin2-Lfunc_begin2      ## >> Call Site 1 <<
	.long	Lset14
Lset15 = Ltmp124-Lfunc_begin2           ##   Call between Lfunc_begin2 and Ltmp124
	.long	Lset15
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset16 = Ltmp124-Lfunc_begin2           ## >> Call Site 2 <<
	.long	Lset16
Lset17 = Ltmp125-Ltmp124                ##   Call between Ltmp124 and Ltmp125
	.long	Lset17
Lset18 = Ltmp126-Lfunc_begin2           ##     jumps to Ltmp126
	.long	Lset18
	.byte	0                       ##   On action: cleanup
Lset19 = Ltmp125-Lfunc_begin2           ## >> Call Site 3 <<
	.long	Lset19
Lset20 = Lfunc_end2-Ltmp125             ##   Call between Ltmp125 and Lfunc_end2
	.long	Lset20
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN3dsa8skiplistIiiE5countERi
	.weak_definition	__ZN3dsa8skiplistIiiE5countERi
	.p2align	4, 0x90
__ZN3dsa8skiplistIiiE5countERi:         ## @_ZN3dsa8skiplistIiiE5countERi
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
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	callq	__ZN3dsa8skiplistIiiE3getERi
	cmpq	$0, %rax
	setne	%cl
	andb	$1, %cl
	movzbl	%cl, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa8skiplistIiiE5eraseERi
	.weak_definition	__ZN3dsa8skiplistIiiE5eraseERi
	.p2align	4, 0x90
__ZN3dsa8skiplistIiiE5eraseERi:         ## @_ZN3dsa8skiplistIiiE5eraseERi
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
	subq	$64, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rsi
	movq	-16(%rbp), %rdi
	movl	(%rdi), %eax
	cmpl	24(%rsi), %eax
	movq	%rsi, -40(%rbp)         ## 8-byte Spill
	jl	LBB19_2
## BB#1:
	jmp	LBB19_18
LBB19_2:
	movq	-16(%rbp), %rsi
	movq	-40(%rbp), %rdi         ## 8-byte Reload
	callq	__ZN3dsa8skiplistIiiE8__searchERi
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %ecx
	movq	-16(%rbp), %rax
	cmpl	(%rax), %ecx
	je	LBB19_4
## BB#3:
	jmp	LBB19_18
LBB19_4:
	movl	$0, -28(%rbp)
LBB19_5:                                ## =>This Inner Loop Header: Depth=1
	xorl	%eax, %eax
	movb	%al, %cl
	movslq	-28(%rbp), %rdx
	movq	-40(%rbp), %rsi         ## 8-byte Reload
	cmpq	(%rsi), %rdx
	movb	%cl, -41(%rbp)          ## 1-byte Spill
	ja	LBB19_7
## BB#6:                                ##   in Loop: Header=BB19_5 Depth=1
	movq	-40(%rbp), %rax         ## 8-byte Reload
	movq	56(%rax), %rcx
	movslq	-28(%rbp), %rdx
	movq	(%rcx,%rdx,8), %rcx
	movq	16(%rcx), %rcx
	movslq	-28(%rbp), %rdx
	movq	(%rcx,%rdx,8), %rcx
	cmpq	-24(%rbp), %rcx
	sete	%sil
	movb	%sil, -41(%rbp)         ## 1-byte Spill
LBB19_7:                                ##   in Loop: Header=BB19_5 Depth=1
	movb	-41(%rbp), %al          ## 1-byte Reload
	testb	$1, %al
	jne	LBB19_8
	jmp	LBB19_10
LBB19_8:                                ##   in Loop: Header=BB19_5 Depth=1
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movslq	-28(%rbp), %rcx
	movq	(%rax,%rcx,8), %rax
	movq	-40(%rbp), %rcx         ## 8-byte Reload
	movq	56(%rcx), %rdx
	movslq	-28(%rbp), %rsi
	movq	(%rdx,%rsi,8), %rdx
	movq	16(%rdx), %rdx
	movslq	-28(%rbp), %rsi
	movq	%rax, (%rdx,%rsi,8)
## BB#9:                                ##   in Loop: Header=BB19_5 Depth=1
	movl	-28(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -28(%rbp)
	jmp	LBB19_5
LBB19_10:
	jmp	LBB19_11
LBB19_11:                               ## =>This Inner Loop Header: Depth=1
	xorl	%eax, %eax
	movb	%al, %cl
	movq	-40(%rbp), %rdx         ## 8-byte Reload
	cmpq	$0, (%rdx)
	movb	%cl, -42(%rbp)          ## 1-byte Spill
	jbe	LBB19_13
## BB#12:                               ##   in Loop: Header=BB19_11 Depth=1
	movq	-40(%rbp), %rax         ## 8-byte Reload
	movq	32(%rax), %rcx
	movq	16(%rcx), %rcx
	movq	(%rax), %rdx
	movq	(%rcx,%rdx,8), %rcx
	cmpq	40(%rax), %rcx
	sete	%sil
	movb	%sil, -42(%rbp)         ## 1-byte Spill
LBB19_13:                               ##   in Loop: Header=BB19_11 Depth=1
	movb	-42(%rbp), %al          ## 1-byte Reload
	testb	$1, %al
	jne	LBB19_14
	jmp	LBB19_15
LBB19_14:                               ##   in Loop: Header=BB19_11 Depth=1
	movq	-40(%rbp), %rax         ## 8-byte Reload
	movq	(%rax), %rcx
	addq	$-1, %rcx
	movq	%rcx, (%rax)
	jmp	LBB19_11
LBB19_15:
	movq	-24(%rbp), %rax
	cmpq	$0, %rax
	movq	%rax, -56(%rbp)         ## 8-byte Spill
	je	LBB19_17
## BB#16:
	movq	-56(%rbp), %rdi         ## 8-byte Reload
	callq	__ZN3dsa15__skiplist_nodeIiiED1Ev
	movq	-56(%rbp), %rdi         ## 8-byte Reload
	callq	__ZdlPv
LBB19_17:
	movq	-40(%rbp), %rax         ## 8-byte Reload
	movq	8(%rax), %rcx
	addq	$-1, %rcx
	movq	%rcx, 8(%rax)
LBB19_18:
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEED1Ev
	.weak_def_can_be_hidden	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEED1Ev
	.p2align	4, 0x90
__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEED1Ev: ## @_ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEED1Ev
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
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEED2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
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
	xorl	%eax, %eax
	movl	%eax, %ecx
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rcx, %rdi
	callq	_time
	movl	%eax, %edx
	movl	%edx, %edi
	callq	_srand
	movl	$100000, %edi           ## imm = 0x186A0
	callq	__Z19performance_comparei
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__13setIiNS_4lessIiEENS_9allocatorIiEEED2Ev
	.weak_def_can_be_hidden	__ZNSt3__13setIiNS_4lessIiEENS_9allocatorIiEEED2Ev
	.p2align	4, 0x90
__ZNSt3__13setIiNS_4lessIiEENS_9allocatorIiEEED2Ev: ## @_ZNSt3__13setIiNS_4lessIiEENS_9allocatorIiEEED2Ev
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
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEED1Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEED1Ev
	.weak_def_can_be_hidden	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEED1Ev
	.p2align	4, 0x90
__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEED1Ev: ## @_ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEED1Ev
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
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEED2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEED2Ev
	.weak_def_can_be_hidden	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEED2Ev
	.p2align	4, 0x90
__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEED2Ev: ## @_ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEED2Ev
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
	subq	$64, %rsp
	movq	%rdi, -56(%rbp)
	movq	-56(%rbp), %rdi
	movq	%rdi, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	callq	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE7destroyEPNS_11__tree_nodeIiPvEE
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE7destroyEPNS_11__tree_nodeIiPvEE
	.weak_definition	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE7destroyEPNS_11__tree_nodeIiPvEE
	.p2align	4, 0x90
__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE7destroyEPNS_11__tree_nodeIiPvEE: ## @_ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE7destroyEPNS_11__tree_nodeIiPvEE
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
	subq	$192, %rsp
	movq	%rdi, -152(%rbp)
	movq	%rsi, -160(%rbp)
	movq	-152(%rbp), %rsi
	cmpq	$0, -160(%rbp)
	movq	%rsi, -176(%rbp)        ## 8-byte Spill
	je	LBB25_4
## BB#1:
	movq	-160(%rbp), %rax
	movq	(%rax), %rax
	movq	-176(%rbp), %rdi        ## 8-byte Reload
	movq	%rax, %rsi
	callq	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE7destroyEPNS_11__tree_nodeIiPvEE
	movq	-160(%rbp), %rax
	movq	8(%rax), %rax
	movq	-176(%rbp), %rdi        ## 8-byte Reload
	movq	%rax, %rsi
	callq	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE7destroyEPNS_11__tree_nodeIiPvEE
	movq	-176(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -88(%rbp)
	movq	-88(%rbp), %rsi
	addq	$8, %rsi
	movq	%rsi, -80(%rbp)
	movq	-80(%rbp), %rsi
	movq	%rsi, -72(%rbp)
	movq	-72(%rbp), %rsi
	movq	%rsi, -168(%rbp)
	movq	-168(%rbp), %rsi
	movq	-160(%rbp), %rdi
	addq	$28, %rdi
	movq	%rdi, -64(%rbp)
	movq	-64(%rbp), %rdi
	movq	%rdi, -56(%rbp)
	movq	-56(%rbp), %rdi
	movq	%rsi, -184(%rbp)        ## 8-byte Spill
	movq	%rdi, -192(%rbp)        ## 8-byte Spill
## BB#2:
	movq	-184(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -24(%rbp)
	movq	-192(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -32(%rbp)
	movq	-24(%rbp), %rdx
	movq	-32(%rbp), %rsi
	movq	%rdx, -8(%rbp)
	movq	%rsi, -16(%rbp)
## BB#3:
	movq	-168(%rbp), %rax
	movq	-160(%rbp), %rcx
	movq	%rax, -128(%rbp)
	movq	%rcx, -136(%rbp)
	movq	$1, -144(%rbp)
	movq	-128(%rbp), %rax
	movq	-136(%rbp), %rcx
	movq	-144(%rbp), %rdx
	movq	%rax, -104(%rbp)
	movq	%rcx, -112(%rbp)
	movq	%rdx, -120(%rbp)
	movq	-112(%rbp), %rax
	movq	%rax, -96(%rbp)
	movq	-96(%rbp), %rdi
	callq	__ZdlPv
LBB25_4:
	addq	$192, %rsp
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

	.section	__TEXT,__literal16,16byte_literals
	.p2align	4
LCPI27_0:
	.long	1127219200              ## 0x43300000
	.long	1160773632              ## 0x45300000
	.long	0                       ## 0x0
	.long	0                       ## 0x0
LCPI27_1:
	.quad	4841369599423283200     ## double 4503599627370496
	.quad	4985484787499139072     ## double 1.9342813113834067E+25
	.section	__TEXT,__literal4,4byte_literals
	.p2align	2
LCPI27_2:
	.long	1073741824              ## float 2
LCPI27_3:
	.long	1593835520              ## float 9.22337203E+18
	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN3dsa8skiplistIiiEC2Eim
	.weak_def_can_be_hidden	__ZN3dsa8skiplistIiiEC2Eim
	.p2align	4, 0x90
__ZN3dsa8skiplistIiiEC2Eim:             ## @_ZN3dsa8skiplistIiiEC2Eim
Lfunc_begin3:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception3
## BB#0:
	pushq	%rbp
Lcfi78:
	.cfi_def_cfa_offset 16
Lcfi79:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi80:
	.cfi_def_cfa_register %rbp
	subq	$144, %rsp
	movq	%rdi, -16(%rbp)
	movl	%esi, -20(%rbp)
	movq	%rdx, -32(%rbp)
	movq	-16(%rbp), %rdx
	movaps	LCPI27_0(%rip), %xmm0   ## xmm0 = [1127219200,1160773632,0,0]
	movq	-32(%rbp), %xmm1        ## xmm1 = mem[0],zero
	punpckldq	%xmm0, %xmm1    ## xmm1 = xmm1[0],xmm0[0],xmm1[1],xmm0[1]
	movapd	LCPI27_1(%rip), %xmm0   ## xmm0 = [4.503600e+15,1.934281e+25]
	subpd	%xmm0, %xmm1
	haddpd	%xmm1, %xmm1
	cvtsd2ss	%xmm1, %xmm0
	movq	%rdx, -64(%rbp)         ## 8-byte Spill
	callq	_logf
	movss	LCPI27_2(%rip), %xmm1   ## xmm1 = mem[0],zero,zero,zero
	movss	%xmm0, -68(%rbp)        ## 4-byte Spill
	movaps	%xmm1, %xmm0
	callq	_logf
	movss	-68(%rbp), %xmm1        ## 4-byte Reload
                                        ## xmm1 = mem[0],zero,zero,zero
	divss	%xmm0, %xmm1
	movss	%xmm1, -4(%rbp)
	movss	-4(%rbp), %xmm0         ## xmm0 = mem[0],zero,zero,zero
	roundss	$10, %xmm0, %xmm0
	movss	LCPI27_3(%rip), %xmm1   ## xmm1 = mem[0],zero,zero,zero
	movaps	%xmm0, %xmm2
	subss	%xmm1, %xmm2
	cvttss2si	%xmm2, %rdx
	movabsq	$-9223372036854775808, %rdi ## imm = 0x8000000000000000
	xorq	%rdi, %rdx
	cvttss2si	%xmm0, %rdi
	ucomiss	%xmm1, %xmm0
	cmovbq	%rdi, %rdx
	decq	%rdx
	movq	-64(%rbp), %rdi         ## 8-byte Reload
	movq	%rdx, 16(%rdi)
	movq	$0, (%rdi)
	movq	$0, 8(%rdi)
	movl	-20(%rbp), %esi
	movl	%esi, 24(%rdi)
	leaq	-40(%rbp), %rdx
	movq	%rdx, %rdi
	movq	%rdx, -80(%rbp)         ## 8-byte Spill
	callq	__ZN3dsa4pairIiiEC1Ev
	movq	-64(%rbp), %rdx         ## 8-byte Reload
	movl	24(%rdx), %esi
	movl	%esi, -40(%rbp)
	movl	$24, %esi
	movl	%esi, %edi
	callq	__Znwm
	movq	%rax, %rdx
	movq	%rax, %rdi
	movq	-64(%rbp), %rcx         ## 8-byte Reload
	movl	16(%rcx), %esi
	incl	%esi
Ltmp127:
	movq	%rdi, -88(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	-80(%rbp), %rax         ## 8-byte Reload
	movl	%esi, -92(%rbp)         ## 4-byte Spill
	movq	%rax, %rsi
	movl	-92(%rbp), %r8d         ## 4-byte Reload
	movq	%rdx, -104(%rbp)        ## 8-byte Spill
	movl	%r8d, %edx
	callq	__ZN3dsa15__skiplist_nodeIiiEC1ERNS_4pairIiiEEi
Ltmp128:
	jmp	LBB27_1
LBB27_1:
	movq	-64(%rbp), %rax         ## 8-byte Reload
	movq	-88(%rbp), %rcx         ## 8-byte Reload
	movq	%rcx, 32(%rax)
	movl	$24, %edx
	movl	%edx, %edi
	callq	__Znwm
	movq	%rax, %rcx
	movq	%rax, %rdi
Ltmp130:
	leaq	-40(%rbp), %rsi
	xorl	%edx, %edx
	movq	%rdi, -112(%rbp)        ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rcx, -120(%rbp)        ## 8-byte Spill
	callq	__ZN3dsa15__skiplist_nodeIiiEC1ERNS_4pairIiiEEi
Ltmp131:
	jmp	LBB27_2
LBB27_2:
	movq	$-1, %rax
	movl	$8, %ecx
	movl	%ecx, %edx
	movq	-64(%rbp), %rsi         ## 8-byte Reload
	movq	-112(%rbp), %rdi        ## 8-byte Reload
	movq	%rdi, 40(%rsi)
	movq	16(%rsi), %r8
	addq	$1, %r8
	movq	%rax, -128(%rbp)        ## 8-byte Spill
	movq	%r8, %rax
	mulq	%rdx
	seto	%r9b
	movq	-128(%rbp), %r8         ## 8-byte Reload
	cmovoq	%r8, %rax
	movq	%rax, %rdi
	movb	%r9b, -129(%rbp)        ## 1-byte Spill
	callq	__Znam
	movq	-64(%rbp), %rsi         ## 8-byte Reload
	movq	%rax, 56(%rsi)
	movq	32(%rsi), %rax
	movq	16(%rax), %rdi
	movq	32(%rsi), %rax
	movq	16(%rax), %rax
	movq	16(%rsi), %r8
	shlq	$3, %r8
	addq	%r8, %rax
	addq	$8, %rax
	addq	$40, %rsi
	movq	%rsi, -144(%rbp)        ## 8-byte Spill
	movq	%rax, %rsi
	movq	-144(%rbp), %rax        ## 8-byte Reload
	movq	%rax, %rdx
	callq	__ZN3dsa4fillIPPNS_15__skiplist_nodeIiiEES3_EEvT_S5_RKT0_
	addq	$144, %rsp
	popq	%rbp
	retq
LBB27_3:
Ltmp129:
	movl	%edx, %ecx
	movq	%rax, -48(%rbp)
	movl	%ecx, -52(%rbp)
	movq	-104(%rbp), %rdi        ## 8-byte Reload
	callq	__ZdlPv
	jmp	LBB27_5
LBB27_4:
Ltmp132:
	movl	%edx, %ecx
	movq	%rax, -48(%rbp)
	movl	%ecx, -52(%rbp)
	movq	-120(%rbp), %rdi        ## 8-byte Reload
	callq	__ZdlPv
LBB27_5:
	movq	-48(%rbp), %rdi
	callq	__Unwind_Resume
Lfunc_end3:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table27:
Lexception3:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.asciz	"\303\200"              ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	65                      ## Call site table length
Lset21 = Lfunc_begin3-Lfunc_begin3      ## >> Call Site 1 <<
	.long	Lset21
Lset22 = Ltmp127-Lfunc_begin3           ##   Call between Lfunc_begin3 and Ltmp127
	.long	Lset22
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset23 = Ltmp127-Lfunc_begin3           ## >> Call Site 2 <<
	.long	Lset23
Lset24 = Ltmp128-Ltmp127                ##   Call between Ltmp127 and Ltmp128
	.long	Lset24
Lset25 = Ltmp129-Lfunc_begin3           ##     jumps to Ltmp129
	.long	Lset25
	.byte	0                       ##   On action: cleanup
Lset26 = Ltmp128-Lfunc_begin3           ## >> Call Site 3 <<
	.long	Lset26
Lset27 = Ltmp130-Ltmp128                ##   Call between Ltmp128 and Ltmp130
	.long	Lset27
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset28 = Ltmp130-Lfunc_begin3           ## >> Call Site 4 <<
	.long	Lset28
Lset29 = Ltmp131-Ltmp130                ##   Call between Ltmp130 and Ltmp131
	.long	Lset29
Lset30 = Ltmp132-Lfunc_begin3           ##     jumps to Ltmp132
	.long	Lset30
	.byte	0                       ##   On action: cleanup
Lset31 = Ltmp131-Lfunc_begin3           ## >> Call Site 5 <<
	.long	Lset31
Lset32 = Lfunc_end3-Ltmp131             ##   Call between Ltmp131 and Lfunc_end3
	.long	Lset32
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN3dsa15__skiplist_nodeIiiEC1ERNS_4pairIiiEEi
	.weak_def_can_be_hidden	__ZN3dsa15__skiplist_nodeIiiEC1ERNS_4pairIiiEEi
	.p2align	4, 0x90
__ZN3dsa15__skiplist_nodeIiiEC1ERNS_4pairIiiEEi: ## @_ZN3dsa15__skiplist_nodeIiiEC1ERNS_4pairIiiEEi
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
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	movl	-20(%rbp), %edx
	callq	__ZN3dsa15__skiplist_nodeIiiEC2ERNS_4pairIiiEEi
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa4fillIPPNS_15__skiplist_nodeIiiEES3_EEvT_S5_RKT0_
	.weak_definition	__ZN3dsa4fillIPPNS_15__skiplist_nodeIiiEES3_EEvT_S5_RKT0_
	.p2align	4, 0x90
__ZN3dsa4fillIPPNS_15__skiplist_nodeIiiEES3_EEvT_S5_RKT0_: ## @_ZN3dsa4fillIPPNS_15__skiplist_nodeIiiEES3_EEvT_S5_RKT0_
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
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
## BB#1:
	jmp	LBB29_2
LBB29_2:
	jmp	LBB29_3
LBB29_3:                                ## =>This Inner Loop Header: Depth=1
	movq	-8(%rbp), %rax
	cmpq	-16(%rbp), %rax
	je	LBB29_6
## BB#4:                                ##   in Loop: Header=BB29_3 Depth=1
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	movq	%rax, (%rcx)
## BB#5:                                ##   in Loop: Header=BB29_3 Depth=1
	movq	-8(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -8(%rbp)
	jmp	LBB29_3
LBB29_6:
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa15__skiplist_nodeIiiEC2ERNS_4pairIiiEEi
	.weak_def_can_be_hidden	__ZN3dsa15__skiplist_nodeIiiEC2ERNS_4pairIiiEEi
	.p2align	4, 0x90
__ZN3dsa15__skiplist_nodeIiiEC2ERNS_4pairIiiEEi: ## @_ZN3dsa15__skiplist_nodeIiiEC2ERNS_4pairIiiEEi
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
	subq	$48, %rsp
	movq	$-1, %rax
	movl	$8, %ecx
	movl	%ecx, %r8d
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
	movq	-8(%rbp), %rsi
	movq	-16(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rdi, (%rsi)
	movslq	-20(%rbp), %rdi
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	movq	%rdi, %rax
	mulq	%r8
	seto	%r9b
	movq	-32(%rbp), %rdi         ## 8-byte Reload
	cmovoq	%rdi, %rax
	movq	%rax, %rdi
	movq	%rsi, -40(%rbp)         ## 8-byte Spill
	movb	%r9b, -41(%rbp)         ## 1-byte Spill
	callq	__Znam
	movq	-40(%rbp), %rsi         ## 8-byte Reload
	movq	%rax, 16(%rsi)
	movl	-20(%rbp), %ecx
	movl	%ecx, 8(%rsi)
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa8skiplistIiiED2Ev
	.weak_def_can_be_hidden	__ZN3dsa8skiplistIiiED2Ev
	.p2align	4, 0x90
__ZN3dsa8skiplistIiiED2Ev:              ## @_ZN3dsa8skiplistIiiED2Ev
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
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
LBB31_1:                                ## =>This Inner Loop Header: Depth=1
	movq	-24(%rbp), %rax         ## 8-byte Reload
	movq	32(%rax), %rcx
	cmpq	40(%rax), %rcx
	je	LBB31_5
## BB#2:                                ##   in Loop: Header=BB31_1 Depth=1
	movq	-24(%rbp), %rax         ## 8-byte Reload
	movq	32(%rax), %rcx
	movq	16(%rcx), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -16(%rbp)
	movq	32(%rax), %rcx
	cmpq	$0, %rcx
	movq	%rcx, -32(%rbp)         ## 8-byte Spill
	je	LBB31_4
## BB#3:                                ##   in Loop: Header=BB31_1 Depth=1
	movq	-32(%rbp), %rdi         ## 8-byte Reload
	callq	__ZN3dsa15__skiplist_nodeIiiED1Ev
	movq	-32(%rbp), %rdi         ## 8-byte Reload
	callq	__ZdlPv
LBB31_4:                                ##   in Loop: Header=BB31_1 Depth=1
	movq	-16(%rbp), %rax
	movq	-24(%rbp), %rcx         ## 8-byte Reload
	movq	%rax, 32(%rcx)
	jmp	LBB31_1
LBB31_5:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	movq	40(%rax), %rcx
	cmpq	$0, %rcx
	movq	%rcx, -40(%rbp)         ## 8-byte Spill
	je	LBB31_7
## BB#6:
	movq	-40(%rbp), %rdi         ## 8-byte Reload
	callq	__ZN3dsa15__skiplist_nodeIiiED1Ev
	movq	-40(%rbp), %rdi         ## 8-byte Reload
	callq	__ZdlPv
LBB31_7:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	movq	56(%rax), %rcx
	cmpq	$0, %rcx
	movq	%rcx, -48(%rbp)         ## 8-byte Spill
	je	LBB31_9
## BB#8:
	movq	-48(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	__ZdaPv
LBB31_9:
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa15__skiplist_nodeIiiED1Ev
	.weak_def_can_be_hidden	__ZN3dsa15__skiplist_nodeIiiED1Ev
	.p2align	4, 0x90
__ZN3dsa15__skiplist_nodeIiiED1Ev:      ## @_ZN3dsa15__skiplist_nodeIiiED1Ev
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
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZN3dsa15__skiplist_nodeIiiED2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa15__skiplist_nodeIiiED2Ev
	.weak_def_can_be_hidden	__ZN3dsa15__skiplist_nodeIiiED2Ev
	.p2align	4, 0x90
__ZN3dsa15__skiplist_nodeIiiED2Ev:      ## @_ZN3dsa15__skiplist_nodeIiiED2Ev
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
	movq	-8(%rbp), %rdi
	movq	16(%rdi), %rdi
	cmpq	$0, %rdi
	movq	%rdi, -16(%rbp)         ## 8-byte Spill
	je	LBB33_2
## BB#1:
	movq	-16(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	__ZdaPv
LBB33_2:
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEEC1ERKS2_
	.weak_def_can_be_hidden	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEEC1ERKS2_
	.p2align	4, 0x90
__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEEC1ERKS2_: ## @_ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEEC1ERKS2_
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
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	callq	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEEC2ERKS2_
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEEC2ERKS2_
	.weak_def_can_be_hidden	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEEC2ERKS2_
	.p2align	4, 0x90
__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEEC2ERKS2_: ## @_ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEEC2ERKS2_
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
	subq	$112, %rsp
	movq	%rdi, -216(%rbp)
	movq	%rsi, -224(%rbp)
	movq	-216(%rbp), %rsi
	movq	%rsi, %rdi
	addq	$8, %rdi
	movq	%rdi, -208(%rbp)
	movq	-208(%rbp), %rdi
	movq	%rdi, -200(%rbp)
	movq	-200(%rbp), %rdi
	movq	%rdi, -192(%rbp)
	movq	-192(%rbp), %rdi
	movq	%rdi, %rax
	movq	%rax, -184(%rbp)
	movq	%rdi, -176(%rbp)
	movq	-176(%rbp), %rax
	movq	%rax, -168(%rbp)
	movq	-168(%rbp), %rax
	movq	$0, (%rax)
	movq	%rsi, -240(%rbp)        ## 8-byte Spill
## BB#1:
	leaq	-96(%rbp), %rax
	leaq	-80(%rbp), %rcx
	leaq	-112(%rbp), %rdx
	leaq	-128(%rbp), %rsi
	movq	-240(%rbp), %rdi        ## 8-byte Reload
	addq	$16, %rdi
	movq	%rdi, -152(%rbp)
	movq	$0, -160(%rbp)
	movq	-152(%rbp), %rdi
	movq	-160(%rbp), %r8
	movq	%rdi, -120(%rbp)
	movq	%r8, -128(%rbp)
	movq	-120(%rbp), %rdi
	movq	%rsi, -104(%rbp)
	movq	-104(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rdx, -56(%rbp)
	movq	%rdi, -88(%rbp)
	movq	%rsi, -96(%rbp)
	movq	-88(%rbp), %rdx
	movq	%rcx, -72(%rbp)
	movq	%rax, -64(%rbp)
	movq	-64(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, (%rdx)
## BB#2:
	movq	-240(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rcx
	addq	$8, %rcx
	movq	%rcx, -32(%rbp)
	movq	-32(%rbp), %rcx
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rcx
	movq	%rcx, -16(%rbp)
	movq	-16(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rdx
	movq	%rcx, (%rdx)
	addq	$112, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa4pairIiiEC2Ev
	.weak_def_can_be_hidden	__ZN3dsa4pairIiiEC2Ev
	.p2align	4, 0x90
__ZN3dsa4pairIiiEC2Ev:                  ## @_ZN3dsa4pairIiiEC2Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi105:
	.cfi_def_cfa_offset 16
Lcfi106:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi107:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movl	$0, (%rdi)
	movl	$0, 4(%rdi)
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
	.weak_definition	__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
	.p2align	4, 0x90
__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m: ## @_ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
Lfunc_begin4:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception4
## BB#0:
	pushq	%rbp
Lcfi108:
	.cfi_def_cfa_offset 16
Lcfi109:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi110:
	.cfi_def_cfa_register %rbp
	subq	$384, %rsp              ## imm = 0x180
	movq	%rdi, -184(%rbp)
	movq	%rsi, -192(%rbp)
	movq	%rdx, -200(%rbp)
	movq	-184(%rbp), %rsi
Ltmp133:
	leaq	-216(%rbp), %rdi
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryC1ERS3_
Ltmp134:
	jmp	LBB37_1
LBB37_1:
	leaq	-216(%rbp), %rax
	movq	%rax, -176(%rbp)
	movq	-176(%rbp), %rax
	movb	(%rax), %cl
	movb	%cl, -249(%rbp)         ## 1-byte Spill
## BB#2:
	movb	-249(%rbp), %al         ## 1-byte Reload
	testb	$1, %al
	jne	LBB37_3
	jmp	LBB37_26
LBB37_3:
	leaq	-248(%rbp), %rax
	movq	-184(%rbp), %rcx
	movq	%rax, -160(%rbp)
	movq	%rcx, -168(%rbp)
	movq	-160(%rbp), %rax
	movq	-168(%rbp), %rcx
	movq	%rax, -144(%rbp)
	movq	%rcx, -152(%rbp)
	movq	-144(%rbp), %rax
	movq	-152(%rbp), %rcx
	movq	(%rcx), %rdx
	movq	-24(%rdx), %rdx
	addq	%rdx, %rcx
	movq	%rcx, -136(%rbp)
	movq	-136(%rbp), %rcx
	movq	%rcx, -128(%rbp)
	movq	-128(%rbp), %rcx
	movq	40(%rcx), %rcx
	movq	%rcx, (%rax)
	movq	-192(%rbp), %rsi
	movq	-184(%rbp), %rax
	movq	(%rax), %rcx
	movq	-24(%rcx), %rcx
	addq	%rcx, %rax
	movq	%rax, -88(%rbp)
	movq	-88(%rbp), %rax
	movl	8(%rax), %edi
	movq	%rsi, -264(%rbp)        ## 8-byte Spill
	movl	%edi, -268(%rbp)        ## 4-byte Spill
## BB#4:
	movl	-268(%rbp), %eax        ## 4-byte Reload
	andl	$176, %eax
	cmpl	$32, %eax
	jne	LBB37_6
## BB#5:
	movq	-192(%rbp), %rax
	addq	-200(%rbp), %rax
	movq	%rax, -280(%rbp)        ## 8-byte Spill
	jmp	LBB37_7
LBB37_6:
	movq	-192(%rbp), %rax
	movq	%rax, -280(%rbp)        ## 8-byte Spill
LBB37_7:
	movq	-280(%rbp), %rax        ## 8-byte Reload
	movq	-192(%rbp), %rcx
	addq	-200(%rbp), %rcx
	movq	-184(%rbp), %rdx
	movq	(%rdx), %rsi
	movq	-24(%rsi), %rsi
	addq	%rsi, %rdx
	movq	-184(%rbp), %rsi
	movq	(%rsi), %rdi
	movq	-24(%rdi), %rdi
	addq	%rdi, %rsi
	movq	%rsi, -72(%rbp)
	movq	-72(%rbp), %rsi
	movq	%rax, -288(%rbp)        ## 8-byte Spill
	movq	%rcx, -296(%rbp)        ## 8-byte Spill
	movq	%rdx, -304(%rbp)        ## 8-byte Spill
	movq	%rsi, -312(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__111char_traitsIcE3eofEv
	movq	-312(%rbp), %rcx        ## 8-byte Reload
	movl	144(%rcx), %esi
	movl	%eax, %edi
	callq	__ZNSt3__111char_traitsIcE11eq_int_typeEii
	testb	$1, %al
	jne	LBB37_8
	jmp	LBB37_13
LBB37_8:
	movq	-312(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -32(%rbp)
	movb	$32, -33(%rbp)
	movq	-32(%rbp), %rsi
Ltmp136:
	leaq	-48(%rbp), %rdi
	callq	__ZNKSt3__18ios_base6getlocEv
Ltmp137:
	jmp	LBB37_9
LBB37_9:
	leaq	-48(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rdi
Ltmp138:
	movq	__ZNSt3__15ctypeIcE2idE@GOTPCREL(%rip), %rsi
	callq	__ZNKSt3__16locale9use_facetERNS0_2idE
Ltmp139:
	movq	%rax, -320(%rbp)        ## 8-byte Spill
	jmp	LBB37_10
LBB37_10:
	movb	-33(%rbp), %al
	movq	-320(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -8(%rbp)
	movb	%al, -9(%rbp)
	movq	-8(%rbp), %rdx
	movq	(%rdx), %rsi
	movq	56(%rsi), %rsi
	movsbl	-9(%rbp), %edi
Ltmp140:
	movl	%edi, -324(%rbp)        ## 4-byte Spill
	movq	%rdx, %rdi
	movl	-324(%rbp), %r8d        ## 4-byte Reload
	movq	%rsi, -336(%rbp)        ## 8-byte Spill
	movl	%r8d, %esi
	movq	-336(%rbp), %rdx        ## 8-byte Reload
	callq	*%rdx
Ltmp141:
	movb	%al, -337(%rbp)         ## 1-byte Spill
	jmp	LBB37_12
LBB37_11:
Ltmp142:
	movl	%edx, %ecx
	movq	%rax, -56(%rbp)
	movl	%ecx, -60(%rbp)
	leaq	-48(%rbp), %rdi
	callq	__ZNSt3__16localeD1Ev
	movq	-56(%rbp), %rax
	movl	-60(%rbp), %ecx
	movq	%rax, -352(%rbp)        ## 8-byte Spill
	movl	%ecx, -356(%rbp)        ## 4-byte Spill
	jmp	LBB37_21
LBB37_12:
	leaq	-48(%rbp), %rdi
	callq	__ZNSt3__16localeD1Ev
	movb	-337(%rbp), %al         ## 1-byte Reload
	movsbl	%al, %ecx
	movq	-312(%rbp), %rdi        ## 8-byte Reload
	movl	%ecx, 144(%rdi)
LBB37_13:
	movq	-312(%rbp), %rax        ## 8-byte Reload
	movl	144(%rax), %ecx
	movb	%cl, %dl
	movb	%dl, -357(%rbp)         ## 1-byte Spill
## BB#14:
	movq	-248(%rbp), %rdi
Ltmp143:
	movb	-357(%rbp), %al         ## 1-byte Reload
	movsbl	%al, %r9d
	movq	-264(%rbp), %rsi        ## 8-byte Reload
	movq	-288(%rbp), %rdx        ## 8-byte Reload
	movq	-296(%rbp), %rcx        ## 8-byte Reload
	movq	-304(%rbp), %r8         ## 8-byte Reload
	callq	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
Ltmp144:
	movq	%rax, -368(%rbp)        ## 8-byte Spill
	jmp	LBB37_15
LBB37_15:
	leaq	-240(%rbp), %rax
	movq	-368(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -240(%rbp)
	movq	%rax, -80(%rbp)
	movq	-80(%rbp), %rax
	cmpq	$0, (%rax)
	jne	LBB37_25
## BB#16:
	movq	-184(%rbp), %rax
	movq	(%rax), %rcx
	movq	-24(%rcx), %rcx
	addq	%rcx, %rax
	movq	%rax, -112(%rbp)
	movl	$5, -116(%rbp)
	movq	-112(%rbp), %rax
	movl	-116(%rbp), %edx
	movq	%rax, -96(%rbp)
	movl	%edx, -100(%rbp)
	movq	-96(%rbp), %rax
	movl	32(%rax), %edx
	movl	-100(%rbp), %esi
	orl	%esi, %edx
Ltmp145:
	movq	%rax, %rdi
	movl	%edx, %esi
	callq	__ZNSt3__18ios_base5clearEj
Ltmp146:
	jmp	LBB37_17
LBB37_17:
	jmp	LBB37_18
LBB37_18:
	jmp	LBB37_25
LBB37_19:
Ltmp135:
	movl	%edx, %ecx
	movq	%rax, -224(%rbp)
	movl	%ecx, -228(%rbp)
	jmp	LBB37_22
LBB37_20:
Ltmp147:
	movl	%edx, %ecx
	movq	%rax, -352(%rbp)        ## 8-byte Spill
	movl	%ecx, -356(%rbp)        ## 4-byte Spill
	jmp	LBB37_21
LBB37_21:
	movl	-356(%rbp), %eax        ## 4-byte Reload
	movq	-352(%rbp), %rcx        ## 8-byte Reload
	leaq	-216(%rbp), %rdi
	movq	%rcx, -224(%rbp)
	movl	%eax, -228(%rbp)
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev
LBB37_22:
	movq	-224(%rbp), %rdi
	callq	___cxa_begin_catch
	movq	-184(%rbp), %rdi
	movq	(%rdi), %rcx
	movq	-24(%rcx), %rcx
	addq	%rcx, %rdi
Ltmp148:
	movq	%rax, -376(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__18ios_base33__set_badbit_and_consider_rethrowEv
Ltmp149:
	jmp	LBB37_23
LBB37_23:
	callq	___cxa_end_catch
LBB37_24:
	movq	-184(%rbp), %rax
	addq	$384, %rsp              ## imm = 0x180
	popq	%rbp
	retq
LBB37_25:
	jmp	LBB37_26
LBB37_26:
	leaq	-216(%rbp), %rdi
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev
	jmp	LBB37_24
LBB37_27:
Ltmp150:
	movl	%edx, %ecx
	movq	%rax, -224(%rbp)
	movl	%ecx, -228(%rbp)
Ltmp151:
	callq	___cxa_end_catch
Ltmp152:
	jmp	LBB37_28
LBB37_28:
	jmp	LBB37_29
LBB37_29:
	movq	-224(%rbp), %rdi
	callq	__Unwind_Resume
LBB37_30:
Ltmp153:
	movl	%edx, %ecx
	movq	%rax, %rdi
	movl	%ecx, -380(%rbp)        ## 4-byte Spill
	callq	___clang_call_terminate
Lfunc_end4:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table37:
Lexception4:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.asciz	"\201\201\200\200"      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	117                     ## Call site table length
Lset33 = Ltmp133-Lfunc_begin4           ## >> Call Site 1 <<
	.long	Lset33
Lset34 = Ltmp134-Ltmp133                ##   Call between Ltmp133 and Ltmp134
	.long	Lset34
Lset35 = Ltmp135-Lfunc_begin4           ##     jumps to Ltmp135
	.long	Lset35
	.byte	5                       ##   On action: 3
Lset36 = Ltmp136-Lfunc_begin4           ## >> Call Site 2 <<
	.long	Lset36
Lset37 = Ltmp137-Ltmp136                ##   Call between Ltmp136 and Ltmp137
	.long	Lset37
Lset38 = Ltmp147-Lfunc_begin4           ##     jumps to Ltmp147
	.long	Lset38
	.byte	5                       ##   On action: 3
Lset39 = Ltmp138-Lfunc_begin4           ## >> Call Site 3 <<
	.long	Lset39
Lset40 = Ltmp141-Ltmp138                ##   Call between Ltmp138 and Ltmp141
	.long	Lset40
Lset41 = Ltmp142-Lfunc_begin4           ##     jumps to Ltmp142
	.long	Lset41
	.byte	3                       ##   On action: 2
Lset42 = Ltmp143-Lfunc_begin4           ## >> Call Site 4 <<
	.long	Lset42
Lset43 = Ltmp146-Ltmp143                ##   Call between Ltmp143 and Ltmp146
	.long	Lset43
Lset44 = Ltmp147-Lfunc_begin4           ##     jumps to Ltmp147
	.long	Lset44
	.byte	5                       ##   On action: 3
Lset45 = Ltmp146-Lfunc_begin4           ## >> Call Site 5 <<
	.long	Lset45
Lset46 = Ltmp148-Ltmp146                ##   Call between Ltmp146 and Ltmp148
	.long	Lset46
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset47 = Ltmp148-Lfunc_begin4           ## >> Call Site 6 <<
	.long	Lset47
Lset48 = Ltmp149-Ltmp148                ##   Call between Ltmp148 and Ltmp149
	.long	Lset48
Lset49 = Ltmp150-Lfunc_begin4           ##     jumps to Ltmp150
	.long	Lset49
	.byte	0                       ##   On action: cleanup
Lset50 = Ltmp149-Lfunc_begin4           ## >> Call Site 7 <<
	.long	Lset50
Lset51 = Ltmp151-Ltmp149                ##   Call between Ltmp149 and Ltmp151
	.long	Lset51
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset52 = Ltmp151-Lfunc_begin4           ## >> Call Site 8 <<
	.long	Lset52
Lset53 = Ltmp152-Ltmp151                ##   Call between Ltmp151 and Ltmp152
	.long	Lset53
Lset54 = Ltmp153-Lfunc_begin4           ##     jumps to Ltmp153
	.long	Lset54
	.byte	5                       ##   On action: 3
Lset55 = Ltmp152-Lfunc_begin4           ## >> Call Site 9 <<
	.long	Lset55
Lset56 = Lfunc_end4-Ltmp152             ##   Call between Ltmp152 and Lfunc_end4
	.long	Lset56
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.byte	0                       ## >> Action Record 1 <<
                                        ##   Cleanup
	.byte	0                       ##   No further actions
	.byte	1                       ## >> Action Record 2 <<
                                        ##   Catch TypeInfo 1
	.byte	125                     ##   Continue to action 1
	.byte	1                       ## >> Action Record 3 <<
                                        ##   Catch TypeInfo 1
	.byte	0                       ##   No further actions
                                        ## >> Catch TypeInfos <<
	.long	0                       ## TypeInfo 1
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__111char_traitsIcE6lengthEPKc
	.weak_definition	__ZNSt3__111char_traitsIcE6lengthEPKc
	.p2align	4, 0x90
__ZNSt3__111char_traitsIcE6lengthEPKc:  ## @_ZNSt3__111char_traitsIcE6lengthEPKc
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
	movq	-8(%rbp), %rdi
	callq	_strlen
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.private_extern	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
	.globl	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
	.weak_definition	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
	.p2align	4, 0x90
__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_: ## @_ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
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
	subq	$464, %rsp              ## imm = 0x1D0
	movb	%r9b, %al
	movq	%rdi, -312(%rbp)
	movq	%rsi, -320(%rbp)
	movq	%rdx, -328(%rbp)
	movq	%rcx, -336(%rbp)
	movq	%r8, -344(%rbp)
	movb	%al, -345(%rbp)
	cmpq	$0, -312(%rbp)
	jne	LBB39_2
## BB#1:
	movq	-312(%rbp), %rax
	movq	%rax, -304(%rbp)
	jmp	LBB39_26
LBB39_2:
	movq	-336(%rbp), %rax
	movq	-320(%rbp), %rcx
	subq	%rcx, %rax
	movq	%rax, -360(%rbp)
	movq	-344(%rbp), %rax
	movq	%rax, -296(%rbp)
	movq	-296(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -368(%rbp)
	movq	-368(%rbp), %rax
	cmpq	-360(%rbp), %rax
	jle	LBB39_4
## BB#3:
	movq	-360(%rbp), %rax
	movq	-368(%rbp), %rcx
	subq	%rax, %rcx
	movq	%rcx, -368(%rbp)
	jmp	LBB39_5
LBB39_4:
	movq	$0, -368(%rbp)
LBB39_5:
	movq	-328(%rbp), %rax
	movq	-320(%rbp), %rcx
	subq	%rcx, %rax
	movq	%rax, -376(%rbp)
	cmpq	$0, -376(%rbp)
	jle	LBB39_9
## BB#6:
	movq	-312(%rbp), %rax
	movq	-320(%rbp), %rcx
	movq	-376(%rbp), %rdx
	movq	%rax, -224(%rbp)
	movq	%rcx, -232(%rbp)
	movq	%rdx, -240(%rbp)
	movq	-224(%rbp), %rax
	movq	(%rax), %rcx
	movq	96(%rcx), %rcx
	movq	-232(%rbp), %rsi
	movq	-240(%rbp), %rdx
	movq	%rax, %rdi
	callq	*%rcx
	cmpq	-376(%rbp), %rax
	je	LBB39_8
## BB#7:
	movq	$0, -312(%rbp)
	movq	-312(%rbp), %rax
	movq	%rax, -304(%rbp)
	jmp	LBB39_26
LBB39_8:
	jmp	LBB39_9
LBB39_9:
	cmpq	$0, -368(%rbp)
	jle	LBB39_21
## BB#10:
	xorl	%esi, %esi
	movl	$24, %eax
	movl	%eax, %edx
	leaq	-400(%rbp), %rcx
	movq	-368(%rbp), %rdi
	movb	-345(%rbp), %r8b
	movq	%rcx, -200(%rbp)
	movq	%rdi, -208(%rbp)
	movb	%r8b, -209(%rbp)
	movq	-200(%rbp), %rcx
	movq	-208(%rbp), %rdi
	movb	-209(%rbp), %r8b
	movq	%rcx, -176(%rbp)
	movq	%rdi, -184(%rbp)
	movb	%r8b, -185(%rbp)
	movq	-176(%rbp), %rcx
	movq	%rcx, -168(%rbp)
	movq	-168(%rbp), %rdi
	movq	%rdi, -160(%rbp)
	movq	-160(%rbp), %rdi
	movq	%rdi, -152(%rbp)
	movq	-152(%rbp), %rdi
	movq	%rdi, %r9
	movq	%r9, -144(%rbp)
	movq	%rcx, -424(%rbp)        ## 8-byte Spill
	callq	_memset
	movq	-184(%rbp), %rsi
	movq	-424(%rbp), %rdi        ## 8-byte Reload
	movsbl	-185(%rbp), %edx
	callq	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initEmc
	leaq	-400(%rbp), %rcx
	movq	-312(%rbp), %rsi
	movq	%rcx, -136(%rbp)
	movq	-136(%rbp), %rcx
	movq	%rcx, -128(%rbp)
	movq	-128(%rbp), %rcx
	movq	%rcx, -120(%rbp)
	movq	-120(%rbp), %rdi
	movq	%rdi, -112(%rbp)
	movq	-112(%rbp), %rdi
	movq	%rdi, -104(%rbp)
	movq	-104(%rbp), %rdi
	movzbl	(%rdi), %eax
	andl	$1, %eax
	cmpl	$0, %eax
	movq	%rsi, -432(%rbp)        ## 8-byte Spill
	movq	%rcx, -440(%rbp)        ## 8-byte Spill
	je	LBB39_12
## BB#11:
	movq	-440(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rcx
	movq	%rcx, -48(%rbp)
	movq	-48(%rbp), %rcx
	movq	%rcx, -40(%rbp)
	movq	-40(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -448(%rbp)        ## 8-byte Spill
	jmp	LBB39_13
LBB39_12:
	movq	-440(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -96(%rbp)
	movq	-96(%rbp), %rcx
	movq	%rcx, -88(%rbp)
	movq	-88(%rbp), %rcx
	movq	%rcx, -80(%rbp)
	movq	-80(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -72(%rbp)
	movq	-72(%rbp), %rcx
	movq	%rcx, -64(%rbp)
	movq	-64(%rbp), %rcx
	movq	%rcx, -448(%rbp)        ## 8-byte Spill
LBB39_13:
	movq	-448(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	-368(%rbp), %rcx
	movq	-432(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -8(%rbp)
	movq	%rax, -16(%rbp)
	movq	%rcx, -24(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rcx
	movq	96(%rcx), %rcx
	movq	-16(%rbp), %rsi
	movq	-24(%rbp), %rdx
Ltmp154:
	movq	%rax, %rdi
	callq	*%rcx
Ltmp155:
	movq	%rax, -456(%rbp)        ## 8-byte Spill
	jmp	LBB39_14
LBB39_14:
	jmp	LBB39_15
LBB39_15:
	movq	-456(%rbp), %rax        ## 8-byte Reload
	cmpq	-368(%rbp), %rax
	je	LBB39_18
## BB#16:
	movq	$0, -312(%rbp)
	movq	-312(%rbp), %rax
	movq	%rax, -304(%rbp)
	movl	$1, -416(%rbp)
	jmp	LBB39_19
LBB39_17:
Ltmp156:
	leaq	-400(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -408(%rbp)
	movl	%ecx, -412(%rbp)
	callq	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev
	jmp	LBB39_27
LBB39_18:
	movl	$0, -416(%rbp)
LBB39_19:
	leaq	-400(%rbp), %rdi
	callq	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev
	movl	-416(%rbp), %eax
	testl	%eax, %eax
	movl	%eax, -460(%rbp)        ## 4-byte Spill
	je	LBB39_20
	jmp	LBB39_29
LBB39_29:
	movl	-460(%rbp), %eax        ## 4-byte Reload
	subl	$1, %eax
	movl	%eax, -464(%rbp)        ## 4-byte Spill
	je	LBB39_26
	jmp	LBB39_28
LBB39_20:
	jmp	LBB39_21
LBB39_21:
	movq	-336(%rbp), %rax
	movq	-328(%rbp), %rcx
	subq	%rcx, %rax
	movq	%rax, -376(%rbp)
	cmpq	$0, -376(%rbp)
	jle	LBB39_25
## BB#22:
	movq	-312(%rbp), %rax
	movq	-328(%rbp), %rcx
	movq	-376(%rbp), %rdx
	movq	%rax, -248(%rbp)
	movq	%rcx, -256(%rbp)
	movq	%rdx, -264(%rbp)
	movq	-248(%rbp), %rax
	movq	(%rax), %rcx
	movq	96(%rcx), %rcx
	movq	-256(%rbp), %rsi
	movq	-264(%rbp), %rdx
	movq	%rax, %rdi
	callq	*%rcx
	cmpq	-376(%rbp), %rax
	je	LBB39_24
## BB#23:
	movq	$0, -312(%rbp)
	movq	-312(%rbp), %rax
	movq	%rax, -304(%rbp)
	jmp	LBB39_26
LBB39_24:
	jmp	LBB39_25
LBB39_25:
	movq	-344(%rbp), %rax
	movq	%rax, -272(%rbp)
	movq	$0, -280(%rbp)
	movq	-272(%rbp), %rax
	movq	24(%rax), %rcx
	movq	%rcx, -288(%rbp)
	movq	-280(%rbp), %rcx
	movq	%rcx, 24(%rax)
	movq	-312(%rbp), %rax
	movq	%rax, -304(%rbp)
LBB39_26:
	movq	-304(%rbp), %rax
	addq	$464, %rsp              ## imm = 0x1D0
	popq	%rbp
	retq
LBB39_27:
	movq	-408(%rbp), %rdi
	callq	__Unwind_Resume
LBB39_28:
Lfunc_end5:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table39:
Lexception5:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset57 = Lfunc_begin5-Lfunc_begin5      ## >> Call Site 1 <<
	.long	Lset57
Lset58 = Ltmp154-Lfunc_begin5           ##   Call between Lfunc_begin5 and Ltmp154
	.long	Lset58
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset59 = Ltmp154-Lfunc_begin5           ## >> Call Site 2 <<
	.long	Lset59
Lset60 = Ltmp155-Ltmp154                ##   Call between Ltmp154 and Ltmp155
	.long	Lset60
Lset61 = Ltmp156-Lfunc_begin5           ##     jumps to Ltmp156
	.long	Lset61
	.byte	0                       ##   On action: cleanup
Lset62 = Ltmp155-Lfunc_begin5           ## >> Call Site 3 <<
	.long	Lset62
Lset63 = Lfunc_end5-Ltmp155             ##   Call between Ltmp155 and Lfunc_end5
	.long	Lset63
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__111char_traitsIcE11eq_int_typeEii
	.weak_definition	__ZNSt3__111char_traitsIcE11eq_int_typeEii
	.p2align	4, 0x90
__ZNSt3__111char_traitsIcE11eq_int_typeEii: ## @_ZNSt3__111char_traitsIcE11eq_int_typeEii
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
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %esi
	cmpl	-8(%rbp), %esi
	sete	%al
	andb	$1, %al
	movzbl	%al, %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__111char_traitsIcE3eofEv
	.weak_definition	__ZNSt3__111char_traitsIcE3eofEv
	.p2align	4, 0x90
__ZNSt3__111char_traitsIcE3eofEv:       ## @_ZNSt3__111char_traitsIcE3eofEv
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
	movl	$4294967295, %eax       ## imm = 0xFFFFFFFF
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEEC2Em
	.weak_def_can_be_hidden	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEEC2Em
	.p2align	4, 0x90
__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEEC2Em: ## @_ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEEC2Em
Lfunc_begin6:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception6
## BB#0:
	pushq	%rbp
Lcfi123:
	.cfi_def_cfa_offset 16
Lcfi124:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi125:
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rsi
	movq	-16(%rbp), %rdi
	leaq	-24(%rbp), %rdx
	movq	%rdi, -56(%rbp)         ## 8-byte Spill
	movq	%rsi, %rdi
	movq	-56(%rbp), %rax         ## 8-byte Reload
	movq	%rsi, -64(%rbp)         ## 8-byte Spill
	movq	%rax, %rsi
	callq	__ZN3dsa13__vector_baseIiNS_24__default_alloc_templateILb0ELi0EEEEC2EmRKS2_
	movq	-64(%rbp), %rax         ## 8-byte Reload
	movq	(%rax), %rdi
	movq	-16(%rbp), %rsi
	movl	$0, -28(%rbp)
Ltmp157:
	leaq	-28(%rbp), %rdx
	callq	__ZN3dsa20uninitialized_fill_nIPimiEET_S2_T0_RKT1_
Ltmp158:
	movq	%rax, -72(%rbp)         ## 8-byte Spill
	jmp	LBB42_1
LBB42_1:
	movq	-64(%rbp), %rax         ## 8-byte Reload
	movq	-72(%rbp), %rcx         ## 8-byte Reload
	movq	%rcx, 8(%rax)
	addq	$80, %rsp
	popq	%rbp
	retq
LBB42_2:
Ltmp159:
	movl	%edx, %ecx
	movq	%rax, -40(%rbp)
	movl	%ecx, -44(%rbp)
	movq	-64(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	__ZN3dsa13__vector_baseIiNS_24__default_alloc_templateILb0ELi0EEEED2Ev
## BB#3:
	movq	-40(%rbp), %rdi
	callq	__Unwind_Resume
Lfunc_end6:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table42:
Lexception6:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset64 = Lfunc_begin6-Lfunc_begin6      ## >> Call Site 1 <<
	.long	Lset64
Lset65 = Ltmp157-Lfunc_begin6           ##   Call between Lfunc_begin6 and Ltmp157
	.long	Lset65
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset66 = Ltmp157-Lfunc_begin6           ## >> Call Site 2 <<
	.long	Lset66
Lset67 = Ltmp158-Ltmp157                ##   Call between Ltmp157 and Ltmp158
	.long	Lset67
Lset68 = Ltmp159-Lfunc_begin6           ##     jumps to Ltmp159
	.long	Lset68
	.byte	0                       ##   On action: cleanup
Lset69 = Ltmp158-Lfunc_begin6           ## >> Call Site 3 <<
	.long	Lset69
Lset70 = Lfunc_end6-Ltmp158             ##   Call between Ltmp158 and Lfunc_end6
	.long	Lset70
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN3dsa13__vector_baseIiNS_24__default_alloc_templateILb0ELi0EEEEC2EmRKS2_
	.weak_def_can_be_hidden	__ZN3dsa13__vector_baseIiNS_24__default_alloc_templateILb0ELi0EEEEC2EmRKS2_
	.p2align	4, 0x90
__ZN3dsa13__vector_baseIiNS_24__default_alloc_templateILb0ELi0EEEEC2EmRKS2_: ## @_ZN3dsa13__vector_baseIiNS_24__default_alloc_templateILb0ELi0EEEEC2EmRKS2_
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
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rdx
	movq	$0, (%rdx)
	movq	$0, 8(%rdx)
	movq	$0, 16(%rdx)
	movq	-16(%rbp), %rsi
	movq	%rdx, %rdi
	movq	%rdx, -32(%rbp)         ## 8-byte Spill
	callq	__ZN3dsa13__vector_baseIiNS_24__default_alloc_templateILb0ELi0EEEE12__m_allocateEm
	movq	-32(%rbp), %rdx         ## 8-byte Reload
	movq	%rax, (%rdx)
	movq	(%rdx), %rax
	movq	%rax, 8(%rdx)
	movq	(%rdx), %rax
	movq	-16(%rbp), %rsi
	shlq	$2, %rsi
	addq	%rsi, %rax
	movq	%rax, 16(%rdx)
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa20uninitialized_fill_nIPimiEET_S2_T0_RKT1_
	.weak_definition	__ZN3dsa20uninitialized_fill_nIPimiEET_S2_T0_RKT1_
	.p2align	4, 0x90
__ZN3dsa20uninitialized_fill_nIPimiEET_S2_T0_RKT1_: ## @_ZN3dsa20uninitialized_fill_nIPimiEET_S2_T0_RKT1_
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
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	movq	-24(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdi, -32(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rdx, -40(%rbp)         ## 8-byte Spill
	movq	%rsi, -48(%rbp)         ## 8-byte Spill
	callq	__ZN3dsa10value_typeIiEEPT_PKS1_
	movq	-32(%rbp), %rdi         ## 8-byte Reload
	movq	-48(%rbp), %rsi         ## 8-byte Reload
	movq	-40(%rbp), %rdx         ## 8-byte Reload
	movq	%rax, %rcx
	callq	__ZN3dsa22__uninitialized_fill_nIPimiiEET_S2_T0_RKT1_PT2_
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa13__vector_baseIiNS_24__default_alloc_templateILb0ELi0EEEED2Ev
	.weak_def_can_be_hidden	__ZN3dsa13__vector_baseIiNS_24__default_alloc_templateILb0ELi0EEEED2Ev
	.p2align	4, 0x90
__ZN3dsa13__vector_baseIiNS_24__default_alloc_templateILb0ELi0EEEED2Ev: ## @_ZN3dsa13__vector_baseIiNS_24__default_alloc_templateILb0ELi0EEEED2Ev
Lfunc_begin7:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception7
## BB#0:
	pushq	%rbp
Lcfi132:
	.cfi_def_cfa_offset 16
Lcfi133:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi134:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	(%rdi), %rax
	movq	16(%rdi), %rcx
	subq	%rax, %rcx
	sarq	$2, %rcx
Ltmp160:
	movq	%rax, %rsi
	movq	%rcx, %rdx
	callq	__ZN3dsa13__vector_baseIiNS_24__default_alloc_templateILb0ELi0EEEE14__m_deallocateEPim
Ltmp161:
	jmp	LBB45_1
LBB45_1:
	addq	$16, %rsp
	popq	%rbp
	retq
LBB45_2:
Ltmp162:
	movl	%edx, %ecx
	movq	%rax, %rdi
	movl	%ecx, -12(%rbp)         ## 4-byte Spill
	callq	___clang_call_terminate
Lfunc_end7:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table45:
Lexception7:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	21                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	13                      ## Call site table length
Lset71 = Ltmp160-Lfunc_begin7           ## >> Call Site 1 <<
	.long	Lset71
Lset72 = Ltmp161-Ltmp160                ##   Call between Ltmp160 and Ltmp161
	.long	Lset72
Lset73 = Ltmp162-Lfunc_begin7           ##     jumps to Ltmp162
	.long	Lset73
	.byte	1                       ##   On action: 1
	.byte	1                       ## >> Action Record 1 <<
                                        ##   Catch TypeInfo 1
	.byte	0                       ##   No further actions
                                        ## >> Catch TypeInfos <<
	.long	0                       ## TypeInfo 1
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN3dsa13__vector_baseIiNS_24__default_alloc_templateILb0ELi0EEEE12__m_allocateEm
	.weak_definition	__ZN3dsa13__vector_baseIiNS_24__default_alloc_templateILb0ELi0EEEE12__m_allocateEm
	.p2align	4, 0x90
__ZN3dsa13__vector_baseIiNS_24__default_alloc_templateILb0ELi0EEEE12__m_allocateEm: ## @_ZN3dsa13__vector_baseIiNS_24__default_alloc_templateILb0ELi0EEEE12__m_allocateEm
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi135:
	.cfi_def_cfa_offset 16
Lcfi136:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi137:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdi
	callq	__ZN3dsa12simple_allocIiNS_24__default_alloc_templateILb0ELi0EEEE8allocateEm
	addq	$16, %rsp
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
Lcfi138:
	.cfi_def_cfa_offset 16
Lcfi139:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi140:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rdi, -8(%rbp)
	cmpq	-8(%rbp), %rcx
	jne	LBB47_2
## BB#1:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rcx, -16(%rbp)         ## 8-byte Spill
	jmp	LBB47_3
LBB47_2:
	movq	-8(%rbp), %rax
	shlq	$2, %rax
	movq	%rax, %rdi
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE8allocateEm
	movq	%rax, -16(%rbp)         ## 8-byte Spill
LBB47_3:
	movq	-16(%rbp), %rax         ## 8-byte Reload
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa24__default_alloc_templateILb0ELi0EE8allocateEm
	.weak_definition	__ZN3dsa24__default_alloc_templateILb0ELi0EE8allocateEm
	.p2align	4, 0x90
__ZN3dsa24__default_alloc_templateILb0ELi0EE8allocateEm: ## @_ZN3dsa24__default_alloc_templateILb0ELi0EE8allocateEm
Lfunc_begin8:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception8
## BB#0:
	pushq	%rbp
Lcfi141:
	.cfi_def_cfa_offset 16
Lcfi142:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi143:
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movq	%rdi, -8(%rbp)
	movq	$0, -16(%rbp)
	cmpq	$128, -8(%rbp)
	jbe	LBB48_2
## BB#1:
	movq	-8(%rbp), %rdi
	callq	__ZN3dsa23__malloc_alloc_templateILi0EE8allocateEm
	movq	%rax, -16(%rbp)
	jmp	LBB48_9
LBB48_2:
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
	jne	LBB48_7
## BB#3:
	movq	-8(%rbp), %rdi
Ltmp163:
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE11_S_round_upEm
Ltmp164:
	movq	%rax, -64(%rbp)         ## 8-byte Spill
	jmp	LBB48_4
LBB48_4:
Ltmp165:
	movq	-64(%rbp), %rdi         ## 8-byte Reload
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE9_S_refillEm
Ltmp166:
	movq	%rax, -72(%rbp)         ## 8-byte Spill
	jmp	LBB48_5
LBB48_5:
	movq	-72(%rbp), %rax         ## 8-byte Reload
	movq	%rax, -16(%rbp)
	jmp	LBB48_8
LBB48_6:
Ltmp167:
	leaq	-32(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -48(%rbp)
	movl	%ecx, -52(%rbp)
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockD1Ev
	jmp	LBB48_10
LBB48_7:
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	-24(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-40(%rbp), %rax
	movq	%rax, -16(%rbp)
LBB48_8:
	leaq	-32(%rbp), %rdi
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockD1Ev
LBB48_9:
	movq	-16(%rbp), %rax
	addq	$80, %rsp
	popq	%rbp
	retq
LBB48_10:
	movq	-48(%rbp), %rdi
	callq	__Unwind_Resume
Lfunc_end8:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table48:
Lexception8:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset74 = Lfunc_begin8-Lfunc_begin8      ## >> Call Site 1 <<
	.long	Lset74
Lset75 = Ltmp163-Lfunc_begin8           ##   Call between Lfunc_begin8 and Ltmp163
	.long	Lset75
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset76 = Ltmp163-Lfunc_begin8           ## >> Call Site 2 <<
	.long	Lset76
Lset77 = Ltmp166-Ltmp163                ##   Call between Ltmp163 and Ltmp166
	.long	Lset77
Lset78 = Ltmp167-Lfunc_begin8           ##     jumps to Ltmp167
	.long	Lset78
	.byte	0                       ##   On action: cleanup
Lset79 = Ltmp166-Lfunc_begin8           ## >> Call Site 3 <<
	.long	Lset79
Lset80 = Lfunc_end8-Ltmp166             ##   Call between Ltmp166 and Lfunc_end8
	.long	Lset80
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
Lcfi144:
	.cfi_def_cfa_offset 16
Lcfi145:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi146:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	_malloc
	xorl	%ecx, %ecx
	movl	%ecx, %edi
	movq	%rax, -16(%rbp)
	cmpq	-16(%rbp), %rdi
	jne	LBB49_2
## BB#1:
	movq	-8(%rbp), %rdi
	callq	__ZN3dsa23__malloc_alloc_templateILi0EE13_S_oom_mallocEm
	movq	%rax, -16(%rbp)
LBB49_2:
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
Lcfi147:
	.cfi_def_cfa_offset 16
Lcfi148:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi149:
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
Lcfi150:
	.cfi_def_cfa_offset 16
Lcfi151:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi152:
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
Lcfi153:
	.cfi_def_cfa_offset 16
Lcfi154:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi155:
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
	jne	LBB52_2
## BB#1:
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	LBB52_9
LBB52_2:
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
LBB52_3:                                ## =>This Inner Loop Header: Depth=1
	movq	-64(%rbp), %rax
	movq	%rax, -56(%rbp)
	movq	-64(%rbp), %rax
	addq	-16(%rbp), %rax
	movq	%rax, -64(%rbp)
	movl	-20(%rbp), %ecx
	cmpl	-68(%rbp), %ecx
	jne	LBB52_5
## BB#4:
	movq	-56(%rbp), %rax
	movq	$0, (%rax)
	jmp	LBB52_8
LBB52_5:                                ##   in Loop: Header=BB52_3 Depth=1
	movq	-64(%rbp), %rax
	movq	-56(%rbp), %rcx
	movq	%rax, (%rcx)
## BB#6:                                ##   in Loop: Header=BB52_3 Depth=1
	jmp	LBB52_7
LBB52_7:                                ##   in Loop: Header=BB52_3 Depth=1
	movl	-68(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -68(%rbp)
	jmp	LBB52_3
LBB52_8:
	movq	-48(%rbp), %rax
	movq	%rax, -8(%rbp)
LBB52_9:
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
Lcfi156:
	.cfi_def_cfa_offset 16
Lcfi157:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi158:
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
Lcfi159:
	.cfi_def_cfa_offset 16
Lcfi160:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi161:
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
Lcfi162:
	.cfi_def_cfa_offset 16
Lcfi163:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi164:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
LBB55_1:                                ## =>This Inner Loop Header: Depth=1
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	__ZN3dsa23__malloc_alloc_templateILi0EE26__malloc_alloc_oom_handlerE@GOTPCREL(%rip), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, -16(%rbp)
	cmpq	-16(%rbp), %rcx
	jne	LBB55_3
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
LBB55_3:                                ##   in Loop: Header=BB55_1 Depth=1
	callq	*-16(%rbp)
	movq	-8(%rbp), %rdi
	callq	_malloc
	movq	%rax, -24(%rbp)
	cmpq	$0, -24(%rbp)
	je	LBB55_5
## BB#4:
	movq	-24(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	retq
LBB55_5:                                ##   in Loop: Header=BB55_1 Depth=1
	jmp	LBB55_1
	.cfi_endproc

	.globl	__ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockC2Ev
	.weak_def_can_be_hidden	__ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockC2Ev
	.p2align	4, 0x90
__ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockC2Ev: ## @_ZN3dsa24__default_alloc_templateILb0ELi0EE5_LockC2Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi165:
	.cfi_def_cfa_offset 16
Lcfi166:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi167:
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
Lcfi168:
	.cfi_def_cfa_offset 16
Lcfi169:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi170:
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
	ja	LBB57_2
## BB#1:
	movq	__ZN3dsa24__default_alloc_templateILb0ELi0EE13_S_start_freeE@GOTPCREL(%rip), %rax
	movq	(%rax), %rcx
	movq	%rcx, -32(%rbp)
	movq	-40(%rbp), %rcx
	addq	(%rax), %rcx
	movq	%rcx, (%rax)
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	LBB57_16
LBB57_2:
	movq	-16(%rbp), %rax
	cmpq	-48(%rbp), %rax
	ja	LBB57_4
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
	jmp	LBB57_16
LBB57_4:
	jmp	LBB57_5
LBB57_5:
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
	jbe	LBB57_7
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
LBB57_7:
	movq	-56(%rbp), %rdi
	callq	_malloc
	xorl	%ecx, %ecx
	movl	%ecx, %edi
	movq	__ZN3dsa24__default_alloc_templateILb0ELi0EE13_S_start_freeE@GOTPCREL(%rip), %rdx
	movq	%rax, (%rdx)
	cmpq	(%rdx), %rdi
	jne	LBB57_15
## BB#8:
	movq	-16(%rbp), %rax
	movq	%rax, -72(%rbp)
LBB57_9:                                ## =>This Inner Loop Header: Depth=1
	cmpq	$128, -72(%rbp)
	ja	LBB57_14
## BB#10:                               ##   in Loop: Header=BB57_9 Depth=1
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
	je	LBB57_12
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
	jmp	LBB57_16
LBB57_12:                               ##   in Loop: Header=BB57_9 Depth=1
	jmp	LBB57_13
LBB57_13:                               ##   in Loop: Header=BB57_9 Depth=1
	movq	-72(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -72(%rbp)
	jmp	LBB57_9
LBB57_14:
	movq	__ZN3dsa24__default_alloc_templateILb0ELi0EE11_S_end_freeE@GOTPCREL(%rip), %rax
	movq	$0, (%rax)
	movq	-56(%rbp), %rdi
	callq	__ZN3dsa23__malloc_alloc_templateILi0EE8allocateEm
	movq	__ZN3dsa24__default_alloc_templateILb0ELi0EE13_S_start_freeE@GOTPCREL(%rip), %rdi
	movq	%rax, (%rdi)
LBB57_15:
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
LBB57_16:
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
Lcfi171:
	.cfi_def_cfa_offset 16
Lcfi172:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi173:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa22__uninitialized_fill_nIPimiiEET_S2_T0_RKT1_PT2_
	.weak_definition	__ZN3dsa22__uninitialized_fill_nIPimiiEET_S2_T0_RKT1_PT2_
	.p2align	4, 0x90
__ZN3dsa22__uninitialized_fill_nIPimiiEET_S2_T0_RKT1_PT2_: ## @_ZN3dsa22__uninitialized_fill_nIPimiiEET_S2_T0_RKT1_PT2_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi174:
	.cfi_def_cfa_offset 16
Lcfi175:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi176:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rcx, -32(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	movq	-24(%rbp), %rdx
	callq	__ZN3dsa26__uninitialized_fill_n_auxIPimiEET_S2_T0_RKT1_11__true_type
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa10value_typeIiEEPT_PKS1_
	.weak_definition	__ZN3dsa10value_typeIiEEPT_PKS1_
	.p2align	4, 0x90
__ZN3dsa10value_typeIiEEPT_PKS1_:       ## @_ZN3dsa10value_typeIiEEPT_PKS1_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi177:
	.cfi_def_cfa_offset 16
Lcfi178:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi179:
	.cfi_def_cfa_register %rbp
	xorl	%eax, %eax
                                        ## kill: %RAX<def> %EAX<kill>
	movq	%rdi, -8(%rbp)
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa26__uninitialized_fill_n_auxIPimiEET_S2_T0_RKT1_11__true_type
	.weak_definition	__ZN3dsa26__uninitialized_fill_n_auxIPimiEET_S2_T0_RKT1_11__true_type
	.p2align	4, 0x90
__ZN3dsa26__uninitialized_fill_n_auxIPimiEET_S2_T0_RKT1_11__true_type: ## @_ZN3dsa26__uninitialized_fill_n_auxIPimiEET_S2_T0_RKT1_11__true_type
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi180:
	.cfi_def_cfa_offset 16
Lcfi181:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi182:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	movq	-16(%rbp), %rdi
	movq	-24(%rbp), %rsi
	movq	-32(%rbp), %rdx
	callq	__ZN3dsa6fill_nIPimiEET_S2_T0_RKT1_
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa6fill_nIPimiEET_S2_T0_RKT1_
	.weak_definition	__ZN3dsa6fill_nIPimiEET_S2_T0_RKT1_
	.p2align	4, 0x90
__ZN3dsa6fill_nIPimiEET_S2_T0_RKT1_:    ## @_ZN3dsa6fill_nIPimiEET_S2_T0_RKT1_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi183:
	.cfi_def_cfa_offset 16
Lcfi184:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi185:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
## BB#1:
	jmp	LBB62_2
LBB62_2:
	jmp	LBB62_3
LBB62_3:                                ## =>This Inner Loop Header: Depth=1
	cmpq	$0, -16(%rbp)
	jbe	LBB62_6
## BB#4:                                ##   in Loop: Header=BB62_3 Depth=1
	movq	-24(%rbp), %rax
	movl	(%rax), %ecx
	movq	-8(%rbp), %rax
	movl	%ecx, (%rax)
## BB#5:                                ##   in Loop: Header=BB62_3 Depth=1
	movq	-16(%rbp), %rax
	addq	$-1, %rax
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rax
	addq	$4, %rax
	movq	%rax, -8(%rbp)
	jmp	LBB62_3
LBB62_6:
	movq	-8(%rbp), %rax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa13__vector_baseIiNS_24__default_alloc_templateILb0ELi0EEEE14__m_deallocateEPim
	.weak_definition	__ZN3dsa13__vector_baseIiNS_24__default_alloc_templateILb0ELi0EEEE14__m_deallocateEPim
	.p2align	4, 0x90
__ZN3dsa13__vector_baseIiNS_24__default_alloc_templateILb0ELi0EEEE14__m_deallocateEPim: ## @_ZN3dsa13__vector_baseIiNS_24__default_alloc_templateILb0ELi0EEEE14__m_deallocateEPim
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi186:
	.cfi_def_cfa_offset 16
Lcfi187:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi188:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rdi
	movq	-24(%rbp), %rsi
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
Lcfi189:
	.cfi_def_cfa_offset 16
Lcfi190:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi191:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	-16(%rbp), %rcx
	je	LBB64_2
## BB#1:
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rcx
	shlq	$2, %rcx
	movq	%rax, %rdi
	movq	%rcx, %rsi
	callq	__ZN3dsa24__default_alloc_templateILb0ELi0EE10deallocateEPvm
LBB64_2:
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
Lcfi192:
	.cfi_def_cfa_offset 16
Lcfi193:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi194:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	$128, -16(%rbp)
	jbe	LBB65_2
## BB#1:
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	callq	__ZN3dsa23__malloc_alloc_templateILi0EE10deallocateEPvm
	jmp	LBB65_3
LBB65_2:
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
LBB65_3:
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
Lcfi195:
	.cfi_def_cfa_offset 16
Lcfi196:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi197:
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

	.globl	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEED2Ev
	.weak_def_can_be_hidden	__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEED2Ev
	.p2align	4, 0x90
__ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEED2Ev: ## @_ZN3dsa6vectorIiNS_24__default_alloc_templateILb0ELi0EEEED2Ev
Lfunc_begin9:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception9
## BB#0:
	pushq	%rbp
Lcfi198:
	.cfi_def_cfa_offset 16
Lcfi199:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi200:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	(%rdi), %rax
	movq	8(%rdi), %rsi
Ltmp168:
	movq	%rdi, -32(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	callq	__ZN3dsa7destroyIPiEEvT_S2_
Ltmp169:
	jmp	LBB67_1
LBB67_1:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	__ZN3dsa13__vector_baseIiNS_24__default_alloc_templateILb0ELi0EEEED2Ev
	addq	$32, %rsp
	popq	%rbp
	retq
LBB67_2:
Ltmp170:
	movl	%edx, %ecx
	movq	%rax, -16(%rbp)
	movl	%ecx, -20(%rbp)
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	__ZN3dsa13__vector_baseIiNS_24__default_alloc_templateILb0ELi0EEEED2Ev
## BB#3:
	movq	-16(%rbp), %rdi
	callq	___clang_call_terminate
Lfunc_end9:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table67:
Lexception9:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	21                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	13                      ## Call site table length
Lset81 = Ltmp168-Lfunc_begin9           ## >> Call Site 1 <<
	.long	Lset81
Lset82 = Ltmp169-Ltmp168                ##   Call between Ltmp168 and Ltmp169
	.long	Lset82
Lset83 = Ltmp170-Lfunc_begin9           ##     jumps to Ltmp170
	.long	Lset83
	.byte	1                       ##   On action: 1
	.byte	1                       ## >> Action Record 1 <<
                                        ##   Catch TypeInfo 1
	.byte	0                       ##   No further actions
                                        ## >> Catch TypeInfos <<
	.long	0                       ## TypeInfo 1
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN3dsa7destroyIPiEEvT_S2_
	.weak_definition	__ZN3dsa7destroyIPiEEvT_S2_
	.p2align	4, 0x90
__ZN3dsa7destroyIPiEEvT_S2_:            ## @_ZN3dsa7destroyIPiEEvT_S2_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi201:
	.cfi_def_cfa_offset 16
Lcfi202:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi203:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	callq	__ZN3dsa9__destroyEPiS0_
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa9__destroyEPiS0_
	.weak_definition	__ZN3dsa9__destroyEPiS0_
	.p2align	4, 0x90
__ZN3dsa9__destroyEPiS0_:               ## @_ZN3dsa9__destroyEPiS0_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi204:
	.cfi_def_cfa_offset 16
Lcfi205:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi206:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__124uniform_int_distributionIlEC1Ell
	.weak_def_can_be_hidden	__ZNSt3__124uniform_int_distributionIlEC1Ell
	.p2align	4, 0x90
__ZNSt3__124uniform_int_distributionIlEC1Ell: ## @_ZNSt3__124uniform_int_distributionIlEC1Ell
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi207:
	.cfi_def_cfa_offset 16
Lcfi208:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi209:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	movq	-24(%rbp), %rdx
	callq	__ZNSt3__124uniform_int_distributionIlEC2Ell
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__124uniform_int_distributionIlEclINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEEElRT_RKNS1_10param_typeE
	.weak_definition	__ZNSt3__124uniform_int_distributionIlEclINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEEElRT_RKNS1_10param_typeE
	.p2align	4, 0x90
__ZNSt3__124uniform_int_distributionIlEclINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEEElRT_RKNS1_10param_typeE: ## @_ZNSt3__124uniform_int_distributionIlEclINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEEElRT_RKNS1_10param_typeE
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi210:
	.cfi_def_cfa_offset 16
Lcfi211:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi212:
	.cfi_def_cfa_register %rbp
	subq	$224, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-40(%rbp), %rdi
	callq	__ZNKSt3__124uniform_int_distributionIlE10param_type1bEv
	movq	-40(%rbp), %rdi
	movq	%rax, -208(%rbp)        ## 8-byte Spill
	callq	__ZNKSt3__124uniform_int_distributionIlE10param_type1aEv
	movq	-208(%rbp), %rdx        ## 8-byte Reload
	subq	%rax, %rdx
	addq	$1, %rdx
	movq	%rdx, -48(%rbp)
	cmpq	$1, -48(%rbp)
	jne	LBB71_2
## BB#1:
	movq	-40(%rbp), %rdi
	callq	__ZNKSt3__124uniform_int_distributionIlE10param_type1aEv
	movq	%rax, -16(%rbp)
	jmp	LBB71_10
LBB71_2:
	movq	$64, -56(%rbp)
	cmpq	$0, -48(%rbp)
	jne	LBB71_4
## BB#3:
	leaq	-120(%rbp), %rdi
	movl	$64, %eax
	movl	%eax, %edx
	movq	-32(%rbp), %rsi
	callq	__ZNSt3__125__independent_bits_engineINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEyEC1ERS2_m
	leaq	-120(%rbp), %rdi
	callq	__ZNSt3__125__independent_bits_engineINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEyEclEv
	movq	%rax, -16(%rbp)
	jmp	LBB71_10
LBB71_4:
	movq	$-1, %rax
	movl	$64, %ecx
	movl	%ecx, %edx
	movq	-48(%rbp), %rsi
	movq	%rsi, -8(%rbp)
	movq	-8(%rbp), %rsi
	bsrq	%rsi, %rsi
	xorq	$63, %rsi
	movl	%esi, %ecx
	movslq	%ecx, %rsi
	movq	%rdx, %rdi
	subq	%rsi, %rdi
	subq	$1, %rdi
	movq	%rdi, -128(%rbp)
	movq	-48(%rbp), %rsi
	subq	-128(%rbp), %rdx
	movq	%rdx, %rcx
                                        ## kill: %CL<def> %RCX<kill>
	shrq	%cl, %rax
	andq	%rax, %rsi
	cmpq	$0, %rsi
	je	LBB71_6
## BB#5:
	movq	-128(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -128(%rbp)
LBB71_6:
	leaq	-192(%rbp), %rdi
	movq	-32(%rbp), %rsi
	movq	-128(%rbp), %rdx
	callq	__ZNSt3__125__independent_bits_engineINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEyEC1ERS2_m
LBB71_7:                                ## =>This Inner Loop Header: Depth=1
	leaq	-192(%rbp), %rdi
	callq	__ZNSt3__125__independent_bits_engineINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEyEclEv
	movq	%rax, -200(%rbp)
## BB#8:                                ##   in Loop: Header=BB71_7 Depth=1
	movq	-200(%rbp), %rax
	cmpq	-48(%rbp), %rax
	jae	LBB71_7
## BB#9:
	movq	-200(%rbp), %rax
	movq	-40(%rbp), %rdi
	movq	%rax, -216(%rbp)        ## 8-byte Spill
	callq	__ZNKSt3__124uniform_int_distributionIlE10param_type1aEv
	movq	-216(%rbp), %rdi        ## 8-byte Reload
	addq	%rax, %rdi
	movq	%rdi, -16(%rbp)
LBB71_10:
	movq	-16(%rbp), %rax
	addq	$224, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__124uniform_int_distributionIlE10param_typeC1Ell
	.weak_def_can_be_hidden	__ZNSt3__124uniform_int_distributionIlE10param_typeC1Ell
	.p2align	4, 0x90
__ZNSt3__124uniform_int_distributionIlE10param_typeC1Ell: ## @_ZNSt3__124uniform_int_distributionIlE10param_typeC1Ell
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi213:
	.cfi_def_cfa_offset 16
Lcfi214:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi215:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	movq	-24(%rbp), %rdx
	callq	__ZNSt3__124uniform_int_distributionIlE10param_typeC2Ell
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__124uniform_int_distributionIlEC2Ell
	.weak_def_can_be_hidden	__ZNSt3__124uniform_int_distributionIlEC2Ell
	.p2align	4, 0x90
__ZNSt3__124uniform_int_distributionIlEC2Ell: ## @_ZNSt3__124uniform_int_distributionIlEC2Ell
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi216:
	.cfi_def_cfa_offset 16
Lcfi217:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi218:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	movq	-24(%rbp), %rdx
	callq	__ZNSt3__124uniform_int_distributionIlE10param_typeC1Ell
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNKSt3__124uniform_int_distributionIlE10param_type1bEv
	.weak_definition	__ZNKSt3__124uniform_int_distributionIlE10param_type1bEv
	.p2align	4, 0x90
__ZNKSt3__124uniform_int_distributionIlE10param_type1bEv: ## @_ZNKSt3__124uniform_int_distributionIlE10param_type1bEv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi219:
	.cfi_def_cfa_offset 16
Lcfi220:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi221:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	8(%rdi), %rax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNKSt3__124uniform_int_distributionIlE10param_type1aEv
	.weak_definition	__ZNKSt3__124uniform_int_distributionIlE10param_type1aEv
	.p2align	4, 0x90
__ZNKSt3__124uniform_int_distributionIlE10param_type1aEv: ## @_ZNKSt3__124uniform_int_distributionIlE10param_type1aEv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi222:
	.cfi_def_cfa_offset 16
Lcfi223:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi224:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	(%rdi), %rax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__125__independent_bits_engineINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEyEC1ERS2_m
	.weak_def_can_be_hidden	__ZNSt3__125__independent_bits_engineINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEyEC1ERS2_m
	.p2align	4, 0x90
__ZNSt3__125__independent_bits_engineINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEyEC1ERS2_m: ## @_ZNSt3__125__independent_bits_engineINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEyEC1ERS2_m
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi225:
	.cfi_def_cfa_offset 16
Lcfi226:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi227:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	movq	-24(%rbp), %rdx
	callq	__ZNSt3__125__independent_bits_engineINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEyEC2ERS2_m
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__125__independent_bits_engineINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEyEclEv
	.weak_definition	__ZNSt3__125__independent_bits_engineINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEyEclEv
	.p2align	4, 0x90
__ZNSt3__125__independent_bits_engineINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEyEclEv: ## @_ZNSt3__125__independent_bits_engineINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEyEclEv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi228:
	.cfi_def_cfa_offset 16
Lcfi229:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi230:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZNSt3__125__independent_bits_engineINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEyE6__evalENS_17integral_constantIbLb1EEE
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__125__independent_bits_engineINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEyEC2ERS2_m
	.weak_def_can_be_hidden	__ZNSt3__125__independent_bits_engineINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEyEC2ERS2_m
	.p2align	4, 0x90
__ZNSt3__125__independent_bits_engineINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEyEC2ERS2_m: ## @_ZNSt3__125__independent_bits_engineINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEyEC2ERS2_m
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi231:
	.cfi_def_cfa_offset 16
Lcfi232:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi233:
	.cfi_def_cfa_register %rbp
	movl	$30, %eax
	movl	%eax, %ecx
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rdx
	movq	-16(%rbp), %rsi
	movq	%rsi, (%rdx)
	movq	-24(%rbp), %rsi
	movq	%rsi, 8(%rdx)
	movq	8(%rdx), %rax
	xorl	%r8d, %r8d
	movq	%rdx, -32(%rbp)         ## 8-byte Spill
	movl	%r8d, %edx
	divq	%rcx
	movq	-32(%rbp), %rsi         ## 8-byte Reload
	movq	8(%rsi), %rdi
	movq	%rax, -40(%rbp)         ## 8-byte Spill
	movq	%rdi, %rax
	xorl	%r8d, %r8d
	movl	%r8d, %edx
	divq	%rcx
	cmpq	$0, %rdx
	setne	%r9b
	andb	$1, %r9b
	movzbl	%r9b, %r8d
	movl	%r8d, %ecx
	movq	-40(%rbp), %rdx         ## 8-byte Reload
	addq	%rcx, %rdx
	movq	%rdx, 24(%rsi)
	movq	8(%rsi), %rcx
	movq	%rcx, %rax
	xorl	%r8d, %r8d
	movl	%r8d, %edx
	divq	24(%rsi)
	movq	%rax, 16(%rsi)
	cmpq	$64, 16(%rsi)
	jae	LBB78_2
## BB#1:
	movl	$2147483646, %eax       ## imm = 0x7FFFFFFE
	movl	%eax, %ecx
	movq	-32(%rbp), %rdx         ## 8-byte Reload
	movq	16(%rdx), %rsi
	movq	%rcx, -48(%rbp)         ## 8-byte Spill
	movq	%rsi, %rcx
                                        ## kill: %CL<def> %RCX<kill>
	movq	-48(%rbp), %rsi         ## 8-byte Reload
	shrq	%cl, %rsi
	movq	16(%rdx), %rcx
                                        ## kill: %CL<def> %RCX<kill>
	shlq	%cl, %rsi
	movq	%rsi, 40(%rdx)
	jmp	LBB78_3
LBB78_2:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	$0, 40(%rax)
LBB78_3:
	movl	$2147483646, %eax       ## imm = 0x7FFFFFFE
	movl	%eax, %ecx
	movq	-32(%rbp), %rdx         ## 8-byte Reload
	subq	40(%rdx), %rcx
	movq	40(%rdx), %rax
	xorl	%esi, %esi
	movl	%esi, %edx
	movq	-32(%rbp), %rdi         ## 8-byte Reload
	divq	24(%rdi)
	cmpq	%rax, %rcx
	jbe	LBB78_8
## BB#4:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	24(%rax), %rcx
	addq	$1, %rcx
	movq	%rcx, 24(%rax)
	movq	8(%rax), %rax
	xorl	%edx, %edx
                                        ## kill: %RDX<def> %EDX<kill>
	movq	-32(%rbp), %rcx         ## 8-byte Reload
	divq	24(%rcx)
	movq	%rax, 16(%rcx)
	cmpq	$64, 16(%rcx)
	jae	LBB78_6
## BB#5:
	movl	$2147483646, %eax       ## imm = 0x7FFFFFFE
	movl	%eax, %ecx
	movq	-32(%rbp), %rdx         ## 8-byte Reload
	movq	16(%rdx), %rsi
	movq	%rcx, -56(%rbp)         ## 8-byte Spill
	movq	%rsi, %rcx
                                        ## kill: %CL<def> %RCX<kill>
	movq	-56(%rbp), %rsi         ## 8-byte Reload
	shrq	%cl, %rsi
	movq	16(%rdx), %rcx
                                        ## kill: %CL<def> %RCX<kill>
	shlq	%cl, %rsi
	movq	%rsi, 40(%rdx)
	jmp	LBB78_7
LBB78_6:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	$0, 40(%rax)
LBB78_7:
	jmp	LBB78_8
LBB78_8:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	24(%rax), %rcx
	movq	8(%rax), %rax
	xorl	%edx, %edx
                                        ## kill: %RDX<def> %EDX<kill>
	movq	-32(%rbp), %rsi         ## 8-byte Reload
	divq	24(%rsi)
	subq	%rdx, %rcx
	movq	%rcx, 32(%rsi)
	cmpq	$63, 16(%rsi)
	jae	LBB78_10
## BB#9:
	movl	$2147483646, %eax       ## imm = 0x7FFFFFFE
	movl	%eax, %ecx
	movq	-32(%rbp), %rdx         ## 8-byte Reload
	movq	16(%rdx), %rsi
	addq	$1, %rsi
	movq	%rcx, -64(%rbp)         ## 8-byte Spill
	movq	%rsi, %rcx
                                        ## kill: %CL<def> %RCX<kill>
	movq	-64(%rbp), %rsi         ## 8-byte Reload
	shrq	%cl, %rsi
	movq	16(%rdx), %rdi
	addq	$1, %rdi
	movq	%rdi, %rcx
                                        ## kill: %CL<def> %RCX<kill>
	shlq	%cl, %rsi
	movq	%rsi, 48(%rdx)
	jmp	LBB78_11
LBB78_10:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	$0, 48(%rax)
LBB78_11:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	cmpq	$0, 16(%rax)
	jbe	LBB78_13
## BB#12:
	movl	$4294967295, %eax       ## imm = 0xFFFFFFFF
	movl	$32, %ecx
	movl	%ecx, %edx
	movq	-32(%rbp), %rsi         ## 8-byte Reload
	subq	16(%rsi), %rdx
	movl	%edx, %ecx
                                        ## kill: %CL<def> %ECX<kill>
	shrl	%cl, %eax
	movl	%eax, -68(%rbp)         ## 4-byte Spill
	jmp	LBB78_14
LBB78_13:
	xorl	%eax, %eax
	movl	%eax, -68(%rbp)         ## 4-byte Spill
	jmp	LBB78_14
LBB78_14:
	movl	-68(%rbp), %eax         ## 4-byte Reload
	movq	-32(%rbp), %rcx         ## 8-byte Reload
	movl	%eax, 56(%rcx)
	cmpq	$31, 16(%rcx)
	jae	LBB78_16
## BB#15:
	movl	$4294967295, %eax       ## imm = 0xFFFFFFFF
	movl	$32, %ecx
	movl	%ecx, %edx
	movq	-32(%rbp), %rsi         ## 8-byte Reload
	movq	16(%rsi), %rdi
	addq	$1, %rdi
	subq	%rdi, %rdx
	movl	%edx, %ecx
                                        ## kill: %CL<def> %ECX<kill>
	shrl	%cl, %eax
	movl	%eax, -72(%rbp)         ## 4-byte Spill
	jmp	LBB78_17
LBB78_16:
	movl	$4294967295, %eax       ## imm = 0xFFFFFFFF
	movl	%eax, -72(%rbp)         ## 4-byte Spill
	jmp	LBB78_17
LBB78_17:
	movl	-72(%rbp), %eax         ## 4-byte Reload
	movq	-32(%rbp), %rcx         ## 8-byte Reload
	movl	%eax, 60(%rcx)
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__125__independent_bits_engineINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEyE6__evalENS_17integral_constantIbLb1EEE
	.weak_definition	__ZNSt3__125__independent_bits_engineINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEyE6__evalENS_17integral_constantIbLb1EEE
	.p2align	4, 0x90
__ZNSt3__125__independent_bits_engineINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEyE6__evalENS_17integral_constantIbLb1EEE: ## @_ZNSt3__125__independent_bits_engineINS_26linear_congruential_engineIjLj48271ELj0ELj2147483647EEEyE6__evalENS_17integral_constantIbLb1EEE
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi234:
	.cfi_def_cfa_offset 16
Lcfi235:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi236:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -96(%rbp)
	movq	-96(%rbp), %rdi
	movq	$0, -104(%rbp)
	movq	$0, -112(%rbp)
	movq	%rdi, -144(%rbp)        ## 8-byte Spill
LBB79_1:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB79_3 Depth 2
	movq	-112(%rbp), %rax
	movq	-144(%rbp), %rcx        ## 8-byte Reload
	cmpq	32(%rcx), %rax
	jae	LBB79_10
## BB#2:                                ##   in Loop: Header=BB79_1 Depth=1
	jmp	LBB79_3
LBB79_3:                                ##   Parent Loop BB79_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	$44488, %eax            ## imm = 0xADC8
	movq	-144(%rbp), %rcx        ## 8-byte Reload
	movq	(%rcx), %rdx
	movq	%rdx, -80(%rbp)
	movq	-80(%rbp), %rdx
	movl	(%rdx), %esi
	movl	%esi, -44(%rbp)
	movl	$48271, -48(%rbp)       ## imm = 0xBC8F
	movl	$2147483647, -52(%rbp)  ## imm = 0x7FFFFFFF
	movl	$44488, -56(%rbp)       ## imm = 0xADC8
	movl	$3399, -60(%rbp)        ## imm = 0xD47
	movl	-44(%rbp), %esi
	movl	%eax, -148(%rbp)        ## 4-byte Spill
	movl	%esi, %eax
	xorl	%esi, %esi
	movq	%rdx, -160(%rbp)        ## 8-byte Spill
	movl	%esi, %edx
	movl	-148(%rbp), %esi        ## 4-byte Reload
	divl	%esi
	imull	$48271, %edx, %edx      ## imm = 0xBC8F
	movl	%edx, -64(%rbp)
	movl	-44(%rbp), %edx
	movl	%edx, %eax
	xorl	%edx, %edx
	divl	%esi
	imull	$3399, %eax, %eax       ## imm = 0xD47
	movl	%eax, -68(%rbp)
	movl	-64(%rbp), %eax
	movl	-64(%rbp), %edi
	cmpl	-68(%rbp), %edi
	setb	%r8b
	andb	$1, %r8b
	movzbl	%r8b, %edi
	imull	$2147483647, %edi, %edi ## imm = 0x7FFFFFFF
	addl	%edi, %eax
	subl	-68(%rbp), %eax
	movl	%eax, -44(%rbp)
	movl	-44(%rbp), %eax
	movq	-160(%rbp), %r9         ## 8-byte Reload
	movl	%eax, (%r9)
	subl	$1, %eax
	movl	%eax, -116(%rbp)
## BB#4:                                ##   in Loop: Header=BB79_3 Depth=2
	movl	-116(%rbp), %eax
	movl	%eax, %ecx
	movq	-144(%rbp), %rdx        ## 8-byte Reload
	cmpq	40(%rdx), %rcx
	jae	LBB79_3
## BB#5:                                ##   in Loop: Header=BB79_1 Depth=1
	movq	-144(%rbp), %rax        ## 8-byte Reload
	cmpq	$64, 16(%rax)
	jae	LBB79_7
## BB#6:                                ##   in Loop: Header=BB79_1 Depth=1
	movq	-144(%rbp), %rax        ## 8-byte Reload
	movq	16(%rax), %rcx
	movq	-104(%rbp), %rdx
                                        ## kill: %CL<def> %RCX<kill>
	shlq	%cl, %rdx
	movq	%rdx, -104(%rbp)
	jmp	LBB79_8
LBB79_7:                                ##   in Loop: Header=BB79_1 Depth=1
	movq	$0, -104(%rbp)
LBB79_8:                                ##   in Loop: Header=BB79_1 Depth=1
	movl	-116(%rbp), %eax
	movq	-144(%rbp), %rcx        ## 8-byte Reload
	andl	56(%rcx), %eax
	movl	%eax, %eax
	movl	%eax, %edx
	addq	-104(%rbp), %rdx
	movq	%rdx, -104(%rbp)
## BB#9:                                ##   in Loop: Header=BB79_1 Depth=1
	movq	-112(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -112(%rbp)
	jmp	LBB79_1
LBB79_10:
	movq	-144(%rbp), %rax        ## 8-byte Reload
	movq	32(%rax), %rcx
	movq	%rcx, -128(%rbp)
LBB79_11:                               ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB79_13 Depth 2
	movq	-128(%rbp), %rax
	movq	-144(%rbp), %rcx        ## 8-byte Reload
	cmpq	24(%rcx), %rax
	jae	LBB79_20
## BB#12:                               ##   in Loop: Header=BB79_11 Depth=1
	jmp	LBB79_13
LBB79_13:                               ##   Parent Loop BB79_11 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	$44488, %eax            ## imm = 0xADC8
	movq	-144(%rbp), %rcx        ## 8-byte Reload
	movq	(%rcx), %rdx
	movq	%rdx, -40(%rbp)
	movq	-40(%rbp), %rdx
	movl	(%rdx), %esi
	movl	%esi, -4(%rbp)
	movl	$48271, -8(%rbp)        ## imm = 0xBC8F
	movl	$2147483647, -12(%rbp)  ## imm = 0x7FFFFFFF
	movl	$44488, -16(%rbp)       ## imm = 0xADC8
	movl	$3399, -20(%rbp)        ## imm = 0xD47
	movl	-4(%rbp), %esi
	movl	%eax, -164(%rbp)        ## 4-byte Spill
	movl	%esi, %eax
	xorl	%esi, %esi
	movq	%rdx, -176(%rbp)        ## 8-byte Spill
	movl	%esi, %edx
	movl	-164(%rbp), %esi        ## 4-byte Reload
	divl	%esi
	imull	$48271, %edx, %edx      ## imm = 0xBC8F
	movl	%edx, -24(%rbp)
	movl	-4(%rbp), %edx
	movl	%edx, %eax
	xorl	%edx, %edx
	divl	%esi
	imull	$3399, %eax, %eax       ## imm = 0xD47
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	movl	-24(%rbp), %edi
	cmpl	-28(%rbp), %edi
	setb	%r8b
	andb	$1, %r8b
	movzbl	%r8b, %edi
	imull	$2147483647, %edi, %edi ## imm = 0x7FFFFFFF
	addl	%edi, %eax
	subl	-28(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movq	-176(%rbp), %r9         ## 8-byte Reload
	movl	%eax, (%r9)
	subl	$1, %eax
	movl	%eax, -132(%rbp)
## BB#14:                               ##   in Loop: Header=BB79_13 Depth=2
	movl	-132(%rbp), %eax
	movl	%eax, %ecx
	movq	-144(%rbp), %rdx        ## 8-byte Reload
	cmpq	48(%rdx), %rcx
	jae	LBB79_13
## BB#15:                               ##   in Loop: Header=BB79_11 Depth=1
	movq	-144(%rbp), %rax        ## 8-byte Reload
	cmpq	$63, 16(%rax)
	jae	LBB79_17
## BB#16:                               ##   in Loop: Header=BB79_11 Depth=1
	movq	-144(%rbp), %rax        ## 8-byte Reload
	movq	16(%rax), %rcx
	addq	$1, %rcx
	movq	-104(%rbp), %rdx
                                        ## kill: %CL<def> %RCX<kill>
	shlq	%cl, %rdx
	movq	%rdx, -104(%rbp)
	jmp	LBB79_18
LBB79_17:                               ##   in Loop: Header=BB79_11 Depth=1
	movq	$0, -104(%rbp)
LBB79_18:                               ##   in Loop: Header=BB79_11 Depth=1
	movl	-132(%rbp), %eax
	movq	-144(%rbp), %rcx        ## 8-byte Reload
	andl	60(%rcx), %eax
	movl	%eax, %eax
	movl	%eax, %edx
	addq	-104(%rbp), %rdx
	movq	%rdx, -104(%rbp)
## BB#19:                               ##   in Loop: Header=BB79_11 Depth=1
	movq	-128(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -128(%rbp)
	jmp	LBB79_11
LBB79_20:
	movq	-104(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__124uniform_int_distributionIlE10param_typeC2Ell
	.weak_def_can_be_hidden	__ZNSt3__124uniform_int_distributionIlE10param_typeC2Ell
	.p2align	4, 0x90
__ZNSt3__124uniform_int_distributionIlE10param_typeC2Ell: ## @_ZNSt3__124uniform_int_distributionIlE10param_typeC2Ell
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi237:
	.cfi_def_cfa_offset 16
Lcfi238:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi239:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rdx
	movq	-16(%rbp), %rsi
	movq	%rsi, (%rdx)
	movq	-24(%rbp), %rsi
	movq	%rsi, 8(%rdx)
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa4pairIiiEC1ERKiS3_
	.weak_def_can_be_hidden	__ZN3dsa4pairIiiEC1ERKiS3_
	.p2align	4, 0x90
__ZN3dsa4pairIiiEC1ERKiS3_:             ## @_ZN3dsa4pairIiiEC1ERKiS3_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi240:
	.cfi_def_cfa_offset 16
Lcfi241:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi242:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	movq	-24(%rbp), %rdx
	callq	__ZN3dsa4pairIiiEC2ERKiS3_
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa4pairIiiEC2ERKiS3_
	.weak_def_can_be_hidden	__ZN3dsa4pairIiiEC2ERKiS3_
	.p2align	4, 0x90
__ZN3dsa4pairIiiEC2ERKiS3_:             ## @_ZN3dsa4pairIiiEC2ERKiS3_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi243:
	.cfi_def_cfa_offset 16
Lcfi244:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi245:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rdx
	movq	-16(%rbp), %rsi
	movl	(%rsi), %eax
	movl	%eax, (%rdx)
	movq	-24(%rbp), %rsi
	movl	(%rsi), %eax
	movl	%eax, 4(%rdx)
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE25__emplace_unique_key_argsIiJRKiEEENS_4pairINS_15__tree_iteratorIiPNS_11__tree_nodeIiPvEElEEbEERKT_DpOT0_
	.weak_definition	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE25__emplace_unique_key_argsIiJRKiEEENS_4pairINS_15__tree_iteratorIiPNS_11__tree_nodeIiPvEElEEbEERKT_DpOT0_
	.p2align	4, 0x90
__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE25__emplace_unique_key_argsIiJRKiEEENS_4pairINS_15__tree_iteratorIiPNS_11__tree_nodeIiPvEElEEbEERKT_DpOT0_: ## @_ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE25__emplace_unique_key_argsIiJRKiEEENS_4pairINS_15__tree_iteratorIiPNS_11__tree_nodeIiPvEElEEbEERKT_DpOT0_
Lfunc_begin10:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception10
## BB#0:
	pushq	%rbp
Lcfi246:
	.cfi_def_cfa_offset 16
Lcfi247:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi248:
	.cfi_def_cfa_register %rbp
	subq	$800, %rsp              ## imm = 0x320
	leaq	-672(%rbp), %rax
	movq	%rdi, -648(%rbp)
	movq	%rsi, -656(%rbp)
	movq	%rdx, -664(%rbp)
	movq	-648(%rbp), %rdx
	movq	-656(%rbp), %rsi
	movq	%rdx, %rdi
	movq	%rsi, -752(%rbp)        ## 8-byte Spill
	movq	%rax, %rsi
	movq	-752(%rbp), %rax        ## 8-byte Reload
	movq	%rdx, -760(%rbp)        ## 8-byte Spill
	movq	%rax, %rdx
	callq	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE12__find_equalIiEERPNS_16__tree_node_baseIPvEERPNS_15__tree_end_nodeISA_EERKT_
	movq	%rax, -680(%rbp)
	movq	-680(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -688(%rbp)
	movb	$0, -689(%rbp)
	movq	-680(%rbp), %rax
	cmpq	$0, (%rax)
	jne	LBB83_16
## BB#1:
	movq	-664(%rbp), %rax
	movq	%rax, -624(%rbp)
	movq	-624(%rbp), %rdx
	leaq	-720(%rbp), %rax
	movq	%rax, %rdi
	movq	-760(%rbp), %rsi        ## 8-byte Reload
	movq	%rax, -768(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE16__construct_nodeIJRKiEEENS_10unique_ptrINS_11__tree_nodeIiPvEENS_22__tree_node_destructorINS3_ISC_EEEEEEDpOT_
	movq	-672(%rbp), %rsi
	movq	-680(%rbp), %rdx
	movq	-768(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -296(%rbp)
	movq	-296(%rbp), %rdi
	movq	%rdi, -288(%rbp)
	movq	-288(%rbp), %rdi
	movq	%rdi, -280(%rbp)
	movq	-280(%rbp), %rdi
	movq	(%rdi), %rcx
Ltmp171:
	movq	-760(%rbp), %rdi        ## 8-byte Reload
	callq	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE16__insert_node_atEPNS_15__tree_end_nodeIPNS_16__tree_node_baseIPvEEEERSA_SA_
Ltmp172:
	jmp	LBB83_2
LBB83_2:
	leaq	-720(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rcx
	movq	%rcx, -32(%rbp)
	movq	-32(%rbp), %rdx
	movq	%rdx, -24(%rbp)
	movq	-24(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, -48(%rbp)
	movq	%rcx, -16(%rbp)
	movq	-16(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	$0, (%rcx)
	movq	-48(%rbp), %rcx
	movq	%rcx, -688(%rbp)
	movb	$1, -689(%rbp)
	movq	%rax, -272(%rbp)
	movq	-272(%rbp), %rax
	movq	%rax, -264(%rbp)
	movq	-264(%rbp), %rax
	movq	%rax, -240(%rbp)
	movq	$0, -248(%rbp)
	movq	-240(%rbp), %rax
	movq	%rax, -232(%rbp)
	movq	-232(%rbp), %rcx
	movq	%rcx, -224(%rbp)
	movq	-224(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -256(%rbp)
	movq	-248(%rbp), %rcx
	movq	%rax, -80(%rbp)
	movq	-80(%rbp), %rdx
	movq	%rdx, -72(%rbp)
	movq	-72(%rbp), %rdx
	movq	%rcx, (%rdx)
	cmpq	$0, -256(%rbp)
	movq	%rax, -776(%rbp)        ## 8-byte Spill
	je	LBB83_8
## BB#3:
	movq	-776(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -64(%rbp)
	movq	-64(%rbp), %rcx
	movq	%rcx, -56(%rbp)
	movq	-56(%rbp), %rcx
	addq	$8, %rcx
	movq	-256(%rbp), %rdx
	movq	%rcx, -208(%rbp)
	movq	%rdx, -216(%rbp)
	movq	-208(%rbp), %rcx
	testb	$1, 8(%rcx)
	movq	%rcx, -784(%rbp)        ## 8-byte Spill
	je	LBB83_5
## BB#4:
	movq	-784(%rbp), %rax        ## 8-byte Reload
	movq	(%rax), %rcx
	movq	-216(%rbp), %rdx
	addq	$28, %rdx
	movq	%rdx, -200(%rbp)
	movq	-200(%rbp), %rdx
	movq	%rdx, -192(%rbp)
	movq	-192(%rbp), %rdx
	movq	%rcx, -160(%rbp)
	movq	%rdx, -168(%rbp)
	movq	-160(%rbp), %rcx
	movq	-168(%rbp), %rdx
	movq	%rcx, -144(%rbp)
	movq	%rdx, -152(%rbp)
LBB83_5:
	cmpq	$0, -216(%rbp)
	je	LBB83_7
## BB#6:
	movq	-784(%rbp), %rax        ## 8-byte Reload
	movq	(%rax), %rcx
	movq	-216(%rbp), %rdx
	movq	%rcx, -120(%rbp)
	movq	%rdx, -128(%rbp)
	movq	$1, -136(%rbp)
	movq	-120(%rbp), %rcx
	movq	-128(%rbp), %rdx
	movq	-136(%rbp), %rsi
	movq	%rcx, -96(%rbp)
	movq	%rdx, -104(%rbp)
	movq	%rsi, -112(%rbp)
	movq	-104(%rbp), %rcx
	movq	%rcx, -88(%rbp)
	movq	-88(%rbp), %rdi
	callq	__ZdlPv
LBB83_7:
	jmp	LBB83_8
LBB83_8:
	jmp	LBB83_16
LBB83_9:
Ltmp173:
	leaq	-720(%rbp), %rcx
	movl	%edx, %esi
	movq	%rax, -728(%rbp)
	movl	%esi, -732(%rbp)
	movq	%rcx, -520(%rbp)
	movq	-520(%rbp), %rax
	movq	%rax, -512(%rbp)
	movq	-512(%rbp), %rax
	movq	%rax, -488(%rbp)
	movq	$0, -496(%rbp)
	movq	-488(%rbp), %rax
	movq	%rax, -480(%rbp)
	movq	-480(%rbp), %rcx
	movq	%rcx, -472(%rbp)
	movq	-472(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -504(%rbp)
	movq	-496(%rbp), %rcx
	movq	%rax, -328(%rbp)
	movq	-328(%rbp), %rdx
	movq	%rdx, -320(%rbp)
	movq	-320(%rbp), %rdx
	movq	%rcx, (%rdx)
	cmpq	$0, -504(%rbp)
	movq	%rax, -792(%rbp)        ## 8-byte Spill
	je	LBB83_15
## BB#10:
	movq	-792(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -312(%rbp)
	movq	-312(%rbp), %rcx
	movq	%rcx, -304(%rbp)
	movq	-304(%rbp), %rcx
	addq	$8, %rcx
	movq	-504(%rbp), %rdx
	movq	%rcx, -456(%rbp)
	movq	%rdx, -464(%rbp)
	movq	-456(%rbp), %rcx
	testb	$1, 8(%rcx)
	movq	%rcx, -800(%rbp)        ## 8-byte Spill
	je	LBB83_12
## BB#11:
	movq	-800(%rbp), %rax        ## 8-byte Reload
	movq	(%rax), %rcx
	movq	-464(%rbp), %rdx
	addq	$28, %rdx
	movq	%rdx, -448(%rbp)
	movq	-448(%rbp), %rdx
	movq	%rdx, -440(%rbp)
	movq	-440(%rbp), %rdx
	movq	%rcx, -408(%rbp)
	movq	%rdx, -416(%rbp)
	movq	-408(%rbp), %rcx
	movq	-416(%rbp), %rdx
	movq	%rcx, -392(%rbp)
	movq	%rdx, -400(%rbp)
LBB83_12:
	cmpq	$0, -464(%rbp)
	je	LBB83_14
## BB#13:
	movq	-800(%rbp), %rax        ## 8-byte Reload
	movq	(%rax), %rcx
	movq	-464(%rbp), %rdx
	movq	%rcx, -368(%rbp)
	movq	%rdx, -376(%rbp)
	movq	$1, -384(%rbp)
	movq	-368(%rbp), %rcx
	movq	-376(%rbp), %rdx
	movq	-384(%rbp), %rsi
	movq	%rcx, -344(%rbp)
	movq	%rdx, -352(%rbp)
	movq	%rsi, -360(%rbp)
	movq	-352(%rbp), %rcx
	movq	%rcx, -336(%rbp)
	movq	-336(%rbp), %rdi
	callq	__ZdlPv
LBB83_14:
	jmp	LBB83_15
LBB83_15:
	jmp	LBB83_17
LBB83_16:
	movq	-688(%rbp), %rax
	leaq	-744(%rbp), %rcx
	movq	%rcx, -544(%rbp)
	movq	%rax, -552(%rbp)
	movq	-544(%rbp), %rax
	movq	-552(%rbp), %rdx
	movq	%rax, -528(%rbp)
	movq	%rdx, -536(%rbp)
	movq	-528(%rbp), %rax
	movq	-536(%rbp), %rdx
	movq	%rdx, (%rax)
	leaq	-640(%rbp), %rax
	movq	%rax, -600(%rbp)
	movq	%rcx, -608(%rbp)
	leaq	-689(%rbp), %rax
	movq	%rax, -616(%rbp)
	movq	-600(%rbp), %rax
	movq	-608(%rbp), %rcx
	movq	-616(%rbp), %rdx
	movq	%rax, -576(%rbp)
	movq	%rcx, -584(%rbp)
	movq	%rdx, -592(%rbp)
	movq	-576(%rbp), %rax
	movq	-584(%rbp), %rcx
	movq	%rcx, -568(%rbp)
	movq	-568(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, (%rax)
	movq	-592(%rbp), %rcx
	movq	%rcx, -560(%rbp)
	movq	-560(%rbp), %rcx
	movb	(%rcx), %sil
	andb	$1, %sil
	movb	%sil, 8(%rax)
	movq	-640(%rbp), %rax
	movb	-632(%rbp), %dl
	addq	$800, %rsp              ## imm = 0x320
	popq	%rbp
	retq
LBB83_17:
	movq	-728(%rbp), %rdi
	callq	__Unwind_Resume
Lfunc_end10:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table83:
Lexception10:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset84 = Lfunc_begin10-Lfunc_begin10    ## >> Call Site 1 <<
	.long	Lset84
Lset85 = Ltmp171-Lfunc_begin10          ##   Call between Lfunc_begin10 and Ltmp171
	.long	Lset85
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset86 = Ltmp171-Lfunc_begin10          ## >> Call Site 2 <<
	.long	Lset86
Lset87 = Ltmp172-Ltmp171                ##   Call between Ltmp171 and Ltmp172
	.long	Lset87
Lset88 = Ltmp173-Lfunc_begin10          ##     jumps to Ltmp173
	.long	Lset88
	.byte	0                       ##   On action: cleanup
Lset89 = Ltmp172-Lfunc_begin10          ## >> Call Site 3 <<
	.long	Lset89
Lset90 = Lfunc_end10-Ltmp172            ##   Call between Ltmp172 and Lfunc_end10
	.long	Lset90
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE12__find_equalIiEERPNS_16__tree_node_baseIPvEERPNS_15__tree_end_nodeISA_EERKT_
	.weak_definition	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE12__find_equalIiEERPNS_16__tree_node_baseIPvEERPNS_15__tree_end_nodeISA_EERKT_
	.p2align	4, 0x90
__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE12__find_equalIiEERPNS_16__tree_node_baseIPvEERPNS_15__tree_end_nodeISA_EERKT_: ## @_ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE12__find_equalIiEERPNS_16__tree_node_baseIPvEERPNS_15__tree_end_nodeISA_EERKT_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi249:
	.cfi_def_cfa_offset 16
Lcfi250:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi251:
	.cfi_def_cfa_register %rbp
	subq	$256, %rsp              ## imm = 0x100
	movq	%rdi, -216(%rbp)
	movq	%rsi, -224(%rbp)
	movq	%rdx, -232(%rbp)
	movq	-216(%rbp), %rdx
	movq	%rdx, -200(%rbp)
	movq	-200(%rbp), %rsi
	movq	%rsi, -192(%rbp)
	movq	-192(%rbp), %rsi
	addq	$8, %rsi
	movq	%rsi, -184(%rbp)
	movq	-184(%rbp), %rsi
	movq	%rsi, -176(%rbp)
	movq	-176(%rbp), %rsi
	movq	%rsi, -168(%rbp)
	movq	-168(%rbp), %rsi
	movq	%rsi, -160(%rbp)
	movq	-160(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -240(%rbp)
	movq	%rdx, %rdi
	movq	%rdx, -256(%rbp)        ## 8-byte Spill
	callq	__ZNKSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE10__root_ptrEv
	movq	%rax, -248(%rbp)
	cmpq	$0, -240(%rbp)
	je	LBB84_15
## BB#1:
	jmp	LBB84_2
LBB84_2:                                ## =>This Inner Loop Header: Depth=1
	movq	-256(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rcx
	addq	$16, %rcx
	movq	%rcx, -16(%rbp)
	movq	-16(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	-232(%rbp), %rdx
	movq	-240(%rbp), %rsi
	addq	$28, %rsi
	movq	%rcx, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-40(%rbp), %rcx
	movl	(%rcx), %edi
	movq	-48(%rbp), %rcx
	cmpl	(%rcx), %edi
	jge	LBB84_7
## BB#3:                                ##   in Loop: Header=BB84_2 Depth=1
	movq	-240(%rbp), %rax
	cmpq	$0, (%rax)
	je	LBB84_5
## BB#4:                                ##   in Loop: Header=BB84_2 Depth=1
	movq	-240(%rbp), %rax
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, -248(%rbp)
	movq	-240(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -240(%rbp)
	jmp	LBB84_6
LBB84_5:
	movq	-240(%rbp), %rax
	movq	-224(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-224(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -208(%rbp)
	jmp	LBB84_16
LBB84_6:                                ##   in Loop: Header=BB84_2 Depth=1
	jmp	LBB84_14
LBB84_7:                                ##   in Loop: Header=BB84_2 Depth=1
	movq	-256(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -80(%rbp)
	movq	-80(%rbp), %rcx
	addq	$16, %rcx
	movq	%rcx, -72(%rbp)
	movq	-72(%rbp), %rcx
	movq	%rcx, -64(%rbp)
	movq	-64(%rbp), %rcx
	movq	-240(%rbp), %rdx
	addq	$28, %rdx
	movq	-232(%rbp), %rsi
	movq	%rcx, -88(%rbp)
	movq	%rdx, -96(%rbp)
	movq	%rsi, -104(%rbp)
	movq	-96(%rbp), %rcx
	movl	(%rcx), %edi
	movq	-104(%rbp), %rcx
	cmpl	(%rcx), %edi
	jge	LBB84_12
## BB#8:                                ##   in Loop: Header=BB84_2 Depth=1
	movq	-240(%rbp), %rax
	cmpq	$0, 8(%rax)
	je	LBB84_10
## BB#9:                                ##   in Loop: Header=BB84_2 Depth=1
	movq	-240(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -112(%rbp)
	movq	-112(%rbp), %rax
	movq	%rax, -248(%rbp)
	movq	-240(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -240(%rbp)
	jmp	LBB84_11
LBB84_10:
	movq	-240(%rbp), %rax
	movq	-224(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-240(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -208(%rbp)
	jmp	LBB84_16
LBB84_11:                               ##   in Loop: Header=BB84_2 Depth=1
	jmp	LBB84_13
LBB84_12:
	movq	-240(%rbp), %rax
	movq	-224(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-248(%rbp), %rax
	movq	%rax, -208(%rbp)
	jmp	LBB84_16
LBB84_13:                               ##   in Loop: Header=BB84_2 Depth=1
	jmp	LBB84_14
LBB84_14:                               ##   in Loop: Header=BB84_2 Depth=1
	jmp	LBB84_2
LBB84_15:
	movq	-256(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -152(%rbp)
	movq	-152(%rbp), %rcx
	addq	$8, %rcx
	movq	%rcx, -144(%rbp)
	movq	-144(%rbp), %rcx
	movq	%rcx, -136(%rbp)
	movq	-136(%rbp), %rcx
	movq	%rcx, -128(%rbp)
	movq	-128(%rbp), %rcx
	movq	%rcx, -120(%rbp)
	movq	-120(%rbp), %rcx
	movq	-224(%rbp), %rdx
	movq	%rcx, (%rdx)
	movq	-224(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -208(%rbp)
LBB84_16:
	movq	-208(%rbp), %rax
	addq	$256, %rsp              ## imm = 0x100
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE16__construct_nodeIJRKiEEENS_10unique_ptrINS_11__tree_nodeIiPvEENS_22__tree_node_destructorINS3_ISC_EEEEEEDpOT_
	.weak_definition	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE16__construct_nodeIJRKiEEENS_10unique_ptrINS_11__tree_nodeIiPvEENS_22__tree_node_destructorINS3_ISC_EEEEEEDpOT_
	.p2align	4, 0x90
__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE16__construct_nodeIJRKiEEENS_10unique_ptrINS_11__tree_nodeIiPvEENS_22__tree_node_destructorINS3_ISC_EEEEEEDpOT_: ## @_ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE16__construct_nodeIJRKiEEENS_10unique_ptrINS_11__tree_nodeIiPvEENS_22__tree_node_destructorINS3_ISC_EEEEEEDpOT_
Lfunc_begin11:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception11
## BB#0:
	pushq	%rbp
Lcfi252:
	.cfi_def_cfa_offset 16
Lcfi253:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi254:
	.cfi_def_cfa_register %rbp
	pushq	%rbx
	subq	$1176, %rsp             ## imm = 0x498
Lcfi255:
	.cfi_offset %rbx, -24
	movq	%rdi, %rax
	movabsq	$576460752303423487, %rcx ## imm = 0x7FFFFFFFFFFFFFF
	movq	%rsi, -1056(%rbp)
	movq	%rdx, -1064(%rbp)
	movq	-1056(%rbp), %rdx
	movq	%rdx, -1048(%rbp)
	movq	-1048(%rbp), %rdx
	addq	$8, %rdx
	movq	%rdx, -1040(%rbp)
	movq	-1040(%rbp), %rdx
	movq	%rdx, -1032(%rbp)
	movq	-1032(%rbp), %rdx
	movq	%rdx, -1072(%rbp)
	movb	$0, -1073(%rbp)
	movq	-1072(%rbp), %rdx
	movq	%rdx, -792(%rbp)
	movq	$1, -800(%rbp)
	movq	-792(%rbp), %rdx
	movq	-800(%rbp), %rsi
	movq	%rdx, -768(%rbp)
	movq	%rsi, -776(%rbp)
	movq	$0, -784(%rbp)
	movq	-768(%rbp), %rdx
	movq	-776(%rbp), %rsi
	movq	%rdx, -760(%rbp)
	cmpq	%rcx, %rsi
	movq	%rax, -1120(%rbp)       ## 8-byte Spill
	movq	%rdi, -1128(%rbp)       ## 8-byte Spill
	jbe	LBB85_4
## BB#1:
	leaq	L_.str.15(%rip), %rax
	movq	%rax, -728(%rbp)
	movl	$16, %ecx
	movl	%ecx, %edi
	callq	___cxa_allocate_exception
	movq	%rax, %rdi
	movq	-728(%rbp), %rdx
	movq	%rax, -712(%rbp)
	movq	%rdx, -720(%rbp)
	movq	-712(%rbp), %rax
	movq	-720(%rbp), %rdx
	movq	%rax, -696(%rbp)
	movq	%rdx, -704(%rbp)
	movq	-696(%rbp), %rax
	movq	-704(%rbp), %rsi
Ltmp174:
	movq	%rdi, -1136(%rbp)       ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rax, -1144(%rbp)       ## 8-byte Spill
	callq	__ZNSt11logic_errorC2EPKc
Ltmp175:
	jmp	LBB85_2
LBB85_2:
	movq	__ZTISt12length_error@GOTPCREL(%rip), %rax
	movq	__ZNSt12length_errorD1Ev@GOTPCREL(%rip), %rcx
	movq	__ZTVSt12length_error@GOTPCREL(%rip), %rdx
	addq	$16, %rdx
	movq	-1144(%rbp), %rsi       ## 8-byte Reload
	movq	%rdx, (%rsi)
	movq	-1136(%rbp), %rdi       ## 8-byte Reload
	movq	%rax, %rsi
	movq	%rcx, %rdx
	callq	___cxa_throw
LBB85_3:
Ltmp176:
	movl	%edx, %ecx
	movq	%rax, -736(%rbp)
	movl	%ecx, -740(%rbp)
	movq	-1136(%rbp), %rdi       ## 8-byte Reload
	callq	___cxa_free_exception
	movq	-736(%rbp), %rdi
	callq	__Unwind_Resume
LBB85_4:
	movq	-776(%rbp), %rax
	shlq	$5, %rax
	movq	%rax, -752(%rbp)
	movq	-752(%rbp), %rdi
	callq	__Znwm
	leaq	-464(%rbp), %rdi
	leaq	-480(%rbp), %rcx
	leaq	-504(%rbp), %rdx
	leaq	-520(%rbp), %rsi
	leaq	-1096(%rbp), %r8
	movq	-1072(%rbp), %r9
	movq	%r8, -672(%rbp)
	movq	%r9, -680(%rbp)
	movb	$0, -681(%rbp)
	movq	-672(%rbp), %r9
	movq	-680(%rbp), %r10
	movb	-681(%rbp), %r11b
	movq	%r9, -648(%rbp)
	movq	%r10, -656(%rbp)
	andb	$1, %r11b
	movb	%r11b, -657(%rbp)
	movq	-648(%rbp), %r9
	movq	-656(%rbp), %r10
	movq	%r10, (%r9)
	movb	-657(%rbp), %r11b
	andb	$1, %r11b
	movb	%r11b, 8(%r9)
	movq	-1128(%rbp), %r9        ## 8-byte Reload
	movq	%r9, -624(%rbp)
	movq	%rax, -632(%rbp)
	movq	%r8, -640(%rbp)
	movq	-624(%rbp), %rax
	movq	-632(%rbp), %r8
	movq	-640(%rbp), %r10
	movq	%rax, -584(%rbp)
	movq	%r8, -592(%rbp)
	movq	%r10, -600(%rbp)
	movq	-584(%rbp), %rax
	movq	-592(%rbp), %r8
	movq	-600(%rbp), %r10
	movq	%r10, -576(%rbp)
	movq	-576(%rbp), %r10
	movq	(%r10), %rbx
	movq	%rbx, -616(%rbp)
	movq	8(%r10), %r10
	movq	%r10, -608(%rbp)
	movq	-616(%rbp), %r10
	movb	-608(%rbp), %r11b
	movq	%r10, -552(%rbp)
	movb	%r11b, -544(%rbp)
	movq	%rax, -560(%rbp)
	movq	%r8, -568(%rbp)
	movq	-560(%rbp), %rax
	movq	-568(%rbp), %r8
	movq	-552(%rbp), %r10
	movb	-544(%rbp), %r11b
	movq	%r10, -504(%rbp)
	movb	%r11b, -496(%rbp)
	movq	%rax, -512(%rbp)
	movq	%r8, -520(%rbp)
	movq	-512(%rbp), %rax
	movq	%rsi, -488(%rbp)
	movq	-488(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rdx, -432(%rbp)
	movq	-432(%rbp), %rdx
	movq	(%rdx), %r8
	movq	%r8, -536(%rbp)
	movq	8(%rdx), %rdx
	movq	%rdx, -528(%rbp)
	movq	-536(%rbp), %rdx
	movb	-528(%rbp), %r11b
	movq	%rdx, -464(%rbp)
	movb	%r11b, -456(%rbp)
	movq	%rax, -472(%rbp)
	movq	%rsi, -480(%rbp)
	movq	-472(%rbp), %rax
	movq	%rcx, -448(%rbp)
	movq	-448(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, (%rax)
	movq	%rdi, -440(%rbp)
	movq	-440(%rbp), %rcx
	movq	(%rcx), %rdx
	movq	%rdx, 8(%rax)
	movq	8(%rcx), %rcx
	movq	%rcx, 16(%rax)
	movq	-1072(%rbp), %rax
	movq	%r9, -424(%rbp)
	movq	-424(%rbp), %rcx
	movq	%rcx, -416(%rbp)
	movq	-416(%rbp), %rcx
	movq	%rcx, -408(%rbp)
	movq	-408(%rbp), %rcx
	movq	(%rcx), %rcx
	addq	$28, %rcx
	movq	%rcx, -400(%rbp)
	movq	-400(%rbp), %rcx
	movq	%rcx, -392(%rbp)
	movq	-392(%rbp), %rcx
	movq	%rax, -1152(%rbp)       ## 8-byte Spill
	movq	%rcx, -1160(%rbp)       ## 8-byte Spill
## BB#5:
	movq	-1064(%rbp), %rax
	movq	%rax, -384(%rbp)
	movq	-384(%rbp), %rax
	movq	-1152(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -120(%rbp)
	movq	-1160(%rbp), %rdx       ## 8-byte Reload
	movq	%rdx, -128(%rbp)
	movq	%rax, -136(%rbp)
	movq	-120(%rbp), %rax
	movq	-128(%rbp), %rsi
	movq	-136(%rbp), %rdi
	movq	%rdi, -112(%rbp)
	movq	-112(%rbp), %rdi
	movq	%rax, -88(%rbp)
	movq	%rsi, -96(%rbp)
	movq	%rdi, -104(%rbp)
	movq	-88(%rbp), %rax
	movq	-96(%rbp), %rsi
	movq	-104(%rbp), %rdi
	movq	%rdi, -72(%rbp)
	movq	-72(%rbp), %rdi
	movq	%rax, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdi, -64(%rbp)
	movq	-56(%rbp), %rax
	movq	-64(%rbp), %rsi
	movq	%rsi, -40(%rbp)
	movq	-40(%rbp), %rsi
	movl	(%rsi), %r8d
	movl	%r8d, (%rax)
## BB#6:
	movq	-1128(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rcx
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rcx
	movq	%rcx, -16(%rbp)
	movq	-16(%rbp), %rcx
	movb	$1, 16(%rcx)
	movb	$1, -1073(%rbp)
	testb	$1, -1073(%rbp)
	jne	LBB85_14
## BB#7:
	movq	-1128(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1024(%rbp)
	movq	-1024(%rbp), %rcx
	movq	%rcx, -1016(%rbp)
	movq	-1016(%rbp), %rcx
	movq	%rcx, -992(%rbp)
	movq	$0, -1000(%rbp)
	movq	-992(%rbp), %rcx
	movq	%rcx, -984(%rbp)
	movq	-984(%rbp), %rdx
	movq	%rdx, -976(%rbp)
	movq	-976(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, -1008(%rbp)
	movq	-1000(%rbp), %rdx
	movq	%rcx, -832(%rbp)
	movq	-832(%rbp), %rsi
	movq	%rsi, -824(%rbp)
	movq	-824(%rbp), %rsi
	movq	%rdx, (%rsi)
	cmpq	$0, -1008(%rbp)
	movq	%rcx, -1168(%rbp)       ## 8-byte Spill
	je	LBB85_13
## BB#8:
	movq	-1168(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -816(%rbp)
	movq	-816(%rbp), %rcx
	movq	%rcx, -808(%rbp)
	movq	-808(%rbp), %rcx
	addq	$8, %rcx
	movq	-1008(%rbp), %rdx
	movq	%rcx, -960(%rbp)
	movq	%rdx, -968(%rbp)
	movq	-960(%rbp), %rcx
	testb	$1, 8(%rcx)
	movq	%rcx, -1176(%rbp)       ## 8-byte Spill
	je	LBB85_10
## BB#9:
	movq	-1176(%rbp), %rax       ## 8-byte Reload
	movq	(%rax), %rcx
	movq	-968(%rbp), %rdx
	addq	$28, %rdx
	movq	%rdx, -952(%rbp)
	movq	-952(%rbp), %rdx
	movq	%rdx, -944(%rbp)
	movq	-944(%rbp), %rdx
	movq	%rcx, -912(%rbp)
	movq	%rdx, -920(%rbp)
	movq	-912(%rbp), %rcx
	movq	-920(%rbp), %rdx
	movq	%rcx, -896(%rbp)
	movq	%rdx, -904(%rbp)
LBB85_10:
	cmpq	$0, -968(%rbp)
	je	LBB85_12
## BB#11:
	movq	-1176(%rbp), %rax       ## 8-byte Reload
	movq	(%rax), %rcx
	movq	-968(%rbp), %rdx
	movq	%rcx, -872(%rbp)
	movq	%rdx, -880(%rbp)
	movq	$1, -888(%rbp)
	movq	-872(%rbp), %rcx
	movq	-880(%rbp), %rdx
	movq	-888(%rbp), %rsi
	movq	%rcx, -848(%rbp)
	movq	%rdx, -856(%rbp)
	movq	%rsi, -864(%rbp)
	movq	-856(%rbp), %rcx
	movq	%rcx, -840(%rbp)
	movq	-840(%rbp), %rdi
	callq	__ZdlPv
LBB85_12:
	jmp	LBB85_13
LBB85_13:
	jmp	LBB85_14
LBB85_14:
	movq	-1120(%rbp), %rax       ## 8-byte Reload
	addq	$1176, %rsp             ## imm = 0x498
	popq	%rbx
	popq	%rbp
	retq
Lfunc_end11:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table85:
Lexception11:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset91 = Lfunc_begin11-Lfunc_begin11    ## >> Call Site 1 <<
	.long	Lset91
Lset92 = Ltmp174-Lfunc_begin11          ##   Call between Lfunc_begin11 and Ltmp174
	.long	Lset92
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset93 = Ltmp174-Lfunc_begin11          ## >> Call Site 2 <<
	.long	Lset93
Lset94 = Ltmp175-Ltmp174                ##   Call between Ltmp174 and Ltmp175
	.long	Lset94
Lset95 = Ltmp176-Lfunc_begin11          ##     jumps to Ltmp176
	.long	Lset95
	.byte	0                       ##   On action: cleanup
Lset96 = Ltmp175-Lfunc_begin11          ## >> Call Site 3 <<
	.long	Lset96
Lset97 = Lfunc_end11-Ltmp175            ##   Call between Ltmp175 and Lfunc_end11
	.long	Lset97
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE16__insert_node_atEPNS_15__tree_end_nodeIPNS_16__tree_node_baseIPvEEEERSA_SA_
	.weak_definition	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE16__insert_node_atEPNS_15__tree_end_nodeIPNS_16__tree_node_baseIPvEEEERSA_SA_
	.p2align	4, 0x90
__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE16__insert_node_atEPNS_15__tree_end_nodeIPNS_16__tree_node_baseIPvEEEERSA_SA_: ## @_ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE16__insert_node_atEPNS_15__tree_end_nodeIPNS_16__tree_node_baseIPvEEEERSA_SA_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi256:
	.cfi_def_cfa_offset 16
Lcfi257:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi258:
	.cfi_def_cfa_register %rbp
	subq	$128, %rsp
	movq	%rdi, -96(%rbp)
	movq	%rsi, -104(%rbp)
	movq	%rdx, -112(%rbp)
	movq	%rcx, -120(%rbp)
	movq	-96(%rbp), %rcx
	movq	-120(%rbp), %rdx
	movq	$0, (%rdx)
	movq	-120(%rbp), %rdx
	movq	$0, 8(%rdx)
	movq	-104(%rbp), %rdx
	movq	-120(%rbp), %rsi
	movq	%rdx, 16(%rsi)
	movq	-120(%rbp), %rdx
	movq	-112(%rbp), %rsi
	movq	%rdx, (%rsi)
	movq	%rcx, -88(%rbp)
	movq	-88(%rbp), %rdx
	movq	(%rdx), %rdx
	cmpq	$0, (%rdx)
	movq	%rcx, -128(%rbp)        ## 8-byte Spill
	je	LBB86_2
## BB#1:
	movq	-128(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	(%rcx), %rcx
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	%rcx, (%rdx)
LBB86_2:
	movq	-128(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rcx
	addq	$8, %rcx
	movq	%rcx, -40(%rbp)
	movq	-40(%rbp), %rcx
	movq	%rcx, -32(%rbp)
	movq	-32(%rbp), %rcx
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rcx
	movq	%rcx, -16(%rbp)
	movq	-16(%rbp), %rcx
	movq	(%rcx), %rdi
	movq	-112(%rbp), %rcx
	movq	(%rcx), %rsi
	callq	__ZNSt3__127__tree_balance_after_insertIPNS_16__tree_node_baseIPvEEEEvT_S5_
	movq	-128(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -80(%rbp)
	movq	-80(%rbp), %rcx
	addq	$16, %rcx
	movq	%rcx, -72(%rbp)
	movq	-72(%rbp), %rcx
	movq	%rcx, -64(%rbp)
	movq	-64(%rbp), %rcx
	movq	(%rcx), %rsi
	addq	$1, %rsi
	movq	%rsi, (%rcx)
	addq	$128, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNKSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE10__root_ptrEv
	.weak_definition	__ZNKSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE10__root_ptrEv
	.p2align	4, 0x90
__ZNKSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE10__root_ptrEv: ## @_ZNKSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE10__root_ptrEv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi259:
	.cfi_def_cfa_offset 16
Lcfi260:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi261:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -56(%rbp)
	movq	-56(%rbp), %rdi
	movq	%rdi, -48(%rbp)
	movq	-48(%rbp), %rdi
	addq	$8, %rdi
	movq	%rdi, -40(%rbp)
	movq	-40(%rbp), %rdi
	movq	%rdi, -32(%rbp)
	movq	-32(%rbp), %rdi
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rdi
	movq	%rdi, -16(%rbp)
	movq	-16(%rbp), %rdi
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__127__tree_balance_after_insertIPNS_16__tree_node_baseIPvEEEEvT_S5_
	.weak_definition	__ZNSt3__127__tree_balance_after_insertIPNS_16__tree_node_baseIPvEEEEvT_S5_
	.p2align	4, 0x90
__ZNSt3__127__tree_balance_after_insertIPNS_16__tree_node_baseIPvEEEEvT_S5_: ## @_ZNSt3__127__tree_balance_after_insertIPNS_16__tree_node_baseIPvEEEEvT_S5_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi262:
	.cfi_def_cfa_offset 16
Lcfi263:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi264:
	.cfi_def_cfa_register %rbp
	subq	$304, %rsp              ## imm = 0x130
	movq	%rdi, -152(%rbp)
	movq	%rsi, -160(%rbp)
	movq	-160(%rbp), %rsi
	cmpq	-152(%rbp), %rsi
	sete	%al
	movq	-160(%rbp), %rsi
	andb	$1, %al
	movb	%al, 24(%rsi)
LBB88_1:                                ## =>This Inner Loop Header: Depth=1
	xorl	%eax, %eax
	movb	%al, %cl
	movq	-160(%rbp), %rdx
	cmpq	-152(%rbp), %rdx
	movb	%cl, -177(%rbp)         ## 1-byte Spill
	je	LBB88_4
## BB#2:                                ##   in Loop: Header=BB88_1 Depth=1
	movq	-160(%rbp), %rax
	movq	%rax, -144(%rbp)
	movq	-144(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -192(%rbp)        ## 8-byte Spill
## BB#3:                                ##   in Loop: Header=BB88_1 Depth=1
	movq	-192(%rbp), %rax        ## 8-byte Reload
	movb	24(%rax), %cl
	xorb	$-1, %cl
	movb	%cl, -177(%rbp)         ## 1-byte Spill
LBB88_4:                                ##   in Loop: Header=BB88_1 Depth=1
	movb	-177(%rbp), %al         ## 1-byte Reload
	testb	$1, %al
	jne	LBB88_5
	jmp	LBB88_35
LBB88_5:                                ##   in Loop: Header=BB88_1 Depth=1
	movq	-160(%rbp), %rax
	movq	%rax, -136(%rbp)
	movq	-136(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -200(%rbp)        ## 8-byte Spill
## BB#6:                                ##   in Loop: Header=BB88_1 Depth=1
	movq	-200(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -128(%rbp)
	movq	-128(%rbp), %rcx
	movq	-128(%rbp), %rdx
	movq	16(%rdx), %rdx
	cmpq	(%rdx), %rcx
	jne	LBB88_21
## BB#7:                                ##   in Loop: Header=BB88_1 Depth=1
	movq	-160(%rbp), %rax
	movq	%rax, -104(%rbp)
	movq	-104(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -208(%rbp)        ## 8-byte Spill
## BB#8:                                ##   in Loop: Header=BB88_1 Depth=1
	movq	-208(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -216(%rbp)        ## 8-byte Spill
## BB#9:                                ##   in Loop: Header=BB88_1 Depth=1
	movq	-216(%rbp), %rax        ## 8-byte Reload
	movq	8(%rax), %rcx
	movq	%rcx, -168(%rbp)
	cmpq	$0, -168(%rbp)
	je	LBB88_14
## BB#10:                               ##   in Loop: Header=BB88_1 Depth=1
	movq	-168(%rbp), %rax
	testb	$1, 24(%rax)
	jne	LBB88_14
## BB#11:                               ##   in Loop: Header=BB88_1 Depth=1
	movq	-160(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -224(%rbp)        ## 8-byte Spill
## BB#12:                               ##   in Loop: Header=BB88_1 Depth=1
	movq	-224(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rcx
	movb	$1, 24(%rcx)
	movq	-160(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -232(%rbp)        ## 8-byte Spill
## BB#13:                               ##   in Loop: Header=BB88_1 Depth=1
	movq	-232(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rcx
	cmpq	-152(%rbp), %rcx
	sete	%dl
	movq	-160(%rbp), %rcx
	andb	$1, %dl
	movb	%dl, 24(%rcx)
	movq	-168(%rbp), %rcx
	movb	$1, 24(%rcx)
	jmp	LBB88_20
LBB88_14:
	movq	-160(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	-16(%rbp), %rcx
	movq	16(%rcx), %rcx
	cmpq	(%rcx), %rax
	je	LBB88_17
## BB#15:
	movq	-160(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -240(%rbp)        ## 8-byte Spill
## BB#16:
	movq	-240(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rdi
	callq	__ZNSt3__118__tree_left_rotateIPNS_16__tree_node_baseIPvEEEEvT_
LBB88_17:
	movq	-160(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -248(%rbp)        ## 8-byte Spill
## BB#18:
	movq	-248(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rcx
	movb	$1, 24(%rcx)
	movq	-160(%rbp), %rcx
	movq	%rcx, -48(%rbp)
	movq	-48(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -256(%rbp)        ## 8-byte Spill
## BB#19:
	movq	-256(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rcx
	movb	$0, 24(%rcx)
	movq	-160(%rbp), %rdi
	callq	__ZNSt3__119__tree_right_rotateIPNS_16__tree_node_baseIPvEEEEvT_
	jmp	LBB88_35
LBB88_20:                               ##   in Loop: Header=BB88_1 Depth=1
	jmp	LBB88_34
LBB88_21:                               ##   in Loop: Header=BB88_1 Depth=1
	movq	-160(%rbp), %rax
	movq	%rax, -64(%rbp)
	movq	-64(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -264(%rbp)        ## 8-byte Spill
## BB#22:                               ##   in Loop: Header=BB88_1 Depth=1
	movq	-264(%rbp), %rax        ## 8-byte Reload
	movq	16(%rax), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -176(%rbp)
	cmpq	$0, -176(%rbp)
	je	LBB88_27
## BB#23:                               ##   in Loop: Header=BB88_1 Depth=1
	movq	-176(%rbp), %rax
	testb	$1, 24(%rax)
	jne	LBB88_27
## BB#24:                               ##   in Loop: Header=BB88_1 Depth=1
	movq	-160(%rbp), %rax
	movq	%rax, -72(%rbp)
	movq	-72(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -272(%rbp)        ## 8-byte Spill
## BB#25:                               ##   in Loop: Header=BB88_1 Depth=1
	movq	-272(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rcx
	movb	$1, 24(%rcx)
	movq	-160(%rbp), %rcx
	movq	%rcx, -80(%rbp)
	movq	-80(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -280(%rbp)        ## 8-byte Spill
## BB#26:                               ##   in Loop: Header=BB88_1 Depth=1
	movq	-280(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rcx
	cmpq	-152(%rbp), %rcx
	sete	%dl
	movq	-160(%rbp), %rcx
	andb	$1, %dl
	movb	%dl, 24(%rcx)
	movq	-176(%rbp), %rcx
	movb	$1, 24(%rcx)
	jmp	LBB88_33
LBB88_27:
	movq	-160(%rbp), %rax
	movq	%rax, -88(%rbp)
	movq	-88(%rbp), %rax
	movq	-88(%rbp), %rcx
	movq	16(%rcx), %rcx
	cmpq	(%rcx), %rax
	jne	LBB88_30
## BB#28:
	movq	-160(%rbp), %rax
	movq	%rax, -96(%rbp)
	movq	-96(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -288(%rbp)        ## 8-byte Spill
## BB#29:
	movq	-288(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rdi
	callq	__ZNSt3__119__tree_right_rotateIPNS_16__tree_node_baseIPvEEEEvT_
LBB88_30:
	movq	-160(%rbp), %rax
	movq	%rax, -112(%rbp)
	movq	-112(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -296(%rbp)        ## 8-byte Spill
## BB#31:
	movq	-296(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rcx
	movb	$1, 24(%rcx)
	movq	-160(%rbp), %rcx
	movq	%rcx, -120(%rbp)
	movq	-120(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -304(%rbp)        ## 8-byte Spill
## BB#32:
	movq	-304(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rcx
	movb	$0, 24(%rcx)
	movq	-160(%rbp), %rdi
	callq	__ZNSt3__118__tree_left_rotateIPNS_16__tree_node_baseIPvEEEEvT_
	jmp	LBB88_35
LBB88_33:                               ##   in Loop: Header=BB88_1 Depth=1
	jmp	LBB88_34
LBB88_34:                               ##   in Loop: Header=BB88_1 Depth=1
	jmp	LBB88_1
LBB88_35:
	addq	$304, %rsp              ## imm = 0x130
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__118__tree_left_rotateIPNS_16__tree_node_baseIPvEEEEvT_
	.weak_definition	__ZNSt3__118__tree_left_rotateIPNS_16__tree_node_baseIPvEEEEvT_
	.p2align	4, 0x90
__ZNSt3__118__tree_left_rotateIPNS_16__tree_node_baseIPvEEEEvT_: ## @_ZNSt3__118__tree_left_rotateIPNS_16__tree_node_baseIPvEEEEvT_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi265:
	.cfi_def_cfa_offset 16
Lcfi266:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi267:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -56(%rbp)
	movq	-56(%rbp), %rdi
	movq	8(%rdi), %rdi
	movq	%rdi, -64(%rbp)
	movq	-64(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-56(%rbp), %rax
	movq	%rdi, 8(%rax)
	movq	-56(%rbp), %rax
	cmpq	$0, 8(%rax)
	je	LBB89_3
## BB#1:
	movq	-56(%rbp), %rax
	movq	8(%rax), %rax
	movq	-56(%rbp), %rcx
	movq	%rax, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	%rcx, 16(%rax)
## BB#2:
	jmp	LBB89_3
LBB89_3:
	movq	-56(%rbp), %rax
	movq	16(%rax), %rax
	movq	-64(%rbp), %rcx
	movq	%rax, 16(%rcx)
	movq	-56(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	-32(%rbp), %rcx
	movq	16(%rcx), %rcx
	cmpq	(%rcx), %rax
	jne	LBB89_5
## BB#4:
	movq	-64(%rbp), %rax
	movq	-56(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rax, (%rcx)
	jmp	LBB89_7
LBB89_5:
	movq	-64(%rbp), %rax
	movq	-56(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rax, -72(%rbp)         ## 8-byte Spill
	movq	%rcx, -80(%rbp)         ## 8-byte Spill
## BB#6:
	movq	-80(%rbp), %rax         ## 8-byte Reload
	movq	-72(%rbp), %rcx         ## 8-byte Reload
	movq	%rcx, 8(%rax)
LBB89_7:
	movq	-56(%rbp), %rax
	movq	-64(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-56(%rbp), %rax
	movq	-64(%rbp), %rcx
	movq	%rax, -16(%rbp)
	movq	%rcx, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	-24(%rbp), %rcx
	movq	%rcx, 16(%rax)
## BB#8:
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__119__tree_right_rotateIPNS_16__tree_node_baseIPvEEEEvT_
	.weak_definition	__ZNSt3__119__tree_right_rotateIPNS_16__tree_node_baseIPvEEEEvT_
	.p2align	4, 0x90
__ZNSt3__119__tree_right_rotateIPNS_16__tree_node_baseIPvEEEEvT_: ## @_ZNSt3__119__tree_right_rotateIPNS_16__tree_node_baseIPvEEEEvT_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi268:
	.cfi_def_cfa_offset 16
Lcfi269:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi270:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -56(%rbp)
	movq	-56(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rdi, -64(%rbp)
	movq	-64(%rbp), %rdi
	movq	8(%rdi), %rdi
	movq	-56(%rbp), %rax
	movq	%rdi, (%rax)
	movq	-56(%rbp), %rax
	cmpq	$0, (%rax)
	je	LBB90_3
## BB#1:
	movq	-56(%rbp), %rax
	movq	(%rax), %rax
	movq	-56(%rbp), %rcx
	movq	%rax, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	%rcx, 16(%rax)
## BB#2:
	jmp	LBB90_3
LBB90_3:
	movq	-56(%rbp), %rax
	movq	16(%rax), %rax
	movq	-64(%rbp), %rcx
	movq	%rax, 16(%rcx)
	movq	-56(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	-32(%rbp), %rcx
	movq	16(%rcx), %rcx
	cmpq	(%rcx), %rax
	jne	LBB90_5
## BB#4:
	movq	-64(%rbp), %rax
	movq	-56(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rax, (%rcx)
	jmp	LBB90_7
LBB90_5:
	movq	-64(%rbp), %rax
	movq	-56(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rax, -72(%rbp)         ## 8-byte Spill
	movq	%rcx, -80(%rbp)         ## 8-byte Spill
## BB#6:
	movq	-80(%rbp), %rax         ## 8-byte Reload
	movq	-72(%rbp), %rcx         ## 8-byte Reload
	movq	%rcx, 8(%rax)
LBB90_7:
	movq	-56(%rbp), %rax
	movq	-64(%rbp), %rcx
	movq	%rax, 8(%rcx)
	movq	-56(%rbp), %rax
	movq	-64(%rbp), %rcx
	movq	%rax, -16(%rbp)
	movq	%rcx, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	-24(%rbp), %rcx
	movq	%rcx, 16(%rax)
## BB#8:
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNKSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE14__count_uniqueIiEEmRKT_
	.weak_definition	__ZNKSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE14__count_uniqueIiEEmRKT_
	.p2align	4, 0x90
__ZNKSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE14__count_uniqueIiEEmRKT_: ## @_ZNKSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE14__count_uniqueIiEEmRKT_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi271:
	.cfi_def_cfa_offset 16
Lcfi272:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi273:
	.cfi_def_cfa_register %rbp
	subq	$56, %rsp
	movq	%rdi, -160(%rbp)
	movq	%rsi, -168(%rbp)
	movq	-160(%rbp), %rsi
	movq	%rsi, -144(%rbp)
	movq	-144(%rbp), %rdi
	movq	%rdi, -136(%rbp)
	movq	-136(%rbp), %rdi
	addq	$8, %rdi
	movq	%rdi, -128(%rbp)
	movq	-128(%rbp), %rdi
	movq	%rdi, -120(%rbp)
	movq	-120(%rbp), %rdi
	movq	%rdi, -112(%rbp)
	movq	-112(%rbp), %rdi
	movq	%rdi, -104(%rbp)
	movq	-104(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rdi, -176(%rbp)
	movq	%rsi, -184(%rbp)        ## 8-byte Spill
LBB91_1:                                ## =>This Inner Loop Header: Depth=1
	cmpq	$0, -176(%rbp)
	je	LBB91_9
## BB#2:                                ##   in Loop: Header=BB91_1 Depth=1
	movq	-184(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rcx
	addq	$16, %rcx
	movq	%rcx, -16(%rbp)
	movq	-16(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	-168(%rbp), %rdx
	movq	-176(%rbp), %rsi
	addq	$28, %rsi
	movq	%rcx, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-40(%rbp), %rcx
	movl	(%rcx), %edi
	movq	-48(%rbp), %rcx
	cmpl	(%rcx), %edi
	jge	LBB91_4
## BB#3:                                ##   in Loop: Header=BB91_1 Depth=1
	movq	-176(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -176(%rbp)
	jmp	LBB91_8
LBB91_4:                                ##   in Loop: Header=BB91_1 Depth=1
	movq	-184(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -72(%rbp)
	movq	-72(%rbp), %rcx
	addq	$16, %rcx
	movq	%rcx, -64(%rbp)
	movq	-64(%rbp), %rcx
	movq	%rcx, -56(%rbp)
	movq	-56(%rbp), %rcx
	movq	-176(%rbp), %rdx
	addq	$28, %rdx
	movq	-168(%rbp), %rsi
	movq	%rcx, -80(%rbp)
	movq	%rdx, -88(%rbp)
	movq	%rsi, -96(%rbp)
	movq	-88(%rbp), %rcx
	movl	(%rcx), %edi
	movq	-96(%rbp), %rcx
	cmpl	(%rcx), %edi
	jge	LBB91_6
## BB#5:                                ##   in Loop: Header=BB91_1 Depth=1
	movq	-176(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -176(%rbp)
	jmp	LBB91_7
LBB91_6:
	movq	$1, -152(%rbp)
	jmp	LBB91_10
LBB91_7:                                ##   in Loop: Header=BB91_1 Depth=1
	jmp	LBB91_8
LBB91_8:                                ##   in Loop: Header=BB91_1 Depth=1
	jmp	LBB91_1
LBB91_9:
	movq	$0, -152(%rbp)
LBB91_10:
	movq	-152(%rbp), %rax
	addq	$56, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE14__erase_uniqueIiEEmRKT_
	.weak_definition	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE14__erase_uniqueIiEEmRKT_
	.p2align	4, 0x90
__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE14__erase_uniqueIiEEmRKT_: ## @_ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE14__erase_uniqueIiEEmRKT_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi274:
	.cfi_def_cfa_offset 16
Lcfi275:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi276:
	.cfi_def_cfa_register %rbp
	subq	$224, %rsp
	movq	%rdi, -152(%rbp)
	movq	%rsi, -160(%rbp)
	movq	-152(%rbp), %rsi
	movq	-160(%rbp), %rdi
	movq	%rdi, -208(%rbp)        ## 8-byte Spill
	movq	%rsi, %rdi
	movq	-208(%rbp), %rax        ## 8-byte Reload
	movq	%rsi, -216(%rbp)        ## 8-byte Spill
	movq	%rax, %rsi
	callq	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE4findIiEENS_15__tree_iteratorIiPNS_11__tree_nodeIiPvEElEERKT_
	leaq	-176(%rbp), %rsi
	leaq	-168(%rbp), %rdi
	leaq	-128(%rbp), %rcx
	movq	%rax, -168(%rbp)
	movq	-216(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -136(%rbp)
	movq	-136(%rbp), %rdx
	movq	%rdx, -120(%rbp)
	movq	-120(%rbp), %rdx
	addq	$8, %rdx
	movq	%rdx, -112(%rbp)
	movq	-112(%rbp), %rdx
	movq	%rdx, -104(%rbp)
	movq	-104(%rbp), %rdx
	movq	%rdx, -96(%rbp)
	movq	-96(%rbp), %rdx
	movq	%rdx, -88(%rbp)
	movq	-88(%rbp), %rdx
	movq	%rcx, -72(%rbp)
	movq	%rdx, -80(%rbp)
	movq	-72(%rbp), %rcx
	movq	-80(%rbp), %rdx
	movq	%rcx, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	-56(%rbp), %rcx
	movq	-64(%rbp), %rdx
	movq	%rdx, (%rcx)
	movq	-128(%rbp), %rcx
	movq	%rcx, -176(%rbp)
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-40(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	-48(%rbp), %rdx
	cmpq	(%rdx), %rcx
	jne	LBB92_2
## BB#1:
	movq	$0, -144(%rbp)
	jmp	LBB92_3
LBB92_2:
	leaq	-184(%rbp), %rax
	movq	-168(%rbp), %rcx
	movq	%rcx, -192(%rbp)
	movq	-192(%rbp), %rcx
	movq	%rcx, -24(%rbp)
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	%rcx, (%rax)
	movq	-184(%rbp), %rsi
	movq	-216(%rbp), %rdi        ## 8-byte Reload
	callq	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE5eraseENS_21__tree_const_iteratorIiPNS_11__tree_nodeIiPvEElEE
	movq	%rax, -200(%rbp)
	movq	$1, -144(%rbp)
LBB92_3:
	movq	-144(%rbp), %rax
	addq	$224, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE4findIiEENS_15__tree_iteratorIiPNS_11__tree_nodeIiPvEElEERKT_
	.weak_definition	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE4findIiEENS_15__tree_iteratorIiPNS_11__tree_nodeIiPvEElEERKT_
	.p2align	4, 0x90
__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE4findIiEENS_15__tree_iteratorIiPNS_11__tree_nodeIiPvEElEERKT_: ## @_ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE4findIiEENS_15__tree_iteratorIiPNS_11__tree_nodeIiPvEElEERKT_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi277:
	.cfi_def_cfa_offset 16
Lcfi278:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi279:
	.cfi_def_cfa_register %rbp
	subq	$432, %rsp              ## imm = 0x1B0
	movq	%rdi, -376(%rbp)
	movq	%rsi, -384(%rbp)
	movq	-376(%rbp), %rsi
	movq	-384(%rbp), %rdi
	movq	%rsi, -360(%rbp)
	movq	-360(%rbp), %rax
	movq	%rax, -352(%rbp)
	movq	-352(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -344(%rbp)
	movq	-344(%rbp), %rax
	movq	%rax, -336(%rbp)
	movq	-336(%rbp), %rax
	movq	%rax, -328(%rbp)
	movq	-328(%rbp), %rax
	movq	%rax, -320(%rbp)
	movq	-320(%rbp), %rax
	movq	(%rax), %rax
	movq	%rsi, -40(%rbp)
	movq	-40(%rbp), %rcx
	addq	$8, %rcx
	movq	%rcx, -32(%rbp)
	movq	-32(%rbp), %rcx
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rcx
	movq	%rcx, -16(%rbp)
	movq	-16(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	%rdi, -408(%rbp)        ## 8-byte Spill
	movq	%rsi, %rdi
	movq	-408(%rbp), %rdx        ## 8-byte Reload
	movq	%rsi, -416(%rbp)        ## 8-byte Spill
	movq	%rdx, %rsi
	movq	%rax, %rdx
	callq	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE13__lower_boundIiEENS_15__tree_iteratorIiPNS_11__tree_nodeIiPvEElEERKT_SB_PNS_15__tree_end_nodeIPNS_16__tree_node_baseIS9_EEEE
	xorl	%r8d, %r8d
	movb	%r8b, %r9b
	leaq	-400(%rbp), %rcx
	leaq	-392(%rbp), %rdx
	leaq	-120(%rbp), %rsi
	movq	%rax, -392(%rbp)
	movq	-416(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -128(%rbp)
	movq	-128(%rbp), %rdi
	movq	%rdi, -112(%rbp)
	movq	-112(%rbp), %rdi
	addq	$8, %rdi
	movq	%rdi, -104(%rbp)
	movq	-104(%rbp), %rdi
	movq	%rdi, -96(%rbp)
	movq	-96(%rbp), %rdi
	movq	%rdi, -88(%rbp)
	movq	-88(%rbp), %rdi
	movq	%rdi, -80(%rbp)
	movq	-80(%rbp), %rdi
	movq	%rsi, -64(%rbp)
	movq	%rdi, -72(%rbp)
	movq	-64(%rbp), %rsi
	movq	-72(%rbp), %rdi
	movq	%rsi, -48(%rbp)
	movq	%rdi, -56(%rbp)
	movq	-48(%rbp), %rsi
	movq	-56(%rbp), %rdi
	movq	%rdi, (%rsi)
	movq	-120(%rbp), %rsi
	movq	%rsi, -400(%rbp)
	movq	%rdx, -152(%rbp)
	movq	%rcx, -160(%rbp)
	movq	-152(%rbp), %rcx
	movq	-160(%rbp), %rdx
	movq	%rcx, -136(%rbp)
	movq	%rdx, -144(%rbp)
	movq	-136(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	-144(%rbp), %rdx
	cmpq	(%rdx), %rcx
	sete	%r10b
	xorb	$-1, %r10b
	testb	$1, %r10b
	movb	%r9b, -417(%rbp)        ## 1-byte Spill
	jne	LBB93_1
	jmp	LBB93_2
LBB93_1:
	leaq	-392(%rbp), %rax
	movq	-416(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -184(%rbp)
	movq	-184(%rbp), %rdx
	addq	$16, %rdx
	movq	%rdx, -176(%rbp)
	movq	-176(%rbp), %rdx
	movq	%rdx, -168(%rbp)
	movq	-168(%rbp), %rdx
	movq	-384(%rbp), %rsi
	movq	%rax, -200(%rbp)
	movq	-200(%rbp), %rax
	movq	%rax, -192(%rbp)
	movq	-192(%rbp), %rax
	movq	(%rax), %rax
	addq	$28, %rax
	movq	%rdx, -208(%rbp)
	movq	%rsi, -216(%rbp)
	movq	%rax, -224(%rbp)
	movq	-216(%rbp), %rax
	movl	(%rax), %edi
	movq	-224(%rbp), %rax
	cmpl	(%rax), %edi
	setl	%r8b
	xorb	$-1, %r8b
	movb	%r8b, -417(%rbp)        ## 1-byte Spill
LBB93_2:
	movb	-417(%rbp), %al         ## 1-byte Reload
	testb	$1, %al
	jne	LBB93_3
	jmp	LBB93_4
LBB93_3:
	movq	-392(%rbp), %rax
	movq	%rax, -368(%rbp)
	jmp	LBB93_5
LBB93_4:
	leaq	-304(%rbp), %rax
	movq	-416(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -312(%rbp)
	movq	-312(%rbp), %rdx
	movq	%rdx, -296(%rbp)
	movq	-296(%rbp), %rdx
	addq	$8, %rdx
	movq	%rdx, -288(%rbp)
	movq	-288(%rbp), %rdx
	movq	%rdx, -280(%rbp)
	movq	-280(%rbp), %rdx
	movq	%rdx, -272(%rbp)
	movq	-272(%rbp), %rdx
	movq	%rdx, -264(%rbp)
	movq	-264(%rbp), %rdx
	movq	%rax, -248(%rbp)
	movq	%rdx, -256(%rbp)
	movq	-248(%rbp), %rax
	movq	-256(%rbp), %rdx
	movq	%rax, -232(%rbp)
	movq	%rdx, -240(%rbp)
	movq	-232(%rbp), %rax
	movq	-240(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-304(%rbp), %rax
	movq	%rax, -368(%rbp)
LBB93_5:
	movq	-368(%rbp), %rax
	addq	$432, %rsp              ## imm = 0x1B0
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE5eraseENS_21__tree_const_iteratorIiPNS_11__tree_nodeIiPvEElEE
	.weak_definition	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE5eraseENS_21__tree_const_iteratorIiPNS_11__tree_nodeIiPvEElEE
	.p2align	4, 0x90
__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE5eraseENS_21__tree_const_iteratorIiPNS_11__tree_nodeIiPvEElEE: ## @_ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE5eraseENS_21__tree_const_iteratorIiPNS_11__tree_nodeIiPvEElEE
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi280:
	.cfi_def_cfa_offset 16
Lcfi281:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi282:
	.cfi_def_cfa_register %rbp
	subq	$384, %rsp              ## imm = 0x180
	leaq	-336(%rbp), %rax
	leaq	-344(%rbp), %rcx
	movq	%rsi, -344(%rbp)
	movq	%rdi, -352(%rbp)
	movq	-352(%rbp), %rsi
	movq	%rcx, -328(%rbp)
	movq	-328(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -360(%rbp)
	movq	-344(%rbp), %rcx
	movq	%rax, -256(%rbp)
	movq	%rcx, -264(%rbp)
	movq	-256(%rbp), %rcx
	movq	-264(%rbp), %rdi
	movq	%rcx, -240(%rbp)
	movq	%rdi, -248(%rbp)
	movq	-240(%rbp), %rcx
	movq	-248(%rbp), %rdi
	movq	%rdi, (%rcx)
	movq	%rax, -152(%rbp)
	movq	-152(%rbp), %rax
	movq	(%rax), %rcx
	movq	%rcx, -144(%rbp)
	movq	-144(%rbp), %rcx
	cmpq	$0, 8(%rcx)
	movq	%rsi, -376(%rbp)        ## 8-byte Spill
	movq	%rax, -384(%rbp)        ## 8-byte Spill
	je	LBB94_5
## BB#1:
	movq	-144(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -128(%rbp)
LBB94_2:                                ## =>This Inner Loop Header: Depth=1
	movq	-128(%rbp), %rax
	cmpq	$0, (%rax)
	je	LBB94_4
## BB#3:                                ##   in Loop: Header=BB94_2 Depth=1
	movq	-128(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -128(%rbp)
	jmp	LBB94_2
LBB94_4:
	movq	-128(%rbp), %rax
	movq	%rax, -136(%rbp)
	jmp	LBB94_9
LBB94_5:
	jmp	LBB94_6
LBB94_6:                                ## =>This Inner Loop Header: Depth=1
	movq	-144(%rbp), %rax
	movq	%rax, -120(%rbp)
	movq	-120(%rbp), %rax
	movq	-120(%rbp), %rcx
	movq	16(%rcx), %rcx
	cmpq	(%rcx), %rax
	sete	%dl
	xorb	$-1, %dl
	testb	$1, %dl
	jne	LBB94_7
	jmp	LBB94_8
LBB94_7:                                ##   in Loop: Header=BB94_6 Depth=1
	movq	-144(%rbp), %rax
	movq	%rax, -112(%rbp)
	movq	-112(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -144(%rbp)
	jmp	LBB94_6
LBB94_8:
	movq	-144(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -136(%rbp)
LBB94_9:
	movq	-136(%rbp), %rax
	movq	-384(%rbp), %rcx        ## 8-byte Reload
	movq	%rax, (%rcx)
	movq	-376(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	(%rdx), %rdx
	cmpq	-344(%rbp), %rdx
	jne	LBB94_11
## BB#10:
	movq	-336(%rbp), %rax
	movq	-376(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	%rax, (%rdx)
LBB94_11:
	movq	-376(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rcx
	addq	$16, %rcx
	movq	%rcx, -32(%rbp)
	movq	-32(%rbp), %rcx
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rcx
	movq	(%rcx), %rdx
	addq	$-1, %rdx
	movq	%rdx, (%rcx)
	movq	%rax, -64(%rbp)
	movq	-64(%rbp), %rcx
	addq	$8, %rcx
	movq	%rcx, -56(%rbp)
	movq	-56(%rbp), %rcx
	movq	%rcx, -48(%rbp)
	movq	-48(%rbp), %rcx
	movq	%rcx, -368(%rbp)
	movq	%rax, -104(%rbp)
	movq	-104(%rbp), %rcx
	addq	$8, %rcx
	movq	%rcx, -96(%rbp)
	movq	-96(%rbp), %rcx
	movq	%rcx, -88(%rbp)
	movq	-88(%rbp), %rcx
	movq	%rcx, -80(%rbp)
	movq	-80(%rbp), %rcx
	movq	%rcx, -72(%rbp)
	movq	-72(%rbp), %rcx
	movq	(%rcx), %rdi
	movq	-360(%rbp), %rcx
	movq	%rcx, %rsi
	callq	__ZNSt3__113__tree_removeIPNS_16__tree_node_baseIPvEEEEvT_S5_
	leaq	-344(%rbp), %rax
	movq	-368(%rbp), %rcx
	movq	%rax, -168(%rbp)
	movq	-168(%rbp), %rax
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rax
	movq	(%rax), %rax
	addq	$28, %rax
	movq	%rax, -184(%rbp)
	movq	-184(%rbp), %rax
	movq	%rax, -176(%rbp)
	movq	-176(%rbp), %rax
	movq	%rcx, -208(%rbp)
	movq	%rax, -216(%rbp)
	movq	-208(%rbp), %rax
	movq	-216(%rbp), %rcx
	movq	%rax, -192(%rbp)
	movq	%rcx, -200(%rbp)
	movq	-368(%rbp), %rax
	movq	-360(%rbp), %rcx
	movq	%rax, -304(%rbp)
	movq	%rcx, -312(%rbp)
	movq	$1, -320(%rbp)
	movq	-304(%rbp), %rax
	movq	-312(%rbp), %rcx
	movq	-320(%rbp), %rdx
	movq	%rax, -280(%rbp)
	movq	%rcx, -288(%rbp)
	movq	%rdx, -296(%rbp)
	movq	-288(%rbp), %rax
	movq	%rax, -272(%rbp)
	movq	-272(%rbp), %rdi
	callq	__ZdlPv
	movq	-336(%rbp), %rax
	addq	$384, %rsp              ## imm = 0x180
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE13__lower_boundIiEENS_15__tree_iteratorIiPNS_11__tree_nodeIiPvEElEERKT_SB_PNS_15__tree_end_nodeIPNS_16__tree_node_baseIS9_EEEE
	.weak_definition	__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE13__lower_boundIiEENS_15__tree_iteratorIiPNS_11__tree_nodeIiPvEElEERKT_SB_PNS_15__tree_end_nodeIPNS_16__tree_node_baseIS9_EEEE
	.p2align	4, 0x90
__ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE13__lower_boundIiEENS_15__tree_iteratorIiPNS_11__tree_nodeIiPvEElEERKT_SB_PNS_15__tree_end_nodeIPNS_16__tree_node_baseIS9_EEEE: ## @_ZNSt3__16__treeIiNS_4lessIiEENS_9allocatorIiEEE13__lower_boundIiEENS_15__tree_iteratorIiPNS_11__tree_nodeIiPvEElEERKT_SB_PNS_15__tree_end_nodeIPNS_16__tree_node_baseIS9_EEEE
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi283:
	.cfi_def_cfa_offset 16
Lcfi284:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi285:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -96(%rbp)
	movq	%rsi, -104(%rbp)
	movq	%rdx, -112(%rbp)
	movq	%rcx, -120(%rbp)
	movq	-96(%rbp), %rcx
	movq	%rcx, -128(%rbp)        ## 8-byte Spill
LBB95_1:                                ## =>This Inner Loop Header: Depth=1
	cmpq	$0, -112(%rbp)
	je	LBB95_6
## BB#2:                                ##   in Loop: Header=BB95_1 Depth=1
	movq	-128(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -80(%rbp)
	movq	-80(%rbp), %rcx
	addq	$16, %rcx
	movq	%rcx, -72(%rbp)
	movq	-72(%rbp), %rcx
	movq	%rcx, -64(%rbp)
	movq	-64(%rbp), %rcx
	movq	-112(%rbp), %rdx
	addq	$28, %rdx
	movq	-104(%rbp), %rsi
	movq	%rcx, -8(%rbp)
	movq	%rdx, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	-16(%rbp), %rcx
	movl	(%rcx), %edi
	movq	-24(%rbp), %rcx
	cmpl	(%rcx), %edi
	jl	LBB95_4
## BB#3:                                ##   in Loop: Header=BB95_1 Depth=1
	movq	-112(%rbp), %rax
	movq	%rax, -120(%rbp)
	movq	-112(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -112(%rbp)
	jmp	LBB95_5
LBB95_4:                                ##   in Loop: Header=BB95_1 Depth=1
	movq	-112(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -112(%rbp)
LBB95_5:                                ##   in Loop: Header=BB95_1 Depth=1
	jmp	LBB95_1
LBB95_6:
	leaq	-88(%rbp), %rax
	movq	-120(%rbp), %rcx
	movq	%rax, -48(%rbp)
	movq	%rcx, -56(%rbp)
	movq	-48(%rbp), %rax
	movq	-56(%rbp), %rcx
	movq	%rax, -32(%rbp)
	movq	%rcx, -40(%rbp)
	movq	-32(%rbp), %rax
	movq	-40(%rbp), %rcx
	movq	%rcx, (%rax)
	movq	-88(%rbp), %rax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__113__tree_removeIPNS_16__tree_node_baseIPvEEEEvT_S5_
	.weak_definition	__ZNSt3__113__tree_removeIPNS_16__tree_node_baseIPvEEEEvT_S5_
	.p2align	4, 0x90
__ZNSt3__113__tree_removeIPNS_16__tree_node_baseIPvEEEEvT_S5_: ## @_ZNSt3__113__tree_removeIPNS_16__tree_node_baseIPvEEEEvT_S5_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi286:
	.cfi_def_cfa_offset 16
Lcfi287:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi288:
	.cfi_def_cfa_register %rbp
	subq	$480, %rsp              ## imm = 0x1E0
	movq	%rdi, -232(%rbp)
	movq	%rsi, -240(%rbp)
	movq	-240(%rbp), %rsi
	cmpq	$0, (%rsi)
	je	LBB96_2
## BB#1:
	movq	-240(%rbp), %rax
	cmpq	$0, 8(%rax)
	jne	LBB96_3
LBB96_2:
	movq	-240(%rbp), %rax
	movq	%rax, -280(%rbp)        ## 8-byte Spill
	jmp	LBB96_4
LBB96_3:
	movq	-240(%rbp), %rdi
	callq	__ZNSt3__111__tree_nextIPNS_16__tree_node_baseIPvEEEET_S5_
	movq	%rax, -280(%rbp)        ## 8-byte Spill
LBB96_4:
	movq	-280(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -248(%rbp)
	movq	-248(%rbp), %rax
	cmpq	$0, (%rax)
	je	LBB96_6
## BB#5:
	movq	-248(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -288(%rbp)        ## 8-byte Spill
	jmp	LBB96_7
LBB96_6:
	movq	-248(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -288(%rbp)        ## 8-byte Spill
LBB96_7:
	movq	-288(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -256(%rbp)
	movq	$0, -264(%rbp)
	cmpq	$0, -256(%rbp)
	je	LBB96_9
## BB#8:
	movq	-248(%rbp), %rax
	movq	16(%rax), %rax
	movq	-256(%rbp), %rcx
	movq	%rax, 16(%rcx)
LBB96_9:
	movq	-248(%rbp), %rax
	movq	%rax, -224(%rbp)
	movq	-224(%rbp), %rax
	movq	-224(%rbp), %rcx
	movq	16(%rcx), %rcx
	cmpq	(%rcx), %rax
	jne	LBB96_15
## BB#10:
	movq	-256(%rbp), %rax
	movq	-248(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rax, (%rcx)
	movq	-248(%rbp), %rax
	cmpq	-232(%rbp), %rax
	je	LBB96_13
## BB#11:
	movq	-248(%rbp), %rax
	movq	%rax, -216(%rbp)
	movq	-216(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -296(%rbp)        ## 8-byte Spill
## BB#12:
	movq	-296(%rbp), %rax        ## 8-byte Reload
	movq	8(%rax), %rcx
	movq	%rcx, -264(%rbp)
	jmp	LBB96_14
LBB96_13:
	movq	-256(%rbp), %rax
	movq	%rax, -232(%rbp)
LBB96_14:
	jmp	LBB96_17
LBB96_15:
	movq	-256(%rbp), %rax
	movq	-248(%rbp), %rcx
	movq	%rcx, -208(%rbp)
	movq	-208(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rax, -304(%rbp)        ## 8-byte Spill
	movq	%rcx, -312(%rbp)        ## 8-byte Spill
## BB#16:
	movq	-312(%rbp), %rax        ## 8-byte Reload
	movq	-304(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, 8(%rax)
	movq	-248(%rbp), %rdx
	movq	16(%rdx), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, -264(%rbp)
LBB96_17:
	movq	-248(%rbp), %rax
	movb	24(%rax), %cl
	andb	$1, %cl
	movb	%cl, -265(%rbp)
	movq	-248(%rbp), %rax
	cmpq	-240(%rbp), %rax
	je	LBB96_29
## BB#18:
	movq	-240(%rbp), %rax
	movq	16(%rax), %rax
	movq	-248(%rbp), %rcx
	movq	%rax, 16(%rcx)
	movq	-240(%rbp), %rax
	movq	%rax, -168(%rbp)
	movq	-168(%rbp), %rax
	movq	-168(%rbp), %rcx
	movq	16(%rcx), %rcx
	cmpq	(%rcx), %rax
	jne	LBB96_20
## BB#19:
	movq	-248(%rbp), %rax
	movq	-248(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rax, (%rcx)
	jmp	LBB96_22
LBB96_20:
	movq	-248(%rbp), %rax
	movq	-248(%rbp), %rcx
	movq	%rcx, -136(%rbp)
	movq	-136(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rax, -320(%rbp)        ## 8-byte Spill
	movq	%rcx, -328(%rbp)        ## 8-byte Spill
## BB#21:
	movq	-328(%rbp), %rax        ## 8-byte Reload
	movq	-320(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, 8(%rax)
LBB96_22:
	movq	-240(%rbp), %rax
	movq	(%rax), %rax
	movq	-248(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-248(%rbp), %rax
	movq	(%rax), %rax
	movq	-248(%rbp), %rcx
	movq	%rax, -104(%rbp)
	movq	%rcx, -112(%rbp)
	movq	-104(%rbp), %rax
	movq	-112(%rbp), %rcx
	movq	%rcx, 16(%rax)
## BB#23:
	movq	-240(%rbp), %rax
	movq	8(%rax), %rax
	movq	-248(%rbp), %rcx
	movq	%rax, 8(%rcx)
	movq	-248(%rbp), %rax
	cmpq	$0, 8(%rax)
	je	LBB96_26
## BB#24:
	movq	-248(%rbp), %rax
	movq	8(%rax), %rax
	movq	-248(%rbp), %rcx
	movq	%rax, -56(%rbp)
	movq	%rcx, -64(%rbp)
	movq	-56(%rbp), %rax
	movq	-64(%rbp), %rcx
	movq	%rcx, 16(%rax)
## BB#25:
	jmp	LBB96_26
LBB96_26:
	movq	-240(%rbp), %rax
	movb	24(%rax), %cl
	movq	-248(%rbp), %rax
	andb	$1, %cl
	movb	%cl, 24(%rax)
	movq	-232(%rbp), %rax
	cmpq	-240(%rbp), %rax
	jne	LBB96_28
## BB#27:
	movq	-248(%rbp), %rax
	movq	%rax, -232(%rbp)
LBB96_28:
	jmp	LBB96_29
LBB96_29:
	testb	$1, -265(%rbp)
	je	LBB96_95
## BB#30:
	cmpq	$0, -232(%rbp)
	je	LBB96_95
## BB#31:
	cmpq	$0, -256(%rbp)
	je	LBB96_33
## BB#32:
	movq	-256(%rbp), %rax
	movb	$1, 24(%rax)
	jmp	LBB96_94
LBB96_33:
	jmp	LBB96_34
LBB96_34:                               ## =>This Inner Loop Header: Depth=1
	jmp	LBB96_35
LBB96_35:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-264(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	-24(%rbp), %rcx
	movq	16(%rcx), %rcx
	cmpq	(%rcx), %rax
	je	LBB96_64
## BB#36:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-264(%rbp), %rax
	testb	$1, 24(%rax)
	jne	LBB96_42
## BB#37:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-264(%rbp), %rax
	movb	$1, 24(%rax)
	movq	-264(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -336(%rbp)        ## 8-byte Spill
## BB#38:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-336(%rbp), %rax        ## 8-byte Reload
	movb	$0, 24(%rax)
	movq	-264(%rbp), %rcx
	movq	%rcx, -16(%rbp)
	movq	-16(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -344(%rbp)        ## 8-byte Spill
## BB#39:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-344(%rbp), %rdi        ## 8-byte Reload
	callq	__ZNSt3__118__tree_left_rotateIPNS_16__tree_node_baseIPvEEEEvT_
	movq	-232(%rbp), %rdi
	movq	-264(%rbp), %rax
	cmpq	(%rax), %rdi
	jne	LBB96_41
## BB#40:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-264(%rbp), %rax
	movq	%rax, -232(%rbp)
LBB96_41:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-264(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rax
	movq	%rax, -264(%rbp)
LBB96_42:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-264(%rbp), %rax
	cmpq	$0, (%rax)
	je	LBB96_44
## BB#43:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-264(%rbp), %rax
	movq	(%rax), %rax
	testb	$1, 24(%rax)
	je	LBB96_55
LBB96_44:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-264(%rbp), %rax
	cmpq	$0, 8(%rax)
	je	LBB96_46
## BB#45:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-264(%rbp), %rax
	movq	8(%rax), %rax
	testb	$1, 24(%rax)
	je	LBB96_55
LBB96_46:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-264(%rbp), %rax
	movb	$0, 24(%rax)
	movq	-264(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -352(%rbp)        ## 8-byte Spill
## BB#47:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-352(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -256(%rbp)
	movq	-256(%rbp), %rcx
	cmpq	-232(%rbp), %rcx
	je	LBB96_49
## BB#48:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-256(%rbp), %rax
	testb	$1, 24(%rax)
	jne	LBB96_50
LBB96_49:
	movq	-256(%rbp), %rax
	movb	$1, 24(%rax)
	jmp	LBB96_93
LBB96_50:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-256(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	-40(%rbp), %rcx
	movq	16(%rcx), %rcx
	cmpq	(%rcx), %rax
	jne	LBB96_53
## BB#51:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-256(%rbp), %rax
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -360(%rbp)        ## 8-byte Spill
## BB#52:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-360(%rbp), %rax        ## 8-byte Reload
	movq	8(%rax), %rcx
	movq	%rcx, -368(%rbp)        ## 8-byte Spill
	jmp	LBB96_54
LBB96_53:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-256(%rbp), %rax
	movq	16(%rax), %rax
	movq	(%rax), %rax
	movq	%rax, -368(%rbp)        ## 8-byte Spill
LBB96_54:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-368(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -264(%rbp)
	jmp	LBB96_63
LBB96_55:
	movq	-264(%rbp), %rax
	cmpq	$0, 8(%rax)
	je	LBB96_57
## BB#56:
	movq	-264(%rbp), %rax
	movq	8(%rax), %rax
	testb	$1, 24(%rax)
	je	LBB96_59
LBB96_57:
	movq	-264(%rbp), %rax
	movq	(%rax), %rax
	movb	$1, 24(%rax)
	movq	-264(%rbp), %rax
	movb	$0, 24(%rax)
	movq	-264(%rbp), %rdi
	callq	__ZNSt3__119__tree_right_rotateIPNS_16__tree_node_baseIPvEEEEvT_
	movq	-264(%rbp), %rax
	movq	%rax, -72(%rbp)
	movq	-72(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -376(%rbp)        ## 8-byte Spill
## BB#58:
	movq	-376(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -264(%rbp)
LBB96_59:
	movq	-264(%rbp), %rax
	movq	%rax, -80(%rbp)
	movq	-80(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -384(%rbp)        ## 8-byte Spill
## BB#60:
	movq	-384(%rbp), %rax        ## 8-byte Reload
	movb	24(%rax), %cl
	movq	-264(%rbp), %rdx
	andb	$1, %cl
	movb	%cl, 24(%rdx)
	movq	-264(%rbp), %rdx
	movq	%rdx, -88(%rbp)
	movq	-88(%rbp), %rdx
	movq	16(%rdx), %rdx
	movq	%rdx, -392(%rbp)        ## 8-byte Spill
## BB#61:
	movq	-392(%rbp), %rax        ## 8-byte Reload
	movb	$1, 24(%rax)
	movq	-264(%rbp), %rcx
	movq	8(%rcx), %rcx
	movb	$1, 24(%rcx)
	movq	-264(%rbp), %rcx
	movq	%rcx, -96(%rbp)
	movq	-96(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -400(%rbp)        ## 8-byte Spill
## BB#62:
	movq	-400(%rbp), %rdi        ## 8-byte Reload
	callq	__ZNSt3__118__tree_left_rotateIPNS_16__tree_node_baseIPvEEEEvT_
	jmp	LBB96_93
LBB96_63:                               ##   in Loop: Header=BB96_34 Depth=1
	jmp	LBB96_92
LBB96_64:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-264(%rbp), %rax
	testb	$1, 24(%rax)
	jne	LBB96_70
## BB#65:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-264(%rbp), %rax
	movb	$1, 24(%rax)
	movq	-264(%rbp), %rax
	movq	%rax, -120(%rbp)
	movq	-120(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -408(%rbp)        ## 8-byte Spill
## BB#66:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-408(%rbp), %rax        ## 8-byte Reload
	movb	$0, 24(%rax)
	movq	-264(%rbp), %rcx
	movq	%rcx, -128(%rbp)
	movq	-128(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -416(%rbp)        ## 8-byte Spill
## BB#67:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-416(%rbp), %rdi        ## 8-byte Reload
	callq	__ZNSt3__119__tree_right_rotateIPNS_16__tree_node_baseIPvEEEEvT_
	movq	-232(%rbp), %rdi
	movq	-264(%rbp), %rax
	cmpq	8(%rax), %rdi
	jne	LBB96_69
## BB#68:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-264(%rbp), %rax
	movq	%rax, -232(%rbp)
LBB96_69:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-264(%rbp), %rax
	movq	8(%rax), %rax
	movq	(%rax), %rax
	movq	%rax, -264(%rbp)
LBB96_70:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-264(%rbp), %rax
	cmpq	$0, (%rax)
	je	LBB96_72
## BB#71:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-264(%rbp), %rax
	movq	(%rax), %rax
	testb	$1, 24(%rax)
	je	LBB96_83
LBB96_72:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-264(%rbp), %rax
	cmpq	$0, 8(%rax)
	je	LBB96_74
## BB#73:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-264(%rbp), %rax
	movq	8(%rax), %rax
	testb	$1, 24(%rax)
	je	LBB96_83
LBB96_74:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-264(%rbp), %rax
	movb	$0, 24(%rax)
	movq	-264(%rbp), %rax
	movq	%rax, -144(%rbp)
	movq	-144(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -424(%rbp)        ## 8-byte Spill
## BB#75:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-424(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -256(%rbp)
	movq	-256(%rbp), %rcx
	testb	$1, 24(%rcx)
	je	LBB96_77
## BB#76:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-256(%rbp), %rax
	cmpq	-232(%rbp), %rax
	jne	LBB96_78
LBB96_77:
	movq	-256(%rbp), %rax
	movb	$1, 24(%rax)
	jmp	LBB96_93
LBB96_78:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-256(%rbp), %rax
	movq	%rax, -152(%rbp)
	movq	-152(%rbp), %rax
	movq	-152(%rbp), %rcx
	movq	16(%rcx), %rcx
	cmpq	(%rcx), %rax
	jne	LBB96_81
## BB#79:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-256(%rbp), %rax
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -432(%rbp)        ## 8-byte Spill
## BB#80:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-432(%rbp), %rax        ## 8-byte Reload
	movq	8(%rax), %rcx
	movq	%rcx, -440(%rbp)        ## 8-byte Spill
	jmp	LBB96_82
LBB96_81:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-256(%rbp), %rax
	movq	16(%rax), %rax
	movq	(%rax), %rax
	movq	%rax, -440(%rbp)        ## 8-byte Spill
LBB96_82:                               ##   in Loop: Header=BB96_34 Depth=1
	movq	-440(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -264(%rbp)
	jmp	LBB96_91
LBB96_83:
	movq	-264(%rbp), %rax
	cmpq	$0, (%rax)
	je	LBB96_85
## BB#84:
	movq	-264(%rbp), %rax
	movq	(%rax), %rax
	testb	$1, 24(%rax)
	je	LBB96_87
LBB96_85:
	movq	-264(%rbp), %rax
	movq	8(%rax), %rax
	movb	$1, 24(%rax)
	movq	-264(%rbp), %rax
	movb	$0, 24(%rax)
	movq	-264(%rbp), %rdi
	callq	__ZNSt3__118__tree_left_rotateIPNS_16__tree_node_baseIPvEEEEvT_
	movq	-264(%rbp), %rax
	movq	%rax, -176(%rbp)
	movq	-176(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -448(%rbp)        ## 8-byte Spill
## BB#86:
	movq	-448(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -264(%rbp)
LBB96_87:
	movq	-264(%rbp), %rax
	movq	%rax, -184(%rbp)
	movq	-184(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -456(%rbp)        ## 8-byte Spill
## BB#88:
	movq	-456(%rbp), %rax        ## 8-byte Reload
	movb	24(%rax), %cl
	movq	-264(%rbp), %rdx
	andb	$1, %cl
	movb	%cl, 24(%rdx)
	movq	-264(%rbp), %rdx
	movq	%rdx, -192(%rbp)
	movq	-192(%rbp), %rdx
	movq	16(%rdx), %rdx
	movq	%rdx, -464(%rbp)        ## 8-byte Spill
## BB#89:
	movq	-464(%rbp), %rax        ## 8-byte Reload
	movb	$1, 24(%rax)
	movq	-264(%rbp), %rcx
	movq	(%rcx), %rcx
	movb	$1, 24(%rcx)
	movq	-264(%rbp), %rcx
	movq	%rcx, -200(%rbp)
	movq	-200(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -472(%rbp)        ## 8-byte Spill
## BB#90:
	movq	-472(%rbp), %rdi        ## 8-byte Reload
	callq	__ZNSt3__119__tree_right_rotateIPNS_16__tree_node_baseIPvEEEEvT_
	jmp	LBB96_93
LBB96_91:                               ##   in Loop: Header=BB96_34 Depth=1
	jmp	LBB96_92
LBB96_92:                               ##   in Loop: Header=BB96_34 Depth=1
	jmp	LBB96_34
LBB96_93:
	jmp	LBB96_94
LBB96_94:
	jmp	LBB96_95
LBB96_95:
	addq	$480, %rsp              ## imm = 0x1E0
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__111__tree_nextIPNS_16__tree_node_baseIPvEEEET_S5_
	.weak_definition	__ZNSt3__111__tree_nextIPNS_16__tree_node_baseIPvEEEET_S5_
	.p2align	4, 0x90
__ZNSt3__111__tree_nextIPNS_16__tree_node_baseIPvEEEET_S5_: ## @_ZNSt3__111__tree_nextIPNS_16__tree_node_baseIPvEEEET_S5_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi289:
	.cfi_def_cfa_offset 16
Lcfi290:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi291:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -48(%rbp)
	movq	-48(%rbp), %rdi
	cmpq	$0, 8(%rdi)
	je	LBB97_5
## BB#1:
	movq	-48(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -32(%rbp)
LBB97_2:                                ## =>This Inner Loop Header: Depth=1
	movq	-32(%rbp), %rax
	cmpq	$0, (%rax)
	je	LBB97_4
## BB#3:                                ##   in Loop: Header=BB97_2 Depth=1
	movq	-32(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -32(%rbp)
	jmp	LBB97_2
LBB97_4:
	movq	-32(%rbp), %rax
	movq	%rax, -40(%rbp)
	jmp	LBB97_11
LBB97_5:
	jmp	LBB97_6
LBB97_6:                                ## =>This Inner Loop Header: Depth=1
	movq	-48(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	-24(%rbp), %rcx
	movq	16(%rcx), %rcx
	cmpq	(%rcx), %rax
	sete	%dl
	xorb	$-1, %dl
	testb	$1, %dl
	jne	LBB97_7
	jmp	LBB97_9
LBB97_7:                                ##   in Loop: Header=BB97_6 Depth=1
	movq	-48(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -56(%rbp)         ## 8-byte Spill
## BB#8:                                ##   in Loop: Header=BB97_6 Depth=1
	movq	-56(%rbp), %rax         ## 8-byte Reload
	movq	%rax, -48(%rbp)
	jmp	LBB97_6
LBB97_9:
	movq	-48(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -64(%rbp)         ## 8-byte Spill
## BB#10:
	movq	-64(%rbp), %rax         ## 8-byte Reload
	movq	%rax, -40(%rbp)
LBB97_11:
	movq	-40(%rbp), %rax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa8skiplistIiiE8__searchERi
	.weak_definition	__ZN3dsa8skiplistIiiE8__searchERi
	.p2align	4, 0x90
__ZN3dsa8skiplistIiiE8__searchERi:      ## @_ZN3dsa8skiplistIiiE8__searchERi
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi292:
	.cfi_def_cfa_offset 16
Lcfi293:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi294:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rsi
	movq	32(%rsi), %rdi
	movq	%rdi, 48(%rsi)
	movq	(%rsi), %rdi
	movl	%edi, %eax
	movl	%eax, -20(%rbp)
	movq	%rsi, -32(%rbp)         ## 8-byte Spill
LBB98_1:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB98_3 Depth 2
	cmpl	$0, -20(%rbp)
	jl	LBB98_7
## BB#2:                                ##   in Loop: Header=BB98_1 Depth=1
	jmp	LBB98_3
LBB98_3:                                ##   Parent Loop BB98_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	48(%rax), %rcx
	movq	16(%rcx), %rcx
	movslq	-20(%rbp), %rdx
	movq	(%rcx,%rdx,8), %rcx
	movl	(%rcx), %esi
	movq	-16(%rbp), %rcx
	cmpl	(%rcx), %esi
	jge	LBB98_5
## BB#4:                                ##   in Loop: Header=BB98_3 Depth=2
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	48(%rax), %rcx
	movq	16(%rcx), %rcx
	movslq	-20(%rbp), %rdx
	movq	(%rcx,%rdx,8), %rcx
	movq	%rcx, 48(%rax)
	jmp	LBB98_3
LBB98_5:                                ##   in Loop: Header=BB98_1 Depth=1
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	48(%rax), %rcx
	movq	56(%rax), %rdx
	movslq	-20(%rbp), %rsi
	movq	%rcx, (%rdx,%rsi,8)
## BB#6:                                ##   in Loop: Header=BB98_1 Depth=1
	movl	-20(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -20(%rbp)
	jmp	LBB98_1
LBB98_7:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	48(%rax), %rcx
	movq	16(%rcx), %rcx
	movq	(%rcx), %rax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa8skiplistIiiE14__decide_levelEv
	.weak_definition	__ZN3dsa8skiplistIiiE14__decide_levelEv
	.p2align	4, 0x90
__ZN3dsa8skiplistIiiE14__decide_levelEv: ## @_ZN3dsa8skiplistIiiE14__decide_levelEv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi295:
	.cfi_def_cfa_offset 16
Lcfi296:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi297:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	$0, -16(%rbp)
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
LBB99_1:                                ## =>This Inner Loop Header: Depth=1
	callq	_rand
	andl	$1, %eax
	cmpl	$0, %eax
	je	LBB99_3
## BB#2:                                ##   in Loop: Header=BB99_1 Depth=1
	movq	-16(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -16(%rbp)
	jmp	LBB99_1
LBB99_3:
	movq	-16(%rbp), %rax
	movq	-24(%rbp), %rcx         ## 8-byte Reload
	cmpq	16(%rcx), %rax
	ja	LBB99_5
## BB#4:
	movq	-16(%rbp), %rax
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	jmp	LBB99_6
LBB99_5:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	movq	16(%rax), %rcx
	movq	%rcx, -32(%rbp)         ## 8-byte Spill
LBB99_6:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN3dsa8skiplistIiiE3getERi
	.weak_definition	__ZN3dsa8skiplistIiiE3getERi
	.p2align	4, 0x90
__ZN3dsa8skiplistIiiE3getERi:           ## @_ZN3dsa8skiplistIiiE3getERi
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi298:
	.cfi_def_cfa_offset 16
Lcfi299:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi300:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	-16(%rbp), %rsi
	movq	-24(%rbp), %rdi
	movl	(%rdi), %eax
	cmpl	24(%rsi), %eax
	movq	%rsi, -40(%rbp)         ## 8-byte Spill
	jl	LBB100_2
## BB#1:
	movq	$0, -8(%rbp)
	jmp	LBB100_12
LBB100_2:
	movq	-40(%rbp), %rax         ## 8-byte Reload
	movq	32(%rax), %rcx
	movq	%rcx, 48(%rax)
	movq	(%rax), %rcx
	movl	%ecx, %edx
	movl	%edx, -28(%rbp)
LBB100_3:                               ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB100_5 Depth 2
	cmpl	$0, -28(%rbp)
	jl	LBB100_9
## BB#4:                                ##   in Loop: Header=BB100_3 Depth=1
	jmp	LBB100_5
LBB100_5:                               ##   Parent Loop BB100_3 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	-40(%rbp), %rax         ## 8-byte Reload
	movq	48(%rax), %rcx
	movq	16(%rcx), %rcx
	movslq	-28(%rbp), %rdx
	movq	(%rcx,%rdx,8), %rcx
	movl	(%rcx), %esi
	movq	-24(%rbp), %rcx
	cmpl	(%rcx), %esi
	jge	LBB100_7
## BB#6:                                ##   in Loop: Header=BB100_5 Depth=2
	movq	-40(%rbp), %rax         ## 8-byte Reload
	movq	48(%rax), %rcx
	movq	16(%rcx), %rcx
	movslq	-28(%rbp), %rdx
	movq	(%rcx,%rdx,8), %rcx
	movq	%rcx, 48(%rax)
	jmp	LBB100_5
LBB100_7:                               ##   in Loop: Header=BB100_3 Depth=1
	jmp	LBB100_8
LBB100_8:                               ##   in Loop: Header=BB100_3 Depth=1
	movl	-28(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -28(%rbp)
	jmp	LBB100_3
LBB100_9:
	movq	-40(%rbp), %rax         ## 8-byte Reload
	movq	48(%rax), %rcx
	movq	16(%rcx), %rcx
	movq	(%rcx), %rcx
	movl	(%rcx), %edx
	movq	-24(%rbp), %rcx
	cmpl	(%rcx), %edx
	jne	LBB100_11
## BB#10:
	movq	-40(%rbp), %rax         ## 8-byte Reload
	movq	48(%rax), %rcx
	movq	16(%rcx), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -8(%rbp)
	jmp	LBB100_12
LBB100_11:
	movq	$0, -8(%rbp)
LBB100_12:
	movq	-8(%rbp), %rax
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__StaticInit,regular,pure_instructions
	.p2align	4, 0x90
__GLOBAL__sub_I_skiplist.cpp:           ## @_GLOBAL__sub_I_skiplist.cpp
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi301:
	.cfi_def_cfa_offset 16
Lcfi302:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi303:
	.cfi_def_cfa_register %rbp
	callq	___cxx_global_var_init
	callq	___cxx_global_var_init.1
	callq	___cxx_global_var_init.2
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_sk                     ## @sk
.zerofill __DATA,__common,_sk,64,3
	.globl	_st                     ## @st
.zerofill __DATA,__common,_st,24,3
	.globl	_p                      ## @p
.zerofill __DATA,__common,_p,8,2
	.globl	_startTime              ## @startTime
.zerofill __DATA,__common,_startTime,8,3
	.globl	_endTime                ## @endTime
.zerofill __DATA,__common,_endTime,8,3
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"The Test Case's Data Size is -> "

L_.str.3:                               ## @.str.3
	.asciz	", The Data is "

L_.str.4:                               ## @.str.4
	.asciz	"sorted"

L_.str.5:                               ## @.str.5
	.asciz	"random"

L_.str.6:                               ## @.str.6
	.asciz	"Iteration is -> "

L_.str.7:                               ## @.str.7
	.asciz	"The average insert time for rbtree is: "

L_.str.8:                               ## @.str.8
	.asciz	"ms"

L_.str.9:                               ## @.str.9
	.asciz	"The average count time for rbtree is: "

L_.str.10:                              ## @.str.10
	.asciz	"The average erase time for rbtree is: "

L_.str.11:                              ## @.str.11
	.asciz	"The average insert time for skiplist is: "

L_.str.12:                              ## @.str.12
	.asciz	"The average count time for skiplist is: "

L_.str.13:                              ## @.str.13
	.asciz	"The average erase time for skiplist is: "

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

	.section	__TEXT,__cstring,cstring_literals
L_.str.15:                              ## @.str.15
	.asciz	"allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size"

	.section	__DATA,__mod_init_func,mod_init_funcs
	.p2align	3
	.quad	__GLOBAL__sub_I_skiplist.cpp

.subsections_via_symbols
