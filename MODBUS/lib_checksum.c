
#include     "stdint.h"
//#include     "inet.h"


//SUM chekcsum 
uint8_t  sum_1b( const uint8_t  *buf, uint16_t  len, uint8_t  init, uint8_t  comp );
uint16_t sum_2b( const uint8_t  *buf, uint16_t  len, uint16_t  init, uint8_t  comp );


//CRC checksum  
uint16_t crc_ccitt( const uint8_t  *buf, uint16_t  len, uint16_t  init );
uint16_t crc_16( const uint8_t  *buf, uint16_t  len, uint16_t  init );
uint16_t crc( const uint8_t  *buf, uint16_t  len );

//LRC checksum
uint8_t  lrc_1b( const uint8_t  *buf, uint16_t  len, uint16_t  init, uint8_t  comp );
uint16_t lrc_2b( const uint16_t  *buf, uint16_t  wlen );
uint16_t lrc_2b_dec( const uint16_t  *buf, uint16_t  wlen );


//Binary to ASCII conversion
uint16_t to_modbus_ascii( uint8_t  *dst, uint8_t  *src, uint16_t  len );

//-----------------------------------------------
// @Name        uint8_t sum_1b(uint8_t *buf, uint16_t len, uint8_t init, uint8_t comp)
// @Function    SUM checksum, output buf len is 1 byte.
// @Parameter
//              buf     point to the command
//              len     buf lenght
//              init        initial value (1 byte)
//              comp        complement index(0,1 or 2)
// @Return      uint8_t     Operation result
//-----------------------------------------------
uint8_t sum_1b( const uint8_t  *buf, uint16_t  len, uint8_t  init, uint8_t  comp )
{
    uint8_t checksum = init;

    while( len )
    {
        --len;
        checksum += *( buf + len );
    }

    switch( comp )
    {
        case 1:
            checksum = ~checksum;
            break;
        case 2:
            checksum = ( ~checksum ) + 1;
            break;
        default:
            break;
    }

    return checksum;
}

//-----------------------------------------------
// @Name        uint16_t sum_1b(uint8_t *buf, uint16_t len, uint16_t init, uint8_t comp)
// @Function    SUM checksum, output buf len is 2 byte.
// @Parameter
//              buf     point to the command
//              len     buf lenght
//              init        initial value (2 byte)
//              comp        complement index(0,1 or 2)
// @Return      uint16_t    Operation result
//-----------------------------------------------
uint16_t sum_2b( const uint8_t  *buf, uint16_t  len, uint16_t  init, uint8_t  comp )
{
    uint16_t checksum = init;

    while( len )
    {
        --len;
        checksum += *( buf + len );
    }

    switch( comp )
    {
        case 1:
            checksum = ~checksum;
            break;
        case 2:
            checksum = ( ~checksum ) + 1;
            break;
        default:
            checksum = checksum;
    }

    return checksum;
}

//-----------------------------------------------
// @Name        uint16_t crc_ccitt(uint8_t *buf, uint16_t len, uint16_t init)
// @Function    CRC-CCITT checksum, output buf len is 2 byte.
// @Parameter
//              buf     point to the command
//              len     buf lenght
//              init        initial value (2 byte)
// @Return      uint16_t    Operation result
//----------------------------------------------
uint16_t crc_ccitt( const uint8_t  *buf, uint16_t  len, uint16_t  init )
{
    uint8_t  i;
    uint16_t checksum = init;

    while( len )
    {
        --len;
        for( i = 0x80U; i != 0U; i /= 2U )
        {
            if( checksum & 0x8000U )
            {
                checksum = ( checksum<<1U ) ^ 0x1021U;
            }
            else
            {
                checksum = checksum<<1U;
            }

            if( ( *buf & i ) != 0U )
            {
                checksum ^= 0x1021U;
            }
        }
        *buf++;
    }

    return checksum;
//    return (checksum >> 8) | ((checksum & 0x00FF) << 8 ); //swap upper/lower bytes
}


/*
********************************************************************************************************************
Objective               : CRC-16 checksum calucator 
Description             : 
Input                   : buf (buf pointer)
                          len (buf len)
                          init (buf initial value) 
Output                  : crc-16 result  

Development History     : 20101228 
@author                 : simon 
@date                   :
@remarks                :

********************************************************************************************************************
*/
uint16_t crc_16( const uint8_t  *buf, uint16_t  len, uint16_t  reg_crc )
{
    uint8_t j;

    while( len > 0U )
    {
        --len;
//reg_crc ^= *buf++;
        reg_crc ^= *buf;
        ++buf;
        for( j = 0U; j < 8U; j++ )
        {
            if( ( reg_crc & 0x0001U ) != 0U )
            {                                                   /*       LSB(b0)=1                                */
                reg_crc = ( reg_crc>>1 ) ^ 0xa001U;
            }
            else
            {
                reg_crc = reg_crc>>1;
            }
        }
    }

    return reg_crc;
}


