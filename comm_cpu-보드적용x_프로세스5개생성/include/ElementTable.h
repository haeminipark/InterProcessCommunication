/* -------------------------------------------------------------------------- /
2017.02.03 :
 - [KRS수정부반영1] 진로제어 요구정보 추가
 - [KRS수정부반영2] OPC 고장상태 변수명 수정
 - [KRS수정부반영3] MTC 상태정보 추가
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
* @exe-env	WinXP SP3 이상.
* @library	not used.
* @brief    KRSEIS에서 사용되는 Element 용 Define File
* @see      main structure TS_ELEMENT_INDEX_TABLE, TS_ELEMENT_DATA_TABLE
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

#pragma once

/* ///////////////////////////////////////////////////////////////////////// */
/* Include Files                                                             */
/* ///////////////////////////////////////////////////////////////////////// */

/*#include	"EisDefine.h"*/
#include	"defconstant.h"			/** 전역으로 사용될 기본 데이터 타입 정의 해더파일 포함 */ 
#include	"defendian.h"			/** Endian 정의 해더파일 포함 */ 

#pragma pack(1)


/* ///////////////////////////////////////////////////////////////////////// */
/* Element 정보에 대한 정의                                                  */
/* ///////////////////////////////////////////////////////////////////////// */

/* Element Type 정의 */
#define  ELM_COMMON				 1U		 /** 역 공통정보. */
#define  ELM_TRACK_GI			 2U		 /** 궤도회로 일반정보. */
#define  ELM_TRACK_EX			 3U		 /** 궤도회로 확장(표찰)정보. */
#define  ELM_SIGNAL_GI			 4U		 /** 신호기 일반정보. */
#define  ELM_SIGNAL_EX			 5U		 /** 신호기 확장정보.(사용안함)  */
#define  ELM_POINT_GI			 6U		 /** 선로전환기 일반정보. */
#define  ELM_POINT_EX			 7U		 /** 선로전환기 확장정보.(사용안함) */
#define  ELM_ROUTE_GI			 8U		 /** 진로 일반정보. */
#define  ELM_GIO_GI				 9U		 /** GENERAL I/O 일반정보. */
#define  ELM_GIO_LX				10U		 /** GENERAL I/O 건널목 정보. */
#define  ELM_GIO_OBSTRUCTION	11U		 /** GENERAL I/O 지장물검지장치 고장정보. */
#define  ELM_GIO_INSULATION		12U		 /** GENERAL I/O 절연예고장치 고장정보. */
#define  ELM_GIO_EXRECTIFIER	13U		 /** 확장랙 정류기 고장정보. */
#define  ELM_EITEND				 0U		 /** ELEMENT TABLE 끝. */


/* Element Type 별 최대 Element 개수 */
#define LIMIT_CNT_ELM_IDX_COMMON	  32U	 /** 역 공통 정보 테이블의 최대 Element 개수 */
#define LIMIT_CNT_ELM_IDX_TRGI		 512U	 /** 궤도회로 일반정보 테이블의 최대Element 개수. 연동논리 S/W가  */
#define LIMIT_CNT_ELM_IDX_TREX		 512U	 /** 궤도회로 확장(표찰)정보 테이블의 최대Element 개수 */
#define LIMIT_CNT_ELM_IDX_SGGI		 512U	 /** 신호기 일반정보 테이블의 최대Element 개수 */
#define LIMIT_CNT_ELM_IDX_PTGI		 256U	 /** 선로전환기 일반정보 테이블의 최대Element 개수 */
#define LIMIT_CNT_ELM_IDX_GIO		  50U	 /** General I/O 일반정보 테이블의 최대Element 개수 */
#define LIMIT_CNT_ELM_IDX_RT		1024U	 /** 진로 일반정보 테이블의 최대Element 개수 */


/* Element Type 별 시작 Element No.ID */
#define ELM_IDNO_COMMON		1											 /** 역 공통 정보 Element No.ID는 1부터 시작함 */
#define ELM_IDNO_TRGI		LIMIT_CNT_ELM_IDX_COMMON					 /** 궤도회로 일반정보 Element No.ID는 33부터 시작함 */
#define ELM_IDNO_TREX		(ELM_IDNO_TRGI + LIMIT_CNT_ELM_IDX_TRGI)	 /** 궤도회로 확장(표찰)정보 Element No.ID는 545부터 시작함 */
#define ELM_IDNO_SGGI		(ELM_IDNO_TREX + LIMIT_CNT_ELM_IDX_TREX)	 /** 신호기 일반정보 Element No.ID는 1057부터 시작함 */
#define ELM_IDNO_PTGI		(ELM_IDNO_SGGI + LIMIT_CNT_ELM_IDX_SGGI)	 /** 선로전환기 일반정보 Element No.ID는 1569부터 시작함 */
#define ELM_IDNO_GIO		(ELM_IDNO_PTGI + LIMIT_CNT_ELM_IDX_PTGI)	 /** General I/O 일반정보 Element No.ID는 1825부터 시작함 */
#define ELM_IDNO_RT			(ELM_IDNO_GIO  + LIMIT_CNT_ELM_IDX_GIO)		 /** 진로의 일반정보 Element No.ID는 1875부터 시작하여 2898까지 정의됨 */


/* 역 공통정보의 Element Object ID 정의 */
#define ELM_IDNO_RUN			 1		 /** 시스템 기동 Element의 ID 및 TYPE */
#define ELM_IDNO_CTC			 2		 /** CTC 운영모드 Element의 ID 및 TYPE */
#define ELM_IDNO_LOCAL			 3		 /** LOCAL 운영모드 Element의 ID 및 TYPE */
#define ELM_IDNO_RC				 4		 /** RC 운영모드 Element의 ID 및 TYPE */
#define ELM_IDNO_SYS1			 5		 /** 1계 운용모드 Element의 ID 및 TYPE */
#define ELM_IDNO_SYS2			 6		 /** 2계 운용모드 Element의 ID 및 TYPE */
#define ELM_IDNO_N1				 7		 /** 한전전원 Element의 ID 및 TYPE */
#define ELM_IDNO_N2				 8		 /** 철도전원 Element의 ID 및 TYPE */
#define ELM_IDNO_UPS			 9		 /** 무정전전원장치 Element의 ID 및 TYPE */
#define ELM_IDNO_RECTIFIER1		10		 /** DC 24V 정류기들 Element의 ID 및 TYPE  */
#define ELM_IDNO_RECTIFIER2		11		 /** DC 24V 정류기들 Element의 ID 및 TYPE  */
#define ELM_IDNO_BATTERY		12		 /** 축전지 Element의 ID 및 TYPE */
#define ELM_IDNO_FUSE			13		 /** 휴즈들 Element의 ID 및 TYPE */
#define ELM_IDNO_PNPOWER		14		 /** 북쪽 선로전환기 전원공급 Element의 ID 및 TYPE */
#define ELM_IDNO_PSPOWER		15		 /** 남쪽 선로전환기 전원공급 Element의 ID 및 TYPE */
#define ELM_IDNO_SG_FAILURE		16		 /** 신호기 고장 Element의 ID 및 TYPE */
#define ELM_IDNO_PT_FAILURE		17		 /** 선로전환기 고장 Element의 ID 및 TYPE */
#define ELM_IDNO_TR_FAILURE		18		 /** 궤도회로 고장 Element의 ID 및 TYPE */
#define ELM_IDNO_RR_DOOR		19		 /** 계전기실 문 열림 Element의 ID 및 TYPE */
#define ELM_IDNO_SG_ALLSTOP		20		 /** 신호기 일괄정지 제어 Element의 ID 및 TYPE */
#define ELM_IDNO_SG_SHSTOP		21		 /** 입환신호기 소등제어 Element의 ID 및 TYPE */
#define ELM_IDNO_HEATER_N		22U		 /** 북쪽 선로전환기 히터제어 Element의 ID 및 TYPE */
#define ELM_IDNO_HEATER_S		23U		 /** 남쪽 선로전환기 히터제어 Element의 ID 및 TYPE */
#define ELM_IDNO_FUSE1			24		 /** FUSE 1 Element의 ID 및 TYPE */
#define ELM_IDNO_FUSE2			25		 /** FUSE 2 Element의 ID 및 TYPE */
#define ELM_IDNO_COM1			26		 /** COM1 Element의 ID 및 TYPE */
#define ELM_IDNO_COM2			27		 /** COM2 Element의 ID 및 TYPE */
#define ELM_IDNO_LCP1			28		 /** LCP 1 Element의 ID 및 TYPE */
#define ELM_IDNO_LCP2			29		 /** LCP 2 Element의 ID 및 TYPE */
#define ELM_IDNO_RES_30			30		 /** 시스템 예비용 Element의 ID 및 TYPE */
#define ELM_IDNO_RES_31			31		 /** 시스템 예비용 Element의 ID 및 TYPE */
#define ELM_IDNO_RES_32			32		 /** 시스템 예비용 Element의 ID 및 TYPE */

#ifdef _WINDOWS
/* ///////////////////////////////////////////////////////////////////////// */
/* 표시정보의 STATE 및 색상 정의                                             */
/* ///////////////////////////////////////////////////////////////////////// */
/* RUN State 정보 */
#define ELM_DISP_RUN_STATE_SYS1_RUN					0x04 /** 1계 기동 여부 : 0:대기, 1:기동 */
#define ELM_DISP_RUN_STATE_SYS2_RUN					0x08 /** 2계 기동 여부 : 0:대기, 1:기동 */
#define ELM_DISP_RUN_STATE_SYS1_GOOD				0x10 /** 1계 정상 여부 : 0:장애, 1:정상 */
#define ELM_DISP_RUN_STATE_SYS2_GOOD				0x20 /** 2계 정상 여부 : 0:장애, 1:정상 */
/* RUN State 표시정보 */
#define ELM_DISP_RUN_1_COLOR_GREEN					0x04 /** RUN(1계측) 버튼의 색상 : 녹색, AND masking으로 Setting  여부 확인 */
#define ELM_DISP_RUN_2_COLOR_GREEN					0x08 /** RUN(2계측) 버튼의 색상 : 녹색, AND masking으로 Setting  여부 확인 */

/* CTC/LOCAL/RC State 정보 */
#define ELM_DISP_OPMODE_STATE_CTC_REQ				0x01 /** CTC 전환요구 여부 : 0:없음, 1:전환요구 */
#define ELM_DISP_OPMODE_STATE_CTC_RUN				0x02 /** CTC 전환 여부 : 0:대기, 1:CTC 운전모드 */
#define ELM_DISP_OPMODE_STATE_LOCAL_REQ				0x04 /** LOCAL 전환요구 여부 : 0:없음, 1:전환요구 */
#define ELM_DISP_OPMODE_STATE_LOCAL_RUN				0x08 /** LOCAL 전환 여부 : 0:대기, 1:LOCAL 운전모드 */
#define ELM_DISP_OPMODE_STATE_RC_REQ				0x10 /** RC 전환요구 여부 : 0:없음, 1:전환요구 */
#define ELM_DISP_OPMODE_STATE_RC_RUN				0x20 /** RC 전환 여부 : 0:대기, 1:RC 운전모드 */
/* CTC/LOCAL/RC State 표시정보 */
#define ELM_DISP_OPMODE_CTC_COLOR_0_GRAY			0x00 /** CTC 버튼의 색상 : 회색 */
#define ELM_DISP_OPMODE_CTC_COLOR_1_GREEN_F			0x01 /** CTC 버튼의 색상 : 녹색 점멸 */
#define ELM_DISP_OPMODE_CTC_COLOR_2_GREEN			0x02 /** CTC 버튼의 색상 : 녹색 */
#define ELM_DISP_OPMODE_LOCAL_COLOR_0_GRAY			0x00 /** LOCAL 버튼의 색상 : 회색 */
#define ELM_DISP_OPMODE_LOCAL_COLOR_1_GREEN_F		0x04 /** LOCAL 버튼의 색상 : 녹색 점멸 */
#define ELM_DISP_OPMODE_LOCAL_COLOR_2_GREEN			0x08 /** LOCAL 버튼의 색상 : 녹색 */
#define ELM_DISP_OPMODE_RC_COLOR_0_GRAY				0x00 /** RC 버튼의 색상 : 회색 */
#define ELM_DISP_OPMODE_RC_COLOR_1_GREEN_F			0x10 /** RC 버튼의 색상 : 녹색 점멸 */
#define ELM_DISP_OPMODE_RC_COLOR_2_GREEN			0x20 /** RC 버튼의 색상 : 녹색 */
/* Mask */
#define ELM_DISP_OPMEDE_CTC_MASK					0x03 /** D0~D1 */
#define ELM_DISP_OPMEDE_LOCAL_MASK					0x0C /** D2~D3 */
#define ELM_DISP_OPMEDE_RC_MASK						0x30 /** D4~D5 */

/* COMMON 표준 ALARM, GGOD State mask */
#define ELM_DISP_ITEM_STATE_ALARM					0x10 /** element alarm state */
#define ELM_DISP_ITEM_STATE_GOOD					0x20 /** element good state */

