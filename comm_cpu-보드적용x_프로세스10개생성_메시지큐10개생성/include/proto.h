/*-----------------------------------------------------------------------------+
|                 CopyRight ⓒ DaeaTi Co., Ltd.                                |
|                 All Rights Reserved                                          |
+------------------------------------------------------------------------------+
| FILE        : proto.h                                                        |
| DIRECTORY   : 													           |
| PROCESS     :                                                                |
| 고 객 명    : 부산교통공사                                                         
| PROJECT     : 부산도시철도 1호선 개량 신호설비 기자재 구매                                                 
| 작성 일자   : 2016.06.01                                                    
| 작 성 자    : 이창수                                                                 |
| SYSTEM 정보 : 개발 환경 - PC                                                 |
|               운영 쳬제 - Linux                                            
|               TARGET    - TI-AM5K2E04	 								       
|               LANGUAGE  -   C language                                       |
+------------------------------------------------------------------------------+
| 1. FUNCTION DESCRIPTION                                                      |
|																			   |
| 2. 소속 함수                                                                 |
|																			   |
| 3. Routine Tree                                                              |
|                                                                              |
+------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------+
|		comLib.c																																	 |
+------------------------------------------------------------------------------*/
uchar	TTC_Purge_Queue( int   msqid);
uchar	DTTC_Purge_Queue( int   msqid);
uchar	EIE_Purge_Queue( int   msqid);
uchar	MC_Purge_Queue( int   msqid);
uchar	SSC_Purge_Queue( int   msqid);
uchar	PAC_Purge_Queue( int   msqid);
uchar	PSD_Purge_Queue( int   msqid);
uchar	OPC_Purge_Queue( int   msqid);
uchar	MTC_Purge_Queue( int   msqid);
int   Make_Log_1(QUEUE_ID channel, int length, uchar data[]);
int   Make_Log_2(QUEUE_ID channel, int length, uchar data[]);
int UcharToAscii(uchar number, char ascii[], ushort radix, ushort arrange, char blank);
uint String2Integer(const uchar* ucInputStr, uint* uiIntNum);
void	get_date_text( char *text );
void Common_InputString(uchar *p);
int RTC_init(void);
int RTC_Write(uchar reg_addr, uchar *data, uint data_sz);
int RTC_Read(uchar reg_addr, uchar *data, uint data_sz);
int RTC_SET_Time(char *SetTime);
int RTC_GET_Time(void);
int change_to_raw_type(uchar *rtc_reg_list, uchar *year, uchar *month, uchar *date, uchar *day, uchar *hour, uchar *minute, uchar *second);
int change_to_rtc_reg_type(uchar *rtc_reg_list, uchar year, uchar month, uchar date, uchar day, uchar hour, uchar minute, uchar second);
uchar Read_DI_Channel(int Channel);
uchar Write_DO_Channel(int Channel, uchar Status);
uchar FND_CONTROL(uchar CODE);
void FND_Init(void);
uchar LED_CONTROL(int LED, uchar Status);
uchar LED_CONTROL2(int LED, uchar Status);
int UART_RecvData(int Channel, uchar *MsgBuff);
uchar UART_SendData(int Channel, uchar *MsgBuff, int MsgSize);
void	WatchdogReset();
void	ChangeEquipmentState();
int	ResetCPU(void);
int  AsciiToHex(uchar *string, uchar *value);
int SetupCrcTable(void);
uint	  CalCrcAll(uint length, uchar ch[], uint *all_crc);
uint	  DUAL_CalCrcAll(uint length, uchar ch[], uint *all_crc);
uint	  CalCrcAll2(uint length, uchar ch[]);
ushort Calculate_CRC(uchar *Buf, uint Len);
int	CalCrcAll_For_CDTS(unsigned short length, uchar ch[], unsigned short *all_crc);				
uint CalcCRC32 (const uchar* block, uint length);
uint calc_crc32(uchar* pvStartAddress, uint ulSize_in_bytes);
uint CalculateCrc32(uint uiAccumCrc, const uchar* pucDataBlkPtr,uint uiDataBlkSize);
void GenerateCrcTable(void);

