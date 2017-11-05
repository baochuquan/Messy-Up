	.file	"m2.c"
	.section	.rodata
	.align	3
.LC0:
	.ascii	"Please input two 5*5  matrixes: \000"
	.align	3
.LC1:
	.ascii	"A[5][5]:\000"
	.align	3
.LC2:
	.ascii	"%d\000"
	.align	3
.LC3:
	.ascii	"B[5][5]:\000"
	.align	3
.LC4:
	.ascii	"Result:\000"
	.align	3
.LC5:
	.ascii	"%d \000"
	.text
	.align	2
	.global	main
	.type	main,function
main:
	@ args = 0, pretend = 0, frame = 324
	@ frame_needed = 1, uses_anonymous_args = 0
	mov	ip, sp
	stm.w	(fp, ip, lr, pc), [sp-]
	sub	fp, ip, #4
	sub	sp, sp, #324
	ldw	r15, .L21
	mov	r0, r15
	b.l	printf
	ldw	r0, .L21+4
	b.l	puts
	mov	r15, #0
	stw	r15, [fp+], #-24
	b	.L2
.L5:
	mov	r15, #0
	stw	r15, [fp+], #-20
	b	.L3
.L4:
	ldw	r13, .L21+8
	sub	r12, fp, #136
	ldw	r14, [fp+], #-24
	mov	r15, r14
	mov	r15, r15 << #2
	add	r14, r15, r14
	ldw	r15, [fp+], #-20
	add	r15, r14, r15
	mov	r15, r15 << #2
	add	r15, r12, r15
	mov	r0, r13
	mov	r1, r15
	b.l	scanf
	ldw	r15, [fp+], #-20
	add	r15, r15, #1
	stw	r15, [fp+], #-20
.L3:
	ldw	r15, [fp+], #-20
	cmpsub.a	r15, #4
	bel	.L4
	ldw	r15, [fp+], #-24
	add	r15, r15, #1
	stw	r15, [fp+], #-24
.L2:
	ldw	r15, [fp+], #-24
	cmpsub.a	r15, #4
	bel	.L5
	ldw	r0, .L21+12
	b.l	puts
	mov	r15, #0
	stw	r15, [fp+], #-24
	b	.L6
.L9:
	mov	r15, #0
	stw	r15, [fp+], #-20
	b	.L7
.L8:
	ldw	r13, .L21+8
	sub	r12, fp, #236
	ldw	r14, [fp+], #-24
	mov	r15, r14
	mov	r15, r15 << #2
	add	r14, r15, r14
	ldw	r15, [fp+], #-20
	add	r15, r14, r15
	mov	r15, r15 << #2
	add	r15, r12, r15
	mov	r0, r13
	mov	r1, r15
	b.l	scanf
	ldw	r15, [fp+], #-20
	add	r15, r15, #1
	stw	r15, [fp+], #-20
.L7:
	ldw	r15, [fp+], #-20
	cmpsub.a	r15, #4
	bel	.L8
	ldw	r15, [fp+], #-24
	add	r15, r15, #1
	stw	r15, [fp+], #-24
.L6:
	ldw	r15, [fp+], #-24
	cmpsub.a	r15, #4
	bel	.L9
	mov	r15, #0
	stw	r15, [fp+], #-24
	b	.L10
.L15:
	mov	r15, #0
	stw	r15, [fp+], #-20
	b	.L11
.L14:
	ldw	r14, [fp+], #-24
	ldw	r13, [fp+], #-20
	mov	r15, r14
	mov	r15, r15 << #2
	add	r15, r15, r14
	add	r14, r15, r13
	not	r15, #323
	mov	r14, r14 << #2
	sub	r9, fp, #12
	add	r14, r9, r14
	add	r15, r14, r15
	mov	r14, #0
	stw	r14, [r15+], #0
	mov	r15, #0
	stw	r15, [fp+], #-16
	b	.L12
