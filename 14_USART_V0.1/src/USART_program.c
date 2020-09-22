
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

#include "RCC_interface.h"

/**----------------------------------------------------------------------------------------------------*/

void USART1_GPIOInit(void)
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

/**----------------------------------------------------------------------------------------------------*/

void USART1_voidInit(void)
{
	USART1_GPIOInit();

	RCC_voidEnableClock(RCC_APB2, 14);		/* Enable USART1 Clock */

	/*	baud rate = 9600		*/
	USART1 -> BRR = 0x341;

	SET_BIT((USART1-> CR[0]), 3);			/* Enabling Transmitter */
	SET_BIT((USART1-> CR[0]), 2);			/* Enabling Receiver */
	SET_BIT((USART1-> CR[0]), 13);			/* Enabling USART */
	
	USART1 -> SR = 0;						/* Clearing status register */
}

/**----------------------------------------------------------------------------------------------------*/

void USART1_voidTransmit(u8 arr[])
{
	u8 i = 0;
	while(arr[i] != '\0')
	{
		USART1 -> DR = arr[i];
		while((GET_BIT((USART1 -> SR), 6)) == 0);
		i++;
	}
	
}

/**----------------------------------------------------------------------------------------------------*/

u8 USART1_u8Receive(void)
{
	u8 Loc_u8ReceivedData = 0;
	while((GET_BIT((USART1 -> SR), 5)) == 0);
	Loc_u8ReceivedData = USART1 -> DR;
	return (Loc_u8ReceivedData);
}

/**----------------------------------------------------------------------------------------------------*/



















