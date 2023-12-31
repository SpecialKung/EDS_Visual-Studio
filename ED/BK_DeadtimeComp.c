/***********************************************************************/
/*                                                                     */
/*  FILE        :hwsetup.c                                             */
/*  DATE        :Fri, Aug 12, 2005                                     */
/*  DESCRIPTION :Hardware Setup file                                   */
/*  CPU TYPE    :SH7149                                                */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.0).     */
/*                                                                     */
/***********************************************************************/
#ifndef  _DEADTIME_C
    #define  _DEADTIME_C
#endif

#include "ProgHeader.h"

#include "PR_SinTable.h"

void DBC_COEFInit(void)
{
	//Deadband compensation coef
  #if 0
	if((pr[HPSPEC]&VFD440V)==VFD220V) {
		if((pr[CTRLM]==VF)||(pr[CTRLM]==VFPG)||(pr[AUTO_T]!=0)) {
		    DBCDu = pr[DBC1]>>4;
		    DBCDt = pr[DBC2]>>4;
		}
		else {
		    DBCDu = 77;
		    DBCDt = 15;
		}
	}
	else {
		if((pr[CTRLM]==VF)||(pr[CTRLM]==VFPG)||(pr[AUTO_T]!=0)) {
		    DBCDu = pr[DBC1]>>4;
		    DBCDt = pr[DBC2]>>4;
	}
	else {
	    	DBCDu = 58;
	    	DBCDt = 12;
		}
	}
  #else
    DBCDu = pr[DBC1]>>4;
	DBCDt = pr[DBC2]>>4;
  #endif
	
    //---- beginning of varibles Initialization of deadtime compensation ---//	
	UaDBC = 0;
	UbDBC = 0;
	UcDBC = 0;
	
	DBC_swAtemp = 0;
	DBC_swBtemp = 0;
	DBC_swCtemp = 0;
	
	DBC_ATmCNT = 0;
	DBC_BTmCNT = 0;
	DBC_CTmCNT = 0;

    DBC_uwIaCnt = 0;
    DBC_uwIbCnt = 0;
    DBC_uwIcCnt = 0;
    
    DBC_ATm = 0;
    DBC_BTm = 0;
    DBC_CTm = 0;
    
    CLorOP = 0;		//ADDED BY SCOTTY 2007/07/17
    //------ end of varibles Initialization of deadtime compensation -------//
    
}


