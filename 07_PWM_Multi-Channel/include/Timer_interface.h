/*
 * Timer_interface.h
 *
 *  Created on: Jan 10, 2021
 *      Author: Mohamed  Ebead
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


#include "Timer_private.h"


typedef struct
{
	u8 Timer_Channel ;
	u8 Timer_Mode ;    /**@TIMER_MODES*/

}Timer_Config_t;



typedef struct
{
	Timer_RegDef_t  *pTimerx         ;
	Timer_Config_t 	 pTimerx_config  ;


}Timer_Handle_t;


/**
 *  advanced Timers
 */
#define TIMER1 ( (Timer_RegDef_t*)TIMER1_BASE_ADDRESS)
#define TIMER8 ( (Timer_RegDef_t*)TIMER8_BASE_ADDRESS)

/**
 *  General purpose timers
 */
#define TIMER2 ( (Timer_RegDef_t*)TIMER2_BASE_ADDRESS)
#define TIMER3 ( (Timer_RegDef_t*)TIMER3_BASE_ADDRESS)
#define TIMER4 ( (Timer_RegDef_t*)TIMER4_BASE_ADDRESS)
#define TIMER5 ( (Timer_RegDef_t*)TIMER5_BASE_ADDRESS)





/**@TIMER_MODES*/
#define TIMER_MODE_PWM  0

/**-------------------------- Timers Related APIs ---------------------------*/

void Timer_voidGPIOInit    (u8 Copy_u8TimerChannel );

void Timer_voidInit        (u8 Copy_u8Timer , u8 Copy_u8Channel) ;
void Timer_SetDutyCycle    (u8 Copy_u8TimerChannel , u16 Copy_u16DutyCycle);

void Timerx_voidStartPWM         (Timer_Handle_t *pTimerx_Handle)     ;
void Timer_PeriClockControl(Timer_RegDef_t *pTimerx, u8 EnorDi) ;
void Timer_DeInit          (Timer_Handle_t *pTimerx_Handle)     ;


#define ENABLE 				1
#define DISABLE 			0
#define SET 				ENABLE
#define RESET 				DISABLE





#endif /* TIMER_INTERFACE_H_ */














