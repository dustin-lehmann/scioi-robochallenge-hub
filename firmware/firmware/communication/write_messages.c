/*
 * write_messages.c
 *
 *  Created on: 13 Feb 2022
 *      Author: Dustin Lehmann
 */

#include <stdint.h>
#include "write_messages.h"

void msg_write_discrete_led(uint8_t *msg, uint16_t length) {
	if (!(length == MSG_WRITE_DISCRETE_LED_LENGTH)) {
		return; //TODO ERROR HANDLING
	}
	if (msg[0] == 0 || msg[0] == 1) {
		set_led(LED_GREEN, msg[0]);
	}
	if (msg[1] == 0 || msg[1] == 1) {
		set_led(LED_BLUE, msg[1]);
	}
	if (msg[2] == 0 || msg[2] == 1) {
		set_led(LED_ORANGE, msg[2]);
	}

	if (msg[0] == 2) {
		toggle_led(LED_GREEN);
	}
	if (msg[1] == 2) {
		toggle_led(LED_BLUE);
	}
	if (msg[2] == 2) {
		toggle_led(LED_ORANGE);
	}
}


void msg_write_status_led(uint8_t* msg, uint16_t length){
	if (!(length == MSG_WRITE_STATUS_LED_LENGTH)) {
		return; //TODO ERROR HANDLING
	}
	ws2812_set(0, msg[0], msg[1], msg[2]);
	ws2812_send();
}

