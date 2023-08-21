/*-----------------------------------------------------------------------------+
|                 CopyRight ⓒ DaeaTi Co., Ltd.                                |
|                 All Rights Reserved                                          |
+------------------------------------------------------------------------------+
| FILE        : comlib.c                                                       |
| DIRECTORY   : 													           |
| PROCESS     :                                                                |
| 고 객 명    : 부산교통공사                                                         
| PROJECT     : 부산도시철도 1호선 개량 신호설비 기자재 구매                                                 
| 작성 일자   : 2016.06.01                                                    
| 작 성 자    :  이창수                                                                    |
| SYSTEM 정보 : 개발 환경 - PC                                                 |
|               운영 쳬제 - Linux                                            
|               TARGET    - TI-AM5K2E04	 								       
|               LANGUAGE  -   C language                                       |
+------------------------------------------------------------------------------+
| 1. FUNCTION DESCRIPTION                                                      |
|																			   |
| 2. 소속 함수                                                                 |
|																			   |
| 3. Routine Tree                                                              |
|    Init                                                                      |
+------------------------------------------------------------------------------*/

#include	"define.h"
#include	"proto.h"

uint CalcCRC32 (const uchar* block, uint length);
void chksum_crc32gentab ();

/* define POLYNOMIAL value */
#define POLYNOMIAL	0x04C11DB7LU

/* crc32 table */
static uint guiCrcTable[256U];

SHM_MSG		*ShmMsg;
SHM_RING_BUF	*ShmDrvMsg;
FPGA_REG		*CommonReg;

static uint crc_tab[256];
static uint isFirstCallCRC32GenTab = 1;

int I2C_Filename;
int adapter_nr = 0; // lenny - change 2 to 0
uchar rtc_reg_list[7] = { 0, };
char day_str[8] = "-SMTWTFS";

#define GPIO_SEGMENT_7_NUM	8
#define SEGMENT_NUMBER	16
static int segmentNumber[SEGMENT_NUMBER][GPIO_SEGMENT_7_NUM] = {	//  DP ; toggle  ,  0 : led on , 1 : led off
			{0, 0, 0, 0, 0, 0, 0, 1},	// 0 
			{1, 1, 0, 0, 1, 1, 1, 1},	// 1
			{1, 0, 0, 1, 0, 0, 1, 0},	// 2
			{1, 0, 0, 0, 0, 1, 1, 0},
			{1, 1, 0, 0, 1, 1, 0, 0},
			{1, 0, 1, 0, 0, 1, 0, 0},	// 5
			{1, 0, 1, 0, 0, 0, 0, 0},
			{1, 0, 0, 0, 1, 1, 1, 1},
			{1, 0, 0, 0, 0, 0, 0, 0},
			{1, 0, 0, 0, 0, 1, 0, 0},
			{1, 0, 0, 0, 0, 0, 1, 0},	// a 
			{1, 1, 1, 0, 0, 0, 0, 0},	// b
			{1, 1, 1, 1, 0, 0, 1, 0},	// c
			{1, 1, 0, 0, 0, 0, 1, 0},
			{1, 0, 0, 1, 0, 0, 0, 0},
			{1, 0, 1, 1, 1, 0, 0, 0}	// f
};

// 382:STS1, 383:STS2, 384:ALARM
unsigned int gpio_array[GPIO_NUM] = { 382, 383, 384 };
unsigned int gpio_dipsw[] = {354, 355, 356, 357, 358, 359, 360, 361};
unsigned int gpio_run_status[] = {386, 387};	// 396 : RUN , 397 : STATUS
unsigned int gpio_segment_7[GPIO_SEGMENT_7_NUM] = {504, 505, 506, 507, 508, 509, 510, 511};
unsigned int gpio_do[] = {494, 495, 496, 497};
unsigned int gpio_di[] = {498, 499, 500, 501};
unsigned int gpio_uart_hdlc = 486;
unsigned int gpio_hdlc_type[] = {502, 503};
unsigned int gpio_vme_client = 487;
unsigned int gpio_vme_master_dtack[] = {488, 489};
unsigned int gpio_vme_memory_size[] = {492, 490};
unsigned int gpio_vme_dtack_clear[] = {484, 485};

static unsigned short    crc_table_for_cdts[256];             /* 0 ~ 255 의 data에 대한 crc 환산표*/

static unsigned int crc_table[256] = {0x0000,
 0xC0C1, 0xC181, 0x0140, 0xC301, 0x03C0, 0x0280, 0xC241,
 0xC601, 0x06C0, 0x0780, 0xC741, 0x0500, 0xC5C1, 0xC481,
 0x0440, 0xCC01, 0x0CC0, 0x0D80, 0xCD41, 0x0F00, 0xCFC1,
 0xCE81, 0x0E40, 0x0A00, 0xCAC1, 0xCB81, 0x0B40, 0xC901,
 0x09C0, 0x0880, 0xC841, 0xD801, 0x18C0, 0x1980, 0xD941,
 0x1B00, 0xDBC1, 0xDA81, 0x1A40, 0x1E00, 0xDEC1, 0xDF81,
 0x1F40, 0xDD01, 0x1DC0, 0x1C80, 0xDC41, 0x1400, 0xD4C1,
 0xD581, 0x1540, 0xD701, 0x17C0, 0x1680, 0xD641, 0xD201,
 0x12C0, 0x1380, 0xD341, 0x1100, 0xD1C1, 0xD081, 0x1040,
 0xF001, 0x30C0, 0x3180, 0xF141, 0x3300, 0xF3C1, 0xF281,
 0x3240, 0x3600, 0xF6C1, 0xF781, 0x3740, 0xF501, 0x35C0,
 0x3480, 0xF441, 0x3C00, 0xFCC1, 0xFD81, 0x3D40, 0xFF01,
 0x3FC0, 0x3E80, 0xFE41, 0xFA01, 0x3AC0, 0x3B80, 0xFB41,
 0x3900, 0xF9C1, 0xF881, 0x3840, 0x2800, 0xE8C1, 0xE981,
 0x2940, 0xEB01, 0x2BC0, 0x2A80, 0xEA41, 0xEE01, 0x2EC0,
 0x2F80, 0xEF41, 0x2D00, 0xEDC1, 0xEC81, 0x2C40, 0xE401,
 0x24C0, 0x2580, 0xE541, 0x2700, 0xE7C1, 0xE681, 0x2640,
 0x2200, 0xE2C1, 0xE381, 0x2340, 0xE101, 0x21C0, 0x2080,
 0xE041, 0xA001, 0x60C0, 0x6180, 0xA141, 0x6300, 0xA3C1,
 0xA281, 0x6240, 0x6600, 0xA6C1, 0xA781, 0x6740, 0xA501,
 0x65C0, 0x6480, 0xA441, 0x6C00, 0xACC1, 0xAD81, 0x6D40, 
 0xAF01, 0x6FC0, 0x6E80, 0xAE41, 0xAA01, 0x6AC0, 0x6B80,
 0xAB41, 0x6900, 0xA9C1, 0xA881, 0x6840, 0x7800, 0xB8C1,
 0xB981, 0x7940, 0xBB01, 0x7BC0, 0x7A80, 0xBA41, 0xBE01,
 0x7EC0, 0x7F80, 0xBF41, 0x7D00, 0xBDC1, 0xBC81, 0x7C40,
 0xB401, 0x74C0, 0x7580, 0xB541, 0x7700, 0xB7C1, 0xB681,
 0x7640, 0x7200, 0xB2C1, 0xB381, 0x7340, 0xB101, 0x71C0,
 0x7080, 0xB041, 0x5000, 0x90C1, 0x9181, 0x5140, 0x9301,
 0x53C0, 0x5280, 0x9241, 0x9601, 0x56C0, 0x5780, 0x9741,
 0x5500, 0x95C1, 0x9481, 0x5440, 0x9C01, 0x5CC0, 0x5D80,
 0x9D41, 0x5F00, 0x9FC1, 0x9E81, 0x5E40, 0x5A00, 0x9AC1,
 0x9B81, 0x5B40, 0x9901, 0x59C0, 0x5880, 0x9841, 0x8801,
 0x48C0, 0x4980, 0x8941, 0x4B00, 0x8BC1, 0x8A81, 0x4A40,
 0x4E00, 0x8EC1, 0x8F81, 0x4F40, 0x8D01, 0x4DC0, 0x4C80,
 0x8C41, 0x4400, 0x84C1, 0x8581, 0x4540, 0x8701, 0x47C0,
 0x4680, 0x8641, 0x8201, 0x42C0, 0x4380, 0x8341, 0x4100,
 0x81C1, 0x8081, 0x4040};

static unsigned int dual_crc_table[256] = {0x0000,
 0xC0C1, 0xC181, 0x0140, 0xC301, 0x03C0, 0x0280, 0xC241,
 0xC601, 0x06C0, 0x0780, 0xC741, 0x0500, 0xC5C1, 0xC481,
 0x0440, 0xCC01, 0x0CC0, 0x0D80, 0xCD41, 0x0F00, 0xCFC1,
 0xCE81, 0x0E40, 0x0A00, 0xCAC1, 0xCB81, 0x0B40, 0xC901,
 0x09C0, 0x0880, 0xC841, 0xD801, 0x18C0, 0x1980, 0xD941,
 0x1B00, 0xDBC1, 0xDA81, 0x1A40, 0x1E00, 0xDEC1, 0xDF81,
 0x1F40, 0xDD01, 0x1DC0, 0x1C80, 0xDC41, 0x1400, 0xD4C1,
 0xD581, 0x1540, 0xD701, 0x17C0, 0x1680, 0xD641, 0xD201,
 0x12C0, 0x1380, 0xD341, 0x1100, 0xD1C1, 0xD081, 0x1040,
 0xF001, 0x30C0, 0x3180, 0xF141, 0x3300, 0xF3C1, 0xF281,
 0x3240, 0x3600, 0xF6C1, 0xF781, 0x3740, 0xF501, 0x35C0,
 0x3480, 0xF441, 0x3C00, 0xFCC1, 0xFD81, 0x3D40, 0xFF01,
 0x3FC0, 0x3E80, 0xFE41, 0xFA01, 0x3AC0, 0x3B80, 0xFB41,
 0x3900, 0xF9C1, 0xF881, 0x3840, 0x2800, 0xE8C1, 0xE981,
 0x2940, 0xEB01, 0x2BC0, 0x2A80, 0xEA41, 0xEE01, 0x2EC0,
 0x2F80, 0xEF41, 0x2D00, 0xEDC1, 0xEC81, 0x2C40, 0xE401,
 0x24C0, 0x2580, 0xE541, 0x2700, 0xE7C1, 0xE681, 0x2640,
 0x2200, 0xE2C1, 0xE381, 0x2340, 0xE101, 0x21C0, 0x2080,
 0xE041, 0xA001, 0x60C0, 0x6180, 0xA141, 0x6300, 0xA3C1,
 0xA281, 0x6240, 0x6600, 0xA6C1, 0xA781, 0x6740, 0xA501,
 0x65C0, 0x6480, 0xA441, 0x6C00, 0xACC1, 0xAD81, 0x6D40, 
 0xAF01, 0x6FC0, 0x6E80, 0xAE41, 0xAA01, 0x6AC0, 0x6B80,
 0xAB41, 0x6900, 0xA9C1, 0xA881, 0x6840, 0x7800, 0xB8C1,
 0xB981, 0x7940, 0xBB01, 0x7BC0, 0x7A80, 0xBA41, 0xBE01,
 0x7EC0, 0x7F80, 0xBF41, 0x7D00, 0xBDC1, 0xBC81, 0x7C40,
 0xB401, 0x74C0, 0x7580, 0xB541, 0x7700, 0xB7C1, 0xB681,
 0x7640, 0x7200, 0xB2C1, 0xB381, 0x7340, 0xB101, 0x71C0,
 0x7080, 0xB041, 0x5000, 0x90C1, 0x9181, 0x5140, 0x9301,
 0x53C0, 0x5280, 0x9241, 0x9601, 0x56C0, 0x5780, 0x9741,
 0x5500, 0x95C1, 0x9481, 0x5440, 0x9C01, 0x5CC0, 0x5D80,
 0x9D41, 0x5F00, 0x9FC1, 0x9E81, 0x5E40, 0x5A00, 0x9AC1,
 0x9B81, 0x5B40, 0x9901, 0x59C0, 0x5880, 0x9841, 0x8801,
 0x48C0, 0x4980, 0x8941, 0x4B00, 0x8BC1, 0x8A81, 0x4A40,
 0x4E00, 0x8EC1, 0x8F81, 0x4F40, 0x8D01, 0x4DC0, 0x4C80,
 0x8C41, 0x4400, 0x84C1, 0x8581, 0x4540, 0x8701, 0x47C0,
 0x4680, 0x8641, 0x8201, 0x42C0, 0x4380, 0x8341, 0x4100,
 0x81C1, 0x8081, 0x4040};

