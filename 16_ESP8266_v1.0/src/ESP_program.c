/*
 *
 *  Created on: Oct 1, 2020
 *      Author: Mohamed  Ebead
 */



#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include<string.h>
#include<stdio.h>

#include "USART_interface.h"

#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"

/**
 * char type is used with strcpy and strcat call to avoid warning
 * warning "passing-argument-1-of-strlen-differ-in-signedness "
 * unsigned char  and signed char  causes this warning
 *
 */

/**------------------------------------------------------------------------------------------------------------------*/

extern char Quotes	[]	;
extern char Comma 	[]	;
extern char Closing []	;

extern u8 Local_u8Response[100]  ;

/**------------------------------------------------------------------------------------------------------------------*/
/**
 * @fun    ESP_voidInit
 * @brief  this function initializes ESP8266 as a wifi module
 */
void ESP_voidInit(void)
{
	u8 Local_u8ValidFlag = 0;

	while(Local_u8ValidFlag == 0)
	{
		/*Stop Echo*/
		USART1_voidTransmit(CMD_SWITCH_ECHO_OFF);
		/*	Check command is done right
			ATE0 returns OK if all is okay*/
		Local_u8ValidFlag = u8ValidateCmd(ECHO_TIMEOUT);
	}
	
	Local_u8ValidFlag = 0;
	
	while(Local_u8ValidFlag == 0)
	{
		/*Set ESP station mode*/
		USART1_voidTransmit(CMD_STATION_MODE);
		/*	Check command is done right
			AT+CWMODE=1 returns OK if all is okay*/
		Local_u8ValidFlag = u8ValidateCmd(MODE_TIMEOUT);
	}
}

/**------------------------------------------------------------------------------------------------------------------*/
/**
 * @fun   ESP_voidConnctToRouter
 * @brief this function connects the ESP8566 to the WIFI
 * @param pu8WIFIName
 * @param pu8WIFIPass
 */
void ESP_voidConnctToRouter(char *pu8WIFIName, char* pu8WIFIPass)
{
	u8 Local_u8ValidFlag = 0;
	char Local_u8Router_Command[50];
	
	/* Empty the pointer that strcat was using last time as it saves at the same location and data may interference*/
	strcpy(Local_u8Router_Command, "");

	/*catenating strings to be : "AT+CWJAP_CUR="Copy_u8StrSsid","Copy_u8StrPassword""*/
	strcat(Local_u8Router_Command, CMD_CONNECT_TO_AP);
	strcat(Local_u8Router_Command, Quotes);

	strcat(Local_u8Router_Command, pu8WIFIName);
	strcat(Local_u8Router_Command, Quotes);
	
	strcat(Local_u8Router_Command, Comma);
	
	strcat(Local_u8Router_Command, Quotes);
	strcat(Local_u8Router_Command, pu8WIFIPass);
	strcat(Local_u8Router_Command, Quotes);
	
	strcat(Local_u8Router_Command, Closing);
	
	while(Local_u8ValidFlag == 0)
	{
		/*Connect to WiFi of name Copy_u8StrSsid and password Copy_u8StrPassword*/
		USART1_voidTransmit(Local_u8Router_Command);
		/*	Check command is done right
			AT+CWJAP_CUR="SSID","Pass" returns OK if all is okay*/
		Local_u8ValidFlag = u8ValidateCmd(ROUTER_TIMEOUT);
	}
}

/**------------------------------------------------------------------------------------------------------------------*/
/**
 * @fun   ESP_voidConnectToServer
 * @brief this function connects the ESP8566 to your server
 * @param pu8Mode
 * @param pu8IP
 * @param pu8Port
 */
void ESP_voidConnectToServer(char* pu8Mode, char* pu8IP, char* pu8Port)
{
	u8 Local_u8ValidFlag = 0;
	char Local_u8Server_Command[42];

	/* Empty the pointer that strcat was using last time as it saves at the same location and data may interference*/
	strcpy(Local_u8Server_Command, "");

	/*catenating strings to be : "AT+CIPSTART="Copy_u8StrMode","Copy_u8StrIP",Copy_u8StrPort"
	 	 Example "AT+CIPSTART="TCP","162.253.155.227",80"    */
	strcat(Local_u8Server_Command, CMD_ESTABLISH_TCP_CONNECTION );
	
	strcat(Local_u8Server_Command, Quotes);
	strcat(Local_u8Server_Command, pu8Mode);
	strcat(Local_u8Server_Command, Quotes);
	
	strcat(Local_u8Server_Command, Comma);
	
	strcat(Local_u8Server_Command, Quotes);
	strcat(Local_u8Server_Command, pu8IP);
	strcat(Local_u8Server_Command, Quotes);
	
	strcat(Local_u8Server_Command, Comma);
	
	strcat(Local_u8Server_Command, pu8Port);
	
	strcat(Local_u8Server_Command, Closing);
	
	while(Local_u8ValidFlag == 0)
	{
		/*	Connect to Server of IP Copy_u8StrIP with Copy_u8StrMode protocol
			Either TCP or UDP and on Port Copy_u8StrPort*/
		USART1_voidTransmit(Local_u8Server_Command);
		/*	Check command is done right
			AT+CIPSTART="MODE","IP",PORT returns OK if all is okay*/
		Local_u8ValidFlag = u8ValidateCmd(SERVER_TIMEOUT);
	}
}

