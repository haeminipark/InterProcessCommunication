/* -------------------------------------------------------------------------- /
2017.02.03 :
 - [KRS�����ιݿ�1] �������� �䱸���� �߰�
 - [KRS�����ιݿ�2] OPC ������� ������ ����
 - [KRS�����ιݿ�3] MTC �������� �߰�
/ -------------------------------------------------------------------------- */
#ifndef _ELEMENTTABLE_H_
#define _ELEMENTTABLE_H_
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
* @file     ElementTable.h : header file
* @project  KRS-EIS
* @author   DAEATI/Jeong Y.J
* @version  1.0
* @dev-env	Microsoft Visual Studio 2013 professional K
*			Microsoft .Net Framework 4.5.50938 SP1Rel
*			Window 7 Professional K 6.1.7601 SP1 build 7601
*			(CPU: intel i5-4200M 2.5Ghz, RAM 8G)
* @exe-env	WinXP SP3 �̻�.
* @library	not used.
* @brief    KRSEIS���� ���Ǵ� Element �� Define File
* @see      main structure TS_ELEMENT_INDEX_TABLE, TS_ELEMENT_DATA_TABLE
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

#pragma once

/* ///////////////////////////////////////////////////////////////////////// */
/* Include Files                                                             */
/* ///////////////////////////////////////////////////////////////////////// */

/*#include	"EisDefine.h"*/
#include	"defconstant.h"			/** �������� ���� �⺻ ������ Ÿ�� ���� �ش����� ���� */ 
#include	"defendian.h"			/** Endian ���� �ش����� ���� */ 

#pragma pack(1)


/* ///////////////////////////////////////////////////////////////////////// */
/* Element ������ ���� ����                                                  */
/* ///////////////////////////////////////////////////////////////////////// */

/* Element Type ���� */
#define  ELM_COMMON				 1U		 /** �� ��������. */
#define  ELM_TRACK_GI			 2U		 /** �˵�ȸ�� �Ϲ�����. */
#define  ELM_TRACK_EX			 3U		 /** �˵�ȸ�� Ȯ��(ǥ��)����. */
#define  ELM_SIGNAL_GI			 4U		 /** ��ȣ�� �Ϲ�����. */
#define  ELM_SIGNAL_EX			 5U		 /** ��ȣ�� Ȯ������.(������)  */
#define  ELM_POINT_GI			 6U		 /** ������ȯ�� �Ϲ�����. */
#define  ELM_POINT_EX			 7U		 /** ������ȯ�� Ȯ������.(������) */
#define  ELM_ROUTE_GI			 8U		 /** ���� �Ϲ�����. */
#define  ELM_GIO_GI				 9U		 /** GENERAL I/O �Ϲ�����. */
#define  ELM_GIO_LX				10U		 /** GENERAL I/O �ǳθ� ����. */
#define  ELM_GIO_OBSTRUCTION	11U		 /** GENERAL I/O ���幰������ġ ��������. */
#define  ELM_GIO_INSULATION		12U		 /** GENERAL I/O ����������ġ ��������. */
#define  ELM_GIO_EXRECTIFIER	13U		 /** Ȯ�巢 ������ ��������. */
#define  ELM_EITEND				 0U		 /** ELEMENT TABLE ��. */


/* Element Type �� �ִ� Element ���� */
#define LIMIT_CNT_ELM_IDX_COMMON	  32U	 /** �� ���� ���� ���̺��� �ִ� Element ���� */
#define LIMIT_CNT_ELM_IDX_TRGI		 512U	 /** �˵�ȸ�� �Ϲ����� ���̺��� �ִ�Element ����. ������ S/W��  */
#define LIMIT_CNT_ELM_IDX_TREX		 512U	 /** �˵�ȸ�� Ȯ��(ǥ��)���� ���̺��� �ִ�Element ���� */
#define LIMIT_CNT_ELM_IDX_SGGI		 512U	 /** ��ȣ�� �Ϲ����� ���̺��� �ִ�Element ���� */
#define LIMIT_CNT_ELM_IDX_PTGI		 256U	 /** ������ȯ�� �Ϲ����� ���̺��� �ִ�Element ���� */
#define LIMIT_CNT_ELM_IDX_GIO		  50U	 /** General I/O �Ϲ����� ���̺��� �ִ�Element ���� */
#define LIMIT_CNT_ELM_IDX_RT		1024U	 /** ���� �Ϲ����� ���̺��� �ִ�Element ���� */


/* Element Type �� ���� Element No.ID */
#define ELM_IDNO_COMMON		1											 /** �� ���� ���� Element No.ID�� 1���� ������ */
#define ELM_IDNO_TRGI		LIMIT_CNT_ELM_IDX_COMMON					 /** �˵�ȸ�� �Ϲ����� Element No.ID�� 33���� ������ */
#define ELM_IDNO_TREX		(ELM_IDNO_TRGI + LIMIT_CNT_ELM_IDX_TRGI)	 /** �˵�ȸ�� Ȯ��(ǥ��)���� Element No.ID�� 545���� ������ */
#define ELM_IDNO_SGGI		(ELM_IDNO_TREX + LIMIT_CNT_ELM_IDX_TREX)	 /** ��ȣ�� �Ϲ����� Element No.ID�� 1057���� ������ */
#define ELM_IDNO_PTGI		(ELM_IDNO_SGGI + LIMIT_CNT_ELM_IDX_SGGI)	 /** ������ȯ�� �Ϲ����� Element No.ID�� 1569���� ������ */
#define ELM_IDNO_GIO		(ELM_IDNO_PTGI + LIMIT_CNT_ELM_IDX_PTGI)	 /** General I/O �Ϲ����� Element No.ID�� 1825���� ������ */
#define ELM_IDNO_RT			(ELM_IDNO_GIO  + LIMIT_CNT_ELM_IDX_GIO)		 /** ������ �Ϲ����� Element No.ID�� 1875���� �����Ͽ� 2898���� ���ǵ� */


/* �� ���������� Element Object ID ���� */
#define ELM_IDNO_RUN			 1		 /** �ý��� �⵿ Element�� ID �� TYPE */
#define ELM_IDNO_CTC			 2		 /** CTC ���� Element�� ID �� TYPE */
#define ELM_IDNO_LOCAL			 3		 /** LOCAL ���� Element�� ID �� TYPE */
#define ELM_IDNO_RC				 4		 /** RC ���� Element�� ID �� TYPE */
#define ELM_IDNO_SYS1			 5		 /** 1�� ����� Element�� ID �� TYPE */
#define ELM_IDNO_SYS2			 6		 /** 2�� ����� Element�� ID �� TYPE */
#define ELM_IDNO_N1				 7		 /** �������� Element�� ID �� TYPE */
#define ELM_IDNO_N2				 8		 /** ö������ Element�� ID �� TYPE */
#define ELM_IDNO_UPS			 9		 /** ������������ġ Element�� ID �� TYPE */
#define ELM_IDNO_RECTIFIER1		10		 /** DC 24V ������� Element�� ID �� TYPE  */
#define ELM_IDNO_RECTIFIER2		11		 /** DC 24V ������� Element�� ID �� TYPE  */
#define ELM_IDNO_BATTERY		12		 /** ������ Element�� ID �� TYPE */
#define ELM_IDNO_FUSE			13		 /** ����� Element�� ID �� TYPE */
#define ELM_IDNO_PNPOWER		14		 /** ���� ������ȯ�� �������� Element�� ID �� TYPE */
#define ELM_IDNO_PSPOWER		15		 /** ���� ������ȯ�� �������� Element�� ID �� TYPE */
#define ELM_IDNO_SG_FAILURE		16		 /** ��ȣ�� ���� Element�� ID �� TYPE */
#define ELM_IDNO_PT_FAILURE		17		 /** ������ȯ�� ���� Element�� ID �� TYPE */
#define ELM_IDNO_TR_FAILURE		18		 /** �˵�ȸ�� ���� Element�� ID �� TYPE */
#define ELM_IDNO_RR_DOOR		19		 /** ������� �� ���� Element�� ID �� TYPE */
#define ELM_IDNO_SG_ALLSTOP		20		 /** ��ȣ�� �ϰ����� ���� Element�� ID �� TYPE */
#define ELM_IDNO_SG_SHSTOP		21		 /** ��ȯ��ȣ�� �ҵ����� Element�� ID �� TYPE */
#define ELM_IDNO_HEATER_N		22U		 /** ���� ������ȯ�� �������� Element�� ID �� TYPE */
#define ELM_IDNO_HEATER_S		23U		 /** ���� ������ȯ�� �������� Element�� ID �� TYPE */
#define ELM_IDNO_FUSE1			24		 /** FUSE 1 Element�� ID �� TYPE */
#define ELM_IDNO_FUSE2			25		 /** FUSE 2 Element�� ID �� TYPE */
#define ELM_IDNO_COM1			26		 /** COM1 Element�� ID �� TYPE */
#define ELM_IDNO_COM2			27		 /** COM2 Element�� ID �� TYPE */
#define ELM_IDNO_LCP1			28		 /** LCP 1 Element�� ID �� TYPE */
#define ELM_IDNO_LCP2			29		 /** LCP 2 Element�� ID �� TYPE */
#define ELM_IDNO_RES_30			30		 /** �ý��� ����� Element�� ID �� TYPE */
#define ELM_IDNO_RES_31			31		 /** �ý��� ����� Element�� ID �� TYPE */
#define ELM_IDNO_RES_32			32		 /** �ý��� ����� Element�� ID �� TYPE */

#ifdef _WINDOWS
/* ///////////////////////////////////////////////////////////////////////// */
/* ǥ�������� STATE �� ���� ����                                             */
/* ///////////////////////////////////////////////////////////////////////// */
/* RUN State ���� */
#define ELM_DISP_RUN_STATE_SYS1_RUN					0x04 /** 1�� �⵿ ���� : 0:���, 1:�⵿ */
#define ELM_DISP_RUN_STATE_SYS2_RUN					0x08 /** 2�� �⵿ ���� : 0:���, 1:�⵿ */
#define ELM_DISP_RUN_STATE_SYS1_GOOD				0x10 /** 1�� ���� ���� : 0:���, 1:���� */
#define ELM_DISP_RUN_STATE_SYS2_GOOD				0x20 /** 2�� ���� ���� : 0:���, 1:���� */
/* RUN State ǥ������ */
#define ELM_DISP_RUN_1_COLOR_GREEN					0x04 /** RUN(1����) ��ư�� ���� : ���, AND masking���� Setting  ���� Ȯ�� */
#define ELM_DISP_RUN_2_COLOR_GREEN					0x08 /** RUN(2����) ��ư�� ���� : ���, AND masking���� Setting  ���� Ȯ�� */

/* CTC/LOCAL/RC State ���� */
#define ELM_DISP_OPMODE_STATE_CTC_REQ				0x01 /** CTC ��ȯ�䱸 ���� : 0:����, 1:��ȯ�䱸 */
#define ELM_DISP_OPMODE_STATE_CTC_RUN				0x02 /** CTC ��ȯ ���� : 0:���, 1:CTC ������� */
#define ELM_DISP_OPMODE_STATE_LOCAL_REQ				0x04 /** LOCAL ��ȯ�䱸 ���� : 0:����, 1:��ȯ�䱸 */
#define ELM_DISP_OPMODE_STATE_LOCAL_RUN				0x08 /** LOCAL ��ȯ ���� : 0:���, 1:LOCAL ������� */
#define ELM_DISP_OPMODE_STATE_RC_REQ				0x10 /** RC ��ȯ�䱸 ���� : 0:����, 1:��ȯ�䱸 */
#define ELM_DISP_OPMODE_STATE_RC_RUN				0x20 /** RC ��ȯ ���� : 0:���, 1:RC ������� */
/* CTC/LOCAL/RC State ǥ������ */
#define ELM_DISP_OPMODE_CTC_COLOR_0_GRAY			0x00 /** CTC ��ư�� ���� : ȸ�� */
#define ELM_DISP_OPMODE_CTC_COLOR_1_GREEN_F			0x01 /** CTC ��ư�� ���� : ��� ���� */
#define ELM_DISP_OPMODE_CTC_COLOR_2_GREEN			0x02 /** CTC ��ư�� ���� : ��� */
#define ELM_DISP_OPMODE_LOCAL_COLOR_0_GRAY			0x00 /** LOCAL ��ư�� ���� : ȸ�� */
#define ELM_DISP_OPMODE_LOCAL_COLOR_1_GREEN_F		0x04 /** LOCAL ��ư�� ���� : ��� ���� */
#define ELM_DISP_OPMODE_LOCAL_COLOR_2_GREEN			0x08 /** LOCAL ��ư�� ���� : ��� */
#define ELM_DISP_OPMODE_RC_COLOR_0_GRAY				0x00 /** RC ��ư�� ���� : ȸ�� */
#define ELM_DISP_OPMODE_RC_COLOR_1_GREEN_F			0x10 /** RC ��ư�� ���� : ��� ���� */
#define ELM_DISP_OPMODE_RC_COLOR_2_GREEN			0x20 /** RC ��ư�� ���� : ��� */
/* Mask */
#define ELM_DISP_OPMEDE_CTC_MASK					0x03 /** D0~D1 */
#define ELM_DISP_OPMEDE_LOCAL_MASK					0x0C /** D2~D3 */
#define ELM_DISP_OPMEDE_RC_MASK						0x30 /** D4~D5 */

/* COMMON ǥ�� ALARM, GGOD State mask */
#define ELM_DISP_ITEM_STATE_ALARM					0x10 /** element alarm state */
#define ELM_DISP_ITEM_STATE_GOOD					0x20 /** element good state */

