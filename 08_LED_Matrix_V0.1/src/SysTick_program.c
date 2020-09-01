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
	STK -> LOAD = Copy_u32Ticks ;

	/* Start Timer */
	SET_BIT(STK->CTRL, 0);

	/* Wait till flag is raised */
	while( !(GET_BIT(STK->CTRL,16)) ) ;


	/* Stop Timer */
	CLR_BIT(STK->CTRL, 0);
	STK -> LOAD = 0;
	STK -> VAL  = 0;

}
/**----------------------------------------------------------------------------------------------*/



