/* -------------------------------------------------------------------------- /
17.10.23 : 
 - [CTC�˵�Reset�߰�]
17.09.28 :
 - [CTC�˵������߰�]
 - [CTC�˵������߰�]
17.09.06 : 
   - [CTC�ý���RUN�߰�]
17.06.12 : [Ȯ��FUSE&REC������]
17.02.01 :
 - [VCR�߰�] VCR A/B IO Type ����
17.02.09 :
 - [TASK�߰�] uart ���� driver task
17.11.11 :
 - [����ü�����Է�����]
17.12.20 :
 - [����ī���͸���] smTOBJ�� TKAXR ��� �߰�
 - [ATS�����߰�] �����Է� ����
 - [ZLMR�и��߰�]
 - [MRFAIL�߰�]
 - [GIO��Ÿǥ���߰�]
 18.03.21 :
  - [�ܼ���������]
/ -------------------------------------------------------------------------- */
#ifndef _EISDEFINE_H_
#define _EISDEFINE_H_
/* ------------------------------------------------------------------------- */
/* Copyright                                                                 */
/* ------------------------------------------------------------------------- */
/**
* EIS Application Developed by ZEST Team
*                                                                   
* Copyright (c) 2015 DAEATI co.,ltd 
* 200-1, Nae-dong, Ojeong-gu, Bucheon-si, Gyeonggi-do, Korea
* All rights reserved.
*/
/* ------------------------------------------------------------------------- */
/* File Description                                                          */
/* ------------------------------------------------------------------------- */
/**
* @file EisDefine.h
* @author KangKM
* @version 1.0
* @brief KRSEIS���� ���Ǵ� Define File
* @see main 
*/

/* ------------------------------------------------------------------------- */
/* General Value Define                                                      */
/* ------------------------------------------------------------------------- */
#ifndef NULL
#ifdef __cplusplus
#define NULL    0
#endif
#endif

#ifndef INITADDR
#ifdef __cplusplus
#define INITADDR    0
#else
#define INITADDR    ((void *)0)
#endif
#endif

#ifndef FALSE
#define FALSE               0U
#endif

#ifndef TRUE
#define TRUE                1U
#endif

#define	SET				1U
#define RESET			0U
#define USED				1U
#define NOTUSED				0U
#define FIND				1U
#define NODATA				0U
#define FAILURE				0U
#define SUCCESS				1U
#define INITBYTE			((uint8)0x00)
#define INITWORD			((uint16)0x0000)
#define INITUINT			((uint32)0x00000000)
/* ------------------------------------------------------------------------- */
/* Variable Type Define                                                      */
/* ------------------------------------------------------------------------- */

typedef char				CHAR;
typedef unsigned char		BYTE;
typedef unsigned int        UINT;
typedef unsigned long       DWORD;
typedef unsigned short      WORD;

typedef unsigned char		uint8;
typedef unsigned short		uint16;
typedef unsigned int		uint32;
typedef signed int       	sint32;

#ifndef BOOL
typedef sint32				BOOL;
#endif

/* ------------------------------------------------------------------------- */
/* Data Section Define                                                       */
/* ------------------------------------------------------------------------- */
#define CRC_DATA_SECTION
#define ILT_DATA_SECTION
#define ECAT_DATA_SECTION
#define IOC_DATA_SECTION
#define SVC_DATA_SECTION
#define QUE_DATA_SECTION

/* ------------------------------------------------------------------------- */
/* Task Max Tick                                                             */
/* ------------------------------------------------------------------------- */
#define MAX_TICK_SVT		((uint32)100)
#define MAX_TICK_ILT		((uint32)200)
#define MAX_TICK_GPT		((uint32)200)
/* ------------------------------------------------------------------------- */
/* ���� Data ���� Define                                                     */
/* ------------------------------------------------------------------------- */
#define OBJECT_START				1		/** Object ID ���� ��            */
/* ------------------------------------------------------------------------- */
/* �� ID Define                                                              */
/* ------------------------------------------------------------------------- */
#define STID_DANYANG				1U		/** �ܾ�                         */
#define STID_YDTERM					2U		/** ������������                 */
#define STID_OKGAE					3U		/** ����                         */
#define STID_JECHENJO				4U		/** ��õ������                   */
#define STID_SEOWONJU				5U		/** ������                       */
#define STID_OSONGTERM				6U		/** ������������                 */
#define STID_GAYATERM				7U		/** ������������                 */
#define STID_PUSANTERM				8U		/** �λ�����������             */
#define STID_BUBALTERM				9U		/** �ι���������                 */
#define STID_101					10U		/** 101��ȣ��                    */
#define STID_MANJONG				11U		/** ����                         */
#define STID_HOINGSUNG				12U		/** Ⱦ��                         */
#define STID_DUNNAE					13U		/** �г�                         */
#define STID_PEYUNGCHANG			14U		/** ��â                         */
#define STID_JINBU					15U		/** ����                         */
#define STID_DGRSIGTERM				16U		/** ����ɽ�ȣ��                 */
#define STID_NKRSIGTERM				17U		/** ��������ȣ��                 */
#define STID_KANGREUNGSIG			18U		/** ������ȣ��                   */
#define STID_KANGREUNG				19U		/** ����                         */
#define STID_POHANG					20U		/** ����                         */
#define STID_CHUNGHA				21U		/** û��                         */
#define STID_NAMJUNG				22U		/** ����                         */
#define STID_YOUNGDUK				23U		/** ����                         */
/* ------------------------------------------------------------------------- */
/* Object Check Type Define                                                  */
/* ------------------------------------------------------------------------- */
#define VTY_TRACK		0x01U
#define VTY_SIGNAL		0x02U
#define VTY_POINT		0x03U
#define VTY_ROUTE		0x04U
#define VTY_GIO			0x05U
#define VTY_LOCELM		0x06U
/* ------------------------------------------------------------------------- */
/* ��ȣ���� �ִ� ���� ����                                                   */
/* ------------------------------------------------------------------------- */
/*�������� �Ź��� ���� �� �� ���� �Ǵ� ����*/
#define MAX_ROUTE 					1024U	/** ���� ���� �ִ�ġ             */
#define MAX_SIGNAL 					512U	/** ���� ��ȣ�� �ִ�ġ           */
#define MAX_POINT 					256U	/** ���� ������ȯ�� �ִ�ġ       */
#define MAX_TRACK 					512U	/** ���� �˵� �ִ�ġ             */

#define MAX_ROUTE_NEW				1024	/** ���� ���� �ִ�ġ             */
#define MAX_TRACK_NEW				512		/** ���� �˵� �ִ�ġ             */
#define MAX_SIGNAL_NEW				512		/** ���� ��ȣ�� �ִ�ġ           */
#define MAX_POINT_NEW				256		/** ���� ������ȯ�� �ִ�ġ       */
#define MAX_GENERAL_IO 				50U		/** ���� GIO �ִ�ġ              */
#define MAX_DESTPOINT 				100		/** ������ �ִ�ġ                */
#define MAX_INFO_GENERAL			128		/** ���� BIT OPERATION �ִ�ġ    */
/* ------------------------------------------------------------------------- */
/* ILDB ���� Define                                                          */
/* ------------------------------------------------------------------------- */
#define ILDB_CRC32_CHECK_BLOCK		((uint32)1000)	/** ILDB CRC32 �˻����(byte)*/
#define MAX_ILDB_CRC32				300		/** ILDB 1000byte CRC32 �ִ��   */
#define ILDB_ALL_CRC32_AREA			4U		/** ILDB ��üCRC�� ���� ũ��     */
#define ILDB_DATASIZE_AREA			4U		/** ILDB ��ü ũ���� ���� ũ��   */
#define ILDB_CRC32_INITVALUE		0x00000000UL	/** CRC32 �ʱⰪ         */

/* ------------------------------------------------------------------------- */
/* ILDB Option define                                                        */
/* ------------------------------------------------------------------------- */
#define SIZE_ILDB_VERSION			18U		/** ILDB Version data size       */
#define VER_BASE_POS				0U		/** Version Data-Base Offset     */
#define VER_STID_POS				6U		/** Version Data-StnID Offset    */
/* Version Option Offset defined ------------------------------------------- */
#define VER_OPT1_POS_INOUT_CHK		8U		/** [Opt1] ILT IN/OUT �� Option*/
#define VER_OPT2_POS_DIAG_OPTION	9U		/** [Opt2] ���� Option           */
#define VER_OPT3_POS_INIT_OPTION	10U		/** [Opt3] ��� Option           */
#define VER_OPT4_POS_TCRLS_VALUE	11U		/** [Opt4] �˵������ð� ����     */
#define VER_OPT5_POS				12U		/** [Opt5]Ver Option Offset      */
#define VER_OPT6_POS				13U		/** [Opt6]Ver Option Offset      */
#define VER_OPT7_POS				14U		/** [Opt7]Ver Option Offset      */
#define VER_OPT8_POS				15U		/** [Opt8]Ver Option Offset      */
#define VER_OPT9_POS				16U		/** [Opt9]Ver Option Offset      */
#define VER_OPT10_POS				17U		/** [Opt10]Ver Offset            */

#define VER_OPT6_POS_LSTN_GIO_IN	13U		/** [Opt6]Ver Option Offset      */
#define VER_OPT7_POS_LSTN_GIO_OUT	14U		/** [Opt7]Ver Option Offset      */
#define VER_OPT8_POS_RSTN_GIO_IN	15U		/** [Opt8]Ver Option Offset      */
#define VER_OPT9_POS_RSTN_GIO_OUT	16U		/** [Opt9]Ver Option Offset      */

/* [Opt1]VER_OPT1_POS_INOUT_CHK bit value (default INOUT_MIS_FAILSAFE) ----- */
#define VO1_INOUT_MIS_SAFESTATE		0x01U
#define VO1_INOUT_MIS_VRDOFF		0x02U
#define VO1_INOUT_MIS_FAILSAFE		0x04U
#define VO1_VRD_MULTI_CONTROL		0x08U
#define VO1_IGNORE_SYS_ALARM		0x10U
#define VO1_DEST_TIMELOCK			0x20U
/* [Opt2]VER_OPT2_POS_DIAG_OPTION bit value -------------------------------- */
#define VO2_IGNORE_VRD_DIAG         0x01U
#define VO2_IGNORE_SYS_PRG_DIAG     0x02U
#define VO2_RTCTRL_ZRON				0x40U	/** ������� �� ZR ON            */
#define VO2_SHUNT_TC_RELEASE_FAIL	0x80U	/** ��ȯOUT��ȣ�� �˵���������   */
/*#define VO2_IOS_IGNORE_OTHER_SAFESTATE 0x80U */ /** ������� ���� */
/* [Opt3]VER_OPT3_POS_INIT_OPTION bit value -------------------------------- */
#define VO3_INIT_CTRLMD_CTC			0x01U
#define VO3_CTRLWR_USED_VDO			0x02U	/** WR���� VDO ���              */
#define VO3_CTC_CTRL_RUN			0x04U	/** CTC RUN ���� ����            */
#define VO3_CTC_CTRL_TC_EG			0x08U	/** CTC ������� ���� ����       */
#define VO3_CTC_CTRL_TC_BLK			0x10U	/** CTC �˵� ������ ���� ����  */
#define VO3_CTC_DSP_TC_LOCK			0x20U	/** CTC �˵� ���μ������� ����   */
#define VO3_CTC_TC_RESET			0x40U	/** CTC �˵�(AXC) Reset ����     */ /* [CTC�˵�Reset�߰�] */
#define VO3_JAKARTA_LRT				0x80U	/** ��ī��Ÿ LRT ���� ���       */

/* [Opt5]VER_OPT3_POS_INIT_OPTION bit value -------------------------------- */
#define VO5_L_STNID_MASK			0xF0U
#define VO5_R_STNID_MASK			0x0FU

#define	VO_UPLINE_MASK				0xF0U
#define	VO_DNLINE_MASK				0x0FU

/* ------------------------------------------------------------------------- */
#define SIZE_ROUTEDATA_AREA			100000U	/** ILDB ����Data �ִ� ũ��      */
#define SIZE_TRACK_LINK_AREA		30000U	/** ����˵�ȸ�� ���̺� ������   */

#define MAX_BLOCKSECTION			10U		/** ILDB ���Data ��             */
#define MAX_SGTBL_APPROACH_INFO		40U		/** Sg info tbl ���ټ��� data �� */
#define MAX_BLOCK_TRACK				20U		/** ��� data �˵����� �ִ�ġ    */


#define POINT_NORMAL_POSITION		0U
#define POINT_REVERSE_POSITION		1U

#define POINT_N_CHECK				1
#define POINT_R_CHECK				2
/* ------------------------------------------------------------------------- */
/* System Fault Value Define                                                 */
/* ------------------------------------------------------------------------- */
/* System Down (Safe-state ����) */
#define ILDB_ROM_SIZE_CHECK_FAILURE	(uint32)(0x00000001U)	/** ROM Data Size Fail   */
#define ILDB_SIZE_CHECK_FAILURE		(uint32)(0x00000002U)	/** Read Data Size Fail  */
#define ILDB_CRC32_CHECK_FAILURE	(uint32)(0x00000004U)	/** CRC32 Check Fail     */
#define ILDB_ALLCRC32_CHECK_FAILURE	(uint32)(0x00000008U)	/** All CRC32 Check Fail */

#define SYSTEM_ID_FAILURE			(uint32)(0x00000010U)	/** System ID Fail   */
#define SYSTEM_ID_DUPLICATION		(uint32)(0x00000020U)	/** System ID �ߺ�   */
#define IOS_LINK_FAILURE			(uint32)(0x00000040U)	/** IOS Link Fail    */
#define MESSAGE_Q_CREATION_FAILURE	(uint32)(0x00000080U)	/** Msg Q ���� Fail  */

#define OTHSYS_ILDB_SIZE_FAILURE	(uint32)(0x00000100U)	/** �谣DB Size Fail */
#define OTHSYS_ILDB_CRC_FAILURE		(uint32)(0x00000200U)	/** �谣DB CRC Fail  */
#define OTHSYS_SYSID_SAME			(uint32)(0x00000400U)	/** �谣 SysID�ߺ�   */
#define OTHSYS_PRGCRC_FAIL			(uint32)(0x00000800U)	/** �谣PG CRC ����ġ*/

#define ILDB_IO_CONFIG_FAILURE		(uint32)(0x00001000U)	/** IO �������� fail */
#define APPLICATION_ACT_FAILURE		(uint32)(0x00002000U)	/** Application Fail */
#define CPU2CPU_ILDB_MISMATCH		(uint32)(0x00004000U)	/** ä�ΰ� ILDB fail */
#define CPU2CPU_CHID_FAILURE		(uint32)(0x00008000U)	/** ä��ID ��������  */

#define DIO_IF_FAILURE				(uint32)(0x00010000U)	/** DIO I/F ����     */
#define COMM_MODULE_FAILURE			(uint32)(0x00020000U)	/** Com module ���  */
#define SYS_IF_FAILURE				(uint32)(0x00040000U)	/** �谣 I/F ���    */
#define VRD_CHECK_FAILURE			(uint32)(0x00080000U)	/** VRD ���� ���    */

#define VCR_FAILURE					(uint32)(0x00100000U)	/** VCR ����         */
#define ILS_SAFESTATE_MASK			(uint32)(0x000FFFFFU)	/** SafeState bit    */

/* ����ü ���� (VRD Off) */
#define VRD_IN_FAIL					(uint32)(0x01000000U)	/** VRD ���ۺҴ�     */
#define IOS_FUSE_FAIL				(uint32)(0x02000000U)	/** FUSE ���        */
#define SYS_IN_MISMATCH				(uint32)(0x04000000U)	/** �谣 �Է� ����ġ */
#define SYS_OUT_MISMATCH			(uint32)(0x08000000U)	/** �谣 ��� ����ġ */
#define INPUT_ILLEGAL_ERROR			(uint32)(0x10000000U)	/** �����Է�(����)   */
#define ILLEGAL_INPUT_MODULE		(uint32)(0x20000000U)	/** IN��� �����Է�  */
#define ILLEGAL_OUTPUT_MODULE		(uint32)(0x40000000U)	/** OUT��� ������� */
#define ILLEGAL_ERROR				(uint32)(0x80000000U)	/** ä�ΰ� ����ó��  */

#define ILS_VRDOFF_STATE_MASK		(uint32)(0xF0000000U)	/** VRD Off Mask     */

