/*
 * GPIO_program.c
 *
 *  Created on: Aug 13, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

/***********************************************************************************************/
/**
 * @fun   : GPIO_VidSetPinDirection
 * @brief : this function sets the direction of a PIN ( input/output ) and their modes
 * @param : Copy_u8Port
 * @param : Copy_u8Pin
 * @param : u8Copy_u8Mode
 */
void GPIO_VidSetPinDirection  ( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Mode  )
{
	switch(Copy_u8Port){
		case GPIOA:

			if(Copy_u8Pin <= 7 ){//low

				GPIOA_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ));// R M W
				GPIOA_CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 );

			}else if(Copy_u8Pin <=15 ){//high

				Copy_u8Pin = Copy_u8Pin - 8;
				GPIOA_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
				GPIOA_CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 );
			}

			break;

		case GPIOB:

			if(Copy_u8Pin <= 7 ){//low

				GPIOB_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );// R M W
				GPIOB_CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;

			}else if(Copy_u8Pin <=15 ){//high

				Copy_u8Pin = Copy_u8Pin - 8;
				GPIOB_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
				GPIOB_CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
			}

			break;
		case GPIOC:

			if(Copy_u8Pin <= 7 ){//low

				GPIOC_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );// R M W
				GPIOC_CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;

			}else if(Copy_u8Pin <=15 ){//high

				Copy_u8Pin = Copy_u8Pin - 8;
				GPIOC_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
				GPIOC_CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
			}

			break;
		default :break;
		}

}

/***********************************************************************************************/
/**
 * @fun   : GPIO_VidSetPinValue
 * @brief : this function sets the value of a PIN ( 0/1 )
 * @param : Copy_u8Port
 * @param : Copy_u8Pin
 * @param : u8Copy_u8Value
 */
void GPIO_VidSetPinValue      ( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Value )
{
	switch(Copy_u8Port){
		case GPIOA:

			if( u8Copy_u8Value == HIGH ){

				SET_BIT( GPIOA_ODR , Copy_u8Pin );

			}else if( u8Copy_u8Value == LOW ){
				CLR_BIT(  GPIOA_ODR , Copy_u8Pin );
			}

			break;
		case GPIOB:

			if( u8Copy_u8Value == HIGH ){

				SET_BIT( GPIOB_ODR  , Copy_u8Pin );

			}else if( u8Copy_u8Value == LOW ){
				CLR_BIT( GPIOB_ODR  , Copy_u8Pin );
			}

			break;
		case GPIOC:

			if( u8Copy_u8Value == HIGH ){

				SET_BIT( GPIOC_ODR , Copy_u8Pin );

			}else if( u8Copy_u8Value == LOW ){
				CLR_BIT( GPIOC_ODR , Copy_u8Pin );
			}

			break;

		}

}

/***********************************************************************************************/
/**
 * @fun    : GPIO_u8GetPinValue
 * @brief  : this function gets the value of the input pin
 * @param  : Copy_u8Port
 * @param  : Copy_u8Pin
 * @return : pin value 0 or 1
 */
u8   GPIO_u8GetPinValue       ( u8 Copy_u8Port , u8 Copy_u8Pin                     )
{
	u8 LOC_u8PinValue = 0 ;

		switch(Copy_u8Port){
		case GPIOA:
			LOC_u8PinValue = GET_BIT( GPIOA_IDR , Copy_u8Pin );

			break;
		case GPIOB:

			LOC_u8PinValue = GET_BIT( GPIOB_IDR , Copy_u8Pin );

			break;
		case GPIOC:

			LOC_u8PinValue = GET_BIT( GPIOC_IDR , Copy_u8Pin );

			break;

		}

		return LOC_u8PinValue;


}

/***********************************************************************************************/
/**
 * @fun   : GPIO_VidSetPortDirection
 * @brief : this functios sets the direction of the entire port
 * @param : Copy_u8Port
 * @param : u8Copy_u8Mode
 * @note  : use this function if aand if only all pins of this port have the same mode
 */
void GPIO_VidSetPortDirection  ( u8 Copy_u8Port , u32 u32Copy_u32PortMode  )
{
	switch(Copy_u8Port){
	case GPIOA:
		GPIOA_CRL = u32Copy_u32PortMode ;
		GPIOA_CRH = u32Copy_u32PortMode ;
		break;

	case GPIOB:
		GPIOB_CRL = u32Copy_u32PortMode ;
		GPIOB_CRH = u32Copy_u32PortMode ;
		break;
	case GPIOC:
		GPIOC_CRL = u32Copy_u32PortMode ;
		GPIOC_CRH = u32Copy_u32PortMode ;
		break;


	default :break;
	}


}

/***********************************************************************************************/
/**
 * @fun   : GPIO_VidSetPortValue
 * @brief : this function sets an output port value (u32)
 * @param : Copy_u8Port
 * @param : u8Copy_u8Value
 */
void GPIO_VidSetPortValue      ( u8 Copy_u8Port , u32 u32Copy_u8Value )
{
	switch (Copy_u8Port)
	{
		case GPIOA : GPIOA_ODR =  u32Copy_u8Value ; break ;
		case GPIOB : GPIOB_ODR =  u32Copy_u8Value ; break ;
		case GPIOC : GPIOC_ODR =  u32Copy_u8Value ; break ;

	}

}

/***********************************************************************************************/
/**
 * @fun    : GPIO_u32GetPortValue
 * @brief  : this function gets the value of an entire input port
 * @param  : Copy_u8Port
 * @return : entire input port value (u32)
 */
u32  GPIO_u32GetPortValue      ( u8 Copy_u8Port )
{
	u32 LOC_u32PortValue = 0 ;

	switch (Copy_u8Port)
	{
		case GPIOA : LOC_u32PortValue = GPIOA_IDR ; break ;
		case GPIOB : LOC_u32PortValue = GPIOB_IDR ; break ;
		case GPIOC : LOC_u32PortValue = GPIOC_IDR ; break ;
		default    : break ;

	}

	return LOC_u32PortValue ;
}

/***********************************************************************************************/


