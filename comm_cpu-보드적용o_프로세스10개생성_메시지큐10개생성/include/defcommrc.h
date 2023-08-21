#ifndef _DEFCOMMRC_H_
#define _DEFCOMMRC_H_
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
* @file     defcommrc.h : header file
* @project  KRS-EIS
* @process  COMM-RC
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
* @date 2015-12-05
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

/* ------------------------------------------------------------------------- */
/* RC 통신 프레임 코드 정의                                                  */
/* ------------------------------------------------------------------------- */
#define COMM_RC_STX						0x02	/** STX of the RC frame */
#define COMM_RC_ETX						0x03	/** ETX of the RC frame */

/* ------------------------------------------------------------------------- */
/* RC 통신 프레임 기능코드 정의                                              */
/* ------------------------------------------------------------------------- */
#define COMM_RC_FUNC_POLLING			0x20	/** 폴링(Polling) 메시지 */
#define COMM_RC_FUNC_STATE				0x21	/** 상태(State)정보 메시지 */
#define COMM_RC_FUNC_CONTROL			0x30U	/** 제어(Control) 메시지 */
#define COMM_RC_FUNC_ACK				0x31	/** Acknowledge 메시지 */
#define COMM_RC_FUNC_NACK				0x41	/** Negative Acknowledge 메시지 */
#define COMM_RC_FUNC_MASTERCLOCK		0x40	/** Master Clock 설정 메시지 */
#define COMM_RC_FUNC_TRAINNUMBER		0x50	/** 열차번호(Train Number) 제어 메시지 */
#define COMM_RC_FUNC_BASESCANREQ		0x60	/** Basescan 요구 메시지 */
#define COMM_RC_FUNC_BASESCAN			0x61	/** Basescan 응답 메시지 */
#define COMM_RC_FUNC_ALARMMSG			0x82	/** ALARM 메시지 */

/* ------------------------------------------------------------------------- */
/* RC 통신 프레임 제어 기능코드 정의                                         */
/* ------------------------------------------------------------------------- */
#define COMM_RC_CTRL_MODE				0x01	/** 제어 기능코드, 운용모드 설정 제어 메시지 */
#define COMM_RC_CTRL_POINT				0x02	/** 제어 기능코드, 선로전환기 제어 */
#define COMM_RC_CTRL_SIGNALROUTE		0x03	/** 제어 기능코드, (주신호) 진로설정 및 해정 제어 */
#define COMM_RC_CTRL_SHUNTROUTE			0x04	/** 제어 기능코드, 입환진로 설정 및 해정 제어 */
#define COMM_RC_CTRL_BLOCK				0x05	/** 제어 기능코드, 폐색 제어 */
#define COMM_RC_CTRL_EMRTRELEASE		0x10	/** 제어 기능코드, 구분진로비상해정 제어 */
#define COMM_RC_CTRL_SYSRUN				0x20	/** 제어 기능코드, SYSTEM RUN 제어 */
#define COMM_RC_CTRL_SHUNTLAMPOFF		0x30	/** 제어 기능코드, 입환 소등/점등 제어 */
#define COMM_RC_CTRL_SGALLSTOP			0x40	/** 제어 기능코드, 신호기일괄정지 제어 */
#define COMM_RC_CTRL_HEATER				0x80	/** 제어 기능코드, 히터가동 제어 */


/* ///////////////////////////////////////////////////////////////////////// */
/* 공용 구조체 정의                                                          */
/* ///////////////////////////////////////////////////////////////////////// */

/* ------------------------------------------------------------------------- */
/* EIS 에서 RC 로 송신하는 데이터 프레임 구조체 정의                         */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_RC_STATE_DATA
* @brief EIS -> RC 로 송신하는 통신 프레임의 업데이트 상태정보 데이터를 정의하는 구조체
*/
typedef struct {
	uint16 usElementID;		/* Data 0~1, ElementID*/
	uint8 ucState;			/* Data 2, state data.*/
} TS_COMM_RC_STATE_DATA;

/* ------------------------------------------------------------------------- */
/* EIS 에서 RC 로 송신하는 데이터 프레임 구조체 정의                         */
/* ------------------------------------------------------------------------- */

