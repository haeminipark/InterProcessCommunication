/* -------------------------------------------------------------------------- /
17.10.23 : 
 - [CTC궤도Reset추가]
17.09.28 :
 - [CTC궤도제어추가]
 - [CTC궤도상태추가]
17.09.06 : 
   - [CTC시스템RUN추가]
17.06.12 : [확장FUSE&REC재정의]
17.02.01 :
 - [VCR추가] VCR A/B IO Type 정의
17.02.09 :
 - [TASK추가] uart 제어 driver task
17.11.11 :
 - [계절체부정입력지연]
17.12.20 :
 - [엑셀카운터리셋] smTOBJ에 TKAXR 출력 추가
 - [ATS고장추가] 현장입력 정보
 - [ZLMR분리추가]
 - [MRFAIL추가]
 - [GIO기타표시추가]
 18.03.21 :
  - [콘솔정보줄임]
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
* @brief KRSEIS에서 사용되는 Define File
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
/* 연동 Data 관련 Define                                                     */
/* ------------------------------------------------------------------------- */
#define OBJECT_START				1		/** Object ID 시작 값            */
/* ------------------------------------------------------------------------- */
/* 역 ID Define                                                              */
/* ------------------------------------------------------------------------- */
#define STID_DANYANG				1U		/** 단양                         */
#define STID_YDTERM					2U		/** 영동보수기지                 */
#define STID_OKGAE					3U		/** 옥계                         */
#define STID_JECHENJO				4U		/** 제천조차장                   */
#define STID_SEOWONJU				5U		/** 서원주                       */
#define STID_OSONGTERM				6U		/** 오송차량기지                 */
#define STID_GAYATERM				7U		/** 가야차량기지                 */
#define STID_PUSANTERM				8U		/** 부산고속차량기지             */
#define STID_BUBALTERM				9U		/** 부발차량기지                 */
#define STID_101					10U		/** 101신호장                    */
#define STID_MANJONG				11U		/** 만종                         */
#define STID_HOINGSUNG				12U		/** 횡성                         */
#define STID_DUNNAE					13U		/** 둔내                         */
#define STID_PEYUNGCHANG			14U		/** 평창                         */
#define STID_JINBU					15U		/** 진부                         */
#define STID_DGRSIGTERM				16U		/** 대관령신호장                 */
#define STID_NKRSIGTERM				17U		/** 남강릉신호장                 */
#define STID_KANGREUNGSIG			18U		/** 강릉신호소                   */
#define STID_KANGREUNG				19U		/** 강릉                         */
#define STID_POHANG					20U		/** 포항                         */
#define STID_CHUNGHA				21U		/** 청하                         */
#define STID_NAMJUNG				22U		/** 남정                         */
#define STID_YOUNGDUK				23U		/** 영덕                         */
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
/* 신호설비 최대 수용 범위                                                   */
/* ------------------------------------------------------------------------- */
/*구번전용 신버전 적용 후 값 변경 또는 삭제*/
#define MAX_ROUTE 					1024U	/** 수용 진로 최대치             */
#define MAX_SIGNAL 					512U	/** 수용 신호기 최대치           */
#define MAX_POINT 					256U	/** 수용 선로전환기 최대치       */
#define MAX_TRACK 					512U	/** 수용 궤도 최대치             */

#define MAX_ROUTE_NEW				1024	/** 수용 진로 최대치             */
#define MAX_TRACK_NEW				512		/** 수용 궤도 최대치             */
#define MAX_SIGNAL_NEW				512		/** 수용 신호기 최대치           */
#define MAX_POINT_NEW				256		/** 수용 선로전환기 최대치       */
#define MAX_GENERAL_IO 				50U		/** 수용 GIO 최대치              */
#define MAX_DESTPOINT 				100		/** 도착점 최대치                */
#define MAX_INFO_GENERAL			128		/** 수용 BIT OPERATION 최대치    */
/* ------------------------------------------------------------------------- */
/* ILDB 관련 Define                                                          */
/* ------------------------------------------------------------------------- */
#define ILDB_CRC32_CHECK_BLOCK		((uint32)1000)	/** ILDB CRC32 검사단위(byte)*/
#define MAX_ILDB_CRC32				300		/** ILDB 1000byte CRC32 최대수   */
#define ILDB_ALL_CRC32_AREA			4U		/** ILDB 전체CRC의 변수 크기     */
#define ILDB_DATASIZE_AREA			4U		/** ILDB 전체 크기의 변수 크기   */
#define ILDB_CRC32_INITVALUE		0x00000000UL	/** CRC32 초기값         */

/* ------------------------------------------------------------------------- */
/* ILDB Option define                                                        */
/* ------------------------------------------------------------------------- */
#define SIZE_ILDB_VERSION			18U		/** ILDB Version data size       */
#define VER_BASE_POS				0U		/** Version Data-Base Offset     */
#define VER_STID_POS				6U		/** Version Data-StnID Offset    */
/* Version Option Offset defined ------------------------------------------- */
#define VER_OPT1_POS_INOUT_CHK		8U		/** [Opt1] ILT IN/OUT 비교 Option*/
#define VER_OPT2_POS_DIAG_OPTION	9U		/** [Opt2] 진단 Option           */
#define VER_OPT3_POS_INIT_OPTION	10U		/** [Opt3] 기능 Option           */
#define VER_OPT4_POS_TCRLS_VALUE	11U		/** [Opt4] 궤도해정시간 설정     */
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
#define VO2_RTCTRL_ZRON				0x40U	/** 진로취급 시 ZR ON            */
#define VO2_SHUNT_TC_RELEASE_FAIL	0x80U	/** 입환OUT신호기 궤도부정복귀   */
/*#define VO2_IOS_IGNORE_OTHER_SAFESTATE 0x80U */ /** 사용하지 않음 */
/* [Opt3]VER_OPT3_POS_INIT_OPTION bit value -------------------------------- */
#define VO3_INIT_CTRLMD_CTC			0x01U
#define VO3_CTRLWR_USED_VDO			0x02U	/** WR제어 VDO 사용              */
#define VO3_CTC_CTRL_RUN			0x04U	/** CTC RUN 제어 가능            */
#define VO3_CTC_CTRL_TC_EG			0x08U	/** CTC 비상해정 제어 가능       */
#define VO3_CTC_CTRL_TC_BLK			0x10U	/** CTC 궤도 사용금지 제어 가능  */
#define VO3_CTC_DSP_TC_LOCK			0x20U	/** CTC 궤도 진로쇄정정보 제공   */
#define VO3_CTC_TC_RESET			0x40U	/** CTC 궤도(AXC) Reset 제어     */ /* [CTC궤도Reset추가] */
#define VO3_JAKARTA_LRT				0x80U	/** 자카르타 LRT 전용 기능       */

/* [Opt5]VER_OPT3_POS_INIT_OPTION bit value -------------------------------- */
#define VO5_L_STNID_MASK			0xF0U
#define VO5_R_STNID_MASK			0x0FU

#define	VO_UPLINE_MASK				0xF0U
#define	VO_DNLINE_MASK				0x0FU

/* ------------------------------------------------------------------------- */
#define SIZE_ROUTEDATA_AREA			100000U	/** ILDB 진로Data 최대 크기      */
#define SIZE_TRACK_LINK_AREA		30000U	/** 연결궤도회로 테이블 사이즈   */

#define MAX_BLOCKSECTION			10U		/** ILDB 폐색Data 수             */
#define MAX_SGTBL_APPROACH_INFO		40U		/** Sg info tbl 접근쇄정 data 수 */
#define MAX_BLOCK_TRACK				20U		/** 폐색 data 궤도정보 최대치    */


#define POINT_NORMAL_POSITION		0U
#define POINT_REVERSE_POSITION		1U

#define POINT_N_CHECK				1
#define POINT_R_CHECK				2
/* ------------------------------------------------------------------------- */
/* System Fault Value Define                                                 */
/* ------------------------------------------------------------------------- */
/* System Down (Safe-state 사유) */
#define ILDB_ROM_SIZE_CHECK_FAILURE	(uint32)(0x00000001U)	/** ROM Data Size Fail   */
#define ILDB_SIZE_CHECK_FAILURE		(uint32)(0x00000002U)	/** Read Data Size Fail  */
#define ILDB_CRC32_CHECK_FAILURE	(uint32)(0x00000004U)	/** CRC32 Check Fail     */
#define ILDB_ALLCRC32_CHECK_FAILURE	(uint32)(0x00000008U)	/** All CRC32 Check Fail */

#define SYSTEM_ID_FAILURE			(uint32)(0x00000010U)	/** System ID Fail   */
#define SYSTEM_ID_DUPLICATION		(uint32)(0x00000020U)	/** System ID 중복   */
#define IOS_LINK_FAILURE			(uint32)(0x00000040U)	/** IOS Link Fail    */
#define MESSAGE_Q_CREATION_FAILURE	(uint32)(0x00000080U)	/** Msg Q 생성 Fail  */

#define OTHSYS_ILDB_SIZE_FAILURE	(uint32)(0x00000100U)	/** 계간DB Size Fail */
#define OTHSYS_ILDB_CRC_FAILURE		(uint32)(0x00000200U)	/** 계간DB CRC Fail  */
#define OTHSYS_SYSID_SAME			(uint32)(0x00000400U)	/** 계간 SysID중복   */
#define OTHSYS_PRGCRC_FAIL			(uint32)(0x00000800U)	/** 계간PG CRC 불일치*/

#define ILDB_IO_CONFIG_FAILURE		(uint32)(0x00001000U)	/** IO 구성정보 fail */
#define APPLICATION_ACT_FAILURE		(uint32)(0x00002000U)	/** Application Fail */
#define CPU2CPU_ILDB_MISMATCH		(uint32)(0x00004000U)	/** 채널간 ILDB fail */
#define CPU2CPU_CHID_FAILURE		(uint32)(0x00008000U)	/** 채널ID 설정오류  */

#define DIO_IF_FAILURE				(uint32)(0x00010000U)	/** DIO I/F 실패     */
#define COMM_MODULE_FAILURE			(uint32)(0x00020000U)	/** Com module 장애  */
#define SYS_IF_FAILURE				(uint32)(0x00040000U)	/** 계간 I/F 장애    */
#define VRD_CHECK_FAILURE			(uint32)(0x00080000U)	/** VRD 동작 장애    */

#define VCR_FAILURE					(uint32)(0x00100000U)	/** VCR 낙하         */
#define ILS_SAFESTATE_MASK			(uint32)(0x000FFFFFU)	/** SafeState bit    */

/* 계절체 사유 (VRD Off) */
#define VRD_IN_FAIL					(uint32)(0x01000000U)	/** VRD 동작불능     */
#define IOS_FUSE_FAIL				(uint32)(0x02000000U)	/** FUSE 장애        */
#define SYS_IN_MISMATCH				(uint32)(0x04000000U)	/** 계간 입력 불일치 */
#define SYS_OUT_MISMATCH			(uint32)(0x08000000U)	/** 계간 출력 불일치 */
#define INPUT_ILLEGAL_ERROR			(uint32)(0x10000000U)	/** 부정입력(연동)   */
#define ILLEGAL_INPUT_MODULE		(uint32)(0x20000000U)	/** IN모듈 부정입력  */
#define ILLEGAL_OUTPUT_MODULE		(uint32)(0x40000000U)	/** OUT모듈 부정출력 */
#define ILLEGAL_ERROR				(uint32)(0x80000000U)	/** 채널간 부정처리  */

#define ILS_VRDOFF_STATE_MASK		(uint32)(0xF0000000U)	/** VRD Off Mask     */

/* ------------------------------------------------------------------------- */
/* System ID Define                                                          */
/* ------------------------------------------------------------------------- */
#define SYSTEM_1_ID					((uint8)0xF1)	/** 1계 */
#define SYSTEM_2_ID					((uint8)0xF2)	/** 2계 */
/* ------------------------------------------------------------------------- */
/* System Delay                                                              */
/* ------------------------------------------------------------------------- */
#define SYS_SWITCH_DELAY	(3000U/MAX_TICK_ILT)   /** 출력에 대한 입력 Count*/ /* [계절체부정입력지연] */
/* ------------------------------------------------------------------------- */
/* CheckBack Delay                                                           */
/* ------------------------------------------------------------------------- */
#define RELAY_CHECKBACK_DELAY		(800U/MAX_TICK_ILT)	/** 출력에 대한 입력 Count */
//#define LMR_CHECK_DELAY				(2000U/MAX_TICK_ILT)/** 출력에 대한 입력 Count */
#define LMR_CHECK_DELAY				(3600U/MAX_TICK_ILT)/** 출력에 대한 입력 Count */
/* ------------------------------------------------------------------------- */
/* System Operate Mode Define                                                */
/* ------------------------------------------------------------------------- */
#define SO_MODE_STRATUP			(uint8)(0x01U)	/** StartUp Mode             */
#define SO_MODE_READY			(uint8)(0x02U)	/** Ready Mode(Run 대기)     */
#define SO_MODE_ACTIVE_RUN		(uint8)(0x04U)	/** Active Mode(주계 운용)   */
#define SO_MODE_STANDBY_RUN		(uint8)(0x08U)	/** Standby Mode(부계 운용)  */
#define SO_MODE_SAFETY			(uint8)(0x10U)	/** Safety Mode              */
#define SO_MODE_SYSTEMDOWN		(uint8)(0x20U)	/** System Down              */
#define SO_MODE_SAFETY_NC		(uint8)(0x40U)	/** Safety Mode (절체 불가)  */
#define SO_MODE_CLEAR			(uint8)(0x00U)
/* ------------------------------------------------------------------------- */
/* 장애 Max Counter                                                          */
/* ------------------------------------------------------------------------- */
#define FAIL_COUNT_VRDIN		(uint8)(0x19U)
#define FAIL_COUNT_VRDINILL		(uint8)(0x0AU)
#define VRD_ON_CHECK_COUNT		(uint8)(0x04U)
/* ------------------------------------------------------------------------- */
/* 신호기 동작 상태                                                          */
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
/* 신호기 동작 상태                                                          */
/* ------------------------------------------------------------------------- */
#define SG_LOGASP_ON			((uint8)0x01U)

/* ------------------------------------------------------------------------- */
/* 신호기 Delay                                                              */
/* ------------------------------------------------------------------------- */
#define SG_DLY_MASK				(uint8)(0x3FU)
#define SG_DLY_BSGVALUE			(uint8)(1400U/MAX_TICK_ILT)
#define SG_DLYBIT_BSGDRI		(uint8)(0x80U)
#define SG_DLYBIT_BSGBRI		(uint8)(0x40U)

