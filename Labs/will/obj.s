
./a.out:     file format elf32-littleunicore32


Disassembly of section .init:

020002b4 <_init>:
 20002b4:	72ef8004 	stw.w	lr, [sp-], #4
 20002b8:	bd000011 	b.l	2000300 <call_gmon_start>
 20002bc:	bd00003b 	b.l	20003ac <frame_dummy>
 20002c0:	bd0000d8 	b.l	2000624 <__do_global_ctors_aux>
 20002c4:	69efc004 	ldw.w	pc, [sp]+, #4

Disassembly of section .text:

020002c8 <_start>:
 20002c8:	79ff0028 	ldw	ip, [pc+], #40	; 20002f4 <_start+0x2c>
 20002cc:	3a06c000 	mov	fp, #0	; 0x0
 20002d0:	69e84004 	ldw.w	r1, [sp]+, #4
 20002d4:	1a00801d 	mov	r2, sp
 20002d8:	72e88004 	stw.w	r2, [sp-], #4
 20002dc:	72e80004 	stw.w	r0, [sp-], #4
 20002e0:	79f80014 	ldw	r0, [pc+], #20	; 20002f8 <_start+0x30>
 20002e4:	79f8c014 	ldw	r3, [pc+], #20	; 20002fc <_start+0x34>
 20002e8:	72ef0004 	stw.w	ip, [sp-], #4
 20002ec:	bd0000ed 	b.l	20006a4 <_fini+0x44>
 20002f0:	bd0000e3 	b.l	2000680 <_fini+0x20>
 20002f4:	020005b4 	.word	0x020005b4
 20002f8:	020003e8 	.word	0x020003e8
 20002fc:	020005b8 	.word	0x020005b8

02000300 <call_gmon_start>:
 2000300:	72ee8004 	stw.w	sl, [sp-], #4
 2000304:	79fe8024 	ldw	sl, [pc+], #36	; 200032c <call_gmon_start+0x2c>
 2000308:	08fe801a 	add	sl, pc, sl
 200030c:	79fbc020 	ldw	r15, [pc+], #32	; 2000330 <call_gmon_start+0x30>
 2000310:	59d3c00f 	ldw	r15, [sl+],r15
 2000314:	35780000 	cmpsub.a	r15, #0	; 0x0
 2000318:	a0000002 	beq	2000324 <call_gmon_start+0x24>
 200031c:	8be82040 	ldm.w	(sl), [sp]+
 2000320:	bc0000da 	b	200068c <_fini+0x2c>
 2000324:	8be82040 	ldm.w	(sl), [sp]+
 2000328:	1a07c01e 	mov	pc, lr
 200032c:	000084ac 	.word	0x000084ac
 2000330:	00000024 	.word	0x00000024

02000334 <__do_global_dtors_aux>:
 2000334:	92ea2e40 	stm.w	(r22, r23, r24, sl, lr), [sp-]
 2000338:	79fd8058 	ldw	r22, [pc+], #88	; 2000394 <__do_global_dtors_aux+0x60>
 200033c:	7db3c000 	ldb	r15, [r22+]
 2000340:	35780000 	cmpsub.a	r15, #0	; 0x0
 2000344:	a2000012 	bne	2000390 <__do_global_dtors_aux+0x5c>
 2000348:	79fdc04c 	ldw	r23, [pc+], #76	; 2000398 <__do_global_dtors_aux+0x64>
 200034c:	79fe004c 	ldw	r24, [pc+], #76	; 200039c <__do_global_dtors_aux+0x68>
 2000350:	79fe804c 	ldw	sl, [pc+], #76	; 20003a0 <__do_global_dtors_aux+0x6c>
 2000354:	06be0018 	rsub	r24, r23, r24
 2000358:	1a060498 	mov	r24, r24 |> #2
 200035c:	79d3c000 	ldw	r15, [sl+]
 2000360:	24c60001 	sub	r24, r24, #1	; 0x1
 2000364:	15780018 	cmpsub.a	r15, r24
 2000368:	a4000007 	bea	2000388 <__do_global_dtors_aux+0x54>
 200036c:	287bc001 	add	r15, r15, #1	; 0x1
 2000370:	78d3c000 	stw	r15, [sl+]
 2000374:	28ff8004 	add	lr, pc, #4	; 0x4
 2000378:	59bfc40f 	ldw	pc, [r23+],r15 << #2
 200037c:	79d3c000 	ldw	r15, [sl+]
 2000380:	15780018 	cmpsub.a	r15, r24
 2000384:	a6fffff9 	bub	200036c <__do_global_dtors_aux+0x38>
 2000388:	3a03c001 	mov	r15, #1	; 0x1
 200038c:	7cb3c000 	stb	r15, [r22+]
 2000390:	8bec2e40 	ldm.w	(r22, r23, r24, sl, pc), [sp]+
 2000394:	020087f0 	.word	0x020087f0
 2000398:	020086e4 	.word	0x020086e4
 200039c:	020086e8 	.word	0x020086e8
 20003a0:	020087f4 	.word	0x020087f4

