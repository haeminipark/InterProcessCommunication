#ifndef _DEFENDIAN_H_
#define _DEFENDIAN_H_

/* ------------------------------------------------------------------------- */
/* Copyright                                                                 */
/* ------------------------------------------------------------------------- */
/**
* EIS Application Developed by KRSEIS Team
*
* Copyright (c) 2015 DAEATI co.,ltd
* 200-1, Nae-dong, Ojeong-gu, Bucheon-si, Gyeonggi-do, Korea
* All rights reserved.
*/
/* ------------------------------------------------------------------------- */
/* File Desicriotion                                                         */
/* ------------------------------------------------------------------------- */
/**
* @file     defendian.h : header file
* @project  KRS-EIS
* @process  CRC32
* @author   DAEATI/Jeong Y.J
* @version  Revision 0.0.9a
* @dev-env  	Microsoft Visual Studio Professional 2013K 버전 12.0.21005.1 REL
*           Microsoft .NET Framework 4.5.51209
*           Window 7 Professional K 6.1.7601 SP1 build 7601
*           (CPU: intel i5-4200M 2.5Ghz, RAM 8G)
* @exe-env  WinXP SP3 이상.
* @library  not used.
* @brief    전역으로 사용될 Endian type을 정의한다.
* @see      history is described below.
*/
/* ------------------------------------------------------------------------- */
/* File History                                                              */
/* ------------------------------------------------------------------------- */
/**
* @date  2015-07-25
* @brief   version 1.0 에서의 History.
* @brief   1. header file 최초생성(by JeongYJ)
*/

/* ----------------------------------------------------------------------- */
/* #include	"hal_stdtypes.h"	*/ /*#include <stdint.h>*//*Add header file by RJH for using uint32*/


/* ///////////////////////////////////////////////////////////////////////// */
/* 사전정의코드/Constant/전역변수/참조문자열을 정의(또는 선언)               */
/* ///////////////////////////////////////////////////////////////////////// */


#if 0
/* Swap 4 byte, 32 bit values: */
#define Swap4Bytes(val) \
 ( (((val) >> 24) & 0x000000FFlU) | (((val) >>  8) & 0x0000FF00lU) | \
   (((val) <<  8) & 0x00FF0000lU) | (((val) << 24) & 0xFF000000lU) )

/*Swap 8 byte, 64 bit values: */
#define Swap8Bytes(val) \
 ( (((val) >> 56) & 0x00000000000000FF) | (((val) >> 40) & 0x000000000000FF00) | \
   (((val) >> 24) & 0x0000000000FF0000) | (((val) >>  8) & 0x00000000FF000000) | \
   (((val) <<  8) & 0x000000FF00000000) | (((val) << 24) & 0x0000FF0000000000) | \
   (((val) << 40) & 0x00FF000000000000) | (((val) << 56) & 0xFF00000000000000) )
/* ------------------------------------------------------------------------- */
/* for ZEST EI and WINDOWS(INTEL Style) : LITTLE ENDIAN                                  */
/* ------------------------------------------------------------------------- */
/* Swap 2 byte, 16 bit values: */
#define Swap2Bytes(val) \
 ( (((val) >> 8U) & 0x00FFU) | (((val) << 8U) & 0xFF00U) )
#endif

/* ------------------------------------------------------------------------- */
/* WORD/DWORD 구조체 정의                                                    */
/* ------------------------------------------------------------------------- */
/**
* @struct TU_WORD2BYTE, TU_DWORD2BYTE
* @brief WORD와 DWORD에 대한 BYTE 위치를 정의하는 구조체
*/
typedef union {/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;외부 I/F Data packet 1000 byte이내에서 이벤트 형식으로 사용함] */
	uint16	wWORD;		/** WORD (2 Byte) 변수 정의 */
	struct {
		uint8 D0;		/** WORD의 Low Byte에 해당하는 Byte 변수 정의 */
		uint8 D1;		/** WORD의 High Byte에 해당하는 Byte 변수 정의 */
	} w;
} TU_WORD2BYTE;

typedef union {/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;외부 I/F Data packet 1000 byte이내에서 이벤트 형식으로 사용함] */
	uint32	dwDWORD;	/** DOUBLE WORD (4 Byte) 변수 정의 */
	struct {
		uint8 D0;		/** DWORD의 최하위 Byte에 해당하는 byte 변수 정의 */
		uint8 D1;		/** DWORD의 하위 byte에 해당하는 byte 변수 정의 */
		uint8 D2;		/** DWORD의 상위 byte에 해당하는 byte 변수 정의 */
		uint8 D3;		/** DWORD의 최상위 Byte에 해당하는 Byte 변수 정의 */
	} dw;
} TU_DWORD2BYTE;


/* ///////////////////////////////////////////////////////////////////////// */


/* ----------------------------------------------------------------------- */

#endif /* _DEFENDIAN_H_ */
