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

	GPIOF->MODER |= (GPIO_MODER_MODER6_0);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_6);

	uint32_t on = 1 << 6;
	uint32_t off = on << 16;
	uint32_t prev = on;

	while (1) {

		for (int i = 0; i < 5; ++i) {

			GPIOF->BSRR = prev << 16;
			GPIOF->BSRR = on << i;
			prev = on << i;

			HAL_Delay(100);

		}
		for (int i = 3; i > 0; --i) {

			GPIOF->BSRR = prev << 16;
			GPIOF->BSRR = on << i;
			prev = on << i;

			HAL_Delay(100);

		}

	}
}
