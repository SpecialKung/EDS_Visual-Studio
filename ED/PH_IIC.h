#ifdef _PH_IIC_C
   #define PH_IIC_EXT 
#else
   #define PH_IIC_EXT extern
#endif

#ifdef _PH_IIC_C 
/* IIC ADDR CONST */
//#define IIC_FRAM_WRITE_CODE	0xa0	//0xa0, 1010:FRAM ID, 000:FRAM Addr, 0:WRITE
//#define IIC_FRAM_READ_CODE	0xa1	//0xa1, 1010:FRAM ID, 000:FRAM Addr, 1:READ  //masked, demo board only
#define IIC_FRAM_WRITE_CODE	0xae	//0xa0, 1010:FRAM ID, 111:FRAM Addr, 0:WRITE
#define IIC_FRAM_READ_CODE	0xaf	//0xa1, 1010:FRAM ID, 111:FRAM Addr, 1:READ	//VLI FRAM environment

#define rtm_ubINIT_TIMEOUT	10		//real-timer init timeout cnt

#define SECTION2_StAddr       4097      //[user define default value, Bernie, 2015/10/21]

#endif

PH_IIC_EXT void IIC_Init(void);
PH_IIC_EXT void IIC_Read(UBYTE *Device,UBYTE *Data,UBYTE DataSize);
PH_IIC_EXT void IIC_Data_Send(UBYTE Data);
PH_IIC_EXT void IIC_Data_Send_LB(UBYTE Data);
PH_IIC_EXT void IIC_Start(void);
PH_IIC_EXT void IIC_Stop(void);
PH_IIC_EXT void IIC_RStart(void);  //Bernie add
PH_IIC_EXT void write_ep(UBYTE wrFlag, UWORD prx, UWORD wrdata);
PH_IIC_EXT UWORD read_ep(UWORD prx);
PH_IIC_EXT void LoadEPData(void);
PH_IIC_EXT void wr_def2ep(void);
PH_IIC_EXT void wr_FF2ep(void);
PH_IIC_EXT void rtm_vdReadyChk(void);
PH_IIC_EXT void rtm_vdRdSta1(void);
PH_IIC_EXT void rtm_vdRdSta2(void);
PH_IIC_EXT void rtm_vdWrSta1(void);
PH_IIC_EXT void rtm_vdWrSta2(void);
PH_IIC_EXT void rtm_vdRdTime(void);
PH_IIC_EXT void rtm_vdWrTime(void);
PH_IIC_EXT void rtm_vdMgr(void);
PH_IIC_EXT UBYTE rtm_ubLSB2MSB(UBYTE ubIn);
PH_IIC_EXT UBYTE rtm_ubBCD2DEC(UBYTE ubIn);
PH_IIC_EXT UBYTE rtm_ubDEC2BCD(UBYTE ubIn);
PH_IIC_EXT void frm_vdWrite(void);	// Fram_Buf added and FRAM read/write to Fram_Buf instead, Sean, 06/30/2010 
PH_IIC_EXT void frm_vdRead(void);	// Fram_Buf added and FRAM read/write to Fram_Buf instead, Sean, 06/30/2010 
PH_IIC_EXT void frm_vdWrite2(void);
PH_IIC_EXT void frm_vdWrite4User(void);
PH_IIC_EXT void frm_vdRead4User(void);
PH_IIC_EXT UBYTE IIC_PrRdStep1(UWORD uwRdAds);
PH_IIC_EXT UBYTE IIC_PrRdStep2(void);
PH_IIC_EXT UBYTE IIC_PrRd4UserStep1(UWORD uwRdAds);
PH_IIC_EXT UBYTE IIC_PrRd4UserStep2(void);

PH_IIC_EXT void frm_vdDLCWrite(void);
PH_IIC_EXT void frm_vdDLCRead(void);
PH_IIC_EXT void DLC_PR_initial(void);

PH_IIC_EXT UWORD cf2_index,
				 rtm_uw1sec,
				 err_uwFRAMErrRd;

PH_IIC_EXT UBYTE rtm_ubSta1,
				 rtm_ubSta2,
				 rtm_ubInitDone,
				 rtm_ubTimeRd[7],
				 rtm_ubTimeWr[7];

#ifdef _PH_IIC_C
const UWORD HorsePower[17]={
    
//Model:0,1    2,3    4,5     6,7     8,9     10,11   12,13   14,15   16,17   18,19
        18,    38,    75,     150,    225,    375,    563,    750,    1125,   1500,
//      20,21   22,23   24,25   26,27   28,29   30,31   32,33           
        1875,   2250,   3000,   3750,   4500,   5625,   7500,
};
#else
extern const UWORD HorsePower[17];
#endif