void GPIO_Setup(gpio_type_e type);
int GPIO_Export(unsigned int gpio);
int GPIO_Unexport(unsigned int gpio);
int GPIO_SetDir(unsigned int gpio, unsigned int dir);
int GPIO_GetVal(unsigned int gpio, unsigned int *val);
int GPIO_SetVal(unsigned int gpio, unsigned int val);
void DisplaySegment(int num);
void FND_Test(void);
int	VME_Init(void);

int LAN_CheckAlive(void);
int	LAN1_MsgRecv(void);
int	LAN2_MsgRecv(void);
int	LAN1_MsgSend(int SendLineNum, uchar Data[ ], int MsgLength);
int	LAN2_MsgSend(int SendLineNum, uchar Data[ ], int MsgLength);

int	LAN1_ConvProtocol(void);
int	LAN2_ConvProtocol(void);
/*-----------------------------------------------------------------------------+
|		Error.c																																	 |
+------------------------------------------------------------------------------*/
int   Warning(error what, char routine[], char specific[]);
int GetArmTime(uchar *buf);
int GetArmTime(uchar *buf);
int GetArmFileName(uchar *buf);
int GetArmDelFileName(uchar *buf);

/*-----------------------------------------------------------------------------+
|		Proc_alm.c																																	 |
+------------------------------------------------------------------------------*/
void ALM_SigHandler(void);

/*-----------------------------------------------------------------------------+
|		Proc_log.c																																 |
+------------------------------------------------------------------------------*/
int GetLogTime(uchar *buf);
int GetFileName(uchar *buf);
int GetDelFileName(uchar *buf);

/*-----------------------------------------------------------------------------+
|		Proc_view.c																																 |
+------------------------------------------------------------------------------*/
int GetTime(uchar *buf);

/*-----------------------------------------------------------------------------+
|		Proc_main.c																																	 |
+------------------------------------------------------------------------------*/
int Open_FPGA(void);
int	Mode_Select(void);
int 	CreateTask (void);
int 	TaskQueCreate(void);
uchar LDTS_LoadEthConfig(void);


/*-----------------------------------------------------------------------------+
|		Proc_dual.c																																 |
+------------------------------------------------------------------------------*/
int Dual_SigHandler(void);
int	Dual_CreateThread(uchar ThreadName);
int	Dual_ChangeCPU(uchar CPUNum);
int	Dual_ResetCPU(uchar CPUNum);
int	Thread_Dual_Mon(void);
int	Thread_Dual_Sig(void);
int	Thread_Dual_Run(void);


/*-----------------------------------------------------------------------------+
|		Proc_sysman.c																																 |
+------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------+
|		Proc_cpu.c																																 |
+------------------------------------------------------------------------------*/
int CPU_Send_Msg(uchar *ptr,int length);
int CPU_Recv_Msg(void);
int CPU_CopyThat(void);
int CPU_LdtsStatus(void);
uchar CPU_GenSeqNum(void);
int CPU_LinkTest(void);
int CPU_Ack_Report(void);
int CPU_Nak_Report(void);

/*-----------------------------------------------------------------------------+
|		Proc_ttc.c																																 |
+------------------------------------------------------------------------------*/
int main(void);
uchar TTC_LoadConfig(void);
uchar TTC_CreatSocket(char Sock_name);
int TTC_CreateThread(uchar ThreadName);
int TTC_CheckLine(uchar Changed);
int	TTC_ChangeCPU(uchar CPUNum);
int	TTC_ResetCPU(uchar CPUNum);
int	TTC_LdtsStatus(int LineNum);
int	TTC_StandardTime(int LineNum);
int	TTC1_GenSeqNum(void);
int	TTC2_GenSeqNum(void);
int	TTC1_LinkTest(void);
int	TTC1_Transfer(void);
int	TTC2_Transfer(void);
int	TTC1_CheckMsg(int View_Cnt);
int	TTC2_CheckMsg(int View_Cnt);
int	TTC1_MakeMsg(uchar MsgType);
int	TTC2_MakeMsg(uchar MsgType);
int	TTC1_Ack_Report(void);
int	TTC2_Ack_Report(void);
int	TTC1_Nak_Report(void);
int	TTC2_Nak_Report(void);
int	TTC1_Indication_Report(void);
int	TTC2_Indication_Report(void);
int Thread_TTC1_MAN(void);
int Thread_TTC1_Send(void);
int Thread_TTC1_Recv(void);
int Thread_TTC2_MAN(void);
int Thread_TTC2_Send(void);
int Thread_TTC2_Recv(void);

