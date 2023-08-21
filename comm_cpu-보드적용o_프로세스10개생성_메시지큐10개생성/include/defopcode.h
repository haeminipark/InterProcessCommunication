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
* @dev-env  	Microsoft Visual Studio Professional 2013K 버전 12.0.21005.1 REL
*           Microsoft .NET Framework 4.5.51209
*			Window 7 Professional K 6.1.7601 SP1 build 7601
*			(CPU: intel i5-4200M 2.5Ghz, RAM 8G)
* @exe-env	WinXP SP3 이상.
* @library	not used.
* @brief    MMI 의 Operation 에 필요한 제어 Code 값을 정의한다.
* @see      history is described below.
*/
/* ------------------------------------------------------------------------- */
/* File History                                                              */
/* ------------------------------------------------------------------------- */
/**
* @date 2015-07-25
* @brief version 1.0 에서의 History.
* @brief 1. header file 최초생성(by JeongYJ)
*/

/* ///////////////////////////////////////////////////////////////////////// */
/* Include Files                                                             */
/* ///////////////////////////////////////////////////////////////////////// */

#include	"defconstant.h"			/** 전역으로 사용될 기본 데이터 타입 정의 해더파일 포함 */ 
#include	"defendian.h"			/** Endian 정의 해더파일 포함 */ 

#pragma pack(1)

/* ///////////////////////////////////////////////////////////////////////// */
/* 사전정의코드/Constant/전역변수/참조문자열을 정의(또는 선언)               */
/* ///////////////////////////////////////////////////////////////////////// */

/* ///////////////////////////////////////////////////////////////////////// */
/* 열차번호에 대한 Control Code 정의                                         */
/* ///////////////////////////////////////////////////////////////////////// */
#define CTRL_CODE_TRNO_ALT	0x51	/** 열차번호 변경 요구 제어 코드 */
#define CTRL_CODE_TRNO_DEL	0x52	/** 열차번호 삭제 요구 제어 코드 */
#define CTRL_CODE_TRNO_XCH 	0x53	/** 열차번호 교환 요구 제어 코드 */
#define CTRL_CODE_TRNO_SET 	0x54	/** 열차번호 생성 요구 제어 코드 */


/* ///////////////////////////////////////////////////////////////////////// */
/* 구조체 정의                                                               */
/* ///////////////////////////////////////////////////////////////////////// */
#define MAX_LEN_TRAINNO		5
#define MAX_LEN_USERNAME	30
#define MAX_LEN_REASON		40
#define MAX_LEN_USERTEXT	20
/* ------------------------------------------------------------------------- */
/* Element 제어(Control) 메시지의 데이터 필드(Field) 구조체 정의             */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_REQ_DATA
* @brief Element 제어(Control) 메시지의 데이터 필드(Field) 구조체
*/
typedef struct {
	uint8  ucCtrlCode;		/** 0, 제어 코드 (Element Control Code의 정의, Element Table.h 참조) */
	uint16  usElementID;	/** 1~2, 제어 대상 Element의 ID */
	uint8  ucCtrlState;		/** 3, 제어 상태정보 */
} TS_ELM_CTRL_REQ_DATA;

/* ------------------------------------------------------------------------- */
/* 비상 제어(Control) 메시지의 데이터 필드(Field) 구조체 정의                */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_EM_ELM_CTRL_REQ_DATA
* @brief 비상 제어(Control) 메시지의 데이터 필드(Field) 구조체
*/
typedef struct {
	uint8  ucCtrlCode;		/** 0, 제어 코드, (Element Control Code의 정의, Element Table.h 참조) */
	uint16  usElementID;		/** 1~2, 제어 대상 Element의 ID */
	uint8  ucCtrlState;		/** 3, 제어 상태정보 */
	uint8  ucUserName[MAX_LEN_USERNAME];	/** 4~33, 취급자명 */
	uint8  ucCtrlReason[MAX_LEN_REASON];	/** 34~73, 취급사유 */
} TS_EM_ELM_CTRL_REQ_DATA;