static unsigned int crc_table2[256] = {0x0000,
 0xC0C1, 0xC181, 0x0140, 0xC301, 0x03C0, 0x0280, 0xC241,
 0xC601, 0x06C0, 0x0780, 0xC741, 0x0500, 0xC5C1, 0xC481,
 0x0440, 0xCC01, 0x0CC0, 0x0D80, 0xCD41, 0x0F00, 0xCFC1,
 0xCE81, 0x0E40, 0x0A00, 0xCAC1, 0xCB81, 0x0B40, 0xC901,
 0x09C0, 0x0880, 0xC841, 0xD801, 0x18C0, 0x1980, 0xD941,
 0x1B00, 0xDBC1, 0xDA81, 0x1A40, 0x1E00, 0xDEC1, 0xDF81,
 0x1F40, 0xDD01, 0x1DC0, 0x1C80, 0xDC41, 0x1400, 0xD4C1,
 0xD581, 0x1540, 0xD701, 0x17C0, 0x1680, 0xD641, 0xD201,
 0x12C0, 0x1380, 0xD341, 0x1100, 0xD1C1, 0xD081, 0x1040,
 0xF001, 0x30C0, 0x3180, 0xF141, 0x3300, 0xF3C1, 0xF281,
 0x3240, 0x3600, 0xF6C1, 0xF781, 0x3740, 0xF501, 0x35C0,
 0x3480, 0xF441, 0x3C00, 0xFCC1, 0xFD81, 0x3D40, 0xFF01,
 0x3FC0, 0x3E80, 0xFE41, 0xFA01, 0x3AC0, 0x3B80, 0xFB41,
 0x3900, 0xF9C1, 0xF881, 0x3840, 0x2800, 0xE8C1, 0xE981,
 0x2940, 0xEB01, 0x2BC0, 0x2A80, 0xEA41, 0xEE01, 0x2EC0,
 0x2F80, 0xEF41, 0x2D00, 0xEDC1, 0xEC81, 0x2C40, 0xE401,
 0x24C0, 0x2580, 0xE541, 0x2700, 0xE7C1, 0xE681, 0x2640,
 0x2200, 0xE2C1, 0xE381, 0x2340, 0xE101, 0x21C0, 0x2080,
 0xE041, 0xA001, 0x60C0, 0x6180, 0xA141, 0x6300, 0xA3C1,
 0xA281, 0x6240, 0x6600, 0xA6C1, 0xA781, 0x6740, 0xA501,
 0x65C0, 0x6480, 0xA441, 0x6C00, 0xACC1, 0xAD81, 0x6D40, 
 0xAF01, 0x6FC0, 0x6E80, 0xAE41, 0xAA01, 0x6AC0, 0x6B80,
 0xAB41, 0x6900, 0xA9C1, 0xA881, 0x6840, 0x7800, 0xB8C1,
 0xB981, 0x7940, 0xBB01, 0x7BC0, 0x7A80, 0xBA41, 0xBE01,
 0x7EC0, 0x7F80, 0xBF41, 0x7D00, 0xBDC1, 0xBC81, 0x7C40,
 0xB401, 0x74C0, 0x7580, 0xB541, 0x7700, 0xB7C1, 0xB681,
 0x7640, 0x7200, 0xB2C1, 0xB381, 0x7340, 0xB101, 0x71C0,
 0x7080, 0xB041, 0x5000, 0x90C1, 0x9181, 0x5140, 0x9301,
 0x53C0, 0x5280, 0x9241, 0x9601, 0x56C0, 0x5780, 0x9741,
 0x5500, 0x95C1, 0x9481, 0x5440, 0x9C01, 0x5CC0, 0x5D80,
 0x9D41, 0x5F00, 0x9FC1, 0x9E81, 0x5E40, 0x5A00, 0x9AC1,
 0x9B81, 0x5B40, 0x9901, 0x59C0, 0x5880, 0x9841, 0x8801,
 0x48C0, 0x4980, 0x8941, 0x4B00, 0x8BC1, 0x8A81, 0x4A40,
 0x4E00, 0x8EC1, 0x8F81, 0x4F40, 0x8D01, 0x4DC0, 0x4C80,
 0x8C41, 0x4400, 0x84C1, 0x8581, 0x4540, 0x8701, 0x47C0,
 0x4680, 0x8641, 0x8201, 0x42C0, 0x4380, 0x8341, 0x4100,
 0x81C1, 0x8081, 0x4040};

/** 설명
* CRC-32 (IEEE 802.3) : International Standard Generator Polynomials
* Generator polynomial: x32 + x26 + x23 + x22 + x16 + x12 + x11 + x10 + x8 + x7 + x5 + x4 + x2 + x1 + 1
* Divisor (polynomial): 0x04C11DB7
* Initial remainder   : 0xFFFFFFFF
* Final XOR value     : 0xFFFFFFFF
*/
#define CRC32_INIT  0xffffffffLU
#define CRC32_XOROT 0xffffffffLU

static const uint g_tableof_CRC32[256] =   
{ /* POLYNOMIAL	0x04C11DB7L : IEEE 802.3 type. */
   0x00000000LU, 0x77073096LU, 0xEE0E612CLU, 0x990951BALU,
   0x076DC419LU, 0x706AF48FLU, 0xE963A535LU, 0x9E6495A3LU,
   0x0EDB8832LU, 0x79DCB8A4LU, 0xE0D5E91ELU, 0x97D2D988LU,
   0x09B64C2BLU, 0x7EB17CBDLU, 0xE7B82D07LU, 0x90BF1D91LU,
   0x1DB71064LU, 0x6AB020F2LU, 0xF3B97148LU, 0x84BE41DELU,
   0x1ADAD47DLU, 0x6DDDE4EBLU, 0xF4D4B551LU, 0x83D385C7LU,
   0x136C9856LU, 0x646BA8C0LU, 0xFD62F97ALU, 0x8A65C9ECLU,
   0x14015C4FLU, 0x63066CD9LU, 0xFA0F3D63LU, 0x8D080DF5LU,
   0x3B6E20C8LU, 0x4C69105ELU, 0xD56041E4LU, 0xA2677172LU,
   0x3C03E4D1LU, 0x4B04D447LU, 0xD20D85FDLU, 0xA50AB56BLU,
   0x35B5A8FALU, 0x42B2986CLU, 0xDBBBC9D6LU, 0xACBCF940LU,
   0x32D86CE3LU, 0x45DF5C75LU, 0xDCD60DCFLU, 0xABD13D59LU,
   0x26D930ACLU, 0x51DE003ALU, 0xC8D75180LU, 0xBFD06116LU,
   0x21B4F4B5LU, 0x56B3C423LU, 0xCFBA9599LU, 0xB8BDA50FLU,
   0x2802B89ELU, 0x5F058808LU, 0xC60CD9B2LU, 0xB10BE924LU,
   0x2F6F7C87LU, 0x58684C11LU, 0xC1611DABLU, 0xB6662D3DLU,
   0x76DC4190LU, 0x01DB7106LU, 0x98D220BCLU, 0xEFD5102ALU,
   0x71B18589LU, 0x06B6B51FLU, 0x9FBFE4A5LU, 0xE8B8D433LU,
   0x7807C9A2LU, 0x0F00F934LU, 0x9609A88ELU, 0xE10E9818LU,
   0x7F6A0DBBLU, 0x086D3D2DLU, 0x91646C97LU, 0xE6635C01LU,
   0x6B6B51F4LU, 0x1C6C6162LU, 0x856530D8LU, 0xF262004ELU,
   0x6C0695EDLU, 0x1B01A57BLU, 0x8208F4C1LU, 0xF50FC457LU,
   0x65B0D9C6LU, 0x12B7E950LU, 0x8BBEB8EALU, 0xFCB9887CLU,
   0x62DD1DDFLU, 0x15DA2D49LU, 0x8CD37CF3LU, 0xFBD44C65LU,
   0x4DB26158LU, 0x3AB551CELU, 0xA3BC0074LU, 0xD4BB30E2LU,
   0x4ADFA541LU, 0x3DD895D7LU, 0xA4D1C46DLU, 0xD3D6F4FBLU,
   0x4369E96ALU, 0x346ED9FCLU, 0xAD678846LU, 0xDA60B8D0LU,
   0x44042D73LU, 0x33031DE5LU, 0xAA0A4C5FLU, 0xDD0D7CC9LU,
   0x5005713CLU, 0x270241AALU, 0xBE0B1010LU, 0xC90C2086LU,
   0x5768B525LU, 0x206F85B3LU, 0xB966D409LU, 0xCE61E49FLU,
   0x5EDEF90ELU, 0x29D9C998LU, 0xB0D09822LU, 0xC7D7A8B4LU,
   0x59B33D17LU, 0x2EB40D81LU, 0xB7BD5C3BLU, 0xC0BA6CADLU,
   0xEDB88320LU, 0x9ABFB3B6LU, 0x03B6E20CLU, 0x74B1D29ALU,
   0xEAD54739LU, 0x9DD277AFLU, 0x04DB2615LU, 0x73DC1683LU,
   0xE3630B12LU, 0x94643B84LU, 0x0D6D6A3ELU, 0x7A6A5AA8LU,
   0xE40ECF0BLU, 0x9309FF9DLU, 0x0A00AE27LU, 0x7D079EB1LU,
   0xF00F9344LU, 0x8708A3D2LU, 0x1E01F268LU, 0x6906C2FELU,
   0xF762575DLU, 0x806567CBLU, 0x196C3671LU, 0x6E6B06E7LU,
   0xFED41B76LU, 0x89D32BE0LU, 0x10DA7A5ALU, 0x67DD4ACCLU,
   0xF9B9DF6FLU, 0x8EBEEFF9LU, 0x17B7BE43LU, 0x60B08ED5LU,
   0xD6D6A3E8LU, 0xA1D1937ELU, 0x38D8C2C4LU, 0x4FDFF252LU,
   0xD1BB67F1LU, 0xA6BC5767LU, 0x3FB506DDLU, 0x48B2364BLU,
   0xD80D2BDALU, 0xAF0A1B4CLU, 0x36034AF6LU, 0x41047A60LU,
   0xDF60EFC3LU, 0xA867DF55LU, 0x316E8EEFLU, 0x4669BE79LU,
   0xCB61B38CLU, 0xBC66831ALU, 0x256FD2A0LU, 0x5268E236LU,
   0xCC0C7795LU, 0xBB0B4703LU, 0x220216B9LU, 0x5505262FLU,
   0xC5BA3BBELU, 0xB2BD0B28LU, 0x2BB45A92LU, 0x5CB36A04LU,
   0xC2D7FFA7LU, 0xB5D0CF31LU, 0x2CD99E8BLU, 0x5BDEAE1DLU,
   0x9B64C2B0LU, 0xEC63F226LU, 0x756AA39CLU, 0x026D930ALU,
   0x9C0906A9LU, 0xEB0E363FLU, 0x72076785LU, 0x05005713LU,
   0x95BF4A82LU, 0xE2B87A14LU, 0x7BB12BAELU, 0x0CB61B38LU,
   0x92D28E9BLU, 0xE5D5BE0DLU, 0x7CDCEFB7LU, 0x0BDBDF21LU,
   0x86D3D2D4LU, 0xF1D4E242LU, 0x68DDB3F8LU, 0x1FDA836ELU,
   0x81BE16CDLU, 0xF6B9265BLU, 0x6FB077E1LU, 0x18B74777LU,
   0x88085AE6LU, 0xFF0F6A70LU, 0x66063BCALU, 0x11010B5CLU,
   0x8F659EFFLU, 0xF862AE69LU, 0x616BFFD3LU, 0x166CCF45LU,
   0xA00AE278LU, 0xD70DD2EELU, 0x4E048354LU, 0x3903B3C2LU,
   0xA7672661LU, 0xD06016F7LU, 0x4969474DLU, 0x3E6E77DBLU,
   0xAED16A4ALU, 0xD9D65ADCLU, 0x40DF0B66LU, 0x37D83BF0LU,
   0xA9BCAE53LU, 0xDEBB9EC5LU, 0x47B2CF7FLU, 0x30B5FFE9LU,
   0xBDBDF21CLU, 0xCABAC28ALU, 0x53B39330LU, 0x24B4A3A6LU,
   0xBAD03605LU, 0xCDD70693LU, 0x54DE5729LU, 0x23D967BFLU,
   0xB3667A2ELU, 0xC4614AB8LU, 0x5D681B02LU, 0x2A6F2B94LU,
   0xB40BBE37LU, 0xC30C8EA1LU, 0x5A05DF1BLU, 0x2D02EF8DLU
};

typedef struct
{
	unsigned short	a	: 8;
	unsigned short	i8: 1;
	unsigned short	i7: 1;
	unsigned short	i6: 1;
	unsigned short	i5: 1;
	unsigned short	i4: 1;
	unsigned short	i3: 1;
	unsigned short	i2: 1;
	unsigned short	i1: 1;


}BITS8BYTE;


typedef struct
{
	unsigned short	b16: 1;
	unsigned short	b15: 1;
	unsigned short	b14: 1;
	unsigned short	b13: 1;
	unsigned short	b12: 1;
	unsigned short	b11: 1;
	unsigned short	b10: 1;
	unsigned short	b9: 1;
	unsigned short	b8: 1;
	unsigned short	b7: 1;
	unsigned short	b6: 1;
	unsigned short	b5: 1;
	unsigned short	b4: 1;
	unsigned short	b3: 1;
	unsigned short	b2: 1;
	unsigned short	b1: 1;
}BITS16UINT;

/* ------------------------------------------------------------------------- *
 * Function Description
 * ------------------------------------------------------------------------- */
/** 
| 함수명 : OPC_Purge_Queue                                                  
| 
| 기능 : OPC_PROC 에서 사용하는 QUEUE 를 퍼지한다.
| 작성자    : 이창수                                                      
| 함수형태 : uchar	OPC_Purge_Queue( int   msqid)  
| 파라미터 : int   msqid : [input]  
| 반환 	  : uchar RetVal : [output]
|					0 : Ok
|					Otherwise : Bad
| 버전        : 1.0
| 수정이력 
|------------------------------------------------------------------------- 
|	20160106 : 최초작성
/------------------------------------------------------------------------- */
uchar	OPC_Purge_Queue( int   msqid)
{
	INTER_MSG       OPC_TmpMsg;
	struct   msqid_ds msqstat; 	
	uint count;
	uchar RetVal = Ok;

	if ( -1 == msgctl( msqid , IPC_STAT, &msqstat))
   	{

   		perror( "OPC_Purge_Queue : msgctl() 실패");
   		return (Bad);
   	}
	
  	
    	for (count = 0; count < msqstat.msg_qnum; count++)
    	{
    		msgrcv( msqid, &OPC_TmpMsg, sizeof( INTER_MSG) - sizeof( long), 0, IPC_NOWAIT|MSG_NOERROR);	
   	 }	

	return (RetVal);
}


/* ------------------------------------------------------------------------- *
 * Function Description
 * ------------------------------------------------------------------------- */
