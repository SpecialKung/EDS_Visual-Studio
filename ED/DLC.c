#ifndef _DLC_C
	#define _DLC_C
#endif

#include "ProgHeader.h"

//DLC function, Henry, 2016/07/20

void DLC_Initial_value(void){
  UWORD i, j; //[for loop die because UBYTE,Lyabryan,2020/09/09]
  
  pr[UNITSEL] = 3;   //00-10 = 3
  pr[SOFC]    = 4;   //00-14 = 4
  pr[SOOC]    = 2;   //00-15 = 2
  
  pr[ACCEL1] = 50;   //01-12 = 0.5
  pr[DECEL1] = 50;   //01-13 = 0.5
  pr[JOGACC] = 15;   //01-20 = 0.15
  pr[JOGDEC] = 50;   //01-21 = 0.5
  pr[JOGF]   = 15;   //01-22 = 0.15
  pr[S4ACC1] = 200;  //01-24 = 2.00
  pr[S4ACC2] = 200;  //01-25 = 2.00
  pr[S4DEC1] = 200;  //01-26 = 2.00
  pr[S4DEC2] = 200;  //01-27 = 2.00
  pr[DECEL5] = 0;    //01-31 = 0.00

  pr[MI1] = 45;      //02-01 = 45
  pr[MI2] = 46;      //02-02 = 46
  pr[MI3] = 0;       //02-03 = 0
  pr[MI4] = 0;       //02-04 = 0
  pr[MI5] = 0;       //02-05 = 0
  pr[MI6] = 0;       //02-06 = 0
  pr[MI7] = 0;       //02-07 = 0
  pr[MI8] = 0;       //02-08 = 0
  pr[MO1] = 9;       //02-09
  
  pr[RSQ_SPD]       = 10;  //04-16
  pr[LEV_SPD]       = 3;   //04-17
  pr[AH_SPD]        = 50;  //04-18
  pr[MAX_FLOOR]     = 8;   //04-22
  pr[LEV_CUR]       = 1;   //04-23
  pr[PG_RST_MODE]   = 100; //04-24
  pr[LAND_DLY_TIME] = 500; //04-26
  pr[LEV_BRD_PG_H]  = 0;   //04-32
  pr[LEV_BRD_PG_L]  = 0;   //04-33
  pr[SENSOR_H]      = 0;   //04-34
  pr[SENSOR_L]      = 0;   //04-35
  
//#if Artemis_ENABLE//04-36 //Enable for Artemis
  //pr[DLC_FUN] = 0x0100|0x0040;// DLC_btPDO_ID005_Enable | DLC_ubSpdLimMode=2:re-leveling
//#else
  //pr[DLC_FUN] = 0x0200|0x0040;//04-36 //DLC_btPosLULDCal |DLC_ubSpdLimMode=2:re-leveling
//#endif

  //[btArtemisEnable at pr[00-02]=200, Special.Kung, 2022/12/02]
  if(btArtemisEnable)
  {
    pr[DLC_FUN] = 0x0100|0x0040;// DLC_btPDO_ID005_Enable | DLC_ubSpdLimMode=2:re-leveling
    pr[CAN_BURD] = 2;   // Jerry.sk.Tseng 2023/04/01 For initial Pr09-06
    write_ep(BLK_WRITE,CAN_BURD, 2);
  }
  else
  {
    pr[DLC_FUN] = 0x0200|0x0040;//04-36 //DLC_btPosLULDCal |DLC_ubSpdLimMode=2:re-leveling
  }    
  pr[PDO_TYPE] = 0;  //04-37
  pr[DS_LEN]   = 0;    //04-38
  //Artemis speed limit, James, 20200220
  pr[DD1_Vlim] = pr[Lift_SPD]; //UDS1/DDS1 Speed Limit  04-45 = 3.0m/s(Lift speed)  
  pr[DD2_Vlim] = pr[Lift_SPD];//UDS1/DDS1 Speed Limit  04-46 = 3.0m/s(Lift speed)  
  pr[DD3_Vlim] = pr[Lift_SPD];//UDS1/DDS1 Speed Limit  04-47 = 3.0m/s(Lift speed)  
  pr[DD4_Vlim] = pr[Lift_SPD];//UDS1/DDS1 Speed Limit  04-48 = 3.0m/s(Lift speed)  
      
  //04-50 to 04-99
  for(i=1; i<=0x4B; i++){
    DLC_ulPosLev[i] = 0;
  }
  
   for(i=0; i<DLCMAX; i++){
    DLCxx[i] = 0;
  }

  if(pr[FLOOR_PAGE] == 0){
    for(i=0; i<DLC_25ADDR; i++){
      pr[FL_POSIT_1H+i]= DLCxx[i];
    }
  }    
  else if(pr[FLOOR_PAGE] == 1){   // JINGDO   
    for(i=DLC_25ADDR; i<DLC_50ADDR; i++){
      pr[FL_POSIT_1H+i-DLC_25ADDR]= DLCxx[i];
    }
  }
  else if(pr[FLOOR_PAGE] == 2){		// JINGDO
    for(i=DLC_50ADDR; i<DLC_75ADDR; i++){
      pr[FL_POSIT_1H+i-DLC_50ADDR]= DLCxx[i];
    }
  }
  else if(pr[FLOOR_PAGE] == 3){		// floor adjustment Aevin 6/192/2018
      for(i=DLC_75ADDR; i<DLC_LimADDR; i++){
        pr[FL_POSIT_1H+i-DLC_75ADDR]= DLCxx[i];
      }
  }
  else if(pr[FLOOR_PAGE] == 4){		//adjust floor position,Henry,2019/01/07
      for(i=DLC_LimADDR; i<DLC_Adj50ADDRUP; i++){
        pr[FL_POSIT_1H+i-DLC_LimADDR]= DLCxx[i];
      }
  }
  else if(pr[FLOOR_PAGE] == 5){		//adjust floor position,Henry,2019/01/07
      for(i=DLC_Adj50ADDRUP; i<DLC_Adj50ADDRDN; i++){
        pr[FL_POSIT_1H+i-DLC_Adj50ADDRUP]= DLCxx[i];
      }
  }  
  else if(pr[FLOOR_PAGE] == 6){		//adjust floor position,Henry,2019/01/07
      for(i=DLC_Adj50ADDRDN; i<DLC_Adj5175ADDRUPDN; i++){
        pr[FL_POSIT_1H+i-DLC_Adj50ADDRDN]= DLCxx[i];
      }
  }
  
  pr[EV_ID] = 0;     //09-09
  pr[CAN_FUN] = 0;   //09-10

  pr[PRRESET] = 0;   //00-02 = 0
  write_ep(BLK_WRITE,PRRESET, 0);
  write_ep(BLK_WRITE,UNITSEL, 3);
  write_ep(BLK_WRITE,SOFC, 4);
  write_ep(BLK_WRITE,SOOC, 2);
  write_ep(BLK_WRITE,ACCEL1, 50);
  write_ep(BLK_WRITE,DECEL1, 50);
  write_ep(BLK_WRITE,JOGACC, 15);
  write_ep(BLK_WRITE,JOGDEC, 50);
  write_ep(BLK_WRITE,JOGF, 15);
  write_ep(BLK_WRITE,S4ACC1, 200);
  write_ep(BLK_WRITE,S4ACC2, 200);
  write_ep(BLK_WRITE,S4DEC1, 200);
  write_ep(BLK_WRITE,S4DEC2, 200);
  write_ep(BLK_WRITE,DECEL5, 0);
  write_ep(BLK_WRITE,MI1, 45);
  write_ep(BLK_WRITE,MI2, 46);
  write_ep(BLK_WRITE,MI3, 0);
  write_ep(BLK_WRITE,MI4, 0);
  write_ep(BLK_WRITE,MI5, 0);
  write_ep(BLK_WRITE,MI6, 0);
  write_ep(BLK_WRITE,MI7, 0);
  write_ep(BLK_WRITE,MI8, 0);
  write_ep(BLK_WRITE,MO1, 9);
  write_ep(BLK_WRITE,RSQ_SPD, 10);
  write_ep(BLK_WRITE,LEV_SPD, 3);
  write_ep(BLK_WRITE,AH_SPD, 50);
  write_ep(BLK_WRITE,MAX_FLOOR, 8);
  write_ep(BLK_WRITE,LEV_CUR, 1);
  write_ep(BLK_WRITE,PG_RST_MODE, 100);
  write_ep(BLK_WRITE,LAND_DLY_TIME, 500);
  write_ep(BLK_WRITE,LEV_BRD_PG_H, 0);
  write_ep(BLK_WRITE,LEV_BRD_PG_L, 0);
  write_ep(BLK_WRITE,SENSOR_H, 0);
  write_ep(BLK_WRITE,SENSOR_L, 0);
  
//#if Artemis_ENABLE
  //write_ep(BLK_WRITE,DLC_FUN, 0x0100|0x0040);   //04-36 //Enable for Artemis-->DLC_btPDO_ID005_Enable & DLC_ubSpdLimMode=2:re-leveling
//#else
  //write_ep(BLK_WRITE,DLC_FUN, 0x0040);   //04-36 //Enable for Artemis-->DLC_btPDO_ID005_Enable & DLC_ubSpdLimMode=2:re-leveling
//#endif

  //[btArtemisEnable at pr[00-02]=200, Special.Kung, 2022/12/02]
  if(btArtemisEnable)
  {
    write_ep(BLK_WRITE,DLC_FUN, 0x0100|0x0040);   //04-36 //Enable for Artemis-->DLC_btPDO_ID005_Enable & DLC_ubSpdLimMode=2:re-leveling
  }
  else
  {
    write_ep(BLK_WRITE,DLC_FUN, 0x0040);   //04-36 //Enable for Artemis-->DLC_btPDO_ID005_Enable & DLC_ubSpdLimMode=2:re-leveling
  }
  
  write_ep(BLK_WRITE,PDO_TYPE, 0);
  write_ep(BLK_WRITE,DS_LEN, 0);
  write_ep(BLK_WRITE,EV_ID, 0);
  write_ep(BLK_WRITE,CAN_FUN, 0);
}

void DLC_Init(void){
  DLC_uwJ4 = 0;
  DLC_uwTD = 0;
  DLC_uwTDCnt = 0;

  DLC_uwS1Tmr = 0;
  DLC_uwAccTmr = 0;
  DLC_uwS2Tmr = 0;
  DLC_uwConTmr = 0;
  DLC_uwS3Tmr = 0;
  DLC_uwDecTmr = 0;
  DLC_uwS4Tmr = 0;
  DLC_ubMode = MODE_NULL;		// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 add
  DLC_ulSpd0p1mm = 0;			// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 add
}