/* SYSTEM 1�� State ���� */
#define ELM_DISP_SYS1_STATE_ALARMON					0x10 /** 1�� �˶��溸 �߻� ���� : 0:�溸����, 1:�溸�߻� */
#define ELM_DISP_SYS1_STATE_SYSGOOD					0x20 /** 1�� ���� ���� : 0:����, 1:���� */
#define ELM_DISP_SYS1_STATE_SYSACTIVE				0x40 /** 1�� Active ���� : 0:Statndby, 1:Active */
/* SYSTEM 1�� State ǥ������ */
#define ELM_DISP_SYS1_COLOR_0_RED					0x00 /** SYS1 ��ư�� ���� : ���� */
#define ELM_DISP_SYS1_COLOR_1_RED_F					0x10 /** SYS1 ��ư�� ���� : ���� ���� */
#define ELM_DISP_SYS1_COLOR_2_GRAY					0x20 /** SYS1 ��ư�� ���� : ȸ�� */
#define ELM_DISP_SYS1_COLOR_6_GREEN					0x60 /** SYS1 ��ư�� ���� : ��� */
/* Mask */
#define ELM_DISP_SYS1_MASK							0x70 /** D4~D6 */
/* SYSTEM 2�� State ���� */
#define ELM_DISP_SYS2_STATE_ALARMON					0x10 /** 2�� �˶��溸 �߻� ���� : 0:�溸����, 1:�溸�߻� */
#define ELM_DISP_SYS2_STATE_SYSGOOD					0x20 /** 2�� ���� ���� : 0:����, 1:���� */
#define ELM_DISP_SYS2_STATE_SYSACTIVE				0x40 /** 2�� Active ���� : 0:Statndby, 1:Active */
/* SYSTEM 2�� State ǥ������ */
#define ELM_DISP_SYS2_COLOR_0_RED					0x00 /** SYS2 ��ư�� ���� : ���� */
#define ELM_DISP_SYS2_COLOR_1_RED_F					0x10 /** SYS2 ��ư�� ���� : ���� ���� */
#define ELM_DISP_SYS2_COLOR_2_GRAY					0x20 /** SYS2 ��ư�� ���� : ȸ�� */
#define ELM_DISP_SYS2_COLOR_6_GREEN					0x60 /** SYS2 ��ư�� ���� : ��� */
/* Mask */
#define ELM_DISP_SYS2_MASK							0x70 /** D4~D6 */
/* �������� N1 State ���� */
#define ELM_DISP_N1_STATE_ALARMON					0x10 /** N! ���� �˶��溸 �߻� ���� : 0:�溸����, 1:�溸�߻� */
#define ELM_DISP_N1_STATE_GOOD						0x20 /** N1 ���� ���� ���� : 0:����, 1:���� */
#define ELM_DISP_N1_STATE_ACTIVE					0x40 /** N1 ���� ���� ���� : 0:Statndby, 1:active */
/* �������� N1 State ǥ������ */
#define ELM_DISP_N1_COLOR_0_RED						0x00 /** N1 ��ư�� ���� : ���� */
#define ELM_DISP_N1_COLOR_1_RED_F					0x10 /** N1 ��ư�� ���� : ���� ���� */
#define ELM_DISP_N1_COLOR_2_GRAY					0x20 /** N1 ��ư�� ���� : ȸ�� */
#define ELM_DISP_N1_COLOR_6_GREEN					0x60 /** N1 ��ư�� ���� : ��� */
/* Mask */
#define ELM_DISP_N1_MASK							0x70 /** D4~D6 */
/* ö������ N2 State ���� */
#define ELM_DISP_N2_STATE_ALARMON					0x10 /** N2 ���� �˶��溸 �߻� ���� : 0:�溸����, 1:�溸�߻� */
#define ELM_DISP_N2_STATE_GOOD						0x20 /** N2 ���� ���� ���� : 0:����, 1:���� */
#define ELM_DISP_N2_STATE_ACTIVE					0x40 /** N2 ���� ���� ���� : 0:Statndby, 1:active */
/* ö������ N2 State ǥ������ */
#define ELM_DISP_N2_COLOR_0_RED						0x00 /** N2 ��ư�� ���� : ���� */
#define ELM_DISP_N2_COLOR_1_RED_F					0x10 /** N2 ��ư�� ���� : ���� ���� */
#define ELM_DISP_N2_COLOR_2_GRAY					0x20 /** N2 ��ư�� ���� : ȸ�� */
#define ELM_DISP_N2_COLOR_6_GREEN					0x60 /** N2 ��ư�� ���� : ��� */
/* Mask */
#define ELM_DISP_N2_MASK							0x70 /** D4~D6 */
/* UPS State ���� */
#define ELM_DISP_UPS_STATE_ALARMON					0x10 /** UPS �˶��溸 �߻� ���� : 0:�溸����, 1:�溸 �߻� */
#define ELM_DISP_UPS_STATE_GOOD						0x20 /** UPS ���� ���� : 0:����, 1:���� */
/* UPS State ǥ������ */
#define ELM_DISP_UPS_COLOR_0_RED					0x00 /** UPS ��ư�� ���� : ���� */
#define ELM_DISP_UPS_COLOR_1_RED_F					0x10 /** UPS ��ư�� ���� : ���� ���� */
#define ELM_DISP_UPS_COLOR_2_GREEN					0x20 /** UPS ��ư�� ���� : ��� */
/* Mask */
#define ELM_DISP_UPS_MASK							0x30 /** D4~D5 */
/* RECTIFIER 1,2 State ���� */
#define ELM_DISP_RECTIFIER_STATE_ALARMON			0x10 /** RECTIFIER �˶��溸 �߻� ���� : 0:�溸����, 1:�溸 �߻� */
#define ELM_DISP_RECTIFIER_STATE_GOOD				0x20 /** RECTIFIER ���� ���� : 0:����, 1:���� */
/* RECTIFIER State ǥ������ */
#define ELM_DISP_RECTIFIER_COLOR_0_RED				0x00 /** RECTIFIER ��ư�� ���� : ���� */
#define ELM_DISP_RECTIFIER_COLOR_1_RED_F			0x10 /** RECTIFIER ��ư�� ���� : ���� ���� */
#define ELM_DISP_RECTIFIER_COLOR_2_GREEN			0x20 /** RECTIFIER ��ư�� ���� : ��� */
/* Mask */
#define ELM_DISP_RECTIFIER_MASK						0x30 /** D4~D5 */
/* BATTERY State ���� */
#define ELM_DISP_BATTERY_STATE_ALARMON				0x10 /** BATTERY �˶��溸 �߻� ���� : 0:�溸����, 1:�溸 �߻� */
#define ELM_DISP_BATTERY_STATE_GOOD					0x20 /** BATTERY ���� ���� : 0:����, 1:���� */
/* BATTERY State ǥ������ */
#define ELM_DISP_BATTERY_COLOR_0_RED				0x00 /** BATTERY ��ư�� ���� : ���� */
#define ELM_DISP_BATTERY_COLOR_1_RED_F				0x10 /** BATTERY ��ư�� ���� : ���� ���� */
#define ELM_DISP_BATTERY_COLOR_2_GREEN				0x20 /** BATTERY ��ư�� ���� : ��� */
/* Mask */
#define ELM_DISP_BATTERY_MASK						0x30 /** D4~D5 */
/* FUSE State ���� */
#define ELM_DISP_FUSE_STATE_ALARMON					0x10 /** FUSE �˶��溸 �߻� ���� : 0:�溸����, 1:�溸 �߻� */
#define ELM_DISP_FUSE_STATE_GOOD					0x20 /** FUSE ���� ���� : 0:����, 1:���� */
/* FUSE State ǥ������ */
#define ELM_DISP_FUSE_COLOR_0_RED					0x00 /** FUSE ��ư�� ���� : ���� */
#define ELM_DISP_FUSE_COLOR_1_RED_F					0x10 /** FUSE ��ư�� ���� : ���� ���� */
#define ELM_DISP_FUSE_COLOR_2_GREEN					0x20 /** FUSE ��ư�� ���� : ��� */
/* Mask */
#define ELM_DISP_FUSE_MASK							0x30 /** D4~D5 */
/* ���� ������ȯ�� ���� ���� State ���� */
#define ELM_DISP_PNPOWER_STATE_ALARMON				0x10 /** ���� ������ȯ�� ���� ���� �˶��溸 �߻� ���� : 0:�溸����, 1:�溸 �߻� */
#define ELM_DISP_PNPOWER_STATE_GOOD					0x20 /** ���� ������ȯ�� ���� ���� ���� ���� : 0:����, 1:���� */
/* ���� ������ȯ�� ���� ���� State ǥ������ */
#define ELM_DISP_PNPOWER_COLOR_0_RED				0x00 /** PNPOWER ��ư�� ���� : ���� */
#define ELM_DISP_PNPOWER_COLOR_1_RED_F				0x10 /** PNPOWER ��ư�� ���� : ���� ���� */
#define ELM_DISP_PNPOWER_COLOR_2_GREEN				0x20 /** PNPOWER ��ư�� ���� : ��� */
/* Mask */
#define ELM_DISP_PNPOWER_MASK						0x30 /** D4~D5 */
/* ���� ������ȯ�� ���� ���� State ���� */
#define ELM_DISP_PSPOWER_STATE_ALARMON				0x10 /** ���� ������ȯ�� ���� ���� �˶��溸 �߻� ���� : 0:�溸����, 1:�溸 �߻� */
#define ELM_DISP_PSPOWER_STATE_GOOD					0x20 /** ���� ������ȯ�� ���� ���� ���� ���� : 0:����, 1:���� */
/* ���� ������ȯ�� ���� ���� State ǥ������ */
#define ELM_DISP_PSPOWER_COLOR_0_RED				0x00 /** PSPOWER ��ư�� ���� : ���� */
#define ELM_DISP_PSPOWER_COLOR_1_RED_F				0x10 /** PSPOWER ��ư�� ���� : ���� ���� */
#define ELM_DISP_PSPOWER_COLOR_2_GREEN				0x20 /** PSPOWER ��ư�� ���� : ��� */
/* Mask */
#define ELM_DISP_PSPOWER_MASK						0x30 /** D4~D5 */
/* Signal Failure State ���� */
#define ELM_DISP_UPS_STATE_ALARMON					0x10 /** Signal Failure �˶��溸 �߻� ���� : 0:�溸����, 1:�溸 �߻� */
#define ELM_DISP_UPS_STATE_GOOD						0x20 /** Signal Failure ���� : 0:����, 1:���� */
/* Signal Failure State ǥ������ */
#define ELM_DISP_SGFAILURE_COLOR_0_RED				0x00 /**  Signal Failure ��ư�� ���� : ���� */
#define ELM_DISP_SGFAILURE_COLOR_1_RED_F			0x10 /**  Signal Failure ��ư�� ���� : ���� ���� */
#define ELM_DISP_SGFAILURE_COLOR_2_GREEN			0x20 /**  Signal Failure ��ư�� ���� : ��� */
/* Mask */
#define ELM_DISP_SGFAILURE_MASK						0x30 /** D4~D5 */
/* Point Failure State ���� */
#define ELM_DISP_PTFAILURE_STATE_ALARMON			0x10 /** Point Failure �˶��溸 �߻� ���� : 0:�溸����, 1:�溸 �߻� */
#define ELM_DISP_PTFAILURE_STATE_GOOD				0x20 /** Point Failure ���� : 0:����, 1:���� */
/* Point Failure  State ǥ������ */
#define ELM_DISP_PTFAILURE_COLOR_0_RED				0x00 /** Point Failure ��ư�� ���� : ���� */
#define ELM_DISP_PTFAILURE_COLOR_1_RED_F			0x10 /** Point Failure ��ư�� ���� : ���� ���� */
#define ELM_DISP_PTFAILURE_COLOR_2_GREEN			0x20 /** Point Failure ��ư�� ���� : ��� */
/* Mask */
#define ELM_DISP_PTFAILURE_MASK						0x30 /** D4~D5 */
/* Track Failure State ���� */
#define ELM_DISP_TRFAILURE_STATE_ALARMON			0x10 /** Track Failure �˶��溸 �߻� ���� : 0:�溸����, 1:�溸 �߻� */
#define ELM_DISP_TRFAILURE_STATE_GOOD				0x20 /** Track Failure ���� : 0:����, 1:���� */
/* Track Failure  State ǥ������ */
#define ELM_DISP_TRFAILURE_COLOR_0_RED				0x00 /** TRFAIL ��ư�� ���� : ���� */
#define ELM_DISP_TRFAILURE_COLOR_1_RED_F			0x10 /** TRFAIL ��ư�� ���� : ���� ���� */
#define ELM_DISP_TRFAILURE_COLOR_2_GREEN			0x20 /** TRFAIL ��ư�� ���� : ��� */
/* Mask */
#define ELM_DISP_TRFAIL_MASK						0x30 /** D4~D5 */
/* ��ȣ���� ���Թ� ���� State ���� */
#define ELM_DISP_RRDOOR_STATE_ALARMON				0x10 /** ��ȣ���� ���Թ� ���� �˶��溸 �߻� ���� : 0:�溸����, 1:�溸 �߻� */
#define ELM_DISP_RRDOOR_STATE_GOOD					0x20 /** ��ȣ���� ���Թ� ���� ���� : 0:����, 1:���� */
/* ��ȣ���� ���Թ� ���� State ǥ������ */
#define ELM_DISP_RRDOOR_COLOR_0_RED					0x00 /** RRDOOR ��ư�� ���� : ����, ���Թ� ���� (�溸����) */
#define ELM_DISP_RRDOOR_COLOR_1_RED_F				0x10 /** RRDOOR ��ư�� ���� : ���� ����, ���Թ� ���� (�溸�߻�) */
#define ELM_DISP_RRDOOR_COLOR_2_GREEN				0x20 /** RRDOOR ��ư�� ���� : ���, ���Թ� ���� */
/* Mask */
#define ELM_DISP_RRDOOR_MASK						0x30 /** D4~D5 */
/* ��ȣ�� �ϰ����� ���� state ǥ������ */
#define ELM_DISP_SGSTOP_ISSET						0x10 /** ��ȣ�� �ϰ����� ���� ���� : 0:�������, 1:���� ��, AND masking���� Setting  ���� Ȯ�� */
#define ELM_DISP_SGSTOP_COLOR_1_RED_F				0x20 /** ��ȣ�� �ϰ����� ��ư�� ���� : ��������, AND masking���� Setting  ���� Ȯ�� */
/* ��ȯǥ��(��ȣ��) �ҵ� ���� state ǥ������ */
#define ELM_DISP_SHOFF_COLOR_1_LIGHTGRAY			0x10 /** ��ȯǥ��(��ȣ��) �ҵ� ��ư�� ���� : �帰ȸ��, AND masking���� Setting  ���� Ȯ�� */
#define ELM_DISP_SHOFF_ISSET_REQ					0x20 /** ��ȯǥ��(��ȣ��) �ҵ� ���� ���� : 0:�������, 1:���� ��, AND masking���� Setting  ���� Ȯ�� */
/* ���� ���� ���� state ���� */
#define ELM_DISP_NHEATER_STATE_ALARMON				0x10 /** ���� ���� �˶��溸 �߻� ���� : 0:�溸����, 1:�溸 �߻� */
#define ELM_DISP_NHEATER_STATE_GOOD					0x20 /** ���� ���� ���󿩺� : 0:����, 1:���� */
#define ELM_DISP_NHEATER_CTRL_ON					0x40 /** ���� ���� ON ���� ��ư�� ���� : ���, AND masking���� Setting  ���� Ȯ�� */
#define ELM_DISP_NHEATER_ISSET						0x80 /** ���� ���� ON ���� �䱸 ���� : 0:�������, 1:���� ��, AND masking���� Setting  ���� Ȯ�� */
/* ���� ���� ���� state ǥ������ */
#define ELM_DISP_NHEATER_COLOR_0_RED				0x00 /** ���� ������ ���� : ����, ���(�溸�� ����) */
#define ELM_DISP_NHEATER_COLOR_1_RED_F				0x10 /** ���� ������ ���� : ��������, ���(�溸�� �߻�) */
#define ELM_DISP_NHEATER_COLOR_2_LIGHTGRAY			0x20 /** ���� ������ ���� : �帰ȸ��, ����(�溸�� ����) */
#define ELM_DISP_NHEATER_COLOR_3_RED_F				0x30 /** ���� ������ ���� : ��������(�帰ȸ��), ����(�溸�� �߻�) */
#define ELM_DISP_NHEATER_COLOR_4_RED				0x40 /** ���� ������ ���� : ����, ���(�溸�� ����) */
#define ELM_DISP_NHEATER_COLOR_5_RED_F				0x50 /** ���� ������ ���� : ��������, ���(�溸�� �߻�) */
#define ELM_DISP_NHEATER_COLOR_6_GREEN				0x60 /** ���� ������ ���� : ���, ����(�溸�� ����) */
#define ELM_DISP_NHEATER_COLOR_7_RED_F				0x70 /** ���� ������ ���� : ��������, ����(�溸�� �߻�) */
/* ���� ���� ���� state ���� */
#define ELM_DISP_SHEATER_STATE_ALARMON				0x10 /** ���� ���� �˶��溸 �߻� ���� : 0:�溸����, 1:�溸 �߻� */
#define ELM_DISP_SHEATER_STATE_GOOD					0x20 /** ���� ���� ���󿩺� : 0:����, 1:���� */
#define ELM_DISP_SHEATER_CTRL_ON					0x40 /** ���� ���� ON ���� ��ư�� ���� : ���, AND masking���� Setting  ���� Ȯ�� */
#define ELM_DISP_SHEATER_ISSET						0x80 /** ���� ���� ON ���� �䱸 ���� : 0:�������, 1:���� ��, AND masking���� Setting  ���� Ȯ�� */
/* ���� ���� ���� state ǥ������ */
#define ELM_DISP_SHEATER_COLOR_0_RED				0x00 /** ���� ������ ���� : ����, ���(�溸�� ����) */
#define ELM_DISP_SHEATER_COLOR_1_RED_F				0x10 /** ���� ������ ���� : ��������, ���(�溸�� �߻�) */
#define ELM_DISP_SHEATER_COLOR_2_LIGHTGRAY			0x20 /** ���� ������ ���� : �帰ȸ��, ����(�溸�� ����) */
#define ELM_DISP_SHEATER_COLOR_3_RED_F				0x30 /** ���� ������ ���� : ��������(�帰ȸ��), ����(�溸�� �߻�) */
#define ELM_DISP_SHEATER_COLOR_4_RED				0x40 /** ���� ������ ���� : ����, ���(�溸�� ����) */
#define ELM_DISP_SHEATER_COLOR_5_RED_F				0x50 /** ���� ������ ���� : ��������, ���(�溸�� �߻�) */
#define ELM_DISP_SHEATER_COLOR_6_GREEN				0x60 /** ���� ������ ���� : ���, ����(�溸�� ����) */
#define ELM_DISP_SHEATER_COLOR_7_RED_F				0x70 /** ���� ������ ���� : ��������, ����(�溸�� �߻�) */
/* FUSE1 State ���� */
#define ELM_DISP_FUSE1_STATE_ALARMON				0x10 /** FUSE1 �˶��溸 �߻� ���� : 0:�溸����, 1:�溸 �߻� */
#define ELM_DISP_FUSE1_STATE_GOOD					0x20 /** FUSE1 ���󿩺� : 0:����, 1:���� */
/* FUSE2 State ���� */
#define ELM_DISP_FUSE2_STATE_ALARMON				0x10 /** FUSE2 �˶��溸 �߻� ���� : 0:�溸����, 1:�溸 �߻� */
#define ELM_DISP_FUSE2_STATE_GOOD					0x20 /** FUSE2 ���󿩺� : 0:����, 1:���� */
/* COM1, COM2 State ���� */
#define ELM_DISP_COM_STATE_FAILURE					0x00 /** COM1 or COM2 ������ �߻� */
#define ELM_DISP_COM_STATE_ALARMON					0x10 /** COM1 or COM2 �˶��溸 �߻� ���� : 0:�溸����, 1:�溸 �߻� */
#define ELM_DISP_COM_STATE_GOOD						0x20 /** COM1 or COM2 ���󿩺� : 0:����, 1:���� */
#define ELM_DISP_COM_STATE_ACTIVE					0x40 /** COM1 or COM2 ACTIVE MAIN ���� : 0:STANDBY, 1:ACTIVE MAIN */
/* LCP1, LCP2 State ���� */
#define ELM_DISP_LCP_STATE_FAILURE					0x00 /** LCP1 ������ �߻� */
#define ELM_DISP_LCP_STATE_ALARMON					0x10 /** LCP1 �˶��溸 �߻� ���� : 0:�溸����, 1:�溸 �߻� */
#define ELM_DISP_LCP_STATE_GOOD						0x20 /** LCP1 ���󿩺� : 0:����, 1:���� */
#define ELM_DISP_LCP_STATE_ACTIVE					0x40 /** COM1 or COM2 ACTIVE MAIN ���� : 0:STANDBY, 1:ACTIVE MAIN */

