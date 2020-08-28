/*
 * Timer_program.c
 *
 *  Created on: Aug 27, 2020
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
 *
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
		else if (pTimerx == TIMER6 )
		{
			RCC_void_EnableClock( RCC_APB1 , RCC_APB1_TIMER6  ) ;
		}
		else if (pTimerx == TIMER7 )
		{
			RCC_void_EnableClock( RCC_APB1 , RCC_APB1_TIMER7  ) ;
		}
		else if (pTimerx == TIMER8 )
		{
			RCC_void_EnableClock( RCC_APB2 , RCC_APB2_TIMER8  ) ;
		}
		else if (pTimerx == TIMER9 )
		{
			RCC_void_EnableClock( RCC_APB2 , RCC_APB2_TIMER9  ) ;
		}
		else if (pTimerx == TIMER10 )
		{
			RCC_void_EnableClock( RCC_APB2 , RCC_APB2_TIMER10 ) ;
		}
		else if (pTimerx == TIMER11 )
		{
			RCC_void_EnableClock( RCC_APB2 , RCC_APB2_TIMER11 ) ;
		}
		else if (pTimerx == TIMER12 )
		{
			RCC_void_EnableClock( RCC_APB1 , RCC_APB1_TIMER12 ) ;
		}
		else if (pTimerx == TIMER13 )
		{
			RCC_void_EnableClock( RCC_APB1 , RCC_APB1_TIMER13 ) ;
		}
		else if (pTimerx == TIMER14 )
		{
			RCC_void_EnableClock( RCC_APB1 , RCC_APB1_TIMER14 ) ;
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
		else if (pTimerx == TIMER6 )
		{
			RCC_void_DisableClock( RCC_APB1 , RCC_APB1_TIMER6  ) ;
		}
		else if (pTimerx == TIMER7 )
		{
			RCC_void_DisableClock( RCC_APB1 , RCC_APB1_TIMER7  ) ;
		}
		else if (pTimerx == TIMER8 )
		{
			RCC_void_DisableClock( RCC_APB2 , RCC_APB2_TIMER8  ) ;
		}
		else if (pTimerx == TIMER9 )
		{
			RCC_void_DisableClock( RCC_APB2 , RCC_APB2_TIMER9  ) ;
		}
		else if (pTimerx == TIMER10 )
		{
			RCC_void_DisableClock( RCC_APB2 , RCC_APB2_TIMER10 ) ;
		}
		else if (pTimerx == TIMER11 )
		{
			RCC_void_DisableClock( RCC_APB2 , RCC_APB2_TIMER11 ) ;
		}
		else if (pTimerx == TIMER12 )
		{
			RCC_void_DisableClock( RCC_APB1 , RCC_APB1_TIMER12 ) ;
		}
		else if (pTimerx == TIMER13 )
		{
			RCC_void_DisableClock( RCC_APB1 , RCC_APB1_TIMER13 ) ;
		}
		else if (pTimerx == TIMER14 )
		{
			RCC_void_DisableClock( RCC_APB1 , RCC_APB1_TIMER14 ) ;
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
void Timer_voidInit            (Timer_Handle_t *pTimerx_Handle)
{
	u16 prescale = 0 ;
	u16 period   = 0 ;
	// ENABLE CLOCK POR TIMER PERIPHERAL
	Timer_PeriClockControl( (pTimerx_Handle->pTimerx) , ENABLE ) ;

	/***
	// CONFIGURE CLOCK DIVISION
	pTimerx_Handle->pTimerx->CR1 &= ~( (0b11) << TIM_CR1_CKD ) ;
	pTimerx_Handle->pTimerx->CR1 |=  ( (pTimerx_Handle->pTimerx_config->ClockDivision) << TIM_CR1_CKD ) ;

	// CONFIGURE AUTO RELOAD PRELOAD
	switch (pTimerx_Handle->pTimerx_config->ARP_State)
	{
	case ARP_DISABLE : CLR_BIT(pTimerx_Handle->pTimerx->CR1 , TIM_CR1_ARPE) ; break ;
	case ARP_ENABLE  : SET_BIT(pTimerx_Handle->pTimerx->CR1 , TIM_CR1_ARPE) ; break ;
	default          : break ; // report error
	}

	// CONFIGURE CENTER ALIGNED MODE
	pTimerx_Handle->pTimerx->CR1 &= ~( (0b11) << TIM_CR1_CMS ) ;
	pTimerx_Handle->pTimerx->CR1 |=  ( (pTimerx_Handle->pTimerx_config->CenterAlignedMode) << TIM_CR1_CKD ) ;

	//CONFIGURE COUNT DIRECTION
	switch (pTimerx_Handle->pTimerx_config->CountDirection)
	{
	case UP_COUNTER    : CLR_BIT(pTimerx_Handle->pTimerx->CR1 , TIM_CR1_DIR) ; break ;
	case DOWN_COUNTER  : SET_BIT(pTimerx_Handle->pTimerx->CR1 , TIM_CR1_DIR) ; break ;
	default          : break ; // report error
	}

	// CONFIGURE ONE PULSE MODE
	switch (pTimerx_Handle->pTimerx_config->OnePulseMode)
	{
	case OPM_DISABLE : CLR_BIT(pTimerx_Handle->pTimerx->CR1 , TIM_CR1_OPM) ; break ;
	case OPM_ENABLE  : SET_BIT(pTimerx_Handle->pTimerx->CR1 , TIM_CR1_OPM) ; break ;
	default          : break ; // report error
	}

	// CONFIGURE UPDATE REQUEST SOURCE
	switch (pTimerx_Handle->pTimerx_config->UpdateRequestSource)
	{
	case URS_OVF_UVF_UG_UGS : CLR_BIT(pTimerx_Handle->pTimerx->CR1 , TIM_CR1_URS) ; break ;
	case URS_OVF_UVF        : SET_BIT(pTimerx_Handle->pTimerx->CR1 , TIM_CR1_URS) ; break ;
	default          : break ; // report error
	}

	// CONFIGURE UPDATE DISABLE
	switch (pTimerx_Handle->pTimerx_config->UpdateEventGeneration)
	{
	case UDIS_ENABLE  : CLR_BIT(pTimerx_Handle->pTimerx->CR1 , TIM_CR1_UDIS) ; break ;
	case UDIS_DISABLE : SET_BIT(pTimerx_Handle->pTimerx->CR1 , TIM_CR1_UDIS) ; break ;
	default          : break ; // report error
	}

*/

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
		prescale = (u16) (SYS_CLOCK / TIMER_PWM_CK_CNT_REQ)  ;
		pTimerx_Handle->pTimerx->PSC = prescale - 1;

		// set period to be 50Hz / 20ms
	    period = (u16)(SYS_CLOCK / prescale / TIMER_PWM_PULSE_FREQ);
		pTimerx_Handle->pTimerx->ARR = period ;

		/** 	FOR THE REQUIRED CHANNEL :
		 *      CONFIGURE THE CHANNEL DUTY CYLE ,
		 *      PWM MODE AND DUTY CYLE ,
		 *      OCR PRELOAD ENABLE ,
		 *      ENABLE OUT COMPARE .
		 */
		switch (TIMER_PWM_CHANNEL)
		{
		case TIMER_CHANNEL_CC1 :
			pTimerx_Handle->pTimerx->CCR1 = TIMER_PWM_DUTY_CYCLE ;
			pTimerx_Handle->pTimerx->CCMR1 &= ~( (0b111)<< TIM_CCMR1_OC1M) ;
			pTimerx_Handle->pTimerx->CCMR1 |=  ( (TIMER_PWM_MODE)<< TIM_CCMR1_OC1M) ;
			SET_BIT(pTimerx_Handle->pTimerx->CCMR1 , TIM_CCMR1_OC1PE) ;
			SET_BIT(pTimerx_Handle->pTimerx->CCER , TIM_CCER_CC1E) ;
		    break;

		case TIMER_CHANNEL_CC2 :
			pTimerx_Handle->pTimerx->CCR2 = TIMER_PWM_DUTY_CYCLE ;
			pTimerx_Handle->pTimerx->CCMR1 &= ~( (0b111)<< TIM_CCMR1_OC2M) ;
			pTimerx_Handle->pTimerx->CCMR1 |=  ( (TIMER_PWM_MODE)<< TIM_CCMR1_OC2M) ;
			SET_BIT(pTimerx_Handle->pTimerx->CCMR1 , TIM_CCMR1_OC2PE) ;
			SET_BIT(pTimerx_Handle->pTimerx->CCER , TIM_CCER_CC2E) ;
			break;

		case TIMER_CHANNEL_CC3 :
			pTimerx_Handle->pTimerx->CCR3 = TIMER_PWM_DUTY_CYCLE ;
			pTimerx_Handle->pTimerx->CCMR2 &= ~( (0b111)<< TIM_CCMR2_OC3M) ;
			pTimerx_Handle->pTimerx->CCMR2 |=  ( (TIMER_PWM_MODE)<< TIM_CCMR2_OC3M) ;
			SET_BIT(pTimerx_Handle->pTimerx->CCMR2 , TIM_CCMR2_OC3PE) ;
			SET_BIT(pTimerx_Handle->pTimerx->CCER , TIM_CCER_CC3E) ;
		    break;

		case TIMER_CHANNEL_CC4 :
			pTimerx_Handle->pTimerx->CCR4 = TIMER_PWM_DUTY_CYCLE ;
		    pTimerx_Handle->pTimerx->CCMR2 &= ~( (0b111)<< TIM_CCMR2_OC4M) ;
		    pTimerx_Handle->pTimerx->CCMR2 |=  ( (TIMER_PWM_MODE)<< TIM_CCMR2_OC4M) ;
		    SET_BIT(pTimerx_Handle->pTimerx->CCMR2 , TIM_CCMR2_OC4PE) ;
		    SET_BIT(pTimerx_Handle->pTimerx->CCER , TIM_CCER_CC4E) ;
		    break;

		default                : break ;




		}  break ;



	default : break ;
	}


	// ENABLE COUNTER
	SET_BIT(pTimerx_Handle->pTimerx->CR1 , TIM_CR1_CEN) ;
}

