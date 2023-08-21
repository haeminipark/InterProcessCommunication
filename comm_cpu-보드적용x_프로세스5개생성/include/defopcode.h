#ifndef _DEFOPCODE_H_
#define _DEFOPCODE_H_

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
* @file     defopcode.h : header file
* @project  KRS-EIS
* @process  CRC32
* @author   DAEATI/Jeong Y.J
* @version  Revision 0.0.9a
* @dev-env  	Microsoft Visual Studio Professional 2013K ���� 12.0.21005.1 REL
*           Microsoft .NET Framework 4.5.51209
*			Window 7 Professional K 6.1.7601 SP1 build 7601
*			(CPU: intel i5-4200M 2.5Ghz, RAM 8G)
* @exe-env	WinXP SP3 �̻�.
* @library	not used.
* @brief    MMI �� Operation �� �ʿ��� ���� Code ���� �����Ѵ�.
* @see      history is described below.
*/
/* ------------------------------------------------------------------------- */
/* File History                                                              */
/* ------------------------------------------------------------------------- */
/**
* @date 2015-07-25
* @brief version 1.0 ������ History.
* @brief 1. header file ���ʻ���(by JeongYJ)
*/

/* ///////////////////////////////////////////////////////////////////////// */
/* Include Files                                                             */
/* ///////////////////////////////////////////////////////////////////////// */

#include	"defconstant.h"			/** �������� ���� �⺻ ������ Ÿ�� ���� �ش����� ���� */ 
#include	"defendian.h"			/** Endian ���� �ش����� ���� */ 

#pragma pack(1)

/* ///////////////////////////////////////////////////////////////////////// */
/* ���������ڵ�/Constant/��������/�������ڿ��� ����(�Ǵ� ����)               */
/* ///////////////////////////////////////////////////////////////////////// */

/* ///////////////////////////////////////////////////////////////////////// */
/* ������ȣ�� ���� Control Code ����                                         */
/* ///////////////////////////////////////////////////////////////////////// */
#define CTRL_CODE_TRNO_ALT	0x51	/** ������ȣ ���� �䱸 ���� �ڵ� */
#define CTRL_CODE_TRNO_DEL	0x52	/** ������ȣ ���� �䱸 ���� �ڵ� */
#define CTRL_CODE_TRNO_XCH 	0x53	/** ������ȣ ��ȯ �䱸 ���� �ڵ� */
#define CTRL_CODE_TRNO_SET 	0x54	/** ������ȣ ���� �䱸 ���� �ڵ� */


/* ///////////////////////////////////////////////////////////////////////// */
/* ����ü ����                                                               */
/* ///////////////////////////////////////////////////////////////////////// */
#define MAX_LEN_TRAINNO		5
#define MAX_LEN_USERNAME	30
#define MAX_LEN_REASON		40
#define MAX_LEN_USERTEXT	20
/* ------------------------------------------------------------------------- */
/* Element ����(Control) �޽����� ������ �ʵ�(Field) ����ü ����             */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_REQ_DATA
* @brief Element ����(Control) �޽����� ������ �ʵ�(Field) ����ü
*/
typedef struct {
	uint8  ucCtrlCode;		/** 0, ���� �ڵ� (Element Control Code�� ����, Element Table.h ����) */
	uint16  usElementID;	/** 1~2, ���� ��� Element�� ID */
	uint8  ucCtrlState;		/** 3, ���� �������� */
} TS_ELM_CTRL_REQ_DATA;

/* ------------------------------------------------------------------------- */
/* ��� ����(Control) �޽����� ������ �ʵ�(Field) ����ü ����                */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_EM_ELM_CTRL_REQ_DATA
* @brief ��� ����(Control) �޽����� ������ �ʵ�(Field) ����ü
*/
typedef struct {
	uint8  ucCtrlCode;		/** 0, ���� �ڵ�, (Element Control Code�� ����, Element Table.h ����) */
	uint16  usElementID;		/** 1~2, ���� ��� Element�� ID */
	uint8  ucCtrlState;		/** 3, ���� �������� */
	uint8  ucUserName[MAX_LEN_USERNAME];	/** 4~33, ����ڸ� */
	uint8  ucCtrlReason[MAX_LEN_REASON];	/** 34~73, ��޻��� */
} TS_EM_ELM_CTRL_REQ_DATA;