/* SYSTEM 1계 State 정보 */
#define ELM_DISP_SYS1_STATE_ALARMON					0x10 /** 1계 알람경보 발생 여부 : 0:경보정지, 1:경보발생 */
#define ELM_DISP_SYS1_STATE_SYSGOOD					0x20 /** 1계 정상 여부 : 0:고장, 1:정상 */
#define ELM_DISP_SYS1_STATE_SYSACTIVE				0x40 /** 1계 Active 여부 : 0:Statndby, 1:Active */
/* SYSTEM 1계 State 표시정보 */
#define ELM_DISP_SYS1_COLOR_0_RED					0x00 /** SYS1 버튼의 색상 : 적색 */
#define ELM_DISP_SYS1_COLOR_1_RED_F					0x10 /** SYS1 버튼의 색상 : 적색 점멸 */
#define ELM_DISP_SYS1_COLOR_2_GRAY					0x20 /** SYS1 버튼의 색상 : 회색 */
#define ELM_DISP_SYS1_COLOR_6_GREEN					0x60 /** SYS1 버튼의 색상 : 녹색 */
/* Mask */
#define ELM_DISP_SYS1_MASK							0x70 /** D4~D6 */
/* SYSTEM 2계 State 정보 */
#define ELM_DISP_SYS2_STATE_ALARMON					0x10 /** 2계 알람경보 발생 여부 : 0:경보정지, 1:경보발생 */
#define ELM_DISP_SYS2_STATE_SYSGOOD					0x20 /** 2계 정상 여부 : 0:고장, 1:정상 */
#define ELM_DISP_SYS2_STATE_SYSACTIVE				0x40 /** 2계 Active 여부 : 0:Statndby, 1:Active */
/* SYSTEM 2계 State 표시정보 */
#define ELM_DISP_SYS2_COLOR_0_RED					0x00 /** SYS2 버튼의 색상 : 적색 */
#define ELM_DISP_SYS2_COLOR_1_RED_F					0x10 /** SYS2 버튼의 색상 : 적색 점멸 */
#define ELM_DISP_SYS2_COLOR_2_GRAY					0x20 /** SYS2 버튼의 색상 : 회색 */
#define ELM_DISP_SYS2_COLOR_6_GREEN					0x60 /** SYS2 버튼의 색상 : 녹색 */
/* Mask */
#define ELM_DISP_SYS2_MASK							0x70 /** D4~D6 */
/* 한전전원 N1 State 정보 */
#define ELM_DISP_N1_STATE_ALARMON					0x10 /** N! 전원 알람경보 발생 여부 : 0:경보정지, 1:경보발생 */
#define ELM_DISP_N1_STATE_GOOD						0x20 /** N1 전원 정상 여부 : 0:고장, 1:정상 */
#define ELM_DISP_N1_STATE_ACTIVE					0x40 /** N1 전원 공급 여부 : 0:Statndby, 1:active */
/* 한전전원 N1 State 표시정보 */
#define ELM_DISP_N1_COLOR_0_RED						0x00 /** N1 버튼의 색상 : 적색 */
#define ELM_DISP_N1_COLOR_1_RED_F					0x10 /** N1 버튼의 색상 : 적색 점멸 */
#define ELM_DISP_N1_COLOR_2_GRAY					0x20 /** N1 버튼의 색상 : 회색 */
#define ELM_DISP_N1_COLOR_6_GREEN					0x60 /** N1 버튼의 색상 : 녹색 */
/* Mask */
#define ELM_DISP_N1_MASK							0x70 /** D4~D6 */
/* 철도전원 N2 State 정보 */
#define ELM_DISP_N2_STATE_ALARMON					0x10 /** N2 전원 알람경보 발생 여부 : 0:경보정지, 1:경보발생 */
#define ELM_DISP_N2_STATE_GOOD						0x20 /** N2 전원 정상 여부 : 0:고장, 1:정상 */
#define ELM_DISP_N2_STATE_ACTIVE					0x40 /** N2 전원 공급 여부 : 0:Statndby, 1:active */
/* 철도전원 N2 State 표시정보 */
#define ELM_DISP_N2_COLOR_0_RED						0x00 /** N2 버튼의 색상 : 적색 */
#define ELM_DISP_N2_COLOR_1_RED_F					0x10 /** N2 버튼의 색상 : 적색 점멸 */
#define ELM_DISP_N2_COLOR_2_GRAY					0x20 /** N2 버튼의 색상 : 회색 */
#define ELM_DISP_N2_COLOR_6_GREEN					0x60 /** N2 버튼의 색상 : 녹색 */
/* Mask */
#define ELM_DISP_N2_MASK							0x70 /** D4~D6 */
/* UPS State 정보 */
#define ELM_DISP_UPS_STATE_ALARMON					0x10 /** UPS 알람경보 발생 여부 : 0:경보정지, 1:경보 발생 */
#define ELM_DISP_UPS_STATE_GOOD						0x20 /** UPS 정상 여부 : 0:고장, 1:정상 */
/* UPS State 표시정보 */
#define ELM_DISP_UPS_COLOR_0_RED					0x00 /** UPS 버튼의 색상 : 적색 */
#define ELM_DISP_UPS_COLOR_1_RED_F					0x10 /** UPS 버튼의 색상 : 적색 점멸 */
#define ELM_DISP_UPS_COLOR_2_GREEN					0x20 /** UPS 버튼의 색상 : 녹색 */
/* Mask */
#define ELM_DISP_UPS_MASK							0x30 /** D4~D5 */
/* RECTIFIER 1,2 State 정보 */
#define ELM_DISP_RECTIFIER_STATE_ALARMON			0x10 /** RECTIFIER 알람경보 발생 여부 : 0:경보정지, 1:경보 발생 */
#define ELM_DISP_RECTIFIER_STATE_GOOD				0x20 /** RECTIFIER 정상 여부 : 0:고장, 1:정상 */
/* RECTIFIER State 표시정보 */
#define ELM_DISP_RECTIFIER_COLOR_0_RED				0x00 /** RECTIFIER 버튼의 색상 : 적색 */
#define ELM_DISP_RECTIFIER_COLOR_1_RED_F			0x10 /** RECTIFIER 버튼의 색상 : 적색 점멸 */
#define ELM_DISP_RECTIFIER_COLOR_2_GREEN			0x20 /** RECTIFIER 버튼의 색상 : 녹색 */
/* Mask */
#define ELM_DISP_RECTIFIER_MASK						0x30 /** D4~D5 */
/* BATTERY State 정보 */
#define ELM_DISP_BATTERY_STATE_ALARMON				0x10 /** BATTERY 알람경보 발생 여부 : 0:경보정지, 1:경보 발생 */
#define ELM_DISP_BATTERY_STATE_GOOD					0x20 /** BATTERY 정상 여부 : 0:고장, 1:정상 */
/* BATTERY State 표시정보 */
#define ELM_DISP_BATTERY_COLOR_0_RED				0x00 /** BATTERY 버튼의 색상 : 적색 */
#define ELM_DISP_BATTERY_COLOR_1_RED_F				0x10 /** BATTERY 버튼의 색상 : 적색 점멸 */
#define ELM_DISP_BATTERY_COLOR_2_GREEN				0x20 /** BATTERY 버튼의 색상 : 녹색 */
/* Mask */
#define ELM_DISP_BATTERY_MASK						0x30 /** D4~D5 */
/* FUSE State 정보 */
#define ELM_DISP_FUSE_STATE_ALARMON					0x10 /** FUSE 알람경보 발생 여부 : 0:경보정지, 1:경보 발생 */
#define ELM_DISP_FUSE_STATE_GOOD					0x20 /** FUSE 정상 여부 : 0:고장, 1:정상 */
/* FUSE State 표시정보 */
#define ELM_DISP_FUSE_COLOR_0_RED					0x00 /** FUSE 버튼의 색상 : 적색 */
#define ELM_DISP_FUSE_COLOR_1_RED_F					0x10 /** FUSE 버튼의 색상 : 적색 점멸 */
#define ELM_DISP_FUSE_COLOR_2_GREEN					0x20 /** FUSE 버튼의 색상 : 녹색 */
/* Mask */
#define ELM_DISP_FUSE_MASK							0x30 /** D4~D5 */
/* 북쪽 선로전환기 전원 공급 State 정보 */
#define ELM_DISP_PNPOWER_STATE_ALARMON				0x10 /** 북쪽 선로전환기 전원 공급 알람경보 발생 여부 : 0:경보정지, 1:경보 발생 */
#define ELM_DISP_PNPOWER_STATE_GOOD					0x20 /** 북쪽 선로전환기 전원 공급 정상 여부 : 0:고장, 1:정상 */
/* 북쪽 선로전환기 전원 공급 State 표시정보 */
#define ELM_DISP_PNPOWER_COLOR_0_RED				0x00 /** PNPOWER 버튼의 색상 : 적색 */
#define ELM_DISP_PNPOWER_COLOR_1_RED_F				0x10 /** PNPOWER 버튼의 색상 : 적색 점멸 */
#define ELM_DISP_PNPOWER_COLOR_2_GREEN				0x20 /** PNPOWER 버튼의 색상 : 녹색 */
/* Mask */
#define ELM_DISP_PNPOWER_MASK						0x30 /** D4~D5 */
/* 남쪽 선로전환기 전원 공급 State 정보 */
#define ELM_DISP_PSPOWER_STATE_ALARMON				0x10 /** 남쪽 선로전환기 전원 공급 알람경보 발생 여부 : 0:경보정지, 1:경보 발생 */
#define ELM_DISP_PSPOWER_STATE_GOOD					0x20 /** 남쪽 선로전환기 전원 공급 정상 여부 : 0:고장, 1:정상 */
/* 남쪽 선로전환기 전원 공급 State 표시정보 */
#define ELM_DISP_PSPOWER_COLOR_0_RED				0x00 /** PSPOWER 버튼의 색상 : 적색 */
#define ELM_DISP_PSPOWER_COLOR_1_RED_F				0x10 /** PSPOWER 버튼의 색상 : 적색 점멸 */
#define ELM_DISP_PSPOWER_COLOR_2_GREEN				0x20 /** PSPOWER 버튼의 색상 : 녹색 */
/* Mask */
#define ELM_DISP_PSPOWER_MASK						0x30 /** D4~D5 */
/* Signal Failure State 정보 */
#define ELM_DISP_UPS_STATE_ALARMON					0x10 /** Signal Failure 알람경보 발생 여부 : 0:경보정지, 1:경보 발생 */
#define ELM_DISP_UPS_STATE_GOOD						0x20 /** Signal Failure 여부 : 0:고장, 1:정상 */
/* Signal Failure State 표시정보 */
#define ELM_DISP_SGFAILURE_COLOR_0_RED				0x00 /**  Signal Failure 버튼의 색상 : 적색 */
#define ELM_DISP_SGFAILURE_COLOR_1_RED_F			0x10 /**  Signal Failure 버튼의 색상 : 적색 점멸 */
#define ELM_DISP_SGFAILURE_COLOR_2_GREEN			0x20 /**  Signal Failure 버튼의 색상 : 녹색 */
/* Mask */
#define ELM_DISP_SGFAILURE_MASK						0x30 /** D4~D5 */
/* Point Failure State 정보 */
#define ELM_DISP_PTFAILURE_STATE_ALARMON			0x10 /** Point Failure 알람경보 발생 여부 : 0:경보정지, 1:경보 발생 */
#define ELM_DISP_PTFAILURE_STATE_GOOD				0x20 /** Point Failure 여부 : 0:고장, 1:정상 */
/* Point Failure  State 표시정보 */
#define ELM_DISP_PTFAILURE_COLOR_0_RED				0x00 /** Point Failure 버튼의 색상 : 적색 */
#define ELM_DISP_PTFAILURE_COLOR_1_RED_F			0x10 /** Point Failure 버튼의 색상 : 적색 점멸 */
#define ELM_DISP_PTFAILURE_COLOR_2_GREEN			0x20 /** Point Failure 버튼의 색상 : 녹색 */
/* Mask */
#define ELM_DISP_PTFAILURE_MASK						0x30 /** D4~D5 */
/* Track Failure State 정보 */
#define ELM_DISP_TRFAILURE_STATE_ALARMON			0x10 /** Track Failure 알람경보 발생 여부 : 0:경보정지, 1:경보 발생 */
#define ELM_DISP_TRFAILURE_STATE_GOOD				0x20 /** Track Failure 여부 : 0:고장, 1:정상 */
/* Track Failure  State 표시정보 */
#define ELM_DISP_TRFAILURE_COLOR_0_RED				0x00 /** TRFAIL 버튼의 색상 : 적색 */
#define ELM_DISP_TRFAILURE_COLOR_1_RED_F			0x10 /** TRFAIL 버튼의 색상 : 적색 점멸 */
#define ELM_DISP_TRFAILURE_COLOR_2_GREEN			0x20 /** TRFAIL 버튼의 색상 : 녹색 */
/* Mask */
#define ELM_DISP_TRFAIL_MASK						0x30 /** D4~D5 */
/* 신호기계실 출입문 열림 State 정보 */
#define ELM_DISP_RRDOOR_STATE_ALARMON				0x10 /** 신호기계실 출입문 열림 알람경보 발생 여부 : 0:경보정지, 1:경보 발생 */
#define ELM_DISP_RRDOOR_STATE_GOOD					0x20 /** 신호기계실 출입문 열림 여부 : 0:열림, 1:딛힘 */
/* 신호기계실 출입문 열림 State 표시정보 */
#define ELM_DISP_RRDOOR_COLOR_0_RED					0x00 /** RRDOOR 버튼의 색상 : 적색, 출입문 열림 (경보정지) */
#define ELM_DISP_RRDOOR_COLOR_1_RED_F				0x10 /** RRDOOR 버튼의 색상 : 적색 점멸, 출입문 열림 (경보발생) */
#define ELM_DISP_RRDOOR_COLOR_2_GREEN				0x20 /** RRDOOR 버튼의 색상 : 녹색, 출입문 닫힘 */
/* Mask */
#define ELM_DISP_RRDOOR_MASK						0x30 /** D4~D5 */
/* 신호기 일괄정지 제어 state 표시정보 */
#define ELM_DISP_SGSTOP_ISSET						0x10 /** 신호기 일괄정지 제어 여부 : 0:제어없음, 1:제어 중, AND masking으로 Setting  여부 확인 */
#define ELM_DISP_SGSTOP_COLOR_1_RED_F				0x20 /** 신호기 일괄정지 버튼의 색상 : 적색점멸, AND masking으로 Setting  여부 확인 */
/* 입환표지(신호기) 소등 제어 state 표시정보 */
#define ELM_DISP_SHOFF_COLOR_1_LIGHTGRAY			0x10 /** 입환표지(신호기) 소등 버튼의 색상 : 흐린회색, AND masking으로 Setting  여부 확인 */
#define ELM_DISP_SHOFF_ISSET_REQ					0x20 /** 입환표지(신호기) 소등 제어 여부 : 0:제어없음, 1:제어 중, AND masking으로 Setting  여부 확인 */
/* 북쪽 히터 제어 state 정보 */
#define ELM_DISP_NHEATER_STATE_ALARMON				0x10 /** 북쪽 히터 알람경보 발생 여부 : 0:경보정지, 1:경보 발생 */
#define ELM_DISP_NHEATER_STATE_GOOD					0x20 /** 북쪽 히터 정상여부 : 0:고장, 1:정상 */
#define ELM_DISP_NHEATER_CTRL_ON					0x40 /** 북쪽 히터 ON 제어 버튼의 색상 : 녹색, AND masking으로 Setting  여부 확인 */
#define ELM_DISP_NHEATER_ISSET						0x80 /** 북쪽 히터 ON 제어 요구 여부 : 0:제어없음, 1:제어 중, AND masking으로 Setting  여부 확인 */
/* 북쪽 히터 제어 state 표시정보 */
#define ELM_DISP_NHEATER_COLOR_0_RED				0x00 /** 북쪽 히터의 색상 : 적색, 장애(경보음 정지) */
#define ELM_DISP_NHEATER_COLOR_1_RED_F				0x10 /** 북쪽 히터의 색상 : 적색점멸, 장애(경보음 발생) */
#define ELM_DISP_NHEATER_COLOR_2_LIGHTGRAY			0x20 /** 북쪽 히터의 색상 : 흐린회색, 정상(경보음 정지) */
#define ELM_DISP_NHEATER_COLOR_3_RED_F				0x30 /** 북쪽 히터의 색상 : 적색점멸(흐린회색), 정상(경보음 발생) */
#define ELM_DISP_NHEATER_COLOR_4_RED				0x40 /** 북쪽 히터의 색상 : 적색, 장애(경보음 정지) */
#define ELM_DISP_NHEATER_COLOR_5_RED_F				0x50 /** 북쪽 히터의 색상 : 적색점멸, 장애(경보음 발생) */
#define ELM_DISP_NHEATER_COLOR_6_GREEN				0x60 /** 북쪽 히터의 색상 : 녹색, 정상(경보음 정지) */
#define ELM_DISP_NHEATER_COLOR_7_RED_F				0x70 /** 북쪽 히터의 색상 : 적색점멸, 정상(경보음 발생) */
/* 남쪽 히터 제어 state 정보 */
#define ELM_DISP_SHEATER_STATE_ALARMON				0x10 /** 남쪽 히터 알람경보 발생 여부 : 0:경보정지, 1:경보 발생 */
#define ELM_DISP_SHEATER_STATE_GOOD					0x20 /** 남쪽 히터 정상여부 : 0:고장, 1:정상 */
#define ELM_DISP_SHEATER_CTRL_ON					0x40 /** 남쪽 히터 ON 제어 버튼의 색상 : 녹색, AND masking으로 Setting  여부 확인 */
#define ELM_DISP_SHEATER_ISSET						0x80 /** 남쪽 히터 ON 제어 요구 여부 : 0:제어없음, 1:제어 중, AND masking으로 Setting  여부 확인 */
/* 남쪽 히터 제어 state 표시정보 */
#define ELM_DISP_SHEATER_COLOR_0_RED				0x00 /** 남쪽 히터의 색상 : 적색, 장애(경보음 정지) */
#define ELM_DISP_SHEATER_COLOR_1_RED_F				0x10 /** 남쪽 히터의 색상 : 적색점멸, 장애(경보음 발생) */
#define ELM_DISP_SHEATER_COLOR_2_LIGHTGRAY			0x20 /** 남쪽 히터의 색상 : 흐린회색, 정상(경보음 정지) */
#define ELM_DISP_SHEATER_COLOR_3_RED_F				0x30 /** 남쪽 히터의 색상 : 적색점멸(흐린회색), 정상(경보음 발생) */
#define ELM_DISP_SHEATER_COLOR_4_RED				0x40 /** 남쪽 히터의 색상 : 적색, 장애(경보음 정지) */
#define ELM_DISP_SHEATER_COLOR_5_RED_F				0x50 /** 남쪽 히터의 색상 : 적색점멸, 장애(경보음 발생) */
#define ELM_DISP_SHEATER_COLOR_6_GREEN				0x60 /** 남쪽 히터의 색상 : 녹색, 정상(경보음 정지) */
#define ELM_DISP_SHEATER_COLOR_7_RED_F				0x70 /** 남쪽 히터의 색상 : 적색점멸, 정상(경보음 발생) */
/* FUSE1 State 정보 */
#define ELM_DISP_FUSE1_STATE_ALARMON				0x10 /** FUSE1 알람경보 발생 여부 : 0:경보정지, 1:경보 발생 */
#define ELM_DISP_FUSE1_STATE_GOOD					0x20 /** FUSE1 정상여부 : 0:고장, 1:정상 */
/* FUSE2 State 정보 */
#define ELM_DISP_FUSE2_STATE_ALARMON				0x10 /** FUSE2 알람경보 발생 여부 : 0:경보정지, 1:경보 발생 */
#define ELM_DISP_FUSE2_STATE_GOOD					0x20 /** FUSE2 정상여부 : 0:고장, 1:정상 */
/* COM1, COM2 State 정보 */
#define ELM_DISP_COM_STATE_FAILURE					0x00 /** COM1 or COM2 통신장애 발생 */
#define ELM_DISP_COM_STATE_ALARMON					0x10 /** COM1 or COM2 알람경보 발생 여부 : 0:경보정지, 1:경보 발생 */
#define ELM_DISP_COM_STATE_GOOD						0x20 /** COM1 or COM2 정상여부 : 0:고장, 1:정상 */
#define ELM_DISP_COM_STATE_ACTIVE					0x40 /** COM1 or COM2 ACTIVE MAIN 여부 : 0:STANDBY, 1:ACTIVE MAIN */
/* LCP1, LCP2 State 정보 */
#define ELM_DISP_LCP_STATE_FAILURE					0x00 /** LCP1 통신장애 발생 */
#define ELM_DISP_LCP_STATE_ALARMON					0x10 /** LCP1 알람경보 발생 여부 : 0:경보정지, 1:경보 발생 */
#define ELM_DISP_LCP_STATE_GOOD						0x20 /** LCP1 정상여부 : 0:고장, 1:정상 */
#define ELM_DISP_LCP_STATE_ACTIVE					0x40 /** COM1 or COM2 ACTIVE MAIN 여부 : 0:STANDBY, 1:ACTIVE MAIN */

