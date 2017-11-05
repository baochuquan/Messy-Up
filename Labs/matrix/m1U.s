	.file	"m1.c"
	.local	C
	.comm	C, 4000000, 4
	.comm	i, 4, 4
	.comm	j, 4, 4
	.comm	k, 4, 4
	.text
	.align	2
	.global	matrixMultiplication
	.type	matrixMultiplication,function
matrixMultiplication:
	@ args = 4, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	mov	ip, sp
	stm.w	(fp, ip, lr, pc), [sp-]
	sub	fp, ip, #4
	sub	sp, sp, #16
	stw	r0, [fp+], #-16
	stw	r1, [fp+], #-20
	stw	r2, [fp+], #-24
	stw	r3, [fp+], #-28
	ldw	r15, .L9
	mov	r14, #0
	stw	r14, [r15+], #0
	b	.L2
.L7:
	ldw	r15, .L9+4
	mov	r14, #0
	stw	r14, [r15+], #0
	b	.L3
.L6:
	ldw	r15, .L9+8
	mov	r14, #0
	stw	r14, [r15+], #0
	b	.L4
.L5:
	ldw	r15, .L9
	ldw	r12, [r15+], #0
	ldw	r15, .L9+4
	ldw	r14, [r15+], #0
	ldw	r15, .L9
	ldw	r11, [r15+], #0
	ldw	r15, .L9+4
	ldw	r13, [r15+], #0
	ldw	r15, .L9+12
	mov	r10, #1000
	mul	r11, r10, r11
	add	r13, r11, r13
	ldw	r13, [r15+], r13 << #2
	ldw	r15, .L9
	ldw	r15, [r15+], #0
	mov	r11, #1000
	mul	r11, r15, r11
	ldw	r15, .L9+8
	ldw	r15, [r15+], #0
	add	r15, r11, r15
	mov	r15, r15 << #2
	ldw	r11, [fp+], #-16
	add	r15, r11, r15
	ldw	r15, [r15+], #0
	ldw	r11, .L9+8
	ldw	r11, [r11+], #0
	mov	r10, #1000
	mul	r10, r11, r10
	ldw	r11, .L9+4
	ldw	r11, [r11+], #0
	add	r11, r10, r11
	mov	r11, r11 << #2
	ldw	r10, [fp+], #-20
	add	r11, r10, r11
	ldw	r11, [r11+], #0
	mul	r15, r11, r15
	add	r13, r13, r15
	ldw	r15, .L9+12
	mov	r11, #1000
	mul	r12, r11, r12
	add	r14, r12, r14
	stw	r13, [r15+], r14 << #2
	ldw	r15, .L9+8
	ldw	r15, [r15+], #0
	add	r14, r15, #1
	ldw	r15, .L9+8
	stw	r14, [r15+], #0
.L4:
	ldw	r15, .L9+8
	ldw	r14, [r15+], #0
	ldw	r15, [fp+], #-28
	cmpsub.a	r14, r15
	bsl	.L5
	ldw	r15, .L9+4
	ldw	r15, [r15+], #0
	add	r14, r15, #1
	ldw	r15, .L9+4
	stw	r14, [r15+], #0
.L3:
	ldw	r15, .L9+4
	ldw	r14, [r15+], #0
	ldw	r15, [fp+], #4
	cmpsub.a	r14, r15
	bsl	.L6
	ldw	r15, .L9
	ldw	r15, [r15+], #0
	add	r14, r15, #1
	ldw	r15, .L9
	stw	r14, [r15+], #0
.L2:
	ldw	r15, .L9
	ldw	r14, [r15+], #0
	ldw	r15, [fp+], #-24
	cmpsub.a	r14, r15
	bsl	.L7
	ldm	(fp, sp, pc), [fp-]
.L10:
	.align	2
.L9:
	.word	i
	.word	j
	.word	k
	.word	C
	.size	matrixMultiplication, .-matrixMultiplication
	.section	.rodata
	.align	3
.LC0:
	.ascii	"Please input the scale of two matrixes: \000"
	.align	3
.LC1:
	.ascii	"%d %d %d\000"
	.align	3
.LC2:
	.ascii	"A[%d][%d]:\012\000"
	.align	3
.LC3:
	.ascii	"%d\000"
	.align	3
.LC4:
	.ascii	"B[%d][%d]:\012\000"
	.align	3
.LC5:
	.ascii	"Result:\000"
	.align	3
.LC6:
	.ascii	"%d \000"
	.text
	.align	2
	.global	main
	.type	main,function
main:
	@ args = 0, pretend = 0, frame = 8000012
	@ frame_needed = 1, uses_anonymous_args = 0
	mov	ip, sp
	stm.w	(fp, ip, lr, pc), [sp-]
	sub	fp, ip, #4
	sub	sp, sp, #7995392
	sub	sp, sp, #4624
	ldw	r15, .L25
	mov	r0, r15
	b.l	printf
	ldw	r12, .L25+4
	sub	r13, fp, #16
	sub	r14, fp, #20
	sub	r15, fp, #24
	mov	r0, r12
	mov	r1, r13
	mov	r2, r14
	mov	r3, r15
	b.l	scanf
	ldw	r13, .L25+8
	ldw	r14, [fp+], #-16
	ldw	r15, [fp+], #-20
	mov	r0, r13
	mov	r1, r14
	mov	r2, r15
	b.l	printf
	ldw	r15, .L25+12
	mov	r14, #0
	stw	r14, [r15+], #0
	b	.L12
.L15:
	ldw	r15, .L25+16
	mov	r14, #0
	stw	r14, [r15+], #0
	b	.L13
