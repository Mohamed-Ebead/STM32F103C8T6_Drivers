/*
 * Interrupting_Button_interface.h
 *
 *  Created on: Aug 25, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef INTERRUPTING_BUTTON_INTERFACE_H_
#define INTERRUPTING_BUTTON_INTERFACE_H_


#include "NVIC_interface.h"
#include "NVIC_config.h"
#include "NVIC_private.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

typedef struct
{
	//u8 GPIO_PinNumber ;
	//u8 InterruptNumber ;
	GPIO_RegDef_t *pGPIOx;       		/*!< This holds the base address of the GPIO port to which the pin belongs >*/
	EXTI_config_t EXTI_Config ;
	NVIC_Config_t NVIC_Config ;

}GPIO_ExternalInterrupt_t ;


void PushButton_voidInit (void) ;
void GPIO_voidInitExternalInterrupt (GPIO_ExternalInterrupt_t *pButtonHandle) ;
void PushButton_Handler (void) ;



#endif /* INTERRUPTING_BUTTON_INTERFACE_H_ */