/* 궤도회로 일반정보 State 정보 */
#define ELM_DISP_TR_GI_STATE_TKUNOCC				0x01 /** 점유 여부 : 0:점유, 1:비점유 */
#define ELM_DISP_TR_GI_STATE_TKROUTE				0x02 /** 진로조사선별 및 재취급 여부 : 0:평상시, 1:진로조사선별 또는 재취급 대기(황색) */
#define ELM_DISP_TR_GI_STATE_TKLRSET				0x04 /** 진로쇄정 여부 : 0:진로해정, 1:진로쇄정 */
#define ELM_DISP_TR_GI_STATE_TKHALARM				0x08 /** 장내접근 여부 : 0:평상시, 1:장내접근 */
#define ELM_DISP_TR_GI_STATE_TKFAILURE				0x10 /** 부정낙하 : 0:정상, 1:부정낙하 */
#define ELM_DISP_TR_GI_STATE_TKREQ					0x20 /** 재취급 가능여부, 0:(재)취급불가, 1:(재)취급가능 */
#define ELM_DISP_TR_GI_STATE_TKEMRELEASE			0x40 /** 구분진로비상해정 가능여부, 0:취급불가, 1:취급가능 */
/* 궤도회로 일반정보 State 표시정보 */
#define ELM_DISP_TR_GI_COLOR_00_RED					0x00 /** TR 의 색상 : 적색, 점유 */
#define ELM_DISP_TR_GI_COLOR_01_WHITE				0x01 /** TR 의 색상 : 백색, 비점유 */
#define ELM_DISP_TR_GI_COLOR_02_RED					0x02 /** TR 의 색상 : 적색, 진로 조사선별 중인 궤도의 점유 */
#define ELM_DISP_TR_GI_COLOR_04_YELLOW				0x04 /** TR 의 색상 : 황색, 진로 조사선별 중인 비점유 궤도 */
#define ELM_DISP_TR_GI_COLOR_05_RED					0x05 /** TR 의 색상 : 적색, 진로쇄정 중인 궤도의 점유 */
#define ELM_DISP_TR_GI_COLOR_06_GREEN				0x06 /** TR 의 색상 : 녹색, 진로쇄정 중인 비점유 궤도 */
/*#define ELM_DISP_TR_GI_COLOR_07_					0x07*/ /** TR 의 색상 : 변화없음-무시, 오류데이터 (진로조사선별 중인 궤도의 진로쇄정설정) */
#define ELM_DISP_TR_GI_COLOR_08_RED_F_YELLOW		0x08 /** TR 의 색상 : 적색점멸(황색바탕), 장내접근이 발생한 점유 궤도 */
/*#define ELM_DISP_TR_GI_COLOR_09_					0x09*/ /** TR 의 색상 : 변화없음-무시, 오류데이터 (비점유 상태에서 장내접근 설정) */
#define ELM_DISP_TR_GI_COLOR_0A_RED_F_WHITE			0x0A /** TR 의 색상 : 적색점멸(황색바탕), 진로조사선별 상태의 장내접근이 발생한 점유 궤도 */
/*#define ELM_DISP_TR_GI_COLOR_0B_					0x0B*/ /** TR 의 색상 : 변화없음-무시, 오류데이터 (비점유 상태에서 장내접근 설정된 진로조사선별 중인 궤도) */
#define ELM_DISP_TR_GI_COLOR_0C_RED_F_GREEN			0x0C /** TR 의 색상 : 적색점멸(녹색바탕), 진로쇄정 상태에서 장내접근이 발생한 점유 궤도 */
/*#define ELM_DISP_TR_GI_COLOR_0D_					0x0D*/ /** TR 의 색상 : 변화없음-무시, 오류데이터 (비점유 상태에서 장내접근 설정된 진로쇄정 중인 궤도) */
#define ELM_DISP_TR_GI_COLOR_0E_RED_F_WHITE			0x0E /** TR 의 색상 : 적색점멸(녹색바탕), 진로조사선별 및 진로쇄정 중인 점유 궤도의 장내접근 발생 */
/*#define ELM_DISP_TR_GI_COLOR_0F_					0x0F*/ /** TR 의 색상 : 변화없음-무시, 오류데이터 (비점유 상태에서 장내접근 설정된 진로조사선별 및 진로쇄정) */
#define ELM_DISP_TR_GI_COLOR_10_RED_A				0x10 /** TR 의 색상 : 적색(궤도전체), 부정낙하로 점유된 궤도  */
/*#define ELM_DISP_TR_GI_COLOR_11_					0x11*/ /** TR 의 색상 : 변화없음-무시, 오류데이터 (비점유 상태에서 부정낙하 설정) */
#define ELM_DISP_TR_GI_COLOR_12_RED_A				0x12 /** TR 의 색상 : 적색(궤도전체), 진로조사선별 중인 점유궤도의 부정낙하 설정 */
/*#define ELM_DISP_TR_GI_COLOR_13_					0x13*/ /** TR 의 색상 : 변화없음-무시, 오류데이터 (비점유 상태에서 부정낙하 설정) */
#define ELM_DISP_TR_GI_COLOR_14_RED_A				0x14 /** TR 의 색상 : 적색(궤도전체), 진로쇄정 중인 점유궤도의 부정낙하 설정 */
/*#define ELM_DISP_TR_GI_COLOR_15_					0x15*/ /** TR 의 색상 : 변화없음-무시, 오류데이터 (비점유 상태에서 부정낙하 설정)  */
#define ELM_DISP_TR_GI_COLOR_16_RED_A				0x16 /** TR 의 색상 : 적색(궤도전체), 진로조사선별 및 진로쇄정 중인 점유 궤도의 부정낙하 설정 */
/*#define ELM_DISP_TR_GI_COLOR_17_					0x17*/ /** TR 의 색상 : 변화없음-무시, 오류데이터 (비점유 상태에서 부정낙하 설정) */
#define ELM_DISP_TR_GI_COLOR_18_RED_A				0x18 /** TR 의 색상 : 적색(궤도전체), 장내접근이 발생한 점유 궤도의 부정낙하 설정 */
/*#define ELM_DISP_TR_GI_COLOR_19_					0x19*/ /** TR 의 색상 : 변화없음-무시, 오류데이터 (비점유 상태에서 부정낙하 설정) */
#define ELM_DISP_TR_GI_COLOR_1A_RED_A				0x1A /** TR 의 색상 : 적색(궤도전체), 진로조사선별 중인 장내접근이 발생한 점유 궤도의 부정낙하 설정 */
/*#define ELM_DISP_TR_GI_COLOR_1B_					0x1B*/ /** TR 의 색상 : 변화없음-무시, 오류데이터 (비점유 상태에서 부정낙하 설정) */
#define ELM_DISP_TR_GI_COLOR_1C_RED_A				0x1C /** TR 의 색상 : 적색(궤도전체), 진로쇄정 중인 장내접근이 발생한 점유 궤도의 부정낙하 설정 */
/*#define ELM_DISP_TR_GI_COLOR_1D_					0x1D*/ /** TR 의 색상 : 변화없음-무시, 오류데이터 (비점유 상태에서 부정낙하 설정) */
#define ELM_DISP_TR_GI_COLOR_1E_RED_A				0x1E /** TR 의 색상 : 적색(궤도전체), 로조사선별 및 진로쇄정 중인 장내접근이 발생한 점유 궤도의 부정낙하 설정 */
/*#define ELM_DISP_TR_GI_COLOR_1F_					0x1F*/ /** TR 의 색상 : 변화없음-무시, 오류데이터 (비점유 상태에서 부정낙하 설정) */
/* Mask */
#define ELM_DISP_TR_GI_STATE_MASK					0x1F /** D0~D4 */
/* 궤도회로 확장정보(운전취급주의표(표찰)) 설정 State 표시정보 */
#define ELM_DISP_TR_EX_COLOR_01_CAUTIONLABEL1			0x01 /** 표찰번호1 : 표찰#1 보선장치입환 */
#define ELM_DISP_TR_EX_COLOR_02_CAUTIONLABEL1			0x02 /** 표찰번호1 : 표찰#2 선로사용중지 */
#define ELM_DISP_TR_EX_COLOR_03_CAUTIONLABEL1			0x03 /** 표찰번호1 : 표찰#3 차단공사 */
#define ELM_DISP_TR_EX_COLOR_04_CAUTIONLABEL1			0x04 /** 표찰번호1 : 표찰#4 전차선단전 */
#define ELM_DISP_TR_EX_COLOR_05_CAUTIONLABEL1			0x05 /** 표찰번호1 : 표찰#5 트로리사용중 */
#define ELM_DISP_TR_EX_COLOR_06_CAUTIONLABEL1			0x06 /** 표찰번호1 : 표찰#6 수신호 */
#define ELM_DISP_TR_EX_COLOR_07_CAUTIONLABEL1			0x07 /** 표찰번호1 : 표찰#7 대용폐색 */
#define ELM_DISP_TR_EX_COLOR_08_CAUTIONLABEL1			0x08 /** 표찰번호1 : 표찰#8 통신식 */
#define ELM_DISP_TR_EX_COLOR_09_CAUTIONLABEL1			0x09 /** 표찰번호1 : 표찰#9 열차퇴행 */
#define ELM_DISP_TR_EX_COLOR_0A_CAUTIONLABEL1			0x0A /** 표찰번호1 : 표찰#10 전차선없음 */
#define ELM_DISP_TR_EX_COLOR_01_CAUTIONLABEL2			0x10 /** 표찰번호2 : 표찰#1 보선장치입환 */
#define ELM_DISP_TR_EX_COLOR_02_CAUTIONLABEL2			0x20 /** 표찰번호2 : 표찰#2 선로사용중지 */
#define ELM_DISP_TR_EX_COLOR_03_CAUTIONLABEL2			0x30 /** 표찰번호2 : 표찰#3 차단공사 */
#define ELM_DISP_TR_EX_COLOR_04_CAUTIONLABEL2			0x40 /** 표찰번호2 : 표찰#4 전차선단전 */
#define ELM_DISP_TR_EX_COLOR_05_CAUTIONLABEL2			0x50 /** 표찰번호2 : 표찰#5 트로리사용중 */
#define ELM_DISP_TR_EX_COLOR_06_CAUTIONLABEL2			0x60 /** 표찰번호2 : 표찰#6 수신호 */
#define ELM_DISP_TR_EX_COLOR_07_CAUTIONLABEL2			0x70 /** 표찰번호2 : 표찰#7 대용폐색 */
#define ELM_DISP_TR_EX_COLOR_08_CAUTIONLABEL2			0x80 /** 표찰번호2 : 표찰#8 통신식 */
#define ELM_DISP_TR_EX_COLOR_09_CAUTIONLABEL2			0x90 /** 표찰번호2 : 표찰#9 열차퇴행 */
#define ELM_DISP_TR_EX_COLOR_0A_CAUTIONLABEL2			0xA0 /** 표찰번호2 : 표찰#10 전차선없음 */
/* Mask */
#define ELM_DISP_TR_EX_CAUTIONLABEL1_MASK				0x0F /** D0~D3 */
#define ELM_DISP_TR_EX_CAUTIONLABEL2_MASK				0xF0 /** D4~D7 */

/* 신호기 일반정보 State 정보 */
#define ELM_DISP_SG_STATE_UDO_GO						0x01 /** (무)유도신호기 진행여부 : 0:소등, 1:진행현시 */
#define ELM_DISP_SG_STATE_TTB_ON						0x02 /** TTB ON/OFF 여부 : 0:OFF, 1:ON */
#define ELM_DISP_SG_STATE_LOCK_ON						0x04 /** 신호기쇄정 여부 : 0:해정, 1:쇄정 */
#define ELM_DISP_SG_STATE_APPROACH_LOCK_ON				0x08 /** 신호기 접근/보류 쇄정 여부 : 0:해정, 1:쇄정 */
#define ELM_DISP_SG_STATE_MAINLAMP_GO					0x10 /** 주신호등 진행현시 여부 : 0:정지현시, 1:진행현시 */
#define ELM_DISP_SG_STATE_MAINLAMP_FAILURE				0x20 /** 주신호등 고장 여부 : 0:정상, 1:고장 */
#define ELM_DISP_SG_STATE_RTSEL_ON						0x40 /** 진로선별등 점등 여부 : 0:소등, 1:점등 */
#define ELM_DISP_SG_STATE_RTSEL_FAILURE					0x80 /** 진로선별등 고장 여부 : 0:정상, 1:고장 */
/* 신호기 일반정보 State 표시정보 */
/* (무)유도신호기등 State 표시정보 */
#define ELM_DISP_SG_ULAMP_COLOR_1_GREEN					0x01 /** (무)유도등의 색상 : 0:흑색-소등, 1:녹색-진행, AND masking으로 Setting  여부 확인 */
/* TTB 설정등 State 표시정보 */
#define ELM_DISP_SG_TTBLAMP_COLOR_1_YELLOW				0x02 /** TTB 등의 색상 : 0:흑색-OFF, 1:황색-ON,글자색:녹색, AND masking으로 Setting  여부 확인 */
/* 신호기의 쇄정등 State 표시정보 */
#define ELM_DISP_SG_LOCKLAMP_COLOR_0_BLACK				0x00 /** 쇄정등의 색상 : 흑색 */
#define ELM_DISP_SG_LOCKLAMP_COLOR_1_YELLOW				0x04 /** 쇄정등의 색상 : 황색 */
#define ELM_DISP_SG_LOCKLAMP_COLOR_2_YELLOW_F_BLACK		0x08 /** 쇄정등의 색상 : 황색점멸 (흑색바탕) */
#define ELM_DISP_SG_LOCKLAMP_COLOR_3_YELLOW_F_BLACK		0x0C /** 쇄정등의 색상 : 황색점멸 (흑색바탕) */
/* Mask */
#define ELM_DISP_SG_LOCKLAMP_MASK						0x0C /** D2~D3 */
/* 신호기의 신호등 State 표시정보 */
#define ELM_DISP_SG_MAINLAMP_COLOR_0_RED				0x00 /** 신호등의 색상 : 적색 */
#define ELM_DISP_SG_MAINLAMP_COLOR_1_GREEN				0x10 /** 신호등의 색상 : 녹색 */
#define ELM_DISP_SG_MAINLAMP_COLOR_2_RED_F_BLACK		0x20 /** 신호등의 색상 : 적색점멸 (흑색바탕) */
#define ELM_DISP_SG_MAINLAMP_COLOR_3_GREEN_F_BLACK		0x30 /** 신호등의 색상 : 녹색점멸 (흑색바탕) */
/* Mask */
#define ELM_DISP_SG_MAINLAMP_MASK						0x30 /** D4~D5 */
/* 신호기의 진로선별등 State 표시정보 */
#define ELM_DISP_SG_RTSELM_COLOR_0_RED					0x00 /** 진로선별등의 색상 : 흐린회색 */
#define ELM_DISP_SG_RTSELM_COLOR_1_YELLOW				0x40 /** 진로선별등의 색상 : 황색 */
#define ELM_DISP_SG_RTSELM_COLOR_2_YELLOW_F_LGRAY		0x80 /** 진로선별등의 색상 : 황색점멸(흐린회색바탕) */
/* Mask */
#define ELM_DISP_SG_RTSELM_MASK							0xC0 /** D6~D7 */

