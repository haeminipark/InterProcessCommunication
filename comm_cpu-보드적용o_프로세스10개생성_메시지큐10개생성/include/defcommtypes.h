/* =========================================================================================
2018.04.16
@1.4f2- [LOCAL최대메세지수정] 메세지 데이터 최대 수 조정에 의한 베이스스캔 최대 블럭 수 수정
============================================================================================ */
#ifndef _DEFCOMMTYPES_H_
#define _DEFCOMMTYPES_H_
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
* @file     defcommtypes.h : header file
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
* @brief    Communication을 위한 통신용 Const value 및 데이터 구조체를 정의한다.
* @see      TS_COMM_PORT_STATE_TABLE, TS_COMM_TASK_STATE_TABLE 구조체들
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

#include	"defopcode.h"
#include	"defeventmsg.h"
#include	"crc_app.h"
#pragma pack(1)

/* ///////////////////////////////////////////////////////////////////////// */
/* 사전정의코드/Constant/전역변수/참조문자열을 정의(또는 선언)               */
/* ///////////////////////////////////////////////////////////////////////// */
 
/* ------------------------------------------------------------------------- */
/* 통신용 장치별 ID 정의                                                     */
/* ------------------------------------------------------------------------- */
/* Only ZEST EIS */
#define  DEF_ID_IOS_01_A			0x21	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 01, 연동논리부 I/O 랙 1계 #01 */
#define  DEF_ID_IOS_01_B			0x41	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 01, 연동논리부 I/O 랙 2계 #01 */
#define  DEF_ID_IOS_02_A			0x22	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 02, 연동논리부 I/O 랙 1계 #01 */
#define  DEF_ID_IOS_02_B			0x42	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 02, 연동논리부 I/O 랙 2계 #01 */
#define  DEF_ID_IOS_03_A			0x23	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 03, 연동논리부 I/O 랙 1계 #01 */
#define  DEF_ID_IOS_03_B			0x43	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 03, 연동논리부 I/O 랙 2계 #01 */
#define  DEF_ID_IOS_04_A			0x24	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 04, 연동논리부 I/O 랙 1계 #01 */
#define  DEF_ID_IOS_04_B			0x44	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 04, 연동논리부 I/O 랙 2계 #01 */
#define  DEF_ID_IOS_05_A			0x25	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 05, 연동논리부 I/O 랙 1계 #01 */
#define  DEF_ID_IOS_05_B			0x45	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 05, 연동논리부 I/O 랙 2계 #01 */
#define  DEF_ID_IOS_06_A			0x26	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 06, 연동논리부 I/O 랙 1계 #01 */
#define  DEF_ID_IOS_06_B			0x46	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 06, 연동논리부 I/O 랙 2계 #01 */
#define  DEF_ID_IOS_07_A			0x27	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 07, 연동논리부 I/O 랙 1계 #01 */
#define  DEF_ID_IOS_07_B			0x47	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 07, 연동논리부 I/O 랙 2계 #01 */
#define  DEF_ID_IOS_08_A			0x28	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 08, 연동논리부 I/O 랙 1계 #01 */
#define  DEF_ID_IOS_08_B			0x48	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 08, 연동논리부 I/O 랙 2계 #01 */
#define  DEF_ID_IOS_09_A			0x29	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 09, 연동논리부 I/O 랙 1계 #01 */
#define  DEF_ID_IOS_09_B			0x49	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 09, 연동논리부 I/O 랙 2계 #01 */
#define  DEF_ID_IOS_10_A			0x2A	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 10, 연동논리부 I/O 랙 1계 #01 */
#define  DEF_ID_IOS_10_B			0x4A	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 10, 연동논리부 I/O 랙 2계 #01 */
#define  DEF_ID_IOS_11_A			0x2B	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 11, 연동논리부 I/O 랙 1계 #01 */
#define  DEF_ID_IOS_11_B			0x4B	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 11, 연동논리부 I/O 랙 2계 #01 */
#define  DEF_ID_IOS_12_A			0x2C	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 12, 연동논리부 I/O 랙 1계 #01 */
#define  DEF_ID_IOS_12_B			0x4C	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 12, 연동논리부 I/O 랙 2계 #01 */
#define  DEF_ID_IOS_13_A			0x2D	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 13, 연동논리부 I/O 랙 1계 #01 */
#define  DEF_ID_IOS_13_B			0x4D	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 13, 연동논리부 I/O 랙 2계 #01 */
#define  DEF_ID_IOS_14_A			0x2E	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 14, 연동논리부 I/O 랙 1계 #01 */
#define  DEF_ID_IOS_14_B			0x4E	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 14, 연동논리부 I/O 랙 2계 #01 */
#define  DEF_ID_IOS_15_A			0x2F	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 15, 연동논리부 I/O 랙 1계 #01 */
#define  DEF_ID_IOS_15_B			0x4F	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 15, 연동논리부 I/O 랙 2계 #01 */
#define  DEF_ID_IOS_16_A			0x30	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 16, 연동논리부 I/O 랙 1계 #01 */
#define  DEF_ID_IOS_16_B			0x50	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 16, 연동논리부 I/O 랙 2계 #01 */
#define  DEF_ID_IOS_17_A			0x31	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 17, 연동논리부 I/O 랙 1계 #01 */
#define  DEF_ID_IOS_17_B			0x51	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 17, 연동논리부 I/O 랙 2계 #01 */
#define  DEF_ID_IOS_18_A			0x32	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 18, 연동논리부 I/O 랙 1계 #01 */
#define  DEF_ID_IOS_18_B			0x52	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 18, 연동논리부 I/O 랙 2계 #01 */
#define  DEF_ID_IOS_19_A			0x33	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 19, 연동논리부 I/O 랙 1계 #01 */
#define  DEF_ID_IOS_19_B			0x53	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 19, 연동논리부 I/O 랙 2계 #01 */
#define  DEF_ID_IOS_20_A			0x34	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 20, 연동논리부 I/O 랙 1계 #01 */
#define  DEF_ID_IOS_20_B			0x54	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 20, 연동논리부 I/O 랙 2계 #01 */
#define  DEF_ID_IOS_21_A			0x35	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 21, 연동논리부 I/O 랙 1계 #01 */
#define  DEF_ID_IOS_21_B			0x55	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 21, 연동논리부 I/O 랙 2계 #01 */
#define  DEF_ID_IOS_22_A			0x36	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 22, 연동논리부 I/O 랙 1계 #01 */
#define  DEF_ID_IOS_22_B			0x56	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 22, 연동논리부 I/O 랙 2계 #01 */
#define  DEF_ID_IOS_23_A			0x37	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 23, 연동논리부 I/O 랙 1계 #01 */
#define  DEF_ID_IOS_23_B			0x57	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 23, 연동논리부 I/O 랙 2계 #01 */
#define  DEF_ID_IOS_24_A			0x38	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 24, 연동논리부 I/O 랙 1계 #01 */
#define  DEF_ID_IOS_24_B			0x58	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 24, 연동논리부 I/O 랙 2계 #01 */
#define  DEF_ID_IOS_25_A			0x39	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 25, 연동논리부 I/O 랙 1계 #01 */
#define  DEF_ID_IOS_25_B			0x59	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 25, 연동논리부 I/O 랙 2계 #01 */
/* Common EIS */
#define  DEF_ID_ILS					0x1AU	/** (BIT5~6)GROUPID 0, (BIT0~4)UNITID 26, 연동논리부 */
#define  DEF_ID_ILS_1A				0x3AU	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 26, 연동논리부 1계_A */
#define  DEF_ID_ILS_1B				0xBAU	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 26, 연동논리부 1계_B */
#define  DEF_ID_ILS_2A				0x5AU	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 26, 연동논리부 2계_A */
#define  DEF_ID_ILS_2B				0xDAU	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 26, 연동논리부 2계_B */
#define  DEF_ID_OPC					0x1BU	/** (BIT5~6)GROUPID 0, (BIT0~4)UNITID 27, OPC */
#define  DEF_ID_OPC_A				0x3BU	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 27, OPC 1계 */
#define  DEF_ID_OPC_B				0x5BU	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 27, OPC 2계 */
#define  DEF_ID_MTC					0x1CU	/** (BIT5~6)GROUPID 0, (BIT0~4)UNITID 28, 유지보수부 MTC */
#define  DEF_ID_LDTS				0x00U	/** (BIT5~6)GROUPID 0, (BIT0~4)UNITID  0, LDTS */
#define  DEF_ID_LDTS_A				0x20U	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID  0, LDTS 1계 */
#define  DEF_ID_LDTS_B				0x40U	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID  0, LDTS 2계 */
#define  DEF_ID_RC					0x1DU	/** (BIT5~6)GROUPID 0, (BIT0~4)UNITID 29, 원격제어부 */
#define  DEF_ID_RC_A				0x3DU	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 29, 원격제어부 1계 */
#define  DEF_ID_RC_B				0x5DU	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 29, 원격제어부 2계 */
#define  DEF_ID_EXM					0x1FU	/** (BIT5~6)GROUPID 0, (BIT0~4)UNITID 31, 체류표시반 TPC */
#define  DEF_ID_IF					0x1FU	/** (BIT5~6)GROUPID 0, (BIT0~4)UNITID 31, 계간 INTERFACE 통신카드 */
#define  DEF_ID_IF_A				0x3F	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 31, 1계 INTERFACE 통신카드 */
#define  DEF_ID_IF_B				0x5F	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 31, 2계 INTERFACE 통신카드 */
#define  DEF_ID_SIMC				0x7F	/** (BIT5~6)GROUPID 3, (BIT0~4)UNITID 31, 시뮬레이터장치 SIMC */
/* ------------------------------------------------------------------------- */
/*#define  DEF_ID_PORTCOM1			0x00*/	/** (Bit7) UINT 의 통신 포트 설정코드, 0:COM1, 1:COM2 */
#define  DEF_ID_PORTCOM2			0x80	/** (Bit7) UINT 의 통신 포트 설정코드, 0:COM1, 1:COM2 */
/* ------------------------------------------------------------------------- */
#define  DEF_UNIT_IDMASK			0x1F	/** (Bit0~Bit4)통신용 장치별 ID 코드에 대한 Mask bit 값 */
#define  DEF_ID_GROUPMASK			0x60	/** (Bit5~Bit6)통신용 장치별 GROUP 코드에 대한 Mask bit 값 */
#define  DEF_PORT_IDMASK			0x9F	/** (Bit0~Bit4)통신포트를 포함한 통신용 장치별 ID 코드에 대한 Mask bit 값 */

