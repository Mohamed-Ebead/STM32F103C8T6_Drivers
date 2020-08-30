/*
 * SysTick_interface.h
 *
 *  Created on: Aug 25, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

//




void STK_voidInit(void) ;


void STK_voidEnableTICKInterrupt(void);
void STK_voidDisableTICKInterrupt(void);


void STK_voidEnableCounter(void) ;
void STK_voidDisbleCounter(void);



void STK_voidLoadVal(u32 Cpy_u32LoadVal);

u32 STK_u32GetCurrentVal(void);


void STK_voidSetBusyWait(u32 Cpy_u32DelayVal, u8 Cpy_u8ValueType, void (*func)(void));

void STK_voidSetSingleInterval(u32 Cpy_u32DelayVal, u8 Cpy_u8ValueType, void (*func)(void));

void STK_voidSetPeriodicInterval(u32 Cpy_u32DelayVal, u8 Cpy_u8ValueType, void (*func)(void));


u32 STK_u32GetElapsedTime(u8 Cpy_u8TimeType);

u32 STK_u32GetRemainingTime(u8 Cpy_u8TimeType);

void STK_voidStopTimer(void);








#endif /* SYSTICK_INTERFACE_H_ */
