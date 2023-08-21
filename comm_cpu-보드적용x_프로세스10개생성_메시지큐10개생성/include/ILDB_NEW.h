/* ========================================================================= /
17.01.24 :
 - [include] EisDefine.h include
17.01.25 :
 - [DB����] DB Size 300,000byte ���߱� ���� (baseinfo�� size, crc ��������(8byte����) aucDummy���� 300K) 
/ ========================================================================= */
#ifndef _ILDB_NEW_H_
#define _ILDB_NEW_H_
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
/* File Description                                                          */
/* ------------------------------------------------------------------------- */
/**
* @file ILDB.h
* @author KangKM
* @version 1.0
* @brief ���� Data Structure
* @see main structure TS_ILDB 
*/
/* ------------------------------------------------------------------------- */
/* Include                                                                   */
/* ------------------------------------------------------------------------- */
#include	"EisDefine.h"
/* ------------------------------------------------------------------------- */
/* Macro                                                                     */
/* ------------------------------------------------------------------------- */
#pragma pack (1)
/* ========================================================================= */
/* Structure Define                                                          */
/* ========================================================================= */
/* ------------------------------------------------------------------------- */
/* ���� Data�� Information                                                   */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ROUTEINFO
* @brief Route Data�� Information
*/
typedef struct {
	uint16	usRtDataStart;				/** ���� Data�� ILDB ���� ��ġ       */
	uint16	usRouteCount;				/** ���Ǵ� ������ ��               */
	uint32	uiRtDataSize;				/** ��ü ���� Data�� ũ��            */
} TS_ROUTEINFO;
/* ------------------------------------------------------------------------- */
/* Object Data�� Information                                                 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_OBJINFO
* @brief Object Data�� Information
*/
typedef struct {
	uint16	usSmOffset;					/** SMEM�� Object ���� ���� ��ġ     */
	uint16	usObjCount;					/** Object�� ��					     */
} TS_OBJINFO;
/* ------------------------------------------------------------------------- */
/* ���� �� �⺻���� Data                                                     */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ILDB_BASEINFO_TABLE
* @brief ���� �� �⺻���� Data
*/
typedef struct {
	uint32			uiILDBSize;						/** IDLB SIZE(CRC_DATA ��)*/
	uint32			uiAllCRC32;						/** 1000byte CRC������ CRC*/
	uint8			aucILDBVer[18];					/** ILDB Version          */

	TS_ROUTEINFO	tRouteInfo;						/** RouteData Infomation  */
	TS_OBJINFO		tSignalInfo;					/** SignalData Infomation */
	TS_OBJINFO		tTrackInfo;						/** TrackData Infomation  */
	TS_OBJINFO		tPointInfo;						/** PointData Infomation  */
	TS_OBJINFO		tGioInfo;						/** GIOData Infomation    */
	uint8			ucGenPointWkTm;					/** �Ϲ�Point Working Time*/
	uint8			ucHiPointWkTm;					/** ���Point Working Time*/
	uint8			ucPointCotrolInterval;			/** Point�� ���� ����     */
	uint8			ucIOSCount;						/** IOS ��                */ /*[����] ���� ��ȣ�� check time�� ������� �ʾ� ����*/
	uint8			ucInMdCount;					/** Input Modeule ��      */
	uint8			ucOutMdCount;					/** Output Modeule ��     */
	uint8			ucPdoMdCount;					/** PDO Modeule ��        */
	uint8			aucIoModuleInfo[MAX_IO_MODULE];	/** IO Module ����    */
	uint8			aucIoModuleId[MAX_IO_MODULE];	/** IO Module ID      */
	uint8			aucTaskInfo[MAX_TASK];			/** Task ��� ����        */
}TS_ILDB_BASEINFO_TABLE;
/* ------------------------------------------------------------------------- */
/* ������ȯ�� Data                                                           */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ILDB_POINTINFO_TABLE
* @brief ������ȯ�� Data
*/
typedef struct {
	uint8	ucPointType;					/** ������ȯ�� ����              */
	uint16	usTC[MAX_TRACK_IN_POINTTABLE];	/** ������ȯ�� ���� �˵�         */
	uint16	usSW[MAX_POINT_IN_POINTTABLE];	/** �Էµ����� ���� ������ȯ��   */
} TS_ILDB_POINTINFO_TABLE;
/* ------------------------------------------------------------------------- */
/* ��ȣ�� Data                                                               */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ILDB_SIGNALINFO_TABLE
* @brief ��ȣ�� Data
*/
typedef struct {
	uint8	ucSignalType;								/** ��ȣ�� ����      */
	uint8	ucSgAspectType;								/** ���� �迭        */
	uint8	ucApprLockTime;								/** ���ټ��� �ð�    */
	uint16	usContinousSg;								/** �������� ��ȣ��  */
	uint16	usFirstTrack;								/** ���� ù�˵�      */
	uint16	usFromTrack;								/** ��ȣ��ܹ� �˵�  */
	uint8	ucRouteCount;								/** ���� ���� ��     */
	uint16	usStartRoute;								/** ���� ����        */
	uint16	usTtbArriveTc;								/** TTB �����˵�     */
	uint16	ausApproachInfo[MAX_SGTBL_APPROACH_INFO];	/** ���ٱ��� ����    */
} TS_ILDB_SIGNALINFO_TABLE;
/* ------------------------------------------------------------------------- */
/* �˵� Data                                                                 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ILDB_TRACKINFO_TABLE
* @brief �˵� Data
*/
typedef struct {
	uint8	ucTrackType;				/** �˵� ����                        */
	uint8	ucTwId;						/** �˵��� ������ ������ȣ â ID     */
	uint8	ucBlkSecTblId;				/** ����˵��� ��� ������� Data ID */
	uint8	ucBlkSecTCsId;				/** ���Data�� �˵� Data buff Index  */
	uint8	ucGioInfo;					/** ����� ������ GIO Data ID        */
	uint16	usApproachSignal[MAX_SGINTC];	/** �˵� ���� ��ȣ�� ����        */
	uint8	ucTcLRinfoCnt;				/** �����˵� ���� ��                 */
	uint32	uiTcLRinfoPos;				/** �����˵� ���̺� ���� ��ġ        */
} TS_ILDB_TRACKINFO_TABLE;
/* ------------------------------------------------------------------------- */
/* IO Information Data                                                       */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ILDB_IOINFO_TABLE
* @brief IO Information Data
*/
typedef struct {
	uint8	ucIoInfo;					/** IO Type �� SMEM ��ġ�� Bit ��ġ  */
	uint16	usIoPosition;				/** IO bit�� SMEM byte offset        */
	uint8	ucObjectType;				/** IO�� �ش� Object Type            */
	uint16	usObjectId;					/** IO�� �ش� Object ID              */
	uint8	ucIoType;					/** Object Type �� IO Type           */
} TS_ILDB_IOINFO_TABLE;
/* ------------------------------------------------------------------------- */
/* Local Element Information Data                                            */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ILDB_LOCALELEMENTINFO_TABLE
* @brief Local Element Information Data
*/
typedef struct {
	uint16	usLocElmSize;					/** Local Element Data Size      */
	uint16	usCommonCount;					/** Common Element Data ��       */
	uint16	usTrackCount;					/** Track Element Data ��        */
	uint16	usTrackLabelCount;				/** Track ǥ�� Element Data ��   */
	uint16	usSignalCount;					/** Signal Element Data ��       */
	uint16	usPointCount;					/** Point Element Data ��        */
	uint16	usGioCount;						/** GIO Element Data ��          */
	uint16	usRouteCount;					/** Rounte Element Data ��       */
	
	uint16	ausLocElmInfo[MAX_LOCAL_ELEMENT];
	
	/*uint16	usLocElmCommon[MAX_LOCAL_ELEMENT_COMMON];*/	/** Common Element   */
	/*uint16	usLocElmTrack[MAX_TRACK_NEW];	*/			/** Track Element    */
	/*uint16	usLocElmTrackLabel[MAX_TRACK_NEW];*/			/** ǥ�� Element     */
	/*uint16	usLocElmSignal[MAX_SIGNAL_NEW];	*/			/** Signal Element   */
	/*uint16	usLocElmPoint[MAX_POINT_NEW];	*/			/** Point Element    */
	/*uint16	usLocElmGio[MAX_GENERAL_IO];	*/			/** GIO Element      */
	/*uint16	usLocElmRoute[MAX_ROUTE_NEW];	*/			/** Route Element    */
	/*uint16	ucLocElmEnd;					*/			/** Element End data */
} TS_ILDB_LOCALELEMENTINFO_TABLE;
/* ------------------------------------------------------------------------- */
/* CTC Element Information Data                                              */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ILDB_CTCELEMENTINFO_TABLE
* @brief CTC Element Information Data
*/
typedef struct {
	uint16	usCtcElmCount;
	struct {
		uint8	ucCtcElmType;			/** CTC Element Type                 */
		uint16	usSmemPos;				/** ���� SMEM�� ��ġ ����            */
	} tCtcElm [MAX_CTC_ELEMENT];
} TS_ILDB_CTCELEMENTINFO_TABLE;
/* ------------------------------------------------------------------------- */
/* RC Element Information Data                                              */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ILDB_RCELEMENTINFO_TABLE
* @brief RC Element Information Data
*/
typedef struct {
	uint16	usRcElmCount;
	struct {
		uint8	ucRcElmType;			/** RC Element Type                  */
		uint16	usSmemPos;				/** ���� SMEM�� ��ġ ����            */
	} tRcElm [MAX_CTC_ELEMENT];
} TS_ILDB_RCELEMENTINFO_TABLE;
/* ------------------------------------------------------------------------- */
/* Summary Tc Information Data                                               */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ILDB_SUMMARYTC_TABLE
* @brief RC Element Information Data
*/
typedef struct {
	uint16	usBaseTc;					/** ���� �˵� (CTC �˵� �� etc..)    */
	uint8	ucTCsCnt;					/** ausSumTCs ��                     */
	uint16	ausSumTCs[MAX_SUMMARY_TC];	/** TC Object ID MAX:10              */
} TS_ILDB_SUMMARYTC_TABLE;
/* ------------------------------------------------------------------------- */
/* Block Section Data                                                        */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ILDB_BLOCKSECTION_TABLE
* @brief Block Section Data
*/
typedef struct {
	uint16	usBlkSgId;					/** ��� ���� ��ȣ��                 */
	uint16	usSgId;						/** �峻 ��ȣ��(������ : 0)          */
	uint8	ucInDir;					/** �峻 ���� Left:0x01 / Right:0x02 */
	uint8	ucBlkSecType;				/** ��� ����                        */
	uint8	ucBlkCount;					/** ����˵�ȸ�� ��                  */
	uint16	ausBlkTc[MAX_BLOCK_TRACK];	/** ����� ���Ե� �˵� ����          */
} TS_ILDB_BLOCKSECTION_TABLE;

