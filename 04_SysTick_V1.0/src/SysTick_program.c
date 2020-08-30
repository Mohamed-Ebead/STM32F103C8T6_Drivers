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





/**---------------------------------------------------------------------------------------------------------*/
/**
 *  @fun   STK_voidInit
 *  @brief Selects Clock source for STK counter
 *
 */
void STK_voidInit(void)
{
	// configure the clock source
#if STK_CLKSOURCE == STK_CLK_AHB
	SET_BIT(STK->CTRL , STK_CTRL_CLK_SOURCE) ;
	#define STK_CLOCK   (u32)8000000
#elif STK_CLKSOURCE == STK_CLK_AHB_DIV_8
	CLR_BIT(STK->CTRL , STK_CTRL_CLK_SOURCE) ;
	#define STK_CLOCK   (u32)1000000

#endif

}

/**---------------------------------------------------------------------------------------------------------*/
/**
 * @fun   STK_voidEnableTICKInterrupt
 * @brief Enables STK interrupt request
 *
 */
void STK_voidEnableTICKInterrupt(void)
{
	SET_BIT(STK->CTRL , STK_CTRL_TICK_INT) ;
}

/**---------------------------------------------------------------------------------------------------------*/
/**
 * @fun   STK_voidDisableTICKInterrupt
 * @brief Disables STK interrupt request
 *
 */
void STK_voidDisableTICKInterrupt(void)
{
	CLR_BIT(STK->CTRL , STK_CTRL_TICK_INT) ;
}


/**---------------------------------------------------------------------------------------------------------*/
/**
 * @fun   STK_voidEnableCounter
 * @brief Enables STK counter
 */
void STK_voidEnableCounter(void)
{
	 SET_BIT(STK->CTRL , STK_CTRL_EN) ;
}

/**---------------------------------------------------------------------------------------------------------*/
/**
 * @fun   STK_voidDisbleCounter
 * @brief Disables STK counter
 */
void STK_voidDisbleCounter(void)
{
	 CLR_BIT(STK->CTRL , STK_CTRL_EN) ;
}

/**---------------------------------------------------------------------------------------------------------*/

/**
 * @fun    STK_voidLoadVal
 * @brief  Reloads STK counter value
 * @param  Cpy_u32LoadVal
 */

void STK_voidLoadVal(u32 Cpy_u32LoadVal)
{
	STK -> LOAD = Cpy_u32LoadVal ;
}

/**---------------------------------------------------------------------------------------------------------*/
/**
 * @fun     STK_u32GetCurrentVal
 * @brief   Returns Current value of STK counter
 * @return
 */
u32 STK_u32GetCurrentVal(void)
{
	return ( (u32)(STK->VAL) ) ;
}

/**---------------------------------------------------------------------------------------------------------*/

/**
 * @fun   STK_voidSetBusyWait
 * @brief Starts a busy wait for a certain time determined
 * 		  by the arguments before calling the callback function
 * @param Cpy_u32DelayVal   Value of delay needed to be done
 * @param Cpy_u8ValueType   Type of delay value
 * @param func               Function to be which is to be called back after the busy wait
 *
 */
void STK_voidSetBusyWait(u32 Cpy_u32DelayVal, u8 Cpy_u8ValueType, void (*func)(void))
{

	switch(Cpy_u8ValueType)
	{
		case STK_TICKS  :								  						    break;
		case STK_MICROS :	Cpy_u32DelayVal *= (STK_CLOCK/STK_MICROS_DIVIDER);		break;
		case STK_MILLIS :	Cpy_u32DelayVal *= (STK_CLOCK/STK_MILLIS_DIVIDER);		break;
		case STK_SECONDS:	Cpy_u32DelayVal *= (STK_CLOCK);							break;
	}
	STK_voidEnableTICKInterrupt ();
	STK->VAL = 0x00;
	STK_voidLoadVal(Cpy_u32DelayVal);
    STK_voidEnableCounter() ;

	while( !(GET_BIT(STK->CTRL, STK_CTRL_COUNT_FLAG)) );
	STK_voidDisbleCounter();

	func();

}

/**---------------------------------------------------------------------------------------------------------*/
/**
 * @fun   STK_voidSetSingleInterval
 * @brief Starts a single interval for a certain time determined
 *        by the arguments before calling the callback function
 * @param Cpy_u32DelayVal  Value of delay needed to be done
 * @param Cpy_u8ValueType  Type of delay value
 * @param func              Function to be which is to be called back after the busy wait
 *
 */

