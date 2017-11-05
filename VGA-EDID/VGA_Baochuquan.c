 /* --------------------------------------------------------------------------
 * PURPOSE:
 * To Read EDID by VGA interface
 * Using GPIO2 and GPIO4 to simulate I2C mechanisum
 * Can read 128 bytes of EDID
 *
 * AUTHOR: BaoChuquan
 *
 * TIME: 2014-11-24
 *
---------------------------------------------------------------------------*/

#define GPIO_SCL 2		//GPIO2 as SCL of I2C
#define GPIO_SDA 4		//GPIO4 as SDA of I2C

#define bool unsigned char
#define true 1
#define false 0

#define __REG(x)    (*((volatile unsigned long *)(x)))

#define GPIO_GPLR       __REG(PKUNITY_GPIO_BASE + 0x0000) /* Voltage Status Reg.  */
#define GPIO_GPDR       __REG(PKUNITY_GPIO_BASE + 0x0004) /* Pin Direction Reg. */
#define GPIO_GPSR       __REG(PKUNITY_GPIO_BASE + 0x0008) /* Output Pin Set Reg.  */
#define GPIO_GPCR       __REG(PKUNITY_GPIO_BASE + 0x000C) /* Output Pin Clear Reg.  */
#define GPIO_GRER       __REG(PKUNITY_GPIO_BASE + 0x0010) /* Raise Edge Detect Reg. */
#define GPIO_GFER       __REG(PKUNITY_GPIO_BASE + 0x0014) /* Fall Edge Detect Reg. */
#define GPIO_GEDR       __REG(PKUNITY_GPIO_BASE + 0x0018) /* Edge Status Reg. */
#define GPIO_GPIR       __REG(PKUNITY_GPIO_BASE + 0x0020) /* Sepcial Voltage Detect Reg. */

#define GPIO_GPIO(Nb)   (0x00000001 << (Nb))			/* GPIO [0..27]       */

ULONG PKUNITY_GPIO_BASE;

//GPIO function declaration
static void SCL_dir();
static void SDA_dir(int dir);
static void SCL_set(int what);
static void SDA_set(int what);
static int SDA_get();
static void SDAbb_send_num(int val, int bits);
static USHORT SDAbb_get_num(int bits);
static void SDAbb_send_bit(int val);
static int SDAbb_get_bit();

//I2C functions declaration
static void VGA_I2C_init();
static void VGA_I2C_start();
static void VGA_I2C_stop();

static void VGA_I2C_Mack();						//Master send ack
static void VGA_I2C_Mnack();					//Master send nack
static bool Waitack();							//Master wait ack

int VGA_I2C_read(int phyaddr);					//I2C read one byte from a phyaddr
int VGA_I2C_write(int phyaddr, USHORT val);		//T2C write one byte to a phyaddr

void VGA_Read_EDID();							//read EDID by VGA
void VGA_IO_ResetCodec();

//functions of read/write data/addr to OS_Mem
ULONG os_ReadMemULong(ULONG addr);
void os_WriteMemULong (ULONG addr, ULONG Data);
USHORT os_ReadMemUShort (ULONG addr);
void os_WriteMemUShort (ULONG addr, USHORT Data);
UCHAR os_ReadMemUChar (ULONG addr);

//functions provided by Windows
PVOID 
  MmMapIoSpace(
    IN PHYSICAL_ADDRESS  PhysicalAddress,
    IN SIZE_T  NumberOfBytes,
    IN MEMORY_CACHING_TYPE  CacheType
    );

VOID 
  KeStallExecutionProcessor(
		      IN ULONG  MicroSeconds
			      );

static void delay_us(ULONG us)
{
	unsigned int i = 0;
	unsigned int j = 0;

	for (i = 0; i < us; i++) {
		/*
		 * if you optimization you code with level 0, please set j max 0x3000;
		 * if you optimization you code with level 1, please set j max 0x7500;
		 * if you optimization you code with level 2, please set j max 0x7500;
		 */
    KeStallExecutionProcessor(20);
	}

}

//set SCL direction output
static void SCL_dir()
{
	GPIO_GPIR &= ~GPIO_GPIO(GPIO_SCL);		//gpio2 as common port
	GPIO_GPDR |= GPIO_GPIO(GPIO_SCL);		//gpio2 as otput
}

//set SDA direction, 1:ouput, 0:input
static void SDA_dir(int dir)
{
    GPIO_GPIR &= ~GPIO_GPIO(GPIO_SDA);		//gpio4 as common port
    if (dir)
        GPIO_GPDR |= GPIO_GPIO(GPIO_SDA);	//if dir=1 --output
    else
        GPIO_GPDR &= ~GPIO_GPIO(GPIO_SDA);	//if dir=0 --input
}

