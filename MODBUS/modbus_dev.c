///  @file   reg_ctrl.c                                                
///  @author OuYang                                             
///  @brief  
///   Draft date:  2010/04/28\n
///   Release date:\n                                           
///   Description :modbus register control and check library\n
///   (c) Copyright 2010 Delta Electronics, Inc.

#include     "modbus_dev.h"
#include     "modbus_dec.h"
#include	 "ProgHeader.h"
#include     "lib_access.h"


#ifndef NULL
#define     NULL     ( void * ) 0U
#endif

//static uint8_t reg_br_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr );
static uint8_t ubErrInfo_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr );
static uint8_t ubWarnInfo_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr );
static uint8_t ubGrpDesc_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr );	// add MODBUS_PARA_GROUP, Sean, 20141225
static uint8_t ubGrpNum_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr );
static uint8_t ubParDesc_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr );


//-----------------aevin add---------------------------------------------------------
static  uint8_t ubC21xx_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr );//6/30/2015	
static  uint8_t ubC22xx_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr );//6/30/2015
static  uint8_t ubC23xx_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr );//6/30/2015
static  uint8_t ubNamePltInfo_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr );//6/30/2015
static  uint8_t ubC20xx_write( uint32_t  addr, uint32_t  count, uint8_t  *ptr );		//7/2/2015
static  uint8_t ubParDesc_write( uint32_t  addr, uint32_t  count, uint8_t  *ptr );		//7/2/2015
static  uint8_t ubC35xx_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr );//7/3/2015
static  uint8_t ubCFFxx_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr );//7/6/2015
static  uint8_t ubCFFxx_write( uint32_t  addr, uint32_t  count, uint8_t  *ptr );//7/6/2015
static  uint8_t ubC_MEMADDR_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr );//7/6/2015


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//mdb_dev_struct detail:
//	uint16_t  type;
//	uint16_t  reserved;
//	uint16_t  addr;
//	uint16_t  max;
//	uint16_t *dev;
//	uint8_t    ( *read )( uint32_t	addr, uint32_t	count, uint8_t	*ptr );
//	uint8_t    ( *write )( uint32_t  addr, uint32_t  count, uint8_t  *ptr );
//	uint8_t    ( *check )( uint32_t  addr, uint32_t  count, uint8_t  *ptr );
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// modbus framework, Sean, 20141225
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Parameter Group 0
//MODBUS_PARA_GROUP imcompatible wif API?
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define GROUP0_SIZE		GROUP1-GROUP0
#define GROUP1_SIZE		GROUP2-GROUP1
#define GROUP2_SIZE		GROUP3-GROUP2
#define GROUP3_SIZE		GROUP4-GROUP3
#define GROUP4_SIZE		GROUP5-GROUP4
#define GROUP5_SIZE		GROUP6-GROUP5
#define GROUP6_SIZE		GROUP7-GROUP6
#define GROUP7_SIZE		GROUP8-GROUP7
#define GROUP8_SIZE		GROUP9-GROUP8
#define GROUP9_SIZE		GROUP10-GROUP9
#define GROUP10_SIZE	GROUP11-GROUP10
#define GROUP11_SIZE	GROUP12-GROUP11
#define GROUP12_SIZE	GROUP13-GROUP12
#define GROUP13_SIZE	GROUP14-GROUP13
#define GROUP14_SIZE	EPMAX-GROUP14
#define GROUP15_SIZE	GROUP0-GROUP15

const struct mdb_dev_struct stPar_Grp_0 = {
	MODBUS_PARA_GROUP,	// add MODBUS_PARA_GROUP, Sean, 20141225
	0,
	0x0000,				//	MODBUS ADDR
	GROUP0_SIZE+DATA_LEN,	//  MAX LENGTH		// MAX_LENGTH modified to pass check, Sean, 20141225
	&pr[GROUP0],		//  MEMORY ADDRESS
	ubParDesc_read,		//  READ FUN
	ubParDesc_write,	// 	WRITE FUNC		//Aevin add--7/2/2015
	NULL,				//  CHK FUNC
};

const struct mdb_dev_struct stPar_Grp_1 = {
	MODBUS_PARA_GROUP,	
	0,
	0x0100,				//	MODBUS ADDR
	GROUP1_SIZE+DATA_LEN,	//  MAX LENGTH
	&pr[GROUP1],		//  MEMORY ADDRESS
	ubParDesc_read,		//  READ FUN
	ubParDesc_write,	// 	WRITE FUNC		//Aevin add--7/2/2015
	NULL,				//  CHK FUNC
};

const struct mdb_dev_struct stPar_Grp_2 = {
	MODBUS_PARA_GROUP,	
	0,
	0x0200,				//	MODBUS ADDR
	GROUP2_SIZE+DATA_LEN,	//  MAX LENGTH
	&pr[GROUP2],		//  MEMORY ADDRESS
	ubParDesc_read,		//  READ FUN
	ubParDesc_write,	// 	WRITE FUNC		//Aevin add--7/2/2015
	NULL,				//  CHK FUNC
};

const struct mdb_dev_struct stPar_Grp_3 = {
	MODBUS_PARA_GROUP,	
	0,
	0x0300,				//	MODBUS ADDR
	GROUP3_SIZE+DATA_LEN,	//  MAX LENGTH
	&pr[GROUP3],		//  MEMORY ADDRESS
	ubParDesc_read,		//  READ FUN
	ubParDesc_write,	// 	WRITE FUNC		//Aevin add--7/2/2015
	NULL,				//  CHK FUNC
};

const struct mdb_dev_struct stPar_Grp_4 = {
	MODBUS_PARA_GROUP,	
	0,
	0x0400,				//	MODBUS ADDR
	GROUP4_SIZE+DATA_LEN,	//  MAX LENGTH
	&pr[GROUP4],		//  MEMORY ADDRESS
	ubParDesc_read,		//  READ FUN
	ubParDesc_write,	// 	WRITE FUNC		//Aevin add--7/2/2015
	NULL,				//  CHK FUNC
};

const struct mdb_dev_struct stPar_Grp_5 = {
	MODBUS_PARA_GROUP,	
	0,
	0x0500,				//	MODBUS ADDR
	GROUP5_SIZE+DATA_LEN,	//  MAX LENGTH
	&pr[GROUP5],		//  MEMORY ADDRESS
	ubParDesc_read,		//  READ FUN
	ubParDesc_write,	// 	WRITE FUNC		//Aevin add--7/2/2015
	NULL,				//  CHK FUNC
};

const struct mdb_dev_struct stPar_Grp_6 = {
	MODBUS_PARA_GROUP,	
	0,
	0x0600,				//	MODBUS ADDR
	GROUP6_SIZE+DATA_LEN,	//  MAX LENGTH
	&pr[GROUP6],		//  MEMORY ADDRESS
	ubParDesc_read,		//  READ FUN
	ubParDesc_write,	// 	WRITE FUNC		//Aevin add--7/2/2015
	NULL,				//  CHK FUNC
};

const struct mdb_dev_struct stPar_Grp_7 = {
	MODBUS_PARA_GROUP,	
	0,
	0x0700,				//	MODBUS ADDR
	GROUP7_SIZE+DATA_LEN,	//  MAX LENGTH
	&pr[GROUP7],		//  MEMORY ADDRESS
	ubParDesc_read,		//  READ FUN
	ubParDesc_write,	// 	WRITE FUNC		//Aevin add--7/2/2015
	NULL,				//  CHK FUNC
};