/* ------------------------------------------------------------------------- */
/* 역 제어 모드 Define                                                       */
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
/* LOCAL Element 관련 Define                                                 */
/* ------------------------------------------------------------------------- */
#define MAX_LOCAL_ELEMENT			2899U	/** Local Element 최대치         */
#define MAX_LOCAL_ELEMENT_COMMON	32U		/** Local Element Common data 수 */

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
/* LOCAL Element 폐색제어 Define                                             */
/* ------------------------------------------------------------------------- */
#define BLDIR_EXIT_REQ				(uint8)(0x01U)	/** 출발                 */
#define BLDIR_ENTRY_ACPT			(uint8)(0x02U)	/** 장내                 */
#define BLDIR_ENTRYOPEN_REQ			(uint8)(0x04U)	/** 개통 (요청)          */
#define BLDIR_ENTRYOPEN_ACPT		(uint8)(0x08U)	/** 개통 (승인)          */
#define BLDIR_CANCEL_REQ			(uint8)(0x10U)	/** 취소 (요청)          */
#define BLDIR_CANCEL_ACPT			(uint8)(0x20U)	/** 취소 (승인)          */
/* ------------------------------------------------------------------------- */
/* LOCAL Element 선로전환기 제어 Define                                      */
/* ------------------------------------------------------------------------- */
#define LOCELM_CTRL_PT_N			(uint8)(0x10U)
#define LOCELM_CTRL_PT_R			(uint8)(0x20U)
/* ------------------------------------------------------------------------- */
/* LOCAL Element 진로 제어 Define                                            */
/* ------------------------------------------------------------------------- */
#define LOCELM_CTRL_RT_SET			(uint8)(0x01U)
#define LOCELM_CTRL_RT_TTB			(uint8)(0x04U)
#define LOCELM_CTRL_RT_TTCB			(uint8)(0x08U)
#define LOCELM_CTRL_RT_CAN			(uint8)(0x10U)
#define LOCELM_CTRL_RT_RESET		(uint8)(0x20U)
/* ------------------------------------------------------------------------- */
/* LOCAL Element 궤도 제어 Define                                            */
/* ------------------------------------------------------------------------- */
#define LOCELM_CTRL_TC_RELEASE		(uint8)(0x20U)
/* ------------------------------------------------------------------------- */
/* LOCAL Element RUN 제어 Define                                             */
/* ------------------------------------------------------------------------- */
#define LOCELM_CTRL_RUN1			(uint8)(0x04U)
#define LOCELM_CTRL_RUN2			(uint8)(0x10U)
/* ------------------------------------------------------------------------- */
/* LOCAL Element 입환소등 제어 Define                                        */
/* ------------------------------------------------------------------------- */
#define LOCELM_CTRL_SHOFF_SET		(uint8)(0x10U)
#define LOCELM_CTRL_SHOFF_CAN		(uint8)(0x20U)
/* ------------------------------------------------------------------------- */
/* LOCAL Element 신호기일괄정지 제어 Define                                  */
/* ------------------------------------------------------------------------- */
#define LOCELM_CTRL_SGALLSTOP_SET		(uint8)(0x10U)
#define LOCELM_CTRL_SGALLSTOP_CAN		(uint8)(0x20U)
/* ------------------------------------------------------------------------- */
/* LOCAL Element 히터 제어 Define                                            */
/* ------------------------------------------------------------------------- */
#define LOCELM_CTRL_HET_SET		(uint8)(0x20U)
#define LOCELM_CTRL_HET_CAN		(uint8)(0x40U)
/* ------------------------------------------------------------------------- */
/* LOCAL Element State Bit Position Define                                   */
/* ------------------------------------------------------------------------- */
#define MAX_LOCELM_STATE_BUFF		12
#define MAX_LOCELM_BASESCAN_BUFF	4 /*[콘솔정보줄임]*/

#define LOCELM_AOFF_REQ_BIT1		0x10U
#define LOCELM_AOFF_REQ_BIT2		0x01U

#define LES_NONE			((uint8)0x00U)
/* --------------------------------- */
/* 시스템 기동 (RUN) 상태            */
/* --------------------------------- */
#define LES_SYSRUN1			((uint8)0x04U)
#define LES_SYSRUN2			((uint8)0x08U)
/* --------------------------------- */
/* 시스템 기동 (RUN) 제어 상태       */
/* --------------------------------- */
#define LES_OP_SYSRUN1		((uint8)0x10U)
#define LES_OP_SYSRUN2		((uint8)0x20U)
/* --------------------------------- */
/* 취급 운영모드 상태                */
/* --------------------------------- */
#define LES_OPMD_CTCREQ		(uint8)(0x01U)
#define LES_OPMD_CTC		(uint8)(0x02U)
#define LES_OPMD_LOCALREQ	(uint8)(0x04U)
#define LES_OPMD_LOCAL		(uint8)(0x08U)
#define LES_OPMD_RCREQ		(uint8)(0x10U)
#define LES_OPMD_RC			(uint8)(0x20U)
/* --------------------------------- */
/* 연동논리부 1 계 시스템 상태       */
/* --------------------------------- */
#define LES_ILS1_ALARM		(uint8)(0x10U)
#define LES_ILS1_STATE		(uint8)(0x20U)
#define LES_ILS1_ACTIVE		(uint8)(0x40U)
/* --------------------------------- */
/* 연동논리부 2 계 시스템 상태       */
/* --------------------------------- */
#define LES_ILS2_ALARM		((uint8)0x10U)
#define LES_ILS2_STATE		((uint8)0x20U)
#define LES_ILS2_ACTIVE		((uint8)0x40U)
/* --------------------------------- */
/* 주 전원 한전전원(N1)   상태       */
/* --------------------------------- */
#define LES_N1_ALARM		((uint8)0x10U)
#define LES_N1_X1			((uint8)0x20U)
#define LES_N1_SUPPLY		((uint8)0x40U)
/* --------------------------------- */
/* 주 전원 철도전원(N2)  상태        */
/* --------------------------------- */
#define LES_N2_ALARM		((uint8)0x10U)
#define LES_N2_X2			((uint8)0x20U)
#define LES_N2_SUPPLY		((uint8)0x40U)
/* --------------------------------- */
/* UPS 상태                          */
/* --------------------------------- */
#define LES_UPS_ALARM		((uint8)0x10U)
#define LES_UPS_STATE		((uint8)0x20U)
/* --------------------------------- */
/* 정류기 상태                       */
/* --------------------------------- */
#define LES_REC_ALARM		((uint8)0x10U)
#define LES_REC_STATE		((uint8)0x20U)
#define LES_REC_MAIN		((uint8)0x40U)
/* --------------------------------- */
/* 축전지 상태                       */
/* --------------------------------- */						
#define LES_CD_ALARM		((uint8)0x10U)
#define LES_CD_STATE		((uint8)0x20U)
/* --------------------------------- */
/* FUSE 상태                         */
/* --------------------------------- */
#define LES_FUSE_ALARM		((uint8)0x10U)
#define LES_FUSE_STATE		((uint8)0x20U)
/* --------------------------------- */
/* 북쪽 선로전환기(P북) 전원 상태    */
/* --------------------------------- */
#define LES_PTPWN_ALARM		((uint8)0x10U)
#define LES_PTPWN_STATE		((uint8)0x20U)
/* --------------------------------- */
/* 남쪽 선로전환기(P남) 전원 상태    */
/* --------------------------------- */
#define LES_PTPWS_ALARM		((uint8)0x10U)
#define LES_PTPWS_STATE		((uint8)0x20U)
/* --------------------------------- */
/* 신호기 공통 고장 상태             */
/* --------------------------------- */
#define LES_COSG_ALARM		((uint8)0x10U)
#define LES_COSG_STATE		((uint8)0x20U)
/* --------------------------------- */
/* 선로전환기 공통 고장 상태         */
/* --------------------------------- */
#define LES_COPT_ALARM		((uint8)0x10U)
#define LES_COPT_STATE		((uint8)0x20U)
/* --------------------------------- */
/* 궤도회로 공통 고장 상태           */
/* --------------------------------- */
#define LES_COTC_ALARM		((uint8)0x10U)
#define LES_COTC_STATE		((uint8)0x20U)
/* --------------------------------- */
/* 신호기계실 출입문 상태            */
/* --------------------------------- */
#define LES_DOOR_ALARM		((uint8)0x10U)
#define LES_DOOR_LOCK		((uint8)0x20U)
/* --------------------------------- */
/* 신호기 일괄정지 제어 상태         */
/* --------------------------------- */
#define LES_ALLSGSTOP_SET	((uint8)0x10)
#define LES_ALLSGSTOP_REQ	((uint8)0x20)
/* --------------------------------- */
/* 입환표지(신호기) 소등 제어 상태   */
/* --------------------------------- */
#define LES_SHOFF_SET		((uint8)0x10)
#define LES_SHOFF_REQ		((uint8)0x20)
/* --------------------------------- */
/* 북쪽 히터 제어 상태	            */
/* --------------------------------- */
#define LES_PTHTN_SET		((uint8)0x40)
#define LES_PTHTN_REQ		((uint8)0x80)
/* --------------------------------- */
/* 남쪽 히터 제어 상태               */
/* --------------------------------- */
#define LES_PTHTS_SET		((uint8)0x40)
#define LES_PTHTS_REQ		((uint8)0x80)
/* --------------------------------- */
/* COM12 상태                        */
/* --------------------------------- */
#define LES_COM12_LINK		((uint8)0x20)
#define LES_COM12_ACT		((uint8)0x40)
/* --------------------------------- */
/* 궤도회로 상태                     */
/* --------------------------------- */
#define LES_TC_OCC			(uint8)(0x01U)
#define LES_TC_ROUTE		(uint8)(0x02U)
#define LES_TC_LRLOCK		(uint8)(0x04U)
#define LES_TC_FAIL			(uint8)(0x10U)
#define LES_TC_REQ			(uint8)(0x20U)
#define LES_TC_EMREL		(uint8)(0x40U)
#define LES_TC_DLOCK		(uint8)(0x80U)
/* --------------------------------- */
/* 궤도회로 표찰 상태                */
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
/* 신호기 상태                       */
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
/* 신호기 상태                       */
/* --------------------------------- */
#define LES_INBSG_GO		(uint8)(0x10U)
#define LES_INBSG_FAIL		(uint8)(0x20U)
/* --------------------------------- */
/* 선로전환기 상태	                 */
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
/* 진로 설정 제어 상태               */
/* --------------------------------- */
#define LES_RUT_Y			((uint8)0x01)
#define LES_RUT_G			((uint8)0x02)
#define LES_RUT_Y1			((uint8)0x04)
#define LES_RUT_ING			((uint8)0x08)
#define LES_RUT_SET			((uint8)0x10)
#define LES_RUT_REQ			((uint8)0x20)
/* --------------------------------- */
/* 폐색(취급버튼/방향표) 표시 상태   */
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
/* 건널목 고장 상태                  */
/* --------------------------------- */
#define LES_RC_ALARM		((uint8)0x10U)
#define LES_RC_STATE		((uint8)0x20U)
/* --------------------------------- */
/* 지장물검지장치 고장 상태          */
/* --------------------------------- */
#define LES_OSTC_ALARM		((uint8)0x10U)
#define LES_OSTC_STATE		((uint8)0x20U)
#define LES_OSTC_OP			((uint8)0x40U)
/* --------------------------------- */
/* 절연구간예고장치 상태             */
/* --------------------------------- */
#define LES_ISLAN1_ALARM	(uint8)(0x01U)
#define LES_ISLAN1_STATE	(uint8)(0x02U)
#define LES_ISLAN1_ACTIVE	(uint8)(0x04U)
#define LES_ISLAN2_ALARM	(uint8)(0x10U)
#define LES_ISLAN2_STATE	(uint8)(0x20U)
#define LES_ISLAN2_ACTIVE	(uint8)(0x40U)
/* --------------------------------- */
/* 확장랙 정류기 상태                */
/* --------------------------------- */
#define LES_EXREC_ALARM		((uint8)0x10U)
#define LES_EXREC_STATE		((uint8)0x20U)
/* ------------------------------------------------------------------------- */
/* Route Data Table Define                                                   */
/* ------------------------------------------------------------------------- */
/* (NEW) Route Data Type Define -------------------------------------------- */
#define RT_TYPE_MAIN				0x0001		/** 주 진로                  */
#define RT_TYPE_TTB					0x0002		/** TTB 진로                 */
#define RT_TYPE_CALLON				0x0004		/** 유도 진로                */
#define RT_TYPE_MAINLINE			0x0008		/** 본선 진로                */

#define RT_TYPE_SHUNT				0x0010		/** 입환표지 진로            */
#define RT_TYPE_SHUNTSIGNAL			0x0020		/** 입환신호기 진로          */
#define RT_TYPE_SHUNTOUT			0x0040		/** 입환신호기 출발          */
#define RT_TYPE_BLOCK				0x0100		/** 구내폐색 진로 RT_BLOCK   */