/* ------------------------------------------------------------------------- */
/* 마스터클럭 시각동기화 메시지의 데이터 필드(Field) 구조체 정의             */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_MSG_MASTER_CLOCK_DATA
* @brief 마스터클럭 시각동기화 메시지의 데이터 필드(Field) 구조체
*/
typedef struct {
	uint8 ucYear;		/** 0, 설정 년도, 0 ~ 255(2000년 ~ 2255년) */
	uint8 ucMonth;		/** 1, 설정 월, 1 ~ 12(월) */
	uint8 ucDay;			/** 2, 설정 일, 1 ~ 31(일) */
	uint8 ucHour;		/** 3, 설정 시간, 0 ~ 23(시) */
	uint8 ucMinute;		/** 4, 설정 분, 0 ~ 59(분) */
	uint8 ucSecond;		/** 5, 설정 초, 0 ~ 59(초) */
} TS_MSG_MASTER_CLOCK_DATA;

/* ------------------------------------------------------------------------- */
/* 열차번호 생성요구 메시지의 데이터 필드(Field) 구조체 정의                 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_MSG_TRNO_SET_DATA
* @brief 열차번호 생성요구 메시지의 데이터 필드(Field) 구조체
*/
typedef struct {
	uint8 ucCtrlCode;		/** 0, 제어코드, 0x54 */
	uint16 usElementID;		/** 1~2, 궤도회로 Element ID (1 ~ 511) */
	uint8 aucTrainNumber[MAX_LEN_TRAINNO];	/** 3~7, 설정하고자 하는 열차번호 */
} TS_MSG_TRNO_SET_DATA;

/* ------------------------------------------------------------------------- */
/* 열차번호 변경요구 메시지의 데이터 필드(Field) 구조체 정의                 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_MSG_TRNO_ALT_DATA
* @brief 열차번호 변경요구 메시지의 데이터 필드(Field) 구조체
*/
typedef struct {
	uint8 ucCtrlCode;			/** 0, 제어코드, 0x51 */
	uint8 aucSourceTrNo[MAX_LEN_TRAINNO];		/** 1~5, 변경하고자 하는 원본의 열차번호 */
	uint8 aucTargetTrNo[MAX_LEN_TRAINNO];		/** 6~10, 변경하고자 하는 목적의 열차번호 */
} TS_MSG_TRNO_ALT_DATA;

/* ------------------------------------------------------------------------- */
/* 열차번호 교환요구 메시지의 데이터 필드(Field) 구조체 정의                 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_MSG_TRNO_XCH_DATA
* @brief 열차번호 교환요구 메시지의 데이터 필드(Field) 구조체
*/
typedef struct {
	uint8 ucCtrlCode;			/** 0, 제어코드, 0x53 */
	uint8 aucTrainNumber1[MAX_LEN_TRAINNO];	/** 1~5, 교환하고자 하는 열차번호 #1 */
	uint8 aucTrainNumber2[MAX_LEN_TRAINNO];	/** 6~10, 교환하고자 하는 열차번호 #2 */
} TS_MSG_TRNO_XCH_DATA;

/* ------------------------------------------------------------------------- */
/* 열차번호 삭제요구 메시지의 데이터 필드(Field) 구조체 정의                 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_MSG_TRNO_DEL_DATA
* @brief 열차번호 삭제요구 메시지의 데이터 필드(Field) 구조체
*/
typedef struct {
	uint8 ucCtrlCode;			/** 0, 제어코드, 0x52 */
	uint8 aucTrainNumber[MAX_LEN_TRAINNO];		/** 1~5, 삭제하고자 하는 열차번호 */
} TS_MSG_TRNO_DEL_DATA;

