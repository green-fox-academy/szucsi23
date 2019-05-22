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

	uint32_t first = 1 << 6;
	uint32_t last = 1 << 10;

	uint32_t prev = last;
	uint32_t next =  first;
	int flag = 0;

	while (1) {

		if (next != last && flag == 0) {
			GPIOF->BSRR = prev << 16;
			GPIOF->BSRR = next;

			prev = next;
			next = next << 1;

			HAL_Delay(100);

			if (next == last) {
				flag = 1;
			}
		}

		if (next != first && flag == 1) {
			GPIOF->BSRR = prev << 16;
			GPIOF->BSRR = next;

			prev = next;
			next = next >> 1;

			HAL_Delay(100);

			if (next == first) {
				flag = 0;
			}
		}

	}
}
