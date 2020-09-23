/*
 * main.c
 *
 *  Created on: sept 23, 2020
 *      Author: Mohamed  Ebead
 */

/***
 * 	This is a program to compare between the speed of the processor and DMA
 * 	for copying a 1000 element of an array ,
 * 	the result is : the DMA finishes all the 1000 element while the processor is in the 332th element
 *
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"

#include "NVIC_interface.h"
#include "DMA_interface.h"



u16 Local_u16Index ;

int main(void)
{
	u32 Arr1[1000]={0};
	u32 Arr2[1000];

	u32 Arr3[1000]={0};
	u32 Arr4[1000];

	RCC_voidInitSysClock() ;
	DMA1_voidChannel1Init();

	NVIC_voidEnableInterrupt (11);
	DMA1_voidChannel1Start(Arr1,Arr2,1000);


	for(Local_u16Index=0;Local_u16Index<1000;Local_u16Index++)
	{
		Arr4[Local_u16Index]=Arr3[Local_u16Index];
	}



	while(1)
	{

	}
	return 0;
}


void DMA1_Channel1_IRQHandler(void)
{
	/*Clear Interrupt flag*/
	DMA1_voidClearGlobalInterruptFlag          (DMA_CHANNEL_1) ;		/*Clear Global Interrupt flag of channel1*/
	DMA1_voidClearTransferCompleteInterruptFlag(DMA_CHANNEL_1) ;		/*Clear transfer complete Interrupt flag of channel1*/
}












