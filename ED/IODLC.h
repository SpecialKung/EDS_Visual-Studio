#ifdef _IODLC_C
   #define IODLC_EXT 
#else
   #define IODLC_EXT extern
#endif


IODLC_EXT void    IODLC_Initial_value(void);
IODLC_EXT void    IODLC_Distance_calculate(void);
IODLC_EXT void    IODLC_Parameter_value(void);
IODLC_EXT void    IODLC_CRPLS(void);

IODLC_EXT UBYTE IODLC_ubArea_status;

IODLC_EXT UWORD IODLC_uwPR_J1,
                IODLC_uwPR_J2,
                IODLC_uwPR_J3,
                IODLC_uwPR_J4,
                IODLC_uwPR_Ts1,
                IODLC_uwPR_Tacc,
                IODLC_uwPR_Ts2,
                IODLC_uwPR_Ts3,
                IODLC_uwPR_Tdec,
                IODLC_uwPR_Ts4,
                IODLC_uwPR_Tl,
                IODLC_uwPR_Tfa,
                IODLC_uwPR_Tfd,
                IODLC_uwPR_Th,
                IODLC_uwPR_Th_Det,
                IODLC_uwPR_Th_CNT,
                IODLC_uwPR_Tl_Det,
                IODLC_uwPR_Tl_CNT,
                IODLC_uwPR_delta_fs2,
                IODLC_uwPR_delta_fs3,
                IODLC_uwPR_delta_fs4,
                IODLC_uwPR_fs4,
                IODLC_uwPR_fl,
                IODLC_uwPR_fMAX,
                IODLC_uwPR_Adec;
IODLC_EXT ULONG IODLC_ulPR_Distance;

IODLC_EXT UWORD IODLC_uwArea_J1,
                IODLC_uwArea_J2,
                IODLC_uwArea_J3,
                IODLC_uwArea_J4,
                IODLC_uwArea_Ts1,
                IODLC_uwArea_Tacc,
                IODLC_uwArea_Ts2,
                IODLC_uwArea_Ts3,
                IODLC_uwArea_Tdec,
                IODLC_uwArea_Ts4,
                IODLC_uwArea_Tl,
                IODLC_uwArea_Tfa,
                IODLC_uwArea_Tfd,
                IODLC_uwArea_Th,
                IODLC_uwArea_delta_fs2,
                IODLC_uwArea_delta_fs3,
                IODLC_uwArea_delta_fs4,
                IODLC_uwArea_fs4,
                IODLC_uwArea_fl,
                IODLC_uwArea_fMAX,
                IODLC_uwArea_Adec,
                IODLC_uwArea_Tdec_now,
                IODLC_uwPRDtotal,
                IODLC_uwSpeed,
                IODLC_uwdecMaxSpeed;
IODLC_EXT UWORD uwspeed_max,
                uwspeed_tmp;


IODLC_EXT SWORD IODLC_swArea_Th_Det;

IODLC_EXT ULONG ulcul_tmp,
                ulcul_tmp1,
                IODLC_ulPRDtotal,
                IODLC_ulDtotal_dp;

IODLC_EXT ULONG IODLC_ulPR_Ts2x3,
                IODLC_ulPR_Ts3x3,
                IODLC_ulPR_Ts4x3,
                IODLC_ulArea_Ts2x3,
                IODLC_ulArea_Ts3x3,
                IODLC_ulArea_Ts4x3,
                IODLC_ulDs2,
                IODLC_ulDh,
                IODLC_ulDs3,
                IODLC_ulDdec,
                IODLC_ulDs4plusDl,
                IODLC_ulDtotal,
                IODLC_ulSFDistance,
                IODLC_ulCPSDistance;

IODLC_EXT UWORD CRPLS_uwJlim;
IODLC_EXT ULONG CRPLS_ulTs4;
IODLC_EXT UDOUBLE CRPLS_ulJs4,
                  cul_speed_tmp,
                  cul_D_tmp;




IODLC_EXT SLONG IODLC_sleqb,
                IODLC_sleqc,
                IODLC_sleqFm,
                IODLC_sleqFlim,
                IODLC_sldelta_sdec;
IODLC_EXT UWORD_UNION    IODLC_control_flag,
                         IODLC_CRPLS_flag;

#define AreaStop        0
#define AreaS1          1
#define AreaAcc         2
#define AreaS2          3
#define Areahold        4
#define AreaS3          5
#define AreaDec         6
#define AreaS4          7
#define Arealand        8
#define AreaS5          9
#define AreaS6         10

#define MI_OFF          0
#define MI_ON           1

#define IODLC_control_return 0
#define IODLC_control_get 1
#define SR_control_get    1         //[KEB ESD&ETS Function/Lyabryan/2018/08/10]
#define SR_control_return 0         //[KEB ESD&ETS Function/Lyabryan/2018/08/10]

//==================flag===================//
#define IODLC_control     IODLC_control_flag.bit.b0
#define IODLC_holdover    IODLC_control_flag.bit.b1
#define IODLC_MIinput     IODLC_control_flag.bit.b2
#define IODLC_MIcheck     IODLC_control_flag.bit.b3
#define IODLC_holdCNT     IODLC_control_flag.bit.b4
#define IODLC_decpoint    IODLC_control_flag.bit.b5
#define IODLC_speedset    IODLC_control_flag.bit.b6
#define IODLC_ctrlgetonce IODLC_control_flag.bit.b7
#define IODLC_dpinaccnod  IODLC_control_flag.bit.b8 // dec point in acc and not over distance
#define IODLC_cutspeed    IODLC_control_flag.bit.b9
#define IODLC_AreaDec     IODLC_control_flag.bit.b10

#define IODLC_CRPLSset    IODLC_CRPLS_flag.bit.b0
#define IODLC_CRPLS_SW    IODLC_CRPLS_flag.bit.b1
#define IODLC_CRPLS_S4    IODLC_CRPLS_flag.bit.b2
#define IODLC_CRPLS_SWSPD IODLC_CRPLS_flag.bit.b3
#define IODLC_CRPLS_MISW  IODLC_CRPLS_flag.bit.b4