/*
 * request_messages.h
 *
 *  Created on: 13 Feb 2022
 *      Author: Dustin Lehmann
 */

#ifndef COMMUNICATION_REQUEST_MESSAGES_H_
#define COMMUNICATION_REQUEST_MESSAGES_H_

#include "messages.h"

#define MSG_REQUEST_ECHO_ID 0x01
#define MSG_REQUEST_ECHO_ANSWER_ID 0x01
void msg_request_echo(uint8_t* msg, uint16_t length);
void msg_request_echo_answer(uint8_t* msg, uint16_t length);



#endif /* COMMUNICATION_REQUEST_MESSAGES_H_ */
