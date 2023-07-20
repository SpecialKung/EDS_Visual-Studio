/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
@Copyright (c)			: 
@Module Name			: 
@Objective				:
@Description			:
@Domain				: [Public/Private]
@Input					:
@Output					:

@Development History	:
@author				: 
@date					: 
@remarks				: 

Notes					:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/





#include	 "stdint.h"


// Big Endian
uint16_t get_u16b( const uint8_t  *addr )
{
	uint16_t tmp16;
	tmp16  = ( ( uint16_t )addr[ 0 ] )<<8;
	tmp16 += ( uint16_t )addr[ 1 ];
	return tmp16;
}

void set_u16b( uint8_t	*addr, const uint16_t  var )
{
	addr[ 0 ] = ( uint8_t )( var>>8 );
	addr[ 1 ] = ( uint8_t )( var & 0x00ffU );
}


uint32_t get_u32b( const uint8_t  *addr )
{
	uint32_t tmp32;

	tmp32  = ( ( uint32_t )addr[ 0 ] )<<24;
	tmp32 += ( ( uint32_t )addr[ 1 ] )<<16;
	tmp32 += ( ( uint32_t )addr[ 2 ] )<<8;
	tmp32 += ( uint32_t )addr[ 3 ];
	return tmp32;
}

void set_u32b( uint8_t	*addr, const uint32_t  var )
{
	addr[ 0 ] = ( uint8_t )( ( var>>24 ) & 0x000000ffU );
	addr[ 1 ] = ( uint8_t )( ( var>>16 ) & 0x000000ffU );
	addr[ 2 ] = ( uint8_t )( ( var>>8 ) & 0x000000ffU );
	addr[ 3 ] = ( uint8_t )( var & 0x000000ffU );
}



uint16_t u8bu16cpy( uint16_t  *dst16, const uint8_t  *src8, uint16_t  wcount )
{
	uint16_t i;
	uint16_t j;
	uint16_t tmp16;

	j = 0;
	for( i = 0; i < wcount; i++ )
	{
		tmp16		 = src8[ j++ ];
		tmp16	   <<= 8;
		tmp16		+= src8[ j++ ];
		dst16[ i ]	 = tmp16;
	}
	return j;
}


uint16_t u16u8bcpy( uint8_t  *dst8, const uint16_t	*src16, uint16_t  wcount )
{
	uint16_t i;
	uint16_t j;

	j = 0;
	for( i = 0; i < wcount; i++ )
	{
		dst8[ j++ ] = ( uint8_t )( src16[ i ]>>8 );
		dst8[ j++ ] = ( uint8_t )( src16[ i ] & 0x00ffU );
	}
	return j;
}





// Bit Access - 8
void set_bit( uint8_t  *ptr, const uint16_t  index, const uint16_t	value )
{
	if( value )
	{																			//	 value !=0						    
		ptr[ index>>3 ] |= ( uint8_t )( ( uint32_t )0x01U<<( index & 0x0007U ) );
																				//	   20090219 optimize by Kevin	    
	}
	else
	{																			//	 value == 0;					    
		ptr[ index>>3 ] &= ( uint8_t )~( ( uint32_t )0x01U<<( index & 0x0007U ) );
																				//	   20090219 optimize by Kevin	    
	}
}


uint8_t get_bit( const uint8_t	*ptr, const uint16_t  index )
{
	uint8_t result = 0;
	if( ptr[ index>>3 ] & ( ( uint32_t )0x01<<( index & 0x0007U ) ) )
	{
		result = 1U;
	}
	else
	{
		result = 0U;
	}
	return result;
}


// Bit Access - 16
void set_16bit( uint16_t  *ptr, const uint16_t  index, const uint16_t	value )
{
	if( value )
	{																			//	 value !=0						    
		ptr[ index>>4 ] |= ( uint16_t )( ( uint32_t )0x01U<<( index & 0x000FU ) );
	}
	else
	{																			//	 value == 0;					    
		ptr[ index>>4 ] &= ( uint16_t )~( ( uint32_t )0x01U<<( index & 0x000FU ) );
	}
}


