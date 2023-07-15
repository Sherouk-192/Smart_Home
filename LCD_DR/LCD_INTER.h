/*
 * LCD_INTER.h
 *
 *  Created on: Sep 13, 2021
 *      Author: LENOVO
 */

#ifndef LCD_DR_LCD_INTER_H_
#define LCD_DR_LCD_INTER_H_

#include "../LIB/STD_TYPES.h"
void LCD_SendCommand(u8 cmd);
void LCD_Init(void);
void LCD_SendCharacter(u8 ch);
void LCD_SendString(char st[]);
void LCD_SendNumber(s32 num);
void LCD_SaveCustomCharacter(u8 addres , u8 array[]);
void LCD_SetCoursorPosition(u8 line , u8 position);



#define LCD_CLEARE_SCREEN				1


#endif /* LCD_DR_LCD_INTER_H_ */
