/*
 * STP_program.c
 *
 *  Created on: Sep 15, 2020
 *      Author: Mohamed  Ebead
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "STP_interface.h"
#include "STP_config.h"
#include "STP_private.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"




/**------------------------------------------------------------------------------------------------*/
/**
 * @fun     STP1_voidInit
 * @brief   this function initializes Serial To Parallel IC connected GPIO PINs
 *
 */
/***************************************************************************************************/
void STP1_voidInit (void)
{
	GPIO_Handle_t STP1_DS ;
	STP1_DS.pGPIOx = STP1_DS_PORT ;
	STP1_DS.GPIO_PinConfig.GPIO_PinNumber = STP1_DS_PIN ;
	STP1_DS.GPIO_PinConfig.GPIO_PinMode   = OUTPUT_10MHZ_PP ;
	GPIO_vidInit(&STP1_DS);

	GPIO_Handle_t STP1_STCP ;
	STP1_STCP.pGPIOx = STP1_STCP_PORT ;
	STP1_STCP.GPIO_PinConfig.GPIO_PinNumber = STP1_STCP_PIN ;
	STP1_STCP.GPIO_PinConfig.GPIO_PinMode   = OUTPUT_10MHZ_PP ;
	GPIO_vidInit(&STP1_STCP);

	GPIO_Handle_t STP1_SHCP ;
	STP1_SHCP.pGPIOx = STP1_SHCP_PORT ;
	STP1_SHCP.GPIO_PinConfig.GPIO_PinNumber = STP1_SHCP_PIN ;
	STP1_SHCP.GPIO_PinConfig.GPIO_PinMode   = OUTPUT_10MHZ_PP ;
	GPIO_vidInit(&STP1_SHCP);



}
/**------------------------------------------------------------------------------------------------*/
/**
 * @fun   STP1_voidSendSynchronous
 * @brief this function sends a serial Byte of data through a GPIO PIN to be converted to parallel
 * @param Copy_u8Data
 */
/***************************************************************************************************/
void STP1_voidSendSynchronous (u8 Copy_u8Data)
{
	s8 Local_s8Counter = 0 ;
	u8 Local_u8Bit = 0 ;

	for (Local_s8Counter = 7 ; Local_s8Counter >=0 ; Local_s8Counter --)
	{
		Local_u8Bit = GET_BIT(Copy_u8Data , Local_s8Counter) ;
		GPIO_WriteToOutputPin(STP1_DS_PORT,STP1_DS_PIN,Local_u8Bit) ;

		STP1_voidSendPulseToShiftClock() ;
	}

	STP1_voidSendPulseToStoreClock();

}
/**------------------------------------------------------------------------------------------------*/
/**
 *@fun   STP1_voidSendPulseToShiftClock
 *@brief this function sends a pulse to shift clock
 */
/***************************************************************************************************/

static void STP1_voidSendPulseToShiftClock (void)
{
	GPIO_WriteToOutputPin(STP1_SHCP_PORT,STP1_SHCP_PIN,GPIO_PIN_SET) ;
	asm ("NOP") ;	asm ("NOP") ;    // for Pulse Settling


	GPIO_WriteToOutputPin(STP1_SHCP_PORT,STP1_SHCP_PIN,GPIO_PIN_RESET) ;
	asm ("NOP") ;	asm ("NOP") ;    // for Pulse Settling
}
/**------------------------------------------------------------------------------------------------*/
/**------------------------------------------------------------------------------------------------*/
/**
 *@fun   STP1_voidSendPulseToStoreClock
 *@brief this function sends a pulse to Store clock
 */
/***************************************************************************************************/
static void STP1_voidSendPulseToStoreClock (void)
{
	GPIO_WriteToOutputPin(STP1_STCP_PORT,STP1_STCP_PIN,GPIO_PIN_SET) ;
	asm ("NOP") ;	asm ("NOP") ;     // for Pulse Settling


	GPIO_WriteToOutputPin(STP1_STCP_PORT,STP1_STCP_PIN,GPIO_PIN_RESET) ;
	asm ("NOP") ;	asm ("NOP") ;     // for Pulse Settling

}
/**------------------------------------------------------------------------------------------------*/


