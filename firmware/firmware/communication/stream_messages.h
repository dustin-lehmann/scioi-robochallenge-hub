/*
 * stream_messages.h
 *
 *  Created on: Mar 15, 2022
 *      Author: lehmann_workstation
 */

#ifndef COMMUNICATION_STREAM_MESSAGES_H_
#define COMMUNICATION_STREAM_MESSAGES_H_

#include "distance.h"
#include "messages.h"


#define MSG_STREAM_DISTANCE_ID 0x03

void msg_stream_distance(uint8_t* buffer, distance_sensor_t* distance_sensor);

#endif /* COMMUNICATION_STREAM_MESSAGES_H_ */