/* ------------------------------------------------------------------------- */
/* ������Ŭ�� �ð�����ȭ �޽����� ������ �ʵ�(Field) ����ü ����             */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_MSG_MASTER_CLOCK_DATA
* @brief ������Ŭ�� �ð�����ȭ �޽����� ������ �ʵ�(Field) ����ü
*/
typedef struct {
	uint8 ucYear;		/** 0, ���� �⵵, 0 ~ 255(2000�� ~ 2255��) */
	uint8 ucMonth;		/** 1, ���� ��, 1 ~ 12(��) */
	uint8 ucDay;			/** 2, ���� ��, 1 ~ 31(��) */
	uint8 ucHour;		/** 3, ���� �ð�, 0 ~ 23(��) */
	uint8 ucMinute;		/** 4, ���� ��, 0 ~ 59(��) */
	uint8 ucSecond;		/** 5, ���� ��, 0 ~ 59(��) */
} TS_MSG_MASTER_CLOCK_DATA;

/* ------------------------------------------------------------------------- */
/* ������ȣ �����䱸 �޽����� ������ �ʵ�(Field) ����ü ����                 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_MSG_TRNO_SET_DATA
* @brief ������ȣ �����䱸 �޽����� ������ �ʵ�(Field) ����ü
*/
typedef struct {
	uint8 ucCtrlCode;		/** 0, �����ڵ�, 0x54 */
	uint16 usElementID;		/** 1~2, �˵�ȸ�� Element ID (1 ~ 511) */
	uint8 aucTrainNumber[MAX_LEN_TRAINNO];	/** 3~7, �����ϰ��� �ϴ� ������ȣ */
} TS_MSG_TRNO_SET_DATA;

/* ------------------------------------------------------------------------- */
/* ������ȣ ����䱸 �޽����� ������ �ʵ�(Field) ����ü ����                 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_MSG_TRNO_ALT_DATA
* @brief ������ȣ ����䱸 �޽����� ������ �ʵ�(Field) ����ü
*/
typedef struct {
	uint8 ucCtrlCode;			/** 0, �����ڵ�, 0x51 */
	uint8 aucSourceTrNo[MAX_LEN_TRAINNO];		/** 1~5, �����ϰ��� �ϴ� ������ ������ȣ */
	uint8 aucTargetTrNo[MAX_LEN_TRAINNO];		/** 6~10, �����ϰ��� �ϴ� ������ ������ȣ */
} TS_MSG_TRNO_ALT_DATA;

/* ------------------------------------------------------------------------- */
/* ������ȣ ��ȯ�䱸 �޽����� ������ �ʵ�(Field) ����ü ����                 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_MSG_TRNO_XCH_DATA
* @brief ������ȣ ��ȯ�䱸 �޽����� ������ �ʵ�(Field) ����ü
*/
typedef struct {
	uint8 ucCtrlCode;			/** 0, �����ڵ�, 0x53 */
	uint8 aucTrainNumber1[MAX_LEN_TRAINNO];	/** 1~5, ��ȯ�ϰ��� �ϴ� ������ȣ #1 */
	uint8 aucTrainNumber2[MAX_LEN_TRAINNO];	/** 6~10, ��ȯ�ϰ��� �ϴ� ������ȣ #2 */
} TS_MSG_TRNO_XCH_DATA;

/* ------------------------------------------------------------------------- */
/* ������ȣ �����䱸 �޽����� ������ �ʵ�(Field) ����ü ����                 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_MSG_TRNO_DEL_DATA
* @brief ������ȣ �����䱸 �޽����� ������ �ʵ�(Field) ����ü
*/
typedef struct {
	uint8 ucCtrlCode;			/** 0, �����ڵ�, 0x52 */
	uint8 aucTrainNumber[MAX_LEN_TRAINNO];		/** 1~5, �����ϰ��� �ϴ� ������ȣ */
} TS_MSG_TRNO_DEL_DATA;

/* ------------------------------------------------------------------------- */
/* ������ȣ ���� ������ �ʵ�(Field) ����ü ����                              */
/* ------------------------------------------------------------------------- */
/**
* @struct TU_MSG_TRNO_CTRL_DATA
* @brief ������ȣ ���� ������ �ʵ�(Field)�� ���� ����ü
*/
typedef union { /* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;�ܺ� I/F Data packet 1000 byte�̳����� �̺�Ʈ �������� �����] */
	uint8 aucTrainNumberCtrl[12];			/** ������ȣ ���� ������ �ʵ� ���� ���� */
	TS_MSG_TRNO_SET_DATA tTNSetData;		/** ������ȣ �����䱸 �޽����� ������ �ʵ�(Field) */
	TS_MSG_TRNO_ALT_DATA tTNAltData;		/** ������ȣ ����䱸 �޽����� ������ �ʵ�(Field) */
	TS_MSG_TRNO_XCH_DATA tTNXchData;		/** ������ȣ ��ȯ�䱸 �޽����� ������ �ʵ�(Field) */
	TS_MSG_TRNO_DEL_DATA tTNDelData;		/** ������ȣ �����䱸 �޽����� ������ �ʵ�(Field) */
} TU_MSG_TRNO_CTRL_DATA;

