#ifndef  _DEFCONSTANT_H_
#define  _DEFCONSTANT_H_

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
* @file     defconstant.h : header file
* @project  KRS-EIS
* @process  CRC32
* @author   DAEATI/Jeong Y.J
* @version  Revision 0.0.9a
* @dev-env  	Microsoft Visual Studio Professional 2013K 버전 12.0.21005.1 REL
*           Microsoft .NET Framework 4.5.51209
*			Window 7 Professional K 6.1.7601 SP1 build 7601
*			(CPU: intel i5-4200M 2.5Ghz, RAM 8G)
* @exe-env	WinXP SP3 이상.
* @library	not used.
* @brief    전역으로 사용될 데이터의 타입 또는 고정 숫자, 계산식을 정의한다.
* @see		history is described below.
*/
/* ------------------------------------------------------------------------- */
/* File History                                                              */
/* ------------------------------------------------------------------------- */
/**
* @date  2015-07-25
* @brief   version 1.0 에서의 History.
* @brief   1. header file 최초생성(by JeongYJ)
*/

/* ------------------------------------------------------------------------- */
/* General Value Define                                                      */
/* ------------------------------------------------------------------------- */
/* scope status */
#define PUBLIC  
#define PRIVATE	static

/* defined const value of the NULL character */
#ifndef NULL
#ifdef __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif

#ifndef SET
#define	SET					1
#endif /* SET */

#ifndef RESET
#define RESET				0
#endif /* RESET */

#ifndef USED
#define USED				1
#endif /* USED */

#ifndef FIND 
#define FIND				1
#endif /* FIND */

#ifndef FAILURE
#define FAILURE				0
#endif /* FAILURE */

#ifndef SUCCESS
#define SUCCESS				1
#endif /* SUCCESS */

#ifndef NONEBYTE
#define NONEBYTE			((BYTE)0x00)	/*MISRA-C 2004:19.04:매크로가 허용되지 않는 형태의 키워드로 재정의:()*/
#endif /* NONEBYTE */

#define VAL_STATUS_ERROR	-1	/* error status */
#define VAL_STATUS_OFF		 0	/* off status */
#define VAL_STATUS_ON		 1	/* on status */

/* false and true */
#ifndef FALSE
#define FALSE		(0)	/* false */
#endif /* FALSE */

#ifndef TRUE
#define TRUE		(1)	/* true */
#endif /* TRUE */

/* return status values */
#ifndef OK
#define OK			0
#endif

#ifndef ERROR
#define ERROR		(-1)
#endif

#ifndef NOGOOD
#define	NOGOOD          0
#endif

#ifndef GOOD
#define	GOOD            1
#endif

#if 0
/* ------------------------------------------------------------------------- */
/* Variable Type Define                                                      */
/* ------------------------------------------------------------------------- */
/* For a 32-bit integer machine, these are as follows. */
#ifndef BOOL
typedef int					BOOL;		/** FALSE or TRUE */
#endif /* BOOL */

#ifndef BYTE
typedef unsigned char       BYTE;
#endif /* BYTE */

#ifndef WORD	/*MISRA-C 2004:6.3:크기와 부호를 알 수 있는 타입을 사용*/
typedef char				CHAR;
typedef unsigned int        UINT;
typedef unsigned long       DWORD;
typedef unsigned short      WORD;
#endif /* WORD */

#ifndef INT8_T
typedef	char				CHAR_T ;		/* plain character */
typedef	signed char			SINT8_T ;		/* 8 bit (1 byte) size */
typedef	char				INT8_T ;		/* 8 bit (1 byte) size */
typedef signed short		SINT16_T ;		/* 16 bit (2 byte) size */
typedef short				INT16_T ;		/* 16 bit (2 byte) size */
typedef	signed int			SINT32_T ;		/* 32 bit (4 byte) size */
typedef	int					INT32_T ;		/* 32 bit (4 byte) size */
typedef	signed long long	SINT64_T ;		/* 64 bit (8 byte) size */
typedef	long long			INT64_T ;		/* 64 bit (8 byte) size */
typedef unsigned char		UINT8_T ;		/* 8 bit (1 byte) size */
typedef unsigned short		UINT16_T ;		/* 16 bit (2 byte) size */
typedef unsigned int		UINT32_T ;		/* 32 bit (4 byte) size */
typedef unsigned long long	UINT64_T ;		/* 64 bit (8 byte) size */
typedef	float				FLOAT32_T ;		/* 32 bit (4 byte) size */
typedef	double				FLOAT64_T ;		/* 64 bit (8 byte) size */
#endif /* INT8_T */

#endif
/* ----------------------------------------------------------------------- */

#endif /* _DEFCONSTANT_H_ */
