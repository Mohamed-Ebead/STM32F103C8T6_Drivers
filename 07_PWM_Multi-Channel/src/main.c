/*
 * main.c
 *
 *  Created on: Jan 10, 2021
 *      Author: Mohamed  Ebead
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "Timer_interface.h"

#include "Timer_config.h"

#include "ADC_interface.h"
#include "ADC_config.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"


 /**
  *  This is a driver is written by Mohamed Ebead to handle 12 PWM channels For Timers 2,3,4 Ch 1,2,3,4  .
  *  The main function controls two channels based on ADC read
  *  I hope this driver will be useful for you ... Good Luck  .
  */

int main(void)
{
	u32 AnalogValue =0 ;

	RCC_voidInitSysClock() ;

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



	Timer_voidGPIOInit(TIMER4_CH4);
	Timer_voidInit    (TIMER_NO_4,CHANNEL_NO_4);

	Timer_voidGPIOInit(TIMER4_CH3);
	Timer_voidInit    (TIMER_NO_4,CHANNEL_NO_3);





	while(1)
	{

	AnalogValue = ADC_u16ReadBlocking(&Potentiometer) ;

	Timer_SetDutyCycle(TIMER4_CH4 , AnalogValue) ;
	Timer_SetDutyCycle(TIMER4_CH3 , 4096-AnalogValue) ;


	}

	return 0;
}