.L14:
	ldw	r14, .L25+20
	sub	r15, fp, #3997696
	sub	r15, r15, #12
	sub	r15, r15, #2312
	sub	r15, r15, #4
	ldw	r13, .L25+12
	ldw	r13, [r13+], #0
	mov	r12, #1000
	mul	r12, r13, r12
	ldw	r13, .L25+16
	ldw	r13, [r13+], #0
	add	r13, r12, r13
	mov	r13, r13 << #2
	add	r15, r15, r13
	mov	r0, r14
	mov	r1, r15
	b.l	scanf
	ldw	r15, .L25+16
	ldw	r15, [r15+], #0
	add	r14, r15, #1
	ldw	r15, .L25+16
	stw	r14, [r15+], #0
.L13:
	ldw	r15, .L25+16
	ldw	r14, [r15+], #0
	ldw	r15, [fp+], #-20
	cmpsub.a	r14, r15
	bsl	.L14
	ldw	r15, .L25+12
	ldw	r15, [r15+], #0
	add	r14, r15, #1
	ldw	r15, .L25+12
	stw	r14, [r15+], #0
.L12:
	ldw	r15, .L25+12
	ldw	r14, [r15+], #0
	ldw	r15, [fp+], #-16
	cmpsub.a	r14, r15
	bsl	.L15
	ldw	r13, .L25+24
	ldw	r14, [fp+], #-20
	ldw	r15, [fp+], #-24
	mov	r0, r13
	mov	r1, r14
	mov	r2, r15
	b.l	printf
	ldw	r15, .L25+12
	mov	r14, #0
	stw	r14, [r15+], #0
	b	.L16
.L19:
	ldw	r15, .L25+16
	mov	r14, #0
	stw	r14, [r15+], #0
	b	.L17
.L18:
	ldw	r14, .L25+20
	sub	r15, fp, #7995392
	sub	r15, r15, #12
	sub	r15, r15, #4608
	sub	r15, r15, #12
	ldw	r13, .L25+12
	ldw	r13, [r13+], #0
	mov	r12, #1000
	mul	r12, r13, r12
	ldw	r13, .L25+16
	ldw	r13, [r13+], #0
	add	r13, r12, r13
	mov	r13, r13 << #2
	add	r15, r15, r13
	mov	r0, r14
	mov	r1, r15
	b.l	scanf
	ldw	r15, .L25+16
	ldw	r15, [r15+], #0
	add	r14, r15, #1
	ldw	r15, .L25+16
	stw	r14, [r15+], #0
.L17:
	ldw	r15, .L25+16
	ldw	r14, [r15+], #0
	ldw	r15, [fp+], #-24
	cmpsub.a	r14, r15
	bsl	.L18
	ldw	r15, .L25+12
	ldw	r15, [r15+], #0
	add	r14, r15, #1
	ldw	r15, .L25+12
	stw	r14, [r15+], #0
.L16:
	ldw	r15, .L25+12
	ldw	r14, [r15+], #0
	ldw	r15, [fp+], #-20
	cmpsub.a	r14, r15
	bsl	.L19
	sub	r14, fp, #3997696
	sub	r14, r14, #12
	sub	r14, r14, #2312
	sub	r14, r14, #4
	sub	r15, fp, #7995392
	sub	r15, r15, #12
	sub	r15, r15, #4608
	sub	r15, r15, #12
	ldw	r12, [fp+], #-16
	ldw	r13, [fp+], #-20
	ldw	r11, [fp+], #-24
	stw	r11, [sp+], #0
	mov	r0, r14
	mov	r1, r15
	mov	r2, r12
	mov	r3, r13
	b.l	matrixMultiplication
	ldw	r0, .L25+28
	b.l	puts
	ldw	r15, .L25+12
	mov	r14, #0
	stw	r14, [r15+], #0
	b	.L20
.L23:
	ldw	r15, .L25+16
	mov	r14, #0
	stw	r14, [r15+], #0
	b	.L21
.L22:
	ldw	r14, .L25+32
	ldw	r15, .L25+12
	ldw	r12, [r15+], #0
	ldw	r15, .L25+16
	ldw	r13, [r15+], #0
	ldw	r15, .L25+36
	mov	r11, #1000
	mul	r12, r11, r12
	add	r13, r12, r13
	ldw	r15, [r15+], r13 << #2
	mov	r0, r14
	mov	r1, r15
	b.l	printf
	ldw	r15, .L25+16
	ldw	r15, [r15+], #0
	add	r14, r15, #1
	ldw	r15, .L25+16
	stw	r14, [r15+], #0
.L21:
	ldw	r15, .L25+16
	ldw	r14, [r15+], #0
	ldw	r15, [fp+], #-24
	cmpsub.a	r14, r15
	bsl	.L22
	mov	r0, #10
	b.l	putchar
	ldw	r15, .L25+12
	ldw	r15, [r15+], #0
	add	r14, r15, #1
	ldw	r15, .L25+12
	stw	r14, [r15+], #0
.L20:
	ldw	r15, .L25+12
	ldw	r14, [r15+], #0
	ldw	r15, [fp+], #-16
	cmpsub.a	r14, r15
	bsl	.L23
	mov	r15, #0
	mov	r0, r15
	ldm	(fp, sp, pc), [fp-]
.L26:
	.align	2
.L25:
	.word	.LC0
	.word	.LC1
	.word	.LC2
	.word	i
	.word	j
	.word	.LC3
	.word	.LC4
	.word	.LC5
	.word	.LC6
	.word	C
	.size	main, .-main
	.ident	"GCC: (UC4_1.0.4_20100811) 4.4.2"
