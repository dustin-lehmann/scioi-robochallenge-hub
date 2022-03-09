/*
 * request_messages.c
 *
 *  Created on: 13 Feb 2022
 *      Author: Dustin Lehmann
 */

#include "request_messages.h"

void msg_request_echo(uint8_t *msg, uint16_t length) {
	msg_request_echo_answer(msg, length);
}
void msg_request_echo_answer(uint8_t *msg, uint16_t length) {
	send_msg(MSG_TYPE_RESPONSE, MSG_REQUEST_ECHO_ANSWER_ID, msg, length);
}