/**------------------------------------------------------------------------------------------------------------------*/
/**
 * @fun   ESP_u8ExecuteRequest
 * @brief this function requests a data from the server which the ESP8266 is connected to
 * @param pu8Request
 * @return
 */
u8 ESP_u8ExecuteRequest(char* pu8Request)
{
	u8   Local_u8ValidFlag = 0;
	u8   Local_u8Temp_char = 0 ;
	char   Local_u8Send_Command[14];
	char   Local_u8Request_Command[(strlen(pu8Request) + 5)];
	char   Local_u8Temp_str[2];


	/* Empty the pointer that strcat was using last time as it saves at the same location and data may interference*/
	strcpy(Local_u8Send_Command, CMD_SEND_DATA);

	/* calculate request length and add 2 for \r\n */
//	u8 Local_u8NumberOfLetters = strlen(pu8Request) + 2;
	/*Convert the number of the request letters to String*/
	sprintf(Local_u8Temp_str, "%i", ( strlen(pu8Request) + 5 ));
	
	strcat(Local_u8Send_Command, Local_u8Temp_str);
	
	strcat(Local_u8Send_Command, Closing);
	
	while(Local_u8ValidFlag == 0)
	{
		/*	Send number of letter from the coming request*/
		USART1_voidTransmit(Local_u8Send_Command);
		/*	Check command is done right
			AT+CIPSEND=NUMBER returns OK if all is okay*/
		Local_u8ValidFlag = u8ValidateCmd(PREREQUEST_TIMEOUT);
	}
	
	Local_u8ValidFlag = 0;
	strcpy(Local_u8Request_Command, "");
	strcat(Local_u8Request_Command, pu8Request);
	strcat(Local_u8Request_Command, Closing);
	
	while(Local_u8ValidFlag == 0)
	{
		/*	Send number of letter from the coming request*/
		USART1_voidTransmit(Local_u8Request_Command);
		/*	Check command is done right
			AT+CIPSEND=NUMBER returns OK if all is okay*/
		Local_u8ValidFlag = u8ValidateCmd(REQUEST_TIMEOUT);
	}
	
	/* When we receive data from server it would be in the form +IPD,NUMBER_OF_LETTERS_RECIEVED;DATA*/
	for(u8 i = 0; i < 98; i++)
	{
		/*Checking that the data recieved have IPD*/
		if(Local_u8Response[i] == 'I' && Local_u8Response[i+1] == 'P' && Local_u8Response[i+2] == 'D')
		{
			/*Return data in the 6th postion after the I*/
			Local_u8Temp_char = Local_u8Response[i+6];
		}
	}

	return Local_u8Temp_char ;
}

/**------------------------------------------------------------------------------------------------------------------*/
/**
 * @fun   u8ValidateCmd
 * @brief this function waits to receive "OK" from the server to validate last command sent to the server
 * @param Copy_u32timeout
 * @return
 */
static u8 u8ValidateCmd(u32 Copy_u32timeout)
{
	u8 Local_u8ValidFlag = 0;
	u8 Local_u8Counter   = 0;
	u8 Local_u8TempChar  = 0;

	for(u8 i = 0; i < 100; i++)
	{
		Local_u8Response[i] = 0;
	}

	/*Make sure that the MC is not receiving any more data from the ESP*/
	while (Local_u8TempChar != 255)
	{
		Local_u8TempChar = USART1_u8Receive(Copy_u32timeout);
		Local_u8Response[Local_u8Counter] = Local_u8TempChar;
		Local_u8Counter++;
	}

	/*	Deleting last element as it is always 255 for stop receiving data	*/
	Local_u8Response[Local_u8Counter-1] = 0;

	/*Strcmp returns 0 if the two strings are iqentical*/
	//Local_u8ValidFlag = strcmp(Copy_u8StrCmd, Local_u8Response);

	/* Checks if any of the received data contains the word "OK" meaning the command is done successfully*/
	for(u8 i = 0; i < Local_u8Counter - 2; i ++)
	{
		if(Local_u8Response[i] == 'O' && Local_u8Response[i+1] == 'K')
		{
			Local_u8ValidFlag = 1;
		}
	}
	return Local_u8ValidFlag;
}

/**------------------------------------------------------------------------------------------------------------------*/

