


#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


#define RCC_AHB     0
#define RCC_APB1    1
#define RCC_APB2    2

#define RCC_PORTA   2
#define RCC_PORTB   3
#define RCC_PORTC   4

#define RCC_DMA1    0   //RCC_AHB
#define RCC_DMA2    1   //RCC_AHB

void RCC_void_EnableClock  (u8 Copy_u8BusID , u8 Copy_u8PeriphID ) ;
void RCC_void_DisableClock (u8 Copy_u8BusID , u8 Copy_u8PeriphID ) ;

void RCC_voidInitSysClock(void);







#endif