/* ------------------------------------------------------------------------- */
/* Equipment Name Data                                                       */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_OBJECT_NAME
* @brief Equipment Name Data
*/
typedef struct {
	uint8	aucCommonNm[MAX_LOCAL_ELEMENT_COMMON][NAME_SIZE];	/** Local Element Common Name */
	uint8	aucTrackNm[MAX_TRACK_NEW][NAME_SIZE];				/** Track Object Name         */
	uint8	aucSignalNm[MAX_SIGNAL_NEW][NAME_SIZE];             /** Signal Object Name        */
	uint8	aucPointNm[MAX_POINT_NEW][NAME_SIZE];               /** Point Object Name         */
	uint8	aucGioNm[MAX_GENERAL_IO][NAME_SIZE];                /** GIO Object Name           */
	uint8	aucDestNm[MAX_DESTPOINT][NAME_SIZE];				/** ������ Name               */
} TS_OBJECT_NAME;
/* ========================================================================= */
/* ���� Data(ILDB)�� ��ü ����                                               */
/* ========================================================================= */
/**
* @struct TS_ILDB
* @brief ���� Data(ILDB)�� ��ü ����
*/
typedef struct {
	TS_ILDB_BASEINFO_TABLE			tBaseInfoTbl;							/** Base Info Table  */
	uint8							aucRouteDataTbl[SIZE_ROUTEDATA_AREA];	/** Route Data table */
	uint32							auiRoutePosTbl[MAX_ROUTE];				/** Route Postion Data Table */
	uint16							ausRouteSizeTbl[MAX_ROUTE];				/** Route Size Table */
	TS_ILDB_POINTINFO_TABLE			tPointInfoTbl[MAX_POINT];				/** Point Info Table */
	TS_ILDB_SIGNALINFO_TABLE		tSignalInfoTbl[MAX_SIGNAL];				/** Signal Info Table*/
	TS_ILDB_TRACKINFO_TABLE			tTrackInfoTbl[MAX_TRACK];				/** Track Info Table */
	TS_ILDB_IOINFO_TABLE			tIoInfoTbl[MAX_ALL_IO_PORT];			/** IO Info Table    */
	TS_ILDB_LOCALELEMENTINFO_TABLE	tLocElmInfoTbl;							/** LOCAL ELM Table  */
	TS_ILDB_CTCELEMENTINFO_TABLE	tCtcElmInfoTbl;							/** CTC ELM Table    */
	TS_ILDB_BLOCKSECTION_TABLE		tBlkSecTbl[MAX_BLOCKSECTION];			/** ������� Table   */
	uint8							aucGIOInfoTbl[MAX_GENERAL_IO];			/** GIO Info Table   */
	uint32							auiInfoGeneral[MAX_INFO_GENERAL];		/** Bit Operation    */
	uint16							ausTwInfo[MAX_TRAINNO];					/** TW Info Table    */
																			/** ����â���ر˵�   */
	uint8							aucTrackLRInfoTbl[SIZE_TRACK_LINK_AREA];/** �����˵� ����    */																			
	TS_OBJECT_NAME					tEpuipNameTbl;							/** ��Ī Table       */
	
	TS_ILDB_RCELEMENTINFO_TABLE		tRcElmInfoTbl;
	TS_ILDB_SUMMARYTC_TABLE			tSumTcTbl[MAX_SUMMARYTC_TBL];
	
	/* [DB����] DB Size 300,000byte ���߱� ���� (baseinfo�� size, crc ��������(8byte����) aucDummy���� 300K) */
	uint8							aucDummy[2983];
} TS_ILDB_NEW;
/* ------------------------------------------------------------------------- */
/*uint32	auiILDB_CRC32[MAX_ILDB_CRC32];*/
/**
* @struct TS_ILDB_ROM
* @brief ���� Data(ILDB)�� ROM ��ü ����(CRC32�߰�)
*/
typedef struct {
	TS_ILDB_NEW		tROMILDB;
	uint32			auiILDB_CRC32[MAX_ILDB_CRC32];
} TS_ILDB_ROM;
/* ========================================================================= */
/* END : ���� Data(ILDB)�� ��ü ����                                         */
/* ========================================================================= */

