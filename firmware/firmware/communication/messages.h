/*
 * messages.h
 *
 *  Created on: 1 Feb 2022
 *      Author: lehmann_workstation
 */

#ifndef COMMUNICATION_MESSAGES_H_
#define COMMUNICATION_MESSAGES_H_

#include <stdint.h>


#include "common.h"
#include "usb_comm.h"
#include "config.h"
#include "errors.h"

#include "write_messages.h"
#include "request_messages.h"
#include "stream_messages.h"

extern uint8_t msg_in_buf[128];
extern uint8_t msg_out_buf[128];

#define MSG_TYPE_STREAMING 0x01
#define MSG_TYPE_EVENT 0x02
#define MSG_TYPE_ERROR 0x03
#define MSG_TYPE_WRITE 0x04
#define MSG_TYPE_REQUEST 0x05
#define MSG_TYPE_RESPONSE 0x06


#define ERROR_MSG_INVALID 0x01
#define ERROR_MSG_LEN 0x02

void uint32_to_byte(uint8_t* buf, uint32_t val);

void float_to_byte(uint8_t* buf, float val);

void msg_handler(uint8_t type, uint8_t id, uint8_t* msg, uint16_t length);
void send_msg(uint8_t type, uint8_t id, uint8_t* data, uint16_t length);

void error_msg(uint8_t error_id, uint8_t* data, uint16_t length);


///* General messages */
//void status_msg_out(uint8_t* buf, uint32_t tick, uint8_t state);
//
///* Error messages */
//struct error_msg_out {
//	uint16_t header;
//	uint8_t error_id;
//	uint8_t error_sub_id;
//	uint8_t data[20];
//};
//
//
///* Battery */
//struct battery_msg_out {
//	uint16_t header;
//	float battery_voltage;
//};
//
///* Distance sensors */
//struct distance_msg_out {
//	uint16_t header;
//	uint8_t len;
//	uint8_t state;
//	uint8_t sensor1_state;
//	float sensor1_dist;
//	uint8_t sensor2_state;
//	float sensor2_dist;
//	uint8_t sensor3_state;
//	float sensor3_dist;
//	uint8_t sensor4_state;
//	float sensor4_dist;
//};
//
//// 0xAA 0xBB 0x01 0x02 0x12
//
///* Motors */
//struct motor_msg_out {
//	uint16_t header;
//	uint8_t len;
//	uint8_t state;
//	float speed_left;
//	float speed_right;
//};
//
///* Servos */
//
//
///* Expansion Header */
//struct expansion_header_msg  {
//
//};
//
///* Incoming messages */
//struct led_msg_incoming {
//	uint16_t header;
//	uint8_t len;
//	uint8_t led_blue_state;
//	uint8_t led_orange_state;
//	uint8_t led_green_state;
//};

#endif /* COMMUNICATION_MESSAGES_H_ */
