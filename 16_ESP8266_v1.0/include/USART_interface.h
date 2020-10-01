/*
 *
 *  Created on: Oct 1, 2020
 *      Author: Mohamed  Ebead
 */



#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H



void USART1_voidInit(void);
void USART1_voidGPIOInit(void ) ;

void USART1_voidTransmit(char* word);

u8   USART1_u8Receive(u32 Copy_u32timeout);

#endif
