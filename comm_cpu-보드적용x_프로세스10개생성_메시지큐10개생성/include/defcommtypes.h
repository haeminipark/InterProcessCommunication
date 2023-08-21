/* =========================================================================================
2018.04.16
@1.4f2- [LOCAL�ִ�޼�������] �޼��� ������ �ִ� �� ������ ���� ���̽���ĵ �ִ� �� �� ����
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
* @date 2015-07-25
* @brief version 1.0 ������ History.
* @brief 1. header file ���ʻ���(by JeongYJ)
*/

/* ///////////////////////////////////////////////////////////////////////// */
/* Include Files                                                             */
/* ///////////////////////////////////////////////////////////////////////// */

#include	"defopcode.h"
#include	"defeventmsg.h"
#include	"crc_app.h"
#pragma pack(1)

/* ///////////////////////////////////////////////////////////////////////// */
/* ���������ڵ�/Constant/��������/�������ڿ��� ����(�Ǵ� ����)               */
/* ///////////////////////////////////////////////////////////////////////// */
 
/* ------------------------------------------------------------------------- */
/* ��ſ� ��ġ�� ID ����                                                     */
/* ------------------------------------------------------------------------- */
/* Only ZEST EIS */
#define  DEF_ID_IOS_01_A			0x21	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 01, �������� I/O �� 1�� #01 */
#define  DEF_ID_IOS_01_B			0x41	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 01, �������� I/O �� 2�� #01 */
#define  DEF_ID_IOS_02_A			0x22	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 02, �������� I/O �� 1�� #01 */
#define  DEF_ID_IOS_02_B			0x42	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 02, �������� I/O �� 2�� #01 */
#define  DEF_ID_IOS_03_A			0x23	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 03, �������� I/O �� 1�� #01 */
#define  DEF_ID_IOS_03_B			0x43	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 03, �������� I/O �� 2�� #01 */
#define  DEF_ID_IOS_04_A			0x24	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 04, �������� I/O �� 1�� #01 */
#define  DEF_ID_IOS_04_B			0x44	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 04, �������� I/O �� 2�� #01 */
#define  DEF_ID_IOS_05_A			0x25	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 05, �������� I/O �� 1�� #01 */
#define  DEF_ID_IOS_05_B			0x45	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 05, �������� I/O �� 2�� #01 */
#define  DEF_ID_IOS_06_A			0x26	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 06, �������� I/O �� 1�� #01 */
#define  DEF_ID_IOS_06_B			0x46	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 06, �������� I/O �� 2�� #01 */
#define  DEF_ID_IOS_07_A			0x27	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 07, �������� I/O �� 1�� #01 */
#define  DEF_ID_IOS_07_B			0x47	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 07, �������� I/O �� 2�� #01 */
#define  DEF_ID_IOS_08_A			0x28	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 08, �������� I/O �� 1�� #01 */
#define  DEF_ID_IOS_08_B			0x48	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 08, �������� I/O �� 2�� #01 */
#define  DEF_ID_IOS_09_A			0x29	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 09, �������� I/O �� 1�� #01 */
#define  DEF_ID_IOS_09_B			0x49	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 09, �������� I/O �� 2�� #01 */
#define  DEF_ID_IOS_10_A			0x2A	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 10, �������� I/O �� 1�� #01 */
#define  DEF_ID_IOS_10_B			0x4A	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 10, �������� I/O �� 2�� #01 */
#define  DEF_ID_IOS_11_A			0x2B	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 11, �������� I/O �� 1�� #01 */
#define  DEF_ID_IOS_11_B			0x4B	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 11, �������� I/O �� 2�� #01 */
#define  DEF_ID_IOS_12_A			0x2C	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 12, �������� I/O �� 1�� #01 */
#define  DEF_ID_IOS_12_B			0x4C	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 12, �������� I/O �� 2�� #01 */
#define  DEF_ID_IOS_13_A			0x2D	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 13, �������� I/O �� 1�� #01 */
#define  DEF_ID_IOS_13_B			0x4D	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 13, �������� I/O �� 2�� #01 */
#define  DEF_ID_IOS_14_A			0x2E	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 14, �������� I/O �� 1�� #01 */
#define  DEF_ID_IOS_14_B			0x4E	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 14, �������� I/O �� 2�� #01 */
#define  DEF_ID_IOS_15_A			0x2F	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 15, �������� I/O �� 1�� #01 */
#define  DEF_ID_IOS_15_B			0x4F	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 15, �������� I/O �� 2�� #01 */
#define  DEF_ID_IOS_16_A			0x30	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 16, �������� I/O �� 1�� #01 */
#define  DEF_ID_IOS_16_B			0x50	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 16, �������� I/O �� 2�� #01 */
#define  DEF_ID_IOS_17_A			0x31	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 17, �������� I/O �� 1�� #01 */
#define  DEF_ID_IOS_17_B			0x51	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 17, �������� I/O �� 2�� #01 */
#define  DEF_ID_IOS_18_A			0x32	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 18, �������� I/O �� 1�� #01 */
#define  DEF_ID_IOS_18_B			0x52	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 18, �������� I/O �� 2�� #01 */
#define  DEF_ID_IOS_19_A			0x33	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 19, �������� I/O �� 1�� #01 */
#define  DEF_ID_IOS_19_B			0x53	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 19, �������� I/O �� 2�� #01 */
#define  DEF_ID_IOS_20_A			0x34	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 20, �������� I/O �� 1�� #01 */
#define  DEF_ID_IOS_20_B			0x54	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 20, �������� I/O �� 2�� #01 */
#define  DEF_ID_IOS_21_A			0x35	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 21, �������� I/O �� 1�� #01 */
#define  DEF_ID_IOS_21_B			0x55	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 21, �������� I/O �� 2�� #01 */
#define  DEF_ID_IOS_22_A			0x36	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 22, �������� I/O �� 1�� #01 */
#define  DEF_ID_IOS_22_B			0x56	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 22, �������� I/O �� 2�� #01 */
#define  DEF_ID_IOS_23_A			0x37	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 23, �������� I/O �� 1�� #01 */
#define  DEF_ID_IOS_23_B			0x57	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 23, �������� I/O �� 2�� #01 */
#define  DEF_ID_IOS_24_A			0x38	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 24, �������� I/O �� 1�� #01 */
#define  DEF_ID_IOS_24_B			0x58	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 24, �������� I/O �� 2�� #01 */
#define  DEF_ID_IOS_25_A			0x39	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 25, �������� I/O �� 1�� #01 */
#define  DEF_ID_IOS_25_B			0x59	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 25, �������� I/O �� 2�� #01 */
/* Common EIS */
#define  DEF_ID_ILS					0x1AU	/** (BIT5~6)GROUPID 0, (BIT0~4)UNITID 26, �������� */
#define  DEF_ID_ILS_1A				0x3AU	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 26, �������� 1��_A */
#define  DEF_ID_ILS_1B				0xBAU	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 26, �������� 1��_B */
#define  DEF_ID_ILS_2A				0x5AU	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 26, �������� 2��_A */
#define  DEF_ID_ILS_2B				0xDAU	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 26, �������� 2��_B */
#define  DEF_ID_OPC					0x1BU	/** (BIT5~6)GROUPID 0, (BIT0~4)UNITID 27, OPC */
#define  DEF_ID_OPC_A				0x3BU	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 27, OPC 1�� */
#define  DEF_ID_OPC_B				0x5BU	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 27, OPC 2�� */
#define  DEF_ID_MTC					0x1CU	/** (BIT5~6)GROUPID 0, (BIT0~4)UNITID 28, ���������� MTC */
#define  DEF_ID_LDTS				0x00U	/** (BIT5~6)GROUPID 0, (BIT0~4)UNITID  0, LDTS */
#define  DEF_ID_LDTS_A				0x20U	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID  0, LDTS 1�� */
#define  DEF_ID_LDTS_B				0x40U	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID  0, LDTS 2�� */
#define  DEF_ID_RC					0x1DU	/** (BIT5~6)GROUPID 0, (BIT0~4)UNITID 29, ��������� */
#define  DEF_ID_RC_A				0x3DU	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 29, ��������� 1�� */
#define  DEF_ID_RC_B				0x5DU	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 29, ��������� 2�� */
#define  DEF_ID_EXM					0x1FU	/** (BIT5~6)GROUPID 0, (BIT0~4)UNITID 31, ü��ǥ�ù� TPC */
#define  DEF_ID_IF					0x1FU	/** (BIT5~6)GROUPID 0, (BIT0~4)UNITID 31, �谣 INTERFACE ���ī�� */
#define  DEF_ID_IF_A				0x3F	/** (BIT5~6)GROUPID 1, (BIT0~4)UNITID 31, 1�� INTERFACE ���ī�� */
#define  DEF_ID_IF_B				0x5F	/** (BIT5~6)GROUPID 2, (BIT0~4)UNITID 31, 2�� INTERFACE ���ī�� */
#define  DEF_ID_SIMC				0x7F	/** (BIT5~6)GROUPID 3, (BIT0~4)UNITID 31, �ùķ�������ġ SIMC */
/* ------------------------------------------------------------------------- */
/*#define  DEF_ID_PORTCOM1			0x00*/	/** (Bit7) UINT �� ��� ��Ʈ �����ڵ�, 0:COM1, 1:COM2 */
#define  DEF_ID_PORTCOM2			0x80	/** (Bit7) UINT �� ��� ��Ʈ �����ڵ�, 0:COM1, 1:COM2 */
/* ------------------------------------------------------------------------- */
#define  DEF_UNIT_IDMASK			0x1F	/** (Bit0~Bit4)��ſ� ��ġ�� ID �ڵ忡 ���� Mask bit �� */
#define  DEF_ID_GROUPMASK			0x60	/** (Bit5~Bit6)��ſ� ��ġ�� GROUP �ڵ忡 ���� Mask bit �� */
#define  DEF_PORT_IDMASK			0x9F	/** (Bit0~Bit4)�����Ʈ�� ������ ��ſ� ��ġ�� ID �ڵ忡 ���� Mask bit �� */

