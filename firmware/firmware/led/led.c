/*
 * led.c
 *
 *  Created on: 13 Feb 2022
 *      Author: Dustin Lehmann
 */

#include "led.h"

void set_led(uint8_t led_num, uint8_t state) {
	switch (led_num) {
	case LED_GREEN:
		HAL_GPIO_WritePin(LED_GREEN_PORT, LED_GREEN_PIN, state);
		break;
	case LED_BLUE:
		HAL_GPIO_WritePin(LED_BLUE_PORT, LED_BLUE_PIN, state);
		break;
	case LED_ORANGE:
		HAL_GPIO_WritePin(LED_ORANGE_PORT, LED_ORANGE_PIN, state);
		break;
	}
}

void toggle_led(uint8_t led_num) {
	switch (led_num) {
	case LED_GREEN:
		HAL_GPIO_TogglePin(LED_GREEN_PORT, LED_GREEN_PIN);
		break;
	case LED_BLUE:
		HAL_GPIO_TogglePin(LED_BLUE_PORT, LED_BLUE_PIN);
		break;
	case LED_ORANGE:
		HAL_GPIO_TogglePin(LED_ORANGE_PORT, LED_ORANGE_PIN);
		break;
	}
}

void set_status_led_color(uint8_t red, uint8_t green, uint8_t blue) {
	ws2812_set(0, red, green, blue);
}
void set_status_led(uint8_t state) {
	switch (state) {
	case LED_STATUS_ERROR:
		set_status_led_color(60, 0, 0);
		break;
	case LED_STATUS_OFF:
		set_status_led_color(0, 0, 0);
		break;
	case LED_STATUS_OK:
		set_status_led_color(0, 60, 0);
		break;
	case LED_STATUS_IDLE:
		set_status_led_color(0, 0, 60);
		break;
	}
	ws2812_send();
}
