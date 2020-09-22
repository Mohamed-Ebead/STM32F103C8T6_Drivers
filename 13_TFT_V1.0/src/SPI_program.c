


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"

#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"



//void (*CallBack)(u8);

/**----------------------------------------------------------------------------------------------------------*/

void SPI1_voidInit(void)
{
	RCC_voidEnableClock(RCC_APB2,12);  /* SPI1  */
	/* CPOL =1 / CPHA = 1 / Prescaller = Clk/2 / SPI Enable / MSB First */
	SPI1->CR1 = 0x0347;
}

/**----------------------------------------------------------------------------------------------------------*/

void SPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_DataToReceive)
{
	/* Clear For Slave Select Pin */
//	GPIO_WriteToOutputPin(GPIOA,GPIO_PIN_NO_0,GPIO_PIN_RESET);
	
	/* Send Data */
	SPI1 -> DR = Copy_u8DataToTransmit;
	
	/* Wait Busy Flag to finish */
	while (GET_BIT(SPI1 -> SR, 7) == 1);

 	/* Return to the received data */
	*Copy_DataToReceive = SPI1 -> DR;
	
	/* Set Salve Select Pin */
//	GPIO_WriteToOutputPin(GPIOA,GPIO_PIN_NO_0,GPIO_PIN_SET);
}

/**----------------------------------------------------------------------------------------------------------*/

