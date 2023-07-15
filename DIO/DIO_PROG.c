/*
 * DIO_PROG.
 *
 *  Created on: Sep 10, 2021
 *      Author: LENOVO
 */

#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include "DIO_PRIV.h"
#include "DIO_CONFIG.h"

void DIO_SetPinDirection(u8 portNumber , u8 pinNumber , u8 direction)
{
	if (direction==1)
	{
		switch(portNumber)
		{
		case 0:
			        SET_BIT(DDRA , pinNumber);
			        break ;
		case 1:
					SET_BIT(DDRB , pinNumber);
					break ;
		case 2:
					SET_BIT(DDRC , pinNumber);
					break ;
		case 3:
					SET_BIT(DDRD , pinNumber);
					break ;

		}
	}
	else if (direction==0)
	{
		switch (portNumber)
		{
			case 0:
				CLR_BIT(DDRA , pinNumber);
	        break ;
			case 1:
				CLR_BIT(DDRB , pinNumber);
			break ;
			case 2:
				CLR_BIT(DDRC , pinNumber);
			break ;
			case 3:
				CLR_BIT(DDRD , pinNumber);
			break ;

		}
	}
}
void DIO_SetPortDirection(u8 portNumber , u8 direction)
{
	switch(portNumber)
			{
			case 0:
				       DDRA=direction;
				        break ;
			case 1:
				       DDRB=direction;
						break ;
			case 2:
				       DDRC=direction;
						break ;
			case 3:
				       DDRD=direction;
					 	break ;

			}
}
void DIO_SetPinValue(u8 portNumber , u8 pinNumber , u8 value)
{
	if (value==1)
		{
			switch(portNumber)
			{
			case 0:
				        SET_BIT(PORTA , pinNumber);
				        break ;
			case 1:
						SET_BIT(PORTB , pinNumber);
						break ;
			case 2:
						SET_BIT(PORTC , pinNumber);
						break ;
			case 3:
						SET_BIT(PORTD , pinNumber);
						break ;

			}
		}
		else if (value==0)
		{
			switch (portNumber)
			{
				case 0:
					CLR_BIT(PORTA , pinNumber);
		        break ;
				case 1:
					CLR_BIT(PORTB , pinNumber);
				break ;
				case 2:
					CLR_BIT(PORTC , pinNumber);
				break ;
				case 3:
					CLR_BIT(PORTD , pinNumber);
				break ;

			}
		}
}
void DIO_SetPortValue(u8 portNumber , u8 value )
{
	switch(portNumber)
				{
				case 0:
					       PORTA=value;
					        break ;
				case 1:
					       PORTB=value;
							break ;
				case 2:
							PORTC=value;
							break ;
				case 3:
							PORTD=value;
						 	break ;

				}
}
u8 DIO_GetPinValue(u8 portNumber , u8 pinNumber )
{
	u8 result = 0 ;
	switch (portNumber)
				{
					case 0:
						result =	GET_BIT(PINA , pinNumber);
			        break ;
					case 1:
						result =	GET_BIT(PINB , pinNumber);
					break ;
					case 2:
						result =	GET_BIT(PINC , pinNumber);
					break ;
					case 3:
						result =		GET_BIT(PIND , pinNumber);
					break ;

				}
	return result ;

}
u8 DIO_GetPortValue(u8 PortNumber)
{
	u8 result = 0 ;
		switch (PortNumber)
					{
						case 0:
							result =	PINA;
				        break ;
						case 1:
							result =	PINB;
						break ;
						case 2:
							result =	PINC;
						break ;
						case 3:
							result =    PIND;
						break ;

					}
		return result ;
}
void DIO_TooglePinValue(u8 PortNumber,u8 pinNumber)
{
	switch(PortNumber)
	{
	case 0:
		TOGGLE_BIT(PORTA,pinNumber);
		break;
	case 1:
		TOGGLE_BIT(PORTB,pinNumber);
		break;
	case 2:
		TOGGLE_BIT(PORTC,pinNumber);
		break;
	case 3:
		TOGGLE_BIT(PORTD,pinNumber);
		break;
	}
}

