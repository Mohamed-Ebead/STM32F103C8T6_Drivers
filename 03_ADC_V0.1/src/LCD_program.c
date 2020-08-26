/*
 * LCD_program.c
 *
 *  Created on: Aug 20, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LCD_interface.h"
#include "LCD_cofig.h"
#include "LCD_private.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"

/*********************************************************************************************************************/
/**
 *
 */
void LCD_Delay (void)
{
	for(u8 i = 0 ; i < 100 ; i++ )
	{
		for(u8 j = 0 ; j < 100 ; j++ )
		{
			asm("NOP");
		}
	}
}

/*********************************************************************************************************************/
/**
 *
 */
void LCD_vidInitialize(void)
{
	/*-------------------------- 	GPIO INITIALICATION   -------------------------- */
	if (LCD_OPERATING_MODE == LCD_8_BIT_INITIALIZATION)
	{
	/* Initialize the Data pins of the LCD */
	GPIO_Handle_t LCD_DataByte;
	LCD_DataByte.pGPIOx = LCD_DATA_PORT;
	LCD_DataByte.GPIO_ByteConfig.GPIO_ByteNumber  = LCD_DATA_BYTE ;
	LCD_DataByte.GPIO_ByteConfig.GPIO_ByteMode    = GPIO_BYTE_OUTPUT_10MHZ_PP ;

	GPIO_vidInitByte(&LCD_DataByte) ;
	}
	else if (LCD_OPERATING_MODE == LCD_4_BIT_INITIALIZATION)
	{
		GPIO_Handle_t LCD_DataNipple ;
		LCD_DataNipple.pGPIOx=LCD_DATA_PORT ;
		LCD_DataNipple.GPIO_NippleConfig.GPIO_NibbleNumber = LCD_CTRL_NIPPLE ;
		LCD_DataNipple.GPIO_NippleConfig.GPIO_NibbleMode = GPIO_NIBBLE_OUTPUT_10MHZ_PP ;

		GPIO_vidInitNibble(&LCD_DataNipple);
	}
	else
	{
		// error LCD configurations
	}


	GPIO_Handle_t LCD_RS ;
	LCD_RS.pGPIOx = LCD_CTRL_PORT ;
	LCD_RS.GPIO_PinConfig.GPIO_PinNumber = LCD_RS_PIN ;
	LCD_RS.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_PP ;
	GPIO_vidInit(&LCD_RS);



	GPIO_Handle_t LCD_EN ;
	LCD_EN.pGPIOx = LCD_CTRL_PORT ;
	LCD_EN.GPIO_PinConfig.GPIO_PinNumber = LCD_EN_PIN ;
	LCD_EN.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_PP ;
	GPIO_vidInit(&LCD_EN);
	/*
	 * GPIO_Handle_t LCD_RW ;
	LCD_RW.pGPIOx = LCD_CTRL_PORT ;
	LCD_RW.GPIO_PinConfig.GPIO_PinNumber = LCD_RW_PIN ;
	LCD_RW.GPIO_PinConfig.GPIO_PinMode = GPIO_BYTE_OUTPUT_10MHZ_PP ;
	GPIO_vidInit(&LCD_RW);
	*/


	/* Initialize the control Pins of the LCD  */
	/*GPIO_Handle_t LCD_ControlPins ;
	LCD_ControlPins.pGPIOx=LCD_CTRL_PORT ;
	LCD_ControlPins.GPIO_NippleConfig.GPIO_NibbleNumber = LCD_CTRL_NIPPLE ;
	LCD_ControlPins.GPIO_NippleConfig.GPIO_NibbleMode   = GPIO_NIBBLE_OUTPUT_10MHZ_PP ;

	GPIO_vidInitNibble(&LCD_ControlPins);*/


   /*------------------------------------------------------------------------------------*/

	// set VDD to 5 volt
	//GPIO_WriteToOutputPin(LCD_CTRL_PORT , LCD_VDD_PIN , GPIO_PIN_SET) ;
	//LCD_Delay() ;

	// FUNCTION SET
	LCD_vidWriteCommand (0b00111000);   //0X38  // N=0 1 line 0b00110000
	LCD_Delay() ;

	// DISPLAY ON/OFF CONTROL
	LCD_vidWriteCommand (0b00001111);
	LCD_Delay() ;

	// DISPLAY CLEAR
	LCD_vidWriteCommand (0b00000001);
	LCD_Delay() ;

	 // Entry mode set
	LCD_vidWriteCommand (0b00000110);   //0X06
	LCD_Delay() ;

}

/*********************************************************************************************************************/
/**
 *
 * @param Copy_u8Command
 */
void LCD_vidWriteCommand (u8 Copy_u8Command)
{
	// RESET RS
	GPIO_WriteToOutputPin(LCD_CTRL_PORT , LCD_RS_PIN , GPIO_PIN_RESET) ;

	// RESET R/W
	//GPIO_WriteToOutputPin(LCD_CTRL_PORT , LCD_RW_PIN , GPIO_PIN_RESET) ;

	// Set EN
	GPIO_WriteToOutputPin(LCD_CTRL_PORT , LCD_EN_PIN , GPIO_PIN_SET) ;

	// read data when E is high  , write data on falling edge
	GPIO_WriteToOutputByte(LCD_DATA_PORT , LCD_DATA_BYTE ,Copy_u8Command ) ;

	// set EN to 1 after settting command
	// pulse
	GPIO_WriteToOutputPin(LCD_CTRL_PORT , LCD_EN_PIN , GPIO_PIN_RESET) ;
	LCD_Delay() ;
	GPIO_WriteToOutputPin(LCD_CTRL_PORT , LCD_EN_PIN , GPIO_PIN_SET) ;

	LCD_Delay() ;
}

