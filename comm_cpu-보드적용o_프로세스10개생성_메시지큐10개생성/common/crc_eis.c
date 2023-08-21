/*-----------------------------------------------------------------------------+
|                 CopyRight �� DaeaTi Co., Ltd.                                |
|                 All Rights Reserved                                          |
+------------------------------------------------------------------------------+
| FILE        : crc_eis.c                                                      |
| DIRECTORY   : 													           |
| PROCESS     :                                                                |
| �� �� ��    : Korail                                                         |
| PROJECT     : ����/���� ������                                               |
| �ۼ� ����   : 2010.08.20                                                     |
| �� �� ��    :                                                                |
| SYSTEM ���� : ���� ȯ�� - PC                                                 |
|               � ��ü�� - Linux                                            |
|               TARGET    -   IXP430  									       |
|               LANGUAGE  -   C language                                       |
+------------------------------------------------------------------------------+
| 1. FUNCTION DESCRIPTION                                                      |
|																			   |																			 |
| 2. �Ҽ� �Լ�                                                                 |
|																			   |																		 |
| 3. Routine Tree                                                              |
|                                                                              |
+------------------------------------------------------------------------------*/


#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <unistd.h>
#include    <sys/types.h>
#include    <sys/ipc.h>
#include    <sys/msg.h>
#include	"define.h"
#include	"proto.h"

static unsigned int crc2_table[256] = {0x0000,
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
 0x81C1, 0x8081, 0x4040 };

typedef struct        {
        uchar        i9 : 8;         /* bit8 ~ bit15 �� byte ��  */
        uchar        i8 : 1;         /* bit0 �� �ǹ�             */
        uchar        i7 : 1;
        uchar        i6 : 1;
        uchar        i5 : 1;
        uchar        i4 : 1;
        uchar        i3 : 1;
        uchar        i2 : 1;
        uchar        i1 : 1;
}       BITS8_BYTE;

typedef struct      {               /* crc table�� ����� �� ���   */
        uchar        b16 : 1;         /* bit0 �� �ǹ�                 */
        uchar        b15 : 1;
        uchar        b14 : 1;
        uchar        b13 : 1;
        uchar        b12 : 1;
        uchar        b11 : 1;
        uchar        b10 : 1;
        uchar        b9 : 1;
        uchar        b8 : 1;
        uchar        b7 : 1;
        uchar        b6 : 1;
        uchar        b5 : 1;
        uchar        b4 : 1;
        uchar        b3 : 1;
        uchar        b2 : 1;        /* bit 15�� �ǹ�                */
        uchar        b1 : 1;
}    BITS16_UINT;


void  CrcTableCreate2(void)
{
    ushort       index;           /* crc table�� index            */
    ushort       number;          /* ���� data                    */
    ushort       word;            /* 16 bit data                  */
    BITS8_BYTE  *index_ptr;      /* index �� ����ų pointer      */
    BITS16_UINT *word_ptr;       /* word �� ����ų pointer       */
    
    for (index = 0; index < 256; index++)
    {
        word = 0;
        index_ptr = (BITS8_BYTE *) &index;
        word_ptr  = (BITS16_UINT *) &word;

        number = (index_ptr->i7 ^ index_ptr->i6 ^ index_ptr->i5 ^
                 index_ptr->i4 ^ index_ptr->i3 ^ index_ptr->i2 ^ index_ptr->i1);

         /* printf("number = [%d][%d]\n", index, number);  */

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

        crc2_table[index] = word;
          /* printf("Crc Table = [%d]-[%X]\n", index, crc2_table[index]);  */
    }

    return;
}

ushort  CalcCrc (char *Buf, int Len)
{
    int i;                             /* ��� �ϴ� ch�� ����   */
    ushort  index;                            /* crc table �� entry no */
    ushort  crc;                              /* �Ͻ����� crc ��       */

    for (i = 0, crc = 0; i < Len; i++) /* 3: CRC-L, CRC-H, ETX */
    {
        index = (crc ^ Buf[i]) & 0x00FF;     /* CRC Table�� Entry No */
        crc = (crc >> 8) ^ crc2_table[index];  /* CRC ����             */
    }
 
    return crc;
}   
