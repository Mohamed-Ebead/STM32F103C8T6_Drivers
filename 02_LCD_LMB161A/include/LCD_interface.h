/*
 * LCD_interface.h
 *
 *  Created on: Aug 20, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


/****************************************************************/

void LCD_Delay (void) ;

/****************************************************************/

void LCD_vidWriteCommand (u8 u8CmdCpy) ;

/****************************************************************/

void LCD_vidInitialize(void);

/****************************************************************/

void LCD_vidWriteCharacter(u8 u8DataCpy) ;

/****************************************************************/

void LCD_vidWriteString (u8* pu8StringCpy, u8 u8Index) ;

/****************************************************************/

void LCD_vidClear(void) ;

/****************************************************************/

void LCD_vidGotoxy (u8 X,u8 Y);

/****************************************************************/

void LCD_vidSeparateResult(u32 u32Result , u8 * u8ArrayResult) ;

/****************************************************************/

void LCD_vidWriteInteger(u16 val , u16 field_length) ;

/****************************************************************/



#endif /* LCD_INTERFACE_H_ */