/* ------------------------------------------------------------------------- */
/* 열차번호 제어 데이터 필드(Field) 구조체 정의                              */
/* ------------------------------------------------------------------------- */
/**
* @struct TU_MSG_TRNO_CTRL_DATA
* @brief 열차번호 제어 데이터 필드(Field)의 공용 구조체
*/
typedef union { /* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;외부 I/F Data packet 1000 byte이내에서 이벤트 형식으로 사용함] */
	uint8 aucTrainNumberCtrl[12];			/** 열차번호 제어 데이터 필드 공용 버퍼 */
	TS_MSG_TRNO_SET_DATA tTNSetData;		/** 열차번호 생성요구 메시지의 데이터 필드(Field) */
	TS_MSG_TRNO_ALT_DATA tTNAltData;		/** 열차번호 변경요구 메시지의 데이터 필드(Field) */
	TS_MSG_TRNO_XCH_DATA tTNXchData;		/** 열차번호 교환요구 메시지의 데이터 필드(Field) */
	TS_MSG_TRNO_DEL_DATA tTNDelData;		/** 열차번호 삭제요구 메시지의 데이터 필드(Field) */
} TU_MSG_TRNO_CTRL_DATA;

/* ------------------------------------------------------------------------- */
/* 사용자등록 표찰 메시지의 데이터 필드(Field) 구조체 정의                 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_MSG_USER_TEXT_DATA
* @brief 사용자등록 표찰 설정 메시지의 데이터 필드(Field) 구조체
*/
typedef struct {
	uint8 ucCtrlCode;						/** 0, 제어코드, 0x10:설정, 0x20:삭제 */
	uint16 usID;								/** 1~2 표찰 순서 ID */
	uint16 usPosX;							/** 3~4, 좌표 x */
	uint16 usPosY;							/** 5~6, 좌표 x */
	uint8 aucUserText[MAX_LEN_USERTEXT];		/** 7~26, 사용자가 설정한 표찰내용 */
} TS_MSG_USER_TEXT_DATA;

/* ------------------------------------------------------------------------- */
/* MMI 송신 제어 데이터 필드(Field) 구조체 정의                              */
/* ------------------------------------------------------------------------- */
/**
* @struct TU_MSG_MMI_FRM_DATA
* @brief 열차번호 제어 데이터 필드(Field)의 공용 구조체
*/

typedef union {/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;외부 I/F Data packet 1000 byte이내에서 이벤트 형식으로 사용함] */
	uint8 aucMsgFrameDataByMMI[80];		/** MMI 송신 메시지의 데이터 필드 공용 버퍼 */
	struct {
		uint8 ucFunc;					/** function code */
		union {/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;외부 I/F Data packet 1000 byte이내에서 이벤트 형식으로 사용함] */
			TS_ELM_CTRL_REQ_DATA	tElmCtrlReqData;	/** Element 데이터 제어 요구 메시지의 데이터 필드(field) */
			TS_EM_ELM_CTRL_REQ_DATA tEmElmCtrlReqData;	/** 비상 제어 요구 메시지의 데이터 필드(field) */
			TS_MSG_MASTER_CLOCK_DATA	tMasterClock;	/** 시간설정 데이터 메시지의 데이터 필드(field) */
			TS_MSG_TRNO_SET_DATA	tTNSetData;			/** 열차번호 생성요구 메시지의 데이터 필드(Field) */
			TS_MSG_TRNO_ALT_DATA	tTNAltData;			/** 열차번호 변경요구 메시지의 데이터 필드(Field) */
			TS_MSG_TRNO_XCH_DATA	tTNXchData;			/** 열차번호 교환요구 메시지의 데이터 필드(Field) */
			TS_MSG_TRNO_DEL_DATA	tTNDelData;			/** 열차번호 삭제요구 메시지의 데이터 필드(Field) */
			TU_MSG_TRNO_CTRL_DATA	tTrnoCtrlData;		/** 열차번호 구조체의 Accessing 을 위한 더미 */
			TS_MSG_USER_TEXT_DATA	tUserTextData;		/** 사용자등록표찰 메시지의 데이터 필드(Field) */
		} MSG;
	} TS;
} TU_MSG_MMI_FRM_DATA;