#define RT_TYPE_LIMIT_YY			0x1000		/** 진로 최대현시 YY         */
#define RT_TYPE_LIMIT_Y				0x2000		/** 진로 최대현시 Y          */
#define RT_TYPE_LIMIT_YG			0x4000		/** 진로 최대현시 YG         */
#define RT_TYPE_LIMIT_G				0x8000		/** 진로 최대현시 G          */
#define RT_TYPE_LIMIT_BITS			0xF000		/** 진로 최대현시 Mask Bit   */
/* ------------------------------------------------------------------------- */
/* Route Data (도착점 궤도)                                                  */
/* ------------------------------------------------------------------------- */	
#define RT_DESTTC_ARRIVETRACK_BIT	0x8000U
#define RT_DEST_TM_LOCK_SET			0x80U
/* ------------------------------------------------------------------------- */
/* Route Data (신호제어 궤도 조건)                                           */
/* ------------------------------------------------------------------------- */	
#define RT_SIGTC_TC_OUTROUTE		0x4000		/** 접촉한계 궤도            */
#define RT_SIGTC_TCCOND_POINT		0x1000		/** 접촉한계 선로전환기 사용 */
#define RT_SIGTC_TCCOND_CLOSETC		0x0800		/** 폐로쇄정 궤도회로        */
#define	RT_SIGTC_CLSH				0x0400		/** 유도/입환표지 용 조건    */
#define	RT_SIGTC_MSSHS				0x0200		/** 주/입환 신호기 용 조건   */
#define RT_SIGTC_TCCOND_TCMASK		0x01FF
/* ------------------------------------------------------------------------- */
/* Route Data (선로전환기 조건)                                              */
/* ------------------------------------------------------------------------- */	
#define	RT_POINT_RLSTC				0x0200		/** 구분해정 조건            */
#define	RT_POINT_CLSH				0x0400		/** 유도/입환표지 용 조건    */
#define	RT_POINT_MSSHS				0x0800		/** 주/입환 신호기 용 조건   */
#define	RT_POINT_TMLOCK				0x1000		/** 유효장 시간쇄정 조건     */
#define	RT_POINT_REVERSE			0x2000		/** 선로전환기 방향          */
#define	RT_POINT_OVERLAP			0x4000		/** 과주 선로전환기 조건     */
#define	RT_POINT_BACKROUTE			0x8000		/** 후방쇄정 선로전환기 조건 */
#define RT_POINT_OVERLAP_SG_MASK	0x01FF
/* ------------------------------------------------------------------------- */
/* Point Data Define                                                         */
/* ------------------------------------------------------------------------- */	
#define POINT_TYPE_SINGLE			0x01U	/** 단동                         */
#define POINT_TYPE_DOUBLE			0x02U	/** 쌍동                         */
#define POINT_TYPE_TRIPLE			0x03	/** 삼동                         */
#define POINT_TYPE_A				0x04	/** 독립형 A(쌍동/삼동)          */
#define POINT_TYPE_B				0x05	/** 독립형 B(쌍동/삼동)          */
#define POINT_TYPE_C				0x06	/** 독립형 C(쌍동/삼동)          */
#define POINT_TYPE_MASK				0x0F	/** ----                         */
#define POINT_TYPE_GENERAL			0x10	/** 일반                         */
#define POINT_TYPE_HIGH				0x20	/** 고속                         */
#define POINT_TYPE_INDIVIDUAL		0x40	/** 개별 처리 (D형 선로전환기)   */ /*이 의미로 사용치 않음*/
#define POINT_TYPE_HIGH_NONCROSSING	0x40	/** 고속(크로싱부 미존재)        */

#define MAX_TRACK_IN_POINTTABLE		3U		/** Point Table 내 궤도 최대치   */
#define MAX_POINT_IN_POINTTABLE		3U		/** Point Table 내 연관 Point 최대치 */

/* [CallBack구현] */ /* [CallBack변경] */
#define PT_CB_N						0x40U
#define PT_CB_R						0x80U

#define PT_CB_MASK_TM				0x0FU
#define PT_CB_WAIT_TM				(3000U/MAX_TICK_ILT)
/* ------------------------------------------------------------------------- */
/* Signal Data Define                                                        */
/* ------------------------------------------------------------------------- */	
#define SG_TYPE_NONE			0x00 	/** SIGNALTYPE_NONE                  */
#define SG_TYPE_BLK_SINTER		0x10 	/** 단선 연동폐색                    */
#define SG_TYPE_BLK_SAUTO		0x20 	/** 단선 자동폐색 - 기본형           */
#define SG_TYPE_BLK_SAUTO_ABS	0x21	/** 단선 자동폐색 - ABS              */
#define SG_TYPE_BLK_SAUTO_SBL	0x22 	/** 단선 자동폐색 - 단폐색           */
#define SG_TYPE_BLK_MINTER		0x30 	/** 복선 연동폐색                    */
#define SG_TYPE_BLK_MAUTO		0x40 	/** 복선 자동폐색                    */
#define SG_TYPE_BLK_MAUTO_DN	0x41 	/** 양방향 장내정방향                */ /*추가170831*/
#define SG_TYPE_BLK_MAUTO_DR	0x42 	/** 양방향 장내역방향                */ /*추가170831*/
#define SG_TYPE_BLK_M5AUTO		0x50 	/** 복선 5현시 자동 폐색             */

#define SG_TYPE_REFERENCE		0x60 	/** 참조 신호기                      */

#define SG_TYPE_ATS				0x70	/** ATS 장애표출용                   */ /* 171226 [ATS고장추가] */

#define SG_TYPE_ENTRY			0x80 	/** 장내 신호기                      */
#define SG_TYPE_EXIT			0xA0 	/** 출발 신호기                      */
#define SG_TYPE_INBLOCK			0x90 	/** 구내폐색 신호기                  */
#define SG_TYPE_SHUNT			0xB0 	/** 입환 표지                        */
#define SG_TYPE_SUHNTSG			0xB8 	/** 입환 신호기                      */
#define SG_TYPE_REPEATSG		0xC0 	/** 중계신호기(입력처리 만)          */
#define SG_TYPE_DISTANTSG		0xD0 	/** 원방신호기                       */
#define SG_TYPE_REPEATSG_CTRL	0xE0 	/** 중계신호기(출력 제어용)          */
#define SG_TYPE_CALLON_BIT		0x08 	/** 유도신호기 포함                  */
#define SG_TYPE_DIR_BIT			0x04U 	/** 신호기 진행 방향 (상행:Set)      */

#define SG_TYPE_MAINTEST_BIT	0x01 	/** 시험선용 주신호기                */


#define SG_TYPE_OUTBLOCK		0xF0	/** 역간 폐색신호기                  */
#define SG_TYPE_VALUE			0xF0
#define SG_TYPE_VALUE_TESTBIT	0xF1

#define SG_ASPECT_LIMIT_2		0x00	/** 2현시 신호기                     */
#define SG_ASPECT_LIMIT_3		0x01	/** 3현시 신호기                     */
#define SG_ASPECT_LIMIT_4		0x02	/** 4현시 신호기                     */
#define SG_ASPECT_LIMIT_5		0x03	/** 5현시 신호기                     */
#define SG_ASPECT_LIMIT_MASK	0x0F	/*0x03*/	/** 현시 Mask bit        */
/* ------------------------------------------------------------------------- */
/* Signal LMR Fail Check Value                                               */
/* ------------------------------------------------------------------------- */	
#define SGLMR_GOOD				((uint16)0x0001U)/** 현시 상태 Good                   */
#define SGLMR_CTRL_HROFF		((uint16)0x0002U)/** 현시 상태 이상으로 HR Off 제어   */
#define SGLMR_CTRL_ZROFF		((uint16)0x0004U)/** 현시 상태 이상으로 ZR Off 제어   */
#define SGLMR_FAIL_R			((uint16)0x0008U)/** 정지 현시 상태 장애              */
#define SGLMR_FAIL_Y1			((uint16)0x0010U)/** Y1 현시 상태 장애                */
#define SGLMR_FAIL_YY			((uint16)0x0020U)/** YY 현시 상태 장애                */
#define SGLMR_FAIL_YF			((uint16)0x0040U)/** Y  현시 상태 장애       */
#define SGLMR_FAIL_YGG			((uint16)0x0080U)/** YG의 G 현시 상태 장애   */
#define SGLMR_FAIL_YGY			((uint16)0x0100U)/** YG의 Y 현시 상태 장애   */
#define SGLMR_FAIL_G			((uint16)0x0200U)/** G  현시 상태 장애                */
#define SGLMR_FAIL_ZLMR			((uint16)0x0400U)/** 유도 현시 상태 장애              */
#define SGLMR_ASP_DOWN			((uint16)0x0800U)/** 하 현시 제어 상태                */
#define SGLMR_ASP_FAIL			((uint16)0x1000U)/** 현시 상태 이상                   */
#define SGLMR_FAIL_LMR			((uint16)0x2000U)/** LMR 상태 이상                    */
#define SGLMR_FAIL_ONLY_Y1		((uint16)0x4000U)/** Y1만 현시                        */
#define SGLMR_CTRL_GROFF		((uint16)0x8000U)/** 현시 상태 이상으로 GR Off 제어   */ /* [G소등GRoff처리] */
/* ------------------------------------------------------------------------- */
/* Track Data Define                                                         */
/* ------------------------------------------------------------------------- */	
#define TC_TYPE_NOTRACK			0x00	/** NO Track -- TI_NOTRACK           */
#define TC_TYPE_INTRACK			0x01	/** 구내 궤도 -- TI_INTRACK          */
#define TC_TYPE_BLOCKTRACK		0x02	/** 폐색 궤도                        */
/*#define TC_TYPE_HASPREV			0x04*//** (임시 DES에서사용후 삭제)      */
#define TC_TYPE_NODELAY			0x04	/** 해정지연처리 무시(1:무시0:지연)  */
#define TC_TYPE_HASDEPTNI		0x08	/** (임시 DES에서사용후 삭제)        */
#define TC_TYPE_ENDTRACK		0x10	/** 종단 궤도                        */
#define TC_TYPE_TNITRACK		0x20	/** 열번창 포함 궤도                 */
#define TC_TYPE_DESTTRACK		0x40	/** 도착 궤도                        */
#define TC_TYPE_ALARMTC			0x80	/** 알람처리 궤도                    */

#define MAX_SGINTC			12		/** 궤도 Table내의 포함 신호기 최대 수   */
#define MAX_TCLR_POINT		5		/** 궤도 연결정보 Table내의 포인트정보 최대 수 */
#define MAX_TCLR_LINK		12		/** 한 궤도의 연결정보 최대 수           */

#define TCS_RT_RLK		0x80U
#define TCS_RT_LLK		0x40U
#define TCS_RT_REQ		0x08U
#define TCS_RT_SET		0x04U

#define CLS_ALL				((uint8)0xAA)	/** 궤도 진로관련 상태 전체 Clear*/
#define CLS_RSRQ			((uint8)0xC1)	/** 궤도 진로쇄정/요청 상태 Clear*/
#define CLS_RTS				((uint8)0xC2)	/** 궤도 진로쇄정 방향 Clear     */
#define CLS_REQ				((uint8)0xC3)	/** 궤도 진로요청 상태 Clear     */
#define CLS_RLK				((uint8)0xC4)	/** 궤도 진로쇄정 상태 Clear     */

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
/* Route Data 내 조건 Data 최대치                                            */
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
#define ROUTE_INVOKE		(uint16)(0x8000U)  /* 진로 재취급 ? */
#define ROUTE_CANCEL		(uint16)(0x4000U)  /* 진로취소 상태 */
#define ROUTE_ONPROCESS		(uint16)(0x2000U)  /* 진로설정 중 -- 분기전환중  */
#define ROUTE_ONEMCANCEL	(uint16)(0x1000U)  /* 구분진로비상해정상태       */
#define ROUTE_DEPBLOCK		(uint16)(0x0800U)
#define ROUTE_ONRTFAIL		(uint16)(0x0400U)
#define RT_STATE_IDMASK		(uint16)(0x03FFU)

/* g_ausRouteSetInTrack[]의 bit state define */
#define ROUTE_FIRST_TC		(uint16)(0x8000U)	/** 구분해정 첫 궤도회로     */
#define ROUTE_EXIT_TC		(uint16)(0x4000U)	/** 열차출발                 */
#define ROUTE_TC_MASK		(uint16)(0x0FFFU)

#define RT_CTRLSTATE_SET	(uint8)(0x01U)		/* 진로 취급제어  상태       */
#define RT_CTRLSTATE_RECTRL	(uint8)(0x02U)   	/* 진로 재취급제어 상태      */
#define RT_CTRLSTATE_CAN	(uint8)(0x04U)		/* 진로 취소제어  상태       */
#define RT_CTRLSTATE_TTBSET	(uint8)(0x08U)		/* TTB 설정제어 상태         */
#define RT_CTRLSTATE_TTBCAN	(uint8)(0x10U)		/* TTB 취제어소 상태         */
/* ------------------------------------------------------------------------- */
/* Route Check State                                                         */
/* ------------------------------------------------------------------------- */
#define ROUTECHECK_TRACK	(uint8)(0x01U)	/** 궤도 점유 상태               */
#define ROUTECHECK_SWITCH	(uint8)(0x02U)	/** 선로전환기 이상 상태         */
#define ROUTECHECK_SIGNAL	(uint8)(0x04U)	/** 신호기 이상 상태             */
#define ROUTECHECK_ROUTE	(uint8)(0x08U)	/** 진로 이상 상태               */
#define ROUTECHECK_SWFREE	(uint8)(0x10U)	/** 선로전환기 Free              */
#define ROUTECHECK_REROUTE	(uint8)(0x20U)	/** 재취급 가능 상태             */
#define ROUTECHECK_RECONT	(uint8)(0x40U)	/** 재취급 처리                  */
#define ROUTECHECK_CONTACT	(uint8)(0x80U)	/**                              */

#define ROUTECHECK_GOOD     (uint8)(0x00U)	/** 신호 현시 가능 상태          */
#define ROUTECHECK_ENABLE   (uint8)(0x2EU)
#define ROUTECHECK_REENABLE (uint8)(0x8FU)

#define ROUTECHECK_SGOFF    ((uint8)0x97U)	/* ROUTECHECK_SWFREE+ROUTECHECK_TRACK+ROUTECHECK_SWITCH+ROUTECHECK_SIGNAL+ROUTECHECK_CONTACT */

#define RT_CHECK_ALARM_ON	((uint8)0x01U)
#define RT_CHECK_ALARM_OFF	((uint8)0x00U)
/* ------------------------------------------------------------------------- */
/* Route EG Release (구분해정 처리 중)                                       */
/* ------------------------------------------------------------------------- */
#define RT_EGRLS_SET		((uint8)0x01U)
#define RT_EGRLS_TKFREE		((uint8)0x02U)
/* ------------------------------------------------------------------------- */
/* Route Exception Data Type (진로제어 True 조건)                            */
/* ------------------------------------------------------------------------- */
#define RT_EX_GIO_OBJID_MASK	((uint16)0x00FFU) /*추가170927*/
#define RT_EX_GIOBIT_MASK		((uint16)0x0F00U) /*추가170927*/

#define RT_EX_TYPEMASK		((uint8)0x7FU)	/** 진로예외 타입ID Mask             */
#define RT_EX_SGLK_COND		((uint8)0x80U)	/** 1:신호취급불가/0:신호진행불가    */

