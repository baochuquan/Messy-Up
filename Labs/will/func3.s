	.file	"func.c"
	.text
	.align	2
	.global	cal_matrix
	.type	cal_matrix,function
cal_matrix:
	@ args = 12, pretend = 0, frame = 28
	@ frame_needed = 1, uses_anonymous_args = 0
	mov	ip, sp
	stm.w	(fp, ip, lr, pc), [sp-]
	sub	fp, ip, #4
	sub	sp, sp, #28
	ldw	r5, [fp+], #8
	ldw	r6, [fp+], #12
	
	mov	r7, #0
	b	.L2
.L7:
	mov	r8, #0
	b	.L3
.L6:
	mov r9, #0
	b	.L4
.L5:
	mul	r15, r7, r5
	add	r15, r15, r8
	mov	r15, r15 << #2
	add r15, r15, r6
	
	mul r14, r7, r2
	add	r14, r14, r9
	mov	r14, r14 << #2
	add r14, r14, r0
	
	mul	r13, r9, r5
	add	r13, r13, r8
	mov r13, r13 << #2
	add	r13, r13, r3
	
	ldw r14, [r14+], #0
	ldw r13, [r13+], #0
	ldw	r12, [r15+], #0
	
	mul	r14, r14, r13
	add	r14, r14, r12
	stw r14, [r15+], #0
	
	add	r9, r9, #1
.L4:
	cmpsub.a	r9, r2
	bsl	.L5
	add	r8, r8, #1
.L3:
	cmpsub.a	r8, r5
	bsl	.L6
	add	r7, r7, #1
.L2:
	cmpsub.a	r7, r1
	bsl	.L7
	ldm	(fp, sp, pc), [fp-]
	.size	cal_matrix, .-cal_matrix
	.ident	"GCC: (UC4_1.0.4_20100811) 4.4.2"
