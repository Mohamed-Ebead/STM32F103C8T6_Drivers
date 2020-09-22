

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H



void SPI1_voidInit(void); /* Home Work */

void SPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_DataToReceive);

//void SPI1_voidSendReceiveAsynch(u8 Copy_u8DataToTransmit, void (*CallBack)(u8));

#endif