void DLC_PrMgr(UBYTE Val){
	UWORD i, j; //[for loop die because UBYTE,Lyabryan,2020/09/09]
	ULONG ulTmp,ulTmp2;
	UDOUBLE ud1, ud2, ud3;
	UWORD uwLift_SPD,uwSpeedLimit_Temp;
	
	if(Val == PR_INIT_RD){	
		//�򥻰Ѽ�
    //DLC_ulOffset = U32xU32divU32((PGBS>>2), COF_ulPls2MMgain, 65536);	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source   
    //DLC_ulOffset = DLC_ulOffset/10;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
    DLC_ulOffset = (ULONG)(((UDOUBLE)PGBS * (UDOUBLE)COF_ulPls2MMgain + 1310720) / 2621440);	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new

    DLC_ulPgCnt = pr[CUR_PG_H]*10000+pr[CUR_PG_L];
    DLC_ulPgBrd = pr[LEV_BRD_PG_H]*10000+pr[LEV_BRD_PG_L];
    DLC_ulPgSen = pr[SENSOR_H]*10000+pr[SENSOR_L];

    //pr[LEV_LEN] = (U32xU32divU32((DLC_ulPgBrd>>2), COF_ulPls2MMgain, 65536))/10;// brd length Aevin 7/6/2018	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source   
    pr[LEV_LEN] = (UWORD)(((UDOUBLE)DLC_ulPgBrd * (UDOUBLE)COF_ulPls2MMgain + 1310720) / 2621440); // Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new

		// DLC pos initial fail over 32F, Henry, 20170621
		//for(i = 1; i <= 32; i ++){
		for(i = 1; i <= 0x4B; i ++){
		    j = i - 1;
			DLC_ulPosLev[i]	= DLCxx[j<<1]*1000;
			DLC_ulPosLev[i] = DLC_ulPosLev[i]+DLCxx[((j<<1)+1)];
		}

        for(i = 1; i <= 0x4B; i ++){
		    //DLC_ulPgLev[i] = (U32xU32divU32(DLC_ulPosLev[i], 65536, COF_ulPls2MMgain))<<2;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
		    //DLC_ulPgLev[i] = DLC_ulPgLev[i]*10;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
			DLC_ulPgLev[i] = (ULONG)(((UDOUBLE)DLC_ulPosLev[i] * 2621440 + (UDOUBLE)(COF_ulPls2MMgain >> 1)) / (UDOUBLE)COF_ulPls2MMgain);	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
        }

		//DLC position offset, Henry
		Update_C40xx();
		
		// DLC position offset, Henry
		if(pr[FLOOR_PAGE] == 0){
		    for(i=0; i<DLC_25ADDR; i++)
    		    pr[FL_POSIT_1H+i]= DLCxx[i];
		}    
		else if(pr[FLOOR_PAGE] == 1){    //prvalue = 1    
		    for(i=DLC_25ADDR; i<DLC_50ADDR; i++)
		        pr[FL_POSIT_1H+i-DLC_25ADDR]= DLCxx[i];
		}
		else if(pr[FLOOR_PAGE] == 2){
		    for(i=DLC_50ADDR; i<DLC_75ADDR; i++)
		        pr[FL_POSIT_1H+i-DLC_50ADDR]= DLCxx[i];
		}
		else if(pr[FLOOR_PAGE] == 3){		// floor adjustment Aevin 6/192/2018
		    for(i=DLC_75ADDR; i<DLC_LimADDR; i++){
		        pr[FL_POSIT_1H+i-DLC_75ADDR]= DLCxx[i];
		    }
		}
		else if(pr[FLOOR_PAGE] == 4){		//adjust floor position,Henry,2019/01/07
			for(i=DLC_LimADDR; i<DLC_Adj50ADDRUP; i++){
			    pr[FL_POSIT_1H+i-DLC_LimADDR]= DLCxx[i];
			}
		}
		else if(pr[FLOOR_PAGE] == 5){		//adjust floor position,Henry,2019/01/07
			for(i=DLC_Adj50ADDRUP; i<DLC_Adj50ADDRDN; i++){
			    pr[FL_POSIT_1H+i-DLC_Adj50ADDRUP]= DLCxx[i];
			}
		}
		else if(pr[FLOOR_PAGE] == 6){		//adjust floor position,Henry,2019/01/07
			for(i=DLC_Adj50ADDRDN; i<DLC_Adj5175ADDRUPDN; i++){
			    pr[FL_POSIT_1H+i-DLC_Adj50ADDRDN]= DLCxx[i];
			}
		}

    //JINGDO
    //decel switch protection trigger, Henry, 2016/08/18
    DLC_ulPosDD1 = DLCxx[DD1_H]*1000+DLCxx[DD1_L]; // JINGDO
    DLC_ulPosDD2 = DLCxx[DD2_H]*1000+DLCxx[DD2_L]; // JINGDO
    DLC_ulPosDD3 = DLCxx[DD3_H]*1000+DLCxx[DD3_L]; // JINGDO
    DLC_ulPosDD4 = DLCxx[DD4_H]*1000+DLCxx[DD4_L]; // JINGDO
    DLC_ulPosUD1 = DLCxx[UD1_H]*1000+DLCxx[UD1_L]; // JINGDO
    DLC_ulPosUD2 = DLCxx[UD2_H]*1000+DLCxx[UD2_L]; // JINGDO
    DLC_ulPosUD3 = DLCxx[UD3_H]*1000+DLCxx[UD3_L]; // JINGDO
    DLC_ulPosUD4 = DLCxx[UD4_H]*1000+DLCxx[UD4_L]; // JINGDO
    DLC_ulPosUL = DLCxx[UL_H]*1000+DLCxx[UL_L];		
			
    DLC_ulPgDD1 = (U32xU32divU32(DLC_ulPosDD1,65536,COF_ulPls2MMgain))<<2;
    DLC_ulPgDD1 = DLC_ulPgDD1*10;
    DLC_ulPgDD2 = (U32xU32divU32(DLC_ulPosDD2,65536,COF_ulPls2MMgain))<<2;
    DLC_ulPgDD2 = DLC_ulPgDD2*10;
    DLC_ulPgDD3 = (U32xU32divU32(DLC_ulPosDD3,65536,COF_ulPls2MMgain))<<2;
    DLC_ulPgDD3 = DLC_ulPgDD3*10;
    DLC_ulPgDD4 = (U32xU32divU32(DLC_ulPosDD4,65536,COF_ulPls2MMgain))<<2;
    DLC_ulPgDD4 = DLC_ulPgDD4*10;
    DLC_ulPgUD1 = (U32xU32divU32(DLC_ulPosUD1,65536,COF_ulPls2MMgain))<<2;		
    DLC_ulPgUD1 = DLC_ulPgUD1*10;
    DLC_ulPgUD2 = (U32xU32divU32(DLC_ulPosUD2,65536,COF_ulPls2MMgain))<<2;		
    DLC_ulPgUD2 = DLC_ulPgUD2*10;
    DLC_ulPgUD3 = (U32xU32divU32(DLC_ulPosUD3,65536,COF_ulPls2MMgain))<<2;		
    DLC_ulPgUD3 = DLC_ulPgUD3*10;
    DLC_ulPgUD4 = (U32xU32divU32(DLC_ulPosUD4,65536,COF_ulPls2MMgain))<<2;		
    DLC_ulPgUD4 = DLC_ulPgUD4*10;
    DLC_ulPgUL = (U32xU32divU32(DLC_ulPosUL,65536,COF_ulPls2MMgain))<<2;		
    DLC_ulPgUL = DLC_ulPgUL*10;

    DLC_ubLevMax = pr[MAX_FLOOR];
    DLC_ubLevMin = 1;
    DLC_ubLevCur = pr[LEV_CUR];
	}
	else if(Val == PR_RD){ 
		// Decoder PDO msg
		DLC_btErr = (DLC_PDO_RX_EM.uw&0x0001)?1:0;        // bit0
		DLC_btRdy = (DLC_PDO_RX_EM.uw&0x0002)?1:0;        // bit1
		DLC_btModNor = (DLC_PDO_RX_EM.uw&0x0004)?1:0;     // bit2
		DLC_btModZeo = (DLC_PDO_RX_EM.uw&0x0008)?1:0;     // bit3
		DLC_btModIns = (DLC_PDO_RX_EM.uw&0x0010)?1:0;     // bit4
		DLC_btModRsq = (DLC_PDO_RX_EM.uw&0x0020)?1:0;     // bit5
		DLC_btModLev = (DLC_PDO_RX_EM.uw&0x0040)?1:0;     // bit6
		DLC_btModAutoLev = (DLC_PDO_RX_EM.uw&0x0080)?1:0; // bit7
		// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong add 20220902 -------
		if(DLC_btModNor && !DLC_btModNorOld){	
			DLC_ubLevSta = DLC_ubLevCur;
		}
		DLC_btModNorOld = DLC_btModNor;
        //========== EPS Flag ===========//
        //EPS function of DLC mode , James, 20200408
        EPS_MI_SET = 0;
		for(i=0;i<8;i++){
            if(pr[MI1+i]==43){
                EPS_MI_SET = 1;
                break;
            }
		}
		if(EPS_MI_SET){
		}
        else{
            DLC_btEPS = (DLC_PDO_RX_EM.uw&0x0100)?1:0;        // bit8
    		if(DLC_btEPS){
                EPS = 1;
    		}
    		else{
                EPS = 0;
    		}
        }
        //========== EPS Flag ===========//
        
		i = DLC_btFSD1;
		j = (DLC_PDO_RX_EM.uw&0x0400)?1:0;
		DLC_btModFSD = ((i==1)||(j==1))?1:0;              // bit10

	    DLC_btModHome = (DLC_PDO_RX_EM.uw&0x0800)?1:0;    // bit11
        UCMP = (DLC_PDO_RX_EM.uw&0x1000)?1:0;             // bit12 //[UCMP function, Bernie, 2016/06/14]

		if((WarnCode==CANOFF_WARN) &&        // CAN OFF
		   (DLC_ubLevCur==DLC_ubLevTar) &&   // arrival target lev
		   (fcmd.uw.hi==0)){                    // zero-spd
		    DLC_PDO_RX_DI.uw &= ~0x0002;    // clr up cmd
		    DLC_PDO_RX_DI.uw &= ~0x0004;    // clr dn cmd
		}
		else if((WarnCode==CANOFF_WARN) &&
			      (fcmd.uw.hi==0) &&
			      (DLC_btModFSD==1)){
			DLC_PDO_RX_DI.uw &= ~0x0002;    // clr up cmd
			DLC_PDO_RX_DI.uw &= ~0x0004;    // clr dn cmd			
		}
				
		DLC_btRst = (DLC_PDO_RX_DI.uw & 0x0001) ? 1 : 0;
		
		if(DLC_btRst == 1){
			DLC_PDO_RX_DI.uw &= ~0x0001;
			reset();
		}
		
		//Gfc DLC modify , Henry, 2018/05/23
		if((DLC_btCANOff)||(pr[SOFC]==5)){ //�g�ѹ���u�����wRUN
			DLC_btUP = (mfi_status&0x01)?1:0;
		}
		else if(pr[SOFC]==4){ //�g��CAN_BUS���w��V
			DLC_btUP = (DLC_PDO_RX_DI.uw&0x02)?1:0;
		}

		if((DLC_btCANOff)||(pr[SOFC]==5)){ //�g�ѹ���u�����wRUN
			DLC_btDN = (mfi_status&0x02)?1:0;
		}
		else if(pr[SOFC]==4){ //�g��CAN_BUS���w��V
			DLC_btDN = (DLC_PDO_RX_DI.uw&0x04)?1:0;
		}
		
		/*
		i = (mfi_status&0x01)?1:0;
		if(DLC_btCANOff==1)
			j = 0;
		else
			j = (DLC_PDO_RX_DI.uw & 0x0002)?1:0;
        DLC_btUP = ((i == 1) || (j == 1)) ? 1 : 0;
		
		i = (mfi_status & 0x02)?1:0; // DLC_UP, DLC_DN MFIO mixed, V9.03 16055
		if(DLC_btCANOff == 1)
			j = 0;
		else		
			j = (DLC_PDO_RX_DI.uw & 0x0004) ? 1 : 0;
		DLC_btDN = (i == 1 || j == 1) ? 1 : 0;
		*/
		
        i = DLC_btLU1;                             // byte2 bit3
        j = (DLC_PDO_RX_DI.uw&0x0008)?1:0;
        DLC_btLU = (i||j)?1:0;
    	
        i = DLC_btLD1;                             // byte2 bit4
        j = (DLC_PDO_RX_DI.uw&0x0010)?1:0;
        DLC_btLD = (i||j)?1:0;
    	
        DLC_btDZN = (DLC_PDO_RX_DI.uw & 0x1000)?1:0;
    	
        i = mio_btDD1;   // JINGDO                 // byte2 bit5
        j = (DLC_PDO_RX_DI.uw&0x0020)?1:0;         
        DLC_btDD1 = (i||j)?1:0;
    	
        i = mio_btUD1;   // JINGDO                 // byte2 bit6
        j = (DLC_PDO_RX_DI.uw&0x0040)?1:0;
        DLC_btUD1 = (i||j)?1:0;

        if(RUNNING==STOP)   //Jerry.sk.Tseng 2022/11/25
        {
            ubDLC_btDD1_Stop = DLC_btDD1;
            ubDLC_btUD1_Stop = DLC_btUD1;
        }
    	
        i = mio_btDD2;   // JINGDO                 // byte4 bit0
        j = (DLC_PDO_RX_RC.ub&0x01)?1:0;         
        DLC_btDD2 = (i||j)?1:0;
    	
        i = mio_btUD2;   // JINGDO                 // byte4 bit1
        j = (DLC_PDO_RX_RC.ub&0x02)?1:0;
        DLC_btUD2 = (i||j)?1:0;
    	
        i = mio_btDD3;   // JINGDO                 // byte4 bit2
        j = (DLC_PDO_RX_RC.ub&0x04)?1:0;         
        DLC_btDD3 = (i||j)?1:0;
    	
        i = mio_btUD3;   // JINGDO                 // byte4 bit3
        j = (DLC_PDO_RX_RC.ub&0x08)?1:0;
        DLC_btUD3 = (i||j)?1:0;
    	
        i = mio_btDD4;   // JINGDO                 // byte4 bit4
        j = (DLC_PDO_RX_RC.ub&0x10)?1:0;         
        DLC_btDD4 = (i||j)?1:0;
    	
        i = mio_btUD4;   // JINGDO                 // byte4 bit5
        j = (DLC_PDO_RX_RC.ub&0x20)?1:0;
        DLC_btUD4 = (i||j)?1:0;
    									
		//DLC�t�װ򥻰Ѽ�Ū�� (���:ms)
		DLC_uwTR1 = pr[S4ACC1]*10;	  //01-24 DOT2
		DLC_uwTR2 = pr[S4ACC2]*10;	  //01-25	DOT2
		DLC_uwTR3 = pr[S4DEC1]*10;	  //01-26 DOT2
		DLC_uwTR4 = pr[S4DEC2]*10;	  //01-27 DOT2
		//DLC_uwTRa = pr[ACCEL1]*10;	//01-12 DOT2
		//DLC_uwTRd = pr[DECEL1]*10;	//01-13 DOT2

		DLC_uwTc = pr[LAND_DLY_TIME]; //04-25 DOT0

		//minimum protection
		DLC_uwTR1 = (DLC_uwTR1==0)?1:DLC_uwTR1;
		DLC_uwTR2 = (DLC_uwTR2==0)?1:DLC_uwTR2;
		DLC_uwTR3 = (DLC_uwTR3==0)?1:DLC_uwTR3;
		DLC_uwTR4 = (DLC_uwTR4==0)?1:DLC_uwTR4;
		
		//���:mm
		//DLC_uwRateSpd = 10*pr[Lift_SPD];	//04-16 DOT2
		//[ADCO EPS Modify]
		ud1 = (UDOUBLE)10*(UDOUBLE)pr[Lift_SPD]*(UDOUBLE)pr[RATIO];
		ud1 = ud1/(UDOUBLE)100;
		//DLC_uwRateSpd = ud1;
		DLC_uwRateSpdMax= ud1;
		if(DLC_ubDIR == DIR_UP)
		{		
			if((DLC_ulPosUD1 != 0)&&(DLC_btUD1 == 1) && (pr[DD1_Vlim] != 0))
			{			
				DLC_uwRateSpd = pr[DD1_Vlim]*10;
			}
			else if((DLC_ulPosUD2 != 0)&&(DLC_btUD2 == 1) && (pr[DD2_Vlim] != 0))
			{
				DLC_uwRateSpd = pr[DD1_Vlim]*10;
			}
			else if((DLC_ulPosUD3 != 0)&&(DLC_btUD3 == 1) && (pr[DD3_Vlim] != 0))
			{
				DLC_uwRateSpd = pr[DD2_Vlim]*10;
			}
			else if((DLC_ulPosUD4 != 0)&&(DLC_btUD4 == 1) && (pr[DD4_Vlim] != 0))
			{
				DLC_uwRateSpd = pr[DD3_Vlim]*10;
			}
			//[Artemis Add Sensor819 Function/Special/2022/06/06]
			else if((DLC_btUD1 == 1 && ubDLC_btUD1_Stop == 1) && (pr[Sensor819] != 0))
			{			
				uwSpeedLimit_Temp = 10*pr[Speed_Limit];

				if(DLC_uwRateSpdMax>uwSpeedLimit_Temp)
				{
					DLC_uwRateSpdMax = uwSpeedLimit_Temp;
				}
				else
				{
					DLC_uwRateSpdMax = DLC_uwRateSpdMax;
				}
		
				DLC_uwRateSpd = DLC_uwRateSpdMax;
			}
			//[Artemis Add Sensor819 Function/Special/2022/06/06]
			else
			{
				DLC_uwRateSpd = DLC_uwRateSpdMax;
			}
		}
			
		if(DLC_ubDIR == DIR_DN)
		{
			if((DLC_ulPosDD1 != 0)&& (DLC_btDD1 == 1) && (pr[DD1_Vlim] != 0))
			{
				DLC_uwRateSpd = pr[DD1_Vlim]*10;
			}
			else if((DLC_ulPosDD2 != 0)&& (DLC_btDD2 == 1) && (pr[DD2_Vlim] != 0))
			{
				DLC_uwRateSpd = pr[DD1_Vlim]*10;
			}
			else if((DLC_ulPosDD3 != 0)&& (DLC_btDD3 == 1) && (pr[DD3_Vlim] != 0))
			{
				DLC_uwRateSpd = pr[DD2_Vlim]*10;
			}
			else if((DLC_ulPosDD4 != 0)&& (DLC_btDD4 == 1) && (pr[DD4_Vlim] != 0))
			{
				DLC_uwRateSpd = pr[DD3_Vlim]*10;
			}
			//[Artemis Add Sensor819 Function/Special/2022/06/06]
			else if((DLC_btDD1 == 1 && ubDLC_btDD1_Stop == 1) && (pr[Sensor819] != 0))
			{
				uwSpeedLimit_Temp = 10*pr[Speed_Limit];

				if(DLC_uwRateSpdMax>uwSpeedLimit_Temp)
				{
					DLC_uwRateSpdMax = uwSpeedLimit_Temp;
				}
				else
				{
					DLC_uwRateSpdMax = DLC_uwRateSpdMax;
				}
		
				DLC_uwRateSpd = DLC_uwRateSpdMax;
			}
			//[Artemis Add Sensor819 Function/Special/2022/06/06]
			else
			{
				DLC_uwRateSpd = DLC_uwRateSpdMax;
			}
		}	
		//���:mm/sec
		//DLC_uwAa = ((UDOUBLE)1000*(UDOUBLE)DLC_uwRateSpd)/(UDOUBLE)DLC_uwTRa;
 	    //DLC_uwAd = ((UDOUBLE)1000*(UDOUBLE)DLC_uwRateSpd)/(UDOUBLE)DLC_uwTRd;
		//DLC_uwAa = pr[AACC];
		//DLC_uwAd = pr[ADEC];
		DLC_uwAa = pr[ACCEL1]*10;
		DLC_uwAd = pr[DECEL1]*10;
		
		//���:mm^2/sec
		DLC_uwJR1 = ((UDOUBLE)1000*(UDOUBLE)DLC_uwAa)/(UDOUBLE)DLC_uwTR1;
		DLC_uwJR2 = ((UDOUBLE)1000*(UDOUBLE)DLC_uwAa)/(UDOUBLE)DLC_uwTR2;
		DLC_uwJR3 = ((UDOUBLE)1000*(UDOUBLE)DLC_uwAd)/(UDOUBLE)DLC_uwTR3;
		DLC_uwJR4 = ((UDOUBLE)1000*(UDOUBLE)DLC_uwAd)/(UDOUBLE)DLC_uwTR4;
	
		//���:mm/sec
		DLC_uwVR1 = ((UDOUBLE)DLC_uwJR1*(UDOUBLE)DLC_uwTR1*(UDOUBLE)DLC_uwTR1)/(UDOUBLE)2000000;	//V1�z�Q�t���ܤƶq
		DLC_uwVR2 = ((UDOUBLE)DLC_uwJR2*(UDOUBLE)DLC_uwTR2*(UDOUBLE)DLC_uwTR2)/(UDOUBLE)2000000;	//V2�z�Q�t���ܤƶq
		DLC_uwVR3 = ((UDOUBLE)DLC_uwJR3*(UDOUBLE)DLC_uwTR3*(UDOUBLE)DLC_uwTR3)/(UDOUBLE)2000000;	//V3�z�Q�t���ܤƶq
		DLC_uwVR4 = ((UDOUBLE)DLC_uwJR4*(UDOUBLE)DLC_uwTR4*(UDOUBLE)DLC_uwTR4)/(UDOUBLE)2000000;	//V4�z�Q�t���ܤƶq
		
		
		//�Ѽ�Ū��
		pr[LEV_CUR] = DLC_ubLevCur; 
		DLC_btPRChk = (pr[CAN_FUN]&0x0001)?1:0;
		DLC_btWelDone = (pr[CAN_FUN]&0x0002)?1:0;
		DLC_btWelExc = (pr[CAN_FUN]&0x0004)?1:0;
		DLC_btWelRec = (pr[CAN_FUN]&0x0008)?1:0;
		DLC_btWelRst = (pr[CAN_FUN]&0x0010)?1:0;
			
		//04-36 DLC Function
		DLC_btADCO = (pr[DLC_FUN]&0x0001)?1:0;   //bit0
		DLC_btEPSDir = (pr[DLC_FUN]&0x0002)?1:0; //bit1
		DLC_btDznMd = (pr[DLC_FUN]&0x0004)?1:0;  //bit2  // adco
		DLC_btWelDec = (pr[DLC_FUN]&0x0008)?1:0; //bit3
		DLC_btCanEmStp = (pr[DLC_FUN]&0x0010)?1:0; //bit4  //Gfc DLC modify , Henry, 2018/05/23
		DLC_ubSpdLimMode = (pr[DLC_FUN]&0x0060)>>5; //bit6&5 over speed treatment>>00:disable 01:Force stop 10:re-leveling
		DLC_btTorOfsDir = (pr[DLC_FUN]&0x0080)?1:0; //bit7	// Sean, 20181210

		DLC_btPosLULDCal = (pr[DLC_FUN]&0x0200)?1:0; //bit9	//James, 20210421
		DLC_btParkTooFar = (pr[DLC_FUN]&0x0400)?1:0;	//bit10 �����L�Y	// Task 268638 �������a-�h�q�t�[��t��S���u Mitong 20220516

		
		DLC_btPDO_ID005_Enable = (pr[DLC_FUN]&0x0100)?1:0;//bit8 //Artemis Speed &Position PDO transmition , James, 20200603
		//expand handshaking time for PDO_ID005	, James, 20201201	 
		
		if(DLC_btPDO_ID005_Enable)
		{
			if(pr[PDO_TX_Time] < 3)
			{
				pr[PDO_TX_Time] = 3;
			}
		}
	}
	else if(Val == PR_WR){
		
		// Encoder PDO Package[
		
		// mfo_ready condition
		if(Error==0 && PGREADY==1 && RelayOFF==0)	
			DLC_PDO_TX_INV_ST.bit.b0 = 1;
		else
			DLC_PDO_TX_INV_ST.bit.b0 = 0;
	
		if(UCMP != 0)          //[UCMP function, Bernie, 2016/06/14]  
			DLC_PDO_TX_INV_ST.bit.b1 = 1;
		else
			DLC_PDO_TX_INV_ST.bit.b1 = 0;

		if(WarnCode!=0)
			DLC_PDO_TX_INV_ST.bit.b2 = 1;
		else
			DLC_PDO_TX_INV_ST.bit.b2 = 0;
		DLC_PDO_TX_INV_ST.bit.b3 = (DLC_btUP == 1) ? 1 : 0;
		DLC_PDO_TX_INV_ST.bit.b4 = (DLC_btDN == 1) ? 1 : 0;
		DLC_PDO_TX_INV_ST.bit.b5 = (DLC_btModNor == 1) ? 1 : 0;
		
		if(DLC_btEPSDir)
			DLC_PDO_TX_INV_ST.bit.b6 = GENDIR?1:0;
		else
			DLC_PDO_TX_INV_ST.bit.b6 = (DLC_btReCalFlag== 1)?1:0;	
		
		//�̾�mfo_fcmdzero����
		if(fcmd.uw.hi==0)
			DLC_PDO_TX_INV_ST.bit.b7 = 1;
		else
			DLC_PDO_TX_INV_ST.bit.b7 = 0;
		DLC_PDO_TX_INV_ST.bit.b8 = (DLC_btModIns==1)?1:0;
		DLC_PDO_TX_INV_ST.bit.b9 = (DLC_btModRsq==1)?1:0;
		DLC_PDO_TX_INV_ST.bit.b10 = (DLC_btModLev==1)?1:0;
		
		//[ADCO EPS Modify]
		if((DLC_btLU == 1 && DLC_btLD == 1)||(DLC_btDZN == 1)){
		    if((EPS)||(fcmd.uw.hi==0))
			    DLC_PDO_TX_INV_ST.bit.b11 = 1;
		    else
			    DLC_PDO_TX_INV_ST.bit.b11 = 0;
		}
		else
		    DLC_PDO_TX_INV_ST.bit.b11 = 0;
			
		DLC_PDO_TX_INV_ST.bit.b12 = (DLC_btModAutoLev==1)?1:0;
		
		#if(0)
		DLC_PDO_TX_INV_ST.bit.b11 = (DLC_btEffic==1)?1:0;
		#endif
		
		// spd deceleration bit, v0.03
		if((DLC_ubMode==MODE_S3)||(DLC_ubMode==MODE_DEC)|| 
			 (DLC_ubMode==MODE_S4)||(DLC_ubMode==MODE_DYN)){
			DLC_ubDecel = 1;
		}
		else{
			DLC_ubDecel = 0;
		}
		DLC_PDO_TX_INV_ST.bit.b13 = (DLC_ubDecel)?1:0;
		
		DLC_PDO_TX_INV_ST.bit.b14 = (DLC_btModFSD==1)?1:0;
		//�̾�mfo_braker_release����
		//DLC_PDO_TX_INV_ST.bit.b15 = (DLC_ulCurSpd<=0)?1:0;
		DLC_PDO_TX_INV_ST.bit.b15 = (BRK_RLS == 1) ? 1 : 0;	
						
		//reserved (byte2)
		DLC_PDO_TX_AskC.ub = Error;
		//accepted landing floor (byte3)
		DLC_PDO_TX_ALF = DLC_ubLevOk;
		//landing target floor (byte4)
		DLC_PDO_TX_LTF = DLC_ubLevTar;
		
		// encoder PDO byte6, byte7
		DLC_PDO_Byte67();
		
		//�ѼƼg�J [
		pr[CUR_PG_H] = DLC_ulPgCnt/10000;
		pr[CUR_PG_L] = DLC_ulPgCnt%10000;
		
		//�ھ�DLC_ulPgCnt�h����XDLC_ulPosVal (mm), DLC_ubLevCur
		//mod pulse to mm
//		ulTmp = DLC_ulPgBrd/pr[LEV_BRD];
//		DLC_ulPosVal = DLC_ulPgCnt/ulTmp;
		//DLC_ulPosVal = U32xU32divU32((DLC_ulPgCnt>>2), COF_ulPls2MMgain, 65536);	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
		//DLC_ulPosVal = DLC_ulPosVal/10;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
		DLC_ulPosVal = (ULONG)(((UDOUBLE)DLC_ulPgCnt * (UDOUBLE)COF_ulPls2MMgain + 1310720) / 2621440);	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
		
#if 1	// Sean, 20181210
		//DLC_ulOffset = U32xU32divU32((PGBS>>2), COF_ulPls2MMgain, 65536);	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
		//DLC_ulOffset = DLC_ulOffset/10;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
		DLC_ulOffset = (ULONG)(((UDOUBLE)PGBS * (UDOUBLE)COF_ulPls2MMgain + 1310720) / 2621440);	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
#endif		
		// DLC position offset, Henry
#if 0
		pr[INV_POS_H] = DLC_ulPosVal/1000;	//m
		pr[INV_POS_L] = DLC_ulPosVal%1000;	//mm
#else
		DLC_ulPosPar.ul = DLC_ulPosVal-DLC_ulOffset;
		pr[INV_POS_H] = DLC_ulPosPar.ul/1000;	//m
		pr[INV_POS_L] = DLC_ulPosPar.ul%1000;	//mm
#endif
		//PDO_ID=0x04
		//Gfc DLC modify , Henry, 2018/05/23
		if(DLC_btModDec)
			DLC_PDO_ID004_B0.bit.b0 = 1;
		else
			DLC_PDO_ID004_B0.bit.b0 = 0;
		
		DLC_PDO_ID004_B1.ub = 0x00;
		DLC_PDO_ID004_B2.ub = WarnCode;
		//Gfc DLC modify , Henry, 2018/05/23
		DLC_PDO_ID004_B3.ub = mfo_now;//mfo_status;//James, 2021/10/25
		DLC_PDO_ID004_B3.bit.b6 = MOTORCONNECTOR;
		DLC_PDO_ID004_B3.bit.b7 = BRK_RLS;
		DLC_PDO_ID004_B4.ub = 0x00;
		DLC_PDO_ID004_B5.ub = 0x00;
		
        uwLift_SPD = U32xU32divU32(SpDt_uwFfbk, pr[Lift_SPD],pr[FMAX]);//(Hz,dot2) --> (m/s, dot2) //Artemis Speed &Position PDO transmition , James, 20200225
		ulLiftSpdFdb.ul = lowpass_ul(256, uwLift_SPD, ulLiftSpdFdb.ul);

		//Artemis Speed &Position PDO transmition , James, 20200603
		if(DLC_btPDO_ID005_Enable)
		{
			DLC_PDO_ID004_B6.ub = ulLiftSpdFdb.ub.b2;//0.01 m/s
			DLC_PDO_ID004_B7.ub = ulLiftSpdFdb.ub.b3;
			DLC_PDO_ID005_B0.ub = DLC_ulPosPar.ub.b0;//mm, byte0+byte1
			DLC_PDO_ID005_B1.ub = DLC_ulPosPar.ub.b1;
			DLC_PDO_ID005_B2.ub = DLC_ulPosPar.ub.b2;//m, byte2+byte3
			DLC_PDO_ID005_B3.ub = DLC_ulPosPar.ub.b3;
			DLC_PDO_ID005_B4.ub = DLC_ulDisTar.ub.b0;//mm, byte0+byte1
			DLC_PDO_ID005_B5.ub = DLC_ulDisTar.ub.b1;
			DLC_PDO_ID005_B6.ub = DLC_ulDisTar.ub.b2;//m, byte2+byte3
			DLC_PDO_ID005_B7.ub = DLC_ulDisTar.ub.b3;
		}
		
		pr[LEV_CUR] = DLC_ubLevCur;
		
		// para 09-11
		// bit0
		pr[DLC_MODE1]=(DLC_btLU==1)?(pr[DLC_MODE1]|0x0001):(pr[DLC_MODE1]&~0x0001);
		// bit1    
		pr[DLC_MODE1]=(DLC_btLD==1)?(pr[DLC_MODE1]|0x0002):(pr[DLC_MODE1]&~0x0002);
		// bit2
		pr[DLC_MODE1]=(DLC_btRst==1)?(pr[DLC_MODE1]|0x0004):(pr[DLC_MODE1]&~0x0004);
		// bit3
		pr[DLC_MODE1]=(DLC_btUP==1)?(pr[DLC_MODE1]|0x0008):(pr[DLC_MODE1]&~0x0008);
		// bit4
		pr[DLC_MODE1]=(DLC_btDN==1)?(pr[DLC_MODE1]|0x0010):(pr[DLC_MODE1]&~0x0010);
		// bit5
		pr[DLC_MODE1]=(DLC_btCANOff==1)?(pr[DLC_MODE1]|0x0020):(pr[DLC_MODE1]&~0x0020);
		// bit6
		pr[DLC_MODE1]=(DLC_btSpdL==1)?(pr[DLC_MODE1]|0x0040):(pr[DLC_MODE1]&~0x0040);		
		// bit7
		pr[DLC_MODE1]=(GENDIR==1)?(pr[DLC_MODE1]|0x0080):(pr[DLC_MODE1]&~0x0080);		
		// bit8
		pr[DLC_MODE1]=(DLC_btDD1==1)?(pr[DLC_MODE1]|0x00100):(pr[DLC_MODE1]&~0x00100);
		// bit9
		pr[DLC_MODE1]=(DLC_btUD1==1)?(pr[DLC_MODE1]|0x0200):(pr[DLC_MODE1]&~0x0200);
		
		
		// para 09-12
		pr[DLC_MODE2] = DLC_uwEM.uw;					
		//]
	}
}

// driver PDO byte6, byte7 data
void DLC_PDO_Byte67(void){
	UDOUBLE udtmp1, udtmp2, udtmp3;

	if(pr[PDO_TYPE] == 0)
		DLC_PDO_TX_INV_SPD.uw = fcmd.uw.hi;   // 0.01Hz
	else if(pr[PDO_TYPE] == 1)
		DLC_PDO_TX_INV_SPD.uw = SpDt_uwFfbk;  // 0.01Hz
	else if(pr[PDO_TYPE] == 2){
		DLC_PDO_TX_INV_SPD.ub.hi = mfo_now;//mfo_status;//James, 2021/10/25
	}
	else if(pr[PDO_TYPE]==3){ //Gfc DLC modify , Henry, 2018/05/23
		udtmp1 = SpDt_uwFfbk;
		udtmp2 = pr[MFBASE1];
		udtmp3 = pr[Lift_SPD];
		
		udtmp1 = (udtmp1*udtmp3*100)/udtmp2;
		DLC_uwSfbk = udtmp1/100;
		DLC_PDO_TX_INV_SPD.uw = DLC_uwSfbk;
	}	
}

