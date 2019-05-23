#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <math.h>

GPIO_InitTypeDef user_button_handle;

void init_led_pins();
void init_button_pins(void);

void EXTI4_IRQHandler();
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

void light_up_in_binary(int binary[]);
void change_to_binary(int binary[], int num);
int main()
{
	HAL_Init();
	init_led_pins();
	init_button_pins();
	int bits[5];

	while (1) {

		for (int i = 0; (i < 32); ++i) {
			if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4)) {
				change_to_binary(bits, i);
				light_up_in_binary(bits);

				HAL_Delay(300);
			} else i--;

		}
	}
}

void init_led_pins()
{
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	GPIO_InitTypeDef gpio_config;

	gpio_config.Pin = GPIO_PIN_All;
	gpio_config.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_config.Pull = GPIO_NOPULL;
	gpio_config.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOF, &gpio_config);
}

void init_button_pins(void)
{
	__HAL_RCC_GPIOB_CLK_ENABLE()
	;

	GPIO_InitTypeDef gpio_config;

	gpio_config.Pin = GPIO_PIN_4;
	gpio_config.Mode = GPIO_MODE_INPUT;
	gpio_config.Pull = GPIO_NOPULL;
	gpio_config.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOB, &gpio_config);

}

void EXTI4_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_10);
}

void light_up_in_binary(int binary[])
{
	for (int i = 0; i < 5; ++i) {
		if (binary[i] == 1) {
			HAL_GPIO_WritePin(GPIOF, 1 << (i + 6), GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(GPIOF, 1 << (i + 6), GPIO_PIN_RESET);
		}

	}

}

void change_to_binary(int binary[], int num)
{
	for (int i = 4; i >= 0; i--) {
		binary[i] = num / (int) pow(2, i);
		num = num % (int) pow(2, i);
	}
}
