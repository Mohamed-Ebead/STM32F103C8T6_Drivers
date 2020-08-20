/**
 * main.c
 *
 *  Author     : Mohamed  Ebead.
 *  Created on : Aug 11, 2020
 *  version    :  0.1
 *
 *
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "RCC_interface.h"
#include "RCC_private.h"


void Delay (void)
{
	for(int i = 0 ; i < 600 ; i++ )
{
	for(int j = 0 ; j < 600 ; j++ )
	{
		asm("NOP");
	}
}

}

int main (void)
{

	RCC_voidInitSysClock() ;
	//RCC_void_EnableClock(RCC_APB2 , RCC_PORT) ;
//	RCC_void_EnableClock(RCC_APB2 , RCC_PORTB) ;
	//RCC_void_EnableClock(RCC_APB2 , RCC_PORTC) ;


	//GPIO_VidSetPinDirection(GPIOB , PIN0 , OUTPUT_10MHZ_PP);
	//GPIO_VidSetPortDirection (GPIOA , OUTPUT_PORT_10MHZ_PP) ;

	while (1)
	{
		// GPIO_VidSetPortValue      ( GPIOB , 0xFFFFFFFF );

		//GPIO_VidSetPinValue(GPIOB , PIN0  , LOW);

	//	 GPIO_VidSetPortValue(GPIOB , PORT_LOW) ;

		// Delay();

	    //GPIO_VidSetPortValue      ( GPIOB , 0x00000000 );

		//GPIO_VidSetPinValue(GPIOB , PIN0  , LOW);

		// GPIO_VidSetPortValue(GPIOB , PORT_LOW) ;

		// Delay();

	}


	return 0 ;
}







