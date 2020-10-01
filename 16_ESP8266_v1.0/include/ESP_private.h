/*
 *
 *  Created on: Oct 1, 2020
 *      Author: Mohamed  Ebead
 */



#ifndef ESP_PRIVATE_H
#define ESP_PRIVATE_H


char Quotes	[]	 = "\""		;
char Comma 	[]	 = {","}    ;
char Closing[]	 = "\r\n"	;

u8 Local_u8Response[100] ={0};

#define CMD_SWITCH_ECHO_OFF 			"ATE0\r\n"
#define CMD_STATION_MODE       		    "AT+CWMODE=1\r\n"
#define CMD_CONNECT_TO_AP     		    "AT+CWJAP_CUR="
#define CMD_ESTABLISH_TCP_CONNECTION    "AT+CIPSTART="
#define CMD_SEND_DATA                   "AT+CIPSEND="







static u8 u8ValidateCmd(u32 Copy_u32timeout) ;

#endif
