/*
 * EXTI_program.c
 *
 *  Created on: Aug 23, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


/**--------------------------------------------------------------------------------------*/
/**
 *
 * @param pEXTI
 */
void EXTI_voidInit(EXTI_config_t *pEXTI )
{
	u8 Local_u8EXTILine  = pEXTI->Line ;
	u8 Local_u8Trigger   = pEXTI->Trigger ;
	u8 Local_u8SWTrigger = pEXTI->SWTrigger ;


	/*Disable interrupt at the beginning */
	//CLR_BIT(EXTI->IMR , Local_u8EXTILine);

	// Enable EXTI
	SET_BIT(EXTI->IMR , Local_u8EXTILine);

	switch (Local_u8Trigger)
	{
	case RISING    : SET_BIT(EXTI->RTSR , EXTI_LINE); break ;
	case FALLING   : SET_BIT(EXTI->FTSR , EXTI_LINE); break ;
	case ON_CHANGE : SET_BIT(EXTI->RTSR , EXTI_LINE);
					 SET_BIT(EXTI->FTSR , EXTI_LINE); break ;
	default :        break ;             // error invalid EXTI Trigger
	}

	// configure SW trigger
	if (Local_u8SWTrigger == SW_TRIG_ENABLE)
	{
		SET_BIT(EXTI->SWIER , Local_u8EXTILine);
	}
	else
	{
		CLR_BIT(EXTI->SWIER , Local_u8EXTILine);
	}







}

/**--------------------------------------------------------------------------------------*/
/**
 *
 * @param Copy_u8Line
 */
void EXTI_voidEnableEXTI(u8 Copy_u8Line)
{
	SET_BIT(EXTI->IMR , Copy_u8Line);
}

/**--------------------------------------------------------------------------------------*/

/**
 *
 * @param Copy_u8Line
 */
void EXTI_voidDisableEXTI(u8 Copy_u8Line)
{
	CLR_BIT(EXTI->IMR , Copy_u8Line);
}

/**--------------------------------------------------------------------------------------*/

/**
 *
 * @param Copy_u8Line
 */
void EXTI_voidSwTrigger(u8 Copy_u8Line)
{
	SET_BIT(EXTI -> SWIER , Copy_u8Line);
}

/**--------------------------------------------------------------------------------------*/

/**
 *
 * @param Copy_u8Line
 * @param Copy_u8Mode
 */
void EXTI_voidSetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
		case RISING 	:	SET_BIT(EXTI->RTSR , Copy_u8Line); 	break;
		case FALLING	:	SET_BIT(EXTI->FTSR , Copy_u8Line); 	break;
		case ON_CHANGE 	:	SET_BIT(EXTI->RTSR , Copy_u8Line);
							SET_BIT(EXTI->FTSR , Copy_u8Line); 	break;
	}
}

/**--------------------------------------------------------------------------------------*/