/* CTLMSCR 용 */
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* 통신 메세지 & 제어 메세지 & Functions Call Message */
#define WS_OPMSG_CMDCLEAR		0		/* CMD CLEAR */
#define WS_OPMSG_START			1		/* 시스템 기동(CMD, ~CMD) */
#define WS_OPMSG_RESET 			2		/* 시스템 초기화(CMD, ~CMD) */
#define WS_OPMSG_SETTIMER		3		/* UNIT 시계 조정(초,분,시,일,월,년)(CMD, Clock[0], Clock[1], Clock[2], Clock[3]) */
#define WS_OPMSG_SETTRAINNAME	4		/* 열차 번호 지정(CMD,TrNo[0], TrNo[1], TrNo[2], TrNo[3], TrNo[4], 0x00) */
#define WS_OPMSG_SIGNALDEST		5		/* 신호 (폐색 포함)취급(CMD, SignaIID(byte), button ID(byte)) */
#define WS_OPMSG_SIGNALCANCEL	6		/* 신호 (폐색 포함)취소(CMD, SignalID) */
#define WS_OPMSG_TTB			7		/* TTB 취급 (CMD, ID) */
#define WS_OPMSG_TTBCANCEL		8		/* TTB 취소 (CMD, ID) */
#define WS_OPMSG_SWTOGGLE		9		/* 선로전환기 토글(toggle) (CMD, ID) */
#define WS_OPMSG_BUTTON			10		/* 버튼 메세지(CMD, ID, ON/OFF), CTC, LOCAL, EXTLOCAL, S, P ... */
#define WS_OPMSG_SWNORMAL		11		/* 선로전환기 정위 제어 (CMD, PointID) */
#define WS_OPMSG_SWREVERSE		12		/* 선로전환기 반위 제어 (CMD, PointID) */
#define WS_OPMSG_USERFREETRACK	13		/* 궤도 사용금지 해제(CMD, ID, LOCKING MODE) */
#define WS_OPMSG_USERLOCKTRACK	14		/* 궤도 사용금지 설정(CMD, ID, LOCKING MODE) */
#define WS_OPMSG_ROUTEEMRELEASE	15		/* 구분진로비상해정(CMD, ID)  */
#define WS_OPMSG_SETLCCLOCKS	16		/* LCC 사용금지 해제(CMD, LOCKING MODE) */
#define WS_OPMSG_FREELCCLOCK	17		/* LCC 사용금지 설정(CMD, LOCKING MODE) */
#define WS_OPMSG_EMSIGNALDEST	18		/* 비상 신호 (폐색 포함)취급(CMD, SignaIID(byte), button ID(byte)) */
#define WS_OPMSG_LCCCTRLLOCK	19		/* LCC 제어금지 설정 취급(CMD, user ID) */
#define WS_OPMSG_LCCCTRLFREE	20		/* LCC 제어금지 해제 취급(CMD, user ID) */
#define WS_OPMSG_USERCHANGE		21		/* 현재 사용중인 운용자 이름 변경(CMD, user string) */
#define WS_OPMSG_USERADDITION	22		/* 운용자 이름 등록(CMD, user string, password) */
#define WS_OPMSG_USERDELETE		23		/* 운용자 이름 삭제(CMD, user string, password) */
#define WS_OPMSG_GETBINFILE		29		/* BIN(*.S) FILE LOAD(CMD, block ID) */
#define WS_OPMSG_EMLOCAL		30		/* 비상LOCAL 전환 */
#define WS_OPMSG_CTCREQ			31		/* CTC 전환 요구  */
#define WS_OPMSG_CTCREQCANCEL	32		/* CTC 전환 요구 취소  */
#define WS_OPMSG_RCREQ			33 		/* RC 전환 요구 */
#define WS_OPMSG_RCREQCANCEL	34 		/* RC 전환 요구 취소 */
#define WS_OPMSG_GETADJTRACKS	35		/* 인접궤도 ID 정보 요구(CMD, track ID), 반환(high 16 bit:left track ID, low 16 bit: right track ID) */
#define	WS_OPMSG_SHUNTLAMPOFF	36		/* 입환소등 버튼취급(0:취급가능, 1:취급불가사유 표출) */
#define WS_OPMSG_GETUSERLABEL	37		/* CTLMscr -> MMI로 사용자등록 데이터(OPCODE, 표찰생성번호, 좌표, 문자열 포인터) 전송. */
#define WS_OPMSG_CLRUSERLABEL	38		/* MMI -> CTLMscr 로 사용자등록 데이터(표찰생성번호) 삭제. */
#define WS_OPMSG_GETRPPBYSG		39		/* signal 에 대한 rpp 상태를 반환(return: 0:주신호진로(A1) or 입환표지(X) or 입환 표지와 도착점이 다른 입환출발신호기(A2@)의 진로, 1:입환표지를 가지고 있는 입환신호기 진로. */

