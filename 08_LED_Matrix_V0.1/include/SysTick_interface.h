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







#endif /* SYSTICK_INTERFACE_H_ */