/*-----------------------------------------------------------------------------+
|		Proc_dttc.c																																 |
+------------------------------------------------------------------------------*/
int main(void);
uchar DTTC_LoadConfig(void);
uchar DTTC_CreatSocket(char Sock_name);
int DTTC_CreateThread(uchar ThreadName);
int DTTC_CheckLine(uchar Changed);
int	DTTC_ChangeCPU(uchar CPUNum);
int	DTTC_ResetCPU(uchar CPUNum);
int	DTTC_LdtsStatus(int LineNum);
int	DTTC_StandardTime(int LineNum);
int	DTTC1_GenSeqNum(void);
int	DTTC2_GenSeqNum(void);
int	DTTC1_LinkTest(void);
int	DTTC1_Transfer(void);
int	DTTC2_Transfer(void);
int	DTTC1_CheckMsg(int View_Cnt);
int	DTTC2_CheckMsg(int View_Cnt);
int	DTTC1_MakeMsg(uchar MsgType);
int	DTTC2_MakeMsg(uchar MsgType);
int	DTTC1_Ack_Report(void);
int	DTTC2_Ack_Report(void);
int	DTTC1_Nak_Report(void);
int	DTTC2_Nak_Report(void);
int	DTTC1_Indication_Report(void);
int	DTTC2_Indication_Report(void);
int Thread_DTTC1_MAN(void);
int Thread_DTTC1_Send(void);
int Thread_DTTC1_Recv(void);
int Thread_DTTC2_MAN(void);
int Thread_DTTC2_Send(void);
int Thread_DTTC2_Recv(void);

/*-----------------------------------------------------------------------------+
|		Proc_eie.c																																 |
+------------------------------------------------------------------------------*/
int main(void);
uchar EIE_LoadConfig(void);
uchar EIE_CreatSocket(char Sock_name);
int EIE_CreateThread(uchar ThreadName);
int EIE_CheckLine(void);
int EIE1_GenSeqNum(void);
int EIE2_GenSeqNum(void);
int EIE_ChangeCPU(uchar CPUNum);
int EIE_ResetCPU(uchar CPUNum);
int EIE1_BaseScanReq(void);
int EIE2_BaseScanReq(void);
int EIE1_LinkTest(void);
int EIE1_Transfer(void);
int EIE2_Transfer(void);
int EIE1_CheckMsg(int View_Cnt);
int EIE2_CheckMsg(int View_Cnt);
int EIE1_MakeMsg(uchar MsgType);
int EIE2_MakeMsg(uchar MsgType);
int EIE1_Operation_msg(void);
int EIE2_Operation_msg(void);
int Thread_EIE1_MAN(void);
int Thread_EIE1_Send(void);
int Thread_EIE1_Recv(void);
int Thread_EIE2_MAN(void);
int Thread_EIE2_Send(void);
int Thread_EIE2_Recv(void);


uchar	EIE1_MsgRecv(void);
int	EIE1_MsgSend(int uiPortNum);
uchar	EIE2_MsgRecv(void);
int	EIE2_MsgSend(int uiPortNum);

/*-----------------------------------------------------------------------------+
|		Proc_mc.c																																 |
+------------------------------------------------------------------------------*/
int	main(void);
uchar MC_LoadConfig(void);
uchar MC_CreatSocket(char Sock_name);
int MC_CreateThread(uchar ThreadName);
int MC_CheckLine(uchar Changed);
int MC_ChangeCPU(uchar CPUNum);
int MC_ResetCPU(uchar CPUNum);
int MC_StatusReport(int LineNum);
int MC1_CheckMsg(int View_Cnt);
int MC2_CheckMsg(int View_Cnt);
int MC1_MakeMsg(uchar MsgType);
int MC2_MakeMsg(uchar MsgType);
int MC1_Ack_Report(void);
int MC2_Ack_Report(void);
int MC1_Nak_Report(void);
int MC2_Nak_Report(void);
int Thread_MC1_MAN(void);
int Thread_MC1_Send(void);
int Thread_MC1_Recv(void);
int Thread_MC2_MAN(void);
int Thread_MC2_Send(void);
int Thread_MC2_Recv(void);

