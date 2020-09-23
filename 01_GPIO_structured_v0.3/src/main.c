/*
 * main.c
 *
 *  Created on: Aug 16, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Led_interface.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"





int main(void)
{
	RCC_voidInitSysClock() ;


	RedLed_Init    () ;
	GreenLed_Init  () ;
	YellowLed_Init () ;


	RedLed_TurnOn    ();
	GreenLed_TurnOn  ();
	YellowLed_TurnOn ();

	while(1)
	{

	}
	return 0;
}
