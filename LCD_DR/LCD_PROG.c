/*
 * LCD_PROG.c
 *
 *  Created on: Sep 13, 2021
 *      Author: LENOVO
 */

#include "../LIB/STD_TYPES.h"
#include "LCD_INTER.h"
#include "LCD_CONFIG.h"
#include "../DIO/DIO_INTER.h"

#include<util/delay.h>

void LCD_SendCommand(u8 cmd)
{
	DIO_SetPinValue(CONTROL_PORT,DIO_PIN0,DIO_LOW);
	DIO_SetPinValue(CONTROL_PORT,DIO_PIN1,DIO_LOW);
	_delay_ms(1);
	DIO_SetPortValue(DATA_PORT,cmd);
	_delay_ms(1);
	DIO_SetPinValue(CONTROL_PORT,DIO_PIN2,DIO_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(CONTROL_PORT,DIO_PIN2,DIO_LOW);
	_delay_ms(1);
}


void LCD_Init(void)
{
	DIO_SetPinDirection(CONTROL_PORT,DIO_PIN0,DIO_OUTPUT);
	DIO_SetPinDirection(CONTROL_PORT,DIO_PIN1,DIO_OUTPUT);
	DIO_SetPinDirection(CONTROL_PORT,DIO_PIN2,DIO_OUTPUT);
	DIO_SetPortDirection(DATA_PORT,0xff);
	_delay_ms(50);
	LCD_SendCommand(0b00111000);
	_delay_ms(1);
	LCD_SendCommand(0b00001100);
	_delay_ms(1);
	LCD_SendCommand(0b00000001);
	_delay_ms(3);
	LCD_SendCommand(0b00000110);
}


void LCD_SendCharacter(u8 ch)
{
	DIO_SetPinValue(CONTROL_PORT,DIO_PIN0,DIO_HIGH);
	DIO_SetPinValue(CONTROL_PORT,DIO_PIN1,DIO_LOW);
	_delay_ms(1);
	DIO_SetPortValue(DATA_PORT,ch);
	_delay_ms(1);
	DIO_SetPinValue(CONTROL_PORT,DIO_PIN2,DIO_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(CONTROL_PORT,DIO_PIN2,DIO_LOW);
	_delay_ms(1);

}
void LCD_SendString(char st[])
{
	for(u8 i =0 ; st[i]!='\0' ; i++)
	{
		LCD_SendCharacter(st[i]);
	}
}
void LCD_SendNumber(s32 num)
{
	u8 count=0;
	u8 arr[10]={0};
	if(num==0)
	{
		LCD_SendCharacter('0');
	}
	if (num <0 )
	{
		LCD_SendCharacter('-');
		num = num*(-1);
	}

	for (u8 i= 0 ; num!=0 ; i++ )
	{ count++;
		arr[i]=num%10;
		num/=10;
	}
	for (s8 i = (count-1) ; i>=0 ; i--)
	{
		LCD_SendCharacter('0'+arr[i]);

	}
}

void LCD_SaveCustomCharacter(u8 addres , u8 array[])
{
	LCD_SendCommand(0x40+(8*addres));
	for(u8 i =0 ; i <8 ; i++)
	{
		LCD_SendCharacter(array[i]);
	}
	LCD_SendCommand(0x80);
}
void LCD_SetCoursorPosition(u8 line , u8 position)
{
	if (line==0)
	{
		LCD_SendCommand(0x80+position);
	}
	else
	{
		LCD_SendCommand(0x80+position+64);
	}
}