const struct mdb_dev_struct stPar_Grp_8 = {
	MODBUS_PARA_GROUP,	
	0,
	0x0800,				//	MODBUS ADDR
	GROUP8_SIZE+DATA_LEN,	//  MAX LENGTH
	&pr[GROUP8],		//  MEMORY ADDRESS
	ubParDesc_read,		//  READ FUN
	ubParDesc_write,	// 	WRITE FUNC		//Aevin add--7/2/2015
	NULL,				//  CHK FUNC
};

const struct mdb_dev_struct stPar_Grp_9 = {
	MODBUS_PARA_GROUP,	
	0,
	0x0900,				//	MODBUS ADDR
	GROUP9_SIZE+DATA_LEN,	//  MAX LENGTH
	&pr[GROUP9],		//  MEMORY ADDRESS
	ubParDesc_read,		//  READ FUN
	ubParDesc_write,	// 	WRITE FUNC		//Aevin add--7/2/2015
	NULL,				//  CHK FUNC
};

const struct mdb_dev_struct stPar_Grp_10 = {
	MODBUS_PARA_GROUP,	
	0,
	0x0A00,				//	MODBUS ADDR
	GROUP10_SIZE+DATA_LEN,	//  MAX LENGTH
	&pr[GROUP10],		//  MEMORY ADDRESS
	ubParDesc_read,		//  READ FUN
	ubParDesc_write,	// 	WRITE FUNC		//Aevin add--7/2/2015
	NULL,				//  CHK FUNC
};

const struct mdb_dev_struct stPar_Grp_11 = {
	MODBUS_PARA_GROUP,	
	0,
	0x0B00,				//	MODBUS ADDR
	GROUP11_SIZE+DATA_LEN,	//  MAX LENGTH
	&pr[GROUP11],		//  MEMORY ADDRESS
	ubParDesc_read,		//  READ FUN
	ubParDesc_write,	// 	WRITE FUNC		//Aevin add--7/2/2015
	NULL,				//  CHK FUNC
};

const struct mdb_dev_struct stPar_Grp_12 = {
	MODBUS_PARA_GROUP,	
	0,
	0x0C00,				//	MODBUS ADDR
	GROUP12_SIZE+DATA_LEN,	//  MAX LENGTH
	&pr[GROUP12],		//  MEMORY ADDRESS
	ubParDesc_read,		//  READ FUN
	ubParDesc_write,	// 	WRITE FUNC		//Aevin add--7/2/2015
	NULL,				//  CHK FUNC
};

const struct mdb_dev_struct stPar_Grp_13 = {
	MODBUS_PARA_GROUP,	
	0,
	0x0D00,				//	MODBUS ADDR
	GROUP13_SIZE+DATA_LEN,	//  MAX LENGTH
	&pr[GROUP13],		//  MEMORY ADDRESS
	ubParDesc_read,		//  READ FUN
	ubParDesc_write,	// 	WRITE FUNC		//Aevin add--7/2/2015
	NULL,				//  CHK FUNC
};

const struct mdb_dev_struct stPar_Grp_14 = {
	MODBUS_PARA_GROUP,	
	0,
	0x0E00,				//	MODBUS ADDR
	GROUP14_SIZE+DATA_LEN,	//  MAX LENGTH
	&pr[GROUP14],		//  MEMORY ADDRESS
	ubParDesc_read,		//  READ FUN
	ubParDesc_write,	// 	WRITE FUNC		//Aevin add--7/2/2015
	NULL,				//  CHK FUNC
};

const struct mdb_dev_struct stPar_Grp_15 = {
	MODBUS_PARA_GROUP,	
	0,
	0x0F00,				//	MODBUS ADDR
	GROUP15_SIZE+DATA_LEN,	//  MAX LENGTH
	&pr[GROUP15],		//  MEMORY ADDRESS
	ubParDesc_read,		//  READ FUN	
	ubParDesc_write,	// 	WRITE FUNC		//Aevin add--7/2/2015
	NULL,				//  CHK FUNC
};

const struct mdb_dev_struct stPar_Grp_GpNo = {
	MODBUS_INTERNAL_REGISTER,	
	0,
	0x1000,				//	MODBUS ADDR
	GRALL+1,			//  MAX LENGTH
	//&pr_gpno[0],		//  MEMORY ADDRESS
	NULL,				//  MEMORY ADDRESS--use in read func
	ubGrpNum_read,		//  READ FUNC
	WRITE_fORBIDDEN,	// 	WRITE FUNC
	NULL,				//  CHK FUNC
	GRALL,				//Parameter's number	//Aevin add---7/3/2015
};
//----------C20xx aevin add//6/30/2015-------------
const struct mdb_dev_struct stC20xx = {
	MODBUS_INTERNAL_REGISTER,
	0,		//update function ----aevin add -6/29/2015
	0x2000,				//	MODBUS ADDR
	C20MAX,				//  MAX LENGTH
	&C20xx[0],			//  MEMORY ADDRESS
	NULL,				//  READ FUNC
	ubC20xx_write,		// 	WRITE FUNC		//modi to add C20xx write function---Aevin, 7/2/2015
	NULL,				//  CHK FUNC
	C20MAX,				//Parameter's number	//Aevin add---7/3/2015
};
//-----------------------------------------------

const struct mdb_dev_struct stC21xx = {
	MODBUS_INTERNAL_REGISTER,
	0,		//update function ----aevin add -6/29/2015
	0x2100,				//	MODBUS ADDR
	C21MAX,				//  MAX LENGTH
	&C21xx[0],			//  MEMORY ADDRESS
	ubC21xx_read,		//  READ FUNC			//aevin add 6/30/2015
	WRITE_fORBIDDEN,	// 	WRITE FUNC
	NULL,				//  CHK FUNC
	C21MAX,				//Parameter's number	//Aevin add---7/3/2015
};

const struct mdb_dev_struct stC22xx = {
	MODBUS_INTERNAL_REGISTER,
	0,		//update function ----aevin add -6/29/2015
	0x2200,				//	MODBUS ADDR
	C22MAX,				//  MAX LENGTH
	&C22xx[0],			//  MEMORY ADDRESS
	ubC22xx_read,		//  READ FUNC			//aevin add 6/30/2015
	WRITE_fORBIDDEN,	// 	WRITE FUNC
	NULL,				//  CHK FUNC
	C22MAX,				//Parameter's number	//Aevin add---7/3/2015
};

const struct mdb_dev_struct stC23xx = {
	MODBUS_INTERNAL_REGISTER,
	0,
	0x2300,				//	MODBUS ADDR
	C23MAX,				//  MAX LENGTH
	&KC23xx[0],			//  MEMORY ADDRESS
	ubC23xx_read,		//  READ FUNC			//aevin add 6/30/2015
	WRITE_fORBIDDEN,	// 	WRITE FUNC
	NULL,				//  CHK FUNC
	C23MAX,				//Parameter's number	//Aevin add---7/3/2015
};

