
/*
 *
 *  Created on: Oct 1, 2020
 *      Author: Mohamed  Ebead
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ESP_interface.h"
#include "ESP_config.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "USART_interface.h"

/**-----------------------------------------------------------------------------------------------------------*/

void LED_Init (void)   ;
void LED_ON   (void)   ;
void LED_OFF  (void)   ;

/**-----------------------------------------------------------------------------------------------------------*/



int main (void)
{
	RCC_voidInitSysClock();

	LED_Init () ;

	USART1_voidInit();

	ESP_voidInit();
	/* Connect to Router, sending name and password as strings*/
	ESP_voidConnctToRouter(ROUTER_SSID, ROUTER_PASSWORD);

	u8  Led_Status = 0;

	while(1)
	{
		ESP_voidInit();
		/* Connect to Router, sending name and password as strings*/
		ESP_voidConnctToRouter(ROUTER_SSID, ROUTER_PASSWORD);

		/*Connecting to server, sending data transmit mode UDP or TCP and IP of server and port number as strings*/
		/* We connect each time as my server is free one and disconnects automatically, if you got a server yourself you don't
		 * have to do so
		 */
		ESP_voidConnectToServer(MODE, IP, PORT);

		/* Send the request as string*/
		Led_Status = ESP_u8ExecuteRequest(REQUEST_LED_STATUS);

		switch ( Led_Status )
		{
			case '0' : LED_OFF() ; break ;
			case '1' : LED_ON () ; break ;
		}
	}

	return 0 ;
}



/**-----------------------------------------------------------------------------------------------------------*/

void LED_Init (void )
{
	GPIO_Handle_t LED ;
	LED.pGPIOx = GPIOA ;
	LED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0  ;
	LED.GPIO_PinConfig.GPIO_PinMode   = OUTPUT_2MHZ_PP ;
	GPIO_vidInit(&LED)  ;
}

/**-----------------------------------------------------------------------------------------------------------*/

void LED_ON (void)
{
	GPIO_WriteToOutputPin(GPIOA ,GPIO_PIN_NO_0,GPIO_PIN_SET) ;
}

/**-----------------------------------------------------------------------------------------------------------*/

void LED_OFF (void)
{
	GPIO_WriteToOutputPin(GPIOA ,GPIO_PIN_NO_0,GPIO_PIN_RESET) ;
}

/**-----------------------------------------------------------------------------------------------------------*/







