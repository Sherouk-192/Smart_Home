/*
 * ADC_PROGRAM.c
 *
 *  Created on: Oct 9, 2021
 *      Author: LENOVO
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "ADC_INTERFACE.h"
#include "ADC_CONFIG.h"
#include "ADC_PRIVATE.h"

  static  void (* global_ADCCallback)(void ) = NULL;

void ADC_vodInit(void)
{
	//select refrance voltage

	ADMUX |= (ADC_REFERANCE_VOLTAGE<<6);

	//selectDATA ADJUSTMENT
#if ADC_DATA_ADJUSTMENT==RIGHT
	CLR_BIT(ADMUX,ADLAR);
#elif ADC_DATA_ADJUSTMENT==LEFT
	SET_BIT(ADMUX,ADLAR);
#endif
	// enable aoto trigger and select source
#if AUT_TRIGGER ==DISABLE

	CLR_BIT(ADCSRA,ADATE);
#elif ADC_AUT_TRIGGER ==ENABLE

	SET_BIT(ADCSRA,ADATE);
	SFIOR |= (AUTO_TRIGGERING_SOURCE<<5>);

#endif
	// enable interrupt

#if ADC_INTERRUPT ==DISABLE
	CLR_BIT(ADCSRA,ADIE);
#elif ADC_INTERRUPT ==ENABLE
	SET_BIT(ADCSRA,ADIE);
#endif

	// select pre scelar

	ADCSRA &= 0xf8;
	ADCSRA |= ADC_PRESCALER_VALUE ;

	// Enable ADC
	SET_BIT(ADCSRA,ADEN);
}
u16 ADC_u16GetDigitalValue(u8 copy_u8ChannelNumber)
{
	u16 analog_value =0;
	//select channale
	ADMUX &=0xe0;
	ADMUX |=copy_u8ChannelNumber;
	if (copy_u8ChannelNumber <8)
	{
	ADMUX |= copy_u8ChannelNumber;
	}

	//select conversion

	SET_BIT(ADCSRA,ADSC);

	//wait for conversion complete
	while (GET_BIT(ADCSRA,ADIF)==0)
		{

		}
	//flag clearing

	SET_BIT(ADCSRA,ADIF);
	//return data
	analog_value= ADCL + (ADCH*256);
	//analog_value =ADCH;
	//analog_value=analog_value<<8;
	//analog_value |= ADCL ;
	return analog_value ;
}
void ADC_SetCallBack(void (*FPTR)(void))
{
	global_ADCCallback=FPTR;
}
void __vector_16(void)__attribute__((signal));
void __vector_16(void)
{
	if(global_ADCCallback!=NULL)
	{
		global_ADCCallback ();
	}
}
void ADC_vodEnable(void)
{
	SET_BIT(ADCSRA,ADEN);
}
void ADC_vodDisable(void)
{
	CLR_BIT(ADCSRA,ADEN);
}
void ADC_vodEnableInterupt(void)
{
	SET_BIT(ADCSRA,ADIE);
}
void ADC_vodDisableInterupt(void)
{
	CLR_BIT(ADCSRA,ADIE);
}

































