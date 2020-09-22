/*
 * main.c
 *
 *  Created on: Sep 15, 2020
 *      Author: Mohamed  Ebead
 */
#include<string.h>


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "SPI_interface.h"



int main (void)
{

	u8 user_data[] = "HELLO";
	u8 user_data2 = 'b';
	u8 data = 49 ;
	RCC_voidInitSysClock() ;

	SPI1_voidInit();

	while(1)
	{

	 	SPI_ControlPeripheral(SPI1 , ENABLE) ;
	  //to send data
		SPI_SendDataSynch(SPI1,&data,sizeof(data));


		//lets confirm SPI is not busy
		while( SPI_GetFlagStatus(SPI1,SPI_BUSY_FLAG) );

		SPI_ControlPeripheral(SPI1 , DISABLE) ;

		  //SPI_ReceiveDataSynch(SPI1,&data,sizeof(data));


	}




	return 0 ;
}








