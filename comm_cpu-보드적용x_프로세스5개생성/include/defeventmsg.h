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
* @dev-env  	Microsoft Visual Studio Professional 2013K ���� 12.0.21005.1 REL
*           Microsoft .NET Framework 4.5.51209
*			Window 7 Professional K 6.1.7601 SP1 build 7601
*			(CPU: intel i5-4200M 2.5Ghz, RAM 8G)
* @exe-env	WinXP SP3 �̻�. VxWorks 6.9
* @library	not used.
* @brief    Event Message�� �ٷ�� ����ü �� ���� ���� �� ����� �����Ѵ�.
* @see		history is described below.
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

#include	"defconstant.h"
#include	"defendian.h"

#pragma pack(1)

/* ///////////////////////////////////////////////////////////////////////// */
/* ���������ڵ�/Constant/��������/�������ڿ��� ����(�Ǵ� ����)               */
/* ///////////////////////////////////////////////////////////////////////// */

/* ------------------------------------------------------------------------- */
/* Defined General Const Value.                                              */
/* ------------------------------------------------------------------------- */
/* �̺�Ʈ �޽��� ����Ʈ�� �������� */
#define EVENT_MSGTYPE_NOTHING			0	/** �������� ���� �޽���(�޽��� ����) */
#define EVENT_MSGTYPE_CONTROLLING		1	/** ��� �̺�Ʈ �޽��� */
#define EVENT_MSGTYPE_INTERLOCKING		2	/** ���� �̺�Ʈ �޽��� */
#define EVENT_MSGTYPE_FAILURE			3	/** ��� �̺�Ʈ �޽��� */
#define EVENT_MSGTYPE_SYSTEM			4	/** �ý��� �̺�Ʈ �޽��� */
#define EVENT_MSGTYPE_OTHERS			5	/** ��Ÿ �̺�Ʈ �޽��� */

/* �̺�Ʈ �޽��� �Ķ���� �ִ� ���� ���� */
#define MAX_EVENTMSG_PARAM_CNT			4	/** �̺�Ʈ �޽����� ������ �Ķ���ʹ� �ִ� 4���� ���� */
#define MAX_EVENTMSG_STRING_CNT			3	/** �̺�Ʈ �޽����� ������ �Ķ���ʹ� �ִ� 3���� ���� */
#define SIZE_MSGSTR						10U	/** �̺�Ʈ �޽��� ������ �Ķ������ ���ڿ� �ִ� ũ��  */
/* ���ڿ� �ִ� ���� ���� */
#define MAX_EVENTMSG_STR_REASON			40	/** ��޻����� ���� �Է¹��� �ִ� ����(���� 40��, �ѱ� 20��) ���� */
#define MAX_EVENTMSG_STR_OPERATOR		20	/** ��޻����� ���� �Է¹��� �ִ� ����(���� 20��, �ѱ� 10��) ���� */
#define MAX_EVENTMSG_STR_TRAINNO		5	/** ������ȣ�� ���� �Է¹��� �ִ� ����(5 BYTE) ���� */

/* �̺�Ʈ �޽��� Date ����ü�� �⵵ �����Ϳ� ���� �⺻ �⵵ ���� */
#define DEF_BASED_YEARS					2000	/** �̺�Ʈ �޽��� date ����ü�� �⵵ �����Ϳ� ���� �⺻ �⵵ ���� */


/* ///////////////////////////////////////////////////////////////////////// */
/* ���� ����ü ����                                                          */
/* ///////////////////////////////////////////////////////////////////////// */

/* ------------------------------------------------------------------------- */
/* �̺�Ʈ �޽��� ������ ����ü ����                                          */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_EVNMSG_PARAM
* @brief �̺�Ʈ �޽����� �⺻�� �Ķ���� - ����/������ ������ ������ ����ü.
*/
typedef struct {
	uint16 usMsgNo;								/** �̺�Ʈ �޽��� ��ȣ */
	uint16 usPARAM[MAX_EVENTMSG_PARAM_CNT];		/** �̺�Ʈ �޽��� ������ �Ķ���� */
	uint8 acStr[MAX_EVENTMSG_STRING_CNT][SIZE_MSGSTR];	/** �̺�Ʈ �޽��� ������ �Ķ���� */
} TS_EVNMSG_PARAM;

/**
* @struct TS_EVNMSG_PARAM
* @brief �̺�Ʈ �޽����� Ȯ���� �Ķ���� - ����/������(�⺻ ������ + sizeof(TS_EVNMSG_PARAM) ��ŭ�� ���ڿ� �߰� Ȯ��) ������ ������ ����ü(TS_EVNMSG_PARAM ����ü�� 2�� ũ����).
*/
typedef struct {
	uint16 usMsgNo;								/** �̺�Ʈ �޽��� ��ȣ */
	uint16 usPARAM[MAX_EVENTMSG_PARAM_CNT];		/** �̺�Ʈ �޽��� ������ �Ķ���� */
	uint8 acStrEx1[sizeof(TS_EVNMSG_PARAM)];		/** �̺�Ʈ �޽��� Ȯ�� ������ �Ķ����(��:��޻���(�ִ� 40��)) or �����(�ִ� 30��) */
	uint8 acStrEx2[(MAX_EVENTMSG_STRING_CNT * SIZE_MSGSTR)];		/** �̺�Ʈ �޽��� ������ �Ķ����(��:�����(�ִ�30��)) */
} TS_EVNMSG_PARAM_EX;

typedef union {/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;�ܺ� I/F Data packet 1000 byte�̳����� �̺�Ʈ �������� �����] */
	TS_EVNMSG_PARAM		tParam;
	TS_EVNMSG_PARAM_EX	tParamEx;
} TU_EVNMSG_PARAMS;


#ifndef DEF_TS_COMM_TIME_DATA
#define DEF_TS_COMM_TIME_DATA
/**
* @struct TS_COMM_TIME_DATA
* @brief ����������� �ð� ���� ����ü.
*/
typedef struct {
	uint8 ucYear;				/** 3 �޽������� ���� �⵵, 0 ~ 255(2000�� ~ 2255��) */
	uint8 ucMonth;				/** 4, �޽������� ���� ��, 1 ~ 12(��) */
	uint8 ucDay;					/** 5, �޽������� ���� ��, 1 ~ 31(��) */
	uint8 ucHour;				/** 6, �޽������� ���� �ð�, 0 ~ 23(��) */
	uint8 ucMinute;				/** 7, �޽������� ���� ��, 0 ~ 59(��) */
	uint8 ucSecond;				/** 8, �޽������� ���� ��, 0 ~ 59(��) */
	uint8 uc10msec;				/** 9, �޽������� ���� 1/100��, 0 ~ 99(10ms~990ms) */
} TS_COMM_TIME_DATA;
#endif /* #ifndef DEF_TS_COMM_TIME_DATA */

typedef struct {
	sint32				lIndex;	/*MISRA-C 2004:6.3:basic type ��� ����:long->sint64*/
	TS_COMM_TIME_DATA	tTimeDate;
	TU_EVNMSG_PARAMS	tEventMsg;
} TS_EVNMSG_LOG_DATA;


/* ----------------------------------------------------------------------- */

#endif /* _DEFEVENTMSG_H_ */
