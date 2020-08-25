/*
 * SysTick_program.c
 *
 *  Created on: Aug 25, 2020
 *      Author: Mohamed  Ebead
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"

#include "SysTick_interface.h"
#include "SysTick_config.h"
#include "SysTick_private.h"

/**-------------------------------------------------------------------------------------------------------*/
/**
 *
 */
void STK_voidInit (void)
{
	// configure the clock source
	switch (STK_CLKSOURCE)
	{
	    case STK_CLK_AHB       : SET_BIT(STK->CTRL , STK_CTRL_CLK_SOURCE) ; break ;
	    case STK_CLK_AHB_DIV_8 : CLR_BIT(STK->CTRL , STK_CTRL_CLK_SOURCE) ; break ;
	    default : break ;   // report error
	}


	// configure the tick interrupt
	switch ( STK_TICK_INTERRUPT )
	{
	    case STK_TICKINT_ENABLE  : SET_BIT(STK->CTRL , STK_CTRL_TICK_INT) ; break ;
	    case STK_TICKINT_DISABLE : CLR_BIT(STK->CTRL , STK_CTRL_TICK_INT) ; break ;
	    default : break ;   // report error
	}


	// configure the counter enable
	switch ( STK_COUNTER )
	{
	    case STK_COUNTER_ENABLE  : SET_BIT(STK->CTRL , STK_CTRL_EN) ; break ;
	    case STK_COUNTER_DISABLE : CLR_BIT(STK->CTRL , STK_CTRL_EN) ; break ;
	    default : break ;   // report error
	}

}

/**-------------------------------------------------------------------------------------------------------*/
/**
 *
 * @param Copy_u8LoadValue
 */
void STK_voidLoadValue (u32 Copy_u8LoadValue)
{
	STK->LOAD = Copy_u8LoadValue ;
}

/**-------------------------------------------------------------------------------------------------------*/
/**
 *
 * @return
 */
u32 STK_u32GetCurrentValue (void )
{
	return (u32)(STK->VAL)  ;
}

/**-------------------------------------------------------------------------------------------------------*/