/* ------------------------------------------------------------------------- */
/* MMI 통신 프레임 코드 정의                                                 */
/* ------------------------------------------------------------------------- */
#define COMM_MMI_STX					0x02	/** STX of the MMI frame */
#define COMM_MMI_ETX					0x03	/** ETX of the MMI frame */
#define COMM_MMI_DLE					0x80	/** DLE of the MMI frame */
#define COMM_MMI_DLE_STX				0x82	/** DLE가 처리된 STX 코드 */
#define COMM_MMI_DLE_ETX				0x83	/** DLE가 처리된 ETX 코드 */

/* ------------------------------------------------------------------------- */
/* 통신 데이터 버퍼 사이즈 정의                                              */
/* ------------------------------------------------------------------------- */
#define LIMIT_CNT_MMI_STD_COMMFRAME		  90U	/** 송/수신 메시지를 저장하기 위한 버퍼의 최대 크기 */
#define LIMIT_CNT_MMI_STD_COMMWRITE		 170U	/** 송/수신 메시지를 저장하기 위한 버퍼의 최대 크기 */
#define LIMIT_CNT_MMI_EXT_COMMFRAME		1000U	/** 송/수신 메시지를 저장하기 위한 버퍼의 최대 크기 */
#define LIMIT_CNT_MMI_EXT_COMMWRITE		1980U	/** 스터핑문자(DLE 문자)가 삽입 처리된 송신데이터를 저장하는 송신버퍼의 최대 크기 */

