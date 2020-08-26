/*
 * EXTI_private.h
 *
 *  Created on: Aug 23, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_



typedef struct{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;

}EXTI_RegDef_t;


#define EXTI ((volatile EXTI_RegDef_t *) 0x40010400 )





#endif /* EXTI_PRIVATE_H_ */



