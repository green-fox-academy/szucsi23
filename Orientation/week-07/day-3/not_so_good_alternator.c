#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

void init_pins(void);

int main(void)
{
	HAL_Init();
	init_pins();

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;

	uint32_t first = 1 << 6;
	uint32_t last = 1 << 10;

	uint32_t prev = last;
	uint32_t now = first;
	int dir = 1;

	uint32_t user_button = (1 << 4);

	while (1) {

		if (GPIOB->IDR & (user_button)) {
			dir *= -1;
		}

		if (now != last && dir == 1) {

			GPIOF->BSRR = now;
			GPIOF->BSRR = prev << 16;

			prev = now;
			now = now << 1;

			HAL_Delay(100);

			if (now == last) {
				GPIOF->BSRR = now;
				GPIOF->BSRR = prev << 16;
				prev = now;
				now = first;
				HAL_Delay(100);
			}
		}

		if (now != first && dir == -1) {

			GPIOF->BSRR = now;
			GPIOF->BSRR = prev << 16;

			prev = now;
			now = now >> 1;

			HAL_Delay(100);

			if (now == first) {
				GPIOF->BSRR = now;
				GPIOF->BSRR = prev << 16;
				prev = now;
				now = last;
				HAL_Delay(100);
			}
		}

	}
}

void init_pins(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
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

	GPIOB->MODER |= (1 << 4);
}
