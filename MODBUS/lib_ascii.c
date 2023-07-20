
#include "stdint.h"


//----------------------------------------------------------------------------------------------------------------------------
/// @brief  
///  Draft   date:2010/08/11\n
///  Release date:          \n                                           
///  Description :Transform data to ASCII code\n 
/// @param   src  source data point
/// @param   dst  destination data point
/// @param   len  length (byte)
/// @return  data length (byte)
//----------------------------------------------------------------------------------------------------------------------------
uint16_t to_ascii( uint8_t  *dst, uint8_t const *src, uint16_t  len )
{
    uint8_t  tmp;
    uint16_t length = len;

    dst = ( dst + ( len * 2U ) );
    src = ( src + len );

    while( len-- )
    {
        tmp    = *--src;
        *--dst = ( ( ( tmp & 0x0fU ) > 9U )? ( ( tmp & 0x0fU ) - 10U  + 'A' ):( ( tmp & 0x0fU ) + '0' ) );
        *--dst = ( ( ( tmp>>4 ) > 9U )? ( ( tmp>>4 ) - 10U  + 'A' ):( ( tmp>>4 ) + '0' ) );
    }

    length *= 2U;

    return length;
}




/*
******************************************************************************************************************************
Objective               : Transfore data to hex format 
Description             : 
Input                   : dst(destination data point)
                          src(source data point)
                          len(data byte length) 
Output                  : data byte length  

Development History     : 20100811, 20101219 
@author                 : Simon 
@date                   :
@remarks                :

******************************************************************************************************************************
*/
uint16_t to_hex( uint8_t  *dst, uint8_t const *src, uint16_t  len )
{
    uint8_t  tmp;
    uint16_t i = 0U;

    while( i < len )
    {
        tmp = *src;
        if( ( tmp <= 57U ) && ( tmp >= 48U ) )                                            //     0~9                          
        {
            *dst = tmp - 48U;
        }
        else
        {
            if( ( tmp >= 65U ) && ( tmp <= 70U ) )                                        //       A~F                        
            {
                *dst = tmp - 55U;
            }
            else                                                                          //       Others                     
            {
                *dst = 0U;
            }
        }

        *dst <<= 4U;
        if( ( ++i ) == len )
        {
            break;
        }
        src++;

        tmp = *src;
        if( ( tmp <= 57U ) && ( tmp >= 48U ) )
        {
            *dst += tmp - 48U;
        }
        else
        {
            if( ( tmp >= 65U ) && ( tmp <= 70U ) )
            {
                *dst += tmp - 55U;
            }
            else
            {
                *dst += 0U;
            }
        }

        i++;
        src++;
        dst++;
    }

    return ( ( i + 1U ) / 2U );
}










#if 0

//----------------------------------------------------------------------------------------------------------------------------
/// @brief  
///  Draft   date:2010/08/11\n
///  Release date:          \n                                           
///  Description :Transform data to ASCII code\n 
/// @param   buf  source data point
/// @param   len  data length (byte)
/// @return  data length (byte)
//----------------------------------------------------------------------------------------------------------------------------
uint16_t D_To_ASCII( uint8_t  *buf, uint16_t  len )
{
    uint8_t   tmp;
    uint8_t  *dst = ( buf + ( len * 2U ) );
    uint8_t  *end = ( buf + len );
    uint16_t  length = len;

    while( len-- )
    {
        tmp = *--end;
        *--dst
        = ( ( ( tmp & 0x0FU ) > 9U )
              ? ( ( ( tmp & 0x0FU ) - 10U ) + ( uint8_t )'A' ):( ( tmp & 0x0FU ) + ( uint8_t )'0' ) );
        *--dst
        = ( ( ( tmp>>4U ) > 9U )
              ? ( ( ( tmp>>4U ) - 10U ) + ( uint8_t )'A' ):( ( tmp>>4U ) + ( uint8_t )'0' ) );
    }
    return ( uint16_t )( length * 2U );
}


/*
******************************************************************************************************************************
Objective               : Transfore data to hex format 
Description             : 
Input                   : dst(destination data point)
                          src(source data point)
                          len(data byte length) 
Output                  : data byte length  

Development History     : 20100811, 20101219 
@author                 : Simon 
@date                   :
@remarks                :

******************************************************************************************************************************
*/
uint16_t ascii_to_hex( uint8_t  *dst, uint8_t  *src, uint16_t  len )
{
    uint8_t  tmp;
    uint16_t length = len;

    while( len-- )
    {
        tmp      = *src++;
        *dst     = ( tmp < 58U )? ( tmp - 48U ):( tmp - 55U );
        *dst   <<= 4;
        tmp      = *src++;
        *dst++  += ( tmp < 58U )? ( tmp - 48U ):( tmp - 55U );
    }
    return ( length / 2U );
}


#endif 
