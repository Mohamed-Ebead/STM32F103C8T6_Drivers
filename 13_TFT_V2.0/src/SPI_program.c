/*
 * SPI_program.c
 *
 *  Created on: Sep 18, 2020
 *      Author: Mohamed  Ebead
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_config.h"
//#include "SPI_private.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"


/**-------------------------------------------------------------------------------------------------------------------*/
/**
 * @fun     SPI1_voidInit
 * @brief
 */
void SPI1_voidInit (void)
{
	//SPI1_voidInitGPIO();
	SPI_Handle_t SPI1handle;

	SPI1handle.pSPIx = SPI1;
	SPI1handle.SPIConfig.SPI_BusConfig  = SPI_BUS_CONFIG_FULLDUPLEX;
	SPI1handle.SPIConfig.SPI_DeviceMode = SPI_DEVICE_MODE_MASTER;
	SPI1handle.SPIConfig.SPI_SclkSpeed  = SPI_SCLK_SPEED_DIV2;//generates sclk of 8MHz
	SPI1handle.SPIConfig.SPI_DFF        = SPI_DFF_8BITS;
	SPI1handle.SPIConfig.SPI_CPOL       = SPI_CPOL_HIGH;
	SPI1handle.SPIConfig.SPI_CPHASE     = SPI_CPHA_HIGH;
	SPI1handle.SPIConfig.SPI_SSM        = SPI_SSM_EN; //software slave management enabled for NSS pin
	SPI1handle.SPIConfig.SPI_SSI        = SPI_SSI_EN;

	SPI_Init(&SPI1handle);

}

/**-------------------------------------------------------------------------------------------------------------------*/
/**
 *
 */
void SPI2_voidInit (void)
{
	SPI2_voidInitGPIO();

	SPI_Handle_t SPI2handle;

	SPI2handle.pSPIx = SPI2;
	SPI2handle.SPIConfig.SPI_BusConfig  = SPI_BUS_CONFIG_FULLDUPLEX;
	SPI2handle.SPIConfig.SPI_DeviceMode = SPI_DEVICE_MODE_MASTER;
	SPI2handle.SPIConfig.SPI_SclkSpeed  = SPI_SCLK_SPEED_DIV2;//generates sclk of 8MHz
	SPI2handle.SPIConfig.SPI_DFF        = SPI_DFF_8BITS;
	SPI2handle.SPIConfig.SPI_CPOL       = SPI_CPOL_HIGH;
	SPI2handle.SPIConfig.SPI_CPHASE     = SPI_CPHA_HIGH;
	SPI2handle.SPIConfig.SPI_SSM        = SPI_SSM_EN;    //software slave management enabled for NSS pin
	SPI2handle.SPIConfig.SPI_SSI        = SPI_SSI_EN;

	SPI_Init(&SPI2handle);

}
/**-------------------------------------------------------------------------------------------------------------------*/
/**
 *
 */
void SPI1_voidInitGPIO (void)
{
	GPIO_Handle_t SPI1Pins ;
	SPI1Pins.pGPIOx = GPIOA ;
	SPI1Pins.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_AFPP ;

	//NSS
//	SPI1Pins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_4 ;
//	GPIO_vidInit(&SPI1Pins) ;

	//SCLK
	SPI1Pins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5 ;
	GPIO_vidInit(&SPI1Pins) ;

	//MISO
//	SPI1Pins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_6 ;
//	GPIO_vidInit(&SPI1Pins) ;

	//MOSI
	SPI1Pins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_7 ;
	GPIO_vidInit(&SPI1Pins) ;



}

/**-------------------------------------------------------------------------------------------------------------------*/
/**
 *
 */
