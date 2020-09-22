/*
 * main.c
 *
 *  Created on: Sep 15, 2020
 *      Author: Mohamed  Ebead
 */
#include<string.h>


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "STK_interface.h"

#include "SPI_interface.h"
#include "TFT_interface.h"
#include "image.h"



int main (void)
{


	RCC_voidInitSysClock() ;
	STK_voidInit();

	SPI1_voidInit();

	TFT_voidInit() ;

	TFT_voidDisplayImage(image) ;


	while(1)
	{

	}


	return 0 ;
}