/***************************************************************************************************/


/**------------------------------------------------------------------------------------------------*/
/**
 * @fun     STP2_voidInit
 * @brief   this function initializes Serial To Parallel IC connected GPIO PINs
 *
 */
/***************************************************************************************************/
void STP2_voidInit (void)
{
	GPIO_Handle_t STP2_DS ;
	STP2_DS.pGPIOx = STP2_DS_PORT ;
	STP2_DS.GPIO_PinConfig.GPIO_PinNumber = STP2_DS_PIN ;
	STP2_DS.GPIO_PinConfig.GPIO_PinMode   = OUTPUT_10MHZ_PP ;
	GPIO_vidInit(&STP2_DS);

	GPIO_Handle_t STP2_STCP ;
	STP2_STCP.pGPIOx = STP2_STCP_PORT ;
	STP2_STCP.GPIO_PinConfig.GPIO_PinNumber = STP2_STCP_PIN ;
	STP2_STCP.GPIO_PinConfig.GPIO_PinMode   = OUTPUT_10MHZ_PP ;
	GPIO_vidInit(&STP2_STCP);

	GPIO_Handle_t STP2_SHCP ;
	STP2_SHCP.pGPIOx = STP1_SHCP_PORT ;
	STP2_SHCP.GPIO_PinConfig.GPIO_PinNumber = STP2_SHCP_PIN ;
	STP2_SHCP.GPIO_PinConfig.GPIO_PinMode   = OUTPUT_10MHZ_PP ;
	GPIO_vidInit(&STP2_SHCP);



}
/**------------------------------------------------------------------------------------------------*/
/**
 * @fun   STP2_voidSendSynchronous
 * @brief this function sends a serial Byte of data through a GPIO PIN to be converted to parallel
 * @param Copy_u8Data
 */
/***************************************************************************************************/
void STP2_voidSendSynchronous (u8 Copy_u8Data)
{
	s8 Local_s8Counter = 0 ;
	u8 Local_u8Bit = 0 ;

	for (Local_s8Counter = 7 ; Local_s8Counter >=0 ; Local_s8Counter --)
	{
		Local_u8Bit = GET_BIT(Copy_u8Data , Local_s8Counter) ;
		GPIO_WriteToOutputPin(STP2_DS_PORT,STP2_DS_PIN,Local_u8Bit) ;

		STP2_voidSendPulseToShiftClock() ;
	}

	STP2_voidSendPulseToStoreClock();

}
/**------------------------------------------------------------------------------------------------*/
/**
 *@fun   STP2_voidSendPulseToShiftClock
 *@brief this function sends a pulse to shift clock
 */
/***************************************************************************************************/
static void STP2_voidSendPulseToShiftClock (void)
{
	GPIO_WriteToOutputPin(STP2_SHCP_PORT,STP2_SHCP_PIN,GPIO_PIN_SET) ;
	asm ("NOP") ;	asm ("NOP") ;


	GPIO_WriteToOutputPin(STP2_SHCP_PORT,STP2_SHCP_PIN,GPIO_PIN_RESET) ;
	asm ("NOP") ;	asm ("NOP") ;
}
/**------------------------------------------------------------------------------------------------*/
/**
 *@fun   STP2_voidSendPulseToStoreClock
 *@brief this function sends a pulse to Store clock
 */
/***************************************************************************************************/
static void STP2_voidSendPulseToStoreClock (void)
{
	GPIO_WriteToOutputPin(STP2_STCP_PORT,STP2_STCP_PIN,GPIO_PIN_SET) ;
	asm ("NOP") ;	asm ("NOP") ;	// for Pulse Settling


	GPIO_WriteToOutputPin(STP2_STCP_PORT,STP2_STCP_PIN,GPIO_PIN_RESET) ;
	asm ("NOP") ;	asm ("NOP") ;	// for Pulse Settling

}
/**------------------------------------------------------------------------------------------------*/







