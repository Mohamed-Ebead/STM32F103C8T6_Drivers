/*
 *
 *  Created on: Sep 6, 2020
 *      Author: Mohamed  Ebead
 */


#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


#define NVIC_DMA1_CHANNEL1     11
#define NVIC_DMA1_CHANNEL2     12
#define NVIC_DMA1_CHANNEL3     13
#define NVIC_DMA1_CHANNEL4     14
#define NVIC_DMA1_CHANNEL5     15
#define NVIC_DMA1_CHANNEL6     16
#define NVIC_DMA1_CHANNEL7     17

#define NVIC_DMA2_CHANNEL1     56
#define NVIC_DMA2_CHANNEL2     57
#define NVIC_DMA2_CHANNEL3     58
#define NVIC_DMA2_CHANNEL4     59
#define NVIC_DMA2_CHANNEL5     60



void NVIC_voidInit                (void);
void NVIC_voidEnableInterrupt     (u8 Copy_u8IntNumber);
void NVIC_voidDisableInterrupt    (u8 Copy_u8IntNumber);
void NVIC_voidSetPendingFlag      (u8 Copy_u8IntNumber);
void NVIC_voidClearPendingFlag    (u8 Copy_u8IntNumber);
u8	 NVIC_u8GetActiveFlag         (u8 Copy_u8IntNumber);
void NVIC_voidSetPriority         (u8 Copy_PeripheralIdx, u8 Copy_u8Priority);


#endif