/* ------------------------------------------------------------------------- */
/* MMI ��� ������ �ڵ� ����                                                 */
/* ------------------------------------------------------------------------- */
#define COMM_MMI_STX					0x02	/** STX of the MMI frame */
#define COMM_MMI_ETX					0x03	/** ETX of the MMI frame */
#define COMM_MMI_DLE					0x80	/** DLE of the MMI frame */
#define COMM_MMI_DLE_STX				0x82	/** DLE�� ó���� STX �ڵ� */
#define COMM_MMI_DLE_ETX				0x83	/** DLE�� ó���� ETX �ڵ� */

/* ------------------------------------------------------------------------- */
/* ��� ������ ���� ������ ����                                              */
/* ------------------------------------------------------------------------- */
#define LIMIT_CNT_MMI_STD_COMMFRAME		  90U	/** ��/���� �޽����� �����ϱ� ���� ������ �ִ� ũ�� */
#define LIMIT_CNT_MMI_STD_COMMWRITE		 170U	/** ��/���� �޽����� �����ϱ� ���� ������ �ִ� ũ�� */
#define LIMIT_CNT_MMI_EXT_COMMFRAME		1000U	/** ��/���� �޽����� �����ϱ� ���� ������ �ִ� ũ�� */
#define LIMIT_CNT_MMI_EXT_COMMWRITE		1980U	/** �����ι���(DLE ����)�� ���� ó���� �۽ŵ����͸� �����ϴ� �۽Ź����� �ִ� ũ�� */

/* ------------------------------------------------------------------------- */
/* MMI ��� ������ ����ڵ� ����                                             */
/* ------------------------------------------------------------------------- */
#define COMM_MMI_FUNC_INITIALPOLLING	0x10U	/** �ʱ�����(Initial Polling) �޽��� */
#define COMM_MMI_FUNC_INITIALRESPONSE	0x11U	/** �ʱ�����(Initial Response) �޽��� */
#define COMM_MMI_FUNC_POLLING			0x20U	/** ����(Polling) �޽��� */
#define COMM_MMI_FUNC_POLLINGRESPONSE	0x21U	/** ��������(Polling Response) �޽��� */
#define COMM_MMI_FUNC_CONTROL			0x30U	/** ����(Control) �޽��� */
#define COMM_MMI_FUNC_ACK				0x31U	/** Acknowledge �޽��� */
#define COMM_MMI_FUNC_EMCONTROL			0x32U	/** ��� ����(Control) �޽��� */
#define COMM_MMI_FUNC_MASTERCLOCK		0x40U	/** Master Clock ���� �޽��� */
#define COMM_MMI_FUNC_NACK				0x41U	/** Negative Acknowledge �޽��� */
#define COMM_MMI_FUNC_USERLABEL			0x42U	/** ����� ��� ǥ�� �޽��� ����/���� */
#define COMM_MMI_FUNC_TRAINNUMBER		0x50U	/** ������ȣ(Train Number) ���� �޽��� */
#define COMM_MMI_FUNC_BASESCANREQ		0x60U	/** Basescan �䱸 �޽��� */
#define COMM_MMI_FUNC_ROM_UPLOAD		0xA0U	/** ROM data�� upload �䱸 �޽��� */
#define COMM_MMI_FUNC_ROM_UPLOADING		0xA1U	/** ROM data�� uploading DB �޽��� */
#define COMM_MMI_FUNC_ROM_DOWNLOAD		0xB0U	/** ROM data�� download �䱸 �޽��� */
#define COMM_MMI_FUNC_ROM_DOWNLOADING	0xB1U	/** ROM data�� downloading DB �޽��� */
#define COMM_MMI_FUNC_LINK				0xF0U	/** LINK �޽��� */

