/*
 *
 *  Created on: Sep 6, 2020
 *      Author: Mohamed  Ebead
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"

#include "EXTI0_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"

#include "IR_interface.h"
#include "RGB_LED_interface.h"
#include "RGB_LED_config.h"



void main(void)
{
	/* RCC Initialize */
	RCC_voidInitSysClock();

	/* IO Pins Initialization */
	IR_voidInit();
	RGB_voidInit();



	/* EXTI Initializtion */
	EXTI_voidSetCallBack(IR_voidGetFrame);
	EXTI_voidInit(); /* A0 EXTI0 Enabled / Falling Edge */

	/* Enable EXTI0 from NVIC */
	NVIC_voidInit();
	NVIC_voidEnableInterrupt(6); /* EXTI0 */

	/* SysTick Init */
	STK_voidInit(); /* Enable SysTick AHB/8 = 1MHZ */

	while(1)
	{

	}

}