const struct mdb_dev_struct stC31xx = {
	MODBUS_INTERNAL_REGISTER,
	0,
	0x3100,				//	MODBUS ADDR
	GRALL+1+20,			//  MAX LENGTH		// MAX_LENGTH modified to pass check, Sean, 20141225
	//&gpname[0],		//  MEMORY ADDRESS
	NULL,				//	MEMORY ADDRESS--use in read func
	ubGrpDesc_read,		//  READ FUNC
	WRITE_fORBIDDEN,	// 	WRITE FUNC
	NULL,				//  CHK FUNC
	GRALL,				//Parameter's number	//Aevin add---7/3/2015
};

const struct mdb_dev_struct stC32xx = {
	MODBUS_INTERNAL_REGISTER,
	0,
	0x3200,				//	MODBUS ADDR
	ERRMAX+20,			//  MAX LENGTH	// MAX_LENGTH modified to pass check, Sean, 20141225
	//&errinfo[0],		//  MEMORY ADDRESS
	NULL,				//	MEMORY ADDRESS--use in read func
	ubErrInfo_read,		//  READ FUNC
	WRITE_fORBIDDEN,	// 	WRITE FUNC
	NULL,				//  CHK FUNC
	ERRMAX,				//Parameter's number	//Aevin add---7/3/2015
};

const struct mdb_dev_struct stC33xx = {
	MODBUS_INTERNAL_REGISTER,
	0,
	0x3300,				//	MODBUS ADDR
	WARNMAX+20,			//  MAX LENGTH	// MAX_LENGTH modified to pass check, Sean, 20141225
	//&warninfo[0],		//  MEMORY ADDRESS
	NULL,				//	MEMORY ADDRESS--use in read func
	ubWarnInfo_read,	//  READ FUNC
	WRITE_fORBIDDEN,	// 	WRITE FUNC
	NULL,				//  CHK FUNC
	(WARNMAX+3),		//Parameter's number	//Aevin add---7/3/2015
};
//-------------for C34xx --------aevin add---6/30/2015-----
const struct mdb_dev_struct stC34xx = {
	MODBUS_INTERNAL_REGISTER,
	0,
	0x3400,				//	MODBUS ADDR
	0xff,			//  MAX LENGTH
	//&ModelinfoSingle[0],//  MEMORY ADDRESS	
	NULL,				//	MEMORY ADDRESS--use in read func
	ubNamePltInfo_read,	//  READ FUNC
	WRITE_fORBIDDEN,	// 	WRITE FUNC
	NULL,				//  CHK FUNC
	0xFF,			//Parameter's number	MAXMODELNO可能會改//Aevin add---7/3/2015
};
//-------------------------------------------------

//-------------for C35xx --------aevin add---7/3/2015-----
const struct mdb_dev_struct stC35xx = {
	MODBUS_INTERNAL_REGISTER,
	0,
	0x3500,				//	MODBUS ADDR
	MFDPAGEMAX+20,		//  MAX LENGTH
	//&sfrinfo[0],		//  MEMORY ADDRESS	
	NULL,				//	MEMORY ADDRESS--use in read func
	ubC35xx_read,		//  READ FUNC
	WRITE_fORBIDDEN,	// 	WRITE FUNC
	NULL,				//  CHK FUNC
	MFDPAGEMAX,			//Parameter's number	//Aevin add---7/3/2015
};
//-------------------------------------------------

//-------------for CFFxx --------aevin add---7/6/2015-----
const struct mdb_dev_struct stCFFxx = {
	MODBUS_INTERNAL_REGISTER,
	0,
	0xFF00,				//	MODBUS ADDR
	//WARNMAX,			//  MAX LENGTH
	DATA_LEN+20,		//  MAX LENGTH
	&CFFxx[0],		//  MEMORY ADDRESS	//this is temp , all will modi in read function-
	ubCFFxx_read,		//  READ FUNC
	ubCFFxx_write,				// 	WRITE FUNC
	NULL,				//  CHK FUNC
	CALIMAX-1,			//Parameter's number	//Aevin add---7/3/2015
};


//-------------for C_MEMADDR --------aevin add---7/6/2015-----
const struct mdb_dev_struct stC_MEMADDR = {
	MODBUS_INTERNAL_REGISTER,
	0,
	0xFF00,				//	MODBUS ADDR , in this dev is useless
	DATA_LEN,		//  MAX LENGTH
	//&MEMADDR[0],		//  MEMORY ADDRESS	
	NULL,				//	MEMORY ADDRESS--use in read func
	ubC_MEMADDR_read,		//  READ FUNC
	WRITE_fORBIDDEN,	// 	WRITE FUNC
	NULL,				//  CHK FUNC
	0xFF,			//Parameter's number	//Aevin add---7/3/2015
};


// Example
//uint16_t br_reg[BR_SIZE];
/*
********************************************************************************************************************
Objective               : Device XXX write Contral 
Description             : Actions and Data Copy for Write Action -- You should edit these functions for your Project
Input                   : addr  address of device
                          value we want to write the value to device 
Output                  : 0(success) 1(fail)  

Development History     : 20100914, 20110121 
@author                 : simon 
@date                   :
@remarks                :

********************************************************************************************************************
*/
/*
static  uint8_t reg_br_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr )
{
    uint16_t i        = addr;
    uint16_t j        = 0;
    uint16_t addr_end = addr + count;


    for( i = addr; i < addr_end; i++ )
    {
        ptr[ j++ ] = ( uint8_t )( br_reg[ i ]>>8 );
        ptr[ j++ ] = ( uint8_t )( br_reg[ i ] & 0x00ffU );
    }
    return ( uint8_t )0U;
}


static  uint8_t reg_br_write( uint32_t  addr, uint32_t  count, uint8_t  *ptr )
{
    uint16_t i        = addr;
    uint16_t j        = 0;
    uint16_t addr_end = addr + count;
    uint16_t tmp16;
    uint16_t read_only = 0;

    for( i = addr; i < addr_end; i++ )
    {
        tmp16             = ( uint16_t )( ptr[ j++ ] );
        tmp16           <<= 8;
        tmp16            += ( uint16_t )( ptr[ j++ ] );
        read_only = 0;
        switch( i )
        {
            case 0:
            case 1:
            case 124:
            case 125:
            case 126: 
            case 127:
                read_only = 1;
                break;
        }
    
        if( read_only == 0)
        {
            br_reg[ i ]   = tmp16;
        }
    }

    return ( uint8_t )0U;
}       


static  uint8_t reg_br_check( uint32_t  addr, uint32_t  count, uint8_t  *ptr )
{
    return 0U;
}


// Example: Data process by user defined
// Modbus Register  
const struct mdb_dev_struct br_ctrl = {
    MODBUS_INTERNAL_REGISTER,
    BR_ADDR,
    0,
    BR_SIZE,
    &br_reg[0],
    reg_br_read,
    reg_br_write,
    reg_br_check
};

*/

/*
// Example: Data process by modbus decode
// Modbus Register
const struct mdb_dev_struct br_ctrl = {
    MODBUS_INTERNAL_REGISTER,
    BR_ADDR,
    0,
    BR_SIZE,
    &br_reg[0],
    NULL,
    NULL,
    NULL,
};

*/

