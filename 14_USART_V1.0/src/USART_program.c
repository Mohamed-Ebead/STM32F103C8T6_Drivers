/*
 * USART_program.c
 *
 *  Created on: Sep 19, 2020
 *      Author: Mohamed  Ebead
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"

#include "RCC_interface.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"




/**---------------------------------------------------------------------------------------------------*/

extern USART_Handle_t USART1_H ;
/**
 *
 */
void USART1_voidInit(void)
{
	USART1_voidGPIOInit() ;

	//USART_Handle_t USART1_H ;
	USART1_H.pUSARTx = USART1 ;
	USART1_H.USART_Config.USART_Baud          = USART_STD_BAUD_9600 ;
	USART1_H.USART_Config.USART_HWFlowControl = USART_HW_FLOW_CTRL_NONE ;
	USART1_H.USART_Config.USART_Mode          = USART_MODE_TXRX ;
	USART1_H.USART_Config.USART_NoOfStopBits  = USART_STOPBITS_1 ;
	USART1_H.USART_Config.USART_WordLength    = USART_WORDLEN_8BITS ;
	USART1_H.USART_Config.USART_ParityControl = USART_PARITY_DISABLE ;
	USART_Init(&USART1_H) ;

}

/**---------------------------------------------------------------------------------------------------*/

/**
 *
 */
void USART1_voidGPIOInit(void)
{
	/* Setting A9:TX pin as Output alternate function push pull w max speed 10 MHz */
	GPIO_Handle_t USART1_TX ;
	USART1_TX.pGPIOx = GPIOA ;
	USART1_TX.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_9  ;
	USART1_TX.GPIO_PinConfig.GPIO_PinMode   = OUTPUT_10MHZ_AFPP  ;
	GPIO_vidInit(&USART1_TX) ;

	/* Setting A10:RX pin as input floating */
	GPIO_Handle_t USART1_RX ;
	USART1_RX.pGPIOx = GPIOA ;
	USART1_RX.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_10  ;
	USART1_RX.GPIO_PinConfig.GPIO_PinMode   = INPUT_FLOATING  ;
	GPIO_vidInit(&USART1_RX) ;

}


/**---------------------------------------------------------------------------------------------------*/
/**
 *
 * @param pUSARTx
 * @param EnOrDi
 */
void USART_PeriClockControl(USART_RegDef_t *pUSARTx, u8 EnOrDi)
{
	if (EnOrDi == ENABLE)
	{
		if      ( pUSARTx == USART1 )
		{
			RCC_voidEnableClock(RCC_APB2,RCC_USART1);
		}
		else if ( pUSARTx == USART2 )
		{
			RCC_voidEnableClock(RCC_APB1,RCC_USART2);
		}
		else if ( pUSARTx == USART3 )
		{
			RCC_voidEnableClock(RCC_APB1,RCC_USART3);
		}
		else if ( pUSARTx == UART4 )
		{
			RCC_voidEnableClock(RCC_APB1,RCC_UART4);
		}
		else if ( pUSARTx == UART5 )
		{
			RCC_voidEnableClock(RCC_APB1,RCC_UART5);
		}
		else
		{
			// invalid USART periheral
		}



	}
	else if (EnOrDi == DISABLE)
	{
		if      ( pUSARTx == USART1 )
		{
			RCC_voidDisableClock(RCC_APB2,RCC_USART1);
		}
		else if ( pUSARTx == USART2 )
		{
			RCC_voidDisableClock(RCC_APB1,RCC_USART2);
		}
		else if ( pUSARTx == USART3 )
		{
			RCC_voidDisableClock(RCC_APB1,RCC_USART3);
		}
		else if ( pUSARTx == UART4 )
		{
			RCC_voidDisableClock(RCC_APB1,RCC_UART4);
		}
		else if ( pUSARTx == UART5 )
		{
			RCC_voidDisableClock(RCC_APB1,RCC_UART5);
		}
		else
		{
			// invalid USART periheral
		}

	}
	else
	{
		// invalid control macro
	}
}

