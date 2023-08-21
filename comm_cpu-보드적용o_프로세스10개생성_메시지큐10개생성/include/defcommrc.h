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
* @dev-env  	Microsoft Visual Studio Professional 2013K ���� 12.0.21005.1 REL
*           Microsoft .NET Framework 4.5.51209
*			Window 7 Professional K 6.1.7601 SP1 build 7601
*			(CPU: intel i5-4200M 2.5Ghz, RAM 8G)
* @exe-env	WinXP SP3 �̻�.
* @library	not used.
* @brief    Communication�� ���� ��ſ� Const value �� ������ ����ü�� �����Ѵ�.
* @see      TS_COMM_PORT_STATE_TABLE, TS_COMM_TASK_STATE_TABLE ����ü��
* @see      history is described below.
*/
/* ------------------------------------------------------------------------- */
/* File History                                                              */
/* ------------------------------------------------------------------------- */
/**
* @date 2015-12-05
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

/* ------------------------------------------------------------------------- */
/* RC ��� ������ �ڵ� ����                                                  */
/* ------------------------------------------------------------------------- */
#define COMM_RC_STX						0x02	/** STX of the RC frame */
#define COMM_RC_ETX						0x03	/** ETX of the RC frame */

/* ------------------------------------------------------------------------- */
/* RC ��� ������ ����ڵ� ����                                              */
/* ------------------------------------------------------------------------- */
#define COMM_RC_FUNC_POLLING			0x20	/** ����(Polling) �޽��� */
#define COMM_RC_FUNC_STATE				0x21	/** ����(State)���� �޽��� */
#define COMM_RC_FUNC_CONTROL			0x30U	/** ����(Control) �޽��� */
#define COMM_RC_FUNC_ACK				0x31	/** Acknowledge �޽��� */
#define COMM_RC_FUNC_NACK				0x41	/** Negative Acknowledge �޽��� */
#define COMM_RC_FUNC_MASTERCLOCK		0x40	/** Master Clock ���� �޽��� */
#define COMM_RC_FUNC_TRAINNUMBER		0x50	/** ������ȣ(Train Number) ���� �޽��� */
#define COMM_RC_FUNC_BASESCANREQ		0x60	/** Basescan �䱸 �޽��� */
#define COMM_RC_FUNC_BASESCAN			0x61	/** Basescan ���� �޽��� */
#define COMM_RC_FUNC_ALARMMSG			0x82	/** ALARM �޽��� */

/* ------------------------------------------------------------------------- */
/* RC ��� ������ ���� ����ڵ� ����                                         */
/* ------------------------------------------------------------------------- */
#define COMM_RC_CTRL_MODE				0x01	/** ���� ����ڵ�, ����� ���� ���� �޽��� */
#define COMM_RC_CTRL_POINT				0x02	/** ���� ����ڵ�, ������ȯ�� ���� */
#define COMM_RC_CTRL_SIGNALROUTE		0x03	/** ���� ����ڵ�, (�ֽ�ȣ) ���μ��� �� ���� ���� */
#define COMM_RC_CTRL_SHUNTROUTE			0x04	/** ���� ����ڵ�, ��ȯ���� ���� �� ���� ���� */
#define COMM_RC_CTRL_BLOCK				0x05	/** ���� ����ڵ�, ��� ���� */
#define COMM_RC_CTRL_EMRTRELEASE		0x10	/** ���� ����ڵ�, �������κ������ ���� */
#define COMM_RC_CTRL_SYSRUN				0x20	/** ���� ����ڵ�, SYSTEM RUN ���� */
#define COMM_RC_CTRL_SHUNTLAMPOFF		0x30	/** ���� ����ڵ�, ��ȯ �ҵ�/���� ���� */
#define COMM_RC_CTRL_SGALLSTOP			0x40	/** ���� ����ڵ�, ��ȣ���ϰ����� ���� */
#define COMM_RC_CTRL_HEATER				0x80	/** ���� ����ڵ�, ���Ͱ��� ���� */


/* ///////////////////////////////////////////////////////////////////////// */
/* ���� ����ü ����                                                          */
/* ///////////////////////////////////////////////////////////////////////// */

/* ------------------------------------------------------------------------- */
/* EIS ���� RC �� �۽��ϴ� ������ ������ ����ü ����                         */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_RC_STATE_DATA
* @brief EIS -> RC �� �۽��ϴ� ��� �������� ������Ʈ �������� �����͸� �����ϴ� ����ü
*/
typedef struct {
	uint16 usElementID;		/* Data 0~1, ElementID*/
	uint8 ucState;			/* Data 2, state data.*/
} TS_COMM_RC_STATE_DATA;

