/*
 *
 *  Created on: Sep 6, 2020
 *      Author: Mohamed  Ebead
 */


#ifndef EXTI0_PRIVATE_H
#define EXTI0_PRIVATE_H


typedef	struct
{
	volatile	u32		IMR;
	volatile	u32		EMR;
	volatile	u32		RTSR;
	volatile	u32		FTSR;
	volatile	u32		SWIER;
	volatile	u32		PR;
	
}EXTI_Type;

#define	EXTI		(( EXTI_Type * )0X40010400)



#endif
