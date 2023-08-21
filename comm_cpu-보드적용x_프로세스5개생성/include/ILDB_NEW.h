/* ========================================================================= /
17.01.24 :
 - [include] EisDefine.h include
17.01.25 :
 - [DB조정] DB Size 300,000byte 맞추기 위함 (baseinfo에 size, crc 다음부터(8byte제외) aucDummy까지 300K) 
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
* @brief 연동 Data Structure
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
/* 진로 Data의 Information                                                   */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ROUTEINFO
* @brief Route Data의 Information
*/
typedef struct {
	uint16	usRtDataStart;				/** 진로 Data의 ILDB 시작 위치       */
	uint16	usRouteCount;				/** 사용되는 진로의 수               */
	uint32	uiRtDataSize;				/** 전체 진로 Data의 크기            */
} TS_ROUTEINFO;
/* ------------------------------------------------------------------------- */
/* Object Data의 Information                                                 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_OBJINFO
* @brief Object Data의 Information
*/
typedef struct {
	uint16	usSmOffset;					/** SMEM의 Object 상태 시작 위치     */
	uint16	usObjCount;					/** Object의 수					     */
} TS_OBJINFO;
/* ------------------------------------------------------------------------- */
/* 연동 역 기본정보 Data                                                     */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ILDB_BASEINFO_TABLE
* @brief 연동 역 기본정보 Data
*/
typedef struct {
	uint32			uiILDBSize;						/** IDLB SIZE(CRC_DATA 전)*/
	uint32			uiAllCRC32;						/** 1000byte CRC에대한 CRC*/
	uint8			aucILDBVer[18];					/** ILDB Version          */

	TS_ROUTEINFO	tRouteInfo;						/** RouteData Infomation  */
	TS_OBJINFO		tSignalInfo;					/** SignalData Infomation */
	TS_OBJINFO		tTrackInfo;						/** TrackData Infomation  */
	TS_OBJINFO		tPointInfo;						/** PointData Infomation  */
	TS_OBJINFO		tGioInfo;						/** GIOData Infomation    */
	uint8			ucGenPointWkTm;					/** 일반Point Working Time*/
	uint8			ucHiPointWkTm;					/** 고속Point Working Time*/
	uint8			ucPointCotrolInterval;			/** Point간 제어 간견     */
	uint8			ucIOSCount;						/** IOS 수                */ /*[수정] 기존 신호기 check time을 사용하지 않아 변경*/
	uint8			ucInMdCount;					/** Input Modeule 수      */
	uint8			ucOutMdCount;					/** Output Modeule 수     */
	uint8			ucPdoMdCount;					/** PDO Modeule 수        */
	uint8			aucIoModuleInfo[MAX_IO_MODULE];	/** IO Module 정보    */
	uint8			aucIoModuleId[MAX_IO_MODULE];	/** IO Module ID      */
	uint8			aucTaskInfo[MAX_TASK];			/** Task 사용 정보        */
}TS_ILDB_BASEINFO_TABLE;
/* ------------------------------------------------------------------------- */
/* 선로전환기 Data                                                           */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ILDB_POINTINFO_TABLE
* @brief 선로전환기 Data
*/
typedef struct {
	uint8	ucPointType;					/** 선로전환기 유형              */
	uint16	usTC[MAX_TRACK_IN_POINTTABLE];	/** 선로전환기 포함 궤도         */
	uint16	usSW[MAX_POINT_IN_POINTTABLE];	/** 입력독립형 연관 선로전환기   */
} TS_ILDB_POINTINFO_TABLE;
/* ------------------------------------------------------------------------- */
/* 신호기 Data                                                               */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ILDB_SIGNALINFO_TABLE
* @brief 신호기 Data
*/
typedef struct {
	uint8	ucSignalType;								/** 신호기 유형      */
	uint8	ucSgAspectType;								/** 현시 계열        */
	uint8	ucApprLockTime;								/** 접근쇄정 시간    */
	uint16	usContinousSg;								/** 연속제어 신호기  */
	uint16	usFirstTrack;								/** 진로 첫궤도      */
	uint16	usFromTrack;								/** 신호기외방 궤도  */
	uint8	ucRouteCount;								/** 관련 진로 수     */
	uint16	usStartRoute;								/** 시작 진로        */
	uint16	usTtbArriveTc;								/** TTB 도착궤도     */
	uint16	ausApproachInfo[MAX_SGTBL_APPROACH_INFO];	/** 접근구간 정보    */
} TS_ILDB_SIGNALINFO_TABLE;
/* ------------------------------------------------------------------------- */
/* 궤도 Data                                                                 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ILDB_TRACKINFO_TABLE
* @brief 궤도 Data
*/
typedef struct {
	uint8	ucTrackType;				/** 궤도 유형                        */
	uint8	ucTwId;						/** 궤도가 포함한 열차번호 창 ID     */
	uint8	ucBlkSecTblId;				/** 폐색궤도일 경우 폐색정보 Data ID */
	uint8	ucBlkSecTCsId;				/** 폐색Data의 궤도 Data buff Index  */
	uint8	ucGioInfo;					/** 폐색과 연관된 GIO Data ID        */
	uint16	usApproachSignal[MAX_SGINTC];	/** 궤도 진입 신호기 정보        */
	uint8	ucTcLRinfoCnt;				/** 인접궤도 정보 수                 */
	uint32	uiTcLRinfoPos;				/** 인접궤도 테이블 시작 위치        */
} TS_ILDB_TRACKINFO_TABLE;
/* ------------------------------------------------------------------------- */
/* IO Information Data                                                       */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ILDB_IOINFO_TABLE
* @brief IO Information Data
*/
typedef struct {
	uint8	ucIoInfo;					/** IO Type 및 SMEM 위치의 Bit 위치  */
	uint16	usIoPosition;				/** IO bit의 SMEM byte offset        */
	uint8	ucObjectType;				/** IO의 해당 Object Type            */
	uint16	usObjectId;					/** IO의 해당 Object ID              */
	uint8	ucIoType;					/** Object Type 별 IO Type           */
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
	uint16	usCommonCount;					/** Common Element Data 수       */
	uint16	usTrackCount;					/** Track Element Data 수        */
	uint16	usTrackLabelCount;				/** Track 표찰 Element Data 수   */
	uint16	usSignalCount;					/** Signal Element Data 수       */
	uint16	usPointCount;					/** Point Element Data 수        */
	uint16	usGioCount;						/** GIO Element Data 수          */
	uint16	usRouteCount;					/** Rounte Element Data 수       */
	
	uint16	ausLocElmInfo[MAX_LOCAL_ELEMENT];
	
	/*uint16	usLocElmCommon[MAX_LOCAL_ELEMENT_COMMON];*/	/** Common Element   */
	/*uint16	usLocElmTrack[MAX_TRACK_NEW];	*/			/** Track Element    */
	/*uint16	usLocElmTrackLabel[MAX_TRACK_NEW];*/			/** 표찰 Element     */
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
		uint16	usSmemPos;				/** 연관 SMEM의 위치 정보            */
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
		uint16	usSmemPos;				/** 연관 SMEM의 위치 정보            */
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
	uint16	usBaseTc;					/** 기준 궤도 (CTC 궤도 및 etc..)    */
	uint8	ucTCsCnt;					/** ausSumTCs 수                     */
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
	uint16	usBlkSgId;					/** 폐색 연관 신호기                 */
	uint16	usSgId;						/** 장내 신호기(미존재 : 0)          */
	uint8	ucInDir;					/** 장내 방향 Left:0x01 / Right:0x02 */
	uint8	ucBlkSecType;				/** 폐색 유형                        */
	uint8	ucBlkCount;					/** 폐색궤도회로 수                  */
	uint16	ausBlkTc[MAX_BLOCK_TRACK];	/** 폐색에 포함된 궤도 정보          */
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
	uint8	aucDestNm[MAX_DESTPOINT][NAME_SIZE];				/** 도착점 Name               */
} TS_OBJECT_NAME;
/* ========================================================================= */
/* 연동 Data(ILDB)의 전체 구조                                               */
/* ========================================================================= */
/**
* @struct TS_ILDB
* @brief 연동 Data(ILDB)의 전체 구조
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
	TS_ILDB_BLOCKSECTION_TABLE		tBlkSecTbl[MAX_BLOCKSECTION];			/** 폐색구간 Table   */
	uint8							aucGIOInfoTbl[MAX_GENERAL_IO];			/** GIO Info Table   */
	uint32							auiInfoGeneral[MAX_INFO_GENERAL];		/** Bit Operation    */
	uint16							ausTwInfo[MAX_TRAINNO];					/** TW Info Table    */
																			/** 열번창기준궤도   */
	uint8							aucTrackLRInfoTbl[SIZE_TRACK_LINK_AREA];/** 인접궤도 정보    */																			
	TS_OBJECT_NAME					tEpuipNameTbl;							/** 명칭 Table       */
	
	TS_ILDB_RCELEMENTINFO_TABLE		tRcElmInfoTbl;
	TS_ILDB_SUMMARYTC_TABLE			tSumTcTbl[MAX_SUMMARYTC_TBL];
	
	/* [DB조정] DB Size 300,000byte 맞추기 위함 (baseinfo에 size, crc 다음부터(8byte제외) aucDummy까지 300K) */
	uint8							aucDummy[2983];
} TS_ILDB_NEW;
/* ------------------------------------------------------------------------- */
/*uint32	auiILDB_CRC32[MAX_ILDB_CRC32];*/
/**
* @struct TS_ILDB_ROM
* @brief 연동 Data(ILDB)의 ROM 전체 구조(CRC32추가)
*/
typedef struct {
	TS_ILDB_NEW		tROMILDB;
	uint32			auiILDB_CRC32[MAX_ILDB_CRC32];
} TS_ILDB_ROM;
/* ========================================================================= */
/* END : 연동 Data(ILDB)의 전체 구조                                         */
/* ========================================================================= */

