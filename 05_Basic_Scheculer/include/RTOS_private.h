/*
 * RTOS_private.h
 *
 *  Created on: Aug 26, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_


typedef struct
{
	u16 u16_Periocicity ;
	u16 u16_FirstDelay ;

	void (*pFn) (void) ;

}Task_TCB;


static void RTO_vid_StartSchedular (void) ;


#endif /* RTOS_PRIVATE_H_ */
