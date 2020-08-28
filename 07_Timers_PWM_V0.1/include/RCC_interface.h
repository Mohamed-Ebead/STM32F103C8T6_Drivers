


#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


#define RCC_AHB     0
#define RCC_APB1    1
#define RCC_APB2    2

#define RCC_PORTA   2
#define RCC_PORTB   3
#define RCC_PORTC   4

#define RCC_ADC_BUS     RCC_APB2
#define RCC_ADC1        9
#define RCC_ADC2        10
#define RCC_ADC3        15


#define RCC_APB2_TIMER1       11
#define RCC_APB1_TIMER2       0
#define RCC_APB1_TIMER3       1
#define RCC_APB1_TIMER4       2
#define RCC_APB1_TIMER5       3
#define RCC_APB1_TIMER6       4
#define RCC_APB1_TIMER7       5
#define RCC_APB2_TIMER8       13
#define RCC_APB2_TIMER9       19
#define RCC_APB2_TIMER10      20
#define RCC_APB2_TIMER11      21
#define RCC_APB1_TIMER12      6
#define RCC_APB1_TIMER13      7
#define RCC_APB1_TIMER14      8



void RCC_void_EnableClock  (u8 Copy_u8BusID , u8 Copy_u8PeriphID ) ;
void RCC_void_DisableClock (u8 Copy_u8BusID , u8 Copy_u8PeriphID ) ;

void RCC_voidInitSysClock(void);







#endif