020003a4 <call___do_global_dtors_aux>:
 20003a4:	72ef8004 	stw.w	lr, [sp-], #4
 20003a8:	69efc004 	ldw.w	pc, [sp]+, #4

020003ac <frame_dummy>:
 20003ac:	72ef8004 	stw.w	lr, [sp-], #4
 20003b0:	79f80024 	ldw	r0, [pc+], #36	; 20003d8 <frame_dummy+0x2c>
 20003b4:	7903c000 	ldw	r15, [r0+]
 20003b8:	35780000 	cmpsub.a	r15, #0	; 0x0
 20003bc:	a0000005 	beq	20003d4 <frame_dummy+0x28>
 20003c0:	79fbc018 	ldw	r15, [pc+], #24	; 20003dc <frame_dummy+0x30>
 20003c4:	35780000 	cmpsub.a	r15, #0	; 0x0
 20003c8:	a0000002 	beq	20003d4 <frame_dummy+0x28>
 20003cc:	28ff8004 	add	lr, pc, #4	; 0x4
 20003d0:	1a07c00f 	mov	pc, r15
 20003d4:	69efc004 	ldw.w	pc, [sp]+, #4
 20003d8:	020086ec 	.word	0x020086ec
 20003dc:	00000000 	.word	0x00000000

020003e0 <call_frame_dummy>:
 20003e0:	72ef8004 	stw.w	lr, [sp-], #4
 20003e4:	69efc004 	ldw.w	pc, [sp]+, #4