/* 구내폐색 신호기 State 표시정보 */
#define ELM_DISP_SG_INBLOCK_COLOR_0_RED					0x00 /** 구내폐색 신호기의 Lamp 색상 : 적색 */
#define ELM_DISP_SG_INBLOCK_COLOR_1_GREEN				0x10 /** 구내폐색 신호기의 Lamp 색상 : 녹색 */
#define ELM_DISP_SG_INBLOCK_COLOR_2_RED_F_BLACK			0x20 /** 구내폐색 신호기의 Lamp 색상 : 적색 점멸 (흑색바탕) */
#define ELM_DISP_SG_INBLOCK_COLOR_3_GREEN_F_BLACK		0x30 /** 구내폐색 신호기의 Lamp 색상 : 녹색 점멸 (흑색바탕) */
/* Mask */
#define ELM_DISP_SG_INBLOCK_MASK						0x30 /** D4~D5 */
/* 폐색구간 신호기 State 표시정보 */
#define ELM_DISP_SG_OUTBLOCK_COLOR_0_RED				0x00 /** 폐색구간 신호기의 Lamp 색상 : 적색 */
#define ELM_DISP_SG_OUTBLOCK_COLOR_1_WHITE				0x10 /** 폐색구간 신호기의 Lamp 색상 : 백색 */
#define ELM_DISP_SG_OUTBLOCK_COLOR_2_RED_F_BLACK		0x20 /** 폐색구간 신호기의 Lamp 색상 : 적색 점멸 (흑색바탕) */
#define ELM_DISP_SG_OUTBLOCK_COLOR_3_RED_F_BLACK		0x30 /** 폐색구간 신호기의 Lamp 색상 : 적색 점멸 (흑색바탕) */
/* Mask */
#define ELM_DISP_SG_OUTBLOCK_MASK						0x30 /** D4~D5 */

/* 연동/자동 폐색 State 표시정보 */
#define ELM_DISP_BLOCKSSTART_COLOR_0_LIGHTGRAY			0x00 /** 연동/자동 폐색의 방향등 색상 : 흐린회색, 평상시(소등) */
#define ELM_DISP_BLOCKSSTART_COLOR_1_YELLOW_F_LIGHTGRAY	0x01 /** 연동/자동 폐색의 방향등 색상 : 황색점멸(흐린회색바탕), 출발/취소요구 (출발역-출발방향표)(6초간 점멸) */
#define ELM_DISP_BLOCKSSTART_COLOR_2_YELLOW				0x02 /** 연동/자동 폐색의 방향등 색상 : 황색, 출발승인/열차통과 (출발역-출발방향표) */
/*#define ELM_DISP_BLOCKSSTART_COLOR_3_					0x03*/ /** 연동/자동 폐색의 방향등 색상 : 변화없음 - 무시, 데이터 오류 */
#define ELM_DISP_BLOCKSSTART_COLOR_4_RED				0x04 /** 연동/자동 폐색의 방향등 색상 : 적색, 열차진입 (출발역-출발방향표) */
/*#define ELM_DISP_BLOCKSSTART_COLOR_5_					0x05*/ /** 연동/자동 폐색의 방향등 색상 : 변화없음 - 무시, 데이터 오류 */
/*#define ELM_DISP_BLOCKSSTART_COLOR_6_					0x06*/ /** 연동/자동 폐색의 방향등 색상 : 변화없음 - 무시, 데이터 오류 */
/*#define ELM_DISP_BLOCKSSTART_COLOR_7_					0x07*/ /** 연동/자동 폐색의 방향등 색상 : 변화없음 - 무시, 데이터 오류 */
#define ELM_DISP_BLOCKSSTART_COLOR_8_RED_F_LIGHTGRAY	0x08 /** 연동/자동 폐색의 방향등 색상 : 적색점멸(흐린회색바탕), 개통요구 중 (출발역-출발방향표) */
/*#define ELM_DISP_BLOCKSSTART_COLOR_9_					0x09*/ /** 연동/자동 폐색의 방향등 색상 : 변화없음 - 무시, 데이터 오류 */
/*#define ELM_DISP_BLOCKSSTART_COLOR_10_					0x0A*/ /** 연동/자동 폐색의 방향등 색상 : 변화없음 - 무시, 데이터 오류 */
/*#define ELM_DISP_BLOCKSSTART_COLOR_11_					0x0B*/ /** 연동/자동 폐색의 방향등 색상 : 변화없음 - 무시, 데이터 오류 */
/*#define ELM_DISP_BLOCKSSTART_COLOR_12_					0x0C*/ /** 연동/자동 폐색의 방향등 색상 : 변화없음 - 무시, 데이터 오류 */
/*#define ELM_DISP_BLOCKSSTART_COLOR_13_					0x0D*/ /** 연동/자동 폐색의 방향등 색상 : 변화없음 - 무시, 데이터 오류 */
/*#define ELM_DISP_BLOCKSSTART_COLOR_14_					0x0E*/ /** 연동/자동 폐색의 방향등 색상 : 변화없음 - 무시, 데이터 오류 */
/*#define ELM_DISP_BLOCKSSTART_COLOR_15_					0x0F*/ /** 연동/자동 폐색의 방향등 색상 : 변화없음 - 무시, 데이터 오류 */
#define ELM_DISP_BLOCKSHOME_COLOR_0_LIGHTGRAY			0x00 /** 연동/자동 폐색의 방향등 색상 : 흐린회색, 평상시(소등) */
#define ELM_DISP_BLOCKSHOME_COLOR_1_YELLOW_F_LIGHTGRAY	0x10 /** 연동/자동 폐색의 방향등 색상 : 황색점멸(흐린회색바탕), 출발/취소요구 (도착역-장내방향표)(6초간 점멸) */
#define ELM_DISP_BLOCKSHOME_COLOR_2_YELLOW				0x20 /** 연동/자동 폐색의 방향등 색상 : 황색, 장내응답 (도착역-장내방향표) */
/*#define ELM_DISP_BLOCKSHOME_COLOR_3_					0x30*/ /** 연동/자동 폐색의 방향등 색상 : 변화없음 - 무시, 데이터 오류 */
#define ELM_DISP_BLOCKSHOME_COLOR_4_RED					0x40 /** 연동/자동 폐색의 방향등 색상 : 적색, 열차진입/열차대기 (도착역-장내방향표) */
/*#define ELM_DISP_BLOCKSHOME_COLOR_5_					0x50*/ /** 연동/자동 폐색의 방향등 색상 : 변화없음 - 무시, 데이터 오류 */
/*#define ELM_DISP_BLOCKSHOME_COLOR_6_					0x60*/ /** 연동/자동 폐색의 방향등 색상 : 변화없음 - 무시, 데이터 오류 */
/*#define ELM_DISP_BLOCKSHOME_COLOR_7_					0x70*/ /** 연동/자동 폐색의 방향등 색상 : 변화없음 - 무시, 데이터 오류 */
#define ELM_DISP_BLOCKSHOME_COLOR_8_RED_F_LIGHTGRAY		0x80 /** 연동/자동 폐색의 방향등 색상 : 적색점멸(흐린회색바탕), 개통요구 (도착역-장내방향표) */
/*#define ELM_DISP_BLOCKSHOME_COLOR_9_					0x90*/ /** 연동/자동 폐색의 방향등 색상 : 변화없음 - 무시, 데이터 오류 */
/*#define ELM_DISP_BLOCKSHOME_COLOR_10_					0xA0*/ /** 연동/자동 폐색의 방향등 색상 : 변화없음 - 무시, 데이터 오류 */
/*#define ELM_DISP_BLOCKSHOME_COLOR_11_					0xB0*/ /** 연동/자동 폐색의 방향등 색상 : 변화없음 - 무시, 데이터 오류 */
/*#define ELM_DISP_BLOCKSHOME_COLOR_12_					0xC0*/ /** 연동/자동 폐색의 방향등 색상 : 변화없음 - 무시, 데이터 오류 */
/*#define ELM_DISP_BLOCKSHOME_COLOR_13_					0xD0*/ /** 연동/자동 폐색의 방향등 색상 : 변화없음 - 무시, 데이터 오류 */
/*#define ELM_DISP_BLOCKSHOME_COLOR_14_					0xE0*/ /** 연동/자동 폐색의 방향등 색상 : 변화없음 - 무시, 데이터 오류 */
/*#define ELM_DISP_BLOCKSHOME_COLOR_15_					0xF0*/ /** 연동/자동 폐색의 방향등 색상 : 변화없음 - 무시, 데이터 오류 */
/* Mask */
#define ELM_DISP_BLOCKSSTART_MASK						0x0F /** D0~D3 */
#define ELM_DISP_BLOCKSHOE_MASK							0xF0 /** D4~D7 */

/* 선로전환기 일반정보 State 정보 */
#define ELM_DISP_PT_GI_STATE_N_POSITION					0x01 /** 선로전환기 정위 여부 : 0:아님, 1:정위상태 */
#define ELM_DISP_PT_GI_STATE_R_POSITION					0x02 /** 선로전환기 반위 여부 : 0:아님, 1:반위상태 */
#define ELM_DISP_PT_GI_STATE_LOCK						0x04 /** 선로전환기 쇄정 여부 : 0:해정, 1:쇄정(철사 or 진로)  */
#define ELM_DISP_PT_GI_STATE_FAILURE					0x08 /** 선로전환기 고장 여부 : 0:정상, 1:고장 */
#define ELM_DISP_PT_GI_STATE_OL_ONTIMER					0x10 /** 선로전환기 오버랩 해정 시소 여부 : 0:없음, 1:시소 중 */
#define ELM_DISP_PT_GI_STATE_SWLOCK						0x20 /** 선로전환기 전환 불가여부 : 0:전환가능, 1:전환불가 */
#define ELM_DISP_PT_GI_STATE_NWRI						0x40 /** 선로전환기 WR 제어 정위 여부 : 0:제어없음, 1:정위 제어 */
#define ELM_DISP_PT_GI_STATE_RWRI						0x80 /** 선로전환기 WR 제어 반위 여부 : 0:제어없음, 1:반위 제어 */
/* 선로전환기 일반정보 State 표시정보 */
#define ELM_DISP_PT_GI_COLOR_00_WHITE_BLACK_QMARK		0x00 /** 선로전환기 쇄정등 색상 : ? 백색글씨 (흑색바탕), 불일치 상태 */
#define ELM_DISP_PT_GI_COLOR_01_WHITE_BLACK_PSIGN		0x01 /** 선로전환기 쇄정등 색상 : + 백색글씨 (흑색바탕), 정위 상태 */
#define ELM_DISP_PT_GI_COLOR_02_WHITE_BLACK_MSIGN		0x02 /** 선로전환기 쇄정등 색상 : - 백색글씨 (흑색바탕), 반위 상태 */
/*#define ELM_DISP_PT_GI_COLOR_03_						0x03*/ /** 선로전환기 쇄정등 색상 : 무시 - 데이터 오류 (정위 & 반위 동시 설정 상태) */
#define ELM_DISP_PT_GI_COLOR_04_BLACK_YELLOW_QMARK		0x04 /** 선로전환기 쇄정등 색상 : ? 흑색글씨 (황색바탕) */
#define ELM_DISP_PT_GI_COLOR_05_BLACK_YELLOW_PSIGN		0x05 /** 선로전환기 쇄정등 색상 : + 흑색글씨 (황색바탕) */
#define ELM_DISP_PT_GI_COLOR_06_BLACK_YELLOW_MSIGN		0x06 /** 선로전환기 쇄정등 색상 : - 흑색글씨 (황색바탕) */
/*#define ELM_DISP_PT_GI_COLOR_07_						0x07*/ /** 선로전환기 쇄정등 색상 : 무시 - 데이터 오류 (정위 & 반위 동시 설정 상태) */
#define ELM_DISP_PT_GI_COLOR_08_WHITE_BLACK_QMARK		0x08 /** 선로전환기 쇄정등 색상 : ? 백색글씨 (흑색바탕) */
#define ELM_DISP_PT_GI_COLOR_09_WHITE_BLACK_PSIGN		0x09 /** 선로전환기 쇄정등 색상 : + 백색글씨 (흑색바탕) */
#define ELM_DISP_PT_GI_COLOR_0A_WHITE_BLACK_MSIGN		0x0A /** 선로전환기 쇄정등 색상 : - 백색글씨 (흑색바탕) */
/*#define ELM_DISP_PT_GI_COLOR_0B_						0x0B*/ /** 선로전환기 쇄정등 색상 : 무시 - 데이터 오류 (정위 & 반위 동시 설정 상태) */
#define ELM_DISP_PT_GI_COLOR_0C_BLACK_YELLOW_QMARK		0x0C /** 선로전환기 쇄정등 색상 : ? 흑색글씨 (황색바탕) */
#define ELM_DISP_PT_GI_COLOR_0D_BLACK_YELLOW_PSIGN		0x0D /** 선로전환기 쇄정등 색상 : + 흑색글씨 (황색바탕) */
#define ELM_DISP_PT_GI_COLOR_0E_BLACK_YELLOW_MSIGN		0x0E /** 선로전환기 쇄정등 색상 : - 흑색글씨 (황색바탕) */
/*#define ELM_DISP_PT_GI_COLOR_0F_						0x0F*/ /** 선로전환기 쇄정등 색상 : 무시 - 데이터 오류 (정위 & 반위 동시 설정 상태) */
#define ELM_DISP_PT_GI_COLOR_10_BLACK_YELLOW_F_QMARK	0x10 /** 선로전환기 쇄정등 색상 : ? 흑색글씨 (황색점멸, 흑색바탕) */
#define ELM_DISP_PT_GI_COLOR_11_BLACK_YELLOW_F_PSIGN	0x11 /** 선로전환기 쇄정등 색상 : + 흑색글씨 (황색점멸, 흑색바탕) */
#define ELM_DISP_PT_GI_COLOR_12_BLACK_YELLOW_F_MSIGN	0x12 /** 선로전환기 쇄정등 색상 : - 흑색글씨 (황색점멸, 흑색바탕) */
/*#define ELM_DISP_PT_GI_COLOR_13_						0x13*/ /** 선로전환기 쇄정등 색상 : 무시 - 데이터 오류 (정위 & 반위 동시 설정 상태) */
#define ELM_DISP_PT_GI_COLOR_14_WHITE_BLACK_QMARK		0x14 /** 선로전환기 쇄정등 색상 : ? 흑색글씨 (황색점멸, 흑색바탕) */
#define ELM_DISP_PT_GI_COLOR_15_WHITE_BLACK_PSIGN		0x15 /** 선로전환기 쇄정등 색상 : + 흑색글씨 (황색점멸, 흑색바탕) */
#define ELM_DISP_PT_GI_COLOR_16_WHITE_BLACK_MSIGN		0x16 /** 선로전환기 쇄정등 색상 : - 흑색글씨 (황색점멸, 흑색바탕) */
/*#define ELM_DISP_PT_GI_COLOR_17_						0x17*/ /** 선로전환기 쇄정등 색상 : 무시 - 데이터 오류 (정위 & 반위 동시 설정 상태) */
#define ELM_DISP_PT_GI_COLOR_18_WHITE_BLACK_QMARK		0x18 /** 선로전환기 쇄정등 색상 : ? 흑색글씨 (황색점멸, 흑색바탕) */
#define ELM_DISP_PT_GI_COLOR_19_WHITE_BLACK_PSIGN		0x19 /** 선로전환기 쇄정등 색상 : + 흑색글씨 (황색점멸, 흑색바탕) */
#define ELM_DISP_PT_GI_COLOR_1A_WHITE_BLACK_MSIGN		0x1A /** 선로전환기 쇄정등 색상 : - 흑색글씨 (황색점멸, 흑색바탕) */
/*#define ELM_DISP_PT_GI_COLOR_1B_						0x1B*/ /** 선로전환기 쇄정등 색상 : 무시 - 데이터 오류 (정위 & 반위 동시 설정 상태) */
#define ELM_DISP_PT_GI_COLOR_1C_WHITE_BLACK_QMARK		0x1C /** 선로전환기 쇄정등 색상 : ? 흑색글씨 (황색점멸, 흑색바탕) */
#define ELM_DISP_PT_GI_COLOR_1D_WHITE_BLACK_PSIGN		0x1D /** 선로전환기 쇄정등 색상 : + 흑색글씨 (황색점멸, 흑색바탕) */
#define ELM_DISP_PT_GI_COLOR_1E_WHITE_BLACK_MSIGN		0x1E /** 선로전환기 쇄정등 색상 : - 흑색글씨 (황색점멸, 흑색바탕) */
/*#define ELM_DISP_PT_GI_COLOR_1F_						0x1F*/ /** 선로전환기 쇄정등 색상 : 무시 - 데이터 오류 (정위 & 반위 동시 설정 상태) */
/* 선로전환기 고장여부 state 정보*/
#define ELM_DISP_PT_GI_FAILURE							0x08 /** D3, AND masking으로 Setting  여부 확인 */
/* 선로전환기 전환 중 state 표시정보 */
#define ELM_DISP_PT_GI_COLOR_1_ORANGE_F					0x20 /** 선로전환기 포함된 궤도회로 색상 : 황색점멸(궤도회로표시바탕), AND masking으로 Setting  여부 확인  */
/* 선로전환기 전환 State 정보 */
#define ELM_DISP_PT_GI_MOV_0_NONE						0x00 /** 선로전환기 전환 중 상태 : 평상시  */
#define ELM_DISP_PT_GI_MOV_1_MOVING_NOCTRL				0x20 /** 선로전환기 전환 중 상태 : 전환중 설정, 제어요구 없는 상태임(불일치)  */
#define ELM_DISP_PT_GI_MOV_2_REQ_N						0x40 /** 선로전환기 전환 중 상태 : 정위 전환 요구 */
#define ELM_DISP_PT_GI_MOV_3_MOVING_N					0x60 /** 선로전환기 전환 중 상태 : 정위로 전환 중 */
#define ELM_DISP_PT_GI_MOV_4_REQ_R						0x80 /** 선로전환기 전환 중 상태 : 반위 전환 요구 */
#define ELM_DISP_PT_GI_MOV_5_MOVING_R					0xA0 /** 선로전환기 전환 중 상태 : 반위로 전환 중 */
/*#define ELM_DISP_PT_GI_MOV_6_							0xC0*/ /** 선로전환기 전환 중 상태 : 무시-데이터 오류 (정위 & 반위 전환 요구) */
/*#define ELM_DISP_PT_GI_MOV_7_							0xE0*/ /** 선로전환기 전환 중 상태 : 무시-데이터 오류 (정위 & 반위 전환 중) */
/* Mask */
#define ELM_DISP_PT_GI_STATE_MASK						0x1F /** D0~D4 */
#define ELM_DISP_PT_GI_MOVING_MASK						0xE0 /** D5~D7 */

