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
	movl	$10000000, %edi         ## imm = 0x989680
	movl	%edi, %edx
	leaq	-88(%rbp), %rdi
	movl	$2147483647, %esi       ## imm = 0x7FFFFFFF
	callq	__ZN3dsa8skiplistIiiEC1Eim
	movl	$1, -100(%rbp)
	movl	$1, -104(%rbp)
Ltmp0:
	leaq	-96(%rbp), %rdi
	leaq	-100(%rbp), %rsi
	leaq	-104(%rbp), %rdx
	callq	__ZN3dsa4pairIiiEC1ERKiS3_
Ltmp1:
	jmp	LBB0_1
LBB0_1:
	movq	-96(%rbp), %rsi
Ltmp2:
	leaq	-88(%rbp), %rdi
	callq	__ZN3dsa8skiplistIiiE6insertENS_4pairIiiEE
Ltmp3:
	jmp	LBB0_2
LBB0_2:
	leaq	-88(%rbp), %rdi
	movl	$0, -4(%rbp)
	callq	__ZN3dsa8skiplistIiiED1Ev
	movl	-4(%rbp), %eax
	addq	$128, %rsp
	popq	%rbp
	retq
LBB0_3:
Ltmp4:
	leaq	-88(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -112(%rbp)
	movl	%ecx, -116(%rbp)
	callq	__ZN3dsa8skiplistIiiED1Ev
## BB#4:
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
Lset3 = Ltmp3-Ltmp0                     ##   Call between Ltmp0 and Ltmp3
	.long	Lset3
Lset4 = Ltmp4-Lfunc_begin0              ##     jumps to Ltmp4
	.long	Lset4
	.byte	0                       ##   On action: cleanup
Lset5 = Ltmp3-Lfunc_begin0              ## >> Call Site 3 <<
	.long	Lset5
Lset6 = Lfunc_end0-Ltmp3                ##   Call between Ltmp3 and Lfunc_end0
	.long	Lset6
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

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

	.globl	__ZN3dsa8skiplistIiiE6insertENS_4pairIiiEE
	.weak_definition	__ZN3dsa8skiplistIiiE6insertENS_4pairIiiEE
	.p2align	4, 0x90
__ZN3dsa8skiplistIiiE6insertENS_4pairIiiEE: ## @_ZN3dsa8skiplistIiiE6insertENS_4pairIiiEE
Lfunc_begin1:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception1
## BB#0:
	pushq	%rbp
Lcfi6:
	.cfi_def_cfa_offset 16
Lcfi7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi8:
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movq	%rsi, -8(%rbp)
	movq	%rdi, -16(%rbp)
	movq	-16(%rbp), %rsi
	movl	-8(%rbp), %eax
	cmpl	24(%rsi), %eax
	movq	%rsi, -64(%rbp)         ## 8-byte Spill
	jl	LBB2_2
## BB#1:
	jmp	LBB2_12
LBB2_2:
	leaq	-8(%rbp), %rsi
	movq	-64(%rbp), %rdi         ## 8-byte Reload
	callq	__ZN3dsa8skiplistIiiE8__searchERi
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %ecx
	cmpl	-8(%rbp), %ecx
	jne	LBB2_4
## BB#3:
	movl	-4(%rbp), %eax
	movq	-24(%rbp), %rcx
	movl	%eax, 4(%rcx)
	jmp	LBB2_12
LBB2_4:
	movq	-64(%rbp), %rdi         ## 8-byte Reload
	callq	__ZN3dsa8skiplistIiiE14__decide_levelEv
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	-64(%rbp), %rdi         ## 8-byte Reload
	cmpq	(%rdi), %rax
	jbe	LBB2_6
## BB#5:
	movq	-64(%rbp), %rax         ## 8-byte Reload
	movq	(%rax), %rcx
	addq	$1, %rcx
	movq	%rcx, (%rax)
	movq	%rcx, -32(%rbp)
	movq	32(%rax), %rcx
	movq	64(%rax), %rdx
	movq	-32(%rbp), %rsi
	movq	%rcx, (%rdx,%rsi,8)
LBB2_6:
	movl	$24, %eax
	movl	%eax, %edi
	callq	__Znwm
	movq	%rax, %rdi
	movq	%rax, %rcx
	movl	-32(%rbp), %edx
	incl	%edx
Ltmp5:
	leaq	-8(%rbp), %rsi
	movq	%rdi, -72(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rcx, -80(%rbp)         ## 8-byte Spill
	callq	__ZN3dsa15__skiplist_nodeIiiEC1ERNS_4pairIiiEEi
Ltmp6:
	jmp	LBB2_7
LBB2_7:
	movq	-80(%rbp), %rax         ## 8-byte Reload
	movq	%rax, -40(%rbp)
	movq	-64(%rbp), %rcx         ## 8-byte Reload
	movq	8(%rcx), %rdx
	addq	$1, %rdx
	movq	%rdx, 8(%rcx)
	movl	$0, -56(%rbp)
LBB2_8:                                 ## =>This Inner Loop Header: Depth=1
	movslq	-56(%rbp), %rax
	cmpq	-32(%rbp), %rax
	ja	LBB2_12
## BB#9:                                ##   in Loop: Header=BB2_8 Depth=1
	movq	-64(%rbp), %rax         ## 8-byte Reload
	movq	64(%rax), %rcx
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
	movq	64(%rax), %rdx
	movslq	-56(%rbp), %rsi
	movq	(%rdx,%rsi,8), %rdx
	movq	16(%rdx), %rdx
	movslq	-56(%rbp), %rsi
	movq	%rcx, (%rdx,%rsi,8)
## BB#10:                               ##   in Loop: Header=BB2_8 Depth=1
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	jmp	LBB2_8
LBB2_11:
Ltmp7:
	movl	%edx, %ecx
	movq	%rax, -48(%rbp)
	movl	%ecx, -52(%rbp)
	movq	-72(%rbp), %rdi         ## 8-byte Reload
	callq	__ZdlPv
	jmp	LBB2_13
LBB2_12:
	addq	$80, %rsp
	popq	%rbp
	retq
LBB2_13:
	movq	-48(%rbp), %rdi
	callq	__Unwind_Resume
Lfunc_end1:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table2:
Lexception1:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset7 = Lfunc_begin1-Lfunc_begin1       ## >> Call Site 1 <<
	.long	Lset7
Lset8 = Ltmp5-Lfunc_begin1              ##   Call between Lfunc_begin1 and Ltmp5
	.long	Lset8
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset9 = Ltmp5-Lfunc_begin1              ## >> Call Site 2 <<
	.long	Lset9
Lset10 = Ltmp6-Ltmp5                    ##   Call between Ltmp5 and Ltmp6
	.long	Lset10
Lset11 = Ltmp7-Lfunc_begin1             ##     jumps to Ltmp7
	.long	Lset11
	.byte	0                       ##   On action: cleanup
Lset12 = Ltmp6-Lfunc_begin1             ## >> Call Site 3 <<
	.long	Lset12
Lset13 = Lfunc_end1-Ltmp6               ##   Call between Ltmp6 and Lfunc_end1
	.long	Lset13
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN3dsa4pairIiiEC1ERKiS3_
	.weak_def_can_be_hidden	__ZN3dsa4pairIiiEC1ERKiS3_
	.p2align	4, 0x90
__ZN3dsa4pairIiiEC1ERKiS3_:             ## @_ZN3dsa4pairIiiEC1ERKiS3_
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

	.globl	__ZN3dsa8skiplistIiiED1Ev
	.weak_def_can_be_hidden	__ZN3dsa8skiplistIiiED1Ev
	.p2align	4, 0x90
__ZN3dsa8skiplistIiiED1Ev:              ## @_ZN3dsa8skiplistIiiED1Ev
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
	callq	__ZN3dsa8skiplistIiiED2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__literal16,16byte_literals
	.p2align	4
LCPI5_0:
	.long	1127219200              ## 0x43300000
	.long	1160773632              ## 0x45300000
	.long	0                       ## 0x0
	.long	0                       ## 0x0
LCPI5_1:
	.quad	4841369599423283200     ## double 4503599627370496
	.quad	4985484787499139072     ## double 1.9342813113834067E+25
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3
LCPI5_2:
	.quad	4890909195324358656     ## double 9.2233720368547758E+18
	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN3dsa8skiplistIiiEC2Eim
	.weak_def_can_be_hidden	__ZN3dsa8skiplistIiiEC2Eim
	.p2align	4, 0x90
__ZN3dsa8skiplistIiiEC2Eim:             ## @_ZN3dsa8skiplistIiiEC2Eim
Lfunc_begin2:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception2
## BB#0:
	pushq	%rbp
Lcfi15:
	.cfi_def_cfa_offset 16
Lcfi16:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi17:
	.cfi_def_cfa_register %rbp
	subq	$144, %rsp
	movq	%rdi, -16(%rbp)
	movl	%esi, -20(%rbp)
	movq	%rdx, -32(%rbp)
	movq	-16(%rbp), %rdx
	movq	-32(%rbp), %rdi
	movq	%rdi, -8(%rbp)
	movaps	LCPI5_0(%rip), %xmm0    ## xmm0 = [1127219200,1160773632,0,0]
	movq	-8(%rbp), %xmm1         ## xmm1 = mem[0],zero
	punpckldq	%xmm0, %xmm1    ## xmm1 = xmm1[0],xmm0[0],xmm1[1],xmm0[1]
	movapd	LCPI5_1(%rip), %xmm0    ## xmm0 = [4.503600e+15,1.934281e+25]
	subpd	%xmm0, %xmm1
	haddpd	%xmm1, %xmm1
	movaps	%xmm1, %xmm0
	movq	%rdx, -64(%rbp)         ## 8-byte Spill
	callq	_log2
	roundsd	$10, %xmm0, %xmm0
	movsd	LCPI5_2(%rip), %xmm1    ## xmm1 = mem[0],zero
	movaps	%xmm0, %xmm2
	subsd	%xmm1, %xmm2
	cvttsd2si	%xmm2, %rdx
	movabsq	$-9223372036854775808, %rdi ## imm = 0x8000000000000000
	xorq	%rdi, %rdx
	cvttsd2si	%xmm0, %rdi
	ucomisd	%xmm1, %xmm0
	cmovbq	%rdi, %rdx
	decq	%rdx
	movq	-64(%rbp), %rdi         ## 8-byte Reload
	movq	%rdx, 16(%rdi)
	movq	$0, 8(%rdi)
	movq	$0, (%rdi)
	movl	-20(%rbp), %esi
	movl	%esi, 24(%rdi)
	leaq	-40(%rbp), %rdx
	movq	%rdx, %rdi
	movq	%rdx, -72(%rbp)         ## 8-byte Spill
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
Ltmp8:
	movq	%rdi, -80(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	-72(%rbp), %rax         ## 8-byte Reload
	movl	%esi, -84(%rbp)         ## 4-byte Spill
	movq	%rax, %rsi
	movl	-84(%rbp), %r8d         ## 4-byte Reload
	movq	%rdx, -96(%rbp)         ## 8-byte Spill
	movl	%r8d, %edx
	callq	__ZN3dsa15__skiplist_nodeIiiEC1ERNS_4pairIiiEEi
Ltmp9:
	jmp	LBB5_1
LBB5_1:
	movq	-64(%rbp), %rax         ## 8-byte Reload
	movq	-80(%rbp), %rcx         ## 8-byte Reload
	movq	%rcx, 32(%rax)
	movl	$24, %edx
	movl	%edx, %edi
	callq	__Znwm
	movq	%rax, %rcx
	movq	%rax, %rdi
Ltmp11:
	leaq	-40(%rbp), %rsi
	xorl	%edx, %edx
	movq	%rdi, -104(%rbp)        ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rcx, -112(%rbp)        ## 8-byte Spill
	callq	__ZN3dsa15__skiplist_nodeIiiEC1ERNS_4pairIiiEEi
Ltmp12:
	jmp	LBB5_2
LBB5_2:
	movq	$-1, %rax
	movl	$8, %ecx
	movl	%ecx, %edx
	movq	-64(%rbp), %rsi         ## 8-byte Reload
	movq	-104(%rbp), %rdi        ## 8-byte Reload
	movq	%rdi, 40(%rsi)
	movq	16(%rsi), %r8
	addq	$1, %r8
	movq	%rax, -120(%rbp)        ## 8-byte Spill
	movq	%r8, %rax
	mulq	%rdx
	seto	%r9b
	movq	-120(%rbp), %r8         ## 8-byte Reload
	cmovoq	%r8, %rax
	movq	%rax, %rdi
	movb	%r9b, -121(%rbp)        ## 1-byte Spill
	callq	__Znam
	movq	-64(%rbp), %rsi         ## 8-byte Reload
	movq	%rax, 64(%rsi)
	movq	32(%rsi), %rax
	movq	16(%rax), %rdi
	movq	32(%rsi), %rax
	movq	16(%rax), %rax
	movq	16(%rsi), %r8
	shlq	$3, %r8
	addq	%r8, %rax
	addq	$8, %rax
	addq	$40, %rsi
	movq	%rsi, -136(%rbp)        ## 8-byte Spill
	movq	%rax, %rsi
	movq	-136(%rbp), %rax        ## 8-byte Reload
	movq	%rax, %rdx
	callq	__ZN3dsa4fillIPPNS_15__skiplist_nodeIiiEES3_EEvT_S5_RKT0_
	addq	$144, %rsp
	popq	%rbp
	retq
LBB5_3:
Ltmp10:
	movl	%edx, %ecx
	movq	%rax, -48(%rbp)
	movl	%ecx, -52(%rbp)
	movq	-96(%rbp), %rdi         ## 8-byte Reload
	callq	__ZdlPv
	jmp	LBB5_5
LBB5_4:
Ltmp13:
	movl	%edx, %ecx
	movq	%rax, -48(%rbp)
	movl	%ecx, -52(%rbp)
	movq	-112(%rbp), %rdi        ## 8-byte Reload
	callq	__ZdlPv
LBB5_5:
	movq	-48(%rbp), %rdi
	callq	__Unwind_Resume
Lfunc_end2:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table5:
Lexception2:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.asciz	"\303\200"              ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	65                      ## Call site table length
Lset14 = Lfunc_begin2-Lfunc_begin2      ## >> Call Site 1 <<
	.long	Lset14
Lset15 = Ltmp8-Lfunc_begin2             ##   Call between Lfunc_begin2 and Ltmp8
	.long	Lset15
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset16 = Ltmp8-Lfunc_begin2             ## >> Call Site 2 <<
	.long	Lset16
Lset17 = Ltmp9-Ltmp8                    ##   Call between Ltmp8 and Ltmp9
	.long	Lset17
Lset18 = Ltmp10-Lfunc_begin2            ##     jumps to Ltmp10
	.long	Lset18
	.byte	0                       ##   On action: cleanup
Lset19 = Ltmp9-Lfunc_begin2             ## >> Call Site 3 <<
	.long	Lset19
Lset20 = Ltmp11-Ltmp9                   ##   Call between Ltmp9 and Ltmp11
	.long	Lset20
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset21 = Ltmp11-Lfunc_begin2            ## >> Call Site 4 <<
	.long	Lset21
Lset22 = Ltmp12-Ltmp11                  ##   Call between Ltmp11 and Ltmp12
	.long	Lset22
Lset23 = Ltmp13-Lfunc_begin2            ##     jumps to Ltmp13
	.long	Lset23
	.byte	0                       ##   On action: cleanup
Lset24 = Ltmp12-Lfunc_begin2            ## >> Call Site 5 <<
	.long	Lset24
Lset25 = Lfunc_end2-Ltmp12              ##   Call between Ltmp12 and Lfunc_end2
	.long	Lset25
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

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

	.globl	__ZN3dsa15__skiplist_nodeIiiEC1ERNS_4pairIiiEEi
	.weak_def_can_be_hidden	__ZN3dsa15__skiplist_nodeIiiEC1ERNS_4pairIiiEEi
	.p2align	4, 0x90
__ZN3dsa15__skiplist_nodeIiiEC1ERNS_4pairIiiEEi: ## @_ZN3dsa15__skiplist_nodeIiiEC1ERNS_4pairIiiEEi
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
Lcfi24:
	.cfi_def_cfa_offset 16
Lcfi25:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi26:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
## BB#1:
	jmp	LBB8_2
LBB8_2:
	jmp	LBB8_3
LBB8_3:                                 ## =>This Inner Loop Header: Depth=1
	movq	-8(%rbp), %rax
	cmpq	-16(%rbp), %rax
	je	LBB8_6
## BB#4:                                ##   in Loop: Header=BB8_3 Depth=1
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	movq	%rax, (%rcx)
## BB#5:                                ##   in Loop: Header=BB8_3 Depth=1
	movq	-8(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -8(%rbp)
	jmp	LBB8_3
LBB8_6:
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
Lcfi27:
	.cfi_def_cfa_offset 16
Lcfi28:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi29:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movl	$0, (%rdi)
	movl	$0, 4(%rdi)
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
Lcfi30:
	.cfi_def_cfa_offset 16
Lcfi31:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi32:
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
Lcfi33:
	.cfi_def_cfa_offset 16
Lcfi34:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi35:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	%rdi, -16(%rbp)         ## 8-byte Spill
LBB11_1:                                ## =>This Inner Loop Header: Depth=1
	movq	-16(%rbp), %rax         ## 8-byte Reload
	movq	32(%rax), %rcx
	cmpq	40(%rax), %rcx
	je	LBB11_5
## BB#2:                                ##   in Loop: Header=BB11_1 Depth=1
	movq	-16(%rbp), %rax         ## 8-byte Reload
	movq	32(%rax), %rcx
	movq	16(%rcx), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, 56(%rax)
	movq	32(%rax), %rcx
	cmpq	$0, %rcx
	movq	%rcx, -24(%rbp)         ## 8-byte Spill
	je	LBB11_4
## BB#3:                                ##   in Loop: Header=BB11_1 Depth=1
	movq	-24(%rbp), %rdi         ## 8-byte Reload
	callq	__ZN3dsa15__skiplist_nodeIiiED1Ev
	movq	-24(%rbp), %rdi         ## 8-byte Reload
	callq	__ZdlPv
LBB11_4:                                ##   in Loop: Header=BB11_1 Depth=1
	movq	-16(%rbp), %rax         ## 8-byte Reload
	movq	56(%rax), %rcx
	movq	%rcx, 32(%rax)
	jmp	LBB11_1
LBB11_5:
	movq	-16(%rbp), %rax         ## 8-byte Reload
	movq	40(%rax), %rcx
	cmpq	$0, %rcx
	movq	%rcx, -32(%rbp)         ## 8-byte Spill
	je	LBB11_7
## BB#6:
	movq	-32(%rbp), %rdi         ## 8-byte Reload
	callq	__ZN3dsa15__skiplist_nodeIiiED1Ev
	movq	-32(%rbp), %rdi         ## 8-byte Reload
	callq	__ZdlPv
LBB11_7:
	movq	-16(%rbp), %rax         ## 8-byte Reload
	movq	64(%rax), %rcx
	cmpq	$0, %rcx
	movq	%rcx, -40(%rbp)         ## 8-byte Spill
	je	LBB11_9
## BB#8:
	movq	-40(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	__ZdaPv
LBB11_9:
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
Lcfi36:
	.cfi_def_cfa_offset 16
Lcfi37:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi38:
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
Lcfi39:
	.cfi_def_cfa_offset 16
Lcfi40:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi41:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	16(%rdi), %rdi
	cmpq	$0, %rdi
	movq	%rdi, -16(%rbp)         ## 8-byte Spill
	je	LBB13_2
## BB#1:
	movq	-16(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	__ZdaPv
LBB13_2:
	addq	$16, %rsp
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
Lcfi42:
	.cfi_def_cfa_offset 16
Lcfi43:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi44:
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
LBB14_1:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB14_3 Depth 2
	cmpl	$-1, -20(%rbp)
	jle	LBB14_7
## BB#2:                                ##   in Loop: Header=BB14_1 Depth=1
	jmp	LBB14_3
LBB14_3:                                ##   Parent Loop BB14_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	48(%rax), %rcx
	movq	16(%rcx), %rcx
	movslq	-20(%rbp), %rdx
	movq	(%rcx,%rdx,8), %rcx
	movl	(%rcx), %esi
	movq	-16(%rbp), %rcx
	cmpl	(%rcx), %esi
	jge	LBB14_5
## BB#4:                                ##   in Loop: Header=BB14_3 Depth=2
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	48(%rax), %rcx
	movq	16(%rcx), %rcx
	movslq	-20(%rbp), %rdx
	movq	(%rcx,%rdx,8), %rcx
	movq	%rcx, 48(%rax)
	jmp	LBB14_3
LBB14_5:                                ##   in Loop: Header=BB14_1 Depth=1
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	48(%rax), %rcx
	movq	64(%rax), %rdx
	movslq	-20(%rbp), %rsi
	movq	%rcx, (%rdx,%rsi,8)
## BB#6:                                ##   in Loop: Header=BB14_1 Depth=1
	movl	-20(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -20(%rbp)
	jmp	LBB14_1
LBB14_7:
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
Lcfi45:
	.cfi_def_cfa_offset 16
Lcfi46:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi47:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	$0, -16(%rbp)
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
LBB15_1:                                ## =>This Inner Loop Header: Depth=1
	callq	_rand
	andl	$1, %eax
	cmpl	$0, %eax
	je	LBB15_3
## BB#2:                                ##   in Loop: Header=BB15_1 Depth=1
	movq	-16(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -16(%rbp)
	jmp	LBB15_1
LBB15_3:
	movq	-16(%rbp), %rax
	movq	-24(%rbp), %rcx         ## 8-byte Reload
	cmpq	16(%rcx), %rax
	jae	LBB15_5
## BB#4:
	movq	-16(%rbp), %rax
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	jmp	LBB15_6
LBB15_5:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	movq	16(%rax), %rcx
	movq	%rcx, -32(%rbp)         ## 8-byte Spill
LBB15_6:
	movq	-32(%rbp), %rax         ## 8-byte Reload
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
Lcfi48:
	.cfi_def_cfa_offset 16
Lcfi49:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi50:
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


.subsections_via_symbols