/** 
| 함수명 : MTC_Purge_Queue                                                  
| 
| 기능 : MTC_PROC 에서 사용하는 QUEUE 를 퍼지한다.
| 작성자    : 이창수                                                      
| 함수형태 : uchar	MTC_Purge_Queue( int   msqid)  
| 파라미터 : int   msqid : [input]  
| 반환 	  : uchar RetVal : [output]
|					0 : Ok
|					Otherwise : Bad
| 버전        : 1.0
| 수정이력 
|------------------------------------------------------------------------- 
|	20160106 : 최초작성
/------------------------------------------------------------------------- */
uchar	MTC_Purge_Queue( int   msqid)
{
	INTER_MSG       MTC_TmpMsg;
	struct   msqid_ds msqstat; 	
	uint count;
	uchar RetVal = Ok;

	if ( -1 == msgctl( msqid , IPC_STAT, &msqstat))
   	{

   		perror( "MTC_Purge_Queue : msgctl() 실패");
   		return (Bad);
   	}
	
  	
    	for (count = 0; count < msqstat.msg_qnum; count++)
    	{
    		msgrcv( msqid, &MTC_TmpMsg, sizeof( INTER_MSG) - sizeof( long), 0, IPC_NOWAIT|MSG_NOERROR);	
   	 }	

	return (RetVal);
}


/* ------------------------------------------------------------------------- *
 * Function Description
 * ------------------------------------------------------------------------- */
/** 
| 함수명 : DTS_Purge_Queue                                                  
| 
| 기능 : DTS_PROC 에서 사용하는 QUEUE 를 퍼지한다.
| 작성자    : 이창수                                                      
| 함수형태 : uchar	DTS_Purge_Queue( int   msqid)  
| 파라미터 : int   msqid : [input]  
| 반환 	  : uchar RetVal : [output]
|					0 : Ok
|					Otherwise : Bad
| 버전        : 1.0
| 수정이력 
|------------------------------------------------------------------------- 
|	20160106 : 최초작성
/------------------------------------------------------------------------- */
uchar	DTS_Purge_Queue( int   msqid)
{
	INTER_MSG       DTS_TmpMsg;
	struct   msqid_ds msqstat; 	
	uint count;
	uchar RetVal = Ok;

	if ( -1 == msgctl( msqid , IPC_STAT, &msqstat))
   	{

   		perror( "DTS_Purge_Queue : msgctl() 실패");
   		return (Bad);
   	}
	
  	
    	for (count = 0; count < msqstat.msg_qnum; count++)
    	{
    		msgrcv( msqid, &DTS_TmpMsg, sizeof( INTER_MSG) - sizeof( long), 0, IPC_NOWAIT|MSG_NOERROR);	
   	 }	

	return (RetVal);
}


/* ------------------------------------------------------------------------- *
 * Function Description
 * ------------------------------------------------------------------------- */
/** 
| 함수명 : RC_Purge_Queue                                                  
| 
| 기능 : MC_PROC 에서 사용하는 QUEUE 를 퍼지한다.
| 작성자    : 이창수                                                      
| 함수형태 : uchar	MC_Purge_Queue( int   msqid)  
| 파라미터 : int   msqid : [input]  
| 반환 	  : uchar RetVal : [output]
|					0 : Ok
|					Otherwise : Bad
| 버전        : 1.0
| 수정이력 
|------------------------------------------------------------------------- 
|	20160106 : 최초작성
/------------------------------------------------------------------------- */
uchar	RC_Purge_Queue( int   msqid)
{
	INTER_MSG       RC_TmpMsg;
	struct   msqid_ds msqstat; 	
	uint count;
	uchar RetVal = Ok;

	if ( -1 == msgctl( msqid , IPC_STAT, &msqstat))
   	{

   		perror( "RC_Purge_Queue : msgctl() 실패");
   		return (Bad);
   	}
	
  	
    	for (count = 0; count < msqstat.msg_qnum; count++)
    	{
    		msgrcv( msqid, &RC_TmpMsg, sizeof( INTER_MSG) - sizeof( long), 0, IPC_NOWAIT|MSG_NOERROR);	
   	 }	

	return (RetVal);
}


/*----------------------------------------------------------------------------+
| 함 수 명 : DV_ViewPortData                                                     |
|                                                                             |
| 입력변수 : port   - 해당 port의 queue (TXQUEn, RXQUEn)                      |
|            length - 보여줄 data의 갯수                                      |
|            data[] - PAC port를 통해 보여줄 data의 pointer                   |
|                                                                             |
| 출력변수 : 없음                                                             |
|                                                                             |
| 결 과 값 : error -  Ok        : 정상적인 처리를 했음을 나타냄.              |
|                     PortErr   : 입력변수 queue가 잘못 되었음.               |
|                     LengthErr : 입력변수 size가 13+2024 보다 크다.              |
|                                                                             |
| 함수설명 : system을 debug하는 동안 각 channel로 송, 수신 되는 data를 화면에 |
|            logging해 볼수 있으면 debug에 상당히 도움이 될것이다.            |
|            이를 처리하기 위해 ViewTask와 interface할 routine을 작성.        |
|            이 routine은 debug시 에는 data를 PAC port로 뿌리는데 사용되고    |
|            그 이후에는 각 port에 송, 수신 된 data를 frame 단위로 관리 하게  |
|            하여 추후 이를 볼수 있게한다.                                    |
|            이 routine의 입력 변수 data[]는 KS_alloc를 통해 할당 받은 pointer|
|            에 copy하고 그 poiter값을 ulong 으로 변환하여 frame의 pointer를  |
|            관리할 queue에 넣어서 ring 구조로 가져간다. (그러므로 queue의    |                            |
|            width 는 4 byte, queue의 depth는 보관 하고자 하는 maximum frame  |
|            의 갯수가 된다)                                                  |
|                                                                             |
| 사용함수 :   |
|                                                                             |
| 변경변수 : 없음                                                             |
|                                                                             |
| 작성일자 : 1992. 9. 26                                                      |
|                                                                             |
| 변경이력 : 1992.  9. 26 - header 작성                                       |
|            1992. 10. 29 - ViewTask 에서 queue를 꺼내서 free 시키므로 각     |
|                           queue에는 data가 비게되어 data의 관리가 이루어    |
|                           지지 않는다.                                      |
|                           이를 위해 별도의 queue (VQUEUE)를 둔다.           |
+-----------------------------------------------------------------------------*/
#if 0
int   DB_ViewPortData(QUEUE_ID port, int length, uchar data[])
{
	 QUEUE_ID       queue;      /* data[]를 copy한 partition의 address를 저장할*/
	                            /* ring 구조의 id*/
	 VIEW_INFORM    inform;     /* queue 이름, data address로 이루어진 정보*/
	 VIEW_INFORM    tmp_info;
	 /* uchar 			SystemTime[6]; */

	
	if (ShmMsg->View_Flag == NO)
	{
		return(0);
	}    	
 
	if ((length >  ViewDataLength) || (length == 0))
	{
		return(LengthErr);
	}
	
	switch (port)
	{  
		/* 어느 port의 data인지 확인*/
		/*========================Ethernet Socket Channel view========================*/
		case    TXOPC1:
			if (ShmMsg->E_VIEW_ENABLE[TxCh_Sock1] == ViewOn)
			{
				queue = VQUETX_OPC1;
		            	break;  
			}
			else 
		            	return(Ok);   

		case    TXOPC2:
		        	if (ShmMsg->E_VIEW_ENABLE[TxCh_Sock2] == ViewOn)
			{
				queue = VQUETX_OPC2;
				break;  
			}
			else 
				return(Ok);   

		case    TXMTC1:
			if (ShmMsg->E_VIEW_ENABLE[TxCh_Sock3] == ViewOn)
			{
				queue = VQUETX_MTC1;
		            	break;  
			}
			else 
		            	return(Ok);   

		case    TXMTC2:
		        	if (ShmMsg->E_VIEW_ENABLE[TxCh_Sock4] == ViewOn)
			{
				queue = VQUETX_MTC2;
				break;  
			}
			else 
				return(Ok);   

		case    TXDTS1:
		        	if (ShmMsg->E_VIEW_ENABLE[TxCh_Sock5] == ViewOn)
			{
		            	queue = VQUETX_DTS1;
		            	break;  
			}
			else 
		            	return(Ok);   
		
	 	case    TXDTS2:
		        	if (ShmMsg->E_VIEW_ENABLE[TxCh_Sock6] == ViewOn)
			{
		            	queue = VQUETX_DTS2;
		            	break;  
			}
			else 
		            	return(Ok);   

	 	case    TXRC1:
		        	if (ShmMsg->E_VIEW_ENABLE[TxCh_Sock7] == ViewOn)
			{
		            	queue = VQUETX_RC1;
		            	break;  
			}
			else 
		            	return(Ok);   
				
	 	case    TXRC2:
		        	if (ShmMsg->E_VIEW_ENABLE[TxCh_Sock8] == ViewOn)
			{
				queue = VQUETX_RC2;
		            	break;  
			}
			else 
		            	return(Ok);   
				
		case    RXOPC1:
		        	if (ShmMsg->E_VIEW_ENABLE[RxCh_Sock1] == ViewOn)
			{
		            	queue = VQUERX_OPC1;
		            	break;  
			}
			else 
		            	return(Ok);   

	        case    RXOPC2:
		        	if (ShmMsg->E_VIEW_ENABLE[RxCh_Sock2] == ViewOn)
			{
		            	queue = VQUERX_OPC2;
		            	break;  
			}
			else 
		            	return(Ok);   

		case    RXMTC1:
		        	if (ShmMsg->E_VIEW_ENABLE[RxCh_Sock3] == ViewOn)
			{
		            	queue = VQUERX_MTC1;
		            	break;  
			}
			else 
		            	return(Ok);   

	        case    RXMTC2:
		        	if (ShmMsg->E_VIEW_ENABLE[RxCh_Sock4] == ViewOn)
			{
		            	queue = VQUERX_MTC2;
		            	break;  
			}
			else 
		            	return(Ok);   

		case    RXDTS1:
		        	if (ShmMsg->E_VIEW_ENABLE[RxCh_Sock5] == ViewOn)
			{
		            	queue = VQUERX_DTS1;
		            	break;  
			}
			else 
		            	return(Ok);   
		
	 	case    RXDTS2:
		        	if (ShmMsg->E_VIEW_ENABLE[RxCh_Sock6] == ViewOn)
			{
		            	queue = VQUERX_DTS2;
		            	break;  
			}
			else 
		            	return(Ok);   

	 	case    RXRC1:
		        	if (ShmMsg->E_VIEW_ENABLE[RxCh_Sock7] == ViewOn)
			{
		            	queue = VQUERX_RC1;
		            	break;  
			}
			else 
		            	return(Ok);   
				
	 	case    RXRC2:
		        	if (ShmMsg->E_VIEW_ENABLE[RxCh_Sock8] == ViewOn)
			{
		            	queue = VQUERX_RC2;
		            	break;  
			}
			else 
		            	return(Ok);   

		/*========================Serial Extention Channel view========================*/
		case	TXQUE1: 	   
			if (ShmMsg->S_VIEW_ENABLE[TxChannel1] == ViewOn)
			{
				 queue = VQUETX1;
				 break;  
			 }
			 else 
				 return(Ok);
			 
		 case	 TXQUE2:		
			 if (ShmMsg->S_VIEW_ENABLE[TxChannel2] == ViewOn)
			 {
				 queue = VQUETX2;
				 break;  
			 }
			 else 
				 return(Ok);
		
	       case    TXQUE3:        
			if (ShmMsg->S_VIEW_ENABLE[TxChannel3] == ViewOn)
			{
		             	queue = VQUETX3;
		            	break;  
			}
			else 
				return(Ok);
	            
	        case    TXQUE4:        
			if (ShmMsg->S_VIEW_ENABLE[TxChannel4] == ViewOn)
			{
				queue = VQUETX4;
		            	break;  
			}
			else 
				return(Ok);
	                        		
	        case    TXQUE5:        	    
			if (ShmMsg->S_VIEW_ENABLE[TxChannel5] == ViewOn)
			{
				queue = VQUETX5;
				break;  
			}
			else 
				return(Ok);

	        case    TXQUE6:
			if (ShmMsg->S_VIEW_ENABLE[TxChannel6] == ViewOn)
			{
				queue = VQUETX6;
				break;  
			}
			else 
				return(Ok);

	        case    TXQUE7:
			if (ShmMsg->S_VIEW_ENABLE[TxChannel7] == ViewOn)
			{
				queue = VQUETX7;
				break;  
			}
			else 
				return(Ok);

	        case    TXQUE8:
			if (ShmMsg->S_VIEW_ENABLE[TxChannel8] == ViewOn)
			{
	            		queue = VQUETX8;
	            		break;  
	           	 }
	            	else 
	            		return(Ok);

	         case    RXQUE1:
	        		if (ShmMsg->S_VIEW_ENABLE[RxChannel1] == ViewOn)
			{
	            		queue = VQUERX1;
	            		break;  
	         	   	}
	            	else 
	            		return(Ok);
	            
	        case    RXQUE2:
	       	 	if (ShmMsg->S_VIEW_ENABLE[RxChannel2] == ViewOn)
			{
	            		queue = VQUERX2;
	            		break;  
	          	}
	            	else 
	            		return(Ok);
				
	        case    RXQUE3:
	        		if (ShmMsg->S_VIEW_ENABLE[RxChannel3] == ViewOn)
			{
	            		queue = VQUERX3;
	            		break;  
	            	}
	            	else 
	            		return(Ok);
	            
	        case    RXQUE4:
	        		if (ShmMsg->S_VIEW_ENABLE[RxChannel4] == ViewOn)
			{
	            		queue = VQUERX4;
	            		break;  
	            	}
	            	else 
	            		return(Ok);

	        case    RXQUE5:        
	        		if (ShmMsg->S_VIEW_ENABLE[RxChannel5] == ViewOn)
			{
	            		queue = VQUERX5;
	            		break;  
	            	}
	            	else 
	            		return(Ok);

	        case    RXQUE6:
	        		if (ShmMsg->S_VIEW_ENABLE[RxChannel6] == ViewOn)
			{
	            		queue = VQUERX6;
	            		break;  
	            	}
	            	else 
	            		return(Ok);

	        case    RXQUE7:
	        		if (ShmMsg->S_VIEW_ENABLE[RxChannel7] == ViewOn)
			{
	            		queue = VQUERX7;
	            		break;  
	            	}
	            	else 
	            		return(Ok);

	        case    RXQUE8:
	        		if (ShmMsg->S_VIEW_ENABLE[RxChannel8] == ViewOn)
			{
	            		queue = VQUERX8;
	            		break;  
	           	}
	            	else 
	            		return(Ok);

	        default:
	            return(PortErr);
	}
    
	/* DB_GetSystemTime(&System_tick); */
	inform.size = length;
	inform.data_type = 1;
	memcpy(inform.ch, data, length);

	if (ShmMsg->runbugflag)
	{ /* rtxcbug에 들어가 있지 않다*/
		inform.queue = queue;
		if ( -1 == msgsnd( ShmMsg->MsgQId[V_QUEUE], &inform, sizeof(VIEW_INFORM) - sizeof(long), IPC_NOWAIT))
     		{

   			if ( -1 == ( ShmMsg->MsgQId[V_QUEUE] = msgget( (key_t)V_QUEUE+100, IPC_CREAT | 0666)))
   			{
      				printf("msgget(V_QUEUE) 실패");
   			}	    
    			else 
    				printf( "MsgQId[V_QUEUE] = Re Creation OK ID[%d] ...\n", ShmMsg->MsgQId[V_QUEUE]);	        	
     	
        		
         			msgrcv( ShmMsg->MsgQId[V_QUEUE], &tmp_info, sizeof(VIEW_INFORM) - sizeof(long), 0, IPC_NOWAIT|MSG_NOERROR);
           		msgsnd( ShmMsg->MsgQId[V_QUEUE], &inform, sizeof(VIEW_INFORM) - sizeof(long), IPC_NOWAIT);
        		}		
	}

	return(Ok);
}
#endif

