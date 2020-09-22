/*
 * TFT_private.h
 *
 *  Created on: Sep 22, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef TFT_PRIVATE_H_
#define TFT_PRIVATE_H_



static void TFT_voidWriteCommand(u8 Copy_u8Command);
static void TFT_voidWriteData   (u8 Copy_u8Data);


#define TFT_COMMAND_SLPOUT      0x11     // sleep out
#define TFT_COMMAND_COLMOD      0x3A     // color mode
#define TFT_COMMAND_DISPON      0x29     // display on
#define TFT_COMMAND_CASET       0x2A     // column address set
#define TFT_COMMAND_RASET       0x2B     // row address set
#define TFT_COMMAND_RAMWR       0x2C     // ram write



#endif /* TFT_PRIVATE_H_ */