/* ------------------------------------------------------------------------- */
/* MMI ��� ������ ����ڵ� ����                                             */
/* ------------------------------------------------------------------------- */
#define COMM_MMI_DATA_TYPE_STATE		0x10	/** �۽ſ� ť�� ���ԵǴ� Element ���º�ȭ���� �����ͺ��� Ÿ�� ���� �� */
#define COMM_MMI_DATA_TYPE_EVENT		0x20	/** �۽ſ� ť�� ���ԵǴ� �̺�Ʈ ���� �����ͺ��� Ÿ�� ���� �� */
#define COMM_MMI_DATA_TYPE_BASESCAN		0x30	/** �۽ſ� ť�� ���ԵǴ� BASESCAN ���� �����ͺ��� Ÿ�� ���� �� */
#define COMM_MMI_DATA_TYPE_NEWBASESCAN	0x31	/** �۽ſ� ť�� ���ԵǴ� REAL TYPE BASESCAN ���� �����ͺ��� Ÿ�� ���� �� */
#define COMM_MMI_DATA_TYPE_TRNOSTATE	0x40	/** �۽ſ� ť�� ���ԵǴ� ������ȣ ���º�ȭ ���� �����ͺ��� Ÿ�� ���� �� */
#define COMM_MMI_DATA_TYPE_TRNOBASESCAN	0x50	/** �۽ſ� ť�� ���ԵǴ� ������ȣ BASESCAN ���� �����ͺ��� Ÿ�� ���� �� */
#define COMM_MMI_DATA_TYPE_INITRESPONSE	0xF0	/** �۽ſ� ť�� ���ԵǴ� �ʱ��������� �����ͺ��� Ÿ�� ���� �� */


/* ------------------------------------------------------------------------- */
/* ���� �� �⺻���� Data ���� (EisDefine.h �� ���ǵǾ� ����)                 */
/* ------------------------------------------------------------------------- */
#ifndef SIZE_ILDB_VERSION
#define SIZE_ILDB_VERSION			18U		/** ILDB Version data size       */
#endif //


/* ///////////////////////////////////////////////////////////////////////// */
/* ���� ����ü ����                                                          */
/* ///////////////////////////////////////////////////////////////////////// */

/* ------------------------------------------------------------------------- */
/* MMI ��� �������� �ش�(Header) ����ü ����                                */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_FRAME_HEADER
* @brief ��� �������� �ش� �����͸� �����ϴ� ����ü
*/
typedef struct {
	uint8	ucSenderID;			/** 1, �޽��� �������� �߽��� ID */
	uint8	ucReceiverID;		/** 2, �޽��� �������� ������ ID */
	uint8	ucSequenceNo;		/** 3, �޽��� �������� ������ȣ, 0x04~ox7F, ��, Initial Polling �޽����� 0x00  */
	uint8	ucFunctionCode;		/** 4, �޽��� �������� ����ڵ� */
	uint16	usLength;			/** 5~6, �޽��� �������� ������ ������, �߽��� ID ���� CRC �ʵ�(Field) ������ ������ �ʵ�(Field)������ Byte Size */
} TS_COMM_MMI_FRAME_HEADER;

/* ------------------------------------------------------------------------- */
/* ������ �ʵ尡 ���� ��ɹ�ȣ���� ������ MMI �޽��� �⺻ �������� ����ü ���� */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_SHORT_MSG_FRAME
* @brief ������ �ʵ尡 ���� ��ɹ�ȣ���� ������ �޽��� �⺻ �������� ����ü
*/
typedef struct {
	uint8 ucSTX;								/** 0, �޽��� �������� ���� ����, STX=0x02 ������ */
	TS_COMM_MMI_FRAME_HEADER	tHeader;	/** 1~6, �޽��� �������� �ش� ������ */
	TS_CRC32_DATA				tCRC32;		/** 7~10, �޽��� �������� CRC32 */
	uint8 ucETX;								/** 11, �޽��� �������� ���� ����, ETX=0x03 ������ */
} TS_COMM_MMI_SHORT_MSG_FRAME;

typedef struct {
	uint8 	ucSTX;				/** 0, �޽��� �������� ���� ����, STX=0x02 ������ */
	uint8	ucSenderID;			/** 1, �޽��� �������� �߽��� ID */
	uint8	ucReceiverID;		/** 2, �޽��� �������� ������ ID */
	uint8	ucSequenceNo;		/** 3, �޽��� �������� ������ȣ, 0x04~ox7F, ��, Initial Polling �޽����� 0x00  */
	uint8	ucFunctionCode;		/** 4, �޽��� �������� ����ڵ� */
	uint16	usLength;			/** 5~6, �޽��� �������� ������ ������, �߽��� ID ���� CRC �ʵ�(Field) ������ ������ �ʵ�(Field)������ Byte Size */		
	uint8	ucCRC32[4];		/** data low => uchCRC32[0], data high => uchCRC32[3] */	
	uint8 	ucETX;				/** 11, �޽��� �������� ���� ����, ETX=0x03 ������ */
} COMM_SHORT_MSG_FRAME;

/* ------------------------------------------------------------------------- */
/* MMI ���� ILS �� �۽��ϴ� �޽��� ������ ����ü ����                        */
/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */
/* Element ���� �޽��� �������� ����ü ����                                  */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_ELM_CTRL_MSG_FRAME
* @brief Element ���� �޽��� �������� ����ü
*/
typedef struct {
	uint8 ucSTX;									/** 0, �޽��� �������� ���� ����, STX=0x02 ������ */
	TS_COMM_MMI_FRAME_HEADER	tHeader;			/** 1~6, �޽��� �������� �ش� ������ */
	TS_ELM_CTRL_REQ_DATA		tCtrlData;			/** 7~10, �޽��� �������� Element ���� ������ �����ϴ� ������ �ʵ� */
	TS_CRC32_DATA				tCRC32;				/** 11~14, �޽��� �������� CRC32 */
	uint8 ucETX;									/** 15, �޽��� �������� ���� ����, ETX=0x03 ������ */
} TS_COMM_MMI_ELM_CTRL_MSG_FRAME;