/* ------------------------------------------------------------------------- */
/* EIS ���� RC �� �۽��ϴ� ������ ������ ����ü ����                         */
/* ------------------------------------------------------------------------- */

/**
* @struct TS_COMM_RC_DATA
* @brief EIS -> RC �� �۽��ϴ� ��� �������� ������Ʈ �������� �����͸� �����ϴ� ����ü
*/
typedef struct {
	uint8 ucData1;			/* Data 0~1, ElementID   */
	uint8 ucData2;			/* Data 0~1, ElementID   */
	uint8 ucData3;			/* Data 0~1, ElementID   */
} TS_COMM_RC_DATA;

/**
* @struct TS_COMM_RC_STATE_TRAINNO
* @brief EIS -> RC �� �۽��ϴ� ��� �������� ���� �������� �����͸� �����ϴ� ����ü
*/
typedef struct {
	uint8 ucCode;			/* Data 0, ���� �ڵ� (0x90:���� 1������, 0x91:���� 2��°����, 0x92:���� 3��°����, 0x93:����4,5��°����, 0x9e:����)	*/
	uint8 ucElementID;		/* Data 1, ElementID                */
	uint8 ucNo;				/* Data 2, ��ȣ(A,1,2,3&4,��������).     */
} TS_COMM_RC_STATE_TRAINNO;


/**
* @struct TS_COMM_RC_STATE_EVNMSG
* @brief EIS -> RC �� �۽��ϴ� ��� �������� ���� �������� �����͸� �����ϴ� ����ü
*/
typedef struct {
	uint8 ucCode;			/* Data 0, �޽��� ��ȣ.*/
	uint8 ucElementID1;		/* Data 1, ElementID #1.*/
	uint8 ucElementID2;		/* Data 2, ElementID #2.*/
} TS_COMM_RC_STATE_EVNMSG;


/**
* @struct TS_COMM_RC_CTRL_MESSAGE
* @brief EIS -> RC �� �۽��ϴ� ��� �������� ���� �������� �����͸� �����ϴ� ����ü
*/
typedef struct {
	uint8 ucCode;			/* Data 0, ����޽��� ��ȣ.*/
	uint16 usElementID;		/* Data 1!2, ElementID.*/
	uint8 ucCtrlState;		/* Data 2, ElementID #2.*/
} TS_COMM_RC_CTRL_MESSAGE;


/**
* @struct TS_COMM_RC_CTRL_MCLOCK
* @brief EIS -> RC �� �۽��ϴ� ��� �������� ������Ŭ�� �����͸� �����ϴ� ����ü
*/
typedef struct {
	uint8 ucYear;		/* Data 0:��(00 ~ 255 -->, 2000�� ~ 2255��).*/
	uint8 ucMonth;		/* Data 1:�� 1 ~ 12.*/
	uint8 ucday;			/* Data 2:�� 1 ~ 31.*/
	uint8 ucHour;		/* Data 3:�� 0 ~ 23.*/
	uint8 ucMinute;		/* Data 4:�� 0 ~ 59.*/
	uint8 ucSecond;		/* Data 5:�� 0 ~ 59.*/
} TS_COMM_RC_CTRL_MCLOCK;


/**
* @struct TS_COMM_RC_CTRL_TRAINNO
* @brief EIS -> RC �� �۽��ϴ� ��� �������� ������ȣ �������� �����͸� �����ϴ� ����ü
*/
typedef struct {
	uint8 ucTrainNo[5];		/* Data 0:������, 1~4:���ڵ�����.*/
	uint16 usElementID;		/* Data 5~6, track ElementID.*/
} TS_COMM_RC_CTRL_TRAINNO;


