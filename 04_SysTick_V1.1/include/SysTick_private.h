/*
 * SysTick_private.h
 *
 *  Created on: Aug 25, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_



typedef struct
{
	volatile u32 CTRL  ;
	volatile u32 LOAD  ;
	volatile u32 VAL   ;
}STK_RegDef_t;

#define     STK    ((STK_RegDef_t*)0xE000E010)


#define     STK_SRC_AHB           0
#define     STK_SRC_AHB_8         1

#define     STK_SINGLE_INTERVAL    0
#define     STK_PERIOD_INTERVAL    1




#endif /* SYSTICK_PRIVATE_H_ */