/* ------------------------------------------------------------------------- */
/* ��� ���� �޽��� �������� ����ü ����                                      */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_MMI_EM_ELM_CTRL_MSG_FRAME
* @brief Element ���� �޽��� �������� ����ü
*/
typedef struct {
	uint8 ucSTX;									/** 0, �޽��� �������� ���� ����, STX=0x02 ������ */
	TS_COMM_MMI_FRAME_HEADER	tHeader;		/** 1~6, �޽��� �������� �ش� ������ */
	TS_EM_ELM_CTRL_REQ_DATA		tEmCtrlData;	/** 7~80, �޽��� �������� Element ���� ������ �����ϴ� ������ �ʵ� */
	TS_CRC32_DATA				tCRC32;			/** 81~84, �޽��� �������� CRC32 */
	uint8 ucETX;									/** 85, �޽��� �������� ���� ����, ETX=0x03 ������ */
} TS_COMM_MMI_EM_ELM_CTRL_MSG_FRAME;

/* ------------------------------------------------------------------------- */
/* MMI�� ����ڵ�� ǥ�� ���� �޽��� �������� ����ü ����                    */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_MMI_USERLABEL_MSG_FRAME
* @brief ����ڵ�� ǥ�� ���� �޽��� �������� ����ü
*/
typedef struct {
	uint8 ucSTX;									/** 0, �޽��� �������� ���� ����, STX=0x02 ������ */
	TS_COMM_MMI_FRAME_HEADER	tHeader;		/** 1~6, �޽��� �������� �ش� ������ */
	TS_MSG_USER_TEXT_DATA		tUserTextData;	/** 7~33, LABEL ���� ���� 20�� */
	TS_CRC32_DATA				tCRC32;			/** 34~37, �޽��� �������� CRC32 */
	uint8 ucETX;									/** 38, �޽��� �������� ���� ����, ETX=0x03 ������ */
} TS_COMM_MMI_USERLABEL_MSG_FRAME;

/* ------------------------------------------------------------------------- */
/* MMI�� ������Ŭ�� ���� �޽��� �������� ����ü ����                         */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_MASTERE_CLOCK_MSG_FRAME
* @brief ������Ŭ�� ���� �޽��� �������� ����ü
*/
typedef struct {
	uint8 ucSTX;								/** 0, �޽��� �������� ���� ����, STX=0x02 ������ */
	TS_COMM_MMI_FRAME_HEADER	tHeader;	/** 1~6, �޽��� �������� �ش� ������ */
	TS_MSG_MASTER_CLOCK_DATA	tClcokData;	/** 7~12, �޽��� �������� ������Ŭ�� ������ �����ϴ� ������ �ʵ� */
	TS_CRC32_DATA				tCRC32;		/** 13~16, �޽��� �������� CRC32 */
	uint8 ucETX;								/** 17, �޽��� �������� ���� ����, ETX=0x03 ������ */
} TS_COMM_MMI_MASTERE_CLOCK_MSG_FRAME;

/* ------------------------------------------------------------------------- */
/* MMI�� ������ȣ ���� �޽��� �������� ����ü ����                           */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_TRNO_SET_MSG_FRAME 
* @brief ������ȣ ���� �޽��� �������� ����ü
*/
typedef struct {
	uint8  ucSTX;							/** 0, �޽��� �������� ���� ����, STX=0x02 ������ */
	TS_COMM_MMI_FRAME_HEADER	tHeader;	/** 1~6, �޽��� �������� �ش� ������ */
	TS_MSG_TRNO_SET_DATA		tTNSetData;	/** 7~13, �޽��� �������� ������ȣ ���� �����͸� �����ϴ� ������ �ʵ� */
	TS_CRC32_DATA				tCRC32;		/** 14~17, �޽��� �������� CRC32 */
	uint8  ucETX;							/** 18, �޽��� �������� ���� ����, ETX=0x03 ������ */
} TS_COMM_MMI_TRNO_SET_MSG_FRAME;

/**
* @struct TS_COMM_TRNO_ALT_MSG_FRAME
* @brief ������ȣ ���� �޽��� �������� ����ü
*/
typedef struct {
	uint8  ucSTX;							/** 0, �޽��� �������� ���� ����, STX=0x02 ������ */
	TS_COMM_MMI_FRAME_HEADER	tHeader;	/** 1~6, �޽��� �������� �ش� ������ */
	TS_MSG_TRNO_ALT_DATA		tTNAltData;	/** 7~17, �޽��� �������� ������ȣ ���� �����͸� �����ϴ� ������ �ʵ� */
	TS_CRC32_DATA				tCRC32;		/** 18~21, �޽��� �������� CRC32 */
	uint8  ucETX;							/** 22, �޽��� �������� ���� ����, ETX=0x03 ������ */
} TS_COMM_MMI_TRNO_ALT_MSG_FRAME;

/**
* @struct TS_COMM_TRNO_DEL_MSG_FRAME
* @brief ������ȣ ���� �޽��� �������� ����ü
*/
typedef struct {
	uint8  ucSTX;							/** 0, �޽��� �������� ���� ����, STX=0x02 ������ */
	TS_COMM_MMI_FRAME_HEADER	tHeader;	/** 1~6, �޽��� �������� �ش� ������ */
	TS_MSG_TRNO_DEL_DATA		tTNDelData;	/** 7~12, �޽��� �������� ������ȣ ���� �����͸� �����ϴ� ������ �ʵ� */
	TS_CRC32_DATA				tCRC32;		/** 13~16, �޽��� �������� CRC32 */
	uint8 ucETX;								/** 17, �޽��� �������� ���� ����, ETX=0x03 ������ */
} TS_COMM_MMI_TRNO_DEL_MSG_FRAME;

/**
* @struct TS_COMM_TRNO_XCH_MSG_FRAME
* @brief ������ȣ ��ȯ �޽��� �������� ����ü
*/
typedef struct {
	uint8  ucSTX;							/** 0, �޽��� �������� ���� ����, STX=0x02 ������ */
	TS_COMM_MMI_FRAME_HEADER	tHeader;	/** 1~6, �޽��� �������� �ش� ������ */
	TS_MSG_TRNO_XCH_DATA		tTNXchData;	/** 7~17, �޽��� �������� ������ȣ ��ȯ �����͸� �����ϴ� ������ �ʵ� */
	TS_CRC32_DATA				tCRC32;		/** 18~21, �޽��� �������� CRC32 */
	uint8 ucETX;								/** 22, �޽��� �������� ���� ����, ETX=0x03 ������ */
} TS_COMM_MMI_TRNO_XCH_MSG_FRAME;