/* ------------------------------------------------------------------------- */
/* RC ���� EIS �� �۽��ϴ� ������ ������ ����ü ����                         */
/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */
/* RC ��� �������� �ش�(Header) ����ü ����                                 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_RC_TX_FRAME_HEADER
* @brief EIS -> RC �� �۽��ϴ� ��� �������� �ش� �����͸� �����ϴ� ����ü
*/
typedef struct {
	uint8	ucSTX;				/** 0, �޽��� �������� ����, STX */
	uint8	ucLength;			/** 1, �޽��� �������� ������ ������, blank ~ Data �ʵ�(Field)������ Byte Size (0x00 ~ 0xFF) */
	uint8	ucSequenceNo;		/** 2, �޽��� �������� ������ȣ, 0x00~ 0x7F, ACK�� ���� sequence ��ȣ�� ������ */
	uint8	ucFunctionCode;		/** 3, �޽��� �������� ����ڵ� */
	uint8	ucStationID;		/** 4, �޽��� �������� ������ �� ID */
	uint8	ucDumyBlank[7];		/** 5~11, �޽��� �������� �� ����(datetime�뵵) */
} TS_COMM_RC_TX_FRAME_HEADER;

/**
* @struct TS_COMM_RC_RX_FRAME_HEADER
* @brief RC -> EIS �� �۽��ϴ� ��� �������� �ش� �����͸� �����ϴ� ����ü
*/
typedef struct {
	uint8	ucSTX;				/** 0, �޽��� �������� ����, STX */
	uint8	ucLength;			/** 1, �޽��� �������� ������ ������, blank ~ Data �ʵ�(Field)������ Byte Size (0x00 ~ 0xFF) */
	uint8	ucSequenceNo;		/** 2, �޽��� �������� ������ȣ, 0x00~ 0x7F, ACK�� ���� sequence ��ȣ�� ������ */
	uint8	ucFunctionCode;		/** 3, �޽��� �������� ����ڵ� */
	uint8	ucStationID;		/** 4, �޽��� �������� ������ �� ID */
} TS_COMM_RC_RX_FRAME_HEADER;

/* ------------------------------------------------------------------------- */
/* RC ��� �������� ��,���� ������ ����ü ����                               */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_RC_TX_FRAME_SHORT
* @brief EIS -> RC �� �۽��ϴ� SHORT ��� �������� �����ϴ� ����ü
*/
typedef struct {
	uint8	ucSTX;				/** 0, �޽��� �������� ����, STX */
	uint8	ucLength;			/** 1, �޽��� �������� ������ ������, blank ~ Data �ʵ�(Field)������ Byte Size (0x00 ~ 0xFF) */
	uint8	ucSequenceNo;		/** 2, �޽��� �������� ������ȣ, 0x00~ 0x7F, ACK�� ���� sequence ��ȣ�� ������ */
	uint8	ucFunctionCode;		/** 3, �޽��� �������� ����ڵ� */
	uint8	ucStationID;		/** 4, �޽��� �������� ������ �� ID */
	uint8	ucDumyBlank[7];		/** 5~11, �޽��� �������� BLANK ������ */
	uint8	ucCRC[2];			/** 12~13, �޽��� �������� CRC-16 */
	uint8	ucETX;				/** 14, �޽��� �������� ��, ETX */
} TS_COMM_RC_TX_FRAME_SHORT;

/**
* @struct TS_COMM_RC_TX_FRAME_STATE
* @brief EIS -> RC �� �۽��ϴ� SHORT ��� �������� �����ϴ� ����ü
*/
#define		MAX_RC_SEND_DATA_SIZE	82U
typedef struct {
	uint8	ucSTX;				/** 0, �޽��� �������� ����, STX */
	uint8	ucLength;			/** 1, �޽��� �������� ������ ������, blank ~ Data �ʵ�(Field)������ Byte Sizev */
	uint8	ucSequenceNo;		/** 2, �޽��� �������� ������ȣ, 0x00~ 0x7F, ACK�� ���� sequence ��ȣ�� ������  */
	uint8	ucFunctionCode;		/** 3, �޽��� �������� ����ڵ� */
	uint8	ucStationID;		/** 4, �޽��� �������� ������ �� ID */
	uint8	ucDumyBlank[7];		/** 5~11, �޽��� �������� BLANK ������ */
	union{/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;�ܺ� I/F Data packet 1000 byte�̳����� �̺�Ʈ �������� �����] */
		TS_COMM_RC_DATA				tData[82];
		TS_COMM_RC_STATE_DATA		tsState[82];
		TS_COMM_RC_STATE_EVNMSG		tsEvnMsg[82];
		TS_COMM_RC_STATE_TRAINNO	tsTrainNo[82];
	} D;
} TS_COMM_RC_TX_FRAME_STATE;