/**
* @struct TS_COMM_RC_DATA
* @brief EIS -> RC 로 송신하는 통신 프레임의 업데이트 상태정보 데이터를 정의하는 구조체
*/
typedef struct {
	uint8 ucData1;			/* Data 0~1, ElementID   */
	uint8 ucData2;			/* Data 0~1, ElementID   */
	uint8 ucData3;			/* Data 0~1, ElementID   */
} TS_COMM_RC_DATA;

/**
* @struct TS_COMM_RC_STATE_TRAINNO
* @brief EIS -> RC 로 송신하는 통신 프레임의 설비 상태정보 데이터를 정의하는 구조체
*/
typedef struct {
	uint8 ucCode;			/* Data 0, 제어 코드 (0x90:열번 1번문자, 0x91:열번 2번째문자, 0x92:열번 3번째문자, 0x93:열번4,5번째문자, 0x9e:삭제)	*/
	uint8 ucElementID;		/* Data 1, ElementID                */
	uint8 ucNo;				/* Data 2, 번호(A,1,2,3&4,삭제여부).     */
} TS_COMM_RC_STATE_TRAINNO;


/**
* @struct TS_COMM_RC_STATE_EVNMSG
* @brief EIS -> RC 로 송신하는 통신 프레임의 설비 상태정보 데이터를 정의하는 구조체
*/
typedef struct {
	uint8 ucCode;			/* Data 0, 메시지 번호.*/
	uint8 ucElementID1;		/* Data 1, ElementID #1.*/
	uint8 ucElementID2;		/* Data 2, ElementID #2.*/
} TS_COMM_RC_STATE_EVNMSG;


/**
* @struct TS_COMM_RC_CTRL_MESSAGE
* @brief EIS -> RC 로 송신하는 통신 프레임의 설비 상태정보 데이터를 정의하는 구조체
*/
typedef struct {
	uint8 ucCode;			/* Data 0, 제어메시지 번호.*/
	uint16 usElementID;		/* Data 1!2, ElementID.*/
	uint8 ucCtrlState;		/* Data 2, ElementID #2.*/
} TS_COMM_RC_CTRL_MESSAGE;


/**
* @struct TS_COMM_RC_CTRL_MCLOCK
* @brief EIS -> RC 로 송신하는 통신 프레임의 마스터클럭 데이터를 정의하는 구조체
*/
typedef struct {
	uint8 ucYear;		/* Data 0:년(00 ~ 255 -->, 2000년 ~ 2255년).*/
	uint8 ucMonth;		/* Data 1:월 1 ~ 12.*/
	uint8 ucday;			/* Data 2:일 1 ~ 31.*/
	uint8 ucHour;		/* Data 3:시 0 ~ 23.*/
	uint8 ucMinute;		/* Data 4:분 0 ~ 59.*/
	uint8 ucSecond;		/* Data 5:초 0 ~ 59.*/
} TS_COMM_RC_CTRL_MCLOCK;


/**
* @struct TS_COMM_RC_CTRL_TRAINNO
* @brief EIS -> RC 로 송신하는 통신 프레임의 열차번호 상태정보 데이터를 정의하는 구조체
*/
typedef struct {
	uint8 ucTrainNo[5];		/* Data 0:영문자, 1~4:숫자데이터.*/
	uint16 usElementID;		/* Data 5~6, track ElementID.*/
} TS_COMM_RC_CTRL_TRAINNO;


/* ------------------------------------------------------------------------- */
/* RC 에서 EIS 로 송신하는 데이터 프레임 구조체 정의                         */
/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */
/* RC 통신 프레임의 해더(Header) 구조체 정의                                 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_RC_TX_FRAME_HEADER
* @brief EIS -> RC 로 송신하는 통신 프레임의 해더 데이터를 정의하는 구조체
*/
typedef struct {
	uint8	ucSTX;				/** 0, 메시지 프레임의 시작, STX */
	uint8	ucLength;			/** 1, 메시지 프레임의 데이터 사이즈, blank ~ Data 필드(Field)까지의 Byte Size (0x00 ~ 0xFF) */
	uint8	ucSequenceNo;		/** 2, 메시지 프레임의 순서번호, 0x00~ 0x7F, ACK는 수신 sequence 번호를 적용함 */
	uint8	ucFunctionCode;		/** 3, 메시지 프레임의 기능코드 */
	uint8	ucStationID;		/** 4, 메시지 프레임의 적용대상 역 ID */
	uint8	ucDumyBlank[7];		/** 5~11, 메시지 프레임의 빈 공간(datetime용도) */
} TS_COMM_RC_TX_FRAME_HEADER;

