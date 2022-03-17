/*
 * messages.c
 *
 *  Created on: 1 Feb 2022
 *      Author: lehmann_workstation
 */

#include "messages.h"
uint8_t msg_in_buf[128];
uint8_t msg_out_buf[128];

void msg_handler(uint8_t type, uint8_t id, uint8_t *msg, uint16_t length) {
	switch (type) {
	case MSG_TYPE_WRITE: {
		switch (id) {
		case MSG_WRITE_DISCRETE_LED_ID: {
			msg_write_discrete_led(msg, length);
			break;
		}
		case MSG_WRITE_STATUS_LED_ID:
			msg_write_status_led(msg, length);
			break;
		}
		break;
	}
	case MSG_TYPE_REQUEST: {
		case MSG_REQUEST_ECHO_ID:
		msg_request_echo(msg, length);
		break;
	}
	}
}

void send_msg(uint8_t type, uint8_t id, uint8_t *data, uint16_t length) {
	usb_tx_buf[0] = HEADER_0;
	usb_tx_buf[1] = HEADER_1;
	usb_tx_buf[2] = type;
	usb_tx_buf[3] = id;
	usb_tx_buf[4] = length;
	if (MSG_CRC8_ENABLE) {

	} else {
		usb_tx_buf[5] = 0x00; //CRC8
	}
	memcpy(&usb_tx_buf[6], data, length);
	usb_tx_buf[6 + length] = FOOTER_0;

	uint8_t ret = usb_send_data(usb_tx_buf, length + 7);
	if (!ret) {
		error_handler(ERROR_ID_USB_TRANSMIT);
	}
}

void error_msg(uint8_t error_id, uint8_t *data, uint16_t length) {
	send_msg(MSG_TYPE_ERROR, error_id, data, length);
}

void float_to_byte(uint8_t *buf, float val) {
	uint32_t temp = *(uint32_t*) &val;
	*(buf) = temp & 0x00FF;
	*(++buf) = (temp >> 8) & 0x00FF;
	*(++buf) = (temp >> 16) & 0x00FF;
	*(++buf) = (temp >> 24);
}
