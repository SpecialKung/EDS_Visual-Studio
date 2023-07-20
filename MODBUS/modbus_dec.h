/*  
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
@Copyright (c)			: Delta Electronic Inc. 2011
@Module Name			: Modbus Decode 
@Objective				:
@Description			: Modbus decode function library
@Domain					: [Public/Private]
@Input					: Modbus Request and request length, not include Slave ID 
@Output					: Modbus Response and replay length, not include Slave ID

@Development History	:  
@author					:  Kevin 
@date					:  2011/07/08
@remarks				: 

Notes					:  1. Provide Modbus Function Code 0x01, 0x02, 0x03, 0x04, x05
							  0x06, 0x0f, 0x10, 0x17

						   2. Abbreviation :
							  mdb	 : Modbus
							  dec	 : Decode
							  func	 : Function 
							  dev	 : Device	 
							  reg	 : register 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/


 

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Manual -- Add your device
// steps
// 1. Definition the MODBUS_DEVICE_MAX
//		Ex. #define MODBUS_DEVICE_MAX		 (16) // 16 Modbus Device
// 2. Edit device_check(), device_write(), and device_read() function in modbus_dev.c
//		Ex. void reg_br_read(uint16_t addr, uint16_t count, uint8_t * ptr)
//			{
//				uint16-t i;
//				for( i = 0; i < count; i++) {
//					ptr[ i * 2 ] = (uint8_t)(G_Reg.BR[ addr + i ] >> 8);
//					ptr[ i * 2 + 1] = (uint8_t)(G_Reg.BR[ addr + i ] &0x00FF);
//				}
//				return 0;
//			}
// 3. Edit void modbus_device_init(void) in modbus_dec_usr.c
//		Ex. mdb_dev_add( &br_ctrl );


// Manual -- Add your function Code -- only User defined function code need 
// steps
// 1. Definition the MDB_FUNCTION_MAX
//		Ex. #define MDB_FUNCTION_MAX		(16) // 16 Function Code 
// 2. Edit device_check(), and device_contral() function in reg_ctrl.c
//		Ex. uint16_t void mdbdec_68_private_read(uint8_t *cmd, uint16_t len);
// 3. Edit void modbus_device_init(void)
//		Ex. mdb_func_code_add( 0x68, mdbdec_68_private_read );

// Manual -- Settting support Modbus Function Code
// setps
// 1. Set Function Code Enable in modbus_dec.h
//    Ex. #define  	MDOBUS_FUNCTION_CODE_01_ENABLE	   1
// 2. Definition the MDB_FUNCTION_MAX
//		Ex. #define MDB_FUNCTION_MAX		(16) // 16 Function Code  
// 3. Initial the device during system boot
// Ex. modbus_decode_init();


// Manual -- using the Modbus Decode
// steps
// 1. Initial the device during system boot
//		Ex. modbus_device_init();
// 2. Check Slave ID by yourself
// 3. Call modbus_decode(), and get reply length and message
//		Ex. reply_length = modbus_decode( &net_app_data[7], net_app_data[5] - 1U) + 1U;
//			net_app_data[5] = reply_length;  	// command length of Modbus cmd
//			reply_length += 6U;  				 // add the Modbus TCP header len
//			net_send(net_app_data, reply_length);




#ifndef _MODBUS_DEC_H_
#define	_MODBUS_DEC_H_

#include	 "stdint.h"
#include	 "modbus_type.h"

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// User Configuration 
// Function Code Enable
#define  	MDOBUS_FUNCTION_CODE_01_ENABLE	   0
#define  	MDOBUS_FUNCTION_CODE_02_ENABLE	   0
#define  	MDOBUS_FUNCTION_CODE_03_ENABLE	   1
#define  	MDOBUS_FUNCTION_CODE_04_ENABLE	   0
#define  	MDOBUS_FUNCTION_CODE_05_ENABLE	   0
#define  	MDOBUS_FUNCTION_CODE_06_ENABLE	   1
#define		MDOBUS_FUNCTION_CODE_08_ENABLE	   1	// modbus_decode_init() not handle yet	// modbus framework, Sean, 20141225
#define  	MDOBUS_FUNCTION_CODE_0F_ENABLE	   0
#define  	MDOBUS_FUNCTION_CODE_10_ENABLE	   1
#define  	MDOBUS_FUNCTION_CODE_17_ENABLE	   0

// Buffer size 
#define  	MODBUS_BUFFER_SIZE				   ( 256U )  								  //< include Slave address, Function Code, Data, CRC >  						  
#define  	MODBUS_REGISTER_READ_MAX		   ( ( MODBUS_BUFFER_SIZE - 6 ) / 2 )		  //< (0x007DU) >																  
#define  	MODBUS_REGISTER_WRITE_MAX		   ( MODBUS_REGISTER_READ_MAX - 2 )  		  //< (0x007BU) >																  
#define  	MODBUS_BIT_READ_MAX  			   ( MODBUS_REGISTER_READ_MAX * 16 )		  //< (0x07D0U) >																  
#define  	MODBUS_BIT_WRITE_MAX			   ( MODBUS_REGISTER_WRITE_MAX * 16 )		  //< (0x07B0U) >																  

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Modbus device data module

// Devices Type MAX Define -- You should edit this part for your project
#define  	MODBUS_DEVICE_MAX				   ( 64U )
// Function Code MAX Define -- You should edit this part for your project
#define  	MODBUS_FUNCTION_MAX  			   ( 20U )//aevin modi from 9 to 20--11/25/2015
// ACTIVE
// 03, 06, 08, 10, 63
// USER
// 71, 72, 74, 75
// LIBRARY: NOT USED
// 01, 02, 03, 04, 05, 
// 06, 0f, 10, 17, 67, 
// 68, 69, 6a, 6b, 42


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*    
    type	  Type of the Device that you want to add to 
    addr	  Modbus Address of the Devices 
    max		  Size of devices
    dev		  Pointer to the array of begin of the device. 
    		  If you pass a NULL to dev, the read and write function can not be set as NULL.  
    read	  Pointer to register read event function -- see example in modbus_dev.c
    write  	  Pointer to register write event function -- see example in modbus_dev.c
    Check  	  Pointer to register writeable check function -- see example in modbus_dev.c
*/
struct	mdb_dev_struct
{
	uint16_t  type;
	uint16_t  reserved;
	//uint16_t  ( *update )( uint32_t	addr, uint32_t	count, uint8_t	*ptr );
    uint16_t  addr;
	uint16_t  max;
	uint16_t *dev;
	uint8_t    ( *read )( uint32_t	addr, uint32_t	count, uint8_t	*ptr );
	uint8_t    ( *write )( uint32_t  addr, uint32_t  count, uint8_t  *ptr );
	uint8_t    ( *check )( uint32_t  addr, uint32_t  count, uint8_t  *ptr );
	uint8_t	  paranumber;	//Aevin add to store the every group's parameter number---this is for "MODBUS_INTERNAL_REGISTER"----7/3/2015 
} ;


