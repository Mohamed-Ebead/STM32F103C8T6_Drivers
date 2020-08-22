/*
 * main.c
 *
 *  Created on: Aug 16, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LCD_interface.h"

#include "ADC_interface.h"
#include "ADC_config.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"


void delay(void)
{
	for(int i = 0 ; i < 600 ; i++ )
	{
		for(int j = 0 ; j < 600 ; j++ )
		{
			asm("NOP");
		}
	}

}


int main(void)
{
	u32 AnalogValue =0 ;

	RCC_voidInitSysClock() ;

	LCD_vidInitialize();

	// configure ADC input pin
	GPIO_Handle_t POT;
	POT.pGPIOx = GPIOB;
	POT.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0 ;
	POT.GPIO_PinConfig.GPIO_PinMode   = INPUT_ANLOG   ;
	GPIO_vidInit(&POT);

	// ADC configurations
	ADC_Handle_t Potentiometer ;
	Potentiometer.pADCx = ADC1 ;
	Potentiometer.ADC_Config.Channel        = ADC_CHANNEL_NUM ;
	Potentiometer.ADC_Config.DataAlign      = ADC_ALIGNMENT ;
	Potentiometer.ADC_Config.SampleTime     = ADC_SAMPLE_TIME ;
	Potentiometer.ADC_Config.ConversionMode = ADC_CONVERSION_MODE ;
	Potentiometer.ADC_Config.ConversionNum  = ADC_CONVERSION_NUM  ;
	ADC_vidInit(&Potentiometer) ;

	delay() ;


	while(1)
	{
		AnalogValue = ADC_u16ReadBlocking(&Potentiometer) ;
		LCD_vidGotoxy(1,1) ;
		LCD_vidWriteInteger(AnalogValue,5) ;
		delay() ;

	}



	return 0;
}







