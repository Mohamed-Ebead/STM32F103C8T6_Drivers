/*
 * RTOS_interface.h
 *
 *  Created on: Aug 26, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_


void RTOS_Init(void) ;
void RTOS_vid_CreateTask (u8 copy_u8Priority ,u16 copy_u16Priodicity ,u16 copy_u16FirstDelay ,void (*copy_pFn)(void) ) ;

#endif /* RTOS_INTERFACE_H_ */
