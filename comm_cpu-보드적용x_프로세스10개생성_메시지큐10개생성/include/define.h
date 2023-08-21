/*-----------------------------------------------------------------------------+
|                 CopyRight �� DaeaTi Co., Ltd.                                |
|                 All Rights Reserved                                          |
+------------------------------------------------------------------------------+
| FILE        : define.h                                                       |
| DIRECTORY   : 													           |
| PROCESS     :                                                                |
| �� �� ��    : �λ걳�����                                                           |
| PROJECT     : �λ굵��ö�� 1ȣ�� ���� ��ȣ���� ������ ����                                    |
| �ۼ� ����   : 2016.04.26                                                         |
| �� �� ��    :                                                                   |
| SYSTEM ���� : ���� ȯ�� - PC                                                      |
|               � ���� - Linux                                            
|               TARGET    - TI-AM5K2E04	 								       
|               LANGUAGE  -   C language                                       |
+------------------------------------------------------------------------------+
| 1. FUNCTION DESCRIPTION                                                      |
|	ELDTS ������ ���� �ʿ��� ������ Flag �� ������ ���� ���							           |
|                                                                              |
| 2. �Ҽ� �Լ�                                                                     |
|																			   |
| 3. Routine Tree                                                              |
|                                                                              |
+------------------------------------------------------------------------------*/
#include    <time.h>			//Time
#include    <stdio.h>			// Standard IN OUT
#include    <stdlib.h>		// Standard Library
#include    <stdarg.h>
#include    <string.h>		// String
#include    <errno.h>		// Error
#include    <unistd.h>	
#include    <signal.h>		// Signal
#include 	 <fcntl.h>         		// O_WRONLY
//#include    <ctype.h>
#include    <pthread.h>		// Thread
#include	 <termios.h>                   // B115200, CS8 �� ��� ����

#include    <arpa/inet.h>		// for TCP/IP
#include    <sys/socket.h>	// for Socket Com
#include	 <sys/poll.h>
#include 	 <sys/ioctl.h>
#include    <sys/types.h>
#include    <sys/ipc.h>		// Inter processor communication
#include    <sys/msg.h>		// Message
#include    <sys/shm.h>		// Share memory
#include 	 <sys/mman.h>	//memory management
#include    <linux/i2c-dev.h>

#include	"FPGA_Config.h"

#pragma pack(1)

//#define	LAN_TEST		1

#define	NEW_PROTO			1

#define	FOR_TEST			0
#define	FOR_DEBUG			0
#define	FOR_OPC_DEBUG		0
#define	FOR_MC_DEBUG		0
#define	FOR_SSC_DEBUG		0
#define	FOR_DTS_DEBUG		0
#define	FOR_CREATE_QUE	0
#define	FOR_COM			0
#define	FOR_LINUX		1
#define	FOR_UDP			0
#define	FOR_EMI			1
#define	FOR_UART_LED	0
#define FOR_ROUTE 		0 // RBC �������̽� �� '1'����
#define	FOR_HOST_ROUTE	0
#define	FOR_RBC_IF		0 // RBC �������̽� �� '1'����
//#define 	FOR_DTS_CH_EXT 	1

#define SUBWAY_TYPE	    0			// �ϳ���, �ų� ���� 

/*=============================================================================+
|		Type definition 														|
+==============================================================================*/
typedef unsigned char		uchar;
typedef unsigned int		uint;
typedef unsigned long		ulong;
typedef unsigned short		ushort;


/*=============================================================================+
|		�����̷� ���																	|
+==============================================================================*/

#define COMM_MMI_FUNC_INDICATION		0x21U	/** ���º�ȭ �޽��� */
#define COMM_MMI_FUNC_BASESCANRSP		0x61U	/** Basescan ���� �޽��� */

#define TRNO_INDICATION					0xA5U	/** ���� ���� ��ȭ ���� */
#define TRNO_BASESCAN					0x5AU	/** ���� Basescan */

/*=============================================================================+
|		Time define 															|
+==============================================================================*/
#define     SEC                     1
#define     SECS_FOR_MIN            (time_t) (SEC * 60)
#define     SECS_FOR_HOUR           (time_t) (SECS_FOR_MIN * 60)
#define     SECS_FOR_DAY            (time_t) (SECS_FOR_HOUR * 24)
#define     START_YEAR              1970
#define     START_WDAY              3       /* 0: WEDNESDAY , 1970, 1, 1*/
#define     DAYS_FOR_WEEK           7
#define     LEAP_DAYS               29
#define     NORMAL_DAYS             28
#define     DAYS_FOR_LEAP_YEAR      366
#define     DAYS_FOR_NORMAL_YEAR    365

#define		POLL_CYCLE				1500     /* 2ms * 1500 = 3sec */

/*=============================================================================+
|		Msg Buffer define																														 |
+==============================================================================*/
#define		NumOf_Queue		200
#define		NumOf_Sema		30

#define  	KEY_ILDB     	5959
#define  	KEY_RING     	9600
#define  	KEY_NUM     	1234
#define  	KEY_FPGA     	4321
#define  	KEY_FPGA2     	14321
#define  	KEY_FPGA3     	20201
#define  	KEY_FPGA4     	34741
#define  	KEY_RING1     	5678
#define  	KEY_RING2     	8765
#define  	KEY_DPRAM_A    	7676
#define  	KEY_DPRAM_B    	9898
#define  	MAX_TASK_NUM	30
#define     MAX_MSG_LENGTH  1024	
#define		Data_Length		0xFF
#define		MAX_SIZE		1037				// 13 + MAX_MSG_LENGTH
#define		BUF_SIZE		1024
	
// ����ڰ� �������� ����, TSIO 
#define 		MODEM_COMPILE
#define 		MODEM_MODE	1

/* �ű� LDTS���� CRC ��� �� high�� low�� �ٲ��� �����Ƿ�
   func_LowB�� func_HighB�� �ٲپ��� 2005�� 7�� 13�� */
#define 	func_HighB(x)   (uchar) ((x >> 8) & 0xff)
#define 	func_LowB(x)	(uchar) (x & 0xff)
	
//#define 		func_HighB(x)   (uchar) (x & 0xff)					// 20160614 
//#define 		func_LowB(x)		(uchar)((x >> 8) & 0xff)			//20160614
#define		func_Set_B(data, bitnumber)                 ( (data) |= (0x01 << (bitnumber) ))
#define		func_Clear_B(data, bitnumber)              ( (data) &= ~(0x01 << (bitnumber) ))

/*=============================================================================+
|		DPRAM Tx/Rx flag														|
+==============================================================================*/
#define		RX_FLAG		0x55
#define		TX_FLAG		0xAA

/*=============================================================================+
|		Message sender flag														|
+==============================================================================*/
#define		CPU_1ST		0x10
#define		CPU_2ND		0x20
	