struct	mdb_func_struct
{
	uint16_t code;
	uint16_t reserved;
	uint16_t  ( *func )( uint8_t  *cmd, uint16_t  len );
} ;

/*
**************************************************************************************************************************************************************************
Objective				: Initial the modbus decode system, include Default function Call and 
						  User Devices 
Description				: 
Input					: void 
Output					: 0    Success
						  1    Failure 

Development History 	:
@author					: Kevin Tseng
@date					: 2010/07/08
@remarks				: 1. User can add your Modbus devices in this function.
						  2. Call this function before decoding any Modbus Command.   
						  3. You should edit this function for your Project. 

**************************************************************************************************************************************************************************
*/
extern	uint16_t modbus_decode_init( void );

//#define 	WRITE_fORBIDDEN		1		//this is for devices , that isnt allow to write------7/6/2015
extern  uint8_t WRITE_fORBIDDEN( uint32_t  addr, uint32_t  count, uint8_t  *ptr );


/*
**************************************************************************************************************************************************************************
Objective				: Modbus Command Decode
Description				: 
Input					: cmd		  pointer to command, include funtion code, not include Slave ID
						  len		  length of the command, not include Slave ID  
Output					: Length of Modbus Reply, Reply message in cmd  

Development History 	:
@author					: Kevin
@date					: 2011/07/08
@remarks				:

**************************************************************************************************************************************************************************
*/
extern	uint16_t modbus_decode( uint8_t  *cmd, uint8_t	len );




// API for user add new funcion code and device

/*
**************************************************************************************************************************************************************************
Objective				: add a Modbus Device to the Modbus decoder system
Description  			: 
Input					: device_ctrl    The control information of this device -- see example in modbus_dev.c 
Output					: 0  		  Success
						  1  		  Failure	 -- MODBUS_DEVICE_MAX should be increased 

Development History  	: 
@author  				: Kevin, Simon 
@date					: 2011/07/08
@remarks				: 

**************************************************************************************************************************************************************************
*/
uint8_t mdb_dev_add( const struct mdb_dev_struct * device_ctrl);


/*
**************************************************************************************************************************************************************************
Objective				: add a Modbus Function Code support to the Modbus decoder system
Description  			: 
Input					: code		  Modbus function Code
						  func		  Pointer to the function Code process function
Output					: 0  		  Success
						  1  		  Failure	 -- MODBUS_FUNCTION_MAX should be increased 

Development History  	: 
@author  				: Kevin, Simon 
@date					: 2011/07/08
@remarks				: 

**************************************************************************************************************************************************************************
*/
//extern	uint8_t  mdb_func_code_add( uint16_t  code, uint16_t   ( *func )( uint8_t  *cmd, uint16_t  len ) );
extern uint8_t mdb_func_code_add( const struct mdb_func_struct *func_ctrl );






// API for user defined function code usage
/*
**************************************************************************************************************************************************************************
Objective				: Modbus Exception Code Reply
Description				: 
Input					: cmd		  pointer to command, include funtion code, not include Slave ID
						  code		  Exception Code 
Output					: Length of Modbus exception reply, Reply message in cmd  

Development History 	:
@author					: Kevin
@date					: 2011/07/08
@remarks				:

**************************************************************************************************************************************************************************
*/
extern	uint16_t				 modbus_exception( uint8_t	*cmd, uint8_t  code );

/*
**************************************************************************************************************************************************************************
Objective				: Modbus Device look up 
Description				: 
Input					: type	   Modbus Device Type
						  addr	   Modbus Device Address
						  quantity Quantitiy of the device	  
Output					: Pointer to the matched device  
						  NULL for address vaild						   
Development History 	:
@author					: Kevin
@date					: 2011/07/08
@remarks				:

**************************************************************************************************************************************************************************
*/
extern	const struct	mdb_dev_struct	*mdb_get_device( uint16_t  type, uint16_t  addr, uint16_t  quantity );


#endif																					  // _MODBUS_DEC_H_  															  