//set SCL output data
static void SCL_set(int what)
{
    if (what)
        GPIO_GPSR |= GPIO_GPIO(GPIO_SCL);	//if what = 1, SCL output 1
    else
        GPIO_GPCR |= GPIO_GPIO(GPIO_SCL);	//if what = 0, SCL output 0
}

//set SDA output data
static void SDA_set(int what)
{
    if (what)
        GPIO_GPSR |= GPIO_GPIO(GPIO_SDA);	//if what = 1, SDA output 1
    else
        GPIO_GPCR |= GPIO_GPIO(GPIO_SDA);	//if what = 0, SDA output 0
}

//SDA get one bit data: 0x0000 000X
static int SDA_get()
{
    return (GPIO_GPLR & GPIO_GPIO(GPIO_SDA)) >> GPIO_SDA;//get related bit , 0x0000 000X
}

/* SDA must already be configured as output. */
static void SDAbb_send_num(int val, int bits)
{
    int i;

    SDA_dir(1);
	for (i = bits - 1; i >= 0; i--)
        SDAbb_send_bit((val >> i) & 1);
}

/* SDA must already be configured as input. */
static USHORT SDAbb_get_num(int bits)
{
    int i;
    USHORT ret = 0;

	SCL_dir();
	SDA_dir(0);
    for (i = bits - 1; i >= 0; i--) {
        ret <<= 1;
        ret |= SDAbb_get_bit();
    }
	SCL_set(0);		//scl =0
    return ret;
}

/* SDA must already be configured as output. */
static void SDAbb_send_bit(int val)
{
	SDA_dir(1);
    SDA_set(val);	//sda =0/1
    delay_us(10);
    SCL_set(1);		//scl =1
    delay_us(10);
    SCL_set(0);		//scl =0
}

/* SDA must already be configured as input. */
static int SDAbb_get_bit()
{
	SDA_dir(0);
    SCL_set(0);		//scl =0
    delay_us(10);
    SCL_set(1);		//scl =1
    return SDA_get();
}

static void VGA_I2C_init()
{
	//DISPDBG((MP_LOUD, "VGA_I2C_init begin\n"));
	SCL_dir();
	SDA_dir(1);

	SDA_set(1);		//sda=1
    delay_us(10);
	SCL_set(1);		//scl=1
    delay_us(10);
	//DISPDBG((MP_LOUD, "VGA_I2C_init end\n"));
}

static void VGA_I2C_start()
{
	SCL_dir();
	SDA_dir(1);		//out

	SDA_set(1);		//sda =1
    delay_us(10);
	SCL_set(1);		//scl =1
    delay_us(10);
	SDA_set(0);		//sda =0
    delay_us(10);
	SCL_set(0);		//scl =0
    delay_us(10);
}

static void VGA_I2C_stop()
{
	SCL_dir();
	SDA_dir(1);

	SCL_set(0);		//scl =0
	delay_us(10);
	SDA_set(0);		//sda =0
    delay_us(10);
	SCL_set(1);		//scl =1
    delay_us(10);
	SDA_set(1);		//sda =1
    delay_us(10);
}

static void VGA_I2C_Mack()
{
	SCL_dir();
	SDA_dir(1);		//out

	SDA_set(0);		//sda =0
	delay_us(10);
	SCL_set(1);		//scl =1
	delay_us(10);
	SCL_set(0);		//scl =0
	delay_us(10);
}

static void VGA_I2C_Mnack()
{
	SCL_dir();
	SDA_dir(1);		//out

	delay_us(10);
	SDA_set(1);		//sda =1
	delay_us(10);
	SCL_set(1);		//scl =1
	delay_us(10);
	SCL_set(0);		//scl =0
	delay_us(10);
}

static bool Waitack()
{
	SDA_dir(1);		//out
	SCL_dir();

	delay_us(1);
	SDA_set(1);		//sda =1
	delay_us(1);

	SDA_dir(0);		//in
	SCL_set(1);		//scl =1
	delay_us(5);
	if(SDA_get())
	{
		SCL_set(0);	//scl =0
		delay_us(5);
		return false;
	}
	else
	{
		SCL_set(0);
		delay_us(5);
		return true;
	}
}

int VGA_I2C_read(int phyaddr)
{
    int ret;

	//DISPDBG((MP_LOUD,"read begin\n"));
    SCL_dir();				//output
    SDA_dir(1);				//SDA output

	VGA_I2C_start();
	SDAbb_send_num(0xa0, 8);//LSB = 0 :  write , 8 bits
	Waitack();

	SDAbb_send_num(phyaddr, 8);
	Waitack();

	VGA_I2C_start();
	SDAbb_send_num(0xa1, 8);//LSB = 1 :  read , 8 bits
	Waitack();

	ret = SDAbb_get_num(8);
    VGA_I2C_Mack();

	VGA_I2C_stop();
	DISPDBG((MP_LOUD,"read end\n"));
    return ret;
}

