/*
 *
 *  Created on: Oct 1, 2020
 *      Author: Mohamed  Ebead
 */



#ifndef ESP_CONFIG_H
#define ESP_CONFIG_H

/**-----------------------------------------------------------------------------------------------------------*/


#define MODE                 "TCP"
#define IP                   "162.253.155.227"
#define PORT                 "80"
#define REQUEST_LED_STATUS   "GET http://atom.orgfree.com/status.txt"

#define ROUTER_SSID          "atom"
#define ROUTER_PASSWORD      "55552222"



/**-----------------------------------------------------------------------------------------------------------*/



/*define recieving timout for each command that if it exceeded it means no more data*/
/*It varies depending on the router and server and also Clock freq, you'll need to try it*/
#define ECHO_TIMEOUT		100
#define MODE_TIMEOUT		150
#define ROUTER_TIMEOUT		1100000
#define SERVER_TIMEOUT		300000
#define PREREQUEST_TIMEOUT	200
#define REQUEST_TIMEOUT		900000

#endif
