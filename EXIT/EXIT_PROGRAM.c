/*
 * EXIT_PROGRAM.c
 *
 *  Created on: Oct 9, 2021
 *      Author: LENOVO
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../DIO/DIO_INTER.h"

#include "EXIT_INTERFACE.h"
#include "EXTI_PRIVATE.h"
#include "EXIT_CONFIG.h"

void (*Global_call_back_int0)(void);
void (*Global_call_back_int1)(void);
void (*Global_call_back_int2)(void);

void EXIT_Init(void)
{
#if SENCE_CONROL_INIT0 == LOW_LEVEL
	CLR_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT);
#elif SENCE_CONROL_INIT0 == TOGGLE
	SET_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT);
#elif SENCE_CONROL_INIT0 == FALING_EDGE
		CLR_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01);
		DIO_SetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT);
#elif SENCE_CONROL_INIT0 == RAISING_EDGE
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT);
#else
#warning "Wrong choice for SENCE_CONROL_INIT0"
#endif


#if SENCE_CONROL_INIT1 == LOW_LEVEL
	CLR_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN3,DIO_INPUT);
#elif SENCE_CONROL_INIT1 == TOGGLE
	SET_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN3,DIO_INPUT);
#elif SENCE_CONROL_INIT1 == FALING_EDGE
		CLR_BIT(MCUCR,ISC10);
		SET_BIT(MCUCR,ISC11);
		DIO_SetPinDirection(DIO_PORTD,DIO_PIN3,DIO_INPUT);
#elif SENCE_CONROL_INIT1 == RAISING_EDGE
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN3,DIO_INPUT);
#else
#warning "Wrong choice for SENCE_CONROL_INIT1"
#endif

#if SENCE_CONROL_INIT2 == FALING_EDGE
		CLR_BIT(MCUCSR,ISC2);
		DIO_SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_INPUT);
#elif SENCE_CONROL_INIT2 == RAISING_EDGE
	SET_BIT(MCUCSR,ISC2);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_INPUT);
#else
#warning "Wrong choice for SENCE_CONROL_INIT2"
#endif
}


void EXIT_EnableExtint(u8 Initid)
{
	switch(Initid)
	{
	case INTF0 :

		SET_BIT(GICR,INTF0);

		break;
	case INTF1 :

		SET_BIT(GICR,INTF1);

		break;
	case INTF2 :

		SET_BIT(GICR,INTF2);

		break;
	}
}


void EXIT_DisableExtint(u8 Initid)
{
	switch(Initid)
	{
	case INTF0 :

		CLR_BIT(GICR,INTF0);

		break;
	case INTF1 :

		CLR_BIT(GICR,INTF1);

		break;
	case INTF2 :

		CLR_BIT(GICR,INTF2);

		break;
	}
}


void EXTI_SetCallBack(u8 intid,void (*FPTR)(void))
{
	switch(intid)
	{
	case int0:
		Global_call_back_int0=FPTR;
		break;
	case int1:
		Global_call_back_int1=FPTR;
		break;
	case int2:
		Global_call_back_int2=FPTR;
		break;
	}

}

void __vector_1(void)__attribute__((signal));

void __vector_1(void)
{
	Global_call_back_int0();
}
void __vector_2(void)__attribute__((signal));

void __vector_2(void)
{
	Global_call_back_int1();
}
void __vector_3(void)__attribute__((signal));

void __vector_3(void)
{
	Global_call_back_int2();
}






















