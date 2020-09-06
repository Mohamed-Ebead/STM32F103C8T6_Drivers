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

#include "RGB_LED_interface.h"
#include "RGB_LED_config.h"

/*****************************************************************************************************/
void RGB_voidInit      (void)
{
	RedLed_Init     () ;
	GreenLed_Init   () ;
	BlueLed_Init    () ;
}
/**--------------------------------------------------------------------------------------------------*/
void RedLed_Init       (void)
{
	GPIO_Handle_t RedLed;
	RedLed.pGPIOx = RED_LED_PORT;
	RedLed.GPIO_PinConfig.GPIO_PinNumber = RED_LED_PIN ;
	RedLed.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_PP;
	GPIO_vidInit(&RedLed);

}

/**--------------------------------------------------------------------------------------------------*/

void GreenLed_Init     (void)
{
	GPIO_Handle_t GreenLed;
	GreenLed.pGPIOx = GREEN_LED_PORT;
	GreenLed.GPIO_PinConfig.GPIO_PinNumber = GREEN_LED_PIN;
	GreenLed.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_PP;
	GPIO_vidInit(&GreenLed);

}

/**--------------------------------------------------------------------------------------------------*/

void BlueLed_Init    (void)
{
	GPIO_Handle_t BlueLed;
	BlueLed.pGPIOx = BLUE_LED_PORT;
	BlueLed.GPIO_PinConfig.GPIO_PinNumber = BLUE_LED_PIN;
	BlueLed.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_PP;
	GPIO_vidInit(&BlueLed);

}
/*****************************************************************************************************/
/**--------------------------------------------------------------------------------------------------*/

void RedLed_Toggle     (void)
{
	GPIO_ToggleOutputPin(RED_LED_PORT,RED_LED_PIN) ;

}

/**--------------------------------------------------------------------------------------------------*/

void GreenLed_Toggle   (void)
{
	GPIO_ToggleOutputPin(GREEN_LED_PORT,GREEN_LED_PIN) ;

}

/**--------------------------------------------------------------------------------------------------*/

void BlueLed_Toggle  (void)
{
	GPIO_ToggleOutputPin(BLUE_LED_PORT,BLUE_LED_PIN) ;

}

/*****************************************************************************************************/
/**--------------------------------------------------------------------------------------------------*/

void RedLed_TurnOn     (void)
{
	GPIO_WriteToOutputPin(RED_LED_PORT,RED_LED_PIN,GPIO_PIN_SET) ;

}

/**--------------------------------------------------------------------------------------------------*/

void GreenLed_TurnOn   (void)
{
	GPIO_WriteToOutputPin(GREEN_LED_PORT,GREEN_LED_PIN,GPIO_PIN_SET) ;

}

/**--------------------------------------------------------------------------------------------------*/

void BlueLed_TurnOn  (void)
{
	GPIO_WriteToOutputPin(BLUE_LED_PORT,BLUE_LED_PIN,GPIO_PIN_SET) ;

}
/*****************************************************************************************************/
/**--------------------------------------------------------------------------------------------------*/

void RedLed_TurnOff    (void)
{
	GPIO_WriteToOutputPin(RED_LED_PORT,RED_LED_PIN,GPIO_PIN_RESET) ;

}

/**--------------------------------------------------------------------------------------------------*/

void GreenLed_TurnOff  (void)
{
	GPIO_WriteToOutputPin(GREEN_LED_PORT,GREEN_LED_PIN,GPIO_PIN_RESET) ;

}

/**--------------------------------------------------------------------------------------------------*/

void BlueLed_TurnOff (void)
{
	GPIO_WriteToOutputPin(BLUE_LED_PORT,BLUE_LED_PIN,GPIO_PIN_RESET) ;

}

/**--------------------------------------------------------------------------------------------------*/
/*****************************************************************************************************/











