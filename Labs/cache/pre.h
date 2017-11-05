
/*enable the cache*/
.macro ENABLECACHE
	//I don't know why is 00ff_ff00_1f41_0000
	movl $0x00ffff00, %edx
	movl $0x1f410000, %eax
	movl $0x00001808, %ecx	//DRCPR
	wrmsr

	//All loads and stores are executed in program order.
	movl $0x00000000, %edx
	movl $0x00000001, %eax
	movl $0x00001800, %ecx	//Data Memory Configuration Register
	wrmsr

	//CR0 30:29(CD:NW) = 0:0, set cache behavior
	//Read/write misses may cause line allocations based on memory region configuration settings.
	movl %cr0, %eax
	andl $0xbfffffff, %eax
	andl $0xdfffffff, %eax
	movl %eax, %cr0
.endm

/*disable the cache*/
.macro DISABLECACHE
	//CR0 30:29 = 1:1
	movl %cr0, %eax
	orl $0x40000000, %eax
	orl $0x20000000, %eax
	movl %eax, %cr0
.endm
