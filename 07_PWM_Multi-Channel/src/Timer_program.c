/*
 * Timer_program.c
 *
 *  Created on: Jan 10, 2021
 *      Author: Mohamed  Ebead
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Timer_interface.h"
#include "Timer_private.h"
#include "Timer_config.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"



/**-----------------------------------------------------------------------------------------------*/
/**
 * @fun     :Timer_voidInit
 * @brief   : Initializes a Specific Channel for a Specific Timer
 * @param1  : Copy_u8Timer
 *    param1 options : TIMER_NO_2 / TIMER_NO_3 / TIMER_NO_4
 * @param2  : Copy_u8Channel
 *    param1 options : CHANNEL_NO_1 / CHANNEL_NO_2 / CHANNEL_NO_3 / CHANNEL_NO_4
 * @
 */
void Timer_voidInit(u8 Copy_u8Timer , u8 Copy_u8Channel)
{
	Timer_Handle_t Temp_Timer ;
	Temp_Timer.pTimerx_config.Timer_Mode = TIMER_MODE_PWM ;
	Temp_Timer.pTimerx_config.Timer_Channel=Copy_u8Channel;


	switch (Copy_u8Timer)
	{
	case TIMER_NO_2 :Temp_Timer.pTimerx = TIMER2 ;break;
	case TIMER_NO_3 :Temp_Timer.pTimerx = TIMER3 ; break;
	case TIMER_NO_4 :Temp_Timer.pTimerx = TIMER4 ;break;
	default : break ;

	}

	Timerx_voidStartPWM(&Temp_Timer);

}

/**-----------------------------------------------------------------------------------------------*/
/**
 * @fun    : Timer_voidGPIOInit
 * @brief  : initializes the related GPIO PIN to the specified Timer Channel
 * @param  :  Copy_u8TimerChannel  :
 * Parameter options  :
 * 				TIMER2_CH1 / TIMER2_CH2 / TIMER2_CH3 / TIMER2_CH4
 * 				TIMER3_CH1 / TIMER3_CH2 / TIMER3_CH3 / TIMER3_CH4
 * 				TIMER3_CH4 / TIMER4_CH2 / TIMER4_CH3 / TIMER4_CH4
 * @return : void
 */

void Timer_voidGPIOInit(u8 Copy_u8TimerChannel )
{
	GPIO_Handle_t  Temp_GPIO ;
	Temp_GPIO.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_AFPP ;
	if (Copy_u8TimerChannel < TIMER3_CH3 )
	{
		Temp_GPIO.pGPIOx = GPIOA ;
	}
	else
	{
		Temp_GPIO.pGPIOx = GPIOB ;
	}

	switch (Copy_u8TimerChannel)
	{
	case TIMER2_CH1 : Temp_GPIO.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0 ; break ;
	case TIMER2_CH2 : Temp_GPIO.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_1 ; break ;
	case TIMER2_CH3 : Temp_GPIO.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_2 ; break ;
	case TIMER2_CH4 : Temp_GPIO.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_3 ; break ;
	case TIMER3_CH1 : Temp_GPIO.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_6 ; break ;
	case TIMER3_CH2 : Temp_GPIO.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_7 ; break ;

	case TIMER3_CH3 : Temp_GPIO.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0 ; break ;
	case TIMER3_CH4 : Temp_GPIO.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_1 ; break ;
	case TIMER4_CH1 : Temp_GPIO.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_6 ; break ;
	case TIMER4_CH2 : Temp_GPIO.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_7 ; break ;
	case TIMER4_CH3 : Temp_GPIO.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_8 ; break ;
	case TIMER4_CH4 : Temp_GPIO.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_9 ; break ;

	default : break ;
	}

	GPIO_vidInit(&Temp_GPIO);

}

/**-----------------------------------------------------------------------------------------------*/
/**
 * @fun     :Timer_SetDutyCycle
 * @brief   :Sets the duty cycle for the corresponding Channel
 * @param1  :Copy_u8TimerChannel
 * Param1 options  :
 * 				TIMER2_CH1 / TIMER2_CH2 / TIMER2_CH3 / TIMER2_CH4
 * 				TIMER3_CH1 / TIMER3_CH2 / TIMER3_CH3 / TIMER3_CH4
 * 				TIMER3_CH4 / TIMER4_CH2 / TIMER4_CH3 / TIMER4_CH4
 * @param2  :Copy_u16DutyCycle
 */