static  uint8_t ubErrInfo_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr )
{
    extern const string20 errinfo[ERRMAX+1];	
	//memcpy(&ptr[0], &errinfo[addr], count);
    if ((C20xx[0x05]&0xff00) == 0x0200)
        #if Language_TC
		memcpy(&ptr[0], &errinfo_tc[addr], count<<1);
        #else
		memcpy(&ptr[0], &errinfo[addr], count<<1);
        #endif
	else if ((C20xx[0x05]&0xff00) == 0x0300)
        #if Language_SC
		memcpy(&ptr[0], &errinfo_sc[addr], count<<1);
        #else
		memcpy(&ptr[0], &errinfo[addr], count<<1);
        #endif
	else
		memcpy(&ptr[0], &errinfo[addr], count<<1);
 
 	if(count == 14){
		ptr[20 + 0] = C21xx[3]>>8;		//get out frq
		ptr[20 + 1] = (uint8_t)C21xx[3];
	
		ptr[20 + 2] = C21xx[4]>>8;		//get out curr
		ptr[20 + 3] = (uint8_t)C21xx[4];
	
		ptr[20 + 4] = C21xx[6]>>8;		//get out vol
		ptr[20 + 5] = (uint8_t)C21xx[6];	
	
		ptr[20 + 6] = C21xx[5]>>8;		//get dcbus
		ptr[20 + 7] = (uint8_t)C21xx[5];
 	}
    return ( uint8_t )0U;
}


static  uint8_t ubWarnInfo_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr )
{
    extern const string20 warninfo[WARNMAX];

	//memcpy(&ptr[0], &warninfo[addr], count);
	if ((C20xx[0x05]&0xff00) == 0x0200)
        #if Language_TC
		memcpy(&ptr[0], &warninfo_tc[addr], count<<1);
        #else
		memcpy(&ptr[0], &warninfo[addr], count<<1);
        #endif
    else if ((C20xx[0x05]&0xff00) == 0x0300)
        #if Language_SC
		memcpy(&ptr[0], &warninfo_sc[addr], count<<1);
        #else
		memcpy(&ptr[0], &warninfo[addr], count<<1);
        #endif
    else
		memcpy(&ptr[0], &warninfo[addr], count<<1);
					
    return ( uint8_t )0U;
}