/*=============================================================================+
|		Line Check Flag define												 |
+==============================================================================*/
// Line Status define
#define		BOTH_CH_GOOD		0x00	// 1,2 ���� ��� ����
// Good
#define		CH_OPC_1_GOOD		0x00	// OPC 1 ���� ����
#define		CH_OPC_2_GOOD		0x00	// OPC 2 ���� ����
#define		CH_MTC_1_GOOD		0x00	// MTC 1 ���� ����
#define		CH_MTC_2_GOOD		0x00	// MTC 2 ���� ����
#define		CH_DTS_1_GOOD		0x00	// DTS 1 ���� ����
#define		CH_DTS_2_GOOD		0x00	// DTS 2 ���� ����
#define		CH_RC_1_GOOD		0x00	// RC 1 ���� ����
#define		CH_RC_2_GOOD		0x00	// RC 2 ���� ����
#define		CH_DUAL_1_GOOD		0x00	// DUAL 1 ���� ����
#define		CH_DUAL_2_GOOD		0x00	// DUAL 2 ���� ����
	
// Bad
#define		CH_OPC_1_BAD		0x10	// OPC 1 ����
#define		CH_OPC_2_BAD		0x01	// OPC 2 ����
#define		CH_MTC_1_BAD		0x20	// MTC 1 ����
#define		CH_MTC_2_BAD		0x02	// MTC 2 ����
#define		CH_DTS_1_BAD		0x40	// DTS 1 ���� ����
#define		CH_DTS_2_BAD		0x04	// DTS 2 ���� ����
#define		CH_RC_1_BAD		0x80	// RC 1 ���� ����
#define		CH_RC_2_BAD		0x08	// RC 2 ���� ����
#define		CH_DUAL_1_BAD		0xF0	// DUAL 1 ���� ����
#define		CH_DUAL_2_BAD		0x0F	// DUAL 2 ���� ����

/*=============================================================================+
|		Common Flag define																														 |
+==============================================================================*/
#define 		MAX_RETRY		3
#define		ReseT						0x00
#define		reset						0x00
#define		SeT							0x01
#define		set							0x01
#define		Open						0x00
#define		Block						0x01
#define		All_Disable			0x00
#define		All_Enable			0x11
#define		Tx_Enable				0x10
#define		Rx_Enable				0x01
#define		RxSeqSet			0x55
#define 		func_Checksum(x, y)  ((uint) x - (uint) y)
#define		func_ChecksumChar(x, y)		((uchar) x - (uchar) y)
	
#define MAX_RING            8
#define EthMAX_RING            24
#define RING_DATA_SIZE      1024
#define Forever    0xffff
	
//#define EOF	-1
	
#define YES      1
#define NO       0
#define	Reserved 0
	
#define ESC     27
#define BS       8
#define DEL    127
	
	
typedef void*		(*start_routine)(void *);
typedef	struct {
	int	status;
}THREAD_PARAM;

#define SYSFS_GPIO_DIR "/sys/class/gpio"
#define MAX_BUF 64
#define GPIO_OUTPUT 0
#define GPIO_INPUT 1
#define GPIO_HIGH  1
#define GPIO_LOW  0
#define GPIO_NUM   3

typedef enum {
	GPIO_NONE,
	GPIO_RUN_STATUS,
	GPIO_SEGMENT_7,
	GPIO_DO,
	GPIO_DI,
	GPIO_UART_HDLC,
	GPIO_HDLC_TYPE,
	GPIO_VME_CLIENT,
	GPIO_VME_MASTER_DTACK,
	GPIO_VME_MEMORY_SIZE,
	GPIO_VME_DTACK_CLEAR,
	GPIO_DIPSW,	
	//GPIO_VME_PATTERN
} gpio_type_e;

/*-----------------------------------------------------------------------------+
|	�� ������ Acitve/ Passive Flag					   |
+------------------------------------------------------------------------------*/

typedef struct{
	int	Line_stat;
}LINE_STAT;


/*-----------------------------------------------------------------------------+
|	��, ���� frame�� PAC port�� �Ѹ����� ���� flag ���� 					   |
+------------------------------------------------------------------------------*/
typedef
enum	{
		ViewOn			= 0x1234,
		ViewOff 		= 0x5678
}		view_state;

/*-----------------------------------------------------------------------------+
| ��� channel�� ��ȣ�� ��Ÿ���� ����										   |
+------------------------------------------------------------------------------*/
typedef
enum	{
	Channel1 = 0x01,  
	Channel2 = 0x02,
	Channel3 = 0x03,	
	Channel4 = 0x04,
 	Channel5 = 0x05,
	Channel6 = 0x06,  
	Channel7 = 0x07,  
	Channel8 = 0x08,  
}	channel_no;
	
/*=============================================================================+
|		For CRC check																															 |
+==============================================================================*/
typedef union
{
	struct for_crc
	{
		uint	i1	:	1;
		uint	i2	:	1;
		uint	i3	:	1;
		uint	i4	:	1;
		uint	i5	:	1;
		uint	i6	:	1;
		uint	i7	:	1;
		uint	i8	:	1;
	}crc_bit;
	
  uchar data;
}ForCrc;

	
typedef union
{
	struct for_crcc
	{
		uint		i1 : 1;
		uint		i2 : 1;
		uint		i3 : 1;
		uint		i4 : 1;
		uint		i5 : 1;
		uint		i6 : 1;
		uint		i7 : 1;
		uint		i8 : 1;
	} crc_bitt;
	uchar dataa;
}ForCrcc;

	
/*=============================================================================+
|		CPU & I/O status																													 |
+==============================================================================*/
typedef
enum	{
	Online				= 0,
	Level_Low		= 0,
	Not_Changed 	= 0,
	Offline 				 ,
	Level_High		= 1,
	Level_Changed = 1
}	RunningStatus ;


typedef
enum	{
	Primary 	= 0,
	Secondary	= 1 	
}	CPU_state ;

typedef enum	{
	Running  =	0x10,
	Pri_set  =		0x01,
	Sec_set  =	0x01,
	Cpustate =	0x01,
	LdmState =	0x02,
}	system_sts;


typedef
enum	{
	InActive		= 0x00,
  	Die			= 0x00,
	Active		= 0x01,
	Alive			= 0x01, 
}	module_state;

typedef
enum	{
	Not_Defined 	= 0x00,
	Line_Active	= 0x01,
  	Line_Passive	= 0x02,
}Master_Line_state;

	
typedef
enum	{
	NoChange = 0 ,
	Change = 1
}	ChangeStatus;


typedef enum
{
	Test0Port	= 0,
	Test1Port	= 1,
	Test2Port	= 2,
	Test3Port	= 3,
	Test4Port	= 4,
	Test5Port	= 5,
	Test6Port	= 6,
	Test7Port	= 7,
	Test8Port	= 8,
} octal_port_assign;

typedef enum
{
	Port0	= 0,
	Port1,
	Port2,
	Port3,
	Port4,
	Port5,
	Port6,
	Port7,
	Port8,
} Port;

