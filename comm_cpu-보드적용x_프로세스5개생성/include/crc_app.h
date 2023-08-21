#ifndef _CRC_H_
#define _CRC_H_

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
* @file     CRC.h : CCommThread 클래스의 인터페이스 해더 파일.
*
* @project  KRS-EIS
* @process  EICON
* @author   DAEATI/Jeong Y.J
* @version  Revision 0.0.9a
* @dev-env  Microsoft Visual Studio Professional 2013K 버전 12.0.21005.1 REL
*           Microsoft .NET Framework 4.5.51209
*           Window 7 Professional K 6.1.7601 SP1 build 7601
*           (CPU: intel i5-4200M 2.5Ghz, RAM 8G)
* @exe-env  	WinXP SP3 이상
* @library  없음.
* @files    CRC.c
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

/* ///////////////////////////////////////////////////////////////////////// */
/* Include Files                                                             */
/* ///////////////////////////////////////////////////////////////////////// */

/*#include	"defconstant.h"*/		/** 전역으로 사용될 기본 데이터 타입 정의 해더파일 포함 */
/*#include	"defendian.h"*/		/** Endian 정의 해더파일 포함 */

/* ///////////////////////////////////////////////////////////////////////// */
/* 공용 구조체 정의                                                          */
/* ///////////////////////////////////////////////////////////////////////// */

/* ------------------------------------------------------------------------- */
/* CRC-32의 데이터 필드(Field) 구조체 정의                                   */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_CRC32_DATA
* @brief CRC-32의 데이터 필드(Field) 구조체
*/
typedef union {/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;외부 I/F Data packet 1000 byte이내에서 이벤트 형식으로 사용함] */
	uint32	ulCRC32;		/** 4 byte size 의 long data */
	uint8	uchCRC32[4];	/** data low => uchCRC32[0], data high => uchCRC32[3] */
} TS_CRC32_DATA;


/* ///////////////////////////////////////////////////////////////////////// */
/* 공용 함수 정의                                                            */
/* ///////////////////////////////////////////////////////////////////////// */

uint16  VxCalcCrc16 (const uint8 *ucBuf, uint16 usLen);		/* big endian 용 crc16 계산 함수, CTC, LDTS, RC 에서 사용 */


/* ------------------------------------------------------------------------- */

#endif /* #ifndef _CRC_H_ */
