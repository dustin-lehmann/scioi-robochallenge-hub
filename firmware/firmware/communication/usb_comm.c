/*
 * usb_comm.c
 *
 *  Created on: Feb 1, 2022
 *      Author: lehmann_workstation
 */


#include "usb_comm.h"
#include "usbd_cdc_if.h"

uint8_t usb_tx_buf[256];
uint8_t usb_rx_buf[256];

usb_cdc_interface_t usb_cdc;


void usb_init(usb_cdc_interface_t* interface, void* rx_callback){
	interface->rx_callback = rx_callback;
}

void usb_rx_handler(uint8_t* data, uint32_t len){
	if (len<2){
		error_msg(ERROR_MSG_INVALID, NULL, 0);
		return;
	}
	// Check if the first two bytes are the correct header
	if (!(data[0] == HEADER_0 && data[1]==HEADER_1)){
		error_msg(ERROR_MSG_INVALID, NULL, 0);
		return; // TODO Error Handling
	}

	// Check if the last byte is the correct footer
	if (!(data[len-1] == FOOTER_0)){
		return; // TODO Error Handling
	}

	// check the minimum length
	if(len<8){
		return; // TODO Error Handling
	}

	// extract the meta data
	uint8_t type = data[2];
	uint8_t id = data[3];
	uint8_t data_len = data[4];

	if (MSG_CRC8_ENABLE){
		uint8_t crc8 = data[5];
	}

	// check if the data length is correct
	if (!((len-7) == data_len)){
		return; // TODO Error Handling
	}

	// Copy the data to the msg_in_buffer
	memcpy(msg_in_buf,&data[6], data_len);

	// Invoke the message handler to execute the corresponding functions
	msg_handler(type, id, msg_in_buf, data_len);
}


uint8_t usb_send_data(uint8_t* data, uint16_t len){
	uint8_t ret = CDC_Transmit_FS(data, len);
	if (ret == USBD_OK){
		return USBD_OK;
	} else {
		return 1;
	}
}
