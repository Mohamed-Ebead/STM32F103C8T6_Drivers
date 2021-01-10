/*
 * Timer_private.h
 *
 *  Created on: Jan 10, 2021
 *      Author: Mohamed  Ebead
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_







/**
 *   TIMERS HANGS ON APB1  BUS
 */
#define TIMER2_BASE_ADDRESS 	0x40000000
#define TIMER3_BASE_ADDRESS 	0x40000400
#define TIMER4_BASE_ADDRESS 	0x40000800
#define TIMER5_BASE_ADDRESS 	0x40000C00
#define TIMER6_BASE_ADDRESS 	0x40001000
#define TIMER7_BASE_ADDRESS 	0x40001400
#define TIMER12_BASE_ADDRESS 	0x40001800
#define TIMER13_BASE_ADDRESS 	0x40001C00
#define TIMER14_BASE_ADDRESS 	0x40002000


/**
 *   TIMERS HANGS ON APB2  BUS
 */
#define TIMER1_BASE_ADDRESS 	0x40012C00
#define TIMER8_BASE_ADDRESS 	0x40013400
#define TIMER9_BASE_ADDRESS 	0x40014C00
#define TIMER10_BASE_ADDRESS 	0x40015000
#define TIMER11_BASE_ADDRESS 	0x40015400


typedef struct
{
	volatile u32 CR1     ;
	volatile u32 CR2     ;
	volatile u32 SMCR    ;
	volatile u32 DIER    ;
	volatile u32 SR      ;
	volatile u32 EGR     ;
	volatile u32 CCMR1   ;
	volatile u32 CCMR2   ;
	volatile u32 CCER    ;
	volatile u32 CNT     ;
	volatile u32 PSC     ;
	volatile u32 ARR     ;
	volatile u32 RCR     ;
	volatile u32 CCR1    ;
	volatile u32 CCR2    ;
	volatile u32 CCR3    ;
	volatile u32 CCR4    ;
	volatile u32 BDTR    ;
	volatile u32 DCR     ;
	volatile u32 DMAR    ;

}Timer_RegDef_t;





/**
 * 	Register bits
 */
#define TIM_CR1_CKD        8    // 8 & 9
#define TIM_CR1_ARPE       7
#define TIM_CR1_CMS        5    // 5 & 6
#define TIM_CR1_DIR        4
#define TIM_CR1_OPM        3
#define TIM_CR1_URS        2
#define TIM_CR1_UDIS       1
#define TIM_CR1_CEN        0

#define TIM_CCMR1_OC1M     4
#define TIM_CCMR1_OC2M     12
#define TIM_CCMR2_OC3M     4
#define TIM_CCMR2_OC4M     12

#define TIM_CCMR1_OC1FE     2
#define TIM_CCMR1_OC1PE     3
#define TIM_CCMR1_OC2FE     10
#define TIM_CCMR1_OC2PE     11
#define TIM_CCMR2_OC3FE     2
#define TIM_CCMR2_OC3PE     3
#define TIM_CCMR2_OC4FE     10
#define TIM_CCMR2_OC4PE     11

#define TIM_CCER_CC1E       0
#define TIM_CCER_CC1P       1
#define TIM_CCER_CC2E       4
#define TIM_CCER_CC2P       5
#define TIM_CCER_CC3E       8
#define TIM_CCER_CC3P       9
#define TIM_CCER_CC4E       12
#define TIM_CCER_CC4P       13

#define TIMER_CHANNEL_CC1  1
#define TIMER_CHANNEL_CC2  2
#define TIMER_CHANNEL_CC3  3
#define TIMER_CHANNEL_CC4  4

#define TIMER_PWM_PULSE_MIN          (u16)480            // 1000  µs = 1 ms
#define TIMER_PWM_PULSE_CENTER       (u16)1340            // 1500  µs = 1.5 ms
#define TIMER_PWM_PULSE_MAX          (u16)2225            // 2000  µs = 2 ms


#define TIMER_PWM_MODE_1             0b110
#define TIMER_PWM_MODE_2             0b111


#define TIMER_NO_2     2
#define TIMER_NO_3     3
#define TIMER_NO_4     4

#define CHANNEL_NO_1   1
#define CHANNEL_NO_2   2
#define CHANNEL_NO_3   3
#define CHANNEL_NO_4   4



#endif /* TIMER_PRIVATE_H_ */










