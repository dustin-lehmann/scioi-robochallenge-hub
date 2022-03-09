/*
 * distance.h
 *
 *  Created on: Mar 4, 2022
 *      Author: lehmann_workstation
 */

#ifndef SENSORS_DISTANCE_H_
#define SENSORS_DISTANCE_H_

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_tim.h"
#include "cmsis_os.h"


#define MAX_NUM_SENSORS 4

typedef struct{
	GPIO_TypeDef* echo_port;
	uint16_t echo_pin;
	GPIO_TypeDef* trig_port;
	uint16_t trig_pin;
	float distance;
	uint8_t overflow;
	uint32_t tick;
} distance_sensor_t;


typedef struct{
	TIM_HandleTypeDef* timer;
	distance_sensor_t** distance_sensors;
	uint8_t num_sensors;
	uint8_t current_sensor;
	void* isr_callback;
	uint16_t meas_freq; // Measurement frequency in ms
	uint8_t initialized;
	// task
} distance_sensor_handler_t;

void register_distance_sensor(distance_sensor_handler_t* handler, distance_sensor_t* sensor);
void init_distance_sensor_handler(distance_sensor_handler_t* handler, TIM_HandleTypeDef* timer, void* isr_callback);
void start_distance_measure(distance_sensor_handler_t* handler, uint8_t sensor_id);

//void init_distance_sensor(uint16_t echo_port, uint16)

void distance_meas_task(distance_sensor_handler_t* handler);

#endif /* SENSORS_DISTANCE_H_ */