/* ========================================================================= */
/* Route Data 각 부분 구조체 (Pointer Assign 용)                             */
/* ========================================================================= */
/* -------------------------------------------------------------------------
 * usRouteType
 *--------------------------------------------------------------------------
	0x0001 :주 진로
	0x0002 :TTB 진로
	0x0004 :유도 진로
	0x0008 :본선 진로
	0x0010 :입환표지 진로
	0x0020 :입환신호기 진로
	0x0040 :입환신호기 출발
	0x0100 :구내폐색 진로
	
	Route Signal Limit
	 - 0x1000 : YY현시
	 - 0x2000 : Y현시
	 - 0x4000 : YG현시
	 - 0x8000 : G현시
-------------------------------------------------------------------------------*/
typedef struct {
	uint16	usPointPos;			/* 선로전환기  Offset 위치 */
	uint16	usCfltSgPos;		/* 상충신호기  Offset 위치 */
	uint16	usTcInfoPos;		/* 궤도정보  Offset 위치 */
	uint16	usPatRelsTcPos;		/* 구분진로 쇄정궤도  Offset 위치 */
	uint16	usExceptionPos;		/* 진로 예외조건  Offset 위치 */
	uint16	usFromTc;			/* 진로 시작 이전 궤도 */
	uint16	usDestTc1;			/* 진입방향 첫번째 홈 궤도회로 */
	uint16	usDestTc2;			/* 진입방향 두번째 홈 궤도회로도 */
	uint16	usDestTc3;			/* 진입방향 세번째 홈 궤도회로 */
	uint16	usStartSg;			/* 진로 시작 신호기 */
	uint8	ucArrPoint;			/* 도착점 */
	uint16	usRouteType;		/* 진로형태 : 주진호, 유도진로, 입환표지 진로 ... */
	uint16	usDependSg;			/* 종속 신호기 -- 중계신호기 등 */
	uint16	usNextSg;			/* 현 진로 다음 신호기 */
	uint16	usPrevDestTc;      	/* 도착점 홈궤도 이전 궤도 */
	uint8	ucOverLkTm;			/* 열차도착에 의한 시간쇄정이 필요한 선로전환기의 쇄정유지 시간(초) */   
	/*
		usPrevDestTc 는 도착점 홈궤도의 이전 궤도이고, ucOverLkTm(Release Time)은 초단위의 시간이 정의되어 있다. 
		도착궤도회로가 점유되고 이전 궤도회로가 해정되면, 정의된 Release Time 만료 후, 
		Overlap 선로전환기 또는 유효장 선로전환기를 해정한다. 만약, Release Time이 0이면 대기 없이 해정한다.
	*/
} TS_ROUTE_HEAD;