/*=============================================================================+
|		Task ID 															|
+==============================================================================*/
typedef enum
{
	PROC_TEST1 = 0,
	PROC_TEST2,	
	PROC_TEST3,	
	PROC_TEST4,
	PROC_TEST5,			
} TASK_ID;

typedef struct{
	int 		TaskId;
	int 		TaskNum;
	uchar		TaskName[20];
	int 		State;
	int 		RestartCnt;
	uchar		StTime[20];
	uchar		TaskStatus;
	uchar		AliveFlag;
}TASK_INFO;

typedef enum
{
	OPC_Pri_Line=0,		// OPC 1 Line ���� 
	OPC_Sec_Line,		// OPC 2 Line ���� 
	MTC_Pri_Line,		// MTC 1 Line ���� 
	MTC_Sec_Line,		// MTC 2 Line ���� 
	DTS_Pri_Line,		// DTS 1 Line ���� 
	DTS_Sec_Line,		// DTS 2 Line ���� 
	RC_Pri_Line,		// RC 1 Line ���� 
	RC_Sec_Line,		// RC 2 Line ���� 
	DUAL_Pri_Line,		// ����ȭ 1 Line ���� 
//	DUAL_Sec_Line,		// ����ȭ 2 Line ���� 
	
#if FOR_RBC_IF		
	RBC_Pri_Line,		// ����ȭ 1 Line ���� 
	RBC_Sec_Line,		// ����ȭ 2 Line ���� 	
#endif	

	EndofLineStat,
}LineStat;

typedef struct
{
	int 	Line_ID;
	uchar	Line_Name[25];
	uchar	Line_State;
	uchar	Line_Mode;
	uchar	StTime[20];
}LINE_INFO;


typedef struct
{
	int 	Device_ID;
	uchar	Device_State[2];
	uchar	Run_Mode;
}FSC_Device_INFO;



typedef struct
{
	uchar	StatChanged;
}RETRY_INFO;

typedef
enum	{
	OPC_Pri = 0x11,
	OPC_Sec = 0x12,
	MTC_Pri = 0x21,
	MTC_Sec = 0x22,
	DTS_Pri = 0x31,
	DTS_Sec = 0x32,
	RC_Pri = 0x41,
	RC_Sec = 0x42,
	DUAL_Pri = 0x81,
	DUAL_Sec = 0x82,
	Serial_1 = 0xD1,
	Serial_2 = 0xD2,
	Serial_3 = 0xD3,
	Serial_4 = 0xD4,
	Serial_5 = 0xD5,
	Serial_6 = 0xD6,
	Serial_7 = 0xD7,
	Serial_8 = 0xD8,	
}	LOG_CH_INFO;	


typedef
enum	{
	RXD = 0,
	TXD = 1,
}	LOG_CH_Type;	


/*=============================================================================+
|		Queue ID																																	 |
+==============================================================================*/
typedef
enum
{
#if 1
	TEST1_TX_QUE = 0,
	TEST1_RX_QUE,
	TEST2_TX_QUE,
	TEST2_RX_QUE,
#else
	/*--- CPU MODULE ---*/
	TASK_STAT_QUE = 0,
	Debug_TX_QUE,
	Debug_RX_QUE,
	V_QUEUE,
	/*--- Serial COMM ---Start : 4*/
	COM1_TX_QUE = 4,			// CPU Dual
	COM1_RX_QUE,			// CPU Dual
	COM2_TX_QUE,
	COM2_RX_QUE,
	COM3_TX_QUE,
	COM3_RX_QUE,
	COM4_TX_QUE,
	COM4_RX_QUE,
	COM5_TX_QUE,
	COM5_RX_QUE,
	COM6_TX_QUE,
	COM6_RX_QUE,
	COM7_TX_QUE,
	COM7_RX_QUE,
	COM8_TX_QUE,			
	COM8_RX_QUE,
	/*--- Socket COMM  ---Start : 20*/
	OPC1_TX_QUE = 20,
	OPC1_RX_QUE,
	MTC1_TX_QUE,
	MTC1_RX_QUE,
	DTS1_TX_QUE,
	DTS1_RX_QUE,
	RC1_TX_QUE, 
	RC1_RX_QUE, 
	YRC1_TX_QUE, 
	YRC1_RX_QUE, 		
	DUAL1_TX_QUE, 
	DUAL1_RX_QUE, 	
	/*--- MESSAGE QUEUE ---Start : 30*/
	OPC2_TX_QUE = 32,
	OPC2_RX_QUE,
	MTC2_TX_QUE,
	MTC2_RX_QUE,
	DTS2_TX_QUE,
	DTS2_RX_QUE,
	RC2_TX_QUE, 
	RC2_RX_QUE, 
	YRC2_TX_QUE, 
	YRC2_RX_QUE, 	
	DUAL2_TX_QUE, 
	DUAL2_RX_QUE,
	RC_RESP_QUE, 
	RC_IND_QUE,		
	RBC1_TX_QUE,
	RBC2_TX_QUE,
#endif	
	EndofQueueID,
} QUEUE_ID;

	
/*=============================================================================+
|		View Queue ID																																	 |
+==============================================================================*/
typedef
enum
{
	/*--- Serial COMM MESSAGE QUEUE for Debug---Start : 100 */
	VQUETX1 = 100,	 /* 					 */
	VQUETX2,   /*					   */
	VQUETX3,	/*						*/
	VQUETX4,   /*					   */
	VQUETX5,   /*					   */
	VQUETX6,   /*					   */
	VQUETX7,   /*					   */
	VQUETX8,   /*					   */
	VQUERX1,   /*					   */
	VQUERX2,   /*					   */
	VQUERX3,   /*					   */
	VQUERX4,   /*					   */
	VQUERX5,   /*					   */
	VQUERX6,   /*					   */
	VQUERX7,   /*					   */
	VQUERX8,   /*					   */
	/*--- Socket COMM MESSAGE QUEUE for Debug ---Start : 116 */
	VQUETX_OPC1 = 116,
	VQUETX_OPC2,
	VQUETX_MTC1,
	VQUETX_MTC2,
	VQUETX_DTS1,
	VQUETX_DTS2,
	VQUETX_RC1,
	VQUETX_RC2,
	VQUETX_DUAL1,
	VQUETX_DUAL2,
	VQUERX_OPC1,
	VQUERX_OPC2,
	VQUERX_MTC1,
	VQUERX_MTC2,
	VQUERX_DTS1,
	VQUERX_DTS2,
	VQUERX_RC1,
	VQUERX_RC2,
	VQUERX_DUAL1,
	VQUERX_DUAL2,
	/*		151 	*/
} V_QUEUE_ID;

/*=============================================================================+
|		View Flags																															 |
+==============================================================================*/


typedef
enum	{
	RealDataView = 0,
	TxChannel1 = 0, 	
    TxChannel2, 
	TxChannel3,
	TxChannel4,
	TxChannel5,
	TxChannel6,
	TxChannel7,
	TxChannel8,
	RxChannel1,	
	RxChannel2,    
	RxChannel3,	
	RxChannel4,
	RxChannel5,
	RxChannel6,
	RxChannel7,
    RxChannel8,
    EndChannel,
}	ring_no;