/* ------------------------------------------------------------------------- */
/* System ID Define                                                          */
/* ------------------------------------------------------------------------- */
#define SYSTEM_1_ID					((uint8)0xF1)	/** 1�� */
#define SYSTEM_2_ID					((uint8)0xF2)	/** 2�� */
/* ------------------------------------------------------------------------- */
/* System Delay                                                              */
/* ------------------------------------------------------------------------- */
#define SYS_SWITCH_DELAY	(3000U/MAX_TICK_ILT)   /** ��¿� ���� �Է� Count*/ /* [����ü�����Է�����] */
/* ------------------------------------------------------------------------- */
/* CheckBack Delay                                                           */
/* ------------------------------------------------------------------------- */
#define RELAY_CHECKBACK_DELAY		(800U/MAX_TICK_ILT)	/** ��¿� ���� �Է� Count */
//#define LMR_CHECK_DELAY				(2000U/MAX_TICK_ILT)/** ��¿� ���� �Է� Count */
#define LMR_CHECK_DELAY				(3600U/MAX_TICK_ILT)/** ��¿� ���� �Է� Count */
/* ------------------------------------------------------------------------- */
/* System Operate Mode Define                                                */
/* ------------------------------------------------------------------------- */
#define SO_MODE_STRATUP			(uint8)(0x01U)	/** StartUp Mode             */
#define SO_MODE_READY			(uint8)(0x02U)	/** Ready Mode(Run ���)     */
#define SO_MODE_ACTIVE_RUN		(uint8)(0x04U)	/** Active Mode(�ְ� ���)   */
#define SO_MODE_STANDBY_RUN		(uint8)(0x08U)	/** Standby Mode(�ΰ� ���)  */
#define SO_MODE_SAFETY			(uint8)(0x10U)	/** Safety Mode              */
#define SO_MODE_SYSTEMDOWN		(uint8)(0x20U)	/** System Down              */
#define SO_MODE_SAFETY_NC		(uint8)(0x40U)	/** Safety Mode (��ü �Ұ�)  */
#define SO_MODE_CLEAR			(uint8)(0x00U)
/* ------------------------------------------------------------------------- */
/* ��� Max Counter                                                          */
/* ------------------------------------------------------------------------- */
#define FAIL_COUNT_VRDIN		(uint8)(0x19U)
#define FAIL_COUNT_VRDINILL		(uint8)(0x0AU)
#define VRD_ON_CHECK_COUNT		(uint8)(0x04U)
/* ------------------------------------------------------------------------- */
/* ��ȣ�� ���� ����                                                          */
/* ------------------------------------------------------------------------- */
#define SG_OUT_OK				((uint8)0x01U)
#define SG_IN_FAIL				((uint8)0x02U)
#define SG_LMR_OK				((uint8)0x04U)
#define SG_LMR_FAIL				((uint8)0x08U)
#define SG_LMR_OFF				((uint8)0x10U)
#define SG_LMR_YDOWN			((uint8)0x20U)
#define SG_LMR_RDOWN			((uint8)0x40U)
#define SG_LMR_DOWN_FAIL		((uint8)0X80U)
/* ------------------------------------------------------------------------- */
/* ��ȣ�� ���� ����                                                          */
/* ------------------------------------------------------------------------- */
#define SG_LOGASP_ON			((uint8)0x01U)

/* ------------------------------------------------------------------------- */
/* ��ȣ�� Delay                                                              */
/* ------------------------------------------------------------------------- */
#define SG_DLY_MASK				(uint8)(0x3FU)
#define SG_DLY_BSGVALUE			(uint8)(1400U/MAX_TICK_ILT)
#define SG_DLYBIT_BSGDRI		(uint8)(0x80U)
#define SG_DLYBIT_BSGBRI		(uint8)(0x40U)

/* ------------------------------------------------------------------------- */
/* �� ���� ��� Define                                                       */
/* ------------------------------------------------------------------------- */
#define REQ_LOCAL			((uint8)1U)
#define REQ_RC				((uint8)2U)
#define REQ_CTC				((uint8)3U)
#define ACPT_LOCAL			((uint8)4U)
#define ACPT_RC				((uint8)5U)
#define ACPT_CTC			((uint8)6U)
#define EMG_LOCAL			((uint8)7U)
#define EMG_RC				((uint8)8U)
#define EMG_CTC				((uint8)9U)

#define LOCAL_COMMAND		0U
#define CTC_COMMAND			1U
#define RC_COMMAND			2U

#define OPER_MODECTRL_BIT_CTCREQ		(uint8)(0x01U)
#define OPER_MODECTRL_BIT_LOCALREQ		(uint8)(0x04U)
#define OPER_MODECTRL_BIT_LOCALACPT		(uint8)(0x08U)
#define OPER_MODECTRL_BIT_EMGLOCAL		(uint8)(0x10U)
#define OPER_MODECTRL_BIT_RCREQ			(uint8)(0x20U)
#define OPER_MODECTRL_BIT_RCACPT		(uint8)(0x40U)
#define OPER_MODECTRL_BIT_EMGRC			(uint8)(0x80U)

#define OPER_MODECTRL_BIT_CTCACPT		(uint8)(0x11U)
#define OPER_MODECTRL_BIT_EMGCTC		(uint8)(0x22U)
/* ------------------------------------------------------------------------- */
/* LOCAL Element ���� Define                                                 */
/* ------------------------------------------------------------------------- */
#define MAX_LOCAL_ELEMENT			2899U	/** Local Element �ִ�ġ         */
#define MAX_LOCAL_ELEMENT_COMMON	32U		/** Local Element Common data �� */

#define LOCELM_TYPE_MASK	(uint16)(0xF000U)	/** Local Element Type Bit mask  */
#define LOCELM_OBJID_MASK	(uint16)(0x0FFFU)	/** Local Element Type Bit mask  */

#define LOCELM_TYPE_COMMON	(uint16)(0x1000U)
#define LOCELM_TYPE_TRACK	(uint16)(0x2000U)
#define LOCELM_TYPE_TCEX	(uint16)(0x3000U)
#define LOCELM_TYPE_SIGNAL	(uint16)(0x4000U)
#define LOCELM_TYPE_POINT	(uint16)(0x6000U)
#define LOCELM_TYPE_GIO		(uint16)(0x9000U)
#define LOCELM_TYPE_ROUTE	(uint16)(0x8000U)

#define LOCELM_IFID_OPC		(uint8)(0x01U)
#define LOCELM_IFID_MTC		(uint8)(0x02U)
#define LOCELM_IFID_RC		(uint8)(0x04U)
#define LOCELM_IFID_MTR		(uint8)(0x08U)
#define LOCELM_IFID_NONE	(uint8)(0x00U)
/* ------------------------------------------------------------------------- */
/* LOCAL Element ������� Define                                             */
/* ------------------------------------------------------------------------- */
#define BLDIR_EXIT_REQ				(uint8)(0x01U)	/** ���                 */
#define BLDIR_ENTRY_ACPT			(uint8)(0x02U)	/** �峻                 */
#define BLDIR_ENTRYOPEN_REQ			(uint8)(0x04U)	/** ���� (��û)          */
#define BLDIR_ENTRYOPEN_ACPT		(uint8)(0x08U)	/** ���� (����)          */
#define BLDIR_CANCEL_REQ			(uint8)(0x10U)	/** ��� (��û)          */
#define BLDIR_CANCEL_ACPT			(uint8)(0x20U)	/** ��� (����)          */
/* ------------------------------------------------------------------------- */
/* LOCAL Element ������ȯ�� ���� Define                                      */
/* ------------------------------------------------------------------------- */
#define LOCELM_CTRL_PT_N			(uint8)(0x10U)
#define LOCELM_CTRL_PT_R			(uint8)(0x20U)
/* ------------------------------------------------------------------------- */
/* LOCAL Element ���� ���� Define                                            */
/* ------------------------------------------------------------------------- */
#define LOCELM_CTRL_RT_SET			(uint8)(0x01U)
#define LOCELM_CTRL_RT_TTB			(uint8)(0x04U)
#define LOCELM_CTRL_RT_TTCB			(uint8)(0x08U)
#define LOCELM_CTRL_RT_CAN			(uint8)(0x10U)
#define LOCELM_CTRL_RT_RESET		(uint8)(0x20U)
/* ------------------------------------------------------------------------- */
/* LOCAL Element �˵� ���� Define                                            */
/* ------------------------------------------------------------------------- */
#define LOCELM_CTRL_TC_RELEASE		(uint8)(0x20U)
/* ------------------------------------------------------------------------- */
/* LOCAL Element RUN ���� Define                                             */
/* ------------------------------------------------------------------------- */
#define LOCELM_CTRL_RUN1			(uint8)(0x04U)
#define LOCELM_CTRL_RUN2			(uint8)(0x10U)
/* ------------------------------------------------------------------------- */
/* LOCAL Element ��ȯ�ҵ� ���� Define                                        */
/* ------------------------------------------------------------------------- */
#define LOCELM_CTRL_SHOFF_SET		(uint8)(0x10U)
#define LOCELM_CTRL_SHOFF_CAN		(uint8)(0x20U)
/* ------------------------------------------------------------------------- */
/* LOCAL Element ��ȣ���ϰ����� ���� Define                                  */
/* ------------------------------------------------------------------------- */
#define LOCELM_CTRL_SGALLSTOP_SET		(uint8)(0x10U)
#define LOCELM_CTRL_SGALLSTOP_CAN		(uint8)(0x20U)
/* ------------------------------------------------------------------------- */
/* LOCAL Element ���� ���� Define                                            */
/* ------------------------------------------------------------------------- */
#define LOCELM_CTRL_HET_SET		(uint8)(0x20U)
#define LOCELM_CTRL_HET_CAN		(uint8)(0x40U)
/* ------------------------------------------------------------------------- */
/* LOCAL Element State Bit Position Define                                   */
/* ------------------------------------------------------------------------- */
#define MAX_LOCELM_STATE_BUFF		12
#define MAX_LOCELM_BASESCAN_BUFF	4 /*[�ܼ���������]*/

#define LOCELM_AOFF_REQ_BIT1		0x10U
#define LOCELM_AOFF_REQ_BIT2		0x01U

#define LES_NONE			((uint8)0x00U)
/* --------------------------------- */
/* �ý��� �⵿ (RUN) ����            */
/* --------------------------------- */
#define LES_SYSRUN1			((uint8)0x04U)
#define LES_SYSRUN2			((uint8)0x08U)
/* --------------------------------- */
/* �ý��� �⵿ (RUN) ���� ����       */
/* --------------------------------- */
#define LES_OP_SYSRUN1		((uint8)0x10U)
#define LES_OP_SYSRUN2		((uint8)0x20U)
/* --------------------------------- */
/* ��� ���� ����                */
/* --------------------------------- */
#define LES_OPMD_CTCREQ		(uint8)(0x01U)
#define LES_OPMD_CTC		(uint8)(0x02U)
#define LES_OPMD_LOCALREQ	(uint8)(0x04U)
#define LES_OPMD_LOCAL		(uint8)(0x08U)
#define LES_OPMD_RCREQ		(uint8)(0x10U)
#define LES_OPMD_RC			(uint8)(0x20U)
/* --------------------------------- */
/* �������� 1 �� �ý��� ����       */
/* --------------------------------- */
#define LES_ILS1_ALARM		(uint8)(0x10U)
#define LES_ILS1_STATE		(uint8)(0x20U)
#define LES_ILS1_ACTIVE		(uint8)(0x40U)
/* --------------------------------- */
/* �������� 2 �� �ý��� ����       */
/* --------------------------------- */
#define LES_ILS2_ALARM		((uint8)0x10U)
#define LES_ILS2_STATE		((uint8)0x20U)
#define LES_ILS2_ACTIVE		((uint8)0x40U)
/* --------------------------------- */
/* �� ���� ��������(N1)   ����       */
/* --------------------------------- */
#define LES_N1_ALARM		((uint8)0x10U)
#define LES_N1_X1			((uint8)0x20U)
#define LES_N1_SUPPLY		((uint8)0x40U)
/* --------------------------------- */
/* �� ���� ö������(N2)  ����        */
/* --------------------------------- */
#define LES_N2_ALARM		((uint8)0x10U)
#define LES_N2_X2			((uint8)0x20U)
#define LES_N2_SUPPLY		((uint8)0x40U)
/* --------------------------------- */
/* UPS ����                          */
/* --------------------------------- */
#define LES_UPS_ALARM		((uint8)0x10U)
#define LES_UPS_STATE		((uint8)0x20U)
/* --------------------------------- */
/* ������ ����                       */
/* --------------------------------- */
#define LES_REC_ALARM		((uint8)0x10U)
#define LES_REC_STATE		((uint8)0x20U)
#define LES_REC_MAIN		((uint8)0x40U)
/* --------------------------------- */
/* ������ ����                       */
/* --------------------------------- */						
#define LES_CD_ALARM		((uint8)0x10U)
#define LES_CD_STATE		((uint8)0x20U)
/* --------------------------------- */
/* FUSE ����                         */
/* --------------------------------- */
#define LES_FUSE_ALARM		((uint8)0x10U)
#define LES_FUSE_STATE		((uint8)0x20U)
/* --------------------------------- */
/* ���� ������ȯ��(P��) ���� ����    */
/* --------------------------------- */
#define LES_PTPWN_ALARM		((uint8)0x10U)
#define LES_PTPWN_STATE		((uint8)0x20U)
/* --------------------------------- */
/* ���� ������ȯ��(P��) ���� ����    */
/* --------------------------------- */
#define LES_PTPWS_ALARM		((uint8)0x10U)
#define LES_PTPWS_STATE		((uint8)0x20U)
/* --------------------------------- */
/* ��ȣ�� ���� ���� ����             */
/* --------------------------------- */
#define LES_COSG_ALARM		((uint8)0x10U)
#define LES_COSG_STATE		((uint8)0x20U)
/* --------------------------------- */
/* ������ȯ�� ���� ���� ����         */
/* --------------------------------- */
#define LES_COPT_ALARM		((uint8)0x10U)
#define LES_COPT_STATE		((uint8)0x20U)
/* --------------------------------- */
/* �˵�ȸ�� ���� ���� ����           */
/* --------------------------------- */
#define LES_COTC_ALARM		((uint8)0x10U)
#define LES_COTC_STATE		((uint8)0x20U)
/* --------------------------------- */
/* ��ȣ���� ���Թ� ����            */
/* --------------------------------- */
#define LES_DOOR_ALARM		((uint8)0x10U)
#define LES_DOOR_LOCK		((uint8)0x20U)
/* --------------------------------- */
/* ��ȣ�� �ϰ����� ���� ����         */
/* --------------------------------- */
#define LES_ALLSGSTOP_SET	((uint8)0x10)
#define LES_ALLSGSTOP_REQ	((uint8)0x20)
/* --------------------------------- */
/* ��ȯǥ��(��ȣ��) �ҵ� ���� ����   */
/* --------------------------------- */
#define LES_SHOFF_SET		((uint8)0x10)
#define LES_SHOFF_REQ		((uint8)0x20)
/* --------------------------------- */
/* ���� ���� ���� ����	            */
/* --------------------------------- */
#define LES_PTHTN_SET		((uint8)0x40)
#define LES_PTHTN_REQ		((uint8)0x80)
/* --------------------------------- */
/* ���� ���� ���� ����               */
/* --------------------------------- */
#define LES_PTHTS_SET		((uint8)0x40)
#define LES_PTHTS_REQ		((uint8)0x80)
/* --------------------------------- */
/* COM12 ����                        */
/* --------------------------------- */
#define LES_COM12_LINK		((uint8)0x20)
#define LES_COM12_ACT		((uint8)0x40)
/* --------------------------------- */
/* �˵�ȸ�� ����                     */
/* --------------------------------- */
#define LES_TC_OCC			(uint8)(0x01U)
#define LES_TC_ROUTE		(uint8)(0x02U)
#define LES_TC_LRLOCK		(uint8)(0x04U)
#define LES_TC_FAIL			(uint8)(0x10U)
#define LES_TC_REQ			(uint8)(0x20U)
#define LES_TC_EMREL		(uint8)(0x40U)
#define LES_TC_DLOCK		(uint8)(0x80U)
/* --------------------------------- */
/* �˵�ȸ�� ǥ�� ����                */
/* --------------------------------- */
#define LES_TCTAG1_SHUNT	(uint8)(0x01U)
#define LES_TCTAG1_LINEX	(uint8)(0x02U)
#define LES_TCTAG1_BLOCKING	(uint8)(0x03U)
#define LES_TCTAG1_ELPWOUT	(uint8)(0x04U)
#define LES_TCTAG1_TROLLEY	(uint8)(0x05U)
#define LES_TCTAG1_HANDSG	(uint8)(0x06U)
#define LES_TCTAG1_USEBLK	(uint8)(0x07U)
#define LES_TCTAG1_COMM		(uint8)(0x08U)
#define LES_TCTAG1_TRBACK	(uint8)(0x09U)
#define LES_TCTAG1_NOPW		(uint8)(0x0AU)
#define LES_TCTAG2_SHUNT	(uint8)(0x01U)
#define LES_TCTAG2_LINEX	(uint8)(0x02U)
#define LES_TCTAG2_BLOCKING	(uint8)(0x03U)
#define LES_TCTAG2_ELPWOUT	(uint8)(0x04U)
#define LES_TCTAG2_TROLLEY	(uint8)(0x05U)
#define LES_TCTAG2_HANDSG	(uint8)(0x06U)
#define LES_TCTAG2_USEBLK	(uint8)(0x07U)
#define LES_TCTAG2_COMM		(uint8)(0x08U)
#define LES_TCTAG2_TRBACK	(uint8)(0x09U)
#define LES_TCTAG2_NOPW		(uint8)(0x0AU)
/* --------------------------------- */
/* ��ȣ�� ����                       */
/* --------------------------------- */
#define LES_SG_CALLON		(uint8)(0x01U)
#define LES_SG_TTB			(uint8)(0x02U)
#define LES_SG_LOCK			(uint8)(0x04U)
#define LES_SG_APLOCK		(uint8)(0x08U)
#define LES_SG_GO			(uint8)(0x10U)
#define LES_SG_FAIL			(uint8)(0x20U)
#define LES_SG_RTLM			(uint8)(0x40U)
#define LES_SG_RTLMFAIL		(uint8)(0x80U)
/* --------------------------------- */
/* ��ȣ�� ����                       */
/* --------------------------------- */
#define LES_INBSG_GO		(uint8)(0x10U)
#define LES_INBSG_FAIL		(uint8)(0x20U)
/* --------------------------------- */
/* ������ȯ�� ����	                 */
/* --------------------------------- */
#define LES_PT_N			(uint8)(0x01U)
#define LES_PT_R			(uint8)(0x02U)
#define LES_PT_LOCK			(uint8)(0x04U)
#define LES_PT_FAIL			(uint8)(0x08U)
#define LES_PT_TMLOCK		(uint8)(0x10U)
#define LES_PT_CTRLLK		(uint8)(0x20U)
#define LES_PT_NWRO			(uint8)(0x40U)
#define LES_PT_RWRO			(uint8)(0x80U)
/* --------------------------------- */
/* ���� ���� ���� ����               */
/* --------------------------------- */
#define LES_RUT_Y			((uint8)0x01)
#define LES_RUT_G			((uint8)0x02)
#define LES_RUT_Y1			((uint8)0x04)
#define LES_RUT_ING			((uint8)0x08)
#define LES_RUT_SET			((uint8)0x10)
#define LES_RUT_REQ			((uint8)0x20)
/* --------------------------------- */
/* ���(��޹�ư/����ǥ) ǥ�� ����   */
/* --------------------------------- */
#define LES_DIR_OUTYF		(uint8)(0x01U)
#define LES_DIR_OUTY		(uint8)(0x02U)
#define LES_DIR_OUTR		(uint8)(0x04U)
#define LES_DIR_OUTRF		(uint8)(0x08U)
#define LES_DIR_INYF		(uint8)(0x10U)
#define LES_DIR_INY			(uint8)(0x20U)
#define LES_DIR_INR			(uint8)(0x40U)
#define LES_DIR_INRF		(uint8)(0x80U)
/* --------------------------------- */
/* �ǳθ� ���� ����                  */
/* --------------------------------- */
#define LES_RC_ALARM		((uint8)0x10U)
#define LES_RC_STATE		((uint8)0x20U)
/* --------------------------------- */
/* ���幰������ġ ���� ����          */
/* --------------------------------- */
#define LES_OSTC_ALARM		((uint8)0x10U)
#define LES_OSTC_STATE		((uint8)0x20U)
#define LES_OSTC_OP			((uint8)0x40U)
/* --------------------------------- */
/* ��������������ġ ����             */
/* --------------------------------- */
#define LES_ISLAN1_ALARM	(uint8)(0x01U)
#define LES_ISLAN1_STATE	(uint8)(0x02U)
#define LES_ISLAN1_ACTIVE	(uint8)(0x04U)
#define LES_ISLAN2_ALARM	(uint8)(0x10U)
#define LES_ISLAN2_STATE	(uint8)(0x20U)
#define LES_ISLAN2_ACTIVE	(uint8)(0x40U)
/* --------------------------------- */
/* Ȯ�巢 ������ ����                */
/* --------------------------------- */
#define LES_EXREC_ALARM		((uint8)0x10U)
#define LES_EXREC_STATE		((uint8)0x20U)
/* ------------------------------------------------------------------------- */
/* Route Data Table Define                                                   */
/* ------------------------------------------------------------------------- */
/* (NEW) Route Data Type Define -------------------------------------------- */
#define RT_TYPE_MAIN				0x0001		/** �� ����                  */
#define RT_TYPE_TTB					0x0002		/** TTB ����                 */
#define RT_TYPE_CALLON				0x0004		/** ���� ����                */
#define RT_TYPE_MAINLINE			0x0008		/** ���� ����                */