/* �˵�ȸ�� �Ϲ����� State ���� */
#define ELM_DISP_TR_GI_STATE_TKUNOCC				0x01 /** ���� ���� : 0:����, 1:������ */
#define ELM_DISP_TR_GI_STATE_TKROUTE				0x02 /** �������缱�� �� ����� ���� : 0:����, 1:�������缱�� �Ǵ� ����� ���(Ȳ��) */
#define ELM_DISP_TR_GI_STATE_TKLRSET				0x04 /** ���μ��� ���� : 0:��������, 1:���μ��� */
#define ELM_DISP_TR_GI_STATE_TKHALARM				0x08 /** �峻���� ���� : 0:����, 1:�峻���� */
#define ELM_DISP_TR_GI_STATE_TKFAILURE				0x10 /** �������� : 0:����, 1:�������� */
#define ELM_DISP_TR_GI_STATE_TKREQ					0x20 /** ����� ���ɿ���, 0:(��)��޺Ұ�, 1:(��)��ް��� */
#define ELM_DISP_TR_GI_STATE_TKEMRELEASE			0x40 /** �������κ������ ���ɿ���, 0:��޺Ұ�, 1:��ް��� */
/* �˵�ȸ�� �Ϲ����� State ǥ������ */
#define ELM_DISP_TR_GI_COLOR_00_RED					0x00 /** TR �� ���� : ����, ���� */
#define ELM_DISP_TR_GI_COLOR_01_WHITE				0x01 /** TR �� ���� : ���, ������ */
#define ELM_DISP_TR_GI_COLOR_02_RED					0x02 /** TR �� ���� : ����, ���� ���缱�� ���� �˵��� ���� */
#define ELM_DISP_TR_GI_COLOR_04_YELLOW				0x04 /** TR �� ���� : Ȳ��, ���� ���缱�� ���� ������ �˵� */
#define ELM_DISP_TR_GI_COLOR_05_RED					0x05 /** TR �� ���� : ����, ���μ��� ���� �˵��� ���� */
#define ELM_DISP_TR_GI_COLOR_06_GREEN				0x06 /** TR �� ���� : ���, ���μ��� ���� ������ �˵� */
/*#define ELM_DISP_TR_GI_COLOR_07_					0x07*/ /** TR �� ���� : ��ȭ����-����, ���������� (�������缱�� ���� �˵��� ���μ�������) */
#define ELM_DISP_TR_GI_COLOR_08_RED_F_YELLOW		0x08 /** TR �� ���� : ��������(Ȳ������), �峻������ �߻��� ���� �˵� */
/*#define ELM_DISP_TR_GI_COLOR_09_					0x09*/ /** TR �� ���� : ��ȭ����-����, ���������� (������ ���¿��� �峻���� ����) */
#define ELM_DISP_TR_GI_COLOR_0A_RED_F_WHITE			0x0A /** TR �� ���� : ��������(Ȳ������), �������缱�� ������ �峻������ �߻��� ���� �˵� */
/*#define ELM_DISP_TR_GI_COLOR_0B_					0x0B*/ /** TR �� ���� : ��ȭ����-����, ���������� (������ ���¿��� �峻���� ������ �������缱�� ���� �˵�) */
#define ELM_DISP_TR_GI_COLOR_0C_RED_F_GREEN			0x0C /** TR �� ���� : ��������(�������), ���μ��� ���¿��� �峻������ �߻��� ���� �˵� */
/*#define ELM_DISP_TR_GI_COLOR_0D_					0x0D*/ /** TR �� ���� : ��ȭ����-����, ���������� (������ ���¿��� �峻���� ������ ���μ��� ���� �˵�) */
#define ELM_DISP_TR_GI_COLOR_0E_RED_F_WHITE			0x0E /** TR �� ���� : ��������(�������), �������缱�� �� ���μ��� ���� ���� �˵��� �峻���� �߻� */
/*#define ELM_DISP_TR_GI_COLOR_0F_					0x0F*/ /** TR �� ���� : ��ȭ����-����, ���������� (������ ���¿��� �峻���� ������ �������缱�� �� ���μ���) */
#define ELM_DISP_TR_GI_COLOR_10_RED_A				0x10 /** TR �� ���� : ����(�˵���ü), �������Ϸ� ������ �˵�  */
/*#define ELM_DISP_TR_GI_COLOR_11_					0x11*/ /** TR �� ���� : ��ȭ����-����, ���������� (������ ���¿��� �������� ����) */
#define ELM_DISP_TR_GI_COLOR_12_RED_A				0x12 /** TR �� ���� : ����(�˵���ü), �������缱�� ���� �����˵��� �������� ���� */
/*#define ELM_DISP_TR_GI_COLOR_13_					0x13*/ /** TR �� ���� : ��ȭ����-����, ���������� (������ ���¿��� �������� ����) */
#define ELM_DISP_TR_GI_COLOR_14_RED_A				0x14 /** TR �� ���� : ����(�˵���ü), ���μ��� ���� �����˵��� �������� ���� */
/*#define ELM_DISP_TR_GI_COLOR_15_					0x15*/ /** TR �� ���� : ��ȭ����-����, ���������� (������ ���¿��� �������� ����)  */
#define ELM_DISP_TR_GI_COLOR_16_RED_A				0x16 /** TR �� ���� : ����(�˵���ü), �������缱�� �� ���μ��� ���� ���� �˵��� �������� ���� */
/*#define ELM_DISP_TR_GI_COLOR_17_					0x17*/ /** TR �� ���� : ��ȭ����-����, ���������� (������ ���¿��� �������� ����) */
#define ELM_DISP_TR_GI_COLOR_18_RED_A				0x18 /** TR �� ���� : ����(�˵���ü), �峻������ �߻��� ���� �˵��� �������� ���� */
/*#define ELM_DISP_TR_GI_COLOR_19_					0x19*/ /** TR �� ���� : ��ȭ����-����, ���������� (������ ���¿��� �������� ����) */
#define ELM_DISP_TR_GI_COLOR_1A_RED_A				0x1A /** TR �� ���� : ����(�˵���ü), �������缱�� ���� �峻������ �߻��� ���� �˵��� �������� ���� */
/*#define ELM_DISP_TR_GI_COLOR_1B_					0x1B*/ /** TR �� ���� : ��ȭ����-����, ���������� (������ ���¿��� �������� ����) */
#define ELM_DISP_TR_GI_COLOR_1C_RED_A				0x1C /** TR �� ���� : ����(�˵���ü), ���μ��� ���� �峻������ �߻��� ���� �˵��� �������� ���� */
/*#define ELM_DISP_TR_GI_COLOR_1D_					0x1D*/ /** TR �� ���� : ��ȭ����-����, ���������� (������ ���¿��� �������� ����) */
#define ELM_DISP_TR_GI_COLOR_1E_RED_A				0x1E /** TR �� ���� : ����(�˵���ü), �����缱�� �� ���μ��� ���� �峻������ �߻��� ���� �˵��� �������� ���� */
/*#define ELM_DISP_TR_GI_COLOR_1F_					0x1F*/ /** TR �� ���� : ��ȭ����-����, ���������� (������ ���¿��� �������� ����) */
/* Mask */
#define ELM_DISP_TR_GI_STATE_MASK					0x1F /** D0~D4 */
/* �˵�ȸ�� Ȯ������(�����������ǥ(ǥ��)) ���� State ǥ������ */
#define ELM_DISP_TR_EX_COLOR_01_CAUTIONLABEL1			0x01 /** ǥ����ȣ1 : ǥ��#1 ������ġ��ȯ */
#define ELM_DISP_TR_EX_COLOR_02_CAUTIONLABEL1			0x02 /** ǥ����ȣ1 : ǥ��#2 ���λ������ */
#define ELM_DISP_TR_EX_COLOR_03_CAUTIONLABEL1			0x03 /** ǥ����ȣ1 : ǥ��#3 ���ܰ��� */
#define ELM_DISP_TR_EX_COLOR_04_CAUTIONLABEL1			0x04 /** ǥ����ȣ1 : ǥ��#4 ���������� */
#define ELM_DISP_TR_EX_COLOR_05_CAUTIONLABEL1			0x05 /** ǥ����ȣ1 : ǥ��#5 Ʈ�θ������ */
#define ELM_DISP_TR_EX_COLOR_06_CAUTIONLABEL1			0x06 /** ǥ����ȣ1 : ǥ��#6 ����ȣ */
#define ELM_DISP_TR_EX_COLOR_07_CAUTIONLABEL1			0x07 /** ǥ����ȣ1 : ǥ��#7 ������ */
#define ELM_DISP_TR_EX_COLOR_08_CAUTIONLABEL1			0x08 /** ǥ����ȣ1 : ǥ��#8 ��Ž� */
#define ELM_DISP_TR_EX_COLOR_09_CAUTIONLABEL1			0x09 /** ǥ����ȣ1 : ǥ��#9 �������� */
#define ELM_DISP_TR_EX_COLOR_0A_CAUTIONLABEL1			0x0A /** ǥ����ȣ1 : ǥ��#10 ���������� */
#define ELM_DISP_TR_EX_COLOR_01_CAUTIONLABEL2			0x10 /** ǥ����ȣ2 : ǥ��#1 ������ġ��ȯ */
#define ELM_DISP_TR_EX_COLOR_02_CAUTIONLABEL2			0x20 /** ǥ����ȣ2 : ǥ��#2 ���λ������ */
#define ELM_DISP_TR_EX_COLOR_03_CAUTIONLABEL2			0x30 /** ǥ����ȣ2 : ǥ��#3 ���ܰ��� */
#define ELM_DISP_TR_EX_COLOR_04_CAUTIONLABEL2			0x40 /** ǥ����ȣ2 : ǥ��#4 ���������� */
#define ELM_DISP_TR_EX_COLOR_05_CAUTIONLABEL2			0x50 /** ǥ����ȣ2 : ǥ��#5 Ʈ�θ������ */
#define ELM_DISP_TR_EX_COLOR_06_CAUTIONLABEL2			0x60 /** ǥ����ȣ2 : ǥ��#6 ����ȣ */
#define ELM_DISP_TR_EX_COLOR_07_CAUTIONLABEL2			0x70 /** ǥ����ȣ2 : ǥ��#7 ������ */
#define ELM_DISP_TR_EX_COLOR_08_CAUTIONLABEL2			0x80 /** ǥ����ȣ2 : ǥ��#8 ��Ž� */
#define ELM_DISP_TR_EX_COLOR_09_CAUTIONLABEL2			0x90 /** ǥ����ȣ2 : ǥ��#9 �������� */
#define ELM_DISP_TR_EX_COLOR_0A_CAUTIONLABEL2			0xA0 /** ǥ����ȣ2 : ǥ��#10 ���������� */
/* Mask */
#define ELM_DISP_TR_EX_CAUTIONLABEL1_MASK				0x0F /** D0~D3 */
#define ELM_DISP_TR_EX_CAUTIONLABEL2_MASK				0xF0 /** D4~D7 */

/* ��ȣ�� �Ϲ����� State ���� */
#define ELM_DISP_SG_STATE_UDO_GO						0x01 /** (��)������ȣ�� ���࿩�� : 0:�ҵ�, 1:�������� */
#define ELM_DISP_SG_STATE_TTB_ON						0x02 /** TTB ON/OFF ���� : 0:OFF, 1:ON */
#define ELM_DISP_SG_STATE_LOCK_ON						0x04 /** ��ȣ����� ���� : 0:����, 1:���� */
#define ELM_DISP_SG_STATE_APPROACH_LOCK_ON				0x08 /** ��ȣ�� ����/���� ���� ���� : 0:����, 1:���� */
#define ELM_DISP_SG_STATE_MAINLAMP_GO					0x10 /** �ֽ�ȣ�� �������� ���� : 0:��������, 1:�������� */
#define ELM_DISP_SG_STATE_MAINLAMP_FAILURE				0x20 /** �ֽ�ȣ�� ���� ���� : 0:����, 1:���� */
#define ELM_DISP_SG_STATE_RTSEL_ON						0x40 /** ���μ����� ���� ���� : 0:�ҵ�, 1:���� */
#define ELM_DISP_SG_STATE_RTSEL_FAILURE					0x80 /** ���μ����� ���� ���� : 0:����, 1:���� */
/* ��ȣ�� �Ϲ����� State ǥ������ */
/* (��)������ȣ��� State ǥ������ */
#define ELM_DISP_SG_ULAMP_COLOR_1_GREEN					0x01 /** (��)�������� ���� : 0:���-�ҵ�, 1:���-����, AND masking���� Setting  ���� Ȯ�� */
/* TTB ������ State ǥ������ */
#define ELM_DISP_SG_TTBLAMP_COLOR_1_YELLOW				0x02 /** TTB ���� ���� : 0:���-OFF, 1:Ȳ��-ON,���ڻ�:���, AND masking���� Setting  ���� Ȯ�� */
/* ��ȣ���� ������ State ǥ������ */
#define ELM_DISP_SG_LOCKLAMP_COLOR_0_BLACK				0x00 /** �������� ���� : ��� */
#define ELM_DISP_SG_LOCKLAMP_COLOR_1_YELLOW				0x04 /** �������� ���� : Ȳ�� */
#define ELM_DISP_SG_LOCKLAMP_COLOR_2_YELLOW_F_BLACK		0x08 /** �������� ���� : Ȳ������ (�������) */
#define ELM_DISP_SG_LOCKLAMP_COLOR_3_YELLOW_F_BLACK		0x0C /** �������� ���� : Ȳ������ (�������) */
/* Mask */
#define ELM_DISP_SG_LOCKLAMP_MASK						0x0C /** D2~D3 */
/* ��ȣ���� ��ȣ�� State ǥ������ */
#define ELM_DISP_SG_MAINLAMP_COLOR_0_RED				0x00 /** ��ȣ���� ���� : ���� */
#define ELM_DISP_SG_MAINLAMP_COLOR_1_GREEN				0x10 /** ��ȣ���� ���� : ��� */
#define ELM_DISP_SG_MAINLAMP_COLOR_2_RED_F_BLACK		0x20 /** ��ȣ���� ���� : �������� (�������) */
#define ELM_DISP_SG_MAINLAMP_COLOR_3_GREEN_F_BLACK		0x30 /** ��ȣ���� ���� : ������� (�������) */
/* Mask */
#define ELM_DISP_SG_MAINLAMP_MASK						0x30 /** D4~D5 */
/* ��ȣ���� ���μ����� State ǥ������ */
#define ELM_DISP_SG_RTSELM_COLOR_0_RED					0x00 /** ���μ������� ���� : �帰ȸ�� */
#define ELM_DISP_SG_RTSELM_COLOR_1_YELLOW				0x40 /** ���μ������� ���� : Ȳ�� */
#define ELM_DISP_SG_RTSELM_COLOR_2_YELLOW_F_LGRAY		0x80 /** ���μ������� ���� : Ȳ������(�帰ȸ������) */
/* Mask */
#define ELM_DISP_SG_RTSELM_MASK							0xC0 /** D6~D7 */

/* ������� ��ȣ�� State ǥ������ */
#define ELM_DISP_SG_INBLOCK_COLOR_0_RED					0x00 /** ������� ��ȣ���� Lamp ���� : ���� */
#define ELM_DISP_SG_INBLOCK_COLOR_1_GREEN				0x10 /** ������� ��ȣ���� Lamp ���� : ��� */
#define ELM_DISP_SG_INBLOCK_COLOR_2_RED_F_BLACK			0x20 /** ������� ��ȣ���� Lamp ���� : ���� ���� (�������) */
#define ELM_DISP_SG_INBLOCK_COLOR_3_GREEN_F_BLACK		0x30 /** ������� ��ȣ���� Lamp ���� : ��� ���� (�������) */
/* Mask */
#define ELM_DISP_SG_INBLOCK_MASK						0x30 /** D4~D5 */
/* ������� ��ȣ�� State ǥ������ */
#define ELM_DISP_SG_OUTBLOCK_COLOR_0_RED				0x00 /** ������� ��ȣ���� Lamp ���� : ���� */
#define ELM_DISP_SG_OUTBLOCK_COLOR_1_WHITE				0x10 /** ������� ��ȣ���� Lamp ���� : ��� */
#define ELM_DISP_SG_OUTBLOCK_COLOR_2_RED_F_BLACK		0x20 /** ������� ��ȣ���� Lamp ���� : ���� ���� (�������) */
#define ELM_DISP_SG_OUTBLOCK_COLOR_3_RED_F_BLACK		0x30 /** ������� ��ȣ���� Lamp ���� : ���� ���� (�������) */
/* Mask */
#define ELM_DISP_SG_OUTBLOCK_MASK						0x30 /** D4~D5 */

