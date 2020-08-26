/*
 * VNIC_program.c
 *
 *  Created on: Aug 23, 2020
 *      Author: Mohamed  Ebead
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

/**----------------------------------------------------------------------------------------------*/
/**
 *
 * @param Copy_u8IntNumber
 */
void NVIC_voidEnableInterrupt (u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31)
	{
		NVIC_ISER0 = (1 << Copy_u8IntNumber);
	}

	else if (  Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISER1 = (1 << Copy_u8IntNumber);
	}

	else
	{
		/* Return Error */
	}

}


/**----------------------------------------------------------------------------------------------*/
/**
 *
 * @param Copy_u8IntNumber
 */
void NVIC_voidDisableInterrupt (u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31)
	{
		NVIC_ICER0 |= 1 << Copy_u8IntNumber;
	}

	else if (  Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICER1 |= 1 << Copy_u8IntNumber;
	}

	else
	{
		/* Return Error */
	}

}

/**----------------------------------------------------------------------------------------------*/
/**
 *
 * @param Copy_u8IntNumber
 */
void NVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31)
	{
		NVIC_ISPR0 |= 1 << Copy_u8IntNumber;
	}

	else if (  Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISPR1 |= 1 << Copy_u8IntNumber;
	}

	else
	{
		/* Return Error */
	}

}

/**----------------------------------------------------------------------------------------------*/
/**
 *
 * @param Copy_u8IntNumber
 */
void NVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31)
	{
		NVIC_ICPR0 = 1 << Copy_u8IntNumber ;
	}

	else if (  Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICPR1 = (1 << Copy_u8IntNumber);
	}

	else
	{
		/* Return Error */
	}

}



/**----------------------------------------------------------------------------------------------*/
/**
 *
 * @param Copy_u8IntNumber
 * @return
 */
u8 NVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8Result = 0 ;

	if ( Copy_u8IntNumber <= 31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
	}

	else if (  Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		Local_u8Result = GET_BIT(NVIC_IABR1,Copy_u8IntNumber);
	}

	else
	{
		/* Return Error */
	}

	return Local_u8Result;

}

/**----------------------------------------------------------------------------------------------*/
/**
 *
 * @param Copy_s8InterruptID
 * @param Copy_u8GroupPriority
 * @param Copy_u8SubPriority
 * @param Copy_u8Group
 */
void NVIC_voidSetPriority (NVIC_Config_t *pNVIC )
{
	s8 Local_s8InterruptID   = pNVIC->InterruptID   ;
	u8 Local_u8GroupPriority = pNVIC->GroupPriority ;
	u8 Local_u8SubPriority   = pNVIC->SubPriority  ;


	u8 Local_u8Priority = Local_u8SubPriority|Local_u8GroupPriority<<((NO_OF_GROUPS_SUB - 0x05FA0300)/256) ;

	/** Core Peripheral */
	if (Local_s8InterruptID <0)
	{

	}

	/** External Peripheral */
	else if (Local_s8InterruptID >= 0)
	{
		NVIC_IPR[Local_s8InterruptID] = Local_u8Priority <<4 ;

	}

	SCB_AIRCR = NO_OF_GROUPS_SUB ;

}

/**----------------------------------------------------------------------------------------------*/



