uint8_t get_16bit( const uint16_t	*ptr, const uint16_t  index )
{
	uint8_t result = 0;
	if( ptr[ index>>4 ] & ( ( uint32_t )0x01<<( index & 0x000FU ) ) )
	{
		result = 1U;
	}
	else
	{
		result = 0U;
	}
	return result;
}


// Bit Access - 32
void set_32bit( uint32_t  *ptr, const uint16_t  index, const uint16_t	value )
{
	if( value )
	{																			//	 value !=0						    
		ptr[ index>>5 ] |= ( uint16_t )( ( uint32_t )0x01U<<( index & 0x001FU ) );
	}
	else
	{																			//	 value == 0;					    
		ptr[ index>>5 ] &= ( uint16_t )~( ( uint32_t )0x01U<<( index & 0x001FU ) );
	}
}


uint8_t get_32bit( const uint32_t *ptr, const uint16_t  index )
{
	uint8_t result = 0;
	if( ptr[ index>>5 ] & ( ( uint32_t )0x01<<( index & 0x001FU ) ) )
	{
		result = 1U;
	}
	else
	{
		result = 0U;
	}
	return result;
}









// Little Endian
uint16_t u8lu16cpy( uint16_t  *dst16, const uint8_t  *src8, uint16_t  wcount )
{
	uint16_t i;
	uint16_t j;
	uint16_t tmp16;

	j = 0;
	for( i = 0; i < wcount; i++ )
	{
		tmp16		= src8[ j++ ];
		tmp16	   += ( ( ( uint16_t )src8[ j++ ] )<<8 );
		dst16[ i ]	= tmp16;
	}
	return j;
}


uint16_t u16u8lcpy( uint8_t  *dst8, const uint16_t	*src16, uint16_t  wcount )
{
	uint16_t i;
	uint16_t j;

	j = 0;
	for( i = 0; i < wcount; i++ )
	{
		dst8[ j++ ] = ( uint8_t )( src16[ i ] & 0x00ffU );
		dst8[ j++ ] = ( uint8_t )( src16[ i ]>>8 );
	}
	return j;
}


uint16_t u16lu32cpy( uint32_t  *dst32, const uint16_t  *src16, uint16_t  dwcount )
{
	uint16_t i;
	uint16_t j;
	uint32_t tmp32;

	j = 0;
	for( i = 0; i < dwcount; i++ )
	{
		tmp32		= src16[ j++ ];
		tmp32	   += ( ( ( uint32_t )src16[ j++ ] )<<16 );
		dst32[ i ]	= tmp32;
	}
	return j;
}

/*
uint32_t u16l_u32_get(uint16_t *addr16)
{
    uint32_t tmp32;
    tmp32 = addr16[1];
    tmp32<<= 16;
    tmp32 += addr16[1];
    return tmp32;
}
*/

void set_u32l( uint8_t	*addr, uint32_t  var )
{
	addr[ 3 ] = ( uint8_t )( var>>24 );
	addr[ 2 ] = ( uint8_t )( var>>16 );
	addr[ 1 ] = ( uint8_t )( var>>8 );
	addr[ 0 ] = ( uint8_t )( var & 0xffU );
}



uint32_t get_u32l( uint8_t	*addr )
{
	uint32_t tmp32;

	tmp32  = ( ( uint32_t )addr[ 3 ] )<<24;
	tmp32 += ( ( uint32_t )addr[ 2 ] )<<16;
	tmp32 += ( ( uint32_t )addr[ 1 ] )<<8;
	tmp32 += ( uint32_t )addr[ 0 ];
	return tmp32;
}



uint16_t get_u16l( const uint8_t  *addr )
{
	//return ( uint16_t )( ( uint32_t )u8addr[ 1 ]<<8 ) + u8addr[ 0 ];
	return ( ( ( uint16_t )addr[ 1 ] )<<8 ) + addr[ 0 ];
}


void set_u16l( uint8_t	*addr, uint16_t  var )
{
	addr[ 1 ] = ( uint8_t )( var>>8 );
	addr[ 0 ] = ( uint8_t )( var & 0xffU );
}