/* ����/�ڵ� ��� State ǥ������ */
#define ELM_DISP_BLOCKSSTART_COLOR_0_LIGHTGRAY			0x00 /** ����/�ڵ� ����� ����� ���� : �帰ȸ��, ����(�ҵ�) */
#define ELM_DISP_BLOCKSSTART_COLOR_1_YELLOW_F_LIGHTGRAY	0x01 /** ����/�ڵ� ����� ����� ���� : Ȳ������(�帰ȸ������), ���/��ҿ䱸 (��߿�-��߹���ǥ)(6�ʰ� ����) */
#define ELM_DISP_BLOCKSSTART_COLOR_2_YELLOW				0x02 /** ����/�ڵ� ����� ����� ���� : Ȳ��, ��߽���/������� (��߿�-��߹���ǥ) */
/*#define ELM_DISP_BLOCKSSTART_COLOR_3_					0x03*/ /** ����/�ڵ� ����� ����� ���� : ��ȭ���� - ����, ������ ���� */
#define ELM_DISP_BLOCKSSTART_COLOR_4_RED				0x04 /** ����/�ڵ� ����� ����� ���� : ����, �������� (��߿�-��߹���ǥ) */
/*#define ELM_DISP_BLOCKSSTART_COLOR_5_					0x05*/ /** ����/�ڵ� ����� ����� ���� : ��ȭ���� - ����, ������ ���� */
/*#define ELM_DISP_BLOCKSSTART_COLOR_6_					0x06*/ /** ����/�ڵ� ����� ����� ���� : ��ȭ���� - ����, ������ ���� */
/*#define ELM_DISP_BLOCKSSTART_COLOR_7_					0x07*/ /** ����/�ڵ� ����� ����� ���� : ��ȭ���� - ����, ������ ���� */
#define ELM_DISP_BLOCKSSTART_COLOR_8_RED_F_LIGHTGRAY	0x08 /** ����/�ڵ� ����� ����� ���� : ��������(�帰ȸ������), ����䱸 �� (��߿�-��߹���ǥ) */
/*#define ELM_DISP_BLOCKSSTART_COLOR_9_					0x09*/ /** ����/�ڵ� ����� ����� ���� : ��ȭ���� - ����, ������ ���� */
/*#define ELM_DISP_BLOCKSSTART_COLOR_10_					0x0A*/ /** ����/�ڵ� ����� ����� ���� : ��ȭ���� - ����, ������ ���� */
/*#define ELM_DISP_BLOCKSSTART_COLOR_11_					0x0B*/ /** ����/�ڵ� ����� ����� ���� : ��ȭ���� - ����, ������ ���� */
/*#define ELM_DISP_BLOCKSSTART_COLOR_12_					0x0C*/ /** ����/�ڵ� ����� ����� ���� : ��ȭ���� - ����, ������ ���� */
/*#define ELM_DISP_BLOCKSSTART_COLOR_13_					0x0D*/ /** ����/�ڵ� ����� ����� ���� : ��ȭ���� - ����, ������ ���� */
/*#define ELM_DISP_BLOCKSSTART_COLOR_14_					0x0E*/ /** ����/�ڵ� ����� ����� ���� : ��ȭ���� - ����, ������ ���� */
/*#define ELM_DISP_BLOCKSSTART_COLOR_15_					0x0F*/ /** ����/�ڵ� ����� ����� ���� : ��ȭ���� - ����, ������ ���� */
#define ELM_DISP_BLOCKSHOME_COLOR_0_LIGHTGRAY			0x00 /** ����/�ڵ� ����� ����� ���� : �帰ȸ��, ����(�ҵ�) */
#define ELM_DISP_BLOCKSHOME_COLOR_1_YELLOW_F_LIGHTGRAY	0x10 /** ����/�ڵ� ����� ����� ���� : Ȳ������(�帰ȸ������), ���/��ҿ䱸 (������-�峻����ǥ)(6�ʰ� ����) */
#define ELM_DISP_BLOCKSHOME_COLOR_2_YELLOW				0x20 /** ����/�ڵ� ����� ����� ���� : Ȳ��, �峻���� (������-�峻����ǥ) */
/*#define ELM_DISP_BLOCKSHOME_COLOR_3_					0x30*/ /** ����/�ڵ� ����� ����� ���� : ��ȭ���� - ����, ������ ���� */
#define ELM_DISP_BLOCKSHOME_COLOR_4_RED					0x40 /** ����/�ڵ� ����� ����� ���� : ����, ��������/������� (������-�峻����ǥ) */
/*#define ELM_DISP_BLOCKSHOME_COLOR_5_					0x50*/ /** ����/�ڵ� ����� ����� ���� : ��ȭ���� - ����, ������ ���� */
/*#define ELM_DISP_BLOCKSHOME_COLOR_6_					0x60*/ /** ����/�ڵ� ����� ����� ���� : ��ȭ���� - ����, ������ ���� */
/*#define ELM_DISP_BLOCKSHOME_COLOR_7_					0x70*/ /** ����/�ڵ� ����� ����� ���� : ��ȭ���� - ����, ������ ���� */
#define ELM_DISP_BLOCKSHOME_COLOR_8_RED_F_LIGHTGRAY		0x80 /** ����/�ڵ� ����� ����� ���� : ��������(�帰ȸ������), ����䱸 (������-�峻����ǥ) */
/*#define ELM_DISP_BLOCKSHOME_COLOR_9_					0x90*/ /** ����/�ڵ� ����� ����� ���� : ��ȭ���� - ����, ������ ���� */
/*#define ELM_DISP_BLOCKSHOME_COLOR_10_					0xA0*/ /** ����/�ڵ� ����� ����� ���� : ��ȭ���� - ����, ������ ���� */
/*#define ELM_DISP_BLOCKSHOME_COLOR_11_					0xB0*/ /** ����/�ڵ� ����� ����� ���� : ��ȭ���� - ����, ������ ���� */
/*#define ELM_DISP_BLOCKSHOME_COLOR_12_					0xC0*/ /** ����/�ڵ� ����� ����� ���� : ��ȭ���� - ����, ������ ���� */
/*#define ELM_DISP_BLOCKSHOME_COLOR_13_					0xD0*/ /** ����/�ڵ� ����� ����� ���� : ��ȭ���� - ����, ������ ���� */
/*#define ELM_DISP_BLOCKSHOME_COLOR_14_					0xE0*/ /** ����/�ڵ� ����� ����� ���� : ��ȭ���� - ����, ������ ���� */
/*#define ELM_DISP_BLOCKSHOME_COLOR_15_					0xF0*/ /** ����/�ڵ� ����� ����� ���� : ��ȭ���� - ����, ������ ���� */
/* Mask */
#define ELM_DISP_BLOCKSSTART_MASK						0x0F /** D0~D3 */
#define ELM_DISP_BLOCKSHOE_MASK							0xF0 /** D4~D7 */

/* ������ȯ�� �Ϲ����� State ���� */
#define ELM_DISP_PT_GI_STATE_N_POSITION					0x01 /** ������ȯ�� ���� ���� : 0:�ƴ�, 1:�������� */
#define ELM_DISP_PT_GI_STATE_R_POSITION					0x02 /** ������ȯ�� ���� ���� : 0:�ƴ�, 1:�������� */
#define ELM_DISP_PT_GI_STATE_LOCK						0x04 /** ������ȯ�� ���� ���� : 0:����, 1:����(ö�� or ����)  */
#define ELM_DISP_PT_GI_STATE_FAILURE					0x08 /** ������ȯ�� ���� ���� : 0:����, 1:���� */
#define ELM_DISP_PT_GI_STATE_OL_ONTIMER					0x10 /** ������ȯ�� ������ ���� �ü� ���� : 0:����, 1:�ü� �� */
#define ELM_DISP_PT_GI_STATE_SWLOCK						0x20 /** ������ȯ�� ��ȯ �Ұ����� : 0:��ȯ����, 1:��ȯ�Ұ� */
#define ELM_DISP_PT_GI_STATE_NWRI						0x40 /** ������ȯ�� WR ���� ���� ���� : 0:�������, 1:���� ���� */
#define ELM_DISP_PT_GI_STATE_RWRI						0x80 /** ������ȯ�� WR ���� ���� ���� : 0:�������, 1:���� ���� */
/* ������ȯ�� �Ϲ����� State ǥ������ */
#define ELM_DISP_PT_GI_COLOR_00_WHITE_BLACK_QMARK		0x00 /** ������ȯ�� ������ ���� : ? ����۾� (�������), ����ġ ���� */
#define ELM_DISP_PT_GI_COLOR_01_WHITE_BLACK_PSIGN		0x01 /** ������ȯ�� ������ ���� : + ����۾� (�������), ���� ���� */
#define ELM_DISP_PT_GI_COLOR_02_WHITE_BLACK_MSIGN		0x02 /** ������ȯ�� ������ ���� : - ����۾� (�������), ���� ���� */
/*#define ELM_DISP_PT_GI_COLOR_03_						0x03*/ /** ������ȯ�� ������ ���� : ���� - ������ ���� (���� & ���� ���� ���� ����) */
#define ELM_DISP_PT_GI_COLOR_04_BLACK_YELLOW_QMARK		0x04 /** ������ȯ�� ������ ���� : ? ����۾� (Ȳ������) */
#define ELM_DISP_PT_GI_COLOR_05_BLACK_YELLOW_PSIGN		0x05 /** ������ȯ�� ������ ���� : + ����۾� (Ȳ������) */
#define ELM_DISP_PT_GI_COLOR_06_BLACK_YELLOW_MSIGN		0x06 /** ������ȯ�� ������ ���� : - ����۾� (Ȳ������) */
/*#define ELM_DISP_PT_GI_COLOR_07_						0x07*/ /** ������ȯ�� ������ ���� : ���� - ������ ���� (���� & ���� ���� ���� ����) */
#define ELM_DISP_PT_GI_COLOR_08_WHITE_BLACK_QMARK		0x08 /** ������ȯ�� ������ ���� : ? ����۾� (�������) */
#define ELM_DISP_PT_GI_COLOR_09_WHITE_BLACK_PSIGN		0x09 /** ������ȯ�� ������ ���� : + ����۾� (�������) */
#define ELM_DISP_PT_GI_COLOR_0A_WHITE_BLACK_MSIGN		0x0A /** ������ȯ�� ������ ���� : - ����۾� (�������) */
/*#define ELM_DISP_PT_GI_COLOR_0B_						0x0B*/ /** ������ȯ�� ������ ���� : ���� - ������ ���� (���� & ���� ���� ���� ����) */
#define ELM_DISP_PT_GI_COLOR_0C_BLACK_YELLOW_QMARK		0x0C /** ������ȯ�� ������ ���� : ? ����۾� (Ȳ������) */
#define ELM_DISP_PT_GI_COLOR_0D_BLACK_YELLOW_PSIGN		0x0D /** ������ȯ�� ������ ���� : + ����۾� (Ȳ������) */
#define ELM_DISP_PT_GI_COLOR_0E_BLACK_YELLOW_MSIGN		0x0E /** ������ȯ�� ������ ���� : - ����۾� (Ȳ������) */
/*#define ELM_DISP_PT_GI_COLOR_0F_						0x0F*/ /** ������ȯ�� ������ ���� : ���� - ������ ���� (���� & ���� ���� ���� ����) */
#define ELM_DISP_PT_GI_COLOR_10_BLACK_YELLOW_F_QMARK	0x10 /** ������ȯ�� ������ ���� : ? ����۾� (Ȳ������, �������) */
#define ELM_DISP_PT_GI_COLOR_11_BLACK_YELLOW_F_PSIGN	0x11 /** ������ȯ�� ������ ���� : + ����۾� (Ȳ������, �������) */
#define ELM_DISP_PT_GI_COLOR_12_BLACK_YELLOW_F_MSIGN	0x12 /** ������ȯ�� ������ ���� : - ����۾� (Ȳ������, �������) */
/*#define ELM_DISP_PT_GI_COLOR_13_						0x13*/ /** ������ȯ�� ������ ���� : ���� - ������ ���� (���� & ���� ���� ���� ����) */
#define ELM_DISP_PT_GI_COLOR_14_WHITE_BLACK_QMARK		0x14 /** ������ȯ�� ������ ���� : ? ����۾� (Ȳ������, �������) */
#define ELM_DISP_PT_GI_COLOR_15_WHITE_BLACK_PSIGN		0x15 /** ������ȯ�� ������ ���� : + ����۾� (Ȳ������, �������) */
#define ELM_DISP_PT_GI_COLOR_16_WHITE_BLACK_MSIGN		0x16 /** ������ȯ�� ������ ���� : - ����۾� (Ȳ������, �������) */
/*#define ELM_DISP_PT_GI_COLOR_17_						0x17*/ /** ������ȯ�� ������ ���� : ���� - ������ ���� (���� & ���� ���� ���� ����) */
#define ELM_DISP_PT_GI_COLOR_18_WHITE_BLACK_QMARK		0x18 /** ������ȯ�� ������ ���� : ? ����۾� (Ȳ������, �������) */
#define ELM_DISP_PT_GI_COLOR_19_WHITE_BLACK_PSIGN		0x19 /** ������ȯ�� ������ ���� : + ����۾� (Ȳ������, �������) */
#define ELM_DISP_PT_GI_COLOR_1A_WHITE_BLACK_MSIGN		0x1A /** ������ȯ�� ������ ���� : - ����۾� (Ȳ������, �������) */
/*#define ELM_DISP_PT_GI_COLOR_1B_						0x1B*/ /** ������ȯ�� ������ ���� : ���� - ������ ���� (���� & ���� ���� ���� ����) */
#define ELM_DISP_PT_GI_COLOR_1C_WHITE_BLACK_QMARK		0x1C /** ������ȯ�� ������ ���� : ? ����۾� (Ȳ������, �������) */
#define ELM_DISP_PT_GI_COLOR_1D_WHITE_BLACK_PSIGN		0x1D /** ������ȯ�� ������ ���� : + ����۾� (Ȳ������, �������) */
#define ELM_DISP_PT_GI_COLOR_1E_WHITE_BLACK_MSIGN		0x1E /** ������ȯ�� ������ ���� : - ����۾� (Ȳ������, �������) */
/*#define ELM_DISP_PT_GI_COLOR_1F_						0x1F*/ /** ������ȯ�� ������ ���� : ���� - ������ ���� (���� & ���� ���� ���� ����) */
/* ������ȯ�� ���忩�� state ����*/
#define ELM_DISP_PT_GI_FAILURE							0x08 /** D3, AND masking���� Setting  ���� Ȯ�� */
/* ������ȯ�� ��ȯ �� state ǥ������ */
#define ELM_DISP_PT_GI_COLOR_1_ORANGE_F					0x20 /** ������ȯ�� ���Ե� �˵�ȸ�� ���� : Ȳ������(�˵�ȸ��ǥ�ù���), AND masking���� Setting  ���� Ȯ��  */
/* ������ȯ�� ��ȯ State ���� */
#define ELM_DISP_PT_GI_MOV_0_NONE						0x00 /** ������ȯ�� ��ȯ �� ���� : ����  */
#define ELM_DISP_PT_GI_MOV_1_MOVING_NOCTRL				0x20 /** ������ȯ�� ��ȯ �� ���� : ��ȯ�� ����, ����䱸 ���� ������(����ġ)  */
#define ELM_DISP_PT_GI_MOV_2_REQ_N						0x40 /** ������ȯ�� ��ȯ �� ���� : ���� ��ȯ �䱸 */
#define ELM_DISP_PT_GI_MOV_3_MOVING_N					0x60 /** ������ȯ�� ��ȯ �� ���� : ������ ��ȯ �� */
#define ELM_DISP_PT_GI_MOV_4_REQ_R						0x80 /** ������ȯ�� ��ȯ �� ���� : ���� ��ȯ �䱸 */
#define ELM_DISP_PT_GI_MOV_5_MOVING_R					0xA0 /** ������ȯ�� ��ȯ �� ���� : ������ ��ȯ �� */
/*#define ELM_DISP_PT_GI_MOV_6_							0xC0*/ /** ������ȯ�� ��ȯ �� ���� : ����-������ ���� (���� & ���� ��ȯ �䱸) */
/*#define ELM_DISP_PT_GI_MOV_7_							0xE0*/ /** ������ȯ�� ��ȯ �� ���� : ����-������ ���� (���� & ���� ��ȯ ��) */
/* Mask */
#define ELM_DISP_PT_GI_STATE_MASK						0x1F /** D0~D4 */
#define ELM_DISP_PT_GI_MOVING_MASK						0xE0 /** D5~D7 */