#define RT_EX_SG_GO			(uint8)(0x01U)	/** 신호기 진행 (SG Obj ID 사용)     */
#define RT_EX_SG_STOP		(uint8)(0x02U)	/** 신호기 정지 (SG Obj ID 사용)     */
#define RT_EX_SG_LOCK		(uint8)(0x03U)	/** 신호기 쇄정 (SG Obj ID 사용)     */
#define RT_EX_SG_CONT		(uint8)(0x04U)	/** 신호기 진행제어 (SG Obj ID 사용) */
#define RT_EX_GIO_LOGIC		(uint8)(0x11U)	/** LOGIC조건의 GIO결과 (GIO ID 사용) - GIO Bit 선택 가능 */
#define RT_EX_RC_ALM_OUT_A	(uint8)(0x12U)	/** 건널목 A 제어 (GIO ID 사용)      */ /* 사용치않음 추후 삭제*/
#define RT_EX_RC_ALM_OUT_B	(uint8)(0x13U)	/** 건널목 B 제어 (GIO ID 사용)      */ /* 사용치않음 추후 삭제*/
#define RT_EX_RC_ALM_OUT_C	(uint8)(0x14U)	/** 건널목 C 제어 (GIO ID 사용)      */ /* 사용치않음 추후 삭제*/
#define RT_EX_RC_ALM_OUT_D	(uint8)(0x15U)	/** 건널목 D 제어 (GIO ID 사용)      */ /* 사용치않음 추후 삭제*/
#define RT_EX_APPROACH		(uint8)(0x12U)	/** 진로별 접근쇄정 다중조건 (GIO ID 사용) - GIO Bit 선택 가능 */ /*추가170927*/
#define RT_EX_NO_RT_RELEASE	(uint8)(0x13U)	/** 진로취소 불가능 조건 (GIO ID 사용) - GIO Bit 선택 가능 */ /*추가170927*/
#define RT_EX_OPT1			(uint8)(0x14U)	/** Spare 1                          */
#define RT_EX_OPT2			(uint8)(0x15U)	/** Spare 2                          */
#define RT_EX_RT_LOCK		(uint8)(0x21U)	/** 진로 쇄정 (RT Obj ID 사용)       */
#define RT_EX_RT_UNLOCK		(uint8)(0x22U)	/** 진로 해정 (RT Obj ID 사용)       */
#define RT_EX_RT_CONT		(uint8)(0x23U)	/** 진로 제어 (RT Obj ID 사용)       */
#define RT_EX_RT_LKDEST_EXC	(uint8)(0x24U)	/** 도착궤도타진로쇄정  (RT ID 사용) */
#define RT_EX_RT_LKTC_EXC	(uint8)(0x25U)	/** 진로내궤도타진로쇄정(RT ID 사용) */
#define RT_EX_TC_RELEASE	(uint8)(0x26U)	/** 궤도 진로해정(TC ID 사용)        */
#define RT_EX_BSG_DIR_STOP	(uint8)(0x31U)	/** 폐색장내 정지 (SG Obj ID 사용)   */
#define RT_EX_RT_DEST_OUT	(uint8)(0x41U)	/** 진로선별(착점)출력  (GIO(0x06) ID 사용)*/
#define RT_EX_RT_DEST_CLOFF	(uint8)(0x42U)	/** 진로선별 상충쇄정 Off  (GIO(0x06) ID 사용)*/
#define RT_EX_RT_LOCK_OUT	(uint8)(0x43U)	/** 진로쇄정출력  (GIO(0x07) ID 사용)*/
#define RT_EX_RT_START_LO	(uint8)(0x44U)	/** 진로선별(시발)좌출력  (GIO(0x08) ID 사용)*/
#define RT_EX_RT_START_RO	(uint8)(0x45U)	/** 진로선별(시발)우출력  (GIO(0x08) ID 사용)*/
#define RT_EX_RT_START_CO	(uint8)(0x46U)	/** 진로선별(시발)정출력  (GIO(0x08) ID 사용)*/
#define RT_EX_ASP_MOD_YY	(uint8)(0x51U)	/** 최대현시 YY (RT Obj ID 사용) */ /*추가170831*/
#define RT_EX_ASP_MOD_Y		(uint8)(0x52U)	/** 최대현시 Y  (RT Obj ID 사용) */ /*추가170831*/
#define RT_EX_ASP_MOD_YG	(uint8)(0x53U)	/** 최대현시 YG (RT Obj ID 사용) */ /*추가170831*/
#define RT_EX_ASP_MOD_G		(uint8)(0x54U)	/** 최대현시 G  (RT Obj ID 사용) */ /*추가170831*/
/* ------------------------------------------------------------------------- */
/* 선로전환기 제어 상태 정의                                                 */
/* ------------------------------------------------------------------------- */
#define POINT_CHECK_CTRL_N	(uint8)(0x01U)
#define POINT_CHECK_CTRL_R	(uint8)(0x02U)
#define ROUTE_CTRL_N		(uint8)(0x04U)
#define ROUTE_CTRL_R		(uint8)(0x08U)
#define POINT_WRMOVE_FAIL	(uint8)(0x40U)
#define POINT_KRMOVE_FAIL	(uint8)(0x80U)
/* ------------------------------------------------------------------------- */
/* 폐색 출력 차단 타이머                                                     */
/* ------------------------------------------------------------------------- */
#define BSG_OUT_TMR			3
/* ------------------------------------------------------------------------- */
/* 선로전환기 히터 제어 입력만료 타이머                                      */
/* ------------------------------------------------------------------------- */
#define PHT_TMR				25U
#define PPW_TMR				13U
/* ------------------------------------------------------------------------- */
/* Task 관리 Define                                                          */
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
#define TASK_COMMDRV	9U	/* [TASK추가] uart 제어 driver task */
#define TASK_AST		10U
/* ------------------------------------------------------------------------- */
/* TaskInfo Bit Pos State                                                    */
/* ------------------------------------------------------------------------- */
#define TINFO_USED		0x01U

#define TINFO_CTC_USED	0x04U			/** CTC: CTC 존재 역 Flag            */

#define TINFO_RC_EES	0x02U			/** RC: 전기기술지원시스템 사용      */
#define TINFO_RC_OPC	0x04U			/** RC: OPC확장으로 RC 제어          */
#define TINFO_RC_LOCAL	0x08U			/** RC: RC모역 제어(LOCAL취급)       */

/* 시리얼 통신 속도 정의 default 19200 */
#define TINFO_BAUD_9600		0x10U		/** baud 9600                        */
#define TINFO_BAUD_38400	0x20U		/** baud 38400                       */
#define TINFO_BAUD_57600	0x40U		/** baud 57600                       */
#define TINFO_BAUD_115200	0x80U		/** baud 115200                      */


/*#define TINFO_RC_PORTNO	0xF0U*/		/** RC: 전기기술시스템 용 Port No.   */
/*#define TINFO_CTC_VER	0xF0U*/			/** CTC: 표준화 버전 No.             */

#define TINFO_ILT_POINTMISMATCH_DELAY_MASK	0x30U	/** 상위 2bit (0 ~ 3) delay 가능 */
/* ------------------------------------------------------------------------- */
/* IO Module 관련 Define (KRSEIS 및 DB 기준)                                 */
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
/* IO Module 관련 Define (ZEST 내부 사용)                                    */
/* ------------------------------------------------------------------------- */
#define MAX_IOS						15U	/** ZEST IOS 최대수                  */

#define REAL_IOM_STATE_BUFFER_SIZE	30U	/** ZEST IO MODULE 최대수 
											IOS(15) * 16bit = 30Byte         */
#define REAL_MAX_IO_PORT			16U	/** ZEST IO 모듈당 port 수           */
#define REAL_MODULE_PER_IOS			16U	/** ZEST IOS 당 모듈 수              */

/* ZEST 최대 IO모듈 수 240 */
#define REAL_MAX_IO_MODULE		(MAX_IOS * REAL_MODULE_PER_IOS)	
/* ZEST 최대 port 수 3,840 */
#define REAL_MAX_ALL_IO_PORT	(REAL_MAX_IO_MODULE * REAL_MAX_IO_PORT)	

#define REAL_SIZE_INOUT_BUFFER		480U	/** 전체IO bit에 대한 byte size 3840bit */
#define REAL_SIZE_IOPORT_FAIL_DATA	480U	/** 전체IO bit에 대한 byte size 3840bit */

#define REAL_SIZE_IODATA_PER_IOS	32U	/** IOS당 전체IO bit에 대한 byte 256bit */

#define BYTE_PER_IOMD	(REAL_MAX_IO_PORT/8)	/** IO모듈 전체 IO bit에 대한 byte size 16bit */

#define SYS_INOUT_MISMATCH_CNT		5U
/* ------------------------------------------------------------------------- */
/* IO Type 관련 Define                                                       */
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
#define IO_T_COMMON_EGRUNSWLOCAL	0x01		/** I  비상 Run Switch(Local)*/
#define IO_T_COMMON_EGRUNSWRC		0x02		/** I  비상 Run Switch(RC)   */
#define IO_T_COMMON_EGCTCSWLO		0x03		/** I  비상 CTC Switch(Local)*/
#define IO_T_COMMON_EGCTCSWRC		0x04		/** I  비상 CTC Switch(RC)   */
#define IO_T_COMMON_EGLOSW			0x05		/** I  비상 Local Switch     */
#define IO_T_COMMON_EGRCSW			0x06		/** I  비상 RC Switch        */
#define IO_T_COMMON_VRDI1			0x07		/** I  VRDI_1                */
#define IO_T_COMMON_VRDI2			0x08		/** I  VRDI_2                */
#define IO_T_COMMON_ACTIVE1I		0x09		/** I  Active_1              */
#define IO_T_COMMON_ACTIVE2I		0x0A		/** I  Active_2              */
#define IO_T_COMMON_N1				0x0B		/** I  N1                    */
#define IO_T_COMMON_N2				0x0C		/** I  N2                    */
#define IO_T_COMMON_X1				0x0D		/** I  X1                    */
#define IO_T_COMMON_X2				0x0E		/** I  X2                    */
#define IO_T_COMMON_UPS				0x0F		/** I  UPS                   */
#define IO_T_COMMON_AVR1			0x10		/** I  AVR1(정류기)          */
#define IO_T_COMMON_AVR2			0x11		/** I  AVR2(정류기)          */
#define IO_T_COMMON_BAT				0x12		/** I  Battery               */
#define IO_T_COMMON_FUSE			0x13		/** I  Field Fuse            */
#define IO_T_COMMON_EISFUSE1		0x14		/** I  EIS Fuse1             */
#define IO_T_COMMON_EISFUSE2		0x15		/** I  EIS Fuse2             */
#define IO_T_COMMON_SWPWN			0x16		/** I  Point PW N            */
#define IO_T_COMMON_SWPWS			0x17		/** I  Point PW S            */
#define IO_T_COMMON_SWHETN_I		0x18		/** I  Point Heat N 입력     */
#define IO_T_COMMON_SWHETS_I		0x19		/** I  Point Heat S 입력     */
#define IO_T_COMMON_SHPWOFFI		0x1A		/** I  Shunt PW Off 입력     */
#define IO_T_COMMON_UPSAC			0x1B		/** I  UPS AC Fail           */
#define IO_T_COMMON_EXTCARD			0x1C		/** I  EXT Card Fail         */
#define IO_T_COMMON_SWHETFAIL_N		0x1D		/** I  Point Heat Fail N     */
#define IO_T_COMMON_SWHETFAIL_S		0x1E		/** I  Point Heat Fail S     */
#define IO_T_COMMON_KEYLOCK			0x1F		/** I  신호기계실 Key Lock   */
#define IO_T_COMMON_SYSRECOVERY		0x20		/** I  EIS 정전복구해제 입력 */ /*위치: SMEM / TS_SMEM_SYSSTAT_SYSTEMSTATE / bSysRecovery */
#define IO_T_COMMON_POINTPWI_N		0x21		/** I  Point N PW 제어 입력  */
#define IO_T_COMMON_POINTPWI_S		0x22		/** I  Point S PW 제어 입력  */

/*#define IO_T_COMMON_VCR_A			0x30		  * I  VCR A 입력              */
/*#define IO_T_COMMON_VCR_B			0x31		  * I  VCR B 입력              */
#define IO_T_COMMON_VCR_1A			0x30		/** I  VCR 1계 A 입력        */ /* [VCR추가수정] 171127 Define 수정 */
#define IO_T_COMMON_VCR_1B			0x31		/** I  VCR 1계 B 입력        */ /* [VCR추가수정] 171127 Define 수정 */
#define IO_T_COMMON_VCR_2A			0x32		/** I  VCR 2계 A 입력        */ /* [VCR추가] 171127 IO Type 추가 */
#define IO_T_COMMON_VCR_2B			0x33		/** I  VCR 2계 B 입력        */ /* [VCR추가] 171127 IO Type 추가 */

