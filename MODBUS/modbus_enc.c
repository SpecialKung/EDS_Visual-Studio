#include     "stdint.h"
#include     "string.h"
#include     "lib_access.h"



//-----------------------------------------------------------------------------
// Encode Funciton 
uint16_t mdbenc_01_read_coils( uint8_t  *buf, const uint16_t  addr, const uint16_t  quantity );
uint16_t mdbenc_02_read_discrete_input( uint8_t  *buf, const uint16_t  addr, const uint16_t  quantity );
uint16_t mdbenc_03_read_holding_register( uint8_t  *buf, const uint16_t  addr, const uint16_t  quantity );
uint16_t mdbenc_04_read_input_register( uint8_t  *buf, const uint16_t  addr, const uint16_t  quantity );
uint16_t mdbenc_05_write_single_coil( uint8_t  *buf, const uint16_t  addr, const uint8_t var);
uint16_t mdbenc_06_write_single_register( uint8_t  *buf, const uint16_t  addr, const uint16_t var);
uint16_t mdbenc_0f_write_multiple_coil( uint8_t  *buf, const uint16_t  addr, const uint16_t  quantity, const uint16_t* var);
uint16_t mdbenc_10_write_multiple_register( uint8_t  *buf, const uint16_t  addr, const uint16_t  quantity, const uint16_t* var);
uint16_t mdbenc_17_read_write_register( uint8_t  *buf, const uint16_t  r_addr, const uint16_t  r_quantity, const uint16_t  w_addr, const uint16_t  w_quantity, const uint16_t* var);



//-----------------------------------------------------------------------------
// Check Function 
uint16_t mdbchk_01_read_coils( uint8_t  *buf, const uint16_t len, const uint16_t  quantity,  uint16_t * var );
uint16_t mdbchk_02_read_discrete_input(  uint8_t  *buf, const uint16_t len, const uint16_t  quantity,  uint16_t * var );
uint16_t mdbchk_03_read_holding_register( uint8_t  *buf, const uint16_t len, const uint16_t  quantity,  uint16_t * var );
uint16_t mdbchk_04_read_input_register( uint8_t  *buf, const uint16_t len, const uint16_t  quantity,  uint16_t * var );
uint16_t mdbchk_05_write_single_coil( uint8_t  *buf, const uint16_t len, const uint16_t  addr );
uint16_t mdbchk_06_write_single_register( uint8_t  *buf, const uint16_t len, const uint16_t  addr );
uint16_t mdbchk_0f_write_multiple_coil( uint8_t  *buf, const uint16_t len, const uint16_t  addr, const uint16_t  quantity);
uint16_t mdbchk_10_write_multiple_register( uint8_t  *buf, const uint16_t len, const uint16_t  addr, const uint16_t  quantity);
uint16_t mdbchk_17_read_write_register( uint8_t  *buf, const uint16_t len, const uint16_t  r_quantity,  uint16_t * var );







//---------------------------------------------------------------------------------------------------------
uint16_t mdbenc_01_read_coils( uint8_t  *buf, const uint16_t  addr, const uint16_t  quantity )
{
    buf[ 0 ] = ( uint8_t )0x01U;
    buf[ 1 ] = ( uint8_t )( ( addr>>8 ) & 0x00ffU );
    buf[ 2 ] = ( uint8_t )( ( addr ) & 0x00ffU );
    buf[ 3 ] = ( uint8_t )( ( quantity>>8 ) & 0x00ffU );
    buf[ 4 ] = ( uint8_t )( ( quantity ) & 0x00ffU );
    return 5U;
}


uint16_t mdbenc_02_read_discrete_input( uint8_t  *buf, const uint16_t  addr, const uint16_t  quantity )
{
    buf[ 0 ] = ( uint8_t )0x02U;
    buf[ 1 ] = ( uint8_t )( ( addr>>8 ) & 0x00ffU );
    buf[ 2 ] = ( uint8_t )( ( addr ) & 0x00ffU );
    buf[ 3 ] = ( uint8_t )( ( quantity>>8 ) & 0x00ffU );
    buf[ 4 ] = ( uint8_t )( ( quantity ) & 0x00ffU );
    return 5U;
}