typedef
enum	{
	DpramRealDataView = 0,
	TxDPRAM1 = 0, 	
    TxDPRAM2, 
	TxDPRAM3,
	TxDPRAM4,
	TxDPRAM5,
	TxDPRAM6,
	TxDPRAM7,
	TxDPRAM8,
	RxDPRAM1,	
	RxDPRAM2,    
	RxDPRAM3,	
	RxDPRAM4,
	RxDPRAM5,
	RxDPRAM6,
	RxDPRAM7,
    RxDPRAM8,
    EndDPRAM,
}	dpr_ring_no;

typedef
enum	{
	SockRealDataView = 0,
	TxCh_Sock1 = 0, 		//	OPC1
	TxCh_Sock2, 		//	OPC2
	TxCh_Sock3, 		//	MTC1
	TxCh_Sock4, 		//	MTC2	
	TxCh_Sock5,			//	DTS1 
	TxCh_Sock6, 		//	DTS2
	TxCh_Sock7, 		//	RC1
	TxCh_Sock8,			//	RC2	
	TxCh_Sock9, 		//	DUAL1
	TxCh_Sock10, 		//	DUAL1	
	TxCh_Sock11, 		//	RBC1
	TxCh_Sock12, 		//	RBC2	
		
	RxCh_Sock1, 		//	OPC1
	RxCh_Sock2, 		//	OPC2
	RxCh_Sock3, 		//	MTC1
	RxCh_Sock4, 		//	MTC2
	RxCh_Sock5,			//	DTS1 
	RxCh_Sock6, 		//	DTS2
	RxCh_Sock7,			//	RC1
	RxCh_Sock8,			//	RC2	
	RxCh_Sock9, 		//	DUAL1
	RxCh_Sock10, 		//	DUAL2 
	RxCh_Sock11, 		//	RBC1
	RxCh_Sock12, 		//	RBC2 	
	SockEndChannel,
}	Sock_ring_no;


typedef
enum	{
	DebugView = 0,
	LAN_Debug,		//   LAN_TASK debug
	VME_Debug,		//	VME_TASK debug
	DRV_Debug,		//	DRV_TASK debug
	CPU_Debug,
	RC_Debug,	
	DebugEndChannel,
}	Debug_ring_no;


/* View Queue List for Extention Board(COM) */
#define		TXDEBUG		Debug_TX_QUE
#define		RXDEBUG		Debug_RX_QUE
#define 	TXQUE1		COM1_TX_QUE
#define 	RXQUE1		COM1_RX_QUE
#define 	TXQUE2		COM2_TX_QUE
#define 	RXQUE2		COM2_RX_QUE
#define 	TXQUE3		COM3_TX_QUE
#define 	RXQUE3		COM3_RX_QUE
#define 	TXQUE4		COM4_TX_QUE
#define 	RXQUE4		COM4_RX_QUE
#define 	TXQUE5		COM5_TX_QUE
#define 	RXQUE5		COM5_RX_QUE
#define 	TXQUE6		COM6_TX_QUE
#define		RXQUE6		COM6_RX_QUE
#define 	TXQUE7		COM7_TX_QUE
#define 	RXQUE7		COM7_RX_QUE
#define		TXQUE8		COM8_TX_QUE  
#define 	RXQUE8		COM8_RX_QUE    

/* View Queue List for Socket COMM (CPU Ethernet) */
#define 	TXOPC1		OPC1_TX_QUE
#define 	RXOPC1    	OPC1_RX_QUE
#define 	TXMTC1    	MTC1_TX_QUE
#define 	RXMTC1    	MTC1_RX_QUE
#define 	TXDTS1		DTS1_TX_QUE
#define 	RXDTS1    	DTS1_RX_QUE
#define 	TXRC1    	RC1_TX_QUE
#define 	RXRC1    	RC1_RX_QUE
#define 	TXDUAL1    	DUAL1_TX_QUE
#define 	RXDUAL1    	DUAL1_RX_QUE
#define 	TXOPC2    	OPC2_TX_QUE
#define 	RXOPC2    	OPC2_RX_QUE
#define 	TXMTC2	 	MTC2_TX_QUE
#define 	RXMTC2		MTC2_RX_QUE
#define 	TXDTS2    	DTS2_TX_QUE
#define 	RXDTS2    	DTS2_RX_QUE
#define 	TXRC2		RC2_TX_QUE
#define 	RXRC2		RC2_RX_QUE
#define 	TXDUAL2		DUAL2_TX_QUE
#define 	RXDUAL2		DUAL2_RX_QUE


/*=============================================================================+
|		Error																	|
+==============================================================================*/
typedef enum	{
	Ok = 0x0,					// �������� ó��
	Bad = 0xFF, 				// ���������� ó��
	NotFound = 0xA1,			// ������ ���� ��ã��.
	LengthErr,				// ���ŵ� ������ ���̰� ������ ������ ���� ����
	PortErr,					// �߸��� port�� access 
	CrcErr, 					// ���ŵ� CRC�� ���� �ǹٸ��� ����
	TimeOutErr, 				// ������ �ð����� ������ �������� ����
	OpCodeErr,				// ������ op code�� ���� ����
	BufferFullErr,				// ���̻� buffer�� �߰� �Ҵ�
	BufferEmptyErr, 			// buffer�� data�� ����
	CalCrcErr,				// CRC ������ �߸� �Ǿ��� ��
	StxErr, 					// ���ŵ� STX Field �� STX �� ���� ����
	SubOpcodeErr,			// ������ sub opcode�� ���� ����
	DataCodeErr,				// ������ data�� ���� ����
	RetryErr,					// ��õ� error
	EtxErr, 					// ���ŵ� ETX Field �� ETX �� ���� ����  
	SeqErr, 					// Sequence error
}	error;

/*=============================================================================+
|		Communication Protocol define																							 |
+==============================================================================*/
/****************** Header and Tailer ******************/
typedef enum
{
	Stx = 0x02, 			// Msg Stx
	Etx = 0x03, 			// Msg Etx
}Msg_Field_defined;


/****************** OP code ******************/
typedef enum
{
	/* ============ Common ============ */
	AYT 						= 0xAC, // AYT
	ACK 						= 0xA0, // ACK
	NAK 						= 0xA7, // NAK
}Msg_OPcode_defined;

	
/****************** Sub OP code ******************/
typedef enum
{
	CON_OP_MODE = 0x1, // � ��� ��ü
	CON_OP_SW	= 0x2, // ������ȯ�� ����
	CON_OP_RO	= 0x3, // ���� ���� �� ����
	CON_OP_ETK	= 0x4, // �˵� ��� ����
	CON_OP_TSR	= 0x5, // �ӽüӵ����� ���� �� ����
	CON_OP_EMS	= 0x6, // ������� ���� �� ����
}Msg_SubOP_defined;
	