/* ========================================================================= */
/* Route Data �� �κ� ����ü (Pointer Assign ��)                             */
/* ========================================================================= */
/* -------------------------------------------------------------------------
 * usRouteType
 *--------------------------------------------------------------------------
	0x0001 :�� ����
	0x0002 :TTB ����
	0x0004 :���� ����
	0x0008 :���� ����
	0x0010 :��ȯǥ�� ����
	0x0020 :��ȯ��ȣ�� ����
	0x0040 :��ȯ��ȣ�� ���
	0x0100 :������� ����
	
	Route Signal Limit
	 - 0x1000 : YY����
	 - 0x2000 : Y����
	 - 0x4000 : YG����
	 - 0x8000 : G����
-------------------------------------------------------------------------------*/
typedef struct {
	uint16	usPointPos;			/* ������ȯ��  Offset ��ġ */
	uint16	usCfltSgPos;		/* �����ȣ��  Offset ��ġ */
	uint16	usTcInfoPos;		/* �˵�����  Offset ��ġ */
	uint16	usPatRelsTcPos;		/* �������� �����˵�  Offset ��ġ */
	uint16	usExceptionPos;		/* ���� ��������  Offset ��ġ */
	uint16	usFromTc;			/* ���� ���� ���� �˵� */
	uint16	usDestTc1;			/* ���Թ��� ù��° Ȩ �˵�ȸ�� */
	uint16	usDestTc2;			/* ���Թ��� �ι�° Ȩ �˵�ȸ�ε� */
	uint16	usDestTc3;			/* ���Թ��� ����° Ȩ �˵�ȸ�� */
	uint16	usStartSg;			/* ���� ���� ��ȣ�� */
	uint8	ucArrPoint;			/* ������ */
	uint16	usRouteType;		/* �������� : ����ȣ, ��������, ��ȯǥ�� ���� ... */
	uint16	usDependSg;			/* ���� ��ȣ�� -- �߰��ȣ�� �� */
	uint16	usNextSg;			/* �� ���� ���� ��ȣ�� */
	uint16	usPrevDestTc;      	/* ������ Ȩ�˵� ���� �˵� */
	uint8	ucOverLkTm;			/* ���������� ���� �ð������� �ʿ��� ������ȯ���� �������� �ð�(��) */   
	/*
		usPrevDestTc �� ������ Ȩ�˵��� ���� �˵��̰�, ucOverLkTm(Release Time)�� �ʴ����� �ð��� ���ǵǾ� �ִ�. 
		�����˵�ȸ�ΰ� �����ǰ� ���� �˵�ȸ�ΰ� �����Ǹ�, ���ǵ� Release Time ���� ��, 
		Overlap ������ȯ�� �Ǵ� ��ȿ�� ������ȯ�⸦ �����Ѵ�. ����, Release Time�� 0�̸� ��� ���� �����Ѵ�.
	*/
} TS_ROUTE_HEAD;

