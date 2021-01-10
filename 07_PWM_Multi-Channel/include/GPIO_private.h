/*
 * GPIO_private.h
 *
 *  Created on: Aug 16, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_



/********************************** START:Processor Specific Details ********************************/


/*
 * AHBx and APBx Bus Peripheral base addresses
 */

#define PERIPH_BASEADDR 			     0x40000000U
#define APB1PERIPH_BASEADDR			     PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR			     0x40010000U
#define AHBPERIPH_BASEADDR			     0x40018000U


#define GPIOA_BASEADDR                   (APB2PERIPH_BASEADDR + 0x0800)
#define GPIOB_BASEADDR                   (APB2PERIPH_BASEADDR + 0x0C00)
#define GPIOC_BASEADDR 					 (APB2PERIPH_BASEADDR + 0x1000)

















#endif /* GPIO_PRIVATE_H_ */