/* ------------------------------------------------------------------------- */
/* MMI 통신 프레임 기능코드 정의                                             */
/* ------------------------------------------------------------------------- */
#define COMM_MMI_FUNC_INITIALPOLLING	0x10U	/** 초기폴링(Initial Polling) 메시지 */
#define COMM_MMI_FUNC_INITIALRESPONSE	0x11U	/** 초기응답(Initial Response) 메시지 */
#define COMM_MMI_FUNC_POLLING			0x20U	/** 폴링(Polling) 메시지 */
#define COMM_MMI_FUNC_POLLINGRESPONSE	0x21U	/** 폴링응답(Polling Response) 메시지 */
#define COMM_MMI_FUNC_CONTROL			0x30U	/** 제어(Control) 메시지 */
#define COMM_MMI_FUNC_ACK				0x31U	/** Acknowledge 메시지 */
#define COMM_MMI_FUNC_EMCONTROL			0x32U	/** 비상 제어(Control) 메시지 */
#define COMM_MMI_FUNC_MASTERCLOCK		0x40U	/** Master Clock 설정 메시지 */
#define COMM_MMI_FUNC_NACK				0x41U	/** Negative Acknowledge 메시지 */
#define COMM_MMI_FUNC_USERLABEL			0x42U	/** 사용자 등록 표찰 메시지 설정/삭제 */
#define COMM_MMI_FUNC_TRAINNUMBER		0x50U	/** 열차번호(Train Number) 제어 메시지 */
#define COMM_MMI_FUNC_BASESCANREQ		0x60U	/** Basescan 요구 메시지 */
#define COMM_MMI_FUNC_ROM_UPLOAD		0xA0U	/** ROM data의 upload 요구 메시지 */
#define COMM_MMI_FUNC_ROM_UPLOADING		0xA1U	/** ROM data의 uploading DB 메시지 */
#define COMM_MMI_FUNC_ROM_DOWNLOAD		0xB0U	/** ROM data의 download 요구 메시지 */
#define COMM_MMI_FUNC_ROM_DOWNLOADING	0xB1U	/** ROM data의 downloading DB 메시지 */
#define COMM_MMI_FUNC_LINK				0xF0U	/** LINK 메시지 */

/* ------------------------------------------------------------------------- */
/* MMI 통신 프레임 기능코드 정의                                             */
/* ------------------------------------------------------------------------- */
#define COMM_MMI_DATA_TYPE_STATE		0x10	/** 송신용 큐에 삽입되는 Element 상태변화정보 데이터블럭의 타입 정의 값 */
#define COMM_MMI_DATA_TYPE_EVENT		0x20	/** 송신용 큐에 삽입되는 이벤트 정보 데이터블럭의 타입 정의 값 */
#define COMM_MMI_DATA_TYPE_BASESCAN		0x30	/** 송신용 큐에 삽입되는 BASESCAN 정보 데이터블럭의 타입 정의 값 */
#define COMM_MMI_DATA_TYPE_NEWBASESCAN	0x31	/** 송신용 큐에 삽입되는 REAL TYPE BASESCAN 정보 데이터블럭의 타입 정의 값 */
#define COMM_MMI_DATA_TYPE_TRNOSTATE	0x40	/** 송신용 큐에 삽입되는 열차번호 상태변화 정보 데이터블럭의 타입 정의 값 */
#define COMM_MMI_DATA_TYPE_TRNOBASESCAN	0x50	/** 송신용 큐에 삽입되는 열차번호 BASESCAN 정보 데이터블럭의 타입 정의 값 */
#define COMM_MMI_DATA_TYPE_INITRESPONSE	0xF0	/** 송신용 큐에 삽입되는 초기응답정보 데이터블럭의 타입 정의 값 */


/* ------------------------------------------------------------------------- */
/* 연동 역 기본정보 Data 정의 (EisDefine.h 에 정의되어 있음)                 */
/* ------------------------------------------------------------------------- */
#ifndef SIZE_ILDB_VERSION
#define SIZE_ILDB_VERSION			18U		/** ILDB Version data size       */
#endif //


/* ///////////////////////////////////////////////////////////////////////// */
/* 공용 구조체 정의                                                          */
/* ///////////////////////////////////////////////////////////////////////// */

/* ------------------------------------------------------------------------- */
/* MMI 통신 프레임의 해더(Header) 구조체 정의                                */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_FRAME_HEADER
* @brief 통신 프레임의 해더 데이터를 정의하는 구조체
*/
typedef struct {
	uint8	ucSenderID;			/** 1, 메시지 프레임의 발신자 ID */
	uint8	ucReceiverID;		/** 2, 메시지 프레임의 수신자 ID */
	uint8	ucSequenceNo;		/** 3, 메시지 프레임의 순서번호, 0x04~ox7F, 단, Initial Polling 메시지는 0x00  */
	uint8	ucFunctionCode;		/** 4, 메시지 프레임의 기능코드 */
	uint16	usLength;			/** 5~6, 메시지 프레임의 데이터 사이즈, 발신자 ID 부터 CRC 필드(Field) 이전의 데이터 필드(Field)까지의 Byte Size */
} TS_COMM_MMI_FRAME_HEADER;

/* ------------------------------------------------------------------------- */
/* 데이터 필드가 없는 기능번호만을 가지는 MMI 메시지 기본 프레임의 구조체 정의 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_SHORT_MSG_FRAME
* @brief 데이터 필드가 없는 기능번호만을 가지는 메시지 기본 프레임의 구조체
*/
typedef struct {
	uint8 ucSTX;								/** 0, 메시지 프레임의 시작 문자, STX=0x02 고정값 */
	TS_COMM_MMI_FRAME_HEADER	tHeader;	/** 1~6, 메시지 프레임의 해더 데이터 */
	TS_CRC32_DATA				tCRC32;		/** 7~10, 메시지 프레임의 CRC32 */
	uint8 ucETX;								/** 11, 메시지 프레임의 종료 문자, ETX=0x03 고정값 */
} TS_COMM_MMI_SHORT_MSG_FRAME;

typedef struct {
	uint8 	ucSTX;				/** 0, 메시지 프레임의 시작 문자, STX=0x02 고정값 */
	uint8	ucSenderID;			/** 1, 메시지 프레임의 발신자 ID */
	uint8	ucReceiverID;		/** 2, 메시지 프레임의 수신자 ID */
	uint8	ucSequenceNo;		/** 3, 메시지 프레임의 순서번호, 0x04~ox7F, 단, Initial Polling 메시지는 0x00  */
	uint8	ucFunctionCode;		/** 4, 메시지 프레임의 기능코드 */
	uint16	usLength;			/** 5~6, 메시지 프레임의 데이터 사이즈, 발신자 ID 부터 CRC 필드(Field) 이전의 데이터 필드(Field)까지의 Byte Size */		
	uint8	ucCRC32[4];		/** data low => uchCRC32[0], data high => uchCRC32[3] */	
	uint8 	ucETX;				/** 11, 메시지 프레임의 종료 문자, ETX=0x03 고정값 */
} COMM_SHORT_MSG_FRAME;