static  uint8_t ubParDesc_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr )	// add MODBUS_PARA_GROUP, Sean, 20141225
{
	uint8_t language,gpno,ubCHGFlag = 0;
	uint8_t par[40];
	uint16_t addr_hi, addr_lo;
	UWORD_UNION  umap_addr,uwEEPData;
	//extern const PARAM_ATTR attr[];
	extern uint16_t pr[];
#if Language_EN
	extern const string20 prinfo[];
#endif
#if Language_TC
	extern const string20 prinfo_tc[];
#endif
#if Language_SC
	extern const string20 prinfo_sc[];
#endif
	#if SIBO_ENABLE   //[Sibocom Function,Lyabryan,2020/6/15]
	extern const string20 SIBO_GROUP4[],SIBO_INS[];
	#endif
	language = (C20xx[0x05]&0xff00)>>8;
	addr_hi = addr>>8;		// PR. Group
	addr_lo = addr&0x00ff;	// PR. Number
    addr = prtab[addr_hi] + addr_lo;	//=ax

	//group 13 need to indpendent modi ---4/22/2016
	if (addr_hi == MAPGOURP){
		umap_addr.ub.hi = pr[UMAP_ADD0+addr_lo] / 100;
		umap_addr.ub.low = pr[UMAP_ADD0+addr_lo] - umap_addr.ub.hi * 100;
        
        if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
            gpno = pr_gpno_Sibo[umap_addr.ub.hi];
        else
            gpno = pr_gpno[umap_addr.ub.hi];

		// Access to C21xx
		if (umap_addr.ub.hi==21 && umap_addr.ub.low<C21MAX){
			if ( (DispAttr[umap_addr.ub.low].ati&JMP)==JMP && SHOW_ALLPR==0 ){
				addr = Unavaliable;
				umap_addr.ub.hi = 0;
			}
			else
				addr = umap_addr.ub.low;
		}
		// Access to C22xx
		else if (umap_addr.ub.hi==22 && umap_addr.ub.low<C22MAX){
			if ( (DispAttr[(umap_addr.ub.low+C21MAX-1)].ati&JMP)==JMP && SHOW_ALLPR==0 ){ // Modify by DINO, 09/08/2008
				addr = Unavaliable;
				umap_addr.ub.hi = 0;
			}
			else
				addr = umap_addr.ub.low;
		}
		// Access to user parameter
		else if ((umap_addr.ub.hi<=ACCESS  || SHOW_ALLPR==1) && umap_addr.ub.low<gpno){
			addr = (UWORD)prtab[umap_addr.ub.hi] + umap_addr.ub.low;	   // pr index //
		}
		// Access to unavailable address
		else{
            //[Remove DateCode unavaliable, Jason, 2018/11/15]
            if(umap_addr.ub.hi == 15 && umap_addr.ub.low == 61)
            {
                addr = (UWORD)prtab[umap_addr.ub.hi] + umap_addr.ub.low;
            }
            else if(umap_addr.ub.hi == 15 && umap_addr.ub.low == 78)
            {
                //[BootLoader Version, Special.Kung, 2022/10/31]
                addr = (UWORD)prtab[umap_addr.ub.hi] + umap_addr.ub.low;
            }
            else if(umap_addr.ub.hi == 15 && umap_addr.ub.low == 83)
            {
                //[BootLoader DataCode, Special.Kung, 2022/10/31]
                addr = (UWORD)prtab[umap_addr.ub.hi] + umap_addr.ub.low;
            }
            else
            {
                umap_addr.ub.hi = 0;
                addr = Unavaliable;   // Unavailable parameter, display "Unavailable"
            }
		}
		// Access to C21xx
		if (umap_addr.ub.hi == 21){
			u16u8bcpy(&par[0], &C21xx[addr], 1);
			//Data Max
		    uwEEPData.uw = 0xffff;
	   		u16u8bcpy(&par[2], &uwEEPData.uw, 1);

	   		//Data Min
	   		uwEEPData.uw = 0x0000;
	   		u16u8bcpy(&par[4], &uwEEPData.uw, 1);

		    //Data attribute
	   		uwEEPData.uw = DispAttr[addr].ati;
	   		u16u8bcpy(&par[6], &uwEEPData.uw, 1);

	   		//Data default
	   		uwEEPData.uw = 0x0000;
	   		u16u8bcpy(&par[8], &uwEEPData.uw, 1);

	   		//Data Description
	   		memcpy(&par[10], &c21info[addr], 20);	
	   		// [ Velocity Unit Change, Add by DINO, 05/25/2009
	   		if ((DispAttr[addr].ati&CHG) == CHG)
		   		ubCHGFlag = 1;
	   		
		}
		// Access to C22xx
		else if (umap_addr.ub.hi == 22){
			u16u8bcpy(&par[0], &C22xx[addr], 1);
			//Data Max
	   		uwEEPData.uw = 0xffff;
	   		u16u8bcpy(&par[2], &uwEEPData.uw, 1);

	   		//Data Min
	   		uwEEPData.uw = 0x0000;
	   		u16u8bcpy(&par[4], &uwEEPData.uw, 1);

		    //Data attribute
	   		uwEEPData.uw = DispAttr_c22xx[addr].ati;
	   		u16u8bcpy(&par[6], &uwEEPData.uw, 1);

		    //Data default	
	   		uwEEPData.uw = 0x0000;
	   		u16u8bcpy(&par[8], &uwEEPData.uw, 1);

		    //Data Description
		    memcpy(&par[10], &c22info[addr], 20);	
	   		// [ Velocity Unit Change, Add by DINO, 05/25/2009
	   		if ((DispAttr[addr].ati&CHG) == CHG)
		    	ubCHGFlag = 1;
	   		
		}
		// Access to User Parameter
		else{
			if ((addr>=BKTRANS1)&&(addr<=BKTRANS10)){
				addr = BLKTransferRead(addr);
				u16u8bcpy(&par[0], &addr, 1);
			}
			else
				u16u8bcpy(&par[0], &pr[addr], 2);
			
			uwEEPData.uw = GetParMax(addr);
			u16u8bcpy(&par[2], &uwEEPData.uw, 1);

			uwEEPData.uw = GetParMin(addr);
			u16u8bcpy(&par[4], &uwEEPData.uw, 1);

			uwEEPData.uw = GetParAttr(addr);
			u16u8bcpy(&par[6], &uwEEPData.uw, 1);

			if ((pr[HPSPEC]&VFD440V)==VFD220V){    // 220V class
				if ( (attr[addr].ati&V440)==V440 )
					uwEEPData.uw = attr[addr].def>>1;
				else
					uwEEPData.uw = attr[addr].def;
			}
			else
				uwEEPData.uw = attr[addr].def;
			
			u16u8bcpy(&par[8], &uwEEPData.uw, 1);

		
			//add to fix DLC read bug-----4/22/2016
    		switch (language){
                
#if Language_TC
    		case 2:
    			if((addr < DLC_PR) || (addr >= GROUP5) || (pr[FLOOR_PAGE]==0))
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15] 
                        if((addr>=FMI0)&&(addr<=FMI15))
                            memcpy(&par[10], &SIBO_GROUP4[addr-FMI0], 20);
                        else if((addr==STO_LOCK)||(addr==FLAND))
                            memcpy(&par[10], &prinfo_tc[ACI_SL], 20);
                        else if((addr>=JOGACC)&&(addr<=JOGF))
                            memcpy(&par[10], &SIBO_INS[addr-JOGACC], 20);
                        else
                            memcpy(&par[10], &prinfo_tc[addr], 20);
#else
					memcpy(&par[10], &prinfo_tc[addr], 20);
#endif
                
				else {
                    if(pr[FLOOR_PAGE]==1)
                        memcpy(&par[10], &prinfo_tc_DLC[addr-DLC_PR], 20);
                    else if(pr[FLOOR_PAGE]==2)
                        memcpy(&par[10], &prinfo_tc_DLC2[addr-DLC_PR], 20);
                    else if(pr[FLOOR_PAGE]==3)
                        memcpy(&par[10], &prinfo_tc_DLC3[addr-DLC_PR], 20);
                    else if(pr[FLOOR_PAGE]==4)
                        memcpy(&par[10], &prinfo_DLC_tc_Adjst[addr-DLC_PR], 20);
                    else if(pr[FLOOR_PAGE]==5)
                        memcpy(&par[10], &prinfo_DLC_tc_Adjst2[addr-DLC_PR], 20);
                    else if(pr[FLOOR_PAGE]==6)
                        memcpy(&par[10], &prinfo_DLC_tc_Adjst3[addr-DLC_PR], 20);
                }
				
				break;
#endif

#if Language_SC
    		case 3:
    			if((addr < DLC_PR) || (addr >= GROUP5) || (pr[FLOOR_PAGE]==0))
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15] 
                        if((addr>=FMI0)&&(addr<=FMI15))
                            memcpy(&par[10], &SIBO_GROUP4[addr-FMI0], 20);
                        else if((addr==STO_LOCK)||(addr==FLAND))
                            memcpy(&par[10], &prinfo_sc[ACI_SL], 20);
                        else if((addr>=JOGACC)&&(addr<=JOGF))
                            memcpy(&par[10], &SIBO_INS[addr-JOGACC], 20);
                        else
                            memcpy(&par[10], &prinfo_sc[addr], 20);
#else
					memcpy(&par[10], &prinfo_sc[addr], 20);
#endif				
				else {
                    if(pr[FLOOR_PAGE]==1)
                        memcpy(&par[10], &prinfo_sc_DLC[addr-DLC_PR], 20);
                    else if(pr[FLOOR_PAGE]==2)
                        memcpy(&par[10], &prinfo_sc_DLC2[addr-DLC_PR], 20);
                    else if(pr[FLOOR_PAGE]==3)
                        memcpy(&par[10], &prinfo_sc_DLC3[addr-DLC_PR], 20);
                    else if(pr[FLOOR_PAGE]==4)
                        memcpy(&par[10], &prinfo_DLC_sc_Adjst[addr-DLC_PR], 20);
                    else if(pr[FLOOR_PAGE]==5)
                        memcpy(&par[10], &prinfo_DLC_sc_Adjst2[addr-DLC_PR], 20);
                    else if(pr[FLOOR_PAGE]==6)
                        memcpy(&par[10], &prinfo_DLC_sc_Adjst3[addr-DLC_PR], 20);
                }

				break;
#endif
    		default:
    			if((addr < DLC_PR) || (addr >= GROUP5) || (pr[FLOOR_PAGE]==0))
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15] 
                        if((addr>=FMI0)&&(addr<=FMI15))
                            memcpy(&par[10], &SIBO_GROUP4[addr-FMI0], 20);
                        else if((addr==STO_LOCK)||(addr==FLAND))
                            memcpy(&par[10], &prinfo[ACI_SL], 20);
                        else if((addr>=JOGACC)&&(addr<=JOGF))
                            memcpy(&par[10], &SIBO_INS[addr-JOGACC], 20);
                        else
                            memcpy(&par[10], &prinfo[addr], 20);
#else
          			memcpy(&par[10], &prinfo[addr], 20);
#endif            	
            	else {
                    if(pr[FLOOR_PAGE]==1)
                        memcpy(&par[10], &prinfo_DLC[addr-DLC_PR], 20);
                    else if(pr[FLOOR_PAGE]==2)
                        memcpy(&par[10], &prinfo_DLC2[addr-DLC_PR], 20);
                    else if(pr[FLOOR_PAGE]==3)
                        memcpy(&par[10], &prinfo_DLC3[addr-DLC_PR], 20);
                    else if(pr[FLOOR_PAGE]==4)
                        memcpy(&par[10], &prinfo_DLC_Adjst[addr-DLC_PR], 20);
                    else if(pr[FLOOR_PAGE]==5)
                        memcpy(&par[10], &prinfo_DLC_Adjst2[addr-DLC_PR], 20);
                    else if(pr[FLOOR_PAGE]==6)
                        memcpy(&par[10], &prinfo_DLC_Adjst3[addr-DLC_PR], 20);
                }
       
    			break;
    		}	

			if((pr[SOFC]<3) && (pr[UNITSEL]<3)){				 //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
				if ((attr[addr].ati&CHG) == CHG)
					ubCHGFlag = 1;
				
			}
			else{												  //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
				if(((pr[SOFC]==4)||(pr[SOFC]==5))&&(pr[UNITSEL]==3)){	 
					if((addr == ACCEL1)||(addr == DECEL1)||
			   	   	   (addr == JOGACC)||(addr == JOGDEC)||
			      	   (addr == JOGF)  ||(addr == DECEL5)){
						ubCHGFlag = 1;
					}
				}
			}
		}

	}
	
	//normal  group0~12 except 13
	else{//for normal para read
	//-----modi to use this---4/18/2016
		uwEEPData.uw = GetParData(addr);
		u16u8bcpy(&par[0], &uwEEPData.uw, 1);
		
		uwEEPData.uw = GetParMax(addr);
		u16u8bcpy(&par[2], &uwEEPData.uw, 1);

		uwEEPData.uw = GetParMin(addr);
		u16u8bcpy(&par[4], &uwEEPData.uw, 1);

		uwEEPData.uw = GetParAttr(addr);
		u16u8bcpy(&par[6], &uwEEPData.uw, 1);

		if ((pr[HPSPEC]&VFD440V)==VFD220V){    // 220V class
			if ( (attr[addr].ati&V440)==V440 )
				uwEEPData.uw = attr[addr].def>>1;
			else
				uwEEPData.uw = attr[addr].def;
		}
		else
			uwEEPData.uw = attr[addr].def;
		
		u16u8bcpy(&par[8], &uwEEPData.uw, 1);

		//u16u8bcpy(&par[0], &pr[addr], 2);
		//u16u8bcpy(&par[2], &attr[addr].max, 2);
		//u16u8bcpy(&par[4], &attr[addr].min, 2);
		//u16u8bcpy(&par[6], &attr[addr].ati, 2);
		//u16u8bcpy(&par[8], &attr[addr].def, 2);

		//add to fix DLC read bug-----4/22/2016
    	switch (language){
#if Language_TC
    	case 2:
    		//memcpy(&par[10], &prinfo_tc[addr], 20);	//the original one
			if((addr < DLC_PR) || (addr >= GROUP5) || (pr[FLOOR_PAGE]==0))
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15] 
                    if((addr>=FMI0)&&(addr<=FMI15))
                        memcpy(&par[10], &SIBO_GROUP4[addr-FMI0], 20);
                    else if((addr==STO_LOCK)||(addr==FLAND))
                        memcpy(&par[10], &prinfo_tc[ACI_SL], 20);
                    else if((addr>=JOGACC)&&(addr<=JOGF))
                        memcpy(&par[10], &SIBO_INS[addr-JOGACC], 20);
                    else
                        memcpy(&par[10], &prinfo_tc[addr], 20);
#else
				memcpy(&par[10], &prinfo_tc[addr], 20);
#endif			
			else {
                if(pr[FLOOR_PAGE]==1)
                    memcpy(&par[10], &prinfo_tc_DLC[addr-DLC_PR], 20);
                else if(pr[FLOOR_PAGE]==2)
                    memcpy(&par[10], &prinfo_tc_DLC2[addr-DLC_PR], 20);
                else if(pr[FLOOR_PAGE]==3)
                    memcpy(&par[10], &prinfo_tc_DLC3[addr-DLC_PR], 20);
                else if(pr[FLOOR_PAGE]==4)
                    memcpy(&par[10], &prinfo_DLC_tc_Adjst[addr-DLC_PR], 20);
                else if(pr[FLOOR_PAGE]==5)
                    memcpy(&par[10], &prinfo_DLC_tc_Adjst2[addr-DLC_PR], 20);
                else if(pr[FLOOR_PAGE]==6)
                    memcpy(&par[10], &prinfo_DLC_tc_Adjst3[addr-DLC_PR], 20);
                

            }
				
			
			break;
#endif

#if Language_SC
    	case 3:
    		//memcpy(&par[10], &prinfo_sc[addr], 20);
			if((addr < DLC_PR) || (addr >= GROUP5) || (pr[FLOOR_PAGE]==0))
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15] 
                    if((addr>=FMI0)&&(addr<=FMI15))
                        memcpy(&par[10], &SIBO_GROUP4[addr-FMI0], 20);
                    else if((addr==STO_LOCK)||(addr==FLAND))
                        memcpy(&par[10], &prinfo_sc[ACI_SL], 20);
                    else if((addr>=JOGACC)&&(addr<=JOGF))
                        memcpy(&par[10], &SIBO_INS[addr-JOGACC], 20);
                    else                        
					    memcpy(&par[10], &prinfo_sc[addr], 20);