/**---------------------------------------------------------------------------------------------------*/
/**
 *
 * @param pUSARTHandle
 */
void USART_Init  (USART_Handle_t *pUSARTHandle)
{
	//Temporary variable
		u32 Local_u32TempReg=0;

	/******************************** Configuration of CR1******************************************/

	//Implement the code to enable the Clock for given USART peripheral
	 USART_PeriClockControl(pUSARTHandle->pUSARTx,ENABLE);

	//Enable USART Tx and Rx engines according to the USART_Mode configuration item
	if ( pUSARTHandle->USART_Config.USART_Mode == USART_MODE_ONLY_RX)
	{
		//Implement the code to enable the Receiver bit field
		Local_u32TempReg|= (1 << USART_CR1_RE);
	}
	else if (pUSARTHandle->USART_Config.USART_Mode == USART_MODE_ONLY_TX)
	{
		//Implement the code to enable the Transmitter bit field
		Local_u32TempReg |= ( 1 << USART_CR1_TE );

	}
	else if (pUSARTHandle->USART_Config.USART_Mode == USART_MODE_TXRX)
	{
		//Implement the code to enable the both Transmitter and Receiver bit fields
		Local_u32TempReg |= ( ( 1 << USART_CR1_RE) | ( 1 << USART_CR1_TE) );
	}

	//Implement the code to configure the Word length configuration item
	Local_u32TempReg |= pUSARTHandle->USART_Config.USART_WordLength << USART_CR1_M ;


	//Configuration of parity control bit fields
	if ( pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_EN_EVEN)
	{
		//Implement the code to enable the parity control
		Local_u32TempReg |= ( 1 << USART_CR1_PCE);

		//Implement the code to enable EVEN parity
		Local_u32TempReg &= ~( 1 << USART_CR1_PS);

	}
	else if (pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_EN_ODD )
	{
		//Implement the code to enable the parity control
		Local_u32TempReg |= ( 1 << USART_CR1_PCE);

		//Implement the code to enable ODD parity
		Local_u32TempReg |= ( 1 << USART_CR1_PS);

	}

		//Program the CR1 register
	pUSARTHandle->pUSARTx->CR1 = Local_u32TempReg;

	/******************************** Configuration of CR2******************************************/

//	pUSARTHandle->pUSARTx->CR2=0;

		//Implement the code to configure the number of stop bits inserted during USART frame transmission
	pUSARTHandle->pUSARTx->CR2 |= pUSARTHandle->USART_Config.USART_NoOfStopBits << USART_CR2_STOP;

		//Program the CR2 register
//	pUSARTHandle->pUSARTx->CR2 = pUSARTHandle->pUSARTx->CR1;

	/******************************** Configuration of CR3******************************************/

	//	pUSARTHandle->pUSARTx->CR1=0;

		//Configuration of USART hardware flow control
		if ( pUSARTHandle->USART_Config.USART_HWFlowControl == USART_HW_FLOW_CTRL_CTS)
		{
			//Implement the code to enable CTS flow control
			pUSARTHandle->pUSARTx->CR3 |= ( 1 << USART_CR3_CTSE);

		}
		else if (pUSARTHandle->USART_Config.USART_HWFlowControl == USART_HW_FLOW_CTRL_RTS)
		{
			//Implement the code to enable RTS flow control
			pUSARTHandle->pUSARTx->CR3 |= ( 1 << USART_CR3_RTSE);

		}
		else if (pUSARTHandle->USART_Config.USART_HWFlowControl == USART_HW_FLOW_CTRL_CTS_RTS)
		{
			//Implement the code to enable both CTS and RTS Flow control
			pUSARTHandle->pUSARTx->CR3 |= ( 1 << USART_CR3_CTSE);
			pUSARTHandle->pUSARTx->CR3 |= ( 1 << USART_CR3_RTSE);
		}


	//	pUSARTHandle->pUSARTx->CR3 = pUSARTHandle->pUSARTx->CR1;

	/******************************** Configuration of BRR(Baudrate register)******************************************/

		/*	baud rate = 9600		*/
		if (pUSARTHandle->USART_Config.USART_Baud == USART_STD_BAUD_9600 )
		{
			USART1 -> BRR = 0x341;
		}
		else if (pUSARTHandle->USART_Config.USART_Baud == USART_STD_BAUD_115200)
		{

		}

		//USART_SetBaudRate(pUSARTHandle->pUSARTx,pUSARTHandle->USART_Config.USART_Baud);

		// Enable USART Peripheral
		USART_PeripheralControl(pUSARTHandle->pUSARTx , ENABLE) ;

}