/* General I/O 건널목 고장정보 State 정보 */
#define ELM_DISP_LX_STATE_ALARMON						0x10 /** LX 알람경보 발생 여부 : 0:경보정지, 1:경보 발생 */
#define ELM_DISP_LX_STATE_GOOD							0x20 /** LX 정상여부 : 0:고장, 1:정상 */
/* General I/O 건널목 고장정보 State 표시정보 */
#define ELM_DISP_LX_COLOR_0_RED							0x00 /** General I/O 건널목 고장정보의 버튼 색상 : 적색 */
#define ELM_DISP_LX_COLOR_1_RED_F						0x10 /** General I/O 건널목 고장정보의 버튼 색상 : 적색 점멸 */
#define ELM_DISP_LX_COLOR_2_GREEN						0x20 /** General I/O 건널목 고장정보의 버튼 색상 : 녹색 */
/* Mask */
#define ELM_DISP_LX_STATE_MASK							0x30 /** D4~D5 */

/* General I/O 지장물검지장치 State 정보 */
#define ELM_DISP_OBSTRUCTION_STATE_ALARMON				0x10 /** 지장물검지장치 고장정보 알람경보 발생 여부 : 0:경보정지, 1:경보 발생 */
#define ELM_DISP_OBSTRUCTION_STATE_GOOD					0x20 /** 지장물검지장치 고장정보 정상여부 : 0:고장, 1:정상 */
#define ELM_DISP_OBSTRUCTION_STATE_SECURITYRELEASE		0x40 /** 지장물검지장치 고장정보 보안해제 취급여부: 0:보안해제취소, 1:보안해제 취급 */
/* General I/O 지장물검지장치 고장정보 State 표시정보 */
#define ELM_DISP_OBSTRUCTION_COLOR_0_RED				0x00 /** General I/O 지장물검지장치 고장정보의 버튼 색상 : 적색 */
#define ELM_DISP_OBSTRUCTION_COLOR_1_RED_F				0x10 /** General I/O 지장물검지장치 고장정보의 버튼 색상 : 적색 점멸 */
#define ELM_DISP_OBSTRUCTION_COLOR_2_GREEN				0x20 /** General I/O 지장물검지장치 고장정보의 버튼 색상 : 녹색 */
#define ELM_DISP_OBS_SECURITY_RELEASE_COLOR_1_YELLOW	0x40 /** General I/O 지장물검지장치 고장정보의 심볼 색상 : 0:흐린회색-보안해제취소, 1:황색-보안해제취급, AND masking으로 Setting  여부 확인 */
/* Mask */
#define ELM_DISP_OBSTRUCTION_STATE_MASK					0x30 /** D4~D5 */

/* General I/O 절연구간예고장치 고장정보 State 정보 */
#define ELM_DISP_INSULATION_STATE_SYS1ALARM				0x01 /** General I/O 절연구간예고장치 고장정보의 1계 알람경보 여부 : 0:경보정지, 1;경보발생, AND masking으로 Setting  여부 확인 */
#define ELM_DISP_INSULATION_STATE_SYS1GOOD				0x02 /** General I/O 절연구간예고장치 고장정보의 1계 고장 여부 : 0:고장, 1;정상 */
#define ELM_DISP_INSULATION_STATE_SYS1RUN				0x04 /** General I/O 절연구간예고장치 고장정보의 1계 운용 여부 : 0:대기, 1;운용 */
#define ELM_DISP_INSULATION_STATE_SYS2ALARM				0x10 /** General I/O 절연구간예고장치 고장정보의 2계 알람경보 여부 : 0:경보정지, 1;경보발생, AND masking으로 Setting  여부 확인 */
#define ELM_DISP_INSULATION_STATE_SYS2GOOD				0x20 /** General I/O 절연구간예고장치 고장정보의 2계 고장 여부 : 0:고장, 1;정상 */
#define ELM_DISP_INSULATION_STATE_SYS2RUN				0x40 /** General I/O 절연구간예고장치 고장정보의 2계 운용 여부 : 0:대기, 1;운용 */
/* General I/O 절연구간예고장치 고장정보 State 표시정보 */
#define ELM_DISP_INSULATION_SYS1_COLOR_0_RED			0x00 /** General I/O 절연구간예고장치 고장정보의 1계 버튼 색상 : 적색, 1계 고장 (경보정지) */
#define ELM_DISP_INSULATION_SYS1_COLOR_1_RED_F			0x01 /** General I/O 절연구간예고장치 고장정보의 1계 버튼 색상 : 적색 점멸, 1계 고장 (경보발생) */
#define ELM_DISP_INSULATION_SYS1_COLOR_2_LIGHTGRAY		0x02 /** General I/O 절연구간예고장치 고장정보의 1계 버튼 색상 : 흐린회색, 1계 정상 (경보정지) */
#define ELM_DISP_INSULATION_SYS1_COLOR_3_				0x03 /** General I/O 절연구간예고장치 고장정보의 1계 버튼 색상 : 변화없음 - 무시, 데이터 오류 (경보정지) */
#define ELM_DISP_INSULATION_SYS1_COLOR_4_				0x04 /** General I/O 절연구간예고장치 고장정보의 1계 버튼 색상 : 변화없음 - 무시, 데이터 오류 (경보정지) */
#define ELM_DISP_INSULATION_SYS1_COLOR_5_				0x05 /** General I/O 절연구간예고장치 고장정보의 1계 버튼 색상 : 변화없음 - 무시, 데이터 오류 (경보정지) */
#define ELM_DISP_INSULATION_SYS1_COLOR_6_GREEN			0x06 /** General I/O 절연구간예고장치 고장정보의 1계 버튼 색상 : 녹색, 1계 운용 (경보정지) */
#define ELM_DISP_INSULATION_SYS1_COLOR_7_				0x07 /** General I/O 절연구간예고장치 고장정보의 1계 버튼 색상 : 변화없음 - 무시, 데이터 오류 (경보정지) */
#define ELM_DISP_INSULATION_SYS2_COLOR_0_RED			0x00 /** General I/O 절연구간예고장치 고장정보의 2계 버튼 색상 : 적색, 2계 고장 (경보정지) */
#define ELM_DISP_INSULATION_SYS2_COLOR_1_RED_F			0x10 /** General I/O 절연구간예고장치 고장정보의 2계 버튼 색상 : 적색 점멸, 2계 고장 (경보발생) */
#define ELM_DISP_INSULATION_SYS2_COLOR_2_LIGHTGRAY		0x20 /** General I/O 절연구간예고장치 고장정보의 2계 버튼 색상 : 흐린회색, 2계 정상 (경보정지) */
#define ELM_DISP_INSULATION_SYS2_COLOR_3_				0x03 /** General I/O 절연구간예고장치 고장정보의 2계 버튼 색상 : 변화없음 - 무시, 데이터 오류 (경보정지) */
#define ELM_DISP_INSULATION_SYS2_COLOR_4_				0x04 /** General I/O 절연구간예고장치 고장정보의 2계 버튼 색상 : 변화없음 - 무시, 데이터 오류 (경보정지) */
#define ELM_DISP_INSULATION_SYS2_COLOR_5_				0x05 /** General I/O 절연구간예고장치 고장정보의 2계 버튼 색상 : 변화없음 - 무시, 데이터 오류 (경보정지) */
#define ELM_DISP_INSULATION_SYS2_COLOR_6_GREEN			0x60 /** General I/O 절연구간예고장치 고장정보의 2계 버튼 색상 : 녹색, 2계 운용 (경보정지) */
#define ELM_DISP_INSULATION_SYS2_COLOR_7_				0x70 /** General I/O 절연구간예고장치 고장정보의 2계 버튼 색상 : 변화없음 - 무시, 데이터 오류 (경보정지) */
/* Mask */
#define ELM_DISP_INSULATION_SYS1_STATE_MASK				0x07 /** D0~D2 */
#define ELM_DISP_INSULATION_SYS2_STATE_MASK				0x70 /** D4~D6 */

/* General I/O 확장랙 정류기 State 정보 */
#define ELM_DISP_RECTIFIER_STATE_ALARMON				0x10 /** General I/O 확장랙 정류기 알람경보 발생 여부 : 0:경보정지, 1:경보 발생 */
#define ELM_DISP_RECTIFIER_STATE_GOOD					0x20 /** General I/O 확장랙 정류기 정상여부 : 0:고장, 1:정상 */
/* General I/O 확장랙 정류기 State 표시정보 */
#define ELM_DISP_RECTIFIER_COLOR_0_RED					0x00 /** General I/O 확장랙 정류기 정보의 버튼 색상 : 적색, 장애 (경보정지) */
#define ELM_DISP_RECTIFIER_COLOR_1_RED_F				0x10 /** General I/O 확장랙 정류기 정보의 버튼 색상 : 적색 점멸, 장애 (경보발생) */
#define ELM_DISP_RECTIFIER_COLOR_2_GREEN				0x20 /** General I/O 확장랙 정류기 정보의 버튼 색상 : 녹색, 정상 */
/* Mask */
#define ELM_DISP_RECTIFIER_STATE_MASK					0x30 /** D4~D5 */
/* Rotue State 표시 정보*/
#define ELM_DISP_ROUTE_YLMR								0x01	/** YLMR ON, 0:OFF, 1:ON */
#define ELM_DISP_ROUTE_GLMR								0x02	/** GLMR ON, 0:OFF, 1:ON */
#define ELM_DISP_ROUTE_T1LMR							0x04	/** Y1LMR ON, 0:OFF, 1:ON */
#define ELM_DISP_ROUTE_RT_ON							0x10	/** 진로설정 ON, (0:진로해정, 1:진로설정) */
#define ELM_DISP_ROUTE_CTRLREQ							0x20	/** 진로설정 제어요구 ON, (0:제어없음, 1:제어요구) */
#define ELM_DISP_ROUTE_CTRL_DISABLE						0x40	/** 진로설정 제어불가 ON, (0:제어허용, 1:제어불가) */
#define ELM_DISP_ROUTE_CTRL_EN_RECTRL					0x80	/** 진로재취급 가능 ON, (0:재취급불가, 1:재취급가능) */
/* Mask */
#define ELM_DISP_ROUTE_LMR_STATE_MASK					0x07	/** 진로의 신호기 LMR 상태 */
#define ELM_DISP_ROUTE_CTRL_RT_MASK						0x30	/** 진로 제어상태 여부 mask */
#define ELM_DISP_ROUTE_EN_CTRL_MASK						0x3F	/** 진로 취급 허용 여부 정보 설정,(취급 허용 + 재취급 불가) */

#endif
/* ///////////////////////////////////////////////////////////////////////// */
/* Element Control Code의 정의                                               */
/* ///////////////////////////////////////////////////////////////////////// */
#define ELM_CTRLCODE_ALARMSTOP				0x10	/** Alarm Bell 정지 제어 명령 (Parameter: Control Code + Element ID + Alarm Stop Data)*/
/** Alarm Bell 정지 제어 기능을 갖는 Element List
*  SYS1, SYS2, N1, N2, UPS, RECTIFIER, BATTERY, FUSE, PNPOWER, PSPOWER, SGFAIL, PTFAIL, TRFAIL,TR_GI,GIO_LX
*/
#define ELM_CTRLCODE_AOFF					0x10	/** 알람경보정지 제어, Alarm OFF */
#define ELM_CTRLCODE_COMMON_RUN				0x11	/** 역공통 기능 제어 명령 - 시스템 기동 (Parameter: Control Code + Common ID + Element Control Data) */
#define ELM_CTRLCODE_COMMON_OPMODE			0x12	/** 역공통 기능 제어 명령 - 운영모드 절체 (Parameter: Control Code + Common ID + Element Control Data) */
#define ELM_CTRLCODE_COMMON_SGSTOP			0x13	/** 역공통 기능 제어 명령 - 신호기 일괄정지 설정/해제 (Parameter: Control Code + Common Element No.ID + Element Control Data) */
#define ELM_CTRLCODE_COMMON_SHOFF			0x14	/** 역공통 기능 제어 명령 - 입환신호기 소등 설정/해제 (Parameter: Control Code + Common Element No.ID + Element Control Data) */
#define ELM_CTRLCODE_COMMON_HEATER			0x15	/** 역공통 기능 제어 명령 - 히터 ON/OFF 설정 (Parameter: Control Code + Common Element No.ID + Element Control Data) */
#define ELM_CTRLCODE_COMMON_PTPOWER			0x16	/** 역공통 기능 제어 명령 - 선로전환기 북쪽/남쪽 전원 ON/OFF 설정 (Parameter: Control Code + Common Element No.ID + Element Control Data) */
#define ELM_CTRLCODE_TRACK					0x20	/** 궤도회로 제어 명령 (Parameter: Control Code + TRACK Element No.ID + Element Control Data) */
#define ELM_CTRLCODE_TRACKFAIL				0x21	/** 궤도회로 부정복귀 제어 명령 (Parameter: Control Code + TRACK Element No.ID + Element Control Data) */
#define ELM_CTRLCODE_POINT					0x30	/** 선로전환기 전환 제어 명령 (Parameter: Control Code + Point Element No.ID + Element Control Data) */
#define ELM_CTRLCODE_ROUTE					0x40	/** 진로 설정 및 해정 명령 (Parameter: Control Code + Route Element No.ID + Element Control Data) */
#define ELM_CTRLCODE_SIGNAL					0x50	/** 신호기 제어 명령 (Parameter: Control Code + Signal Element No.ID + Element Control Data) */
#define ELM_CTRLCODE_BLOCK					0x60	/** 폐색 제어 명령 (Parameter: Control Code + Signal(Block) Element No.ID + Element Control Data) */
#define ELM_CTRLCODE_CATIONLABEL			0x70	/** 운전취급주의표 설정 명령 (Parameter: Control Code + Track Element No.ID + Element Control Data) */
#define ELM_CTRLCODE_GIO					0x90	/** GIO 제어 */
#define ELM_CTRLCODE_GIO_OBSTRUCTION		0x91	/** General I/O 지장물검지장치 고장정보 제어취급 명령 (Parameter: Control Code + GIO Element No.ID + Element Control Data) */
#define ELM_CTRLCODE_GIO_INSULATION			0x92	/** General I/O 절연구간예고장치 고장정보 제어취급 명령 (Parameter: Control Code + GIO Element No.ID + Element Control Data) */

/* 제어 설정값 정의 */
#define ELM_CTRL_SYS_ALARM_OFF				0x10	/** Alarm OFF */
#define ELM_CTRL_GIO_ALARM1_OFF				0x01	/** 절연구간예고장치 1계 Alarm OFF */
#define ELM_CTRL_GIO_ALARM2_OFF				0x10	/** 절연구간예고장치 2계 Alarm OFF */

#define ELM_CTRL_SYS_CTC_SW_REQ				0x01	/** CTC 전환 요청 by CTC element */

#define ELM_CTRL_SYS_LOCAL_SW_REQ			0x04	/** LOCAL 전환 요구 by LOCAL element */
#define ELM_CTRL_SYS_LOCAL_SW_APPROVAL		0x08	/** LOCAL 전환 승인 by LOCAL element */
#define ELM_CTRL_SYS_LOCAL_CANCEL_CTC		0x08	/** CTC 전환 요정 중 취소 by LOCAL element */
#define ELM_CTRL_SYS_LOCAL_CANCEL_RC		0x08	/** RC 전환 요구 by LOCAL element */
#define ELM_CTRL_SYS_LOCAL_SW_EMREQ			0x10	/** LOCAL 비상전환 by LOCAL element */