/**
* @struct TS_COMM_RC_RX_FRAME_HEADER
* @brief RC -> EIS 로 송신하는 통신 프레임의 해더 데이터를 정의하는 구조체
*/
typedef struct {
	uint8	ucSTX;				/** 0, 메시지 프레임의 시작, STX */
	uint8	ucLength;			/** 1, 메시지 프레임의 데이터 사이즈, blank ~ Data 필드(Field)까지의 Byte Size (0x00 ~ 0xFF) */
	uint8	ucSequenceNo;		/** 2, 메시지 프레임의 순서번호, 0x00~ 0x7F, ACK는 수신 sequence 번호를 적용함 */
	uint8	ucFunctionCode;		/** 3, 메시지 프레임의 기능코드 */
	uint8	ucStationID;		/** 4, 메시지 프레임의 적용대상 역 ID */
} TS_COMM_RC_RX_FRAME_HEADER;

/* ------------------------------------------------------------------------- */
/* RC 통신 프레임의 송,수신 프레임 구조체 정의                               */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_RC_TX_FRAME_SHORT
* @brief EIS -> RC 로 송신하는 SHORT 통신 프레임을 정의하는 구조체
*/
typedef struct {
	uint8	ucSTX;				/** 0, 메시지 프레임의 시작, STX */
	uint8	ucLength;			/** 1, 메시지 프레임의 데이터 사이즈, blank ~ Data 필드(Field)까지의 Byte Size (0x00 ~ 0xFF) */
	uint8	ucSequenceNo;		/** 2, 메시지 프레임의 순서번호, 0x00~ 0x7F, ACK는 수신 sequence 번호를 적용함 */
	uint8	ucFunctionCode;		/** 3, 메시지 프레임의 기능코드 */
	uint8	ucStationID;		/** 4, 메시지 프레임의 적용대상 역 ID */
	uint8	ucDumyBlank[7];		/** 5~11, 메시지 프레임의 BLANK 데이터 */
	uint8	ucCRC[2];			/** 12~13, 메시지 프레임의 CRC-16 */
	uint8	ucETX;				/** 14, 메시지 프레임의 끝, ETX */
} TS_COMM_RC_TX_FRAME_SHORT;

/**
* @struct TS_COMM_RC_TX_FRAME_STATE
* @brief EIS -> RC 로 송신하는 SHORT 통신 프레임을 정의하는 구조체
*/
#define		MAX_RC_SEND_DATA_SIZE	82U
typedef struct {
	uint8	ucSTX;				/** 0, 메시지 프레임의 시작, STX */
	uint8	ucLength;			/** 1, 메시지 프레임의 데이터 사이즈, blank ~ Data 필드(Field)까지의 Byte Sizev */
	uint8	ucSequenceNo;		/** 2, 메시지 프레임의 순서번호, 0x00~ 0x7F, ACK는 수신 sequence 번호를 적용함  */
	uint8	ucFunctionCode;		/** 3, 메시지 프레임의 기능코드 */
	uint8	ucStationID;		/** 4, 메시지 프레임의 적용대상 역 ID */
	uint8	ucDumyBlank[7];		/** 5~11, 메시지 프레임의 BLANK 데이터 */
	union{/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;외부 I/F Data packet 1000 byte이내에서 이벤트 형식으로 사용함] */
		TS_COMM_RC_DATA				tData[82];
		TS_COMM_RC_STATE_DATA		tsState[82];
		TS_COMM_RC_STATE_EVNMSG		tsEvnMsg[82];
		TS_COMM_RC_STATE_TRAINNO	tsTrainNo[82];
	} D;
} TS_COMM_RC_TX_FRAME_STATE;

