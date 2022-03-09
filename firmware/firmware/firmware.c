/*
 * firmware.c
 *
 *  Created on: Feb 1, 2022
 *      Author: lehmann_workstation
 */

#include "firmware.h"

TIM_HandleTypeDef *distance_sensor_timer;

distance_sensor_handler_t distance_sensor_handler;
distance_sensor_t distance_sensor_1;

void firmware_init() {

	// Set the status LED to IDLE
	set_status_led(LED_STATUS_IDLE);
	// Initialize the USB Device
	MX_USB_DEVICE_Init();

	// Set the status LED to OK
	set_status_led(LED_STATUS_OK);

	// Define one distance sensor
	init_distance_sensor_handler(&distance_sensor_handler,
			distance_sensor_timer, NULL);

	distance_sensor_1.echo_port = GPIOB;
	distance_sensor_1.echo_pin = GPIO_PIN_14;
	distance_sensor_1.trig_port = GPIOB;
	distance_sensor_1.trig_pin = GPIO_PIN_13;

	register_distance_sensor(&distance_sensor_handler, &distance_sensor_1);

}

void error_handler(uint8_t error_id) {
	set_status_led(LED_STATUS_ERROR);
}

//void usb_comm_thread(void const * argument){
//	while (1){
//		HAL_GPIO_TogglePin(LED_BLUE_PORT, LED_BLUE_PIN);
//		osDelay(500);
//	}
//}
