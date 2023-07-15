/*
 * EXTI_PRIVATE.h
 *
 *  Created on: Oct 8, 2021
 *      Author: LENOVO
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_
#define MCUCR			*((volatile u8*)(0x55))
#define ISC00			0
#define ISC01			1
#define ISC10			2
#define ISC11			3
#define MCUCSR			*((volatile u8*)(0x54))
#define ISC2			6
#define GICR			*((volatile u8*)(0x5B))

#define GIFR			*((volatile u8*)(0x5A))

#define LOW_LEVEL		0
#define TOGGLE			1
#define FALING_EDGE		2
#define RAISING_EDGE	3


#endif /* EXTI_PRIVATE_H_ */
