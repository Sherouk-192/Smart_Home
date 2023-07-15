/*
 * ADC_INTERFACE.h
 *
 *  Created on: Oct 9, 2021
 *      Author: LENOVO
 */

#ifndef ADC_ADC_INTERFACE_H_
#define ADC_ADC_INTERFACE_H_




#define ADC0						0b00000
#define ADC1						0b00001
#define ADC2						0b00010
#define ADC3						0b00011
#define ADC4						0b00100
#define ADC5						0b00101
#define ADC6						0b00110
#define ADC7						0b00111
#define ADC0_ADC0_10x						0b01000
#define ADC1_ADC0_10x						0b01001
#define ADC0_ADC0_200x						0b01010
#define ADC1_ADC0_200x						0b01011
#define ADC2_ADC2_10x						0b01100
#define ADC3_ADC2_10x						0b01101
#define ADC2_ADC2_200x						0b01110
#define ADC3_ADC2_200x						0b01111
#define ADC0_ADC1_1x						0b10000
#define ADC1_ADC1_1x						0b10001
#define ADC2_ADC1 1x						0b10010
#define ADC3_ADC1_1x						0b10011
#define ADC4_ADC1_1x						0b10100
#define ADC5_ADC1_1x						0b10101
#define ADC6_ADC1_1x						0b10110
#define ADC7_ADC1_1x						0b10111
#define ADC0_ADC2_1x						0b11000
#define ADC1_ADC2_1x						0b11001
#define ADC2_ADC2_1x						0b11010
#define ADC3_ADC2_1x						0b11011
#define ADC4_ADC2_1x						0b11100
#define ADC5_ADC2_1x						0b11101
#define VBG							0b11110
#define GND							0b11111


void ADC_vodInit(void);
u16 ADC_u16GetDigitalValue(u8 copy_u8ChannelNumber);
void ADC_SetCallBack(void (*FPTR)(void));
void ADC_vodEnable(void);
void ADC_vodDisable(void);
void ADC_vodEnableInterupt(void);
void ADC_vodDisableInterupt(void);
void ADC_vodGetData(void);
void ADC_vodStartConvergion(void);
void ADC_ISR(void);

















#endif /* ADC_ADC_INTERFACE_H_ */
