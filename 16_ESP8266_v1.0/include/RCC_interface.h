/*
 *
 *  Created on: Sep 6, 2020
 *      Author: Mohamed  Ebead
 */


#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


#define RCC_AHB     0
#define RCC_APB1    1
#define RCC_APB2    2

#define RCC_SPI1   12                  //RCC_APB2ENR
#define RCC_SPI2   14                  //RCC_APB1ENR
#define RCC_SPI3   15                  //RCC_APB1ENR

#define RCC_AFIO    0                  //RCC_APB2ENR
#define RCC_PORTA   2
#define RCC_PORTB   3
#define RCC_PORTC   4

#define RCC_USART1  14          // APB2
#define RCC_USART2  17          // APB1
#define RCC_USART3  18          // APB1
#define RCC_UART4   19          // APB1
#define RCC_UART5   20          // APB1


void RCC_voidInitSysClock(void);


void RCC_voidEnableClock  (u8 Copy_u8BusID , u8 Copy_u8PeriphID ) ;
void RCC_voidDisableClock (u8 Copy_u8BusID , u8 Copy_u8PeriphID ) ;



#endif




