#ifndef  _DEFEVENTMSG_H_
#define  _DEFEVENTMSG_H_

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
* @file     defeventmsg.h : header file
* @project  KRS-EIS
* @process  EICON, EIPROC
* @author   DAEATI/Jeong Y.J
* @version  Revision 0.0.9a
* @dev-env  	Microsoft Visual Studio Professional 2013K 버전 12.0.21005.1 REL
*           Microsoft .NET Framework 4.5.51209
*			Window 7 Professional K 6.1.7601 SP1 build 7601
*			(CPU: intel i5-4200M 2.5Ghz, RAM 8G)
* @exe-env	WinXP SP3 이상. VxWorks 6.9
* @library	not used.
* @brief    Event Message를 다루는 구조체 및 전역 문자 및 상수를 정의한다.
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


/* ///////////////////////////////////////////////////////////////////////// */
/* Include Files                                                             */
/* ///////////////////////////////////////////////////////////////////////// */

#include	"defconstant.h"
#include	"defendian.h"

#pragma pack(1)

/* ///////////////////////////////////////////////////////////////////////// */
/* 사전정의코드/Constant/전역변수/참조문자열을 정의(또는 선언)               */
/* ///////////////////////////////////////////////////////////////////////// */

/* ------------------------------------------------------------------------- */
/* Defined General Const Value.                                              */
/* ------------------------------------------------------------------------- */
/* 이벤트 메시지 리스트의 형태정보 */
#define EVENT_MSGTYPE_NOTHING			0	/** 규정되지 않은 메시지(메시지 없음) */
#define EVENT_MSGTYPE_CONTROLLING		1	/** 취급 이벤트 메시지 */
#define EVENT_MSGTYPE_INTERLOCKING		2	/** 연동 이벤트 메시지 */
#define EVENT_MSGTYPE_FAILURE			3	/** 장애 이벤트 메시지 */
#define EVENT_MSGTYPE_SYSTEM			4	/** 시스템 이벤트 메시지 */
#define EVENT_MSGTYPE_OTHERS			5	/** 기타 이벤트 메시지 */

/* 이벤트 메시지 파라메터 최대 갯수 정의 */
#define MAX_EVENTMSG_PARAM_CNT			4	/** 이벤트 메시지의 정수형 파라메터는 최대 4개로 정의 */
#define MAX_EVENTMSG_STRING_CNT			3	/** 이벤트 메시지의 문자형 파라메터는 최대 3개로 정의 */
#define SIZE_MSGSTR						10U	/** 이벤트 메시지 문자형 파라메터의 문자열 최대 크기  */
/* 문자열 최대 개수 정의 */
#define MAX_EVENTMSG_STR_REASON			40	/** 취급사유에 대한 입력문자 최대 개수(영문 40자, 한글 20자) 정의 */
#define MAX_EVENTMSG_STR_OPERATOR		20	/** 취급사유에 대한 입력문자 최대 개수(영문 20자, 한글 10자) 정의 */
#define MAX_EVENTMSG_STR_TRAINNO		5	/** 열차번호에 대한 입력문자 최대 개수(5 BYTE) 정의 */

/* 이벤트 메시지 Date 구조체의 년도 데이터에 대한 기본 년도 정의 */
#define DEF_BASED_YEARS					2000	/** 이벤트 메시지 date 구조체의 년도 데이터에 대한 기본 년도 정의 */


/* ///////////////////////////////////////////////////////////////////////// */
/* 공용 구조체 정의                                                          */
/* ///////////////////////////////////////////////////////////////////////// */

/* ------------------------------------------------------------------------- */
/* 이벤트 메시지 데이터 구조체 정의                                          */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_EVNMSG_PARAM
* @brief 이벤트 메시지의 기본형 파라메터 - 숫자/문자형 정보를 가지는 구조체.
*/
typedef struct {
	uint16 usMsgNo;								/** 이벤트 메시지 번호 */
	uint16 usPARAM[MAX_EVENTMSG_PARAM_CNT];		/** 이벤트 메시지 숫자형 파라메터 */
	uint8 acStr[MAX_EVENTMSG_STRING_CNT][SIZE_MSGSTR];	/** 이벤트 메시지 문자형 파라메터 */
} TS_EVNMSG_PARAM;

/**
* @struct TS_EVNMSG_PARAM
* @brief 이벤트 메시지의 확장형 파라메터 - 숫자/문자형(기본 문자형 + sizeof(TS_EVNMSG_PARAM) 만큼의 문자열 추가 확보) 정보를 가지는 구조체(TS_EVNMSG_PARAM 구조체의 2배 크기임).
*/
typedef struct {
	uint16 usMsgNo;								/** 이벤트 메시지 번호 */
	uint16 usPARAM[MAX_EVENTMSG_PARAM_CNT];		/** 이벤트 메시지 숫자형 파라메터 */
	uint8 acStrEx1[sizeof(TS_EVNMSG_PARAM)];		/** 이벤트 메시지 확장 문자형 파라메터(예:취급사유(최대 40자)) or 취급자(최대 30자) */
	uint8 acStrEx2[(MAX_EVENTMSG_STRING_CNT * SIZE_MSGSTR)];		/** 이벤트 메시지 문자형 파라메터(예:취급자(최대30자)) */
} TS_EVNMSG_PARAM_EX;

typedef union {/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;외부 I/F Data packet 1000 byte이내에서 이벤트 형식으로 사용함] */
	TS_EVNMSG_PARAM		tParam;
	TS_EVNMSG_PARAM_EX	tParamEx;
} TU_EVNMSG_PARAMS;


#ifndef DEF_TS_COMM_TIME_DATA
#define DEF_TS_COMM_TIME_DATA
/**
* @struct TS_COMM_TIME_DATA
* @brief 통신프레임의 시간 정보 구조체.
*/
typedef struct {
	uint8 ucYear;				/** 3 메시지블럭의 생성 년도, 0 ~ 255(2000년 ~ 2255년) */
	uint8 ucMonth;				/** 4, 메시지블럭의 생성 월, 1 ~ 12(월) */
	uint8 ucDay;					/** 5, 메시지블럭의 생성 일, 1 ~ 31(일) */
	uint8 ucHour;				/** 6, 메시지블럭의 생성 시간, 0 ~ 23(시) */
	uint8 ucMinute;				/** 7, 메시지블럭의 생성 분, 0 ~ 59(분) */
	uint8 ucSecond;				/** 8, 메시지블럭의 생성 초, 0 ~ 59(초) */
	uint8 uc10msec;				/** 9, 메시지블럭의 생성 1/100초, 0 ~ 99(10ms~990ms) */
} TS_COMM_TIME_DATA;
#endif /* #ifndef DEF_TS_COMM_TIME_DATA */

typedef struct {
	sint32				lIndex;	/*MISRA-C 2004:6.3:basic type 사용 금지:long->sint64*/
	TS_COMM_TIME_DATA	tTimeDate;
	TU_EVNMSG_PARAMS	tEventMsg;
} TS_EVNMSG_LOG_DATA;


/* ----------------------------------------------------------------------- */

#endif /* _DEFEVENTMSG_H_ */
