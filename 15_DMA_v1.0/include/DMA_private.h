/*
 * DMA_private.h
 *
 *  Created on: Sep 23, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_



#define DMA1_BASEADDRESS  0x40020000
#define DMA2_BASEADDRESS  0x40020400

typedef struct
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 Reserved;

}DMA_Channel_t;



typedef struct
{
	volatile u32  ISR;
	volatile u32  IFCR;
	DMA_Channel_t Channel[7];

}DMA_RegDef_t;


/**
 * Bit Position of CCR register
 */

#define DMA_CCR_EN        0
#define DMA_CCR_TCIE      1
#define DMA_CCR_HTIE      2
#define DMA_CCR_TEIE      3
#define DMA_CCR_DIR       4
#define DMA_CCR_CIRC      5
#define DMA_CCR_PINC      6
#define DMA_CCR_MINC      7
#define DMA_CCR_PSIZE0    8
#define DMA_CCR_PSIZE1    9
#define DMA_CCR_MSIZE0    10
#define DMA_CCR_MSIZE1    11
#define DMA_CCR_PL0       12
#define DMA_CCR_PL1       13
#define DMA_CCR_MEM2MEM   14







#endif /* DMA_PRIVATE_H_ */
