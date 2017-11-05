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
	stw	r0, [fp+], #-28
	stw	r1, [fp+], #-32
	stw	r2, [fp+], #-36
	stw	r3, [fp+], #-40
	mov	r15, #0
	stw	r15, [fp+], #-24
	b	.L2
.L7:
	mov	r15, #0
	stw	r15, [fp+], #-20
	b	.L3
.L6:
	mov	r15, #0
	stw	r15, [fp+], #-16
	b	.L4
.L5:
	ldw	r15, [fp+], #-24
	ldw	r14, [fp+], #8
	mul	r15, r14, r15
	mov	r14, r15
	ldw	r15, [fp+], #-20
	add	r15, r14, r15
	mov	r15, r15 << #2
	ldw	r14, [fp+], #12
	add	r15, r14, r15
	ldw	r14, [fp+], #-24
	ldw	r13, [fp+], #8
	mul	r14, r13, r14
	mov	r13, r14
	ldw	r14, [fp+], #-20
	add	r14, r13, r14
	mov	r14, r14 << #2
	ldw	r13, [fp+], #12
	add	r14, r13, r14
	ldw	r13, [r14+], #0
	ldw	r14, [fp+], #-24
	ldw	r12, [fp+], #-36
	mul	r14, r12, r14
	mov	r12, r14
	ldw	r14, [fp+], #-16
	add	r14, r12, r14
	mov	r14, r14 << #2
	ldw	r12, [fp+], #-28
	add	r14, r12, r14
	ldw	r14, [r14+], #0
	ldw	r12, [fp+], #-16
	ldw	r11, [fp+], #8
	mul	r12, r11, r12
	mov	r11, r12
	ldw	r12, [fp+], #-20
	add	r12, r11, r12
	mov	r12, r12 << #2
	ldw	r11, [fp+], #-40
	add	r12, r11, r12
	ldw	r12, [r12+], #0
	mul	r14, r12, r14
	add	r14, r13, r14
	stw	r14, [r15+], #0
	ldw	r15, [fp+], #-16
	add	r15, r15, #1
	stw	r15, [fp+], #-16
.L4:
	ldw	r14, [fp+], #-16
	ldw	r15, [fp+], #-36
	cmpsub.a	r14, r15
	bsl	.L5
	ldw	r15, [fp+], #-20
	add	r15, r15, #1
	stw	r15, [fp+], #-20
.L3:
	ldw	r14, [fp+], #-20
	ldw	r15, [fp+], #8
	cmpsub.a	r14, r15
	bsl	.L6
	ldw	r15, [fp+], #-24
	add	r15, r15, #1
	stw	r15, [fp+], #-24
.L2:
	ldw	r14, [fp+], #-24
	ldw	r15, [fp+], #-32
	cmpsub.a	r14, r15
	bsl	.L7
	ldm	(fp, sp, pc), [fp-]
	.size	cal_matrix, .-cal_matrix
	.ident	"GCC: (UC4_1.0_gama_20101125) 4.4.2"