/*
********************************************************************************************************************
Objective               :  crc-16 for modbus use
Description             : 
Input                   : buf ( buf pointer )
                          len ( buf len ) 
Output                  : 16bit crc result  

Development History     : 20110126 modify
@author                 : simon
@date                   :
@remarks                :

********************************************************************************************************************
*/
uint16_t crc( const uint8_t  *buf, uint16_t  len )
{
    uint8_t  j;
    uint16_t reg_crc = 0xffffU;

    while( len )
    {
        --len;
        reg_crc ^= *buf;                                        /*     20110126                                   */
        ++buf;                                                  /*     20110126                                   */
        for( j = 0U; j < 8U; j++ )
        {
            if( reg_crc & 0x01U )
            {                                                   /*       LSB(b0)=1                                */
                reg_crc = ( reg_crc>>1 ) ^ 0xa001U;
            }
            else
            {
                reg_crc = reg_crc>>1;
            }
        }
    }
    //return htons( reg_crc );
	return ( ((uint32_t)(reg_crc & 0x00FFU) << 8) | (reg_crc >> 8) ); //swap upper/lower bytes
}

//------------------------------------------------------------------------------------------------------------------
/// @brief  
///  Draft   date:2010/08/11\n
///  Release date:          \n                                           
///  Description :LRC checksum, output buf len is 1 byte.\n 
/// @param      buf     point to the command
//              len     buf len
//              init        initial value (2 byte)
//              comp        complement index (0,1 or 2)
/// @return uint8_t operation result
//------------------------------------------------------------------------------------------------------------------
uint8_t lrc_1b( const uint8_t  *buf, uint16_t  len, uint16_t  init, uint8_t  comp )
{
    uint16_t checksum = init;

    while( len )
    {
        --len;
        checksum ^= *( buf + len );
    }

    switch( comp )
    {
        case 1:
            checksum = ~checksum;
            break;
        case 2:
            checksum = ( ~checksum ) + 1U;
            break;
        default:
            break;
    }
    return ( uint8_t )checksum;
}


//------------------------------------------------------------------------------------------------------------------
/// @brief   Draft date:2010/05/25\n          
///          Release date:\n     
///          Description: Encode 2bytes LRC checksum, output buf len is 1 word./       /       /       /       //
/// @param   buf    point to buf array
/// @param   wlen   word len of buf
/// @return  replying check sum
//------------------------------------------------------------------------------------------------------------------
uint16_t lrc_2b( const uint16_t  *buf, uint16_t  wlen )
{
    uint16_t chk = 0U;

    while( wlen )
    {
        --wlen;
        chk += *( buf + wlen );
    }

    return ( ~chk ) + 1U;
}


//------------------------------------------------------------------------------------------------------------------
/// @brief   Draft date:2010/05/25\n          
///          Release date:\n     
///          Description: Decode 2bytes LRC checksum, output buf len is 1 word./       /       /       /       //
/// @param   buf    point to buf array
/// @param   wlen   word len of buf
/// @return  replying check sum
//------------------------------------------------------------------------------------------------------------------
uint16_t lrc_2b_dec( const uint16_t  *buf, uint16_t  wlen )
{
    uint16_t chk = 0U;

    while( wlen-- )
    {
        chk += *( buf + wlen );
    }

    return chk;
}


//------------------------------------------------------------------------------------------------------------------
/// @brief   Draft date:2010/08/17\n          
///          Release date:\n     
///          Description: Decode 1bytes LRC checksum, output buf len is 1 word./       /       /       /       //
/// @param   buf    point to buf array
/// @param   wlen   word len of buf
/// @return  replying check sum
//------------------------------------------------------------------------------------------------------------------
uint8_t lrc_1b_dec( const uint8_t  *buf, uint16_t  len )
{
    uint16_t chk = 0U;

    while( len )
    {
        --len;
        chk += *( buf + len );
    }

    return chk;
}

//-----------------------------------------------
// @Name        uint16_t to_modbus_ascii(uint8_t *dst, uint8_t *src, uint16_t len)
// @Function    Change Modbus RTU buf to ASCII Data
// @Parameter
//              buf         point to the command
//              len         buf lenght
// @Return      uint16_t    lenght of final command
//-----------------------------------------------
uint16_t to_modbus_ascii( uint8_t  *dst, uint8_t  *src, uint16_t  len )
{
    uint8_t  tmp;
    uint16_t src_len = len;

    dst = ( dst + ( len * 2 ) );
    src = ( src + len );

    while( len )
    {
        --len;
        tmp    = *--src;
        *--dst = ( ( ( tmp>>4 ) > 9 )? ( ( tmp>>4 ) - 10  + 'A' ):( ( tmp>>4 ) + '0' ) );
        *--dst
        = ( ( ( tmp & 0x0F ) > 9 )? ( ( tmp & 0x0F ) - 10  + 'A' ):( ( tmp & 0x0F ) + '0' ) );
        //       *--dst = ( ( ( tmp >> 4 ) > 9 ) ? ( (tmp >> 4) - 10 + 'A') : ( (tmp>>4)+'0') );
    }
    return ( src_len * 2 );
}

//-------------------------------------------
// @Name        uint16_t reorder(uint8_t *dst, uint8_t *src, uint16_t len, uint8_t index)
// @Function    exchange the buf order according to index    
// @Parameter   
//              buf         point to the command
//              len         buf len
//              inedx       reorder index
// @Return      uint16_t    len of final command
//-------------------------------------------
/*
uint16_t reorder(uint8_t *dst, uint8_t *src, uint16_t len, uint8_t index)
{
      
}*/


