/*
 * GIE_PROGRAM.c
 *
 *  Created on: Oct 9, 2021
 *      Author: LENOVO
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"


#include "GIE_INTERFACE.h"
#include "GIE_PRIVTE.h"

void GIE_Enable(void)
{
	SET_BIT(SREG,SREG_I);

}
void GIE_Disable(void)

{
	CLR_BIT(SREG,SREG_I);
}