/* General I/O �ǳθ� �������� State ���� */
#define ELM_DISP_LX_STATE_ALARMON						0x10 /** LX �˶��溸 �߻� ���� : 0:�溸����, 1:�溸 �߻� */
#define ELM_DISP_LX_STATE_GOOD							0x20 /** LX ���󿩺� : 0:����, 1:���� */
/* General I/O �ǳθ� �������� State ǥ������ */
#define ELM_DISP_LX_COLOR_0_RED							0x00 /** General I/O �ǳθ� ���������� ��ư ���� : ���� */
#define ELM_DISP_LX_COLOR_1_RED_F						0x10 /** General I/O �ǳθ� ���������� ��ư ���� : ���� ���� */
#define ELM_DISP_LX_COLOR_2_GREEN						0x20 /** General I/O �ǳθ� ���������� ��ư ���� : ��� */
/* Mask */
#define ELM_DISP_LX_STATE_MASK							0x30 /** D4~D5 */

/* General I/O ���幰������ġ State ���� */
#define ELM_DISP_OBSTRUCTION_STATE_ALARMON				0x10 /** ���幰������ġ �������� �˶��溸 �߻� ���� : 0:�溸����, 1:�溸 �߻� */
#define ELM_DISP_OBSTRUCTION_STATE_GOOD					0x20 /** ���幰������ġ �������� ���󿩺� : 0:����, 1:���� */
#define ELM_DISP_OBSTRUCTION_STATE_SECURITYRELEASE		0x40 /** ���幰������ġ �������� �������� ��޿���: 0:�����������, 1:�������� ��� */
/* General I/O ���幰������ġ �������� State ǥ������ */
#define ELM_DISP_OBSTRUCTION_COLOR_0_RED				0x00 /** General I/O ���幰������ġ ���������� ��ư ���� : ���� */
#define ELM_DISP_OBSTRUCTION_COLOR_1_RED_F				0x10 /** General I/O ���幰������ġ ���������� ��ư ���� : ���� ���� */
#define ELM_DISP_OBSTRUCTION_COLOR_2_GREEN				0x20 /** General I/O ���幰������ġ ���������� ��ư ���� : ��� */
#define ELM_DISP_OBS_SECURITY_RELEASE_COLOR_1_YELLOW	0x40 /** General I/O ���幰������ġ ���������� �ɺ� ���� : 0:�帰ȸ��-�����������, 1:Ȳ��-�����������, AND masking���� Setting  ���� Ȯ�� */
/* Mask */
#define ELM_DISP_OBSTRUCTION_STATE_MASK					0x30 /** D4~D5 */

/* General I/O ��������������ġ �������� State ���� */
#define ELM_DISP_INSULATION_STATE_SYS1ALARM				0x01 /** General I/O ��������������ġ ���������� 1�� �˶��溸 ���� : 0:�溸����, 1;�溸�߻�, AND masking���� Setting  ���� Ȯ�� */
#define ELM_DISP_INSULATION_STATE_SYS1GOOD				0x02 /** General I/O ��������������ġ ���������� 1�� ���� ���� : 0:����, 1;���� */
#define ELM_DISP_INSULATION_STATE_SYS1RUN				0x04 /** General I/O ��������������ġ ���������� 1�� ��� ���� : 0:���, 1;��� */
#define ELM_DISP_INSULATION_STATE_SYS2ALARM				0x10 /** General I/O ��������������ġ ���������� 2�� �˶��溸 ���� : 0:�溸����, 1;�溸�߻�, AND masking���� Setting  ���� Ȯ�� */
#define ELM_DISP_INSULATION_STATE_SYS2GOOD				0x20 /** General I/O ��������������ġ ���������� 2�� ���� ���� : 0:����, 1;���� */
#define ELM_DISP_INSULATION_STATE_SYS2RUN				0x40 /** General I/O ��������������ġ ���������� 2�� ��� ���� : 0:���, 1;��� */
/* General I/O ��������������ġ �������� State ǥ������ */
#define ELM_DISP_INSULATION_SYS1_COLOR_0_RED			0x00 /** General I/O ��������������ġ ���������� 1�� ��ư ���� : ����, 1�� ���� (�溸����) */
#define ELM_DISP_INSULATION_SYS1_COLOR_1_RED_F			0x01 /** General I/O ��������������ġ ���������� 1�� ��ư ���� : ���� ����, 1�� ���� (�溸�߻�) */
#define ELM_DISP_INSULATION_SYS1_COLOR_2_LIGHTGRAY		0x02 /** General I/O ��������������ġ ���������� 1�� ��ư ���� : �帰ȸ��, 1�� ���� (�溸����) */
#define ELM_DISP_INSULATION_SYS1_COLOR_3_				0x03 /** General I/O ��������������ġ ���������� 1�� ��ư ���� : ��ȭ���� - ����, ������ ���� (�溸����) */
#define ELM_DISP_INSULATION_SYS1_COLOR_4_				0x04 /** General I/O ��������������ġ ���������� 1�� ��ư ���� : ��ȭ���� - ����, ������ ���� (�溸����) */
#define ELM_DISP_INSULATION_SYS1_COLOR_5_				0x05 /** General I/O ��������������ġ ���������� 1�� ��ư ���� : ��ȭ���� - ����, ������ ���� (�溸����) */
#define ELM_DISP_INSULATION_SYS1_COLOR_6_GREEN			0x06 /** General I/O ��������������ġ ���������� 1�� ��ư ���� : ���, 1�� ��� (�溸����) */
#define ELM_DISP_INSULATION_SYS1_COLOR_7_				0x07 /** General I/O ��������������ġ ���������� 1�� ��ư ���� : ��ȭ���� - ����, ������ ���� (�溸����) */
#define ELM_DISP_INSULATION_SYS2_COLOR_0_RED			0x00 /** General I/O ��������������ġ ���������� 2�� ��ư ���� : ����, 2�� ���� (�溸����) */
#define ELM_DISP_INSULATION_SYS2_COLOR_1_RED_F			0x10 /** General I/O ��������������ġ ���������� 2�� ��ư ���� : ���� ����, 2�� ���� (�溸�߻�) */
#define ELM_DISP_INSULATION_SYS2_COLOR_2_LIGHTGRAY		0x20 /** General I/O ��������������ġ ���������� 2�� ��ư ���� : �帰ȸ��, 2�� ���� (�溸����) */
#define ELM_DISP_INSULATION_SYS2_COLOR_3_				0x03 /** General I/O ��������������ġ ���������� 2�� ��ư ���� : ��ȭ���� - ����, ������ ���� (�溸����) */
#define ELM_DISP_INSULATION_SYS2_COLOR_4_				0x04 /** General I/O ��������������ġ ���������� 2�� ��ư ���� : ��ȭ���� - ����, ������ ���� (�溸����) */
#define ELM_DISP_INSULATION_SYS2_COLOR_5_				0x05 /** General I/O ��������������ġ ���������� 2�� ��ư ���� : ��ȭ���� - ����, ������ ���� (�溸����) */
#define ELM_DISP_INSULATION_SYS2_COLOR_6_GREEN			0x60 /** General I/O ��������������ġ ���������� 2�� ��ư ���� : ���, 2�� ��� (�溸����) */
#define ELM_DISP_INSULATION_SYS2_COLOR_7_				0x70 /** General I/O ��������������ġ ���������� 2�� ��ư ���� : ��ȭ���� - ����, ������ ���� (�溸����) */
/* Mask */
#define ELM_DISP_INSULATION_SYS1_STATE_MASK				0x07 /** D0~D2 */
#define ELM_DISP_INSULATION_SYS2_STATE_MASK				0x70 /** D4~D6 */

/* General I/O Ȯ�巢 ������ State ���� */
#define ELM_DISP_RECTIFIER_STATE_ALARMON				0x10 /** General I/O Ȯ�巢 ������ �˶��溸 �߻� ���� : 0:�溸����, 1:�溸 �߻� */
#define ELM_DISP_RECTIFIER_STATE_GOOD					0x20 /** General I/O Ȯ�巢 ������ ���󿩺� : 0:����, 1:���� */
/* General I/O Ȯ�巢 ������ State ǥ������ */
#define ELM_DISP_RECTIFIER_COLOR_0_RED					0x00 /** General I/O Ȯ�巢 ������ ������ ��ư ���� : ����, ��� (�溸����) */
#define ELM_DISP_RECTIFIER_COLOR_1_RED_F				0x10 /** General I/O Ȯ�巢 ������ ������ ��ư ���� : ���� ����, ��� (�溸�߻�) */
#define ELM_DISP_RECTIFIER_COLOR_2_GREEN				0x20 /** General I/O Ȯ�巢 ������ ������ ��ư ���� : ���, ���� */
/* Mask */
#define ELM_DISP_RECTIFIER_STATE_MASK					0x30 /** D4~D5 */
/* Rotue State ǥ�� ����*/
#define ELM_DISP_ROUTE_YLMR								0x01	/** YLMR ON, 0:OFF, 1:ON */
#define ELM_DISP_ROUTE_GLMR								0x02	/** GLMR ON, 0:OFF, 1:ON */
#define ELM_DISP_ROUTE_T1LMR							0x04	/** Y1LMR ON, 0:OFF, 1:ON */
#define ELM_DISP_ROUTE_RT_ON							0x10	/** ���μ��� ON, (0:��������, 1:���μ���) */
#define ELM_DISP_ROUTE_CTRLREQ							0x20	/** ���μ��� ����䱸 ON, (0:�������, 1:����䱸) */
#define ELM_DISP_ROUTE_CTRL_DISABLE						0x40	/** ���μ��� ����Ұ� ON, (0:�������, 1:����Ұ�) */
#define ELM_DISP_ROUTE_CTRL_EN_RECTRL					0x80	/** ��������� ���� ON, (0:����޺Ұ�, 1:����ް���) */
/* Mask */
#define ELM_DISP_ROUTE_LMR_STATE_MASK					0x07	/** ������ ��ȣ�� LMR ���� */
#define ELM_DISP_ROUTE_CTRL_RT_MASK						0x30	/** ���� ������� ���� mask */
#define ELM_DISP_ROUTE_EN_CTRL_MASK						0x3F	/** ���� ��� ��� ���� ���� ����,(��� ��� + ����� �Ұ�) */

#endif
/* ///////////////////////////////////////////////////////////////////////// */
/* Element Control Code�� ����                                               */
/* ///////////////////////////////////////////////////////////////////////// */
#define ELM_CTRLCODE_ALARMSTOP				0x10	/** Alarm Bell ���� ���� ��� (Parameter: Control Code + Element ID + Alarm Stop Data)*/
/** Alarm Bell ���� ���� ����� ���� Element List
*  SYS1, SYS2, N1, N2, UPS, RECTIFIER, BATTERY, FUSE, PNPOWER, PSPOWER, SGFAIL, PTFAIL, TRFAIL,TR_GI,GIO_LX
*/
#define ELM_CTRLCODE_AOFF					0x10	/** �˶��溸���� ����, Alarm OFF */
#define ELM_CTRLCODE_COMMON_RUN				0x11	/** ������ ��� ���� ��� - �ý��� �⵿ (Parameter: Control Code + Common ID + Element Control Data) */
#define ELM_CTRLCODE_COMMON_OPMODE			0x12	/** ������ ��� ���� ��� - ���� ��ü (Parameter: Control Code + Common ID + Element Control Data) */
#define ELM_CTRLCODE_COMMON_SGSTOP			0x13	/** ������ ��� ���� ��� - ��ȣ�� �ϰ����� ����/���� (Parameter: Control Code + Common Element No.ID + Element Control Data) */
#define ELM_CTRLCODE_COMMON_SHOFF			0x14	/** ������ ��� ���� ��� - ��ȯ��ȣ�� �ҵ� ����/���� (Parameter: Control Code + Common Element No.ID + Element Control Data) */
#define ELM_CTRLCODE_COMMON_HEATER			0x15	/** ������ ��� ���� ��� - ���� ON/OFF ���� (Parameter: Control Code + Common Element No.ID + Element Control Data) */
#define ELM_CTRLCODE_COMMON_PTPOWER			0x16	/** ������ ��� ���� ��� - ������ȯ�� ����/���� ���� ON/OFF ���� (Parameter: Control Code + Common Element No.ID + Element Control Data) */
#define ELM_CTRLCODE_TRACK					0x20	/** �˵�ȸ�� ���� ��� (Parameter: Control Code + TRACK Element No.ID + Element Control Data) */
#define ELM_CTRLCODE_TRACKFAIL				0x21	/** �˵�ȸ�� �������� ���� ��� (Parameter: Control Code + TRACK Element No.ID + Element Control Data) */
#define ELM_CTRLCODE_POINT					0x30	/** ������ȯ�� ��ȯ ���� ��� (Parameter: Control Code + Point Element No.ID + Element Control Data) */
#define ELM_CTRLCODE_ROUTE					0x40	/** ���� ���� �� ���� ��� (Parameter: Control Code + Route Element No.ID + Element Control Data) */
#define ELM_CTRLCODE_SIGNAL					0x50	/** ��ȣ�� ���� ��� (Parameter: Control Code + Signal Element No.ID + Element Control Data) */
#define ELM_CTRLCODE_BLOCK					0x60	/** ��� ���� ��� (Parameter: Control Code + Signal(Block) Element No.ID + Element Control Data) */
#define ELM_CTRLCODE_CATIONLABEL			0x70	/** �����������ǥ ���� ��� (Parameter: Control Code + Track Element No.ID + Element Control Data) */
#define ELM_CTRLCODE_GIO					0x90	/** GIO ���� */
#define ELM_CTRLCODE_GIO_OBSTRUCTION		0x91	/** General I/O ���幰������ġ �������� ������� ��� (Parameter: Control Code + GIO Element No.ID + Element Control Data) */
#define ELM_CTRLCODE_GIO_INSULATION			0x92	/** General I/O ��������������ġ �������� ������� ��� (Parameter: Control Code + GIO Element No.ID + Element Control Data) */

/* ���� ������ ���� */
#define ELM_CTRL_SYS_ALARM_OFF				0x10	/** Alarm OFF */
#define ELM_CTRL_GIO_ALARM1_OFF				0x01	/** ��������������ġ 1�� Alarm OFF */
#define ELM_CTRL_GIO_ALARM2_OFF				0x10	/** ��������������ġ 2�� Alarm OFF */

#define ELM_CTRL_SYS_CTC_SW_REQ				0x01	/** CTC ��ȯ ��û by CTC element */

#define ELM_CTRL_SYS_LOCAL_SW_REQ			0x04	/** LOCAL ��ȯ �䱸 by LOCAL element */
#define ELM_CTRL_SYS_LOCAL_SW_APPROVAL		0x08	/** LOCAL ��ȯ ���� by LOCAL element */
#define ELM_CTRL_SYS_LOCAL_CANCEL_CTC		0x08	/** CTC ��ȯ ���� �� ��� by LOCAL element */
#define ELM_CTRL_SYS_LOCAL_CANCEL_RC		0x08	/** RC ��ȯ �䱸 by LOCAL element */
#define ELM_CTRL_SYS_LOCAL_SW_EMREQ			0x10	/** LOCAL �����ȯ by LOCAL element */

#define ELM_CTRL_SYS_RC_SW_REQ				0x20	/** RC ��ȯ �䱸 by RC element */
#define ELM_CTRL_SYS_RC_SW_APPROVAL			0x40	/** RC ��ȯ ���� by RC element */
#define ELM_CTRL_SYS_RC_CANCEL_CTC			0x40	/** CTC ��ȯ ���� �� ��� by RC element */
#define ELM_CTRL_SYS_RC_CANCEL_LOCAL		0x40	/** RC ��ȯ �䱸 by RC element */
#define ELM_CTRL_SYS_RC_SW_EMREQ			0x80	/** RC �����ȯ by RC element */

#define ELM_CTRL_SYS_PTPOWER_ON				0x20	/** ������ȯ�� ��/�� ���� ON ���� �䱸 */
#define ELM_CTRL_SYS_PTPOWER_OFF			0x40	/** ������ȯ�� ��/�� ���� OFF ���� �䱸 */

#define ELM_CTRL_SG_ALLSTOP_SET				0x10	/** ��ȣ�� �ϰ����� �����䱸 */
#define ELM_CTRL_SG_ALLSTOP_RELEASE			0x20	/** ��ȣ�� �ϰ����� �����䱸 */
#define ELM_CTRL_SG_SHUNTOFF_SET			0x10	/** ��ȯ(��ȣ��)ǥ�� �ҵ����� �����䱸 */
#define ELM_CTRL_SG_SHUNTOFF_RELEASE		0x20	/** ��ȯ(��ȣ��)ǥ�� �ҵ����� �����䱸 */

#define ELM_CTRL_SYS_HEATER_ON				0x20	/** ���� ON ���� �䱸 */
#define ELM_CTRL_SYS_HEATER_OFF				0x40	/** ���� OFF ���� �䱸 */