#define IO_T_COMMON_VRDO1			0x81		/** O  VRDO1                 */
#define IO_T_COMMON_VRDO2			0x82		/** O  VRDO2                 */
#define IO_T_COMMON_ACTIVEO1		0x83		/** O  ACTIVEO1              */
#define IO_T_COMMON_ACTIVEO2		0x83		/** O  ACTIVEO2              */
#define IO_T_COMMON_SWHETN_O		0x84		/** O  Point Heat N 출력     */
#define IO_T_COMMON_SWHETS_O		0x85		/** O  Point Heat S 출력     */
#define IO_T_COMMON_SHPWOFFO		0x86		/** O  Shunt PW Off 출력     */
#define IO_T_COMMON_POINTPWO_N		0x87		/** O  Point N PW 제어 출력  */
#define IO_T_COMMON_POINTPWO_S		0x88		/** O  Point S PW 제어 출력  */
/* ---------------------------- */
/* IO Track Type                */
/* ---------------------------- */
#define IO_T_TRACK_OCCUPY			0x02		/** I  Track Occupy          */
#define IO_T_TRACK_TLS				0x07		/** O  신호 좌 쇄정          */
#define IO_T_TRACK_TRS				0x08		/** O  신호 우 쇄정          */
#define IO_T_TRACK_RTL				0x0A		/** O  진로 좌 쇄정          */
#define IO_T_TRACK_RTR				0x0B		/** O  진로 우 쇄정          */
#define IO_T_TRACK_OCL				0x0C		/** O  좌 점유               */
#define IO_T_TRACK_OCR				0x0D		/** O  우 점유               */
#define IO_T_TRACK_CFLTLK			0x0E		/** I  상충쇄정              */
#define IO_T_TRACK_AXR				0x0F		/** O  엑셀카운트리셋 출력   */ /* 171220 추가 [엑셀카운터리셋] */
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
#define IO_T_SG_ZLMR				0x11	/** I  ZLMR(유도신호기 현시상태) */ /*171220 [ZLMR분리추가]*/
#define IO_T_SG_MRTLMR				0x17	/** I  진로선별 주Lamp(MRTLMR)   */
#define IO_T_SG_ARTLMR				0x18	/** I  진로선별 보조Lamp(ARTLMR) */
#define IO_T_SG_YRO					0x09	/** O  YRO                       */
#define IO_T_SG_GRO					0x0A	/** O  GRO                       */
#define IO_T_SG_HRO					0x0B	/** O  HRO                       */
#define IO_T_SG_URO					0x0C	/** O  URO                       */
#define IO_T_SG_MRFAIL				0x0D	/** I  진로표시기 고장상태       */ /*171220 [MRFAIL추가]*/
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
#define IO_T_BSG_RREH   			0x12			/** I  RREH  연동폐색    */
#define IO_T_BSG_OREH   			0x13			/** I  OREH  연동폐색    */
#define IO_T_BSG_AREH   			0x19			/** I  AREH  연동폐색    */
#define IO_T_BSG_CREH   			0x1C			/** I  CREH  연동폐색    */
#define IO_T_BSG_RRO				0x01			/** O  RRO	             */
#define IO_T_BSG_BRO				0x02			/** O  BRO	             */
#define IO_T_BSG_CNRO   			0x06			/** O  CNRO	             */
#define IO_T_BSG_BLK_ARO			0x11			/** O  BLK_ARO  연동폐색 */
#define IO_T_BSG_BLK_CRO			0x14			/** O  BLK_CRO  연동폐색 */
#define IO_T_BSG_BLK_RRO			0x1A			/** O  BLK_RRO  연동폐색 */
#define IO_T_BSG_BLK_ORO			0x1B			/** O  BLK_ORO  연동폐색 */
#define IO_T_BSG_GRI 				0x1E			/** I  복선폐색 GR       */
#define IO_T_BSG_YRI				0x1F			/** I  복선폐색 YR       */
#define IO_T_BSG_Y1RI				0x20			/** I  복선폐색 Y1R      */
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
#define IO_T_GIO_RC					0x01	/** I  건널목 상태               */
#define IO_T_GIO_RC_OUTA			0x02	/** O  건널목 출력 A             */
#define IO_T_GIO_RC_OUTB			0x03	/** O  건널목 출력 B             */
#define IO_T_GIO_RC_OUTC			0x04	/** O  건널목 출력 C             */
#define IO_T_GIO_RC_INA				0x06	/** I  건널목 입력 A             */
#define IO_T_GIO_RC_INB				0x07	/** I  건널목 입력 B             */
#define IO_T_GIO_RC_INC				0x08	/** I  건널목 입력 C             */
#define IO_T_GIO_OB_STATE			0x11	/** I  지장물검지장치 상태       */
#define IO_T_GIO_OB_ACCEPT			0x12	/** I  지장물검지장치 확인조작   */

/*#define IO_T_GIO_EXTREC1			0x21*/	/** I  1계 확장 정류기 상태      */
/*#define IO_T_GIO_EXTREC2			0x22*/	/** I  2계 확장 정류기 상태      */
/* [확장FUSE&REC재정의] 위 삭제 후 확장 정류기 랙별 1/2계 구분하여 정의함 */
#define IO_T_GIO_EXTREC1			0x20	/** I  1계 IOS 1~8  정류기 상태  */
#define IO_T_GIO_EXTREC2			0x21	/** I  1계 IOS 9~16 정류기 상태  */
#define IO_T_GIO_EXTREC3			0x22	/** I  2계 IOS 1~8  정류기 상태  */
#define IO_T_GIO_EXTREC4			0x23	/** I  2계 IOS 9~16 정류기 상태  */
#define IO_T_GIO_EXTREC5			0x24	/** I  Spare                     */

#define IO_T_GIO_IS1_S				0x41	/** I  절연구간예고장치 1계 상태 */
#define IO_T_GIO_IS1_O				0x42	/** I  절연구간예고장치 1계 운용 */
#define IO_T_GIO_IS2_S				0x44	/** I  절연구간예고장치 2계 상태 */
#define IO_T_GIO_IS2_O				0x48	/** I  절연구간예고장치 2계 운용 */

/*#define IO_T_GIO_EXTFUSE1			0x51*/	/** I  1계 확장 FUSE 상태        */
/*#define IO_T_GIO_EXTFUSE2			0x52*/	/** I  2계 확장 FUSE 상태        */
/* [확장FUSE&REC재정의] 위 삭제 후 확장 FUSE 랙별 1/2계 구분하여 정의함 */
#define IO_T_GIO_EXTFUSE1			0x50	/** I  1계 IOS 1~8  FUSE 상태    */
#define IO_T_GIO_EXTFUSE2			0x51	/** I  1계 IOS 9~16 FUSE 상태    */
#define IO_T_GIO_EXTFUSE3			0x52	/** I  2계 IOS 1~8  FUSE 상태    */
#define IO_T_GIO_EXTFUSE4			0x53	/** I  2계 IOS 9~16 FUSE 상태    */
#define IO_T_GIO_EXTFUSE5			0x54	/** I  Spare                     */

#define IO_T_GIO_RTDEST_OUT			0x61	/** O  진로선별 출력             */
#define IO_T_GIO_RTDEST_IN			0x62	/** I  진로선별 출력의 Feedback  */
#define IO_T_GIO_RTDEST_CFLKI		0x63	/** I  착선상충쇄정 입력         */
#define IO_T_GIO_RTLK_OUT			0x71	/** O  진로쇄정 출력             */
#define IO_T_GIO_RTLK_IN			0x72	/** I  진로쇄정 출력의 Feedback  */
#define IO_T_GIO_RTLK_CFLKI			0x73	/** I  상대 진로쇄정 입력        */
#define IO_T_GIO_RTSTART_LDIRO		0x81	/** O  좌방향 출력               */
#define IO_T_GIO_RTSTART_LDIRI		0x82	/** I  좌방향 출력의 Feedback    */
#define IO_T_GIO_RTSTART_RDIRO		0x83	/** O  우방향 출력               */
#define IO_T_GIO_RTSTART_RDIRI		0x84	/** I  우방향 출력의 Feedback    */
#define IO_T_GIO_RTSTART_CDIRO		0x85	/** O  정방향 출력               */
#define IO_T_GIO_RTSTART_CDIRI		0x86	/** I  정방향 출력의 Feedback    */
#define IO_T_GIO_EX2PHT_N_O			0x91	/** O  확장2 북히터 제어 출력    */
#define IO_T_GIO_EX2PHT_N_I			0x92	/** I  확장2 북히터 제어 입력    */
#define IO_T_GIO_EX2PHT_N_S			0x93	/** I  확장2 북히터 동작 상태    */
#define IO_T_GIO_EX2PHT_S_O			0xA1	/** O  확장2 남히터 제어 출력    */
#define IO_T_GIO_EX2PHT_S_I			0xA2	/** I  확장2 남히터 제어 입력    */
#define IO_T_GIO_EX2PHT_S_S			0xA3	/** I  확장2 남히터 동작 상태    */
#define IO_T_GIO_EX3PHT_N_O			0xB1	/** O  확장3 북히터 제어 출력    */
#define IO_T_GIO_EX3PHT_N_I			0xB2	/** I  확장3 북히터 제어 입력    */
#define IO_T_GIO_EX3PHT_N_S			0xB3	/** I  확장3 북히터 동작 상태    */
#define IO_T_GIO_EX3PHT_S_O			0xC1	/** O  확장3 남히터 제어 출력    */
#define IO_T_GIO_EX3PHT_S_I			0xC2	/** I  확장3 남히터 제어 입력    */
#define IO_T_GIO_EX3PHT_S_S			0xC3	/** I  확장3 남히터 동작 상태    */
#define IO_T_GIO_EXGOUT_1			0xD0	/** O  확장 출력 1               */
#define IO_T_GIO_EXGOUT_2			0xD1	/** O  확장 출력 2               */
#define IO_T_GIO_EXGOUT_3			0xD2	/** O  확장 출력 3               */
#define IO_T_GIO_EXGOUT_4			0xD3	/** O  확장 출력 4               */
#define IO_T_GIO_EXGOUT_5			0xD4	/** O  확장 출력 5               */
#define IO_T_GIO_EXGOUT_6			0xD5	/** O  확장 출력 6               */
#define IO_T_GIO_EXGOUT_7			0xD6	/** O  확장 출력 7               */
#define IO_T_GIO_EXGOUT_8			0xD7	/** O  확장 출력 8               */
#define IO_T_GIO_EXGIN_1			0xD8	/** I  확장 입력 1               */
#define IO_T_GIO_EXGIN_2			0xD9	/** I  확장 입력 2               */
#define IO_T_GIO_EXGIN_3			0xDA	/** I  확장 입력 3               */
#define IO_T_GIO_EXGIN_4			0xDB	/** I  확장 입력 4               */
#define IO_T_GIO_EXGIN_5			0xDC	/** I  확장 입력 5               */
#define IO_T_GIO_EXGIN_6			0xDD	/** I  확장 입력 6               */
#define IO_T_GIO_EXGIN_7			0xDE	/** I  확장 입력 7               */
#define IO_T_GIO_EXGIN_8			0xDF	/** I  확장 입력 8               */

#define IO_T_GIO_ETCIN_1			0xE0	/** I  기타표시용 입력 1         */ /*추가171227 [GIO기타표시추가]*/
#define IO_T_GIO_ETCIN_2			0xE1	/** I  기타표시용 입력 2         */
#define IO_T_GIO_ETCIN_3			0xE2	/** I  기타표시용 입력 3         */
#define IO_T_GIO_ETCIN_4			0xE3	/** I  기타표시용 입력 4         */
#define IO_T_GIO_ETCIN_5			0xE4	/** I  기타표시용 입력 5         */
#define IO_T_GIO_ETCIN_6			0xE5	/** I  기타표시용 입력 6         */
#define IO_T_GIO_ETCIN_7			0xE6	/** I  기타표시용 입력 7         */
#define IO_T_GIO_ETCIN_8			0xE7	/** I  기타표시용 입력 8         */

/*#define IO_T_GIO_ATSFAIL_Y			0xEE	  * I  ATS Y 고장                   //추가171220 [ATS고장추가] GIO Type = GIO_TYPE_ATS_FAIL*/
/*#define IO_T_GIO_ATSFAIL_G			0xEF	  * I  ATS G 고장                   //추가171220 [ATS고장추가] GIO Type = GIO_TYPE_ATS_FAIL*/

#define IO_T_GIO_EXC_INOUT_I1		0xF0	/** I  일반입출력 입력 1         */
#define IO_T_GIO_EXC_INOUT_I2		0xF1	/** I  일반입출력 입력 2         */
#define IO_T_GIO_EXC_INOUT_I3		0xF2	/** I  일반입출력 입력 3         */
#define IO_T_GIO_EXC_INOUT_I4		0xF3	/** I  일반입출력 입력 4         */
#define IO_T_GIO_EXC_INOUT_I5		0xF4	/** I  일반입출력 입력 5         */
#define IO_T_GIO_EXC_INOUT_I6		0xF5	/** I  일반입출력 입력 6         */
#define IO_T_GIO_EXC_INOUT_O1		0xF6	/** O  일반입출력 출력 1         */
#define IO_T_GIO_EXC_INOUT_O2		0xF7	/** O  일반입출력 출력 2         */
#define IO_T_GIO_DRAG_NORNAL		0xF8	/** I  끌림검지장치   상태       */ /*추가170831*/
#define IO_T_GIO_DRAG_SWITCH		0xF9	/** I  끌림검지장치 확인조작     */

/* ------------------------------------------------------------------------- */
/* General IO Type Define                                                    */
/* ------------------------------------------------------------------------- */
#define GIO_TYPE_RC			((uint8)0x01)	/* 건널목                        */
#define GIO_TYPE_OB			((uint8)0x02)	/* 지장물 검지장치               */
#define GIO_TYPE_REC		((uint8)0x03)	/* 확장 정류기                   */
#define GIO_TYPE_IS			((uint8)0x04)	/* 절연구간예고장치              */
#define GIO_TYPE_FUSE		((uint8)0x05)	/* 확장 FUSE                     */
#define GIO_TYPE_RTDEST		((uint8)0x06)	/* 진로선별(도착점기준)          */
#define GIO_TYPE_RTLOCK		((uint8)0x07)	/* 진로쇄정 입/출력(진로기준)    */
#define GIO_TYPE_RTSTART	((uint8)0x08)	/* 진로선별(시발점기준)          */
#define GIO_TYPE_PHEAT_N2	((uint8)0x09)	/* 선로전환기 북히터2 제어 확장  */
#define GIO_TYPE_PHEAT_S2	((uint8)0x0A)	/* 선로전환기 남히터2 제어 확장  */
#define GIO_TYPE_PHEAT_N3	((uint8)0x0B)	/* 선로전환기 북히터3 제어 확장  */
#define GIO_TYPE_PHEAT_S3	((uint8)0x0C)	/* 선로전환기 남히터3 제어 확장  */
#define GIO_TYPE_GOUT		((uint8)0x0D)	/* 확장 출력                     */
#define GIO_TYPE_GIN		((uint8)0x0E)	/* 확장 입력                     */
#define GIO_TYPE_EXC_INOUT	((uint8)0x0F)	/* 예외 입출력                   */
#define GIO_TYPE_DRAG		((uint8)0x10)	/* 끌림 검지 장치                */ /*추가170831*/
#define GIO_TYPE_ETC		((uint8)0x11)	/* 기타표시용                    */ /*추가171227 [GIO기타표시추가]*/
/*#define GIO_TYPE_ATS_FAIL	((uint8)0x11)	   ATS 고장정보                     //추가171220 [ATS고장추가]*/
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
/* GIO Type별 bit State Define (SMEM상의 Bit 위치)                           */
/* ========================================================================= */
/* GIO_TYPE_RC	(uint8)0x01	건널목                                           */
/* ------------------------------------------------------------------------- */
#define GIOBIT_RC_S					0x01	/** I  건널목 상태               */ 
#define GIOBIT_RC_OUTA				0x80    /** O  건널목 출력 A             */
#define GIOBIT_RC_OUTB				0x40    /** O  건널목 출력 B             */
#define GIOBIT_RC_OUTC				0x20    /** O  건널목 출력 C             */
#define GIOBIT_RC_INA				0x08    /** I  건널목 입력 A             */
#define GIOBIT_RC_INB				0x04    /** I  건널목 입력 B             */
#define GIOBIT_RC_INC				0x02    /** I  건널목 입력 C             */

