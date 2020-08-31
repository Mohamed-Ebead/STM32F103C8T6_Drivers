/*
 * RCC_program.c
 *
 *  Created on: Aug 31, 2020
 *      Author: Mohamed  Ebead
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SysTick_interface.h"
#include "SysTick_private.h"
#include "SysTick_config.h"


/* Define Callback Global Variable */
static void(*STK_CallBack)(void);

/* Define Variable for interval mode */
static u8 STK_u8ModeOfInterval;

/**----------------------------------------------------------------------------------------------*/
/**
 *
 */
void STK_voidInit(void)
{
#if STK_CLK_SRC == MSTK_SRC_AHB
    /* Disable STK - Disable STK Interrupt - Set clock source AHB */
	STK -> CTRL = 0x00000004;
#else
    /* Disable STK - Disable STK Interrupt - Set clock source AHB/8 */
	STK -> CTRL = 0;

#endif
}

/**----------------------------------------------------------------------------------------------*/
/**
 *
 * @param Copy_u32Ticks
 */
void STK_voidSetBusyWait( u32 Copy_u32Ticks )
{
	/* Load ticks to load register */
	STK -> LOAD = Copy_u32Ticks;

	/* Start Timer */
	SET_BIT(STK->CTRL, 0);

	/* Wait till flag is raised */
	while( (GET_BIT(STK->CTRL,16)) == 0);

	/* Stop Timer */
	SET_BIT(STK->CTRL, 0);
	STK -> LOAD = 0;
	STK -> VAL  = 0;

}

/**----------------------------------------------------------------------------------------------*/
/**
 *
 * @param Copy_u32Ticks
 * @param Copy_ptr
 */
void STK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* Load ticks to load register */
	STK -> LOAD = Copy_u32Ticks;

	/* Start Timer */
	SET_BIT(STK->CTRL, 0);

	/* Save CallBack */
	STK_CallBack = Copy_ptr;

	/* Set Mode to Single */
	STK_u8ModeOfInterval = STK_SINGLE_INTERVAL;

	/* Enable STK Interrupt */
	SET_BIT(STK->CTRL, 1);
}

/**----------------------------------------------------------------------------------------------*/
/**
 *
 * @param Copy_u32Ticks
 * @param Copy_ptr
 */
void STK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* Load ticks to load register */
	STK -> LOAD = Copy_u32Ticks;

	/* Start Timer */
	SET_BIT(STK->CTRL, 0);

	/* Save CallBack */
	STK_CallBack = Copy_ptr;

	/* Set Mode to Single */
	STK_u8ModeOfInterval = STK_PERIOD_INTERVAL;

	/* Enable STK Interrupt */
	SET_BIT(STK->CTRL, 1);
}

/**----------------------------------------------------------------------------------------------*/
/**
 *
 */
void STK_voidStopInterval(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(STK->CTRL, 1);

	/* Stop Timer */
	SET_BIT(STK->CTRL, 0);
	STK -> LOAD = 0;
	STK -> VAL  = 0;
}

/**----------------------------------------------------------------------------------------------*/
/**
 *
 * @return
 */
u32  STK_u32GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime;

	Local_u32ElapsedTime = STK -> LOAD - STK -> VAL ;

	return Local_u32ElapsedTime;
}

/**----------------------------------------------------------------------------------------------*/
/**
 *
 * @return
 */
u32  STK_u32GetRemainingTime(void)
{
	u32 Local_u32RemainTime;

	Local_u32RemainTime = STK -> VAL ;

	return Local_u32RemainTime;
}

/**----------------------------------------------------------------------------------------------*/
/**
 *
 */
void SysTick_Handler(void)
{
	u8 Local_u8Temporary ;

	if (STK_u8ModeOfInterval == STK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(STK->CTRL, 1);

		/* Stop Timer */
		SET_BIT(STK->CTRL, 0);
		STK -> LOAD = 0;
		STK -> VAL  = 0;
	}

	/* Callback notification */
	STK_CallBack();

	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(STK->CTRL,16);
}

/**----------------------------------------------------------------------------------------------*/