/**
* @struct TU_COMM_MMI_STD_MSG_FRAME
* @brief MMI ���� �۽��ϴ� �޽��� �������� ����ü
*/
typedef union {/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;�ܺ� I/F Data packet 1000 byte�̳����� �̺�Ʈ �������� �����] */
	uint8 aucMsgFrame[LIMIT_CNT_MMI_STD_COMMFRAME];	/** ��/���� �޽��� �������� �����Ͱ� ��� ���� */
	TS_COMM_MMI_SHORT_MSG_FRAME		tShortMsg;		/** �����͸� �������� �ʴ� �޽���(ACK, NACK, �ʱ�����, Basescan �䱸, LINK) */
	TS_COMM_MMI_ELM_CTRL_MSG_FRAME	tElmCtrlMsg;	/** 16.Element ���� �޽��� */
	TS_COMM_MMI_EM_ELM_CTRL_MSG_FRAME	tEmElmCtrlMsg;	/** 86.��� ���� �޽��� */
	TS_COMM_MMI_MASTERE_CLOCK_MSG_FRAME	tMClockMsg;	/** 18.������Ŭ��(Master Clock) ���� ������ */
	TS_COMM_MMI_TRNO_SET_MSG_FRAME	tTrNoSetMsg;	/** 19.������ȣ ���� �޽��� */
	TS_COMM_MMI_TRNO_ALT_MSG_FRAME	tTrNoAltMsg;	/** 23.������ȣ ���� �޽��� */
	TS_COMM_MMI_TRNO_DEL_MSG_FRAME	tTrNoDelMsg;	/** 18.������ȣ ���� �޽��� */
	TS_COMM_MMI_TRNO_XCH_MSG_FRAME	tTrNoXchMsg;	/** 23.������ȣ ��ȯ �޽��� */
} TU_COMM_MMI_STD_MSG_FRAME;


/* ------------------------------------------------------------------------- */
/* ILS ���� MMI �� �۽��ϴ� �޽��� ������ ����ü ����                        */
/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */
/* �ʱ�����(Initial response) �޽����� ������ �ʵ� ����ü ����                */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_INITIAL_RESPONSE_DATA
* @brief Polling ������� �۽� Que�� ����Ǵ� �޽������� ���� �����ͺ� ����ü
*/
typedef struct {
	uint8 ucDataType;			/** 0, �޽����� �������� Ÿ��, 0x10:���º�ȭ���� ������, 0x20:�̺�Ʈ�޽��� ������, 0x30:Basescan �������� ������, 0x40:������ȣ ���º�ȭ ������, 0x50: Basescan ������ȣ ������, 0xF0: Initial polling ������ */
	uint16 usLength;				/** 1-2, �޽������� �� ������ ����, ������ Ÿ�Ժ��� ������ �����ͱ����� uint8 SIZE ���� */
	uint8 ucYear;				/** 3 �޽������� ���� �⵵, 0 ~ 255(2000�� ~ 2255��) */
	uint8 ucMonth;				/** 4, �޽������� ���� ��, 1 ~ 12(��) */
	uint8 ucDay;					/** 5, �޽������� ���� ��, 1 ~ 31(��) */
	uint8 ucHour;				/** 6, �޽������� ���� �ð�, 0 ~ 23(��) */
	uint8 ucMinute;				/** 7, �޽������� ���� ��, 0 ~ 59(��) */
	uint8 ucSecond;				/** 8, �޽������� ���� ��, 0 ~ 59(��) */
	uint8 uc10msec;				/** 9, �޽������� ���� 1/100��, 0 ~ 99(10ms~990ms) */
	uint16 usElmTH_COMMON_CNT;	/** 10~11, �� ��������(ELM_COMMON) table �� �ǻ�� ���� (��ü 32��) */
	uint16 usElmTH_TR_GI_CNT;		/** 12~13, �˵�ȸ�� �Ϲ�����(ELM_TRACK_GI) table �� �ǻ�� ���� (��ü 512��) */
	uint16 usElmTH_TR_EX_CNT;		/** 14~15, �˵�ȸ�� Ȯ��(ǥ��)����(ELM_TRACK_EX) table �� �ǻ�� ���� (��ü 512��) */
	uint16 usElmTH_SG_GI_CNT;		/** 16~17, ��ȣ�� �Ϲ�����(ELM_SIGNAL_GI) table �� �ǻ�� ���� (��ü 512��) */
	uint16 usElmTH_PT_GI_CNT;		/** 18~19, ������ȯ�� ��������(ELM_POINT GI) table �� �ǻ�� ���� (��ü 256��) */
	uint16 usElmTH_GIO_GI_CNT;	/** 20~21, General I/O �Ϲ�����(ELM_GIO_GI) table �� �ǻ�� ���� (��ü 49��) */
	uint16 usElmTH_RT_GI_CNT;		/** 22~23, ���� �Ϲ�����(ELM_ROUTE GI) table �� �ǻ�� ���� (��ü 1024��) */
	uint32 uiILDBSize;			/** 24~27, IDLB SIZE(CRC_DATA ��) */
	uint32 uiAllCRC32;			/** 28~31, 1000byte CRC������ CRC */
	uint8 aucILDBVer[SIZE_ILDB_VERSION];	/** 32~49, ILDB Version (18 BYTE) */
} TS_COMM_MMI_INITIAL_RESPONSE_DATA;

/* ------------------------------------------------------------------------- */
/* Polling ����� �۽� Que�� ����Ǵ� �޽������� ���� �����ͺ� ����ü ���� */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_MSG_BLOCK
* @brief Polling ������� �۽� Que�� ����Ǵ� �޽������� ���� �����ͺ� ����ü
*/
typedef struct {
	uint16  usElementID;	/** 0~1, Element�� ID */
	uint8  ucState;		/** 2, Element�� �������� */
} TS_COMM_ELM_STATE_DATA;