#else
				memcpy(&par[10], &prinfo_sc[addr], 20);
#endif			
			else {
                if(pr[FLOOR_PAGE]==1)
                    memcpy(&par[10], &prinfo_sc_DLC[addr-DLC_PR], 20);
                else if(pr[FLOOR_PAGE]==2)
                    memcpy(&par[10], &prinfo_sc_DLC2[addr-DLC_PR], 20);
                else if(pr[FLOOR_PAGE]==3)
                    memcpy(&par[10], &prinfo_sc_DLC3[addr-DLC_PR], 20);
                else if(pr[FLOOR_PAGE]==4)
                    memcpy(&par[10], &prinfo_DLC_sc_Adjst[addr-DLC_PR], 20);
                else if(pr[FLOOR_PAGE]==5)
                    memcpy(&par[10], &prinfo_DLC_sc_Adjst2[addr-DLC_PR], 20);
                else if(pr[FLOOR_PAGE]==6)
                    memcpy(&par[10], &prinfo_DLC_sc_Adjst3[addr-DLC_PR], 20);

            }
			
			break;
#endif
    	default:
    		//memcpy(&par[10], &prinfo[addr], 20);	
			if((addr < DLC_PR) || (addr >= GROUP5) || (pr[FLOOR_PAGE]==0))
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15] 
                    if((addr>=FMI0)&&(addr<=FMI15))
                        memcpy(&par[10], &SIBO_GROUP4[addr-FMI0], 20);
                    else if((addr==STO_LOCK)||(addr==FLAND))
                        memcpy(&par[10], &prinfo[ACI_SL], 20);
                    else if((addr>=JOGACC)&&(addr<=JOGF))
                        memcpy(&par[10], &SIBO_INS[addr-JOGACC], 20);
                    else
                        memcpy(&par[10], &prinfo[addr], 20);
#else
          		memcpy(&par[10], &prinfo[addr], 20);