020003e8 <main>:
 20003e8:	92ea2e40 	stm.w	(r22, r23, r24, sl, lr), [sp-]
 20003ec:	24ef68a3 	sub	sp, sp, #667648	; 0xa3000
 20003f0:	24ef41e0 	sub	sp, sp, #480	; 0x1e0
 20003f4:	3a034000 	mov	r13, #0	; 0x0
 20003f8:	28eb2dc5 	add	r12, sp, #463872	; 0x71400
 20003fc:	3a02f619 	mov	r11, #800	; 0x320
 2000400:	286301e0 	add	r12, r12, #480	; 0x1e0
 2000404:	246300f0 	sub	r12, r12, #240	; 0xf0
 2000408:	026b992b 	mula	r14, r11, r13, r12
 200040c:	3a03c000 	mov	r15, #0	; 0x0
 2000410:	287bc001 	add	r15, r15, #1	; 0x1
 2000414:	357800c8 	cmpsub.a	r15, #200	; 0xc8
 2000418:	6873c004 	stw.w	r15, [r14]+, #4
 200041c:	a2fffffc 	bne	2000410 <main+0x28>
 2000420:	286b4001 	add	r13, r13, #1	; 0x1
 2000424:	356800ff 	cmpsub.a	r13, #255	; 0xff
 2000428:	a2fffff7 	bne	2000408 <main+0x20>
 200042c:	28ebaa7f 	add	r14, sp, #260096	; 0x3f800
 2000430:	3a060000 	mov	r24, #0	; 0x0
 2000434:	287381e0 	add	r14, r14, #480	; 0x1e0
 2000438:	247381d0 	sub	r14, r14, #464	; 0x1d0
 200043c:	06c3d018 	rsub	r15, r24, r24 << #8
 2000440:	3a068000 	mov	sl, #0	; 0x0
 2000444:	0873c40f 	add	r15, r14, r15 << #2
 2000448:	28d68001 	add	sl, sl, #1	; 0x1
 200044c:	35d000ff 	cmpsub.a	sl, #255	; 0xff
 2000450:	687e8004 	stw.w	sl, [r15]+, #4
 2000454:	a2fffffc 	bne	2000448 <main+0x60>
 2000458:	28c60001 	add	r24, r24, #1	; 0x1
 200045c:	35c000c8 	cmpsub.a	r24, #200	; 0xc8
 2000460:	a2fffff6 	bne	200043c <main+0x54>
 2000464:	28edc1e0 	add	r23, sp, #480	; 0x1e0
 2000468:	3a00aa7f 	mov	r2, #260096	; 0x3f800
 200046c:	24bdc1d4 	sub	r23, r23, #468	; 0x1d4
 2000470:	28108004 	add	r2, r2, #4	; 0x4
 2000474:	3a004000 	mov	r1, #0	; 0x0
 2000478:	1a000017 	mov	r0, r23
 200047c:	bd000086 	b.l	2000698 <_fini+0x38>
 2000480:	28e828a3 	add	r0, sp, #667648	; 0xa3000
 2000484:	3a004000 	mov	r1, #0	; 0x0
 2000488:	280001d8 	add	r0, r0, #472	; 0x1d8
 200048c:	bd000088 	b.l	20006b0 <_fini+0x50>
 2000490:	28e82dc5 	add	r0, sp, #463872	; 0x71400
 2000494:	28e8ea7f 	add	r3, sp, #260096	; 0x3f800
 2000498:	28eda8a3 	add	r22, sp, #667648	; 0xa3000
 200049c:	280001e0 	add	r0, r0, #480	; 0x1e0
 20004a0:	2818c1e0 	add	r3, r3, #480	; 0x1e0
 20004a4:	28b581d0 	add	r22, r22, #464	; 0x1d0
 20004a8:	1a008018 	mov	r2, r24
 20004ac:	2418c1d0 	sub	r3, r3, #464	; 0x1d0
 20004b0:	1a00401a 	mov	r1, sl
 20004b4:	240000f0 	sub	r0, r0, #240	; 0xf0
 20004b8:	78edc008 	stw	r23, [sp+], #8
 20004bc:	78ee0000 	stw	r24, [sp+]
 20004c0:	78ee8004 	stw	sl, [sp+], #4
 20004c4:	bd000015 	b.l	200051c <cal_matrix>
 20004c8:	3a004000 	mov	r1, #0	; 0x0
 20004cc:	1a000016 	mov	r0, r22
 20004d0:	bd000077 	b.l	20006b0 <_fini+0x50>
 20004d4:	28eade05 	add	r11, sp, #655360	; 0xa0000
 20004d8:	79b30004 	ldw	r12, [r22+], #4
 20004dc:	795bb1d0 	ldw	r14, [r11+], #12752
 20004e0:	795bf1d8 	ldw	r15, [r11+], #12760
 20004e4:	795b71dc 	ldw	r13, [r11+], #12764
 20004e8:	067bc00e 	rsub	r15, r15, r14
 20004ec:	79f80028 	ldw	r0, [pc+], #40	; 2000518 <main+0x130>
 20004f0:	067b8a0f 	rsub	r14, r15, r15 << #5
 20004f4:	066b400c 	rsub	r13, r13, r12
 20004f8:	06738c0e 	rsub	r14, r14, r14 << #6
 20004fc:	087bc60e 	add	r15, r15, r14 << #3
 2000500:	08684c0f 	add	r1, r13, r15 << #6
 2000504:	bd00006d 	b.l	20006bc <_fini+0x5c>
 2000508:	3a000000 	mov	r0, #0	; 0x0
 200050c:	28ef778f 	add	sp, sp, #12768	; 0x31e0
 2000510:	28ef5e05 	add	sp, sp, #655360	; 0xa0000
 2000514:	8bec2e40 	ldm.w	(r22, r23, r24, sl, pc), [sp]+
 2000518:	020006d0 	.word	0x020006d0

