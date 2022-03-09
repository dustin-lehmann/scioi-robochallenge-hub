/*
 * write_messages.h
 *
 *  Created on: 13 Feb 2022
 *      Author: Dustin Lehmann
 */

#ifndef COMMUNICATION_WRITE_MESSAGES_H_
#define COMMUNICATION_WRITE_MESSAGES_H_

#include "led.h"
#include "ws2812.h"

#define MSG_WRITE_DISCRETE_LED_ID 0x01
#define MSG_WRITE_DISCRETE_LED_LENGTH 3
void msg_write_discrete_led(uint8_t* msg, uint16_t length);

#define MSG_WRITE_STATUS_LED_ID 0x02
#define MSG_WRITE_STATUS_LED_LENGTH 3
void msg_write_status_led(uint8_t* msg, uint16_t length);


#endif /* COMMUNICATION_WRITE_MESSAGES_H_ */
