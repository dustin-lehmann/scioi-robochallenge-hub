/*
 * board.h
 *
 *  Created on: Feb 1, 2022
 *      Author: lehmann_workstation
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "stm32f4xx_hal.h"

#define ROBOCHALLENGE_BOARD_REV1


#ifdef ROBOCHALLENGE_BOARD_REV1

#define LED_ORANGE_PORT GPIOC
#define LED_ORANGE_PIN GPIO_PIN_9

#define LED_BLUE_PORT GPIOA
#define LED_BLUE_PIN GPIO_PIN_8

#define LED_GREEN_PORT GPIOC
#define LED_GREEN_PIN GPIO_PIN_10

#endif

#endif /* BOARD_H_ */