/*********************************************************************************************************************/
/**
 *
 * @param u8DataCpy
 */
void LCD_vidWriteCharacter(u8 Copy_u8Data)
{
	 // Set RS
	GPIO_WriteToOutputPin(LCD_CTRL_PORT , LCD_RS_PIN , GPIO_PIN_SET) ;

	// RESET R/W
	//GPIO_WriteToOutputPin(LCD_CTRL_PORT , LCD_RW_PIN , GPIO_PIN_RESET) ;

	// Set EN
	GPIO_WriteToOutputPin(LCD_CTRL_PORT , LCD_EN_PIN , GPIO_PIN_SET) ;

	// Load Command on Data bus
	GPIO_WriteToOutputByte(LCD_DATA_PORT , LCD_DATA_BYTE ,Copy_u8Data ) ;

	// RESET EN  ( write on falling edge)
	GPIO_WriteToOutputPin(LCD_CTRL_PORT , LCD_EN_PIN , GPIO_PIN_RESET) ;


	// Wait for E to settle
	LCD_Delay() ;

	// SET EN
	GPIO_WriteToOutputPin(LCD_CTRL_PORT , LCD_EN_PIN , GPIO_PIN_SET) ;

	// Delay to let the LCD Display the character
	LCD_Delay() ;
	LCD_Delay() ;

}

/*********************************************************************************************************************/
/**
 *
 * @param pu8StringCpy
 * @param u8Index
 */
void LCD_vidWriteString (u8* pu8StringCpy, u8 u8Index)
{
	// Local loop index

	u8 iteration=0;

	for (iteration=0; ((iteration<u8Index)&&(pu8StringCpy[iteration] != '\0')) ; iteration++)
	{
		/* Write Character on LCD */
		LCD_vidWriteCharacter(pu8StringCpy[iteration]);

		/* Delay to let the LCD show the character */
		LCD_Delay() ;
	}

}

/*********************************************************************************************************************/
/**
 *
 */
void LCD_vidClear(void)
{
	LCD_vidWriteCommand (0x01);		/* clear display */
	LCD_vidWriteCommand (0x02);		/* cursor at home position */

}

/*********************************************************************************************************************/
/**
 *
 * @param X
 * @param Y
 */
void LCD_vidGotoxy (u8 X,u8 Y)
{
	/*
	  2*16 LCD
			    {80 81 ... 8F}   0X80 = 128  :Force cursor to beginning of the first line
			    {C0 C1 ... CF}   0XC0 = 192  :Force cursor to beginning of the SECOND line

	*/
	if (X>0 && X<=16)           // x from 1 to 16 , y : 1 or 2
		{
			switch(Y)
			{
				case 1:
					LCD_vidWriteCommand(X+127);
				break;
				case 2:
					LCD_vidWriteCommand(X+191);
				break;
				default:
				break;
			}
		}

}

/*********************************************************************************************************************/
/**
 *
 * @param u32Result
 * @param u8ArrayResult
 */
void LCD_vidSeparateResult(u32 u32Result , u8 * u8ArrayResult)
{
	u8ArrayResult[0]= ( (u32Result / 10000) % 10 ) + 48 ;   //48 is the asci of 0
	u8ArrayResult[1]= ( (u32Result / 1000) % 10 ) + 48 ;
	u8ArrayResult[2]= ( (u32Result / 100) % 10 ) + 48 ;
	u8ArrayResult[3]= ( (u32Result / 10) % 10 ) + 48 ;
	u8ArrayResult[4]=   (u32Result  % 10 ) + 48 ;


}

/*********************************************************************************************************************/
/**
 *
 * @param val
 * @param field_length
 */
void LCD_vidWriteInteger(u16 val , u16 field_length)
{
/***************************************************************
	This function writes a integer type value to LCD module

	Arguments:
	1)int val	: Value to print

	2)unsigned int field_length :total length of field in which the value is printed
	must be between 1-5 if it is -1 the field length is no of digits in the val

****************************************************************/

	u16 str[5]={0,0,0,0,0};
	u16 i=4,j=0;

	//Handle negative integers
	if(val<0)
	{
		LCD_vidWriteCharacter('-');   //Write Negative sign
		val=val*(-1);     //convert to positive
	}
	else
	{
		LCD_vidWriteCharacter(' ');
	}

	while(val)
	{
		str[i]=val%10;
		val=val/10;
		i--;
	}

	if(field_length==-1)
		while(str[j]==0) j++;
	else
		j=5-field_length;

	for(i=j;i<5;i++)
	{
		LCD_vidWriteCharacter('0'+str[i]);
	}

}

/*********************************************************************************************************************/






