/*
 * main.c
 *
 *  Created on: Sep 15, 2020
 *      Author: Mohamed  Ebead
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STP_interface.h"

#include "RCC_interface.h"



int main (void)
{


	RCC_voidInitSysClock() ;



	STP1_voidInit();




	while(1)
	{
		STP1_voidSendSynchronous(0x55) ;
	}




	return 0 ;
}