#define ELM_CTRL_TR_RT_EM_RELEASE			0x20	/** �������κ������ by track */

#define ELM_CTRL_LABEL_LOC_POS2				0x40	/** ǥ����� ����� �����ġ�� ���� �Ϻ��� ��� ���� */
#define ELM_CTRL_LABEL_SET_CMD				0x80	/** ǥ����� ��� ���� */

#define ELM_CTRL_SG_RELEASE					0x10	/** ��ȣ�� ���� (��������) �䱸 */

#define ELM_CTRL_BLOCK_START_REQ			0x01	/** ��� ���-��߿�û */
#define ELM_CTRL_BLOCK_HOME_APPROVAL		0x02	/** ��� �峻-�峻���� */
#define ELM_CTRL_BLOCK_OPEN_REQ				0x04	/** ��� ����-�����û */
#define ELM_CTRL_BLOCK_OPEN_APPROVAL		0x08	/** ��� ����-������� */
#define ELM_CTRL_BLOCK_CANCEL_REQ			0x10	/** ��� ���-��ҿ�û */
#define ELM_CTRL_BLOCK_CANCEL_APPROVAL		0x20	/** ��� ���-��ҽ��� */

#define ELM_CTRL_POINT_N_SWITCH_REQ			0x10	/** ������ȯ�� ���� ��ȯ ���� �䱸 */
#define ELM_CTRL_POINT_R_SWITCH_REQ			0x20	/** ������ȯ�� ���� ��ȯ ���� �䱸 */

#define ELM_CTRL_ROUTE_SET					0x01	/** ���μ��� �䱸 */
#define ELM_CTRL_ROUTE_TTB_ON				0x04	/** TTB ���� �䱸 */
#define ELM_CTRL_ROUTE_TTB_OFF				0x08	/** TTB ��� �䱸 */
#define ELM_CTRL_ROUTE_RELEASE				0x10	/** ���� ���� �䱸 */
#define ELM_CTRL_ROUTE_RESET				0x20	/** ���� ����� ���� �䱸 */

/* ///////////////////////////////////////////////////////////////////////// */
/* ǥ�������� ���� Element Data ����ü ����                                  */
/* ///////////////////////////////////////////////////////////////////////// */

/* ------------------------------------------------------------------------- */
/* for ZEST EI and WINDOWS(INTEL Style) : LITTLE ENDIAN                                  */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* RUN State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_RUN
* @brief �� ���� ������(Common Data)�� RUN Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES      : 2;	 /** D0~D1, ������� ����, 0 ������ */
	uint32 bSys1Run  : 1;	 /** D2, 0:������ ����-1�� ���, 1:������ ���-1�� �⵿ */
	uint32 bSys2Run  : 1;	 /** D3, 0:����   ����-2�� ���, 1:����   ���-2�� �⵿ */
	uint32 bSys1good : 1;	 /** D4, 0:1�� ���, 1:1�� ���� */
	uint32 bSys2Good : 1;	 /** D5, 0:2�� ���, 1:2�� ���� */
	uint32 bRES1     : 2;	 /** D6~D7, ������� ����, 0 ������ */
} TS_ELM_DISP_RUN;

/* ------------------------------------------------------------------------- */
/* CTC/LOCAL/RC State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_OPMODE
* @brief �� ���� ������(Common Data)�� CTC/LOCAL/RC Mode Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bCtcReq   : 1;	 /** D0, 0:�������, 1:CTC ��ȯ�䱸 */
	uint32 bCtcRun   : 1;	 /** D1, 0:�����, 1:CTC ���� */
	uint32 bLocalReq : 1;	 /** D2, 0:�������, 1:LOCAL ���� */
	uint32 bLocalRun : 1;	 /** D3, 0:�����, 1:LOCAL ���� */
	uint32 bRcReq    : 1;	 /** D4, 0:�������, 1:RC ���� */
	uint32 bRcRun    : 1;	 /** D5, 0:�����, 1:RC ���� */
	uint32 bRES      : 2;	 /** D6~D7, ������� ����, 0 ������ */
} TS_ELM_DISP_OPMODE;

/* ------------------------------------------------------------------------- */
/* SYSTEM 1�� State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_SYS1
* @brief �� ���� ������(Common Data)�� SYSTEM 1�� Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES      : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bAlarmOn  : 1;	 /** D4, 0:SYSTEM 1�� alarm ����, 1:SYSTEM 1�� alarm �溸 */
	uint32 bSys1Good : 1;	 /** D5, 0:SYSTEM 1�� ����, 1: SYSTEM 1�� ���� */
	uint32 bActive   : 1;	 /** D6, 0:SYSTEM 1�� Standby, 1:SYSTEM 1�� Active */
	uint32 bRES1     : 1;	 /** D7, ������� ����, 0 ������ */
} TS_ELM_DISP_SYS1;

/* ------------------------------------------------------------------------- */
/* SYSTEM 2�� State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_SYS2
* @brief �� ���� ������(Common Data)�� SYSTEM 2�� Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES      : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bAlarmOn  : 1;	 /** D4, 0:SYSTEM 2�� alarm ����, 1:SYSTEM 2�� alarm �溸 */
	uint32 bSys2Good : 1;	 /** D5, 0:SYSTEM 2�� ����, 1: SYSTEM 2�� ���� */
	uint32 bActive   : 1;	 /** D6, 0:SYSTEM 2�� Standby, 1:SYSTEM 2�� Active */
	uint32 bRES1     : 1;	 /** D7, ������� ����, 0 ������ */
} TS_ELM_DISP_SYS2;

/* ------------------------------------------------------------------------- */
/* �������� N1 State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_N1
* @brief �� ���� ������(Common Data)�� �������� N1 Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES      : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bAlarmOn  : 1;	 /** D4, 0:�溸����, 1:�溸�︲ */
	uint32 bX1Good   : 1;	 /** D5, 0:X1 ����, 1:X1 ���� */
	uint32 bN1Supply : 1;	 /** D6, 0:N1 ���, 1:N1 ���� */
	uint32 bRES1     : 1;	 /** D7, ������� ����, 0 ������ */
} TS_ELM_DISP_N1;

/* ------------------------------------------------------------------------- */
/* ö������ N2 State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_N2
* @brief �� ���� ������(Common Data)�� ö������ N2 Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES      : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bAlarmOn  : 1;	 /** D4, 0:�溸����, 1:�溸�︲ */
	uint32 bX2Good   : 1;	 /** D5, 0:X2 ����, 1:X2 ���� */
	uint32 bN2Supply : 1;	 /** D6, 0:N2 ���, 1:N2 ���� */
	uint32 bRES1     : 1;	 /** D7, ������� ����, 0 ������ */
} TS_ELM_DISP_N2;

/* ------------------------------------------------------------------------- */
/* UPS State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_UPS
* @brief �� ���� ������(Common Data)�� UPS Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES      : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bAlarmOn  : 1;	 /** D4, 0:�溸����, 1:�溸�︲ */
	uint32 bUpsGood  : 1;	 /** D5, 0:UPS ����, 1:UPS ���� */
	uint32 bRES1     : 2;	 /** D6~D7, ������� ����, 0 ������ */
} TS_ELM_DISP_UPS;

/* ------------------------------------------------------------------------- */
/* RECTIFIER 1,2, Other State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_RECTIFIER
* @brief �� ���� ������(Common Data)�� RECTIFIER Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES           : 4; /** D0~D3, ������� ����, 0 ������ */
	uint32 bAlarmOn       : 1; /** D4, 0:�溸����, 1:�溸�︲ */
	uint32 bRectifierGood : 1; /** D5, 0:RECTIFIER ����, 1:RECTIFIER ���� */
	uint32 bRES1          : 2; /** D6~D7, ������� ����, 0 ������ */
} TS_ELM_DISP_RECTIFIER;

/* ------------------------------------------------------------------------- */
/* BATTERY State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_BATTERY
* @brief �� ���� ������(Common Data)�� BATTERY Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES         : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bAlarmOn     : 1;	 /** D4, 0:�溸����, 1:�溸�︲ */
	uint32 bBatteryGood : 1;	 /** D5, 0:BATTERY ����, 1:BATTERY ���� */
	uint32 bRES1        : 2;	 /** D6~D7, ������� ����, 0 ������ */
} TS_ELM_DISP_BATTERY;

/* ------------------------------------------------------------------------- */
/* FUSE, FUSE1, FUSE2 State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_FUSE
* @brief �� ���� ������(Common Data)�� FUSE or FUSE1 or FUSE2 Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES      : 4;		 /** D0~D3, ������� ����, 0 ������ */
	uint32 bAlarmOn  : 1;		 /** D4, 0:�溸����, 1:�溸�︲ */
	uint32 bFuseGood : 1;		 /** D5, 0:FUSE ����, 1:FUSE ���� */
	uint32 bRES1     : 2;		 /** D6~D7, ������� ����, 0 ������ */
} TS_ELM_DISP_FUSE;

/* ------------------------------------------------------------------------- */
/* ���� ������ȯ�� ���� ���� State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_PNPOWER
* @brief �� ���� ������(Common Data)�� ���� ������ȯ�� ���� ���� Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES         : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bAlarmOn     : 1;	 /** D4, 0:�溸����, 1:�溸�︲ */
	uint32 bPNPowerGood : 1;	 /** D5, 0:PNPOWER ����, 1:PNPOWER ���� */
	uint32 bRES1        : 2;	 /** D6~D7, ������� ����, 0 ������ */
} TS_ELM_DISP_PNPOWER;

/* ------------------------------------------------------------------------- */
/* ���� ������ȯ�� ���� ���� State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_PSPOWER
* @brief �� ���� ������(Common Data)�� ���� ������ȯ�� ���� ���� Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES         : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bAlarmOn     : 1;	 /** D4, 0:�溸����, 1:�溸�︲ */
	uint32 bPSPowerGood : 1;	 /** D5, 0:PSPOWER ����, 1:PSPOWER ���� */
	uint32 bPowerON     : 1;	 /** D6, 0:�������, 1:������ */
	uint32 bRES1        : 1;	 /** D7, ������� ����, 0 ������ */
} TS_ELM_DISP_PSPOWER;

/* ------------------------------------------------------------------------- */
/* Signal Failure State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_SGFAIL
* @brief �� ���� ������(Common Data)�� Signal Failure Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES       : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bAlarmOn   : 1;	 /** D4, 0:�溸����, 1:�溸�︲ */
	uint32 bSgFailure : 1;	 /** D5, 0:SGFAILURE ����, 1:SGFAILURE ���� */
	uint32 bRES1      : 2;	 /** D6~D7, ������� ����, 0 ������ */
} TS_ELM_DISP_SGFAIL;

/* ------------------------------------------------------------------------- */
/* Point Failure  State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_PTFAIL
* @brief �� ���� ������(Common Data)�� Point Failure Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES       : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bAlarmOn   : 1;	 /** D4, 0:�溸����, 1:�溸�︲ */
	uint32 bPtFailure : 1;	 /** D5, 0:PTFAILURE ����, 1:PTFAILURE ���� */
	uint32 bRES1      : 2;	 /** D6~D7, ������� ����, 0 ������ */
} TS_ELM_DISP_PTFAIL;

/* ------------------------------------------------------------------------- */
/* Track Failure  State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_TRFAIL
* @brief �� ���� ������(Common Data)�� Track Failure Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES       : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bAlarmOn   : 1;	 /** D4, 0:�溸����, 1:�溸�︲ */
	uint32 bTrFailure : 1;	 /** D5, 0:TRFAILURE ����, 1:TRFAILURE ���� */
	uint32 bRES1      : 2;	 /** D6~D7, ������� ����, 0 ������ */
} TS_ELM_DISP_TRFAIL;

/* ------------------------------------------------------------------------- */
/* ��ȣ���� ���Թ� State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_RRDOOR
* @brief �� ���� ������(Common Data)�� ��ȣ���� ���Թ� Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES     : 4;		 /** D0~D3, ������� ����, 0 ������ */
	uint32 bAlarmOn : 1;		 /** D4, 0:�溸����, 1:�溸�︲ */
	uint32 bRrDoor  : 1;		 /** D5, 0:RRDOOR ����, 1:RRDOOR ���� */
	uint32 bRES1    : 2;		 /** D6~D7, ������� ����, 0 ������ */
} TS_ELM_DISP_RRDOOR;

/* ------------------------------------------------------------------------- */
/* ��ȣ�� �ϰ����� ���� State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_SGSTOP
* @brief �� ���� ������(Common Data)�� ��ȣ�� �ϰ����� ���� Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES       : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bSetSgStop : 1;	 /** D4, 0:�̼���, 1:��������-�������� */
	uint32 bReqSgStop : 1;	 /** D5, 0:����䱸����, 1:��������-���� �� ���� */
	uint32 bRES1      : 2;	 /** D6~D7, ������� ����, 0 ������ */
} TS_ELM_DISP_SGSTOP;

/* ------------------------------------------------------------------------- */
/* ��ȯǥ��(��ȣ��) �ҵ� ���� State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_SHOFF
* @brief �� ���� ������(Common Data)�� ��ȯǥ��(��ȣ��) �ҵ� ���� Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES       : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bSetShOff  : 1;	 /** D4, 0:Ȳ��-�������, 1:�帰ȸ��-�ҵ���� */
	uint32 bReqShOff  : 1;	 /** D5, 0:����䱸����, 1:����䱸�� */
	uint32 bRES1      : 2;	 /** D6~D7, ������� ����, 0 ������ */
} TS_ELM_DISP_SHOFF;

/* ------------------------------------------------------------------------- */
/* ���� ���� ���� State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_HEATERN
* @brief �� ���� ������(Common Data)�� ���� ���� ���� Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES         : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bAlarmOn     : 1;	 /** D4, 0:�帰ȸ��-Off ��������, 1:���-ON �������� */
	uint32 bHeaterNGood : 1;	 /** D5, 0:����䱸����, 1:����䱸�� */
	uint32 bSetHeaterN  : 1;	 /** D6, 0:�帰ȸ��-Off ��������, 1:���-ON �������� */
	uint32 bReqHeaterN  : 1;	 /** D7, 0:����䱸����, 1:����䱸�� */
} TS_ELM_DISP_HEATERN;

/* ------------------------------------------------------------------------- */
/* ���� ���� ���� State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_HEATERS
* @brief �� ���� ������(Common Data)�� ���� ���� ���� Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES         : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bAlarmOn     : 1;	 /** D4, 0:�帰ȸ��-Off ��������, 1:���-ON �������� */
	uint32 bHeaterSGood : 1;	 /** D5, 0:����䱸����, 1:����䱸�� */
	uint32 bSetHeaterS  : 1;	 /** D6, 0:�帰ȸ��-Off ��������, 1:���-ON �������� */
	uint32 bReqHeaterS  : 1;	 /** D7, 0:����䱸����, 1:����䱸�� */
} TS_ELM_DISP_HEATERS;

/* ------------------------------------------------------------------------- */
/* COM 1,2 State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_COM
* @brief �� ���� ������(Common Data)�� COM 1 or 2 Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES     : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bAlarmOn : 1;	 /** D4, 0:�溸����, 1:�溸�︲ */
	uint32 bComGood : 1;	 /** D5, 0:COM  ����, 1:COM  ���� */
	uint32 bActive  : 1;	 /** D6, 0:Standby, 1:Active main */
	uint32 bRES1    : 1;	 /** D7, ������� ����, 0 ������ */
} TS_ELM_DISP_COM;

/* ------------------------------------------------------------------------- */
/* LCP 1,2 State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_LCP
* @brief �� ���� ������(Common Data)�� LCP 1 or 2 Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES     : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bAlarmOn : 1;	 /** D4, 0:�溸����, 1:�溸�︲ */
	uint32 bGood    : 1;	 /** D5, 0:LCP ����, 1:LCP ���� */ /* [KRS�����ιݿ�2] OPC ������� ������ ���� */
	uint32 bActive  : 1;	 /** D6, 0:Standby, 1:Active main */
	uint32 bRES1    : 1;	 /** D7, ������� ����, 0 ������ */
} TS_ELM_DISP_LCP;

/* [KRS�����ιݿ�3] MTC �������� �߰� */
/* ------------------------------------------------------------------------- */
/* MTC State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_MTC
* @brief �� ���� ������(Common Data)�� MTC Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES     : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bAlarmOn : 1;	 /** D4, 0:�溸����, 1:�溸�︲ */
	uint32 bGood    : 1;	 /** D5, 0:MTC ����, 1:MTC ���� */
	uint32 bRES1    : 2;	 /** D6-D7, ������� ����, 0 ������ */
} TS_ELM_DISP_MTC;

