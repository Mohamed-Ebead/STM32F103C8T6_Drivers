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





#endif /* SYSTICK_PRIVATE_H_ */