/****************** Indication Type for Simulator ******************/
typedef enum
{
	IND_MODE	= 0x0, // ���� ��������
	IND_SIG		= 0x1, // ��ȣ�� ��������
	IND_SW		= 0x2, // ������ȯ�� ��������
	IND_RO		= 0x3, // ���� ��������
	IND_TD		= 0x4, // �˵� ��������
	IND_TRS		= 0x5, // �ӽüӵ����� ��������
	IND_EMS		= 0x6, // ������� ��������
	IND_DL		= 0x7, // ������ (Dwell Light) ��������
	IND_EIE		= 0x8, // ���ڿ�����ġ ��������
	IND_PW		= 0x9, // ������ġ ��������
}Msg_Indication_defined;


/****************** Schedule Type ******************/
typedef enum
{
	WeekDay 	= 0x31, // ����
	WeekEnd 	= 0x32, // �ָ�
	HoliDay		= 0x33, // ����, �Ͽ���
	SpecialDay	= 0x34, // Ư����
	LineDown	= 0x35, // ����
}SCH_Type_defined;

typedef struct{
	long    data_type;
	uchar	Stx;
	uchar	Length;
	uchar	Seq;
	uchar	Opcode;
	uchar	Data[MAX_MSG_LENGTH]; /* crc, etx ���� */
}NEW_COMM_MSG;

typedef struct{
	long  data_type;					// Data Type �� CR or CC �� ��� 0x01, Datagram �ΰ�� 0x02
	uchar	S_Data[MAX_MSG_LENGTH]; 	// Test Data
}S_COMM_MSG;


typedef struct{
	long    data_type;					// Data Type �� CR or CC �� ��� 0x01, Datagram �ΰ�� 0x02
	uchar	H_STX;						// Packet Header , STX
	uchar	H_SenderID;					// Sender ID	
	uchar	H_ReceiverID;				// Receiver ID		
	uchar	H_SEQ;						// Seq#
	uchar	H_OP_CODE;					// function code ID
	uchar	H_LENGTH[2];				// Length = H_SenderID ~ Data[var]
	uchar 	D_Data[MAX_MSG_LENGTH]; 	// User Data Part, Max Data Size (1024 - 9) bytes, include CRC32(4) and ETX
}COMM_MSG;								// Total 11 + 1024(max) bytes

typedef struct {
	long    data_type;			// Data Type �� CR or CC �� ��� 0x01, Datagram �ΰ�� 0x02	
	uchar 	ucSTX;				/** 0, �޽��� �������� ���� ����, STX=0x02 ������ */
	uchar	ucSenderID;			/** 1, �޽��� �������� �߽��� ID */
	uchar	ucReceiverID;		/** 2, �޽��� �������� ������ ID */
	uchar	ucSequenceNo;		/** 3, �޽��� �������� ������ȣ, 0x04~ox7F, ��, Initial Polling �޽����� 0x00  */
	uchar	ucFunctionCode;		/** 4, �޽��� �������� ����ڵ� */
	ushort	usLength;			/** 5~6, �޽��� �������� ������ ������, �߽��� ID ���� CRC �ʵ�(Field) ������ ������ �ʵ�(Field)������ Byte Size */		
	uchar 	ucData[MAX_MSG_LENGTH]; 	
	uchar	ucCRC32[4];			/** data low => uchCRC32[0], data high => uchCRC32[3] */	
	uchar 	ucETX;				/** 11, �޽��� �������� ���� ����, ETX=0x03 ������ */
} COMM_MSG_FRAME;


typedef struct{
	long    data_type;
	uchar	Length;
	uchar	Data[250]; /* crc, etx ���� */
}NEW_INTER_MSG;

typedef struct{
	long    data_type;
	int		date_length;
	uchar	Data[MAX_MSG_LENGTH+6];	
}INTER_MSG;

typedef struct{
	long    data_type;
	uchar	Data[2]; 
}STATUS_MSG;

typedef struct{
	long    data_type;
	uchar	Data; 
}CHAR_MSG;

typedef struct{
	long    data_type;
	uchar	Data[MAX_MSG_LENGTH+6]; 
}WORD_MSG;

typedef struct lingerStruct
{
	 int l_onoff;						 // linger �ɼ� ����(l_onoff = 1), ����(l_onoff=0)
	 int l_linger;						 // linger timeout
}LINGER;							// SO_LINGER �ɼ� ����ü


/*-----------------------------------------------------------------------------+
|	����� ���� �ƴ����� ��Ÿ���� flag�� ����								   |
+------------------------------------------------------------------------------*/
typedef
enum	{
	Usable		= 0,
	InUse,
	UnUsable	= -1
}	use;

/*-----------------------------------------------------------------------------+
|	������ position 														   |
+------------------------------------------------------------------------------*/
typedef
enum	{
	NonArray		  = 1,	  /* ������ array�� �ƴϴ�.*/
	VarNamePosEach	  = 3,
	VarNamePos		  = 5,	  /* �߻��� ������ �̸��� ȭ�� ��ġ*/
	VarArrayPosEach   = 36,   /* array�� ��ȣ�� �� ��ġ*/
	VarArrayPos 	  = 40,   /* array�� ��ȣ�� �� ��ġ*/
	VarValuePosEach   = 41,   /* ������ ���� ���� ������ �� ��ġ*/
	VarHexPos		  = 44,   /* 16������ ���� �� ��ġ*/
	VarValuePos 	  = 45,   /* ������ ���� ���� ������ �� ��ġ*/
	VarDecPos		  = 52,   /* 10������ ���� �� ��ġ*/
	VarMsgSize		  = 82,   /* �ϳ��� ���� message�� �ѱ���*/
	VarFileCirculated,
	VarMsgEntries	  = 100,/* ������ ���� message�� �� ����*/
	MaxVarSize		  = 256 /* array�� ��� �ִ� ����*/
}	var_position;


/*-----------------------------------------------------------------------------+
| ��, ���� frame�� PAC port�� �Ѹ��� ���� format							   |
+------------------------------------------------------------------------------*/
typedef
enum	{
	ViewCountPos	= 1,
	ViewDataWidth	= 3,
	ViewChannelPos	= 3,
	ViewTxRxPos 	= 6,
	ViewDataPos2	= 4,	
	ViewBoundary	= 7,
	ViewDataPos 	= 9,
	ViewLineEntries = 16,
	ViewAsciiPos	= 59,
	ViewContents	= 76,
	ViewDataLength	= 13+MAX_MSG_LENGTH,
}	viewdata;


/*-----------------------------------------------------------------------------+
|	variable data���� ���													   |
+------------------------------------------------------------------------------*/
typedef
enum	{
	Single			= 0 ,	/* VAR_ATTR�� size field*/
							/* VAR_ATTR�� operating�� operand field*/
	Bit 				,	/* �� bit���� �ǹ̸� �������*/
	Ordinary			,	/* �ش� �� ��ü�� �ǹ̸� ���� ���*/
	NonDecode			,	/* �� ��ü�� ascii�� �ٲپ� �ִ� ���*/
}		operating;
/*-----------------------------------------------------------------------------+
|	���� ���� -- variable data���� ��� 									   |
+------------------------------------------------------------------------------*/

