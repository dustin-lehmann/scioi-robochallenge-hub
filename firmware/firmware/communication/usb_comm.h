/*
 * usb_comm.h
 *
 *  Created on: Feb 1, 2022
 *      Author: lehmann_workstation
 */

#ifndef COMMUNICATION_USB_COMM_H_
#define COMMUNICATION_USB_COMM_H_

#include "usb_device.h"
#include "usbd_cdc_if.h"
#include "messages.h"


#define HEADER_0 0xAA
#define HEADER_1 0xBB
#define FOOTER_0 0xCC

extern uint8_t usb_rx_buf[256];
extern uint8_t usb_tx_buf[256];

typedef struct{
	uint8_t state;
	uint8_t enable;
	void* rx_callback;
}usb_cdc_interface_t;

extern usb_cdc_interface_t usb_cdc;


void usb_init(usb_cdc_interface_t* interface, void* rx_callback);
void usb_rx_handler(uint8_t* data, uint32_t len);
uint8_t usb_send_data(uint8_t* data, uint16_t len);


#endif /* COMMUNICATION_USB_COMM_H_ */
