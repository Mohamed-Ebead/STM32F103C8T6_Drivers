/*
 * ADC_program.c
 *
 *  Created on: Aug 21, 2020
 *      Author: Mohamed  Ebead
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"



/*-------------------------------------------------------------------------------------------------*/
/**
 * @fun      ADC_vidPeriClockControl
 * @brief    this function enables or disables the clock for the ADC peripheral
 * @param    pADCx      // ADc peripheral
 * @param    EnorDi     // ENABLE or DISABLE   macro
 * @return   none
 */
void ADC_vidPeriClockControl (ADC_RegDef_t *pADCx , u8 EnorDi  )
{
	if(EnorDi == ENABLE)
	{
		if       (pADCx == ADC1)
		{
			RCC_void_EnableClock(RCC_ADC_BUS , RCC_ADC1) ;
		}else if (pADCx == ADC2)
		{
			RCC_void_EnableClock(RCC_ADC_BUS , RCC_ADC2) ;
		}else if (pADCx == ADC3)
		{
			RCC_void_EnableClock(RCC_ADC_BUS , RCC_ADC3) ;
		}
	}
	else
	{
		if	     (pADCx == ADC1)
		{
			RCC_void_DisableClock(RCC_ADC_BUS , RCC_ADC1) ;
		}else if (pADCx == ADC2)
		{
			RCC_void_DisableClock(RCC_ADC_BUS , RCC_ADC2) ;
		}else if (pADCx == ADC3)
		{
			RCC_void_DisableClock(RCC_ADC_BUS , RCC_ADC3) ;
		}
	}

}

/*-------------------------------------------------------------------------------------------------*/
/**
 *
 * @param pADC_Handle
 */
void ADC_vidInit (ADC_Handle_t *pADC_Handle )
{
	u8 Local_u8Channel    = pADC_Handle->ADC_Config.Channel        ;
	u8 Local_u8DataAlign  = pADC_Handle->ADC_Config.DataAlign      ;
	u8 Local_u8SampleTime = pADC_Handle->ADC_Config.SampleTime     ;
	u8 Local_u8ConvMode   = pADC_Handle->ADC_Config.ConversionMode ;
	u8 Local_u8ConvNum    = pADC_Handle->ADC_Config.ConversionNum  ;

	// ENABLE clock for ADC peripheral
	ADC_vidPeriClockControl ( (pADC_Handle->pADCx ) , ENABLE) ;




	// configure the data alignment
	if (Local_u8DataAlign == ADC_LEFT_ALIGNMENT)
	{
		pADC_Handle->pADCx->CR2 |= (1<<CR2_ALIGN_BIT) ;
	}
	else if (Local_u8DataAlign == ADC_RIGHT_ALIGNMENT)
	{
		pADC_Handle->pADCx->CR2 &= ~(1<<CR2_ALIGN_BIT) ;
	}
	else
	{
		// error data alignment parameter
	}

	// select the sample time for the channel
	if 		( Local_u8Channel <= 9 )
	{
		pADC_Handle->pADCx->SMPR2 &= ~( (0b111) << (3*Local_u8Channel) )   ;
		pADC_Handle->pADCx->SMPR2 |=  ( (Local_u8SampleTime) << (3*Local_u8Channel) )   ;
	}
	else if ( Local_u8Channel <= 17 )
	{
		pADC_Handle->pADCx->SMPR1 &= ~( (0b111) << (3*(Local_u8Channel-10)) )   ;
		pADC_Handle->pADCx->SMPR1 |=  ( (Local_u8SampleTime) << (3*(Local_u8Channel-10)) )   ;
	}
	else
	{
		// error invalid channel
	}


	pADC_Handle->pADCx->SQR3 |= Local_u8Channel << (5*Local_u8ConvNum) ;

	switch (Local_u8ConvMode)
	{
		case ADC_CONVMODE_CONTINOUS :
			/* not concerned about power consumption, just start the continuous
			 * conversions and will read the DR periodically
			 */
			// put ADC into continuous mode and turn on ADC
			pADC_Handle->pADCx->CR2 |= (1<<CR2_CONT_BIT) ;
			break ;
		case ADC_CONVMODE_SINGLE :
			// put ADC into single mode and turn on ADC
			pADC_Handle->pADCx->CR2 &= ~(1<<CR2_CONT_BIT) ;
			break ;
		case ADC_CONVMODE_SCAN :

			break ;

		default :
			// error invalid conversion mode
			break ;
	}


	// Wake up the ADC from Power Down state
	pADC_Handle->pADCx->CR2 |= (1<<CR2_ADON_BIT) ;

	// reset calibration registers
	pADC_Handle->pADCx->CR2 |= (1<<CR2_RSTCAL_BIT) ;


	// wait for calibration register initialized
	while ( ( GET_BIT( (pADC_Handle->pADCx->CR2),CR2_RSTCAL_BIT ) ) ) ;

	 // enable calibration
	pADC_Handle->pADCx->CR2 |= (1<<CR2_CAL_BIT) ;

	// wait for calibration completed
	while ( ( GET_BIT( (pADC_Handle->pADCx->CR2),CR2_CAL_BIT ) ) ) ;


}

/*-------------------------------------------------------------------------------------------------*/
/**
 *
 * @param pADC_Handle
 * @return
 */
u32 ADC_u16ReadBlocking    ( ADC_Handle_t *pADC_Handle )
{
	u32 Local_u32Digital_Value  = 0 ;

	// Start conversion
	pADC_Handle->pADCx->CR2 &= ~(1<<CR2_ADON_BIT) ;

	// Start conversion
	pADC_Handle->pADCx->CR2 |= (1<<CR2_ADON_BIT) ;
	// Start conversion
	pADC_Handle->pADCx->CR2 |= (1<<CR2_ADON_BIT) ;

	// wait for the End of conversion
	while ( !( GET_BIT( (pADC_Handle->pADCx->SR),SR_EOC_BIT ) ) ) ;

	// Store the value after conversion and clear EOC bit by software or by reading the ADC_DR.
	Local_u32Digital_Value = pADC_Handle->pADCx->DR ;
	pADC_Handle->pADCx->SR &= ~(1<<SR_EOC_BIT) ;

	// Clear Regular channel Start flag
	pADC_Handle->pADCx->SR &= ~(1<<SR_STRT_BIT) ;


	return Local_u32Digital_Value ;
}

/*-------------------------------------------------------------------------------------------------*/
/**
 *
 * @param pADC_Handle
 * @return
 */
u32 ADC_u16ReadNonBlocking ( ADC_Handle_t *pADC_Handle )
{

}

/*-------------------------------------------------------------------------------------------------*/