/**
* @struct TS_COMM_RC_TX_FRAME_BSCAN
* @brief EIS -> RC �� �۽��ϴ� BASESCAN ��� �������� �����ϴ� ����ü
*/
#define		MAX_RC_SEND_BSCANDATA_SIZE	242U
typedef struct {
	uint8	ucSTX;				/** 0, �޽��� �������� ����, STX */
	uint8	ucLength;			/** 1, �޽��� �������� ������ ������, blank ~ Data �ʵ�(Field)������ Byte Size (0x00 ~ 0xFF) */
	uint8	ucSequenceNo;		/** 2, �޽��� �������� ������ȣ, 0x00~ 0x7F, ACK�� ���� sequence ��ȣ�� ������  */
	uint8	ucFunctionCode;		/** 3, �޽��� �������� ����ڵ� */
	uint8	ucStationID;		/** 4, �޽��� �������� ������ �� ID */
	uint8	ucDumyBlank[7];		/** 5~11, �޽��� �������� BLANK ������ */
	uint16	usElementID1;		/** 12~13, ���� element ID */
	uint16	usElementID2;		/** 14~15, ������ element ID */
	uint8    ucState[242];		/** 16~257, �������� ���̺� */
} TS_COMM_RC_TX_FRAME_BSCAN;

/**
* @struct TS_COMM_RC_RX_FRAME_SHORT
* @brief RC -> EIS �� �۽��ϴ� SHORT ��� �������� �����ϴ� ����ü
*/
typedef struct {
	uint8	ucSTX;				/** 0, �޽��� �������� ����, STX */
	uint8	ucLength;			/** 1, �޽��� �������� ������ ������, Data �ʵ�(Field)������ Byte Size (0x00 ~ 0xFF) */
	uint8	ucSequenceNo;		/** 2, �޽��� �������� ������ȣ, 0x00~ 0x7F, ACK�� ���� sequence ��ȣ�� ������  */
	uint8	ucFunctionCode;		/** 3, �޽��� �������� ����ڵ� */
	uint8	ucStationID;		/** 4, �޽��� �������� ������ �� ID */
	uint8	ucCRC[2];			/** 5~6, �޽��� �������� */
	uint8	ucETX;				/** 7, �޽��� �������� ��, ETX */
} TS_COMM_RC_RX_FRAME_SHORT;

/**
* @struct TS_COMM_RC_RX_FRAME_CTRLCMD
* @brief RC -> EIS �� �۽��ϴ� ������ ��� �������� �����ϴ� ����ü
*/
typedef struct {
	uint8	ucSTX;				/** 0, �޽��� �������� ����, STX */
	uint8	ucLength;			/** 1, �޽��� �������� ������ ������, Data �ʵ�(Field)������ Byte Size (0x00 ~ 0xFF) */
	uint8	ucSequenceNo;		/** 2, �޽��� �������� ������ȣ, 0x00~ 0x7F, ACK�� ���� sequence ��ȣ�� ������ */
	uint8	ucFunctionCode;		/** 3, �޽��� �������� ����ڵ� */
	uint8	ucStationID;		/** 4, �޽��� �������� ������ �� ID */
	TS_COMM_RC_CTRL_MESSAGE tsCtrlMsg;	/** 5~8, �޽��� �������� ���� ������ */
	uint8	ucCRC[2];			/** 9~10, �޽��� �������� CRC-16 */
	uint8	ucETX;				/** 11, �޽��� �������� ��, ETX */
} TS_COMM_RC_RX_FRAME_CTRLCMD;

/**
* @struct TS_COMM_RC_RX_FRAME_MCLOCK
* @brief RC -> EIS �� �۽��ϴ� ������Ŭ�� ��� �������� �����ϴ� ����ü
*/
typedef struct {
	uint8	ucSTX;				/** 0, �޽��� �������� ����, STX */
	uint8	ucLength;			/** 1, �޽��� �������� ������ ������, Data �ʵ�(Field)������ Byte Size (0x00 ~ 0xFF) */
	uint8	ucSequenceNo;		/** 2, �޽��� �������� ������ȣ, 0x00~ 0x7F, ACK�� ���� sequence ��ȣ�� ������ */
	uint8	ucFunctionCode;		/** 3, �޽��� �������� ����ڵ� */
	uint8	ucStationID;		/** 4, �޽��� �������� ������ �� ID */
	uint8	ucData[6];			/** 5~10, �޽��� �������� ���� ������ */
	uint8	ucCRC[2];			/** 11~12, �޽��� �������� CRC-16 */
	uint8	ucETX;				/** 13, �޽��� �������� ��, ETX */
} TS_COMM_RC_RX_FRAME_MCLOCK;

