/*
 * led.h
 *
 *  Created on: 13 Feb 2022
 *      Author: Dustin Lehmann
 */

#ifndef LED_LED_H_
#define LED_LED_H_

#include <stdint.h>
#include "board.h"
#include "ws2812.h"

#define LED_GREEN 1
#define LED_BLUE 2
#define LED_ORANGE 3

#define LED_STATUS_OFF 0
#define LED_STATUS_OK 1
#define LED_STATUS_ERROR 2
#define LED_STATUS_IDLE 3


void set_led(uint8_t led_num, uint8_t state);
void toggle_led(uint8_t led_num);

void set_status_led_color(uint8_t red, uint8_t green, uint8_t blue);
void set_status_led(uint8_t state);



#endif /* LED_LED_H_ */
