/*
 * ADC_private.h
 *
 *  Created on: Aug 21, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_



#define ADC1_BASEADDR 		(0x40012400)
#define ADC2_BASEADDR 		(0x40012800)
#define ADC3_BASEADDR		(0x40013C00)

#define CR2_ADON_BIT        0
#define CR2_CONT_BIT        1
#define CR2_CAL_BIT         2
#define CR2_RSTCAL_BIT      3
#define CR2_ALIGN_BIT       11

#define SR_EOC_BIT          1
#define SR_STRT_BIT         4

#endif /* ADC_PRIVATE_H_ */
