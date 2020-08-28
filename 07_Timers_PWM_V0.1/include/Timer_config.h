/*
 * Timer_config.h
 *
 *  Created on: Aug 27, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_



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