/*----------------------------------------------------------------------------+
| 함 수 명 : UcharToAscii                                                     |
|                                                                             |
| 입력변수 : number  - 변환하고자 하는 숫자                                   |
|            radix   - 변환하고자 하는 base (10, 16)                          |
|            arrange - 변환한 ascii 값을 오른쪽 으로 맞추기 위한 자리수       |
|                      (xxxx(4) 일때 변환된 것이 13이면 xx13 이 된다)         |
|            blank   - 자리를 맞춘후 좌측의 여백을 메울 char.                 |
|                                                                             |
| 출력변수 : ascii   - 변환된 ascii string의 저장 위치                        |
|                                                                             |
| 결 과 값 : error   - 항상 Ok                                                |
|                                                                             |
| 함수설명 : unsigned char 를 10 진수 혹은 16진수의 ascii 값으로 변환하고     |
|            자리수를 맞추어 준다.                                            |
|                                                                             |
| 사용함수 : itoa                                                             |
|                                                                             |
| 변경변수 : 없음                                                             |
|                                                                             |
| 작성일자 : 1992. 9. 30                                                      |
|                                                                             |
| 변경이력 : 1992. 9. 30 - header 작성                                        |
+-----------------------------------------------------------------------------*/
int UcharToAscii(uchar number, char ascii[], ushort radix, ushort arrange, char blank)
{
 char   ch[4];  /* number를 ascii로 변환한 결과 */
 uchar  data;
 ushort tmp;
 
    /* itoa((int) number, ch, radix); */
    
    tmp = radix ;
    tmp = arrange;
    data = blank;
    
    data = (number  >> 4) & 0x0f;
      
   if (data <= 9)
   {
   	   data = data + 0x30 ;
   }
   else if ((data >= 0x0a) && (data <= 0x0f)) 
   {
   		data = data + 0x57 ;
   }
    
   
   ch[0] = data;
       
   data = number & 0x0f;
      
   if (data <= 0x09) 
   {
   	   data = data + 0x30 ;
   }
   else if ((data >= 0x0a) && (data <= 0x0f)) {
   		data = data + 0x57 ;
   }     
        
   ch[1] = data;     
        
    memcpy(&ascii[0], ch, 2);
   
    
    return(Ok);
}


/* ------------------------------------------------------------------------- *
 * Function Description
 * ------------------------------------------------------------------------- */
/** 
| 함수명 : AsciiToHex                                                 
| 
| 기능 : Ascii code 를 hex value 로 변환
| 작성자    : 이창수                                                      
| 함수형태 : int  AsciiToHex(uchar *string, uchar *value)
| 파라미터 : uchar *string : [input]
|						ascii value
|		    uchar *value : [output]
|						converted hex value
| 반환 	  : int RetVal : [output]
|						0x0 : Ok, Pass
|						otherwise : Bad, Bad
| 버전        : 1.0
| 수정이력 
|------------------------------------------------------------------------- 
|	20151230 : 최초작성
/------------------------------------------------------------------------- */
int  AsciiToHex(uchar *string, uchar *value)
{
	int RetVal = Ok;
	
      if (string[0] <= '9' && string[0] >= '0')
      {
              string[0] = string[0] - 0x30;
              string[0] = string[0] << 4;
              if ((string[1] <= 'f' && string[1] >= 'a') ||(string[1] <= 'F' && string[1] >= 'A')) 
              {
              	switch(string[1]) 
              	{
              	  case 'a' :
              	  case 'A' :	
              	      string[0] = string[0] | 0x0a ; 
              	      break;
              	  case 'b' :
              	  case 'B' :	
              	      string[0] = string[0] | 0x0b ; 
              	      break;                            	      
              	  case 'c' :
              	  case 'C' :	
              	      string[0] = string[0] | 0x0c ; 
              	      break;                            	      
              	  case 'd' :
              	  case 'D' :	
              	      string[0] = string[0] | 0x0d ; 
              	      break;                            	      
              	  case 'e' :
              	  case 'E' :	
              	      string[0] = string[0] | 0x0e ; 
              	      break;                            	      
              	  case 'f' :
              	  case 'F' :	
              	      string[0] = string[0] | 0x0f ; 
              	      break;                            	      
              	}
              	      
              }
              else
              {
              	string[1] = string[1] - 0x30;
              	string[0] = string[0] | string[1];	
              }
              	
              	
              *value = string[0];
/*            
              printf("%x", string[0]);
              printf("\n");
*/
      } /* 입력의 첫 문자가 0~9이면 끝*/
      else if ((string[0] <= 'f' && string[0] >= 'a') ||(string[0] <= 'F' && string[0] >= 'A')) 
      {
			switch(string[0]) 
          {
              case 'a' :
              case 'A' :	
                  string[0] = 0xa0 ; 
                  break;
              case 'b' :
              case 'B' :	
                  string[0] = 0xb0 ; 
                  break;                	      
              case 'c' :
              case 'C' :	
                  string[0] = 0xc0 ; 
                  break;                	      
              case 'd' :
              case 'D' :	
                  string[0] = 0xd0 ; 
                  break;                	      
              case 'e' :
              case 'E' :	
                  string[0] = 0xe0 ; 
                  break;                	      
              case 'f' :
              case 'F' :	
                  string[0] = 0xf0 ; 
                  break;                            	      
           }   
           
           if (string[1] <= '9' && string[1] >= '0')   
           {               	
      			string[1] = string[1] - 0x30;
              	string[0] = string[0] | string[1];
           }
           else
           {
				switch(string[1]) 
          	{
          	    case 'a' :
          	    case 'A' :	
          	        string[0] = string[0] | 0x0a ; 
          	        break;
          	    case 'b' :
          	    case 'B' :	
          	        string[0] = string[0] | 0x0b ; 
          	        break;                	      
          	    case 'c' :
          	    case 'C' :	
          	        string[0] = string[0] | 0x0c ; 
          	        break;                	      
          	    case 'd' :
          	    case 'D' :	
          	        string[0] = string[0] | 0x0d ;
          	        break;                	      
          	    case 'e' :
          	    case 'E' :	
          	        string[0] = string[0] | 0x0e ;
          	        break;                	      
          	    case 'f' :
          	    case 'F' :	
          	        string[0] = string[0] | 0x0f ; 
          	        break;                            	      
          	 }                            	
           }
           
           *value = string[0];
/*            
           printf("%x", string[0]);
           printf("\n");
*/           
      }
      else {
           printf("\n Bad Number!! \n");
	    RetVal = Bad;
           return(RetVal);
      }

     return(RetVal);
}


void	get_date_text( char *text )
{
	time_t     cur_time;
	struct tm *tm_data;
	
	time( &cur_time );
	tm_data = localtime( &cur_time );
	
	sprintf( text, "%04d-%02d-%02d %02d:%02d:%02d", 
                        tm_data->tm_year + 1900, 
                        tm_data->tm_mon +1, 
                        tm_data->tm_mday,
                        tm_data->tm_hour, 
                        tm_data->tm_min, 
                        tm_data->tm_sec );
}

/* ------------------------------------------------------------------------- *
 * Function Description
 * ------------------------------------------------------------------------- */
/** 
 @brief Convert a string to an integer.                                                  
                                                                            
 @author DH.Kim                                                            
 @fn uint String2Integer(const uchar* ucInputStr, uint* uiIntNum)   
 @param const uchar* ucInputStr  : [in] pointer to string input 
 @param uint* uiIntNum         : [in] pointer to converted integer value
 @return : [out] void   
 @version 1.00                                                              
 @section Module-ID
  - MD-0C-26
 @section MODIFYINFO
  - 2015-03-10 / DH.Kim : 최초 작성
  - 2015-08-17 / DH.Kim : Module ID 변경(from MD-04-10-3)
*/  
uint String2Integer(const uchar* ucInputStr, uint* uiIntNum)
{
  uint 	uiIndex = 0U;
  uint 	uiRes = 0U;
  uint 	uiValue = 0U;
  uint	uiCount = 0U;
  uchar   	ucStr[16] = {0U};
  uchar		ucExitFlag = 0U;
  
	/* char type conversion */
  	for (uiCount = 0U; uiCount < 16U; uiCount++)
  	{
  		ucStr[(int)uiCount] = ucInputStr[(int)uiCount];
	}


    if ((ucStr[0] == 0x30U) && ((ucStr[1] == 0x58U) || (ucStr[1] == 0x78U)))
    {
        if (ucStr[2] != 0x00U) /* '\0' */
        {

            for (uiIndex = 2U; uiIndex < 11U; uiIndex++)
            {
                if (ucStr[(int)uiIndex] == 0x00U) /* '\0' */
                {
                    *uiIntNum = uiValue;
                    /* return 1; */
                    uiRes = 1U;
                    ucExitFlag = 1U;
                }
                else
                {
                	/* MISRA-C WARNING : rule 19.7 (advisory) violated.
                       A function should be used in preference to a function like-macro.
                     */
                	/*if (ISVALIDHEX(ucStr[uiIndex]))*//*PolySpace: change macro to statement*/
					if (((((ucStr[(int)uiIndex]) >= (uchar)0x41U) && ((ucStr[(int)uiIndex]) <= (uchar)0x46U))
						|| (((ucStr[(int)uiIndex]) >= (uchar)0x61U) && ((ucStr[(int)uiIndex]) <= (uchar)0x66U))
						|| (((ucStr[(int)uiIndex]) >= (uchar)0x30U) && ((ucStr[(int)uiIndex]) <= (uchar)0x39U))))
                	{
						/* MISRA-C WARNING : rule 12.1 (advisory) violated.
 						   Limited dependence should be placed on C뭩 operator precedence rules in expressions.
 						 */              		
                	    /*uiValue = (uint)(uiValue << 4U) + CONVERTHEX(ucStr[uiIndex]); *//*PolySpace: change marco to statement*/
						uiValue = (uint)((uint)(uiValue << 4U)) + ((((uint)ucStr[(int)uiIndex] >= 0x30U) && ((uint)ucStr[(int)uiIndex] <= 0x39U)) 
						             ? ((uint)ucStr[(int)uiIndex] - 0x30U) : ((((uint)ucStr[(int)uiIndex] >= 0x41U) && ((uint)ucStr[(int)uiIndex] <= 0x46U)) 
						         	? (((uint)ucStr[(int)uiIndex] - 0x41U)+10U) : (((uint)ucStr[(int)uiIndex] - 0x61U)+10U)));
                	}
                	else
                	{
                	    /* return 0, Invalid input */
                	    uiRes = 0U;
                	    ucExitFlag = 1U;
                	} 
                }
                if (ucExitFlag == 1U)
                {
                	break;
                }
            } /* end of for */
            /* over 8 digit hex --invalid */
            if (uiIndex >= 11U)
            {
                uiRes = 0U;
            }
        } /* end of if */
        else
        {    
            uiRes = 0U;   
        }                
    } /* end of if */
    else /* max 10-digit decimal input */
    {
        for (uiIndex = 0U;uiIndex < 11U; uiIndex++)
        {
            if (ucStr[(int)uiIndex] == 0x00U) /* '\0' */
            {
                *uiIntNum = uiValue;
                /* return 1 */
                uiRes = 1U;
                ucExitFlag = 1U;
            }
            else if (((ucStr[(int)uiIndex] == 0x6BU) || (ucStr[(int)uiIndex] == 0x4BU)) && (uiIndex > 0U))
            {
                uiValue = uiValue << 10U;
                *uiIntNum = uiValue;
                uiRes = 1U;
                ucExitFlag = 1U;
            }
            else if (((ucStr[(int)uiIndex] == 0x6DU) || (ucStr[(int)uiIndex] == 0x4DU)) && (uiIndex > 0U))
            {
                uiValue = uiValue << 20U;
                *uiIntNum = uiValue;
                uiRes = 1U;
                ucExitFlag = 1U; 
            }
            /* MISRA-C WARNING : rule 19.7 (advisory) violated.
               A function should be used in preference to a function like-macro.
             */            
            /*else if (ISVALIDDEC(ucStr[uiIndex]))*/
            /*PolySpace : change macro to statement*/
			else if (((((ucStr[(int)uiIndex]) >= 0x30U) && ((ucStr[(int)uiIndex]) <= 0x39U))))
            {
               /* uiValue = (uiValue * 10U) + CONVERTDEC(ucStr[uiIndex]);*/
               /*PolySpace : change macro to statement*/
			   uiValue = (uint)((uiValue * 10U) + ((uint)ucStr[(int)uiIndex] - 0x30U));
            }
            else
            {
                /* return 0, Invalid input */
                uiRes = 0U;
                ucExitFlag = 1U;
            } 
            
            if (ucExitFlag == 1U)
            {
            	break;
            }            
        } /* end of for */
        
        /* Over 10 digit decimal --invalid */
        if (uiIndex >= 11U)
        {
            uiRes = 0U;
        }
    } /* end of else */

  return uiRes;
}