int VGA_I2C_write(int phyaddr, USHORT val)
{
	DISPDBG((MP_LOUD,"write begin\n"));
    SCL_dir();

	VGA_I2C_start();

	SDAbb_send_num(0xa0,8);//LSB = 0 ;  write ,  8 bits
	Waitack();

	SDAbb_send_num(phyaddr,8);
	Waitack();

	SDAbb_send_num(val,8);
	Waitack();

	VGA_I2C_stop();
	delay_us(10);
	DISPDBG((MP_LOUD,"write end\n"));
    return 0;
}

/*-------------------------------------------------------------------------*/
//the function to read EDID by VGA , using I2C
//EDID will be storaged in a 256 bytes array
//VGA can actually read 128 bytes , while HDMI can read 256 bytes
/*-------------------------------------------------------------------------*/
void VGA_Read_EDID()
{
	int i;
	unsigned int vga_edid_buffer[256]={0};

	//DISPDBG((MP_LOUD,"VGA_Read_EDID begin\n"));
	VGA_IO_ResetCodec();//I2C initialize

	VGA_I2C_init();
	//DISPDBG((MP_LOUD,"getting vga_edid_buffer...\n"));
	for (i = 0;i < 256; i++)
	{
		vga_edid_buffer[i] = VGA_I2C_read(0x00 + i);
	}

	//DISPDBG((MP_LOUD,"printing vag_edid_buffer begin\n"));
	for (i = 0;i < 256; i++)
	{
		DISPDBG((MP_LOUD," vga_read EDID[%x] = %x\n", i, vga_edid_buffer[i]));
	}
	//DISPDBG((MP_LOUD,"VGA_Read_EDID end\n"));
}




 /* --------------------------------------------------------------------------
 * PURPOSE:
 *     Reset Codec.
 *
 * PARAMETERS:
 *
 * RETURN:
 *
---------------------------------------------------------------------------*/
void VGA_IO_ResetCodec()
{
    unsigned int temp;
    PHYSICAL_ADDRESS GPIOPhys;
    ULONG GPIOVirtAddr;
	DISPDBG((MP_LOUD, "VGA_IO_ResetCodec begin\n"));

    GPIOPhys.LowPart  = 0xEE500000;    //GPIO Physic Base
    GPIOPhys.HighPart = 0;

    // Mem Map GPIO
	DISPDBG((MP_LOUD, "VGA_IO_ResetCodec Mem maping...\n"));
    if (!(GPIOVirtAddr=(ULONG) MmMapIoSpace(GPIOPhys, 0x100000, MmNonCached)))
	{
        DISPDBG((MP_WARN, "Cant Map GPIO PhyAddr.\n"));
        return;
    }
	PKUNITY_GPIO_BASE = GPIOVirtAddr;
	DISPDBG((MP_LOUD, "get GPIOVirtAddr %x \n,",GPIOVirtAddr));

	// Reset I2S codec through GPIO
	DISPDBG((MP_LOUD, "VGA_IO_ResetCodec reading Mem...\n"));
    temp = os_ReadMemULong( GPIOVirtAddr + 0x20) & 0xffffebeb;	//1110 1011  1110 1011
    os_WriteMemULong( GPIOVirtAddr + 0x20, temp);				//Disable  GPIO2 & GPIO4 interrput function,by GPIR
    temp = os_ReadMemULong( GPIOVirtAddr + 0x20);				//1110 1011  1110 1011
	DISPDBG((MP_LOUD, "GPIR = %x,,\n",temp));

	temp = os_ReadMemULong( GPIOVirtAddr + 0x04) | 0x14;		//0001 0100
    os_WriteMemULong( GPIOVirtAddr + 0x04, temp);				//config GPIO2 & GPIO4 to output, temp for I2S codec reset
    temp = os_ReadMemULong( GPIOVirtAddr + 0x04);				//1110 1011  1110 1011
	DISPDBG((MP_LOUD, "GPDR = %x,,\n",temp));

    os_WriteMemULong( GPIOVirtAddr + 0x0c, 0x00000014);			//GPIO2 & GPIO4 output 0
    delay_us(10);

    os_WriteMemULong( GPIOVirtAddr + 0x08, 0x00000014);			//GPIO2 & GPIO4 output 1
    delay_us(10);
	DISPDBG((MP_LOUD, "VGA_IO_ResetCodec end\n"));
}

//ORI os_inc.c
ULONG os_ReadMemULong(ULONG addr)
{
	return *((volatile ULONG *) addr);
}

void os_WriteMemULong (ULONG addr, ULONG Data)
{
	*((volatile ULONG *) addr) = Data;
}

USHORT os_ReadMemUShort (ULONG addr)
{
	return *((volatile USHORT *) addr);
}

void os_WriteMemUShort (ULONG addr, USHORT Data)
{
	*((volatile USHORT *) addr) = Data;
}

UCHAR os_ReadMemUChar (ULONG addr)
{
	return *((volatile UCHAR *) addr);
}