/* ------------------------------------------------------------------------- */
/* ����ڵ�� ǥ�� �޽����� ������ �ʵ�(Field) ����ü ����                 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_MSG_USER_TEXT_DATA
* @brief ����ڵ�� ǥ�� ���� �޽����� ������ �ʵ�(Field) ����ü
*/
typedef struct {
	uint8 ucCtrlCode;						/** 0, �����ڵ�, 0x10:����, 0x20:���� */
	uint16 usID;								/** 1~2 ǥ�� ���� ID */
	uint16 usPosX;							/** 3~4, ��ǥ x */
	uint16 usPosY;							/** 5~6, ��ǥ x */
	uint8 aucUserText[MAX_LEN_USERTEXT];		/** 7~26, ����ڰ� ������ ǥ������ */
} TS_MSG_USER_TEXT_DATA;

/* ------------------------------------------------------------------------- */
/* MMI �۽� ���� ������ �ʵ�(Field) ����ü ����                              */
/* ------------------------------------------------------------------------- */
/**
* @struct TU_MSG_MMI_FRM_DATA
* @brief ������ȣ ���� ������ �ʵ�(Field)�� ���� ����ü
*/

typedef union {/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;�ܺ� I/F Data packet 1000 byte�̳����� �̺�Ʈ �������� �����] */
	uint8 aucMsgFrameDataByMMI[80];		/** MMI �۽� �޽����� ������ �ʵ� ���� ���� */
	struct {
		uint8 ucFunc;					/** function code */
		union {/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;�ܺ� I/F Data packet 1000 byte�̳����� �̺�Ʈ �������� �����] */
			TS_ELM_CTRL_REQ_DATA	tElmCtrlReqData;	/** Element ������ ���� �䱸 �޽����� ������ �ʵ�(field) */
			TS_EM_ELM_CTRL_REQ_DATA tEmElmCtrlReqData;	/** ��� ���� �䱸 �޽����� ������ �ʵ�(field) */
			TS_MSG_MASTER_CLOCK_DATA	tMasterClock;	/** �ð����� ������ �޽����� ������ �ʵ�(field) */
			TS_MSG_TRNO_SET_DATA	tTNSetData;			/** ������ȣ �����䱸 �޽����� ������ �ʵ�(Field) */
			TS_MSG_TRNO_ALT_DATA	tTNAltData;			/** ������ȣ ����䱸 �޽����� ������ �ʵ�(Field) */
			TS_MSG_TRNO_XCH_DATA	tTNXchData;			/** ������ȣ ��ȯ�䱸 �޽����� ������ �ʵ�(Field) */
			TS_MSG_TRNO_DEL_DATA	tTNDelData;			/** ������ȣ �����䱸 �޽����� ������ �ʵ�(Field) */
			TU_MSG_TRNO_CTRL_DATA	tTrnoCtrlData;		/** ������ȣ ����ü�� Accessing �� ���� ���� */
			TS_MSG_USER_TEXT_DATA	tUserTextData;		/** ����ڵ��ǥ�� �޽����� ������ �ʵ�(Field) */
		} MSG;
	} TS;
} TU_MSG_MMI_FRM_DATA;