/* ------------------------------------------------------------------------- */
/* MMI 에서 ILS 로 송신하는 메시지 프레임 구조체 정의                        */
/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */
/* Element 제어 메시지 프레임의 구조체 정의                                  */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_ELM_CTRL_MSG_FRAME
* @brief Element 제어 메시지 프레임의 구조체
*/
typedef struct {
	uint8 ucSTX;									/** 0, 메시지 프레임의 시작 문자, STX=0x02 고정값 */
	TS_COMM_MMI_FRAME_HEADER	tHeader;			/** 1~6, 메시지 프레임의 해더 데이터 */
	TS_ELM_CTRL_REQ_DATA		tCtrlData;			/** 7~10, 메시지 프레임의 Element 제어 정보를 포함하는 데이터 필드 */
	TS_CRC32_DATA				tCRC32;				/** 11~14, 메시지 프레임의 CRC32 */
	uint8 ucETX;									/** 15, 메시지 프레임의 종료 문자, ETX=0x03 고정값 */
} TS_COMM_MMI_ELM_CTRL_MSG_FRAME;

/* ------------------------------------------------------------------------- */
/* 비상 제어 메시지 프레임의 구조체 정의                                      */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_MMI_EM_ELM_CTRL_MSG_FRAME
* @brief Element 제어 메시지 프레임의 구조체
*/
typedef struct {
	uint8 ucSTX;									/** 0, 메시지 프레임의 시작 문자, STX=0x02 고정값 */
	TS_COMM_MMI_FRAME_HEADER	tHeader;		/** 1~6, 메시지 프레임의 해더 데이터 */
	TS_EM_ELM_CTRL_REQ_DATA		tEmCtrlData;	/** 7~80, 메시지 프레임의 Element 제어 정보를 포함하는 데이터 필드 */
	TS_CRC32_DATA				tCRC32;			/** 81~84, 메시지 프레임의 CRC32 */
	uint8 ucETX;									/** 85, 메시지 프레임의 종료 문자, ETX=0x03 고정값 */
} TS_COMM_MMI_EM_ELM_CTRL_MSG_FRAME;

/* ------------------------------------------------------------------------- */
/* MMI의 사용자등록 표찰 제어 메시지 프레임의 구조체 정의                    */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_MMI_USERLABEL_MSG_FRAME
* @brief 사용자등록 표찰 제어 메시지 프레임의 구조체
*/
typedef struct {
	uint8 ucSTX;									/** 0, 메시지 프레임의 시작 문자, STX=0x02 고정값 */
	TS_COMM_MMI_FRAME_HEADER	tHeader;		/** 1~6, 메시지 프레임의 해더 데이터 */
	TS_MSG_USER_TEXT_DATA		tUserTextData;	/** 7~33, LABEL 문자 내용 20자 */
	TS_CRC32_DATA				tCRC32;			/** 34~37, 메시지 프레임의 CRC32 */
	uint8 ucETX;									/** 38, 메시지 프레임의 종료 문자, ETX=0x03 고정값 */
} TS_COMM_MMI_USERLABEL_MSG_FRAME;

/* ------------------------------------------------------------------------- */
/* MMI의 마스터클럭 설정 메시지 프레임의 구조체 정의                         */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_MASTERE_CLOCK_MSG_FRAME
* @brief 마스터클럭 설정 메시지 프레임의 구조체
*/
typedef struct {
	uint8 ucSTX;								/** 0, 메시지 프레임의 시작 문자, STX=0x02 고정값 */
	TS_COMM_MMI_FRAME_HEADER	tHeader;	/** 1~6, 메시지 프레임의 해더 데이터 */
	TS_MSG_MASTER_CLOCK_DATA	tClcokData;	/** 7~12, 메시지 프레임의 마스터클럭 정보를 포함하는 데이터 필드 */
	TS_CRC32_DATA				tCRC32;		/** 13~16, 메시지 프레임의 CRC32 */
	uint8 ucETX;								/** 17, 메시지 프레임의 종료 문자, ETX=0x03 고정값 */
} TS_COMM_MMI_MASTERE_CLOCK_MSG_FRAME;

/* ------------------------------------------------------------------------- */
/* MMI의 열차번호 제어 메시지 프레임의 구조체 정의                           */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_TRNO_SET_MSG_FRAME 
* @brief 열차번호 설정 메시지 프레임의 구조체
*/
typedef struct {
	uint8  ucSTX;							/** 0, 메시지 프레임의 시작 문자, STX=0x02 고정값 */
	TS_COMM_MMI_FRAME_HEADER	tHeader;	/** 1~6, 메시지 프레임의 해더 데이터 */
	TS_MSG_TRNO_SET_DATA		tTNSetData;	/** 7~13, 메시지 프레임의 열차번호 설정 데이터를 포함하는 데이터 필드 */
	TS_CRC32_DATA				tCRC32;		/** 14~17, 메시지 프레임의 CRC32 */
	uint8  ucETX;							/** 18, 메시지 프레임의 종료 문자, ETX=0x03 고정값 */
} TS_COMM_MMI_TRNO_SET_MSG_FRAME;

/**
* @struct TS_COMM_TRNO_ALT_MSG_FRAME
* @brief 열차번호 변경 메시지 프레임의 구조체
*/
typedef struct {
	uint8  ucSTX;							/** 0, 메시지 프레임의 시작 문자, STX=0x02 고정값 */
	TS_COMM_MMI_FRAME_HEADER	tHeader;	/** 1~6, 메시지 프레임의 해더 데이터 */
	TS_MSG_TRNO_ALT_DATA		tTNAltData;	/** 7~17, 메시지 프레임의 열차번호 변경 데이터를 포함하는 데이터 필드 */
	TS_CRC32_DATA				tCRC32;		/** 18~21, 메시지 프레임의 CRC32 */
	uint8  ucETX;							/** 22, 메시지 프레임의 종료 문자, ETX=0x03 고정값 */
} TS_COMM_MMI_TRNO_ALT_MSG_FRAME;

/**
* @struct TS_COMM_TRNO_DEL_MSG_FRAME
* @brief 열차번호 삭제 메시지 프레임의 구조체
*/
typedef struct {
	uint8  ucSTX;							/** 0, 메시지 프레임의 시작 문자, STX=0x02 고정값 */
	TS_COMM_MMI_FRAME_HEADER	tHeader;	/** 1~6, 메시지 프레임의 해더 데이터 */
	TS_MSG_TRNO_DEL_DATA		tTNDelData;	/** 7~12, 메시지 프레임의 열차번호 삭제 데이터를 포함하는 데이터 필드 */
	TS_CRC32_DATA				tCRC32;		/** 13~16, 메시지 프레임의 CRC32 */
	uint8 ucETX;								/** 17, 메시지 프레임의 종료 문자, ETX=0x03 고정값 */
} TS_COMM_MMI_TRNO_DEL_MSG_FRAME;