#define ELM_CTRL_SYS_RC_SW_REQ				0x20	/** RC 전환 요구 by RC element */
#define ELM_CTRL_SYS_RC_SW_APPROVAL			0x40	/** RC 전환 승인 by RC element */
#define ELM_CTRL_SYS_RC_CANCEL_CTC			0x40	/** CTC 전환 요정 중 취소 by RC element */
#define ELM_CTRL_SYS_RC_CANCEL_LOCAL		0x40	/** RC 전환 요구 by RC element */
#define ELM_CTRL_SYS_RC_SW_EMREQ			0x80	/** RC 비상전환 by RC element */

#define ELM_CTRL_SYS_PTPOWER_ON				0x20	/** 선로전환기 남/북 전원 ON 설정 요구 */
#define ELM_CTRL_SYS_PTPOWER_OFF			0x40	/** 선로전환기 남/북 전원 OFF 설정 요구 */

#define ELM_CTRL_SG_ALLSTOP_SET				0x10	/** 신호기 일괄정지 설정요구 */
#define ELM_CTRL_SG_ALLSTOP_RELEASE			0x20	/** 신호기 일괄정지 해제요구 */
#define ELM_CTRL_SG_SHUNTOFF_SET			0x10	/** 입환(신호기)표지 소등제어 설정요구 */
#define ELM_CTRL_SG_SHUNTOFF_RELEASE		0x20	/** 입환(신호기)표지 소등제어 해제요구 */

#define ELM_CTRL_SYS_HEATER_ON				0x20	/** 히터 ON 설정 요구 */
#define ELM_CTRL_SYS_HEATER_OFF				0x40	/** 히터 OFF 설정 요구 */

#define ELM_CTRL_TR_RT_EM_RELEASE			0x20	/** 구분진로비상해정 by track */

#define ELM_CTRL_LABEL_LOC_POS2				0x40	/** 표찰등록 명령의 대상위치가 상위 니블인 경우 설정 */
#define ELM_CTRL_LABEL_SET_CMD				0x80	/** 표찰등록 명령 설정 */

#define ELM_CTRL_SG_RELEASE					0x10	/** 신호기 정지 (진로해제) 요구 */

#define ELM_CTRL_BLOCK_START_REQ			0x01	/** 폐색 출발-출발요청 */
#define ELM_CTRL_BLOCK_HOME_APPROVAL		0x02	/** 폐색 장내-장내승인 */
#define ELM_CTRL_BLOCK_OPEN_REQ				0x04	/** 폐색 개통-개통요청 */
#define ELM_CTRL_BLOCK_OPEN_APPROVAL		0x08	/** 폐색 개통-개통승인 */
#define ELM_CTRL_BLOCK_CANCEL_REQ			0x10	/** 폐쌕 취소-취소요청 */
#define ELM_CTRL_BLOCK_CANCEL_APPROVAL		0x20	/** 폐쌕 취소-취소승인 */

#define ELM_CTRL_POINT_N_SWITCH_REQ			0x10	/** 선로전환기 정위 전환 제어 요구 */
#define ELM_CTRL_POINT_R_SWITCH_REQ			0x20	/** 선로전환기 반위 전환 제어 요구 */

#define ELM_CTRL_ROUTE_SET					0x01	/** 진로설정 요구 */
#define ELM_CTRL_ROUTE_TTB_ON				0x04	/** TTB 설정 요구 */
#define ELM_CTRL_ROUTE_TTB_OFF				0x08	/** TTB 취소 요구 */
#define ELM_CTRL_ROUTE_RELEASE				0x10	/** 진로 해제 요구 */
#define ELM_CTRL_ROUTE_RESET				0x20	/** 진로 재취급 설정 요구 */

/* ///////////////////////////////////////////////////////////////////////// */
/* 표시정보를 위한 Element Data 구조체 정의                                  */
/* ///////////////////////////////////////////////////////////////////////// */

/* ------------------------------------------------------------------------- */
/* for ZEST EI and WINDOWS(INTEL Style) : LITTLE ENDIAN                                  */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* RUN State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_RUN
* @brief 역 공통 데이터(Common Data)의 RUN Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES      : 2;	 /** D0~D1, 사용하지 않음, 0 설정함 */
	uint32 bSys1Run  : 1;	 /** D2, 0:오른쪽 적색-1계 대기, 1:오른쪽 녹색-1계 기동 */
	uint32 bSys2Run  : 1;	 /** D3, 0:왼쪽   적색-2계 대기, 1:왼쪽   녹색-2계 기동 */
	uint32 bSys1good : 1;	 /** D4, 0:1계 장애, 1:1계 정상 */
	uint32 bSys2Good : 1;	 /** D5, 0:2계 장애, 1:2계 정상 */
	uint32 bRES1     : 2;	 /** D6~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_RUN;

/* ------------------------------------------------------------------------- */
/* CTC/LOCAL/RC State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_OPMODE
* @brief 역 공통 데이터(Common Data)의 CTC/LOCAL/RC Mode Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bCtcReq   : 1;	 /** D0, 0:제어없음, 1:CTC 전환요구 */
	uint32 bCtcRun   : 1;	 /** D1, 0:대기모드, 1:CTC 운영모드 */
	uint32 bLocalReq : 1;	 /** D2, 0:제어없음, 1:LOCAL 운영모드 */
	uint32 bLocalRun : 1;	 /** D3, 0:대기모드, 1:LOCAL 운영모드 */
	uint32 bRcReq    : 1;	 /** D4, 0:제어없음, 1:RC 운영모드 */
	uint32 bRcRun    : 1;	 /** D5, 0:대기모드, 1:RC 운영모드 */
	uint32 bRES      : 2;	 /** D6~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_OPMODE;

/* ------------------------------------------------------------------------- */
/* SYSTEM 1계 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_SYS1
* @brief 역 공통 데이터(Common Data)의 SYSTEM 1계 Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES      : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bAlarmOn  : 1;	 /** D4, 0:SYSTEM 1계 alarm 정지, 1:SYSTEM 1계 alarm 경보 */
	uint32 bSys1Good : 1;	 /** D5, 0:SYSTEM 1계 고장, 1: SYSTEM 1계 정상 */
	uint32 bActive   : 1;	 /** D6, 0:SYSTEM 1계 Standby, 1:SYSTEM 1계 Active */
	uint32 bRES1     : 1;	 /** D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_SYS1;

/* ------------------------------------------------------------------------- */
/* SYSTEM 2계 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_SYS2
* @brief 역 공통 데이터(Common Data)의 SYSTEM 2계 Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES      : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bAlarmOn  : 1;	 /** D4, 0:SYSTEM 2계 alarm 정지, 1:SYSTEM 2계 alarm 경보 */
	uint32 bSys2Good : 1;	 /** D5, 0:SYSTEM 2계 고장, 1: SYSTEM 2계 정상 */
	uint32 bActive   : 1;	 /** D6, 0:SYSTEM 2계 Standby, 1:SYSTEM 2계 Active */
	uint32 bRES1     : 1;	 /** D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_SYS2;

/* ------------------------------------------------------------------------- */
/* 한전전원 N1 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_N1
* @brief 역 공통 데이터(Common Data)의 한전전원 N1 Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES      : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bAlarmOn  : 1;	 /** D4, 0:경보정지, 1:경보울림 */
	uint32 bX1Good   : 1;	 /** D5, 0:X1 고장, 1:X1 정상 */
	uint32 bN1Supply : 1;	 /** D6, 0:N1 대기, 1:N1 공급 */
	uint32 bRES1     : 1;	 /** D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_N1;

/* ------------------------------------------------------------------------- */
/* 철도전원 N2 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_N2
* @brief 역 공통 데이터(Common Data)의 철도전원 N2 Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES      : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bAlarmOn  : 1;	 /** D4, 0:경보정지, 1:경보울림 */
	uint32 bX2Good   : 1;	 /** D5, 0:X2 고장, 1:X2 정상 */
	uint32 bN2Supply : 1;	 /** D6, 0:N2 대기, 1:N2 공급 */
	uint32 bRES1     : 1;	 /** D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_N2;

/* ------------------------------------------------------------------------- */
/* UPS State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_UPS
* @brief 역 공통 데이터(Common Data)의 UPS Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES      : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bAlarmOn  : 1;	 /** D4, 0:경보정지, 1:경보울림 */
	uint32 bUpsGood  : 1;	 /** D5, 0:UPS 고장, 1:UPS 정상 */
	uint32 bRES1     : 2;	 /** D6~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_UPS;

/* ------------------------------------------------------------------------- */
/* RECTIFIER 1,2, Other State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_RECTIFIER
* @brief 역 공통 데이터(Common Data)의 RECTIFIER Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES           : 4; /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bAlarmOn       : 1; /** D4, 0:경보정지, 1:경보울림 */
	uint32 bRectifierGood : 1; /** D5, 0:RECTIFIER 고장, 1:RECTIFIER 정상 */
	uint32 bRES1          : 2; /** D6~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_RECTIFIER;

/* ------------------------------------------------------------------------- */
/* BATTERY State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_BATTERY
* @brief 역 공통 데이터(Common Data)의 BATTERY Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES         : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bAlarmOn     : 1;	 /** D4, 0:경보정지, 1:경보울림 */
	uint32 bBatteryGood : 1;	 /** D5, 0:BATTERY 고장, 1:BATTERY 정상 */
	uint32 bRES1        : 2;	 /** D6~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_BATTERY;

/* ------------------------------------------------------------------------- */
/* FUSE, FUSE1, FUSE2 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_FUSE
* @brief 역 공통 데이터(Common Data)의 FUSE or FUSE1 or FUSE2 Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES      : 4;		 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bAlarmOn  : 1;		 /** D4, 0:경보정지, 1:경보울림 */
	uint32 bFuseGood : 1;		 /** D5, 0:FUSE 고장, 1:FUSE 정상 */
	uint32 bRES1     : 2;		 /** D6~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_FUSE;

/* ------------------------------------------------------------------------- */
/* 북쪽 선로전환기 전원 공급 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_PNPOWER
* @brief 역 공통 데이터(Common Data)의 북쪽 선로전환기 전원 공급 Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES         : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bAlarmOn     : 1;	 /** D4, 0:경보정지, 1:경보울림 */
	uint32 bPNPowerGood : 1;	 /** D5, 0:PNPOWER 고장, 1:PNPOWER 정상 */
	uint32 bRES1        : 2;	 /** D6~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_PNPOWER;

/* ------------------------------------------------------------------------- */
/* 남쪽 선로전환기 전원 공급 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_PSPOWER
* @brief 역 공통 데이터(Common Data)의 남쪽 선로전환기 전원 공급 Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES         : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bAlarmOn     : 1;	 /** D4, 0:경보정지, 1:경보울림 */
	uint32 bPSPowerGood : 1;	 /** D5, 0:PSPOWER 고장, 1:PSPOWER 정상 */
	uint32 bPowerON     : 1;	 /** D6, 0:제어없음, 1:제어중 */
	uint32 bRES1        : 1;	 /** D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_PSPOWER;

/* ------------------------------------------------------------------------- */
/* Signal Failure State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_SGFAIL
* @brief 역 공통 데이터(Common Data)의 Signal Failure Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES       : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bAlarmOn   : 1;	 /** D4, 0:경보정지, 1:경보울림 */
	uint32 bSgFailure : 1;	 /** D5, 0:SGFAILURE 고장, 1:SGFAILURE 정상 */
	uint32 bRES1      : 2;	 /** D6~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_SGFAIL;

/* ------------------------------------------------------------------------- */
/* Point Failure  State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_PTFAIL
* @brief 역 공통 데이터(Common Data)의 Point Failure Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES       : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bAlarmOn   : 1;	 /** D4, 0:경보정지, 1:경보울림 */
	uint32 bPtFailure : 1;	 /** D5, 0:PTFAILURE 고장, 1:PTFAILURE 정상 */
	uint32 bRES1      : 2;	 /** D6~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_PTFAIL;

/* ------------------------------------------------------------------------- */
/* Track Failure  State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_TRFAIL
* @brief 역 공통 데이터(Common Data)의 Track Failure Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES       : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bAlarmOn   : 1;	 /** D4, 0:경보정지, 1:경보울림 */
	uint32 bTrFailure : 1;	 /** D5, 0:TRFAILURE 고장, 1:TRFAILURE 정상 */
	uint32 bRES1      : 2;	 /** D6~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_TRFAIL;

/* ------------------------------------------------------------------------- */
/* 신호기계실 출입문 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_RRDOOR
* @brief 역 공통 데이터(Common Data)의 신호기계실 출입문 Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES     : 4;		 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bAlarmOn : 1;		 /** D4, 0:경보정지, 1:경보울림 */
	uint32 bRrDoor  : 1;		 /** D5, 0:RRDOOR 열림, 1:RRDOOR 닫힘 */
	uint32 bRES1    : 2;		 /** D6~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_RRDOOR;

/* ------------------------------------------------------------------------- */
/* 신호기 일괄정지 제어 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_SGSTOP
* @brief 역 공통 데이터(Common Data)의 신호기 일괄정지 제어 Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES       : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bSetSgStop : 1;	 /** D4, 0:미설정, 1:적색점등-설정상태 */
	uint32 bReqSgStop : 1;	 /** D5, 0:제어요구없음, 1:적색점멸-설정 중 상태 */
	uint32 bRES1      : 2;	 /** D6~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_SGSTOP;

/* ------------------------------------------------------------------------- */
/* 입환표지(신호기) 소등 제어 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_SHOFF
* @brief 역 공통 데이터(Common Data)의 입환표지(신호기) 소등 제어 Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES       : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bSetShOff  : 1;	 /** D4, 0:황색-점등상태, 1:흐린회색-소등상태 */
	uint32 bReqShOff  : 1;	 /** D5, 0:제어요구없음, 1:제어요구중 */
	uint32 bRES1      : 2;	 /** D6~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_SHOFF;

/* ------------------------------------------------------------------------- */
/* 북쪽 히터 제어 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_HEATERN
* @brief 역 공통 데이터(Common Data)의 북쪽 히터 제어 Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES         : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bAlarmOn     : 1;	 /** D4, 0:흐린회색-Off 설정상태, 1:녹색-ON 설정상태 */
	uint32 bHeaterNGood : 1;	 /** D5, 0:제어요구없음, 1:제어요구중 */
	uint32 bSetHeaterN  : 1;	 /** D6, 0:흐린회색-Off 설정상태, 1:녹색-ON 설정상태 */
	uint32 bReqHeaterN  : 1;	 /** D7, 0:제어요구없음, 1:제어요구중 */
} TS_ELM_DISP_HEATERN;

/* ------------------------------------------------------------------------- */
/* 남쪽 히터 제어 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_HEATERS
* @brief 역 공통 데이터(Common Data)의 남쪽 히터 제어 Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES         : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bAlarmOn     : 1;	 /** D4, 0:흐린회색-Off 설정상태, 1:녹색-ON 설정상태 */
	uint32 bHeaterSGood : 1;	 /** D5, 0:제어요구없음, 1:제어요구중 */
	uint32 bSetHeaterS  : 1;	 /** D6, 0:흐린회색-Off 설정상태, 1:녹색-ON 설정상태 */
	uint32 bReqHeaterS  : 1;	 /** D7, 0:제어요구없음, 1:제어요구중 */
} TS_ELM_DISP_HEATERS;

/* ------------------------------------------------------------------------- */
/* COM 1,2 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_COM
* @brief 역 공통 데이터(Common Data)의 COM 1 or 2 Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES     : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bAlarmOn : 1;	 /** D4, 0:경보정지, 1:경보울림 */
	uint32 bComGood : 1;	 /** D5, 0:COM  고장, 1:COM  정상 */
	uint32 bActive  : 1;	 /** D6, 0:Standby, 1:Active main */
	uint32 bRES1    : 1;	 /** D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_COM;

/* ------------------------------------------------------------------------- */
/* LCP 1,2 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_LCP
* @brief 역 공통 데이터(Common Data)의 LCP 1 or 2 Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES     : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bAlarmOn : 1;	 /** D4, 0:경보정지, 1:경보울림 */
	uint32 bGood    : 1;	 /** D5, 0:LCP 고장, 1:LCP 정상 */ /* [KRS수정부반영2] OPC 고장상태 변수명 수정 */
	uint32 bActive  : 1;	 /** D6, 0:Standby, 1:Active main */
	uint32 bRES1    : 1;	 /** D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_LCP;

/* [KRS수정부반영3] MTC 상태정보 추가 */
/* ------------------------------------------------------------------------- */
/* MTC State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_MTC
* @brief 역 공통 데이터(Common Data)의 MTC Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES     : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bAlarmOn : 1;	 /** D4, 0:경보정지, 1:경보울림 */
	uint32 bGood    : 1;	 /** D5, 0:MTC 고장, 1:MTC 정상 */
	uint32 bRES1    : 2;	 /** D6-D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_MTC;

/* ------------------------------------------------------------------------- */
/* 궤도회로 일반정보 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_TR_GI
* @brief 궤도회로 일반정보 Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bTRACKOCC  : 1;	 /** D0, 0:점유(적색), 1:비점유(백색) */
	uint32 bTKROUTE   : 1;	 /** D1, 0:진로선별해정상태(백색), 1:진로선별쇄정상태(황색) */
	uint32 bLRLOCK    : 1;	 /** D2, 0:진로쇄정 좌행 및 우행 해정상태, 1:진로쇄정 좌행 또는우행 쇄정상태(녹색) */
	uint32 bTKALARM   : 1;	 /** D3, 0:접근없음(백색), 1:장내접근(적색점멸) */
	uint32 bTKFAIL    : 1;	 /** D4, 0:궤도회로정상(백색), 1:궤도회로부정낙하(적색) */
	uint32 bTKREQ     : 1;	 /** D5, 0:궤도(재)취급불가 1:궤도(재)취급가능 */
	uint32 bTKEMREL   : 1;	 /** D6, 0:비상해정취급불가 1:비상해정취급가능 */
	uint32 bAPLOCK    : 1;	 /** D7, 0:도착점해정, 1:도착점쇄정 */
} TS_ELM_DISP_TR_GI;

