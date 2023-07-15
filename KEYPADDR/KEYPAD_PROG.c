/*
 * KEYPAD_PROG.c
 *
 *  Created on: Sep 18, 2021
 *      Author: LENOVO
 */
#include "../LIB/STD_TYPES.h"
#include "../DIO/DIO_INTER.h"
#include "KEYBAD_INER.h"
#include "KEYPAD_CONFIG.h"
#include<util/delay.h>
void KeyPadIniit(void)
{
	DIO_SetPortDirection(KEYPAD_PORT , 0x0f);
	DIO_SetPortValue(KEYPAD_PORT , 0xff );
}

u8 KeyPadGetPresedKey(void)
{
    for(u8 c =0 ; c<3 ; c++ )
    {
	DIO_SetPortValue(KEYPAD_PORT , 0b11111111 );
	DIO_SetPinValue(KEYPAD_PORT , c ,DIO_LOW);
	for (u8 r =0 ; r< 3 ;r++)
	{
	if (DIO_GetPinValue(KEYPAD_PORT , 4+r )==0)
	{
		return (c + (3*r)+1);
		 _delay_ms(100);
	}
	}
    }
    DIO_SetPortValue(KEYPAD_PORT , 0b11111111 );
    DIO_SetPinValue(KEYPAD_PORT , 0 ,DIO_LOW);
    if (DIO_GetPinValue(KEYPAD_PORT , 7 )==0)
    {
    	return 0;
     _delay_ms(100);

    }

   return 'z' ;
}

u8 KeyPadGetPresedOperation(void)
{

	DIO_SetPortValue(KEYPAD_PORT , 0b11111111 );
	DIO_SetPinValue(KEYPAD_PORT , 3 ,DIO_LOW);
	for (u8 r =0 ; r< 4 ;r++)
		{
		if (DIO_GetPinValue(KEYPAD_PORT , 4+r )==0)
		{
			return (r+1);
			 _delay_ms(100);
		}
		}
	return 0 ;
}



  u8 KeyPadAskForResult(void)
{
	DIO_SetPortValue(KEYPAD_PORT , 0b11111111 );
	DIO_SetPinValue(KEYPAD_PORT , 2 ,DIO_LOW);
	if (DIO_GetPinValue(KEYPAD_PORT , 7 )==0)
	{
		return 1 ;
	}
	else
	{
		return 0 ;
	}
}

  u8 KeyPadAskForSign(void)
  {
	  DIO_SetPortValue(KEYPAD_PORT , 0b11111111 );
	  	DIO_SetPinValue(KEYPAD_PORT , 3,DIO_LOW);
	  	if (DIO_GetPinValue(KEYPAD_PORT , 6 )==0)
	  	{
	  		return 1 ;
	  		_delay_ms(100);
	  	}
	  	else
	  	{
	  		return 0 ;
	  		_delay_ms(100);
	  	}
  }
  u8 KeyPadAskForFloat(void)
  {
	  DIO_SetPortValue(KEYPAD_PORT , 0b11111111 );
	  	  DIO_SetPinValue(KEYPAD_PORT , 1,DIO_LOW);
	   	if (DIO_GetPinValue(KEYPAD_PORT , 7 )==0)
	 	{
	  	  return 1 ;
	  	  _delay_ms(100);
	 	}
	   	else
	   	{
	   		return 0 ;
	   		_delay_ms(100);
	  	}
  }