/**
* @struct TS_COMM_TRNO_XCH_MSG_FRAME
* @brief 열차번호 교환 메시지 프레임의 구조체
*/
typedef struct {
	uint8  ucSTX;							/** 0, 메시지 프레임의 시작 문자, STX=0x02 고정값 */
	TS_COMM_MMI_FRAME_HEADER	tHeader;	/** 1~6, 메시지 프레임의 해더 데이터 */
	TS_MSG_TRNO_XCH_DATA		tTNXchData;	/** 7~17, 메시지 프레임의 열차번호 교환 데이터를 포함하는 데이터 필드 */
	TS_CRC32_DATA				tCRC32;		/** 18~21, 메시지 프레임의 CRC32 */
	uint8 ucETX;								/** 22, 메시지 프레임의 종료 문자, ETX=0x03 고정값 */
} TS_COMM_MMI_TRNO_XCH_MSG_FRAME;


/**
* @struct TU_COMM_MMI_STD_MSG_FRAME
* @brief MMI 에서 송신하는 메시지 프레임의 구조체
*/
typedef union {/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;외부 I/F Data packet 1000 byte이내에서 이벤트 형식으로 사용함] */
	uint8 aucMsgFrame[LIMIT_CNT_MMI_STD_COMMFRAME];	/** 송/수신 메시지 프레임의 데이터가 담긴 버퍼 */
	TS_COMM_MMI_SHORT_MSG_FRAME		tShortMsg;		/** 데이터를 포함하지 않는 메시지(ACK, NACK, 초기폴링, Basescan 요구, LINK) */
	TS_COMM_MMI_ELM_CTRL_MSG_FRAME	tElmCtrlMsg;	/** 16.Element 제어 메시지 */
	TS_COMM_MMI_EM_ELM_CTRL_MSG_FRAME	tEmElmCtrlMsg;	/** 86.비상 제어 메시지 */
	TS_COMM_MMI_MASTERE_CLOCK_MSG_FRAME	tMClockMsg;	/** 18.마스터클럭(Master Clock) 설정 메지시 */
	TS_COMM_MMI_TRNO_SET_MSG_FRAME	tTrNoSetMsg;	/** 19.열차번호 생성 메시지 */
	TS_COMM_MMI_TRNO_ALT_MSG_FRAME	tTrNoAltMsg;	/** 23.열차번호 변경 메시지 */
	TS_COMM_MMI_TRNO_DEL_MSG_FRAME	tTrNoDelMsg;	/** 18.열차번호 삭제 메시지 */
	TS_COMM_MMI_TRNO_XCH_MSG_FRAME	tTrNoXchMsg;	/** 23.열차번호 교환 메시지 */
} TU_COMM_MMI_STD_MSG_FRAME;


/* ------------------------------------------------------------------------- */
/* ILS 에서 MMI 로 송신하는 메시지 프레임 구조체 정의                        */
/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */
/* 초기응답(Initial response) 메시지의 데이터 필드 구조체 정의                */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_INITIAL_RESPONSE_DATA
* @brief Polling 응답용의 송신 Que에 저장되는 메시지블럭의 공통 데이터부 구조체
*/
typedef struct {
	uint8 ucDataType;			/** 0, 메시지블럭 데이터의 타입, 0x10:상태변화정보 데이터, 0x20:이벤트메시지 데이터, 0x30:Basescan 상태정보 데이터, 0x40:열차번호 상태변화 데이터, 0x50: Basescan 열차번호 데이터, 0xF0: Initial polling 데이터 */
	uint16 usLength;				/** 1-2, 메시지블럭의 총 데이터 개수, 데이터 타입부터 마지막 데이터까지의 uint8 SIZE 개수 */
	uint8 ucYear;				/** 3 메시지블럭의 생성 년도, 0 ~ 255(2000년 ~ 2255년) */
	uint8 ucMonth;				/** 4, 메시지블럭의 생성 월, 1 ~ 12(월) */
	uint8 ucDay;					/** 5, 메시지블럭의 생성 일, 1 ~ 31(일) */
	uint8 ucHour;				/** 6, 메시지블럭의 생성 시간, 0 ~ 23(시) */
	uint8 ucMinute;				/** 7, 메시지블럭의 생성 분, 0 ~ 59(분) */
	uint8 ucSecond;				/** 8, 메시지블럭의 생성 초, 0 ~ 59(초) */
	uint8 uc10msec;				/** 9, 메시지블럭의 생성 1/100초, 0 ~ 99(10ms~990ms) */
	uint16 usElmTH_COMMON_CNT;	/** 10~11, 역 공통정보(ELM_COMMON) table 의 실사용 개수 (전체 32개) */
	uint16 usElmTH_TR_GI_CNT;		/** 12~13, 궤도회로 일반정보(ELM_TRACK_GI) table 의 실사용 개수 (전체 512개) */
	uint16 usElmTH_TR_EX_CNT;		/** 14~15, 궤도회로 확장(표찰)정보(ELM_TRACK_EX) table 의 실사용 개수 (전체 512개) */
	uint16 usElmTH_SG_GI_CNT;		/** 16~17, 신호기 일반정보(ELM_SIGNAL_GI) table 의 실사용 개수 (전체 512개) */
	uint16 usElmTH_PT_GI_CNT;		/** 18~19, 선로전환기 공통정보(ELM_POINT GI) table 의 실사용 개수 (전체 256개) */
	uint16 usElmTH_GIO_GI_CNT;	/** 20~21, General I/O 일반정보(ELM_GIO_GI) table 의 실사용 개수 (전체 49개) */
	uint16 usElmTH_RT_GI_CNT;		/** 22~23, 진로 일반정보(ELM_ROUTE GI) table 의 실사용 개수 (전체 1024개) */
	uint32 uiILDBSize;			/** 24~27, IDLB SIZE(CRC_DATA 전) */
	uint32 uiAllCRC32;			/** 28~31, 1000byte CRC에대한 CRC */
	uint8 aucILDBVer[SIZE_ILDB_VERSION];	/** 32~49, ILDB Version (18 BYTE) */
} TS_COMM_MMI_INITIAL_RESPONSE_DATA;

/* ------------------------------------------------------------------------- */
/* Polling 응답용 송신 Que에 저장되는 메시지블럭의 공통 데이터부 구조체 정의 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_MSG_BLOCK
* @brief Polling 응답용의 송신 Que에 저장되는 메시지블럭의 공통 데이터부 구조체
*/
typedef struct {
	uint16  usElementID;	/** 0~1, Element의 ID */
	uint8  ucState;		/** 2, Element의 상태정보 */
} TS_COMM_ELM_STATE_DATA;

