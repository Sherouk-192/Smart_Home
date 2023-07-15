/*
 * main.c
 *
 *  Created on: Oct 21, 2021
 *      Author: LENOVO
 */

#include "LIB/STD_TYPES.h"
#include "DIO/DIO_INTER.h"
#include "ADC/ADC_INTERFACE.h"
#include "EXIT/EXIT_INTERFACE.h"
#include "LCD_DR/LCD_INTER.h"
#include "KEYPADDR/KEYBAD_INER.h"
#include <util/delay.h>


int main (void)
{
	u8 n=0 ;
	u8 pass =  0 ;
	u8 tray =  0 ;
	int temp =  0 ;

	DIO_SetPinDirection(DIO_PORTA,DIO_PIN7,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN6,DIO_OUTPUT);

	LCD_Init();
	KeyPadIniit();
	ADC_vodInit();

	LCD_SendString("WELCOME");
	_delay_ms(2000);
	LCD_SendCommand(LCD_CLEARE_SCREEN);
	LCD_SendString("Enter your  ");
	LCD_SetCoursorPosition(1,0);
	LCD_SendString(" pasworde ");
	while (KeyPadGetPresedKey()=='z')
	{

	}
	LCD_SendCommand(LCD_CLEARE_SCREEN);


	//********************************************
	while (tray !=3)
	{
		while (n!=3)
		{
			while (KeyPadGetPresedKey()=='z')
			{

			}

			pass=(pass*10)+ KeyPadGetPresedKey();
			LCD_SendCharacter('*');
			_delay_ms(500);

			n++ ;
		}

		if (pass == 123)
		{
			LCD_SendCommand(LCD_CLEARE_SCREEN);
			break ;
		}
		else
		{
			LCD_SendCommand(LCD_CLEARE_SCREEN);
			_delay_ms(500);
			n =  0 ;
			pass=0;
			tray ++ ;
			if (tray !=3)
			{
				LCD_SendString("Tray again  ");
				_delay_ms(2000);
				LCD_SendCommand(LCD_CLEARE_SCREEN);
			}

		}

	}

	//*******************************************

	while(1)
	{


		if (tray == 3 )
		{
			LCD_SendCommand(LCD_CLEARE_SCREEN);
			LCD_SendString("No more tries ");
			tray ++;
		}

		else if (tray <3)
		{
			while (KeyPadGetPresedKey()!=4)
			{
				if (tray == 5 )
				{
					break ;
				}
				LCD_SendCommand(LCD_CLEARE_SCREEN);
				LCD_SendString("1-fan");
				LCD_SendString("    2-temp ");
				LCD_SetCoursorPosition(1,0);
				LCD_SendString("3-light  ");
				LCD_SendString("4-back");
				//LCD_SendString("5-ESC ");


				while (KeyPadGetPresedKey()=='z' &&KeyPadGetPresedKey()!=1 &&KeyPadGetPresedKey()!=2 &&KeyPadGetPresedKey()!=3 &&KeyPadGetPresedKey()!=4)
				{

				}

				switch(KeyPadGetPresedKey())
				{
				case 1 :
					LCD_SendCommand(LCD_CLEARE_SCREEN);
					LCD_SendString("1-ON   ");
					LCD_SendString("2-OFF ");
					LCD_SetCoursorPosition(1,0);
					LCD_SendString("  4-back ");
					_delay_ms(200);
					while (KeyPadGetPresedKey()!=4)
					{
						while (KeyPadGetPresedKey()=='z')
						{

						}
						if (KeyPadGetPresedKey()==1)
						{
							DIO_SetPinValue(DIO_PORTA,DIO_PIN7, DIO_HIGH);
							_delay_ms(100);
						}
						else if (KeyPadGetPresedKey()==2)
						{
							DIO_SetPinValue(DIO_PORTA,DIO_PIN7, DIO_LOW);
							_delay_ms(100);
						}
					}

					break;
				case 2 :
					LCD_SendCommand(LCD_CLEARE_SCREEN);
					LCD_SetCoursorPosition(1,0);
					LCD_SendString("4- for back ");
					LCD_SetCoursorPosition(0,0);
					LCD_SendString("    temp:");
					while (KeyPadGetPresedKey()!=4)
					{
						LCD_SetCoursorPosition(0,9);
						temp = ADC_u16GetDigitalValue(ADC0);
						LCD_SendNumber(temp/10);
						_delay_ms(200);
					}
					break;
				case 3 :
					LCD_SendCommand(LCD_CLEARE_SCREEN);
					LCD_SetCoursorPosition(1,0);
					LCD_SendString("4- for back ");
					LCD_SetCoursorPosition(0,0);
					LCD_SendString("   light: ");
					while (KeyPadGetPresedKey()!=4)

					{
						LCD_SetCoursorPosition(0,9);
						temp = ADC_u16GetDigitalValue(ADC1);
						LCD_SendNumber(temp/10);
						if (temp <500)
						{
							DIO_SetPinValue(DIO_PORTA,DIO_PIN6, DIO_HIGH);
						}
						else
						{
							DIO_SetPinValue(DIO_PORTA,DIO_PIN6, DIO_LOW);
						}
						_delay_ms(200);
					}
					DIO_SetPinValue(DIO_PORTA,DIO_PIN6, DIO_LOW);

					break;
				case 4 :
					LCD_SendCommand(LCD_CLEARE_SCREEN);
					//DIO_SetPinValue(DIO_PORTA,DIO_PIN7, DIO_LOW);
					n =  0 ;
					pass=0;
					tray = 5 ;
					//_delay_ms(2000);
					break;
				}
			}
		}
		/*if (KeyPadGetPresedKey()!='z')
		{
			LCD_SendNumber(KeyPadGetPresedKey());
			_delay_ms(500);

		}*/
	}
}