int  ato16(char *lpstr,int *lpi16)
{
     u_char	ch;
     int	i,ival,ipow,ilen;
     char	*lptr;

     ival = 0;
     ipow = 1;
     ilen = strlen(lpstr);
     lptr = (char *)(lpstr+ilen-1);
     for (i = 0;i < ilen;i ++) {
	ch = *lptr | 0x20;
	if (ch >= '0' && ch <= '9') ch = ch - '0';
	else
	if (ch >= 'a' && ch <= 'f') ch = ch - 0x57;
	else			    return 0;
	if (i) ipow = ipow * 16;
	ival += ch * ipow;
	lptr --;
     }
     *lpi16 = ival;
     return 1;
}


int  ato10(char *lpstr,int *lpi10)
{
     u_char	ch;
     int	ival,ipow,i,ilen;
     char	*lptr;

     ival = 0;
     ipow = 1;
     lpstr[2] = '\0';
     ilen = strlen(lpstr);
     /* printf("\nlength [%d] \n",ilen );  */
       
     lptr = (char *)(lpstr+ilen-1);
     for (i = 0;i < ilen;i ++) {
		ch = *lptr - '0';
		if (ch > 9) 
			return 0;
		if (i) 
			ipow = ipow * 10;
		ival += ch * ipow;
		lptr --;
     }
     *lpi10 = ival;
     return 1;
}


/* ------------------------------------------------------------------------- *
 * Function Description
 * ------------------------------------------------------------------------- */
/** 
| 함수명 : Common_InputString                                                  
| 
| 기능 : 사용자 입력을 받아들인다.
| 작성자    : 이창수                                                      
| 함수형태 : void Common_InputString(void)   
| 파라미터 : void : [N/A]
| 반환 	  : return : [output]
|					0 : Ok, Task terminated
|					Otherwise : Task is running
| 버전        : 1.0
| 수정이력 
|------------------------------------------------------------------------- 
|	20151230 : 최초작성
/------------------------------------------------------------------------- */
void Common_InputString(uchar *p)
{
   uchar *q, c, b;
   int cnt, getflg;

   getflg = YES;
   q = p;
   cnt = 1;
   while (getflg)
   {
   	
   	  c = getchar();
   	  
      if ( '\n' == c)
      {
      	 *q = '\0';
         break;   
      }
      else
      {
	  
      		if (c != '\n')
      		{
      		   if (c != ESC)
      		   {
      		      if (c == BS)
      		      {
      		         if (cnt > 1)
      		         {
      		            --cnt;
      		            --q;
      		         }
      		      }
      		
      		      if ( (c == BS) || (c == DEL) )
      		      {
      		         b = ' ';
      		      }
      		      if ( (c >= 32) && (c <= 126) ) /* printable */
      		      {
      		         *q++ = c;
      		         cnt++;
      		      }
      		   }
      		   else
      		   {
      		      *p = c;
      		      cnt = 1;
      		      getflg = NO;
      		   }
      		}
      		else
      		   getflg = NO;
      	}
   }

}


/* ------------------------------------------------------------------------- *
 * Function Description
 * ------------------------------------------------------------------------- */
/** 
| 함수명 : RTC_init                                                  
| 
| 기능 : I2C 인터페이스를 위한 디바이스 노드를 열어 RTC 제어를 가능하게 한다.
| 작성자    : 이창수                                                      
| 함수형태 : int RTC_init(void)   
| 파라미터 : void : [N/A]
| 반환 	  : int RetVal : [output]
|					0 : Ok
|					Otherwise : Bad
| 버전        : 1.0
| 수정이력 
|------------------------------------------------------------------------- 
|	20151230 : 최초작성
/------------------------------------------------------------------------- */
int RTC_init(void)
{
	int RetVal = Bad;

	ShmMsg->I2C_File = open("/dev/i2c-0", O_RDWR);

	if (ShmMsg->I2C_File < 0) 
	{
		printf(" you can check errno to see what went wrong\n");
		return (RetVal);
	}

	RetVal = ioctl(ShmMsg->I2C_File, I2C_SLAVE, 0x68);
	if (RetVal < 0)
	{
		printf(" ERROR HANDLING; you can check errno to see what went wrong\n");
		return (RetVal);
	}
	RetVal = ShmMsg->I2C_File;
    return (RetVal);
}


/* ------------------------------------------------------------------------- *
 * Function Description
 * ------------------------------------------------------------------------- */
/** 
| 함수명 : RTC_Write                                                  
| 
| 기능 : RTC 에 데이터를 저장한다.
| 작성자    : 이창수                                                      
| 함수형태 : int RTC_Write(uchar reg_addr, uchar *data, uint data_sz)
| 파라미터 : uchar : [input]
|					RTC Register
|					: 0x0 ~ 0xFFFFFFFF
|		    uchar *data : [input]
|					Write data
|					: 0x0 ~ 0xFFFFFFFF
|		    uint data_sz : [inpu]
|					Write data size
|					: 0x0 ~ 0xFFFFFFFF
| 반환 	  : int RetVal : [output]
|					0 : Ok
|					Otherwise : Bad
| 버전        : 1.0
| 수정이력 
|------------------------------------------------------------------------- 
|	20151230 : 최초작성
/------------------------------------------------------------------------- */
int RTC_Write(uchar reg_addr, uchar *data, uint data_sz)
{
	uint RetVal = Bad;
	uchar *temp_list = NULL;

	/* check parameters */
	if((data == NULL) || (data_sz == 0))
	{
		printf("error: Input parameters error [%x] [%x]\n",data, data_sz );
		return -1;
	}

	temp_list = (uchar *)malloc(sizeof(uchar)*data_sz);

	temp_list[0] = reg_addr;
	memcpy(&temp_list[1], data, data_sz);
	RetVal = write(ShmMsg->I2C_File, &temp_list[0], data_sz+1);
	if(RetVal != (data_sz+1))
	{
		printf("error: cannot write register address [0x%x]\n", ShmMsg->I2C_File);
		printf("error: Write result [0x%x], data_sz =[0x%x]\n", RetVal, data_sz+1);
		return -1;
	}
	else
	{
		RetVal = Ok;
	}
	free(temp_list);

	return (RetVal);
}


/* ------------------------------------------------------------------------- *
 * Function Description
 * ------------------------------------------------------------------------- */
/** 
| 함수명 : RTC_Read                                                  
| 
| 기능 : RTC 에서 데이터를 읽어온다.
| 작성자    : 이창수                                                      
| 함수형태 : int RTC_Read(uchar reg_addr, uchar *data, uint data_sz)
| 파라미터 : uchar : [input]
|					RTC Register
|					: 0x0 ~ 0xFFFFFFFF
|		    uchar *data : [ouput]
|					read buffer
|					: 0x0 ~ 0xFFFFFFFF
|		    uint data_sz : [inpu]
|					read data size
|					: 0x0 ~ 0xFFFFFFFF
| 반환 	  : int RetVal : [output]
|					0 : Ok
|					Otherwise : Bad
| 버전        : 1.0
| 수정이력 
|------------------------------------------------------------------------- 
|	20151230 : 최초작성
/------------------------------------------------------------------------- */
int RTC_Read(uchar reg_addr, uchar *data, uint data_sz)
{
	uint RetVal = 0;
	uint data_size = 0;
	uint cnt = 0;
	uchar temp_list[3];

	/* check parameters */
	if((data == NULL) || (data_sz == 0))
	{
		printf("error: Input parameters error [%x] [%x]\n",data, data_sz );
		return -1;
	}
#if 1
	/* write a register address */
	temp_list[0] = reg_addr;
	RetVal = write(ShmMsg->I2C_File, &temp_list[0], 1);
	if(RetVal != 1)
	{
		printf("error: cannot write register address [0x%x]\n", ShmMsg->I2C_File);
		return -1;
	}
#endif
	/* read a data */
	RetVal = read(ShmMsg->I2C_File, data, data_sz);
	if(RetVal != data_sz)
	{
		printf("error: cannot read data [%x] != [%x]\n", RetVal, data_sz);
		return -1;
	}

	return (RetVal);
}


int RTC_SET_Time(char *SetTime)
{
	int RetVal = Ok;
	int idx = 0;
	uchar reg_addr = 0;
	uint size = 0;
	uchar year = 0;
	uchar month = 0;
	uchar date = 0;
	uchar day = 0;
	uchar hour = 0;
	uchar minute = 0;
	uchar second = 0;
	uchar *argv[6];
	uint	TimeValue[7];

	/* 2016-08-11-12-00-00 */
	argv[0] = strtok(SetTime, "-");
	TimeValue[0] = atoi(argv[0]);
	for(idx=1; idx < 6; idx++)
	{
		argv[idx] = strtok(NULL, "-");
		TimeValue[idx] = atoi(argv[idx]);
	}

	/* get a year data */
	if (TimeValue[0] == 0)
	{
		printf("error: invalid year data [%d]\r\n", TimeValue[0]);
		return (RetVal);
	}
	year = (uchar)(TimeValue[0] - 2000);
	
	/* get a month data */
	if ((TimeValue[1] == 0) || (TimeValue[1] > 12))
	{
		printf("error: invalid month data [%d]\r\n", TimeValue[1]);
		return (RetVal);
	}
	month = (uchar)TimeValue[1];

	/* get a date data */
	if ((TimeValue[2] == 0) || (TimeValue[2] > 31))
	{
		printf("error: invalid date data [%d]\r\n", TimeValue[2]);
		return (RetVal);
	}
	date = (uchar)TimeValue[2];
	
	/* get a day data */
	day = 0x0;
	
/* 요일 정보 사용 안함 */
/*
	if (strcmp(argv[3], "SUN") == 0)	
	{
		day = 1;
	}
	else if (strcmp(argv[3], "MON") == 0)	
	{
		day = 2;
	}
	else if (strcmp(argv[3], "TUE") == 0)	
	{
		day = 3;
	}
	else if (strcmp(argv[3], "WED") == 0)	
	{
		day = 4;
	}
	else if (strcmp(argv[3], "THU") == 0)	
	{
		day = 5;
	}
	else if (strcmp(argv[3], "FRI") == 0)	
	{
		day = 6;
	}
	else if (strcmp(argv[3], "SAT") == 0)	
	{
		day = 7;
	}
	else 
	{
		printf("Day of week input value error [%s]\r\n", argv[3]);
		return (RetVal);
	}
*/
	/* get a hour data */
	if (TimeValue[3] > 23)
	{
		printf("error: invalid hour data [%d]\r\n", TimeValue[3]);
		return (RetVal);
	}
	hour = (uchar)TimeValue[3];

	/* get a minute data */
	if (TimeValue[4] > 59)
	{
		printf("error: invalid minute data [%d]\r\n", TimeValue[4]);
		return (RetVal);
	}
	minute = (uchar)TimeValue[4];

	/* get a second data */
	if (TimeValue[5] > 59)
	{
		printf("error: invalid second data [%d]\r\n", TimeValue[5]);
		return (RetVal);
	}
	second = (uchar)TimeValue[5];

	printf("%04d. ", 2000 + year);
	printf("%02d. ", month);
	printf("%02d. - ", date);
	printf("%02d:", hour);
	printf("%02d:", minute);
	printf("%02d\r\n", second);

	change_to_rtc_reg_type(rtc_reg_list, year, month, date, day, hour, minute, second);

	reg_addr = 0;
	size = 7;
	RetVal = RTC_Write(reg_addr, rtc_reg_list, size);
	if (RetVal != 0)
	{
		printf("error: cannot write data to rtc\r\n");
		return (RetVal);
	}		
}


int RTC_GET_Time(void)
{
	int RetVal = Ok;
	uchar reg_addr = 0;
	uint size = 0;
	uchar year = 0;
	uchar month = 0;
	uchar date = 0;
	uchar day = 0;
	uchar hour = 0;
	uchar minute = 0;
	uchar second = 0;
	uchar SyncTime[50];
	
	printf("Load a LDTS Clock from I2C(RTC)\n");
	reg_addr = 0x0;
	size = 7;
	RetVal = RTC_Read(reg_addr, rtc_reg_list, size);
	if (RetVal < 0)
	{
		printf("error: cannot read data from rtc [%x]\r\n", RetVal);
		return RetVal;
	}

#if 0
	    FILE *fp = popen("hwclock -r", "r");
    	if (fp) {
        	if (fgets(buff, 256, fp)) {
            	if (strstr(buff, "failed") == NULL) {
             		pclose(fp);
					printf("\t %s", buff);

					if (++count >= 5)
             			return 1;	// PASS
             		sleep(1);
					continue;
            	}
        	}
        	pclose(fp);
			break;
    	}
		else
			break;
#endif
			
	change_to_raw_type(rtc_reg_list, &year, &month, &date, &day, &hour, &minute, &second);
/*
	printf("[%04d.", 2000 + year);
	printf("%02d.", month);
	printf("%02d.", date);
	printf("[%c], ", day_str[day]);
	printf("%02d:", hour);
	printf("%02d:", minute);
	printf("%02d]\r\n", second);
*/
	printf("Synchronize the local time from RTC.\n");
	sprintf(&SyncTime[0], "date %04d.%02d.%02d-%02d:%02d:%02d", 2000 + year, month, date, hour, minute, second);
	system(&SyncTime[0]);
	return (RetVal);
}

int change_to_raw_type(uchar *rtc_reg_list, uchar *year, uchar *month, uchar *date, uchar *day, uchar *hour, uchar *minute, uchar *second)
{
	uchar tempb0 = 0;
	uchar tempb1 = 0;

	/* change year data */
	tempb0 = (rtc_reg_list[6] & 0xf0) >> 0x4;
	tempb1 = rtc_reg_list[6] & 0x0f;
	(*year) = (tempb0 * 10) + tempb1;

	/* change month data */
	tempb0 = (rtc_reg_list[5] & 0x10) >> 0x4;
	tempb1 = rtc_reg_list[5] & 0x0f;
	(*month) = (tempb0 * 10) + tempb1;

	/* change date data */
	tempb0 = (rtc_reg_list[4] & 0x30) >> 0x4;
	tempb1 = rtc_reg_list[4] & 0x0f;
	(*date) = (tempb0 * 10) + tempb1;

	/* change day data */
	(*day) = rtc_reg_list[3] & 0x7;

	/* change hour data */
	tempb0 = (rtc_reg_list[2] & 0x30) >> 0x4;
	tempb1 = rtc_reg_list[2] & 0x0f;
	(*hour) = (tempb0 * 10) + tempb1;

	/* change minute data */
	tempb0 = (rtc_reg_list[1] & 0x70) >> 0x4;
	tempb1 = rtc_reg_list[1] & 0x0f;
	(*minute) = (tempb0 * 10) + tempb1;

	/* change second data */
	tempb0 = (rtc_reg_list[0] & 0x70) >> 0x4;
	tempb1 = rtc_reg_list[0] & 0x0f;
	(*second) = (tempb0 * 10) + tempb1;

	return 0;
}