/**
* @struct TS_COMM_RC_TX_FRAME_BSCAN
* @brief EIS -> RC 로 송신하는 BASESCAN 통신 프레임을 정의하는 구조체
*/
#define		MAX_RC_SEND_BSCANDATA_SIZE	242U
typedef struct {
	uint8	ucSTX;				/** 0, 메시지 프레임의 시작, STX */
	uint8	ucLength;			/** 1, 메시지 프레임의 데이터 사이즈, blank ~ Data 필드(Field)까지의 Byte Size (0x00 ~ 0xFF) */
	uint8	ucSequenceNo;		/** 2, 메시지 프레임의 순서번호, 0x00~ 0x7F, ACK는 수신 sequence 번호를 적용함  */
	uint8	ucFunctionCode;		/** 3, 메시지 프레임의 기능코드 */
	uint8	ucStationID;		/** 4, 메시지 프레임의 적용대상 역 ID */
	uint8	ucDumyBlank[7];		/** 5~11, 메시지 프레임의 BLANK 데이터 */
	uint16	usElementID1;		/** 12~13, 시작 element ID */
	uint16	usElementID2;		/** 14~15, 마지막 element ID */
	uint8    ucState[242];		/** 16~257, 상태정보 테이블 */
} TS_COMM_RC_TX_FRAME_BSCAN;

/**
* @struct TS_COMM_RC_RX_FRAME_SHORT
* @brief RC -> EIS 로 송신하는 SHORT 통신 프레임을 정의하는 구조체
*/
typedef struct {
	uint8	ucSTX;				/** 0, 메시지 프레임의 시작, STX */
	uint8	ucLength;			/** 1, 메시지 프레임의 데이터 사이즈, Data 필드(Field)까지의 Byte Size (0x00 ~ 0xFF) */
	uint8	ucSequenceNo;		/** 2, 메시지 프레임의 순서번호, 0x00~ 0x7F, ACK는 수신 sequence 번호를 적용함  */
	uint8	ucFunctionCode;		/** 3, 메시지 프레임의 기능코드 */
	uint8	ucStationID;		/** 4, 메시지 프레임의 적용대상 역 ID */
	uint8	ucCRC[2];			/** 5~6, 메시지 프레임의 */
	uint8	ucETX;				/** 7, 메시지 프레임의 끝, ETX */
} TS_COMM_RC_RX_FRAME_SHORT;

/**
* @struct TS_COMM_RC_RX_FRAME_CTRLCMD
* @brief RC -> EIS 로 송신하는 제어명령 통신 프레임을 정의하는 구조체
*/
typedef struct {
	uint8	ucSTX;				/** 0, 메시지 프레임의 시작, STX */
	uint8	ucLength;			/** 1, 메시지 프레임의 데이터 사이즈, Data 필드(Field)까지의 Byte Size (0x00 ~ 0xFF) */
	uint8	ucSequenceNo;		/** 2, 메시지 프레임의 순서번호, 0x00~ 0x7F, ACK는 수신 sequence 번호를 적용함 */
	uint8	ucFunctionCode;		/** 3, 메시지 프레임의 기능코드 */
	uint8	ucStationID;		/** 4, 메시지 프레임의 적용대상 역 ID */
	TS_COMM_RC_CTRL_MESSAGE tsCtrlMsg;	/** 5~8, 메시지 프레임의 제어 데이터 */
	uint8	ucCRC[2];			/** 9~10, 메시지 프레임의 CRC-16 */
	uint8	ucETX;				/** 11, 메시지 프레임의 끝, ETX */
} TS_COMM_RC_RX_FRAME_CTRLCMD;

/**
* @struct TS_COMM_RC_RX_FRAME_MCLOCK
* @brief RC -> EIS 로 송신하는 마스터클럭 통신 프레임을 정의하는 구조체
*/
typedef struct {
	uint8	ucSTX;				/** 0, 메시지 프레임의 시작, STX */
	uint8	ucLength;			/** 1, 메시지 프레임의 데이터 사이즈, Data 필드(Field)까지의 Byte Size (0x00 ~ 0xFF) */
	uint8	ucSequenceNo;		/** 2, 메시지 프레임의 순서번호, 0x00~ 0x7F, ACK는 수신 sequence 번호를 적용함 */
	uint8	ucFunctionCode;		/** 3, 메시지 프레임의 기능코드 */
	uint8	ucStationID;		/** 4, 메시지 프레임의 적용대상 역 ID */
	uint8	ucData[6];			/** 5~10, 메시지 프레임의 제어 데이터 */
	uint8	ucCRC[2];			/** 11~12, 메시지 프레임의 CRC-16 */
	uint8	ucETX;				/** 13, 메시지 프레임의 끝, ETX */
} TS_COMM_RC_RX_FRAME_MCLOCK;