void SPI2_voidInitGPIO (void)
{
	GPIO_Handle_t SPI2Pins ;
	SPI2Pins.pGPIOx = GPIOA ;
	SPI2Pins.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_AFPP ;

	//NSS
	SPI2Pins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12 ;
	GPIO_vidInit(&SPI2Pins) ;

	//SCLK
	SPI2Pins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13 ;
	GPIO_vidInit(&SPI2Pins) ;

	//MISO
	SPI2Pins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14 ;
	GPIO_vidInit(&SPI2Pins) ;

	//MOSI
	SPI2Pins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15 ;
	GPIO_vidInit(&SPI2Pins) ;


}

/**-------------------------------------------------------------------------------------------------------------------*/
/**
 *
 * @param pSPIx
 * @param EnOrDi
 */
void SPI_ControlPeripheral(SPI_RegDef_t *pSPIx, u8 EnOrDi)
{
	if(EnOrDi == ENABLE)
	{
		pSPIx->CR1 |=  (1 << SPI_CR1_SPE);
	}else
	{
		pSPIx->CR1 &=  ~(1 << SPI_CR1_SPE);
	}


}

/**-------------------------------------------------------------------------------------------------------------------*/
/**
 *
 * @param pSPIx
 * @param EnorDi
 */
void SPI_PeriClockControl (SPI_RegDef_t *pSPIx, u8 EnorDi)
{
	if (EnorDi == ENABLE)
	{
		if      (pSPIx == SPI1)
		{
			RCC_voidEnableClock  (RCC_APB2 ,RCC_SPI1 ) ;
		}
		else if (pSPIx == SPI2)
		{
			RCC_voidEnableClock  (RCC_APB1 ,RCC_SPI2 ) ;
		}
		else if (pSPIx == SPI3)
		{
			RCC_voidEnableClock  (RCC_APB1 ,RCC_SPI3 ) ;
		}
		else
		{
			// INVALID SPI PERIPHERAL
		}

	}
	else if (EnorDi == DISABLE)
	{
		if      (pSPIx == SPI1)
		{
			RCC_voidDisableClock  (RCC_APB2 ,RCC_SPI1 ) ;
		}
		else if (pSPIx == SPI2)
		{
			RCC_voidDisableClock  (RCC_APB1 ,RCC_SPI2 ) ;
		}
		else if (pSPIx == SPI3)
		{
			RCC_voidDisableClock  (RCC_APB1 ,RCC_SPI3 ) ;
		}
		else
		{
			// INVALID SPI PERIPHERAL
		}

	}
	else
	{
		// ERROR PARAMETER ENABLE OR DISABLE MACRO
	}

}

/**-------------------------------------------------------------------------------------------------------------------*/
/**
 *
 * @param pSPIHandle
 */
void SPI_Init   (SPI_Handle_t *pSPIHandle)
{
	//peripheral clock enable
	SPI_PeriClockControl (pSPIHandle->pSPIx,ENABLE ) ;

	//first lets configure the SPI_CR1 register

	u32 Local_u32TempRegister = 0;

	//1. configure the device mode
	Local_u32TempRegister |= pSPIHandle->SPIConfig.SPI_DeviceMode << SPI_CR1_MSTR ;

	//2. Configure the bus config
	if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FULLDUPLEX)
	{
		//bidi mode should be cleared
		Local_u32TempRegister &= ~( 1 << SPI_CR1_BIDIMODE);

	}
	else if (pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HALFDUPLEX)
	{
		//bidi mode should be set
		Local_u32TempRegister |= ( 1 << SPI_CR1_BIDIMODE);
	}
	else if (pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RXONLY)
	{
		//BIDI mode should be cleared
		Local_u32TempRegister &= ~( 1 << SPI_CR1_BIDIMODE);
		//RXONLY bit must be set
		Local_u32TempRegister |= ( 1 << SPI_CR1_RXONLY);
	}

	// 3. Configure the spi serial clock speed (baud rate)
	Local_u32TempRegister |= pSPIHandle->SPIConfig.SPI_SclkSpeed << SPI_CR1_BR;

	//4.  Configure the DFF
	Local_u32TempRegister |= pSPIHandle->SPIConfig.SPI_DFF << SPI_CR1_DFF;

	//5. configure the CPOL
	Local_u32TempRegister |= pSPIHandle->SPIConfig.SPI_CPOL << SPI_CR1_CPOL;

	//6 . configure the CPHA
	Local_u32TempRegister |= pSPIHandle->SPIConfig.SPI_CPHASE << SPI_CR1_CPHA;

	Local_u32TempRegister |= pSPIHandle->SPIConfig.SPI_SSM << SPI_CR1_SSM;
	Local_u32TempRegister |= pSPIHandle->SPIConfig.SPI_SSI << SPI_CR1_SSI;

	pSPIHandle->pSPIx->CR1 = Local_u32TempRegister ;

	SPI_ControlPeripheral(pSPIHandle->pSPIx , ENABLE) ;

}