int change_to_rtc_reg_type(uchar *rtc_reg_list, uchar year, uchar month, uchar date, uchar day, uchar hour, uchar minute, uchar second)
{
	/* change year data */
	rtc_reg_list[6] = ((year / 10) << 4) | (year % 10);
	/* change month data */
	rtc_reg_list[5] = ((month / 10) << 4) | (month % 10);
	/* change date data */
	rtc_reg_list[4] = ((date / 10) << 4) | (date % 10);
	/* change day data */
	rtc_reg_list[3] = day & 0x7;
	/* change hour data */
	rtc_reg_list[2] = ((hour / 10) << 4) | (hour % 10);
	/* change minute data */
	rtc_reg_list[1] = ((minute / 10) << 4) | (minute % 10);
	/* change second data */
	rtc_reg_list[0] = ((second / 10) << 4) | (second % 10);
	return 0;
}

int Close_FPGA(void)
{
	munmap(CommonReg->FPGA_MEM_BASE, 0x1000);
	close(CommonReg->FPGA_MEM_FD);

	return 0;
}

/* ------------------------------------------------------------------------- *
 * Function Description
 * ------------------------------------------------------------------------- */
/** 
| 함수명 : Open_FPGA                                                  
| 
| 기능 : FPGA Base address 를 읽어 offset value 를 참조하여 각 Component 의 address 를 얻어 공유한다. 
| 작성자    : 이창수                                                      
| 함수형태 : int Open_FPGA(void)   
| 파라미터 : void : [N/A]
| 반환 	  : int : [output]
|					0 : Ok
|					Otherwise : Bad
| 버전        : 1.0
| 수정이력 
|------------------------------------------------------------------------- 
|	20151230 : 최초작성
/------------------------------------------------------------------------- */
int Open_FPGA(void)
{
	int RetVal = Ok;

	/********************************************************************/
	/* Get FPGA Base Address */	
	/********************************************************************/
	CommonReg->FPGA_MAP_TARGET = EMIF_CS1_BASE;
		
	if((CommonReg->FPGA_MEM_FD = open(MAP_FILE_POS, O_RDWR | O_SYNC)) == -1)
	{
		printf("error : fail fpga open %s \r\n", MAP_FILE_POS);
		RetVal = Bad;
		return(RetVal);
	}
	
	CommonReg->FPGA_MEM_BASE = mmap(0, 0x1000, PROT_READ | PROT_WRITE, MAP_SHARED, CommonReg->FPGA_MEM_FD, CommonReg->FPGA_MAP_TARGET);
	if (CommonReg->FPGA_MEM_BASE == (void *)-1)
	{
		printf("error : fail fpga Memory mapped \r\n");
		close(CommonReg->FPGA_MEM_FD);
		RetVal = Bad;
		return(RetVal);
	}

	/* Get Test0 Register Address 0x3400_0002 */
	CommonReg->TEST0 = CommonReg->FPGA_MEM_BASE + FPGA_TEST0_REG_OFFSET;

	/* Get Test1 Register Address 0x3400_0004 */
	CommonReg->TEST1 = CommonReg->FPGA_MEM_BASE + FPGA_TEST1_REG_OFFSET;

	/* Get Test2 Register Address 0x3400_0006 */
	CommonReg->TEST2 = CommonReg->FPGA_MEM_BASE + FPGA_TEST2_REG_OFFSET;

	/* Get Test3 Register Address 0x3400_0008 */
	CommonReg->TEST3 = CommonReg->FPGA_MEM_BASE + FPGA_TEST3_REG_OFFSET;

	/* Get Test4 Register Address 0x3400_000A */
	CommonReg->TEST4 = CommonReg->FPGA_MEM_BASE + FPGA_TEST4_REG_OFFSET;

	/* Get Test5 Register Address 0x3400_000C */
	CommonReg->TEST5 = CommonReg->FPGA_MEM_BASE + FPGA_TEST5_REG_OFFSET;

	/* Get Test6 Register Address 0x3400_000E */
	CommonReg->TEST6 = CommonReg->FPGA_MEM_BASE + FPGA_TEST6_REG_OFFSET;

	/* Get Discrete in Register Address 0x3400_0010 */
	CommonReg->DI = CommonReg->FPGA_MEM_BASE + FPGA_DISC_IN_REG_OFFSET;

	/* Get Discrete out Register Address 0x3400_0012 */
	CommonReg->DO = CommonReg->FPGA_MEM_BASE + FPGA_DISC_OUT_REG_OFFSET;

	/* Get RS-422 Enable/Disable Register Address 0x3400_0014 */
	CommonReg->RS422_ENABLE0 = CommonReg->FPGA_MEM_BASE + FPGA_RS422_CON_REG_OFFSET;
	
	/* Get RS-422 Enable/Disable Register Address 0x3400_0015 */
	CommonReg->RS422_ENABLE1 = CommonReg->FPGA_MEM_BASE + FPGA_RS422_CON_REG_OFFSET + 0x1;

	/* Get RS-422 Mode Dip Switch Register Address 0x3400_0016 */
	CommonReg->RS422_MODE = CommonReg->FPGA_MEM_BASE + FPGA_RS422_MODE_REG_OFFSET;

	/* Get RS-422 Clock Mode Dip Switch Register Address 0x3400_0018 */
	CommonReg->RS422_CLK = CommonReg->FPGA_MEM_BASE + FPGA_RS422_SPEED_REG_OFFSET;

	/* Get Application Switch Address 0x3400_001A */
	CommonReg->APP_SW = CommonReg->FPGA_MEM_BASE + FPGA_APP_MODE_REG_OFFSET;

	/* Get 7-Segment LED Mode Control Address 0x3400_001B */
	CommonReg->FND_ENABLE= CommonReg->FPGA_MEM_BASE + FPGA_SEGMENT_MODE_REG_OFFSET;

	/* Get 7-Segment LED Control Address 0x3400_001C */
	CommonReg->FND_LED = CommonReg->FPGA_MEM_BASE + FPGA_SEGMENT_LED_REG_OFFSET;

	/* Get RUN/Status LED Control Address 0x3400_001E */
	CommonReg->STATUS_LED = CommonReg->FPGA_MEM_BASE + FPGA_STATUS_LED_REG_OFFSET;

	/* Get LED Speed Control Address 0x3400_0020 */
	CommonReg->LED_BLANK = CommonReg->FPGA_MEM_BASE + FPGA_LED_SPEED_REG_OFFSET;

	/* Get RS422 LED Control Address 0x3400_0022 */
	CommonReg->RS422_LED = CommonReg->FPGA_MEM_BASE + FPGA_RS422_LED_CON_REG_OFFSET;

	/* Get RS422 LED Mode Control Address 0x3400_0024 */
	CommonReg->RS422_LED_CON = CommonReg->FPGA_MEM_BASE + FPGA_RS422_LED_MODE_REG_OFFSET;
	
	/* Get Watchdog Timer Control Register Address 0x3400_0026 */
	CommonReg->WDT_CON= CommonReg->FPGA_MEM_BASE + FPGA_WDT_CON_REG_OFFSET;

	/* Get Watchdog Timer Counter Register Address 0x3400_0024 */
	CommonReg->WDT_TIMER = CommonReg->FPGA_MEM_BASE + FPGA_WDT_TIMER_REG_OFFSET;

	/* Get RS422/DIO Termination Control Register Address 0x3400_0030 */
	CommonReg->RS422_TERM_CON = CommonReg->FPGA_MEM_BASE + FPGA_RS422_TERM_CON_REG_OFFSET;

	/* LED Debug disable */
	(*(CommonReg->RS422_LED_CON )) = 0x0;
	/* That's it */

	/* LED Blank speed setting and ACC1,2 LED disable */
//	(*(CommonReg->LED_BLANK )) = 0x3;

	/* FND  Enable */
	(*(CommonReg->FND_ENABLE )) = 0x1;

	return(RetVal);
}


int	VME_Init(void)
{
	int	RetVal = Ok;
	
	/********************************************************************/
	/* Get address for each component										*/
	/********************************************************************/
	//RetVal=Open_FPGA();
	CommonReg->VME0_MAP_TARGET = VME0_REG_BASE;
	CommonReg->VME1_MAP_TARGET = VME1_REG_BASE;

	if((CommonReg->VME0_MEM_FD = open(MAP_FILE_POS, O_RDWR | O_SYNC)) == -1)
	{
		printf("error : fail fpga VME0 open %s \r\n", MAP_FILE_POS);
		RetVal = Bad;
		return(RetVal);
	}
	
	CommonReg->VME0_MEM_BASE = mmap(0, 0x4000, PROT_READ | PROT_WRITE, MAP_SHARED, CommonReg->VME0_MEM_FD, CommonReg->VME0_MAP_TARGET & ~VME_MAP_MASK );
	if (CommonReg->VME0_MEM_BASE == (void *)-1)
	{
		printf("error : fail VME0 Memory mapped \r\n");
		close(CommonReg->VME0_MEM_FD);
		RetVal = Bad;
		return(RetVal);
	}
	CommonReg->VME0_BUFF = CommonReg->VME0_MEM_BASE;

	if((CommonReg->VME1_MEM_FD = open(MAP_FILE_POS, O_RDWR | O_SYNC)) == -1)
	{
		printf("error : fail fpga VME1 open %s \r\n", MAP_FILE_POS);
		RetVal = Bad;
		return(RetVal);
	}
		
	CommonReg->VME1_MEM_BASE = mmap(0, 0x4000, PROT_READ | PROT_WRITE, MAP_SHARED, CommonReg->VME1_MEM_FD, CommonReg->VME1_MAP_TARGET & ~VME_MAP_MASK );
	if (CommonReg->VME1_MEM_BASE == (void *)-1)
	{
		printf("error : fail VME1 Memory mapped \r\n");
		close(CommonReg->VME0_MEM_FD);
		RetVal = Bad;
		return(RetVal);
	}
	CommonReg->VME1_BUFF = CommonReg->VME1_MEM_BASE;
	
	/* That's it */
	return(RetVal);	
}



uchar Read_DI_Channel(int Channel)
{
	uchar RetVal = Ok;
	uchar TmpVal = 0;
	
	/********************************************************************/
	/* Verifying for arg0  												*/
	/********************************************************************/
	if((Channel < 0) ||(Channel > 4))
	{
		printf("Read_DI_Channel : Invalid param Channel[%x]\n", Channel);
		RetVal = Bad;	
	}
	else
	{
		/********************************************************************/
		/* Read Current Status    												*/
		/********************************************************************/
		TmpVal = (*CommonReg->DI);	
		
		/********************************************************************/
		/* Get value from register  												*/
		/********************************************************************/
		switch(Channel)
		{
			case 0 :
				RetVal = TmpVal & 0x1;
				break;
				
			case 1 :
				RetVal = (TmpVal & 0x2) >> 1;
				break;
			
			case 2 :
				RetVal = (TmpVal & 0x4) >> 2;
				break;

			case 3 :
				RetVal = (TmpVal & 0x8) >> 3;
				break;

			default :
				printf("Read_DI_Channel : Invalid param Channel[%x]\n", Channel);
				printf("Current DIO Status [%x]\n", TmpVal);
				RetVal = Bad;
				break;
		}
	}
	return(RetVal);
}


uchar Write_DO_Channel(int Channel, uchar Status)
{
	uchar RetVal = Ok;
	uchar TmpVal = 0;
	
	/********************************************************************/
	/* Read Current Status    												*/
	/********************************************************************/
	TmpVal = (*CommonReg->DO);	

	
	/********************************************************************/
	/* Verifying for arg0  												*/
	/********************************************************************/
	if((Channel < 0) ||(Channel > 4))
	{
		printf("Write_DO_Channel : Invalid param Channel[%x]\n", Channel);
		RetVal = Bad;	
	}
	else
	{
		/********************************************************************/
		/* Make set value */
		/********************************************************************/
		if(Status == set)
		{
			TmpVal |= (0x1<<Channel) ;
		}
		else if(Status == reset)
		{
			TmpVal &= ~(0x1<<Channel) ;
		}
		else
		{
			printf("Write_DO_Channel : Invalid param Status[%x]\n", Status);
			RetVal = Bad;
		}
		
		/********************************************************************/
		/* Set register */
		/********************************************************************/	
		(*CommonReg->DO) = TmpVal;	
		
	}
	return(RetVal);
}

