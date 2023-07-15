/*
 * KEYBAD_INER.h
 *
 *  Created on: Sep 18, 2021
 *      Author: LENOVO
 */

#ifndef KEYPADDR_KEYBAD_INER_H_
#define KEYPADDR_KEYBAD_INER_H_

#include "../LIB/STD_TYPES.h"
void KeyPadIniit(void);

u8 KeyPadGetPresedKey(void);
u8 KeyPadGetPresedOperation(void);
u8 KeyPadAskForResult(void);
u8 KeyPadAskForSign(void);
u8 KeyPadAskForFloat(void);

#endif /* KEYPADDR_KEYBAD_INER_H_ */