#define RT_TYPE_SHUNT				0x0010		/** ��ȯǥ�� ����            */
#define RT_TYPE_SHUNTSIGNAL			0x0020		/** ��ȯ��ȣ�� ����          */
#define RT_TYPE_SHUNTOUT			0x0040		/** ��ȯ��ȣ�� ���          */
#define RT_TYPE_BLOCK				0x0100		/** ������� ���� RT_BLOCK   */

#define RT_TYPE_LIMIT_YY			0x1000		/** ���� �ִ����� YY         */
#define RT_TYPE_LIMIT_Y				0x2000		/** ���� �ִ����� Y          */
#define RT_TYPE_LIMIT_YG			0x4000		/** ���� �ִ����� YG         */
#define RT_TYPE_LIMIT_G				0x8000		/** ���� �ִ����� G          */
#define RT_TYPE_LIMIT_BITS			0xF000		/** ���� �ִ����� Mask Bit   */
/* ------------------------------------------------------------------------- */
/* Route Data (������ �˵�)                                                  */
/* ------------------------------------------------------------------------- */	
#define RT_DESTTC_ARRIVETRACK_BIT	0x8000U
#define RT_DEST_TM_LOCK_SET			0x80U
/* ------------------------------------------------------------------------- */
/* Route Data (��ȣ���� �˵� ����)                                           */
/* ------------------------------------------------------------------------- */	
#define RT_SIGTC_TC_OUTROUTE		0x4000		/** �����Ѱ� �˵�            */
#define RT_SIGTC_TCCOND_POINT		0x1000		/** �����Ѱ� ������ȯ�� ��� */
#define RT_SIGTC_TCCOND_CLOSETC		0x0800		/** ��μ��� �˵�ȸ��        */
#define	RT_SIGTC_CLSH				0x0400		/** ����/��ȯǥ�� �� ����    */
#define	RT_SIGTC_MSSHS				0x0200		/** ��/��ȯ ��ȣ�� �� ����   */
#define RT_SIGTC_TCCOND_TCMASK		0x01FF
/* ------------------------------------------------------------------------- */
/* Route Data (������ȯ�� ����)                                              */
/* ------------------------------------------------------------------------- */	
#define	RT_POINT_RLSTC				0x0200		/** �������� ����            */
#define	RT_POINT_CLSH				0x0400		/** ����/��ȯǥ�� �� ����    */
#define	RT_POINT_MSSHS				0x0800		/** ��/��ȯ ��ȣ�� �� ����   */
#define	RT_POINT_TMLOCK				0x1000		/** ��ȿ�� �ð����� ����     */
#define	RT_POINT_REVERSE			0x2000		/** ������ȯ�� ����          */
#define	RT_POINT_OVERLAP			0x4000		/** ���� ������ȯ�� ����     */
#define	RT_POINT_BACKROUTE			0x8000		/** �Ĺ���� ������ȯ�� ���� */
#define RT_POINT_OVERLAP_SG_MASK	0x01FF
/* ------------------------------------------------------------------------- */
/* Point Data Define                                                         */
/* ------------------------------------------------------------------------- */	
#define POINT_TYPE_SINGLE			0x01U	/** �ܵ�                         */
#define POINT_TYPE_DOUBLE			0x02U	/** �ֵ�                         */
#define POINT_TYPE_TRIPLE			0x03	/** �ﵿ                         */
#define POINT_TYPE_A				0x04	/** ������ A(�ֵ�/�ﵿ)          */
#define POINT_TYPE_B				0x05	/** ������ B(�ֵ�/�ﵿ)          */
#define POINT_TYPE_C				0x06	/** ������ C(�ֵ�/�ﵿ)          */
#define POINT_TYPE_MASK				0x0F	/** ----                         */
#define POINT_TYPE_GENERAL			0x10	/** �Ϲ�                         */
#define POINT_TYPE_HIGH				0x20	/** ���                         */
#define POINT_TYPE_INDIVIDUAL		0x40	/** ���� ó�� (D�� ������ȯ��)   */ /*�� �ǹ̷� ���ġ ����*/
#define POINT_TYPE_HIGH_NONCROSSING	0x40	/** ���(ũ�ν̺� ������)        */

#define MAX_TRACK_IN_POINTTABLE		3U		/** Point Table �� �˵� �ִ�ġ   */
#define MAX_POINT_IN_POINTTABLE		3U		/** Point Table �� ���� Point �ִ�ġ */

/* [CallBack����] */ /* [CallBack����] */
#define PT_CB_N						0x40U
#define PT_CB_R						0x80U

#define PT_CB_MASK_TM				0x0FU
#define PT_CB_WAIT_TM				(3000U/MAX_TICK_ILT)
/* ------------------------------------------------------------------------- */
/* Signal Data Define                                                        */
/* ------------------------------------------------------------------------- */	
#define SG_TYPE_NONE			0x00 	/** SIGNALTYPE_NONE                  */
#define SG_TYPE_BLK_SINTER		0x10 	/** �ܼ� �������                    */
#define SG_TYPE_BLK_SAUTO		0x20 	/** �ܼ� �ڵ���� - �⺻��           */
#define SG_TYPE_BLK_SAUTO_ABS	0x21	/** �ܼ� �ڵ���� - ABS              */
#define SG_TYPE_BLK_SAUTO_SBL	0x22 	/** �ܼ� �ڵ���� - �����           */
#define SG_TYPE_BLK_MINTER		0x30 	/** ���� �������                    */
#define SG_TYPE_BLK_MAUTO		0x40 	/** ���� �ڵ����                    */
#define SG_TYPE_BLK_MAUTO_DN	0x41 	/** ����� �峻������                */ /*�߰�170831*/
#define SG_TYPE_BLK_MAUTO_DR	0x42 	/** ����� �峻������                */ /*�߰�170831*/
#define SG_TYPE_BLK_M5AUTO		0x50 	/** ���� 5���� �ڵ� ���             */

#define SG_TYPE_REFERENCE		0x60 	/** ���� ��ȣ��                      */

#define SG_TYPE_ATS				0x70	/** ATS ���ǥ���                   */ /* 171226 [ATS�����߰�] */

#define SG_TYPE_ENTRY			0x80 	/** �峻 ��ȣ��                      */
#define SG_TYPE_EXIT			0xA0 	/** ��� ��ȣ��                      */
#define SG_TYPE_INBLOCK			0x90 	/** ������� ��ȣ��                  */
#define SG_TYPE_SHUNT			0xB0 	/** ��ȯ ǥ��                        */
#define SG_TYPE_SUHNTSG			0xB8 	/** ��ȯ ��ȣ��                      */
#define SG_TYPE_REPEATSG		0xC0 	/** �߰��ȣ��(�Է�ó�� ��)          */
#define SG_TYPE_DISTANTSG		0xD0 	/** �����ȣ��                       */
#define SG_TYPE_REPEATSG_CTRL	0xE0 	/** �߰��ȣ��(��� �����)          */
#define SG_TYPE_CALLON_BIT		0x08 	/** ������ȣ�� ����                  */
#define SG_TYPE_DIR_BIT			0x04U 	/** ��ȣ�� ���� ���� (����:Set)      */

#define SG_TYPE_MAINTEST_BIT	0x01 	/** ���輱�� �ֽ�ȣ��                */


#define SG_TYPE_OUTBLOCK		0xF0	/** ���� �����ȣ��                  */
#define SG_TYPE_VALUE			0xF0
#define SG_TYPE_VALUE_TESTBIT	0xF1

#define SG_ASPECT_LIMIT_2		0x00	/** 2���� ��ȣ��                     */
#define SG_ASPECT_LIMIT_3		0x01	/** 3���� ��ȣ��                     */
#define SG_ASPECT_LIMIT_4		0x02	/** 4���� ��ȣ��                     */
#define SG_ASPECT_LIMIT_5		0x03	/** 5���� ��ȣ��                     */
#define SG_ASPECT_LIMIT_MASK	0x0F	/*0x03*/	/** ���� Mask bit        */
/* ------------------------------------------------------------------------- */
/* Signal LMR Fail Check Value                                               */
/* ------------------------------------------------------------------------- */	
#define SGLMR_GOOD				((uint16)0x0001U)/** ���� ���� Good                   */
#define SGLMR_CTRL_HROFF		((uint16)0x0002U)/** ���� ���� �̻����� HR Off ����   */
#define SGLMR_CTRL_ZROFF		((uint16)0x0004U)/** ���� ���� �̻����� ZR Off ����   */
#define SGLMR_FAIL_R			((uint16)0x0008U)/** ���� ���� ���� ���              */
#define SGLMR_FAIL_Y1			((uint16)0x0010U)/** Y1 ���� ���� ���                */
#define SGLMR_FAIL_YY			((uint16)0x0020U)/** YY ���� ���� ���                */
#define SGLMR_FAIL_YF			((uint16)0x0040U)/** Y  ���� ���� ���       */
#define SGLMR_FAIL_YGG			((uint16)0x0080U)/** YG�� G ���� ���� ���   */
#define SGLMR_FAIL_YGY			((uint16)0x0100U)/** YG�� Y ���� ���� ���   */
#define SGLMR_FAIL_G			((uint16)0x0200U)/** G  ���� ���� ���                */
#define SGLMR_FAIL_ZLMR			((uint16)0x0400U)/** ���� ���� ���� ���              */
#define SGLMR_ASP_DOWN			((uint16)0x0800U)/** �� ���� ���� ����                */
#define SGLMR_ASP_FAIL			((uint16)0x1000U)/** ���� ���� �̻�                   */
#define SGLMR_FAIL_LMR			((uint16)0x2000U)/** LMR ���� �̻�                    */
#define SGLMR_FAIL_ONLY_Y1		((uint16)0x4000U)/** Y1�� ����                        */
#define SGLMR_CTRL_GROFF		((uint16)0x8000U)/** ���� ���� �̻����� GR Off ����   */ /* [G�ҵ�GRoffó��] */
/* ------------------------------------------------------------------------- */
/* Track Data Define                                                         */
/* ------------------------------------------------------------------------- */	
#define TC_TYPE_NOTRACK			0x00	/** NO Track -- TI_NOTRACK           */
#define TC_TYPE_INTRACK			0x01	/** ���� �˵� -- TI_INTRACK          */
#define TC_TYPE_BLOCKTRACK		0x02	/** ��� �˵�                        */
/*#define TC_TYPE_HASPREV			0x04*//** (�ӽ� DES��������� ����)      */
#define TC_TYPE_NODELAY			0x04	/** ��������ó�� ����(1:����0:����)  */
#define TC_TYPE_HASDEPTNI		0x08	/** (�ӽ� DES��������� ����)        */
#define TC_TYPE_ENDTRACK		0x10	/** ���� �˵�                        */
#define TC_TYPE_TNITRACK		0x20	/** ����â ���� �˵�                 */
#define TC_TYPE_DESTTRACK		0x40	/** ���� �˵�                        */
#define TC_TYPE_ALARMTC			0x80	/** �˶�ó�� �˵�                    */

#define MAX_SGINTC			12		/** �˵� Table���� ���� ��ȣ�� �ִ� ��   */
#define MAX_TCLR_POINT		5		/** �˵� �������� Table���� ����Ʈ���� �ִ� �� */
#define MAX_TCLR_LINK		12		/** �� �˵��� �������� �ִ� ��           */

#define TCS_RT_RLK		0x80U
#define TCS_RT_LLK		0x40U
#define TCS_RT_REQ		0x08U
#define TCS_RT_SET		0x04U

#define CLS_ALL				((uint8)0xAA)	/** �˵� ���ΰ��� ���� ��ü Clear*/
#define CLS_RSRQ			((uint8)0xC1)	/** �˵� ���μ���/��û ���� Clear*/
#define CLS_RTS				((uint8)0xC2)	/** �˵� ���μ��� ���� Clear     */
#define CLS_REQ				((uint8)0xC3)	/** �˵� ���ο�û ���� Clear     */
#define CLS_RLK				((uint8)0xC4)	/** �˵� ���μ��� ���� Clear     */

#define TC_RELEASE_FAIL_DELAY_CNT		(3000U/MAX_TICK_ILT)
#define SET_TC_RELEASE_FAIL_CHECKBIT	0x80U
#define SET_TC_RELEASE_FAIL_OVERLAP		0x40U
/* ------------------------------------------------------------------------- */
/* Route/Signal/Track Direction                                              */
/* ------------------------------------------------------------------------- */
#define RTDIR_LUP			1
#define RTDIR_RDOWN			0
#define TRKDIR_L			((uint8)0x01)
#define TRKDIR_R			((uint8)0x02)
/* ------------------------------------------------------------------------- */
/* Route Data �� ���� Data �ִ�ġ                                            */
/* ------------------------------------------------------------------------- */
#define MAX_RT_POINT		30
#define MAX_RT_CONFLICTSG	30
#define MAX_RT_SIGTRACK		30
#define MAX_RT_RATRLSTC		30
#define MAX_RT_EXCEPTION	30
/* ------------------------------------------------------------------------- */
/* Signal Input Error Check Value                                            */
/* ------------------------------------------------------------------------- */
#define SG_INFAIL_YR		((uint8)0x01U)
#define SG_INFAIL_GR		((uint8)0x02U)
#define SG_INFAIL_HR		((uint8)0x04U)
#define SG_INFAIL_UR		((uint8)0x08U)
/* ------------------------------------------------------------------------- */
/* Route Control State                                                       */
/* ------------------------------------------------------------------------- */
#define ROUTE_INVOKE		(uint16)(0x8000U)  /* ���� ����� ? */
#define ROUTE_CANCEL		(uint16)(0x4000U)  /* ������� ���� */
#define ROUTE_ONPROCESS		(uint16)(0x2000U)  /* ���μ��� �� -- �б���ȯ��  */
#define ROUTE_ONEMCANCEL	(uint16)(0x1000U)  /* �������κ����������       */
#define ROUTE_DEPBLOCK		(uint16)(0x0800U)
#define ROUTE_ONRTFAIL		(uint16)(0x0400U)
#define RT_STATE_IDMASK		(uint16)(0x03FFU)

/* g_ausRouteSetInTrack[]�� bit state define */
#define ROUTE_FIRST_TC		(uint16)(0x8000U)	/** �������� ù �˵�ȸ��     */
#define ROUTE_EXIT_TC		(uint16)(0x4000U)	/** �������                 */
#define ROUTE_TC_MASK		(uint16)(0x0FFFU)