/* ------------------------------------------------------------------------- */
/* Polling ����� �۽� Que�� ����Ǵ� ���º�ȭ���� �޽������� ����ü ����  */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_STATE_MSGBLOCK
* @brief Polling ����� �۽� Que�� ����Ǵ� ���º�ȭ���� �޽������� ����ü
*/
/* [LOCAL�ִ�޼�������] */
/*#define MAX_MSGBLK_ELM_STATE_DATA_CNT       255 */        /** �޽������� ���º�ȭ���� ������ �� (765 = 255 * 3) */
#define MAX_MSGBLK_ELM_STATE_DATA_CNT       230         /** �޽������� ���º�ȭ���� ������ �� (765 = 255 * 3) */
typedef struct {
	uint8 ucDataType;		/** 0, �޽����� �������� Ÿ��, 0x10:���º�ȭ���� ������, 0x20:�̺�Ʈ�޽��� ������, 0x30:Basescan �������� ������, 0x40:������ȣ ���º�ȭ ������, 0x50: Basescan ������ȣ ������, 0xF0: Initial polling ������ */
	uint16 usLength;		/** 1-2, �޽������� �� ������ ����, ������ Ÿ�Ժ��� ������ �����ͱ����� BYTE SIZE ���� */
	uint8 ucYear;			/** 3 �޽������� ���� �⵵, 0 ~ 255(2000�� ~ 2255��) */
	uint8 ucMonth;			/** 4, �޽������� ���� ��, 1 ~ 12(��) */
	uint8 ucDay;			/** 5, �޽������� ���� ��, 1 ~ 31(��) */
	uint8 ucHour;			/** 6, �޽������� ���� �ð�, 0 ~ 23(��) */
	uint8 ucMinute;			/** 7, �޽������� ���� ��, 0 ~ 59(��) */
	uint8 ucSecond;			/** 8, �޽������� ���� ��, 0 ~ 59(��) */
	uint8 uc10msec;			/** 9, �޽������� ���� 1/100��, 0 ~ 99(10ms~990ms) */
	uint8 ucElementCnt;		/** 10, �޽������� ���º�ȭ���� ������ ����, 1 ~ 255. */
	TS_COMM_ELM_STATE_DATA	atStateData[MAX_MSGBLK_ELM_STATE_DATA_CNT];	/** 11~875, �޽������� ���º�ȭ���� ������ �� (765 = 255 * 3) */
} TS_COMM_MMI_STATE_MSGBLOCK;

/* ------------------------------------------------------------------------- */
/* Polling ����� �۽� Que�� ����Ǵ� �̺�Ʈ���� �޽������� ����ü ����    */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_EVENT_MSGBLOCK
* @brief Polling ����� �۽� Que�� ����Ǵ� �̺�Ʈ���� �޽������� ����ü
*/
/* [LOCAL�ִ�޼�������] */
/*#define MAX_MSGBLK_EVENT_DATA_CNT       970 */    /** ������ �ʵ�(Field)�� �ִ� ũ�Ⱑ 988 BYTE �� ��� ���� */
/*#define MAX_MSGBLK_EVENT_PARAM_MSG_CNT  24U */    /** ������ �ʵ�(Field)�� �̺�Ʈ �Ķ��Ʈ �޼������� ��     */  /*MISRA-C 2004:10.1:integer underlying type�� ��ȣ�� ���������� ��ȯ:Type casting 'U'*/
#define MAX_MSGBLK_EVENT_DATA_CNT       610     /** ������ �ʵ�(Field)�� �ִ� ũ�Ⱑ 988 BYTE �� ��� ���� */
#define MAX_MSGBLK_EVENT_PARAM_MSG_CNT  15U     /** ������ �ʵ�(Field)�� �̺�Ʈ �Ķ��Ʈ �޼������� ��     */  /*MISRA-C 2004:10.1:integer underlying type�� ��ȣ�� ���������� ��ȯ:Type casting 'U'*/
typedef struct {
	uint8 ucDataType;		/** 0, �޽����� �������� Ÿ��, 0x10:���º�ȭ���� ������, 0x20:�̺�Ʈ�޽��� ������, 0x30:Basescan �������� ������, 0x40:������ȣ ���º�ȭ ������, 0x50: Basescan ������ȣ ������, 0xF0: Initial polling ������ */
	uint16 usLength;			/** 1-2, �޽������� �� ������ ����, ������ Ÿ�Ժ��� ������ �����ͱ����� BYTE SIZE ���� */
	uint8 ucYear;			/** 3 �޽������� ���� �⵵, 0 ~ 255(2000�� ~ 2255��) */
	uint8 ucMonth;			/** 4, �޽������� ���� ��, 1 ~ 12(��) */
	uint8 ucDay;				/** 5, �޽������� ���� ��, 1 ~ 31(��) */
	uint8 ucHour;			/** 6, �޽������� ���� �ð�, 0 ~ 23(��) */
	uint8 ucMinute;			/** 7, �޽������� ���� ��, 0 ~ 59(��) */
	uint8 ucSecond;			/** 8, �޽������� ���� ��, 0 ~ 59(��) */
	uint8 uc10msec;			/** 9, �޽������� ���� 1/100��, 0 ~ 99(10ms~990ms) */
	uint8 ucEventCnt;		/** 10, �޽������� �̺�Ʈ�޽��� ������ ����, 1 ~ 255. */
	uint16 usEventCode;		/** 11-12, �޽������� �̺�Ʈ�޽��� ù �������� �̺�Ʈ ��ȣ, 1 ~ 999. */
	union {/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;�ܺ� I/F Data packet 1000 byte�̳����� �̺�Ʈ �������� �����] */
		uint8 ucEventData[MAX_MSGBLK_EVENT_DATA_CNT];	/** 13~982, ��ӵǴ� �޽������� �̺�Ʈ�޽��� �����͵� (������ �ʵ�(Field)�� �ִ� ũ�Ⱑ 988 BYTE �� ��� ����). */
		TS_EVNMSG_PARAM atMsg[MAX_MSGBLK_EVENT_PARAM_MSG_CNT];	
	}Msg;
} TS_COMM_MMI_EVENT_MSGBLOCK;