void Timer_SetDutyCycle(u8 Copy_u8TimerChannel , u16 Copy_u16DutyCycle)
{
	switch (Copy_u8TimerChannel)
	{
	case TIMER2_CH1 : TIMER2->CCR1 = Copy_u16DutyCycle; break ;
	case TIMER2_CH2 : TIMER2->CCR2 = Copy_u16DutyCycle; break ;
	case TIMER2_CH3 : TIMER2->CCR3 = Copy_u16DutyCycle; break ;
	case TIMER2_CH4 : TIMER2->CCR4 = Copy_u16DutyCycle; break ;
	case TIMER3_CH1 : TIMER3->CCR1 = Copy_u16DutyCycle; break ;
	case TIMER3_CH2 : TIMER3->CCR2 = Copy_u16DutyCycle; break ;
	case TIMER3_CH3 : TIMER3->CCR3 = Copy_u16DutyCycle; break ;
	case TIMER3_CH4 : TIMER3->CCR4 = Copy_u16DutyCycle; break ;
	case TIMER4_CH1 : TIMER4->CCR1 = Copy_u16DutyCycle; break ;
	case TIMER4_CH2 : TIMER4->CCR2 = Copy_u16DutyCycle; break ;
	case TIMER4_CH3 : TIMER4->CCR3 = Copy_u16DutyCycle; break ;
	case TIMER4_CH4 : TIMER4->CCR4 = Copy_u16DutyCycle; break ;

	default : break ;
	}
}

/**---------------------------------  Private Functions-------------------------------------------*/
/**************************************************************************************************/
/**-----------------------------------------------------------------------------------------------*/
/**
 * @fun   Timer_PeriClockControl
 * @brief Enables or disables the Clock for a specific Timer Perioheral
 * @param pTimerx
 * @param EnorDi
 */
void Timer_PeriClockControl(Timer_RegDef_t *pTimerx, u8 EnorDi)
{
	if      ( EnorDi == ENABLE )
	{
		if (pTimerx == TIMER1 )
		{
			RCC_void_EnableClock( RCC_APB2 , RCC_APB2_TIMER1  ) ;

		}
		else if (pTimerx == TIMER2 )
		{
			 RCC_void_EnableClock( RCC_APB1 , RCC_APB1_TIMER2  ) ;
		}
		else if (pTimerx == TIMER3 )
		{
			RCC_void_EnableClock( RCC_APB1 , RCC_APB1_TIMER3  ) ;
		}
		else if (pTimerx == TIMER4 )
		{
			RCC_void_EnableClock( RCC_APB1 , RCC_APB1_TIMER4  ) ;
		}
		else if (pTimerx == TIMER5 )
		{
			RCC_void_EnableClock( RCC_APB1 , RCC_APB1_TIMER5  ) ;
		}

		else
		{
			// report error
		}


	}
	else if ( EnorDi == DISABLE )
	{
		if (pTimerx == TIMER1 )
		{
			RCC_void_DisableClock( RCC_APB2 , RCC_APB2_TIMER1  ) ;

		}
		else if (pTimerx == TIMER2 )
		{
			RCC_void_DisableClock( RCC_APB1 , RCC_APB1_TIMER2  ) ;
		}
		else if (pTimerx == TIMER3 )
		{
			RCC_void_DisableClock( RCC_APB1 , RCC_APB1_TIMER3  ) ;
		}
		else if (pTimerx == TIMER4 )
		{
			RCC_void_DisableClock( RCC_APB1 , RCC_APB1_TIMER4  ) ;
		}
		else if (pTimerx == TIMER5 )
		{
			RCC_void_DisableClock( RCC_APB1 , RCC_APB1_TIMER5  ) ;
		}
		else
		{
			// report error configurating Timer address
		}

	}
	else
	{
		// report error configurating Enable or Disable macros
	}

}

/**-----------------------------------------------------------------------------------------------*/
/**
 *
 * @param pTimerx_Handle
 */
