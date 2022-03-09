/*
 * firmware.h
 *
 *  Created on: Feb 1, 2022
 *      Author: lehmann_workstation
 */

#ifndef FIRMWARE_H_
#define FIRMWARE_H_

#include "usb_comm.h"
#include "board.h"
#include "cmsis_os.h"
#include "messages.h"
#include "usbd_cdc_if.h"
#include "ws2812.h"
#include "errors.h"
#include "distance.h"


extern TIM_HandleTypeDef* distance_sensor_timer;


extern distance_sensor_handler_t distance_sensor_handler;
extern distance_sensor_t distance_sensor_1;

void firmware_init();

void error_handler(uint8_t error_id);

/* Threads */
osThreadId_t usb_task_handle;
void usb_comm_thread(void const * argument);

osThreadId_t distanceMeas_task_handle;
void distance_meas_thread(void const * argument);


#endif /* FIRMWARE_H_ */