typedef enum{
	UARTCh01 = 1, 	
	UARTCh02 = 2, 	
	UARTCh03 = 3,	
	UARTCh04 = 4,	
	UARTCh05 = 5, 	
	UARTCh06 = 6, 	
	UARTCh07 = 7,		
	UARTCh08 = 8,	
}UARTChType;

/*-----------------------------------------------------------------------------+
| �̺κ��� ���� error�� define�ص� �ǳ� assembley�� �ۼ��� interrupt		   |
| service routine�� �����ؾ��ϴ� �κ��̹Ƿ� �и��ؼ� ����					   |
+------------------------------------------------------------------------------*/
typedef
enum	{
	FormatErr	= 0x01,
	ChecksumErr = 0x10,
	FrameErr	= 0x20,
	OverrunErr	= 0x40,
	BreakErr	= 0x80
}	comm_err;

/*-----------------------------------------------------------------------------+
| error message ���� �� ��ġ												   |
+------------------------------------------------------------------------------*/
typedef
enum	{
	RoutinePos		= 0,   /* error�� �߻��� routine�� �̸�*/
	ErrorKindPos	= 20,  /* enum���� ���ǵ� error*/
	SpecificPos 	= 40,  /* ErrorKind �̿ܿ� �����̰� ���� message*/
	TimePos 		= 61,	/* error�� �߻��� �ð�*/
	ErrMsgSize		= 84,	 /* error message�� �ѱ���*/
	ErrFileCirculated,
	NextPointContinue,
	ErrMsgEntries	= 256 /* ������ error message�� �� ����*/
}	error_position;

#define 	MAX_ELEMENT_NUM		1024



/*=============================================================================+
|		System status table 																											 |
+==============================================================================*/
typedef
union
{
	struct
	{
	unsigned SystemChange : 1;	/* ��Ʈ#1 ~ #8 ���� �ٲ��Change/Nochange */
								/* ���º�ȭ�� ������ ������ Change�ϰ� */
								 
	unsigned SystemSwitch : 1;	/* ����ü�� ��Ʈ��. */
								 
	unsigned CpuPriSts	  : 1;	/* Pri cpu�� ���¸� ��Ÿ�� Alive/Die */
								/* Self Process���� �����Ѵ�. */
								 
	unsigned CpuSecSts	  : 1;	/* Sec cpu�� ���¸� ��Ÿ�� Alive/Die */
								/* DstsDrv���� �����Ѵ�. */
								 
	unsigned reserved : 1;	/* bit3 reserved */
								 
	unsigned CpuDuty	  : 1;	/* bit2 ���� Running ���� CPU�� ��Ÿ��. Pri/Sec */
								 
	unsigned MyLine 	  : 1;	/* bit1 ���� �ڽ��� �踦 ��Ÿ����. Pri/Sec */
								/* self process���� ������. */
								 
	unsigned OtherCpuSts	: 1;  /* bit0 ��� CPU �� ��� ���¸� ��Ÿ�� Alive/Die */
								/* CpuProc���� �����Ѵ�. */
								 
	unsigned EventSts	  : 1;	/* bit7��� cpu�� �ǰ� ���¸� ��Ÿ�� Alive/Die */
								/* self process���� �����Ѵ�. */
								 
	unsigned DropReq	  : 1;	/* bit6 ����ü �䱸 */
		unsigned						: 6;
	}	SSfield ;
	uint	SSunion ;
} StatusSystemUnion ;
	
	
/*=============================================================================+
|		FOR DRIVER TASK SPAWNING																									 |
+==============================================================================*/


typedef 	struct	{
			int 	port_name;
			int 	size;
			uchar	ch[ViewDataLength - 1];
}	VIEW_LIST;

/*-----------------------------------------------------------------------------+
| ring buffer �� ���� ����													   |
+------------------------------------------------------------------------------*/
typedef struct		{
	ushort		front_counter;				/* ring buffer�� data�� �Է��� ��ġ */
	ushort		rear_counter;				/* ring buffer���� data�� ����� ��ġ*/
	uchar	contents[RING_DATA_SIZE];	/* data*/
}	RING_BUFFER;

/*-----------------------------------------------------------------------------+
|	�� ���� ���¿� ���� ����												   |
+------------------------------------------------------------------------------*/
typedef struct		{
	int 	state_name;
	char	state_explain[VarMsgSize];	/* ������ ���� ascii code*/
}	VAR_STATUS;


/*-----------------------------------------------------------------------------+
|	���� ���� ������ �Ӽ�													   |
+------------------------------------------------------------------------------*/
typedef struct		{
	void		*name;			/* ������ �̸� */
	int 		size;			/* ������ ����*/
	operating	operand;		/* bit operation�ΰ�?*/
	int 		pass_num;		/* ������ ������ ����*/
	uchar		msg[VarMsgSize];/* ������ �� ����*/
	VAR_STATUS	*var_status;	/* ������ ����*/
}	VAR_ATTR;

/*-----------------------------------------------------------------------------+
|	�� port�� ��, ���� data�� ������ ���� ����								   |
+------------------------------------------------------------------------------*/
typedef struct		{
	time_t		time;
	int 		size;
	uchar		ch[13+MAX_MSG_LENGTH];
}	VIEW_MSG;


/*-----------------------------------------------------------------------------+
|	Log information for DT_logger													   |
+------------------------------------------------------------------------------*/
typedef struct		{
	long    data_type;  	
	int 		size;
	uchar	CH_INFO;
	uchar	CH_TYPE;
	uchar	    Data[13+MAX_MSG_LENGTH];
}	LOG_INFORM;

/*-----------------------------------------------------------------------------+
|	View information														   |
+------------------------------------------------------------------------------*/
#if FOR_LINUX
typedef struct		{
	long    data_type;  	
	int			queue;
	int 		size;
	uchar	    ch[13+MAX_MSG_LENGTH];
}	VIEW_INFORM;
#else
typedef struct		{
	MessageQ_MsgHeader	reserved;
	long	data_type;
	int 		queue;
	int 		size;
	uchar		ch[13+MAX_MSG_LENGTH];
}	VIEW_INFORM;
#endif	


/*-----------------------------------------------------------------------------+
| �ϳ��� error message														   |
+------------------------------------------------------------------------------*/
typedef struct	{
	uchar		msg[ErrMsgSize];
}	ERROR_MSG;

/*-----------------------------------------------------------------------------+
| �� error�� ������ ���� ����												   |
+------------------------------------------------------------------------------*/
typedef struct		{
	uchar		kind;				/* error �� ���� */
	char		explain[ErrMsgSize];/* error�� ���� ascii code */
}	ERROR_INFORM;
	
