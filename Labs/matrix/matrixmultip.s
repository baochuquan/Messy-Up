	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_matrixMultiplication
	.align	4, 0x90
_matrixMultiplication:                  ## @matrixMultiplication
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
	movl	%edx, -20(%rbp)
	movl	%ecx, -24(%rbp)
	movl	%r8d, -28(%rbp)
	movl	$0, -32(%rbp)
LBB0_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_3 Depth 2
                                        ##       Child Loop BB0_5 Depth 3
	movl	-32(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jge	LBB0_12
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	$0, -36(%rbp)
LBB0_3:                                 ##   Parent Loop BB0_1 Depth=1
                                        ## =>  This Loop Header: Depth=2
                                        ##       Child Loop BB0_5 Depth 3
	movl	-36(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jge	LBB0_10
## BB#4:                                ##   in Loop: Header=BB0_3 Depth=2
	movl	$0, -40(%rbp)
LBB0_5:                                 ##   Parent Loop BB0_1 Depth=1
                                        ##     Parent Loop BB0_3 Depth=2
                                        ## =>    This Inner Loop Header: Depth=3
	movl	-40(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jge	LBB0_8
## BB#6:                                ##   in Loop: Header=BB0_5 Depth=3
	leaq	_C(%rip), %rax
	imull	$1000, -32(%rbp), %ecx  ## imm = 0x3E8
	addl	-40(%rbp), %ecx
	movslq	%ecx, %rdx
	movq	-8(%rbp), %rsi
	movl	(%rsi,%rdx,4), %ecx
	imull	$1000, -40(%rbp), %edi  ## imm = 0x3E8
	addl	-36(%rbp), %edi
	movslq	%edi, %rdx
	movq	-16(%rbp), %rsi
	imull	(%rsi,%rdx,4), %ecx
	movslq	-36(%rbp), %rdx
	movslq	-32(%rbp), %rsi
	imulq	 $4000, %rsi            ## imm = 0xFA0
	addq	%rsi, %rax
	movl	(%rax,%rdx,4), %edi
	addl	%ecx, %edi
	movl	%edi, (%rax,%rdx,4)
## BB#7:                                ##   in Loop: Header=BB0_5 Depth=3
	movl	-40(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -40(%rbp)
	jmp	LBB0_5
LBB0_8:                                 ##   in Loop: Header=BB0_3 Depth=2
	jmp	LBB0_9
LBB0_9:                                 ##   in Loop: Header=BB0_3 Depth=2
	movl	-36(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -36(%rbp)
	jmp	LBB0_3
LBB0_10:                                ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_11
LBB0_11:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	jmp	LBB0_1
LBB0_12:
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	subq	$8000096, %rsp          ## imm = 0x7A1260
	leaq	L_.str(%rip), %rdi
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -8000020(%rbp)
	movb	$0, %al
	callq	_printf
	leaq	L_.str1(%rip), %rdi
	leaq	-8000024(%rbp), %rsi
	leaq	-8000028(%rbp), %rdx
	leaq	-8000032(%rbp), %rcx
	movl	%eax, -8000060(%rbp)    ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	leaq	L_.str2(%rip), %rdi
	movl	-8000024(%rbp), %esi
	movl	-8000028(%rbp), %edx
	movl	%eax, -8000064(%rbp)    ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movl	$0, -8000036(%rbp)
	movl	%eax, -8000068(%rbp)    ## 4-byte Spill
LBB1_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_3 Depth 2
	movl	-8000036(%rbp), %eax
	cmpl	-8000024(%rbp), %eax
	jge	LBB1_8
## BB#2:                                ##   in Loop: Header=BB1_1 Depth=1
	movl	$0, -8000040(%rbp)
LBB1_3:                                 ##   Parent Loop BB1_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	-8000040(%rbp), %eax
	cmpl	-8000028(%rbp), %eax
	jge	LBB1_6
## BB#4:                                ##   in Loop: Header=BB1_3 Depth=2
	leaq	L_.str3(%rip), %rdi
	leaq	-4000016(%rbp), %rax
	movslq	-8000040(%rbp), %rcx
	movslq	-8000036(%rbp), %rdx
	imulq	 $4000, %rdx            ## imm = 0xFA0
	addq	%rdx, %rax
	shlq	$2, %rcx
	addq	%rcx, %rax
	movq	%rax, %rsi
	movb	$0, %al
	callq	_scanf
	movl	%eax, -8000072(%rbp)    ## 4-byte Spill
## BB#5:                                ##   in Loop: Header=BB1_3 Depth=2
	movl	-8000040(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8000040(%rbp)
	jmp	LBB1_3
LBB1_6:                                 ##   in Loop: Header=BB1_1 Depth=1
	jmp	LBB1_7
LBB1_7:                                 ##   in Loop: Header=BB1_1 Depth=1
	movl	-8000036(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8000036(%rbp)
	jmp	LBB1_1
LBB1_8:
	leaq	L_.str4(%rip), %rdi
	movl	-8000028(%rbp), %esi
	movl	-8000032(%rbp), %edx
	movb	$0, %al
	callq	_printf
	movl	$0, -8000044(%rbp)
	movl	%eax, -8000076(%rbp)    ## 4-byte Spill
LBB1_9:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_11 Depth 2
	movl	-8000044(%rbp), %eax
	cmpl	-8000028(%rbp), %eax
	jge	LBB1_16
## BB#10:                               ##   in Loop: Header=BB1_9 Depth=1
	movl	$0, -8000048(%rbp)
LBB1_11:                                ##   Parent Loop BB1_9 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	-8000048(%rbp), %eax
	cmpl	-8000032(%rbp), %eax
	jge	LBB1_14
## BB#12:                               ##   in Loop: Header=BB1_11 Depth=2
	leaq	L_.str3(%rip), %rdi
	leaq	-8000016(%rbp), %rax
	movslq	-8000048(%rbp), %rcx
	movslq	-8000044(%rbp), %rdx
	imulq	 $4000, %rdx            ## imm = 0xFA0
	addq	%rdx, %rax
	shlq	$2, %rcx
	addq	%rcx, %rax
	movq	%rax, %rsi
	movb	$0, %al
	callq	_scanf
	movl	%eax, -8000080(%rbp)    ## 4-byte Spill
## BB#13:                               ##   in Loop: Header=BB1_11 Depth=2
	movl	-8000048(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8000048(%rbp)
	jmp	LBB1_11
LBB1_14:                                ##   in Loop: Header=BB1_9 Depth=1
	jmp	LBB1_15
LBB1_15:                                ##   in Loop: Header=BB1_9 Depth=1
	movl	-8000044(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8000044(%rbp)
	jmp	LBB1_9
LBB1_16:
	leaq	-8000016(%rbp), %rax
	leaq	-4000016(%rbp), %rcx
	movl	-8000024(%rbp), %edx
	movl	-8000028(%rbp), %esi
	movl	-8000032(%rbp), %r8d
	movq	%rcx, %rdi
	movl	%esi, -8000084(%rbp)    ## 4-byte Spill
	movq	%rax, %rsi
	movl	-8000084(%rbp), %ecx    ## 4-byte Reload
	callq	_matrixMultiplication
	leaq	L_.str5(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$0, -8000052(%rbp)
	movl	%eax, -8000088(%rbp)    ## 4-byte Spill
LBB1_17:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_19 Depth 2
	movl	-8000052(%rbp), %eax
	cmpl	-8000024(%rbp), %eax
	jge	LBB1_24
## BB#18:                               ##   in Loop: Header=BB1_17 Depth=1
	movl	$0, -8000056(%rbp)
LBB1_19:                                ##   Parent Loop BB1_17 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	-8000056(%rbp), %eax
	cmpl	-8000032(%rbp), %eax
	jge	LBB1_22
## BB#20:                               ##   in Loop: Header=BB1_19 Depth=2
	leaq	L_.str6(%rip), %rdi
	leaq	_C(%rip), %rax
	movslq	-8000056(%rbp), %rcx
	movslq	-8000052(%rbp), %rdx
	imulq	 $4000, %rdx            ## imm = 0xFA0
	addq	%rdx, %rax
	movl	(%rax,%rcx,4), %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -8000092(%rbp)    ## 4-byte Spill
## BB#21:                               ##   in Loop: Header=BB1_19 Depth=2
	movl	-8000056(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8000056(%rbp)
	jmp	LBB1_19
LBB1_22:                                ##   in Loop: Header=BB1_17 Depth=1
	leaq	L_.str7(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -8000096(%rbp)    ## 4-byte Spill
## BB#23:                               ##   in Loop: Header=BB1_17 Depth=1
	movl	-8000052(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8000052(%rbp)
	jmp	LBB1_17
LBB1_24:
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	cmpq	-8(%rbp), %rax
	jne	LBB1_26
## BB#25:                               ## %SP_return
	xorl	%eax, %eax
	addq	$8000096, %rsp          ## imm = 0x7A1260
	popq	%rbp
	retq
LBB1_26:                                ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	.cfi_endproc

.zerofill __DATA,__bss,_C,4000000,4     ## @C
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Please input the scale of two matrixes: "

L_.str1:                                ## @.str1
	.asciz	"%d %d %d"

L_.str2:                                ## @.str2
	.asciz	"A[%d][%d]:\n"

L_.str3:                                ## @.str3
	.asciz	"%d"

L_.str4:                                ## @.str4
	.asciz	"B[%d][%d]:\n"

L_.str5:                                ## @.str5
	.asciz	"Result:\n"

L_.str6:                                ## @.str6
	.asciz	"%d "

L_.str7:                                ## @.str7
	.asciz	"\n"


.subsections_via_symbols