/* ---------------------------------------------------
*   usPointCond
* ----------------------------------------------------
	bit15 set : ��������
	bit14 set : Overlap POINT
	bit13 set : reverse (reset : normal)
	bit12 set : ��ȿ�� �ð�����(TOK)
	bit11 set : ��/��ȯ ��ȣ�� �� ����
	bit10 set : ����/��ȯǥ�� �� ����
	bit9  set : ������������ Ovelap Set �� ��ȣ�� Obj ID
	bit8 ~ bit0 : ��ȣ�� Obj ID (0 ~ 511)
	            ������������ Set �� �˵� OBJ ID
	bit8 ~ bit0 : �˵� Obj ID (0 ~ 511)
*------------------------------------------------------*/
typedef struct {
	uint8	ucPointCount;		/* ���γ� ������ȯ�� �� - overlap ������ȯ�� ���� */
	struct {
		uint8	ucPointId;		/* ���ο� ����� ������ȯ�� ID */
		uint16	usPointCond;	/* ������ȯ���� ó�� ���� */
	} tPointInfo[MAX_RT_POINT];
} TS_ROUTE_POINTINFO;

typedef struct {
	uint8	ucCflSgCount;					/* �ش� ���ο� ����Ǵ� ��ȣ�� �� */
	uint16	ausCflSg[MAX_RT_CONFLICTSG]; 	/* ���� ��ȣ�� ID ����Ʈ */
} TS_ROUTE_CONFLICT_SG;