uint16_t mdbenc_03_read_holding_register( uint8_t  *buf, const uint16_t  addr, const uint16_t  quantity )
{
    buf[ 0 ] = ( uint8_t )0x03U;
    buf[ 1 ] = ( uint8_t )( ( addr>>8 ) & 0x00ffU );
    buf[ 2 ] = ( uint8_t )( ( addr ) & 0x00ffU );
    buf[ 3 ] = ( uint8_t )( ( quantity>>8 ) & 0x00ffU );
    buf[ 4 ] = ( uint8_t )( ( quantity ) & 0x00ffU );
    return 5U;
}



uint16_t mdbenc_04_read_input_register( uint8_t  *buf, const uint16_t  addr, const uint16_t  quantity )
{
    buf[ 0 ] = ( uint8_t )0x04U;
    buf[ 1 ] = ( uint8_t )( ( addr>>8 ) & 0x00ffU );
    buf[ 2 ] = ( uint8_t )( ( addr ) & 0x00ffU );
    buf[ 3 ] = ( uint8_t )( ( quantity>>8 ) & 0x00ffU );
    buf[ 4 ] = ( uint8_t )( ( quantity ) & 0x00ffU );
    return 5U;
}



uint16_t mdbenc_05_write_single_coil( uint8_t  *buf, const uint16_t  addr, const uint8_t var)
{
    buf[ 0 ] = ( uint8_t )0x05U;
    buf[ 1 ] = ( uint8_t )( ( addr>>8 ) & 0x00ffU );
    buf[ 2 ] = ( uint8_t )( ( addr ) & 0x00ffU );
    if( var != 0)
    {
        buf[ 3 ] = ( uint8_t )0xffU;
    }
    buf[ 4 ] = ( uint8_t )0x0U;
    return 5U;    
}


uint16_t mdbenc_06_write_single_register( uint8_t  *buf, const uint16_t  addr, const uint16_t var)
{
    buf[ 0 ] = ( uint8_t )0x06U;
    buf[ 1 ] = ( uint8_t )( ( addr>>8 ) & 0x00ffU );
    buf[ 2 ] = ( uint8_t )( ( addr ) & 0x00ffU );
    buf[ 3 ] = ( uint8_t )( ( var>>8 ) & 0x00ffU );
    buf[ 4 ] = ( uint8_t )( ( var ) & 0x00ffU );
    return 5U;    
}



uint16_t mdbenc_0f_write_multiple_coil( uint8_t  *buf, const uint16_t  addr, const uint16_t  quantity, const uint16_t* var)
{
    //uint16_t len = 6;
    uint16_t byte_len = 0;
    uint16_t i;
    
    byte_len = (quantity + 7)/8;
    
    buf[ 0 ] = ( uint8_t )0x0fU;
    buf[ 1 ] = ( uint8_t )( ( addr>>8 ) & 0x00ffU );
    buf[ 2 ] = ( uint8_t )( ( addr ) & 0x00ffU );
    buf[ 3 ] = ( uint8_t )( ( quantity>>8 ) & 0x00ffU );
    buf[ 4 ] = ( uint8_t )( ( quantity ) & 0x00ffU );
    buf[ 5 ] = ( uint8_t )byte_len;
    
    for( i = 0; i < quantity; i++ )
    {
        set_bit( (uint8_t *)&buf[ 6 ], i, ( uint16_t )get_16bit( &var[ 0 ], i ) );
    }
    
    return (6 + byte_len);    
}




uint16_t mdbenc_10_write_multiple_register( uint8_t  *buf, const uint16_t  addr, const uint16_t  quantity, const uint16_t* var)
{
    uint16_t byte_len = 0;
    uint16_t i;
    
    byte_len = (quantity * 2);
    
    buf[ 0 ] = ( uint8_t )0x10U;
    buf[ 1 ] = ( uint8_t )( ( addr>>8 ) & 0x00ffU );
    buf[ 2 ] = ( uint8_t )( ( addr ) & 0x00ffU );
    buf[ 3 ] = ( uint8_t )( ( quantity>>8 ) & 0x00ffU );
    buf[ 4 ] = ( uint8_t )( ( quantity ) & 0x00ffU );
    buf[ 5 ] = ( uint8_t )byte_len;
    
    
    for( i = 0; i < quantity; i++ )
    {
        buf[ 6  + ( i * 2 ) ] = ( uint8_t )( ( var[ i ]>>8 ) & 0x00ffU );
        buf[ 7  + ( i * 2 ) ] = ( uint8_t )( var[ i ] & 0x00ffU );
    }
    return (6 + byte_len);    
}



