	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
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
	subq	$400, %rsp              ## imm = 0x190
	leaq	L_.str(%rip), %rdi
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -340(%rbp)
	movb	$0, %al
	callq	_printf
	leaq	L_.str1(%rip), %rdi
	movl	%eax, -368(%rbp)        ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movl	$0, -356(%rbp)
	movl	%eax, -372(%rbp)        ## 4-byte Spill
LBB0_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_3 Depth 2
	cmpl	$5, -356(%rbp)
	jge	LBB0_8
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	$0, -360(%rbp)
LBB0_3:                                 ##   Parent Loop BB0_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpl	$5, -360(%rbp)
	jge	LBB0_6
## BB#4:                                ##   in Loop: Header=BB0_3 Depth=2
	leaq	L_.str2(%rip), %rdi
	leaq	-112(%rbp), %rax
	movslq	-360(%rbp), %rcx
	movslq	-356(%rbp), %rdx
	imulq	 $20, %rdx
	addq	%rdx, %rax
	shlq	$2, %rcx
	addq	%rcx, %rax
	movq	%rax, %rsi
	movb	$0, %al
	callq	_scanf
	movl	%eax, -376(%rbp)        ## 4-byte Spill
## BB#5:                                ##   in Loop: Header=BB0_3 Depth=2
	movl	-360(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -360(%rbp)
	jmp	LBB0_3
LBB0_6:                                 ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_7
LBB0_7:                                 ##   in Loop: Header=BB0_1 Depth=1
	movl	-356(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -356(%rbp)
	jmp	LBB0_1
LBB0_8:
	leaq	L_.str3(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$0, -356(%rbp)
	movl	%eax, -380(%rbp)        ## 4-byte Spill
LBB0_9:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_11 Depth 2
	cmpl	$5, -356(%rbp)
	jge	LBB0_16
## BB#10:                               ##   in Loop: Header=BB0_9 Depth=1
	movl	$0, -360(%rbp)
LBB0_11:                                ##   Parent Loop BB0_9 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpl	$5, -360(%rbp)
	jge	LBB0_14
## BB#12:                               ##   in Loop: Header=BB0_11 Depth=2
	leaq	L_.str2(%rip), %rdi
	leaq	-224(%rbp), %rax
	movslq	-360(%rbp), %rcx
	movslq	-356(%rbp), %rdx
	imulq	 $20, %rdx
	addq	%rdx, %rax
	shlq	$2, %rcx
	addq	%rcx, %rax
	movq	%rax, %rsi
	movb	$0, %al
	callq	_scanf
	movl	%eax, -384(%rbp)        ## 4-byte Spill
## BB#13:                               ##   in Loop: Header=BB0_11 Depth=2
	movl	-360(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -360(%rbp)
	jmp	LBB0_11
LBB0_14:                                ##   in Loop: Header=BB0_9 Depth=1
	jmp	LBB0_15
LBB0_15:                                ##   in Loop: Header=BB0_9 Depth=1
	movl	-356(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -356(%rbp)
	jmp	LBB0_9
LBB0_16:
	movl	$0, -356(%rbp)
LBB0_17:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_19 Depth 2
                                        ##       Child Loop BB0_21 Depth 3
	cmpl	$5, -356(%rbp)
	jge	LBB0_28
## BB#18:                               ##   in Loop: Header=BB0_17 Depth=1
	movl	$0, -360(%rbp)
LBB0_19:                                ##   Parent Loop BB0_17 Depth=1
                                        ## =>  This Loop Header: Depth=2
                                        ##       Child Loop BB0_21 Depth 3
	cmpl	$5, -360(%rbp)
	jge	LBB0_26
## BB#20:                               ##   in Loop: Header=BB0_19 Depth=2
	leaq	-336(%rbp), %rax
	movslq	-360(%rbp), %rcx
	movslq	-356(%rbp), %rdx
	imulq	 $20, %rdx
	addq	%rdx, %rax
	movl	$0, (%rax,%rcx,4)
	movl	$0, -364(%rbp)
LBB0_21:                                ##   Parent Loop BB0_17 Depth=1
                                        ##     Parent Loop BB0_19 Depth=2
                                        ## =>    This Inner Loop Header: Depth=3
	cmpl	$5, -364(%rbp)
	jge	LBB0_24
## BB#22:                               ##   in Loop: Header=BB0_21 Depth=3
	leaq	-336(%rbp), %rax
	leaq	-224(%rbp), %rcx
	leaq	-112(%rbp), %rdx
	movslq	-364(%rbp), %rsi
	movslq	-356(%rbp), %rdi
	imulq	 $20, %rdi
	addq	%rdi, %rdx
	movl	(%rdx,%rsi,4), %r8d
	movslq	-360(%rbp), %rdx
	movslq	-364(%rbp), %rsi
	imulq	 $20, %rsi
	addq	%rsi, %rcx
	imull	(%rcx,%rdx,4), %r8d
	movslq	-360(%rbp), %rcx
	movslq	-356(%rbp), %rdx
	imulq	 $20, %rdx
	addq	%rdx, %rax
	movl	(%rax,%rcx,4), %r9d
	addl	%r8d, %r9d
	movl	%r9d, (%rax,%rcx,4)
## BB#23:                               ##   in Loop: Header=BB0_21 Depth=3
	movl	-364(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -364(%rbp)
	jmp	LBB0_21
LBB0_24:                                ##   in Loop: Header=BB0_19 Depth=2
	jmp	LBB0_25
LBB0_25:                                ##   in Loop: Header=BB0_19 Depth=2
	movl	-360(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -360(%rbp)
	jmp	LBB0_19
LBB0_26:                                ##   in Loop: Header=BB0_17 Depth=1
	jmp	LBB0_27
LBB0_27:                                ##   in Loop: Header=BB0_17 Depth=1
	movl	-356(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -356(%rbp)
	jmp	LBB0_17
LBB0_28:
	leaq	L_.str4(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$0, -356(%rbp)
	movl	%eax, -388(%rbp)        ## 4-byte Spill
LBB0_29:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_31 Depth 2
	cmpl	$5, -356(%rbp)
	jge	LBB0_36
## BB#30:                               ##   in Loop: Header=BB0_29 Depth=1
	movl	$0, -360(%rbp)
LBB0_31:                                ##   Parent Loop BB0_29 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpl	$5, -360(%rbp)
	jge	LBB0_34
## BB#32:                               ##   in Loop: Header=BB0_31 Depth=2
	leaq	L_.str5(%rip), %rdi
	leaq	-336(%rbp), %rax
	movslq	-360(%rbp), %rcx
	movslq	-356(%rbp), %rdx
	imulq	 $20, %rdx
	addq	%rdx, %rax
	movl	(%rax,%rcx,4), %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -392(%rbp)        ## 4-byte Spill
## BB#33:                               ##   in Loop: Header=BB0_31 Depth=2
	movl	-360(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -360(%rbp)
	jmp	LBB0_31
LBB0_34:                                ##   in Loop: Header=BB0_29 Depth=1
	leaq	L_.str6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -396(%rbp)        ## 4-byte Spill
## BB#35:                               ##   in Loop: Header=BB0_29 Depth=1
	movl	-356(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -356(%rbp)
	jmp	LBB0_29
LBB0_36:
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	cmpq	-8(%rbp), %rax
	jne	LBB0_38
## BB#37:                               ## %SP_return
	xorl	%eax, %eax
	addq	$400, %rsp              ## imm = 0x190
	popq	%rbp
	retq
LBB0_38:                                ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Please input two 5*5  matrixes: "

L_.str1:                                ## @.str1
	.asciz	"A[5][5]:\n"

L_.str2:                                ## @.str2
	.asciz	"%d"

L_.str3:                                ## @.str3
	.asciz	"B[5][5]:\n"

L_.str4:                                ## @.str4
	.asciz	"Result:\n"

L_.str5:                                ## @.str5
	.asciz	"%d "

L_.str6:                                ## @.str6
	.asciz	"\n"


.subsections_via_symbols