/**---------------------------------------------------------------------------------------------------*/
/**
 *
 * @param pUSARTx
 * @param StatusFlagName
 * @return
 */
u8 USART_GetFlagStatus(USART_RegDef_t *pUSARTx, u8 StatusFlagName)
{
    if(pUSARTx->SR & StatusFlagName)
    {
    	return SET;
    }

   return RESET;
}

/**---------------------------------------------------------------------------------------------------*/
/**
 *
 * @param pUSARTHandle
 * @param pTxBuffer
 * @param Len
 */
void USART_SendData(USART_Handle_t *pUSARTHandle, u8 *pTxBuffer, u32 Len)
{

	u16 *pdata;

   //Loop over until "Len" number of bytes are transferred
	for(u32 i = 0 ; i < Len; i++)
	{
		//Implement the code to wait until TXE flag is set in the SR
		while(! USART_GetFlagStatus(pUSARTHandle->pUSARTx,USART_FLAG_TXE));

		//Check the USART_WordLength item for 9BIT or 8BIT in a frame
		if(pUSARTHandle->USART_Config.USART_WordLength == USART_WORDLEN_9BITS)
		{
			//if 9BIT load the DR with 2bytes masking  the bits other than first 9 bits
			pdata = (u16*) pTxBuffer;
			pUSARTHandle->pUSARTx->DR = (*pdata & (u16)0x01FF);

			//check for USART_ParityControl
			if(pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_DISABLE)
			{
				//No parity is used in this transfer , so 9bits of user data will be sent
				//Implement the code to increment pTxBuffer twice
				pTxBuffer++;
				pTxBuffer++;
			}
			else
			{
				//Parity bit is used in this transfer . so 8bits of user data will be sent
				//The 9th bit will be replaced by parity bit by the hardware
				pTxBuffer++;
			}
		}
		else
		{
			//This is 8bit data transfer
			pUSARTHandle->pUSARTx->DR = (*pTxBuffer & (u8)0xFF);

			//Implement the code to increment the buffer address
			pTxBuffer++;
		}
	}

	//Implement the code to wait till TC flag is set in the SR
	while( ! USART_GetFlagStatus(pUSARTHandle->pUSARTx,USART_FLAG_TC));

}


/**---------------------------------------------------------------------------------------------------*/

/**
 *
 * @param pUSARTHandle
 * @param pRxBuffer
 * @param Len
 */
