/*
 * SysTick_program.c
 *
 *  Created on: Aug 25, 2020
 *      Author: Mohamed  Ebead
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "SysTick_interface.h"
#include "SysTick_config.h"
#include "SysTick_private.h"


/**-------------------------------------------------------------------------------------------------------*/
/**
 * @fun    STK_voidInit
 * @brief  this function initializes the systick timer as configured in STK_config.h
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
 * @fun   STK_voidLoadValue
 * @brief this function loads the timer with a value to start counting down from it until it reaches zero
 * 			until underflow occurs
 * @param Copy_u8LoadValue
 */
void STK_voidLoadValue (u32 Copy_u8LoadValue)
{
	STK->LOAD = Copy_u8LoadValue ;
}

/**-------------------------------------------------------------------------------------------------------*/
/**
 * @fun    STK_u32GetCurrentValue
 * @brief  this function returns the current value in the counting register
 * @return u32 the current counting value
 */
u32 STK_u32GetCurrentValue (void )
{
	return (u32)(STK->VAL)  ;
}

/**-------------------------------------------------------------------------------------------------------*/
/**
 * @fun   STK_voidDelay_ms_Polling
 * @brief this function makes a delay for chosen milliseconds
 * @param Copy_u16MilliSeconds
 * @note  this function acts in polling mode not interrupt mode
 * 			so configure the systick timer interrupt as STK_TICKINT_DISABLE in STK_config.h
 */
void STK_voidDelay_ms_Polling (u16 Copy_u16MilliSeconds)
{
	switch (STK_CLKSOURCE)
	{
		case STK_CLK_AHB       : STK->LOAD = (1000*8*Copy_u16MilliSeconds) ; break ;
		case STK_CLK_AHB_DIV_8 : STK->LOAD = (1000*Copy_u16MilliSeconds  ) ; break ;
		default : break ;   // report error
	}

	while (!(GET_BIT(STK->CTRL , STK_CTRL_COUNT_FLAG ))) ;  // wait until under flow flag is raised

	CLR_BIT(STK->CTRL , STK_CTRL_COUNT_FLAG ) ;     // clear under flow flag
}

/**-------------------------------------------------------------------------------------------------------*/
/**
 * @fun   STK_voidDelay_us_Polling
 * @brief this function makes a delay for chosen microseconds
 * @param Copy_u16MicroSeconds
 * @note  this function acts in polling mode not interrupt mode
 * 			so configure the systick timer interrupt as STK_TICKINT_DISABLE in STK_config.h
 */
void STK_voidDelay_us_Polling (u16 Copy_u16MicroSeconds)
{
	switch (STK_CLKSOURCE)
	{
		case STK_CLK_AHB       : STK->LOAD = (8*Copy_u16MicroSeconds) ; break ;
		case STK_CLK_AHB_DIV_8 : STK->LOAD = (  Copy_u16MicroSeconds) ; break ;
		default : break ;   // report error
	}

	while (!(GET_BIT(STK->CTRL , STK_CTRL_COUNT_FLAG ))) ;  // wait until under flow flag is raised

	CLR_BIT(STK->CTRL , STK_CTRL_COUNT_FLAG ) ;     // clear under flow flag

}

/**-------------------------------------------------------------------------------------------------------*/

/**------------------ RTOS SPECIFIC ------------------*/
//
static void(*Global_pFn)(void) ;

void STK_SetCallBack (void (*local_pFn)(void))
{
	Global_pFn = local_pFn ;

}



void SysTick_Handler(void)
{
	Global_pFn () ;
}





