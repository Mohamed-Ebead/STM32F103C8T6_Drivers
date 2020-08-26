/*
 * Led_program.c
 *
 *  Created on: Aug 26, 2020
 *      Author: Mohamed  Ebead
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"

/*****************************************************************************************************/
/**--------------------------------------------------------------------------------------------------*/
void RedLed_Init       (void)
{
	GPIO_Handle_t RedLed;
	RedLed.pGPIOx = GPIOB;
	RedLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	RedLed.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_PP;
	GPIO_vidInit(&RedLed);

}

/**--------------------------------------------------------------------------------------------------*/

void GreenLed_Init     (void)
{
	GPIO_Handle_t GreenLed;
	GreenLed.pGPIOx = GPIOB;
	GreenLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_6;
	GreenLed.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_PP;
	GPIO_vidInit(&GreenLed);

}

/**--------------------------------------------------------------------------------------------------*/

void YellowLed_Init    (void)
{
	GPIO_Handle_t YellowLed;
	YellowLed.pGPIOx = GPIOB;
	YellowLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_7;
	YellowLed.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_PP;
	GPIO_vidInit(&YellowLed);

}
/*****************************************************************************************************/
/**--------------------------------------------------------------------------------------------------*/

void RedLed_Toggle     (void)
{
	GPIO_ToggleOutputPin(GPIOB,GPIO_PIN_NO_5) ;

}

/**--------------------------------------------------------------------------------------------------*/

void GreenLed_Toggle   (void)
{
	GPIO_ToggleOutputPin(GPIOB,GPIO_PIN_NO_6) ;

}

/**--------------------------------------------------------------------------------------------------*/

void YellowLed_Toggle  (void)
{
	GPIO_ToggleOutputPin(GPIOB,GPIO_PIN_NO_7) ;

}

/*****************************************************************************************************/
/**--------------------------------------------------------------------------------------------------*/

void RedLed_TurnOn     (void)
{
	GPIO_WriteToOutputPin(GPIOB,GPIO_PIN_NO_5,GPIO_PIN_SET) ;

}

/**--------------------------------------------------------------------------------------------------*/

void GreenLed_TurnOn   (void)
{
	GPIO_WriteToOutputPin(GPIOB,GPIO_PIN_NO_6,GPIO_PIN_SET) ;

}

/**--------------------------------------------------------------------------------------------------*/

void YellowLed_TurnOn  (void)
{
	GPIO_WriteToOutputPin(GPIOB,GPIO_PIN_NO_7,GPIO_PIN_SET) ;

}
/*****************************************************************************************************/
/**--------------------------------------------------------------------------------------------------*/

void RedLed_TurnOff    (void)
{
	GPIO_WriteToOutputPin(GPIOB,GPIO_PIN_NO_5,GPIO_PIN_RESET) ;

}

/**--------------------------------------------------------------------------------------------------*/

void GreenLed_TurnOff  (void)
{
	GPIO_WriteToOutputPin(GPIOB,GPIO_PIN_NO_6,GPIO_PIN_RESET) ;

}

/**--------------------------------------------------------------------------------------------------*/

void YellowLed_TurnOff (void)
{
	GPIO_WriteToOutputPin(GPIOB,GPIO_PIN_NO_7,GPIO_PIN_RESET) ;

}

/**--------------------------------------------------------------------------------------------------*/
/*****************************************************************************************************/











