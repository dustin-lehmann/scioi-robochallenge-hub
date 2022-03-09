/*
 * ws2812.c
 *
 *  Created on: Feb 11, 2022
 *      Author: Dustin Lehmann
 */


#include "ws2812.h"

volatile uint8_t datasentflag = 0;
TIM_HandleTypeDef* ws2812_tim = NULL;

uint8_t LED_Data[MAX_LED][4];
uint8_t LED_Mod[MAX_LED][4];

uint16_t pwmData[(24*MAX_LED)+50];


void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
	HAL_TIM_PWM_Stop_DMA(ws2812_tim, WS2812_TIM_CHANNEL);
	datasentflag=1;
}

void ws2812_init(TIM_HandleTypeDef* tim){
	ws2812_tim = tim;
	for (int i=0;i<MAX_LED;i++){
		LED_Data[i][0] = i;
		LED_Data[i][1] = 0;
		LED_Data[i][2] = 0;
		LED_Data[i][3] = 0;
	}
}

void ws2812_set(int LEDnum, int Red, int Green, int Blue)
{
	LED_Data[LEDnum][0] = LEDnum;
	LED_Data[LEDnum][1] = Green;
	LED_Data[LEDnum][2] = Red;
	LED_Data[LEDnum][3] = Blue;
}

void ws2812_brightness(uint8_t brightness)  // 0-100
{
#if USE_BRIGHTNESS

	if (brightness > 100) brightness = 100;
	for (int i=0; i<MAX_LED; i++)
	{
		LED_Mod[i][0] = LED_Data[i][0];
		for (int j=1; j<4; j++)
		{
			LED_Mod[i][j] = (uint8_t) (LED_Data[i][j] * brightness/100.0);
		}
	}
#endif
}

void ws2812_send(void)
{
	uint32_t indx=0;
	uint32_t color;


	for (int i= 0; i<MAX_LED; i++)
	{
#if USE_BRIGHTNESS
		color = ((LED_Mod[i][1]<<16) | (LED_Mod[i][2]<<8) | (LED_Mod[i][3]));
#else
		color = ((LED_Data[i][1]<<16) | (LED_Data[i][2]<<8) | (LED_Data[i][3]));
#endif

		for (int i=23; i>=0; i--)
		{
			if (color&(1<<i))
			{
				pwmData[indx] = 40;  // 2/3 of 60
			}

			else pwmData[indx] = 20;  // 1/3 of 60

			indx++;
		}

	}

	for (int i=0; i<50; i++)
	{
		pwmData[indx] = 0;
		indx++;
	}

	HAL_TIM_PWM_Start_DMA(ws2812_tim, WS2812_TIM_CHANNEL, (uint32_t *)pwmData, indx);
	while (datasentflag==0){

	};
	datasentflag = 0;
}

void ws2812_reset(void)
{
	for (int i=0; i<MAX_LED; i++)
	{
		LED_Data[i][0] = i;
		LED_Data[i][1] = 0;
		LED_Data[i][2] = 0;
		LED_Data[i][3] = 0;
	}
}
