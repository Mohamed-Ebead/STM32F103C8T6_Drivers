/*
 * IR_program.c
 *
 *  Created on: Sep 6, 2020
 *      Author: Mohamed  Ebead
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "IR_interface.h"
#include "IR_private.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "EXTI0_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"


volatile u8   u8StartFlag       = 0;
volatile u32  u32FrameData[50]  = {0};
volatile u8   u8EdgeCounter     = 0;
volatile u8   u8Data            = 0;


void IR_voidInit       (void)
{
	GPIO_Handle_t IR ;
	IR.pGPIOx = GPIOA ;
	IR.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0 ;
	IR.GPIO_PinConfig.GPIO_PinMode = INPUT_FLOATING  ;

	GPIO_vidInit(&IR) ;
}
/**--------------------------------------------------------------------------------------------------------*/

void IR_voidPlay(void)
{
	switch (u8Data)
	{
		case REMOTE_ONE: RedLed_TurnOn  () ;  break;
		case REMOTE_TWO: GreenLed_TurnOn() ;  break;
		case REMOTE_THREE: BlueLed_TurnOn () ;  break;
	}
}

/**--------------------------------------------------------------------------------------------------------*/

void IR_voidTakeAction(void)
{
	u8 i;
	u8Data = 0;

	if ( (u32FrameData[0] >= 10000) && (u32FrameData[0] <= 14000) )
	{
		for (i=0;i<8;i++)
		{
			if (  (u32FrameData[17+i] >= 2000) && (u32FrameData[17+i] <=2300) )
			{
				SET_BIT(u8Data,i);
			}

			else
			{
				CLR_BIT(u8Data,i);
			}
		}

		IR_voidPlay();
	}

	else
	{
		/* Invalid Frame */
	}

	u8StartFlag     = 0;
	u32FrameData[0] = 0;
	u8EdgeCounter   = 0;
}

/**--------------------------------------------------------------------------------------------------------*/

void IR_voidGetFrame(void)
{
	if (u8StartFlag == 0)
	{
		/* Start Timer */
		STK_voidSetIntervalSingle(1000000,IR_voidTakeAction);
		u8StartFlag = 1;
	}

	else
	{
		u32FrameData[u8EdgeCounter] = STK_u32GetElapsedTime();
		STK_voidSetIntervalSingle(1000000,IR_voidTakeAction);
		u8EdgeCounter++;
	}
}

/**--------------------------------------------------------------------------------------------------------*/