/* ---------------------------------------------------
*   usPointCond
* ----------------------------------------------------
	bit15 set : 발점쇄정
	bit14 set : Overlap POINT
	bit13 set : reverse (reset : normal)
	bit12 set : 유효장 시간쇄정(TOK)
	bit11 set : 주/입환 신호기 용 조건
	bit10 set : 유도/입환표지 용 조건
	bit9  set : 구분해정조건 Ovelap Set 시 신호기 Obj ID
	bit8 ~ bit0 : 신호기 Obj ID (0 ~ 511)
	            구분해정조건 Set 시 궤도 OBJ ID
	bit8 ~ bit0 : 궤도 Obj ID (0 ~ 511)
*------------------------------------------------------*/
typedef struct {
	uint8	ucPointCount;		/* 진로내 선로전환기 수 - overlap 선로전환기 포함 */
	struct {
		uint8	ucPointId;		/* 진로와 관계된 선로전환기 ID */
		uint16	usPointCond;	/* 선로전환기의 처리 조건 */
	} tPointInfo[MAX_RT_POINT];
} TS_ROUTE_POINTINFO;

typedef struct {
	uint8	ucCflSgCount;					/* 해당 진로에 상충되는 신호기 수 */
	uint16	ausCflSg[MAX_RT_CONFLICTSG]; 	/* 상충 신호기 ID 리스트 */
} TS_ROUTE_CONFLICT_SG;