/* ------------------------------------------------------------------------- */
/* �˵�ȸ�� �Ϲ����� State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_TR_GI
* @brief �˵�ȸ�� �Ϲ����� Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bTRACKOCC  : 1;	 /** D0, 0:����(����), 1:������(���) */
	uint32 bTKROUTE   : 1;	 /** D1, 0:���μ�����������(���), 1:���μ�����������(Ȳ��) */
	uint32 bLRLOCK    : 1;	 /** D2, 0:���μ��� ���� �� ���� ��������, 1:���μ��� ���� �Ǵ¿��� ��������(���) */
	uint32 bTKALARM   : 1;	 /** D3, 0:���پ���(���), 1:�峻����(��������) */
	uint32 bTKFAIL    : 1;	 /** D4, 0:�˵�ȸ������(���), 1:�˵�ȸ�κ�������(����) */
	uint32 bTKREQ     : 1;	 /** D5, 0:�˵�(��)��޺Ұ� 1:�˵�(��)��ް��� */
	uint32 bTKEMREL   : 1;	 /** D6, 0:���������޺Ұ� 1:���������ް��� */
	uint32 bAPLOCK    : 1;	 /** D7, 0:����������, 1:���������� */
} TS_ELM_DISP_TR_GI;

/* ------------------------------------------------------------------------- */
/* �˵�ȸ�� Ȯ������(�����������ǥ(ǥ��)) ���� State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_TR_EX
* @brief �˵�ȸ�� Ȯ������(�����������ǥ(ǥ��)) ���� Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bINHIBIT_ID1 : 4;	 /** D0~D3, 0:��������, 1~10:������, ��Ÿ:���õ� */
	uint32 bINHIBIT_ID2 : 4;	 /** D4`D7, 0:��������, 1~10:������, ��Ÿ:���õ� */
 /** Bit 0 ~ Bit 3, Bit 4 ~ Bit 7, INHIBIT_ID1 �� INHIBIT_ID2 ���� ���� �ǹ̴� �Ʒ��� ������.
	0x00 : ����
	0x01 : ������ġ��ȯ
	0x02 : ���λ������
	0x03 : ���ܰ���
	0x04 : ����������
	0x05 : Ʈ�θ������
	0x06 : ����ȣ
	0x07 : ������
	0x08 : ��Ž�
	0x09 : ��������
	0x0A : ����������
	0x0B : ��ȭ���� - ����, �����������
	0x0C : ��ȭ���� - ����, �����������
	0x0D : ��ȭ���� - ����, �����������
	0x0E : ��ȭ���� - ����, �����������
	0x0F : ��ȭ���� - ����, �����������
	*/
} TS_ELM_DISP_TR_EX;

/* ------------------------------------------------------------------------- */
/* ��ȣ�� �Ϲ����� State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_SG_GI
* @brief ��ȣ�� �Ϲ����� Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bINU         : 1;	 /** D0, 0:���-������ȣ�� �ҵ�, 1:���-������ȣ�� �������� */
	uint32 bTTB         : 1;	 /** D1, 0:���-TTB OFF, 1:Ȳ��-TTB ON */
	uint32 bSGROUTE     : 1;	 /** D2, 0:��ȣ�� ����, 1:��ȣ�� ���� */
	uint32 bSGON_TIMER  : 1;	 /** D3, 0:����,���� ����, 1:����,���� ���� */
	uint32 bGO          : 1;	 /** D4, 0:��������, 1:�������� */
	uint32 bSGFAIL      : 1;	 /** D5, 0:����, 1:���� */
	uint32 bRTSELM_GO   : 1;	 /** D6, 0:���μ����� �ҵ�, 1:���μ����� �������� */
	uint32 bRTSELM_FAIL : 1;	 /** D7, 0:���μ����� ����, 1:���μ����� ��� */
} TS_ELM_DISP_SG_GI;

/* ------------------------------------------------------------------------- */
/* ������� ��ȣ�� State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_SG_INBLOCK
* @brief ������� ��ȣ�� Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES    : 4;		 /** D0~D3, ������� ����, 0 ������ */
	uint32 bGO     : 1;		 /** D4, 0:��������, 1:�������� */
	uint32 bSGFAIL : 1;		 /** D5, 0:����, 1:���� */
	uint32 bRES1   : 2;		 /** D6~D7, ������� ����, 0 ������ */
} TS_ELM_DISP_SG_INBLOCK;

/* ------------------------------------------------------------------------- */
/* ������� ��ȣ�� State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_SG_OUTBLOCK
* @brief ������� ��ȣ�� Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES     : 4;		 /** D0~D3, ������� ����, 0 ������ */
	uint32 bGO      : 1;		 /** D4, 0:��������, 1:�������� */
	uint32 bSGFAIL  : 1;		 /** D5, 0:����, 1:���� */
	uint32 bRES1    : 2;		 /** D6~D7, ������� ����, 0 ������ */
} TS_ELM_DISP_SG_OUTBLOCK;

/* ------------------------------------------------------------------------- */
/* ����/�ڵ� ��� State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_BLOCKS
* @brief ����/�ڵ� ��� Element�� ǥ������ Data
*/
typedef struct {
	uint32 bBLKOUT_YF : 1;	 /** D0, 0:�䱸����, 1:���-���/��� �䱸 */
	uint32 bBLKOUT_Y  : 1;	 /** D1, 0:���ξ���, 1:����-��߽��� */
	uint32 bBLKOUT_R  : 1;	 /** D2, 0:���Ծ���, 1:���-�������� */
	uint32 bBLKOUT_RF : 1;	 /** D3, 0:�䱸����, 1:���-����䱸�� */
	uint32 bBLKIN_YF  : 1;	 /** D4, 0:�䱸����, 1:�峻-���/��� �䱸 */
	uint32 bBLKIN_Y   : 1;	 /** D5, 0:�������, 1:�峻-�峻���� */
	uint32 bBLKIN_R   : 1;	 /** D6, 0:���Ծ���, 1:�峻-�������� */
	uint32 bBLKIN_RF  : 1;	 /** D7, 0:�䱸����, 1:�峻-����䱸 */
} TS_ELM_DISP_BLOCKS;

/* ------------------------------------------------------------------------- */
/* ������ȯ�� �Ϲ����� State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_PT_GI
* @brief ������ȯ�� �Ϲ����� Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bNKRI     : 1;	 /** D0, 0:��, 1:���� */
	uint32 bRKRI     : 1;	 /** D1, 0:��, 1:���� */
	uint32 bPTLOCK   : 1;	 /** D2, 0:��������, 1:�������� */
	uint32 bPTFAIL   : 1;	 /** D3, 0:�������, 1:������� */
	uint32 bPTONTIMR : 1;	 /** D4, 0:�����������üҾ���, 1:�����������ü����� �� */
	uint32 bSWLOCK   : 1;	 /** D5, 0:������ȯ�� ��ȯ����, 1:��ȯ�Ұ� */
	uint32 bNWRO     : 1;	 /** D6, 0:NWRO OFF, 1:NWRO ON (����) */
	uint32 bRWRO     : 1;	 /** D7, 0:RWRO OFF, 1:RWRO ON (����) */
} TS_ELM_DISP_PT_GI;

/* ------------------------------------------------------------------------- */
/* General I/O �ǳθ� State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_LX
* @brief �� ���� ������(Common Data)�� CTC/LOCAL/RC Mode Element Data
*/
typedef struct {
	uint32 bRES     : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bAlarmOn : 1;	 /** D4, 0:�˶�����, 1:�˶��溸�߻� */
	uint32 bLxGood  : 1;	 /** D5, 0:����, 1:���� */
	uint32 bRES1    : 2;	 /** D6~D7, ������� ����, 0 ������ */
} TS_ELM_DISP_LX;

/* ------------------------------------------------------------------------- */
/* General I/O ���幰������ġ �������� State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_OBSTRUCTION
* @brief General I/O ���幰������ġ �������� Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES             : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bAlarmOn         : 1;	 /** D4, 0:�˶�����, 1:�˶��溸�߻� */
	uint32 bObstructionGood : 1;	 /** D5, 0:����, 1:���� */
	uint32 bSetUnsecurity   : 1;	 /** D6, 0:�帰ȸ��-�����������, 1:Ȳ��-����������� */
	uint32 bRES1            : 1;	 /** D7, ������� ����, 0 ������ */
} TS_ELM_DISP_OBSTRUCTION;

/* ------------------------------------------------------------------------- */
/* General I/O ��������������ġ �������� State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_INSULATION
* @brief General I/O ��������������ġ �������� Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bSys1AlarmOn : 1;	 /** D0, 0:1�� �˶��溸����, 1:1�� �˶��溸�߻� */
	uint32 bSys1Good    : 1;	 /** D1, 0:1�� ����, 1:1�� ���� */
	uint32 bSys1Active  : 1;	 /** D2, 0:1�� ���, 1:1�� ��� */
	uint32 bRES         : 1;	 /** D3, ������� ����, 0 ������ */
	uint32 bSys2AlarmOn : 1;	 /** D4, 0:2�� �˶��溸����, 1:2�� �˶��溸�߻� */
	uint32 bSys2Good    : 1;	 /** D5, 0:2�� ����, 1:2�� ���� */
	uint32 bSys2Active  : 1;	 /** D6, 0:2�� ���, 1:2�� ��� */
	uint32 bRES1        : 1;	 /** D7, ������� ����, 0 ������ */
} TS_ELM_DISP_INSULATION;

/* ------------------------------------------------------------------------- */
/* General I/O Ȯ�巢 ������ State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_OPMODE
* @brief General I/O Ȯ�巢 ������ Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bRES           : 4; /** D0~D3, ������� ����, 0 ������ */
	uint32 bAlarmOn       : 1; /** D4, 0:�˶�����, 1:�˶��溸�߻� */
	uint32 bRectifierGood : 1; /** D5, 0:����, 1:���� */
	uint32 bRES1          : 2; /** D6~D7, ������� ����, 0 ������ */
} TS_ELM_DISP_EXRECTIFIER;

/* ------------------------------------------------------------------------- */
/* ���� �Ϲ����� State ǥ������ */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_RT_GI
* @brief ���� �Ϲ����� Element�� State ǥ������ Data
*/
typedef struct {
	uint32 bYLMR         : 1;		 /** D0, 0: YLMR OFF, 1: YLMR ON */
	uint32 bGLMR	     : 1;		 /** D1, 0: YLMR OFF, 1: YLMR ON */
	uint32 bY1LMR        : 1;		 /** D2, 0: YLMR OFF, 1: YLMR ON */
	uint32 bRouteSel     : 1;		 /** D3, 0:���-��������, 1:Ȳ��-���μ����� */
	uint32 bRouteON      : 1;		 /** D4, 0:���-��������, 1:Ȳ��-���μ��� */
	uint32 bRouteReq     : 1;		 /** D5, 0:�䱸����, 1:����䱸 */ /* [KRS�����ιݿ�1] �������� �䱸���� �߰� */
	uint32 bEnableRoute  : 1;		 /** D6, 0:�������, 1:����Ұ� */
	uint32 bEnableReCtrl : 1;		 /** D7, 0:����޺Ұ�, 1:����ް��� */
} TS_ELM_DISP_RT_GI;

/* ///////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////////////////////////////////////////////////// */
/* ���������� ���� Element Data ����ü ����                                  */
/* ///////////////////////////////////////////////////////////////////////// */

/* ------------------------------------------------------------------------- */
/* for ZEST EI and WINDOWS(INTEL Style) : LITTLE ENDIAN                                  */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* Element�� �˶��溸 ���� �������� */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_ALARMBELL_OFF
* @brief Element�� �˶��溸 ���� ��������
*/
typedef struct {
	uint32 bSys1AlarmOFF : 1;	 /** D0, 0:�������, 1:��������������ġ 1�� Alarm �溸 ����(��������������ġ Element ID �� ���) */
	uint32 bRES          : 3;	 /** D1~D3, ������� ����, 0 ������ */
	uint32 bSysAlarmOFF  : 1;	 /** D4, 0:�������, 1:�Ϲ����� Alarm �Ǵ� ��������������ġ 2�� Alarm �溸 ����(��������������ġ Element ID �� ���) */
	uint32 bRES1         : 3;	 /** D5~D7, ������� ����, 0 ������ */
} TS_ELM_CTRL_ALARMBELL_OFF;

/* ------------------------------------------------------------------------- */
/* RUN �䱸 �������� */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_RUN
* @brief �� ���� ������(Common Data)�� RUN Elemen�� ��������
*/
typedef struct {
	uint32 bRES        : 2; /** D0~D1, ������� ����, 0 ������ */
	uint32 bSys1RunReq : 1; /** D2, 0:�������, 1:1�� RUN �䱸 */
	uint32 bRES1       : 1; /** D3, ������� ����, 0 ������ */
	uint32 bSys2RunReq : 1; /** D4, 0:�������, 1:2�� RUN �䱸 */
	uint32 bRES2       : 3; /** D5~D7, ������� ����, 0 ������ */
} TS_ELM_CTRL_RUN;

/* ------------------------------------------------------------------------- */
/* CTC Mode ��ȯ �������� */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_CTC_MODE
* @brief �� ���� ������(Common Data)�� CTC Mode Element�� ��������
*/
typedef struct {
	uint32 bCtcReq : 1; /** D0, 0:�������, 1:CTC ��ȯ�䱸 */
	uint32 bRES    : 7; /** D1~D7, ������� ����, 0 ������ */
} TS_ELM_CTRL_CTC_MODE;

/* ------------------------------------------------------------------------- */
/* LOCAL Mode ��ȯ �������� */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_LOCAL_MODE
* @brief �� ���� ������(Common Data)�� LOCAL Mode Element�� ��������
*/
typedef struct {
	uint32 bRES           : 2; /** D0~D1, ������� ����, 0 ������ */
	uint32 bLocalReq      : 1; /** D2, 0:�������, 1:LOCAL ��ȯ�䱸 */
	uint32 bLocalApproval : 1; /** D3, 0:�������, 1:LOCAL ��ȯ����/CTC or RC ��û  �� ��� */
	uint32 bEmLocal       : 1; /** D4, 0:�������, 1:��� LOCAL ��ȯ */
	uint32 bRES1          : 3; /** D5~D7, ������� ����, 0 ������ */
} TS_ELM_CTRL_LOCAL_MODE;

/* ------------------------------------------------------------------------- */
/* RC Mode ��ȯ �������� */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_RC_MODE
* @brief �� ���� ������(Common Data)�� RC Mode Element�� ��������
*/
typedef struct {
	uint32 bRES		 : 5;	 /** D0~D4, ������� ����, 0 ������ */
	uint32 bRCReq		 : 1;	 /** D5, 0:�������, 1:RC ��ȯ�䱸 */
	uint32 bRCApproval : 1;	 /** D6, 0:�������, 1:RC ��ȯ����/CTC or LOCAL ��û �� ��� */
	uint32 bEmRC		 : 1;	 /** D7, 0:�������, 1:��� RC ��ȯ */
} TS_ELM_CTRL_RC_MODE;


/* ------------------------------------------------------------------------- */
/* ����&���� ������ȯ�� �������� */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_PTPOWER
* @brief �� ���� ������(Common Data)�� N/S Point Power Element�� ��������
*/
typedef struct {
	uint32 bRES           : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bAlarmOFF      : 1;	 /** D4, 0:�������, 1:Alarm �溸 ���� */
	uint32 bPTPowerONReq  : 1;	 /** D5, 0:�������, 1:Point power ON ���� �䱸 */
	uint32 bPTPowerOFFReq : 1;	 /** D6, 0:�������, 1:Point Power OFF ���� �䱸 */
	uint32 bRES1          : 1;	 /** D7, ������� ����, 0 ������ */
} TS_ELM_CTRL_PTPOWER;


/* ------------------------------------------------------------------------- */
/* ��ȣ�� �ϰ����� �������� */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_SGSTOP
* @brief �� ���� ������(Common Data)�� ��ȣ�� �ϰ����� Element�� ��������
*/
typedef struct {
	uint32 bRES             : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bSetSgStopReq    : 1;	 /** D4, 0:�������, 1:��ȣ�� �ϰ����� �����䱸 */
	uint32 bCancelSgStopReq : 1;	 /** D5, 0:�������, 1:��ȣ�� �ϰ����� �����䱸 */
	uint32 bRES1            : 2;	 /** D6~D7, ������� ����, 0 ������ */
} TS_ELM_CTRL_SGSTOP;

/* ------------------------------------------------------------------------- */
/*��ȯǥ��(��ȣ��) �ҵ� �������� */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_SHOFF
* @brief �� ���� ������(Common Data)�� ��ȯǥ��(��ȣ��) �ҵ� Element�� ��������
*/
typedef struct {
	uint32 bRES            : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bSetShOffReq    : 1;	 /** D4, 0:�������, 1:��ȯǥ��(��ȣ��) �ҵ����� ���� �䱸 */
	uint32 bCancelShOffReq : 1;	 /** D5, 0:�������, 1:��ȯǥ��(��ȣ��) �ҵ����� ���� �䱸 */
	uint32 bRES1           : 2;	 /** D6~D7, ������� ����, 0 ������ */
} TS_ELM_CTRL_SHOFF;

