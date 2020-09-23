/*
 * DMA_interface.h
 *
 *  Created on: Sep 23, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_



void DMA1_voidChannel1Init(void);
void DMA1_voidChannel1Start(u32* Copy_pu32SourceAddress, u32* Copy_pu32DestinationAddress, u16 Copy_u16BlockLength);

/*Clear Interrupt flag*/
#define DMA_CHANNEL_1      0
#define DMA_CHANNEL_2      1
#define DMA_CHANNEL_3      2
#define DMA_CHANNEL_4      3
#define DMA_CHANNEL_5      4
#define DMA_CHANNEL_6      5
#define DMA_CHANNEL_7      6


void DMA1_voidClearGlobalInterruptFlag           (u8 Copy_u8Channel) ;
void DMA1_voidClearTransferCompleteInterruptFlag (u8 Copy_u8Channel) ;


#endif /* DMA_INTERFACE_H_ */





