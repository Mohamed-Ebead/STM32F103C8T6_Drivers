

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"

#include "USART_interface.h"



void LED_Init (void)   ;
void LED_ON   (void)   ;
void LED_OFF  (void)   ;



int main(void)
{
	RCC_voidInitSysClock();

	LED_Init ();

	USART1_voidInit();
	USART1_voidTransmit("Press 1 to Turn ON  the LED ");
	USART1_voidTransmit("Press 0 to turn OFF the LED ");
	u8 x;

	while(1)
	{


		x = USART1_u8Receive();
		if(x == '1')
		{
			USART1_voidTransmit("1");
			LED_ON();
		}
		if(x == '0')
		{
			USART1_voidTransmit("0");
			LED_OFF();
		}
	}

	return 0;
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