void USART_ReceiveData(USART_Handle_t *pUSARTHandle, u8 *pRxBuffer, u32 Len)
{
   //Loop over until "Len" number of bytes are transferred
	for(u32 i = 0 ; i < Len; i++)
	{
		//Implement the code to wait until RXNE flag is set in the SR
		while(! USART_GetFlagStatus(pUSARTHandle->pUSARTx,USART_FLAG_RXNE));

		//Check the USART_WordLength to decide whether we are going to receive 9bit of data in a frame or 8 bit
		if(pUSARTHandle->USART_Config.USART_WordLength == USART_WORDLEN_9BITS)
		{
			//We are going to receive 9bit data in a frame

			//Now, check are we using USART_ParityControl control or not
			if(pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_DISABLE)
			{
				//No parity is used , so all 9bits will be of user data

				//read only first 9 bits so mask the DR with 0x01FF
				*((u16*) pRxBuffer) = (pUSARTHandle->pUSARTx->DR  & (u16)0x01FF);

				//Now increment the pRxBuffer two times
				pRxBuffer++;
				pRxBuffer++;
			}
			else
			{
				//Parity is used, so 8bits will be of user data and 1 bit is parity
				 *pRxBuffer = (pUSARTHandle->pUSARTx->DR  & (u8)0xFF);
				 pRxBuffer++;
			}
		}
		else
		{
			//We are going to receive 8bit data in a frame

			//Now, check are we using USART_ParityControl control or not
			if(pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_DISABLE)
			{
				//No parity is used , so all 8bits will be of user data

				//read 8 bits from DR
				 *pRxBuffer = (pUSARTHandle->pUSARTx->DR  & (u8)0xFF);
			}

			else
			{
				//Parity is used, so , 7 bits will be of user data and 1 bit is parity

				//read only 7 bits , hence mask the DR with 0X7F
				 *pRxBuffer = (u8) (pUSARTHandle->pUSARTx->DR  & (u8)0x7F);

			}

			//Now , increment the pRxBuffer
			pRxBuffer++;
		}
	}

}

/**---------------------------------------------------------------------------------------------------*/
/**
 *
 * @param pUSARTx
 * @param BaudRate
 */
void USART_SetBaudRate(USART_RegDef_t *pUSARTx, u32 BaudRate)
{

	//Variable to hold the APB clock
	u32 PCLKx;

	u32 usartdiv;

	//variables to hold Mantissa and Fraction values
	u32 M_part,F_part;

	u32 tempreg=0;
/*
  //Get the value of APB bus clock in to the variable PCLKx
  if(pUSARTx == USART1 )
  {
	   //USART1 and USART6 are hanging on APB2 bus
	   PCLKx = RCC_GetPCLK2Value();
  }else
  {
	   PCLKx = RCC_GetPCLK1Value();
  }
*/

  PCLKx = 8000000UL ; // TODO make the clock configured

  //Check for OVER8 configuration bit
  if(pUSARTx->CR1 & (1 << USART_CR1_OVER8))
  {
	   //OVER8 = 1 , over sampling by 8
	   usartdiv = ((25 * PCLKx) / (2 *BaudRate));
  }else
  {
	   //over sampling by 16
	   usartdiv = ((25 * PCLKx) / (4 *BaudRate));
  }

  //Calculate the Mantissa part
  M_part = usartdiv/100;

  //Place the Mantissa part in appropriate bit position . refer USART_BRR
  tempreg |= M_part << 4;

  //Extract the fraction part
  F_part = (usartdiv - (M_part * 100));

  //Calculate the final fractional
  if(pUSARTx->CR1 & ( 1 << USART_CR1_OVER8))
   {
	  //OVER8 = 1 , over sampling by 8
	  F_part = ((( F_part * 8)+ 50) / 100)& ((u8)0x07);

   }else
   {
	   //over sampling by 16
	   F_part = ((( F_part * 16)+ 50) / 100) & ((u8)0x0F);

   }

  //Place the fractional part in appropriate bit position . refer USART_BRR
  tempreg |= F_part;

  //copy the value of tempreg in to BRR register
  pUSARTx->BRR = tempreg;
}

/**---------------------------------------------------------------------------------------------------*/
/**
 *
 * @param pUSARTx
 * @param EnOrDi
 */
void USART_PeripheralControl(USART_RegDef_t *pUSARTx, u8 EnOrDi)
{
	if(EnOrDi == ENABLE)
	{
		pUSARTx->CR1 |= (1 << 13);
	}else
	{
		pUSARTx->CR1 &= ~(1 << 13);
	}

}

/**---------------------------------------------------------------------------------------------------*/