void DBC_Open(void)
{
	UWORD uw_dbwtemp;

#if SCOTTY	
	if (CRM_swThetaStep>0)
		DBC_swSTEPANGLE = CRM_swThetaStep;
	else
		DBC_swSTEPANGLE = -CRM_swThetaStep;	
#else
	 DBC_swSTEPANGLE = CRM_swThetaStep;
#endif 
		
    DBheight = (SWORD)(DBCDu + DBCDt);

    //----------phase A Dead Time Compensation (start) ---------------------//    
	if (AD_swIAPu < (-pr[DBLEAD])){
	    // negative Ia, AD_swIAPu is Lower than (-pr[DBLEAD])
		DBC_swAtemp = (SWORD)(DBheight);

		DBC_ATmCNT = DBC_ATmCNT + DBC_swSTEPANGLE;	
		
		if (DBC_ATmCNT > phase30)
		    DBC_uwIaCnt = 0;
	}
	else if (AD_swIAPu > (pr[DBLEAD])){
	    // positive Ia, AD_swIAPu is Higher than (+pr[DBLEAD])
		DBC_swAtemp = (SWORD)(-DBheight);

		DBC_ATmCNT = DBC_ATmCNT + DBC_swSTEPANGLE;
		
		if (DBC_ATmCNT > phase30)
		    DBC_uwIaCnt = 0;
	}
	else{
	    DBC_ATmCNT = 0;
	    if (DBC_uwIaCnt < 50000){ 
			DBC_uwIaCnt = DBC_uwIaCnt + DBC_swSTEPANGLE;
		}

	    if (CRM_SinSection>=3){
	    	//positive Ia
	    	if (pr[DBRATIO]==0)
	        	DBC_swAtemp = (SWORD)(-DBheight);
	    	else{
	        	DBC_swAtemp = DBheight - (SWORD)(((ULONG)DBC_uwIaCnt * pr[DBRATIO]) >> 16);
	        	if (DBC_swAtemp < (SWORD)(-DBheight))
	            	DBC_swAtemp = (SWORD)(-DBheight);
	    	}
	    }
	    else{
	    	//negative Ia
	    	if (pr[DBRATIO]==0)
	        	DBC_swAtemp = (SWORD)(DBheight);
	    	else{
	        	DBC_swAtemp = (SWORD)(((ULONG)DBC_uwIaCnt * pr[DBRATIO]) >> 16)  - DBheight;
	        	if (DBC_swAtemp > (SWORD)(DBheight))
	            	DBC_swAtemp = (SWORD)(DBheight);
	    	}
	    }
	}
	//----------phase A Dead Time Compensation (end) -----------------------//
	
	//----------phase B Dead Time Compensation (start) ---------------------//
	if (AD_swIBPu < (-pr[DBLEAD])){
	    // negative Ib, AD_swIBPu is Lower than (-pr[DBLEAD])
		DBC_swBtemp = (SWORD)(DBheight);
		
		DBC_BTmCNT = DBC_BTmCNT + DBC_swSTEPANGLE;
		
		if (DBC_BTmCNT > phase30)
		    DBC_uwIbCnt = 0;
	}
	else if (AD_swIBPu > (pr[DBLEAD])){
	    // positive Ib, AD_swIBPu is Higher than (+pr[DBLEAD])
		DBC_swBtemp = (SWORD)(-DBheight);

		DBC_BTmCNT = DBC_BTmCNT + DBC_swSTEPANGLE;

		if (DBC_BTmCNT > phase30)
		    DBC_uwIbCnt = 0;
	}
	else {
	    DBC_BTmCNT = 0;
	    if (DBC_uwIbCnt < 50000){ 
			DBC_uwIbCnt = DBC_uwIbCnt + DBC_swSTEPANGLE;	
		}		

	    	if ((CRM_SinSection==5)||(CRM_SinSection<=1)){
	    		//positive Ib
	    		if (pr[DBRATIO]==0)
	    	    	DBC_swBtemp = (SWORD)(-DBheight);
	    		else{
	    	    	DBC_swBtemp = DBheight - (SWORD)(((ULONG)DBC_uwIbCnt * pr[DBRATIO]) >> 16);
	    	    	if (DBC_swBtemp < (SWORD)(-DBheight))
	    	        DBC_swBtemp = (SWORD)(-DBheight);	    	    	    	        
	    		}
	    	}
	    	else {
	        	//negative Ib
	       		if (pr[DBRATIO]==0)
	    	    	DBC_swBtemp = (SWORD)(DBheight);
	    		else{
	    	    	DBC_swBtemp = (SWORD)(((ULONG)DBC_uwIbCnt * pr[DBRATIO]) >> 16)  - DBheight;
	    	    	if (DBC_swBtemp > DBheight)
	    	        	DBC_swBtemp = (SWORD)(DBheight);
	    		}
	    	}	
  
	}
	//----------phase B Dead Time Compensation (end) -----------------------//
	
	//----------phase C Dead Time Compensation (start) ---------------------//
	if (AD_swICPu < (-pr[DBLEAD])){
	    // negative Ic, AD_swICPu is Lower than (-pr[DBLEAD])
		DBC_swCtemp = (SWORD)(DBheight);
		
		DBC_CTmCNT = DBC_CTmCNT + DBC_swSTEPANGLE;
			
		if (DBC_CTmCNT > phase30)
		    DBC_uwIcCnt = 0;
	}
	else if (AD_swICPu > (pr[DBLEAD])){
	    // positive Ic, AD_swICPu is Higher than (+pr[DBLEAD])
		DBC_swCtemp = (SWORD)(-DBheight);
		DBC_CTmCNT = DBC_CTmCNT + DBC_swSTEPANGLE;	
		
		if (DBC_CTmCNT > phase30)
		    DBC_uwIcCnt = 0;
	}
	else{
	    DBC_CTmCNT = 0;
	    if (DBC_uwIcCnt < 50000){ 
			DBC_uwIcCnt = DBC_uwIcCnt + DBC_swSTEPANGLE;		
		}

	    	if ((CRM_SinSection>=1)&&(CRM_SinSection<=3)){
	    		//positive Ic
	    		if (pr[DBRATIO]==0)
	    		    DBC_swCtemp = (SWORD)(-DBheight);
	    		else{
	    		    DBC_swCtemp = DBheight - (SWORD)(((ULONG)DBC_uwIcCnt * pr[DBRATIO]) >> 16);
	    		    if (DBC_swCtemp < (SWORD)(-DBheight))
	    		        DBC_swCtemp = (SWORD)(-DBheight);
	    		}
	    	}
	    	else {
	    	    //negative Ic
	    	    if (pr[DBRATIO]==0)
	    		    DBC_swCtemp = (SWORD)(DBheight);
	    		else{
	    		    DBC_swCtemp = (SWORD)(((ULONG)DBC_uwIcCnt * pr[DBRATIO]) >> 16)  - DBheight;
	    		    if (DBC_swCtemp > DBheight)
	    		        DBC_swCtemp = (SWORD)(DBheight);
	    		}
	    	}	    
	}
	//----------phase C Dead Time Compensation (end) -----------------------//	
	
}