void GPIO_Setup(gpio_type_e type)
{
    int i, size;
    
	switch (type) 
	{
		case GPIO_NONE:
		    for(i=0; i<GPIO_NUM; i++)   
		    {
		        GPIO_Export(gpio_array[i]);  //사용함을 정의
		        GPIO_SetDir(gpio_array[i], GPIO_OUTPUT); // 입력/출력 정의 
		    }
			break;
		case GPIO_DIPSW:			
		    for(i=0; i<8; i++)   
		    {
		        GPIO_Export(gpio_dipsw[i]);
		        GPIO_SetDir(gpio_dipsw[i], GPIO_INPUT);
		    }
			break;			
		case GPIO_RUN_STATUS:
			size = sizeof(gpio_run_status) / sizeof(int);
			for (i = 0; i < size; i++) 
			{
				GPIO_Export(gpio_run_status[i]);
				GPIO_SetDir(gpio_run_status[i], GPIO_OUTPUT);
			}
			break;
		case GPIO_SEGMENT_7:
			for (i = 0; i < GPIO_SEGMENT_7_NUM; i++) 
			{
				GPIO_Export(gpio_segment_7[i]);
				GPIO_SetDir(gpio_segment_7[i], GPIO_OUTPUT);
			}
			break;
		case GPIO_DO:			
			size = sizeof(gpio_do) / sizeof(int);
			for (i = 0; i < size; i++) 
			{
				GPIO_Export(gpio_do[i]);
				GPIO_SetDir(gpio_do[i], GPIO_OUTPUT);
			}
			break;
		case GPIO_DI:
			size = sizeof(gpio_di) / sizeof(int);
			for (i = 0; i < size; i++) 
			{
				GPIO_Export(gpio_di[i]);
				GPIO_SetDir(gpio_di[i], GPIO_INPUT);
			}
			break;
		case GPIO_UART_HDLC:			
			GPIO_Export(gpio_uart_hdlc);
			GPIO_SetDir(gpio_uart_hdlc, GPIO_INPUT);
			break;	
		case GPIO_HDLC_TYPE:
			size = sizeof(gpio_hdlc_type) / sizeof(int);
			for (i = 0; i < size; i++) 
			{
				GPIO_Export(gpio_hdlc_type[i]);
				GPIO_SetDir(gpio_hdlc_type[i], GPIO_INPUT);
			}
			break;	
		case GPIO_VME_CLIENT:
			GPIO_Export(gpio_vme_client);
			GPIO_SetDir(gpio_vme_client, GPIO_INPUT);
			break;
		case GPIO_VME_MASTER_DTACK:
			size = sizeof(gpio_vme_master_dtack) / sizeof(int);
			for (i = 0; i < size; i++) 
			{
				GPIO_Export(gpio_vme_master_dtack[i]);
				GPIO_SetDir(gpio_vme_master_dtack[i], GPIO_INPUT);
			}
			break;
		case GPIO_VME_MEMORY_SIZE:
			size = sizeof(gpio_vme_memory_size) / sizeof(int);
			for (i = 0; i < size; i++) 
			{
				GPIO_Export(gpio_vme_memory_size[i]);
				GPIO_SetDir(gpio_vme_memory_size[i], GPIO_INPUT);
			}
			break;
		case GPIO_VME_DTACK_CLEAR:
			size = sizeof(gpio_vme_dtack_clear) / sizeof(int);
			for (i = 0; i < size; i++) 
			{
				GPIO_Export(gpio_vme_dtack_clear[i]);
				GPIO_SetDir(gpio_vme_dtack_clear[i], GPIO_OUTPUT);
			}
			break;
	}
}

void GPIO_On(gpio_type_e type, int index)
{
    int i, size;
    
	switch (type) 
	{
		case GPIO_NONE:
		    for(i=0; i<GPIO_NUM; i++)   
		    {
		        GPIO_SetVal(gpio_array[i], GPIO_HIGH);
		    }
			break;
		case GPIO_RUN_STATUS:
			size = sizeof(gpio_run_status) / sizeof(int);
			for (i = 0; i < size; i++) 
			{
				GPIO_SetVal(gpio_run_status[i], GPIO_HIGH);
			}
			break;
		case GPIO_SEGMENT_7:
			for (i = 0; i < GPIO_SEGMENT_7_NUM; i++) 
			{
				GPIO_SetVal(gpio_segment_7[i], GPIO_HIGH);
			}
			break;
		case GPIO_DO:			
			size = sizeof(gpio_do) / sizeof(int);
			for (i = 0; i < size; i++) 
			{
				GPIO_SetVal(gpio_do[i], GPIO_HIGH);
			}
			break;
		case GPIO_VME_DTACK_CLEAR:
			GPIO_SetVal(gpio_vme_dtack_clear[index], GPIO_HIGH);
			break;
	}
}

void GPIO_Off(gpio_type_e type, int index)
{
    int i, size;
    
	switch (type) 
	{
		case GPIO_NONE:
		    for(i=0; i<GPIO_NUM; i++)   {
		        GPIO_SetVal(gpio_array[i], GPIO_LOW);
		    }
			break;
		case GPIO_RUN_STATUS:
			size = sizeof(gpio_run_status) / sizeof(int);
			for (i = 0; i < size; i++) {
				GPIO_SetVal(gpio_run_status[i], GPIO_LOW);
			}
			break;
		case GPIO_SEGMENT_7:
			for (i = 0; i < GPIO_SEGMENT_7_NUM; i++) {
				GPIO_SetVal(gpio_segment_7[i], GPIO_LOW);
			}
			break;
		case GPIO_DO:			
			size = sizeof(gpio_do) / sizeof(int);
			for (i = 0; i < size; i++) {
				GPIO_SetVal(gpio_do[i], GPIO_LOW);
			}
			break;
		case GPIO_VME_DTACK_CLEAR:
			GPIO_SetVal(gpio_vme_dtack_clear[index], GPIO_LOW);
			break;
	}
}

//GPIO 사용안함 정의
void GPIO_Release(gpio_type_e type)
{
    int i, size;
    
	switch (type) 
	{
		case GPIO_NONE:
		    for(i=0; i<GPIO_NUM; i++)   {
		        GPIO_Unexport(gpio_array[i]);
		    }
			break;
		case GPIO_RUN_STATUS:
			size = sizeof(gpio_run_status) / sizeof(int);
			for (i = 0; i < size; i++) {
				GPIO_Unexport(gpio_run_status[i]);
			}
			break;
		case GPIO_SEGMENT_7:
			for (i = 0; i < GPIO_SEGMENT_7_NUM; i++) {
				GPIO_Unexport(gpio_segment_7[i]);
			}
			break;
		case GPIO_DO:			
			size = sizeof(gpio_do) / sizeof(int);
			for (i = 0; i < size; i++) {
				GPIO_Unexport(gpio_do[i]);
			}
			break;
		case GPIO_DI:
			size = sizeof(gpio_di) / sizeof(int);
			for (i = 0; i < size; i++) {
				GPIO_Unexport(gpio_di[i]);
			}
			break;
		case GPIO_UART_HDLC:
			GPIO_Unexport(gpio_uart_hdlc);
			break;
		case GPIO_HDLC_TYPE:			
			size = sizeof(gpio_hdlc_type) / sizeof(int);
			for (i = 0; i < size; i++) {
				GPIO_Unexport(gpio_hdlc_type[i]);
			}
			break;
		case GPIO_VME_CLIENT:
			GPIO_Unexport(gpio_vme_client);
			break;
		case GPIO_VME_MASTER_DTACK:
			size = sizeof(gpio_vme_master_dtack) / sizeof(int);
			for (i = 0; i < size; i++) {
				GPIO_Unexport(gpio_vme_master_dtack[i]);
			}
			break;
		case GPIO_VME_MEMORY_SIZE:
			size = sizeof(gpio_vme_memory_size) / sizeof(int);
			for (i = 0; i < size; i++) {
				GPIO_Unexport(gpio_vme_memory_size[i]);
			}
			break;
		case GPIO_VME_DTACK_CLEAR:
			size = sizeof(gpio_vme_dtack_clear) / sizeof(int);
			for (i = 0; i < size; i++) {
				GPIO_Unexport(gpio_vme_dtack_clear[i]);
			}
			break;
		case GPIO_DIPSW:			
		    for(i=0; i<8; i++)   
		    {
		        GPIO_Unexport(gpio_dipsw[i]);
		    }
			break;					
	}
}
//GPIO 사용함 정의
int GPIO_Export(unsigned int gpio)
{
    int fd, len;
    char buf[MAX_BUF];

    fd = open(SYSFS_GPIO_DIR "/export", O_WRONLY);

    if (fd < 0) {
        fprintf(stderr, "Can't export GPIO %d pin: %s\n", gpio, strerror(errno));
        return fd;
    }

    len = snprintf(buf, sizeof(buf), "%d", gpio);
    write(fd, buf, len);
    close(fd);

    return 0;
}
//GPIO 사용안함 정의
int GPIO_Unexport(unsigned int gpio)
{
    int fd, len;
    char buf[MAX_BUF];

    fd = open(SYSFS_GPIO_DIR "/unexport", O_WRONLY);

    if (fd < 0) {
        fprintf(stderr, "Can't unexport GPIO %d pin: %s\n", gpio, strerror(errno));
        return fd;
    }

    len = snprintf(buf, sizeof(buf), "%d", gpio);
    write(fd, buf, len);
    close(fd);

    return 0;
}
//GPIO 입,출력 정의
int GPIO_SetDir(unsigned int gpio, unsigned int dir)//, unsigned int val)
{
    int fd, len;
    char buf[MAX_BUF];

    len = snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR  "/gpio%d/direction", gpio);

    fd = open(buf, O_WRONLY);

    if (fd < 0) {
        fprintf(stderr, "Can't set GPIO %d pin direction: %s\n", gpio, strerror(errno));
        return fd;
    }

    if (dir == GPIO_OUTPUT) {
        write(fd, "out", 4);
    } else {
        write(fd, "in", 3);
    }

    close(fd);

    return 0;
}

int GPIO_GetVal(unsigned int gpio, unsigned int *val)
{
    int fd, len;
    char buf[MAX_BUF];

    len = snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/value", gpio);
	
    fd = open(buf, O_RDONLY);

    if (fd < 0) {
        fprintf(stderr, "Can't get GPIO %d pin value: %s\n", gpio, strerror(errno));
        return fd;
    }

    read(fd, buf, 1);
    close(fd);

	printf("GPIO_GetVal [%x, %s]\n", buf[0], buf);

    if (*buf != '0')
        *val = GPIO_HIGH;
    else
        *val = GPIO_LOW;

    return 0;
}

int GPIO_SetVal(unsigned int gpio, unsigned int val)
{
    int fd, len;
    uchar buf[MAX_BUF];

    len = snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/value", gpio);

    fd = open(buf, O_WRONLY);

    if (fd < 0) {
        fprintf(stderr, "Can't set GPIO %d pin value: %s\n", gpio, strerror(errno));
        return fd;
    }

    if (val == GPIO_HIGH)
        write(fd, "1", 2);
    else
        write(fd, "0", 2);

    close(fd);

    return 0;
}

void DisplaySegment(int num)
{
	int count = 0;
	
	for (count = 0; count < GPIO_SEGMENT_7_NUM; count++) 
	{
		GPIO_SetVal(gpio_segment_7[count], segmentNumber[num][count]);
	}
}


void FND_Test(void)
{
	char count;
	
	GPIO_Setup(GPIO_SEGMENT_7);
	GPIO_On(GPIO_SEGMENT_7, 0);		// 1 : lef off

#if 0	
	usleep(800 * 1000);
	for (count = 0; count < SEGMENT_NUMBER; count++) 
	{
		DisplaySegment(count);
		usleep(500 * 1000);
	}
#endif
	
	GPIO_Off(GPIO_SEGMENT_7, 0);		// 0 : led on
	//GPIO_Release(GPIO_SEGMENT_7); // 사용안함을 정의 
}


uchar LED_CONTROL(int LED, uchar Status)
{
	uchar RetVal = Ok;
	uchar TmpVal = 0;
	
	/********************************************************************/
	/* Read Current Status    												*/
	/********************************************************************/

	//TmpVal = (*CommonReg->STATUS_LED);	
	/********************************************************************/
	/* Verifying for arg0  												*/
	/********************************************************************/
	if((LED < RUN_LED) ||(LED > ALL_LED))
	{
		printf("LED_CONTROL : Invalid param LED[%x]\n", LED);
		RetVal = Bad;	
	}
	else
	{

    	GPIO_Setup(GPIO_RUN_STATUS); // 하는 이유는 ? 그리고 계속해야 하는건지.. 한번만 하면 되는건지 문의 할것 !!

		if(Status == LED_ON)
		{
    		GPIO_On(GPIO_RUN_STATUS, 0);
		}
		else if(Status == LED_OFF)
		{
			GPIO_Off(GPIO_RUN_STATUS, 0);
		}
		else
		{
			printf("LED_CONTROL : Invalid param Status[%x]\n", Status);
			RetVal = Bad;
		}
		
    	GPIO_Release(GPIO_RUN_STATUS); // 하는 이유는 ? 그리고 계속해야 하는건지.. 한번만 하면 되는건지 문의 할것 !!	 	
		
	}
	return(RetVal);
}


uchar LED_CONTROL2(int LED, uchar Status)
{
	uchar RetVal = Ok;
	uchar TmpVal = 0;
	
	/********************************************************************/
	/* Read Current Status    												*/
	/********************************************************************/

	TmpVal = (*CommonReg->STATUS_LED);	
	/********************************************************************/
	/* Verifying for arg0  												*/
	/********************************************************************/
	if((LED < RUN_LED) ||(LED > ALL_LED))
	{
		printf("LED_CONTROL : Invalid param LED[%x]\n", LED);
		RetVal = Bad;	
	}
	else
	{
		if(LED == ALL_LED)
		{
			(*CommonReg->STATUS_LED) = 0xFF;
			TmpVal = (*CommonReg->STATUS_LED);
			return TmpVal;
		}
		
		//SetVal = (0x1 << LED) ;

		if(Status == LED_ON)
		{
			TmpVal &= ~(0x1<<LED) ;
		}
		else if(Status == LED_OFF)
		{
			TmpVal |= (1<<LED) ;
		}
		else
		{
			printf("LED_CONTROL : Invalid param Status[%x]\n", Status);
			RetVal = Bad;
		}
		
		/********************************************************************/
		/* Set register */
		/********************************************************************/	
		(*CommonReg->STATUS_LED) = TmpVal;

		RetVal = (*CommonReg->STATUS_LED);	
	}
	return(RetVal);
}

int UART_RecvData(int Channel, uchar *MsgBuff)
{
	int	Recv_length = 0;
	int	index = 0;
	uchar	RingNum = 0x00;


	RingNum =(uchar)Channel;

	/* Check for Rx Flag */
	if(ShmDrvMsg->RxChFlag[Channel] == RingNum)
	{
		index=0;				
		while(ShmDrvMsg->RX_BUFFER[Channel].front_counter != ShmDrvMsg->RX_BUFFER[Channel].rear_counter)
		{
			MsgBuff[index] = ShmDrvMsg->RX_BUFFER[Channel].contents[ShmDrvMsg->RX_BUFFER[Channel].rear_counter];
			ShmDrvMsg->RX_BUFFER[Channel].rear_counter++;
			index++;			
			if(ShmDrvMsg->RX_BUFFER[Channel].rear_counter == RING_DATA_SIZE)
			{
				ShmDrvMsg->RX_BUFFER[Channel].rear_counter = 0;
			}
		}
		Recv_length = index;
	}
	return(Recv_length);	
}