/* CTLMSCR �� */
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* ��� �޼��� & ���� �޼��� & Functions Call Message */
#define WS_OPMSG_CMDCLEAR		0		/* CMD CLEAR */
#define WS_OPMSG_START			1		/* �ý��� �⵿(CMD, ~CMD) */
#define WS_OPMSG_RESET 			2		/* �ý��� �ʱ�ȭ(CMD, ~CMD) */
#define WS_OPMSG_SETTIMER		3		/* UNIT �ð� ����(��,��,��,��,��,��)(CMD, Clock[0], Clock[1], Clock[2], Clock[3]) */
#define WS_OPMSG_SETTRAINNAME	4		/* ���� ��ȣ ����(CMD,TrNo[0], TrNo[1], TrNo[2], TrNo[3], TrNo[4], 0x00) */
#define WS_OPMSG_SIGNALDEST		5		/* ��ȣ (��� ����)���(CMD, SignaIID(byte), button ID(byte)) */
#define WS_OPMSG_SIGNALCANCEL	6		/* ��ȣ (��� ����)���(CMD, SignalID) */
#define WS_OPMSG_TTB			7		/* TTB ��� (CMD, ID) */
#define WS_OPMSG_TTBCANCEL		8		/* TTB ��� (CMD, ID) */
#define WS_OPMSG_SWTOGGLE		9		/* ������ȯ�� ���(toggle) (CMD, ID) */
#define WS_OPMSG_BUTTON			10		/* ��ư �޼���(CMD, ID, ON/OFF), CTC, LOCAL, EXTLOCAL, S, P ... */
#define WS_OPMSG_SWNORMAL		11		/* ������ȯ�� ���� ���� (CMD, PointID) */
#define WS_OPMSG_SWREVERSE		12		/* ������ȯ�� ���� ���� (CMD, PointID) */
#define WS_OPMSG_USERFREETRACK	13		/* �˵� ������ ����(CMD, ID, LOCKING MODE) */
#define WS_OPMSG_USERLOCKTRACK	14		/* �˵� ������ ����(CMD, ID, LOCKING MODE) */
#define WS_OPMSG_ROUTEEMRELEASE	15		/* �������κ������(CMD, ID)  */
#define WS_OPMSG_SETLCCLOCKS	16		/* LCC ������ ����(CMD, LOCKING MODE) */
#define WS_OPMSG_FREELCCLOCK	17		/* LCC ������ ����(CMD, LOCKING MODE) */
#define WS_OPMSG_EMSIGNALDEST	18		/* ��� ��ȣ (��� ����)���(CMD, SignaIID(byte), button ID(byte)) */
#define WS_OPMSG_LCCCTRLLOCK	19		/* LCC ������� ���� ���(CMD, user ID) */
#define WS_OPMSG_LCCCTRLFREE	20		/* LCC ������� ���� ���(CMD, user ID) */
#define WS_OPMSG_USERCHANGE		21		/* ���� ������� ����� �̸� ����(CMD, user string) */
#define WS_OPMSG_USERADDITION	22		/* ����� �̸� ���(CMD, user string, password) */
#define WS_OPMSG_USERDELETE		23		/* ����� �̸� ����(CMD, user string, password) */
#define WS_OPMSG_GETBINFILE		29		/* BIN(*.S) FILE LOAD(CMD, block ID) */
#define WS_OPMSG_EMLOCAL		30		/* ���LOCAL ��ȯ */
#define WS_OPMSG_CTCREQ			31		/* CTC ��ȯ �䱸  */
#define WS_OPMSG_CTCREQCANCEL	32		/* CTC ��ȯ �䱸 ���  */
#define WS_OPMSG_RCREQ			33 		/* RC ��ȯ �䱸 */
#define WS_OPMSG_RCREQCANCEL	34 		/* RC ��ȯ �䱸 ��� */
#define WS_OPMSG_GETADJTRACKS	35		/* �����˵� ID ���� �䱸(CMD, track ID), ��ȯ(high 16 bit:left track ID, low 16 bit: right track ID) */
#define	WS_OPMSG_SHUNTLAMPOFF	36		/* ��ȯ�ҵ� ��ư���(0:��ް���, 1:��޺Ұ����� ǥ��) */
#define WS_OPMSG_GETUSERLABEL	37		/* CTLMscr -> MMI�� ����ڵ�� ������(OPCODE, ǥ��������ȣ, ��ǥ, ���ڿ� ������) ����. */
#define WS_OPMSG_CLRUSERLABEL	38		/* MMI -> CTLMscr �� ����ڵ�� ������(ǥ��������ȣ) ����. */
#define WS_OPMSG_GETRPPBYSG		39		/* signal �� ���� rpp ���¸� ��ȯ(return: 0:�ֽ�ȣ����(A1) or ��ȯǥ��(X) or ��ȯ ǥ���� �������� �ٸ� ��ȯ��߽�ȣ��(A2@)�� ����, 1:��ȯǥ���� ������ �ִ� ��ȯ��ȣ�� ����. */