/**-----------------------------------------------------------------------------------------------*/

void Timer_DeInit          (Timer_Handle_t *pTimerx_Handle)
{
	// DISABLE COUNTER
	CLR_BIT(pTimerx_Handle->pTimerx->CR1 , TIM_CR1_CEN) ;

	// DISABLE CLOCK
	Timer_PeriClockControl(pTimerx_Handle->pTimerx , DISABLE ) ;
}



/**-----------------------------------------------------------------------------------------------*/
void Timer_Init_PWM        (void )
{
	GPIO_Handle_t PWM_CH ;
	PWM_CH.pGPIOx = GPIOA ;
	PWM_CH.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0 ;
	PWM_CH.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_AFPP ;
	GPIO_vidInit(&PWM_CH);

	Timer_Handle_t TIM2_CH2 ;
	TIM2_CH2.pTimerx = TIMER2 ;
	TIM2_CH2.pTimerx_config.Timer_Mode = TIMER_MODE_PWM ;
	Timer_voidInit(&TIM2_CH2);


}

/**-----------------------------------------------------------------------------------------------*/
void Timer_LoadPWM         (Timer_RegDef_t *pTimerx , u16 Copy_u16Value )
{
	pTimerx->ARR = Copy_u16Value ;
}

/**-----------------------------------------------------------------------------------------------*/

