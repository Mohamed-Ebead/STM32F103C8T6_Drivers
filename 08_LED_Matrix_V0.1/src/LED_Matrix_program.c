/*
 * LED_Matrix_program.c
 *
 *  Created on: Aug 31, 2020
 *      Author: Mohamed  Ebead
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED_Matrix_interface.h"
#include "LED_Matrix_private.h"
#include "LED_Matrix_config.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"

#include "SysTick_interface.h"




extern u8 MyName1 [] ;
extern u8 MyName2 [] ;
extern u8 MyName3 [] ;
extern u8 MyName4 [] ;

/**-------------------------------------------------------------------------------------------------------------*/
/**
 * @fun    LEDMATREX_voidInit
 * @brief  this function initializes the GPIO connected to the LED Matrix
 *
 */
void LEDMATREX_voidInit (void)
{
	// Columns control , LSB at top
	/** GPIO INITIALIZATION **/
	GPIO_Handle_t LEDMATREX_ROWs ;
	LEDMATREX_ROWs.pGPIOx = GPIOA ;
	LEDMATREX_ROWs.GPIO_ByteConfig.GPIO_ByteNumber = LEDMATREX_ROWS ;
	LEDMATREX_ROWs.GPIO_ByteConfig.GPIO_ByteMode   = GPIO_BYTE_OUTPUT_2MHZ_PP ;
	GPIO_vidInitByte(&LEDMATREX_ROWs) ;

	GPIO_Handle_t LEDMATREX_COLs ;
	LEDMATREX_COLs.pGPIOx = GPIOB ;
	LEDMATREX_COLs.GPIO_ByteConfig.GPIO_ByteNumber = LEDMATREX_COLUMNS ;
	LEDMATREX_COLs.GPIO_ByteConfig.GPIO_ByteMode   = GPIO_BYTE_OUTPUT_2MHZ_PP ;
	GPIO_vidInitByte(&LEDMATREX_COLs) ;

}
/**-------------------------------------------------------------------------------------------------------------*/
/**
 * @fun   LEDMATREX_voidSetRowValue
 * @brief this function sets the row value
 * @param Copy_u8Value
 */

 static void LEDMATREX_voidSetRowValue ( u8 Copy_u8Value )
{

	GPIO_WriteToOutputByte(GPIOA , LEDMATREX_ROWS ,Copy_u8Value ) ;

}
/**-------------------------------------------------------------------------------------------------------------*/
/**
 * @fun   LEDMATREX_voidDisableAllColumns
 * @brief this function Disables All columns
 */
static void LEDMATREX_voidDisableAllColumns (void)
{

	GPIO_WriteToOutputByte(GPIOB , LEDMATREX_COLUMNS , 0XFF ) ;
}

/**-------------------------------------------------------------------------------------------------------------*/
/**
 * @fun    LEDMATREX_voidDisplayLetter
 * @brief  this function displays a letter ( an array of characters )
 * @param  Copy_u8Data
 */
void LEDMATREX_voidDisplayLetter ( u8 *Copy_u8Data )
{

	u8 Array_Looper = 0 ;

	for ( Array_Looper = 0 ;Array_Looper<8 ; Array_Looper ++ )
	{

	    LEDMATREX_voidDisableAllColumns();

	    LEDMATREX_voidSetRowValue (Copy_u8Data[Array_Looper]) ;
	    GPIO_WriteToOutputPin(GPIOB , (Array_Looper+8),  GPIO_PIN_RESET ) ;

	    STK_voidSetBusyWait(2500) ;

	}

}

/**-------------------------------------------------------------------------------------------------------------*/
/**
 * @fun    LEDMATREX_voidDisplayMyName
 * @brief  this function is a special function that display a name converted to an array
 * 		   this array is shifted 3 time so that we have 4 arrays to hold the shifting name
 */
void LEDMATREX_voidDisplayMyName   ( void )
{
	/**
	 * we need to display one element of each array for a while
	 * as I wrote my name in 4 arrays , and I want to display it on 20 changes ,
	 * then we have to loop 5 times on the 4 arrays
	 *
	 * if you want to make the display
	 */
	u8 Local_u8NameLoop ;  // 5 loops * 3 arrays = 20 change for one name display
	u8 Local_u8Wait ;     // wait to see each letter

	for ( Local_u8NameLoop = 0 ; Local_u8NameLoop <5 ; Local_u8NameLoop ++ )
	{
		for ( Local_u8Wait = 0 ; Local_u8Wait<30 ; Local_u8Wait++ )
		{
			LEDMATREX_voidDisplayLetter( (8*Local_u8NameLoop) + MyName1   );
		}
		for ( Local_u8Wait = 0 ; Local_u8Wait<30 ; Local_u8Wait++ )
		{
			LEDMATREX_voidDisplayLetter( (8*Local_u8NameLoop) + MyName2   );
		}
		for ( Local_u8Wait = 0 ; Local_u8Wait<30 ; Local_u8Wait++ )
		{
			LEDMATREX_voidDisplayLetter( (8*Local_u8NameLoop) + MyName3   );
		}
		for ( Local_u8Wait = 0 ; Local_u8Wait<30 ; Local_u8Wait++ )
		{
			LEDMATREX_voidDisplayLetter( (8*Local_u8NameLoop) + MyName4   );
		}

	}


}

/**-------------------------------------------------------------------------------------------------------------*/