/* ------------------------------------------------------------------------- */
/* 궤도회로 확장정보(운전취급주의표(표찰)) 설정 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_TR_EX
* @brief 궤도회로 확장정보(운전취급주의표(표찰)) 설정 Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bINHIBIT_ID1 : 4;	 /** D0~D3, 0:설정없음, 1~10:설정됨, 기타:무시됨 */
	uint32 bINHIBIT_ID2 : 4;	 /** D4`D7, 0:설정없음, 1~10:설정됨, 기타:무시됨 */
 /** Bit 0 ~ Bit 3, Bit 4 ~ Bit 7, INHIBIT_ID1 과 INHIBIT_ID2 설정 값의 의미는 아래와 동일함.
	0x00 : 없음
	0x01 : 보선장치입환
	0x02 : 선로사용중지
	0x03 : 차단공사
	0x04 : 전차선단전
	0x05 : 트로리사용중
	0x06 : 수신호
	0x07 : 대용폐색
	0x08 : 통신식
	0x09 : 열차퇴행
	0x0A : 전차선없음
	0x0B : 변화없음 - 무시, 사용하지않음
	0x0C : 변화없음 - 무시, 사용하지않음
	0x0D : 변화없음 - 무시, 사용하지않음
	0x0E : 변화없음 - 무시, 사용하지않음
	0x0F : 변화없음 - 무시, 사용하지않음
	*/
} TS_ELM_DISP_TR_EX;

/* ------------------------------------------------------------------------- */
/* 신호기 일반정보 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_SG_GI
* @brief 신호기 일반정보 Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bINU         : 1;	 /** D0, 0:흑색-유도신호기 소등, 1:녹색-유도신호기 진행현시 */
	uint32 bTTB         : 1;	 /** D1, 0:흑색-TTB OFF, 1:황색-TTB ON */
	uint32 bSGROUTE     : 1;	 /** D2, 0:신호기 해정, 1:신호기 쇄정 */
	uint32 bSGON_TIMER  : 1;	 /** D3, 0:접근,보류 해정, 1:접근,보류 쇄정 */
	uint32 bGO          : 1;	 /** D4, 0:정지현시, 1:진행현시 */
	uint32 bSGFAIL      : 1;	 /** D5, 0:정상, 1:고장 */
	uint32 bRTSELM_GO   : 1;	 /** D6, 0:진로선별등 소등, 1:진로선별등 진행현시 */
	uint32 bRTSELM_FAIL : 1;	 /** D7, 0:진로선별등 정상, 1:진로선별등 장애 */
} TS_ELM_DISP_SG_GI;

/* ------------------------------------------------------------------------- */
/* 구내폐색 신호기 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_SG_INBLOCK
* @brief 구내폐색 신호기 Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES    : 4;		 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bGO     : 1;		 /** D4, 0:정지현시, 1:진행현시 */
	uint32 bSGFAIL : 1;		 /** D5, 0:정상, 1:고장 */
	uint32 bRES1   : 2;		 /** D6~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_SG_INBLOCK;

/* ------------------------------------------------------------------------- */
/* 폐색구간 신호기 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_SG_OUTBLOCK
* @brief 폐색구간 신호기 Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES     : 4;		 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bGO      : 1;		 /** D4, 0:정지현시, 1:진행현시 */
	uint32 bSGFAIL  : 1;		 /** D5, 0:정상, 1:고장 */
	uint32 bRES1    : 2;		 /** D6~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_SG_OUTBLOCK;

/* ------------------------------------------------------------------------- */
/* 연동/자동 폐색 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_BLOCKS
* @brief 연동/자동 폐색 Element의 표시정보 Data
*/
typedef struct {
	uint32 bBLKOUT_YF : 1;	 /** D0, 0:요구없음, 1:출발-출발/취소 요구 */
	uint32 bBLKOUT_Y  : 1;	 /** D1, 0:승인없음, 1:츨발-출발승인 */
	uint32 bBLKOUT_R  : 1;	 /** D2, 0:진입없음, 1:출발-열차진입 */
	uint32 bBLKOUT_RF : 1;	 /** D3, 0:요구없음, 1:출발-개통요구중 */
	uint32 bBLKIN_YF  : 1;	 /** D4, 0:요구없음, 1:장내-취소/출발 요구 */
	uint32 bBLKIN_Y   : 1;	 /** D5, 0:응답없음, 1:장내-장내응답 */
	uint32 bBLKIN_R   : 1;	 /** D6, 0:진입없음, 1:장내-열차진입 */
	uint32 bBLKIN_RF  : 1;	 /** D7, 0:요구없음, 1:장내-개통요구 */
} TS_ELM_DISP_BLOCKS;

/* ------------------------------------------------------------------------- */
/* 선로전환기 일반정보 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_PT_GI
* @brief 선로전환기 일반정보 Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bNKRI     : 1;	 /** D0, 0:모름, 1:정위 */
	uint32 bRKRI     : 1;	 /** D1, 0:모름, 1:반위 */
	uint32 bPTLOCK   : 1;	 /** D2, 0:해정상태, 1:쇄정상태 */
	uint32 bPTFAIL   : 1;	 /** D3, 0:정상상태, 1:고장상태 */
	uint32 bPTONTIMR : 1;	 /** D4, 0:오버랩해정시소없음, 1:오버랩해정시소진행 중 */
	uint32 bSWLOCK   : 1;	 /** D5, 0:선로전환기 전환가능, 1:전환불가 */
	uint32 bNWRO     : 1;	 /** D6, 0:NWRO OFF, 1:NWRO ON (정위) */
	uint32 bRWRO     : 1;	 /** D7, 0:RWRO OFF, 1:RWRO ON (반위) */
} TS_ELM_DISP_PT_GI;

