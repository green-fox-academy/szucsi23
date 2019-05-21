/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

int main(void)
{
	HAL_Init();

	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

	BSP_LED_Init(LED1);

	int counter = 1;
	int delay = 2000;
	int flag = 0;
	while (1) {

		counter = 1;
		while (counter <= 3) {

			BSP_LED_On(LED1);
			HAL_Delay(10);
			BSP_LED_Off(LED1);

			HAL_Delay(delay);
			counter++;
		}
		if (flag == 0) {
			delay /= 2;
			if (delay == 250) {
				flag = 1;
			}
		}
		if (flag == 1) {
			delay *= 2;
			if (delay == 250) {
				flag = 0;
			}
		}

	}
}