#endif            
            else {
                if(pr[FLOOR_PAGE]==1)
                    memcpy(&par[10], &prinfo_DLC[addr-DLC_PR], 20);
                else if(pr[FLOOR_PAGE]==2)
                    memcpy(&par[10], &prinfo_DLC2[addr-DLC_PR], 20);
                else if(pr[FLOOR_PAGE]==3)
                    memcpy(&par[10], &prinfo_DLC3[addr-DLC_PR], 20);
                else if(pr[FLOOR_PAGE]==4)
                    memcpy(&par[10], &prinfo_DLC_Adjst[addr-DLC_PR], 20);
                else if(pr[FLOOR_PAGE]==5)
                    memcpy(&par[10], &prinfo_DLC_Adjst2[addr-DLC_PR], 20);
                else if(pr[FLOOR_PAGE]==6)
                    memcpy(&par[10], &prinfo_DLC_Adjst3[addr-DLC_PR], 20);
            }
    		
    		break;
    	}	

		if((pr[SOFC]<3) && (pr[UNITSEL]<3)){				 //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
			if ((attr[addr].ati&CHG) == CHG)
				ubCHGFlag = 1;
			
		}
		else{												  //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
			if(((pr[SOFC]==4)||(pr[SOFC]==5))&&(pr[UNITSEL]==3)){	 
				if((addr == ACCEL1)||(addr == DECEL1)||
			   	   (addr == JOGACC)||(addr == JOGDEC)||
			       (addr == JOGF)  ||(addr == DECEL5)){
					ubCHGFlag = 1;
				}
			}
		}
	}

	if (ubCHGFlag == 1){
		if (pr[UNITSEL] == 1){
            if((addr == ACCEL1) || (addr == DECEL1) || (addr == ACCEL2)      // m/s2
            || (addr == DECEL2) || (addr == ACCEL3) || (addr == DECEL3)
            || (addr == ACCEL4) || (addr == DECEL4) || (addr == JOGACC)
            || (addr == JOGDEC) || (addr == DECEL5)
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]	 		
			|| (addr == SIBO_DECEMY)
#endif			
			){
			par[10+16] = 'm';
			par[10+17] = '/';
			par[10+18] = 's';
			par[10+19] = '2';
            }
            else if((addr == S4ACC1) || (addr == S4ACC2) || (addr == S4DEC1) // m/s3
    				|| (addr == S4DEC2) || (addr == S4DEC3)
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
					|| (addr == SIBO_S3EMY)|| (addr == SIBO_S4EMY)
#endif
					){
                par[10+16] = 'm';
                par[10+17] = '/';
                par[10+18] = 's';
                par[10+19] = '3';
            }
            else{
                par[10+16] = 'm';
                par[10+17] = '/';
                par[10+18] = 's';
                par[10+19] = ' ';
            }
		}
		else if (pr[UNITSEL] == 2){
            if((addr == ACCEL1) || (addr == DECEL1) || (addr == ACCEL2)      // m/s2
            || (addr == DECEL2) || (addr == ACCEL3) || (addr == DECEL3)
            || (addr == ACCEL4) || (addr == DECEL4) || (addr == JOGACC)
            || (addr == JOGDEC) || (addr == DECEL5)
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]	 		
			|| (addr == SIBO_DECEMY)
#endif
			){
			par[10+16] = 'f';
                par[10+17] = '/';
                par[10+18] = 't';
                par[10+19] = '2';
            }
            else if((addr == S4ACC1) || (addr == S4ACC2) || (addr == S4DEC1) // m/s3
    				|| (addr == S4DEC2) || (addr == S4DEC3)
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]					
					|| (addr == SIBO_S3EMY)|| (addr == SIBO_S4EMY)
#endif
					){
                par[10+16] = 'f';
                par[10+17] = '/';
                par[10+18] = 't';
                par[10+19] = '3';
            }
            else{
                par[10+16] = 'f';
			par[10+17] = 't';
			par[10+18] = '/';
			par[10+19] = 's';
            }
		}
		else if (pr[UNITSEL] == 3){ 			//[parameter in keypad, Bernie, 2015/09/02 ]
			par[10+16] = 'm';
			par[10+17] = '/';
			par[10+18] = 's';
			par[10+19] = '2';
		}
	}	
	
    memset(&par[30],0,10);
	memcpy(&ptr[0], &par[0], count<<1);
	
    return ( uint8_t )0U;
}

//--------------for parameter 06 function write---------Aevin---7/2/2015
static  uint8_t ubParDesc_write( uint32_t  addr, uint32_t  count, uint8_t  *ptr )
{
	//addr =RxBuf_2[2] , RxBuf_2[3]
	//*ptr = RxBuf_2[4]
	//*(ptr+1) = RxBuf_2[5]
	
	UWORD_UNION rxdata, umap_addr;
	UWORD ax, MaxTemp, MinTemp , i;
	UBYTE addrLo , addrHi,gpno;

	for(i = 0;i < count ; i++){


		addrLo = (addr+i) & 0x00FF;	//=RxBuf_2[3]
		addrHi = (UBYTE)(((addr+i) & 0xFF00)>>8);
	 	// function NO. //
        if ((PUON2LINE==1)/*||(RxBuf_2[0]==0xFF)*/)
        {  
            KEYPAD_CMD = 1;  
        }
        else
        {  
            KEYPAD_CMD = 0;
        }
	 
#if ACCESS_GROUP
	 	if (/*RxBuf_2[2]*/addrHi == MAPGOURP)
        {
       		umap_addr.ub.hi = pr[UMAP_ADD0+(addrLo+i)/*RxBuf_2[3]*/] / 100;
        	umap_addr.ub.low = pr[UMAP_ADD0+(addrLo+i)/*RxBuf_2[3]*/] - umap_addr.ub.hi * 100;
        	// [ Mapping to hidden parameters, DINO, 12/23/2009

            if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
            {
                gpno = pr_gpno_Sibo[umap_addr.ub.hi];
            }
            else
            {
                gpno = pr_gpno[umap_addr.ub.hi];
            }

            
        	//if ( (umap_addr.ub.hi<=ACCESS || SHOW_ALLPR==1) && umap_addr.ub.low<pr_gpno[umap_addr.ub.hi] )
            if ( (umap_addr.ub.hi<=ACCESS || SHOW_ALLPR==1) && umap_addr.ub.low<gpno)
            {
                ax = (UWORD)prtab[umap_addr.ub.hi] + umap_addr.ub.low;     // pr index //
            }
            else
            {   
                ax = Unavaliable;	// Unavailable parameter, display "Unavailable"
            }
		}
		else
#endif
        {
            //ax = (UWORD)prtab[RxBuf_2[2]]+RxBuf_2[3];     // pr index //
            ax = (UWORD)prtab[addrHi] + addrLo;     // pr index //---Aevin modi  7/2/2015
        }

      //  TxCntTemp = Rx2CNT;
        rxdata.ub.hi =  *(ptr + (i<<1))/*RxBuf_2[4]*/;
        rxdata.ub.low = *(ptr + (i<<1)+ 1) /*RxBuf_2[5]*/;
                
		MaxTemp = GetParMax(ax);
        MinTemp = GetParMin(ax);


		if ((attr[ax].ati&SIGN)!=0)
        {
            if (((SWORD)rxdata.uw<=(SWORD)MaxTemp)&&((SWORD)rxdata.uw>=(SWORD)MinTemp))
            {      
                write_pr(ax,rxdata.uw);
            }
            else
            {
                //SCOTTY ADD 08/31/2007
                KEYEND = ERR;				//SCOTTY ADD 08/31/2007
            }
    	}
        else
        {
            if ((rxdata.uw<=MaxTemp)&&(rxdata.uw>=MinTemp))
            {
                write_pr(ax,rxdata.uw); 
            }
            else
            {
                //SCOTTY ADD 08/31/2007
                KEYEND = ERR;    	        //SCOTTY ADD 08/31/2007
            }
        }                
        if (KEYEND==ERR)
        {
            COM2Err = PC_CE02;
        }
	}
    KEYPAD_CMD = 0;         
            
	return ( uint8_t )0U;
}

static  uint8_t ubGrpNum_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr )	// add MODBUS_PARA_GROUP, Sean, 20141225
{
	uint16_t	tmp[GRALL+1];
	uint8_t		cnt;
	
	extern const uint16_t pr_gpno[];
	extern const uint16_t pr_gpno_Sibo[];
    
    if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
    	memcpy(&tmp[0], &pr_gpno_Sibo[addr], count<<1);
    else
    	memcpy(&tmp[0], &pr_gpno[addr], count<<1);
	cnt = count;

	do{
		tmp[--cnt]-=1;
	}while(cnt!=0);
	
	u16u8bcpy(&ptr[0], &tmp[0], count);
	
    return ( uint8_t )0U;
}

