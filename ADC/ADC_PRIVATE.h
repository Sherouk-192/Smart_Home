/*
 * ADC_PRIVATE.h
 *
 *  Created on: Oct 9, 2021
 *      Author: LENOVO
 */

#ifndef ADC_ADC_PRIVATE_H_
#define ADC_ADC_PRIVATE_H_


#define ADMUX     		*((volatile u8*)(0x27))
#define ADLAR     		5
#define REFS0     		6
#define REFS1     		7
#define ADCSRA     		*((volatile u8*)(0x26))
#define ADIE			3
#define ADIF			4
#define ADATE			5
#define ADSC			6
#define ADEN			7

#define ADCH    		*((volatile u8*)(0x25))
#define ADCL     		*((volatile u8*)(0x24))
#define SFIOR    		*((volatile u8*)(0x50))
#define ADTS0    		5
#define ADTS1    		6
#define ADTS2    		7

#define ADC_RESULT      *((volatile u16*)(0x24))


#define DIV_BY_2       	0b001
#define DIV_BY_4		0b010
#define DIV_BY_8		0b011
#define DIV_BY_16		0b100
#define DIV_BY_32		0b101
#define DIV_BY_64		0b110
#define DIV_BY_128		0b111

#define  AREF_INTERNAL_VREF_TURNED_OFF													0b00
#define  AVCC_WITH_EXTERNAL_CAPACITOR_AT_AREF_PIN										0b01
#define  INTERNAL_256V_VOLTAGE_REFERENCE_WITH_EXTERNAL_CAPACITOR_AT_AREF_PIN			0b11



#define LEFT                     0
#define RIGHT                    1


#define ENABLE                     1
#define DISABLE                    0

#define  FREE_RUNNING_MODE       					0b000
#define  Analog_Comparator      					0b001
#define  External_Interrupt_Request_0       		0b020
#define  TIMER_COUNTER0_COMPARE_MATCH      		 	0b011
#define  TIMER_COUNTER0_OVERFLOW       				0b100
#define  TIMER_COUNTER_COMPARE_MATCH_B       		0b101
#define  TIMER_COUNTER1_OVERFLOW       				0b110
#define  TIMER_COUNTER1_CAPTURE_EVENT       		0b111

#endif /* ADC_ADC_PRIVATE_H_ */
