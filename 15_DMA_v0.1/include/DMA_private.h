/*
 * DMA_private.h
 *
 *  Created on: Sep 23, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_


typedef struct
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 Reserved;

}DMA_Channel;



typedef struct
{
	volatile u32 ISR;
	volatile u32 IFCR;
	DMA_Channel Channel[7];

}DMA_RegDef_t;


#define DMA1	(( DMA_RegDef_t*)0x40020000)



#endif /* DMA_PRIVATE_H_ */