#define GIOBIT_LOGIC_RESULT			0x80	/** Logic 식의 결과 bit          */
/* ------------------------------------------------------------------------- */
/* GIO_TYPE_OB	(BYTE)0x02	지장물검지장치                                   */
/* ------------------------------------------------------------------------- */
#define GIOBIT_OB_GOOD				0x01	/** I  지장물검지장치 상태       */
#define GIOBIT_OB_ACPT				0x02    /** I  지장물검지장치 확인조작   */
/* ------------------------------------------------------------------------- */
/* GIO_TYPE_REC	(BYTE)0x03	확장 정류기 (GIO idx 1~5 고정)                   */
/* ------------------------------------------------------------------------- */
/*#define GIOBIT_REC_1				0x01*/    /** I  1계 확장 정류기 상태      */
/*#define GIOBIT_REC_2				0x02*/    /** I  2계 확장 정류기 상태      */

/* [확장FUSE&REC재정의] 위의 이전 정의는 고정된 GIO idx1이 Rack2 idx5가 Rack6이였으나 
   ZEST 확장랙이 최대 15개이므로 이를 다음과 같이 변경함 */

/* GIO idx 1, 2는 ZEST EI 1계의 확장 정류기 용으로 사용
   GIO idx 3, 4는 ZEST EI 2계의 확장 정류기 용으로 사용,
   GIO idx 5는 Spare 
   총 16bit를 1/2계 공용으로 다음과 같이 정의하여 사용함. */
/* GIO idx 1(1계), 3(2계)의 Bit 정의 : Rack 1~8 까지 사용 */
/* GIO idx 2(1계), 4(2계)의 Bit 정의 : Rack 9~16 까지 사용 */
#define GIOBIT_REC_1			0x01    /** I 1/2계 1 or 9  rack 정류기 상태 */
#define GIOBIT_REC_2			0x02    /** I 1/2계 2 or 10 rack 정류기 상태 */
#define GIOBIT_REC_3			0x04    /** I 1/2계 3 or 11 rack 정류기 상태 */
#define GIOBIT_REC_4			0x08    /** I 1/2계 4 or 12 rack 정류기 상태 */
#define GIOBIT_REC_5			0x10    /** I 1/2계 5 or 13 rack 정류기 상태 */
#define GIOBIT_REC_6			0x20    /** I 1/2계 6 or 14 rack 정류기 상태 */
#define GIOBIT_REC_7			0x40    /** I 1/2계 7 or 15 rack 정류기 상태 */
#define GIOBIT_REC_8			0x80    /** I 1/2계 8 or 16 rack 정류기 상태 */

/* ------------------------------------------------------------------------- */
/* GIO_TYPE_IS	(BYTE)0x04	절연구간예고장치                                 */
/* ------------------------------------------------------------------------- */
#define GIOBIT_IS1_GOOD				0x01U	/** I  절연구간예고장치 1계 상태 */
#define GIOBIT_IS1_OP				0x02U   /** I  절연구간예고장치 1계 운용 */
#define GIOBIT_IS2_GOOD				0x04U   /** I  절연구간예고장치 2계 상태 */
#define GIOBIT_IS2_OP				0x08U   /** I  절연구간예고장치 2계 운용 */
/* ------------------------------------------------------------------------- */
/* GIO_TYPE_FUSE	(BYTE)0x05	확장 FUSE (GIO idx 6~10 고정)                */
/* ------------------------------------------------------------------------- */
/*#define GIOBIT_FUSE_1				0x01U*/ /** I  1계 확장 FUSE 상태        */
/*#define GIOBIT_FUSE_2				0x02U*/ /** I  2계 확장 FUSE 상태        */

/* [확장FUSE&REC재정의] 위의 이전 정의는 고정된 GIO idx6이 Rack2 idx10이 Rack6이였으나
   ZEST 확장랙이 최대 15개이므로 이를 다음과 같이 변경함 */

/* GIO idx 6, 7은 ZEST EI 1계의 확장 FUSE 용으로 사용
   GIO idx 8, 9는 ZEST EI 2계의 확장 FUSE 용으로 사용,
   GIO idx 10은 Spare 
   총 16bit를 1/2계 공용으로 다음과 같이 정의하여 사용함. */
/* GIO idx 6(1계), 8(2계)의 Bit 정의 : Rack 1~8 까지 사용 */
/* GIO idx 7(1계), 9(2계)의 Bit 정의 : Rack 9~16 까지 사용 */
#define GIOBIT_FUSE_1			0x01    /** I 1/2계 1 or 9  rack FUSE 상태   */
#define GIOBIT_FUSE_2			0x02    /** I 1/2계 2 or 10 rack FUSE 상태   */
#define GIOBIT_FUSE_3			0x04    /** I 1/2계 3 or 11 rack FUSE 상태   */
#define GIOBIT_FUSE_4			0x08    /** I 1/2계 4 or 12 rack FUSE 상태   */
#define GIOBIT_FUSE_5			0x10    /** I 1/2계 5 or 13 rack FUSE 상태   */
#define GIOBIT_FUSE_6			0x20    /** I 1/2계 6 or 14 rack FUSE 상태   */
#define GIOBIT_FUSE_7			0x40    /** I 1/2계 7 or 15 rack FUSE 상태   */
#define GIOBIT_FUSE_8			0x80    /** I 1/2계 8 or 16 rack FUSE 상태   */
/* ------------------------------------------------------------------------- */
/* GIO_TYPE_RTDEST	(BYTE)0x06	진로선별                                     */
/* ------------------------------------------------------------------------- */
#define GIOBIT_RTD_OUT				0x01U	/** O  진로선별 출력             */
#define GIOBIT_RTD_IN				0x02U	/** I  진로선별 출력의 Feedback  */
#define GIOBIT_RTD_CFLKI			0x04U	/** I  착선상충쇄정 입력         */
/* ------------------------------------------------------------------------- */
/* GIO_TYPE_RTLOCK	(BYTE)0x07	진로쇄정 입/출력(진로기준)                   */
/* ------------------------------------------------------------------------- */
#define GIOBIT_RTLK_OUT				0x01U	/** O  진로쇄정 출력             */
#define GIOBIT_RTLK_IN				0x02U	/** I  진로쇄정 출력의 Feedback  */
#define GIOBIT_RTLK_CFLKI			0x04U	/** I  상대 진로쇄정 입력        */
/* ------------------------------------------------------------------------- */
/* GIO_TYPE_RTSTART	(BYTE)0x08	진로선별(시발점기준)                         */
/* ------------------------------------------------------------------------- */
#define GIOBIT_RTS_LDIRO			0x01U	/** O  좌방향 출력               */
#define GIOBIT_RTS_LDIRI			0x02U	/** I  좌방향 출력의 Feedback    */
#define GIOBIT_RTS_RDIRO			0x04U	/** O  우방향 출력               */
#define GIOBIT_RTS_RDIRI			0x08U	/** I  우방향 출력의 Feedback    */
#define GIOBIT_RTS_CDIRO			0x10U	/** O  정방향 출력               */
#define GIOBIT_RTS_CDIRI			0x20U	/** I  정방향 출력의 Feedback    */
/* ------------------------------------------------------------------------- */
/* GIO_TYPE_PHEAT2/3(BYTE)0x09/0x0A/0x0B/0x0C  히터2,3 제어 및 표시 확장     */
/* ------------------------------------------------------------------------- */
#define GIOBIT_EXPHT_O				0x01U	/** O  확장 히터 제어 출력       */
#define GIOBIT_EXPHT_I				0x02U	/** I  확장 히터 제어 입력       */
#define GIOBIT_EXPHT_S				0x04U	/** I  확장 히터 동작 상태       */

/* ------------------------------------------------------------------------- */
/* GIO_TYPE_EXINOUT (BYTE)0x0F 예외적인 입/출력 처리                         */
/* ------------------------------------------------------------------------- */
#define GIOBIT_EXC_INOUT_I1			0x01U	/** I  일반입출력 입력 1         */
#define GIOBIT_EXC_INOUT_I2			0x02U	/** I  일반입출력 입력 2         */
#define GIOBIT_EXC_INOUT_I3			0x04U	/** I  일반입출력 입력 3         */
#define GIOBIT_EXC_INOUT_I4			0x08U	/** I  일반입출력 입력 4         */
#define GIOBIT_EXC_INOUT_I5			0x10U	/** I  일반입출력 입력 5         */
#define GIOBIT_EXC_INOUT_I6			0x20U	/** I  일반입출력 입력 6         */
#define GIOBIT_EXC_INOUT_O1			0x40U	/** O  일반입출력 출력 1         */
#define GIOBIT_EXC_INOUT_O2			0x80U	/** O  일반입출력 출력 2         */
/* ------------------------------------------------------------------------- */
/* GIO_TYPE_DRAG	(BYTE)0x10	끌림검지장치                                 */ /*추가170831*/
/* ------------------------------------------------------------------------- */
#define GIOBIT_DRAG_NORMAL			0x01	/** I  끌림검지장치 정상(1)/경보 */
#define GIOBIT_DRAG_SWITCH			0x02    /** I  끌림검지장치 확인         */
/* ------------------------------------------------------------------------- */
/* GIO_TYPE_ETC (BYTE)0x11	GIO 기타표시용                                   */ /*추가171227 [GIO기타표시추가]*/
/* ------------------------------------------------------------------------- */
#define GIOBIT_ETC_BIT1				0x01    /** I  기타표시용 1              */
#define GIOBIT_ETC_BIT2				0x02    /** I  기타표시용 2              */
#define GIOBIT_ETC_BIT3				0x04    /** I  기타표시용 3              */
#define GIOBIT_ETC_BIT4				0x08    /** I  기타표시용 4              */
#define GIOBIT_ETC_BIT5				0x10    /** I  기타표시용 5              */
#define GIOBIT_ETC_BIT6				0x20    /** I  기타표시용 6              */
#define GIOBIT_ETC_BIT7				0x40    /** I  기타표시용 7              */
#define GIOBIT_ETC_BIT8				0x80    /** I  기타표시용 8              */
/* ------------------------------------------------------------------------- */
/* GIO_TYPE_ATS_FAIL (BYTE)0x11	ATS 고장정보                                 */
/* ------------------------------------------------------------------------- */
/*#define GIOBIT_ATS_YFAILL			0x01	  * I  ATS Y 고장                   // 추가171220[ATS고장추가]*/
/*#define GIOBIT_ATS_GFAILL			0x02      * I  ATS G 고장                   // 추가171220[ATS고장추가]*/

/* ------------------------------------------------------------------------- */
/* 선로전환기 제어 타이머 관련                                               */
/* ------------------------------------------------------------------------- */
#define POINT_TIMER_SET			((uint8)0x80U)
#define POINT_TIMER_BIT_MASK	((uint8)0x3FU)

#define POINT_ILLEGAL_FAIL_SET	((uint8)0x40U)
#define POINT_ILLEGAL_BIT_MASK	((uint8)0x3FU)

#define POINT_ILLEGAL_DELAY		(1800U/MAX_TICK_ILT)/** 출력에 대한 입력 Count*/

#define SG_ATSRI_FAIL_DLY		(600U/MAX_TICK_ILT)
/* ------------------------------------------------------------------------- */
/* 신호기일괄 정지 상태                                                      */
/* ------------------------------------------------------------------------- */
#define ALL_SIGNAL_STOP_SET					0x10
#define ALL_SIGNAL_STOP_BLOCKING			0x08
#define ALL_SIGNAL_STOP_TIMER				10
/* ------------------------------------------------------------------------- */
/* Object 관련 Define (Signal)                                               */
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
/* Object 별 Size                                                            */
/* ------------------------------------------------------------------------- */
#define SIZE_SIGNAL_OBJECT					5
#define SIZE_POINT_OBJECT					2
#define SIZE_TRACK_OBJECT					2
/* ------------------------------------------------------------------------- */
/* 열차번호 관련 Define                                                      */
/* ------------------------------------------------------------------------- */
#define TRAINNO_SIZE						5U
#define MAX_TRAINNO 						50U
#define MAX_CTC_COMMAND_SIZE				26
#define USED_SECOND_WINDOW					((uint8)0x80)
#define FIRST_WIN							1
#define SECOND_WIN							2

/* [CTC궤도제어추가] */
#define TRACK_BLOCKING_1					0x02	/** 궤도사용중지 1       */
#define TRACK_BLOCKING_2					0x20	/** 궤도사용중지 2       */
#define TRACK_LABEL1_MASK					0x0F
#define TRACK_LABEL2_MASK					0xF0
/* ------------------------------------------------------------------------- */
/* CTC Element 관련 Define                                                   */
/* ------------------------------------------------------------------------- */
#define MAX_SUMMARYTC_TBL					10
#define MAX_SUMMARY_TC						10
#define MAX_CTC_ELEMENT						(uint16)(2048U)

#define CTC_SENDER_ID						0xA5	/** CTC명령어 구분(내부용) */

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
#define CTCELM_T_DRAG						0x31	/** 끌림검지장치         */ /*추가170831*/
#define CTCELM_T_ATS						0x32	/** ATS 고장 정보        */ /* 171227 [ATS고장추가] */

#define RCELM_T_DOOR						0x0E	/** RC용 출입문          */
#define RCELM_T_EQ							0x0F	/** RC용 전원설비        */
#define RCELM_T_PHETS						0x10	/** RC용 남히터          */
#define RCELM_T_PHETN						0x20	/** RC용 북히터          */
#define RCELM_T_IS_SYS1						0x33    /** RC용 절연예고장치고장정보 1계 STATE */ /* 추가 190916 */
#define RCELM_T_IS_SYS2						0x34    /** RC용 절연예고장치고장정보 2계 STATE */ /* 추가 190916 */
#define RCELM_T_IS_ACTIVE					0x35    /** RC용 절연예고장치고장정보 ONLINE STATE */ /* 추가 190916 */
/* ========================================================================= */
/* CTC Element 별 Display Bit State Define                                   */
/* ========================================================================= */
#define MAX_CTCELM_STATE_BUFF				13 /** CTC 변화상태 전송 버퍼 수 */
#define MAX_CTCELM_BASESCAN_BUFF			5  /** CTC Basescan 최대치       */
#define CTCELM_DSP_MODE_NONE_MODE         0x00
/* ------------------------------------------------------------------------- */
/* CTC 운영모드 표시 상태 Bit Position                                       */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_MODE_LOC               0x01U    /* 1:Local Mode           */
#define CTCELM_DSP_MODE_MR                0x02U    /* 1:CTC모드로전환요청중  */
#define CTCELM_DSP_MODE_REM               0x04U    /* 1:CTC Mode             */
#define CTCELM_DSP_MODE_ML                0x08U    /* 1:Local모드로전환요청중*/
/* ------------------------------------------------------------------------- */
/* CTC 전원장치 표시 상태 Bit Position                                       */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_PW_N1                0x01U    /* 1:Power on N1            */
#define CTCELM_DSP_PW_N2                0x02U    /* 1:Power on N2            */
#define CTCELM_DSP_PW_REC               0x04U    /* 1:DC 24V 고장, 0:정상    */
#define CTCELM_DSP_PW_UPS               0x08U    /* 1:UPS 정상, 0:고장       */
#define CTCELM_DSP_PW_C                 0x10U    /* 1:충전                   */
#define CTCELM_DSP_PW_D                 0x20U    /* 1:방전                   */
#define CTCELM_DSP_PW_SHSGOFF           0x80U    /* 1:입환소등, 0:On         */