/* ---------------------------------------------------
*   usTrackCond
* ----------------------------------------------------
	bit0 ~ bit8 : �˵�ȸ�� Obj ID (0 ~ 511)
	bit9  set : ��/��ȯ ��ȣ�� �� ����
	bit10 set : ����/��ȯǥ�� �� ����
	bit11 Set : ��μ��� �˵�ȸ��
	bit12 Set : ������ȯ�� ����
	bit13 Set : ������ȯ�� Reverse Pos (RESET : Normal) (bit12 set�� ��� check)
	bit14 Set : ���� �� �̿��� ��ȣ���� �˵�ȸ��(�����Ѱ� �˵�)
*------------------------------------------------------*/
typedef struct {
	uint8	ucTrackCount;					/* ���γ� ���Ե� �˵� �� -- ������ Ȩ �˵�, ����˵� ���� */
	struct {
		uint16	usTrackCond;    			/* ��ȣ���� �˵� ���� */
		uint8	ucPoint;        			/* �����Ѱ� ������ȯ�� ? */
	} tTrackInfo[MAX_RT_SIGTRACK];
} TS_ROUTE_TRACKINFO;

typedef struct {
	uint8	ucPatRlsTcCount;				/* ������������ �˵� �� -- ������ Ȩ �˵� ���� */
	uint16	ausPatRlsTc[MAX_RT_RATRLSTC];   /* ������������ �˵� ����Ʈ  */
} TS_ROUTE_PATRLS_TC;

typedef struct {
	uint8	ucExceptionCount;				/* ���� �������� �� */
	struct {
		uint8	ucExType;					/* ���� �������� ����  */
		uint16	usObjId;					/*              */
	} tEception[MAX_RT_EXCEPTION];
} TS_ROUTE_EXCEPTION;

typedef struct {
	uint8	ucFunctionCode;
	uint16	usSMemPos;
	uint8	ucBitPos;
} TS_BIT_EXCEPTION;

/* ========================================================================= */
/* Track L/R Info Table�� Pointer Assign ��                                  */
/* ========================================================================= */
typedef struct {
	uint16	usBaseTc;						/** �ڱ� �˵�                    */
	uint16	usLTc;							/** ���� �˵�                    */
	uint16	usRTc;							/** ������  �˵�                 */
	uint8	ucPntCnt;						/** ������ȯ�� ���� ���� ��      */
	struct {
		uint8	ucPntIdx;					/** ������ȯ�� Obj ID            */
		uint8	ucPntPos;					/** ������ȯ�� ���� (N:1/R:2)    */
	} tPnt[MAX_TCLR_POINT];
} TS_TRACK_LR_INFO_TABLE;

typedef struct {
	uint8	ucPntCnt;
	uint8	aucPoint[MAX_TCLR_POINT];
} TS_POINT_IN_TRACK;

/* �ʱ� ���� DB */
typedef struct {
	uint16	usCTCPT[MAX_POINT];
	uint16	usCTCSG[MAX_SIGNAL];
	uint16	usCTCTC[MAX_TRACK];
	uint16	usCTCRT[MAX_ROUTE];
} TS_OBJ_LINK_CTCRCELM;
#endif