void STK_voidSetSingleInterval(u32 Cpy_u32DelayVal, u8 Cpy_u8ValueType, void (*func)(void))
{

	STK_u8PvtIntervalState = STK_U8_SINGLE_INTERVAL;
	switch(Cpy_u8ValueType)
	{
		case STK_TICKS  :															break;
		case STK_MICROS :	Cpy_u32DelayVal *= (STK_CLOCK/STK_MICROS_DIVIDER);		break;
		case STK_MILLIS :	Cpy_u32DelayVal *= (STK_CLOCK/STK_MILLIS_DIVIDER);		break;
		case STK_SECONDS:	Cpy_u32DelayVal *= (STK_CLOCK);							break;
	}
	STK_voidEnableTICKInterrupt ();
	STK->VAL = 0x00;
	STK_voidLoadVal(Cpy_u32DelayVal);
	STK_voidEnableCounter() ;

	CallBack = func;

}

/**---------------------------------------------------------------------------------------------------------*/
/**
 * @fun   STK_voidSetPeriodicInterval
 * @brief Starts a periodic interval for a certain time determined
 *        by the arguments before calling the callback function
 * @param Cpy_u32DelayVal  Value of delay needed to be done
 * @param Cpy_u8ValueType  Type of delay value
 * @param func             Function to be which is to be called back after the busy wait
 *
 */
void STK_voidSetPeriodicInterval(u32 Cpy_u32DelayVal, u8 Cpy_u8ValueType, void (*func)(void))
{
	STK_u8PvtIntervalState = STK_U8_PERIODIC_INTERVAL;
	switch(Cpy_u8ValueType)
	{
		case STK_TICKS  :															break;
		case STK_MICROS :	Cpy_u32DelayVal *= (STK_CLOCK/STK_MICROS_DIVIDER);		break;
		case STK_MILLIS :	Cpy_u32DelayVal *= (STK_CLOCK/STK_MILLIS_DIVIDER);		break;
		case STK_SECONDS:	Cpy_u32DelayVal *= (STK_CLOCK);							break;
	}
	STK_voidEnableTICKInterrupt ();
	STK->VAL = 0x00;
	STK_voidLoadVal(Cpy_u32DelayVal);
	STK_voidEnableCounter() ;

	CallBack = func;

}

/**---------------------------------------------------------------------------------------------------------*/

/**
 * @fun     STK_u32GetElapsedTime
 * @brief   Returns Elapsed time since start of current interval
 * @param   Cpy_u8TimeType
 * @return
 */
u32 STK_u32GetElapsedTime(u8 Cpy_u8TimeType)
{
	switch(Cpy_u8TimeType)
	{
		case STK_TICKS   : return ((STK->LOAD)  - (STK->VAL));										break;
		case STK_MICROS  : return (((STK->LOAD) - (STK->VAL)) / (STK_CLOCK/STK_MICROS_DIVIDER));	break;
		case STK_MILLIS  : return (((STK->LOAD) - (STK->VAL)) / (STK_CLOCK/STK_MILLIS_DIVIDER));	break;
		case STK_SECONDS : return (((STK->LOAD) - (STK->VAL)) / (STK_CLOCK));						break;
	}
}

/**---------------------------------------------------------------------------------------------------------*/
/**
 * @fun   STK_u32GetRemainingTime
 * @brief Returns remaining time of current interval
 * @param Cpy_u8TimeType
 * @return
 *
 */
u32 STK_u32GetRemainingTime(u8 Cpy_u8TimeType)
{
	switch(Cpy_u8TimeType)
	{
		case STK_TICKS  :	return (STK->VAL);											break;
		case STK_MICROS :	return ((STK->VAL) / (STK_CLOCK/STK_MICROS_DIVIDER));		break;
		case STK_MILLIS :	return ((STK->VAL) / (STK_CLOCK/STK_MILLIS_DIVIDER));		break;
		case STK_SECONDS:	return ((STK->VAL) / (STK_CLOCK));							break;
	}
}

/**---------------------------------------------------------------------------------------------------------*/
/**
 * @fun    STK_voidStopTimer
 * @brief  Disables the STK timer which stops the periodic interval
 *
 */
void STK_voidStopTimer(void)
{
	STK_voidDisbleCounter() ;
}

/**---------------------------------------------------------------------------------------------------------*/


void SysTick_Handler(void)
{
	CallBack();
	switch(STK_u8PvtIntervalState)
	{
	case STK_U8_SINGLE_INTERVAL:
		STK_voidDisbleCounter();
		break;
	case STK_U8_PERIODIC_INTERVAL:
		break;
	}
}


/**---------------------------------------------------------------------------------------------------------*/


