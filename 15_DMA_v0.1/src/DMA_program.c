/*
 * DMA_program.c
 *
 *  Created on: Sep 23, 2020
 *      Author: Mohamed  Ebead
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"

#include "DMA_interface.h"
#include "DMA_config.h"
#include "DMA_private.h"

/**--------------------------------------------------------------------------------------------------------*/

void DMA1_voidChannel1Init(void)
{
	/*Enable clock on DMA Peripheral*/
	RCC_void_EnableClock(RCC_AHB , RCC_DMA1) ;

	/*
		Memory to memory
		Priority very high
		Source, destination size=32bit
		MINC , PINC activated
		No circular
		Direction: peripheral to memory
		Transfer complete interrupt enable
		Channel Disable
	*/
	DMA1->Channel[0].CCR=0x00007AC2;
}

/**--------------------------------------------------------------------------------------------------------*/

void DMA1_voidChannel1Start(u32* Copy_pu32SourceAddress, u32* Copy_pu32DestinationAddress, u16 Copy_u16BlockLength)
{
	/*Make sure channel is disabled*/
	CLR_BIT(DMA1->Channel[0].CCR,0);
	/*Load the addresses*/
	DMA1->Channel[0].CPAR=Copy_pu32SourceAddress;
	DMA1->Channel[0].CMAR=Copy_pu32DestinationAddress;

	/*Load the block length*/
	DMA1->Channel[0].CNDTR=Copy_u16BlockLength;

	SET_BIT(DMA1->Channel[0].CCR,0);
}

/**--------------------------------------------------------------------------------------------------------*/

void DMA1_voidClearGlobalInterruptFlag           (u8 Copy_u8Channel)
{
	DMA1->IFCR |= ( 1<<(4*Copy_u8Channel) )  ;		/*Clear Global Interrupt flag of channel1*/
}


void DMA1_voidClearTransferCompleteInterruptFlag (u8 Copy_u8Channel)
{
	DMA1->IFCR |= ( 1<<(1+(4*Copy_u8Channel)) )  ;		/*Clear transfer complete Interrupt flag of channel1*/

}