#define CTCELM_DSP_JK_PW_REC            0x01U    /* 1:REC  고장, 0:정상      */
#define CTCELM_DSP_JK_PW_FUSE           0x02U    /* 1:FUSE 고장, 0:정상      */
/* ------------------------------------------------------------------------- */
/* CTC EIS 상태표시  Bit Position                                            */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_EIDEV1            0x01U    /* EIS 1계 정상:1 고장:0       */
#define CTCELM_DSP_EION1             0x02U    /* EIS 1계 Online:1 Stndby:0   */
#define CTCELM_DSP_EISRUN1           0x04U    /* EIS 1계 RUN:1               */ /*170906 [CTC시스템RUN추가] 추가*/
#define CTCELM_DSP_EISPARE4          0x08U
#define CTCELM_DSP_EISPARE5          0x10U
#define CTCELM_DSP_EISRUN2           0x20U    /* EIS 2계 RUN:1               */ /*170906 [CTC시스템RUN추가] 추가*/
#define CTCELM_DSP_EIDEV2            0x40U    /* EIS 2계 정상:1 고장:0       */
#define CTCELM_DSP_EION2             0x80U    /* EIS 2계 Online:1 Stndby:0   */
/* ------------------------------------------------------------------------- */
/* CTC 선로전환기 표시 상태 Bit Position                                     */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_PT_NP             0x01U    /* 1:정위상태, 0:다른상태      */
#define CTCELM_DSP_PT_RP             0x02U    /* 1:반위상태, 0:다른상태      */
#define CTCELM_DSP_PT_LK             0x04U    /* 1:쇄정상태, 0:해정상태      */
#define CTCELM_DSP_PT_PF             0x08U    /* 1:정상상태, 0:고장상태      */
#define CTCELM_DSP_PT_MVN            0x10U    /* 1:정위로 동작중, 0:다른상태 */
#define CTCELM_DSP_PT_MVR            0x20U    /* 1:반위로 동작중, 0:다른상태 */
#define CTCELM_DSP_PT_CB             0x80U    /* 1:CallBack, 0:N/A           */ /* [CallBack구현] */
/* ------------------------------------------------------------------------- */
/* CTC 출발, 장내신호기 표시 상태 Bit Position                               */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_SG_GO             0x01U  /* 1:진행현시, 0:정지현시        */
#define CTCELM_DSP_SG_SF             0x02U  /* 1:정상, 0:고장                */
#define CTCELM_DSP_SG_RI             0x04U  /* 1:진로표시기On,0:진로표시기off*/
#define CTCELM_DSP_SG_TTB            0x08U  /* 1:TTB On, 0:TTB Off           */
#define CTCELM_DSP_SG_AL             0x10U  /* 1:접근쇄정, 0:접근해정        */
#define CTCELM_DSP_SG_CG             0x20U  /* 1:유도신호기On,0:유도신호기Off*/
#define CTCELM_DSP_SG_LK             0x40U  /* 1:신호기쇄정, 0:Off           */
/* ------------------------------------------------------------------------- */
/* CTC 출발, 장내신호기 표시 상태 Bit Position (Jakarta)                     */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_JK_SG_G           0x01U  /* 1:G현시, 0:정지               */
#define CTCELM_DSP_JK_SG_Y           0x02U  /* 1:Y현시, 0:정지               */
#define CTCELM_DSP_JK_SG_RI_F        0x04U  /* 1:진로표시기고장,0:정상       */
#define CTCELM_DSP_JK_SG_TTB         0x08U  /* 1:TTB On, 0:TTB Off           */
#define CTCELM_DSP_JK_SG_AL          0x10U  /* 1:접근쇄정, 0:접근해정        */
#define CTCELM_DSP_JK_SG_CG          0x20U  /* 1:유도신호기On,0:유도신호기Off*/
#define CTCELM_DSP_JK_SG_SF          0x40U  /* 1:고장,  0:정상               */
#define CTCELM_DSP_JK_SG_LK          0x80U  /* 1:정상,  0:쇄정               */
/* ------------------------------------------------------------------------- */
/* CTC 입환신호기, 입환표지 표시 상태 Bit Position                           */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_SHSG_GO           0x01U  /* 1:진행현시, 0:정지현시        */
#define CTCELM_DSP_SHSG_SSF          0x02U  /* 1:정상, 0:고장                */
#define CTCELM_DSP_SHSG_SAL          0x10U  /* 1:접근/보류쇄정On 0:Off       */
#define CTCELM_DSP_SHSG_NCS          0x20U  /* 1:무유도 표시 On 0:Off        */
#define CTCELM_DSP_SHSG_LK           0x40U  /* 1:신호기쇄정, 0:Off           */
/* ------------------------------------------------------------------------- */
/* CTC 진로 표시 상태 Bit Position                                           */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_RT_LK             0x80U    /* 1:진로설정 0:진로해정       */
/* ------------------------------------------------------------------------- */
/* CTC 궤도회로 표시 상태 Bit Position                                       */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_TC_OCC            0x01U    /* 1:비점유, 0:점유            */
#define CTCELM_DSP_TC_SGGO	         0x02U    /* 1:신호진행, 0:신호정지      */ /* [CTC궤도상태추가] */
#define CTCELM_DSP_TC_EGSET	         0x04U    /* 1:비상해정가능, 0:불가능    */ /* [CTC궤도상태추가] */
#define CTCELM_DSP_TC_BLK	         0x08U    /* 1:차단, 0:해제              */ /* [CTC궤도상태추가] */
#define CTCELM_DSP_TC_RTLOCK         0x10U    /* 1:진로해정, 0:진로쇄정      */ /* [CTC궤도상태추가] */
#define CTCELM_DSP_TC_FAIL			 0x20U    /* 1:궤도장애, 0:정상          */ /* [CTC궤도장애추가]  */
/* ------------------------------------------------------------------------- */
/* CTC 구내폐색신호기 표시 상태 Bit Position                                 */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_ABSG_HBG     0x01U    /* 1:진행현시, 0:정지현시           */
#define CTCELM_DSP_ABSG_HBF     0x02U    /* 1:정상, 0:고장                   */
/* ------------------------------------------------------------------------- */
/* CTC 폐색신호기 표시 상태 Bit Position                                     */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_BSG_BSF      0x01U    /* 1:고장, 0:정상                   */
#define CTCELM_DSP_BSG_GO       0x02U    /* 1:진행, 0:정지                   */
/* ------------------------------------------------------------------------- */
/* CTC 건널목 표시 상태 Bit Position                                         */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_RC           0x01U    /* 1:정상, 0:고장                   */
/* ------------------------------------------------------------------------- */
/* CTC 방향폐색등 표시 상태 Bit Position                                     */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_DIR_DYF      0x01U    /* 폐색 황색등 점멸 SET:1           */
#define CTCELM_DSP_DIR_DY       0x02U    /* 폐색 황색등 점등 SET:1           */
#define CTCELM_DSP_DIR_DR       0x04U    /* 폐색 적색등 점등 SET:1           */
#define CTCELM_DSP_DIR_DRF      0x08U    /* 폐색 적색등 점멸 SET:1           */
/* ------------------------------------------------------------------------- */
/* CTC 역 공통 고장 표시 상태                                                */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_SCO_P        0x01U    /* 선로전환기 공통 고장 (정상:1)    */
#define CTCELM_DSP_SCO_S        0x02U    /* 신호기 공통 고장 (정상:1)        */
#define CTCELM_DSP_SCO_TE       0x04U    /* 신호기 공통 시소 (정상:1)        */
#define CTCELM_DSP_SCO_BS       0x08U    /* 폐색신호기 공통 고장 (정상:1)    */
/* ------------------------------------------------------------------------- */
/* CTC 지장물 검지 장치  표시 상태                                           */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_OBSFAIL		0x01U	/* 지장물검지장치 상태  1:고장 0:정상*/
#define CTCELM_DSP_OBSOPER		0x02U	/* 확인조작  1:설정 0:해제           */
/* ------------------------------------------------------------------------- */
/* CTC 신호기 일괄정지 표시 상태                                             */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_ALLSGSTOP	0x01U	/* 신호기 일괄정지 1:설정 0:해제     */
/* ------------------------------------------------------------------------- */
/* CTC 끌림검지장치 표시 상태                                                */
/* ------------------------------------------------------------------------- */
#define CTCELM_DSP_DRAGFAIL		0x01U	/* 끌림검지장치 상태  1:고장 0:정상  */
#define CTCELM_DSP_DRAGOPER		0x02U	/* 확인조작  1:설정 0:해제           */
/* ------------------------------------------------------------------------- */
/* CTC ATS 고장 상태                                                         */
/* ------------------------------------------------------------------------- */
#define CTCELM_ATS_GFAIL		0x01U	/* 1:고장 0:정상  */ /* 171227 [ATS고장추가] */
#define CTCELM_ATS_YFAIL		0x02U	/* 1:고장 0:정상  */ /* 171227 [ATS고장추가] */

/* ========================================================================= */
/* CTC Element 별 Control Bit State Define                                   */
/* ========================================================================= */
/* ------------------------------------------------------------------------- */
/* CTC 제어 코드                                                             */
/* ------------------------------------------------------------------------- */
#define CTCELM_CTRL_MODE		((uint8)0x01U)
#define CTCELM_CTRL_POINT		((uint8)0x02U)
#define CTCELM_CTRL_ROUTE		((uint8)0x03U)
#define CTCELM_CTRL_SHRUT		((uint8)0x04U)
#define CTCELM_CTRL_DIR			((uint8)0x05U)
#define CTCELM_CTRL_RUN			((uint8)0x06U) /* [CTC시스템RUN추가] */
#define CTCELM_CTRL_TRACK		((uint8)0x07U) /* [CTC궤도제어추가] */
/* ------------------------------------------------------------------------- */
/* CTC 시스템 RUN 수신 Bit                                                   */ /* [CTC시스템RUN추가] */
/* ------------------------------------------------------------------------- */
#define CTCELM_CTRL_EI_RUN1		((uint8)0x01U)
#define CTCELM_CTRL_EI_RUN2		((uint8)0x02U)
/* ------------------------------------------------------------------------- */
/* CTC 제어모드 전환 수신 Bit                                                */
/* ------------------------------------------------------------------------- */
#define CTCELM_CTRL_MD_LOCREQ	((uint8)0x01U)
#define CTCELM_CTRL_MD_EMGCTC	((uint8)0x02U)
#define CTCELM_CTRL_MD_CTCACPT	((uint8)0x80U)
/* ------------------------------------------------------------------------- */
/* CTC 선로전환기 전환 수신 Bit                                              */
/* ------------------------------------------------------------------------- */
#define CTCELM_CTRL_PT_MVN		((uint8)0x01U)
#define CTCELM_CTRL_PT_MVR		((uint8)0x02U)
/* ------------------------------------------------------------------------- */
/* CTC 진로 제어 수신 Bit                                                    */
/* ------------------------------------------------------------------------- */
#define CTCELM_CTRL_RT_SET		((uint8)0x01U)
#define CTCELM_CTRL_RT_CAN		((uint8)0x02U)
#define CTCELM_CTRL_RT_TTB		((uint8)0x04U)
#define CTCELM_CTRL_RT_TTCB		((uint8)0x08U)
#define CTCELM_CTRL_RT_STOP		((uint8)0x10U)
#define CTCELM_CTRL_RT_RSET		((uint8)0x20U)
/* ------------------------------------------------------------------------- */
/* CTC 궤도 제어 수신 Bit                                                    */ /* [CTC궤도제어추가] */
/* ------------------------------------------------------------------------- */
#define CTCELM_CTRL_TC_EG			((uint8)0x01U)	/** 궤도 구분진로 해정   */
#define CTCELM_CTRL_TC_BLK_SET		((uint8)0x02U)	/** 궤도 Blocking 설정   */
#define CTCELM_CTRL_TC_BLK_RESET	((uint8)0x04U)	/** 궤도 Blocking 해제   */
#define CTCELM_CTRL_TC_RESET		((uint8)0x08U)	/** 궤도(AXC) Reset      */ /* [CTC궤도Reset추가] */
/* ------------------------------------------------------------------------- */
/* CTC 폐색 제어 수신 Bit                                                    */
/* ------------------------------------------------------------------------- */
#define CTCELM_CTRL_DIR_CAN		((uint8)0x01U)		/** 폐색 취소            */
#define CTCELM_CTRL_DIR_ENT		((uint8)0x02U)		/** 폐색 장내            */
#define CTCELM_CTRL_DIR_ACPT	((uint8)0x04U)		/** 폐색 개통            */
#define CTCELM_CTRL_DIR_EXIT	((uint8)0x08U)		/** 폐색 출발            */