/**
* @struct TS_COMM_RC_RX_FRAME_TRAINNO
* @brief RC -> EIS �� �۽��ϴ� ������Ŭ�� ��� �������� �����ϴ� ����ü
*/
typedef struct {
	uint8	ucSTX;				/** 0, �޽��� �������� ����, STX */
	uint8	ucLength;			/** 1, �޽��� �������� ������ ������, Data �ʵ�(Field)������ Byte Size (0x00 ~ 0xFF) */
	uint8	ucSequenceNo;		/** 2, �޽��� �������� ������ȣ, 0x00~ 0x7F, ACK�� ���� sequence ��ȣ�� ������ */
	uint8	ucFunctionCode;		/** 3, �޽��� �������� ����ڵ� */
	uint8	ucStationID;		/** 4, �޽��� �������� ������ �� ID */
	TS_COMM_RC_CTRL_TRAINNO tsTrainNo;		/** 5~11, �޽��� �������� ���� ������ */
	uint8	ucCRC[2];			/** 12~13, �޽��� �������� CRC-16 */
	uint8	ucETX;				/** 14, �޽��� �������� ��, ETX */
} TS_COMM_RC_RX_FRAME_TRAINNO;

/**
* @struct TS_COMM_RC_RX_FRAME_BSCAN
* @brief RC -> EIS �� �۽��ϴ� ���̽���ĵ ��� �������� �����ϴ� ����ü
*/
typedef struct {
	uint8	ucSTX;				/** 0, �޽��� �������� ����, STX */
	uint8	ucLength;			/** 1, �޽��� �������� ������ ������, Data �ʵ�(Field)������ Byte Size (0x00 ~ 0xFF) */
	uint8	ucSequenceNo;		/** 2, �޽��� �������� ������ȣ, 0x00~ 0x7F, ACK�� ���� sequence ��ȣ�� ������ */
	uint8	ucFunctionCode;		/** 3, �޽��� �������� ����ڵ� */
	uint8	ucStationID;		/** 4, �޽��� �������� ������ �� ID */
	uint16	usStartID;			/** 5~6, ���� element ID */
	uint16	usEndID;			/** 7~8, ������ element ID */
	uint8	ucCRC[2];			/** 9~10, �޽��� �������� CRC-16 */
	uint8	ucETX;				/** 11, �޽��� �������� ��, ETX */
} TS_COMM_RC_RX_FRAME_BSCAN;


/* ------------------------------------------------------------------------- */
/* RC ��� �������� ��,���� ������ ���� ����ü ����                          */
/* ------------------------------------------------------------------------- */
/**
* @struct TU_COMM_RC_TX_FRAME
* @brief EIS -> RC �� �۽��ϴ� ��ü ��� �������� �����ϴ� ����ü
*/
typedef union {/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;�ܺ� I/F Data packet 1000 byte�̳����� �̺�Ʈ �������� �����] */
	uint8	aucBuff[264];					/** 0, �޽��� �������� ���� */
	TS_COMM_RC_TX_FRAME_SHORT	tsShort;	/* short frame*/
	TS_COMM_RC_TX_FRAME_STATE	tsState;	/* state frame*/
	TS_COMM_RC_TX_FRAME_BSCAN	tsBScan;	/* basescan frame*/
} TU_COMM_RC_TX_FRAME;

/**
* @struct TU_COMM_RC_RX_FRAME
* @brief RC EIS -> �� �۽��ϴ� ��ü ��� �������� �����ϴ� ����ü
*/
typedef union {/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;�ܺ� I/F Data packet 1000 byte�̳����� �̺�Ʈ �������� �����] */
	uint8	aucBuff[20];		/** 0, �޽��� �������� ���� */
	TS_COMM_RC_RX_FRAME_SHORT	tsShort;	/* short frame*/
	TS_COMM_RC_RX_FRAME_CTRLCMD	tsCtrlCmd;	/* control command frame*/
	TS_COMM_RC_RX_FRAME_MCLOCK	tsMClock;	/* master clock frame*/
	TS_COMM_RC_RX_FRAME_TRAINNO	tsTrainNo;	/* train no control frame */
	TS_COMM_RC_RX_FRAME_BSCAN	tsBScanReq;	/* basescan request frame */
} TU_COMM_RC_RX_FRAME;

/* ------------------------------------------------------------------------- */

#endif /* #ifndef _DEFCOMMRC_H_ */