/* ------------------------------------------------------------------------- */
/* General I/O 건널목 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_LX
* @brief 역 공통 데이터(Common Data)의 CTC/LOCAL/RC Mode Element Data
*/
typedef struct {
	uint32 bRES     : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bAlarmOn : 1;	 /** D4, 0:알람정지, 1:알람경보발생 */
	uint32 bLxGood  : 1;	 /** D5, 0:고장, 1:정상 */
	uint32 bRES1    : 2;	 /** D6~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_LX;

/* ------------------------------------------------------------------------- */
/* General I/O 지장물검지장치 고장정보 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_OBSTRUCTION
* @brief General I/O 지장물검지장치 고장정보 Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES             : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bAlarmOn         : 1;	 /** D4, 0:알람정지, 1:알람경보발생 */
	uint32 bObstructionGood : 1;	 /** D5, 0:고장, 1:정상 */
	uint32 bSetUnsecurity   : 1;	 /** D6, 0:흐린회색-보안해제취소, 1:황색-보안해제취급 */
	uint32 bRES1            : 1;	 /** D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_OBSTRUCTION;

/* ------------------------------------------------------------------------- */
/* General I/O 절연구간예고장치 고장정보 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_INSULATION
* @brief General I/O 절연구간예고장치 고장정보 Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bSys1AlarmOn : 1;	 /** D0, 0:1계 알람경보정지, 1:1계 알람경보발생 */
	uint32 bSys1Good    : 1;	 /** D1, 0:1계 고장, 1:1계 정상 */
	uint32 bSys1Active  : 1;	 /** D2, 0:1계 대기, 1:1계 운용 */
	uint32 bRES         : 1;	 /** D3, 사용하지 않음, 0 설정함 */
	uint32 bSys2AlarmOn : 1;	 /** D4, 0:2계 알람경보정지, 1:2계 알람경보발생 */
	uint32 bSys2Good    : 1;	 /** D5, 0:2계 고장, 1:2계 정상 */
	uint32 bSys2Active  : 1;	 /** D6, 0:2계 대기, 1:2계 운용 */
	uint32 bRES1        : 1;	 /** D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_INSULATION;

/* ------------------------------------------------------------------------- */
/* General I/O 확장랙 정류기 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_OPMODE
* @brief General I/O 확장랙 정류기 Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bRES           : 4; /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bAlarmOn       : 1; /** D4, 0:알람정지, 1:알람경보발생 */
	uint32 bRectifierGood : 1; /** D5, 0:고장, 1:정상 */
	uint32 bRES1          : 2; /** D6~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_DISP_EXRECTIFIER;

/* ------------------------------------------------------------------------- */
/* 진로 일반정보 State 표시정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_RT_GI
* @brief 진로 일반정보 Element의 State 표시정보 Data
*/
typedef struct {
	uint32 bYLMR         : 1;		 /** D0, 0: YLMR OFF, 1: YLMR ON */
	uint32 bGLMR	     : 1;		 /** D1, 0: YLMR OFF, 1: YLMR ON */
	uint32 bY1LMR        : 1;		 /** D2, 0: YLMR OFF, 1: YLMR ON */
	uint32 bRouteSel     : 1;		 /** D3, 0:흑색-진로해정, 1:황색-진로설정중 */
	uint32 bRouteON      : 1;		 /** D4, 0:흑색-진로해정, 1:황색-진로설정 */
	uint32 bRouteReq     : 1;		 /** D5, 0:요구없음, 1:제어요구 */ /* [KRS수정부반영1] 진로제어 요구정보 추가 */
	uint32 bEnableRoute  : 1;		 /** D6, 0:제어허용, 1:제어불가 */
	uint32 bEnableReCtrl : 1;		 /** D7, 0:재취급불가, 1:재취급가능 */
} TS_ELM_DISP_RT_GI;

/* ///////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////////////////////////////////////////////////// */
/* 제어정보를 위한 Element Data 구조체 정의                                  */
/* ///////////////////////////////////////////////////////////////////////// */

/* ------------------------------------------------------------------------- */
/* for ZEST EI and WINDOWS(INTEL Style) : LITTLE ENDIAN                                  */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* Element의 알람경보 정지 제어정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_ALARMBELL_OFF
* @brief Element의 알람경보 정지 제어정보
*/
typedef struct {
	uint32 bSys1AlarmOFF : 1;	 /** D0, 0:제어없음, 1:절연구간예고장치 1계 Alarm 경보 정지(절연구간예고장치 Element ID 인 경우) */
	uint32 bRES          : 3;	 /** D1~D3, 사용하지 않음, 0 설정함 */
	uint32 bSysAlarmOFF  : 1;	 /** D4, 0:제어없음, 1:일반적인 Alarm 또는 절연구간예고장치 2계 Alarm 경보 정지(절연구간예고장치 Element ID 인 경우) */
	uint32 bRES1         : 3;	 /** D5~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_CTRL_ALARMBELL_OFF;

/* ------------------------------------------------------------------------- */
/* RUN 요구 제어정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_RUN
* @brief 역 공통 데이터(Common Data)의 RUN Elemen의 제어정보
*/
typedef struct {
	uint32 bRES        : 2; /** D0~D1, 사용하지 않음, 0 설정함 */
	uint32 bSys1RunReq : 1; /** D2, 0:제어없음, 1:1계 RUN 요구 */
	uint32 bRES1       : 1; /** D3, 사용하지 않음, 0 설정함 */
	uint32 bSys2RunReq : 1; /** D4, 0:제어없음, 1:2계 RUN 요구 */
	uint32 bRES2       : 3; /** D5~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_CTRL_RUN;

/* ------------------------------------------------------------------------- */
/* CTC Mode 전환 제어정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_CTC_MODE
* @brief 역 공통 데이터(Common Data)의 CTC Mode Element의 제어정보
*/
typedef struct {
	uint32 bCtcReq : 1; /** D0, 0:제어없음, 1:CTC 전환요구 */
	uint32 bRES    : 7; /** D1~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_CTRL_CTC_MODE;

/* ------------------------------------------------------------------------- */
/* LOCAL Mode 전환 제어정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_LOCAL_MODE
* @brief 역 공통 데이터(Common Data)의 LOCAL Mode Element의 제어정보
*/
typedef struct {
	uint32 bRES           : 2; /** D0~D1, 사용하지 않음, 0 설정함 */
	uint32 bLocalReq      : 1; /** D2, 0:제어없음, 1:LOCAL 전환요구 */
	uint32 bLocalApproval : 1; /** D3, 0:제어없음, 1:LOCAL 전환승인/CTC or RC 요청  중 취소 */
	uint32 bEmLocal       : 1; /** D4, 0:제어없음, 1:비상 LOCAL 전환 */
	uint32 bRES1          : 3; /** D5~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_CTRL_LOCAL_MODE;

/* ------------------------------------------------------------------------- */
/* RC Mode 전환 제어정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_RC_MODE
* @brief 역 공통 데이터(Common Data)의 RC Mode Element의 제어정보
*/
typedef struct {
	uint32 bRES		 : 5;	 /** D0~D4, 사용하지 않음, 0 설정함 */
	uint32 bRCReq		 : 1;	 /** D5, 0:제어없음, 1:RC 전환요구 */
	uint32 bRCApproval : 1;	 /** D6, 0:제어없음, 1:RC 전환승인/CTC or LOCAL 요청 중 취소 */
	uint32 bEmRC		 : 1;	 /** D7, 0:제어없음, 1:비상 RC 전환 */
} TS_ELM_CTRL_RC_MODE;


/* ------------------------------------------------------------------------- */
/* 북쪽&남쪽 선로전환기 제어정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_PTPOWER
* @brief 역 공통 데이터(Common Data)의 N/S Point Power Element의 제어정보
*/
typedef struct {
	uint32 bRES           : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bAlarmOFF      : 1;	 /** D4, 0:제어없음, 1:Alarm 경보 정지 */
	uint32 bPTPowerONReq  : 1;	 /** D5, 0:제어없음, 1:Point power ON 설정 요구 */
	uint32 bPTPowerOFFReq : 1;	 /** D6, 0:제어없음, 1:Point Power OFF 설정 요구 */
	uint32 bRES1          : 1;	 /** D7, 사용하지 않음, 0 설정함 */
} TS_ELM_CTRL_PTPOWER;


/* ------------------------------------------------------------------------- */
/* 신호기 일괄정지 제어정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_SGSTOP
* @brief 역 공통 데이터(Common Data)의 신호기 일괄정지 Element의 제어정보
*/
typedef struct {
	uint32 bRES             : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bSetSgStopReq    : 1;	 /** D4, 0:제어없음, 1:신호기 일괄정지 설정요구 */
	uint32 bCancelSgStopReq : 1;	 /** D5, 0:제어없음, 1:신호기 일괄정지 해제요구 */
	uint32 bRES1            : 2;	 /** D6~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_CTRL_SGSTOP;

/* ------------------------------------------------------------------------- */
/*입환표지(신호기) 소등 제어정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_SHOFF
* @brief 역 공통 데이터(Common Data)의 입환표지(신호기) 소등 Element의 제어정보
*/
typedef struct {
	uint32 bRES            : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bSetShOffReq    : 1;	 /** D4, 0:제어없음, 1:입환표지(신호기) 소등제어 설정 요구 */
	uint32 bCancelShOffReq : 1;	 /** D5, 0:제어없음, 1:입환표지(신호기) 소등제어 해제 요구 */
	uint32 bRES1           : 2;	 /** D6~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_CTRL_SHOFF;

/* ------------------------------------------------------------------------- */
/* 북쪽&남쪽 히터 제어정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_HEATER
* @brief 역 공통 데이터(Common Data)의 Heater N/S Element의 제어정보
*/
typedef struct {
	uint32 bRES          : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bAlarmOFF     : 1;	 /** D4, 0:제어없음, 1:Alarm 경보 정지 */
	uint32 bHeaterONReq  : 1;	 /** D5, 0:제어없음, 1:Heater ON 설정 요구 */
	uint32 bHeaterOFFReq : 1;	 /** D6, 0:제어없음, 1:Heater OFF 설정 요구 */
	uint32 bRES1         : 1;	 /** D7, 사용하지 않음, 0 설정함 */
} TS_ELM_CTRL_HEATER;

/* ------------------------------------------------------------------------- */
/* 궤도회로 제어정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_TR_GI
* @brief 궤도회로 Element의 제어정보
*/
typedef struct {
	uint32 bRES            : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bAlarmOFF       : 1;	 /** D4, 0:제어없음, 1:Alarm 경보 정지 */
	uint32 bEmRtReleaseReq : 1;	 /** D5, 0:제어없음, 1:구분진로비상해정 요구 */
	uint32 bRES1           : 2;	 /** D6~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_CTRL_TR_GI;

/* ------------------------------------------------------------------------- */
/* 궤도회로 운전취급주의표(표찰) 설정 제어정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_TR_EX
* @brief 궤도회로 운전취급주의표(표찰) 설정 Element의 제어정보
*/
typedef struct {
	uint32 bINHIBIT_IDREQ  : 4;	 /** D0~D3, 1~10:제어대상 표찰설정값, 기타:무시됨 */
	uint32 bRES            : 2;	 /** D4`D5, 사용하지 않음, 0 설정함 */
	uint32 bLabelCtrlLoc   : 1;	 /** D6, 0:표찰#1 제어, 1:표찰#2 제어 */
	uint32 bLabelCtrlReq   : 1;	 /** D7, 0:표찰 삭제 제어, 1:표찰 설정 제어 */
	/** Bit 0 ~ Bit 3, INHIBIT_ID 설정 값의 의미는 아래와 동일함.
	0x00 : 표찰삭제
	0x01 : 보선장치입환
	0x02 : 선로사용중지
	0x03 : 차단공사
	0x04 : 전차선단전
	0x05 : 트로리사용중
	0x06 : 수신호
	0x07 : 대용폐색
	0x08 : 통신식
	0x09 : 열차퇴행
	0x0A : 전차선없음
	0x0B : 변화없음 - 무시, 사용하지않음
	0x0C : 변화없음 - 무시, 사용하지않음
	0x0D : 변화없음 - 무시, 사용하지않음
	0x0E : 변화없음 - 무시, 사용하지않음
	0x0F : 변화없음 - 무시, 사용하지않음
	*/
} TS_ELM_CTRL_TR_EX;

/* ------------------------------------------------------------------------- */
/* 신호기(주신오/입환신호기/입환표지/구내폐색신호기/폐색구간신호기) 제어정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_SG_GI
* @brief 신호기(주신오/입환신호기/입환표지/구내폐색신호기/폐색구간신호기) Element의 제어정보
*/
typedef struct {
	uint32 bRES			 : 4;	 /** D0-D3, 사용하지 않음, 0 설정함 */
	uint32 bSGStopReq      : 1;	 /** D4, 0:제어없음, 1:신호기 정지현시(진로해제) 요구 */
	uint32 bRES1		     : 3;	 /** D5-D7, 사용하지 않음, 0 설정함 */
} TS_ELM_CTRL_SG_GI;

/* ------------------------------------------------------------------------- */
/* 연동/자동 폐색(취급버튼/방향표)의 제어정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_DISP_OPMODE
* @brief 연동/자동 폐색(취급버튼/방향표) Element의 제어정보
*/
typedef struct {
	uint32 bBLKOUT_DEPARTURE_REQ : 1;	 /** D0, 0:제어없음, 1:출발-출발요청 */
	uint32 bBLKIN_ENTRANCE_OK    : 1;	 /** D1, 0:제어없음, 1:장내-장내승인 */
	uint32 bBLKIN_OPENING_REQ    : 1;	 /** D2, 0:제어없음, 1:장내-개통요청 */
	uint32 bBLKOUT_OPENING_OK    : 1;	 /** D3, 0:제어없음, 1:출발-개통승인 */
	uint32 bBLKIN_CANCEL_REQ     : 1;	 /** D4, 0:요구없음, 1:장내-취소요청 */
	uint32 bBLKOUT_CANCEL_OK	   : 1;	 /** D5, 0:제어없음, 1:출발-취소승인 */
	uint32 bRES                  : 2;	 /** D6-D7, 사용하지 않음, 0 설정함 */
} TS_ELM_CTRL_BLOCKS;

/* ------------------------------------------------------------------------- */
/* 선로전환기의 전환요구 제어정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_PT_GI
* @brief 선로전환기 Element의 제어정보
*/
typedef struct {
	uint32 bRES     : 4;	 /** D0~D3, 사용하지 않음, 0 설정함 */
	uint32 bNWRReq  : 1;	 /** D4, 0:제어없음, 1:정위전환제어요구 */
	uint32 bRWROReq : 1;	 /** D5, 0:제어없음, 1:반위전환제어요구 */
	uint32 bRES1    : 2;	 /** D6~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_CTRL_PT_GI;

/* ------------------------------------------------------------------------- */
/* 진로 일반정보 Element의 제어 정보 */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELM_CTRL_RT_GI
* @brief 진로 Element용 제어 Data Structure
*/
typedef struct {
	uint32 bSetRouteReq    : 1;		 /** D0, 0:제어없음, 1:진로설정요구 */
	uint32 bRES            : 1;		 /** D1, 사용하지 않음, 0 설정함 */
	uint32 bTTBONReq       : 1;		 /** D2, 0:제어없음, 1:TTB ON 요구 */
	uint32 bTTBOFFReq      : 1;		 /** D3, 0:제어없음, 1:TTB OFF 요구 */
	uint32 bCancelRouteReq : 1;		 /** D4, 0:제어없음, 1:진로해제요구 */
	uint32 bResetRouteReq  : 1;		 /** D5, 0:제어없음, 1:진로재취급요구 */
	uint32 bRES1           : 2;		 /** D6~D7, 사용하지 않음, 0 설정함 */
} TS_ELM_CTRL_RT_GI;
/* ///////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////////////////////////////////////////////////// */
/* Element Indexing Table의 Element Object ID 구조체 정의                    */
/* ///////////////////////////////////////////////////////////////////////// */

/* ------------------------------------------------------------------------- */
/* for ZEST EI and WINDOWS(INTEL Style)                                                  */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* Element의 Indexing용 Type 및 ID 정보                                      */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELEMENT_IDTYPE
* @brief Element Indexing Table의 Element에 대한 Type 및 ID 정보.
*/
typedef struct {
	uint32 bID   : 12;		 /** D0~D11까지의 12 Bit가 Element's Object ID. */
	uint32 bType :  4;		 /** D12~D15까지의  4 Bit가 Element's Object Type. */
} TS_ELEMENT_IDTYPE;

/* ///////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////////////////////////////////////////////////// */
/* Element Indexing Table & Element Data Table 의 구조체 정의                */
/* ///////////////////////////////////////////////////////////////////////// */
/* ------------------------------------------------------------------------- */
/* Element의 Indexing Table 구조체 정의                                      */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELEMENT_INDEX_TABLE
* @brief Element들에 대한 Indexing Table 
*/
typedef struct {
	uint16	usElmTH_TOTALSIZE;						/** Byte 단위로 계산된 Element Indexing Table의 전체 크기. */
	uint16	usElmTH_COMMON_CNT;						/** 역 공통정보(ELM_COMMON) table 의 실사용 개수 (전체 32개) */
	uint16	usElmTH_TR_GI_CNT;						/** 궤도회로 일반정보(ELM_TRACK_GI) table 의 실사용 개수 (전체 512개) */
	uint16	usElmTH_TR_EX_CNT;						/** 궤도회로 확장(표찰)정보(ELM_TRACK_EX) table 의 실사용 개수 (전체 512개) */
	uint16	usElmTH_SG_GI_CNT;						/** 신호기 일반정보(ELM_SIGNAL_GI) table 의 실사용 개수 (전체 512개) */
	uint16	usElmTH_PT_GI_CNT;						/** 선로전환기 공통정보(ELM_POINT GI) table 의 실사용 개수 (전체 256개) */
	uint16	usElmTH_GIO_GI_CNT;						/** General I/O 일반정보(ELM_GIO_GI) table 의 실사용 개수 (전체 49개) */
	uint16	usElmTH_RT_GI_CNT;						/** 진로 일반정보(ELM_ROUTE GI) table 의 실사용 개수 (전체 1024개) */
	TS_ELEMENT_IDTYPE	atElmIDX_COMMON[LIMIT_CNT_ELM_IDX_COMMON];	/** 역 공통 정보 Element ID 및 TYPE */
	TS_ELEMENT_IDTYPE	atElmIDX_TR[LIMIT_CNT_ELM_IDX_TRGI];		/** 궤도회로 일반정보 Element의 ID 및 TYPE */
	TS_ELEMENT_IDTYPE	atElmIDX_TREX[LIMIT_CNT_ELM_IDX_TREX];		/** 궤도회로 확장(표찰)정보 Element의 ID 및 TYPE */
	TS_ELEMENT_IDTYPE	atElmIDX_SG[LIMIT_CNT_ELM_IDX_SGGI];		/** 신호기 일반정보 Element의 ID 및 TYPE */
	TS_ELEMENT_IDTYPE	atElmIDX_PT[LIMIT_CNT_ELM_IDX_PTGI];		/** 선로전환기 일반정보 Element의 ID 및 TYPE */
	TS_ELEMENT_IDTYPE	atElmIDX_GIO[LIMIT_CNT_ELM_IDX_GIO];		/** General I/O 일반정보 Element의 ID 및 TYPE */
	TS_ELEMENT_IDTYPE	atElmIDX_RT[LIMIT_CNT_ELM_IDX_RT];			/** 진로 일반정보 Element의 ID 및 TYPE */
} TS_ELEMENT_INDEX_TABLE;

/* ------------------------------------------------------------------------- */
/* Element의 Data Table 구조체 정의                                          */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELEMENT_DATA_TABLE
* @brief Element의 State Data Table
*/
typedef struct {
	uint8					aucElmCOMMON_STATE[LIMIT_CNT_ELM_IDX_COMMON];	/** 역 공통 정보 Element 의 상태정보 data */
	TS_ELM_DISP_TR_GI		atElmTR_STATE[LIMIT_CNT_ELM_IDX_TRGI];			/** 궤도회로 일반정보 Element의 상태정보 data */
	TS_ELM_DISP_TR_EX		atElmTREX_STATE[LIMIT_CNT_ELM_IDX_TREX];		/** 궤도회로 확장(표찰)정보 Element의 상태정보 data */
	TS_ELM_DISP_SG_GI		atElmSG_STATE[LIMIT_CNT_ELM_IDX_SGGI];			/** 신호기 일반정보 Element의 상태정보 data */
	TS_ELM_DISP_PT_GI		atElmPT_STATE[LIMIT_CNT_ELM_IDX_PTGI];			/** 선로전환기 일반정보 Element의 상태정보 data */
	uint8 					aucElmGIO_STATE[LIMIT_CNT_ELM_IDX_GIO];			/** General I/O 일반정보 Element의 상태정보 data */
	TS_ELM_DISP_RT_GI		atElmRT_STATE[LIMIT_CNT_ELM_IDX_RT];			/** 진로 일반정보 Element의 상태정보 data */
	uint8					aucEnd;											/** 블럭 마지막 바이트 정의(사용안함) */
} TS_ELEMENT_DATA_TABLE;


/* ------------------------------------------------------------------------- */
/* Element의 Data Table 구조체 정의                                          */
/* ------------------------------------------------------------------------- */
/**
* @struct TS_ELEMENT_DATA_COMMON_TABLE
* @brief 역 공통 정보 Element의 State Data Table
*/
typedef struct {
	uint8 					usElmTEMP_STATE;		 /** 역 공통 정보의 0번째 Element 의 상태정보 data */
	TS_ELM_DISP_RUN			tElmRUN_STATE;			 /** 역 공통 정보의 1번째 RUN Element 의 상태정보 data */
	TS_ELM_DISP_OPMODE		tElmCTC_STATE;			 /** 역 공통 정보의 2번째 CTC Element 의 상태정보 data */
	TS_ELM_DISP_OPMODE		tElmLOCAL_STATE;		 /** 역 공통 정보의 3번째 LOCAL Element 의 상태정보 data */
	TS_ELM_DISP_OPMODE		tElmRC_STATE;			 /** 역 공통 정보의 4번째 RC Element 의 상태정보 data */
	TS_ELM_DISP_SYS1		tElmSYS1_STATE;			 /** 역 공통 정보의 5번째 SYS1 Element 의 상태정보 data */
	TS_ELM_DISP_SYS2		tElmSYS2_STATE;			 /** 역 공통 정보의 6번째 SYS2 Element 의 상태정보 data */
	TS_ELM_DISP_N1			tElmN1_STATE;			 /** 역 공통 정보의 7번째 N1 Element 의 상태정보 data */
	TS_ELM_DISP_N2			tElmN2_STATE;			 /** 역 공통 정보의 8번째 N2 Element 의 상태정보 data */
	TS_ELM_DISP_UPS			tElmUPS_STATE;			 /** 역 공통 정보의 9번째 UPS Element 의 상태정보 data */
	TS_ELM_DISP_RECTIFIER	tElmRECTIFIER1_STATE;	 /** 역 공통 정보의 10번째RECTIFER1  Element 의 상태정보 data */
	TS_ELM_DISP_RECTIFIER	tElmRECTIFIER2_STATE;	 /** 역 공통 정보의 11번째RECTIFER2  Element 의 상태정보 data */
	TS_ELM_DISP_BATTERY		tElmBATTERY_STATE;		 /** 역 공통 정보의 12번째 BATTERY Element 의 상태정보 data */
	TS_ELM_DISP_FUSE		tElmFUSE_STATE;			 /** 역 공통 정보의 13번째 FUSE Element 의 상태정보 data */
	TS_ELM_DISP_PNPOWER		tElmPNPOWER_STATE;		 /** 역 공통 정보의 14번째 PNPOWER Element 의 상태정보 data */
	TS_ELM_DISP_PSPOWER		tElmPSPOWER_STATE;		 /** 역 공통 정보의 15번째 PSPOWER Element 의 상태정보 data */
	TS_ELM_DISP_SGFAIL		tElmSGFAIL_STATE;		 /** 역 공통 정보의 16번째 SGFAILURE Element 의 상태정보 data */
	TS_ELM_DISP_PTFAIL		tElmPTFAIL_STATE;		 /** 역 공통 정보의 17번째 PTFAILURE Element 의 상태정보 data */
	TS_ELM_DISP_TRFAIL		tElmTRFAIL_STATE;		 /** 역 공통 정보의 18번째 TRFAILURE Element 의 상태정보 data */
	TS_ELM_DISP_RRDOOR		tElmRRDOOR_STATE;		 /** 역 공통 정보의 19번째 RRDOOR Element 의 상태정보 data */
	TS_ELM_DISP_SGSTOP		tElmSGSTOP_STATE;		 /** 역 공통 정보의 20번째 SGSTOP Element 의 상태정보 data */
	TS_ELM_DISP_SHOFF		tElmSHOFF_STATE;		 /** 역 공통 정보의 21번째 SHOFF Element 의 상태정보 data */
	TS_ELM_DISP_HEATERN		tElmHEATERN_STATE;		 /** 역 공통 정보의 22번째 HEATERN Element 의 상태정보 data */
	TS_ELM_DISP_HEATERS		tElmHEATERS_STATE;		 /** 역 공통 정보의 23번째 HEATERS Element 의 상태정보 data */
	TS_ELM_DISP_FUSE		tElmFUSE1_STATE;		 /** 역 공통 정보의 24번째 FUSE1 Element 의 상태정보 data */
	TS_ELM_DISP_FUSE		tElmFUSE2_STATE;		 /** 역 공통 정보의 25번째 FUSE2 Element 의 상태정보 data */
	TS_ELM_DISP_COM			tElmCOM1_STATE;			 /** 역 공통 정보의 26번째 COM1 Element 의 상태정보 data */
	TS_ELM_DISP_COM			tElmCOM2_STATE;			 /** 역 공통 정보의 27번째 COM2 Element 의 상태정보 data */
	TS_ELM_DISP_LCP 		tElmLCP1_STATE;			 /** 역 공통 정보의 28번째 LCP1 Element 의 상태정보 data */
	TS_ELM_DISP_LCP			tElmLCP2_STATE;			 /** 역 공통 정보의 29번째 LCP2 Element 의 상태정보 data */
	TS_ELM_DISP_MTC			tElmMTC_STATE;			 /** 역 공통 정보의 30번째 MTC Element 의 상태정보 data */ /* [KRS수정부반영3] MTC 상태정보 추가 */
	uint8 					aucElmRES_STATS;		 /** 역 공통 정보의 31 번째 예비 Element 의 상태정보 data */
} TS_ELEMENT_DATA_COMMON_TABLE;

#endif /** #ifndef _ELEMENTTABLE_H_ */
