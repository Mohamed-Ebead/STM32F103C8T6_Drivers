/*
 * SysTick_interface.h
 *
 *  Created on: Aug 25, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

void STK_voidInit (void) ;

void STK_voidLoadValue (u32 Copy_u8LoadValue) ;

u32 STK_u32GetCurrentValue (void ) ;

#endif /* SYSTICK_INTERFACE_H_ */
