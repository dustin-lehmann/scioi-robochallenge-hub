/*
 * stream_messages.c
 *
 *  Created on: Mar 15, 2022
 *      Author: lehmann_workstation
 */

#include "stream_messages.h"

void msg_stream_distance(uint8_t* buffer, distance_sensor_t* distance_sensor){
	buffer[0] = 0x00; // tick[0]
	buffer[1] = 0x00; // tick[1]
	buffer[2] = 0x00; // tick[2]
	buffer[3] = 0x00; // tick[3]

	buffer[4] = distance_sensor ->id;
	buffer[5] = distance_sensor ->overflow;
	float_to_byte(&buffer[6], distance_sensor->distance);

	send_msg(MSG_TYPE_STREAMING, MSG_STREAM_DISTANCE_ID, buffer, 10);
}