void DLC_Algorithm(void){
    UWORD ubDILow, ax, ubPgDir, i, j, ubTmp; //[for loop die because UBYTE,Lyabryan,2020/09/09]
    UWORD uwDI, uwPgTmp, uwTmp; // 0504 JINGDO
    UWORD uwPgDif,uwadjstVal;
    ULONG ulTmp, ulDisTar, ul_1, ul_2,uladjstVal,ulDelayCmpPg, ulDelayCmpmm;
    SLONG slPgDif;
    UDOUBLE ud1, ud2, ud3, ulspeed, ud4;
    double d1, d2, d3, d4;	
    Bool blCHG;
	UWORD	t_s3,	a_dec,	t_s4;	// Task 268638 �������a-�h�q�t�[��t��S���u Mitong 20220516
	//Ū��DLC�����Ѽ�
	DLC_PrMgr(PR_RD);
	
	//Ū����V�H��
	if(DLC_btUP == 1 && DLC_btDN == 1){
		DLC_btModDec = 1;
		if(DLC_ulCurSpd == 0){
			DLC_ubDIR = DIR_NULL;
			RUN_DCI_OK = 0;
		}
		else{
			DLC_ubDIR = DLC_ubDIR;
		}
	}
	else if(DLC_btUP == 1){ 
		if((DLC_btModNor == 1)&&(DLC_ubLevTar < DLC_ubLevCur)){ //Artemis DLC Reverse direction command Issue, James, 2020/01/16
			DLC_ubDIR = DLC_ubDIR;
			DLC_btModDec = 1;
			WarnDisplaySave();
			WarnCode = DLCDIR_WARN; 		
		}
		else{
			DLC_ubDIR = DIR_UP;
			if(WarnCode == DLCDIR_WARN){	
				WarnCode = 0;
				Keypad_Page = pr[S_DISP];
				Keypad_PageTmp = 0;
			}			
		}
	}
	else if(DLC_btDN == 1){
		if((DLC_btModNor == 1)&&(DLC_ubLevTar > DLC_ubLevCur)){ //Artemis DLC Reverse direction command Issue, James, 2020/01/16
			DLC_ubDIR = DLC_ubDIR;
			DLC_btModDec = 1;
			WarnDisplaySave();
			WarnCode = DLCDIR_WARN; 		
		}
		else{			
			DLC_ubDIR = DIR_DN;
			if(WarnCode == DLCDIR_WARN){	
				WarnCode = 0;
				Keypad_Page = pr[S_DISP];
				Keypad_PageTmp = 0;
			}	
		}
	}
	else{ //DLC_btUp=0 & DLC_btDn=0
		if(WarnCode == DLCDIR_WARN){	
			WarnCode = 0;
			Keypad_Page = pr[S_DISP];
			Keypad_PageTmp = 0;
		}		
		if(DLC_ulCurSpd == 0){
			DLC_ubDIR = DIR_NULL;
			RUN_DCI_OK = 0;
			DLC_btModDec = 0;
		}
		else{
			DLC_ubDIR = DLC_ubDIR;
			DLC_btModDec = 1;
		}
	}
    
	//#18597 DLC Edge Triggered, 2021/11/17
	//Detect edge of direction command 
	uwDI_buf = DLC_uwDI.uw & 0x0006;
	blCHG = (uwDI_old ^ uwDI_buf);
	uwDI_old = uwDI_buf;
	//Change to edge trigger after tuning
	if((blCHG == 0 && TUN_STOP == 1))
	{
		DLC_ubDIR = DIR_NULL;
		RUN_DCI_OK = 0;
		DLC_btModDec = 0;
	}

	//��k2
	uwPgTmp = MTU1.TCNT;
	slPgDif = (SWORD)(uwPgTmp - MTU1_Old);
	MTU1_Old = MTU1.TCNT;
	
	if(PGDIR == 1){
		if (pr[CHG_DIR] == 0)
			DLC_ulPgCnt += slPgDif;
		else
			DLC_ulPgCnt -= slPgDif;
	}
	else{
		if (pr[CHG_DIR] == 0)
			DLC_ulPgCnt -= slPgDif;
		else
			DLC_ulPgCnt += slPgDif;
	}
	// encoder pulse protection, Henry, 2016/08/18
	if(DLC_ulPgCnt > 100000000000000)
		DLC_ulPgCnt = 0;
	if(DLC_ulPgCnt < PGBS)//fix Ayra bug, Aevin yu, 2017/12/13
		DLC_ulPgCnt = PGBS;
	
	// level position correction
	ulTmp = 100*pr[Lift_SPD]*pr[PG_RST_MODE]/100;
	/*  // Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source --------------------------------
	//#16386 optimization for over landing cause from leveling sensor calibration , James, 2021/04/13
	if(pr[DelayCmp] != 0)	//04-40(�}��������v    sec)
	{
		ulDelayCmpmm = DLC_ulCurSpd * pr[DelayCmp];//m/s(dot4)*sec(dot3)-->mm(dot7), 4+3=7
		ulDelayCmpPg = U32xU32divU32(ulDelayCmpmm , 65536, COF_ulPls2MMgain)/250;//mm(dot7)*Q16/gain*Q2/1000
	}
	else
	{
		ulDelayCmpmm = 0;
		ulDelayCmpPg = 0;
	}   
	ultest1 = ulDelayCmpmm;
	ultest2 = ulDelayCmpPg;
	*/	//----------------------------------------------------------------------------------------------------------------

	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new -------------------------------------
	//#16386 optimization for over landing cause from leveling sensor calibration , James, 2021/04/13
	//04-40(�}��������v    sec)
	ulDelayCmpmm = DLC_ulCurSpd * (pr[DelayCmp] + pr[DIN_RES]);//m/s(dot4)*sec(dot3)-->mm(dot7), 4+3=7	//�N  �}��������v  �P  MI�o�i�ɶ����}
	//ulDelayCmpPg = U32xU32divU32(ulDelayCmpmm , 65536, COF_ulPls2MMgain)/250;//mm(dot7)*Q16/gain*Q2/1000	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
	ud4 = (UDOUBLE)COF_ulPls2MMgain * 250;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
	ulDelayCmpPg = (ULONG)(((UDOUBLE)ulDelayCmpmm * 65536 + (ud4>>1)) / ud4);	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
	// --------------------------------------------------------------------------------------------
	if((DLC_btWelExc == 0)&&(DLC_ulCurSpd <= ulTmp))
	{
	    if(DLC_btDznMd == 1)// adco
		{  
		    //DIR_UP LU position correction
			if(DLC_ubDIR == DIR_UP)
			{
				if((DLC_btDZN == 1)&&(DLC_btDZNOld == 0))	//�i�J�����e100mm
				{
					if((DLC_ulPosUD1 != 0)&&(DLC_btUD1 == 1) && (Driver_ID == IEDS_DRIVER))//#13761 position calibration on UDS1, James, 2020/03/03
					{
						 /*   [Artemis Add Sensor819 Function/Special/2022/06/06]
                        Arttemis no required floor correction
                        so add Driver_ID == IEDS_DRIVER
                        */
						DLC_ubLevCur = pr[MAX_FLOOR];	
			    	}
					//DLC_ulPgCnt = DLC_ulPgLev[DLC_ubLevCur]-(DLC_ulPgBrd>>1)+ulDelayCmpPg;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
					DLC_ulPgCnt = DLC_ulPgLev[DLC_ubLevCur]-((DLC_ulPgBrd+1)>>1)+ulDelayCmpPg;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
				}
				else if((DLC_btDZN == 0)&&(DLC_btDZNOld == 1))	//���}������100mm // Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 add
				{
					if(DLC_ubLevCur == DLC_ubLevSta)	// Mitong new �u�b�ҰʼӰ���@��
					{
						//DLC_ulPgCnt = DLC_ulPgLev[DLC_ubLevCur]+(DLC_ulPgBrd>>1)+ulDelayCmpPg;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
						DLC_ulPgCnt = DLC_ulPgLev[DLC_ubLevCur]+((DLC_ulPgBrd+1)>>1)+ulDelayCmpPg;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
					}
				}
			}
			//DIR_DN LD position correction
			else if(DLC_ubDIR == DIR_DN)
			{
				if((DLC_btDZN == 1)&&(DLC_btDZNOld == 0))	//�i�J�����e100mm
				{
                	// �NJames�[�������������v���즹�B,�U������eLD��Off��On�ɰ�����v // Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 --
                	//#16023 Rope compensation start
	                if(DLC_ubLevTar == DLC_ubLevCur){  //�i�J�����e185mm	
    	                DLC_ulPosRopeCmp = (ULONG)pr[ROPE_CMP] * 10 * (DLC_ulPosLev[pr[MAX_FLOOR]] - DLC_ulPosLev[DLC_ubLevTar]) / 
                                (DLC_ulPosLev[pr[MAX_FLOOR]] - DLC_ulPosLev[DLC_ubLevMin]); // 0.1mm
        	            DLC_ulPgRopeCmp = ((U32xU32divU32(DLC_ulPosRopeCmp, 65536, COF_ulPls2MMgain))<<2);  //�����������v��Pulse
            	    }
                	else{
                    	DLC_ulPgRopeCmp = 0;
	                }
    	            // -------------------------------------------------------------------------------------------------------------
                
					if((DLC_ulPosDD1 != 0)&&(DLC_btDD1 == 1) && (Driver_ID == IEDS_DRIVER))//#13761 position calibration on DDS1, James, 2020/03/03
					{
						/*   [Artemis Add Sensor819 Function/Special/2022/06/06]
                        Arttemis no required floor correction
                        so add Driver_ID == IEDS_DRIVER
                        */
						DLC_ubLevCur = DLC_ubLevMin;					      	
					}
					//	DLC_ulPgCnt = DLC_ulPgLev[DLC_ubLevCur]+(DLC_ulPgBrd>>1)-ulDelayCmpPg;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 souce
					DLC_ulPgCnt = DLC_ulPgLev[DLC_ubLevCur]+((DLC_ulPgBrd+1)>>1)-ulDelayCmpPg + DLC_ulPgRopeCmp;// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
				}
				else if((DLC_btDZN == 0)&&(DLC_btDZNOld == 1))	//���}������100mm	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 add
				{
					if(DLC_ubLevCur == DLC_ubLevSta)	// Mitong new �u�b�ҰʼӰ���@��
					{
						DLC_ulPgCnt = DLC_ulPgLev[DLC_ubLevCur]-((DLC_ulPgBrd+1)>>1)-ulDelayCmpPg;
					}
				}
			}
		}
		else
		{
			//DIR_UP LU position correction
			if(DLC_ubDIR == DIR_UP)
			{
				if((DLC_btLU == 1)&&(DLC_btLUOld == 0))//1st landing Calibration //�i�J�����e185mm,LU Off��On
				{
					if((DLC_ulPosUD1 != 0)&&(DLC_btUD1 == 1) && (Driver_ID == IEDS_DRIVER))//#13761 position calibration on UDS1, James, 2020/03/03
					{
						/*   [Artemis Add Sensor819 Function/Special/2022/06/06]
                        Arttemis no required floor correction
                        so add Driver_ID == IEDS_DRIVER
                        */						
						DLC_ubLevCur = pr[MAX_FLOOR];
					}
					//DLC_ulPgCnt = DLC_ulPgLev[DLC_ubLevCur]-(DLC_ulPgBrd>>1)-(DLC_ulPgSen>>1)+ulDelayCmpPg;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
					DLC_ulPgCnt = DLC_ulPgLev[DLC_ubLevCur]-((DLC_ulPgBrd+DLC_ulPgSen+1)>>1)+ulDelayCmpPg;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
				}
				else if((DLC_btLU == 1)&&(DLC_btLD == 1)&&(DLC_btLDOld == 0))//2nd landing Calibration //�i�J�����e15mm,��LU On,LD Off��On
				{	
					if(DLC_btPosLULDCal)	//04-36 Bit8==1
					{
						//DLC_ulPgCnt = DLC_ulPgLev[DLC_ubLevCur]-(DLC_ulPgBrd>>1)+(DLC_ulPgSen>>1)+ulDelayCmpPg;//#16023 advance landing	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
						DLC_ulPgCnt = DLC_ulPgLev[DLC_ubLevCur]-((DLC_ulPgBrd-DLC_ulPgSen+1)>>1)+ulDelayCmpPg;//#16023 advance landing	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
					}
				}
				//else if((DLC_btLU == 0)&&(DLC_btLUOld == 1))//leaving Calibration	// Mitong source
				else if(DLC_ubLevCur == DLC_ubLevSta)	// Mitong new �u�b�ҰʼӰ���@��
				{
					if((DLC_btLU == 0)&&(DLC_btLUOld == 1))//leaving Calibration	//���}����15mm,LU On��Off 
					{
						DLC_ulPgCnt = DLC_ulPgLev[DLC_ubLevCur] + ((DLC_ulPgBrd - DLC_ulPgSen + 1) >> 1) + ulDelayCmpPg;
					}
					else if((DLC_btLD == 0)&&(DLC_btLDOld == 1))//���}����185mm,LD On��Off // Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 add
					{
						DLC_ulPgCnt = DLC_ulPgLev[DLC_ubLevCur] + ((DLC_ulPgBrd + DLC_ulPgSen + 1) >> 1) + ulDelayCmpPg;
					}
				}
			}
			//DIR_DN LD position correction
			else if(DLC_ubDIR == DIR_DN)
			{
				if((DLC_btLD == 1)&&(DLC_btLDOld == 0))//1st landing Calibration //�i�J�����e185mm,LD Off��On
				{                 
                    // �NJames�[�������������v���즹�B,�U������eLD��Off��On�ɰ�����v // Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 --
                    //#16023 Rope compensation start
                    if(DLC_ubLevTar == DLC_ubLevCur){  //�i�J�����e185mm
                        DLC_ulPosRopeCmp = (ULONG)pr[ROPE_CMP] * 10 * (DLC_ulPosLev[pr[MAX_FLOOR]] - DLC_ulPosLev[DLC_ubLevTar]) / 
                                    (DLC_ulPosLev[pr[MAX_FLOOR]] - DLC_ulPosLev[DLC_ubLevMin]); // 0.1mm
                        DLC_ulPgRopeCmp = ((U32xU32divU32(DLC_ulPosRopeCmp, 65536, COF_ulPls2MMgain))<<2);  //�����������v��Pulse
                    }
                    else{
                        DLC_ulPgRopeCmp = 0;
                    }
                    // -------------------------------------------------------------------------------------------------------------
                    
					if((DLC_ulPosDD1 != 0)&&(DLC_btDD1 == 1) && (Driver_ID == IEDS_DRIVER))//#13761 position calibration on DDS1, James, 2020/03/03
					{
						/*   [Artemis Add Sensor819 Function/Special/2022/06/06]
                        Arttemis no required floor correction
                        so add Driver_ID == IEDS_DRIVER
                        */	
						DLC_ubLevCur = DLC_ubLevMin;					      	
					}
					//DLC_ulPgCnt = DLC_ulPgLev[DLC_ubLevCur]+(DLC_ulPgBrd>>1)+(DLC_ulPgSen>>1)-ulDelayCmpPg ;	 // Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
					DLC_ulPgCnt = DLC_ulPgLev[DLC_ubLevCur]+((DLC_ulPgBrd+DLC_ulPgSen+1)>>1)-ulDelayCmpPg + DLC_ulPgRopeCmp;	 // Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
				}
				else if((DLC_btLD == 1)&&(DLC_btLU == 1)&&(DLC_btLUOld == 0))//2nd landing Calibration, //�i�J�����e15mm,��LD On,LU Off��On
				{
					if(DLC_btPosLULDCal)	//04-36 Bit8==1
					{
						//DLC_ulPgCnt = DLC_ulPgLev[DLC_ubLevCur]+(DLC_ulPgBrd>>1)-(DLC_ulPgSen>>1)-ulDelayCmpPg ;//#16023 advance landing	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source						
						DLC_ulPgCnt = DLC_ulPgLev[DLC_ubLevCur]+((DLC_ulPgBrd-DLC_ulPgSen+1)>>1)-ulDelayCmpPg ;//#16023 advance landing	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
					}
				}
				//else if((DLC_btLD == 0)&&(DLC_btLDOld == 1))//leaving Calibration // Mitong source
				else if(DLC_ubLevCur == DLC_ubLevSta){	//�u�b�ҰʼӰ���@��// Mitong new
					if((DLC_btLD == 0)&&(DLC_btLDOld == 1))//leaving Calibration //���}����15mm,LD On��Off 
					{
						//DLC_ulPgCnt = DLC_ulPgLev[DLC_ubLevCur]-(DLC_ulPgBrd>>1)+(DLC_ulPgSen>>1)-ulDelayCmpPg ;
						DLC_ulPgCnt = DLC_ulPgLev[DLC_ubLevCur] - ((DLC_ulPgBrd - DLC_ulPgSen + 1) >> 1) - ulDelayCmpPg;
					}
					else if((DLC_btLU == 0)&&(DLC_btLUOld == 1))	//���}����185mm,LU On��Off // Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 add
					{
						DLC_ulPgCnt = DLC_ulPgLev[DLC_ubLevCur] - ((DLC_ulPgBrd + DLC_ulPgSen + 1) >> 1) - ulDelayCmpPg;
					}
				}
			}
	    }
	}
	
	// dec_sw pos protect, Henry, 2017/06/21
	// decel switch pos correction, �YDS_LEN��0,�����ե��\��
	if((DLC_btWelExc==0)&&(pr[DS_LEN]!=0)){
	    DLC_Decel_Protect();
	}
	
	//mod pulse to mm [
	if (DLC_ulPgCnt<=PGBS)
		DLC_ulPosVal = 0;	// for Artemis simulation platform
	else{
		//DLC_ulPosVal = U32xU32divU32((DLC_ulPgCnt>>2), COF_ulPls2MMgain, 65536);
		//DLC_ulPosVal = DLC_ulPosVal/10;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
		DLC_ulPosVal = (ULONG)(((UDOUBLE)DLC_ulPgCnt * (UDOUBLE)COF_ulPls2MMgain + 1310720) / 2621440); // Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
	}
	//]

	//�Ӽh�߽Ĭ���
    //if((DLC_btModIns==1)&&((DLC_btWelRec==1)||(DLC_btWelExc==1)))
    if((DLC_btWelRec==1)||(DLC_btWelExc==1))
	    WelTunProc();	//WelTun Proc
	
	//Wel-Tune��, ���Q�Φ���k��s�Ӽh
	if(DLC_btWelExc == 0){
		DLC_LevCur();
		pr[LEV_CUR] = DLC_ubLevCur;
	}
	
	// eps dir chg after GEN_OK, Henry, 20170621
	//if(DLC_btEPS && GEN_OK){
	if(DLC_btEPS && (GEN_OK || pr[EPS_OPTM]==0|| pr[EPS_OPTM]==4)){ //#13951, No function when  06-46=0 in DLC mode, James, 2020/03/20
		DLC_uwDCICnt = DLC_uwDCICnt<pr[DCISTA]*100?DLC_uwDCICnt+1:DLC_uwDCICnt;
	}
	else{
		DLC_uwDCICnt = 0;	
	}

	// Task 268638 �������a-�h�q�t�[��t��S���u Mitong 20220616 add ---------------------------------
	if((DLC_ubDec0SMode != MODE_NULL) && (DLC_ulCurSpd == 0)){
		if(DLC_ubDec0SModeTmr < 255){
			DLC_ubDec0SModeTmr++ ;
		}
		else{
			DLC_ubDec0SMode = MODE_NULL;
		}
	}
	else{
		DLC_ubDec0SModeTmr = 0;
	}
	//-------------------------------------------------------------------------------------
				
	//speed calculate	
	if(DLC_btErr == 1 || TUN_START == 1){   //  Jerry.sk.tsemg, James, 2021/11/09
		DLC_ubtra = 0x01;
		DLC_ubMode = MODE_NULL;
		DLC_ulCurSpd = 0;
	}
    else if(RUN_DCI_OK == 0){
		DLC_ubtra = 0x02;
		DLC_ubMode = MODE_NULL;

		if(DLC_ulCurSpd > 0)
			DLC_ulCurSpd --;
		else
			DLC_ulCurSpd = 0;
		/*
        //supt VF open loop can run INS mode Aevin 2018/07/16
        if((ZEROST || ZEROSP) && (pr[CTRLM] == VF) && DLC_btModIns){
            ZEROST = 0;
            ZEROSP = 0;
        }*/
        if((ZEROST || ZEROSP) && DLC_btModIns)
		{
			// #15266 Can't do Tuning without setting PG_TYPE, James, 20201201
			if((DLC_btWelExc == 1) && (pr[CTRLM]!=FOCPG && pr[CTRLM]!=FOCPM))
			{
				if(DLC_ulCurSpd==0)
				{
					if(Error==0)
					{
						Error = DLC_ERR; 
					}
				}
			}
			else if(pr[CTRLM] == VF)
			{
	            ZEROST = 0;
	            ZEROSP = 0;
			}
        
		}
    }
	// eps dir chg after GEN_OK, Henry, 20170621
	else if((DLC_btEPS)&&(DLC_uwDCICnt<pr[DCISTA]*100)){
		DLC_ubtra = 0x20;
		DLC_ubMode = MODE_NULL;
		DLC_ulCurSpd = 0;
	}
	else if(DLC_btModDec){
		DLC_ubtra = 0x1f;
		DLC_ubMode = MODE_NULL;

		if(DLC_btEPS){
			DLC_ulCurSpd = Spd_Linear(0, pr[ACCEL1], pr[DECEL1]);
			DLC_ubtra = 0x31;
		}
		else if(DLC_btModIns){
			if(DLC_btParkTooFar && (Driver_ID == IEDS_DRIVER)){	// Task 268638 �������a-�h�q�t�[��t��S���u Mitong 20220516 new ------------------------------------------------	
				//IEDS�A���h�ɷ|Ĳ�o������,�˭׼Ҧ�REV FWD off,�t���٤��S����F�s�t			
				//���氱����,�p�G�t�קC��0.02m/s,�h���[�t��0.02m/s��A�}�l��t
				if((DLC_ubDec0SMode == MODE_NULL) && (DLC_ulCurSpd < (pr[LEV_SPD]*100)) && (DLC_ulCurSpd > 0)){ // 0.0m/s < speed < pr[LEV_SPD]							
					DLC_ulCurSpd = Spd_Linear(pr[LEV_SPD]*10, 10, 100);	//speed pr[LEV_SPD]*10, acc 0.100m/s2, decel 1.00m/s2
					DLC_ubtra = 0x32;
				}
				else{
					//��t��0�t , S3���ms , Dec���mm/s^2 , S4������ms
					t_s3 = 1000;//���ms , t=a/j=((pr[JOGDEC]*10) / J(800mm/s^3)) * 1000=pr[JOGDEC] * 12.5 = 80 * 12.5 = 1000ms
					a_dec= 800;	//���mm/s^2
					t_s4 = 2000;//���ms , t=a/j=((pr[JOGDEC]*10) / J(400mm/s^3)) * 1000=pr[JOGDEC] * 25 = 80 * 25 = 2000ms 
					DLC_ulCurSpd = Spd_Dec0S(t_s3, a_dec, t_s4);	// Mitong 20220616
					DLC_ubtra = 0x33;
				}
			}	// -----------------------------------------------------------------------------------------------------------------------------------
			else{
				DLC_ulCurSpd = Spd_Linear(0, pr[JOGACC], pr[JOGDEC]);
				DLC_ubtra = 0x35;
			}		
		}
		else{
			DLC_ulCurSpd = Spd_FSD(pr[FSD], 100);
			DLC_ubtra = 0x36;
		}
	}
	else if((DLC_btADCO==0)&&(DLC_btEPS)){
		DLC_ubtra = 0x1c;
		DLC_ubMode = MODE_NULL;
		//[ADCO EPS Modify]
		ulTmp = ((ULONG)pr[Lift_SPD]*(ULONG)10*(ULONG)pr[FEPS])/(ULONG)pr[FMAX];
		uwTmp = ulTmp;
			
		// eps accel modi, Henry, 20170621
		//EPS speed curve modify, Henry, 2017/05/24
		//if((GEN_OK)&&((DLC_ubDIR==DIR_UP)||(DLC_ubDIR==DIR_DN))){		
		if((GEN_OK || pr[EPS_OPTM]==0|| pr[EPS_OPTM]==4)&&((DLC_ubDIR==DIR_UP)||(DLC_ubDIR==DIR_DN))){
            if(DLC_btLU && DLC_btLD)
            {
                DLC_ulCurSpd = Spd_Linear(pr[LEV_SPD]*10, pr[ACCEL1], pr[DECEL1]);
            }
            else if(DLC_btLU || DLC_btLD)
            {
                if((pr[LEV_SPD]*10)>=uwTmp)
                    DLC_ulCurSpd = Spd_Linear(uwTmp, pr[ACCEL1], pr[DECEL1]);
                else
                    DLC_ulCurSpd = Spd_Linear(pr[LEV_SPD]*10, pr[ACCEL1], pr[DECEL1]);
            }
            else
            {
                if((pr[RSQ_SPD]*10)>=uwTmp)
                    DLC_ulCurSpd = Spd_Linear(uwTmp, pr[ACCEL1], pr[DECEL1]);
                else
                    DLC_ulCurSpd = Spd_Linear(pr[RSQ_SPD]*10, pr[ACCEL1], pr[DECEL1]);
            }
        }
		else
			DLC_ulCurSpd = 0;
    }
	else if(DLC_btModFSD){
		DLC_ubtra = 0x04;
		DLC_ubMode = MODE_NULL;
		if(DLC_btParkTooFar && (Driver_ID == IEDS_DRIVER) && (DLC_ubDIR != DIR_NULL)){	// Task 268638 �������a-�h�q�t�[��t��S���u Mitong 20220616 new -------------		
			//���� IED-S �˭װ���	
			//��t��0�t , S3���ms , Dec���mm/s^2 , S4������ms		
			//��S3=0.000s(J3=�L���j) , Dec=pr[FSD] 
			a_dec = pr[FSD];	//���mm/s^2 
			t_s3 = 0;			//���ms	
			if(pr[FSD] < 1000){
				//S4=pr[FSD](J4=1m/s^3=1000mm/s^3) 
				t_s4 = pr[FSD];		//���ms,t=a/j=(a(pr[FSD] * 1) / j(1000mm/s^3)) * 1000=pr[FSD]
			}
			else if((pr[FSD] >= 1000) && (pr[FSD] < 2000)){
				//S4=pr[FSD](J4=2m/s^3=2000mm/s^3) 
				t_s4 = pr[FSD]>>1;		//���ms,t=a/j=(a(pr[FSD] * 1) / j(2000mm/s^3)) * 1000=pr[FSD]/2
			}
			else if((pr[FSD] >= 2000) && (pr[FSD] < 3000)){
				//S4=pr[FSD](J4=4m/s^3=4000mm/s^3) 
				t_s4 = pr[FSD]>>2;		//���ms,t=a/j=(a(pr[FSD] * 1) / j(4000mm/s^3)) * 1000=pr[FSD]/4
			}
			else{
				t_s4 = 0;
			}
			DLC_ulCurSpd = Spd_Dec0S(t_s3, a_dec, t_s4);	// Mitong 20220616
		}	// --------------------------------------------------------------------------------------------------------------------------------
		else{
			DLC_ulCurSpd = Spd_FSD(pr[FSD], 100);	// Task 268638 �������a-�h�q�t�[��t��S���u Mitong 20220516 source
		}
	}
	else if(DLC_btModZeo){
		DLC_ubtra = 0x05;
		DLC_ubMode = MODE_NULL;
		//DLC_ulCurSpd = 0;
		DLC_ulCurSpd = Spd_FSD(pr[FSD], 100);
	}
	else if(DLC_btModIns){
		DLC_ubtra = 0x06;
		DLC_ubMode = MODE_NULL;
//		DLC_ulCurSpd = Spd_Linear(pr[JOGF]*10, pr[JOGACC], pr[JOGDEC]);
		
		// Jingdo WelTun Decel, Henry
		if(DLC_btWelDec && DLC_btWelExc){
        	if((DLC_ubDIR==DIR_UP)&&(DLC_btUD1))
				DLC_ulCurSpd = Spd_Linear(pr[RSQ_SPD]*10, pr[JOGACC], pr[JOGDEC]);
        	else if((DLC_ubDIR==DIR_UP)&&(DLC_ubLevCur==1)&&((DLC_btLU == 1)||(DLC_btLD == 1)))
				DLC_ulCurSpd = Spd_Linear(pr[LEV_SPD]*10, pr[JOGACC], pr[JOGDEC]);
			else if((DLC_ubDIR==DIR_DN)&&(DLC_btDD1))
				DLC_ulCurSpd = Spd_Linear(pr[RSQ_SPD]*10, pr[JOGACC], pr[JOGDEC]);
			else
				DLC_ulCurSpd = Spd_Linear(pr[JOGF]*10, pr[JOGACC], pr[JOGDEC]);
		}
		else{
        	DLC_ulCurSpd = Spd_Linear(pr[JOGF]*10, pr[JOGACC], pr[JOGDEC]);
          }
	}
	else if(DLC_btModLev){ 
		DLC_ubtra = 0x07;
		DLC_ubMode = MODE_NULL;
		//Gfc DLC modify , Henry, 2018/05/23
		//DLC_ulCurSpd = Spd_Linear(pr[LEV_SPD]*10, pr[JOGACC], pr[JOGDEC]);
		if(DLC_btParkTooFar && (Driver_ID == IEDS_DRIVER)){
			DLC_ulCurSpd = Spd_Linear(pr[LEV_SPD]*10, 10, 100); //acc 0.10m/s2, decel 1.00m/s2	// Task 268638 �������a-�h�q�t�[��t��S���u Mitong 20220516 new
		}
		else{
			DLC_ulCurSpd = Spd_Linear(pr[LEV_SPD]*10, 20, 20); //decel 0.2m/s2	// Task 268638 �������a-�h�q�t�[��t��S���u Mitong 20220516 source
		}
	}
	else if(DLC_btModRsq){
		DLC_ubtra = 0x08;
		DLC_ubMode = MODE_NULL;
		//Gfc DLC modify , Henry, 2018/05/23
		//DLC_ulCurSpd = Spd_Linear(pr[RSQ_SPD]*10, pr[JOGACC], pr[JOGDEC]);
		if(DLC_btParkTooFar && (Driver_ID == IEDS_DRIVER)){
			DLC_ulCurSpd = Spd_Linear(pr[RSQ_SPD]*10, 10, 100);	 //acc 0.10m/s2, decel 1.00m/s2	// Task 268638 �������a-�h�q�t�[��t��S���u Mitong 20220516 new
		}
		else{
			DLC_ulCurSpd = Spd_Linear(pr[RSQ_SPD]*10, 20, 20);	// Task 268638 �������a-�h�q�t�[��t��S���u Mitong 20220516 source
		}
	}
	//MI Control Speed Mode
	else if(DLC_btCANOff){
		DLC_ubMode = MODE_NULL;
		
		if((DLC_ubDIR == DIR_UP) || (DLC_ubDIR == DIR_DN)){
			if(DLC_btSpdL == 1){
				DLC_ubtra = 0x09;
				DLC_ulCurSpd = Spd_Linear(pr[LEV_SPD]*10, pr[JOGACC], pr[JOGDEC]);
			}
			else{
				DLC_ubtra = 0x0a;
				DLC_ulCurSpd = Spd_Linear(pr[RSQ_SPD]*10, pr[JOGACC], pr[JOGDEC]);
			}
		}
		else{
			DLC_ubtra = 0x0b;
			DLC_ulCurSpd = 0;
		}	
	}
	// auto-releveling mode
	else if((DLC_btModAutoLev == 1)&&(DLC_btADCO == 0)){
		DLC_ubMode = MODE_NULL;
        
        //------------------------------------------------------------------------------------------
        //adjust floor ---Aevin 7/2/2018
        //------------------------------------------------------------------------------------------
        if(DLC_ubLevTar != 0){
            

            if(DLC_ubDIR == DIR_UP && DLC_ulPosVal <= uladjstVal){
                
                if(DLC_ubLevTar<=50)
                    uwadjstVal = (UWORD)(DLC_ulPosLev[DLC_ubLevTar]) + (DLCxx[DLC_LimADDR + DLC_ubLevTar - 1]);
                else
                    uwadjstVal = (UWORD)(DLC_ulPosLev[DLC_ubLevTar]) + (DLCxx[DLC_Adj50ADDRDN + DLC_ubLevTar - 50 - 1]);
                uladjstVal = (DLC_ulPosLev[DLC_ubLevTar] & 0xffff0000) | ((ULONG)uwadjstVal & 0x0000ffff);

    			if(DLC_ulPosVal >= uladjstVal)
    				ulDisTar = DLC_ulPosVal - uladjstVal;
    			else
    				ulDisTar = uladjstVal - DLC_ulPosVal;
                                
    			if(DLC_ubLevCur != DLC_ubLevTar){
    				DLC_ubtra = 0x0c;
    				DLC_ulCurSpd = Spd_Linear(pr[RSQ_SPD]*10, pr[JOGACC], pr[JOGDEC]);
    			}
    			else if(DLC_ubLevCur == DLC_ubLevTar)
    			{
    				if(ulDisTar <= 3){
    					DLC_ubtra = 0x0e;
    					DLC_ulCurSpd = 0;
    				}
    				else if((DLC_btDznMd == 1 && DLC_btDZN == 1)||      // adco
    					      (DLC_btDznMd == 0 && DLC_btLU && DLC_btLD == 1)){
    					DLC_ubtra = 0x0f;
    					DLC_ulCurSpd = Spd_Linear(pr[LEV_SPD]*10, pr[JOGACC], pr[JOGDEC]);
    				}
    				else{
    					DLC_ubtra = 0x10;
    					DLC_ulCurSpd = Spd_Linear(pr[RSQ_SPD]*10, pr[JOGACC], pr[JOGDEC]);
    				}
    			}
    			else{
    				DLC_ubtra = 0x11;
    				DLC_ulCurSpd = 0;
    			}
    		}
            else if(DLC_ubDIR == DIR_DN && DLC_ulPosVal >= uladjstVal){
                
                if(DLC_ubLevTar<=50)
                    uwadjstVal = (UWORD)(DLC_ulPosLev[DLC_ubLevTar]) + (DLCxx[DLC_Adj50ADDRUP + DLC_ubLevTar - 1]);
                else
                    uwadjstVal = (UWORD)(DLC_ulPosLev[DLC_ubLevTar]) + (DLCxx[DLC_Adj50ADDRDN + DLC_ubLevTar - 50 +25 - 1]);
                uladjstVal = (DLC_ulPosLev[DLC_ubLevTar] & 0xffff0000) | ((ULONG)uwadjstVal & 0x0000ffff);

    			if(DLC_ulPosVal >= uladjstVal)
    				ulDisTar = DLC_ulPosVal - uladjstVal;
    			else
    				ulDisTar = uladjstVal - DLC_ulPosVal;
                                
    			if(DLC_ubLevCur != DLC_ubLevTar){
    				DLC_ubtra = 0x0c;
    				DLC_ulCurSpd = Spd_Linear(pr[RSQ_SPD]*10, pr[JOGACC], pr[JOGDEC]);
    			}
    			else if(DLC_ubLevCur == DLC_ubLevTar)
    			{
    				if(ulDisTar <= 3){
    					DLC_ubtra = 0x0e;
    					DLC_ulCurSpd = 0;
    				}
    				else if((DLC_btDznMd == 1 && DLC_btDZN == 1)||      // adco
    					      (DLC_btDznMd == 0 && DLC_btLU && DLC_btLD == 1)){
    					DLC_ubtra = 0x0f;
    					DLC_ulCurSpd = Spd_Linear(pr[LEV_SPD]*10, pr[JOGACC], pr[JOGDEC]);
    				}
    				else{
    					DLC_ubtra = 0x10;
    					DLC_ulCurSpd = Spd_Linear(pr[RSQ_SPD]*10, pr[JOGACC], pr[JOGDEC]);
    				}
    			}
    			else{
    				DLC_ubtra = 0x11;
    				DLC_ulCurSpd = 0;
    			}
            }
    		else{
    			DLC_ubtra = 0x12;
    			DLC_ulCurSpd = 0;
    		}
        }    		
        else{
			DLC_ubtra = 0x12;
			DLC_ulCurSpd = 0;
		}
	}	
	//ADCO auto-releveling mode
    //[ADCO EPS Modify]
	else if((DLC_btEPS || DLC_btModAutoLev) && (DLC_btADCO == 1)){			
		DLC_ubMode = MODE_NULL;
		
		if((DLC_btWelDone == 1) && (DLC_btAutoFlag == 0)){
			DLC_btAutoFlag = 1;
			
			if(DLC_ubLevCur <= DLC_ubLevMin)
				DLC_uwAutoTar = DLC_ubLevMin;
			else if(DLC_ulPosVal <= DLC_ulPosLev[DLC_ubLevCur])
				DLC_uwAutoTar = (DLC_ubLevCur>1)?(DLC_ubLevCur-1):DLC_ubLevCur;
			else if(DLC_ulPosVal >= DLC_ulPosLev[DLC_ubLevCur])
				DLC_uwAutoTar = DLC_ubLevCur;
			else
				DLC_uwAutoTar = 0;		
		}
		
		DLC_ubLevTar = DLC_uwAutoTar;
		
		if(((DLC_ubDIR == DIR_DN) && (DLC_ulPosVal >= DLC_ulPosLev[DLC_ubLevTar])) && 
			 (DLC_ubLevTar != 0)){
			if(DLC_ulPosVal >= DLC_ulPosLev[DLC_ubLevTar])
				ulDisTar = DLC_ulPosVal - DLC_ulPosLev[DLC_ubLevTar];
			else
				ulDisTar = DLC_ulPosLev[DLC_ubLevTar] - DLC_ulPosVal;
							
			if(DLC_ubLevCur != DLC_ubLevTar){
				DLC_ubtra = 0x13;
				if(DLC_btEPS){
					ulTmp = ((ULONG)pr[Lift_SPD]*(ULONG)100*(ULONG)pr[FEPS])/(ULONG)pr[FMAX];
					DLC_ulCurSpd = ulTmp;
				}
				else
					DLC_ulCurSpd = Spd_Linear(pr[RSQ_SPD]*10, pr[JOGACC], pr[JOGDEC]);
			}
			else if(DLC_ubLevCur == DLC_ubLevTar){
				
				if((DLC_btDznMd == 1 && DLC_btDZN == 1)||      // adco
	 	       (DLC_btDznMd == 0 && DLC_btLU && DLC_btLD == 1)){
					DLC_ubtra = 0x14;
					DLC_ulCurSpd = Spd_Linear(0, pr[JOGACC], pr[JOGDEC]); // adco
				}
				else if((DLC_btDznMd == 0)&&(DLC_btLU == 1 || DLC_btLD == 1)){ // adco
					DLC_ubtra = 0x15;
					DLC_ulCurSpd = Spd_Linear(pr[LEV_SPD]*10, pr[JOGACC], pr[JOGDEC]);
				}
				else{
					DLC_ubtra = 0x16;
					if(DLC_btEPS){
						ulTmp = ((ULONG)pr[Lift_SPD]*(ULONG)100*(ULONG)pr[FEPS])/(ULONG)pr[FMAX];
						DLC_ulCurSpd = ulTmp;
					}
					else
						DLC_ulCurSpd = Spd_Linear(pr[RSQ_SPD]*10, pr[JOGACC], pr[JOGDEC]);
				}
			}
			else{
				DLC_ubtra = 0x17;
				DLC_ulCurSpd = 0;
			}
		}
		else{
			DLC_ubtra = 0x18;
			DLC_ulCurSpd = 0;
		}
	}
	else if(DLC_btModHome == 1){
		DLC_ubtra = 0x19;
		DLC_ubMode = MODE_NULL;
		DLC_ulCurSpd = Spd_Linear(pr[AH_SPD]*10, pr[JOGACC], pr[JOGDEC]);
	}
	//normal
	else if(DLC_btModNor == 1){
		DLC_ubtra = 0x1a;
		ulTmp = Spd_NOR(DLC_ulCurSpd);
		ulTmp = DLC_Decel_Protect_SpdLim(ulTmp);//Artemis speed limit, James, 20200220
		if(ulTmp == 0x00FF)
			ulTmp = DLC_ulCurSpd;
		DLC_ulCurSpd = ulTmp;
		DLC_LULD_Protect(DLC_btLU, DLC_btLUOld, DLC_btLD, DLC_btLDOld);
	}
	else	//protection
	{
		DLC_ulCurSpd = 0;
		DLC_ubtra = 0x1b;
		DLC_ubMode = MODE_NULL;
		
		if(DLC_ulCurSpd == 0)
			RUN_DCI_OK = 0;
	}
	
	
	if(DLC_btModAutoLev == 0){
		DLC_btAutoFlag = 0;
		DLC_uwAutoTar = 0;
	}

   if(pr[Sensor819] != 0)
   {
       Sensor817_Protect();    //[Artemis Add Sensor819 Function/Special/2022/06/06]
       Sensor818_Protect();    //[Artemis Add Sensor819 Function/Special/2022/06/06]
   }


	

	//�i���a�Ӽh DLC_ubLevTar
	ubTmp = DLC_ubLevOk;
	if(DLC_btModNor == 1){
		if(DLC_ulCurSpd == 0 && fcmd.uw.hi == 0 && DLC_ubDIR == DIR_NULL){
			DLC_ubLevOk = DLC_ubLevCur;
			DLC_uwTra4 = 0x01;
		}
		else if(DLC_ubDIR == DIR_UP){
			if(DLC_ubMode == MODE_NULL || DLC_ubMode == MODE_S1 || 
				 DLC_ubMode == MODE_ACC || DLC_ubMode == MODE_S2 || DLC_ubMode == MODE_CON){
				for(i = DLC_ubLevCur+1; i <= DLC_ubLevMax; i++){
				    //----------------------------------------------------------------------------
				    //Adjust floor Aevin 7/2/2018
				    if(i<=50)
                        uwadjstVal = (UWORD)(DLC_ulPosLev[i]) + (DLCxx[DLC_LimADDR + i - 1]);
                    else
                        uwadjstVal = (UWORD)(DLC_ulPosLev[i]) + (DLCxx[DLC_Adj50ADDRDN + i - 50 - 1]);
                    uladjstVal = (DLC_ulPosLev[i] & 0xffff0000) | ((ULONG)uwadjstVal & 0x0000ffff);
                    //------------------------------------------------------------------------------
                    
					if(uladjstVal > DLC_ulPosVal)//Adjust floor Aevin 7/2/2018
					{
						ulDisTar = uladjstVal - DLC_ulPosVal;//Adjust floor Aevin 7/2/2018
						if(ulDisTar >= DLC_ulDStop)
						{
							DLC_ubLevOk = i;
							i = DLC_ubLevMax+1; //ready for break
						}
					}
					if(i >= DLC_ubLevMax+1)
						break;
				}


				if(DLC_ubLevOk > DLC_ubLevTar)  //protect : lev_ok > lev_tar, should lev_ok = lev_tar
					DLC_ubLevOk = DLC_ubLevTar;
				else if(DLC_ubLevOk < ubTmp)    //make sure lev_ok increase
					DLC_ubLevOk = ubTmp;					
				DLC_uwTra4 = 0x02;
			}
			else{
				if(DLC_ubLevTar != 0)
					DLC_ubLevOk = DLC_ubLevTar;
				DLC_uwTra4 = 0x03;
			}			
		}	
		else if(DLC_ubDIR == DIR_DN){
			if(DLC_ubMode == MODE_NULL || DLC_ubMode == MODE_S1 || 
				 DLC_ubMode == MODE_ACC || DLC_ubMode == MODE_S2 || DLC_ubMode == MODE_CON){
				// 2F to 1F tar lev cal error, v0.03
				for(i = DLC_ubLevCur-1; i >= DLC_ubLevMin; i--){
                    //----------------------------------------------------------------------------
				    //Adjust floor Aevin 7/2/2018
				    if(i<=50)
                        uwadjstVal = (UWORD)(DLC_ulPosLev[i]) + (DLCxx[DLC_Adj50ADDRUP + i - 1]);
                    else
                        uwadjstVal = (UWORD)(DLC_ulPosLev[i]) + (DLCxx[DLC_Adj50ADDRDN + i - 25 - 1]);
                    uladjstVal = (DLC_ulPosLev[i] & 0xffff0000) | ((ULONG)uwadjstVal & 0x0000ffff);
                    //------------------------------------------------------------------------------
                    if(DLC_ulPosVal > uladjstVal){//Adjust floor Aevin 7/2/2018
						ulDisTar = DLC_ulPosVal-uladjstVal;//Adjust floor Aevin 7/2/2018
						if(ulDisTar >= DLC_ulDStop){
							DLC_ubLevOk = i;
							i = 0;              //ready for break
						}
					}
					if(i == 0)
						break;
				}

				if((DLC_ubLevOk < DLC_ubLevTar) && (DLC_ubLevTar != 0))  //protect : lev_ok < lev_tar, should lev_ok = lev_tar
					DLC_ubLevOk = DLC_ubLevTar;
				else if(DLC_ubLevOk > ubTmp)    //make sure lev_ok decrease
					DLC_ubLevOk = ubTmp;
					
				DLC_uwTra4 = 0x04;				
			}
			else{
				DLC_ubLevOk = DLC_ubLevTar;
				DLC_uwTra4 = 0x05;
			}				
		}
		else{
			DLC_ubLevOk = DLC_ubLevCur;
			DLC_uwTra4 = 0x06;
		}
	}		
	else{
		DLC_ubLevOk = DLC_ubLevCur;
		DLC_uwTra4 = 0x07;
	}

	if((DLC_ubMode == MODE_S1) || (DLC_ubMode == MODE_ACC))
		DLC_btReCalFlag = 1;
	else
		DLC_btReCalFlag = 0;
		
	//Para upgrade
	DLC_PrMgr(PR_WR);

    DLC_btLUOld = DLC_btLU;
    DLC_btLDOld = DLC_btLD;
    DLC_btDZNOld = DLC_btDZN;  // adco
  
    DLC_btDD1Old = DLC_btDD1;
    DLC_btDD2Old = DLC_btDD2;
    DLC_btDD3Old = DLC_btDD3;
    DLC_btDD4Old = DLC_btDD4;
    DLC_btUD1Old = DLC_btUD1;
    DLC_btUD2Old = DLC_btUD2;
    DLC_btUD3Old = DLC_btUD3;
    DLC_btUD4Old = DLC_btUD4;

	//speed trace reg
	DLC_uwTra3 = DLC_ubMode;
	DLC_uwSpdTra = DLC_ulCurSpd/10;
	
	//------------------------------//
	//direciotn & speed command to driver
	//ubDILow = (DLC_uwDI.ub.low >> 1);
	ax = 0;
	ax = (DLC_ubDIR==DIR_UP)?(ax|0x01):(ax&~0x01);
	ax = (DLC_ubDIR==DIR_DN)?(ax|0x02):(ax&~0x02);
	PDO_sub0(ax);
 	MFI_REMOTE = 0;
#if 1//#15436, James. 2020/12/25
	//ud1 = (UDOUBLE)DLC_ulCurSpd*(UDOUBLE)pr[FMAX]/(UDOUBLE)pr[Lift_SPD];
	//ulspeed = ud1/100;
    // ---------------------------------------------------------------------
    // Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new �|�ˤ��J ------
    ud1 = (UDOUBLE)DLC_ulCurSpd*(UDOUBLE)pr[FMAX];
    ud2 = (UDOUBLE)pr[Lift_SPD] * 100;
    ulspeed = (ud1 + (ud2>>1)) / ud2;  // Mitong �|�ˤ��J
    // --------------------------------------------------------------------
	
#else	
	ud1 = (UDOUBLE)DLC_ulCurSpd*(UDOUBLE)0xffff*(UDOUBLE)pr[FMAX];
	ud2 = (UDOUBLE)pr[Lift_SPD]*(UDOUBLE)100*(UDOUBLE)pr[MFBASE1];
	
	ud1 = ud1 << 8;
	ud3 = ud1/ud2;
	ud3 = ud3 >> 8;
	
	if(ud3 >= 0xFFFFFFFF)
	{
		ulspeed = 0xFFFFFFFF;
	}
	else
	{
		ulspeed = ud3;
	}

 	//uwspeed 0-65535�N��0-fase(�B�w�W�v)
    ulspeed = U32xU32divU32(ulspeed,fbase,0xffff);
#endif	
	if(ulspeed >= 65535)
	{
		ulspeed = 65535;
	}
	else
	{
		ulspeed = ulspeed;
	}
	PCRemote2001H((UWORD)ulspeed); 
}