.L13:
	ldw	r14, [fp+], #-24
	ldw	r12, [fp+], #-20
	ldw	r13, [fp+], #-24
	ldw	r11, [fp+], #-20
	mov	r15, r13
	mov	r15, r15 << #2
	add	r15, r15, r13
	add	r13, r15, r11
	not	r15, #323
	mov	r13, r13 << #2
	sub	r10, fp, #12
	add	r13, r10, r13
	add	r15, r13, r15
	ldw	r11, [r15+], #0
	ldw	r13, [fp+], #-24
	ldw	r10, [fp+], #-16
	mov	r15, r13
	mov	r15, r15 << #2
	add	r15, r15, r13
	add	r13, r15, r10
	not	r15, #123
	mov	r13, r13 << #2
	sub	r9, fp, #12
	add	r13, r9, r13
	add	r15, r13, r15
	ldw	r10, [r15+], #0
	ldw	r13, [fp+], #-16
	ldw	r9, [fp+], #-20
	mov	r15, r13
	mov	r15, r15 << #2
	add	r15, r15, r13
	add	r13, r15, r9
	not	r15, #223
	mov	r13, r13 << #2
	sub	r9, fp, #12
	add	r13, r9, r13
	add	r15, r13, r15
	ldw	r15, [r15+], #0
	mul	r15, r10, r15
	add	r13, r11, r15
	mov	r15, r14
	mov	r15, r15 << #2
	add	r15, r15, r14
	add	r14, r15, r12
	not	r15, #323
	mov	r14, r14 << #2
	sub	r10, fp, #12
	add	r14, r10, r14
	add	r15, r14, r15
	stw	r13, [r15+], #0
	ldw	r15, [fp+], #-16
	add	r15, r15, #1
	stw	r15, [fp+], #-16
.L12:
	ldw	r15, [fp+], #-16
	cmpsub.a	r15, #4
	bel	.L13
	ldw	r15, [fp+], #-20
	add	r15, r15, #1
	stw	r15, [fp+], #-20
.L11:
	ldw	r15, [fp+], #-20
	cmpsub.a	r15, #4
	bel	.L14
	ldw	r15, [fp+], #-24
	add	r15, r15, #1
	stw	r15, [fp+], #-24
.L10:
	ldw	r15, [fp+], #-24
	cmpsub.a	r15, #4
	bel	.L15
	ldw	r0, .L21+16
	b.l	puts
	mov	r15, #0
	stw	r15, [fp+], #-24
	b	.L16
.L19:
	mov	r15, #0
	stw	r15, [fp+], #-20
	b	.L17
.L18:
	ldw	r13, .L21+20
	ldw	r14, [fp+], #-24
	ldw	r12, [fp+], #-20
	mov	r15, r14
	mov	r15, r15 << #2
	add	r15, r15, r14
	add	r14, r15, r12
	not	r15, #323
	mov	r14, r14 << #2
	sub	r11, fp, #12
	add	r14, r11, r14
	add	r15, r14, r15
	ldw	r15, [r15+], #0
	mov	r0, r13
	mov	r1, r15
	b.l	printf
	ldw	r15, [fp+], #-20
	add	r15, r15, #1
	stw	r15, [fp+], #-20
.L17:
	ldw	r15, [fp+], #-20
	cmpsub.a	r15, #4
	bel	.L18
	mov	r0, #10
	b.l	putchar
	ldw	r15, [fp+], #-24
	add	r15, r15, #1
	stw	r15, [fp+], #-24
.L16:
	ldw	r15, [fp+], #-24
	cmpsub.a	r15, #4
	bel	.L19
	mov	r15, #0
	mov	r0, r15
	ldm	(fp, sp, pc), [fp-]
.L22:
	.align	2
.L21:
	.word	.LC0
	.word	.LC1
	.word	.LC2
	.word	.LC3
	.word	.LC4
	.word	.LC5
	.size	main, .-main
	.ident	"GCC: (UC4_1.0.4_20100811) 4.4.2"