#define RT_CTRLSTATE_SET	(uint8)(0x01U)		/* ���� �������  ����       */
#define RT_CTRLSTATE_RECTRL	(uint8)(0x02U)   	/* ���� ��������� ����      */
#define RT_CTRLSTATE_CAN	(uint8)(0x04U)		/* ���� �������  ����       */
#define RT_CTRLSTATE_TTBSET	(uint8)(0x08U)		/* TTB �������� ����         */
#define RT_CTRLSTATE_TTBCAN	(uint8)(0x10U)		/* TTB ������� ����         */
/* ------------------------------------------------------------------------- */
/* Route Check State                                                         */
/* ------------------------------------------------------------------------- */
#define ROUTECHECK_TRACK	(uint8)(0x01U)	/** �˵� ���� ����               */
#define ROUTECHECK_SWITCH	(uint8)(0x02U)	/** ������ȯ�� �̻� ����         */
#define ROUTECHECK_SIGNAL	(uint8)(0x04U)	/** ��ȣ�� �̻� ����             */
#define ROUTECHECK_ROUTE	(uint8)(0x08U)	/** ���� �̻� ����               */
#define ROUTECHECK_SWFREE	(uint8)(0x10U)	/** ������ȯ�� Free              */
#define ROUTECHECK_REROUTE	(uint8)(0x20U)	/** ����� ���� ����             */
#define ROUTECHECK_RECONT	(uint8)(0x40U)	/** ����� ó��                  */
#define ROUTECHECK_CONTACT	(uint8)(0x80U)	/**                              */

#define ROUTECHECK_GOOD     (uint8)(0x00U)	/** ��ȣ ���� ���� ����          */
#define ROUTECHECK_ENABLE   (uint8)(0x2EU)
#define ROUTECHECK_REENABLE (uint8)(0x8FU)

#define ROUTECHECK_SGOFF    ((uint8)0x97U)	/* ROUTECHECK_SWFREE+ROUTECHECK_TRACK+ROUTECHECK_SWITCH+ROUTECHECK_SIGNAL+ROUTECHECK_CONTACT */

#define RT_CHECK_ALARM_ON	((uint8)0x01U)
#define RT_CHECK_ALARM_OFF	((uint8)0x00U)
/* ------------------------------------------------------------------------- */
/* Route EG Release (�������� ó�� ��)                                       */
/* ------------------------------------------------------------------------- */
#define RT_EGRLS_SET		((uint8)0x01U)
#define RT_EGRLS_TKFREE		((uint8)0x02U)
/* ------------------------------------------------------------------------- */
/* Route Exception Data Type (�������� True ����)                            */
/* ------------------------------------------------------------------------- */
#define RT_EX_GIO_OBJID_MASK	((uint16)0x00FFU) /*�߰�170927*/
#define RT_EX_GIOBIT_MASK		((uint16)0x0F00U) /*�߰�170927*/

#define RT_EX_TYPEMASK		((uint8)0x7FU)	/** ���ο��� Ÿ��ID Mask             */
#define RT_EX_SGLK_COND		((uint8)0x80U)	/** 1:��ȣ��޺Ұ�/0:��ȣ����Ұ�    */

#define RT_EX_SG_GO			(uint8)(0x01U)	/** ��ȣ�� ���� (SG Obj ID ���)     */
#define RT_EX_SG_STOP		(uint8)(0x02U)	/** ��ȣ�� ���� (SG Obj ID ���)     */
#define RT_EX_SG_LOCK		(uint8)(0x03U)	/** ��ȣ�� ���� (SG Obj ID ���)     */
#define RT_EX_SG_CONT		(uint8)(0x04U)	/** ��ȣ�� �������� (SG Obj ID ���) */
#define RT_EX_GIO_LOGIC		(uint8)(0x11U)	/** LOGIC������ GIO��� (GIO ID ���) - GIO Bit ���� ���� */
#define RT_EX_RC_ALM_OUT_A	(uint8)(0x12U)	/** �ǳθ� A ���� (GIO ID ���)      */ /* ���ġ���� ���� ����*/
#define RT_EX_RC_ALM_OUT_B	(uint8)(0x13U)	/** �ǳθ� B ���� (GIO ID ���)      */ /* ���ġ���� ���� ����*/
#define RT_EX_RC_ALM_OUT_C	(uint8)(0x14U)	/** �ǳθ� C ���� (GIO ID ���)      */ /* ���ġ���� ���� ����*/
#define RT_EX_RC_ALM_OUT_D	(uint8)(0x15U)	/** �ǳθ� D ���� (GIO ID ���)      */ /* ���ġ���� ���� ����*/
#define RT_EX_APPROACH		(uint8)(0x12U)	/** ���κ� ���ټ��� �������� (GIO ID ���) - GIO Bit ���� ���� */ /*�߰�170927*/
#define RT_EX_NO_RT_RELEASE	(uint8)(0x13U)	/** ������� �Ұ��� ���� (GIO ID ���) - GIO Bit ���� ���� */ /*�߰�170927*/
#define RT_EX_OPT1			(uint8)(0x14U)	/** Spare 1                          */
#define RT_EX_OPT2			(uint8)(0x15U)	/** Spare 2                          */
#define RT_EX_RT_LOCK		(uint8)(0x21U)	/** ���� ���� (RT Obj ID ���)       */
#define RT_EX_RT_UNLOCK		(uint8)(0x22U)	/** ���� ���� (RT Obj ID ���)       */
#define RT_EX_RT_CONT		(uint8)(0x23U)	/** ���� ���� (RT Obj ID ���)       */
#define RT_EX_RT_LKDEST_EXC	(uint8)(0x24U)	/** �����˵�Ÿ���μ���  (RT ID ���) */
#define RT_EX_RT_LKTC_EXC	(uint8)(0x25U)	/** ���γ��˵�Ÿ���μ���(RT ID ���) */
#define RT_EX_TC_RELEASE	(uint8)(0x26U)	/** �˵� ��������(TC ID ���)        */
#define RT_EX_BSG_DIR_STOP	(uint8)(0x31U)	/** ����峻 ���� (SG Obj ID ���)   */
#define RT_EX_RT_DEST_OUT	(uint8)(0x41U)	/** ���μ���(����)���  (GIO(0x06) ID ���)*/
#define RT_EX_RT_DEST_CLOFF	(uint8)(0x42U)	/** ���μ��� ������� Off  (GIO(0x06) ID ���)*/
#define RT_EX_RT_LOCK_OUT	(uint8)(0x43U)	/** ���μ������  (GIO(0x07) ID ���)*/
#define RT_EX_RT_START_LO	(uint8)(0x44U)	/** ���μ���(�ù�)�����  (GIO(0x08) ID ���)*/
#define RT_EX_RT_START_RO	(uint8)(0x45U)	/** ���μ���(�ù�)�����  (GIO(0x08) ID ���)*/
#define RT_EX_RT_START_CO	(uint8)(0x46U)	/** ���μ���(�ù�)�����  (GIO(0x08) ID ���)*/
#define RT_EX_ASP_MOD_YY	(uint8)(0x51U)	/** �ִ����� YY (RT Obj ID ���) */ /*�߰�170831*/
#define RT_EX_ASP_MOD_Y		(uint8)(0x52U)	/** �ִ����� Y  (RT Obj ID ���) */ /*�߰�170831*/
#define RT_EX_ASP_MOD_YG	(uint8)(0x53U)	/** �ִ����� YG (RT Obj ID ���) */ /*�߰�170831*/
#define RT_EX_ASP_MOD_G		(uint8)(0x54U)	/** �ִ����� G  (RT Obj ID ���) */ /*�߰�170831*/
/* ------------------------------------------------------------------------- */
/* ������ȯ�� ���� ���� ����                                                 */
/* ------------------------------------------------------------------------- */
#define POINT_CHECK_CTRL_N	(uint8)(0x01U)
#define POINT_CHECK_CTRL_R	(uint8)(0x02U)
#define ROUTE_CTRL_N		(uint8)(0x04U)
#define ROUTE_CTRL_R		(uint8)(0x08U)
#define POINT_WRMOVE_FAIL	(uint8)(0x40U)
#define POINT_KRMOVE_FAIL	(uint8)(0x80U)
/* ------------------------------------------------------------------------- */
/* ��� ��� ���� Ÿ�̸�                                                     */
/* ------------------------------------------------------------------------- */
#define BSG_OUT_TMR			3
/* ------------------------------------------------------------------------- */
/* ������ȯ�� ���� ���� �Է¸��� Ÿ�̸�                                      */
/* ------------------------------------------------------------------------- */
#define PHT_TMR				25U
#define PPW_TMR				13U
/* ------------------------------------------------------------------------- */
/* Task ���� Define                                                          */
/* ------------------------------------------------------------------------- */
#define MAX_TASK		16U
#define USED_TASK		10U

#define TASK_SVT		0U
#define TASK_IOSIF		1U
#define TASK_OPCIF		2U
#define TASK_MTCIF		3U
#define TASK_CTCIF		4U
#define TASK_ILT		5U
#define TASK_RCIF		6U
#define TASK_COMIF		7U
#define TASK_GPT 		8U
#define TASK_COMMDRV	9U	/* [TASK�߰�] uart ���� driver task */
#define TASK_AST		10U
/* ------------------------------------------------------------------------- */
/* TaskInfo Bit Pos State                                                    */
/* ------------------------------------------------------------------------- */
#define TINFO_USED		0x01U

#define TINFO_CTC_USED	0x04U			/** CTC: CTC ���� �� Flag            */

#define TINFO_RC_EES	0x02U			/** RC: �����������ý��� ���      */
#define TINFO_RC_OPC	0x04U			/** RC: OPCȮ������ RC ����          */
#define TINFO_RC_LOCAL	0x08U			/** RC: RC�� ����(LOCAL���)       */

/* �ø��� ��� �ӵ� ���� default 19200 */
#define TINFO_BAUD_9600		0x10U		/** baud 9600                        */
#define TINFO_BAUD_38400	0x20U		/** baud 38400                       */
#define TINFO_BAUD_57600	0x40U		/** baud 57600                       */
#define TINFO_BAUD_115200	0x80U		/** baud 115200                      */


/*#define TINFO_RC_PORTNO	0xF0U*/		/** RC: �������ý��� �� Port No.   */
/*#define TINFO_CTC_VER	0xF0U*/			/** CTC: ǥ��ȭ ���� No.             */

#define TINFO_ILT_POINTMISMATCH_DELAY_MASK	0x30U	/** ���� 2bit (0 ~ 3) delay ���� */
/* ------------------------------------------------------------------------- */
/* IO Module ���� Define (KRSEIS �� DB ����)                                 */
/* ------------------------------------------------------------------------- */
#define MAX_IO_MODULE						256
#define MAX_IOM_STATE_BUFFER_SIZE			32
#define MAX_IO_PORT							32
#define MAX_ALL_IO_PORT						(MAX_IO_MODULE * MAX_IO_PORT)
#define SIZE_INOUT_BUFFER					1024U
#define SIZE_IOPORT_FAIL_DATA				1024

#define IO_MODULE_FAILURE					((uint8)0xF1)
#define IO_PORT_FAILURE						((uint8)0xF2)
/* ------------------------------------------------------------------------- */
/* IO Module ���� Define (ZEST ���� ���)                                    */
/* ------------------------------------------------------------------------- */
#define MAX_IOS						15U	/** ZEST IOS �ִ��                  */

#define REAL_IOM_STATE_BUFFER_SIZE	30U	/** ZEST IO MODULE �ִ�� 
											IOS(15) * 16bit = 30Byte         */
#define REAL_MAX_IO_PORT			16U	/** ZEST IO ���� port ��           */
#define REAL_MODULE_PER_IOS			16U	/** ZEST IOS �� ��� ��              */

/* ZEST �ִ� IO��� �� 240 */
#define REAL_MAX_IO_MODULE		(MAX_IOS * REAL_MODULE_PER_IOS)	
/* ZEST �ִ� port �� 3,840 */
#define REAL_MAX_ALL_IO_PORT	(REAL_MAX_IO_MODULE * REAL_MAX_IO_PORT)	

#define REAL_SIZE_INOUT_BUFFER		480U	/** ��üIO bit�� ���� byte size 3840bit */
#define REAL_SIZE_IOPORT_FAIL_DATA	480U	/** ��üIO bit�� ���� byte size 3840bit */

#define REAL_SIZE_IODATA_PER_IOS	32U	/** IOS�� ��üIO bit�� ���� byte 256bit */

#define BYTE_PER_IOMD	(REAL_MAX_IO_PORT/8)	/** IO��� ��ü IO bit�� ���� byte size 16bit */

#define SYS_INOUT_MISMATCH_CNT		5U
/* ------------------------------------------------------------------------- */
/* IO Type ���� Define                                                       */
/* ------------------------------------------------------------------------- */
#define IOM_TY_IN					((uint8)0x01)
#define IOM_TY_OUT					((uint8)0x02)
#define IOM_TY_PDO					((uint8)0x03)
/* ---------------------------- */
/* IO Object Type               */
/* ---------------------------- */
#define OBJECT_TYPE_COMMON			0x01
#define OBJECT_TYPE_TRACK			0x02
#define OBJECT_TYPE_SIGNAL			0x04
#define OBJECT_TYPE_POINT			0x08
#define OBJECT_TYPE_GIO				0x10
#define OBJECT_TYPE_BUTTON			0x20
/* ---------------------------- */
/* IO Common Type               */
/* ---------------------------- */
#define IO_TYPE_NONE				0x00
#define IO_T_COMMON_EGRUNSWLOCAL	0x01		/** I  ��� Run Switch(Local)*/
#define IO_T_COMMON_EGRUNSWRC		0x02		/** I  ��� Run Switch(RC)   */
#define IO_T_COMMON_EGCTCSWLO		0x03		/** I  ��� CTC Switch(Local)*/
#define IO_T_COMMON_EGCTCSWRC		0x04		/** I  ��� CTC Switch(RC)   */
#define IO_T_COMMON_EGLOSW			0x05		/** I  ��� Local Switch     */
#define IO_T_COMMON_EGRCSW			0x06		/** I  ��� RC Switch        */
#define IO_T_COMMON_VRDI1			0x07		/** I  VRDI_1                */
#define IO_T_COMMON_VRDI2			0x08		/** I  VRDI_2                */
#define IO_T_COMMON_ACTIVE1I		0x09		/** I  Active_1              */
#define IO_T_COMMON_ACTIVE2I		0x0A		/** I  Active_2              */
#define IO_T_COMMON_N1				0x0B		/** I  N1                    */
#define IO_T_COMMON_N2				0x0C		/** I  N2                    */
#define IO_T_COMMON_X1				0x0D		/** I  X1                    */
#define IO_T_COMMON_X2				0x0E		/** I  X2                    */
#define IO_T_COMMON_UPS				0x0F		/** I  UPS                   */
#define IO_T_COMMON_AVR1			0x10		/** I  AVR1(������)          */
#define IO_T_COMMON_AVR2			0x11		/** I  AVR2(������)          */
#define IO_T_COMMON_BAT				0x12		/** I  Battery               */
#define IO_T_COMMON_FUSE			0x13		/** I  Field Fuse            */
#define IO_T_COMMON_EISFUSE1		0x14		/** I  EIS Fuse1             */
#define IO_T_COMMON_EISFUSE2		0x15		/** I  EIS Fuse2             */
#define IO_T_COMMON_SWPWN			0x16		/** I  Point PW N            */
#define IO_T_COMMON_SWPWS			0x17		/** I  Point PW S            */
#define IO_T_COMMON_SWHETN_I		0x18		/** I  Point Heat N �Է�     */
#define IO_T_COMMON_SWHETS_I		0x19		/** I  Point Heat S �Է�     */
#define IO_T_COMMON_SHPWOFFI		0x1A		/** I  Shunt PW Off �Է�     */
#define IO_T_COMMON_UPSAC			0x1B		/** I  UPS AC Fail           */
#define IO_T_COMMON_EXTCARD			0x1C		/** I  EXT Card Fail         */
#define IO_T_COMMON_SWHETFAIL_N		0x1D		/** I  Point Heat Fail N     */
#define IO_T_COMMON_SWHETFAIL_S		0x1E		/** I  Point Heat Fail S     */
#define IO_T_COMMON_KEYLOCK			0x1F		/** I  ��ȣ���� Key Lock   */
#define IO_T_COMMON_SYSRECOVERY		0x20		/** I  EIS ������������ �Է� */ /*��ġ: SMEM / TS_SMEM_SYSSTAT_SYSTEMSTATE / bSysRecovery */
#define IO_T_COMMON_POINTPWI_N		0x21		/** I  Point N PW ���� �Է�  */
#define IO_T_COMMON_POINTPWI_S		0x22		/** I  Point S PW ���� �Է�  */

/*#define IO_T_COMMON_VCR_A			0x30		  * I  VCR A �Է�              */
/*#define IO_T_COMMON_VCR_B			0x31		  * I  VCR B �Է�              */
#define IO_T_COMMON_VCR_1A			0x30		/** I  VCR 1�� A �Է�        */ /* [VCR�߰�����] 171127 Define ���� */
#define IO_T_COMMON_VCR_1B			0x31		/** I  VCR 1�� B �Է�        */ /* [VCR�߰�����] 171127 Define ���� */
#define IO_T_COMMON_VCR_2A			0x32		/** I  VCR 2�� A �Է�        */ /* [VCR�߰�] 171127 IO Type �߰� */
#define IO_T_COMMON_VCR_2B			0x33		/** I  VCR 2�� B �Է�        */ /* [VCR�߰�] 171127 IO Type �߰� */