uint16_t mdbenc_17_read_write_register( uint8_t  *buf, const uint16_t  r_addr, const uint16_t  r_quantity, const uint16_t  w_addr, const uint16_t  w_quantity, const uint16_t* var)
{
    uint16_t byte_len = 0;
    uint16_t i;
    
    byte_len = (w_quantity * 2);
    
    buf[ 0 ] = ( uint8_t )0x17U;
    buf[ 1 ] = ( uint8_t )( ( r_addr>>8 ) & 0x00ffU );
    buf[ 2 ] = ( uint8_t )( ( r_addr ) & 0x00ffU );
    buf[ 3 ] = ( uint8_t )( ( w_quantity>>8 ) & 0x00ffU );
    buf[ 4 ] = ( uint8_t )( ( w_quantity ) & 0x00ffU );
    buf[ 5 ] = ( uint8_t )( ( w_addr>>8 ) & 0x00ffU );
    buf[ 6 ] = ( uint8_t )( ( w_addr ) & 0x00ffU );
    
    buf[ 7 ] = ( uint8_t )( ( w_quantity>>8 ) & 0x00ffU );
    buf[ 8 ] = ( uint8_t )( ( w_quantity ) & 0x00ffU );
    buf[ 9 ] = ( uint8_t )byte_len;
    
    
    for( i = 0; i < w_quantity; i++ )
    {
        buf[ 10  + ( i * 2 ) ] = ( uint8_t )( ( var[ i ]>>8 ) & 0x00ffU );
        buf[ 11  + ( i * 2 ) ] = ( uint8_t )( var[ i ] & 0x00ffU );
    }
    return (10 + byte_len);    
}








//---------------------------------------------------------------------------------------------------------
uint16_t mdbenc_read(uint8_t  *buf, const uint16_t code, const uint32_t  addr, const uint16_t  quantity )
{
    uint16_t len = 0;
    
    switch( code )
    {
        case 0x01U:
            len = mdbenc_01_read_coils(buf, (const uint16_t)addr, quantity);
            break;
        case 0x02U:
            len = mdbenc_02_read_discrete_input(buf, (const uint16_t)addr, quantity);
            break;
        case 0x03U:
            len = mdbenc_03_read_holding_register(buf, (const uint16_t)addr, quantity);
            break;
        case 0x04U:
            len = mdbenc_04_read_input_register(buf, (const uint16_t)addr, quantity);
            break;
    }
    return len;
}




uint16_t mdbenc_write(uint8_t  *buf, const uint16_t code, const uint32_t  addr, const uint16_t  quantity, const uint16_t* var )
{
    uint16_t len = 0;
    
    switch( code )
    {
        case 0x05U:
            len = mdbenc_05_write_single_coil( buf, (const uint16_t)addr, (uint8_t)var[0]);
            break;            
        case 0x06U:
            len = mdbenc_06_write_single_register( buf, (const uint16_t)addr, var[0]);
            break;
        case 0x0fU:
            len = mdbenc_0f_write_multiple_coil( buf, (const uint16_t)addr, quantity, var);
            break;
        case 0x10U:
            len = mdbenc_10_write_multiple_register( buf, (const uint16_t)addr, quantity, var);
            break; 
    }
    
    return len;
}




uint16_t mdbenc_read_write(uint8_t  *buf, const uint16_t code, const uint32_t  r_addr, const uint16_t  r_quantity, const uint32_t  w_addr, const uint16_t  w_quantity, const uint16_t* var )
{
    uint16_t len = 0;
    switch( code )
    {
        case 0x17:
            len = mdbenc_17_read_write_register( buf, r_addr, r_quantity, w_addr, w_quantity, var);
            break;
    }
    return len;

}















//---------------------------------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------------------------
uint16_t mdbchk_01_read_coils( uint8_t  *buf, const uint16_t len, const uint16_t  quantity,  uint16_t * var )
{
    uint16_t error_code = 0x05;    
    uint16_t i;
    uint16_t byte_count;
    
    byte_count = (quantity + 7)/8;
    
    if( ( buf[ 0 ] & 0x80 ) == 0 )
    {
        if( buf[ 0 ] == 0x01)
        {
            if( len >= (byte_count + 2))
            {
                if( buf[1] == (uint8_t)byte_count)
                {
                    for( i = 0; i < quantity; i++ )
                    {
                        for( i = 0; i < quantity; i++ )
                        {
                            set_16bit( (uint16_t *)&var[ 0 ], i, ( uint16_t )get_bit( &buf[ 2 ], i ) );
                        }
                    }
                    error_code = 0U;
                }
            }
        }
    } 
    else
    {
        error_code = buf[1];
        
    }
    
    return error_code;
}


