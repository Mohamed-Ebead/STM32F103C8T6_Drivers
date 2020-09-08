/*
 * DAC_program.c
 *
 *  Created on: Sep 8, 2020
 *      Author: Mohamed  Ebead
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"

#include "DAC_interface.h"
#include "DAC_private.h"
#include "DAC_config.h"


volatile u16  u16_SongSize = 0 ;

/**--------------------------------------------------------------------------------------------------------*/
void DAC_voidInit(void)
{
	GPIO_Handle_t DAC ;
	DAC.pGPIOx = DAC_PORT ;
	DAC.GPIO_ByteConfig.GPIO_ByteNumber = DAC_BYTE ;
	DAC.GPIO_ByteConfig.GPIO_ByteMode   = GPIO_BYTE_OUTPUT_2MHZ_PP ;
	GPIO_vidInitByte(&DAC);

}

/**--------------------------------------------------------------------------------------------------------*/

void DAC_voidPlayAudio(void)
{
	GPIO_WriteToOutputByte(DAC_PORT ,DAC_BYTE , Amaren_raw[u16_SongSize] ) ;
	u16_SongSize ++ ;

	if (u16_SongSize == DAC_SONG_SIZE)
	{
		u16_SongSize = 0 ;
	}

}
/**--------------------------------------------------------------------------------------------------------*/