/* ------------------------------------------------------------------------- */
/* Polling 응답용 송신 Que에 저장되는 상태변화정보 메시지블럭의 구조체 정의  */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_STATE_MSGBLOCK
* @brief Polling 응답용 송신 Que에 저장되는 상태변화정보 메시지블럭의 구조체
*/
/* [LOCAL최대메세지수정] */
/*#define MAX_MSGBLK_ELM_STATE_DATA_CNT       255 */        /** 메시지블럭의 상태변화정보 데이터 블럭 (765 = 255 * 3) */
#define MAX_MSGBLK_ELM_STATE_DATA_CNT       230         /** 메시지블럭의 상태변화정보 데이터 블럭 (765 = 255 * 3) */
typedef struct {
	uint8 ucDataType;		/** 0, 메시지블럭 데이터의 타입, 0x10:상태변화정보 데이터, 0x20:이벤트메시지 데이터, 0x30:Basescan 상태정보 데이터, 0x40:열차번호 상태변화 데이터, 0x50: Basescan 열차번호 데이터, 0xF0: Initial polling 데이터 */
	uint16 usLength;		/** 1-2, 메시지블럭의 총 데이터 개수, 데이터 타입부터 마지막 데이터까지의 BYTE SIZE 개수 */
	uint8 ucYear;			/** 3 메시지블럭의 생성 년도, 0 ~ 255(2000년 ~ 2255년) */
	uint8 ucMonth;			/** 4, 메시지블럭의 생성 월, 1 ~ 12(월) */
	uint8 ucDay;			/** 5, 메시지블럭의 생성 일, 1 ~ 31(일) */
	uint8 ucHour;			/** 6, 메시지블럭의 생성 시간, 0 ~ 23(시) */
	uint8 ucMinute;			/** 7, 메시지블럭의 생성 분, 0 ~ 59(분) */
	uint8 ucSecond;			/** 8, 메시지블럭의 생성 초, 0 ~ 59(초) */
	uint8 uc10msec;			/** 9, 메시지블럭의 생성 1/100초, 0 ~ 99(10ms~990ms) */
	uint8 ucElementCnt;		/** 10, 메시지블럭의 상태변화정보 데이터 개수, 1 ~ 255. */
	TS_COMM_ELM_STATE_DATA	atStateData[MAX_MSGBLK_ELM_STATE_DATA_CNT];	/** 11~875, 메시지블럭의 상태변화정보 데이터 블럭 (765 = 255 * 3) */
} TS_COMM_MMI_STATE_MSGBLOCK;

/* ------------------------------------------------------------------------- */
/* Polling 응답용 송신 Que에 저장되는 이벤트정보 메시지블럭의 구조체 정의    */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_EVENT_MSGBLOCK
* @brief Polling 응답용 송신 Que에 저장되는 이벤트정보 메시지블럭의 구조체
*/
/* [LOCAL최대메세지수정] */
/*#define MAX_MSGBLK_EVENT_DATA_CNT       970 */    /** 데이터 필드(Field)의 최대 크기가 988 BYTE 인 경우 상정 */
/*#define MAX_MSGBLK_EVENT_PARAM_MSG_CNT  24U */    /** 데이터 필드(Field)의 이벤트 파라메트 메세지구조 수     */  /*MISRA-C 2004:10.1:integer underlying type의 부호가 묵시적으로 변환:Type casting 'U'*/
#define MAX_MSGBLK_EVENT_DATA_CNT       610     /** 데이터 필드(Field)의 최대 크기가 988 BYTE 인 경우 상정 */
#define MAX_MSGBLK_EVENT_PARAM_MSG_CNT  15U     /** 데이터 필드(Field)의 이벤트 파라메트 메세지구조 수     */  /*MISRA-C 2004:10.1:integer underlying type의 부호가 묵시적으로 변환:Type casting 'U'*/
typedef struct {
	uint8 ucDataType;		/** 0, 메시지블럭 데이터의 타입, 0x10:상태변화정보 데이터, 0x20:이벤트메시지 데이터, 0x30:Basescan 상태정보 데이터, 0x40:열차번호 상태변화 데이터, 0x50: Basescan 열차번호 데이터, 0xF0: Initial polling 데이터 */
	uint16 usLength;			/** 1-2, 메시지블럭의 총 데이터 개수, 데이터 타입부터 마지막 데이터까지의 BYTE SIZE 개수 */
	uint8 ucYear;			/** 3 메시지블럭의 생성 년도, 0 ~ 255(2000년 ~ 2255년) */
	uint8 ucMonth;			/** 4, 메시지블럭의 생성 월, 1 ~ 12(월) */
	uint8 ucDay;				/** 5, 메시지블럭의 생성 일, 1 ~ 31(일) */
	uint8 ucHour;			/** 6, 메시지블럭의 생성 시간, 0 ~ 23(시) */
	uint8 ucMinute;			/** 7, 메시지블럭의 생성 분, 0 ~ 59(분) */
	uint8 ucSecond;			/** 8, 메시지블럭의 생성 초, 0 ~ 59(초) */
	uint8 uc10msec;			/** 9, 메시지블럭의 생성 1/100초, 0 ~ 99(10ms~990ms) */
	uint8 ucEventCnt;		/** 10, 메시지블럭의 이벤트메시지 데이터 개수, 1 ~ 255. */
	uint16 usEventCode;		/** 11-12, 메시지블럭의 이벤트메시지 첫 데이터의 이벤트 번호, 1 ~ 999. */
	union {/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;외부 I/F Data packet 1000 byte이내에서 이벤트 형식으로 사용함] */
		uint8 ucEventData[MAX_MSGBLK_EVENT_DATA_CNT];	/** 13~982, 계속되는 메시지블럭의 이벤트메시지 데이터들 (데이터 필드(Field)의 최대 크기가 988 BYTE 인 경우 상정). */
		TS_EVNMSG_PARAM atMsg[MAX_MSGBLK_EVENT_PARAM_MSG_CNT];	
	}Msg;
} TS_COMM_MMI_EVENT_MSGBLOCK;

