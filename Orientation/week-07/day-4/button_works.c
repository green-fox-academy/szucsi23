#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

void init_led_pins(void);
void init_button_pins(void);

int main(void)
{
	HAL_Init();
	init_led_pins();
	init_button_pins();



	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);

	while (1) {

		if(HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_11)){
			HAL_Delay(200);
			HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_10);
			HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_9);
		}

	}
}

void init_led_pins(void)
{
	__HAL_RCC_GPIOF_CLK_ENABLE();

	GPIO_InitTypeDef gpio_config;

	gpio_config.Pin = GPIO_PIN_10 | GPIO_PIN_9;
	gpio_config.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_config.Pull = GPIO_NOPULL;
	gpio_config.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOF, &gpio_config);
}

void init_button_pins(void)
{
	__HAL_RCC_GPIOI_CLK_ENABLE();

	GPIO_InitTypeDef gpio_config;

	gpio_config.Pin = GPIO_PIN_11;
	gpio_config.Mode = GPIO_MODE_INPUT;
	gpio_config.Pull = GPIO_NOPULL;
	gpio_config.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOI, &gpio_config);
}

