/*
 * distance.c
 *
 *  Created on: Mar 4, 2022
 *      Author: lehmann_workstation
 */

#include "distance.h"

distance_sensor_t* distance_sensors[MAX_NUM_SENSORS];


void init_distance_sensor_handler(distance_sensor_handler_t* handler, TIM_HandleTypeDef* timer, void* isr_callback){
	handler -> distance_sensors = distance_sensors;
	handler -> timer = timer;
	handler -> num_sensors = 0;
	handler -> isr_callback = isr_callback;
	handler -> initialized = 1;

}


void register_distance_sensor(distance_sensor_handler_t* handler, distance_sensor_t* sensor){
	handler -> num_sensors++;
	handler -> distance_sensors[handler->num_sensors-1] = sensor;
	sensor -> distance = -1;
	sensor -> overflow = 1;
	sensor ->tick = 0;
}

void distance_meas_task(distance_sensor_handler_t* handler)
{

	if (handler -> initialized != 1){
		return;
	}
	if (handler -> num_sensors == 0){
		return;
	}

	while(1){
		// Start the measurement for the current sensor
		if (handler -> current_sensor > (handler -> num_sensors-1)){
			handler -> current_sensor = 0;
		}
		start_distance_measure(handler, handler -> current_sensor);
		handler -> current_sensor++;
		osDelay(handler->meas_freq);
	}
}


void start_distance_measure(distance_sensor_handler_t* handler, uint8_t sensor_id){
	// Start the timer

	// Generate Trigger Pulse




}




void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){

	// 1. Detect which Sensor is generating the interrupt (later)

	// 2. Detect whether the interrupt is a rising or falling edge

	// 3. Either start or stop the timer

//	// Start the timer
//	__HAL_TIM_SET_COUNTER(handler->timer, 0);
//	HAL_TIM_Base_Start(handler->timer);
//
//
//	// Stop the timer
//	HAL_TIM_Base_Stop(handler->timer);
//	uint32_t tick = __HAL_TIM_GET_COUNTER(handler->timer);

	// Calculate the distance from the tick variable


	// Handle overflow

}
