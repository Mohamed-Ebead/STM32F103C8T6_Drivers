/*
 * USART_interface.h
 *
 *  Created on: Sep 19, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#include "USART_private.h"




/*
 * Configuration structure for USARTx peripheral
 */
typedef struct
{
	u32 USART_Baud;
	u8 USART_Mode;
	u8 USART_NoOfStopBits;
	u8 USART_WordLength;
	u8 USART_ParityControl;
	u8 USART_HWFlowControl;

}USART_Config_t;


/*
 * Handle structure for USARTx peripheral
 */
typedef struct
{
	USART_RegDef_t  *pUSARTx;
	USART_Config_t   USART_Config;
	u8 *pTxBuffer;
	u8 *pRxBuffer;
	u8  TxBusyState;
	u8  RxBusyState;
	u32 TxLen;
	u32 RxLen;

}USART_Handle_t;



/*
 *@USART_Mode
 *Possible options for USART_Mode
 */
#define USART_MODE_ONLY_TX 	0
#define USART_MODE_ONLY_RX 	1
#define USART_MODE_TXRX  	2

/*
 *@USART_Baud
 *Possible options for USART_Baud
 */
#define USART_STD_BAUD_1200					1200
#define USART_STD_BAUD_2400					400
#define USART_STD_BAUD_9600					9600
#define USART_STD_BAUD_19200 				19200
#define USART_STD_BAUD_38400 				38400
#define USART_STD_BAUD_57600 				57600
#define USART_STD_BAUD_115200 				115200
#define USART_STD_BAUD_230400 				230400
#define USART_STD_BAUD_460800 				460800
#define USART_STD_BAUD_921600 				921600
#define USART_STD_BAUD_2M 					2000000
#define SUART_STD_BAUD_3M 					3000000


/*
 *@USART_ParityControl
 *Possible options for USART_ParityControl
 */
#define USART_PARITY_EN_ODD   2
#define USART_PARITY_EN_EVEN  1
#define USART_PARITY_DISABLE   0

/*
 *@USART_WordLength
 *Possible options for USART_WordLength
 */
#define USART_WORDLEN_8BITS  0
#define USART_WORDLEN_9BITS  1

/*
 *@USART_NoOfStopBits
 *Possible options for USART_NoOfStopBits
 */
#define USART_STOPBITS_1     0
#define USART_STOPBITS_0_5   1
#define USART_STOPBITS_2     2
#define USART_STOPBITS_1_5   3


/*
 *@USART_HWFlowControl
 *Possible options for USART_HWFlowControl
 */
#define USART_HW_FLOW_CTRL_NONE    	0
#define USART_HW_FLOW_CTRL_CTS    	1
#define USART_HW_FLOW_CTRL_RTS    	2
#define USART_HW_FLOW_CTRL_CTS_RTS	3


/*
 * USART flags
 */

#define USART_FLAG_TXE 			( 1 << USART_SR_TXE)
#define USART_FLAG_RXNE 		( 1 << USART_SR_RXNE)
#define USART_FLAG_TC 			( 1 << USART_SR_TC)

/*
 * Application states
 */
#define USART_BUSY_IN_RX 1
#define USART_BUSY_IN_TX 2
#define USART_READY 0


#define 	USART_EVENT_TX_CMPLT   0
#define		USART_EVENT_RX_CMPLT   1
#define		USART_EVENT_IDLE       2
#define		USART_EVENT_CTS        3
#define		USART_EVENT_PE         4
#define		USART_ERR_FE           5
#define		USART_ERR_NE    	   6
#define		USART_ERR_ORE    	   7

/******************************************************************************************
 *								APIs supported by this driver
 *		 For more information about the APIs check the function definitions
 ******************************************************************************************/




void USART1_voidInit(void) ;
void USART1_voidGPIOInit(void) ;





/*
 * Peripheral Clock setup
 */
void USART_PeriClockControl(USART_RegDef_t *pUSARTx, u8 EnOrDi);

/*
 * Init and De-init
 */
void USART_Init  (USART_Handle_t *pUSARTHandle);
void USART_DeInit(USART_Handle_t *pUSARTHandle);

/*
 * Data Send and Receive
 */
void  USART_SendData   (USART_Handle_t *pUSARTHandle, u8 *pTxBuffer, u32 Len);
void  USART_ReceiveData(USART_Handle_t *pUSARTHandle, u8 *pRxBuffer, u32 Len);

void USART_PeripheralControl(USART_RegDef_t *pUSARTx, u8 EnOrDi) ;

/*
 * Other Peripheral Control APIs
 */

u8   USART_GetFlagStatus(USART_RegDef_t *pUSARTx, u8 StatusFlagName);
void USART_ClearFlag(USART_RegDef_t *pUSARTx, u16 StatusFlagName);
void USART_SetBaudRate(USART_RegDef_t *pUSARTx, u32 BaudRate);


/*
 * Application Callbacks
 */
void USART_ApplicationEventCallback(USART_Handle_t *pUSARTHandle,u8 ApEv);




#endif /* USART_INTERFACE_H_ */