/* ------------------------------------------------------------------------- */
/* Polling ����� �۽� Que�� ����Ǵ� Basescan �������� �޽������� ����ü ����  */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_BSSTATE_MSGBLOCK
* @brief Polling ����� �۽� Que�� ����Ǵ� Basescan �������� �޽������� ����ü
*/
#define MAX_MSGBLK_BSSTATE_CNT	970		/** ������ �ʵ�(Field)�� �ִ� ũ�Ⱑ 988 BYTE �� ��� ���� */
typedef struct {
	uint8 ucDataType;	/** 0, �޽����� �������� Ÿ��, 0x10:���º�ȭ���� ������, 0x20:�̺�Ʈ�޽��� ������, 0x30:Basescan �������� ������, 0x40:������ȣ ���º�ȭ ������, 0x50: Basescan ������ȣ ������, 0xF0: Initial polling ������ */
	uint16 usLength;		/** 1-2, �޽������� �� ������ ����, ������ Ÿ�Ժ��� ������ �����ͱ����� BYTE SIZE ���� */
	uint8 ucYear;		/** 3 �޽������� ���� �⵵, 0 ~ 255(2000�� ~ 2255��) */
	uint8 ucMonth;		/** 4, �޽������� ���� ��, 1 ~ 12(��) */
	uint8 ucDay;			/** 5, �޽������� ���� ��, 1 ~ 31(��) */
	uint8 ucHour;		/** 6, �޽������� ���� �ð�, 0 ~ 23(��) */
	uint8 ucMinute;		/** 7, �޽������� ���� ��, 0 ~ 59(��) */
	uint8 ucSecond;		/** 8, �޽������� ���� ��, 0 ~ 59(��) */
	uint8 uc10msec;		/** 9, �޽������� ���� 1/100��, 0 ~ 99(10ms~990ms) */
	uint16 usStartID;		/** 10-11, �޽������� Basescan �������� ���� Element ID(usElement[0])�� ������ Element ID(usElement[1]) */
	uint16 usEndID;		/** 12-13, �޽������� Basescan �������� ���� Element ID(usElement[0])�� ������ Element ID(usElement[1]) */
	uint8 aucState[MAX_MSGBLK_BSSTATE_CNT];	/** 14~983, �޽������� Basescan �������� �����͵� (������ �ʵ�(Field)�� �ִ� ũ�Ⱑ 988 BYTE �� ��� ����) */
} TS_COMM_MMI_BSSTATE_MSGBLOCK;

/**
* @struct TS_COMM_MMI_BSSTATE_REAL_MSGBLOCK
* @brief Polling ����� �۽� Que�� ����Ǵ� �ǻ�� ���� �ǻ�� ������ ���� Basescan �������� �޽������� ����ü
*/
/* [LOCAL�ִ�޼�������] */
/* #define MAX_MSGBLK_BSSTATE_REAL_CNT	966U */		/** ������ �ʵ�(Field)�� �ִ� ũ�Ⱑ 988 BYTE �� ��� ���� */
#define MAX_MSGBLK_BSSTATE_REAL_CNT	700U		/** ������ �ʵ�(Field)�� �ִ� ũ�Ⱑ 720 BYTE �� ��� ���� */
typedef struct {
	uint8 ucDataType;			/** 0, �޽����� �������� Ÿ��, 0x10:���º�ȭ���� ������, 0x20:�̺�Ʈ�޽��� ������, 0x30:Basescan �������� ������, 0x31:REAL TYPE BASESCAN �������� ������, 0x40:������ȣ ���º�ȭ ������, 0x50: Basescan ������ȣ ������, 0xF0: Initial polling ������ */
	uint16 usLength;				/** 1-2, �޽������� �� ������ ����, ������ Ÿ�Ժ��� ������ �����ͱ����� BYTE SIZE ���� */
	uint8 ucYear;				/** 3 �޽������� ���� �⵵, 0 ~ 255(2000�� ~ 2255��) */
	uint8 ucMonth;				/** 4, �޽������� ���� ��, 1 ~ 12(��) */
	uint8 ucDay;					/** 5, �޽������� ���� ��, 1 ~ 31(��) */
	uint8 ucHour;				/** 6, �޽������� ���� �ð�, 0 ~ 23(��) */
	uint8 ucMinute;				/** 7, �޽������� ���� ��, 0 ~ 59(��) */
	uint8 ucSecond;				/** 8, �޽������� ���� ��, 0 ~ 59(��) */
	uint8 uc10msec;				/** 9, �޽������� ���� 1/100��, 0 ~ 99(10ms~990ms) */
	uint16 usStationNo;			/** 10~11, �� ���� ��ȣ */
	uint8 ucSpare[4];			/** 12~15, spare */
	uint8 ucCurrBlkID;			/** 16, Current �޽������� ��ȣ */
	uint8 ucEndBlkID;			/** 17, Total �޽������� ��ȣ */
	uint8 aucState[MAX_MSGBLK_BSSTATE_REAL_CNT];			/** 18~983, �޽������� Basescan �������� �����͵� (������ �ʵ�(Field)�� �ִ� ũ�Ⱑ 988 BYTE �� ��� ����) */
} TS_COMM_MMI_BSSTATE_REAL_MSGBLOCK;

/* ------------------------------------------------------------------------- */
/* Polling ����� �۽� Que�� ����Ǵ� �޽������� ������ȣ �����ͺ� ����ü ���� */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_OBJ_TRNO_DATA
* @brief Polling ������� �۽� Que�� ����Ǵ� �޽������� ������ȣ �����ͺ� ����ü
*/
typedef struct {
	uint16 usTrainNoID;			/** 0~1, Train No. Window �� ID */
	uint16 usTrackID;			/** 2-3, Track Object �� ID */
	uint8 aucTrainNumber1[5];	/** 4~8, ������ȣ #1 */
	uint8 aucTrainNumber2[5];	/** 9~13, ������ȣ #2 */
} TS_COMM_TRNO_OBJ_DATA;

/* ------------------------------------------------------------------------- */
/* Polling ����� �۽� Que�� ����Ǵ� Basescan �䱸�� �Ǵ� ���º�ȭ�� ������ȣ �޽������� ����ü ����  */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_COMM_MMI_TRNOSTATE_MSGBLOCK
* @brief Polling ����� �۽� Que�� ����Ǵ� Basescan �䱸�� �Ǵ� ���º�ȭ�� ������ȣ �޽������� ����ü
*/
#define MAX_MSGBLK_TRNO_OBJ_DATA_CNT	50		/** �ִ� 50��, 0 ��°�� ������� ����-Reserved */
typedef struct {
	uint8 ucDataType;	/** 0, �޽����� �������� Ÿ��, 0x10:���º�ȭ���� ������, 0x20:�̺�Ʈ�޽��� ������, 0x30:Basescan �������� ������, 0x40:������ȣ ���º�ȭ ������, 0x50: Basescan ������ȣ ������, 0xF0: Initial polling ������ */
	uint16 usLength;		/** 1-2, �޽������� �� ������ ����, ������ Ÿ�Ժ��� ������ �����ͱ����� BYTE SIZE ���� */
	uint8 ucYear;		/** 3 �޽������� ���� �⵵, 0 ~ 255(2000�� ~ 2255��) */
	uint8 ucMonth;		/** 4, �޽������� ���� ��, 1 ~ 12(��) */
	uint8 ucDay;			/** 5, �޽������� ���� ��, 1 ~ 31(��) */
	uint8 ucHour;		/** 6, �޽������� ���� �ð�, 0 ~ 23(��) */
	uint8 ucMinute;		/** 7, �޽������� ���� ��, 0 ~ 59(��) */
	uint8 ucSecond;		/** 8, �޽������� ���� ��, 0 ~ 59(��) */
	uint8 uc10msec;		/** 9, �޽������� ���� 1/100��, 0 ~ 99(10ms~990ms) */
	uint8 ucTrainWndCnt;	/** 10, �޽������ǿ�����ȣ ���� ����(0~49) */
	TS_COMM_TRNO_OBJ_DATA tTrainObjDB[50];	/** 12, ������ȣ �޽������� ��ü ������(�ִ� 50��, 0 ��°�� ������� ����-Reserved) */
} TS_COMM_MMI_TRNOSTATE_MSGBLOCK;


