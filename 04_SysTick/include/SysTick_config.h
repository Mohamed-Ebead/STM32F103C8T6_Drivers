/*
 * SysTick_config.h
 *
 *  Created on: Aug 25, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef SYSTICK_CONFIG_H_
#define SYSTICK_CONFIG_H_


/**
 * SYSTICK  clock source
 * options : STK_CLK_AHB_DIV_8
 * 			 STK_CLK_AHB
 */
#define STK_CLKSOURCE        STK_CLK_AHB_DIV_8

/**
 * SYSTICK  TICK INTERRUPT
 * options : STK_TICKINT_DISABLE
 * 			 STK_TICKINT_ENABLE
 */
#define STK_TICK_INTERRUPT   STK_TICKINT_ENABLE



/**
 * SYSTICK  COUNTER
 * options : STK_COUNTER_ENABLE
 * 			 STK_COUNTER_DISABLE
 */
#define STK_COUNTER           STK_COUNTER_ENABLE








#endif /* SYSTICK_CONFIG_H_ */