/* ------------------------------------------------------------------------- */
/* ����&���� ���� �������� */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_HEATER
* @brief �� ���� ������(Common Data)�� Heater N/S Element�� ��������
*/
typedef struct {
	uint32 bRES          : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bAlarmOFF     : 1;	 /** D4, 0:�������, 1:Alarm �溸 ���� */
	uint32 bHeaterONReq  : 1;	 /** D5, 0:�������, 1:Heater ON ���� �䱸 */
	uint32 bHeaterOFFReq : 1;	 /** D6, 0:�������, 1:Heater OFF ���� �䱸 */
	uint32 bRES1         : 1;	 /** D7, ������� ����, 0 ������ */
} TS_ELM_CTRL_HEATER;

/* ------------------------------------------------------------------------- */
/* �˵�ȸ�� �������� */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_TR_GI
* @brief �˵�ȸ�� Element�� ��������
*/
typedef struct {
	uint32 bRES            : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bAlarmOFF       : 1;	 /** D4, 0:�������, 1:Alarm �溸 ���� */
	uint32 bEmRtReleaseReq : 1;	 /** D5, 0:�������, 1:�������κ������ �䱸 */
	uint32 bRES1           : 2;	 /** D6~D7, ������� ����, 0 ������ */
} TS_ELM_CTRL_TR_GI;

/* ------------------------------------------------------------------------- */
/* �˵�ȸ�� �����������ǥ(ǥ��) ���� �������� */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_TR_EX
* @brief �˵�ȸ�� �����������ǥ(ǥ��) ���� Element�� ��������
*/
typedef struct {
	uint32 bINHIBIT_IDREQ  : 4;	 /** D0~D3, 1~10:������ ǥ��������, ��Ÿ:���õ� */
	uint32 bRES            : 2;	 /** D4`D5, ������� ����, 0 ������ */
	uint32 bLabelCtrlLoc   : 1;	 /** D6, 0:ǥ��#1 ����, 1:ǥ��#2 ���� */
	uint32 bLabelCtrlReq   : 1;	 /** D7, 0:ǥ�� ���� ����, 1:ǥ�� ���� ���� */
	/** Bit 0 ~ Bit 3, INHIBIT_ID ���� ���� �ǹ̴� �Ʒ��� ������.
	0x00 : ǥ������
	0x01 : ������ġ��ȯ
	0x02 : ���λ������
	0x03 : ���ܰ���
	0x04 : ����������
	0x05 : Ʈ�θ������
	0x06 : ����ȣ
	0x07 : ������
	0x08 : ��Ž�
	0x09 : ��������
	0x0A : ����������
	0x0B : ��ȭ���� - ����, �����������
	0x0C : ��ȭ���� - ����, �����������
	0x0D : ��ȭ���� - ����, �����������
	0x0E : ��ȭ���� - ����, �����������
	0x0F : ��ȭ���� - ����, �����������
	*/
} TS_ELM_CTRL_TR_EX;

/* ------------------------------------------------------------------------- */
/* ��ȣ��(�ֽſ�/��ȯ��ȣ��/��ȯǥ��/���������ȣ��/���������ȣ��) �������� */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_SG_GI
* @brief ��ȣ��(�ֽſ�/��ȯ��ȣ��/��ȯǥ��/���������ȣ��/���������ȣ��) Element�� ��������
*/
typedef struct {
	uint32 bRES			 : 4;	 /** D0-D3, ������� ����, 0 ������ */
	uint32 bSGStopReq      : 1;	 /** D4, 0:�������, 1:��ȣ�� ��������(��������) �䱸 */
	uint32 bRES1		     : 3;	 /** D5-D7, ������� ����, 0 ������ */
} TS_ELM_CTRL_SG_GI;

/* ------------------------------------------------------------------------- */
/* ����/�ڵ� ���(��޹�ư/����ǥ)�� �������� */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_OPMODE
* @brief ����/�ڵ� ���(��޹�ư/����ǥ) Element�� ��������
*/
typedef struct {
	uint32 bBLKOUT_DEPARTURE_REQ : 1;	 /** D0, 0:�������, 1:���-��߿�û */
	uint32 bBLKIN_ENTRANCE_OK    : 1;	 /** D1, 0:�������, 1:�峻-�峻���� */
	uint32 bBLKIN_OPENING_REQ    : 1;	 /** D2, 0:�������, 1:�峻-�����û */
	uint32 bBLKOUT_OPENING_OK    : 1;	 /** D3, 0:�������, 1:���-������� */
	uint32 bBLKIN_CANCEL_REQ     : 1;	 /** D4, 0:�䱸����, 1:�峻-��ҿ�û */
	uint32 bBLKOUT_CANCEL_OK	   : 1;	 /** D5, 0:�������, 1:���-��ҽ��� */
	uint32 bRES                  : 2;	 /** D6-D7, ������� ����, 0 ������ */
} TS_ELM_CTRL_BLOCKS;

/* ------------------------------------------------------------------------- */
/* ������ȯ���� ��ȯ�䱸 �������� */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_PT_GI
* @brief ������ȯ�� Element�� ��������
*/
typedef struct {
	uint32 bRES     : 4;	 /** D0~D3, ������� ����, 0 ������ */
	uint32 bNWRReq  : 1;	 /** D4, 0:�������, 1:������ȯ����䱸 */
	uint32 bRWROReq : 1;	 /** D5, 0:�������, 1:������ȯ����䱸 */
	uint32 bRES1    : 2;	 /** D6~D7, ������� ����, 0 ������ */
} TS_ELM_CTRL_PT_GI;

/* ------------------------------------------------------------------------- */
/* ���� �Ϲ����� Element�� ���� ���� */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_RT_GI
* @brief ���� Element�� ���� Data Structure
*/
typedef struct {
	uint32 bSetRouteReq    : 1;		 /** D0, 0:�������, 1:���μ����䱸 */
	uint32 bRES            : 1;		 /** D1, ������� ����, 0 ������ */
	uint32 bTTBONReq       : 1;		 /** D2, 0:�������, 1:TTB ON �䱸 */
	uint32 bTTBOFFReq      : 1;		 /** D3, 0:�������, 1:TTB OFF �䱸 */
	uint32 bCancelRouteReq : 1;		 /** D4, 0:�������, 1:���������䱸 */
	uint32 bResetRouteReq  : 1;		 /** D5, 0:�������, 1:��������޿䱸 */
	uint32 bRES1           : 2;		 /** D6~D7, ������� ����, 0 ������ */
} TS_ELM_CTRL_RT_GI;
/* ///////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////////////////////////////////////////////////// */
/* Element Indexing Table�� Element Object ID ����ü ����                    */
/* ///////////////////////////////////////////////////////////////////////// */

/* ------------------------------------------------------------------------- */
/* for ZEST EI and WINDOWS(INTEL Style)                                                  */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* Element�� Indexing�� Type �� ID ����                                      */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELEMENT_IDTYPE
* @brief Element Indexing Table�� Element�� ���� Type �� ID ����.
*/
typedef struct {
	uint32 bID   : 12;		 /** D0~D11������ 12 Bit�� Element's Object ID. */
	uint32 bType :  4;		 /** D12~D15������  4 Bit�� Element's Object Type. */
} TS_ELEMENT_IDTYPE;

/* ///////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////////////////////////////////////////////////// */
/* Element Indexing Table & Element Data Table �� ����ü ����                */
/* ///////////////////////////////////////////////////////////////////////// */
/* ------------------------------------------------------------------------- */
/* Element�� Indexing Table ����ü ����                                      */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELEMENT_INDEX_TABLE
* @brief Element�鿡 ���� Indexing Table 
*/
typedef struct {
	uint16	usElmTH_TOTALSIZE;						/** Byte ������ ���� Element Indexing Table�� ��ü ũ��. */
	uint16	usElmTH_COMMON_CNT;						/** �� ��������(ELM_COMMON) table �� �ǻ�� ���� (��ü 32��) */
	uint16	usElmTH_TR_GI_CNT;						/** �˵�ȸ�� �Ϲ�����(ELM_TRACK_GI) table �� �ǻ�� ���� (��ü 512��) */
	uint16	usElmTH_TR_EX_CNT;						/** �˵�ȸ�� Ȯ��(ǥ��)����(ELM_TRACK_EX) table �� �ǻ�� ���� (��ü 512��) */
	uint16	usElmTH_SG_GI_CNT;						/** ��ȣ�� �Ϲ�����(ELM_SIGNAL_GI) table �� �ǻ�� ���� (��ü 512��) */
	uint16	usElmTH_PT_GI_CNT;						/** ������ȯ�� ��������(ELM_POINT GI) table �� �ǻ�� ���� (��ü 256��) */
	uint16	usElmTH_GIO_GI_CNT;						/** General I/O �Ϲ�����(ELM_GIO_GI) table �� �ǻ�� ���� (��ü 49��) */
	uint16	usElmTH_RT_GI_CNT;						/** ���� �Ϲ�����(ELM_ROUTE GI) table �� �ǻ�� ���� (��ü 1024��) */
	TS_ELEMENT_IDTYPE	atElmIDX_COMMON[LIMIT_CNT_ELM_IDX_COMMON];	/** �� ���� ���� Element ID �� TYPE */
	TS_ELEMENT_IDTYPE	atElmIDX_TR[LIMIT_CNT_ELM_IDX_TRGI];		/** �˵�ȸ�� �Ϲ����� Element�� ID �� TYPE */
	TS_ELEMENT_IDTYPE	atElmIDX_TREX[LIMIT_CNT_ELM_IDX_TREX];		/** �˵�ȸ�� Ȯ��(ǥ��)���� Element�� ID �� TYPE */
	TS_ELEMENT_IDTYPE	atElmIDX_SG[LIMIT_CNT_ELM_IDX_SGGI];		/** ��ȣ�� �Ϲ����� Element�� ID �� TYPE */
	TS_ELEMENT_IDTYPE	atElmIDX_PT[LIMIT_CNT_ELM_IDX_PTGI];		/** ������ȯ�� �Ϲ����� Element�� ID �� TYPE */
	TS_ELEMENT_IDTYPE	atElmIDX_GIO[LIMIT_CNT_ELM_IDX_GIO];		/** General I/O �Ϲ����� Element�� ID �� TYPE */
	TS_ELEMENT_IDTYPE	atElmIDX_RT[LIMIT_CNT_ELM_IDX_RT];			/** ���� �Ϲ����� Element�� ID �� TYPE */
} TS_ELEMENT_INDEX_TABLE;

/* ------------------------------------------------------------------------- */
/* Element�� Data Table ����ü ����                                          */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELEMENT_DATA_TABLE
* @brief Element�� State Data Table
*/
typedef struct {
	uint8					aucElmCOMMON_STATE[LIMIT_CNT_ELM_IDX_COMMON];	/** �� ���� ���� Element �� �������� data */
	TS_ELM_DISP_TR_GI		atElmTR_STATE[LIMIT_CNT_ELM_IDX_TRGI];			/** �˵�ȸ�� �Ϲ����� Element�� �������� data */
	TS_ELM_DISP_TR_EX		atElmTREX_STATE[LIMIT_CNT_ELM_IDX_TREX];		/** �˵�ȸ�� Ȯ��(ǥ��)���� Element�� �������� data */
	TS_ELM_DISP_SG_GI		atElmSG_STATE[LIMIT_CNT_ELM_IDX_SGGI];			/** ��ȣ�� �Ϲ����� Element�� �������� data */
	TS_ELM_DISP_PT_GI		atElmPT_STATE[LIMIT_CNT_ELM_IDX_PTGI];			/** ������ȯ�� �Ϲ����� Element�� �������� data */
	uint8 					aucElmGIO_STATE[LIMIT_CNT_ELM_IDX_GIO];			/** General I/O �Ϲ����� Element�� �������� data */
	TS_ELM_DISP_RT_GI		atElmRT_STATE[LIMIT_CNT_ELM_IDX_RT];			/** ���� �Ϲ����� Element�� �������� data */
	uint8					aucEnd;											/** �� ������ ����Ʈ ����(������) */
} TS_ELEMENT_DATA_TABLE;


/* ------------------------------------------------------------------------- */
/* Element�� Data Table ����ü ����                                          */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELEMENT_DATA_COMMON_TABLE
* @brief �� ���� ���� Element�� State Data Table
*/
typedef struct {
	uint8 					usElmTEMP_STATE;		 /** �� ���� ������ 0��° Element �� �������� data */
	TS_ELM_DISP_RUN			tElmRUN_STATE;			 /** �� ���� ������ 1��° RUN Element �� �������� data */
	TS_ELM_DISP_OPMODE		tElmCTC_STATE;			 /** �� ���� ������ 2��° CTC Element �� �������� data */
	TS_ELM_DISP_OPMODE		tElmLOCAL_STATE;		 /** �� ���� ������ 3��° LOCAL Element �� �������� data */
	TS_ELM_DISP_OPMODE		tElmRC_STATE;			 /** �� ���� ������ 4��° RC Element �� �������� data */
	TS_ELM_DISP_SYS1		tElmSYS1_STATE;			 /** �� ���� ������ 5��° SYS1 Element �� �������� data */
	TS_ELM_DISP_SYS2		tElmSYS2_STATE;			 /** �� ���� ������ 6��° SYS2 Element �� �������� data */
	TS_ELM_DISP_N1			tElmN1_STATE;			 /** �� ���� ������ 7��° N1 Element �� �������� data */
	TS_ELM_DISP_N2			tElmN2_STATE;			 /** �� ���� ������ 8��° N2 Element �� �������� data */
	TS_ELM_DISP_UPS			tElmUPS_STATE;			 /** �� ���� ������ 9��° UPS Element �� �������� data */
	TS_ELM_DISP_RECTIFIER	tElmRECTIFIER1_STATE;	 /** �� ���� ������ 10��°RECTIFER1  Element �� �������� data */
	TS_ELM_DISP_RECTIFIER	tElmRECTIFIER2_STATE;	 /** �� ���� ������ 11��°RECTIFER2  Element �� �������� data */
	TS_ELM_DISP_BATTERY		tElmBATTERY_STATE;		 /** �� ���� ������ 12��° BATTERY Element �� �������� data */
	TS_ELM_DISP_FUSE		tElmFUSE_STATE;			 /** �� ���� ������ 13��° FUSE Element �� �������� data */
	TS_ELM_DISP_PNPOWER		tElmPNPOWER_STATE;		 /** �� ���� ������ 14��° PNPOWER Element �� �������� data */
	TS_ELM_DISP_PSPOWER		tElmPSPOWER_STATE;		 /** �� ���� ������ 15��° PSPOWER Element �� �������� data */
	TS_ELM_DISP_SGFAIL		tElmSGFAIL_STATE;		 /** �� ���� ������ 16��° SGFAILURE Element �� �������� data */
	TS_ELM_DISP_PTFAIL		tElmPTFAIL_STATE;		 /** �� ���� ������ 17��° PTFAILURE Element �� �������� data */
	TS_ELM_DISP_TRFAIL		tElmTRFAIL_STATE;		 /** �� ���� ������ 18��° TRFAILURE Element �� �������� data */
	TS_ELM_DISP_RRDOOR		tElmRRDOOR_STATE;		 /** �� ���� ������ 19��° RRDOOR Element �� �������� data */
	TS_ELM_DISP_SGSTOP		tElmSGSTOP_STATE;		 /** �� ���� ������ 20��° SGSTOP Element �� �������� data */
	TS_ELM_DISP_SHOFF		tElmSHOFF_STATE;		 /** �� ���� ������ 21��° SHOFF Element �� �������� data */
	TS_ELM_DISP_HEATERN		tElmHEATERN_STATE;		 /** �� ���� ������ 22��° HEATERN Element �� �������� data */
	TS_ELM_DISP_HEATERS		tElmHEATERS_STATE;		 /** �� ���� ������ 23��° HEATERS Element �� �������� data */
	TS_ELM_DISP_FUSE		tElmFUSE1_STATE;		 /** �� ���� ������ 24��° FUSE1 Element �� �������� data */
	TS_ELM_DISP_FUSE		tElmFUSE2_STATE;		 /** �� ���� ������ 25��° FUSE2 Element �� �������� data */
	TS_ELM_DISP_COM			tElmCOM1_STATE;			 /** �� ���� ������ 26��° COM1 Element �� �������� data */
	TS_ELM_DISP_COM			tElmCOM2_STATE;			 /** �� ���� ������ 27��° COM2 Element �� �������� data */
	TS_ELM_DISP_LCP 		tElmLCP1_STATE;			 /** �� ���� ������ 28��° LCP1 Element �� �������� data */
	TS_ELM_DISP_LCP			tElmLCP2_STATE;			 /** �� ���� ������ 29��° LCP2 Element �� �������� data */
	TS_ELM_DISP_MTC			tElmMTC_STATE;			 /** �� ���� ������ 30��° MTC Element �� �������� data */ /* [KRS�����ιݿ�3] MTC �������� �߰� */
	uint8 					aucElmRES_STATS;		 /** �� ���� ������ 31 ��° ���� Element �� �������� data */
} TS_ELEMENT_DATA_COMMON_TABLE;

#endif /** #ifndef _ELEMENTTABLE_H_ */