/**-------------------------------------------------------------------------------------------------------------------*/
/**
 *
 * @param pSPIx
 */
void SPI_DeInit (SPI_RegDef_t *pSPIx)
{
	//peripheral clock enable
	SPI_PeriClockControl (pSPIx,DISABLE ) ;
}

/**-------------------------------------------------------------------------------------------------------------------*/
/**
 *
 * @param pSPIx
 * @param FlagName
 * @return
 */
u8 SPI_GetFlagStatus(SPI_RegDef_t *pSPIx , u32 FlagName)
{
	if(pSPIx->SR & FlagName)
	{
		return FLAG_SET;
	}
	return FLAG_RESET;
}
/**-------------------------------------------------------------------------------------------------------------------*/
/**
 *
 * @param pSPIx
 * @param pTxBuffer
 * @param Len
 */
void SPI_SendDataSynch    (SPI_RegDef_t *pSPIx,u8 *pTxBuffer, u32 Copy_u32NumberOfDataBytes)
{
	while(Copy_u32NumberOfDataBytes > 0)
    {
    	//1. wait until TXE is set
    	while(SPI_GetFlagStatus(pSPIx,SPI_TXE_FLAG)  == FLAG_RESET );

    	//2. check the DFF bit in CR1
    	if( (pSPIx->CR1 & ( 1 << SPI_CR1_DFF) ) )
    	{
    		//16 bit DFF
    		//1. load the data in to the DR
    		pSPIx->DR =   *((u16*)pTxBuffer);
    		Copy_u32NumberOfDataBytes--;
    		Copy_u32NumberOfDataBytes--;
    		(u16*)pTxBuffer++;
    	}
    	else
    	{
    		//8 bit DFF
    		pSPIx->DR =   *pTxBuffer;
    		Copy_u32NumberOfDataBytes--;
    		pTxBuffer++;
    	}
    }



}

/**-------------------------------------------------------------------------------------------------------------------*/
/**
 *
 * @param pSPIx
 * @param pRxBuffer
 * @param Len
 */
void SPI_ReceiveDataSynch (SPI_RegDef_t *pSPIx,u8 *pRxBuffer, u32 Copy_u32NumberOfDataBytes)
{
	while(Copy_u32NumberOfDataBytes > 0)
	{
		//1. wait until RXNE is set
		while(SPI_GetFlagStatus(pSPIx,SPI_RXNE_FLAG)  == (u8)FLAG_RESET );

		//2. check the DFF bit in CR1
		if( (pSPIx->CR1 & ( 1 << SPI_CR1_DFF) ) )
		{
			//16 bit DFF
			//1. load the data from DR to Rxbuffer address
			 *((u16*)pRxBuffer) = pSPIx->DR ;
			 Copy_u32NumberOfDataBytes--;
			 Copy_u32NumberOfDataBytes--;
			(u16*)pRxBuffer++;
		}else
		{
			//8 bit DFF
			*(pRxBuffer) = pSPIx->DR ;
			Copy_u32NumberOfDataBytes--;
			pRxBuffer++;
		}
	}

}

/**-------------------------------------------------------------------------------------------------------------------*/