/**
* @struct TS_COMM_RC_RX_FRAME_TRAINNO
* @brief RC -> EIS 로 송신하는 마스터클럭 통신 프레임을 정의하는 구조체
*/
typedef struct {
	uint8	ucSTX;				/** 0, 메시지 프레임의 시작, STX */
	uint8	ucLength;			/** 1, 메시지 프레임의 데이터 사이즈, Data 필드(Field)까지의 Byte Size (0x00 ~ 0xFF) */
	uint8	ucSequenceNo;		/** 2, 메시지 프레임의 순서번호, 0x00~ 0x7F, ACK는 수신 sequence 번호를 적용함 */
	uint8	ucFunctionCode;		/** 3, 메시지 프레임의 기능코드 */
	uint8	ucStationID;		/** 4, 메시지 프레임의 적용대상 역 ID */
	TS_COMM_RC_CTRL_TRAINNO tsTrainNo;		/** 5~11, 메시지 프레임의 제어 데이터 */
	uint8	ucCRC[2];			/** 12~13, 메시지 프레임의 CRC-16 */
	uint8	ucETX;				/** 14, 메시지 프레임의 끝, ETX */
} TS_COMM_RC_RX_FRAME_TRAINNO;

/**
* @struct TS_COMM_RC_RX_FRAME_BSCAN
* @brief RC -> EIS 로 송신하는 베이스스캔 통신 프레임을 정의하는 구조체
*/
typedef struct {
	uint8	ucSTX;				/** 0, 메시지 프레임의 시작, STX */
	uint8	ucLength;			/** 1, 메시지 프레임의 데이터 사이즈, Data 필드(Field)까지의 Byte Size (0x00 ~ 0xFF) */
	uint8	ucSequenceNo;		/** 2, 메시지 프레임의 순서번호, 0x00~ 0x7F, ACK는 수신 sequence 번호를 적용함 */
	uint8	ucFunctionCode;		/** 3, 메시지 프레임의 기능코드 */
	uint8	ucStationID;		/** 4, 메시지 프레임의 적용대상 역 ID */
	uint16	usStartID;			/** 5~6, 시작 element ID */
	uint16	usEndID;			/** 7~8, 마지막 element ID */
	uint8	ucCRC[2];			/** 9~10, 메시지 프레임의 CRC-16 */
	uint8	ucETX;				/** 11, 메시지 프레임의 끝, ETX */
} TS_COMM_RC_RX_FRAME_BSCAN;


/* ------------------------------------------------------------------------- */
/* RC 통신 프레임의 송,수신 프레임 통합 구조체 정의                          */
/* ------------------------------------------------------------------------- */
/**
* @struct TU_COMM_RC_TX_FRAME
* @brief EIS -> RC 로 송신하는 전체 통신 프레임을 정의하는 구조체
*/
typedef union {/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;외부 I/F Data packet 1000 byte이내에서 이벤트 형식으로 사용함] */
	uint8	aucBuff[264];					/** 0, 메시지 프레임의 버퍼 */
	TS_COMM_RC_TX_FRAME_SHORT	tsShort;	/* short frame*/
	TS_COMM_RC_TX_FRAME_STATE	tsState;	/* state frame*/
	TS_COMM_RC_TX_FRAME_BSCAN	tsBScan;	/* basescan frame*/
} TU_COMM_RC_TX_FRAME;

/**
* @struct TU_COMM_RC_RX_FRAME
* @brief RC EIS -> 로 송신하는 전체 통신 프레임을 정의하는 구조체
*/
typedef union {/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;외부 I/F Data packet 1000 byte이내에서 이벤트 형식으로 사용함] */
	uint8	aucBuff[20];		/** 0, 메시지 프레임의 버퍼 */
	TS_COMM_RC_RX_FRAME_SHORT	tsShort;	/* short frame*/
	TS_COMM_RC_RX_FRAME_CTRLCMD	tsCtrlCmd;	/* control command frame*/
	TS_COMM_RC_RX_FRAME_MCLOCK	tsMClock;	/* master clock frame*/
	TS_COMM_RC_RX_FRAME_TRAINNO	tsTrainNo;	/* train no control frame */
	TS_COMM_RC_RX_FRAME_BSCAN	tsBScanReq;	/* basescan request frame */
} TU_COMM_RC_RX_FRAME;

/* ------------------------------------------------------------------------- */

#endif /* #ifndef _DEFCOMMRC_H_ */
