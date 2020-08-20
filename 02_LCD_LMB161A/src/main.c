/*
 * main.c
 *
 *  Created on: Aug 16, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LCD_interface.h"

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

	LCD_vidInitialize();



	LCD_vidGotoxy(1,1) ;

	LCD_vidWriteCharacter('s') ;

	LCD_vidGotoxy(1,2) ;
	LCD_vidWriteInteger(1234,4) ;



	while(1)
	{

	}
	return 0;
}







