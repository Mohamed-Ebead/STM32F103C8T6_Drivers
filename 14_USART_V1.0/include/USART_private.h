/*
 * USART_private.h
 *
 *  Created on: Sep 19, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_


#define USART1_BASE_ADDRESS   0x40013800   // APB2
#define USART2_BASE_ADDRESS   0x40004400   // APB1
#define USART3_BASE_ADDRESS   0x40004800   // APB1
#define UART4_BASE_ADDRESS    0x40004C00   // APB1
#define UART5_BASE_ADDRESS    0x40005000   // APB1



/*
 * peripheral register definition structure for USART
 */
typedef struct
{
	volatile u32 SR;         /*!< ,     										Address offset: 0x00 */
	volatile u32 DR;         /*!< ,     										Address offset: 0x04 */
	volatile u32 BRR;        /*!< ,     										Address offset: 0x08 */
	volatile u32 CR1;        /*!< ,     										Address offset: 0x0C */
	volatile u32 CR2;        /*!< ,     										Address offset: 0x10 */
	volatile u32 CR3;        /*!< ,     										Address offset: 0x14 */
	volatile u32 GTPR;       /*!< ,     										Address offset: 0x18 */

} USART_RegDef_t;


#define USART1  			((USART_RegDef_t*)USART1_BASE_ADDRESS)
#define USART2  			((USART_RegDef_t*)USART2_BASE_ADDRESS)
#define USART3  			((USART_RegDef_t*)USART3_BASE_ADDRESS)
#define UART4  				((USART_RegDef_t*)UART4_BASE_ADDRESS)
#define UART5  				((USART_RegDef_t*)UART5_BASE_ADDRESS)



#define ENABLE 				1
#define DISABLE 			0

/******************************************************************************************
 *Bit position definitions of USART peripheral
 ******************************************************************************************/

/*
 * Bit position definitions USART_CR1
 */
#define USART_CR1_SBK					0
#define USART_CR1_RWU 					1
#define USART_CR1_RE  					2
#define USART_CR1_TE 					3
#define USART_CR1_IDLEIE 				4
#define USART_CR1_RXNEIE  				5
#define USART_CR1_TCIE					6
#define USART_CR1_TXEIE					7
#define USART_CR1_PEIE 					8
#define USART_CR1_PS 					9
#define USART_CR1_PCE 					10
#define USART_CR1_WAKE  				11
#define USART_CR1_M 					12
#define USART_CR1_UE 					13
#define USART_CR1_OVER8  				15



/*
 * Bit position definitions USART_CR2
 */
#define USART_CR2_ADD   				0
#define USART_CR2_LBDL   				5
#define USART_CR2_LBDIE  				6
#define USART_CR2_LBCL   				8
#define USART_CR2_CPHA   				9
#define USART_CR2_CPOL   				10
#define USART_CR2_STOP   				12
#define USART_CR2_LINEN   				14


/*
 * Bit position definitions USART_CR3
 */
#define USART_CR3_EIE   				0
#define USART_CR3_IREN   				1
#define USART_CR3_IRLP  				2
#define USART_CR3_HDSEL   				3
#define USART_CR3_NACK   				4
#define USART_CR3_SCEN   				5
#define USART_CR3_DMAR  				6
#define USART_CR3_DMAT   				7
#define USART_CR3_RTSE   				8
#define USART_CR3_CTSE   				9
#define USART_CR3_CTSIE   				10
#define USART_CR3_ONEBIT   				11

/*
 * Bit position definitions USART_SR
 */

#define USART_SR_PE        				0
#define USART_SR_FE        				1
#define USART_SR_NE        				2
#define USART_SR_ORE       				3
#define USART_SR_IDLE       			4
#define USART_SR_RXNE        			5
#define USART_SR_TC        				6
#define USART_SR_TXE        			7
#define USART_SR_LBD        			8
#define USART_SR_CTS        			9







#endif /* USART_PRIVATE_H_ */








