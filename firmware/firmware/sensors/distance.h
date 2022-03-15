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

//Clock/ Prescaler = 200000
#define TIMER_FREQUENCY 200000.0

typedef struct{
	GPIO_TypeDef* echo_port;
	uint16_t echo_pin;
	GPIO_TypeDef* trig_port;
	uint16_t trig_pin;
	float distance;
	uint8_t overflow;
	uint32_t tick;
	uint8_t id;
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
void sensor_timeout();

//check if Trigger or Echo caused interrupt
extern uint8_t TriggerFlag;

//pointer to current sensor
extern distance_sensor_t *current_sensor_ptr;

//pointer to sensor handler
extern distance_sensor_handler_t *distance_sensor_handler_ptr;

//execute measurement
void distance_meas_task(distance_sensor_handler_t* handler);


void distance_sensor_timer_callback();

#endif /* SENSORS_DISTANCE_H_ */