/* ------------------------------------------------------------------------- */
/* Polling 응답용 송신 Que에 저장되는 Basescan 상태정보 메시지블럭의 구조체 정의  */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_BSSTATE_MSGBLOCK
* @brief Polling 응답용 송신 Que에 저장되는 Basescan 상태정보 메시지블럭의 구조체
*/
#define MAX_MSGBLK_BSSTATE_CNT	970		/** 데이터 필드(Field)의 최대 크기가 988 BYTE 인 경우 상정 */
typedef struct {
	uint8 ucDataType;	/** 0, 메시지블럭 데이터의 타입, 0x10:상태변화정보 데이터, 0x20:이벤트메시지 데이터, 0x30:Basescan 상태정보 데이터, 0x40:열차번호 상태변화 데이터, 0x50: Basescan 열차번호 데이터, 0xF0: Initial polling 데이터 */
	uint16 usLength;		/** 1-2, 메시지블럭의 총 데이터 개수, 데이터 타입부터 마지막 데이터까지의 BYTE SIZE 개수 */
	uint8 ucYear;		/** 3 메시지블럭의 생성 년도, 0 ~ 255(2000년 ~ 2255년) */
	uint8 ucMonth;		/** 4, 메시지블럭의 생성 월, 1 ~ 12(월) */
	uint8 ucDay;			/** 5, 메시지블럭의 생성 일, 1 ~ 31(일) */
	uint8 ucHour;		/** 6, 메시지블럭의 생성 시간, 0 ~ 23(시) */
	uint8 ucMinute;		/** 7, 메시지블럭의 생성 분, 0 ~ 59(분) */
	uint8 ucSecond;		/** 8, 메시지블럭의 생성 초, 0 ~ 59(초) */
	uint8 uc10msec;		/** 9, 메시지블럭의 생성 1/100초, 0 ~ 99(10ms~990ms) */
	uint16 usStartID;		/** 10-11, 메시지블럭의 Basescan 상태정보 시작 Element ID(usElement[0])와 마지막 Element ID(usElement[1]) */
	uint16 usEndID;		/** 12-13, 메시지블럭의 Basescan 상태정보 시작 Element ID(usElement[0])와 마지막 Element ID(usElement[1]) */
	uint8 aucState[MAX_MSGBLK_BSSTATE_CNT];	/** 14~983, 메시지블럭의 Basescan 상태정보 데이터들 (데이터 필드(Field)의 최대 크기가 988 BYTE 인 경우 상정) */
} TS_COMM_MMI_BSSTATE_MSGBLOCK;

/**
* @struct TS_COMM_MMI_BSSTATE_REAL_MSGBLOCK
* @brief Polling 응답용 송신 Que에 저장되는 실사용 역별 실사용 개수에 맞춘 Basescan 상태정보 메시지블럭의 구조체
*/
/* [LOCAL최대메세지수정] */
/* #define MAX_MSGBLK_BSSTATE_REAL_CNT	966U */		/** 데이터 필드(Field)의 최대 크기가 988 BYTE 인 경우 상정 */
#define MAX_MSGBLK_BSSTATE_REAL_CNT	700U		/** 데이터 필드(Field)의 최대 크기가 720 BYTE 인 경우 상정 */
typedef struct {
	uint8 ucDataType;			/** 0, 메시지블럭 데이터의 타입, 0x10:상태변화정보 데이터, 0x20:이벤트메시지 데이터, 0x30:Basescan 상태정보 데이터, 0x31:REAL TYPE BASESCAN 상태정보 데이터, 0x40:열차번호 상태변화 데이터, 0x50: Basescan 열차번호 데이터, 0xF0: Initial polling 데이터 */
	uint16 usLength;				/** 1-2, 메시지블럭의 총 데이터 개수, 데이터 타입부터 마지막 데이터까지의 BYTE SIZE 개수 */
	uint8 ucYear;				/** 3 메시지블럭의 생성 년도, 0 ~ 255(2000년 ~ 2255년) */
	uint8 ucMonth;				/** 4, 메시지블럭의 생성 월, 1 ~ 12(월) */
	uint8 ucDay;					/** 5, 메시지블럭의 생성 일, 1 ~ 31(일) */
	uint8 ucHour;				/** 6, 메시지블럭의 생성 시간, 0 ~ 23(시) */
	uint8 ucMinute;				/** 7, 메시지블럭의 생성 분, 0 ~ 59(분) */
	uint8 ucSecond;				/** 8, 메시지블럭의 생성 초, 0 ~ 59(초) */
	uint8 uc10msec;				/** 9, 메시지블럭의 생성 1/100초, 0 ~ 99(10ms~990ms) */
	uint16 usStationNo;			/** 10~11, 역 고정 번호 */
	uint8 ucSpare[4];			/** 12~15, spare */
	uint8 ucCurrBlkID;			/** 16, Current 메시지블럭의 번호 */
	uint8 ucEndBlkID;			/** 17, Total 메시지블럭의 번호 */
	uint8 aucState[MAX_MSGBLK_BSSTATE_REAL_CNT];			/** 18~983, 메시지블럭의 Basescan 상태정보 데이터들 (데이터 필드(Field)의 최대 크기가 988 BYTE 인 경우 상정) */
} TS_COMM_MMI_BSSTATE_REAL_MSGBLOCK;

/* ------------------------------------------------------------------------- */
/* Polling 응답용 송신 Que에 저장되는 메시지블럭의 열차번호 데이터부 구조체 정의 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_OBJ_TRNO_DATA
* @brief Polling 응답용의 송신 Que에 저장되는 메시지블럭의 열차번호 데이터부 구조체
*/
typedef struct {
	uint16 usTrainNoID;			/** 0~1, Train No. Window 의 ID */
	uint16 usTrackID;			/** 2-3, Track Object 의 ID */
	uint8 aucTrainNumber1[5];	/** 4~8, 열차번호 #1 */
	uint8 aucTrainNumber2[5];	/** 9~13, 열차번호 #2 */
} TS_COMM_TRNO_OBJ_DATA;

/* ------------------------------------------------------------------------- */
/* Polling 응답용 송신 Que에 저장되는 Basescan 요구된 또는 상태변화된 열차번호 메시지블럭의 구조체 정의  */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_MMI_TRNOSTATE_MSGBLOCK
* @brief Polling 응답용 송신 Que에 저장되는 Basescan 요구된 또는 상태변화된 열차번호 메시지블럭의 구조체
*/
#define MAX_MSGBLK_TRNO_OBJ_DATA_CNT	50		/** 최대 50개, 0 번째는 사용하지 않음-Reserved */
typedef struct {
	uint8 ucDataType;	/** 0, 메시지블럭 데이터의 타입, 0x10:상태변화정보 데이터, 0x20:이벤트메시지 데이터, 0x30:Basescan 상태정보 데이터, 0x40:열차번호 상태변화 데이터, 0x50: Basescan 열차번호 데이터, 0xF0: Initial polling 데이터 */
	uint16 usLength;		/** 1-2, 메시지블럭의 총 데이터 개수, 데이터 타입부터 마지막 데이터까지의 BYTE SIZE 개수 */
	uint8 ucYear;		/** 3 메시지블럭의 생성 년도, 0 ~ 255(2000년 ~ 2255년) */
	uint8 ucMonth;		/** 4, 메시지블럭의 생성 월, 1 ~ 12(월) */
	uint8 ucDay;			/** 5, 메시지블럭의 생성 일, 1 ~ 31(일) */
	uint8 ucHour;		/** 6, 메시지블럭의 생성 시간, 0 ~ 23(시) */
	uint8 ucMinute;		/** 7, 메시지블럭의 생성 분, 0 ~ 59(분) */
	uint8 ucSecond;		/** 8, 메시지블럭의 생성 초, 0 ~ 59(초) */
	uint8 uc10msec;		/** 9, 메시지블럭의 생성 1/100초, 0 ~ 99(10ms~990ms) */
	uint8 ucTrainWndCnt;	/** 10, 메시지블럭의열차번호 정보 개수(0~49) */
	TS_COMM_TRNO_OBJ_DATA tTrainObjDB[50];	/** 12, 열차번호 메시지블럭의 전체 데이터(최대 50개, 0 번째는 사용하지 않음-Reserved) */
} TS_COMM_MMI_TRNOSTATE_MSGBLOCK;


