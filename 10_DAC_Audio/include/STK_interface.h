/*
 *
 *  Created on: Sep 6, 2020
 *      Author: Mohamed  Ebead
 */


#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


/* Apply Clock choice from configuration file 
   Disable SysTick interrupt 
   Disable Systick                          */
void STK_voidInit               (void);
void STK_voidStopInterval       (void);
u32  STK_u32GetElapsedTime      (void);
u32  STK_u32GetRemainingTime    (void);
void STK_voidSetBusyWait        ( u32 Copy_u32Ticks );
void STK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void STK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );

#endif