/* ����� ��ɹ�ȣ �߰� */
/* Function Call Message */
#define WS_OPMSG_LOADFILE		41		/* SFM Load */
#define WS_OPMSG_ASSIGNSCRINFO	42		/* Assign Info(Down.bin) */
#define WS_OPMSG_UPDATESCREEN	43		/* Update VMem buffer */
#define WS_OPMSG_SETMSCRSIZE	44		/* Set MSCR SIZE (resizing) */
#define WS_OPMSG_SETMSCROPTION	45		/* ǥ�� �� ���� �ɼ� ���� */
#define WS_OPMSG_SETOPTERATOR	46		/* ���� ������ ���� */
/* Fail Functions */
#define WS_OPMSG_COMSTATUS		50		/* ��� ���� ����(0:/normal, other/fail) */
#define WS_OPMSG_OPERATESTATE	51		/* ���� LOCKING �ɼ� ����.  */
#define WS_OPMSG_SETDISPTIME	60		/* ��� �ð� ������ ǥ�� ����(�»��� ���� �ð� �ؿ� ǥ��)  */
#define WS_OPMSG_CALLCHECKROUTE	90		/* Call Check route in EipEmp class */
#define WS_OPMSG_GETSCRINFO		98		/* Get ScrInfo class Table ptr */
#define WS_OPMSG_GETEMUPTR		99		/* Get EipEmp class ptr */

/*#define WS_OPMSG_GETCOUNTTRACK	100	 */	/* Get Track count in EipEmp class */
/*#define WS_OPMSG_GETCOUNTSIGNAL	101	 */	/* Get Signal count in EipEmp class */
/*#define WS_OPMSG_GETCOUNTSWITCH	102	 */	/* Get Switch count in EipEmp class */
/*#define WS_OPMSG_GETCOUNTBUTTON	103	 */	/* Get Button count in EipEmp class */
/*#define WS_OPMSG_GETCOUNTLAMP	104	 */	/* Get Lamp count in EipEmp class */

#define WS_OPMSG_GETTRACKLOCKID	105		/* �˵� �������� ���� Ȯ�� �� ����� �˵� ID ��ȯ. */

#define WS_OPMSG_OBJECTMODIFY	254		/* ������Ʈ �� ���� */
#define WS_OPMSG_TRKSEL			255		/* �˵� ���� */
/*/////////////////////////////////////////////////////////////////////////// */

/*/////////////////////////////////////////////////////////////////////////// */
/* ������ ������ �� */
#define TRACKLOCK_FREE			0x00
/* #define TRACKLOCK_PWRDOWN		0x40 */
/* #define TRACKLOCK_MOTORCAR		0x80 */
/* #define TRACKLOCK_USING			0xc0 */

/* ///////////////////////////////////////////////////////////////////////////// */

/* ------------------------------------------------------------------------- */
/* tGPT(Target General Task) - OPC,RC,CTC �� ����(����,�ð�) �ڵ� ����       */
/*   ; OPC,RC & CTC �� ������ȣ, �ð����� ��Ŷ ������ �����Ͽ�,              */
/*     �� ��� Task���� FunctionCode��                                       */
/*       - COMM_MMI_FUNC_TRAINNUMBER or COMM_CTC_FUNC_TRAINNUMBER            */
/*       - COMM_MMI_FUNC_MASTERCLOCK or COMM_CTC_FUNC_MASTERCLOCK            */
/*     �� ��� ���� ������ GPT MSGQ_RX_GEN Q�� ����                          */
/*     ���� �� Cmd Code[0] ���� data�� �� ���Task���� ������                */
/*                                                                           */
/* tGPT ���� �ڵ�                                                            */
/*	[0] : Cmd Code : (��:CTC ��� & ������ȣ ��� => 0x11)                   */
/*  [0] byte ���� ���(Data) ���� �� �� ���Task���� ������ ������ ��������  */
/*  �� data ����.                                                            */
/*      - TS_MSG_MASTER_CLOCK_DATA                                           */
/*      - TS_MSG_TRNO_SET_DATA                                               */
/*      - TS_MSG_TRNO_ALT_DATA                                               */
/*      - TS_MSG_TRNO_XCH_DATA                                               */
/*      - TS_MSG_TRNO_DEL_DATA                                               */
/* ------------------------------------------------------------------------- */
#define	GPT_R_CMD_CODE_OPC		((uint8)0x00)
#define	GPT_R_CMD_CODE_CTC		((uint8)0x01)
#define	GPT_R_CMD_CODE_RC		((uint8)0x02)

#define GPT_R_CMD_TRNO			((uint8)0x10)
#define GPT_R_CMD_CLOCK			((uint8)0x20)

#endif /** #ifndef _DEFOPCODE_H_ */
