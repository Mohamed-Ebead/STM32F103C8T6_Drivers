/*
 * main.c
 *
 *  Created on: Aug 16, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RTOS_interface.h"

#include "Led_interface.h"

#include "SysTick_interface.h"
#include "SysTick_config.h"

#include "RCC_interface.h"




int main(void)
{
	RCC_voidInitSysClock() ;



	RedLed_Init    () ;
	GreenLed_Init  () ;
	YellowLed_Init () ;

	RTOS_Init();

	RTOS_vid_CreateTask(0 ,3000 ,0 ,   &RedLed_Toggle    ) ;
	RTOS_vid_CreateTask(1 ,3000 ,1000 ,&GreenLed_Toggle  ) ;
	RTOS_vid_CreateTask(2 ,3000 ,2000 ,&YellowLed_Toggle ) ;



	STK_voidInit();
	STK_voidLoadValue(1000) ; // 1 ms




	while(1)
	{

	}
	return 0;
}