uint16_t mdbchk_02_read_discrete_input(  uint8_t  *buf, const uint16_t len, const uint16_t  quantity,  uint16_t * var )
{
    uint16_t error_code = 0x05;    
    uint16_t i;
    uint16_t byte_count;
    
    byte_count = (quantity + 7)/8;
    
    if( ( buf[ 0 ] & 0x80 ) == 0 )
    {
        if( buf[ 0 ] == 0x02)
        {
            if( len >= (byte_count + 2))
            {
                if( buf[1] == (uint8_t)byte_count)
                {
                    for( i = 0; i < quantity; i++ )
                    {
                        for( i = 0; i < quantity; i++ )
                        {
                            set_16bit( (uint16_t *)&var[ 0 ], i, ( uint16_t )get_bit( &buf[ 2 ], i ) );
                        }
                    }
                    error_code = 0U;
                }
            }
        }
    } 
    else
    {
        error_code = buf[1];
        
    }
    
    return error_code;
}


uint16_t mdbchk_03_read_holding_register( uint8_t  *buf, const uint16_t len, const uint16_t  quantity,  uint16_t * var )
{
    uint16_t error_code = 0x05;    
    uint16_t i;
    uint16_t offset;
    uint16_t tmp16;
    
    if( ( buf[ 0 ] & 0x80 ) == 0 )
    {
        if( buf[ 0 ] == 0x03)
        {
            if( len >= (buf[1] + 2))
            {
                if( buf[1] == (uint8_t)(quantity * 2))
                {
                    offset = 2;
                    for( i = 0; i < quantity; i++ )
                    {
                        tmp16      = buf[offset++ ];
                        tmp16    <<= 8;
                        tmp16      += buf[offset++];
                        var[ i ]   = tmp16;
                    }
                    error_code = 0U;
                }
            }
        }
    } 
    else
    {
        error_code = buf[1];
        
    }
    
    return error_code;
}



uint16_t mdbchk_04_read_input_register( uint8_t  *buf, const uint16_t len, const uint16_t  quantity,  uint16_t * var )
{
    uint16_t error_code = 0x05;    
    uint16_t i;
    uint16_t offset;
    uint16_t tmp16;
    
    if( ( buf[ 0 ] & 0x80 ) == 0 )
    {
        if( buf[ 0 ] == 0x04)
        {
            if( len >= (buf[1] + 2))
            {
                if( buf[1] == (uint8_t)(quantity * 2))
                {
                    offset = 2;
                    for( i = 0; i < quantity; i++ )
                    {
                        tmp16      = buf[offset++ ];
                        tmp16    <<= 8;
                        tmp16      += buf[offset++];
                        var[ i ]   = tmp16;
                    }
                    error_code = 0U;
                }
            }
        }
    } 
    else
    {
        error_code = buf[1];
        
    }
    
    return error_code;
}



uint16_t mdbchk_05_write_single_coil( uint8_t  *buf, const uint16_t len, const uint16_t  addr )
{
    uint16_t error_code = 0x05;  
    uint16_t tmp16;  
    
    if( ( buf[ 0 ] & 0x80 ) == 0 )
    {
        if( buf[ 0 ] == 0x05)
        {
            if( len >= 5)
            {
                tmp16 = get_u16b(&buf[1]);  
                if( tmp16 == addr )
                {
                    error_code = 0U;
                }
            }
        }
    } 
    else
    {
        error_code = buf[1];
        
    }
    
    return error_code;        
}


uint16_t mdbchk_06_write_single_register( uint8_t  *buf, const uint16_t len, const uint16_t  addr )
{
    uint16_t error_code = 0x05;  
    uint16_t tmp16;  
    
    if( ( buf[ 0 ] & 0x80 ) == 0 )
    {
        if( buf[ 0 ] == 0x06)
        {
            if( len >= 5)
            {
                tmp16 = get_u16b(&buf[1]);  
                if( tmp16 == addr )
                {
                    error_code = 0U;
                }
            }
        }
    } 
    else
    {
        error_code = buf[1];
        
    }
    
    return error_code;    
}