/* ------------------------------------------------------------------------- */
/* Polling ������� �۽� Que�� ����Ǵ� �޽������� ����ü ����             */
/* ------------------------------------------------------------------------- */
/**
* @struct TU_COMM_MSG_BLOCK
* @brief Polling ������� �۽� Que�� ����Ǵ� �޽������� ����ü
*/
typedef union {/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;�ܺ� I/F Data packet 1000 byte�̳����� �̺�Ʈ �������� �����] */
	uint8	aucMsgBlock[LIMIT_CNT_MMI_EXT_COMMFRAME];		/** �޽������� �����Ͱ� ��� ���� */
	TS_COMM_MMI_INITIAL_RESPONSE_DATA	tInitRespData;		/** �޽������� Initial Polling ���� ������ �� */
	TS_COMM_MMI_STATE_MSGBLOCK			tStateMsgBlk;		/** �޽������� ���º�ȭ ���� ������ �� */
	TS_COMM_MMI_EVENT_MSGBLOCK			tEventMsgBlk;		/** �޽������� �̺�Ʈ�޽��� ���� ������ �� */
	TS_COMM_MMI_BSSTATE_MSGBLOCK		tBSStateMsgBlk;		/** �޽������� Basescan �������� ������ �� */
	TS_COMM_MMI_TRNOSTATE_MSGBLOCK		tTrNoStateMsgBlk;	/** �޽������� ������ȣ(���º�ȭ �Ǵ� Basescan) ������ �� */
} TU_COMM_MSG_BLOCK;

/**
* @struct TS_COMM_INITPOLLING_RESPONSE_MSG_FRAME
* @brief �ʱ�����(Initial Response) �޽��� �������� ����ü
*/
typedef struct {
	uint8  ucSTX;										/** 0, �޽��� �������� ���� ����, STX=0x02 ������ */
	TS_COMM_MMI_FRAME_HEADER			tHeader;		/** 1~6, �޽��� �������� �ش� ������ */
	TS_COMM_MMI_INITIAL_RESPONSE_DATA	tInitRespData;	/** 7~23, �޽��� �������� ������ȣ ��ȯ �����͸� �����ϴ� ������ �ʵ� */
	TS_CRC32_DATA						tCRC32;			/** 24~27, �޽��� �������� CRC32 */
	uint8 ucETX;											/** 28, �޽��� �������� ���� ����, ETX=0x03 ������ */
} TS_COMM_MMI_INITIAL_RESP_MSG_FRAME;

/**
* @struct TS_COMM_INITPOLLING_RESPONSE_MSG_FRAME
* @brief �ʱ�����(Initial Response) �޽��� �������� ����ü
*/
typedef struct {	
	uint8  ucSTX;										/** 0, �޽��� �������� ���� ����, STX=0x02 ������ */
	TS_COMM_MMI_FRAME_HEADER			tHeader;		/** 1~6, �޽��� �������� �ش� ������ */
	union {/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;�ܺ� I/F Data packet 1000 byte�̳����� �̺�Ʈ �������� �����] */
		TS_COMM_MMI_STATE_MSGBLOCK		tStateMsgBlk;	/** �޽������� ���º�ȭ ���� ������ �� */
		TS_COMM_MMI_EVENT_MSGBLOCK		tEventMsgBlk;	/** �޽������� �̺�Ʈ�޽��� ���� ������ �� */
		TS_COMM_MMI_BSSTATE_MSGBLOCK	tBSStateMsgBlk;	/** �޽������� Basescan �������� ������ �� */
		TS_COMM_MMI_TRNOSTATE_MSGBLOCK	tTrNoStateMsgBlk;	/** �޽������� ������ȣ(���º�ȭ �Ǵ� Basescan) ������ �� */
	} BLK;
	TS_CRC32_DATA						tCRC32;			/** 24~27, �޽��� �������� CRC32, ������ ���� ���� ũ�⿡ ���� �� �����Ͱ� ���õǰ� �ٸ����� ���ǵ� ���� ����. */
	uint8 ucETX;											/** 28, �޽��� �������� ���� ����, ETX=0x03 ������, ������ ���� ���� ũ�⿡ ���� �� �����Ͱ� ���õǰ� �ٸ����� ���ǵ� ���� ����. */
} TS_COMM_MMI_POLLING_RESP_MSG_FRAME;


/**
* @struct TU_COMM_ILS_MSG_FRAME
* @brief ILS ���� �۽��ϴ� �޽��� �������� ����ü
*/
typedef union {/* [CS_IGNORE=MISRA_C_2004.MISRA_18_04;�ܺ� I/F Data packet 1000 byte�̳����� �̺�Ʈ �������� �����] */
	uint8 aucMsgFrame[LIMIT_CNT_MMI_EXT_COMMFRAME];		/** ��/���� �޽��� �������� �����Ͱ� ��� ���� */
	TS_COMM_MMI_SHORT_MSG_FRAME			tShortMsg;		/** �����͸� �������� �ʴ� �޽���(ACK, NACK, LINK) */
	TS_COMM_MMI_INITIAL_RESP_MSG_FRAME	tInitRespMsg;	/** �ʱ�����(Initial Response) �޽��� */
	TS_COMM_MMI_POLLING_RESP_MSG_FRAME	tPollRespMsg;	/** ��������(Polling Respoinse) (���º�ȭ����/�̺�Ʈ/Basescan ��������) �޽��� */
} TU_COMM_ILS_MSG_FRAME;


/* ------------------------------------------------------------------------- */

#endif /** #ifndef _DEFCOMMTYPES_H_ */
