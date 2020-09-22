/*
 * TFT_program.c
 *
 *  Created on: Sep 22, 2020
 *      Author: Mohamed  Ebead
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"

#include "STK_interface.h"
#include "SPI_interface.h"

#include "TFT_interface.h"
#include "TFT_config.h"
#include "TFT_private.h"



/**-------------------------------------------------------------------------------------------------------**/
/**
 *
 */
void TFT_voidGPIOInit     (void)
{
	GPIO_Handle_t TFT_RST  ;
	TFT_RST.pGPIOx = TFT_RST_PORT ;
	TFT_RST.GPIO_PinConfig.GPIO_PinNumber = TFT_RST_PIN ;
	TFT_RST.GPIO_PinConfig.GPIO_PinMode   = OUTPUT_2MHZ_PP ;
	GPIO_vidInit(&TFT_RST) ;

	GPIO_Handle_t TFT_A0  ;
	TFT_A0.pGPIOx = TFT_A0_PORT ;
	TFT_A0.GPIO_PinConfig.GPIO_PinNumber = TFT_A0_PIN ;
	TFT_A0.GPIO_PinConfig.GPIO_PinMode   = OUTPUT_2MHZ_PP ;
	GPIO_vidInit(&TFT_A0) ;

	GPIO_Handle_t TFT_SDA  ;
	TFT_SDA.pGPIOx = TFT_SDA_PORT ;
	TFT_SDA.GPIO_PinConfig.GPIO_PinNumber = TFT_SDA_PIN ;
	TFT_SDA.GPIO_PinConfig.GPIO_PinMode   = OUTPUT_10MHZ_AFPP ;
	GPIO_vidInit(&TFT_SDA) ;

	GPIO_Handle_t TFT_SCK  ;
	TFT_SCK.pGPIOx = TFT_SCK_PORT ;
	TFT_SCK.GPIO_PinConfig.GPIO_PinNumber = TFT_SCK_PIN ;
	TFT_SCK.GPIO_PinConfig.GPIO_PinMode   = OUTPUT_10MHZ_AFPP ;
	GPIO_vidInit(&TFT_SCK) ;


}

/**-------------------------------------------------------------------------------------------------------**/
/**
 *
 */
void TFT_voidInit         (void)
{
	TFT_voidGPIOInit();

	/* Reset Pulse */
	GPIO_WriteToOutputPin(TFT_RST_PORT,TFT_RST_PIN,GPIO_PIN_SET);
	STK_voidSetBusyWait(100);
	GPIO_WriteToOutputPin(TFT_RST_PORT,TFT_RST_PIN,GPIO_PIN_RESET);
	STK_voidSetBusyWait(1);
	GPIO_WriteToOutputPin(TFT_RST_PORT,TFT_RST_PIN,GPIO_PIN_SET);
	STK_voidSetBusyWait(100);
	GPIO_WriteToOutputPin(TFT_RST_PORT,TFT_RST_PIN,GPIO_PIN_RESET);
	STK_voidSetBusyWait(100);
	GPIO_WriteToOutputPin(TFT_RST_PORT,TFT_RST_PIN,GPIO_PIN_SET);
	STK_voidSetBusyWait(120000);

	/* Sleep Out Command */
	TFT_voidWriteCommand(TFT_COMMAND_SLPOUT);

	/* Wait 150 ms */
	STK_voidSetBusyWait(150000);

	/* Color Mode Command */
	TFT_voidWriteCommand(TFT_COMMAND_COLMOD);
	TFT_voidWriteData   (0x05);

	/* Display On Command */
	TFT_voidWriteCommand(TFT_COMMAND_DISPON);



}

/**-------------------------------------------------------------------------------------------------------**/
/**
 *
 */
void TFT_voidDeInit       (void)
{

}

/**-------------------------------------------------------------------------------------------------------**/
/**
 *
 * @param Copy_Image
 */
void TFT_voidDisplayImage (const u16* Copy_Image)
{
	u16 counter;
	u8 Data;

	/* Set X Address */
	TFT_voidWriteCommand(TFT_COMMAND_CASET);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(127);

	/* Set Y Address */
	TFT_voidWriteCommand(TFT_COMMAND_RASET);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(159);

	/* RAM Write */
	TFT_voidWriteCommand(TFT_COMMAND_RAMWR);

	for(counter = 0; counter< 20480;counter++)
	{
		Data = Copy_Image[counter] >> 8;

		/* Write the high byte */
		TFT_voidWriteData(Data);
		/* Write the low byte */
		Data = Copy_Image[counter] & 0x00ff;
		TFT_voidWriteData(Data);
	}


}

/**-------------------------------------------------------------------------------------------------------**/
/**
 *
 * @param Copy_u8Command
 */
static void TFT_voidWriteCommand(u8 Copy_u8Command)
{
	u8 Local_u8Command = Copy_u8Command ;

	/* Set A0 Pin to Low */
	GPIO_WriteToOutputPin(TFT_A0_PORT,TFT_A0_PIN,GPIO_PIN_RESET);

	/* Send Command over SPI */
	SPI_SendDataSynch(SPI1,&Local_u8Command,1);

}
/**-------------------------------------------------------------------------------------------------------**/

/**
 *
 * @param Copy_u8Data
 */
static void TFT_voidWriteData   (u8 Copy_u8Data)
{
	u8 Local_u8Data = Copy_u8Data;

	/* Set A0 Pin to High */
	GPIO_WriteToOutputPin(TFT_A0_PORT,TFT_A0_PIN,GPIO_PIN_SET);

	/* Send data over SPI */
	SPI_SendDataSynch(SPI1,&Local_u8Data,1);


}

/**-------------------------------------------------------------------------------------------------------**/