#define IO_T_COMMON_VRDO1			0x81		/** O  VRDO1                 */
#define IO_T_COMMON_VRDO2			0x82		/** O  VRDO2                 */
#define IO_T_COMMON_ACTIVEO1		0x83		/** O  ACTIVEO1              */
#define IO_T_COMMON_ACTIVEO2		0x83		/** O  ACTIVEO2              */
#define IO_T_COMMON_SWHETN_O		0x84		/** O  Point Heat N ���     */
#define IO_T_COMMON_SWHETS_O		0x85		/** O  Point Heat S ���     */
#define IO_T_COMMON_SHPWOFFO		0x86		/** O  Shunt PW Off ���     */
#define IO_T_COMMON_POINTPWO_N		0x87		/** O  Point N PW ���� ���  */
#define IO_T_COMMON_POINTPWO_S		0x88		/** O  Point S PW ���� ���  */
/* ---------------------------- */
/* IO Track Type                */
/* ---------------------------- */
#define IO_T_TRACK_OCCUPY			0x02		/** I  Track Occupy          */
#define IO_T_TRACK_TLS				0x07		/** O  ��ȣ �� ����          */
#define IO_T_TRACK_TRS				0x08		/** O  ��ȣ �� ����          */
#define IO_T_TRACK_RTL				0x0A		/** O  ���� �� ����          */
#define IO_T_TRACK_RTR				0x0B		/** O  ���� �� ����          */
#define IO_T_TRACK_OCL				0x0C		/** O  �� ����               */
#define IO_T_TRACK_OCR				0x0D		/** O  �� ����               */
#define IO_T_TRACK_CFLTLK			0x0E		/** I  �������              */
#define IO_T_TRACK_AXR				0x0F		/** O  ����ī��Ʈ���� ���   */ /* 171220 �߰� [����ī���͸���] */
/* ---------------------------- */
/* IO Signal Type               */
/* ---------------------------- */
#define IO_T_SG_YRI					0x05	/** I  YR                        */
#define IO_T_SG_GRI					0x06	/** I  GR                        */
#define IO_T_SG_HRI					0x07	/** I  HR                        */
#define IO_T_SG_URI					0x08	/** I  UR                        */
#define IO_T_SG_YM_LMR 				0x19	/** I  YM_LMR                    */
#define IO_T_SG_YA_LMR 				0x1A	/** I  YA_LMR                    */
#define IO_T_SG_RM_LMR 				0x1B	/** I  RM_LMR                    */
#define IO_T_SG_RA_LMR 				0x1C	/** I  RA_LMR                    */
#define IO_T_SG_GM_LMR 				0x1D	/** I  GM_LMR                    */
#define IO_T_SG_GA_LMR 				0x1E	/** I  GA_LMR                    */
#define IO_T_SG_Y1M_LMR				0x1F	/** I  Y1M_LMR                   */
#define IO_T_SG_Y1A_LMR				0x20	/** I  Y1A_LMR                   */
#define IO_T_SG_ZLMR				0x11	/** I  ZLMR(������ȣ�� ���û���) */ /*171220 [ZLMR�и��߰�]*/
#define IO_T_SG_MRTLMR				0x17	/** I  ���μ��� ��Lamp(MRTLMR)   */
#define IO_T_SG_ARTLMR				0x18	/** I  ���μ��� ����Lamp(ARTLMR) */
#define IO_T_SG_YRO					0x09	/** O  YRO                       */
#define IO_T_SG_GRO					0x0A	/** O  GRO                       */
#define IO_T_SG_HRO					0x0B	/** O  HRO                       */
#define IO_T_SG_URO					0x0C	/** O  URO                       */
#define IO_T_SG_MRFAIL				0x0D	/** I  ����ǥ�ñ� �������       */ /*171220 [MRFAIL�߰�]*/
/* ---------------------------- */
/* IO Block Type                */
/* ---------------------------- */
#define IO_T_BSG_EHBRI				0x03			/** I  EHBRI	         */
#define IO_T_BSG_DIRI				0x04			/** I  DIRI	             */
#define IO_T_BSG_EHDRI				0x05			/** I  EHDRI	         */
#define IO_T_BSG_BLTI				0x07			/** I  BLTI	             */
#define IO_T_BSG_EHRRI				0x08			/** I  EHRRI	         */
#define IO_T_BSG_TPSR				0x10			/** I  TPSR	             */
#define IO_T_BSG_EHCNRI 			0x0E			/** I  EHCNRI	         */
#define IO_T_BSG_RREH   			0x12			/** I  RREH  �������    */
#define IO_T_BSG_OREH   			0x13			/** I  OREH  �������    */
#define IO_T_BSG_AREH   			0x19			/** I  AREH  �������    */
#define IO_T_BSG_CREH   			0x1C			/** I  CREH  �������    */
#define IO_T_BSG_RRO				0x01			/** O  RRO	             */
#define IO_T_BSG_BRO				0x02			/** O  BRO	             */
#define IO_T_BSG_CNRO   			0x06			/** O  CNRO	             */
#define IO_T_BSG_BLK_ARO			0x11			/** O  BLK_ARO  ������� */
#define IO_T_BSG_BLK_CRO			0x14			/** O  BLK_CRO  ������� */
#define IO_T_BSG_BLK_RRO			0x1A			/** O  BLK_RRO  ������� */
#define IO_T_BSG_BLK_ORO			0x1B			/** O  BLK_ORO  ������� */
#define IO_T_BSG_GRI 				0x1E			/** I  ������� GR       */
#define IO_T_BSG_YRI				0x1F			/** I  ������� YR       */
#define IO_T_BSG_Y1RI				0x20			/** I  ������� Y1R      */
/* ---------------------------- */
/* IO Point Type                */
/* ---------------------------- */
#define IO_T_PT_WR_I_N				0x09			/** I  WR_I_N   */
#define IO_T_PT_WR_I_R				0x0A			/** I  WR_I_R   */
#define IO_T_PT_WLRI  				0x0B			/** I  WLRI     */
#define IO_T_PT_KR_N				0x0F			/** I  (A)KR_N  */
#define IO_T_PT_KR_R				0x10			/** I  (A)KR_R  */
#define IO_T_PT_BKR_N 				0x11			/** I  BKR_N    */
#define IO_T_PT_BKR_R 				0x12			/** I  BKR_R    */
#define IO_T_PT_CKR_N 				0x13			/** I  CKR_N    */
#define IO_T_PT_CKR_R 				0x14			/** I  CKR_R    */
#define IO_T_PT_DKR_N 				0x15			/** I  DKR_N    */
#define IO_T_PT_DKR_R 				0x16			/** I  DKR_R    */
#define IO_T_PT_AMCRI 				0x1B			/** I  AMCRI    */
#define IO_T_PT_BMCRI 				0x1C			/** I  BMCRI    */
#define IO_T_PT_CMCRI 				0x1D			/** I  CMCRI    */
#define IO_T_PT_DMCRI 				0x1E			/** I  DMCRI    */
#define IO_T_PT_WR_O_N				0x0C			/** O  WR_O_N   */
#define IO_T_PT_WR_O_R				0x0D			/** O  WR_O_R   */
#define IO_T_PT_WLRO  				0x0E			/** O  WLRO     */
#define IO_T_PT_AMCRO 				0x17			/** O  AMCRO    */
#define IO_T_PT_BMCRO 				0x18			/** O  BMCRO    */
#define IO_T_PT_CMCRO 				0x19			/** O  CMCRO    */
#define IO_T_PT_DMCRO 				0x1A			/** O  DMCRO    */
/* ---------------------------- */
/* IO GIO Type                  */
/* ---------------------------- */
#define IO_T_GIO_RC					0x01	/** I  �ǳθ� ����               */
#define IO_T_GIO_RC_OUTA			0x02	/** O  �ǳθ� ��� A             */
#define IO_T_GIO_RC_OUTB			0x03	/** O  �ǳθ� ��� B             */
#define IO_T_GIO_RC_OUTC			0x04	/** O  �ǳθ� ��� C             */
#define IO_T_GIO_RC_INA				0x06	/** I  �ǳθ� �Է� A             */
#define IO_T_GIO_RC_INB				0x07	/** I  �ǳθ� �Է� B             */
#define IO_T_GIO_RC_INC				0x08	/** I  �ǳθ� �Է� C             */
#define IO_T_GIO_OB_STATE			0x11	/** I  ���幰������ġ ����       */
#define IO_T_GIO_OB_ACCEPT			0x12	/** I  ���幰������ġ Ȯ������   */

/*#define IO_T_GIO_EXTREC1			0x21*/	/** I  1�� Ȯ�� ������ ����      */
/*#define IO_T_GIO_EXTREC2			0x22*/	/** I  2�� Ȯ�� ������ ����      */
/* [Ȯ��FUSE&REC������] �� ���� �� Ȯ�� ������ ���� 1/2�� �����Ͽ� ������ */
#define IO_T_GIO_EXTREC1			0x20	/** I  1�� IOS 1~8  ������ ����  */
#define IO_T_GIO_EXTREC2			0x21	/** I  1�� IOS 9~16 ������ ����  */
#define IO_T_GIO_EXTREC3			0x22	/** I  2�� IOS 1~8  ������ ����  */
#define IO_T_GIO_EXTREC4			0x23	/** I  2�� IOS 9~16 ������ ����  */
#define IO_T_GIO_EXTREC5			0x24	/** I  Spare                     */

#define IO_T_GIO_IS1_S				0x41	/** I  ��������������ġ 1�� ���� */
#define IO_T_GIO_IS1_O				0x42	/** I  ��������������ġ 1�� ��� */
#define IO_T_GIO_IS2_S				0x44	/** I  ��������������ġ 2�� ���� */
#define IO_T_GIO_IS2_O				0x48	/** I  ��������������ġ 2�� ��� */

/*#define IO_T_GIO_EXTFUSE1			0x51*/	/** I  1�� Ȯ�� FUSE ����        */
/*#define IO_T_GIO_EXTFUSE2			0x52*/	/** I  2�� Ȯ�� FUSE ����        */
/* [Ȯ��FUSE&REC������] �� ���� �� Ȯ�� FUSE ���� 1/2�� �����Ͽ� ������ */
#define IO_T_GIO_EXTFUSE1			0x50	/** I  1�� IOS 1~8  FUSE ����    */
#define IO_T_GIO_EXTFUSE2			0x51	/** I  1�� IOS 9~16 FUSE ����    */
#define IO_T_GIO_EXTFUSE3			0x52	/** I  2�� IOS 1~8  FUSE ����    */
#define IO_T_GIO_EXTFUSE4			0x53	/** I  2�� IOS 9~16 FUSE ����    */
#define IO_T_GIO_EXTFUSE5			0x54	/** I  Spare                     */

#define IO_T_GIO_RTDEST_OUT			0x61	/** O  ���μ��� ���             */
#define IO_T_GIO_RTDEST_IN			0x62	/** I  ���μ��� ����� Feedback  */
#define IO_T_GIO_RTDEST_CFLKI		0x63	/** I  ����������� �Է�         */
#define IO_T_GIO_RTLK_OUT			0x71	/** O  ���μ��� ���             */
#define IO_T_GIO_RTLK_IN			0x72	/** I  ���μ��� ����� Feedback  */
#define IO_T_GIO_RTLK_CFLKI			0x73	/** I  ��� ���μ��� �Է�        */
#define IO_T_GIO_RTSTART_LDIRO		0x81	/** O  �¹��� ���               */
#define IO_T_GIO_RTSTART_LDIRI		0x82	/** I  �¹��� ����� Feedback    */
#define IO_T_GIO_RTSTART_RDIRO		0x83	/** O  ����� ���               */
#define IO_T_GIO_RTSTART_RDIRI		0x84	/** I  ����� ����� Feedback    */
#define IO_T_GIO_RTSTART_CDIRO		0x85	/** O  ������ ���               */
#define IO_T_GIO_RTSTART_CDIRI		0x86	/** I  ������ ����� Feedback    */
#define IO_T_GIO_EX2PHT_N_O			0x91	/** O  Ȯ��2 ������ ���� ���    */
#define IO_T_GIO_EX2PHT_N_I			0x92	/** I  Ȯ��2 ������ ���� �Է�    */
#define IO_T_GIO_EX2PHT_N_S			0x93	/** I  Ȯ��2 ������ ���� ����    */
#define IO_T_GIO_EX2PHT_S_O			0xA1	/** O  Ȯ��2 ������ ���� ���    */
#define IO_T_GIO_EX2PHT_S_I			0xA2	/** I  Ȯ��2 ������ ���� �Է�    */
#define IO_T_GIO_EX2PHT_S_S			0xA3	/** I  Ȯ��2 ������ ���� ����    */
#define IO_T_GIO_EX3PHT_N_O			0xB1	/** O  Ȯ��3 ������ ���� ���    */
#define IO_T_GIO_EX3PHT_N_I			0xB2	/** I  Ȯ��3 ������ ���� �Է�    */
#define IO_T_GIO_EX3PHT_N_S			0xB3	/** I  Ȯ��3 ������ ���� ����    */
#define IO_T_GIO_EX3PHT_S_O			0xC1	/** O  Ȯ��3 ������ ���� ���    */
#define IO_T_GIO_EX3PHT_S_I			0xC2	/** I  Ȯ��3 ������ ���� �Է�    */
#define IO_T_GIO_EX3PHT_S_S			0xC3	/** I  Ȯ��3 ������ ���� ����    */
#define IO_T_GIO_EXGOUT_1			0xD0	/** O  Ȯ�� ��� 1               */
#define IO_T_GIO_EXGOUT_2			0xD1	/** O  Ȯ�� ��� 2               */
#define IO_T_GIO_EXGOUT_3			0xD2	/** O  Ȯ�� ��� 3               */
#define IO_T_GIO_EXGOUT_4			0xD3	/** O  Ȯ�� ��� 4               */
#define IO_T_GIO_EXGOUT_5			0xD4	/** O  Ȯ�� ��� 5               */
#define IO_T_GIO_EXGOUT_6			0xD5	/** O  Ȯ�� ��� 6               */
#define IO_T_GIO_EXGOUT_7			0xD6	/** O  Ȯ�� ��� 7               */
#define IO_T_GIO_EXGOUT_8			0xD7	/** O  Ȯ�� ��� 8               */
#define IO_T_GIO_EXGIN_1			0xD8	/** I  Ȯ�� �Է� 1               */
#define IO_T_GIO_EXGIN_2			0xD9	/** I  Ȯ�� �Է� 2               */
#define IO_T_GIO_EXGIN_3			0xDA	/** I  Ȯ�� �Է� 3               */
#define IO_T_GIO_EXGIN_4			0xDB	/** I  Ȯ�� �Է� 4               */
#define IO_T_GIO_EXGIN_5			0xDC	/** I  Ȯ�� �Է� 5               */
#define IO_T_GIO_EXGIN_6			0xDD	/** I  Ȯ�� �Է� 6               */
#define IO_T_GIO_EXGIN_7			0xDE	/** I  Ȯ�� �Է� 7               */
#define IO_T_GIO_EXGIN_8			0xDF	/** I  Ȯ�� �Է� 8               */

#define IO_T_GIO_ETCIN_1			0xE0	/** I  ��Ÿǥ�ÿ� �Է� 1         */ /*�߰�171227 [GIO��Ÿǥ���߰�]*/
#define IO_T_GIO_ETCIN_2			0xE1	/** I  ��Ÿǥ�ÿ� �Է� 2         */
#define IO_T_GIO_ETCIN_3			0xE2	/** I  ��Ÿǥ�ÿ� �Է� 3         */
#define IO_T_GIO_ETCIN_4			0xE3	/** I  ��Ÿǥ�ÿ� �Է� 4         */
#define IO_T_GIO_ETCIN_5			0xE4	/** I  ��Ÿǥ�ÿ� �Է� 5         */
#define IO_T_GIO_ETCIN_6			0xE5	/** I  ��Ÿǥ�ÿ� �Է� 6         */
#define IO_T_GIO_ETCIN_7			0xE6	/** I  ��Ÿǥ�ÿ� �Է� 7         */
#define IO_T_GIO_ETCIN_8			0xE7	/** I  ��Ÿǥ�ÿ� �Է� 8         */

/*#define IO_T_GIO_ATSFAIL_Y			0xEE	  * I  ATS Y ����                   //�߰�171220 [ATS�����߰�] GIO Type = GIO_TYPE_ATS_FAIL*/
/*#define IO_T_GIO_ATSFAIL_G			0xEF	  * I  ATS G ����                   //�߰�171220 [ATS�����߰�] GIO Type = GIO_TYPE_ATS_FAIL*/

#define IO_T_GIO_EXC_INOUT_I1		0xF0	/** I  �Ϲ������ �Է� 1         */
#define IO_T_GIO_EXC_INOUT_I2		0xF1	/** I  �Ϲ������ �Է� 2         */
#define IO_T_GIO_EXC_INOUT_I3		0xF2	/** I  �Ϲ������ �Է� 3         */
#define IO_T_GIO_EXC_INOUT_I4		0xF3	/** I  �Ϲ������ �Է� 4         */
#define IO_T_GIO_EXC_INOUT_I5		0xF4	/** I  �Ϲ������ �Է� 5         */
#define IO_T_GIO_EXC_INOUT_I6		0xF5	/** I  �Ϲ������ �Է� 6         */
#define IO_T_GIO_EXC_INOUT_O1		0xF6	/** O  �Ϲ������ ��� 1         */
#define IO_T_GIO_EXC_INOUT_O2		0xF7	/** O  �Ϲ������ ��� 2         */
#define IO_T_GIO_DRAG_NORNAL		0xF8	/** I  ����������ġ   ����       */ /*�߰�170831*/
#define IO_T_GIO_DRAG_SWITCH		0xF9	/** I  ����������ġ Ȯ������     */