void DLC_Decel_Protect(void){
	ULONG ulTmp;

	if(DLC_ubDIR == DIR_UP){
			
		if((DLC_ulPosUD1 != 0)&&(DLC_btUD1Old == 0)&&(DLC_btUD1 == 1)){
		
			if(DLC_ulPosVal >= DLC_ulPosUD1)
				ulTmp = DLC_ulPosVal - DLC_ulPosUD1;
			else
				ulTmp = DLC_ulPosUD1 - DLC_ulPosVal;
			
			if(ulTmp >= pr[DS_LEN])
				DLC_ulPgCnt = DLC_ulPgUD1;
		}
		else if((DLC_ulPosUD2 != 0)&&(DLC_btUD2Old == 0)&&(DLC_btUD2 == 1)){
		
			if(DLC_ulPosVal >= DLC_ulPosUD2)
				ulTmp = DLC_ulPosVal - DLC_ulPosUD2;
			else
				ulTmp = DLC_ulPosUD2 - DLC_ulPosVal;
			
			if(ulTmp >= pr[DS_LEN])
				DLC_ulPgCnt = DLC_ulPgUD2;
		}
		else if((DLC_ulPosUD3 != 0)&&(DLC_btUD3Old == 0)&&(DLC_btUD3 == 1)){
		
			if(DLC_ulPosVal >= DLC_ulPosUD3)
				ulTmp = DLC_ulPosVal - DLC_ulPosUD3;
			else
				ulTmp = DLC_ulPosUD3 - DLC_ulPosVal;
			
			if(ulTmp >= pr[DS_LEN])
				DLC_ulPgCnt = DLC_ulPgUD3;
		}
		else if((DLC_ulPosUD4 != 0)&&(DLC_btUD4Old == 0)&&(DLC_btUD4 == 1)){
		
			if(DLC_ulPosVal >= DLC_ulPosUD4)
				ulTmp = DLC_ulPosVal - DLC_ulPosUD4;
			else
				ulTmp = DLC_ulPosUD4 - DLC_ulPosVal;
			
			if(ulTmp >= pr[DS_LEN])
				DLC_ulPgCnt = DLC_ulPgUD4;
		}
	}
		
	if(DLC_ubDIR == DIR_DN){
		 	
		if((DLC_ulPosDD1 != 0)&&(DLC_btDD1Old == 0)&& (DLC_btDD1 == 1)){
			if(DLC_ulPosVal >= DLC_ulPosDD1)
				ulTmp = DLC_ulPosVal - DLC_ulPosDD1;
			else
				ulTmp = DLC_ulPosDD1 - DLC_ulPosVal;
			
			if(ulTmp >= pr[DS_LEN])
				DLC_ulPgCnt = DLC_ulPgDD1;
		}
		else if((DLC_ulPosDD2 != 0)&&(DLC_btDD2Old == 0)&& (DLC_btDD2 == 1)){
			if(DLC_ulPosVal >= DLC_ulPosDD2)
				ulTmp = DLC_ulPosVal - DLC_ulPosDD2;
			else
				ulTmp = DLC_ulPosDD2 - DLC_ulPosVal;
			
			if(ulTmp >= pr[DS_LEN])
				DLC_ulPgCnt = DLC_ulPgDD2;
		}
		else if((DLC_ulPosDD3 != 0)&&(DLC_btDD3Old == 0)&& (DLC_btDD3 == 1)){
			if(DLC_ulPosVal >= DLC_ulPosDD3)
				ulTmp = DLC_ulPosVal - DLC_ulPosDD3;
			else
				ulTmp = DLC_ulPosDD3 - DLC_ulPosVal;
			
			if(ulTmp >= pr[DS_LEN])
				DLC_ulPgCnt = DLC_ulPgDD3;
		}
		else if((DLC_ulPosDD4 != 0)&&(DLC_btDD4Old == 0)&& (DLC_btDD4 == 1)){
			if(DLC_ulPosVal >= DLC_ulPosDD4)
				ulTmp = DLC_ulPosVal - DLC_ulPosDD4;
			else
				ulTmp = DLC_ulPosDD4 - DLC_ulPosVal;
			
			if(ulTmp >= pr[DS_LEN])
				DLC_ulPgCnt = DLC_ulPgDD4;
		}
	}	
}

ULONG DLC_Decel_Protect_SpdLim(ULONG ulCurSpd){ //Artemis speed limit, James, 20200220
	ULONG ulCurSpd_Tmp;
	UWORD uwCurSpd, uwSpdLim;
	UBYTE ubSpdCheckFlag;
	UDOUBLE ud1;
	
	uwCurSpd = ulCurSpd/10;//ulCurSpd(m/s, dot4)
	//uwSpdLim = 100*pr[Lift_SPD];//pr[Lift_SPD](m/s, dot2)
	
	//when UDS/DDS is trigged: 1.update Speed limit. 2.Enable Speed Check Flag 	
	if(DLC_ubDIR == DIR_UP){
			
		if((DLC_ulPosUD1 != 0)&&(DLC_btUD1 == 1) && (pr[DD1_Vlim] != 0)){			
			DLC_uwSpdLim = pr[DD1_Vlim]*10;
			ubSpdCheckFlag = 0x01;
		}
		else if((DLC_ulPosUD2 != 0)&&(DLC_btUD2 == 1) && (pr[DD2_Vlim] != 0)){
			DLC_uwSpdLim = pr[DD2_Vlim]*10;
			ubSpdCheckFlag = 0x02;
		}
		else if((DLC_ulPosUD3 != 0)&&(DLC_btUD3 == 1) && (pr[DD3_Vlim] != 0)){
			DLC_uwSpdLim = pr[DD3_Vlim]*10;
			ubSpdCheckFlag = 0x03;
		}
		else if((DLC_ulPosUD4 != 0)&&(DLC_btUD4 == 1) && (pr[DD4_Vlim] != 0)){
			DLC_uwSpdLim = pr[DD4_Vlim]*10;
			ubSpdCheckFlag = 0x04;
		}
		else{
			DLC_uwSpdLim = DLC_uwRateSpdMax;
			ubSpdCheckFlag = 0x00;
		}
	}
		
	if(DLC_ubDIR == DIR_DN){
		 	
		if((DLC_ulPosDD1 != 0)&& (DLC_btDD1 == 1) && (pr[DD1_Vlim] != 0)){
			DLC_uwSpdLim = pr[DD1_Vlim]*10;
			ubSpdCheckFlag = 0x05;
		}
		else if((DLC_ulPosDD2 != 0)&& (DLC_btDD2 == 1) && (pr[DD2_Vlim] != 0)){
			DLC_uwSpdLim = pr[DD2_Vlim]*10;
			ubSpdCheckFlag = 0x06;
		}
		else if((DLC_ulPosDD3 != 0)&& (DLC_btDD3 == 1) && (pr[DD3_Vlim] != 0)){
			DLC_uwSpdLim = pr[DD3_Vlim]*10;
			ubSpdCheckFlag = 0x07;
		}
		else if((DLC_ulPosDD4 != 0)&& (DLC_btDD4 == 1) && (pr[DD4_Vlim] != 0)){
			DLC_uwSpdLim = pr[DD4_Vlim]*10;
			ubSpdCheckFlag = 0x08;
		}
		else{
			DLC_uwSpdLim = DLC_uwRateSpdMax;
			ubSpdCheckFlag = 0x00;
		}
	}	

	//Check if Speed is over limit
	if((ubSpdCheckFlag != 0x00) && (uwCurSpd > DLC_uwSpdLim)){//over speed trigger
		DLC_ubSpdLimFlag = ubSpdCheckFlag;
		if(WarnCode==0){
			WarnDisplaySave();
			switch(DLC_ubSpdLimFlag){
	    	    case 0x01:
					WarnCode = UD1_Vlim_WARN;
					break;
				case 0x05:
					WarnCode = DD1_Vlim_WARN; 
					break;			
	    	    case 0x02:
					WarnCode = UD2_Vlim_WARN;
					break;
				case 0x06:
					WarnCode = DD2_Vlim_WARN; 
					break;
				case 0x03:
					WarnCode = UD3_Vlim_WARN;
					break;
				case 0x07:
					WarnCode = DD3_Vlim_WARN; 
					break;			
	    	    case 0x04:
					WarnCode = UD4_Vlim_WARN;
					break;
				case 0x08:
					WarnCode = DD4_Vlim_WARN; 
					break;    
			}
		}
	}
	
	if((uwCurSpd==0)||(DLC_ubDIR==DIR_NULL)||(DLC_ubSpdLimMode==0)){//over speed reset
		DLC_ubSpdLimFlag = 0;
		if((WarnCode >= UD1_Vlim_WARN)||(WarnCode <= DD4_Vlim_WARN)){	
			WarnCode = 0;
			Keypad_Page = pr[S_DISP];
			Keypad_PageTmp = 0;
		}			
	}
	
	//limit the speed 
	if((DLC_ubSpdLimFlag != 0x00)&&(DLC_ubSpdLimMode!=0)){
		if(DLC_ubSpdLimMode==1)
		{
			if((ubSpdCheckFlag == 0x01) || (ubSpdCheckFlag == 0x05))//FSD in xDS1			
			{
				uwtest4 = 11;
				ulCurSpd_Tmp = Spd_FSD(pr[DECEL1]*10*1.4, 100);
			}			
			else if(DLC_ubMode <= MODE_CON)//Speed limit in Acc, James, 20201208
			{
				uwtest4 = 12;
				ulCurSpd_Tmp = Spd_Linear(DLC_uwSpdLim, pr[ACCEL1]*1.4, pr[DECEL1]*1.4);
			}
			else
			{
				uwtest4 = 13;
				ulCurSpd_Tmp = Spd_FSD(pr[DECEL1]*10*1.4, 100);
			}
		}
		else //if(DLC_ubSpdLimMode==2)
		{
			if((DLC_ubSpdLimFlag == 0x01) || (DLC_ubSpdLimFlag == 0x05))//when trigger is UDS1/DDS1
			{
				if(DLC_btLU && DLC_btLD){						
					uwtest4 = 25;
					ulCurSpd_Tmp = Spd_FSD(pr[DECEL1]*10, 100);
				}/*
				else if(DLC_btLU || DLC_btLD){
					uwtest4 = 5;
					ulCurSpd_Tmp = Spd_Linear(pr[LEV_SPD]*10, pr[JOGACC]*10, pr[JOGDEC]*10);
				}*/
				else{
					uwtest4 = 24;
					ulCurSpd_Tmp = Spd_Linear(pr[LEV_SPD]*10, pr[ACCEL1]*1.4, pr[DECEL1]*1.4);
				}
			}
			else if(DLC_ubMode <= MODE_CON)//Speed limit in Acc, James, 20201208
			{
				uwtest4 = 26;
				ulCurSpd_Tmp = Spd_Linear(DLC_uwSpdLim, pr[ACCEL1]*1.4, pr[DECEL1]*1.4);
			}
			else//when trigger is UDS2/DDS2, UDS3/DDS3, UDS4/DDS4, 
			{
				if((DLC_btLU && DLC_btLD)&&((ubSpdCheckFlag == 0x01) || (ubSpdCheckFlag == 0x05))){						
					uwtest4 = 23;
					ulCurSpd_Tmp = Spd_FSD(pr[DECEL1]*10, 100);
				}
				else if((DLC_btLU || DLC_btLD)&&((ubSpdCheckFlag == 0x01) || (ubSpdCheckFlag == 0x05))){
					uwtest4 = 22;
					ulCurSpd_Tmp = Spd_Linear(pr[LEV_SPD]*10, pr[JOGACC], pr[JOGDEC]);
				}
				else{
					uwtest4 = 21;
					ulCurSpd_Tmp = Spd_Linear(pr[RSQ_SPD]*10, pr[ACCEL1]*1.4, pr[DECEL1]*1.4);
				}
			}
		}
	}
	else{
		uwtest4 = 0;
		ulCurSpd_Tmp = ulCurSpd;
	}
	
	return ulCurSpd_Tmp;
}

