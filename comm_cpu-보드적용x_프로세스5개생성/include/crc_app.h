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
* @file     CRC.h : CCommThread Ŭ������ �������̽� �ش� ����.
*
* @project  KRS-EIS
* @process  EICON
* @author   DAEATI/Jeong Y.J
* @version  Revision 0.0.9a
* @dev-env  Microsoft Visual Studio Professional 2013K ���� 12.0.21005.1 REL
*           Microsoft .NET Framework 4.5.51209
*           Window 7 Professional K 6.1.7601 SP1 build 7601
*           (CPU: intel i5-4200M 2.5Ghz, RAM 8G)
* @exe-env  	WinXP SP3 �̻�
* @library  ����.
* @files    CRC.c
* @see      history is described below.
*/
/* ------------------------------------------------------------------------- */
/* File History                                                              */
/* ------------------------------------------------------------------------- */
/**
* @date  2015-07-25
* @brief   version 1.0 ������ History.
* @brief   1. header file ���ʻ���(by JeongYJ)
*/

/* ///////////////////////////////////////////////////////////////////////// */
/* Include Files                                                             */
/* ///////////////////////////////////////////////////////////////////////// */

/*#include	"defconstant.h"*/		/** �������� ���� �⺻ ������ Ÿ�� ���� �ش����� ���� */
/*#include	"defendian.h"*/		/** Endian ���� �ش����� ���� */

/* ///////////////////////////////////////////////////////////////////////// */
/* ���� ����ü ����                                                          */
/* ///////////////////////////////////////////////////////////////////////// */

/* ------------------------------------------------------------------------- */
/* CRC-32�� ������ �ʵ�(Field) ����ü ����                                   */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_CRC32_DATA
* @brief CRC-32�� ������ �ʵ�(Field) ����ü
*/
typedef union {/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;�ܺ� I/F Data packet 1000 byte�̳����� �̺�Ʈ �������� �����] */
	uint32	ulCRC32;		/** 4 byte size �� long data */
	uint8	uchCRC32[4];	/** data low => uchCRC32[0], data high => uchCRC32[3] */
} TS_CRC32_DATA;


/* ///////////////////////////////////////////////////////////////////////// */
/* ���� �Լ� ����                                                            */
/* ///////////////////////////////////////////////////////////////////////// */

uint16  VxCalcCrc16 (const uint8 *ucBuf, uint16 usLen);		/* big endian �� crc16 ��� �Լ�, CTC, LDTS, RC ���� ��� */


/* ------------------------------------------------------------------------- */

#endif /* #ifndef _CRC_H_ */
