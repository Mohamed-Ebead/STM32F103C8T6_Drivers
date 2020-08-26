/*
 * EXTI_config.h
 *
 *  Created on: Aug 24, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_


/**
 * EXTI Line
 * Options : LINE_0 >> LINE_15
 */
#define EXTI_LINE	LINE_0


/**
 * Triggering selection of EXTI
 * options : RISING
 *		     FALLING
 *			 ON_CHANGE
 */
#define EXTI_TRIGGER	FALLING

/**
 * software  trigger
 * 	options : SW_TRIG_ENABLE
 * 			  SW_TRIG_DISABLE
 */
#define EXTI_SW_TRIGGER  SW_TRIG_DISABLE



#endif /* EXTI_CONFIG_H_ */
