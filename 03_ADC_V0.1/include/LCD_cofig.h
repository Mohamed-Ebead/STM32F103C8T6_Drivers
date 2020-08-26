/*
 * LCD_cofig.h
 *
 *  Created on: Aug 20, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef LCD_COFIG_H_
#define LCD_COFIG_H_


/**
 * LCD hardware connections
 * choose GPIO which is connected to your LCD pins control and data buffer pins
 * OPTIONS : GPIOA , GPIOB
 */
#define LCD_DATA_PORT	 GPIOB
#define LCD_CTRL_PORT 	 GPIOB

/**
 * choose the start pin of your data bus
 * OPTIONS : GPIO_LOWER_BYTE in  case GPIOA
 * 			 GPIO_HIGHER_BYTE in case GPIOB
 * 	then , connect the rest data bus after it ordered
 */
#define LCD_DATA_BYTE   GPIO_HIGHER_BYTE

/**
 * @CTRL_NIPPLE_NUMBER
 * choose the control nipple of the 4 control pins VDD,RS,R/W,EN
 *  if you changed the nipple you must change the control pins pin number @CTRL_PIN_NUMBERS
 *options :  GPIO_NIPPLE_1
			 GPIO_NIPPLE_2
			 GPIO_NIPPLE_3
			 GPIO_NIPPLE_4
 */
#define LCD_CTRL_NIPPLE 		GPIO_NIPPLE_2

/**
 * @CTRL_PIN_NUMBERS
 * change it only if you changed the nipple number @CTRL_NIPPLE_NUMBER
 * choose control pins pin number
 * OPTIONS : GPIO_PIN_NO_0 >> GPIO_PIN_NO_15
 */

#define LCD_RS_PIN 		     GPIO_PIN_NO_7
#define LCD_EN_PIN  	     GPIO_PIN_NO_6
//#define LCD_VDD_PIN 		 GPIO_PIN_NO_8       // always VCC 5v

//#define LCD_RW_PIN 		     GPIO_PIN_NO_10   // always Grounded



/**
 * choose LCD operating mode
 * OPTIONS :LCD_8_BIT_INITIALIZATION
 * 			LCD_4_BIT_INITIALIZATION
 */


#define LCD_OPERATING_MODE 		LCD_8_BIT_INITIALIZATION

// only in case of LCD_4_BIT_INITIALIZATION
#if LCD_OPERATING_MODE == LCD_4_BIT_INITIALIZATION
	#define LCD_DATA_NIPPLE 		GPIO_NIPPLE_0
#endif


#endif /* LCD_COFIG_H_ */