uint16_t mdbchk_0f_write_multiple_coil( uint8_t  *buf, const uint16_t len, const uint16_t  addr, const uint16_t  quantity)
{
    uint16_t error_code = 0x05;    
    uint16_t tmp16;
    
    if( ( buf[ 0 ] & 0x80 ) == 0 )
    {
        if( buf[ 0 ] == 0x0f)
        {
            if( len >= 5)            
            {
                tmp16 = get_u16b(&buf[1]);  
                if( tmp16 == addr )
                {
                    tmp16 = get_u16b(&buf[3]);  
                    if( tmp16 == quantity )
                    {   
                        error_code = 0U;
                    }
                }
            }
        }
    } 
    else
    {
        error_code = buf[1];
        
    }
    
    return error_code;    
}




uint16_t mdbchk_10_write_multiple_register( uint8_t  *buf, const uint16_t len, const uint16_t  addr, const uint16_t  quantity)
{
   uint16_t error_code = 0x05;    
    uint16_t tmp16;
    
    if( ( buf[ 0 ] & 0x80 ) == 0 )
    {
        if( buf[ 0 ] == 0x10)
        {
            if( len >= 5)            
            {
                tmp16 = get_u16b(&buf[1]);  
                if( tmp16 == addr )
                {
                    tmp16 = get_u16b(&buf[3]);  
                    if( tmp16 == quantity )
                    {   
                        error_code = 0U;
                    }
                }
            }
        }
    } 
    else
    {
        error_code = buf[1];        
    } 
    return error_code;   
}





uint16_t mdbchk_17_read_write_register( uint8_t  *buf, const uint16_t len, const uint16_t  r_quantity,  uint16_t * var )
{
    uint16_t error_code = 0x05;    
    uint16_t i;
    uint16_t offset;
    uint16_t tmp16;
    
    if( ( buf[ 0 ] & 0x80 ) == 0 )
    {
        if( buf[ 0 ] == 0x17)
        {
            if( len >= (buf[1] + 2))
            {
                if( buf[1] == (uint8_t)(r_quantity * 2))
                {
                    offset = 2;
                    for( i = 0; i < r_quantity; i++ )
                    {
                        tmp16      = buf[offset++ ];
                        tmp16    <<= 8;
                        tmp16      += buf[offset++];
                        var[ i ]   = tmp16;
                    }
                    error_code = 0U;
                }
            }
        }
    } 
    else
    {
        error_code = buf[1];
        
    }
    
    return error_code;
}





uint16_t mdbchk_read(uint8_t  *buf, const uint16_t len, const uint16_t code, const uint16_t  quantity, uint16_t * var )
{
    uint16_t error_code = 0U;
    
     switch( code )
    {
        case 0x01U:
            error_code = mdbchk_01_read_coils(buf, len, quantity, var);
            break;
        case 0x02U:
            error_code = mdbchk_02_read_discrete_input(buf, len, quantity, var);
            break;
        case 0x03U:
            error_code = mdbchk_03_read_holding_register(buf, len, quantity, var);
            break;
        case 0x04U:
            error_code = mdbchk_04_read_input_register(buf, len, quantity, var);
            break;
         
        default:
            error_code = 0x06;
            break;
        
    }
    return error_code;
}



uint16_t mdbchk_write(uint8_t  *buf, const uint16_t len, const uint16_t code, const uint32_t  addr, const uint16_t  quantity)
{
    uint16_t error_code = 0U;

    switch( code )
    {
        case 0x05U:
            error_code = mdbchk_05_write_single_coil(buf, len, (const uint16_t)addr);
            break;
        case 0x06U:
            error_code = mdbchk_06_write_single_register(buf, len, (const uint16_t)addr);
            break;
        case 0x0fU:
            error_code = mdbchk_0f_write_multiple_coil(buf, len, (const uint16_t)addr, quantity);
            break;
        case 0x10U:
            error_code = mdbchk_10_write_multiple_register(buf, len, (const uint16_t)addr, quantity);
            break;
        default:
            error_code = 0x06;
            break;

    }
    return error_code;
   
}




uint16_t mdbchk_read_write(uint8_t  *buf, const uint16_t len, const uint16_t code, const uint16_t  quantity, uint16_t * var )
{
    uint16_t error_code = 0U;
    
     switch( code )
    {
       
        case 0x17U:
            error_code = mdbchk_17_read_write_register(buf, len, quantity, var);
            break;        
        default:
            error_code = 0x06;
            break;
        
    }
    return error_code;
}



