/* ========================================================================= */
/* RC Element 별 Display Bit State Define                                    */
/* ========================================================================= */
#define RCELM_TWC_CODE			((uint8)0x90U)
#define RCELM_TW1_CODE			((uint8)0x91U)
#define RCELM_TW2_CODE			((uint8)0x92U)
#define RCELM_TW3_CODE			((uint8)0x93U)
#define RCELM_TWE_CODE			((uint8)0x9EU)
/* ------------------------------------------------------------------------- */
/* RC  운영모드 표시 상태 Bit Position                                       */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_MODE_LOC               0x01U    /* 1:Local Mode            */
#define RCELM_DSP_MODE_MR                0x02U    /* 1:CTC모드로전환요청중   */
#define RCELM_DSP_MODE_REM               0x04U    /* 1:CTC Mode              */
#define RCELM_DSP_MODE_ML                0x08U    /* 1:Local모드로전환요청중 */
#define RCELM_DSP_MODE_RC                0x10U    /* 1:RC  Mode              */
#define RCELM_DSP_MODE_MRC               0x20U    /* 1:RC모드로전환요청중    */
/* ------------------------------------------------------------------------- */
/* RC  전원장치 표시 상태 Bit Position                                       */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_PW_N1     		0x01U	/* bit0 | 1:N1 사용              */
#define RCELM_DSP_PW_N2     		0x02U	/* bit1 | 1:N2 사용              */
#define RCELM_DSP_PW_REC    		0x04U	/* bit2 | 1:정류기 / 0:고장      */
#define RCELM_DSP_PW_UPS    		0x08U	/* bit3 | 1:UPS 정상 / 0:UPS 고장*/
#define RCELM_DSP_PW_C      		0x10U	/* bit4 | 1:충전 / 0:방전        */
#define RCELM_DSP_PW_PS      		0x20U	/* bit5 | 1:P남 전원 / 0:고장    */
#define RCELM_DSP_PW_PN     		0x40U	/* bit6 | 1:P북 전원 / 0:고장    */
#define RCELM_DSP_PW_FUSE			0x80U	/* bit7 | 1:Fuse / 0:고장        */
/* ------------------------------------------------------------------------- */
/* RC  EIS 상태표시  Bit Position                                            */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_EIDEV1	0x01U    /* bit0 | 1: 1계 EIS 동작 / 0: 1계 고장 */
#define RCELM_DSP_EION1		0x02U    /* bit1 | 1: 1계 EIS 주계 / 0: 1계 대기 */
#define RCELM_DSP_SYSRUN1	0x04U    /* bit2 | 1: Systerm 1 Run On           */
#define RCELM_DSP_FS		0x08U    /* bit3 | 1: S (신호기 고장)            */
#define RCELM_DSP_FP		0x10U    /* bit4 | 1: P (전철기 고장)            */
#define RCELM_DSP_FT		0x20U    /* bit5 | 1: T (궤도 장애)              */
#define RCELM_DSP_EIDEV2	0x40U    /* bit6 | 1: 2계 EIS 동작 / 0: 2계 고장 */
#define RCELM_DSP_EION2		0x80U    /* bit7 | 1: 2계 EIS 주계 / 0: 2계 대기 */
/* ------------------------------------------------------------------------- */
/* RC  선로전환기 표시 상태 Bit Position                                     */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_PT_NP		0x01U    					/* bit0 | 1:정위     */
#define RCELM_DSP_PT_RP		0x02U    					/* bit1 | 1:반위     */
#define RCELM_DSP_PT_LK		0x04U    					/* bit2 | 1:쇄정     */
#define RCELM_DSP_PT_PF		0x08U    					/* bit3 | 1:고장     */
#define RCELM_DSP_PT_MVN	0x10U    					/* bit4 | 1:정위동작 */
#define RCELM_DSP_PT_MVR	0x20U    					/* bit5 | 1:반위동작 */
#define RCELM_DSP_PT_WRR	0x40U    					/* bit6 | 1:WR-R     */
#define RCELM_DSP_PT_WRN	0x80U    					/* bit7 | 1:WR-N"    */
/* ------------------------------------------------------------------------- */
/* RC  출발, 장내신호기 표시 상태 Bit Position                               */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_SG_GO		0x01U  /* bit0 | 1: 진행 현시 / 0: 정지 현시     */
#define RCELM_DSP_SG_SF		0x02U  /* bit1 | 1: 고장 / 0:  정상              */
#define RCELM_DSP_SG_GO2	0x04U  /* bit2 | 1: 주의, 감속 현시일 경우       */
#define RCELM_DSP_SG_TTB	0x08U  /* bit3 | 1: TTB ON / 0: TTB OFF(TTCB)    */
#define RCELM_DSP_SG_AL		0x10U  /* bit4 | 1: 접근쇄정 ON / 0: 접근쇄정해정*/
#define RCELM_DSP_SG_CG		0x20U  /* bit5 | 1: 유도 ON / 0: 유도 0FF        */
#define RCELM_DSP_SG_GO3	0x40U  /* bit6 | 1: 경계, 감속 현시 현시일 경우  */
#define RCELM_DSP_SG_LK		0x80U  /* bit7 | 1: REQ (신호기 쇄정등)"         */
/* ------------------------------------------------------------------------- */
/* RC  입환신호기, 입환표지 표시 상태 Bit Position                           */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_SHSG_GO           0x01U  /* 1:진행현시, 0:정지현시         */
#define RCELM_DSP_SHSG_SSF          0x02U  /* 1:고장, 0:정상                 */
#define RCELM_DSP_SHSG_SAL          0x10U  /* 1:접근/보류쇄정On 0:Off        */
#define RCELM_DSP_SHSG_NCS          0x20U  /* 1:무유도 표시 On 0:Off         */
#define RCELM_DSP_SHSG_LK           0x40U  /* 1:신호기쇄정, 0:Off            */
/* ------------------------------------------------------------------------- */
/* RC  구내폐색신호기 표시 상태 Bit Position                                 */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_ABSG_HBG	0x01U	/* bit0 | 1:진행현시, 0:정지현시         */
#define RCELM_DSP_ABSG_HBF	0x02U	/* bit1 | 1:고장, 0:정상                 */
#define RCELM_DSP_ABSG_GO2	0x04U	/* bit2 | 1: 주의, 감속 현시일 경우      */
#define RCELM_DSP_ABSG_GO3	0x40U	/* bit6 | 1: 경계, 감속 현시 현시일 경우 */
/* ------------------------------------------------------------------------- */
/* RC  폐색신호기 표시 상태 Bit Position                                     */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_BSG_BSF		0x01U    /* 1:고장, 0:정상                   */
#define RCELM_DSP_BSG_GO		0x02U    /* 1:진행, 0:정지                   */
/* ------------------------------------------------------------------------- */
/* RC  진로 표시 상태 Bit Position                                           */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_RT_TTB		0x01U    /* 1:TTB Set  0:Reset               */
#define RCELM_DSP_RT_LK			0x80U    /* 1:진로설정 0:진로해정            */
/* ------------------------------------------------------------------------- */
/* RC  궤도회로 표시 상태 Bit Position                                       */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_TC_OCC		0x01U	/* 1:비점유, 0:점유                  */
#define RCELM_DSP_TC_FAIL		0x02U	/* 1:장애                            */
#define RCELM_DSP_TC_GLK		0x04U	/* 1:녹색                            */
#define RCELM_DSP_TC_YLK		0x08U	/* 1:황색                            */
#define RCELM_DSP_TC_TTB		0x20U	/* 1:TTB                             */
#define RCELM_DSP_TC_EGR		0x40U	/* 1:비상해정                        */
/* ------------------------------------------------------------------------- */
/* RC  건널목 표시 상태 Bit Position                                         */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_RC			0x01U    /* 1:고장, 0:정상                   */
/* ------------------------------------------------------------------------- */
/* RC  출입문 표시 상태 Bit Position                                         */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_DOOR			0x01U    /* 1:닫힘, 0:열림                   */
/* ------------------------------------------------------------------------- */
/* RC  방향폐색등 표시 상태 Bit Position                                     */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_DIR_DYF		0x01U    /* 폐색 황색등 점멸 SET:1           */
#define RCELM_DSP_DIR_DY		0x02U    /* 폐색 황색등 점등 SET:1           */
#define RCELM_DSP_DIR_DR		0x04U    /* 폐색 적색등 점등 SET:1           */
#define RCELM_DSP_DIR_DRF		0x08U    /* 폐색 적색등 점멸 SET:1           */
/* ------------------------------------------------------------------------- */
/* RC  설비 표시 상태 Bit Position                                           */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_EQ_C1ACT		0x01U	/* bit0 | 1:COM1 동작중 / 0: 고장    */
#define RCELM_DSP_EQ_C1M		0x02U	/* bit1 | 1:COM1 주사용 / 0: 대기    */
#define RCELM_DSP_EQ_C2ACT		0x04U	/* bit2 | 1:COM2 동작중 / 0: 고장    */
#define RCELM_DSP_EQ_C2M		0x08U	/* bit3 | 1:COM2 주사용 / 0: 대기    */
#define RCELM_DSP_EQ_SHOFF		0x10U	/* bit4 | 1:입환 소등   / 0: 입환점등*/
#define RCELM_DSP_SYSRUN2		0x20U   /* bit5 | 1: Systerm 2 Run On       */
#define RCELM_DSP_EQ_N1X		0x40U	/* bit6 | 1:N1 정상     / 0: N1 고장 */
#define RCELM_DSP_EQ_N2X		0x80U	/* bit7 | 1:N2 정상     / 0: N2 고장 */
/* ------------------------------------------------------------------------- */
/* RC  신호기 일괄정지 표시 상태                                             */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_ALLSGSTOP		0x01U	/* 신호기 일괄정지 1:설정 0:해제     */
/* ------------------------------------------------------------------------- */
/* RC  히터 상태 Bit Position                                                */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_HT_O			0x01U	/* bit0 | 1:히터제어(1)              */
#define RCELM_DSP_HT_I			0x08U	/* bit3 | 1:히터입력(1)              */
#define RCELM_DSP_HT_F			0x80U	/* bit7 | 1:히터고장(1)              */
/* ------------------------------------------------------------------------- */
/* RC  절연예고장치고장정보 표시 상태 Bit Position                           */
/* ------------------------------------------------------------------------- */
#define RCELM_DSP_IS1			0x01U    /* 1:정상, 0:고장                   */
#define RCELM_DSP_IS2			0x01U    /* 1:정상, 0:고장                   */
#define RCELM_DSP_ISACT			0x01U    /* 1:1계운용, 0:2계운용             */

/* ========================================================================= */
/* RC Element 별 Control Bit State Define                                    */
/* ========================================================================= */
/* ------------------------------------------------------------------------- */
/* RC  제어 코드                                                             */
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
/* RC  제어모드 전환 수신 Bit                                                */
/* ------------------------------------------------------------------------- */
#define RCELM_CTRL_MD_LOCACT	(uint8)(0x01U)  /* 1 : LOCAL 모드 전환 승인  */
#define RCELM_CTRL_MD_EMLOC		(uint8)(0x02U)	/* 1 : 비상 Local 전환 요청  */
#define RCELM_CTRL_MD_RCACT		(uint8)(0x04U)  /* 1 : RC 전환 명령          */
#define RCELM_CTRL_MD_EMRC		(uint8)(0x08U)  /* 1 : 비상 RC 전환 명령     */
#define RCELM_CTRL_MD_LOCCAN	(uint8)(0x10U)  /* 1 : Local 전환 취소       */
#define RCELM_CTRL_MD_CTCCAN	(uint8)(0x20U)  /* 1 : CTC 전환 취소         */
#define RCELM_CTRL_MD_CTCREQ	(uint8)(0x80U)  /* 1 : CTC 전환 요청         */
/* ------------------------------------------------------------------------- */
/* RC  선로전환기 전환 수신 Bit                                              */
/* ------------------------------------------------------------------------- */
#define RCELM_CTRL_PT_MVN		((uint8)0x01U)		/* bit0 | 1 : 정위전환 요청  */
#define RCELM_CTRL_PT_MVR		((uint8)0x02U)  	/* bit1 | 1 : 반위전환 요청  */
/* ------------------------------------------------------------------------- */
/* RC  진로 제어 수신 Bit                                                    */
/* ------------------------------------------------------------------------- */
#define RCELM_CTRL_RT_SET		(uint8)(0x01U)		/* 1 : 진로설정              */
#define RCELM_CTRL_RT_CAN		(uint8)(0x02U)		/* 1 : 진로취소              */
#define RCELM_CTRL_RT_TTB		(uint8)(0x04U)		/* 1 : 진행정위진로 ON(TTB)  */
#define RCELM_CTRL_RT_TTCB		(uint8)(0x08U)		/* 1 : 진행정위진로 OFF(TTCB)*/
#define RCELM_CTRL_RT_STOP		(uint8)(0x10U)		/* 1 : 신호기 정지명령       */
#define RCELM_CTRL_RT_RSET		(uint8)(0x20U)		/* 1 : 진로재취급            */
/* ------------------------------------------------------------------------- */
/* RC  비상구분해정 제어 수신 Bit                                            */
/* ------------------------------------------------------------------------- */
#define RCELM_CTRL_EGTC			((uint8)0x01)		/** 1: 비상해정          */
#define RCELM_CTRL_FAILRLS		((uint8)0x02)		/** 1: 비상복귀          */
/* ------------------------------------------------------------------------- */
/* RC  System RUN 제어 수신 Bit                                              */
/* ------------------------------------------------------------------------- */
#define RCELM_CTRL_SYSRUN		((uint8)0x01)		/** 1: RUN 설정          */
/* ------------------------------------------------------------------------- */
/* RC  폐색 제어 수신 Bit                                                    */
/* ------------------------------------------------------------------------- */
#define RCELM_CTRL_DIR_CAN		((uint8)0x01U)		/** 폐색 취소            */
#define RCELM_CTRL_DIR_ENT		((uint8)0x02U)		/** 폐색 장내            */
#define RCELM_CTRL_DIR_ACPT		((uint8)0x04U)		/** 폐색 개통            */
#define RCELM_CTRL_DIR_EXIT		((uint8)0x08U)		/** 폐색 출발            */
/* ------------------------------------------------------------------------- */
/* RC  신호기일괄 정지 제어 수신 Bit                                         */
/* ------------------------------------------------------------------------- */
#define RCELM_CTRL_ALLSGSET		((uint8)0x01)		/** 1: 일괄정지 설정     */
#define RCELM_CTRL_ALLSGCAN		((uint8)0x02)		/** 1: 일괄정지 해제     */
/* ------------------------------------------------------------------------- */
/* RC  입환소등 제어 수신 Bit                                                */
/* ------------------------------------------------------------------------- */
#define RCELM_CTRL_SHOFFSET		((uint8)0x01)		/** 1: 입환소등 설정     */
#define RCELM_CTRL_SHONSET		((uint8)0x02)		/** 1: 입환점등 설정     */
/* ------------------------------------------------------------------------- */
/* RC  히터 제어 수신 Bit                                                    */
/* ------------------------------------------------------------------------- */
#define RCELM_CTRL_HEATON		((uint8)0x01)		/** 1: 히터제어 On       */
#define RCELM_CTRL_HEATOFF		((uint8)0x02)		/** 1: 히터제어 Off      */

/* ------------------------------------------------------------------------- */
/* Bit Operation 용 처리 Type                                                */
/* ------------------------------------------------------------------------- */
#define FUNC_LDA	1
#define FUNC_STA	2
#define FUNC_AND	3
#define FUNC_ORA	4
#define FUNC_ANS	5
#define FUNC_ORS	6
#define FUNC_MOV	7
#define FUNC_TRS	8			/** TRUE일 때만 SET                          */

#define BIO_ROUTE_VALUE	0xFF	/** BIT_EXCEPTION ucBitPos의 값(ROUTE 사용시)*/

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
