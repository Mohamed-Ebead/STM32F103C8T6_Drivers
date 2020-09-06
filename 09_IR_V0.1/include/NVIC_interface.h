/*
 *
 *  Created on: Sep 6, 2020
 *      Author: Mohamed  Ebead
 */


#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


void NVIC_voidInit                (void);
void NVIC_voidEnableInterrupt     (u8 Copy_u8IntNumber);
void NVIC_voidDisableInterrupt    (u8 Copy_u8IntNumber);
void NVIC_voidSetPendingFlag      (u8 Copy_u8IntNumber);
void NVIC_voidClearPendingFlag    (u8 Copy_u8IntNumber);
u8	 NVIC_u8GetActiveFlag         (u8 Copy_u8IntNumber);
void NVIC_voidSetPriority         (u8 Copy_PeripheralIdx, u8 Copy_u8Priority);


#endif