/* ------------------------------------------------------------------------- */
/* General IO Type Define                                                    */
/* ------------------------------------------------------------------------- */
#define GIO_TYPE_RC			((uint8)0x01)	/* �ǳθ�                        */
#define GIO_TYPE_OB			((uint8)0x02)	/* ���幰 ������ġ               */
#define GIO_TYPE_REC		((uint8)0x03)	/* Ȯ�� ������                   */
#define GIO_TYPE_IS			((uint8)0x04)	/* ��������������ġ              */
#define GIO_TYPE_FUSE		((uint8)0x05)	/* Ȯ�� FUSE                     */
#define GIO_TYPE_RTDEST		((uint8)0x06)	/* ���μ���(����������)          */
#define GIO_TYPE_RTLOCK		((uint8)0x07)	/* ���μ��� ��/���(���α���)    */
#define GIO_TYPE_RTSTART	((uint8)0x08)	/* ���μ���(�ù�������)          */
#define GIO_TYPE_PHEAT_N2	((uint8)0x09)	/* ������ȯ�� ������2 ���� Ȯ��  */
#define GIO_TYPE_PHEAT_S2	((uint8)0x0A)	/* ������ȯ�� ������2 ���� Ȯ��  */
#define GIO_TYPE_PHEAT_N3	((uint8)0x0B)	/* ������ȯ�� ������3 ���� Ȯ��  */
#define GIO_TYPE_PHEAT_S3	((uint8)0x0C)	/* ������ȯ�� ������3 ���� Ȯ��  */
#define GIO_TYPE_GOUT		((uint8)0x0D)	/* Ȯ�� ���                     */
#define GIO_TYPE_GIN		((uint8)0x0E)	/* Ȯ�� �Է�                     */
#define GIO_TYPE_EXC_INOUT	((uint8)0x0F)	/* ���� �����                   */
#define GIO_TYPE_DRAG		((uint8)0x10)	/* ���� ���� ��ġ                */ /*�߰�170831*/
#define GIO_TYPE_ETC		((uint8)0x11)	/* ��Ÿǥ�ÿ�                    */ /*�߰�171227 [GIO��Ÿǥ���߰�]*/
/*#define GIO_TYPE_ATS_FAIL	((uint8)0x11)	   ATS ��������                     //�߰�171220 [ATS�����߰�]*/
/* ------------------------------------------------------------------------- */
/* GIO Default Index                                                         */
/* ------------------------------------------------------------------------- */
#define GIO_EX_REC2					1
#define GIO_EX_REC3					2
#define GIO_EX_REC4					3
#define GIO_EX_REC5					4
#define GIO_EX_REC6					5
#define GIO_EX_FUSE2				6
#define GIO_EX_FUSE3				7
#define GIO_EX_FUSE4				8
#define GIO_EX_FUSE5				9
#define GIO_EX_FUSE6				10

/* ========================================================================= */
/* GIO Type�� bit State Define (SMEM���� Bit ��ġ)                           */
/* ========================================================================= */
/* GIO_TYPE_RC	(uint8)0x01	�ǳθ�                                           */
/* ------------------------------------------------------------------------- */
#define GIOBIT_RC_S					0x01	/** I  �ǳθ� ����               */ 
#define GIOBIT_RC_OUTA				0x80    /** O  �ǳθ� ��� A             */
#define GIOBIT_RC_OUTB				0x40    /** O  �ǳθ� ��� B             */
#define GIOBIT_RC_OUTC				0x20    /** O  �ǳθ� ��� C             */
#define GIOBIT_RC_INA				0x08    /** I  �ǳθ� �Է� A             */
#define GIOBIT_RC_INB				0x04    /** I  �ǳθ� �Է� B             */
#define GIOBIT_RC_INC				0x02    /** I  �ǳθ� �Է� C             */

#define GIOBIT_LOGIC_RESULT			0x80	/** Logic ���� ��� bit          */
/* ------------------------------------------------------------------------- */
/* GIO_TYPE_OB	(BYTE)0x02	���幰������ġ                                   */
/* ------------------------------------------------------------------------- */
#define GIOBIT_OB_GOOD				0x01	/** I  ���幰������ġ ����       */
#define GIOBIT_OB_ACPT				0x02    /** I  ���幰������ġ Ȯ������   */
/* ------------------------------------------------------------------------- */
/* GIO_TYPE_REC	(BYTE)0x03	Ȯ�� ������ (GIO idx 1~5 ����)                   */
/* ------------------------------------------------------------------------- */
/*#define GIOBIT_REC_1				0x01*/    /** I  1�� Ȯ�� ������ ����      */
/*#define GIOBIT_REC_2				0x02*/    /** I  2�� Ȯ�� ������ ����      */

/* [Ȯ��FUSE&REC������] ���� ���� ���Ǵ� ������ GIO idx1�� Rack2 idx5�� Rack6�̿����� 
   ZEST Ȯ�巢�� �ִ� 15���̹Ƿ� �̸� ������ ���� ������ */

/* GIO idx 1, 2�� ZEST EI 1���� Ȯ�� ������ ������ ���
   GIO idx 3, 4�� ZEST EI 2���� Ȯ�� ������ ������ ���,
   GIO idx 5�� Spare 
   �� 16bit�� 1/2�� �������� ������ ���� �����Ͽ� �����. */
/* GIO idx 1(1��), 3(2��)�� Bit ���� : Rack 1~8 ���� ��� */
/* GIO idx 2(1��), 4(2��)�� Bit ���� : Rack 9~16 ���� ��� */
#define GIOBIT_REC_1			0x01    /** I 1/2�� 1 or 9  rack ������ ���� */
#define GIOBIT_REC_2			0x02    /** I 1/2�� 2 or 10 rack ������ ���� */
#define GIOBIT_REC_3			0x04    /** I 1/2�� 3 or 11 rack ������ ���� */
#define GIOBIT_REC_4			0x08    /** I 1/2�� 4 or 12 rack ������ ���� */
#define GIOBIT_REC_5			0x10    /** I 1/2�� 5 or 13 rack ������ ���� */
#define GIOBIT_REC_6			0x20    /** I 1/2�� 6 or 14 rack ������ ���� */
#define GIOBIT_REC_7			0x40    /** I 1/2�� 7 or 15 rack ������ ���� */
#define GIOBIT_REC_8			0x80    /** I 1/2�� 8 or 16 rack ������ ���� */

/* ------------------------------------------------------------------------- */
/* GIO_TYPE_IS	(BYTE)0x04	��������������ġ                                 */
/* ------------------------------------------------------------------------- */
#define GIOBIT_IS1_GOOD				0x01U	/** I  ��������������ġ 1�� ���� */
#define GIOBIT_IS1_OP				0x02U   /** I  ��������������ġ 1�� ��� */
#define GIOBIT_IS2_GOOD				0x04U   /** I  ��������������ġ 2�� ���� */
#define GIOBIT_IS2_OP				0x08U   /** I  ��������������ġ 2�� ��� */
/* ------------------------------------------------------------------------- */
/* GIO_TYPE_FUSE	(BYTE)0x05	Ȯ�� FUSE (GIO idx 6~10 ����)                */
/* ------------------------------------------------------------------------- */
/*#define GIOBIT_FUSE_1				0x01U*/ /** I  1�� Ȯ�� FUSE ����        */
/*#define GIOBIT_FUSE_2				0x02U*/ /** I  2�� Ȯ�� FUSE ����        */

/* [Ȯ��FUSE&REC������] ���� ���� ���Ǵ� ������ GIO idx6�� Rack2 idx10�� Rack6�̿�����
   ZEST Ȯ�巢�� �ִ� 15���̹Ƿ� �̸� ������ ���� ������ */

/* GIO idx 6, 7�� ZEST EI 1���� Ȯ�� FUSE ������ ���
   GIO idx 8, 9�� ZEST EI 2���� Ȯ�� FUSE ������ ���,
   GIO idx 10�� Spare 
   �� 16bit�� 1/2�� �������� ������ ���� �����Ͽ� �����. */
/* GIO idx 6(1��), 8(2��)�� Bit ���� : Rack 1~8 ���� ��� */
/* GIO idx 7(1��), 9(2��)�� Bit ���� : Rack 9~16 ���� ��� */
#define GIOBIT_FUSE_1			0x01    /** I 1/2�� 1 or 9  rack FUSE ����   */
#define GIOBIT_FUSE_2			0x02    /** I 1/2�� 2 or 10 rack FUSE ����   */
#define GIOBIT_FUSE_3			0x04    /** I 1/2�� 3 or 11 rack FUSE ����   */
#define GIOBIT_FUSE_4			0x08    /** I 1/2�� 4 or 12 rack FUSE ����   */
#define GIOBIT_FUSE_5			0x10    /** I 1/2�� 5 or 13 rack FUSE ����   */
#define GIOBIT_FUSE_6			0x20    /** I 1/2�� 6 or 14 rack FUSE ����   */
#define GIOBIT_FUSE_7			0x40    /** I 1/2�� 7 or 15 rack FUSE ����   */
#define GIOBIT_FUSE_8			0x80    /** I 1/2�� 8 or 16 rack FUSE ����   */
/* ------------------------------------------------------------------------- */
/* GIO_TYPE_RTDEST	(BYTE)0x06	���μ���                                     */
/* ------------------------------------------------------------------------- */
#define GIOBIT_RTD_OUT				0x01U	/** O  ���μ��� ���             */
#define GIOBIT_RTD_IN				0x02U	/** I  ���μ��� ����� Feedback  */
#define GIOBIT_RTD_CFLKI			0x04U	/** I  ����������� �Է�         */
/* ------------------------------------------------------------------------- */
/* GIO_TYPE_RTLOCK	(BYTE)0x07	���μ��� ��/���(���α���)                   */
/* ------------------------------------------------------------------------- */
#define GIOBIT_RTLK_OUT				0x01U	/** O  ���μ��� ���             */
#define GIOBIT_RTLK_IN				0x02U	/** I  ���μ��� ����� Feedback  */
#define GIOBIT_RTLK_CFLKI			0x04U	/** I  ��� ���μ��� �Է�        */
/* ------------------------------------------------------------------------- */
/* GIO_TYPE_RTSTART	(BYTE)0x08	���μ���(�ù�������)                         */
/* ------------------------------------------------------------------------- */
#define GIOBIT_RTS_LDIRO			0x01U	/** O  �¹��� ���               */
#define GIOBIT_RTS_LDIRI			0x02U	/** I  �¹��� ����� Feedback    */
#define GIOBIT_RTS_RDIRO			0x04U	/** O  ����� ���               */
#define GIOBIT_RTS_RDIRI			0x08U	/** I  ����� ����� Feedback    */
#define GIOBIT_RTS_CDIRO			0x10U	/** O  ������ ���               */
#define GIOBIT_RTS_CDIRI			0x20U	/** I  ������ ����� Feedback    */
/* ------------------------------------------------------------------------- */
/* GIO_TYPE_PHEAT2/3(BYTE)0x09/0x0A/0x0B/0x0C  ����2,3 ���� �� ǥ�� Ȯ��     */
/* ------------------------------------------------------------------------- */
#define GIOBIT_EXPHT_O				0x01U	/** O  Ȯ�� ���� ���� ���       */
#define GIOBIT_EXPHT_I				0x02U	/** I  Ȯ�� ���� ���� �Է�       */
#define GIOBIT_EXPHT_S				0x04U	/** I  Ȯ�� ���� ���� ����       */

/* ------------------------------------------------------------------------- */
/* GIO_TYPE_EXINOUT (BYTE)0x0F �������� ��/��� ó��                         */
/* ------------------------------------------------------------------------- */
#define GIOBIT_EXC_INOUT_I1			0x01U	/** I  �Ϲ������ �Է� 1         */
#define GIOBIT_EXC_INOUT_I2			0x02U	/** I  �Ϲ������ �Է� 2         */
#define GIOBIT_EXC_INOUT_I3			0x04U	/** I  �Ϲ������ �Է� 3         */
#define GIOBIT_EXC_INOUT_I4			0x08U	/** I  �Ϲ������ �Է� 4         */
#define GIOBIT_EXC_INOUT_I5			0x10U	/** I  �Ϲ������ �Է� 5         */
#define GIOBIT_EXC_INOUT_I6			0x20U	/** I  �Ϲ������ �Է� 6         */
#define GIOBIT_EXC_INOUT_O1			0x40U	/** O  �Ϲ������ ��� 1         */
#define GIOBIT_EXC_INOUT_O2			0x80U	/** O  �Ϲ������ ��� 2         */
/* ------------------------------------------------------------------------- */
/* GIO_TYPE_DRAG	(BYTE)0x10	����������ġ                                 */ /*�߰�170831*/
/* ------------------------------------------------------------------------- */
#define GIOBIT_DRAG_NORMAL			0x01	/** I  ����������ġ ����(1)/�溸 */
#define GIOBIT_DRAG_SWITCH			0x02    /** I  ����������ġ Ȯ��         */
/* ------------------------------------------------------------------------- */
/* GIO_TYPE_ETC (BYTE)0x11	GIO ��Ÿǥ�ÿ�                                   */ /*�߰�171227 [GIO��Ÿǥ���߰�]*/
/* ------------------------------------------------------------------------- */
#define GIOBIT_ETC_BIT1				0x01    /** I  ��Ÿǥ�ÿ� 1              */
#define GIOBIT_ETC_BIT2				0x02    /** I  ��Ÿǥ�ÿ� 2              */
#define GIOBIT_ETC_BIT3				0x04    /** I  ��Ÿǥ�ÿ� 3              */
#define GIOBIT_ETC_BIT4				0x08    /** I  ��Ÿǥ�ÿ� 4              */
#define GIOBIT_ETC_BIT5				0x10    /** I  ��Ÿǥ�ÿ� 5              */
#define GIOBIT_ETC_BIT6				0x20    /** I  ��Ÿǥ�ÿ� 6              */
#define GIOBIT_ETC_BIT7				0x40    /** I  ��Ÿǥ�ÿ� 7              */
#define GIOBIT_ETC_BIT8				0x80    /** I  ��Ÿǥ�ÿ� 8              */
/* ------------------------------------------------------------------------- */
/* GIO_TYPE_ATS_FAIL (BYTE)0x11	ATS ��������                                 */
/* ------------------------------------------------------------------------- */
/*#define GIOBIT_ATS_YFAILL			0x01	  * I  ATS Y ����                   // �߰�171220[ATS�����߰�]*/
/*#define GIOBIT_ATS_GFAILL			0x02      * I  ATS G ����                   // �߰�171220[ATS�����߰�]*/

/* ------------------------------------------------------------------------- */
/* ������ȯ�� ���� Ÿ�̸� ����                                               */
/* ------------------------------------------------------------------------- */
#define POINT_TIMER_SET			((uint8)0x80U)
#define POINT_TIMER_BIT_MASK	((uint8)0x3FU)

#define POINT_ILLEGAL_FAIL_SET	((uint8)0x40U)
#define POINT_ILLEGAL_BIT_MASK	((uint8)0x3FU)

#define POINT_ILLEGAL_DELAY		(1800U/MAX_TICK_ILT)/** ��¿� ���� �Է� Count*/

#define SG_ATSRI_FAIL_DLY		(600U/MAX_TICK_ILT)
/* ------------------------------------------------------------------------- */
/* ��ȣ���ϰ� ���� ����                                                      */
/* ------------------------------------------------------------------------- */
#define ALL_SIGNAL_STOP_SET					0x10
#define ALL_SIGNAL_STOP_BLOCKING			0x08
#define ALL_SIGNAL_STOP_TIMER				10
/* ------------------------------------------------------------------------- */
/* Object ���� Define (Signal)                                               */
/* ------------------------------------------------------------------------- */
#define OBJ_SIGNAL_REALOUT_BITMASK			0x0F
#define OBJ_SIGNAL_REALIN_BITMASK			0xF0
#define OBJ_SIGNAL_BUFFOUT_BITMASK			0x0F
#define OBJ_SIGNAL_TMCLEAR_BITMASK			0xFC

#define OBJ_SIGNAL_YRO						0x01
#define OBJ_SIGNAL_GRO						0x02
#define OBJ_SIGNAL_HRO						0x04
#define OBJ_SIGNAL_OUTMAIN_BITMASK			0x07

#define OBJ_SIGNAL_BUFF_YRO					0x01
#define OBJ_SIGNAL_BUFF_GRO					0x02
#define OBJ_SIGNAL_BUFF_HRO					0x04
#define OBJ_SIGNAL_OUTBUFFMAIN_BITMASK		0x07

#define OBJ_SIGNAL_MAINLMR_BITMASK			0x55
#define OBJ_SIGNAL_AUXLMR_BITMASK			0xAA
#define OBJ_SIGNAL_MLMR_Y					0x01
#define OBJ_SIGNAL_ALMR_Y					0x02
#define OBJ_SIGNAL_MLMR_R					0x04
#define OBJ_SIGNAL_ALMR_R					0x08
#define OBJ_SIGNAL_MLMR_G					0x10
#define OBJ_SIGNAL_ALMR_G					0x20
#define OBJ_SIGNAL_MLMR_YY					0x40
#define OBJ_SIGNAL_ALMR_YY					0x80
/* ------------------------------------------------------------------------- */
/* Object �� Size                                                            */
/* ------------------------------------------------------------------------- */
#define SIZE_SIGNAL_OBJECT					5
#define SIZE_POINT_OBJECT					2
#define SIZE_TRACK_OBJECT					2
/* ------------------------------------------------------------------------- */
/* ������ȣ ���� Define                                                      */
/* ------------------------------------------------------------------------- */
#define TRAINNO_SIZE						5U
#define MAX_TRAINNO 						50U
#define MAX_CTC_COMMAND_SIZE				26
#define USED_SECOND_WINDOW					((uint8)0x80)
#define FIRST_WIN							1
#define SECOND_WIN							2

