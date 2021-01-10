/*
 * Timer_config.h
 *
 *  Created on: Jan 10, 2021
 *      Author: Mohamed  Ebead
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_


// void Timer_voidGPIOInit(u8 Copy_u8TimerChannel ) parameters
#define TIMER2_CH1   1       // GPIOA
#define TIMER2_CH2   2       // GPIOA
#define TIMER2_CH3   3       // GPIOA
#define TIMER2_CH4   4       // GPIOA
#define TIMER3_CH1   5       // GPIOA
#define TIMER3_CH2   6       // GPIOA

#define TIMER3_CH3   7       // GPIOB
#define TIMER3_CH4   8       // GPIOB
#define TIMER4_CH1   9       // GPIOB
#define TIMER4_CH2   10      // GPIOB
#define TIMER4_CH3   11      // GPIOB
#define TIMER4_CH4   12      // GPIOB


#define TIMER_PWM_PULSE_FREQ         (u8)50              // 20000 µs = 20 ms

#define SYS_CLOCK                    (u32)8000000
#define TIMER_PWM_CK_CNT_REQ         (u32)1000000

/**
 * OPTIONS : TIMER_PWM_MODE_1
 *           TIMER_PWM_MODE_2
 *
 */
#define TIMER_PWM_MODE         TIMER_PWM_MODE_1




/**
 * OPTIONS : TIMER_PWM_PULSE_MIN
			 TIMER_PWM_PULSE_CENTER
T			 IMER_PWM_PULSE_MAX
 */
#define TIMER_PWM_DUTY_CYCLE         TIMER_PWM_PULSE_CENTER


/**
 * OPTIONS : TIMER_CHANNEL_CC1
 * 			 TIMER_CHANNEL_CC2
 *			 TIMER_CHANNEL_CC3
 *			 TIMER_CHANNEL_CC4
 *
 */
#define TIMER_PWM_CHANNEL          TIMER_CHANNEL_CC1



#endif /* TIMER_CONFIG_H_ */
