/*
 * distance.c
 *
 *  Created on: Mar 4, 2022
 *      Author: lehmann_workstation
 */

#include "distance.h"

//determine how many time has elapsed during echo
float time_elapsed;

//Array to store distance sensors
distance_sensor_t *distance_sensors[MAX_NUM_SENSORS];

//pointer to used handler
distance_sensor_handler_t *distance_sensor_handler_ptr;

//pointer to sensor that is currently used
distance_sensor_t *current_sensor_ptr;

//pointer to the used timer for distance measurement
extern TIM_HandleTypeDef *distance_sensor_timer;

//switch between Trigger and Echo
uint8_t RunVar = 0;

//make sure that interrupt does not start until sensors are initialized and measurement is started
uint8_t InterruptReady = 0;

//Flag to determine what caused the interrupt Trigger or Echo-Timeout
uint8_t TriggerFlag = 0;

void init_distance_sensor_handler(distance_sensor_handler_t *handler,
		TIM_HandleTypeDef *timer, void *isr_callback) {
	handler->distance_sensors = distance_sensors;
	handler->timer = timer;
	handler->num_sensors = 0;
	handler->isr_callback = isr_callback;
	handler->initialized = 1;
	distance_sensor_handler_ptr = handler;
}

void register_distance_sensor(distance_sensor_handler_t *handler,
		distance_sensor_t *sensor) {
	handler->num_sensors++;
	handler->distance_sensors[handler->num_sensors - 1] = sensor;
	sensor->distance = -1;
	sensor->overflow = 1;
	sensor->tick = 0;
	sensor->id = handler->num_sensors - 1;
}

void distance_meas_task(distance_sensor_handler_t *handler) {
	//check if handler is initialized
	if (handler->initialized != 1) {
		return;
	}
	//check if any sensors are registered
	if (handler->num_sensors == 0) {
		return;
	}

	while (1) {
		// Start the measurement for the current sensor
		if (handler->current_sensor > (handler->num_sensors - 1)) {
			handler->current_sensor = 0;
		}
		start_distance_measure(handler, handler->current_sensor);
		//wait for EXTI from Echo (measurement completed) and afterwards change to next Sensor
		while (RunVar == 0) {
		}
		RunVar = 0;
		handler->current_sensor++;
		osDelay(handler->meas_freq);

	}
}

void start_distance_measure(distance_sensor_handler_t *handler,
		uint8_t sensor_id) {

	//activate Interrupts
	InterruptReady = 1;

	//pointer to current sensor for EXTI callback function
	current_sensor_ptr = handler->distance_sensors[sensor_id];

	//Set Counter of timer to 1 -> triggers in ~10ys
	__HAL_TIM_SET_COUNTER(handler->timer, 1);

	// Start the timer
	HAL_TIM_Base_Start_IT(handler->timer);

	//Generate trigger Pulse for at least 10us -> Counter Period = 1sec*CPU Clockspeed[MHZ] / Total prescaler-value
	HAL_GPIO_WritePin(
			handler->distance_sensors[handler->current_sensor]->trig_port,
			handler->distance_sensors[handler->current_sensor]->trig_pin, 1);
	TriggerFlag = 1;

}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {

	//tell interrupt it is caused by the echo function
	TriggerFlag = 0;
	if (InterruptReady) {
		//Interrupt rising edge -> start Timer
		if (HAL_GPIO_ReadPin(current_sensor_ptr->echo_port,
				current_sensor_ptr->echo_pin)) {
			// Start the timer
			__HAL_TIM_SET_COUNTER(&*distance_sensor_handler_ptr->timer, 0);
			HAL_TIM_Base_Start(&*distance_sensor_handler_ptr->timer);
		}
		//Interrupt falling edge -> stop Timer
		else {
			//Stop the timer
			HAL_TIM_Base_Stop(&*distance_sensor_handler_ptr->timer);

			//detect how many ticks during Echo (timer counter mode: down): Timer_Period - Timer_Counter
			uint32_t tick = (uint32_t) (distance_sensor_timer->Init.Period)
					- __HAL_TIM_GET_COUNTER(
							&*distance_sensor_handler_ptr->timer);

			//calculate elapsed time during Echo
			time_elapsed = tick / TIMER_FREQUENCY;
			//write distance value to current sensor
			distance_sensor_handler_ptr->distance_sensors[distance_sensor_handler_ptr->current_sensor]->distance =
					0.5 * 343.5 * time_elapsed;
			distance_sensor_handler_ptr->distance_sensors[distance_sensor_handler_ptr->current_sensor]->overflow =
					0;

			//enable next Trigger-Pulse
			RunVar = 1;
		}
	}
	//Interrupt is caused by SensorTrigger to put Trigger Signal to low again
//	TriggerFlag = 1;
}

void sensor_timeout() {
	//Distance Sensor Timeout: Distance of current Sensor = -1
	distance_sensor_handler_ptr->distance_sensors[distance_sensor_handler_ptr->current_sensor]->distance =
			-1;
	distance_sensor_handler_ptr->distance_sensors[distance_sensor_handler_ptr->current_sensor]->overflow =
			1;
	RunVar = 1;
}

void distance_sensor_timer_callback() {
	if (TriggerFlag == 1) //Interrupt from Distance-Sensor Trigger Function
			{
		HAL_GPIO_WritePin(
				distance_sensor_handler_ptr->distance_sensors[distance_sensor_handler_ptr->current_sensor]->trig_port,
				distance_sensor_handler_ptr->distance_sensors[distance_sensor_handler_ptr->current_sensor]->trig_pin,
				0);
		TriggerFlag = 0;
	}
	else if (TriggerFlag == 0) //Interrupt from Distance-Sensor Timeout Echo
			{
		sensor_timeout();
	}
}
