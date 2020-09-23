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


/***
 * This is a full options  DMA driver
 */

extern u32 Arr1[1000] ;
extern u32 Arr2[1000] ;


/**--------------------------------------------------------------------------------------------------------*/

void DMA1_voidInitChannel1(void)
{

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

	DMA_Handle_t DMA1_CH1 ;
	DMA1_CH1.pDMA = DMA1 ;
	DMA1_CH1.SourceAddress = Arr1 ;
	DMA1_CH1.DestinationAddress = Arr2 ;
	DMA1_CH1.BlockLength = 1000 ;
	DMA1_CH1.DMA_Config.Channel = DMA_CHANNEL_1 ;
	DMA1_CH1.DMA_Config.Mem2Mem = DMAMEM2MEM_ENABLE ;
	DMA1_CH1.DMA_Config.PriorityLevel  = DMA_PL_VERYHIGH ;
	DMA1_CH1.DMA_Config.MemorySize     = DMA_MEMORY_SIZE_32_BITS ;
	DMA1_CH1.DMA_Config.PeripheralSize = DMA_PERIPHERAL_SIZE_32_BITS ;
	DMA1_CH1.DMA_Config.MemoryIncrementMode    = DMA_MEMORY_INCREMENT_MODE_ENABLE ;
	DMA1_CH1.DMA_Config.PeripheralIncrementMode = DMA_PERIPHERAL_INCREMENT_MODE_ENABLE ;
	DMA1_CH1.DMA_Config.CircularMode            = DMA_CIRCULAR_MODE_DISABLE ;
	DMA1_CH1.DMA_Config.DataTransferDirection   = DMA_DIR_READ_FROM_PERIPHERAL ;
	DMA1_CH1.DMA_Config.TransferCompleteInterrupt = DMA_TCI_ENABLE ;
	DMA1_CH1.DMA_Config.TransferErrorInterrupt    = DMA_TEI_DISABLE ;
	DMA1_CH1.DMA_Config.HalfTransferErrorInterrupt = DMA_HTEI_DISABLE ;

	DMA_voidInit(&DMA1_CH1) ;

}

/**---------------------------------------------------------------------------------------------------------*/

