/*
 * AFIO_private.h
 *
 *  Created on: Aug 24, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef AFIO_PRIVATE_H_
#define AFIO_PRIVATE_H_



typedef struct{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];
	volatile u32 MAPR2;

}AFIO_RegDef_t;


#define AFIO ((volatile AFIO_RegDef_t *) 0x40010000 )


#endif /* AFIO_PRIVATE_H_ */