/*-----------------------------------------------------------------------------+
|		Proc_ssc.c																																 |
+------------------------------------------------------------------------------*/
uchar SSC_LoadConfig(void);
uchar SSC_CreatSocket(char Sock_name);
int SSC_CreateThread(uchar ThreadName);
int SSC_CheckLine(uchar Changed);
int SSC_ChangeCPU(uchar CPUNum);
int SSC_ResetCPU(uchar CPUNum);
int SSC_StatusReport(int LineNum);
int SSC1_CheckMsg(int View_Cnt);
int SSC2_CheckMsg(int View_Cnt);
int SSC1_MakeMsg(uchar MsgType);
int SSC2_MakeMsg(uchar MsgType);
int SSC1_Ack_Report(void);
int SSC2_Ack_Report(void);
int SSC1_Nak_Report(void);
int SSC2_Nak_Report(void);
int Thread_SSC1_MAN(void);
int Thread_SSC1_Send(void);
int Thread_SSC1_Recv(void);
int Thread_SSC2_MAN(void);
int Thread_SSC2_Send(void);
int Thread_SSC2_Recv(void);


/*-----------------------------------------------------------------------------+
|		Proc_pac.c																																 |
+------------------------------------------------------------------------------*/
int	main(void);
uchar PAC_LoadConfig(void);
uchar PAC_CreatSocket(char Sock_name);
int	PAC_CreateThread(uchar ThreadName);
int PAC_CheckLine(uchar Changed);
int	PAC1_GenSeqNum(void);
int	PAC2_GenSeqNum(void);
int	PAC1_Logger_msg(void);
int 	PAC2_Logger_msg(void);
int	Thread_PAC1_MAN(void);
int	Thread_PAC1_Send(void);
int	Thread_PAC1_Recv(void);
int	Thread_PAC2_MAN(void);
int	Thread_PAC2_Send(void);
int	Thread_PAC2_Recv(void);

/*-----------------------------------------------------------------------------+
|		Proc_drv.c																																 |
+------------------------------------------------------------------------------*/
int	DRV_CreateThread(int ThreadName);
int   Thread_TXDrv(void);
int   Thread_RXDrv(void);
int  	UART_write( uchar port, uchar *data, uint data_len );
uint  	UART_read( uchar port, uchar *data);
uint UART_CheckRxFlag(uchar port);
uint UART_CheckTxFlag(uchar port);
uchar UART_CheckINTSTS(uchar port);
int	UART_Init(void);
int 	UART_GetAddr(uchar port, int RegType);
int	UART_reInit(uchar port);

/*-----------------------------------------------------------------------------+
|		Proc_bug.c																																 |
+------------------------------------------------------------------------------*/
int data_compare(uchar *recv_data);
int  ato16(char *lpstr,int *lpi16);
int  ato10(char *lpstr,int *lpi10);
int main(void);
int Debug_SimMenu(void);
int Sim_Indication(void);
int Sim_Operation(void);
int Sim_ChangeCPU(void);
int Sim_ResetCPU(void);
int Debug_SubMenu(void);
int   Eth_ViewEnable(void);
int   Serial_ViewEnable(void);
int   Task_DebugEnable(void);
int   Eth_WarnEnable(void);
int   Serial_WarnEnable(void);
void Debug_InputString(uchar *p);
int UintToAscii(ushort number, char ascii[], ushort radix, ushort arrange, char blank);
void UserShow(char *fargv[], int fargc);
void showmem(unsigned char *addr, unsigned int cnt, uint unit);
void UserSet(char *fargv[], int fargc);
void setmem(unsigned char *addr, unsigned int val, int unit, int loop);
int GetTime(uchar *buf);
int   Dpram_WarnEnable_B(void);
int   Dpram_WarnEnable(void);
int   Debug_ViewEnable(void);