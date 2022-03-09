/*
 * ws2812.h
 *
 *  Created on: Feb 11, 2022
 *      Author: Dustin Lehmann
 */

#ifndef WS2812_H_
#define WS2812_H_

#include "stm32f4xx_hal.h"
#include "math.h"

#define MAX_LED 16
#define USE_BRIGHTNESS 0

#define PI 3.14159265

#define WS2812_TIM_CHANNEL TIM_CHANNEL_2

extern uint8_t LED_Data[MAX_LED][4];
extern uint8_t LED_Mod[MAX_LED][4];  // for brightness

extern TIM_HandleTypeDef* ws2812_tim;

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim);

void ws2812_set(int LEDnum, int Red, int Green, int Blue);
void ws2812_brightness(uint8_t brightness);

void ws2812_send(void);
void ws2812_reset(void);

void ws2812_init();


#endif /* WS2812_H_ */
