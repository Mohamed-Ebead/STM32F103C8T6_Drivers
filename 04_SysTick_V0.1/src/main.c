/*
 * main.c
 *
 *  Created on: Aug 16, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SysTick_interface.h"
#include "SysTick_config.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"



void delay(void)
{
	for(int i = 0 ; i < 600 ; i++ )
{
	for(int j = 0 ; j < 600 ; j++ )
	{
		asm("NOP");
	}
}

}

u16 counter = 0 ;

int main(void)
{
	RCC_voidInitSysClock() ;

	GPIO_Handle_t GpioLed;
	GpioLed.pGPIOx = GPIOB;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_1;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_PP;
	GPIO_vidInit(&GpioLed);


	STK_voidInit();
	STK_voidLoadValue(1000) ; // 1 ms




	while(1)
	{
		//GPIO_ToggleOutputPin(GPIOB,GPIO_PIN_NO_1) ;
		//STK_voidDelay_ms_Polling(1000) ;



	}
	return 0;
}



void SysTick_Handler(void)
{
	counter ++ ;
	if (counter == 1000 )      // for 1 second
	{
		counter = 0 ;
		GPIO_ToggleOutputPin(GPIOB,GPIO_PIN_NO_1) ;
	}
}