UBYTE DLC_LULD_Protect(Bool LU, Bool LUOld, Bool LD, Bool LDOld)//#15977, LULD detect, James, 2021/04/01
{
	if(DLC_ubLuLdProtectState == LULD_Fault)
	{
		DLC_uwLuLdTimer = 0;
		if(DLC_ubLuLdError != LULD_OK)
		{
			if(pr[LS_Method]==2)
			{
				DLC_ubLuLdProtectState = LULD_Fault;
                DLC_ubLuLdError = 0;
			}
            else if((pr[LS_Method]==0) || (DLC_ubLuLdError == LDok_LU_SHORT) ||(DLC_ubLuLdError == LUok_LD_SHORT))
            {
                if(DLC_ulDisTar.ul< ((DLC_ulPgBrd - DLC_ulPgSen)>>1))
                {
                    DLC_uwLuLdResetTimer++;
                }
                if(DLC_uwLuLdResetTimer > 2000U)//reset after 2sec
                {   
                    DLC_uwLuLdResetTimer = 0;
                    DLC_ubLuLdError = 0;
                }
				WarnDisplaySave();
                if(WarnCode == 0)
                {
				    WarnCode = LULD_WARN;
                }
			}
			else if(pr[LS_Method]==1)
			{
				WGOFF;                
                DLC_uwLuLdResetTimer++;
				if((DLC_ubLuLdError == LULD_SHORT) || (DLC_ubLuLdError == LU_SHORT) ||(DLC_ubLuLdError == LD_SHORT))
				{
					if(Error == 0)
					{
						Error = LULD_SHORT_ERR;
					}
				}
				else if(DLC_ubLuLdError == LULD_OPEN)
				{
					if(Error == 0)						
					{
						Error = LULD_OPEN_ERR;
					}
				}
				else
				{;}
				WGOFF;
				LIFT_ENABLE = 0;					
				CMDFREE = 1;
                DLC_ubLuLdError = 0;
			}
			/*
			//short reset
			if(((DLC_ubLuLdError == LULD_SHORT) && (LD == 0)&&(LU == 0)) || 
				 ((DLC_ubLuLdError == LU_SHORT) && (LU == 0)) ||
				 ((DLC_ubLuLdError == LD_SHORT) && (LD == 0)))
			{
				if(WarnCode == LULD_WARN)
				{
					WarnCode = 0;
				}
				if(Error == LULD_SHORT_ERR)
				{
					Error = 0;
				}
				DLC_ubLuLdProtectState = LULD_STANDBY;
			}
			else 
			{
				DLC_ubLuLdProtectState = LULD_Fault;
			}
			//open reset
			if(((DLC_ubLuLdError == LULD_OPEN) && (LD == 1)&&(LU == 1)) || 
				 ((DLC_ubLuLdError == LU_OPEN) && (LU == 1)) ||
				 ((DLC_ubLuLdError == LD_OPEN) && (LD == 1)))
			{
				if(WarnCode == LULD_WARN)
				{
					WarnCode = 0;
				}
				if(Error == LULD_OPEN_ERR)
				{
					Error = 0;
				}
				DLC_ubLuLdProtectState = LULD_STANDBY;
			}
			else 
			{
				DLC_ubLuLdProtectState = LULD_Fault;
			}*/
		}
		else
		{
			DLC_ubLuLdProtectState = LULD_STANDBY;
		}
		
	}
	else if(DLC_ubLuLdProtectState == LULD_STANDBY)
	{
		DLC_ubLuLdError = LULD_OK;
		if(DLC_ubMode > MODE_NULL && DLC_ubMode < MODE_CON)
		{
			if(DLC_btUP)
			{
				DLC_ubLuLdProtectState = LULD_UP_JUDGE;
			}
			else if(DLC_btDN)
			{
				DLC_ubLuLdProtectState = LULD_DN_JUDGE;
			}
			else
			{
				DLC_ubLuLdProtectState = LULD_STANDBY;
			}

		}
		else
		{
			DLC_ubLuLdProtectState = LULD_STANDBY;
		}
	}
	else if(DLC_ubLuLdProtectState == LULD_DN_JUDGE)
	{
		if((LD == 1)&&(LU == 0)&&(LUOld == 1))
		{
			DLC_ubLuLdError = LD_SHORT;//logic 1
			DLC_ubLuLdProtectState = LULD_Fault;
		}
		else if((LU == 1)&&(LD == 0)&&(LDOld == 1))
		{
			DLC_uwLuLdTimer = 0;
			DLC_ubLuLdProtectState = LULD_DN_LDok;
		}
		else
		{
			DLC_ubLuLdProtectState = LULD_DN_JUDGE;
		}
	}
	else if(DLC_ubLuLdProtectState == LULD_DN_LDok)
	{
		DLC_uwLuLdTimer++;
		if(DLC_uwLuLdTimer < pr[LS_SHORT_TIME]*100U)//02-42(dot1)->dot3
		{
			if((LU == 0)&&(LUOld == 1))
			{
				DLC_ubLuLdError = LULD_OK;
				DLC_ubLuLdProtectState = LULD_OK_RUN;
			}
			else
			{
				DLC_ubLuLdProtectState = LULD_DN_LDok;
			}
		}
		else
		{
			DLC_ubLuLdError = LDok_LU_SHORT;//logic 4
			DLC_ubLuLdProtectState = LULD_Fault;
		}
	}
	else if(DLC_ubLuLdProtectState == LULD_UP_JUDGE)
	{
		if((LU == 1)&&(LD == 0)&&(LDOld == 1))
		{
			DLC_ubLuLdError = LU_SHORT;//logic 2
			DLC_ubLuLdProtectState = LULD_Fault;
		}
		else if((LD == 1)&&(LU == 0)&&(LUOld == 1))
		{
			DLC_uwLuLdTimer= 0;
			DLC_ubLuLdProtectState = LULD_UP_LUok;
		}
		else
		{
			DLC_ubLuLdProtectState = LULD_UP_JUDGE;
		}
	}
	else if(DLC_ubLuLdProtectState == LULD_UP_LUok)
	{
		DLC_uwLuLdTimer++;
		if(DLC_uwLuLdTimer < pr[LS_SHORT_TIME]*100U)//02-42(dot1)->dot3
		{
			if((LD == 0)&&(LDOld == 1))
			{
				DLC_ubLuLdError = LULD_OK;
				DLC_ubLuLdProtectState = LULD_OK_RUN;
			}
			else
			{
				DLC_ubLuLdProtectState = LULD_UP_LUok;
			}
		}
		else
		{
			DLC_ubLuLdError = LUok_LD_SHORT;//logic 5
			DLC_ubLuLdProtectState = LULD_Fault;
		}
	}
	else if(DLC_ubLuLdProtectState == LULD_OK_RUN)
	{
		if((DLC_ubMode > MODE_NULL) &&(DLC_ubMode < MODE_DON) && (LU == 1)&&(LD == 1))
		{
			DLC_uwLuLdTimer++;
		}
		else
		{
			DLC_uwLuLdTimer = 0;
		}
		
		if(DLC_ulDisTar.ul < ((DLC_ulPgBrd - DLC_ulPgSen)>>1))
		{
			DLC_uwLuLdTimer = 0;
			DLC_ubLuLdProtectState = LULD_Leveling;
		}
		else if(DLC_uwLuLdTimer > pr[LS_SHORT_TIME]*100U)//02-42(dot1)->dot3
		{
			DLC_ubLuLdError = LULD_SHORT;//logic 7
			DLC_ubLuLdProtectState = LULD_Fault;
		}		
		else
		{
			DLC_ubLuLdProtectState = LULD_OK_RUN;
		}		
	}
	else if(DLC_ubLuLdProtectState == LULD_Leveling)
	{
		DLC_uwLuLdTimer++;
		if((LU == 1) && (LD == 1))
		{
			DLC_uwLuLdTimer = 0;			
			DLC_ubLuLdProtectState = LULD_STANDBY;
		}
		else if(DLC_uwLuLdTimer > pr[LS_OPEN_TIME]*100U)//02-41(dot1)->dot3
		{
			DLC_ubLuLdError = LULD_OPEN;//logic 3&6
			DLC_ubLuLdProtectState = LULD_Fault;
		}
		else
		{
			DLC_ubLuLdProtectState = LULD_Leveling;
		}
	}
	return 0;

}
//calculate Accepted Landing Floor
UBYTE DLC_LevStop(ULONG ulDis)
{
	ULONG ulTmp,uladjstVal;
    UWORD uwadjstVal;
	UBYTE	ubStpLev, ubLev, ubCnt;
	if(DLC_btModNor == 1 && BRK_RLS == 1){
        #if 0
		if(DLC_ubDIR == DIR_UP){
			ubCnt = (DLC_ulPosVal > DLC_ulPosLev[DLC_ubLevCur] ) ? 1 : 0;
			for(ubLev = 1; ulDis > (DLC_ulPosLev[DLC_ubLevCur + ubCnt]  - DLC_ulPosVal); ubCnt ++){
				if((DLC_ubLevCur + ubCnt) > DLC_ubLevMax){
					DLC_uwTra1 = 0x01;
					break;
				}
				else{
					DLC_uwTra1 = 0x02;	
					ubLev ++;
				} 	
			}
		}
		else if(DLC_ubDIR == DIR_DN){
			ubCnt = (DLC_ulPosVal < DLC_ulPosLev[DLC_ubLevCur]) ? 1 : 0;
			for(ubLev = 1; ulDis > (DLC_ulPosVal - DLC_ulPosLev[DLC_ubLevCur - ubCnt]);  ubCnt++){//adjust floor Aevin 7/2/2018
				if((DLC_ubLevCur - ubCnt) < DLC_ubLevMin){
					DLC_uwTra1 = 0x03;
					break;
				}
				else{
					DLC_uwTra1 = 0x04;
					ubLev ++;
				}
			}
		}
        #else
        //Adjust floor Aevin 7/2/2018

        if(DLC_ubDIR == DIR_UP){
            if(DLC_ubLevCur<=50)
                uwadjstVal = (UWORD)(DLC_ulPosLev[DLC_ubLevCur]) + (DLCxx[DLC_LimADDR + DLC_ubLevCur - 1]);
            else
                uwadjstVal = (UWORD)(DLC_ulPosLev[DLC_ubLevCur]) + (DLCxx[DLC_Adj50ADDRDN + DLC_ubLevCur -50 - 1]);
            uladjstVal = (DLC_ulPosLev[DLC_ubLevCur] & 0xffff0000) | ((ULONG)uwadjstVal & 0x0000ffff);
            
			ubCnt = (DLC_ulPosVal > uladjstVal ) ? 1 : 0;
            if((DLC_ubLevCur+ ubCnt)<=50)
                uwadjstVal = (UWORD)(DLC_ulPosLev[DLC_ubLevCur+ ubCnt]) + (DLCxx[DLC_LimADDR + DLC_ubLevCur - 1 + ubCnt]);
            else
                uwadjstVal = (UWORD)(DLC_ulPosLev[DLC_ubLevCur+ ubCnt]) + (DLCxx[DLC_Adj50ADDRDN + DLC_ubLevCur - 1 + ubCnt]);
            uladjstVal = (DLC_ulPosLev[DLC_ubLevCur+ ubCnt] & 0xffff0000) | ((ULONG)uwadjstVal & 0x0000ffff);
            
			for(ubLev = 1; ulDis > (uladjstVal  - DLC_ulPosVal); ubCnt ++){
				if((DLC_ubLevCur + ubCnt) > DLC_ubLevMax){
					DLC_uwTra1 = 0x01;
					break;
				}
				else{
					DLC_uwTra1 = 0x02;	
					ubLev ++;
				} 	
			}
		}
		else if(DLC_ubDIR == DIR_DN){
            if(DLC_ubLevCur<=50)
                uwadjstVal = (UWORD)(DLC_ulPosLev[DLC_ubLevCur]) + (DLCxx[DLC_Adj50ADDRUP + DLC_ubLevCur - 1]);
            else
                uwadjstVal = (UWORD)(DLC_ulPosLev[DLC_ubLevCur]) + (DLCxx[DLC_Adj50ADDRDN + DLC_ubLevCur -50 + 25 - 1]);
            uladjstVal = (DLC_ulPosLev[DLC_ubLevCur] & 0xffff0000) | ((ULONG)uwadjstVal & 0x0000ffff);
            
			ubCnt = (DLC_ulPosVal < uladjstVal ) ? 1 : 0;
            if((DLC_ubLevCur - ubCnt)<=50)
                uwadjstVal = (UWORD)(DLC_ulPosLev[DLC_ubLevCur - ubCnt]) + (DLCxx[DLC_Adj50ADDRUP + DLC_ubLevCur - 1 - ubCnt]);
            else
                uwadjstVal = (UWORD)(DLC_ulPosLev[DLC_ubLevCur - ubCnt]) + (DLCxx[DLC_Adj50ADDRDN + DLC_ubLevCur -50 +25 - 1 - ubCnt]);
            uladjstVal = (DLC_ulPosLev[DLC_ubLevCur - ubCnt] & 0xffff0000) | ((ULONG)uwadjstVal & 0x0000ffff);
            
			for(ubLev = 1; ulDis > (DLC_ulPosVal - uladjstVal);  ubCnt++){//adjust floor Aevin 7/2/2018
				if((DLC_ubLevCur - ubCnt) < DLC_ubLevMin){
					DLC_uwTra1 = 0x03;
					break;
				}
				else{
					DLC_uwTra1 = 0x04;
					ubLev ++;
				}
			}
		}
        #endif
		else{
			DLC_uwTra1 = 0x05;
			ubStpLev = 0;
		}
			
		ubStpLev = DLC_ubLevCur + ubLev;
	}
	else{
		DLC_uwTra1 = 0x07;
		ubStpLev = 0;
	}
	
	return ubStpLev;
}

void DLC_LevCur(void){
	ULONG ulUp, ulDn;
	UBYTE ubCur, i;
	
	if(DLC_ulPosVal > DLC_ulPosLev[DLC_ubLevMax] ){
		DLC_ubLevCur = DLC_ubLevMax;
		DLC_uwTra2 = 0x01;
	}
	else if(DLC_ulPosVal < DLC_ulPosLev[DLC_ubLevMin]){
		DLC_ubLevCur = DLC_ubLevMin;
		DLC_uwTra2 = 0x02;
	}
	else{
		for(i = DLC_ubLevMin; i <= DLC_ubLevMax; i ++){
			if(i == DLC_ubLevMin){
				ulUp = (DLC_ulPosLev[DLC_ubLevMin] + DLC_ulPosLev[DLC_ubLevMin + 1]) >> 1;
				if(DLC_ulPosVal <= ulUp){
					DLC_ubLevCur = DLC_ubLevMin;
					i = DLCFLOORMAX;	//jump out
					DLC_uwTra2 = 0x03;
				}
			}
			else if(i == DLC_ubLevMax){
				ulDn = (DLC_ulPosLev[DLC_ubLevMax] + DLC_ulPosLev[DLC_ubLevMax - 1]) >> 1;
				if(DLC_ulPosVal >= ulDn){
					DLC_ubLevCur = DLC_ubLevMax;
					i = DLCFLOORMAX;	//jump out
					DLC_uwTra2 = 0x04; 
				}					
			}
			else{
				ulUp = (DLC_ulPosLev[i] + DLC_ulPosLev[i + 1]) >> 1;
				ulDn = (DLC_ulPosLev[i] + DLC_ulPosLev[i - 1]) >> 1;
				if((DLC_ulPosVal > ulDn) && (DLC_ulPosVal < ulUp)){
					DLC_ubLevCur = i;
					i = DLCFLOORMAX;	//jump out
					DLC_uwTra2 = 0x05; 
				}
			}	
		}
	}
	
	//DLC_ubLevCur = ubCur;
	//return ubCur;
}