void DMA_voidInit(DMA_Handle_t * pDMA_Handle)
{
	u32 Local_u32TempRegister = 0 ;

	/*Enable clock on DMA Peripheral*/
	DMA_PeriphControlClock (pDMA_Handle->pDMA,ENABLE) ;

	// Mem2Mem
	switch (pDMA_Handle->DMA_Config.Mem2Mem)
	{
	case DMAMEM2MEM_ENABLE  : SET_BIT(Local_u32TempRegister , DMA_CCR_MEM2MEM) ; break ;
	case DMAMEM2MEM_DISABLE : CLR_BIT(Local_u32TempRegister , DMA_CCR_MEM2MEM) ; break ;
	default : break ;
	}

	// PriorityLevel
	switch (pDMA_Handle->DMA_Config.PriorityLevel)
	{
	case DMA_PL_LOW  :
		CLR_BIT(Local_u32TempRegister , DMA_CCR_PL0) ;
		CLR_BIT(Local_u32TempRegister , DMA_CCR_PL1) ;
		break ;
	case DMA_PL_MEDIUM :
		SET_BIT(Local_u32TempRegister , DMA_CCR_PL0) ;
		CLR_BIT(Local_u32TempRegister , DMA_CCR_PL1) ;
		break ;
	case DMA_PL_HIGH  :
		CLR_BIT(Local_u32TempRegister , DMA_CCR_PL0) ;
		SET_BIT(Local_u32TempRegister , DMA_CCR_PL1) ;
		break ;
	case DMA_PL_VERYHIGH :
		SET_BIT(Local_u32TempRegister , DMA_CCR_PL0) ;
		SET_BIT(Local_u32TempRegister , DMA_CCR_PL1) ;
		break ;
	default : break ;
	}


	// MemorySize
	switch (pDMA_Handle->DMA_Config.MemorySize)
	{
	case DMA_MEMORY_SIZE_8_BITS  :
		CLR_BIT(Local_u32TempRegister , DMA_CCR_MSIZE0) ;
		CLR_BIT(Local_u32TempRegister , DMA_CCR_MSIZE1) ;
		break ;
	case DMA_MEMORY_SIZE_16_BITS :
		SET_BIT(Local_u32TempRegister , DMA_CCR_MSIZE0) ;
		CLR_BIT(Local_u32TempRegister , DMA_CCR_MSIZE1) ;
		break ;
	case DMA_MEMORY_SIZE_32_BITS :
		CLR_BIT(Local_u32TempRegister , DMA_CCR_MSIZE0) ;
		SET_BIT(Local_u32TempRegister , DMA_CCR_MSIZE1) ;
		break ;
	default : break ;
	}


	// PeripheralSize
	switch (pDMA_Handle->DMA_Config.PeripheralSize)
	{
	case DMA_PERIPHERAL_SIZE_8_BITS  :
		CLR_BIT(Local_u32TempRegister , DMA_CCR_PSIZE0) ;
		CLR_BIT(Local_u32TempRegister , DMA_CCR_PSIZE1) ;
		break ;
	case DMA_PERIPHERAL_SIZE_16_BITS :
		SET_BIT(Local_u32TempRegister , DMA_CCR_PSIZE0) ;
		CLR_BIT(Local_u32TempRegister , DMA_CCR_PSIZE1) ;
		break ;
	case DMA_PERIPHERAL_SIZE_32_BITS :
		CLR_BIT(Local_u32TempRegister , DMA_CCR_PSIZE0) ;
		SET_BIT(Local_u32TempRegister , DMA_CCR_PSIZE1) ;
		break ;
	default : break ;
	}

	// MemoryIncrementMode
	switch (pDMA_Handle->DMA_Config.MemoryIncrementMode)
	{
	case DMA_MEMORY_INCREMENT_MODE_ENABLE  :SET_BIT(Local_u32TempRegister , DMA_CCR_MINC) ; break ;
	case DMA_MEMORY_INCREMENT_MODE_DISABLE :CLR_BIT(Local_u32TempRegister , DMA_CCR_MINC) ; break ;
	default : break ;
	}

	// PeripheralIncrementMode
	switch (pDMA_Handle->DMA_Config.PeripheralIncrementMode)
	{
	case DMA_PERIPHERAL_INCREMENT_MODE_ENABLE  :SET_BIT(Local_u32TempRegister , DMA_CCR_PINC) ; break ;
	case DMA_PERIPHERAL_INCREMENT_MODE_DISABLE :CLR_BIT(Local_u32TempRegister , DMA_CCR_PINC) ; break ;
	default : break ;
	}

	// CircularMode
	switch (pDMA_Handle->DMA_Config.CircularMode)
	{
	case DMA_CIRCULAR_MODE_ENABLE  :SET_BIT(Local_u32TempRegister , DMA_CCR_CIRC) ; break ;
	case DMA_CIRCULAR_MODE_DISABLE :CLR_BIT(Local_u32TempRegister , DMA_CCR_CIRC) ; break ;
	default : break ;
	}

	// DataTransferDirection
	switch (pDMA_Handle->DMA_Config.DataTransferDirection)
	{
	case DMA_DIR_READ_FROM_MEMORY     :SET_BIT(Local_u32TempRegister , DMA_CCR_DIR) ; break ;
	case DMA_DIR_READ_FROM_PERIPHERAL :CLR_BIT(Local_u32TempRegister , DMA_CCR_DIR) ; break ;
	default : break ;
	}

	// TransferErrorInterrupt
	switch (pDMA_Handle->DMA_Config.TransferErrorInterrupt)
	{
	case DMA_TEI_ENABLE  :SET_BIT(Local_u32TempRegister , DMA_CCR_TEIE) ; break ;
	case DMA_TEI_DISABLE :CLR_BIT(Local_u32TempRegister , DMA_CCR_TEIE) ; break ;
	default : break ;
	}

	// HalfTransferErrorInterrupt
	switch (pDMA_Handle->DMA_Config.HalfTransferErrorInterrupt)
	{
	case DMA_HTEI_ENABLE  :SET_BIT(Local_u32TempRegister , DMA_CCR_HTIE) ; break ;
	case DMA_HTEI_DISABLE :CLR_BIT(Local_u32TempRegister , DMA_CCR_HTIE) ; break ;
	default : break ;
	}

	// TransferCompleteInterrupt
	switch (pDMA_Handle->DMA_Config.TransferCompleteInterrupt)
	{
	case DMA_TCI_ENABLE  :SET_BIT(Local_u32TempRegister , DMA_CCR_TCIE) ; break ;
	case DMA_TCI_DISABLE :CLR_BIT(Local_u32TempRegister , DMA_CCR_TCIE) ; break ;
	default : break ;
	}

	// disable channel
	CLR_BIT(Local_u32TempRegister , DMA_CCR_EN) ;

	// Apply all configurations
	pDMA_Handle->pDMA->Channel[(pDMA_Handle->DMA_Config.Channel)].CCR = Local_u32TempRegister ;

	// set source address
	pDMA_Handle->pDMA->Channel[(pDMA_Handle->DMA_Config.Channel)].CPAR = (u32)(pDMA_Handle->SourceAddress);

	// set DestinationAddress
	pDMA_Handle->pDMA->Channel[(pDMA_Handle->DMA_Config.Channel)].CMAR =  (u32)(pDMA_Handle->DestinationAddress) ;

	// set the block length
	pDMA_Handle->pDMA->Channel[(pDMA_Handle->DMA_Config.Channel)].CNDTR = pDMA_Handle->BlockLength ;

}

