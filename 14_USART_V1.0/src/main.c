/*
 * main.c
 *
 *  Created on: Sep 15, 2020
 *      Author: Mohamed  Ebead
 */
#include<string.h>


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"

#include "USART_interface.h"
#include <stdio.h>

USART_Handle_t USART1_H ;

void LED_Init (void)   ;
void LED_ON   (void)   ;
void LED_OFF  (void)   ;



int main (void)
{
	u8 u8_SendData  [1024] = "UART TX-RX testing...\n\r";
	u8 u8_ReciveData[1] = {0};



	RCC_voidInitSysClock() ;
	LED_Init();
	USART1_voidInit();

	USART_SendData(&USART1_H,(u8*)u8_SendData,strlen(u8_SendData));

	while(1)
	{


		USART_ReceiveData(&USART1_H,(u8*)u8_ReciveData,sizeof(u8_ReciveData)) ;

		if(u8_ReciveData[0] == '1')
		{
			LED_ON();
		}
		if(u8_ReciveData[0] == '0')
		{
			LED_OFF();
		}
	}

	return 0 ;
}



void LED_Init (void )
{
	GPIO_Handle_t LED ;
	LED.pGPIOx = GPIOA ;
	LED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0  ;
	LED.GPIO_PinConfig.GPIO_PinMode   = OUTPUT_2MHZ_PP ;
	GPIO_vidInit(&LED)  ;
}

void LED_ON (void)
{
	GPIO_WriteToOutputPin(GPIOA ,GPIO_PIN_NO_0,GPIO_PIN_SET) ;
}

void LED_OFF (void)
{
	GPIO_WriteToOutputPin(GPIOA ,GPIO_PIN_NO_0,GPIO_PIN_RESET) ;
}