ULONG Spd_NOR(ULONG ulCurSpd){
	UDOUBLE  udJ1, udJ2, udJ3, udJ4, udAa, udAd,
	         udV1, udVa, udV2, udVc, udV3, udVd, udV4,
	         udT1, udTa, udT2, udTc, udT3, udTd, udT4,
	         ud1, ud2, ud3;
	ULONG    ulTmp, ulSpd, uladjstVal = 0;
	ULONG	   ulD2, ulDacc, ulDcon, ulD3, ulDdec, ulD4, ulDisStp, ulDisTar;
	UWORD    uw1, uwVcon, uwReg, uwCurSpd, uwSpd, uwTmr, uwNewJ4,uwadjstVal, uwDecDynJ, uwDecPct, uwPosPct;	
	UBYTE	   i, ubj;
	SWORD	swadjstVal;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 add

	fdec5.ul = cal_time(pr[FMAX],0);

	//1mm unit in Spd_NOR
	//uwCurSpd = ulCurSpd / 10;           // Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
	uwCurSpd = (ulCurSpd+5) / 10;	    // Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new

	if(DLC_ubMode==MODE_DYN)
		DynJerkTmr = DynJerkTmr<65535?DynJerkTmr+1:65535;
	else
		DynJerkTmr = 0;

/*
	if(DLC_ubDIR == DIR_UP){
		ulTmp = DLC_ulPosLev[DLC_ubLevTar]+3000;
		if(DLC_ulPosVal <= ulTmp)
			ulDisTar = DLC_ulPosLev[DLC_ubLevTar] - DLC_ulPosVal;
		else
			ulDisTar = 0;
	}
	else if(DLC_ubDIR == DIR_DN){
		ulTmp = (DLC_ulPosLev[DLC_ubLevTar]>3000)?(DLC_ulPosLev[DLC_ubLevTar]-3000):0;
		if(DLC_ulPosVal >= ulTmp)
			ulDisTar = DLC_ulPosVal - DLC_ulPosLev[DLC_ubLevTar];
		else
			ulDisTar = 0;
	}
	else{
		ulDisTar = 0;
	}
*/
#if 0	
	//calculate target level distance
	if(DLC_ubLevTar != 0){
		if(DLC_ulPosVal >= DLC_ulPosLev[DLC_ubLevTar])
			ulDisTar = DLC_ulPosVal - DLC_ulPosLev[DLC_ubLevTar];
		else
			ulDisTar = DLC_ulPosLev[DLC_ubLevTar] - DLC_ulPosVal;
	}
	else
		ulDisTar = 0;
#else
    //add  adjust floor position -----Aevin 7/2/2018
    //calculate target level distance
    if(DLC_ubLevTar!=0){

		if(DLC_btUP){	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
			if(DLC_ubLevTar <= 50){
				swadjstVal = DLCxx[DLC_LimADDR+DLC_ubLevTar-1];
			}
			else{
				swadjstVal = DLCxx[DLC_Adj50ADDRDN+DLC_ubLevTar-50+25-1];
			}
			swadjstVal += pr[DisDly] ;	// �u®�������v , �]+���ܭn���ᰱ��,�]-���ܭn���e����
			if(DLC_btPosLULDCal){		// �}�ҤG���ե�
				//swadjstVal++ ;			// �ؼЦ�m����1mm�~�ఱ���h
			}
		}
		else if(DLC_btDN){
            if(DLC_ubLevTar <= 50){
				swadjstVal = DLCxx[DLC_Adj50ADDRUP+DLC_ubLevTar-1];
            }
			else{
				swadjstVal = DLCxx[DLC_Adj50ADDRDN+DLC_ubLevTar-50+25-1];
			}
			swadjstVal -= pr[DisDly] ;	// �u®�������v , �]+���ܭn���ᰱ��,�]-���ܭn���e����
			if(DLC_btPosLULDCal){		// �}�ҤG���ե�
				//swadjstVal-- ;			// �ؼЦ�m����1mm�~�ఱ���h
			}
		}
		
		if(swadjstVal >= 0){
			uwadjstVal = swadjstVal;
			uladjstVal = DLC_ulPosLev[DLC_ubLevTar] + (ULONG)uwadjstVal;
		}
		else{
			uwadjstVal = (~swadjstVal) + 1;
			uladjstVal = DLC_ulPosLev[DLC_ubLevTar] - (ULONG)uwadjstVal;
		}

        if(DLC_ulPosVal >= uladjstVal){
            ulDisTar = DLC_ulPosVal - uladjstVal;
        }
        else{
            ulDisTar = uladjstVal - DLC_ulPosVal;
        }
    }
    else
        ulDisTar = 0;
#endif


	DLC_ulPosTar.ul = DLC_ulPosLev[DLC_ubLevTar];	// Sean, 20181207
	DLC_ulDisTar.ul = ulDisTar;//Artemis Speed &Position PDO transmition , James, 20200220
		
	if(DLC_ubDIR == DIR_UP || DLC_ubDIR == DIR_DN){
		// adco
		//if((DLC_ubMode == MODE_S3 || DLC_ubMode == MODE_DEC || DLC_ubMode == MODE_DYN)&&
		//	 (DLC_ubLevTar == DLC_ubLevCur)&&(DLC_btLU == 1 || DLC_btLD == 1))
		if((DLC_ubMode == MODE_S3 || DLC_ubMode == MODE_DEC || DLC_ubMode == MODE_DYN)&&
			 (DLC_ubLevTar == DLC_ubLevCur))
		{
			//if((DLC_btDznMd == 0)&&(DLC_btLU == 1 || DLC_btLD == 1))			
			if((DLC_btDznMd == 0)&&(((DLC_ubDIR == DIR_UP)&&(DLC_btLU == 1)&&(DLC_btLUOld == 0)) 
				|| ((DLC_ubDIR == DIR_DN)&&(DLC_btLD == 1)&&(DLC_btLDOld == 0))))//#15483 Short Floor Distance issue for Artemis 
			{
			    DLC_ubMode = MODE_DYN;
			}
			else if((DLC_btDznMd == 1)&&(DLC_btDZN == 1))
			{
			  	DLC_ubMode = MODE_DYN;
			}
		}
		
		if((DLC_ubMode==MODE_NULL) && (DLC_ubLevTar!=0) && (DLC_ubLevTar!=DLC_ubLevCur)){
			DLC_Init();	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 add
			DLC_ubSubtra = 0x02;
			DLC_ulDStop = 0;
			uwSpd = 0;
			DLC_ubMode = MODE_S1;
			DLC_btDisTar0mm = 0;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 add
			// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 del ---------
			/*
			DLC_uwS1Tmr = 0;
			DLC_uwS2Tmr = 0;
			DLC_uwS3Tmr = 0;
			DLC_uwAccTmr = 0;
			DLC_uwDecTmr = 0;
			*/ // ----------------------------------------------------------------------------			
		}
		else if(DLC_ubMode==MODE_S1)	//MODE_S1 = 1
		{		
			//S2 area
			ulD2 = EqCal_D2(uwCurSpd);
			//V-const (EqCal_D2)
			DLC_uwVc = DLC_uwV2;
			//V-const area
			ud1 = (UDOUBLE)DLC_uwVc*(UDOUBLE)DLC_uwTc/1000;
			ulDcon = (ULONG)ud1;
			//ulDcon = ((float)DLC_uwVc/1000.0)*((float)DLC_uwTc/1000.0)*1000.0;
			//T3, Tdec, T4
			EqCal_T3_Tdec_T4(DLC_uwVc);
			//S3 area
			ulD3 = EqCal_D3(DLC_uwVc);
			//dec area
			ulDdec = EqCal_Ddec();
			//S4 area
			ulD4 = EqCal_D4();
			//stopping area
			ulDisStp = ulD2 + ulDcon + ulD3 + ulDdec + ulD4;			
			DLC_ulDStop = ulDisStp;
				
			//mode change
			//04-39 modi, 17372
			//if((ulDisTar <= ulDisStp) || (DLC_uwVc >=(10*pr[Lift_SPD])) )
			if((ulDisTar<=ulDisStp)||(DLC_uwVc>=DLC_uwRateSpd)){
				DLC_ubSubtra = 0x03;
				DLC_ubMode = MODE_S2;
			}
			else
			{
				if(DLC_uwS1Tmr<(pr[S4ACC1]*10))
				{
					DLC_ubSubtra = 0x04;
					DLC_ubMode = MODE_S1;
					DLC_uwS1Tmr = (DLC_uwS1Tmr<65535)?DLC_uwS1Tmr+1:65535;
				}
				else
				{
					DLC_ubSubtra = 0x05;
					DLC_ubMode = MODE_ACC;					
				}
			} 
			
			//Speed Output (J1*T1*T1/2)
			udJ1 = (UDOUBLE)DLC_uwJR1;
			ud1 = (UDOUBLE)DLC_uwS1Tmr;
			//ud2 = udJ1*ud1*ud1/2000000;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D source
			//uwSpd = (UWORD)ud2;			// Issue 277400 ���t�観����t�Υ��h���Ǫ����D source
			ud2 = (udJ1*ud1*ud1+100000)/200000;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D new
			DLC_ulSpd0p1mm = (ULONG)ud2;		// Issue 277400 ���t�観����t�Υ��h���Ǫ����D new
			
			//accel
			//ud1 = (UDOUBLE)DLC_uwJR1*(UDOUBLE)DLC_uwS1Tmr/1000;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
			ud1 = ((UDOUBLE)DLC_uwJR1*(UDOUBLE)DLC_uwS1Tmr+500)/1000;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
			DLC_uwATmp = (UWORD)ud1;
		}
		else if(DLC_ubMode == MODE_ACC)	//MODE_ACC = 2
		{
			//S2 area
			ulD2 = EqCal_D2(uwCurSpd);	//�Υثe���t��,�}�l��S2��{,����S2��{��|���h�ֶZ��
			//V-const (EqCal_D2)
			DLC_uwVc = DLC_uwV2;	//�H�ثe���t�׶}�l�p��,��S2������,�t�׷|�O�h��,���mm/s
			//V-const area
			//ud1 = (UDOUBLE)DLC_uwVc*(UDOUBLE)DLC_uwTc/1000;	//���t�q�ݭn�����Z��	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
			ud1 = ((UDOUBLE)DLC_uwVc*(UDOUBLE)DLC_uwTc+500)/1000;	//���t�q�ݭn�����Z��	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
			ulDcon = (ULONG)ud1;
			//ulDcon = ((double)DLC_uwVc/1000.0)*((double)DLC_uwTc/1000.0)*1000.0;
			//T3, Tdec, T4
			EqCal_T3_Tdec_T4(DLC_uwVc);
			//S3 area
			ulD3 = EqCal_D3(DLC_uwVc);	//��DLC_uwVc(S3�}�l���t��),�}�l��S3��{,����S3��{��|���h�ֶZ��
			//dec area
			ulDdec = EqCal_Ddec();
			//S4 area
			ulD4 = EqCal_D4();
			//stopping area
			ulDisStp = ulD2 + ulDcon + ulD3 + ulDdec + ulD4;
			DLC_ulDStop = ulDisStp;
							
			//mode change
			//DLC_uwVc>=DLC_uwRateSpd��,�i�JMODE_CON�q,�h���ӥؼжZ��
			if((ulDisTar <= ulDisStp) || (DLC_uwVc >= DLC_uwRateSpd))
			{
				DLC_ubSubtra = 0x06;
				DLC_ubMode = MODE_S2;
			}
			else
			{
				DLC_ubSubtra = 0x07;
				DLC_ubMode = MODE_ACC;
			}

			//Speed Output
			//uwSpd = DLC_uwVR1+(DLC_uwAccTmr*DLC_uwAa)/1000;	
			//uwSpd = uwCurSpd;
			if(DLC_uwVc < DLC_uwRateSpd)
			{
				DLC_uwAccTmr = (DLC_uwAccTmr<60000)?(DLC_uwAccTmr+1):60000;
				
				udV1 = (UDOUBLE)DLC_uwVR1;
				udAa = (UDOUBLE)DLC_uwAa;
				ud1 = (UDOUBLE)DLC_uwAccTmr;
				
				//ud2 = udV1+((udAa*ud1)/1000);		// Issue 277400 ���t�観����t�Υ��h���Ǫ����D source
				//uwSpd = (UWORD)ud2;				// Issue 277400 ���t�観����t�Υ��h���Ǫ����D source
				ud2 = (udV1*10)+((udAa*ud1+50)/100);// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong new
				DLC_ulSpd0p1mm = (ULONG)ud2;		// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong new			
			}
			else
			{
				//uwSpd = uwCurSpd;			// Issue 277400 ���t�観����t�Υ��h���Ǫ����D source
				DLC_ulSpd0p1mm = ulCurSpd;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D new
			}
			
			//accel
			DLC_uwATmp = DLC_uwAa;			
		}
		else if(DLC_ubMode == MODE_S2)	//MODE_S2 = 3
		{
			//DLC_ulDStop = DLC_ulDStop;
			
			//V-const area
			//ud1 = (UDOUBLE)DLC_uwVc*(UDOUBLE)DLC_uwTc/1000;	//���t�q�ݭn�����Z��	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
			ud1 = ((UDOUBLE)DLC_uwVc*(UDOUBLE)DLC_uwTc+500)/1000;	//���t�q�ݭn�����Z��	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
			ulDcon = (ULONG)ud1;
			//T3, Tdec, T4
			EqCal_T3_Tdec_T4(DLC_uwVc);
			//S3 area
			ulD3 = EqCal_D3(DLC_uwVc);
			//dec area
			ulDdec = EqCal_Ddec();
			//S4 area
			ulD4 = EqCal_D4();
			//stopping area
			ulDisStp = ulDcon + ulD3 + ulDdec + ulD4;		
			DLC_ulDStop = ulDisStp;			
			
			
			//mode change
			if(DLC_uwS2Tmr >= DLC_uwT2){
				DLC_ubSubtra = 0x08;
				DLC_ubMode = MODE_CON;
			}
			else{
				DLC_ubSubtra = 0x09;
				DLC_ubMode = MODE_S2;
			}
			
			//Speed Output
			//uwSpd = DLC_uwVc-(DLC_uwJR2*uwTmr*uwTmr/2000000);	
			DLC_uwS2Tmr = (DLC_uwS2Tmr<DLC_uwT2)?(DLC_uwS2Tmr+1):DLC_uwT2;
			
			ud1 = (UDOUBLE)(DLC_uwT2-DLC_uwS2Tmr);
			udVc = (UDOUBLE)DLC_uwVc;
			udJ2 = (UDOUBLE)DLC_uwJR2;
			
			//ud1 = udVc-(udJ2*ud1*ud1/2000000);	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D source
			//uwSpd = (UWORD)ud1;					// Issue 277400 ���t�観����t�Υ��h���Ǫ����D source
			ud1 = (udVc*10)-((udJ2*ud1*ud1+100000)/200000);	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong new
			DLC_ulSpd0p1mm = (ULONG)ud1;			// Issue 277400 ���t�観����t�Υ��h���Ǫ����D new

			//over-spd protection
			//if(uwSpd >= (10*pr[Lift_SPD])){		// Issue 277400 ���t�観����t�Υ��h���Ǫ����D source
			//	uwSpd = 10*pr[Lift_SPD];
			if(DLC_ulSpd0p1mm >= (100*pr[Lift_SPD])){	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D new
				DLC_ulSpd0p1mm = (ULONG)100*pr[Lift_SPD];		// Issue 277400 ���t�観����t�Υ��h���Ǫ����D new
				//DLC_uwVc = 10*pr[Lift_SPD];  //friday
				DLC_uwVc = DLC_uwRateSpd;
				DLC_uwS2Tmr = DLC_uwT2;
			}
			/*
			if(uwSpd >= (10*pr[Lift_SPD])){
				uwSpd = 10*pr[Lift_SPD];
				//DLC_uwVc = 10*pr[Lift_SPD];  //friday
				DLC_uwVc = DLC_uwRateSpd;
			}
			*/
		}
		else if(DLC_ubMode == MODE_CON){	//MODE_CON = 4
			//T3, Tdec, T4
			EqCal_T3_Tdec_T4(uwCurSpd);
			//S3 area
			ulD3 = EqCal_D3(uwCurSpd);
			//dec area
			ulDdec = EqCal_Ddec();
			//S4 area
			ulD4 = EqCal_D4();
			//stopping area
			ulDisStp = ulD3 + ulDdec + ulD4;
			DLC_ulDStop = ulDisStp;
			
			if(ulDisTar <= ulDisStp){
				DLC_ubSubtra = 0x0a;
				DLC_ubMode = MODE_S3;
			}
			else
			{
				DLC_ubSubtra = 0x0b;
			}
				
			//Speed Output
			//uwSpd = DLC_uwVc;				// Issue 277400 ���t�観����t�Υ��h���Ǫ����D source
			DLC_ulSpd0p1mm = (ULONG)DLC_uwVc*10;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D new
		}
		else if(DLC_ubMode == MODE_S3){	//MODE_S3 = 5
			//����ɧǳy�����~
			DLC_ulDStop = DLC_ulDStop;
			 	
			DLC_uwJD = DLC_uwJR4;
			DLC_uwPeriodCnt = 0;
			
			if(DLC_uwS3Tmr >= DLC_uwT3){
				if(DLC_uwTd > 0){
					DLC_ubSubtra = 0x0c;
					DLC_ubMode = MODE_DEC;
				}
				else{
					DLC_ubSubtra = 0x0d;
					DLC_ubMode = MODE_DYN;
				}
			}
			else{
				DLC_ubSubtra = 0x0e;
				DLC_ubMode = MODE_S3;
			}
				
			//Speed Output
			//uwSpd = DLC_uwVc-(DLC_uwJR3*DLC_uwS3Tmr*DLC_uwS3Tmr/2000000);
			DLC_uwS3Tmr = (DLC_uwS3Tmr<DLC_uwT3)?(DLC_uwS3Tmr+1):DLC_uwT3;
			
			udVc = (UDOUBLE)DLC_uwVc;
			udJ3 = (UDOUBLE)DLC_uwJR3;
			ud1 = (UDOUBLE)DLC_uwS3Tmr;
			//ud2 = udVc-(udJ3*ud1*ud1/2000000);// Issue 277400 ���t�観����t�Υ��h���Ǫ����D source
			//uwSpd = (UWORD)ud2;				// Issue 277400 ���t�観����t�Υ��h���Ǫ����D source
			ud2 = (udVc*10)-((udJ3*ud1*ud1+100000)/200000);	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong new
			DLC_ulSpd0p1mm = (ULONG)ud2;			// Issue 277400 ���t�観����t�Υ��h���Ǫ����D new
		}
		else if(DLC_ubMode==MODE_DEC){	//MODE_DEC=6

			ulD4 = EqCal_D4();
			ulDisStp = ulD4;

			if((ulDisTar <= ulDisStp) || (DLC_uwDecTmr >= DLC_uwTd)){
				DLC_ubSubtra = 0x0f;
				DLC_ubMode = MODE_DYN;
			}
			else{
				DLC_ubSubtra = 0x10;
				DLC_ubMode = MODE_DEC;
			}
			
			//Speed Output
			if(uwCurSpd > DLC_uwV4){
				//uwSpd = DLC_uwVc-DLC_uwV3-(Ad*Td);
				DLC_uwDecTmr = (DLC_uwDecTmr<DLC_uwTd)?(DLC_uwDecTmr+1):DLC_uwTd;
				
				udVc = (UDOUBLE)DLC_uwVc;
				udV3 = (UDOUBLE)DLC_uwV3;
				udAd = (UDOUBLE)DLC_uwAd;
				
				ud1 = (UDOUBLE)DLC_uwDecTmr;
				//ud2 = (ud1*udAd)/1000;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D source		
				//ud3 = udVc-udV3-ud2;		// Issue 277400 ���t�観����t�Υ��h���Ǫ����D source
				//uwSpd = (UWORD)ud3;		// Issue 277400 ���t�観����t�Υ��h���Ǫ����D source
				ud2 = (ud1*udAd+50)/100;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong new		
				ud3 = ((udVc-udV3)*10)-ud2;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D new
				DLC_ulSpd0p1mm = (ULONG)ud3;// Issue 277400 ���t�観����t�Υ��h���Ǫ����D new
			}
			else
				//uwSpd = uwCurSpd;			// Issue 277400 ���t�観����t�Υ��h���Ǫ����D source
				DLC_ulSpd0p1mm = ulCurSpd;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D new
		}
//		else if(DLC_ubMode == MODE_S4)	//MODE_S4=7
//		{
//			DLC_ubMode = MODE_S4;			
//			
//			DLC_uwS4Tmr = (DLC_uwS4Tmr<DLC_uwT4)?(DLC_uwS4Tmr+1):DLC_uwT4;
//			//Speed Output
//			ud1 = (UDOUBLE)DLC_uwJR4;
//			ud2 = (UDOUBLE)DLC_uwT4-(UDOUBLE)DLC_uwS4Tmr;
//			ud3 = ud1*ud2*ud2/2000000;
//			uwSpd = (UWORD)ud3;			
//		}
		else if(DLC_ubMode==MODE_DYN){  //MODE_DYN=8
			DLC_ulDStop = 0;
			DLC_ubMode = MODE_DYN;
			// Issue 277400 ���t�観����t�Υ��h���Ǫ����D Mitong add ---------
			if(ulDisTar == 0){
				DLC_btDisTar0mm = 1;
			}
			// -----------------------------------------------------
			
			if(DLC_uwPeriodCnt > 0){
				DLC_uwPeriodCnt --;
				
					DLC_uwTDCnt = (DLC_uwTDCnt<DLC_uwTD)?(DLC_uwTDCnt+1):DLC_uwTD;
					
				//spd output
				udJ4 = (UDOUBLE)DLC_uwJD;						//DLC_uwJD��S4���ʺAJ,���mm/s3
				udT4 = (UDOUBLE)DLC_uwTD-(UDOUBLE)DLC_uwTDCnt;
				//ud1 = udJ4*udT4*udT4/2000000;	//�t��	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D Mitong source
				//uwSpd = (UWORD)ud1;					// Issue 277400 ���t�観����t�Υ��h���Ǫ����D Mitong source	
				ud1 = (udJ4*udT4*udT4+100000) / 200000;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D Mitong new �|�ˤ��J
				DLC_ulSpd0p1mm = (ULONG)ud1;			// Issue 277400 ���t�観����t�Υ��h���Ǫ����D Mitong new
				DLC_ubSubtra = 0x20;	
			}
			else{
				DLC_uwPeriodCnt = 9;
				DLC_uwTDCnt = 0;
				if(!DLC_btDisTar0mm && (ulCurSpd > 50)){
					/*
					//(3)���DT4', �A�DJ4'
					//cal T4'      T4'=3*S'/V				
					ud1 = (UDOUBLE)3*(UDOUBLE)1000*(UDOUBLE)ulDisTar;
					ud1 = ud1 << 8;
					ud2 = (UDOUBLE)uwCurSpd;
					ud3 = ud1/ud2;
					ud3 = ud3 >> 8;
					DLC_uwTD = (UWORD)ud3;			
				
					//cal J4'      J4'=2*V/(T4'*T4')
					ud1 = (UDOUBLE)2*(UDOUBLE)1000000*(UDOUBLE)uwCurSpd;
					ud1 = ud1 << 8;
					ud2 = (UDOUBLE)DLC_uwTD*(UDOUBLE)DLC_uwTD;
					ud3 = ud1/ud2;
					ud3 = ud3 >> 8;
					DLC_uwJD = (UWORD)ud3;
	
					//spd output
					udJ4 = (UDOUBLE)DLC_uwJD << 8;
					udT4 = (UDOUBLE)DLC_uwTD;  //-(UDOUBLE)DLC_uwTDCnt;
					ud1 = udJ4*udT4*udT4/2000000;
					ud1 = ud1 >> 8;
					uwSpd = (UWORD)ud1;
					*/
				
					//(4)
					//J4' = 8v^3 / 36s^2
					uw1 = DLC_uwJD;	
				
					/* // Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
					ud1 = (UDOUBLE)uwCurSpd;
					ud2 = (UDOUBLE)ulDisTar;
					ud3 = ((UDOUBLE)8*ud1*ud1*ud1)/((UDOUBLE)36*ud2*ud2);	//�Υثe���t�פζZ����XJ��			
					DLC_uwJD = (UWORD)ud3;	//DLC_uwJD��S4���ʺAJ,���mm/s3
					*/
					// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new -----------------------------
					ud1 = (UDOUBLE)ulCurSpd;
					ud2 = (UDOUBLE)ulDisTar;
					//ud3 = (8 * ud1 * ud1 * ud1/1000) / (36 * ud2 * ud2) = (ud1 * ud1 * ud1) / (4500 * ud2 * ud2);
					ud1 = ud1 * ud1 * ud1;
					ud2 = (UDOUBLE)4500 * ud2 * ud2;
					ud3 = (ud1 + (ud2>>1)) / ud2;	//�|�ˤ��J
					DLC_uwJD = (UWORD)ud3;	//DLC_uwJD��S4���ʺAJ,���mm/s3
					// -----------------------------------------------------------------------------------------------

                    //uwtest11 = DLC_uwJD;
			        //jerk adj,Henry
					/*
					ubj=4, acc=0.8m, s1=2s, j1=400
					*/

    			    //jerk adj,Henry
        	
					//�ʺAJ����					
					if(DLC_uwJD > uw1){
						if((DLC_uwJD - uw1) > 2000){	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 15��1000
							DLC_uwJD = uw1 + 2000;
						}
					}

					if(DLC_uwJD > 50000){	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 add
						DLC_uwJD = 50000;
					}
					else if(DLC_uwJD < 100){
						DLC_uwJD = 100;
					}
					
						// -----------------------------------------------------
					
                    //uwtest12 = DLC_uwJD;
					//�ʺAJ����
					
					//�ʺAJ����
					
				}
				else{
					if(DLC_uwJD < 100){
						DLC_uwJD = 100;
					}
				}
				//T=sqrt(2V/J), �}����
				//ud1 = (UDOUBLE)2000000*(UDOUBLE)uwCurSpd/(UDOUBLE)DLC_uwJD;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
				ud1 = ((UDOUBLE)200000*(UDOUBLE)ulCurSpd+(UDOUBLE)(DLC_uwJD>>1))/(UDOUBLE)DLC_uwJD;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
				DLC_uwTD = uw_Sqrt32c_1((ULONG)ud1);
				
				//spd output
				udJ4 = (UDOUBLE)DLC_uwJD;
				udT4 = (UDOUBLE)DLC_uwTD;
				//ud1 = udJ4*udT4*udT4/2000000;		// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
				//uwSpd = (UWORD)ud1;				// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
				ud1 = (udJ4*udT4*udT4+100000)/200000;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new �|�ˤ��J
				DLC_ulSpd0p1mm = (ULONG)ud1;		// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
				DLC_ubSubtra = 0x21;	
			}

			if(DLC_ulSpd0p1mm > ulCurSpd){	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 add
				DLC_ulSpd0p1mm = ulCurSpd;
			}
			if(DLC_ulSpd0p1mm < 10){		// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 add
				DLC_ubMode = MODE_DON;
				DLC_ubSubtra = 0x30;
			}
					
	        //up over level
  			if(DLC_ubDIR == DIR_UP){
				//if(DLC_ulPosVal > uladjstVal){	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
				if((DLC_ulPosVal > uladjstVal) && ((DLC_ulPosVal - 10) > uladjstVal)){	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
					DLC_ubSubtra = 0x15;	// Sean, 20181207	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 del ROM����
           			DLC_ubMode = MODE_DON;         
            		//uwSpd = 0;		// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
					DLC_ulSpd0p1mm = 0;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
				}
				else if(DLC_ubLevTar == DLC_ubLevCur){
					if(DLC_btDznMd){
						if(!DLC_btDZN && DLC_btDZNOld){
							DLC_ubSubtra = 0x1B;
		            	   	DLC_ubMode = MODE_DON;         
        					//uwSpd = 0;		// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
							DLC_ulSpd0p1mm = 0;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
						}
					}
					else{
						if(!DLC_btLU && DLC_btLUOld){
							DLC_ubSubtra = 0x1C;
		        	       	DLC_ubMode = MODE_DON;         
        					//uwSpd = 0;		// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
							DLC_ulSpd0p1mm = 0;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
						}
					}
				}
  			}
			
            //dn over level
	        else if(DLC_ubDIR == DIR_DN){ 
				//if(DLC_ulPosVal < uladjstVal){	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
				if((DLC_ulPosVal < uladjstVal) && ((DLC_ulPosVal + 10) < uladjstVal)){	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
					DLC_ubSubtra = 0x16;	// Sean, 20181207
		        	    DLC_ubMode = MODE_DON;
            		//uwSpd = 0;		// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
					DLC_ulSpd0p1mm = 0;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
				}
				else if(DLC_ubLevTar == DLC_ubLevCur){
					if(DLC_btDznMd){
						if(!DLC_btDZN && DLC_btDZNOld){
							DLC_ubSubtra = 0x1D;
            				DLC_ubMode = MODE_DON;
            				//uwSpd = 0;		// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
							DLC_ulSpd0p1mm = 0;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
						}
					}
					else{
						if(!DLC_btLD && DLC_btLDOld){
							DLC_ubSubtra = 0x1E;
            				DLC_ubMode = MODE_DON;
            				//uwSpd = 0;		// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
							DLC_ulSpd0p1mm = 0;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
						}
					}
				}
  			}
		}
		else if(DLC_ubMode == MODE_DON){   //MODE_DON=9
			DLC_ubSubtra = 0x22;
			//uwSpd = 0;		// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
			DLC_ulSpd0p1mm = 0;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
			if(fcmd.uw.hi==0){
				//DLC_ubMode = MODE_NULL;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 del
				DLC_Init();
				DLC_ubSubtra = 0x23;
			}
		}
		else{		//protection
			DLC_ubSubtra = 0x13;
			//uwSpd = 0;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 del
			DLC_Init();		// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 add
		}	
	}
	else{
		DLC_ubSubtra = 0x14;
		//uwSpd = 0;				// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 del
		//ulDisStp = 0;				// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 del
		//DLC_ubMode = MODE_NULL;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 del
		DLC_Init();	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 add
	}	
	
	if((DLC_ubMode == MODE_DON) || (DLC_ubMode == MODE_NULL)){	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 add
		DLC_ulSpd0p1mm = 0;
	}
	
	//ulSpd = uwSpd * 10;		// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
	//return ulSpd;			// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
	return DLC_ulSpd0p1mm;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new	
}

// Task 268638 �������a-�h�q�t�[��t��S���u Mitong 20220616 add
ULONG Spd_Dec0S(UWORD uwS3, UWORD uwDec, UWORD uwS4)	//��S3 S4��t��0�t,S3 S3������ms,Dec������mm/s
{
// uwS3 uwS4���0.00s
// uwDec ���0.00m/s^2
	UDOUBLE	udJ3, udAd,	udVc, udV3, ud1, ud2, ud3;
	ULONG	ulSpd;
	UWORD	uwCurSpd, uwSpd;	
	

	fdec5.ul = cal_time(pr[FMAX],0);	// Mitong ?

	//1mm
	uwCurSpd = (UWORD)(DLC_ulCurSpd / 10);
	uwSpd = uwCurSpd;
	if(DLC_ulCurSpd != 0){			
		if(DLC_ubDec0SMode == MODE_NULL){	//�Ĥ@���i�JSpd_Dec0S
			//DLC_ubSubtra = 0xe0;			
			DLC_uwVc = uwCurSpd;//���:mm/s		
			DLC_uwAd = uwDec;	//���:mm/sec^2
			
			//�p��t�צ��u
			//DLC�t�װ򥻰Ѽ�Ū��
			DLC_uwTR3 = uwS3;	//���:ms
			DLC_uwTR3 = (DLC_uwTR3==0)?1:DLC_uwTR3;	//minimum protection
			DLC_uwJR3 = ((UDOUBLE)1000*(UDOUBLE)DLC_uwAd)/(UDOUBLE)DLC_uwTR3;	//���:mm/sec^3
			DLC_uwVR3 = ((UDOUBLE)DLC_uwJR3*(UDOUBLE)DLC_uwTR3*(UDOUBLE)DLC_uwTR3)/(UDOUBLE)2000000;	//V3�z�Q�t���ܤƶq	//���:mm/sec

			DLC_uwTR4 = uwS4;	//���:ms
			DLC_uwTR4 = (DLC_uwTR4==0)?1:DLC_uwTR4;	//minimum protection						
			DLC_uwJR4 = ((UDOUBLE)1000*(UDOUBLE)DLC_uwAd)/(UDOUBLE)DLC_uwTR4;	//���:mm/sec^3			
			DLC_uwVR4 = ((UDOUBLE)DLC_uwJR4*(UDOUBLE)DLC_uwTR4*(UDOUBLE)DLC_uwTR4)/(UDOUBLE)2000000;	//V4�z�Q�t���ܤƶq	//���:mm/sec
			
			//T3, Tdec, T4
			EqCal_T3_Tdec_T4(uwCurSpd);
			DLC_uwT3_Dec0S = DLC_uwT3;	//�B���S3��ڭn�����ɶ�,��� ms
			DLC_uwV3_Dec0S = DLC_uwV3;	//�qS3�}�l��S3����,�t�׷|��֦h��,��� mm/s
			DLC_uwJR3_Dec0S = DLC_uwJR3;//S3��J,,��� mm/s^3

			DLC_uwTd_Dec0S = DLC_uwTd;	//����t�q�n�����ɶ�,��� ms
			DLC_uwVd_Dec0S = DLC_uwVd;	//����t�q�n�����t���ܤƶq,��� mm/s
			
			DLC_uwT4_Dec0S = DLC_uwT4;	//�B���S4��ڭn�����ɶ�,��� ms		
			DLC_uwV4_Dec0S = DLC_uwV4;	//S4�}�l�ɪ��t��,��� mm/s
			DLC_uwJR4_Dec0S = DLC_uwJR4;//S4��J,,��� mm/s^3
						
			DLC_uwVc_Dec0S = DLC_uwVc;	//��t�}�l�ɪ��t��,��� mm/s
			DLC_uwAd_Dec0S = DLC_uwAd;	//��t��,��� mm/s^2
			
			DLC_ubDec0SMode = MODE_S3;
			DLC_uwS3Tmr = 0;
		}
		if(DLC_ubDec0SMode == MODE_S3){	//MODE_S3 = 5
			if(uwS3 != 0){
				//Speed Output
				//uwSpd = DLC_uwVc-(DLC_uwJR3*DLC_uwS3Tmr*DLC_uwS3Tmr/2000000);
				DLC_uwS3Tmr = (DLC_uwS3Tmr < 65535)?(DLC_uwS3Tmr+1):65535;	//S3�ثe�w�B�઺�ɶ�,���ms			
				udVc = (UDOUBLE)DLC_uwVc_Dec0S;
				udJ3 = (UDOUBLE)DLC_uwJR3_Dec0S;
				ud1 = (UDOUBLE)DLC_uwS3Tmr;
				ud2 = udVc-(udJ3*ud1*ud1/2000000);
				uwSpd = (UWORD)ud2;
				if(DLC_uwS3Tmr >= DLC_uwT3_Dec0S){
					if(DLC_uwTd_Dec0S > 0){
						DLC_ubSubtra = 0xe1;
						DLC_ubDec0SMode = MODE_DEC;
					}
					else{
						if(uwS4 != 0){
							DLC_ubSubtra = 0xe2;
							DLC_ubDec0SMode = MODE_S4;
						}
						else{
							DLC_ubSubtra = 0xe3;
							DLC_ubDec0SMode = MODE_DEC;
						}
					}
				}
				else if(uwSpd <= (DLC_uwVc_Dec0S - DLC_uwV3_Dec0S)){
					if(DLC_uwTd_Dec0S > 0){
						DLC_ubSubtra = 0xe4;
						DLC_ubDec0SMode = MODE_DEC;
					}
					else{
						if(uwS4 != 0){
							DLC_ubSubtra = 0xe5;
							DLC_ubDec0SMode = MODE_S4;
						}
						else{
							DLC_ubSubtra = 0xe6;
							DLC_ubDec0SMode = MODE_DEC;
						}
					}
				}
				else if(uwSpd <= DLC_uwV4_Dec0S){
					if(uwS4 != 0){
						DLC_ubSubtra = 0xe7;
						DLC_ubDec0SMode = MODE_S4;
					}
					else{
						DLC_ubSubtra = 0xe8;
						DLC_ubDec0SMode = MODE_DEC;
					}
				}
				else{
					DLC_ubSubtra = 0xe9;
					DLC_ubDec0SMode = MODE_S3;
				}				
			}
			else{
				DLC_ubSubtra = 0xea;
				DLC_ubDec0SMode = MODE_DEC;	
				DLC_uwV3_Dec0S = 0;
			}

			if(DLC_ubDec0SMode == MODE_DEC){
				DLC_uwDecTmr = 0;
				DLC_uwVc_Dec0S = uwSpd;
			}
			else if(DLC_ubDec0SMode == MODE_S4){
				DLC_uwS4Tmr = 0;
				DLC_uwDecTmr = 0;			
				DLC_uwVc_Dec0S = uwSpd;
			}
		}
		else if(DLC_ubDec0SMode==MODE_DEC){	//MODE_DEC=6
			DLC_uwDecTmr = (DLC_uwDecTmr<65535)?(DLC_uwDecTmr+1):65535;	//����t�q�ثe�w�B�઺�ɶ�,���ms
			if((uwS3 != 0) && (uwS4 != 0)){			
				//Speed Output
				if(uwCurSpd > DLC_uwV4_Dec0S){	//S4�}�l�ɪ��t��
					//uwSpd = DLC_uwVc - (Ad*Td);				
					udVc = (UDOUBLE)DLC_uwVc_Dec0S;
					udAd = (UDOUBLE)DLC_uwAd_Dec0S;							
					ud1 = (UDOUBLE)DLC_uwDecTmr;
					ud2 = (udAd * ud1) / 1000;	
					if(udVc >= ud2){
						ud3 = udVc - ud2;
						uwSpd = (UWORD)ud3;
						DLC_ubSubtra = 0xed;
					}
					else{
						DLC_ubDec0SMode = MODE_S4;
						DLC_ubSubtra = 0xee;
					}
				}
				else{
					DLC_ubDec0SMode = MODE_S4;
					DLC_ubSubtra = 0xf0;
				}
				
				if(DLC_uwDecTmr >= DLC_uwTd_Dec0S){
					DLC_ubSubtra = 0xf1;
					DLC_ubDec0SMode = MODE_S4;
				}
				else if(uwSpd < DLC_uwV4_Dec0S){
					DLC_ubSubtra = 0xf2;
					DLC_ubDec0SMode = MODE_S4;
				}
				else{
					DLC_ubSubtra = 0xf3;
					DLC_ubDec0SMode = MODE_DEC;
				}				
			}
			else if((uwS3 == 0) && (uwS4 != 0)){
				if(uwCurSpd > DLC_uwV4_Dec0S){	//S4�}�l�ɪ��t��
					//uwSpd = DLC_uwVc - (Ad*Td);				
					udVc = (UDOUBLE)DLC_uwVc_Dec0S;
					udAd = (UDOUBLE)DLC_uwAd_Dec0S;				
					ud1 = (UDOUBLE)DLC_uwDecTmr;
					ud2 = (udAd * ud1) / 1000;

					if(udVc >= ud2){
						ud3 = udVc - ud2;
						uwSpd = (UWORD)ud3;
						DLC_ubSubtra = 0xf4;
					}
					else{
						DLC_ubSubtra = 0xf5;
						DLC_ubDec0SMode = MODE_S4;
					}
				}
				else{
					DLC_ubSubtra = 0xf6;
					DLC_ubDec0SMode = MODE_S4;
				}

				if(uwSpd < DLC_uwV4_Dec0S){
					DLC_ubSubtra = 0xf7;
					DLC_ubDec0SMode = MODE_S4;
				}
			}
			else if((uwS3 != 0) && (uwS4 == 0)){
				//Speed Output
				if(uwCurSpd > 0){	//S4�}�l�ɪ��t��
					//uwSpd = DLC_uwVc - (Ad*Td);				
					udVc = (UDOUBLE)DLC_uwVc_Dec0S;
					udAd = (UDOUBLE)DLC_uwAd_Dec0S;							
					ud1 = (UDOUBLE)DLC_uwDecTmr;
					ud2 = (udAd * ud1) / 1000;	
					if(udVc >= ud2){
						ud3 = udVc - ud2;
						uwSpd = (UWORD)ud3;
						DLC_ubSubtra = 0xf8;
					}
					else{
						DLC_ubSubtra = 0xf9;
						DLC_ubDec0SMode = MODE_DON;
						uwSpd = 0;
					}
				}
				else{
					DLC_ubSubtra = 0xfb;
					DLC_ubDec0SMode = MODE_DON;
					uwSpd = 0;
				}
			}
			else if((uwS3 == 0) && (uwS4 == 0)){
				if(uwCurSpd > 0){	//S4�}�l�ɪ��t��
					//uwSpd = DLC_uwVc - (Ad*Td);				
					udVc = (UDOUBLE)DLC_uwVc_Dec0S;
					udAd = (UDOUBLE)DLC_uwAd_Dec0S;				
					ud1 = (UDOUBLE)DLC_uwDecTmr;
					ud2 = (udAd * ud1) / 1000;

					if(udVc >= ud2){
						ud3 = udVc - ud2;
						uwSpd = (UWORD)ud3;
						DLC_ubSubtra = 0xfc;
					}
					else{
						DLC_ubSubtra = 0xfd;
						DLC_ubDec0SMode = MODE_DON;
						uwSpd = 0;
					}
				}
				else{
					DLC_ubSubtra = 0xfe;
					DLC_ubDec0SMode = MODE_DON;
					uwSpd = 0;
				}
			}
			
			if(DLC_ubDec0SMode == MODE_S4){
				DLC_uwS4Tmr = 0;
				DLC_uwDecTmr = 0;
				DLC_uwVc_Dec0S = uwSpd;
			}
		}
		else if(DLC_ubDec0SMode == MODE_S4)	//MODE_S4=7
		{
			do{
				if((uwCurSpd > 0) && (uwS4 != 0)){			
					if(uwCurSpd <= DLC_uwV4_Dec0S){					
						DLC_uwS4Tmr = (DLC_uwS4Tmr<65535)?(DLC_uwS4Tmr+1):65535;					
						if(DLC_uwS4Tmr <= DLC_uwT4_Dec0S){
							//Speed Output
							ud1 = (UDOUBLE)DLC_uwJR4_Dec0S;
							ud2 = (UDOUBLE)DLC_uwT4_Dec0S - (UDOUBLE)DLC_uwS4Tmr;
							ud3 = ud1*ud2*ud2/2000000;
							uwSpd = (UWORD)ud3;
							DLC_ubSubtra = 0xff;
						}
						else{
							DLC_ubSubtra = 0xeb;
							DLC_ubDec0SMode = MODE_DON;
							uwSpd = 0;
						}					
					}
					else{
						DLC_uwDecTmr = (DLC_uwDecTmr<65535)?(DLC_uwDecTmr+1):65535;
						//uwSpd = DLC_uwVc -(Ad*Td);				
						udVc = (UDOUBLE)DLC_uwVc_Dec0S;
						udAd = (UDOUBLE)DLC_uwAd_Dec0S;				
						ud1 = (UDOUBLE)DLC_uwDecTmr;
						ud2 = (ud1*udAd)/1000;
						if(udVc >= ud2){
							ud3 = udVc - ud2;
							uwSpd = (UWORD)ud3;
							DLC_ubSubtra = 0xec;
						}
						else{
							DLC_ubSubtra = 0xef;
							DLC_ubDec0SMode = MODE_DON;
							uwSpd = 0;
						}
						if(uwSpd <= DLC_uwV4_Dec0S){
							uwSpd = DLC_uwV4_Dec0S;
							DLC_uwS4Tmr = 0;
						}				
					}
				}
				else{
					DLC_ubDec0SMode = MODE_DON;
					uwSpd = 0;
				}
			}while((uwSpd > uwCurSpd) && (uwSpd != 0));
		}
		else if(DLC_ubDec0SMode == MODE_DON){   //MODE_DON=9
			uwSpd = 0;
			if(fcmd.uw.hi==0){
				DLC_ubDec0SMode = MODE_NULL;
				DLC_Init();
			}
		}
		else{		//protection
			DLC_ubSubtra = 0xf3;
			uwSpd = 0;
		}	
	}
	else{
		DLC_ubDec0SMode = MODE_NULL;
	}
	
	if(uwSpd > uwCurSpd){
		uwSpd = uwCurSpd;
		DLC_ubSubtra = 0xfa;
	}
	ulSpd = uwSpd * 10;
	
	return ulSpd;
}