/* ---------------------------------------------------
*   usTrackCond
* ----------------------------------------------------
	bit0 ~ bit8 : 궤도회로 Obj ID (0 ~ 511)
	bit9  set : 주/입환 신호기 용 조건
	bit10 set : 유도/입환표지 용 조건
	bit11 Set : 폐로쇄정 궤도회로
	bit12 Set : 선로전환기 조건
	bit13 Set : 선로전환기 Reverse Pos (RESET : Normal) (bit12 set일 경우 check)
	bit14 Set : 진로 내 이외의 신호제어 궤도회로(접촉한계 궤도)
*------------------------------------------------------*/
typedef struct {
	uint8	ucTrackCount;					/* 진로내 포함된 궤도 수 -- 도착점 홈 궤도, 지장궤도 포함 */
	struct {
		uint16	usTrackCond;    			/* 신호제어 궤도 조건 */
		uint8	ucPoint;        			/* 접촉한계 선로전환기 ? */
	} tTrackInfo[MAX_RT_SIGTRACK];
} TS_ROUTE_TRACKINFO;

typedef struct {
	uint8	ucPatRlsTcCount;				/* 구분진로해정 궤도 수 -- 도착점 홈 궤도 포함 */
	uint16	ausPatRlsTc[MAX_RT_RATRLSTC];   /* 구분진로해정 궤도 리스트  */
} TS_ROUTE_PATRLS_TC;

typedef struct {
	uint8	ucExceptionCount;				/* 진로 예외조건 수 */
	struct {
		uint8	ucExType;					/* 진로 예외조건 형태  */
		uint16	usObjId;					/*              */
	} tEception[MAX_RT_EXCEPTION];
} TS_ROUTE_EXCEPTION;

typedef struct {
	uint8	ucFunctionCode;
	uint16	usSMemPos;
	uint8	ucBitPos;
} TS_BIT_EXCEPTION;

/* ========================================================================= */
/* Track L/R Info Table의 Pointer Assign 용                                  */
/* ========================================================================= */
typedef struct {
	uint16	usBaseTc;						/** 자기 궤도                    */
	uint16	usLTc;							/** 왼쪽 궤도                    */
	uint16	usRTc;							/** 오르쪽  궤도                 */
	uint8	ucPntCnt;						/** 선로전환기 방향 조건 수      */
	struct {
		uint8	ucPntIdx;					/** 선로전환기 Obj ID            */
		uint8	ucPntPos;					/** 선로전환기 방향 (N:1/R:2)    */
	} tPnt[MAX_TCLR_POINT];
} TS_TRACK_LR_INFO_TABLE;

typedef struct {
	uint8	ucPntCnt;
	uint8	aucPoint[MAX_TCLR_POINT];
} TS_POINT_IN_TRACK;

/* 초기 생성 DB */
typedef struct {
	uint16	usCTCPT[MAX_POINT];
	uint16	usCTCSG[MAX_SIGNAL];
	uint16	usCTCTC[MAX_TRACK];
	uint16	usCTCRT[MAX_ROUTE];
} TS_OBJ_LINK_CTCRCELM;
#endif