/* ------------------------------------------------------------------------- */
/* Polling 응답용의 송신 Que에 저장되는 메시지블럭의 구조체 정의             */
/* ------------------------------------------------------------------------- */
/**
* @struct TU_COMM_MSG_BLOCK
* @brief Polling 응답용의 송신 Que에 저장되는 메시지블럭의 구조체
*/
typedef union {/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;외부 I/F Data packet 1000 byte이내에서 이벤트 형식으로 사용함] */
	uint8	aucMsgBlock[LIMIT_CNT_MMI_EXT_COMMFRAME];		/** 메시지블럭의 데이터가 담긴 버퍼 */
	TS_COMM_MMI_INITIAL_RESPONSE_DATA	tInitRespData;		/** 메시지블럭의 Initial Polling 응답 데이터 블럭 */
	TS_COMM_MMI_STATE_MSGBLOCK			tStateMsgBlk;		/** 메시지블럭의 상태변화 정보 데이터 블럭 */
	TS_COMM_MMI_EVENT_MSGBLOCK			tEventMsgBlk;		/** 메시지블럭의 이벤트메시지 정보 데이터 블럭 */
	TS_COMM_MMI_BSSTATE_MSGBLOCK		tBSStateMsgBlk;		/** 메시지블럭의 Basescan 상태정보 데이터 블럭 */
	TS_COMM_MMI_TRNOSTATE_MSGBLOCK		tTrNoStateMsgBlk;	/** 메시지블럭의 열차번호(상태변화 또는 Basescan) 데이터 블럭 */
} TU_COMM_MSG_BLOCK;

/**
* @struct TS_COMM_INITPOLLING_RESPONSE_MSG_FRAME
* @brief 초기응답(Initial Response) 메시지 프레임의 구조체
*/
typedef struct {
	uint8  ucSTX;										/** 0, 메시지 프레임의 시작 문자, STX=0x02 고정값 */
	TS_COMM_MMI_FRAME_HEADER			tHeader;		/** 1~6, 메시지 프레임의 해더 데이터 */
	TS_COMM_MMI_INITIAL_RESPONSE_DATA	tInitRespData;	/** 7~23, 메시지 프레임의 열차번호 교환 데이터를 포함하는 데이터 필드 */
	TS_CRC32_DATA						tCRC32;			/** 24~27, 메시지 프레임의 CRC32 */
	uint8 ucETX;											/** 28, 메시지 프레임의 종료 문자, ETX=0x03 고정값 */
} TS_COMM_MMI_INITIAL_RESP_MSG_FRAME;

/**
* @struct TS_COMM_INITPOLLING_RESPONSE_MSG_FRAME
* @brief 초기응답(Initial Response) 메시지 프레임의 구조체
*/
typedef struct {	
	uint8  ucSTX;										/** 0, 메시지 프레임의 시작 문자, STX=0x02 고정값 */
	TS_COMM_MMI_FRAME_HEADER			tHeader;		/** 1~6, 메시지 프레임의 해더 데이터 */
	union {/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;외부 I/F Data packet 1000 byte이내에서 이벤트 형식으로 사용함] */
		TS_COMM_MMI_STATE_MSGBLOCK		tStateMsgBlk;	/** 메시지블럭의 상태변화 정보 데이터 블럭 */
		TS_COMM_MMI_EVENT_MSGBLOCK		tEventMsgBlk;	/** 메시지블럭의 이벤트메시지 정보 데이터 블럭 */
		TS_COMM_MMI_BSSTATE_MSGBLOCK	tBSStateMsgBlk;	/** 메시지블럭의 Basescan 상태정보 데이터 블럭 */
		TS_COMM_MMI_TRNOSTATE_MSGBLOCK	tTrNoStateMsgBlk;	/** 메시지블럭의 열차번호(상태변화 또는 Basescan) 데이터 블럭 */
	} BLK;
	TS_CRC32_DATA						tCRC32;			/** 24~27, 메시지 프레임의 CRC32, 데이터 블럭의 실제 크기에 따라 이 데이터가 무시되고 다른곳에 정의될 수도 있음. */
	uint8 ucETX;											/** 28, 메시지 프레임의 종료 문자, ETX=0x03 고정값, 데이터 블럭의 실제 크기에 따라 이 데이터가 무시되고 다른곳에 정의될 수도 있음. */
} TS_COMM_MMI_POLLING_RESP_MSG_FRAME;


/**
* @struct TU_COMM_ILS_MSG_FRAME
* @brief ILS 에서 송신하는 메시지 프레임의 구조체
*/
typedef union {/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;외부 I/F Data packet 1000 byte이내에서 이벤트 형식으로 사용함] */
	uint8 aucMsgFrame[LIMIT_CNT_MMI_EXT_COMMFRAME];		/** 송/수신 메시지 프레임의 데이터가 담긴 버퍼 */
	TS_COMM_MMI_SHORT_MSG_FRAME			tShortMsg;		/** 데이터를 포함하지 않는 메시지(ACK, NACK, LINK) */
	TS_COMM_MMI_INITIAL_RESP_MSG_FRAME	tInitRespMsg;	/** 초기응답(Initial Response) 메시지 */
	TS_COMM_MMI_POLLING_RESP_MSG_FRAME	tPollRespMsg;	/** 폴링응답(Polling Respoinse) (상태변화정보/이벤트/Basescan 상태정보) 메시지 */
} TU_COMM_ILS_MSG_FRAME;


/* ------------------------------------------------------------------------- */

#endif /** #ifndef _DEFCOMMTYPES_H_ */
