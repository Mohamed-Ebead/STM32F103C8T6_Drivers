/*
 * main.c
 *
 *  Created on: September 1, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED_Matrix_interface.h"
#include "LED_Matrix_private.h"
#include "LED_Matrix_config.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "SysTick_interface.h"




int main(void)
{
	RCC_voidInitSysClock() ;

	STK_voidInit() ;

	LEDMATREX_voidInit ();




	while (1)
	{

		LEDMATREX_voidDisplayMyName();


	}


	return 0;
}








