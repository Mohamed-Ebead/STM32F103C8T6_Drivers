/*
 * SPI_interface.h
 *
 *  Created on: Sep 18, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


#include "SPI_private.h"






/*
 *  Configuration structure for SPIx peripheral
 */
typedef struct
{
	u8 SPI_DeviceMode  ;   //  @SPI_DeviceMode
	u8 SPI_BusConfig   ;   //  @SPI_BusConfig
	u8 SPI_SclkSpeed   ;   //  @SPI_SclkSpeed
	u8 SPI_DFF         ;   //  @SPI_DFF          Data Frame Format
	u8 SPI_CPOL        ;   //  @CPOL
	u8 SPI_CPHASE      ;   //  @CPHASE
	u8 SPI_SSM         ;   //  @SPI_SSM
	u8 SPI_SSI         ;   //  @SPI_SSI

}SPI_Config_t;


/*
 *Handle structure for SPIx peripheral
 */
typedef struct
{
	SPI_RegDef_t 	*pSPIx;   /*!< This holds the base address of SPIx(x:0,1,2) peripheral >*/
	SPI_Config_t 	SPIConfig;
	u8		        *pTxBuffer; /* !< To store the app. Tx buffer address > */
	u8		        *pRxBuffer;	/* !< To store the app. Rx buffer address > */
	u8 		        TxLen;		/* !< To store Tx len > */
	u8 		        RxLen;		/* !< To store Tx len > */
	u8		        TxState;	/* !< To store Tx state > */
	u8		        RxState;	/* !< To store Rx state > */

}SPI_Handle_t;


/**-----------------------------------------------------------------------------------------------------**/

/*
 * @SPI_DeviceMode
 */
#define SPI_DEVICE_MODE_MASTER    1
#define SPI_DEVICE_MODE_SLAVE     0


/*
 * @SPI_BusConfig
 */
#define SPI_BUS_CONFIG_FULLDUPLEX             1
#define SPI_BUS_CONFIG_HALFDUPLEX             2
#define SPI_BUS_CONFIG_SIMPLEX_RXONLY         3

/*
 * @SPI_SclkSpeed
 */
#define SPI_SCLK_SPEED_DIV2              0
#define SPI_SCLK_SPEED_DIV4              1
#define SPI_SCLK_SPEED_DIV8              2
#define SPI_SCLK_SPEED_DIV16             3
#define SPI_SCLK_SPEED_DIV32             4
#define SPI_SCLK_SPEED_DIV64             5
#define SPI_SCLK_SPEED_DIV128            6
#define SPI_SCLK_SPEED_DIV256            7

/*
 * @SPI_DFF
 */
#define SPI_DFF_8BITS 	0
#define SPI_DFF_16BITS  1

/*
 * @CPOL
 */
#define SPI_CPOL_HIGH 1
#define SPI_CPOL_LOW 0

/*
 * @CPHASE
 */
#define SPI_CPHA_HIGH 1
#define SPI_CPHA_LOW 0

/*
 * @SPI_SSM
 */
#define SPI_SSM_EN     1
#define SPI_SSM_DI     0

/*
 * @SPI_SSI
 */
#define SPI_SSI_EN     1
#define SPI_SSI_DI     0

/**-----------------------------------------------------------------------------------------------------**/

/******************************************************************************************
 *								APIs supported by this driver
 *		 For more information about the APIs check the function definitions
 ******************************************************************************************/
/*
 * Peripheral Clock setup
 */
void SPI_PeriClockControl (SPI_RegDef_t *pSPIx, u8 EnorDi);

/*
 * Init and De-init
 */

void SPI1_voidInit (void) ;
void SPI2_voidInit (void) ;
void SPI1_voidInitGPIO (void) ;
void SPI2_voidInitGPIO (void) ;

void SPI_Init   (SPI_Handle_t *pSPIHandle);
void SPI_DeInit (SPI_RegDef_t *pSPIx);



/*
 *    Get flag status
 *    @FlagName
 */
u8 SPI_GetFlagStatus(SPI_RegDef_t *pSPIx , u32 FlagName) ;

/*
 * Data Send and Receive
 */
void SPI_SendDataSynch    (SPI_RegDef_t *pSPIx,u8 *pTxBuffer, u32 Copy_u32NumberOfDataBytes);

void SPI_ReceiveDataSynch (SPI_RegDef_t *pSPIx,u8 *pRxBuffer, u32 Copy_u32NumberOfDataBytes);















#endif /* SPI_INTERFACE_H_ */