const UWORD DBC_Tbl[9] = {
    0,  10000,  20000,  30000,  40000,  50000,  60000,  65535,
};


void DBC_Close(void)
{
    SWORD swIAPuTmp,swIBPuTmp,swICPuTmp;
    UWORD uwTun;
    
    DBheight = (SWORD)(DBCDu + DBCDt);
	uwTun = pr[AUTO_T] + pr[PM_AUTO_T];

    CurSyn2Stat_e2s(CRM_swIqPu,CRM_swIdPu);
    Curdq2abc(swIqssPu,swIdssPu);

/*--- ADD FOCPM 01/29/2007	---*/
    if (((pr[CTRLM]==FOCPG)||(pr[CTRLM]==TQCPG)||(pr[CTRLM]==FOCPM))){
        swIAPuTmp = swIasRefPu;
        swIBPuTmp = swIbsRefPu;
        swICPuTmp = swIcsRefPu;
    }
    else{
       	swIAPuTmp = AD_swIAPu;
       	swIBPuTmp = AD_swIBPu;
       	swICPuTmp = AD_swICPu;
    }
    
    if (uwTun !=0 ){
    	if ( pr[PM_AUTO_T]!=3 ){  // Add by DINO, 08/13/2008
       		swIAPuTmp = AD_swIAPu;
       		swIBPuTmp = AD_swIBPu;
       		swICPuTmp = AD_swICPu;
    	}
    }
/*--- END FOCPM 01/29/2007	--*/  

	//----------phase A Dead Time Compensation (start) ---------------------//    
	if (swIAPuTmp < (-pr[DBLEAD2])){
	    // negative Ia, AD_swIAPu is Lower than (-pr[DBLEAD])
		DBC_swAtemp = (SWORD)(DBheight);
	}
	else if (swIAPuTmp > (pr[DBLEAD2])){
	    // positive Ia, AD_swIAPu is Higher than (+pr[DBLEAD])
		DBC_swAtemp = (SWORD)(-DBheight);
	}
	else {
        if ((pr[DBC_MODE]&0x0001)==0x0001){
            DBC_swAtemp = ((ULONG)DBC_Tbl[((ULONG)abs(swIAPuTmp)<<3)/pr[DBLEAD2]]*DBheight)>>16;
            if (swIAPuTmp >= 0)
                DBC_swAtemp = - DBC_swAtemp;
            else
                DBC_swAtemp =  DBC_swAtemp;    
        }
        else{
    	    DBC_swAtemp = ((long)(-swIAPuTmp)*(SWORD)pr[DBRATIO2]) >> 16;		//Q16
// [ Decrease 100us time, Modify by DINO, 03/06/2009
	        if (DBC_swAtemp > DBheight){
				DBC_swAtemp = DBheight;
			}
			else if (-DBC_swAtemp > DBheight){
				DBC_swAtemp = -DBheight;
	        }
/* Original Program
	        if (abs(DBC_swAtemp) > DBheight) {
		        if (DBC_swAtemp > 0)
			        DBC_swAtemp = DBheight;
		        else	
			        DBC_swAtemp = -DBheight;
	        }
*/
// End 03/06/2009 ]
	    }
	}
	//----------phase A Dead Time Compensation (end) -----------------------//
	
	//----------phase B Dead Time Compensation (start) ---------------------//
	if (swIBPuTmp < (-pr[DBLEAD2])){
	    // negative Ib, AD_swIBPu is Lower than (-pr[DBLEAD])
		DBC_swBtemp = (SWORD)(DBheight);
	}
	else if (swIBPuTmp > (pr[DBLEAD2])){
	    // positive Ib, AD_swIBPu is Higher than (+pr[DBLEAD])
		DBC_swBtemp = (SWORD)(-DBheight);
	}
	else {
        if ((pr[DBC_MODE]&0x0001)==0x0001){
            DBC_swBtemp = ((ULONG)DBC_Tbl[((ULONG)abs(swIBPuTmp)<<3)/pr[DBLEAD2]]*DBheight)>>16;
            if (swIBPuTmp >= 0)
            DBC_swBtemp = - DBC_swBtemp;
            else
            DBC_swBtemp =  DBC_swBtemp;    
        }
        else{    
	        DBC_swBtemp = ((long)(-swIBPuTmp)*(SWORD)pr[DBRATIO2]) >> 16;		//Q16
// [ Decrease 100us time, Modify by DINO, 03/06/2009
	        if (DBC_swBtemp > DBheight){
				DBC_swBtemp = DBheight;
			}
			else if (-DBC_swBtemp > DBheight){
				DBC_swBtemp = -DBheight;
	        }
/* Original Program
	        if (abs(DBC_swBtemp) > DBheight) {
		        if (DBC_swBtemp > 0)	
    			    DBC_swBtemp = DBheight;
	    	    else	
		    	    DBC_swBtemp = -DBheight;
	        }    
*/
// End 03/06/2009]
	    }    
	}
	//----------phase B Dead Time Compensation (end) -----------------------//
	
	//----------phase C Dead Time Compensation (start) ---------------------//
	if (swICPuTmp < (-pr[DBLEAD2])){
	    // negative Ic, AD_swICPu is Lower than (-pr[DBLEAD])
		DBC_swCtemp = (SWORD)(DBheight);
	}
	else if (swICPuTmp > (pr[DBLEAD2])){
	    // positive Ic, AD_swICPu is Higher than (+pr[DBLEAD])
		DBC_swCtemp = (SWORD)(-DBheight);
	}
	else {
        if ((pr[DBC_MODE]&0x0001)==0x0001){
            DBC_swCtemp = ((ULONG)DBC_Tbl[((ULONG)abs(swICPuTmp)<<3)/pr[DBLEAD2]]*DBheight)>>16;
            if (swICPuTmp >= 0)
                DBC_swCtemp = - DBC_swCtemp;
            else
                DBC_swCtemp =  DBC_swCtemp;    
        }
        else{
	        DBC_swCtemp = ((long)(-swICPuTmp)*(SWORD)pr[DBRATIO2]) >> 16;		//Q16
// [ Decrease 100us time, Modify by DINO, 03/06/2009
	        if (DBC_swCtemp > DBheight){
				DBC_swCtemp = DBheight;
			}
			else if (-DBC_swCtemp > DBheight){
				DBC_swCtemp = -DBheight;
	        }
/* Original Program
	        if (abs(DBC_swCtemp) > DBheight) {
		        if (DBC_swCtemp > 0)	
    			    DBC_swCtemp = DBheight;
	    	    else	
		    	    DBC_swCtemp = -DBheight;
		    }	    
*/
// End 03/06/2009 ]
		}
	}
	//----------phase C Dead Time Compensation (end) -----------------------//	

}

