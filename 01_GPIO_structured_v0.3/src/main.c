/*
 * main.c
 *
 *  Created on: Aug 16, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"


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


int main(void)
{
	RCC_voidInitSysClock() ;

	//RCC_void_EnableClock(RCC_APB2 , RCC_PORTA) ;

	/*GPIO_Handle_t GpioLed;

	GpioLed.pGPIOx = GPIOB;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_PP;

	GPIO_vidInit(&GpioLed);*/





/*	GPIO_Handle_t SSD;

	SSD.pGPIOx = GPIOA;
	SSD.GPIO_ByteConfig.GPIO_ByteNumber  = GPIO_LOWER_BYTE ;
SSD.GPIO_ByteConfig.GPIO_ByteMode = GPIO_BYTE_OUTPUT_10MHZ_PP ;

	GPIO_vidInitByte(&SSD) ;

	*/


	//delay() ;


	while(1)
	{


//GPIO_WriteToOutputByte(GPIOA,GPIO_LOWER_BYTE,0xAA);

		/*GPIO_WriteToOutputPin(GPIOB,GPIO_PIN_NO_12,GPIO_PIN_SET) ;
	GPIO_WriteToOutputPin(GPIOB,GPIO_PIN_NO_13,GPIO_PIN_SET) ;
	GPIO_WriteToOutputPin(GPIOB,GPIO_PIN_NO_14,GPIO_PIN_SET) ;
	GPIO_WriteToOutputPin(GPIOB,GPIO_PIN_NO_15,GPIO_PIN_SET) ;*/


		//GPIO_ToggleOutputPin(GPIOB,GPIO_PIN_NO_0);
	//	for (u32 delay = 0 ;delay <80000 ; delay ++ ) ;
	// delay();

		/*GPIO_WriteToOutputPin(GPIOB,GPIO_PIN_NO_12,GPIO_PIN_RESET) ;
		GPIO_WriteToOutputPin(GPIOB,GPIO_PIN_NO_13,GPIO_PIN_RESET) ;
		GPIO_WriteToOutputPin(GPIOB,GPIO_PIN_NO_14,GPIO_PIN_RESET) ;
		GPIO_WriteToOutputPin(GPIOB,GPIO_PIN_NO_15,GPIO_PIN_RESET) ;
	//  GPIO_WriteToOutputPin(GPIOA,GPIO_PIN_NO_0,GPIO_PIN_RESET) ;*/
	//  delay();

	}
	return 0;
}