/* [CTC�˵������߰�] */
#define TRACK_BLOCKING_1					0x02	/** �˵�������� 1       */
#define TRACK_BLOCKING_2					0x20	/** �˵�������� 2       */
#define TRACK_LABEL1_MASK					0x0F
#define TRACK_LABEL2_MASK					0xF0
/* ------------------------------------------------------------------------- */
/* CTC Element ���� Define                                                   */
/* ------------------------------------------------------------------------- */
#define MAX_SUMMARYTC_TBL					10
#define MAX_SUMMARY_TC						10
#define MAX_CTC_ELEMENT						(uint16)(2048U)

#define CTC_SENDER_ID						0xA5	/** CTC��ɾ� ����(���ο�) */

#define CTCELM_T_MODE						0x01
#define CTCELM_T_POWER						0x02
#define CTCELM_T_EIS						0x03
#define CTCELM_T_POINT						0x04
#define CTCELM_T_SIGNAL						0x05
#define CTCELM_T_ROUTE						0x06
#define CTCELM_T_TRACK						0x07
#define CTCELM_T_TW							0x08
#define CTCELM_T_LC							0x09
#define CTCELM_T_DIR						0x0A
#define CTCELM_T_DIRUP						0x1A
#define CTCELM_T_DIRDN						0x2A
#define CTCELM_T_COMMON						0x0B
#define CTCELM_T_OBS						0x0C
#define CTCELM_T_ALLSGSTOP					0x0D
#define CTCELM_T_DRAG						0x31	/** ����������ġ         */ /*�߰�170831*/
#define CTCELM_T_ATS						0x32	/** ATS ���� ����        */ /* 171227 [ATS�����߰�] */

#define RCELM_T_DOOR						0x0E	/** RC�� ���Թ�          */
#define RCELM_T_EQ							0x0F	/** RC�� ��������        */
#define RCELM_T_PHETS						0x10	/** RC�� ������          */
#define RCELM_T_PHETN						0x20	/** RC�� ������          */
#define RCELM_T_IS_SYS1						0x33    /** RC�� ����������ġ�������� 1�� STATE */ /* �߰� 190916 */
#define RCELM_T_IS_SYS2						0x34    /** RC�� ����������ġ�������� 2�� STATE */ /* �߰� 190916 */
#define RCELM_T_IS_ACTIVE					0x35    /** RC�� ����������ġ�������� ONLINE STATE */ /* �߰� 190916 */
/* ========================================================================= */
/* CTC Element �� Display Bit State Define                                   */
/* ========================================================================= */
#define MAX_CTCELM_STATE_BUFF				13 /** CTC ��ȭ���� ���� ���� �� */
#define MAX_CTCELM_BASESCAN_BUFF			5  /** CTC Basescan �ִ�ġ       */
#define CTCELM_DSP_MODE_NONE_MODE         0x00
/* ------------------------------------------------------------------------- */
/* CTC ���� ǥ�� ���� Bit Position                                       */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_MODE_LOC               0x01U    /* 1:Local Mode           */
#define CTCELM_DSP_MODE_MR                0x02U    /* 1:CTC������ȯ��û��  */
#define CTCELM_DSP_MODE_REM               0x04U    /* 1:CTC Mode             */
#define CTCELM_DSP_MODE_ML                0x08U    /* 1:Local������ȯ��û��*/
/* ------------------------------------------------------------------------- */
/* CTC ������ġ ǥ�� ���� Bit Position                                       */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_PW_N1                0x01U    /* 1:Power on N1            */
#define CTCELM_DSP_PW_N2                0x02U    /* 1:Power on N2            */
#define CTCELM_DSP_PW_REC               0x04U    /* 1:DC 24V ����, 0:����    */
#define CTCELM_DSP_PW_UPS               0x08U    /* 1:UPS ����, 0:����       */
#define CTCELM_DSP_PW_C                 0x10U    /* 1:����                   */
#define CTCELM_DSP_PW_D                 0x20U    /* 1:����                   */
#define CTCELM_DSP_PW_SHSGOFF           0x80U    /* 1:��ȯ�ҵ�, 0:On         */

#define CTCELM_DSP_JK_PW_REC            0x01U    /* 1:REC  ����, 0:����      */
#define CTCELM_DSP_JK_PW_FUSE           0x02U    /* 1:FUSE ����, 0:����      */
/* ------------------------------------------------------------------------- */
/* CTC EIS ����ǥ��  Bit Position                                            */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_EIDEV1            0x01U    /* EIS 1�� ����:1 ����:0       */
#define CTCELM_DSP_EION1             0x02U    /* EIS 1�� Online:1 Stndby:0   */
#define CTCELM_DSP_EISRUN1           0x04U    /* EIS 1�� RUN:1               */ /*170906 [CTC�ý���RUN�߰�] �߰�*/
#define CTCELM_DSP_EISPARE4          0x08U
#define CTCELM_DSP_EISPARE5          0x10U
#define CTCELM_DSP_EISRUN2           0x20U    /* EIS 2�� RUN:1               */ /*170906 [CTC�ý���RUN�߰�] �߰�*/
#define CTCELM_DSP_EIDEV2            0x40U    /* EIS 2�� ����:1 ����:0       */
#define CTCELM_DSP_EION2             0x80U    /* EIS 2�� Online:1 Stndby:0   */
/* ------------------------------------------------------------------------- */
/* CTC ������ȯ�� ǥ�� ���� Bit Position                                     */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_PT_NP             0x01U    /* 1:��������, 0:�ٸ�����      */
#define CTCELM_DSP_PT_RP             0x02U    /* 1:��������, 0:�ٸ�����      */
#define CTCELM_DSP_PT_LK             0x04U    /* 1:��������, 0:��������      */
#define CTCELM_DSP_PT_PF             0x08U    /* 1:�������, 0:�������      */
#define CTCELM_DSP_PT_MVN            0x10U    /* 1:������ ������, 0:�ٸ����� */
#define CTCELM_DSP_PT_MVR            0x20U    /* 1:������ ������, 0:�ٸ����� */
#define CTCELM_DSP_PT_CB             0x80U    /* 1:CallBack, 0:N/A           */ /* [CallBack����] */
/* ------------------------------------------------------------------------- */
/* CTC ���, �峻��ȣ�� ǥ�� ���� Bit Position                               */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_SG_GO             0x01U  /* 1:��������, 0:��������        */
#define CTCELM_DSP_SG_SF             0x02U  /* 1:����, 0:����                */
#define CTCELM_DSP_SG_RI             0x04U  /* 1:����ǥ�ñ�On,0:����ǥ�ñ�off*/
#define CTCELM_DSP_SG_TTB            0x08U  /* 1:TTB On, 0:TTB Off           */
#define CTCELM_DSP_SG_AL             0x10U  /* 1:���ټ���, 0:��������        */
#define CTCELM_DSP_SG_CG             0x20U  /* 1:������ȣ��On,0:������ȣ��Off*/
#define CTCELM_DSP_SG_LK             0x40U  /* 1:��ȣ�����, 0:Off           */
/* ------------------------------------------------------------------------- */
/* CTC ���, �峻��ȣ�� ǥ�� ���� Bit Position (Jakarta)                     */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_JK_SG_G           0x01U  /* 1:G����, 0:����               */
#define CTCELM_DSP_JK_SG_Y           0x02U  /* 1:Y����, 0:����               */
#define CTCELM_DSP_JK_SG_RI_F        0x04U  /* 1:����ǥ�ñ����,0:����       */
#define CTCELM_DSP_JK_SG_TTB         0x08U  /* 1:TTB On, 0:TTB Off           */
#define CTCELM_DSP_JK_SG_AL          0x10U  /* 1:���ټ���, 0:��������        */
#define CTCELM_DSP_JK_SG_CG          0x20U  /* 1:������ȣ��On,0:������ȣ��Off*/
#define CTCELM_DSP_JK_SG_SF          0x40U  /* 1:����,  0:����               */
#define CTCELM_DSP_JK_SG_LK          0x80U  /* 1:����,  0:����               */
/* ------------------------------------------------------------------------- */
/* CTC ��ȯ��ȣ��, ��ȯǥ�� ǥ�� ���� Bit Position                           */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_SHSG_GO           0x01U  /* 1:��������, 0:��������        */
#define CTCELM_DSP_SHSG_SSF          0x02U  /* 1:����, 0:����                */
#define CTCELM_DSP_SHSG_SAL          0x10U  /* 1:����/��������On 0:Off       */
#define CTCELM_DSP_SHSG_NCS          0x20U  /* 1:������ ǥ�� On 0:Off        */
#define CTCELM_DSP_SHSG_LK           0x40U  /* 1:��ȣ�����, 0:Off           */
/* ------------------------------------------------------------------------- */
/* CTC ���� ǥ�� ���� Bit Position                                           */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_RT_LK             0x80U    /* 1:���μ��� 0:��������       */
/* ------------------------------------------------------------------------- */
/* CTC �˵�ȸ�� ǥ�� ���� Bit Position                                       */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_TC_OCC            0x01U    /* 1:������, 0:����            */
#define CTCELM_DSP_TC_SGGO	         0x02U    /* 1:��ȣ����, 0:��ȣ����      */ /* [CTC�˵������߰�] */
#define CTCELM_DSP_TC_EGSET	         0x04U    /* 1:�����������, 0:�Ұ���    */ /* [CTC�˵������߰�] */
#define CTCELM_DSP_TC_BLK	         0x08U    /* 1:����, 0:����              */ /* [CTC�˵������߰�] */
#define CTCELM_DSP_TC_RTLOCK         0x10U    /* 1:��������, 0:���μ���      */ /* [CTC�˵������߰�] */
#define CTCELM_DSP_TC_FAIL			 0x20U    /* 1:�˵����, 0:����          */ /* [CTC�˵�����߰�]  */
/* ------------------------------------------------------------------------- */
/* CTC ���������ȣ�� ǥ�� ���� Bit Position                                 */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_ABSG_HBG     0x01U    /* 1:��������, 0:��������           */
#define CTCELM_DSP_ABSG_HBF     0x02U    /* 1:����, 0:����                   */
/* ------------------------------------------------------------------------- */
/* CTC �����ȣ�� ǥ�� ���� Bit Position                                     */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_BSG_BSF      0x01U    /* 1:����, 0:����                   */
#define CTCELM_DSP_BSG_GO       0x02U    /* 1:����, 0:����                   */
/* ------------------------------------------------------------------------- */
/* CTC �ǳθ� ǥ�� ���� Bit Position                                         */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_RC           0x01U    /* 1:����, 0:����                   */
/* ------------------------------------------------------------------------- */
/* CTC ��������� ǥ�� ���� Bit Position                                     */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_DIR_DYF      0x01U    /* ��� Ȳ���� ���� SET:1           */
#define CTCELM_DSP_DIR_DY       0x02U    /* ��� Ȳ���� ���� SET:1           */
#define CTCELM_DSP_DIR_DR       0x04U    /* ��� ������ ���� SET:1           */
#define CTCELM_DSP_DIR_DRF      0x08U    /* ��� ������ ���� SET:1           */
/* ------------------------------------------------------------------------- */
/* CTC �� ���� ���� ǥ�� ����                                                */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_SCO_P        0x01U    /* ������ȯ�� ���� ���� (����:1)    */
#define CTCELM_DSP_SCO_S        0x02U    /* ��ȣ�� ���� ���� (����:1)        */
#define CTCELM_DSP_SCO_TE       0x04U    /* ��ȣ�� ���� �ü� (����:1)        */
#define CTCELM_DSP_SCO_BS       0x08U    /* �����ȣ�� ���� ���� (����:1)    */
/* ------------------------------------------------------------------------- */
/* CTC ���幰 ���� ��ġ  ǥ�� ����                                           */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_OBSFAIL		0x01U	/* ���幰������ġ ����  1:���� 0:����*/
#define CTCELM_DSP_OBSOPER		0x02U	/* Ȯ������  1:���� 0:����           */
/* ------------------------------------------------------------------------- */
/* CTC ��ȣ�� �ϰ����� ǥ�� ����                                             */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_ALLSGSTOP	0x01U	/* ��ȣ�� �ϰ����� 1:���� 0:����     */
/* ------------------------------------------------------------------------- */
/* CTC ����������ġ ǥ�� ����                                                */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_DRAGFAIL		0x01U	/* ����������ġ ����  1:���� 0:����  */
#define CTCELM_DSP_DRAGOPER		0x02U	/* Ȯ������  1:���� 0:����           */
/* ------------------------------------------------------------------------- */
/* CTC ATS ���� ����                                                         */
/* ------------------------------------------------------------------------- */
#define CTCELM_ATS_GFAIL		0x01U	/* 1:���� 0:����  */ /* 171227 [ATS�����߰�] */
#define CTCELM_ATS_YFAIL		0x02U	/* 1:���� 0:����  */ /* 171227 [ATS�����߰�] */

/* ========================================================================= */
/* CTC Element �� Control Bit State Define                                   */
/* ========================================================================= */
/* ------------------------------------------------------------------------- */
/* CTC ���� �ڵ�                                                             */
/* ------------------------------------------------------------------------- */
#define CTCELM_CTRL_MODE		((uint8)0x01U)
#define CTCELM_CTRL_POINT		((uint8)0x02U)
#define CTCELM_CTRL_ROUTE		((uint8)0x03U)
#define CTCELM_CTRL_SHRUT		((uint8)0x04U)
#define CTCELM_CTRL_DIR			((uint8)0x05U)
#define CTCELM_CTRL_RUN			((uint8)0x06U) /* [CTC�ý���RUN�߰�] */
#define CTCELM_CTRL_TRACK		((uint8)0x07U) /* [CTC�˵������߰�] */
/* ------------------------------------------------------------------------- */
/* CTC �ý��� RUN ���� Bit                                                   */ /* [CTC�ý���RUN�߰�] */
/* ------------------------------------------------------------------------- */
#define CTCELM_CTRL_EI_RUN1		((uint8)0x01U)
#define CTCELM_CTRL_EI_RUN2		((uint8)0x02U)
/* ------------------------------------------------------------------------- */
/* CTC ������ ��ȯ ���� Bit                                                */
/* ------------------------------------------------------------------------- */
#define CTCELM_CTRL_MD_LOCREQ	((uint8)0x01U)
#define CTCELM_CTRL_MD_EMGCTC	((uint8)0x02U)
#define CTCELM_CTRL_MD_CTCACPT	((uint8)0x80U)
/* ------------------------------------------------------------------------- */
/* CTC ������ȯ�� ��ȯ ���� Bit                                              */
/* ------------------------------------------------------------------------- */
#define CTCELM_CTRL_PT_MVN		((uint8)0x01U)
#define CTCELM_CTRL_PT_MVR		((uint8)0x02U)
/* ------------------------------------------------------------------------- */
/* CTC ���� ���� ���� Bit                                                    */
/* ------------------------------------------------------------------------- */
#define CTCELM_CTRL_RT_SET		((uint8)0x01U)
#define CTCELM_CTRL_RT_CAN		((uint8)0x02U)
#define CTCELM_CTRL_RT_TTB		((uint8)0x04U)
#define CTCELM_CTRL_RT_TTCB		((uint8)0x08U)
#define CTCELM_CTRL_RT_STOP		((uint8)0x10U)
#define CTCELM_CTRL_RT_RSET		((uint8)0x20U)
/* ------------------------------------------------------------------------- */
/* CTC �˵� ���� ���� Bit                                                    */ /* [CTC�˵������߰�] */
/* ------------------------------------------------------------------------- */
#define CTCELM_CTRL_TC_EG			((uint8)0x01U)	/** �˵� �������� ����   */
#define CTCELM_CTRL_TC_BLK_SET		((uint8)0x02U)	/** �˵� Blocking ����   */
#define CTCELM_CTRL_TC_BLK_RESET	((uint8)0x04U)	/** �˵� Blocking ����   */
#define CTCELM_CTRL_TC_RESET		((uint8)0x08U)	/** �˵�(AXC) Reset      */ /* [CTC�˵�Reset�߰�] */
/* ------------------------------------------------------------------------- */
/* CTC ��� ���� ���� Bit                                                    */
/* ------------------------------------------------------------------------- */
#define CTCELM_CTRL_DIR_CAN		((uint8)0x01U)		/** ��� ���            */
#define CTCELM_CTRL_DIR_ENT		((uint8)0x02U)		/** ��� �峻            */
#define CTCELM_CTRL_DIR_ACPT	((uint8)0x04U)		/** ��� ����            */
#define CTCELM_CTRL_DIR_EXIT	((uint8)0x08U)		/** ��� ���            */