/**--------------------------------------------------------------------------------------------------------*/
void DMA_voidStart( DMA_RegDef_t *pDMA , u8 Copy_u8Channel)
{
	// Enable required channel
	pDMA->Channel[Copy_u8Channel].CCR |= (1<<DMA_CCR_EN) ;
}

/**--------------------------------------------------------------------------------------------------------*/

void DMA1_voidClearGlobalInterruptFlag           (u8 Copy_u8Channel)
{
	DMA1->IFCR |= ( 1<<(4*Copy_u8Channel) )  ;		/*Clear Global Interrupt flag of channel1*/
}

/**--------------------------------------------------------------------------------------------------------*/

void DMA1_voidClearTransferCompleteInterruptFlag (u8 Copy_u8Channel)
{
	DMA1->IFCR |= ( 1<<(1+(4*Copy_u8Channel)) )  ;		/*Clear transfer complete Interrupt flag of channel1*/

}

/**--------------------------------------------------------------------------------------------------------*/
void DMA_PeriphControlClock (DMA_RegDef_t *pDMA , u8 EnOrDis)
{
	if 		(EnOrDis == ENABLE)
	{
		if 		( pDMA == DMA1 )
		{
			RCC_void_EnableClock(RCC_AHB , RCC_DMA1) ;
		}
		else if (pDMA == DMA2)
		{
			RCC_void_EnableClock(RCC_AHB , RCC_DMA2) ;
		}
		else
		{
			 // invalid DMA peripheral
		}
	}
	else if (EnOrDis == DISABLE)
	{
		if 		( pDMA == DMA1 )
		{
			RCC_void_EnableClock(RCC_AHB , RCC_DMA1) ;
		}
		else if (pDMA == DMA2)
		{
			RCC_void_EnableClock(RCC_AHB , RCC_DMA2) ;
		}
		else
		{
			 // invalid DMA peripheral
		}
	}
	else
	{
		// invalic MACRO
	}

}

/**---------------------------------------------------------------------------------------------------------*/