/*-----------------------------------------------------------------------------+
| error message�� �����ϱ� ���� ring ����									   |
+------------------------------------------------------------------------------*/
typedef struct		{
	uchar		push_counter;	/* ������ ���� error message�� ��ġ*/
	uchar		full;			/* ring�� ä���������� ��Ÿ���� flag*/
	uchar		time[22];
	int 		reset_count;	/* reset �� Ƚ���� ����*/
	uint		checksum;		/* ��� error message�� ���� checksum*/
								/* battery backup �� memory�� ���� check*/
								/* �Ҷ� ���*/
	ERROR_MSG	entry[ErrMsgEntries];/* error message ��ü*/
}	ERROR_FILE;

typedef struct qheader
{
   char *base;		   /* volatile version of qkheader.base    */
   size_t width;	   /* volatile version of qkheader.width   */
   int depth;		   /* volatile version of qkheader.depth   */
   int putndx;		   /* internal use, initially = depth - 1  */
   int curndx;		   /* internal use, initially = 0		   */
   int *waiters;		/* priority list of waiting tasks		*/
   int *dummy;			/* reserved - must follow *waiters		*/

   unsigned int count; /* statistics - count */
   int worst;		   /* statistics - worst case full level */
} QHEADER;


typedef struct {
	int tm_sec; /* seconds after the minute - [0,59] */
	int tm_min; /* minutes after the hour - [0,59] */
	int tm_hour;	/* hours since midnight - [0,23] */
	int tm_mday;	/* day of the month - [1,31] */
	int tm_mon; /* months since January - [0,11] */
	int tm_year;	/* years since 1900 */
	int tm_wday;	/* days since Sunday - [0,6] */
	int tm_yday;	/* days since January 1 - [0,365] */
	int tm_isdst;	/* daylight savings time flag */
}tm;


typedef enum 
{
 	COMM_FAIL = 0,

} AlarmType;
	
typedef enum 
{
	ON=1, OFF /* sbkim */
} OnOff;

typedef struct	{
	uchar		   name[8];
	int 		   errNum;	
}PORT_INFO;

typedef struct	{
	uchar		   name[20];
	int 		   errNum;	
}Socket_PORT_INFO;


typedef struct	{
	int   qid;
	int      	   numMsgs;
	uchar           name[15];
}QUE_INFO;


typedef struct	{
	char *Control_Zone[8];	/* Board Section_Param(string) */
	char Station_ID; 		/* Station ID ���� */
	char *Station_Name[15];	/* Station Name ���� */
	char *Station_Type[3];		/* Station Type ���� */
	/* Host IP */
	char *Host_ip_0[16];		/* Ethernet 0 IP Address ���� */
	char *Host_ip_1[16];		/* Ethernet 1 IP Address ���� */
	char *Host_ip_2[16];		/* Ethernet 2 IP Address ���� */
	char *Host_ip_3[16];		/* Ethernet 3 IP Address ���� */
	char *Host_ip_4[16];		/* Ethernet 4 IP Address ���� */
	char *Host_ip_5[16];		/* Ethernet 5 IP Address ���� */
	/* Host Port */
	char *Host_port_0[10];		/* Ethernet 0 port ���� */
	char *Host_port_1[10];		/* Ethernet 1 port ���� */
	char *Host_port_2[10];		/* Ethernet 2 port ���� */
	char *Host_port_3[10];		/* Ethernet 3 port ���� */
	char *Host_port_4[10];		/* Ethernet 4 port ���� */
	char *Host_port_5[10];		/* Ethernet 5 port ���� */
	/* Destination IP */
	char *OPC1_Line_ip[16]; 		/* OPC 1 Line ip ���� */
	char *OPC2_Line_ip[16]; 		/* OPC 2 Line ip ���� */
	char *OPC1_Line_Other_ip[16]; 	/* OPC 1 Line ip ���� */
	char *OPC2_Line_Other_ip[16]; 	/* OPC 2 Line ip ���� */	
	char *MTC1_Line_ip[16]; 		/* MTC 1 Line ip ���� */
	char *MTC2_Line_ip[16]; 		/* MTC 2 Line ip ���� */
	char *MTC1_Line_Other_ip[16]; 	/* MTC 1 Line ip ���� */
	char *MTC2_Line_Other_ip[16]; 	/* MTC 2 Line ip ���� */		
	char *DTS1_Line_ip[16]; 		/* DTS 1 Line ip ���� */
	char *DTS2_Line_ip[16]; 		/* DTS 2 Line ip ���� */
	char *RC1_Line_ip[16]; 			/* RC 1 Line ip ���� */
	char *RC2_Line_ip[16]; 			/* RC 2 Line ip ���� */
	char *RC1_Line_Other_ip[16]; 	/* RC 1 Line ip ���� */
	char *RC2_Line_Other_ip[16]; 	/* RC 2 Line ip ���� */		
	char *DUAL1_Line_ip[16]; 		/* DUAL 1 Line ip ���� */
	char *DUAL2_Line_ip[16]; 		/* DUAL 2 Line ip ���� */
	char *RBC1_Line_ip[16]; 		/* RBC 1 Line ip ���� */
	char *RBC2_Line_ip[16]; 		/* RBC 2 Line ip ���� */
	char *RBC1_Line_Other_ip[16]; 	/* RBC 1 Line ip ���� */
	char *RBC2_Line_Other_ip[16]; 	/* RBC 2 Line ip ���� */			
	/* Destination Port */
	char *OPC1_Line_Port[10];		/* OPC 1 Line Port ���� */
	char *OPC2_Line_Port[10];		/* OPC 2 Line Port ���� */
	char *OPC1_DST_Port[10];		/* OPC 1 Destination Port ���� */
	char *OPC2_DST_Port[10];		/* OPC 2 Destination Port ���� */
	char *OPC1_DST_Other_Port[10];	/* OPC 1 Destination Port ���� */
	char *OPC2_DST_Other_Port[10];	/* OPC 2 Destination Port ���� */	
	char *MTC1_Line_Port[10];		/* MTC 1 Line Port ���� */
	char *MTC2_Line_Port[10];		/* MTC 2 Line Port ���� */
	char *MTC1_DST_Port[10];		/* MTC 1 Destination Port ���� */
	char *MTC2_DST_Port[10];		/* MTC 2 Destination Port ���� */
	char *MTC3_Line_Port[10];		/* MTC 1 Line Port ���� */
	char *MTC4_Line_Port[10];		/* MTC 2 Line Port ���� */
	char *MTC3_DST_Port[10];		/* MTC 1 Destination Port ���� */
	char *MTC4_DST_Port[10];		/* MTC 2 Destination Port ���� */	
	char *DTS1_Line_Port[10];		/* DTS 1 Line Port ���� */
	char *DTS2_Line_Port[10];		/* DTS 2 Line Port ���� */
	char *DTS1_DST_Port[10];		/* DTS 1 Destination Port ���� */
	char *DTS2_DST_Port[10];		/* DTS 2 Destination Port ���� */
	char *RC1_Line_Port[10];		/* RC 1 Line Port ���� */
	char *RC2_Line_Port[10];		/* RC 2 Line Port ���� */
	char *RC1_DST_Port[10];			/* RC 1 Destination Port ���� */
	char *RC2_DST_Port[10];			/* RC 2 Destination Port ���� */
	char *RC1_DST_Other_Port[10];	/* RC 1 Destination Port ���� */
	char *RC2_DST_Other_Port[10];	/* RC 2 Destination Port ���� */		
	char *RBC1_Line_Port[10];		/* RBC 1 Line Port ���� */
	char *RBC2_Line_Port[10];		/* RBC 2 Line Port ���� */
	char *RBC1_Other_Line_Port[10];		/* RBC 1 Line Port ���� */
	char *RBC2_Other_Line_Port[10];		/* RBC 2 Line Port ���� */	
	char *RBC1_DST_Port[10];		/* RBC 1 Destination Port ���� */
	char *RBC2_DST_Port[10];		/* RBC 2 Destination Port ���� */	
	char *RBC1_DST_Other_Port[10];	/* RBC 1 Destination Port ���� */
	char *RBC2_DST_Other_Port[10];	/* RBC 2 Destination Port ���� */	
	char *DUAL1_Line_Port[10];		/* DUAL1 Line Port ���� */
	char *DUAL2_Line_Port[10];		/* DUAL 2 Line Port ���� */
	char *DUAL1_DST_Port[10];		/* DUAL 1 Destination Port ���� */
	char *DUAL2_DST_Port[10];		/* DUAL 2 Destination Port ���� */
}HOST_INFO;

