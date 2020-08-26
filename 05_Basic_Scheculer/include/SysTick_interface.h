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

void STK_voidDelay_ms_Polling (u16 Copy_u16MilliSeconds) ;
void STK_voidDelay_us_Polling (u16 Copy_u16MicroSeconds) ;

//  RTOS SPECIFIC
void STK_SetCallBack (void (*local_pFn)(void)) ;



#endif /* SYSTICK_INTERFACE_H_ */







