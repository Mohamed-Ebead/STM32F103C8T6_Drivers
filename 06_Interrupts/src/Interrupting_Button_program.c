/*
 * Interrupting_Button_program.c
 *
 *  Created on: Aug 25, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"



#include "AFIO_interface.h"
#include "AFIO_config.h"

#include "Interrupting_Button_interface.h"


/**--------------------------------------------------------------------------------------------------*/
/**
 *
 */
void PushButton_voidInit (void)
{

	GPIO_Handle_t Btn ;
	Btn.pGPIOx = GPIOB ;
	Btn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0 ;
	Btn.GPIO_PinConfig.GPIO_PinMode = INPUT_PULLUP_PULLDOWN ;
	GPIO_vidInit(&Btn);
	GPIO_WriteToOutputPin(GPIOB,GPIO_PIN_NO_0,GPIO_PIN_SET) ;


	GPIO_ExternalInterrupt_t PushButton ;
	PushButton.pGPIOx = GPIOB ;
	PushButton.EXTI_Config.Line          = EXTI_LINE ;
	PushButton.EXTI_Config.SWTrigger     = EXTI_SW_TRIGGER ;
	PushButton.EXTI_Config.Trigger       = EXTI_TRIGGER  ;
	PushButton.NVIC_Config.InterruptID   = NVIC_EXTI0 ;
	PushButton.NVIC_Config.GroupPriority = 0b00 ;
	PushButton.NVIC_Config.SubPriority   = 0b00 ;

	GPIO_voidInitExternalInterrupt(&PushButton);


}

/**--------------------------------------------------------------------------------------------------*/
/**
 *
 * @param pButtonHandle
 */

void GPIO_voidInitExternalInterrupt (GPIO_ExternalInterrupt_t *pButtonHandle)
{
	// variable  to select the source input for EXTIx external interrupt for AFIO
	u8 Local_u8PortMap = 0b000 ;
	//enable the peripheral clock
	GPIO_PeriClockControl(pButtonHandle->pGPIOx, ENABLE);

	if (pButtonHandle->pGPIOx == GPIOA)
		{Local_u8PortMap = 0b000 ;}
	else if ( pButtonHandle->pGPIOx == GPIOB)
		{Local_u8PortMap = 0b001 ;}
	else if ( pButtonHandle->pGPIOx == GPIOC)
		{Local_u8PortMap = 0b010 ;}
	else { }// error }


		// configure GPIO Alternate function for EXTI
	AFIO_voidSetEXTIConfiguration (pButtonHandle->EXTI_Config.Line ,Local_u8PortMap ) ;

	// Enable the interrupt
	NVIC_voidEnableInterrupt(pButtonHandle->NVIC_Config.InterruptID) ;

	// set interrupt priority , group priority & sub priority
	NVIC_voidSetPriority (&(pButtonHandle->NVIC_Config)) ;

	NVIC_voidClearPendingFlag(NVIC_EXTI0) ;

	// initialize EXTI
	EXTI_voidInit(&(pButtonHandle->EXTI_Config)) ;




}
/**--------------------------------------------------------------------------------------------------*/
/**
 *
 */

void PushButton_Handler (void)
{

	NVIC_voidClearPendingFlag(NVIC_EXTI0) ;
	GPIO_ToggleOutputPin(GPIOB,GPIO_PIN_NO_1) ;

}