/* 사용자 기능번호 추가 */
/* Function Call Message */
#define WS_OPMSG_LOADFILE		41		/* SFM Load */
#define WS_OPMSG_ASSIGNSCRINFO	42		/* Assign Info(Down.bin) */
#define WS_OPMSG_UPDATESCREEN	43		/* Update VMem buffer */
#define WS_OPMSG_SETMSCRSIZE	44		/* Set MSCR SIZE (resizing) */
#define WS_OPMSG_SETMSCROPTION	45		/* 표시 및 제어 옵션 설정 */
#define WS_OPMSG_SETOPTERATOR	46		/* 현재 조작자 설정 */
/* Fail Functions */
#define WS_OPMSG_COMSTATUS		50		/* 통신 상태 지정(0:/normal, other/fail) */
#define WS_OPMSG_OPERATESTATE	51		/* 제어 LOCKING 옵션 설정.  */
#define WS_OPMSG_SETDISPTIME	60		/* 기록 시간 정보의 표시 유무(좌상의 기존 시간 밑에 표시)  */
#define WS_OPMSG_CALLCHECKROUTE	90		/* Call Check route in EipEmp class */
#define WS_OPMSG_GETSCRINFO		98		/* Get ScrInfo class Table ptr */
#define WS_OPMSG_GETEMUPTR		99		/* Get EipEmp class ptr */

/*#define WS_OPMSG_GETCOUNTTRACK	100	 */	/* Get Track count in EipEmp class */
/*#define WS_OPMSG_GETCOUNTSIGNAL	101	 */	/* Get Signal count in EipEmp class */
/*#define WS_OPMSG_GETCOUNTSWITCH	102	 */	/* Get Switch count in EipEmp class */
/*#define WS_OPMSG_GETCOUNTBUTTON	103	 */	/* Get Button count in EipEmp class */
/*#define WS_OPMSG_GETCOUNTLAMP	104	 */	/* Get Lamp count in EipEmp class */

#define WS_OPMSG_GETTRACKLOCKID	105		/* 궤도 사용금지에 대한 확인 및 수용시 궤도 ID 반환. */

#define WS_OPMSG_OBJECTMODIFY	254		/* 오브젝트 값 변경 */
#define WS_OPMSG_TRKSEL			255		/* 궤도 선택 */
/*/////////////////////////////////////////////////////////////////////////// */

/*/////////////////////////////////////////////////////////////////////////// */
/* 사용금지 데이터 값 */
#define TRACKLOCK_FREE			0x00
/* #define TRACKLOCK_PWRDOWN		0x40 */
/* #define TRACKLOCK_MOTORCAR		0x80 */
/* #define TRACKLOCK_USING			0xc0 */

/* ///////////////////////////////////////////////////////////////////////////// */

/* ------------------------------------------------------------------------- */
/* tGPT(Target General Task) - OPC,RC,CTC 간 제어(열번,시각) 코드 정의       */
/*   ; OPC,RC & CTC 의 열차번호, 시각변경 패킷 구조가 상이하여,              */
/*     각 통신 Task에서 FunctionCode가                                       */
/*       - COMM_MMI_FUNC_TRAINNUMBER or COMM_CTC_FUNC_TRAINNUMBER            */
/*       - COMM_MMI_FUNC_MASTERCLOCK or COMM_CTC_FUNC_MASTERCLOCK            */
/*     일 경우 다음 구조로 GPT MSGQ_RX_GEN Q로 전송                          */
/*     전송 시 Cmd Code[0] 다음 data는 각 통신Task에서 수신한                */
/*                                                                           */
/* tGPT 수신 코드                                                            */
/*	[0] : Cmd Code : (예:CTC 명령 & 열차번호 명령 => 0x11)                   */
/*  [0] byte 이후 명령(Data) 전송 시 각 통신Task에서 수신한 다음의 형식으로  */
/*  된 data 들임.                                                            */
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
