.file "test_bao_dcache.s"
.arch i686
.include "pre.h"

.macro put_word
	movl %eax, (%edi)
	addl $4, %edi
.endm

.text
.code32
.org 0

//CONFIG_DDR

/*write num to DDR for 8 lines*/
	movl $0x00000000, %eax
	movl $0x01234567, 0x0000(%eax)
	movl $0x11234567, 0x1000(%eax)
	movl $0x21234567, 0x2000(%eax)
	movl $0x31234567, 0x3000(%eax)
	movl $0x41234567, 0x4000(%eax)
	movl $0x51234567, 0x5000(%eax)
	movl $0x61234567, 0x6000(%eax)
	movl $0x71234567, 0x7000(%eax)

/*invalidate and enable cache*/
invd
ENABLECACHE

/*read data from cache, get 8 line to cache*/
	movl $0x00000000, %eax		//clear zero	
	movl $0x00000000, %edx		//clear zero
	movl 0x0000(%eax), %edx	
	movl 0x1000(%eax), %edx
	movl 0x2000(%eax), %edx
	movl 0x3000(%eax), %edx
	movl 0x4000(%eax), %edx
	movl 0x5000(%eax), %edx
	movl 0x6000(%eax), %edx
	movl 0x7000(%eax), %edx

/*disable cache, and invalidate the cache*/
DISABLECACHE

/*modify DDR*/
	movl $0x00000000, %eax
	movl $0x0abcdef0, 0x0000(%eax) 
	movl $0x1abcdef0, 0x1000(%eax) 
	movl $0x2abcdef0, 0x2000(%eax) 
	movl $0x3abcdef0, 0x3000(%eax) 
	movl $0x4abcdef0, 0x4000(%eax) 
	movl $0x5abcdef0, 0x5000(%eax) 
	movl $0x6abcdef0, 0x6000(%eax) 
	movl $0x7abcdef0, 0x7000(%eax) 

/*enable cache*/
ENABLECACHE

/*read data from cache, 8 line, and judge for each result*/
	movl $0x00000000, %eax
	movl $0x00000000, %edx
	movl 0x0000(%eax), %edx		//line 0
	cmpl $0x01234567, %edx
	jz next1
	jmp error

next1:
	movl $0x00000000, %eax
	movl $0x00000000, %edx
	movl 0x1000(%eax), %edx		//line 1
	cmpl $0x11234567, %edx
	jz next2
	jmp error

next2:
	movl $0x00000000, %eax
	movl $0x00000000, %edx
	movl 0x2000(%eax), %edx		//line 2
	cmpl $0x21234567, %edx
	jz next3
	jmp error

next3:
	movl $0x00000000, %eax
	movl $0x00000000, %edx
	movl 0x3000(%eax), %edx		//line 3
	cmpl $0x31234567, %edx
	jz next4
	jmp error

next4:
	movl $0x00000000, %eax
	movl $0x00000000, %edx
	movl 0x4000(%eax), %edx		//line 4
	cmpl $0x41234567, %edx
	jz next5
	jmp error

next5:
	movl $0x00000000, %eax
	movl $0x00000000, %edx
	movl 0x5000(%eax), %edx		//line 5
	cmpl $0x51234567, %edx
	jz next6
	jmp error

next6:
	movl $0x00000000, %eax
	movl $0x00000000, %edx
	movl 0x6000(%eax), %edx		//line 6
	cmpl $0x61234567, %edx
	jz next7
	jmp error

next7:
	movl $0x00000000, %eax
	movl $0x00000000, %edx
	movl 0x7000(%eax), %edx		//line 7
	cmpl $0x51234567, %edx
	jz right_label
	jmp error

error:
	jmp wrong_label

right_label:
	movl $0xbeafbeaf, %eax
	movl $0x7fff0000, %edi
	put_word
	jmp exit

wrong_label:
	movl $0xdeadbeaf, %eax
	movl $0x7fff0000, %edi
	put_word
	jmp exit

exit:
	movb $0xdb, 0x7ffffffc

	nop
	nop
	nop
	nop
	nop
	nop