//extern HOST_INFO	Host_Info;

typedef /* board�� �ֺ� ��ġ�� ���¸� ��Ÿ���� ����ü��. */
struct{
	uchar				DiN;
	uchar				DoN;
	uchar				TsK;
	uchar               EisStatus[2];
}	StssS ;

typedef enum	
{
	OPC_Report = 0,
	MTC_Report,
	DTS_Report,
	RC_Report,
	EndofReportList
}Report_Type_List;


typedef struct{
	int			MsgQId[NumOf_Queue];
	QUE_INFO	QueInfo[EndofQueueID];
	LINE_STAT	LineStat[EndofLineStat];
	int 		VME_A_WARN_ENABLE[EndDPRAM+1];		/*	for Serial IF	*/
	int 		VME_B_WARN_ENABLE[EndDPRAM+1];		/*	for Serial IF	*/	
	int 		S_WARN_ENABLE[EndChannel+1];		/*	for Serial IF	*/
	int 		S_VIEW_ENABLE[RxChannel8+1];		/*	for Serial IF, port�� data�� ȭ�� logging ����	*/
	int 		E_WARN_ENABLE[SockEndChannel+1];	/*	for Ethernet IF 	*/
	int 		E_VIEW_ENABLE[RxCh_Sock8+3];	/*	for Ethernet IFport�� data�� ȭ�� logging ����	*/
	int 		Debug_ENABLE[DebugEndChannel+1];	/*	for Ethernet IF 	*/
	int			Debug_EnableFlag[255];
	int 		VME_WARNNING_ENABLE;	   /* error ������ ȭ�� logging ����*/
	int 		S_WARNNING_ENABLE;	   /* error ������ ȭ�� logging ����*/
	int			E_WARNNING_ENABLE;
	int			D_WARNNING_ENABLE;
	int       	runbugflag;   /* console���� ����� �������� flag, �ʱⰪ = 0 */
	uchar		COMM_STAT;
	uchar		COMM_IF_STAT;
	uchar 		ChangedMyStatus;
	uchar		OpcRemoteCtrlFlag;
	uchar		View_Flag;
	LINE_INFO	OTHER_LINE_STATE[EndofLineStat];
	uchar		OTHER_COMM_STATE[2];
	uchar		OTHER_COMM;
	uchar		MY_LINE;
	uchar		MASTER_INPUT_STATE;
	uchar		real_data_view;
	uchar		SockReal_data_view;
	uchar		SYSTEMSWITCH;
	uchar 		ChangeDevice;
	uchar		AlarmCode[25];
	uchar		ucExtInterface[4];	
	int 		MaxTaskNum;
	int 		MaxLineNum;
	uchar		Interface_to_EIS;
	StatusSystemUnion	SystemStatus;
	HOST_INFO	Host_Info;
	TASK_INFO	TaskInfo[10];
	LINE_INFO	LineInfo[EndofLineStat];
	FSC_Device_INFO FSC_Run_Info;
	uchar		Section_Param[8];
	uchar		Revision[3][VarMsgSize];
	PORT_INFO	portInfo[10];
	Socket_PORT_INFO Sock_portInfo[15];
	RETRY_INFO	status_report[EndofLineStat];
	uchar		LAN_Client_Sts[EndofLineStat];
	int	 I2C_File;
	struct timeval time_tx_start;
	struct timeval time_tx_end;  
	struct timeval time_rx_start;
	struct timeval time_rx_end;  	
}SHM_MSG;


typedef struct{
	void		*FPGA_MEM_BASE;
	int			FPGA_MEM_FD;
	off_t 		FPGA_MAP_TARGET;
	void		*UART_MEM_BASE;
	int			UART_MEM_FD;
	off_t 		UART_MAP_TARGET;
	volatile uchar *Version;
	volatile uchar *TEST0;
	volatile uchar *TEST1;
	volatile uchar *TEST2;
	volatile uchar *TEST3;
	volatile uchar *TEST4;
	volatile uchar *TEST5;
	volatile uchar *TEST6;
	volatile uchar *DI;
	volatile uchar *DO;
	volatile uchar *RS422_ENABLE0;
	volatile uchar *RS422_ENABLE1;
	volatile uchar *RS422_MODE;
	volatile uchar *RS422_CLK;
	volatile uchar *RS422_LED;
	volatile uchar *RS422_LED_CON;
	volatile uchar *RS422_TERM_CON;
	volatile uchar *APP_SW;
	volatile uchar *FND_ENABLE;
	volatile uchar *FND_LED;
	volatile uchar *STATUS_LED;
	volatile uchar *LED_BLANK;	
	volatile int *WDT_CON;	
	volatile int *WDT_TIMER;	
	void		*VME0_MEM_BASE;
	int			VME0_MEM_FD;
	off_t		VME0_MAP_TARGET;	
	volatile uchar *VME0_BUFF;
//	uchar *VME0_BUFF;
	void		*VME1_MEM_BASE;
	int			VME1_MEM_FD;
	off_t		VME1_MAP_TARGET;		
	volatile uchar *VME1_BUFF;
//	uchar *VME1_BUFF;
}FPGA_REG;


typedef struct{
	uchar 	TxChFlag[8];
	uchar 	RxChFlag[8];
 	RING_BUFFER TX_BUFFER[8];
  	RING_BUFFER RX_BUFFER[8];
}SHM_RING_BUF;

typedef struct{
	uchar 	VmeTxData[4][MAX_MSG_LENGTH];
	uchar 	VmeRxData[4][MAX_MSG_LENGTH];	
}SHM_DP_RAM;


