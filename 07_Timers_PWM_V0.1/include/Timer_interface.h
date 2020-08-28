/*
 * Timer_interface.h
 *
 *  Created on: Aug 27, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


#include "Timer_private.h"


typedef struct
{
	//u8 ClockDivision ;       /** @TIMER_CLOCK_DIVISION **/
	//u8 ARP_State ;           /**@TIMER_AUTO_RELOAD_PRELOAD */
	//u8 CenterAlignedMode ;   /**@CENTER_ALIGNED_MODE */
	//u8 CountDirection  ;       /**@COUNT_DIRECTION*/
	//u8 OnePulseMode ;             /**@ONE_PULSE_MODE */
	//u8 UpdateRequestSource ;     /**@UPDATE_REQUEST_SOURCE*/
	//u8 UpdateEventGeneration  ;  /**@UPDATE_EVENT_GENERATION*/
//	u16 Prescaler  ;
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


/**
 *  General purpose timers
 */
#define TIMER9  ( (Timer_RegDef_t*)TIMER9_BASE_ADDRESS)
#define TIMER10 ( (Timer_RegDef_t*)TIMER10_BASE_ADDRESS)
#define TIMER11 ( (Timer_RegDef_t*)TIMER11_BASE_ADDRESS)
#define TIMER12 ( (Timer_RegDef_t*)TIMER12_BASE_ADDRESS)
#define TIMER13 ( (Timer_RegDef_t*)TIMER13_BASE_ADDRESS)
#define TIMER14 ( (Timer_RegDef_t*)TIMER14_BASE_ADDRESS)

/**
 *  Basic Timers
 */
#define TIMER6 ( (Timer_RegDef_t*)TIMER6_BASE_ADDRESS)
#define TIMER7 ( (Timer_RegDef_t*)TIMER7_BASE_ADDRESS)



/** @TIMER_CLOCK_DIVISION **/
#define CLK_DIV_CLK_INPUT         0b00
#define CLK_DIV_CLK_INPUT_MUL_2   0b01
#define CLK_DIV_CLK_INPUT_MUL_4   0b10

/**@TIMER_AUTO_RELOAD_PRELOAD */
#define ARP_DISABLE   0
#define ARP_ENABLE    1

/**@CENTER_ALIGNED_MODE */
#define EDGE_ALIGNED_MODE        0b00  /**The counter counts up or down depending on the direction bit (DIR).*/
#define CENTER_ALIGNED_MODE_1    0b01
#define CENTER_ALIGNED_MODE_2    0b10
#define CENTER_ALIGNED_MODE_3    0b11

/**@COUNT_DIRECTION*/
#define UP_COUNTER     0
#define DOWN_COUNTER   1

/**@ONE_PULSE_MODE */
#define OPM_DISABLE   0
#define OPM_ENABLE    1

/**@UPDATE_REQUEST_SOURCE*/
/**
 *  URS_OVF_UVF_UG_UGS
 *  Any of the following events generate an update interrupt or DMA request if enabled.
 *   These events can be:
 * – Counter overflow/underflow
 * – Setting the UG bit
 * – Update generation through the slave mode controller
 */
#define URS_OVF_UVF_UG_UGS  0
/**
 * URS_OVF_UVF
 * Only counter overflow/underflow generates an update interrupt or DMA request if
 * enabled.
 */
#define URS_OVF_UVF         1


/**@UPDATE_EVENT_GENERATION*/
#define UDIS_ENABLE     0
#define UDIS_DISABLE    1

/**@TIMER_MODES*/
#define TIMER_MODE_PWM  0

void Timer_PeriClockControl(Timer_RegDef_t *pTimerx, u8 EnorDi) ;
void Timer_voidInit            (Timer_Handle_t *pTimerx_Handle)     ;
void Timer_DeInit          (Timer_Handle_t *pTimerx_Handle)     ;
void Timer_Init_PWM        (void )     ;
void Timer_LoadPWM         (Timer_RegDef_t *pTimerx , u16 Copy_u16Value ) ;

#define ENABLE 				1
#define DISABLE 			0
#define SET 				ENABLE
#define RESET 				DISABLE





#endif /* TIMER_INTERFACE_H_ */














