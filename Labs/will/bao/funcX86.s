	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_matrixmultip
	.align	4, 0x90
_matrixmultip:                          ## @matrixmultip
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
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movl	%ecx, -28(%rbp)
	movl	%r8d, -32(%rbp)
	movl	%r9d, -36(%rbp)
	movl	$0, -40(%rbp)
LBB0_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_3 Depth 2
                                        ##       Child Loop BB0_5 Depth 3
	movl	-40(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jge	LBB0_12
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	$0, -44(%rbp)
LBB0_3:                                 ##   Parent Loop BB0_1 Depth=1
                                        ## =>  This Loop Header: Depth=2
                                        ##       Child Loop BB0_5 Depth 3
	movl	-44(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jge	LBB0_10
## BB#4:                                ##   in Loop: Header=BB0_3 Depth=2
	movq	-24(%rbp), %rax
	movl	$0, (%rax)
	movl	$0, -48(%rbp)
LBB0_5:                                 ##   Parent Loop BB0_1 Depth=1
                                        ##     Parent Loop BB0_3 Depth=2
                                        ## =>    This Inner Loop Header: Depth=3
	movl	-48(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jge	LBB0_8
## BB#6:                                ##   in Loop: Header=BB0_5 Depth=3
	movq	-8(%rbp), %rax
	movl	-40(%rbp), %ecx
	imull	-28(%rbp), %ecx
	movslq	%ecx, %rdx
	shlq	$2, %rdx
	addq	%rdx, %rax
	movslq	-48(%rbp), %rdx
	movl	(%rax,%rdx,4), %ecx
	movq	-16(%rbp), %rax
	movl	-48(%rbp), %esi
	imull	-36(%rbp), %esi
	movslq	%esi, %rdx
	shlq	$2, %rdx
	addq	%rdx, %rax
	movslq	-44(%rbp), %rdx
	imull	(%rax,%rdx,4), %ecx
	movq	-24(%rbp), %rax
	movl	-40(%rbp), %esi
	imull	-28(%rbp), %esi
	movslq	%esi, %rdx
	shlq	$2, %rdx
	addq	%rdx, %rax
	movslq	-44(%rbp), %rdx
	movl	(%rax,%rdx,4), %esi
	addl	%ecx, %esi
	movl	%esi, (%rax,%rdx,4)
## BB#7:                                ##   in Loop: Header=BB0_5 Depth=3
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	jmp	LBB0_5
LBB0_8:                                 ##   in Loop: Header=BB0_3 Depth=2
	jmp	LBB0_9
LBB0_9:                                 ##   in Loop: Header=BB0_3 Depth=2
	movl	-44(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -44(%rbp)
	jmp	LBB0_3
LBB0_10:                                ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_11
LBB0_11:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	-40(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -40(%rbp)
	jmp	LBB0_1
LBB0_12:
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
