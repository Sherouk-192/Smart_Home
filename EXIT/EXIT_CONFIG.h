/*
 * EXIT_CONFIG.h
 *
 *  Created on: Oct 9, 2021
 *      Author: LENOVO
 */

#ifndef EXIT_CONFIG_H_
#define EXIT_CONFIG_H_

/*
 * DEFINE SENSE CONTROL FOR INT1 AND INT0
 * LOW_LEVEL  	: The low level of INT0 generates an interrupt request
 * TOGGLE 		: Any logical change on INT0 generates an interrupt request
 * FALING_EDGE 	: The falling edge of INT0 generates an interrupt request
 * RAISING_EDGE :  The rising edge of INT0 generates an interrupt request
 */

#define SENCE_CONROL_INIT0		FALING_EDGE
#define SENCE_CONROL_INIT1		FALING_EDGE


/*
 * DEFINE SENSE CONTROL FOR INT2
 * FALING_EDGE 	: The falling edge of INT0 generates an interrupt request
 * RAISING_EDGE :  The rising edge of INT0 generates an interrupt request
 */
#define SENCE_CONROL_INIT2	FALING_EDGE

#endif /* EXIT_CONFIG_H_ */
