/*
 * RTOS_program.c
 *
 *  Created on: Aug 26, 2020
 *      Author: Mohamed  Ebead
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RTOS_interface.h"
#include "RTOS_config.h"
#include "RTOS_private.h"

#include "SysTick_interface.h"


// make an array of structures to hold your tasks data

Task_TCB Tasks[RTO_MAX_NB_OF_TASKS] ;
/**----------------------------------------------------------------------------------------------------*/
/**
 *
 */
void RTOS_Init(void)
{
	STK_SetCallBack(&RTO_vid_StartSchedular) ;
}

/**----------------------------------------------------------------------------------------------------*/
/**
 *
 * @param copy_u8Priority
 * @param copy_u16Priodicity
 * @param copy_u16FirstDelay
 * @param copy_pFn
 */
void RTOS_vid_CreateTask (u8 copy_u8Priority ,u16 copy_u16Priodicity ,u16 copy_u16FirstDelay ,void (*copy_pFn)(void) )
{
	// use priority as an index
		Tasks[copy_u8Priority].u16_Periocicity = copy_u16Priodicity ;
		Tasks[copy_u8Priority].u16_FirstDelay = copy_u16FirstDelay ;
		Tasks[copy_u8Priority].pFn = copy_pFn ;
}

/**----------------------------------------------------------------------------------------------------*/
static void RTO_vid_StartSchedular (void)
{
	u8 u8_TCB_Counter =0;
	for (u8_TCB_Counter = 0 ;u8_TCB_Counter<RTO_MAX_NB_OF_TASKS ; u8_TCB_Counter ++ )
	{
		if ( (Tasks[u8_TCB_Counter].u16_FirstDelay)== 0)
		{
			// Run Task
			Tasks[u8_TCB_Counter].pFn() ;

			// FirstDelay = Periocicity
			// periodicity determines how many steps until next call
			Tasks[u8_TCB_Counter].u16_FirstDelay = ( Tasks[u8_TCB_Counter].u16_Periocicity ) -1 ;


		}
		else
		{
			( Tasks[u8_TCB_Counter].u16_FirstDelay ) -- ;

		}

	}


}