void DBCValue(void)
{
// [ Decrease 100us time, Add by DINO, 03/06/2009
	UWORD uwTun;

	uwTun = pr[AUTO_T] + pr[PM_AUTO_T];
// ]

	if (RUNNING==RUN){	
	    if (uwTun != 0) {
	        DBC_Close();
		}
	    else{
		    switch(pr[CTRLM]){
			    case VF:
			    case VFPG:
			    case SVC:
#if SCOTTY	//ADD  SCOTTY 2007/07/17
			        if (fout.uw.hi>=(pr[DBCCHG_F]+ 200))
			            CLorOP = 1;
			        else if (fout.uw.hi<=(pr[DBCCHG_F]))
			            CLorOP = 0;
			            
			        if (CLorOP || RUNDCI){  // DINO, 05/07/2010
			        	DBC_Close();
                    }    
			        else{
			        	DBC_Open();
                    }
			        break;
#else
			        if (fout.uw.hi>=pr[DBCCHG_F])
			            DBC_Close();
			        else
			            DBC_Open();
			        break;
#endif 
			    case FOC:
			    case FOCPG:
			    case TQCPG:
#if SCOTTY	//ADDED 01/29/2007
				case FOCPM:
#endif 			    
			        DBC_Close();
			        break;
			    default:
			        break;
		    }
	    }
	}

	if ((pr[SysControl]&0x0008)==0 || uwTun!=0){ //System Control bit3 (Dead time Compensation Disable)
		// [ Disable Deadtime Compensation, Added by Sampo ,05/12/2009
		if (STtune || TUN_SS || MPHL_DET){
			UaDBC = 0;
			UbDBC = 0;
			UcDBC = 0;		
		}
		// ]
		else{
			UaDBC = -DBC_swAtemp;
			UbDBC = -DBC_swBtemp;
			UcDBC = -DBC_swCtemp;
		}
	}
	else{
		UaDBC = 0;
		UbDBC = 0;
		UcDBC = 0;		
	}
}

#ifdef  _DEADTIME_C
    #undef  _DEADTIME_C
#endif

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