uchar UART_SendData(int Channel, uchar *MsgBuff, int MsgSize)
{
	int	index = 0;
	uchar RingNum = 0x00;
	
	RingNum =(uchar)Channel;

	/* Check for Tx Flag */
	if(ShmDrvMsg->TxChFlag[Channel] == 0x00)
	{		
		for (index = 0; index < MsgSize; index ++)
		{
			ShmDrvMsg->TX_BUFFER[Channel].contents[index] = MsgBuff[index];
			ShmDrvMsg->TX_BUFFER[Channel].front_counter++;
		}
		ShmDrvMsg->TxChFlag[Channel] = RingNum ;
	}
	else
	{
		printf("TX Flag is occupied [0x%02x]\n", ShmDrvMsg->TxChFlag[Channel]);
	}
	return(ShmDrvMsg->TxChFlag[Channel]);	
}


void	WatchdogReset()
{
	// !!! RESET이 걸려도 마스터 신호가 유지되는 관계로 재 부팅전에
   	//     마스터 신호를 스텐바이로 제어하여 상대방이 온라인이 될 수 있도록 함
	// Diff Out set to High(1)
	ShmMsg->ChangeDevice = set;
	printf("WatchdogReset : WatchdogReset Activated ... \n");	
	system("reboot");
}

void	ChangeEquipmentState()
{
	
 	// 계 절체시 온라인/스텐바이 상태만 바꿈
	// Diff Out set to High(1)
	Write_DO_Channel(0, Level_High);
	LED_CONTROL(STAT_LED, LED_OFF);
	
	ShmMsg->MASTER_INPUT_STATE = Level_Low; // 스텐바이로 설정
	ShmMsg->ChangeDevice = ReseT;
	
	sleep(1);					
}

int	ResetCPU(void)
{		
	printf("ResetCPU : CPU RESET \n ");	
	WatchdogReset();					/* reset*/

	sleep(5);	// 리셋 걸리동안 대기		
	return(1);
}


int SetupCrcTable(void)
{
	unsigned short		index =0;
	unsigned short		number=0;
	unsigned short		word;
	BITS8BYTE		*index_ptr;
	BITS16UINT	*word_ptr;


	for (index = 0; index < 256; index++)
	{
		
		word = 0;
    	index_ptr = (BITS8BYTE *) &index;
    	word_ptr  = (BITS16UINT *) &word;
		number = (index_ptr->i7 ^ index_ptr->i6 ^ index_ptr->i5 ^ index_ptr->i4 ^ index_ptr->i3 ^ index_ptr->i2 ^ index_ptr->i1);
		
		word_ptr->b16 = (index_ptr->i8 ^ number);
		word_ptr->b15 = (number);
		word_ptr->b14 = (index_ptr->i8 ^ index_ptr->i7);
		word_ptr->b13 = (index_ptr->i7 ^ index_ptr->i6);
		word_ptr->b12 = (index_ptr->i6 ^ index_ptr->i5);
		word_ptr->b11 = (index_ptr->i5 ^ index_ptr->i4);
		word_ptr->b10 = (index_ptr->i4 ^ index_ptr->i3);
		word_ptr->b9  = (index_ptr->i3 ^ index_ptr->i2);
		word_ptr->b8  = (index_ptr->i2 ^ index_ptr->i1);
		word_ptr->b7  = (index_ptr->i1);
		word_ptr->b1  = (index_ptr->i8 ^ number);
		crc_table_for_cdts[index] = word;
	}
	return (Ok);
}                                                        
                                                                                
                                                                                
/*----------------------------------------------------------------------------+ 
| 함 수 명 : CalCrcAll                                                        | 
|                                                                             | 
| 입력변수 : length  - 계산 하고자 하는 data의 byte 수.                       |
|            ch      - 계산 하고자 하는 data byte 의 array.                   |
|            all_crc - 처음 crc를 계산 하고자 할때는 반드시 0.                |
|                      이미 계산된 crc 값에 새로운 data byte array의 crc를    |
|                      연장 하려할 때는 이미 계산된 crc 값                    |
|                                                                             |
| 출력변수 : all_crc - 모든 byte에 대한 계산 결과                             |
|                                                                             |
| 결 과 값 : error - 처리한 결과를 나타낸다. 항상 Ok                          |
|                                                                             |
| 함수설명 : polinomial x^16 + x^15 + x^2 + 1 을 이용하여 Cyclic Redundancy   |
|			   Code 를 계산한다.				      |
|            16 bit를 계산하는 것이 아니고 8 bit를 계산하는 것이므로 계산     |
|            하고자 하는 byte 값에 대한 crc table (256 개의 entry를 갖는다)   |
|            의 값을 가지고 와서 계산한다.                                    |
|            array의 length 의 byte에 대해서 계산                             |
|                                                                             |
+-----------------------------------------------------------------------------*/
uint	  CalCrcAll(uint length, uchar ch[], uint *all_crc)
{
 uint   count=0;  // 계산 하는 ch의 순서
 uint   index=0;  // crc table 의 entry no
 uint   crc=0;    // 일시적인 crc 값

 	//if(firstCall==1)
	//{
	//	SetupCrcTable();
 	//}
	
    for (count = 0, crc = *all_crc; count < length; count++)
    {
        index = (crc ^ ch[count]) & 0x00ff; // crc table의 entry no
        crc = (crc >> 8) ^ crc_table[index];// crc 갱신
    }
    *all_crc = crc;     // 새로운 crc
    return(Ok);
}

uint	  DUAL_CalCrcAll(uint length, uchar ch[], uint *all_crc)
{
 uint   count=0;  // 계산 하는 ch의 순서
 uint   index=0;  // crc table 의 entry no
 uint   crc=0;    // 일시적인 crc 값

 	//if(firstCall==1)
	//{
	//	SetupCrcTable();
 	//}
	
    for (count = 0, crc = *all_crc; count < length; count++)
    {
        index = (crc ^ ch[count]) & 0x00ff; // crc table의 entry no
        crc = (crc >> 8) ^ dual_crc_table[index];// crc 갱신
    }
    *all_crc = crc;     // 새로운 crc
    return(Ok);
}


uint	  CalCrcAll2(uint length, uchar ch[])
{
 uint   count=0;  // 계산 하는 ch의 순서
 uint   index=0;  // crc table 의 entry no
 uint   crc=0;    // 일시적인 crc 값
 uint	RetCRC=0;

 	//if(firstCall==1)
	//{
	//	SetupCrcTable();
 	//}
	
    for (count = 0; count < length; count++)
    {
        index = (crc ^ ch[count]) & 0x00ff; // crc table의 entry no
        crc = (crc >> 8) ^ crc_table2[index];// crc 갱신
    }
    RetCRC = crc;     // 새로운 crc
    return(RetCRC);
}

ushort Calculate_CRC(uchar *Buf, uint Len)
{
    uint i=0;                             /* 계산 하는 ch의 순서   */
    ushort  index=0;                            /* crc table 의 entry no */
    ushort  crc=0;                              /* 일시적인 crc 값       */

    for (i = 0, crc = 0; i < Len; i++) /* 3: CRC-L, CRC-H, ETX */
    {
        index = (crc ^ Buf[i]) & 0x00FF;     /* CRC Table의 Entry No */
        crc = (crc >> 8) ^ crc_table[index];  /* CRC 갱신             */
    }
 
    return crc;
}       
                                                        

int	CalCrcAll_For_CDTS(unsigned short length, uchar ch[], unsigned short *all_crc)					
{                                                                           
	uint   count;  /* 계산 하는 ch의 순서*/                                    
	uint   index;  /* crc table 의 entry no*/                                  
	uint   crc;    /* 일시적인 crc 값*/                                        
	
	
	for (count = 0, crc = *all_crc; count < length; count++)                
	{                                                                       
	    index = (crc ^ ch[count]) & 0x00ff; /* crc table의 entry no*/       
	    crc = (crc >> 8) ^ crc_table_for_cdts[index];/* crc 갱신*/                   
	}                                                                       
	*all_crc = crc;     /* 새로운 crc*/                                     
	return(Ok);                                                             
}    

/* ------------------------------------------------------------------------- *
 * Function Description
 * ------------------------------------------------------------------------- */
/** 
 @brief generate the table of CRC remainders for all possible bytes.                                                   
                                                                            
 @author DH.Kim                                                            
 @fn void GenerateCrcTable(void)                                          
 @return[out] no                                                                      
 @version 1.00                                                              
 @section Module-ID
  - MD-0C-3
 @section MODIFYINFO
 - 2015-03-10 / DH.Kim : 최초 작성
*/ 
void GenerateCrcTable(void)
{
	/* table index */
	uint uiIndex;		
	/* table count */
	uint uiCount;		
	/* accumulator value 저장 */
	uint uiCrcAccum;	

	/* CRC table 생성 */
	for(uiIndex=0U; uiIndex < 256U; uiIndex++)
	{
		/* 생성 */
		uiCrcAccum = ((uint) uiIndex << 24U);
		/* loop */
		for(uiCount=0U; uiCount<8U; uiCount++)
		{
			/* 비교 */
			if((uiCrcAccum & 0x80000000U) == 0x80000000U)
			{
				/* 다항식 계산 */
				uiCrcAccum = (uiCrcAccum << 1U) ^ (uint)POLYNOMIAL;
		    }
		    /* 아닌 경우  */
			else
			{	
				/* 생성 값 저장   */
				uiCrcAccum = (uiCrcAccum << 1U);
			}
		}
		/* crc table 에 생성 값 저장 */
		guiCrcTable[(int)uiIndex] = uiCrcAccum;

	}
} /* end of  GenerateCrcTable() */

/* ------------------------------------------------------------------------- *
 * Function Description
 * ------------------------------------------------------------------------- */
/** 
 @brief update the CRC on the data block one byte at a time.                                                   
                                                                            
 @author DH.Kim                                                            
 @fn uint32 CalculateCrc32(uint32 uiAccumCrc, const uint8* pucDataBlkPtr,uint32 uiDataBlkSize)
 @param[in] uint32 uiAccumCrc  - crc value 
 @param[in] const uint8* pucDataBlkPtr  - data pointer
 @param[in] uint32 uiDataBlkSize  - data length 
 @return[out] uint32 uiAccumCrc : Calculated CRC32 value                                                                         
 @version 1.00                                                              
 @section Module-ID
  - MD-01-5-2-2
 @section MODIFYINFO
 - 2015-03-10 / DH.Kim : 최초 작성
*/ 
uint CalculateCrc32(uint uiAccumCrc, const uchar* pucDataBlkPtr,uint uiDataBlkSize)
{
	/* table index */
	uint uiIndex;		
	/* table count */
	uint uiCount;		
	/* data value 저장 */
	uchar  ucDataValue = 0U;
	
    /* blk size만큼 crc calculation */
	for(uiCount=0U; uiCount<uiDataBlkSize; uiCount++)
	{	
		/* 계산할 데이터 저장 */
		ucDataValue = pucDataBlkPtr[(int)uiCount];
		/* crc table의 index 위치 계산 */
		uiIndex = ((uint)((uint)uiAccumCrc >> 24U) ^ ucDataValue) & 0xffU;
		/* crc table 로 부터 crc value 생성 */
		uiAccumCrc = ((uint)uiAccumCrc << 8U) ^ guiCrcTable[(int)uiIndex];
	}
	/* 생성된 CRC value 반환 */
	return uiAccumCrc;
} /* end of  CalculateCrc32() */ 

/* ------------------------------------------------------------------------- *
* calc_crc32() Function Declaration
* ------------------------------------------------------------------------- */
uint calc_crc32(uchar* pvStartAddress, uint ulSize_in_bytes)
{
    uint 	 crc;
    uchar*   bufptr;
	/* data value 저장 */
	uchar  ucDataValue = 0U;
	/* table index */
	uint uiIndex;		
	uint uiAddr;
		
   crc    = CRC32_INIT;
   bufptr = (uchar*)pvStartAddress;

	   
   while (ulSize_in_bytes != 0U)
   {
   	  	ulSize_in_bytes--;
   	  	ucDataValue = *bufptr;

		/* crc table의 index 위치 계산 */
		uiIndex = (uint)(crc ^ ucDataValue) & 0x0FFLU;
      	crc = g_tableof_CRC32[uiIndex] ^ (crc >> 8U);

		bufptr++;
   }
  
   return (uint)(crc ^ CRC32_XOROT);
}


/* ------------------------------------------------------------------------- *
* calc_crc32() Function Declaration for RBC
* ------------------------------------------------------------------------- */
void chksum_crc32gentab ()
{
   uint crc32, poly;  /*crc table 생성에 필요한 변수 선언*/
   uint i, j;         /*반복문 제어변수 선언*/
   
   if(isFirstCallCRC32GenTab == 1)
   {
	   poly = 0xEDB88320U;          /*poly값 설정*/
	   for (i = 0; i < 256; i++)    /*반복실행*/
	   {
	      crc32 = i;                /*crc초기화*/
	      for (j = 8; j > 0; j--)   /*반복실행*/
	      {
	          if ((crc32 & 1) == 1) /*crc가 홀수인 경우*/
	          {
	             crc32 = (crc32 >> 1) ^ poly;   /*crc계산*/
	          }
	          else                  /*crc가 짝수인 경우*/
	          {
	             crc32 >>= 1;                   /*crc계산*/
	          }
	      }
	      crc_tab[i] = crc32;       /*crc table 생성*/
	      /*printf("[%d]<%X>\n", i, crc);*/
	   }
   }	
	
}

uint CalcCRC32 (const uchar* block, uint length)
{
   register uint crc32;       /*crc변수 선언*/
   uint i;    /*반복문 제어변수 선언*/

	/* CRC Table을 생성시킨다.*/
   if(isFirstCallCRC32GenTab == 1)  
   { 
   		chksum_crc32gentab(); 
   }                   

   crc32 = 0xFFFFFFFFU;             /*crc초기값*/
   for (i = 0; i < length; i++)     /*반복 실행*/
   {
      crc32 = ((crc32 >> 8) & 0x00FFFFFF) ^ crc_tab[(crc32 ^ block[i])& 0xFF];  /*crc계산*/
   }
   return (crc32 ^ 0xFFFFFFFFU);    /*crc리턴*/
}