ULONG Spd_Linear(UWORD uwTarSpd, UWORD uwAcc, UWORD uwDec)
{
	UDOUBLE ud1, ud2, ud3;
	ULONG ulCurSpd, ulMaxSpd, ulSpd;
	UWORD uwSpdOut, uwTmr, uwAa, uwAd;

	ulSpd = 0;
	ulCurSpd = DLC_ulCurSpd;		//0.1mm
	uwTarSpd = uwTarSpd*10;	    //0.1mm
	uwAa = uwAcc;
	uwAd = uwDec;
	
	fdec5.ul = cal_time(pr[FMAX],10);

	if(DLC_ubDIR == DIR_UP || DLC_ubDIR == DIR_DN)
	{
		if(DLC_ubCnt < 9)
		{
			DLC_ubCnt ++;
			ulSpd = ulCurSpd;
		}
		else
		{
			DLC_ubCnt = 0;

			if((ulCurSpd + uwAa) <= uwTarSpd)
			{
				ulSpd = ulCurSpd + uwAa;
				DLC_uwTra3 = 0x01;
			}
			else if(ulCurSpd > uwTarSpd){
				if((ulCurSpd >= uwAd)&&((ulCurSpd - uwAd) > uwTarSpd))
				{
					ulSpd = ulCurSpd - uwAd;
					DLC_uwTra3 = 0x02;
				}
				else
				{
					ulSpd = uwTarSpd;
					DLC_uwTra3 = 0x03;
				}
			}
			else
			{
				ulSpd = uwTarSpd;
				DLC_uwTra3 = 0x04;
			}
			
		}
	}
	else
	{
		ulSpd = 0;
		DLC_uwTra3 = 0x05;
	}
	if(ulSpd > (ULONG)pr[Lift_SPD] * 100U)
	{
		ulSpd = (ULONG)pr[Lift_SPD] * 100U; //DLC_ulCurSpd: dot4, pr[Lift_SPD]: dot2
	}
	return ulSpd;
}

/*
ULONG Spd_FSD(UWORD uwPrFSD, UWORD uwDecTmr){
	ULONG ulSpd, ulCurSpd;
	UWORD uwSpdDec;
	
	//uwSpdDec = (uwPrFSD * 10) / uwDecTmr;
	ulSpd = 0;
	ulCurSpd = DLC_ulCurSpd;		//0.1mm
	
	uwPrFSD = uwPrFSD/10;	
	
	if(DLC_ubCnt < 10){
		DLC_ubCnt ++;
		ulSpd = ulCurSpd;
	}
	else{
		DLC_ubCnt = 0;
		if(DLC_ulCurSpd <= uwPrFSD){
			ulSpd = 0;
			DLC_ubSubtra = 0x30;
		}
		else{
			ulSpd = DLC_ulCurSpd - uwPrFSD;
			DLC_ubSubtra = 0x31;
		}		
	}

	return ulSpd;
}
*/
ULONG Spd_FSD(UWORD uwPrFSD, UWORD uwDecTmr){
    ULONG ulSpd, ulCurSpd;
    UWORD uwSpdFSD;
    
    //uwSpdDec = (uwPrFSD * 10) / uwDecTmr;
    ulSpd = 0;
    ulCurSpd = DLC_ulCurSpd;        //0.1mm
    
    uwSpdFSD = uwPrFSD/10;  
    
//    uwtest24 = DLC_ulCurSpd;
//    uwtest25 = uwSpdFSD;

	//if(DLC_ubCnt < 10){	// Task 268638 �������a-�h�q�t�[��t��S���u Mitong 20220516 source
    if(DLC_ubCnt < 9){	// Task 268638 �������a-�h�q�t�[��t��S���u Mitong 20220516 new
        DLC_ubCnt ++;
        ulSpd = ulCurSpd;
    }
    else{
        DLC_ubCnt = 0;
        if(DLC_ulCurSpd <= uwSpdFSD){
            ulSpd = 0;
            DLC_ubSubtra = 0x30;
        }
        else{
            ulSpd = DLC_ulCurSpd - uwSpdFSD;
            DLC_ubSubtra = 0x31;
        }       
    }
    return ulSpd;
}



//D2=(V2*T2)-(J2*T2*T2*T2/6)
ULONG EqCal_D2(UWORD uwCurSpd){
	UDOUBLE  udCurSpd, udJ2, udT2, udV2,
	         ud1, ud2, ud3;
	ULONG L1;
	
	udCurSpd = (UDOUBLE)uwCurSpd;
	udJ2 = (UDOUBLE)DLC_uwJR2;
		
	if(uwCurSpd >= DLC_uwVR2){
		DLC_uwT2 = DLC_uwTR2;
		DLC_uwV2 = uwCurSpd+DLC_uwVR2;
		
		udT2 = (UDOUBLE)DLC_uwT2;
		udV2 = (UDOUBLE)DLC_uwV2;
	}
	else{
		//�p��T2
		//ud1 = (UDOUBLE)10000*2*udCurSpd/udJ2;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
		ud1 = ((UDOUBLE)20000*udCurSpd+(udJ2>>1))/udJ2;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
		L1 = (ULONG)ud1;
		DLC_uwT2 = 10*uw_Sqrt32c_1(L1);
		udT2 = (UDOUBLE)DLC_uwT2;
		
		//�p��V2���t��
		//ud1 = (udJ2*udT2*udT2)/(UDOUBLE)2000000;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
		ud1 = (udJ2*udT2*udT2+(UDOUBLE)1000000)/(UDOUBLE)2000000;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
		DLC_uwV2 = uwCurSpd+(UWORD)ud1;	//�H�ثe���t�׶}�l�p��,��S2������,�t�׷|�O�h��,���mm/s
		udV2 = (UDOUBLE)DLC_uwV2;
	}
			
	//ud1 = udJ2*udT2*udT2*udT2/6000000000;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
	ud1 = (udJ2*udT2*udT2*udT2+3000000000)/6000000000;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
	//ud2 = udV2*udT2/1000;		// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
	ud2 = (udV2*udT2+500)/1000;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
	ud3 = ud2-ud1;
	L1 = (ULONG)ud3;
		
	return L1;
}

//D3=Vc
ULONG EqCal_D3(UWORD uwVcon){
	ULONG     L1;
	UDOUBLE   udJ3, udT3, udVc,
	          ud1, ud2, ud3;
	
	udJ3 = (UDOUBLE)DLC_uwJR3;
	udT3 = (UDOUBLE)DLC_uwT3;
	udVc = (UDOUBLE)uwVcon;
	
	//ud1 = udJ3*udT3*udT3*udT3/6000000000;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
	ud1 = (udJ3*udT3*udT3*udT3+3000000000)/6000000000;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
	//ud2 = udVc*udT3/1000;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
	ud2 = (udVc*udT3+500)/1000;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
	ud3 = ud2 - ud1;
	L1 = (ULONG)ud3;

	return L1;
}

//D4=J4*T4*T4*T4/6;
ULONG EqCal_D4(void){
	UDOUBLE  udJ4, udT4, ud1;
	ULONG    L1;
	
	udJ4 = (UDOUBLE)DLC_uwJR4;
	udT4 = (UDOUBLE)DLC_uwT4;
	
	//ud1 = (udJ4*udT4*udT4*udT4)/6000000000;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
	ud1 = (udJ4*udT4*udT4*udT4+3000000000)/6000000000;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
	L1 = (ULONG)ud1;
	
	return L1;	
}

//Dc=Vc*Tc
ULONG EqCal_Dcon(UWORD uwVcon){
	UDOUBLE udVc, udTc, ud1;
	ULONG L1;
	
	udVc = (UDOUBLE)uwVcon;
	udTc = (UDOUBLE)pr[LAND_DLY_TIME];
	
	ud1 = (udVc*udTc)/1000;
	L1 = (ULONG)ud1;

	return L1;
}

//Dd=(V4+V4+Vd)*Td/2;	
ULONG EqCal_Ddec(void){
	UDOUBLE  udV4, udVd, udTd,
	         ud1, ud2, ud3;
	ULONG    L1;
	
	udV4 = (UDOUBLE)DLC_uwV4;
	udVd = (UDOUBLE)DLC_uwVd;
	udTd = (UDOUBLE)DLC_uwTd;
		
	//ud1 = ((udV4+udV4+udVd)*udTd)/2000;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
	ud1 = (((udV4+udV4+udVd)*udTd)+1000)/2000;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
	L1 = (ULONG)ud1;

	return L1;
}

//T3, Td, T4
void EqCal_T3_Tdec_T4(UWORD uwVcon){
	UDOUBLE udVc, udV3, udVd, udV4, udT3, udTd, udT4, udAd, udJ3, udJ4,
	        ud1, ud2, ud3;
	ULONG   L1;

	udVc = (UDOUBLE)uwVcon;
	udAd = (UDOUBLE)DLC_uwAd;
	udJ3 = (UDOUBLE)DLC_uwJR3;
	udJ4 = (UDOUBLE)DLC_uwJR4;
	
	if((DLC_uwVR3 + DLC_uwVR4) <= uwVcon){
		//T3 = TR3
		//T4 = TR4
		//V3 = VR3
		//V4 = VR4
		DLC_uwT3 = DLC_uwTR3;
		DLC_uwT4 = DLC_uwTR4;
		DLC_uwV3 = DLC_uwVR3;
		DLC_uwV4 = DLC_uwVR4;
				
		udT3 = (UDOUBLE)DLC_uwT3;
		udT4 = (UDOUBLE)DLC_uwT4;
		udV3 = (UDOUBLE)DLC_uwV3;
		udV4 = (UDOUBLE)DLC_uwV4;
		
		//Td = (Vc-V3-V4)/Ad
		//udTd = (UDOUBLE)1000*(udVc-udV3-udV4)/udAd;	//����t�q�n�����ɶ� ms// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
		udTd = ((UDOUBLE)1000*(udVc-udV3-udV4)+(udAd>>1))/udAd;	//����t�q�n�����ɶ� ms// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
		DLC_uwTd = (UWORD)udTd;	//����t�q�n�����ɶ� ms
		
		//Vd = Ad*Td
		//udVd = udAd*udTd/1000;		//����t�q�n�����ɶ� ms// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
		udVd = (udAd*udTd+500)/1000;	//����t�q�n�����ɶ� ms// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
		DLC_uwVd = (UWORD)udVd;	//����t�q�n�����t���ܤƶq
	}
	else{
		//T3 = sqrt{(2*Vc)/[J3+(J3*J3/J4)]}		
		ud1 = 2*udVc;
		//ud2 = udJ3+((udJ3*udJ3)/udJ4);//����t�q�n�����ɶ� ms// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
		ud2 = udJ3+((udJ3*udJ3+(udJ4>>1))/udJ4);//����t�q�n�����ɶ� ms// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
		
		//ud3 = (UDOUBLE)(10000*ud1)/ud2;	//����t�q�n�����ɶ� ms// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
		ud3 = (UDOUBLE)(10000*ud1+(ud2>>1))/ud2;	//����t�q�n�����ɶ� ms// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
		L1 = (ULONG)ud3;
		DLC_uwT3 = 10*uw_Sqrt32c_1(L1);
		udT3 = (UDOUBLE)DLC_uwT3;
	
		//T4 = T3*J3/J4
		//udT4 = udT3*udJ3/udJ4;	//����t�q�n�����ɶ� ms// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
		udT4 = (udT3*udJ3+(udJ4>>1))/udJ4;	//����t�q�n�����ɶ� ms// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
		DLC_uwT4 = (UWORD)udT4;
		
		//Td = 0
		udTd = 0;
		DLC_uwTd = 0;			////����t�q, ��t�ɶ�
		
		//V3=J3*T3*T3/2
		//udV3 = udJ3*udT3*udT3/2000000;	//����t�q�n�����ɶ� ms// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
		udV3 = (udJ3*udT3*udT3+1000000)/2000000;	//����t�q�n�����ɶ� ms// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
		DLC_uwV3 = (UWORD)udV3;	//�qS3�}�l��S3����,�t�׷|��֦h��,���mm/s
		
		//V4=J4*T4*T4/2
		//udV4 = udJ4*udT4*udT4/2000000;	//����t�q�n�����ɶ� ms// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
		udV4 = (udJ4*udT4*udT4+1000000)/2000000;	//����t�q�n�����ɶ� ms// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
		DLC_uwV4 = (UWORD)udV4;	//S4�}�l�ɪ��t��
		
		//Vd = 0
		udVd = 0;
		DLC_uwVd = 0;
	}	
}

void WelTunProc(void){
	ULONG ulTmp, ulVal;
	UBYTE i, j, k, ErrFlag=0;
	ULONG ulDelayCmpmm, ulDelayCmpPg;
	UDOUBLE	udTmp;
	
	// Reset PG Pulse Matrix
	if(DLC_btWelRst == 1){	
		DLC_uwWelTra = 0x01;
		WelTunReset();
	}
	// PG Pulse Record
	else if(DLC_btWelRec == 1){
		DLC_uwWelTra = 0x02;
		DLC_uwEeprom = 1;
		
		DLC_ulPgUL = DLC_ulPgCnt;
		DLC_ubLevMax = DLC_ubLevCur;
		pr[MAX_FLOOR] = DLC_ubLevMax;
		write_ep(0,MAX_FLOOR,pr[MAX_FLOOR]);
	
	}
	// DIR_UP and do the well-tune
	else{	
		//#16386 optimization for over landing cause from leveling sensor calibration , James, 2021/04/13
		ulDelayCmpmm = DLC_ulCurSpd * (pr[DelayCmp] + pr[DIN_RES]);//pr[DIN_RES];//m/s(dot4)*sec(dot3)-->mm(dot7), 4+3=7	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
		//ulDelayCmpPg = U32xU32divU32(ulDelayCmpmm , 65536, COF_ulPls2MMgain)/250;//mm(dot7)*Q16/gain*Q2/1000 // Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source		
		udTmp = COF_ulPls2MMgain * 250;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
		ulDelayCmpPg = (ULONG)(((UDOUBLE)ulDelayCmpmm * 65536 + (udTmp >> 1)) / udTmp);	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
		if(DLC_ubDIR == DIR_UP){		
			//�Ӽh�ƥ� ���W
			if((DLC_btDznMd == 0 && DLC_btLU == 1 && DLC_btLUOld == 0)||
				 (DLC_btDznMd == 1 && DLC_btDZN == 1 && DLC_btDZNOld == 0))
				DLC_ubLevCur = (DLC_ubLevCur < 0x4B) ? DLC_ubLevCur + 1 : 0x4B;	
			
			if(DLC_btDznMd == 0){           // adco
				if(DLC_ubLevCur == 1){
					//LD, LU PG Pulse
					if(DLC_btLU == 0 && DLC_btLUOld == 1){
						DLC_ulPgSen = DLC_ulPgCnt - ulDelayCmpPg;
					}
					if(DLC_btLD == 0 && DLC_btLDOld == 1){
						DLC_ulPgSen = DLC_ulPgCnt - ulDelayCmpPg - DLC_ulPgSen;
					}

					//�����B�OPG�߽ļ�				
					if(DLC_btLD == 1 && DLC_btLDOld == 0){     //LD into plank
						DLC_ulPgBrd = DLC_ulPgCnt-ulDelayCmpPg;
						DLC_uwWelTra = 0x04;
					}
					else if(DLC_btLD == 0 && DLC_btLDOld == 1){ //LD leave plank
						DLC_ulPgBrd = DLC_ulPgCnt - ulDelayCmpPg- DLC_ulPgBrd;					
						DLC_uwWelTra = 0x05;
					}
					else if(DLC_btLU == 0 && DLC_btLUOld == 1){
						//1F����LU���������B�O����m
						DLC_ulPgLev[DLC_ubLevCur] = DLC_ulPgCnt-ulDelayCmpPg;
						DLC_uwWelTra = 0x06;
					}
				}
				else
				{					
					if(DLC_btLU == 1 && DLC_btLUOld == 0){
						//�]������1F��m���ɭ�, DLC_ulPgSen�|������
						//�]��, �b2F����m��, �h�ץ�1F��m
						if(DLC_ubLevCur == 2)
						{
							//DLC_ulPgLev[1] = DLC_ulPgLev[1]-(DLC_ulPgBrd>>1)+(DLC_ulPgSen>>1)-ulDelayCmpPg;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
							DLC_ulPgLev[1] = DLC_ulPgLev[1] - ((DLC_ulPgBrd - DLC_ulPgSen + 1) >> 1) - ulDelayCmpPg;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
						}
						//DLC_ulPgLev[DLC_ubLevCur] = DLC_ulPgCnt+(DLC_ulPgBrd>>1)+(DLC_ulPgSen>>1)-ulDelayCmpPg;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
						DLC_ulPgLev[DLC_ubLevCur] = DLC_ulPgCnt + ((DLC_ulPgBrd + DLC_ulPgSen + 1) >> 1) - ulDelayCmpPg;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
						DLC_uwWelTra = 0x07;
					}
					else
						DLC_uwWelTra = 0x08;
				}
			}
			else{  // DLC_btDznMd = 1   // adco
				
				DLC_ulPgSen = 0;
				if(DLC_ubLevCur == 1){
					// 1F pos
					//if(DLC_btDZN == 1 && DLC_btDZNOld == 0)
					if(DLC_btDZN == 0 && DLC_btDZNOld == 1){
						DLC_ulPgLev[DLC_ubLevCur] = DLC_ulPgCnt-ulDelayCmpPg;	//aevinpoint
						DLC_uwWelTra = 0x09;
					}
					else
						DLC_uwWelTra = 0x0a;
			  }
			  else{
			  	
					if(DLC_ubLevCur == 2){
						// learn board length
				    if(DLC_btDZN == 1 && DLC_btDZNOld == 0){     //Dzn enter
					    DLC_ulPgBrd = DLC_ulPgCnt - ulDelayCmpPg;
					    DLC_uwWelTra = 0x0b;
				    }
				    else if(DLC_btDZN == 0 && DLC_btDZNOld == 1){ //Dzn leave
					    DLC_ulPgBrd = DLC_ulPgCnt - ulDelayCmpPg - DLC_ulPgBrd;
					    DLC_uwWelTra = 0x0c;

				      // fix 1F, 2F pos
					  //DLC_ulPgLev[1] = DLC_ulPgLev[1]-(DLC_ulPgBrd>>1);	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
					  DLC_ulPgLev[1] = DLC_ulPgLev[1]-((DLC_ulPgBrd+1)>>1);	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
					  //DLC_ulPgLev[2] = DLC_ulPgLev[2]+(DLC_ulPgBrd>>1);	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
					  DLC_ulPgLev[2] = DLC_ulPgLev[2]+((DLC_ulPgBrd+1)>>1);	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new			  
				    }
				  }			  	
			  	
			  	// record each level pos
					if(DLC_btDZN == 1 && DLC_btDZNOld == 0){
						if(DLC_ubLevCur == 2)   // 2F��, DLC_ulPgBrd�|���o��
					    DLC_ulPgLev[DLC_ubLevCur] = DLC_ulPgCnt-ulDelayCmpPg;
					  else
					    //DLC_ulPgLev[DLC_ubLevCur] = DLC_ulPgCnt+(DLC_ulPgBrd>>1)-ulDelayCmpPg;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
					    DLC_ulPgLev[DLC_ubLevCur] = DLC_ulPgCnt+((DLC_ulPgBrd+1)>>1)-ulDelayCmpPg;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
					}
			  }
			}
		}
		else
			DLC_uwWelTra = 0x03;
			
		if(DLC_ubDIR == DIR_UP){
			//DIR_UP, leave DDS
			if((DLC_btDD1Old == 1)&&(DLC_btDD1 == 0))
				DLC_ulPgDD1 = DLC_ulPgCnt;
			if((DLC_btDD2Old == 1)&&(DLC_btDD2 == 0))
				DLC_ulPgDD2 = DLC_ulPgCnt;
			if((DLC_btDD3Old == 1)&&(DLC_btDD3 == 0))
				DLC_ulPgDD3 = DLC_ulPgCnt;
			if((DLC_btDD4Old == 1)&&(DLC_btDD4 == 0))
				DLC_ulPgDD4 = DLC_ulPgCnt;
				
			//DIP_UP, into UDS
			if((DLC_btUD1Old == 0)&&(DLC_btUD1 == 1))
				DLC_ulPgUD1 = DLC_ulPgCnt;
			if((DLC_btUD2Old == 0)&&(DLC_btUD2 == 1))
				DLC_ulPgUD2 = DLC_ulPgCnt;
			if((DLC_btUD3Old == 0)&&(DLC_btUD3 == 1))
				DLC_ulPgUD3 = DLC_ulPgCnt;
			if((DLC_btUD4Old == 0)&&(DLC_btUD4 == 1))
				DLC_ulPgUD4 = DLC_ulPgCnt;
		}
	}
}