0200051c <cal_matrix>:
 200051c:	72ef8004 	stw.w	lr, [sp-], #4
 2000520:	35080000 	cmpsub.a	r1, #0	; 0x0
 2000524:	79e94008 	ldw	r5, [sp+], #8
 2000528:	ba000021 	bel	20005b0 <cal_matrix+0x94>
 200052c:	79ef000c 	ldw	ip, [sp+], #12
 2000530:	1a020405 	mov	r8, r5 << #2
 2000534:	1a078402 	mov	lr, r2 << #2
 2000538:	3a010000 	mov	r4, #0	; 0x0
 200053c:	35280000 	cmpsub.a	r5, #0	; 0x0
 2000540:	ba000016 	bel	200059c <cal_matrix+0x80>
 2000544:	1a018003 	mov	r6, r3
 2000548:	1a02401c 	mov	r9, ip
 200054c:	3a01c000 	mov	r7, #0	; 0x0
 2000550:	35100000 	cmpsub.a	r2, #0	; 0x0
 2000554:	ba00000c 	bel	2000588 <cal_matrix+0x6c>
 2000558:	794b4000 	ldw	r13, [r9+]
 200055c:	1a038006 	mov	r14, r6
 2000560:	1a030000 	mov	r12, r0
 2000564:	3a03c000 	mov	r15, #0	; 0x0
 2000568:	7972c000 	ldw	r11, [r14+]
 200056c:	287bc001 	add	r15, r15, #1	; 0x1
 2000570:	69628004 	ldw.w	r10, [r12]+, #4
 2000574:	15780002 	cmpsub.a	r15, r2
 2000578:	08738008 	add	r14, r14, r8
 200057c:	025b5b2a 	mula	r13, r10, r11, r13
 2000580:	784b4000 	stw	r13, [r9+]
 2000584:	a2fffff8 	bne	2000568 <cal_matrix+0x4c>
 2000588:	2839c001 	add	r7, r7, #1	; 0x1
 200058c:	28318004 	add	r6, r6, #4	; 0x4
 2000590:	15380005 	cmpsub.a	r7, r5
 2000594:	284a4004 	add	r9, r9, #4	; 0x4
 2000598:	a2ffffed 	bne	2000550 <cal_matrix+0x34>
 200059c:	28210001 	add	r4, r4, #1	; 0x1
 20005a0:	08e70008 	add	ip, ip, r8
 20005a4:	15200001 	cmpsub.a	r4, r1
 20005a8:	0800001e 	add	r0, r0, lr
 20005ac:	a2ffffe3 	bne	200053c <cal_matrix+0x20>
 20005b0:	69efc004 	ldw.w	pc, [sp]+, #4

020005b4 <__libc_csu_fini>:
 20005b4:	10ffc13e 	jump	lr

020005b8 <__libc_csu_init>:
 20005b8:	92ea2e78 	stm.w	(r19, r20, r21, r22, r23, r24, sl, lr), [sp-]
 20005bc:	79fe8058 	ldw	sl, [pc+], #88	; 2000618 <__libc_csu_init+0x60>
 20005c0:	08fe801a 	add	sl, pc, sl
 20005c4:	1a058000 	mov	r22, r0
 20005c8:	1a054001 	mov	r21, r1
 20005cc:	1a050002 	mov	r20, r2
 20005d0:	bdffff38 	b.l	20002b4 <_init>
 20005d4:	79fbc044 	ldw	r15, [pc+], #68	; 200061c <__libc_csu_init+0x64>
 20005d8:	59d4c00f 	ldw	r19, [sl+],r15
 20005dc:	79fbc040 	ldw	r15, [pc+], #64	; 2000620 <__libc_csu_init+0x68>
 20005e0:	59d5c00f 	ldw	r23, [sl+],r15
 20005e4:	069dc017 	rsub	r23, r19, r23
 20005e8:	1b05c497 	mov.a	r23, r23 |> #2
 20005ec:	a0000009 	beq	2000614 <__libc_csu_init+0x5c>
 20005f0:	3a060000 	mov	r24, #0	; 0x0
 20005f4:	1a000016 	mov	r0, r22
 20005f8:	1a004015 	mov	r1, r21
 20005fc:	1a008014 	mov	r2, r20
 2000600:	28ff8004 	add	lr, pc, #4	; 0x4
 2000604:	599fc418 	ldw	pc, [r19+],r24 << #2
 2000608:	28c60001 	add	r24, r24, #1	; 0x1
 200060c:	15c00017 	cmpsub.a	r24, r23
 2000610:	a6fffff8 	bub	20005f4 <__libc_csu_init+0x3c>
 2000614:	8bec2e78 	ldm.w	(r19, r20, r21, r22, r23, r24, sl, pc), [sp]+
 2000618:	000081f4 	.word	0x000081f4
 200061c:	0000002c 	.word	0x0000002c
 2000620:	00000028 	.word	0x00000028