/* ========================================================================= */
/* RC Element �� Display Bit State Define                                    */
/* ========================================================================= */
#define RCELM_TWC_CODE			((uint8)0x90U)
#define RCELM_TW1_CODE			((uint8)0x91U)
#define RCELM_TW2_CODE			((uint8)0x92U)
#define RCELM_TW3_CODE			((uint8)0x93U)
#define RCELM_TWE_CODE			((uint8)0x9EU)
/* ------------------------------------------------------------------------- */
/* RC  ���� ǥ�� ���� Bit Position                                       */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_MODE_LOC               0x01U    /* 1:Local Mode            */
#define RCELM_DSP_MODE_MR                0x02U    /* 1:CTC������ȯ��û��   */
#define RCELM_DSP_MODE_REM               0x04U    /* 1:CTC Mode              */
#define RCELM_DSP_MODE_ML                0x08U    /* 1:Local������ȯ��û�� */
#define RCELM_DSP_MODE_RC                0x10U    /* 1:RC  Mode              */
#define RCELM_DSP_MODE_MRC               0x20U    /* 1:RC������ȯ��û��    */
/* ------------------------------------------------------------------------- */
/* RC  ������ġ ǥ�� ���� Bit Position                                       */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_PW_N1     		0x01U	/* bit0 | 1:N1 ���              */
#define RCELM_DSP_PW_N2     		0x02U	/* bit1 | 1:N2 ���              */
#define RCELM_DSP_PW_REC    		0x04U	/* bit2 | 1:������ / 0:����      */
#define RCELM_DSP_PW_UPS    		0x08U	/* bit3 | 1:UPS ���� / 0:UPS ����*/
#define RCELM_DSP_PW_C      		0x10U	/* bit4 | 1:���� / 0:����        */
#define RCELM_DSP_PW_PS      		0x20U	/* bit5 | 1:P�� ���� / 0:����    */
#define RCELM_DSP_PW_PN     		0x40U	/* bit6 | 1:P�� ���� / 0:����    */
#define RCELM_DSP_PW_FUSE			0x80U	/* bit7 | 1:Fuse / 0:����        */
/* ------------------------------------------------------------------------- */
/* RC  EIS ����ǥ��  Bit Position                                            */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_EIDEV1	0x01U    /* bit0 | 1: 1�� EIS ���� / 0: 1�� ���� */
#define RCELM_DSP_EION1		0x02U    /* bit1 | 1: 1�� EIS �ְ� / 0: 1�� ��� */
#define RCELM_DSP_SYSRUN1	0x04U    /* bit2 | 1: Systerm 1 Run On           */
#define RCELM_DSP_FS		0x08U    /* bit3 | 1: S (��ȣ�� ����)            */
#define RCELM_DSP_FP		0x10U    /* bit4 | 1: P (��ö�� ����)            */
#define RCELM_DSP_FT		0x20U    /* bit5 | 1: T (�˵� ���)              */
#define RCELM_DSP_EIDEV2	0x40U    /* bit6 | 1: 2�� EIS ���� / 0: 2�� ���� */
#define RCELM_DSP_EION2		0x80U    /* bit7 | 1: 2�� EIS �ְ� / 0: 2�� ��� */
/* ------------------------------------------------------------------------- */
/* RC  ������ȯ�� ǥ�� ���� Bit Position                                     */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_PT_NP		0x01U    					/* bit0 | 1:����     */
#define RCELM_DSP_PT_RP		0x02U    					/* bit1 | 1:����     */
#define RCELM_DSP_PT_LK		0x04U    					/* bit2 | 1:����     */
#define RCELM_DSP_PT_PF		0x08U    					/* bit3 | 1:����     */
#define RCELM_DSP_PT_MVN	0x10U    					/* bit4 | 1:�������� */
#define RCELM_DSP_PT_MVR	0x20U    					/* bit5 | 1:�������� */
#define RCELM_DSP_PT_WRR	0x40U    					/* bit6 | 1:WR-R     */
#define RCELM_DSP_PT_WRN	0x80U    					/* bit7 | 1:WR-N"    */
/* ------------------------------------------------------------------------- */
/* RC  ���, �峻��ȣ�� ǥ�� ���� Bit Position                               */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_SG_GO		0x01U  /* bit0 | 1: ���� ���� / 0: ���� ����     */
#define RCELM_DSP_SG_SF		0x02U  /* bit1 | 1: ���� / 0:  ����              */
#define RCELM_DSP_SG_GO2	0x04U  /* bit2 | 1: ����, ���� ������ ���       */
#define RCELM_DSP_SG_TTB	0x08U  /* bit3 | 1: TTB ON / 0: TTB OFF(TTCB)    */
#define RCELM_DSP_SG_AL		0x10U  /* bit4 | 1: ���ټ��� ON / 0: ���ټ�������*/
#define RCELM_DSP_SG_CG		0x20U  /* bit5 | 1: ���� ON / 0: ���� 0FF        */
#define RCELM_DSP_SG_GO3	0x40U  /* bit6 | 1: ���, ���� ���� ������ ���  */
#define RCELM_DSP_SG_LK		0x80U  /* bit7 | 1: REQ (��ȣ�� ������)"         */
/* ------------------------------------------------------------------------- */
/* RC  ��ȯ��ȣ��, ��ȯǥ�� ǥ�� ���� Bit Position                           */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_SHSG_GO           0x01U  /* 1:��������, 0:��������         */
#define RCELM_DSP_SHSG_SSF          0x02U  /* 1:����, 0:����                 */
#define RCELM_DSP_SHSG_SAL          0x10U  /* 1:����/��������On 0:Off        */
#define RCELM_DSP_SHSG_NCS          0x20U  /* 1:������ ǥ�� On 0:Off         */
#define RCELM_DSP_SHSG_LK           0x40U  /* 1:��ȣ�����, 0:Off            */
/* ------------------------------------------------------------------------- */
/* RC  ���������ȣ�� ǥ�� ���� Bit Position                                 */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_ABSG_HBG	0x01U	/* bit0 | 1:��������, 0:��������         */
#define RCELM_DSP_ABSG_HBF	0x02U	/* bit1 | 1:����, 0:����                 */
#define RCELM_DSP_ABSG_GO2	0x04U	/* bit2 | 1: ����, ���� ������ ���      */
#define RCELM_DSP_ABSG_GO3	0x40U	/* bit6 | 1: ���, ���� ���� ������ ��� */
/* ------------------------------------------------------------------------- */
/* RC  �����ȣ�� ǥ�� ���� Bit Position                                     */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_BSG_BSF		0x01U    /* 1:����, 0:����                   */
#define RCELM_DSP_BSG_GO		0x02U    /* 1:����, 0:����                   */
/* ------------------------------------------------------------------------- */
/* RC  ���� ǥ�� ���� Bit Position                                           */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_RT_TTB		0x01U    /* 1:TTB Set  0:Reset               */
#define RCELM_DSP_RT_LK			0x80U    /* 1:���μ��� 0:��������            */
/* ------------------------------------------------------------------------- */
/* RC  �˵�ȸ�� ǥ�� ���� Bit Position                                       */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_TC_OCC		0x01U	/* 1:������, 0:����                  */
#define RCELM_DSP_TC_FAIL		0x02U	/* 1:���                            */
#define RCELM_DSP_TC_GLK		0x04U	/* 1:���                            */
#define RCELM_DSP_TC_YLK		0x08U	/* 1:Ȳ��                            */
#define RCELM_DSP_TC_TTB		0x20U	/* 1:TTB                             */
#define RCELM_DSP_TC_EGR		0x40U	/* 1:�������                        */
/* ------------------------------------------------------------------------- */
/* RC  �ǳθ� ǥ�� ���� Bit Position                                         */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_RC			0x01U    /* 1:����, 0:����                   */
/* ------------------------------------------------------------------------- */
/* RC  ���Թ� ǥ�� ���� Bit Position                                         */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_DOOR			0x01U    /* 1:����, 0:����                   */
/* ------------------------------------------------------------------------- */
/* RC  ��������� ǥ�� ���� Bit Position                                     */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_DIR_DYF		0x01U    /* ��� Ȳ���� ���� SET:1           */
#define RCELM_DSP_DIR_DY		0x02U    /* ��� Ȳ���� ���� SET:1           */
#define RCELM_DSP_DIR_DR		0x04U    /* ��� ������ ���� SET:1           */
#define RCELM_DSP_DIR_DRF		0x08U    /* ��� ������ ���� SET:1           */
/* ------------------------------------------------------------------------- */
/* RC  ���� ǥ�� ���� Bit Position                                           */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_EQ_C1ACT		0x01U	/* bit0 | 1:COM1 ������ / 0: ����    */
#define RCELM_DSP_EQ_C1M		0x02U	/* bit1 | 1:COM1 �ֻ�� / 0: ���    */
#define RCELM_DSP_EQ_C2ACT		0x04U	/* bit2 | 1:COM2 ������ / 0: ����    */
#define RCELM_DSP_EQ_C2M		0x08U	/* bit3 | 1:COM2 �ֻ�� / 0: ���    */
#define RCELM_DSP_EQ_SHOFF		0x10U	/* bit4 | 1:��ȯ �ҵ�   / 0: ��ȯ����*/
#define RCELM_DSP_SYSRUN2		0x20U   /* bit5 | 1: Systerm 2 Run On       */
#define RCELM_DSP_EQ_N1X		0x40U	/* bit6 | 1:N1 ����     / 0: N1 ���� */
#define RCELM_DSP_EQ_N2X		0x80U	/* bit7 | 1:N2 ����     / 0: N2 ���� */
/* ------------------------------------------------------------------------- */
/* RC  ��ȣ�� �ϰ����� ǥ�� ����                                             */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_ALLSGSTOP		0x01U	/* ��ȣ�� �ϰ����� 1:���� 0:����     */
/* ------------------------------------------------------------------------- */
/* RC  ���� ���� Bit Position                                                */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_HT_O			0x01U	/* bit0 | 1:��������(1)              */
#define RCELM_DSP_HT_I			0x08U	/* bit3 | 1:�����Է�(1)              */
#define RCELM_DSP_HT_F			0x80U	/* bit7 | 1:���Ͱ���(1)              */
/* ------------------------------------------------------------------------- */
/* RC  ����������ġ�������� ǥ�� ���� Bit Position                           */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_IS1			0x01U    /* 1:����, 0:����                   */
#define RCELM_DSP_IS2			0x01U    /* 1:����, 0:����                   */
#define RCELM_DSP_ISACT			0x01U    /* 1:1����, 0:2����             */

/* ========================================================================= */
/* RC Element �� Control Bit State Define                                    */
/* ========================================================================= */
/* ------------------------------------------------------------------------- */
/* RC  ���� �ڵ�                                                             */
/* ------------------------------------------------------------------------- */
#define RCELM_CTRLCODE_MODE			(uint8)(0x01U)
#define RCELM_CTRLCODE_POINT		(uint8)(0x02U)
#define RCELM_CTRLCODE_ROUTE		(uint8)(0x03U)
#define RCELM_CTRLCODE_SHRUT		(uint8)(0x04U)
#define RCELM_CTRLCODE_DIR			(uint8)(0x05U)
#define RCELM_CTRLCODE_TCEG			(uint8)(0x10U)
#define RCELM_CTRLCODE_SYSRUN		(uint8)(0x20U)
#define RCELM_CTRLCODE_SHOFF		(uint8)(0x30U)
#define RCELM_CTRLCODE_ALLSGS		(uint8)(0x40U)
#define RCELM_CTRLCODE_HEAT			(uint8)(0x80U)
/* ------------------------------------------------------------------------- */
/* RC  ������ ��ȯ ���� Bit                                                */
/* ------------------------------------------------------------------------- */
#define RCELM_CTRL_MD_LOCACT	(uint8)(0x01U)  /* 1 : LOCAL ��� ��ȯ ����  */
#define RCELM_CTRL_MD_EMLOC		(uint8)(0x02U)	/* 1 : ��� Local ��ȯ ��û  */
#define RCELM_CTRL_MD_RCACT		(uint8)(0x04U)  /* 1 : RC ��ȯ ���          */
#define RCELM_CTRL_MD_EMRC		(uint8)(0x08U)  /* 1 : ��� RC ��ȯ ���     */
#define RCELM_CTRL_MD_LOCCAN	(uint8)(0x10U)  /* 1 : Local ��ȯ ���       */
#define RCELM_CTRL_MD_CTCCAN	(uint8)(0x20U)  /* 1 : CTC ��ȯ ���         */
#define RCELM_CTRL_MD_CTCREQ	(uint8)(0x80U)  /* 1 : CTC ��ȯ ��û         */
/* ------------------------------------------------------------------------- */
/* RC  ������ȯ�� ��ȯ ���� Bit                                              */
/* ------------------------------------------------------------------------- */
#define RCELM_CTRL_PT_MVN		((uint8)0x01U)		/* bit0 | 1 : ������ȯ ��û  */
#define RCELM_CTRL_PT_MVR		((uint8)0x02U)  	/* bit1 | 1 : ������ȯ ��û  */
/* ------------------------------------------------------------------------- */
/* RC  ���� ���� ���� Bit                                                    */
/* ------------------------------------------------------------------------- */
#define RCELM_CTRL_RT_SET		(uint8)(0x01U)		/* 1 : ���μ���              */
#define RCELM_CTRL_RT_CAN		(uint8)(0x02U)		/* 1 : �������              */
#define RCELM_CTRL_RT_TTB		(uint8)(0x04U)		/* 1 : ������������ ON(TTB)  */
#define RCELM_CTRL_RT_TTCB		(uint8)(0x08U)		/* 1 : ������������ OFF(TTCB)*/
#define RCELM_CTRL_RT_STOP		(uint8)(0x10U)		/* 1 : ��ȣ�� �������       */
#define RCELM_CTRL_RT_RSET		(uint8)(0x20U)		/* 1 : ���������            */
/* ------------------------------------------------------------------------- */
/* RC  ��󱸺����� ���� ���� Bit                                            */
/* ------------------------------------------------------------------------- */
#define RCELM_CTRL_EGTC			((uint8)0x01)		/** 1: �������          */
#define RCELM_CTRL_FAILRLS		((uint8)0x02)		/** 1: ��󺹱�          */
/* ------------------------------------------------------------------------- */
/* RC  System RUN ���� ���� Bit                                              */
/* ------------------------------------------------------------------------- */
#define RCELM_CTRL_SYSRUN		((uint8)0x01)		/** 1: RUN ����          */
/* ------------------------------------------------------------------------- */
/* RC  ��� ���� ���� Bit                                                    */
/* ------------------------------------------------------------------------- */
#define RCELM_CTRL_DIR_CAN		((uint8)0x01U)		/** ��� ���            */
#define RCELM_CTRL_DIR_ENT		((uint8)0x02U)		/** ��� �峻            */
#define RCELM_CTRL_DIR_ACPT		((uint8)0x04U)		/** ��� ����            */
#define RCELM_CTRL_DIR_EXIT		((uint8)0x08U)		/** ��� ���            */
/* ------------------------------------------------------------------------- */
/* RC  ��ȣ���ϰ� ���� ���� ���� Bit                                         */
/* ------------------------------------------------------------------------- */
#define RCELM_CTRL_ALLSGSET		((uint8)0x01)		/** 1: �ϰ����� ����     */
#define RCELM_CTRL_ALLSGCAN		((uint8)0x02)		/** 1: �ϰ����� ����     */
/* ------------------------------------------------------------------------- */
/* RC  ��ȯ�ҵ� ���� ���� Bit                                                */
/* ------------------------------------------------------------------------- */
#define RCELM_CTRL_SHOFFSET		((uint8)0x01)		/** 1: ��ȯ�ҵ� ����     */
#define RCELM_CTRL_SHONSET		((uint8)0x02)		/** 1: ��ȯ���� ����     */
/* ------------------------------------------------------------------------- */
/* RC  ���� ���� ���� Bit                                                    */
/* ------------------------------------------------------------------------- */
#define RCELM_CTRL_HEATON		((uint8)0x01)		/** 1: �������� On       */
#define RCELM_CTRL_HEATOFF		((uint8)0x02)		/** 1: �������� Off      */

/* ------------------------------------------------------------------------- */
/* Bit Operation �� ó�� Type                                                */
/* ------------------------------------------------------------------------- */
#define FUNC_LDA	1
#define FUNC_STA	2
#define FUNC_AND	3
#define FUNC_ORA	4
#define FUNC_ANS	5
#define FUNC_ORS	6
#define FUNC_MOV	7
#define FUNC_TRS	8			/** TRUE�� ���� SET                          */

#define BIO_ROUTE_VALUE	0xFF	/** BIT_EXCEPTION ucBitPos�� ��(ROUTE ����)*/

#define LIMIT_SWCHECK_TIME	12	/** 12 sec.    */
/* ------------------------------------------------------------------------- */
/* SMEM Position Define                                                      */
/* ------------------------------------------------------------------------- */
/* IO INFO TABLE */
#define IO_INFO_TYPE_IO_INVERSE 0x40
#define IO_INFO_TYPE_IO_OUTPUT  0x80
#define IO_INFO_MASK_BIT_OFFSET 0x07

#define NAME_SIZE		10
/* ------------------------------------------------------------------------- */
/* Axle counter Reset timing Define                                          */
/* ------------------------------------------------------------------------- */
#define AXLE_RS_SAFETY_INTERVAL		1U	/*(10000U/MAX_TICK_ILT)*/
#define AXLE_RS_FIRST_IMPULSE		((5000U/MAX_TICK_ILT) + AXLE_RS_SAFETY_INTERVAL)
#define AXLE_RS_PAUSE				((3000U/MAX_TICK_ILT) + AXLE_RS_FIRST_IMPULSE)
#define AXLE_RS_SECOND_IMPULSE		((5000U/MAX_TICK_ILT) + AXLE_RS_PAUSE)
/* ------------------------------------------------------------------------- */

#endif
