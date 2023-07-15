/*
 * DIO_INTER.h
 *
 *  Created on: Sep 10, 2021
 *      Author: LENOVO
 */

#ifndef DIO_DIO_INTER_H_
#define DIO_DIO_INTER_H_
#include"../LIB/STD_TYPES.h"
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_OUTPUT 1
#define DIO_INPUT  0

#define DIO_HIGH 1
#define DIO_LOW  0

void DIO_SetPinDirection(u8 portNumber , u8 pinNumber , u8 direction);
void DIO_SetPortDirection(u8 portNumber , u8 direction);
void DIO_SetPinValue(u8 portNumber , u8 pinNumber , u8 value);
void DIO_SetPortValue(u8 portNumber , u8 value );
u8 DIO_GetPinValue(u8 portNumber , u8 pinNumber );
u8 DIO_GetPortValue(u8 PortNumber);
void DIO_TooglePinValue(u8 PortNumber,u8 pinNumber);//abo zied

#endif /* DIO_DIO_INTER_H_ */
