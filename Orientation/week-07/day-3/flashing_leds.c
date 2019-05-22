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

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;

	GPIOF->MODER |= (GPIO_MODER_MODER10_0);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_10);

	GPIOF->MODER |= (GPIO_MODER_MODER9_0);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_9);

	GPIOF->MODER |= (GPIO_MODER_MODER8_0);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_8);

	GPIOF->MODER |= (GPIO_MODER_MODER7_0);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_7);


	uint32_t on = 1 << 7;
	uint32_t off = on << 16;

	while (1) {

		GPIOF->BSRR = off << 4;
		GPIOF->BSRR = on;
		HAL_Delay(500);
		GPIOF->BSRR = off;
		GPIOF->BSRR = on << 1;
		HAL_Delay(500);
		GPIOF->BSRR = off << 1;
		GPIOF->BSRR = on << 2;
		HAL_Delay(500);
		GPIOF->BSRR = off << 2;
		GPIOF->BSRR = on << 3;
		HAL_Delay(500);
		GPIOF->BSRR = off << 3;
		GPIOF->BSRR = on << 4;


	}
}