static  uint8_t ubGrpDesc_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr )	// add MODBUS_PARA_GROUP, Sean, 20141225
{
    uint8_t	 language;
    
    extern uint16_t	C20xx[];
    extern const string20 gpname_tc[],gpname_sc[],gpname[];

    language = (C20xx[0x05]&0xff00)>>8;
    addr &= 0x00ff;
    
    switch (language){
        #if Language_TC
    	case 2:
    		memcpy(&ptr[0], &gpname_tc[addr], count<<1);
    		break;
        #endif
        #if Language_SC
    	case 3:
    		memcpy(&ptr[0], &gpname_sc[addr], count<<1);
    		break;
        #endif
    	default:
    		memcpy(&ptr[0], &gpname[addr], count<<1);
    		break;
    }
	
    return ( uint8_t )0U;
}

//-----------------C21xx read function6/30/2015---------------------
static  uint8_t ubC21xx_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr )	
{
    extern uint16_t	C21xx[];
    Update_C21xx();
	u16u8bcpy( ptr, &C21xx[addr], count);

    return ( uint8_t )0U;
}
//-----------------C22xx read function6/30/2015---------------------
static  uint8_t ubC22xx_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr )	
{
    extern uint16_t	C22xx[];
    Update_C22xx();
	u16u8bcpy( ptr, &C22xx[addr], count);

    return ( uint8_t )0U;
}

//-----------------C22xx read function6/30/2015---------------------
static  uint8_t ubC23xx_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr )	
{
    extern uint16_t	KC23xx[];
    Update_KeypadDisp();
	u16u8bcpy( ptr, &KC23xx[addr], count);

    return ( uint8_t )0U;
}
//----------------for C34xx--------- 6/30/2015
static  uint8_t ubNamePltInfo_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr )
{
    extern const string20 ModelinfoSingle[MAXMODELNO];
	extern const string20 Modelinfo[MAXMODELNO];
    UBYTE HPSPEC_temp;

    HPSPEC_temp = addr;
	//---for  if = 0xff ,then show absolute msg
	if(addr == 0xff){
		memcpy(&ptr[0], &Modelinfo[pr[HPSPEC]], count<<1);
	}
	
    if(addr>VFD_SINGLEPHASE)      //[Single phase input, Bernie, 01/19/2012]
        HPSPEC_temp -= VFD_SINGLEPHASE;

    
    if (HPSPEC_temp<=MAXMODELNO){           //[Single phase input, Bernie, 01/19/2012]
	   if (count<=DESMAX){                

             if(addr>VFD_SINGLEPHASE){          //[Single phase input, Bernie, 01/19/2012]
             	  memcpy(&ptr[0], &ModelinfoSingle[addr-VFD_SINGLEPHASE], count<<1);	

             }
             else{
			 	  memcpy(&ptr[0], &Modelinfo[addr], count<<1);
             }    
       }
       else
             COM2Err = PC_CE03;			
	}
	else
    {   
        COM2Err = PC_CE02;
    }
	
    return ( uint8_t )0U;
}

//-----for C20xx write function----------7/2/2015
static  uint8_t ubC20xx_write( uint32_t  addr, uint32_t  count, uint8_t  *ptr )
{
	uint16_t value, i ;

    //[JES SE1_ERR, Rational 282940, Special.Kung, 2022/08/24]
    COPYFLAG = 1;
    
	for(i = 0 ; i <count;i++ ){
		value  = get_u16b( (ptr + (i<<1))  );
		addr = addr & 0x00ff;
		addr += i;
		Keypad_20xxH(addr,value);
	}
	return ( uint8_t )0U;
}
//------for C35xx read function-----7/3/2015
static  uint8_t ubC35xx_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr )
{
	//extern const string20 sfrinfo_vel_sel[2];
	extern const string20 sfrinfo[(MFDPAGEMAX+1)];
	
	addr &= 0x00ff;
	
	if (addr == 2){
		if (pr[UNITSEL] == 1){
			memcpy(&ptr[0], &sfrinfo_vel_sel[0], count<<1);
		}
		else if (pr[UNITSEL] == 2){
			memcpy(&ptr[0], &sfrinfo_vel_sel[1], count<<1);
		}
		else{
			memcpy(&ptr[0], &sfrinfo[addr], count<<1);
		}
	}
	else{
		memcpy(&ptr[0], &sfrinfo[addr], count<<1);
	}
	
	return ( uint8_t )0U;
}



//------for CFFxx read function-----7/6/2015
static  uint8_t ubCFFxx_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr )
{
	extern uint16_t CFFxx[];

 	if(SHOW_ALLPR==1){ //FF - 00 -00
	     u16u8bcpy( ptr, &CFFxx[addr], count);
 	}
	 else
    	COM2Err = PC_CE03;
	
	return ( uint8_t )0U;
}

//-----for CFFxx write function----------7/6/2015
static  uint8_t ubCFFxx_write( uint32_t  addr, uint32_t  count, uint8_t  *ptr )
{
	//addr =RxBuf_2[2] , RxBuf_2[3]
	//*ptr = RxBuf_2[4]
	//*(ptr+1) = RxBuf_2[5]
	uint16_t value;
	UBYTE addrLo = addr & 0x00FF;				//=RxBuf_2[3]
	
	value  = get_u16b( ptr );

#if !SH7286 //Sean, 01/25/2010    
	
	if ((addrLo==0||addrLo==CFFxx[0]) && (SHOW_ALLPR==1)){

		if (addrLo==0)
			CFFxx[0] = value;
		else
			FFcalibration(addrLo,value);
		}
	else
		COM2Err = PC_CE04;
			
#else    
#if SH7147  /* dino, 05/08/2007 */		
		if ((addrLo==0||addrLo==CFFxx[0]) && (SHOW_ALLPR==1)){

			if (addrLo==0)
				CFFxx[0] = value;
			else
				FFcalibration(addrLo,value);
		}
		else
			COM2Err = PC_CE04;	
#endif
#endif
	
	return ( uint8_t )0U;
}


//------for C_MEMADDR read function-----7/6/2015
static  uint8_t ubC_MEMADDR_read( uint32_t  addr, uint32_t  count, uint8_t  *ptr )
{
	//extern uint16_t MEMADDR[];
	
	//this addr include rbuf[2] and  rbuf[3] , it's a UWORD length 
	u16u8bcpy( ptr, &MEMADDR[addr], count);
 		
	return ( uint8_t )0U;
}


//static  uint8_t reg_br_write( uint32_t  addr, uint32_t  count, uint8_t  *ptr )
//{
//    uint16_t i        = addr;
//    uint16_t j        = 0;
//    uint16_t addr_end = addr + count;
//    uint16_t tmp16;
//    uint16_t read_only = 0;
//
//    for( i = addr; i < addr_end; i++ )
//    {
//        tmp16             = ( uint16_t )( ptr[ j++ ] );
//        tmp16           <<= 8;
//        tmp16            += ( uint16_t )( ptr[ j++ ] );
//        read_only = 0;
//        switch( i )
//        {
//            case 0:
//            case 1:
//            case 124:
//            case 125:
//            case 126: 
//            case 127:
//                read_only = 1;
//                break;
//        }
//    
//        if( read_only == 0)
//        {
//            br_reg[ i ]   = tmp16;
//        }
//    }
//
//    return ( uint8_t )0U;
//}       