void Timerx_voidStartPWM  (Timer_Handle_t *pTimerx_Handle)
{

	// ENABLE CLOCK POR TIMER PERIPHERAL
	Timer_PeriClockControl( (pTimerx_Handle->pTimerx) , ENABLE ) ;


	// CONFIGURE TIMER MODE
	switch (pTimerx_Handle->pTimerx_config.Timer_Mode)
	{
	case TIMER_MODE_PWM :
		// CONFIGURE  THE PRESCALER
		/** The counter clock frequency CK_CNT is equal to fCK_PSC / (PSC[15:0] + 1)
		* set prescale to be F = 1 MHz ; T = 0.000001 = 1µs
		* Fcounter = Fprescale/(PSC + 1) -> PSC = (Fprescale / Fcounter) - 1
		*
	    */

		pTimerx_Handle->pTimerx->PSC= 1 ;
		pTimerx_Handle->pTimerx->CR1 |=(1<<7); // 1: TIMx_ARR register is buffered
		pTimerx_Handle->pTimerx->CR1 &= ~(1<<4); // 0: Counter used as upcounter

		TIMER4->ARR = 4096 ;

		/** 	FOR THE REQUIRED CHANNEL :
		 *      CONFIGURE THE PWM MODE AND DUTY CYLE ,
		 *      OCR PRELOAD ENABLE ,
		 *      ENABLE OUT COMPARE .
		 */

		switch (pTimerx_Handle->pTimerx_config.Timer_Channel)
		{
		case TIMER_CHANNEL_CC1 :
			pTimerx_Handle->pTimerx->CCMR1 &= ~( (0b111)<< TIM_CCMR1_OC1M) ;
			pTimerx_Handle->pTimerx->CCMR1 |=  ( (TIMER_PWM_MODE)<< TIM_CCMR1_OC1M) ;
			SET_BIT(pTimerx_Handle->pTimerx->CCMR1 , TIM_CCMR1_OC1PE) ;
			SET_BIT(pTimerx_Handle->pTimerx->CCER , TIM_CCER_CC1E) ;
		    break;

		case TIMER_CHANNEL_CC2 :
			pTimerx_Handle->pTimerx->CCMR1 &= ~( (0b111)<< TIM_CCMR1_OC2M) ;
			pTimerx_Handle->pTimerx->CCMR1 |=  ( (TIMER_PWM_MODE)<< TIM_CCMR1_OC2M) ;
			SET_BIT(pTimerx_Handle->pTimerx->CCMR1 , TIM_CCMR1_OC2PE) ;
			SET_BIT(pTimerx_Handle->pTimerx->CCER , TIM_CCER_CC2E) ;
			break;

		case TIMER_CHANNEL_CC3 :
			pTimerx_Handle->pTimerx->CCMR2 &= ~( (0b111)<< TIM_CCMR2_OC3M) ;
			pTimerx_Handle->pTimerx->CCMR2 |=  ( (TIMER_PWM_MODE)<< TIM_CCMR2_OC3M) ;
			SET_BIT(pTimerx_Handle->pTimerx->CCMR2 , TIM_CCMR2_OC3PE) ;
			SET_BIT(pTimerx_Handle->pTimerx->CCER , TIM_CCER_CC3E) ;
		    break;

		case TIMER_CHANNEL_CC4 :
		    pTimerx_Handle->pTimerx->CCMR2 &= ~( (0b111)<< TIM_CCMR2_OC4M) ;
		    pTimerx_Handle->pTimerx->CCMR2 |=  ( (TIMER_PWM_MODE)<< TIM_CCMR2_OC4M) ;
		    SET_BIT(pTimerx_Handle->pTimerx->CCMR2 , TIM_CCMR2_OC4PE) ;
		    SET_BIT(pTimerx_Handle->pTimerx->CCER , TIM_CCER_CC4E) ;
		    break;

		default                : break ;

		}  break ;



	default : break ;
	}

	pTimerx_Handle->pTimerx->EGR |=(1<<0);  // update generation
	// ENABLE COUNTER
	SET_BIT(pTimerx_Handle->pTimerx->CR1 , TIM_CR1_CEN) ;
}

/**-----------------------------------------------------------------------------------------------*/
/**
 * @fun    Timer_DeInit
 * @brief De-initializes a specific Timer
 * @param pTimerx_Handle
 */
void Timer_DeInit          (Timer_Handle_t *pTimerx_Handle)
{
	// DISABLE COUNTER
	CLR_BIT(pTimerx_Handle->pTimerx->CR1 , TIM_CR1_CEN) ;

	// DISABLE CLOCK
	Timer_PeriClockControl(pTimerx_Handle->pTimerx , DISABLE ) ;
}

/**-----------------------------------------------------------------------------------------------*/