void WelTunReset(void){
	UWORD i, j;

	for(i = 0; i <= 0x4B; i ++){
		DLC_ulPgLev[i] = 0;
		DLC_ulPosLev[i] = 0;
		j = i - 1;
		DLCxx[j<<1] = 0;
		DLCxx[((j<<1)+1)] = 0;
		C40xx[j<<1] = 0;
		C40xx[((j<<1)+1)] = 0;
	}

    for(i=FL_POSIT_1H; i<=FL_POSIT_25L; i++) //[GFC FHM EOL issue,Lyabryan,2020/09/15]
  	{
	    pr[i]= 0;
    }
	DLC_ubLevCur = 1;
	DLC_ulPgCnt = PGBS;
	DLC_ulPgLev[0] = DLC_ulPgCnt;
	pr[LEV_BRD_PG_H] = 0;
	pr[LEV_BRD_PG_L] = 0;
	pr[SENSOR_H] = 0;
	pr[SENSOR_L] = 0;
		
	DLC_ulPgDD1 = 0;
	DLC_ulPgDD2 = 0;
	DLC_ulPgDD3 = 0;
	DLC_ulPgDD4 = 0;
	DLC_ulPgUD1 = 0;
	DLC_ulPgUD2 = 0;
	DLC_ulPgUD3 = 0;
	DLC_ulPgUD4 = 0;
	DLC_ulPgUL = 0;
	DLC_ulPosDD1 = 0;
	DLC_ulPosDD2 = 0;
	DLC_ulPosDD3 = 0;
	DLC_ulPosDD4 = 0;
	DLC_ulPosUD1 = 0;
	DLC_ulPosUD2 = 0;
	DLC_ulPosUD3 = 0;
	DLC_ulPosUD4 = 0;
	DLC_ulPosUL = 0;
}

void WelTun_eeprom(void){
	UWORD i, j; //[for loop die because UBYTE,Lyabryan,2020/09/09]
	UWORD uwUD1_Vlim, uwDD1_Vlim, uwUD2_Vlim, uwDD2_Vlim,uwUD3_Vlim, uwDD3_Vlim,uwUD4_Vlim, uwDD4_Vlim;

	// pg pulse to mm
	for(i = 1; i <= 0x4B; i ++){
		//����ഫ-PULSE to mm
		//DLC_ulPosLev[i] = U32xU32divU32((DLC_ulPgLev[i]>>2), COF_ulPls2MMgain, 65536);		// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
		//DLC_ulPosLev[i] = DLC_ulPosLev[i]/10;	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
		DLC_ulPosLev[i] = (ULONG)(((UDOUBLE)DLC_ulPgLev[i] * (UDOUBLE)COF_ulPls2MMgain + 1310720) / 2621440);// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
		
		j = i - 1;
		DLCxx[j<<1] = DLC_ulPosLev[i]/1000; //m
		DLCxx[((j<<1)+1)] = DLC_ulPosLev[i]%1000; //mm
		
	}

	DLC_ulPosDD1 = U32xU32divU32((DLC_ulPgDD1>>2),COF_ulPls2MMgain,65536);
	DLC_ulPosDD1 /= 10; // decel sw position modify, Henry, 2017/05/25
	DLC_ulPosDD2 = U32xU32divU32((DLC_ulPgDD2>>2),COF_ulPls2MMgain,65536);
	DLC_ulPosDD2 /= 10; // decel sw position modify, Henry, 2017/05/25
	DLC_ulPosDD3 = U32xU32divU32((DLC_ulPgDD3>>2),COF_ulPls2MMgain,65536);
	DLC_ulPosDD3 /= 10; // decel sw position modify, Henry, 2017/05/25
	DLC_ulPosDD4 = U32xU32divU32((DLC_ulPgDD4>>2),COF_ulPls2MMgain,65536);
	DLC_ulPosDD4 /= 10; // decel sw position modify, Henry, 2017/05/25
	DLC_ulPosUD1 = U32xU32divU32((DLC_ulPgUD1>>2),COF_ulPls2MMgain,65536);
	DLC_ulPosUD1 /= 10; // decel sw position modify, Henry, 2017/05/25
	DLC_ulPosUD2 = U32xU32divU32((DLC_ulPgUD2>>2),COF_ulPls2MMgain,65536);
	DLC_ulPosUD2 /= 10; // decel sw position modify, Henry, 2017/05/25
	DLC_ulPosUD3 = U32xU32divU32((DLC_ulPgUD3>>2),COF_ulPls2MMgain,65536);
	DLC_ulPosUD3 /= 10; // decel sw position modify, Henry, 2017/05/25
	DLC_ulPosUD4 = U32xU32divU32((DLC_ulPgUD4>>2),COF_ulPls2MMgain,65536);
	DLC_ulPosUD4 /= 10; // decel sw position modify, Henry, 2017/05/25
	DLC_ulPosUL = U32xU32divU32((DLC_ulPgUL>>2),COF_ulPls2MMgain,65536);
	DLC_ulPosUL /= 10;


	DLC_ulPosDD1 = DLC_ulPosDD1>3000000?0:DLC_ulPosDD1;
	DLC_ulPosDD2 = DLC_ulPosDD2>3000000?0:DLC_ulPosDD2;
	DLC_ulPosDD3 = DLC_ulPosDD3>3000000?0:DLC_ulPosDD3;
	DLC_ulPosDD4 = DLC_ulPosDD4>3000000?0:DLC_ulPosDD4;
	DLC_ulPosUD1 = DLC_ulPosUD1>3000000?0:DLC_ulPosUD1;
	DLC_ulPosUD2 = DLC_ulPosUD2>3000000?0:DLC_ulPosUD2;
	DLC_ulPosUD3 = DLC_ulPosUD3>3000000?0:DLC_ulPosUD3;
	DLC_ulPosUD4 = DLC_ulPosUD4>3000000?0:DLC_ulPosUD4;
	DLC_ulPosUL = DLC_ulPosUL>3000000?0:DLC_ulPosUL;	
		
	DLCxx[DD1_H] = DLC_ulPosDD1/1000;
	DLCxx[DD1_L] = DLC_ulPosDD1%1000;
	DLCxx[DD2_H] = DLC_ulPosDD2/1000;
	DLCxx[DD2_L] = DLC_ulPosDD2%1000;
	DLCxx[DD3_H] = DLC_ulPosDD3/1000;
	DLCxx[DD3_L] = DLC_ulPosDD3%1000;
	DLCxx[DD4_H] = DLC_ulPosDD4/1000;
	DLCxx[DD4_L] = DLC_ulPosDD4%1000;
	DLCxx[UD1_H] = DLC_ulPosUD1/1000;
	DLCxx[UD1_L] = DLC_ulPosUD1%1000;
	DLCxx[UD2_H] = DLC_ulPosUD2/1000;
	DLCxx[UD2_L] = DLC_ulPosUD2%1000;
	DLCxx[UD3_H] = DLC_ulPosUD3/1000;
	DLCxx[UD3_L] = DLC_ulPosUD3%1000;
	DLCxx[UD4_H] = DLC_ulPosUD4/1000;
	DLCxx[UD4_L] = DLC_ulPosUD4%1000;
	DLCxx[UL_H] = DLC_ulPosUL/1000;
	DLCxx[UL_L] = DLC_ulPosUL%1000;

	Update_C40xx();
    
    if(pr[FLOOR_PAGE] == 0){
      for(i=0; i<DLC_25ADDR; i++){
        pr[FL_POSIT_1H+i]= DLCxx[i];
      }
    }    
    else if(pr[FLOOR_PAGE] == 1){   // JINGDO   
      for(i=DLC_25ADDR; i<DLC_50ADDR; i++){
        pr[FL_POSIT_1H+i-DLC_25ADDR]= DLCxx[i];
      }
    }
    else if(pr[FLOOR_PAGE] == 2){     // JINGDO
      for(i=DLC_50ADDR; i<DLC_75ADDR; i++){
        pr[FL_POSIT_1H+i-DLC_50ADDR]= DLCxx[i];
      }
    }
    else if(pr[FLOOR_PAGE] == 3){     // floor adjustment Aevin 6/192/2018
        for(i=DLC_75ADDR; i<DLC_LimADDR; i++){
          pr[FL_POSIT_1H+i-DLC_75ADDR]= DLCxx[i];
        }
    }
    else if(pr[FLOOR_PAGE] == 4){     //adjust floor position,Henry,2019/01/07
        for(i=DLC_LimADDR; i<DLC_Adj50ADDRUP; i++){
          pr[FL_POSIT_1H+i-DLC_LimADDR]= DLCxx[i];
        }
    }
    else if(pr[FLOOR_PAGE] == 5){     //adjust floor position,Henry,2019/01/07
        for(i=DLC_Adj50ADDRUP; i<DLC_Adj50ADDRDN; i++){
          pr[FL_POSIT_1H+i-DLC_Adj50ADDRUP]= DLCxx[i];
        }
    }  
    else if(pr[FLOOR_PAGE] == 6){     //adjust floor position,Henry,2019/01/07
        for(i=DLC_Adj50ADDRDN; i<DLC_Adj5175ADDRUPDN; i++){
          pr[FL_POSIT_1H+i-DLC_Adj50ADDRDN]= DLCxx[i];
        }
    }
    
			
	pr[LEV_BRD_PG_H] = DLC_ulPgBrd / 10000;
	pr[LEV_BRD_PG_L] = DLC_ulPgBrd % 10000;
	
	pr[SENSOR_H] = DLC_ulPgSen / 10000;
	pr[SENSOR_L] = DLC_ulPgSen % 10000;
	
	//pr[LEV_LEN] = (U32xU32divU32((DLC_ulPgBrd>>2), COF_ulPls2MMgain, 65536))/10;// vrd length Aevin 7/6/2018	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
	pr[LEV_LEN] = (ULONG)(((UDOUBLE)DLC_ulPgBrd * (UDOUBLE)COF_ulPls2MMgain + 1310720) / 2621440); // Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new
	
	//Artemis speed limit, James, 20200220
	if((DLC_ulPosDD1>DLC_ulPosLev[DLC_ubLevMin])&&(DLC_ulPosDD1 != 0))
		uwDD1_Vlim = uw_Sqrt32c((DLC_ulPosDD1-DLC_ulPosLev[DLC_ubLevMin]) * pr[DECEL1]*2/10)*1.1;
	else
		uwDD1_Vlim = 0;
	if((DLC_ulPosDD2>DLC_ulPosLev[DLC_ubLevMin])&&(DLC_ulPosDD2 != 0))
		uwDD2_Vlim = uw_Sqrt32c((DLC_ulPosDD2-DLC_ulPosLev[DLC_ubLevMin]) * pr[DECEL1]*2/10)*1.1;
	else
		uwDD2_Vlim = 0;
	if((DLC_ulPosDD3>DLC_ulPosLev[DLC_ubLevMin])&&(DLC_ulPosDD3 != 0))
		uwDD3_Vlim = uw_Sqrt32c((DLC_ulPosDD3-DLC_ulPosLev[DLC_ubLevMin]) * pr[DECEL1]*2/10)*1.1;
	else
		uwDD3_Vlim = 0;
	if((DLC_ulPosDD4>DLC_ulPosLev[DLC_ubLevMin])&&(DLC_ulPosDD4 != 0))
		uwDD4_Vlim = uw_Sqrt32c((DLC_ulPosDD4-DLC_ulPosLev[DLC_ubLevMin]) * pr[DECEL1]*2/10)*1.1;
	else
		uwDD4_Vlim = 0;
	
	if((DLC_ulPosLev[pr[MAX_FLOOR]]>DLC_ulPosUD1)&&(DLC_ulPosUD1 != 0))
		uwUD1_Vlim = uw_Sqrt32c((DLC_ulPosLev[pr[MAX_FLOOR]]-DLC_ulPosUD1) * pr[DECEL1]*2/10)*1.1;
	else
		uwUD1_Vlim = 0;
	if((DLC_ulPosLev[pr[MAX_FLOOR]]>DLC_ulPosUD2)&&(DLC_ulPosUD2 != 0))
		uwUD2_Vlim = uw_Sqrt32c((DLC_ulPosLev[pr[MAX_FLOOR]]-DLC_ulPosUD2) * pr[DECEL1]*2/10)*1.1;
	else
		uwUD2_Vlim = 0;
	if((DLC_ulPosLev[pr[MAX_FLOOR]]>DLC_ulPosUD3)&&(DLC_ulPosUD3 != 0))
		uwUD3_Vlim = uw_Sqrt32c((DLC_ulPosLev[pr[MAX_FLOOR]]-DLC_ulPosUD3) * pr[DECEL1]*2/10)*1.1;
	else
		uwUD3_Vlim = 0;
	if((DLC_ulPosLev[pr[MAX_FLOOR]]>DLC_ulPosUD4)&&(DLC_ulPosUD4 != 0))
		uwUD4_Vlim = uw_Sqrt32c((DLC_ulPosLev[pr[MAX_FLOOR]]-DLC_ulPosUD4) * pr[DECEL1]*2/10)*1.1;
	else
		uwUD4_Vlim = 0;
	
	if((uwDD1_Vlim <= pr[Lift_SPD]) && (uwUD1_Vlim <= pr[Lift_SPD]))
	{
		if(uwDD1_Vlim == 0 && uwUD1_Vlim == 0)			
			pr[DD1_Vlim] = pr[Lift_SPD];
		else if(uwDD1_Vlim>uwUD1_Vlim)
			pr[DD1_Vlim] = uwDD1_Vlim;
		else
			pr[DD1_Vlim] = uwUD1_Vlim;
	}
	else		
		pr[DD1_Vlim] = pr[Lift_SPD];
	
	if((uwDD2_Vlim <= pr[Lift_SPD]) && (uwUD2_Vlim <= pr[Lift_SPD]))
	{
		if(uwDD1_Vlim == 0 && uwUD1_Vlim == 0)			
			pr[DD2_Vlim] = pr[Lift_SPD];
		else if(uwDD2_Vlim>uwUD2_Vlim)
			pr[DD2_Vlim] = uwDD2_Vlim;
		else
			pr[DD2_Vlim] = uwUD2_Vlim;
	}
	else		
		pr[DD2_Vlim] = pr[Lift_SPD];
	
	if((uwDD3_Vlim <= pr[Lift_SPD]) && (uwUD3_Vlim <= pr[Lift_SPD]))
	{
		if(uwDD3_Vlim == 0 && uwUD3_Vlim == 0)			
			pr[DD3_Vlim] = pr[Lift_SPD];
		else if(uwDD3_Vlim>uwUD3_Vlim)
			pr[DD3_Vlim] = uwDD3_Vlim;
		else
			pr[DD3_Vlim] = uwUD3_Vlim;
	}
	else		
		pr[DD3_Vlim] = pr[Lift_SPD];
	
	if((uwDD4_Vlim <= pr[Lift_SPD]) && (uwUD4_Vlim <= pr[Lift_SPD]))
	{
		if(uwDD4_Vlim == 0 && uwUD4_Vlim == 0)			
			pr[DD4_Vlim] = pr[Lift_SPD];
		else if(uwDD4_Vlim>uwUD4_Vlim)
			pr[DD4_Vlim] = uwDD4_Vlim;
		else
			pr[DD4_Vlim] = uwUD4_Vlim;
	}
	else		
		pr[DD4_Vlim] = pr[Lift_SPD];
	   
	//write into fram
	//for(i=0; i<64; i++)                               //[mask by Bernie and the code move to frm_vdDLCWrite(); in LV_REC(); ]
         //write_ep(0,FL_POSIT_1H+i,pr[FL_POSIT_1H+i]);    //[mask by Bernie and the code move to frm_vdDLCWrite(); in LV_REC(); ]
//    write_ep(0,DLS_POSIT_H,pr[DLS_POSIT_H]);	
//    write_ep(0,DLS_POSIT_L,pr[DLS_POSIT_L]);	
//    write_ep(0,ULS_POSIT_H,pr[ULS_POSIT_H]);	
//    write_ep(0,ULS_POSIT_L,pr[ULS_POSIT_L]);
  write_ep(0,LEV_BRD_PG_H,pr[LEV_BRD_PG_H]);	
  write_ep(0,LEV_BRD_PG_L,pr[LEV_BRD_PG_L]);	
  write_ep(0,SENSOR_H,pr[SENSOR_H]);	
  write_ep(0,SENSOR_L,pr[SENSOR_L]);
  write_ep(0,CUR_PG_H,pr[CUR_PG_H]);	
  write_ep(0,CUR_PG_L,pr[CUR_PG_L]);
  write_ep(0,DD1_Vlim,pr[DD1_Vlim]);//Artemis speed limit, James, 20200220
  write_ep(0,DD2_Vlim,pr[DD2_Vlim]);
  write_ep(0,DD3_Vlim,pr[DD3_Vlim]);
  write_ep(0,DD4_Vlim,pr[DD4_Vlim]);
	
}

// DLC position offset 2, Henry
void Update_C40xx(void){
	ULONG ultmp, ultmp2;
	UWORD i, j;
	
    //ultmp = U32xU32divU32((PGBS>>2), COF_ulPls2MMgain, 65536);	// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
	//ultmp = ultmp/10;											// Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 source
	ultmp = (ULONG)(((UDOUBLE)PGBS * (UDOUBLE)COF_ulPls2MMgain + 1310720) / 2621440); // Issue 277400 ���t�観����t�Υ��h���Ǫ����D // Mitong 20220902 new

	// DLC position offset, Henry
	for(i = 1; i <= 0x4B; i ++){
		if(DLC_ulPosLev[i]>0){
			ultmp2 = DLC_ulPosLev[i]-ultmp;
			j = i - 1;
			C40xx[j<<1] = ultmp2/1000; //m
			C40xx[((j<<1)+1)] = ultmp2%1000; //mm
		}
		else{
			j = i - 1;
			C40xx[j<<1] = 0;
			C40xx[((j<<1)+1)] = 0;
		}
	}

	
	if(DLC_ulPosDD1>0){
		ultmp2 = DLC_ulPosDD1-ultmp;
		C40xx[DD1_H] = ultmp2/1000;
		C40xx[DD1_L] = ultmp2%1000;
	}
	else{
		C40xx[DD1_H] = 0;
		C40xx[DD1_L] = 0;
	}
	
	if(DLC_ulPosDD2>0){
		ultmp2 = DLC_ulPosDD2-ultmp;
		C40xx[DD2_H] = ultmp2/1000;
		C40xx[DD2_L] = ultmp2%1000;
	}
	else{
		C40xx[DD2_H] = 0;
		C40xx[DD2_L] = 0;
	}

	if(DLC_ulPosDD3>0){
		ultmp2 = DLC_ulPosDD3-ultmp;
		C40xx[DD3_H] = ultmp2/1000;
		C40xx[DD3_L] = ultmp2%1000;
	}
	else{
		C40xx[DD3_H] = 0;
		C40xx[DD3_L] = 0;
	}

	if(DLC_ulPosDD4>0){
		ultmp2 = DLC_ulPosDD4-ultmp;
		C40xx[DD4_H] = ultmp2/1000;
		C40xx[DD4_L] = ultmp2%1000;
	}
	else{
		C40xx[DD4_H] = 0;
		C40xx[DD4_L] = 0;
	}

	if(DLC_ulPosUD1>0){
		ultmp2 = DLC_ulPosUD1-ultmp;
		C40xx[UD1_H] = ultmp2/1000;
		C40xx[UD1_L] = ultmp2%1000;
	}
	else{
		C40xx[UD1_H] = 0;
		C40xx[UD1_L] = 0;
	}
	
	if(DLC_ulPosUD2>0){
		ultmp2 = DLC_ulPosUD2-ultmp;
		C40xx[UD2_H] = ultmp2/1000;
		C40xx[UD2_L] = ultmp2%1000;
	}
	else{
		C40xx[UD2_H] = 0;
		C40xx[UD2_L] = 0;
	}
	
	if(DLC_ulPosUD3>0){
		ultmp2 = DLC_ulPosUD3-ultmp;
		C40xx[UD3_H] = ultmp2/1000;
		C40xx[UD3_L] = ultmp2%1000;
	}
	else{
		C40xx[UD3_H] = 0;
		C40xx[UD3_L] = 0;
	}
	
	if(DLC_ulPosUD4>0){
		ultmp2 = DLC_ulPosUD4-ultmp;
		C40xx[UD4_H] = ultmp2/1000;
		C40xx[UD4_L] = ultmp2%1000;
	}
	else{
		C40xx[UD4_H] = 0;
		C40xx[UD4_L] = 0;
	}
}

void Sensor818_Protect(void)
{
	//if((Error==0) && (WarnCode==0))
	if(Error==0)
	{
		if(DLC_ubDIR == DIR_UP)
		{
			if(DLC_btModNor)
			{
				if(pr[Sensor819]==4) //  DDS + UDS +819_Both
				{	
					if((DLC_btUD1==0) && (DLC_btDD1==0) && (MFI_btSensor819_Both==1))
					{	
						Error = Sensor818_ERR;
					}
					else if((DLC_btUD1==1) && (DLC_btDD1==1) && (MFI_btSensor819_Both==0))
					{	
						Error = Sensor818_ERR;
					}
				}
				/*else if(pr[Sensor819]==3)
				{	
					Error = 0;
				}*/
				else if(pr[Sensor819]==2) // UDS + 819_Button
				{	
					if((DLC_btUD1==1) && (DLC_btDD1==0) && (MFI_btSensor819_Top==0))
					{	
						Error = Sensor818_ERR;
					}
					else if((DLC_btUD1==0) && (DLC_btDD1==0) && (MFI_btSensor819_Top==1))
					{	
						Error = Sensor818_ERR;
					}
					else if((DLC_btUD1==1) && (DLC_btDD1==1) && (MFI_btSensor819_Top==0))
					{	
						Error = Sensor818_ERR;
					}
				}
				/*else if(pr[Sensor819]==0)
				{	
					Error = 0;
				}*/
			}
			else
			{
				if(pr[Sensor819]==4) //  DDS + UDS +819_Both
				{
					if((DLC_btUD1==0) && (DLC_btDD1==0) && (MFI_btSensor819_Both==1))
					{	
						WarnCode = Sensor818_WARN;
					}
					else if((DLC_btUD1==1) && (DLC_btDD1==1) && (MFI_btSensor819_Both==0))
					{	
						WarnCode = Sensor818_WARN;
					}
                    else
					{	
					    if(Sensor818_WARN == WarnCode)
                        {
                            WarnCode = 0;
                        }     
					}
				}
				/*else if(pr[Sensor819]==3)
				{	
					WarnCode = 0;
				}*/	
				else if(pr[Sensor819]==2) // UDS + 819_Button
				{	
					if((DLC_btUD1==1) && (DLC_btDD1==0) && (MFI_btSensor819_Top==0))   //[Rational 332450 Artemis Warn Issue, Jerry.sk.Tseng 2023/03/31]
					{	
						WarnCode = Sensor818_WARN;
					}
					else if((DLC_btUD1==0) && (DLC_btDD1==0) && (MFI_btSensor819_Top==1))
					{	
						WarnCode = Sensor818_WARN;
					}
					else if((DLC_btUD1==1) && (DLC_btDD1==1) && (MFI_btSensor819_Top==0))
					{	
						WarnCode = Sensor818_WARN;
					}
					else
					{	
					    if(Sensor818_WARN == WarnCode)
                        {
                            WarnCode = 0;
                        }     
					}
				}              
				/*else if(pr[Sensor819]==1)
				{	
					WarnCode = 0;
				}*/

			}
		}
		else
		{
			if(WarnCode==Sensor818_WARN)
			{
				WarnCode = 0;
				Keypad_Page = pr[S_DISP];
				Keypad_PageTmp = 0;
			}
		}
	}
}

void Sensor817_Protect(void)
{
	//if((Error==0) && (WarnCode==0))
	if(Error==0)
	{
		if(DLC_ubDIR == DIR_DN)
		{
			if(DLC_btModNor)
			{
				if(pr[Sensor819]==4) //  DDS + UDS +819_Both 
				{	
					if((DLC_btUD1==0) && (DLC_btDD1==0) && (MFI_btSensor819_Both==1))
					{	
						Error = Sensor817_ERR;
					}
					else if((DLC_btUD1==1) && (DLC_btDD1==1) && (MFI_btSensor819_Both==0))
					{	
						Error = Sensor817_ERR;
					}
				}
				else if(pr[Sensor819]==3) // DDS + 819_Button 
				{	
					if((DLC_btUD1==0) && (DLC_btDD1==1) && (MFI_btSensor819_Button==0))
					{	
						Error = Sensor817_ERR;
					}
					else if((DLC_btUD1==0) && (DLC_btDD1==0) && (MFI_btSensor819_Button==1))
					{	
						Error = Sensor817_ERR;
					}
					else if((DLC_btUD1==1) && (DLC_btDD1==1) && (MFI_btSensor819_Button==0))
					{	
						Error = Sensor817_ERR;
					}
				}
				/*else if(pr[Sensor819]==2)
				{	
					Error = 0;
				}
				else if(pr[Sensor819]==1)
				{	
					Error = 0;
				}*/
			}
			else
			{
				if(pr[Sensor819]==4) // UDS + DDS + 819_Both   
				{	
					if((DLC_btUD1==0) && (DLC_btDD1==0) && (MFI_btSensor819_Both==1))
					{	
						WarnCode = Sensor817_WARN;
					}
					else if((DLC_btUD1==1) && (DLC_btDD1==1) && (MFI_btSensor819_Both==0))
					{	
						WarnCode = Sensor817_WARN;
					}
                    else
					{	
					    if(Sensor817_WARN == WarnCode)
                        {
                            WarnCode = 0;
                        }     
					}
				}
				else if(pr[Sensor819]==3)// DDS + 819_Button
				{	
					if((DLC_btUD1==0) && (DLC_btDD1==1) && (MFI_btSensor819_Button==0)) //[Rational 332450 Artemis Warn Issue, Jerry.sk.Tseng 2023/03/31]
					{	
						WarnCode = Sensor817_WARN;
					}
					else if((DLC_btUD1==0) && (DLC_btDD1==0) && (MFI_btSensor819_Button==1))
					{	
						WarnCode = Sensor817_WARN;
					}
					else if((DLC_btUD1==1) && (DLC_btDD1==1) && (MFI_btSensor819_Button==0))
					{	
						WarnCode = Sensor817_WARN;
					}
                    else
					{	
					    if(Sensor817_WARN == WarnCode)
                        {
                            WarnCode = 0;
                        }     
					}
				}
				/*else if(pr[Sensor819]==2)
				{	
					WarnCode = 0;
				}
				else if(pr[Sensor819]==1)
				{	
					WarnCode = 0;
				}*/
			}
			
		}
		else
		{
			if(WarnCode==Sensor817_WARN)
			{
				WarnCode = 0;
				Keypad_Page = pr[S_DISP];
				Keypad_PageTmp = 0;
			}
		}
	}
}

#ifndef _DLC_C
	#undef _DLC_C
#endif
