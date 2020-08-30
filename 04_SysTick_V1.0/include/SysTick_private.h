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
	volatile u32 CALIB ;

}STK_RegDef_t;


//#define STK_BASE_ADDRESS  (*(volatile(u32*)0xE000E010))

#define STK               ((volatile STK_RegDef_t*)0xE000E010)


#define STK_CTRL_EN           0
#define STK_CTRL_TICK_INT     1
#define STK_CTRL_CLK_SOURCE   2

#define STK_CTRL_COUNT_FLAG   16


#define STK_CLK_AHB_DIV_8     0
#define STK_CLK_AHB           1


#define STK_TICKINT_DISABLE   0
#define STK_TICKINT_ENABLE    1

#define STK_COUNTER_DISABLE   0
#define STK_COUNTER_ENABLE    1




/* Wait value type Macros */
#define STK_TICKS 					0
#define STK_MILLIS 					1
#define STK_MICROS 					2
#define STK_SECONDS 					3

/* Wait value divider Macros */
#define STK_MILLIS_DIVIDER			1000	/* Value used to calculate Load value in the wait functions when the wait value is in milliseconds */
#define STK_MICROS_DIVIDER			1000000	/* Value used to calculate Load value in the wait functions when the wait value is in microseconds */

/* Interval Macros definitions */
#define STK_U8_SINGLE_INTERVAL			0
#define STK_U8_PERIODIC_INTERVAL		1




/* PRIVATE variables */
u8 STK_u8PvtIntervalState = 0;

/** Pointer to function to be used as call back function */
void (* CallBack)(void);




#endif /* SYSTICK_PRIVATE_H_ */



