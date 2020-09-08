/*
 *
 *  Created on: Sep 6, 2020
 *      Author: Mohamed  Ebead
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DAC_interface.h"

#include "RCC_interface.h"

#include "STK_interface.h"




void main(void)
{
	/* RCC Initialize */
	RCC_voidInitSysClock();

	/* IO Pins Initialization */
	DAC_voidInit();

	/* SysTick Init */
	STK_voidInit(); /* Enable SysTick AHB/8 = 1MHZ */
	STK_voidSetIntervalPeriodic(125,&DAC_voidPlayAudio) ;


	while(1)
	{

	}

}
















