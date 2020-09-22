/*
 * SPI_private.h
 *
 *  Created on: Sep 18, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_





#define SPI1_BASEADDR       0x40013000
#define SPI2_BASEADDR       0x40003800
#define SPI3_BASEADDR 	    0x40003C00




typedef struct
{
	volatile u32 CR1      ;
	volatile u32 CR2      ;
	volatile u32 SR       ;
	volatile u32 DR       ;
	volatile u32 CRCPR    ;
	volatile u32 RXCRCR   ;
	volatile u32 TXCRCR   ;
	volatile u32 I2SCFGR  ;
	volatile u32 I2SPR    ;

}SPI_RegDef_t;



#define SPI1       ( (SPI_RegDef_t*)SPI1_BASEADDR )
#define SPI2       ( (SPI_RegDef_t*)SPI2_BASEADDR )
#define SPI3       ( (SPI_RegDef_t*)SPI3_BASEADDR )




#define ENABLE   1
#define DISABLE  0


/*
* Bit position definitions SPI_CR1
*/
#define SPI_CR1_CPHA     				 0
#define SPI_CR1_CPOL      				 1
#define SPI_CR1_MSTR     				 2
#define SPI_CR1_BR   					 3
#define SPI_CR1_SPE     				 6
#define SPI_CR1_LSBFIRST   			 	 7
#define SPI_CR1_SSI     				 8
#define SPI_CR1_SSM      				 9
#define SPI_CR1_RXONLY      		 	10
#define SPI_CR1_DFF     			 	11
#define SPI_CR1_CRCNEXT   			 	12
#define SPI_CR1_CRCEN   			 	13
#define SPI_CR1_BIDIOE     			 	14
#define SPI_CR1_BIDIMODE      			15

/*
* Bit position definitions SPI_CR2
*/
#define SPI_CR2_RXDMAEN		 			0
#define SPI_CR2_TXDMAEN				 	1
#define SPI_CR2_SSOE				 	2
#define SPI_CR2_ERRIE					5
#define SPI_CR2_RXNEIE				 	6
#define SPI_CR2_TXEIE					7

/*
 * Bit position definitions SPI_SR
 */
#define SPI_SR_RXNE						0
#define SPI_SR_TXE				 		1
#define SPI_SR_CHSIDE				 	2
#define SPI_SR_UDR					 	3
#define SPI_SR_CRCERR				 	4
#define SPI_SR_MODF					 	5
#define SPI_SR_OVR					 	6
#define SPI_SR_BSY					 	7


/*
 * SPI related status flags definitions  @FlagName
 */
#define SPI_TXE_FLAG    ( 1 << SPI_SR_TXE)
#define SPI_RXNE_FLAG   ( 1 << SPI_SR_RXNE)
#define SPI_BUSY_FLAG   ( 1 << SPI_SR_BSY)








#endif /* SPI_PRIVATE_H_ */
