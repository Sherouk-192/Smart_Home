/*
 * EXIT_INTERFACE.h
 *
 *  Created on: Oct 8, 2021
 *      Author: LENOVO
 */

#ifndef EXIT_INTERFACE_H_
#define EXIT_INTERFACE_H_
#include "../LIB/STD_TYPES.h"
void EXIT_Init(void);
void EXIT_EnableExtint(u8 Initid);
void EXIT_DisableExtint(u8 Initid);
void EXTI_SetCallBack(u8 intid, void (*FPTR)(void));

#define INTF0			6
#define INTF1			7
#define INTF2			5
#define int0			0
#define int1			1
#define int2			2
#endif /* EXIT_INTERFACE_H_ */