02000624 <__do_global_ctors_aux>:
 2000624:	92ea2040 	stm.w	(sl, lr), [sp-]
 2000628:	79fe8028 	ldw	sl, [pc+], #40	; 2000654 <__do_global_ctors_aux+0x30>
 200062c:	71d3c004 	ldw	r15, [sl-], #4
 2000630:	37780001 	cmpadd.a	r15, #1	; 0x1
 2000634:	a0000006 	beq	2000650 <__do_global_ctors_aux+0x2c>
 2000638:	24d68004 	sub	sl, sl, #4	; 0x4
 200063c:	28ff8004 	add	lr, pc, #4	; 0x4
 2000640:	1a07c00f 	mov	pc, r15
 2000644:	73d3c004 	ldw.w	r15, [sl-], #4
 2000648:	37780001 	cmpadd.a	r15, #1	; 0x1
 200064c:	a2fffffb 	bne	200063c <__do_global_ctors_aux+0x18>
 2000650:	8bec2040 	ldm.w	(sl, pc), [sp]+
 2000654:	020086e0 	.word	0x020086e0

02000658 <call___do_global_ctors_aux>:
 2000658:	72ef8004 	stw.w	lr, [sp-], #4
 200065c:	69efc004 	ldw.w	pc, [sp]+, #4

Disassembly of section .fini:

02000660 <_fini>:
 2000660:	72ef8004 	stw.w	lr, [sp-], #4
 2000664:	bdffff33 	b.l	2000334 <__do_global_dtors_aux>
 2000668:	69efc004 	ldw.w	pc, [sp]+, #4

Disassembly of section .plt:

0200066c <.plt>:
 200066c:	72ef8004 	stw.w	lr, [sp-], #4
 2000670:	79ff8008 	ldw	lr, [pc+], #8	; 200067c <_fini+0x1c>
 2000674:	08ff801e 	add	lr, pc, lr
 2000678:	7bf7c00c 	ldw.w	pc, [lr+], #12
 200067c:	0000813c 	.word	0x0000813c
 2000680:	28ff1200 	add	ip, pc, #0	; 0x0
 2000684:	28e72402 	add	ip, ip, #32768	; 0x8000
 2000688:	7be7c140 	ldw.w	pc, [ip+], #320
 200068c:	28ff1200 	add	ip, pc, #0	; 0x0
 2000690:	28e72402 	add	ip, ip, #32768	; 0x8000
 2000694:	7be7c138 	ldw.w	pc, [ip+], #312
 2000698:	28ff1200 	add	ip, pc, #0	; 0x0
 200069c:	28e72402 	add	ip, ip, #32768	; 0x8000
 20006a0:	7be7c130 	ldw.w	pc, [ip+], #304
 20006a4:	28ff1200 	add	ip, pc, #0	; 0x0
 20006a8:	28e72402 	add	ip, ip, #32768	; 0x8000
 20006ac:	7be7c128 	ldw.w	pc, [ip+], #296
 20006b0:	28ff1200 	add	ip, pc, #0	; 0x0
 20006b4:	28e72402 	add	ip, ip, #32768	; 0x8000
 20006b8:	7be7c120 	ldw.w	pc, [ip+], #288
 20006bc:	28ff1200 	add	ip, pc, #0	; 0x0
 20006c0:	28e72402 	add	ip, ip, #32768	; 0x8000
 20006c4:	7be7c118 	ldw.w	pc, [ip+], #280
