/*
 *
 *  Created on: Oct 1, 2020
 *      Author: Mohamed  Ebead
 */



#ifndef INTERFACE_H
#define INTERFACE_H

void ESP_voidInit(void);
void ESP_voidConnctToRouter (char *pu8WIFIName, char* pu8WIFIPass) ;
void ESP_voidConnectToServer(char* pu8Mode, char* pu8IP, char* pu8Port) ;
u8 ESP_u8ExecuteRequest     (char* pu8Request) ;

#endif
