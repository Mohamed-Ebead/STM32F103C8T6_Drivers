/*
 * SysTick_interface.h
 *
 *  Created on: Aug 25, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

/* Apply Clock choice from configuration file
   Disable SysTick interrupt
   Disable Systick                          */
void STK_voidInit(void);
void STK_voidSetBusyWait( u32 Copy_u32Ticks );
void STK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void STK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void STK_voidStopInterval(void);
u32  STK_u32GetElapsedTime(void);
u32  STK_u32GetRemainingTime(void);








#endif /* SYSTICK_INTERFACE_H_ */
