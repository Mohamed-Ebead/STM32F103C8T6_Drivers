/*
 * DMA_interface.h
 *
 *  Created on: Sep 23, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_



#include "DMA_private.h"

#define DMA1	(( DMA_RegDef_t*)DMA1_BASEADDRESS)
#define DMA2	(( DMA_RegDef_t*)DMA2_BASEADDRESS)



typedef struct
{
	u8 Channel ;    		               // @DMA_CHANNEL_NUMBER
	u8 Mem2Mem ;   		 	               // @MEM2MEM_CONTROL
	u8 PriorityLevel ; 		               // @PRIORITY_LEVEL
	u8 MemorySize ;                        // @MEMORY_SIZE
	u8 PeripheralSize ;                    // @PERIPHERAL_SIZE
	u8 MemoryIncrementMode ;               // @MEMORY_INCREMENT_MODE
	u8 PeripheralIncrementMode ;           // @PERIPHERAL_INCREMENT_MODE
	u8 CircularMode ; 			           // @CIRCULAR_MODE
	u8 DataTransferDirection  ;            // @DATA_TRANSFER_DIRECTION
	u8 TransferErrorInterrupt ;			   // @TRANSFER_ERROR_INTERRUPT
	u8 HalfTransferErrorInterrupt ;        // @HALF_TRANSFER_ERROR_INTERRUPT
	u8 TransferCompleteInterrupt  ;        // @TRANSFER_COMPLETE_INTERRUPT

}DMA_Config_t;



typedef struct
{

	DMA_RegDef_t *pDMA ;
	DMA_Config_t  DMA_Config ;

	u32 *SourceAddress      ;
	u32 *DestinationAddress ;
	u16  BlockLength ;


}DMA_Handle_t;


/**
 *  @DMA_CHANNEL_NUMBER
 */
#define DMA_CHANNEL_1      0
#define DMA_CHANNEL_2      1
#define DMA_CHANNEL_3      2
#define DMA_CHANNEL_4      3
#define DMA_CHANNEL_5      4
#define DMA_CHANNEL_6      5
#define DMA_CHANNEL_7      6

/**
 * @MEM2MEM_CONTROL
 */
#define DMAMEM2MEM_ENABLE   1
#define DMAMEM2MEM_DISABLE  0

/**
 * // @PRIORITY_LEVEL
 */
#define DMA_PL_LOW       	0
#define DMA_PL_MEDIUM    	1
#define DMA_PL_HIGH       	2
#define DMA_PL_VERYHIGH     3

/**
 *   @MEMORY_SIZE
 */
#define DMA_MEMORY_SIZE_8_BITS    0
#define DMA_MEMORY_SIZE_16_BITS   1
#define DMA_MEMORY_SIZE_32_BITS   2

/**
 *   @PERIPHERAL_SIZE
 */
#define DMA_PERIPHERAL_SIZE_8_BITS    0b00
#define DMA_PERIPHERAL_SIZE_16_BITS   0b01
#define DMA_PERIPHERAL_SIZE_32_BITS   0b10

/**
 * @MEMORY_INCREMENT_MODE
 *
 */
#define DMA_MEMORY_INCREMENT_MODE_ENABLE   	1
#define DMA_MEMORY_INCREMENT_MODE_DISABLE  	0
/**
 * @PERIPHERAL_INCREMENT_MODE
 *
 */
#define DMA_PERIPHERAL_INCREMENT_MODE_ENABLE   1
#define DMA_PERIPHERAL_INCREMENT_MODE_DISABLE  0

/**
 * @CIRCULAR_MODE
 *
 */
#define DMA_CIRCULAR_MODE_ENABLE   1
#define DMA_CIRCULAR_MODE_DISABLE  0

/**
 * @DATA_TRANSFER_DIRECTION
 */
#define DMA_DIR_READ_FROM_PERIPHERAL   0
#define DMA_DIR_READ_FROM_MEMORY       1

/**
 * @TRANSFER_ERROR_INTERRUPT
 *
 */
#define DMA_TEI_ENABLE   1
#define DMA_TEI_DISABLE  0


/**
 * @HALF_TRANSFER_ERROR_INTERRUPT
 *
 */
#define DMA_HTEI_ENABLE   1
#define DMA_HTEI_DISABLE  0

/**
 * @TRANSFER_COMPLETE_INTERRUPT
 *
 */
#define DMA_TCI_ENABLE   1
#define DMA_TCI_DISABLE  0



void DMA_PeriphControlClock (DMA_RegDef_t *pDMA , u8 EnOrDis);
void DMA1_voidInitChannel1 (void);
void DMA_voidInit          (DMA_Handle_t * pDMA_Handle) ;

void DMA_voidStart( DMA_RegDef_t *pDMA , u8 Copy_u8Channel) ;

/*Clear Interrupt flag*/


void DMA1_voidClearGlobalInterruptFlag           (u8 Copy_u8Channel) ;
void DMA1_voidClearTransferCompleteInterruptFlag (u8 Copy_u8Channel) ;



#define ENABLE   1
#define DISABLE  0






#endif /* DMA_INTERFACE_H_ */





