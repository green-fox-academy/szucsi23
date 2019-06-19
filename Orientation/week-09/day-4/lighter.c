/*
 * EXTERNAL BUTTON ON F10, F9
 * EXTERNAL LED ON F7, F6
 *
 */

#include "stm32746g_discovery.h"
#include "stm32f7xx.h"
#include "stm32f7xx_it.h"


static void SystemClock_Config(void);


TIM_HandleTypeDef timer_interrupt_handle3;
GPIO_InitTypeDef external_Button_handle1;
GPIO_InitTypeDef external_Button_handle2;
GPIO_InitTypeDef gpio_handle;

volatile uint8_t spark = 0;
volatile uint8_t gas = 0;
volatile uint8_t ignition = 0;

void init_Analog_Pins()
{
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	gpio_handle.Pin = GPIO_PIN_7 | GPIO_PIN_6;
	gpio_handle.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_handle.Pull = GPIO_NOPULL;
	gpio_handle.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOF, &gpio_handle);
}

void init_Timer3_as_Interrupt()
{
	__HAL_RCC_TIM3_CLK_ENABLE()
	;

	timer_interrupt_handle3.Instance = TIM3;
	timer_interrupt_handle3.Init.Prescaler = 10800 - 1;
	timer_interrupt_handle3.Init.Period = 1000 - 1;
	timer_interrupt_handle3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_interrupt_handle3.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&timer_interrupt_handle3);

	HAL_NVIC_SetPriority(TIM3_IRQn, 1, 1);

	HAL_NVIC_EnableIRQ(TIM3_IRQn);
}

void init_External_Button_as_Interrupt()
{

	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	external_Button_handle1.Pin = GPIO_PIN_9;
	external_Button_handle1.Mode = GPIO_MODE_IT_RISING;
	external_Button_handle1.Pull = GPIO_NOPULL;
	external_Button_handle1.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOF, &external_Button_handle1);

	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 2, 1);
	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	external_Button_handle2.Pin = GPIO_PIN_10;
	external_Button_handle2.Mode = GPIO_MODE_INPUT;
	external_Button_handle2.Pull = GPIO_NOPULL;
	external_Button_handle2.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOF, &external_Button_handle2);
}

int main(void)
{
	HAL_Init();
	SystemClock_Config();

	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
	init_Analog_Pins();
	init_Timer3_as_Interrupt();
	init_External_Button_as_Interrupt();



	while (1) {

		/*-----------------------------INSERT MAGIC HERE---------------------------------*/
		while(HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_10) == 0) {
			if(spark) {
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);
			}
		}
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);

	}
}

void EXTI9_5_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_9);
}

void TIM3_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&timer_interrupt_handle3);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, GPIO_PIN_SET);
		spark = 1;
		HAL_TIM_Base_Start_IT(&timer_interrupt_handle3);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM3) {
		spark = 0;
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, GPIO_PIN_RESET);
		HAL_TIM_Base_Stop_IT(&timer_interrupt_handle3);

	}

}

//-----------------------------------------------------------------------------------------------------------------------------------

void Error_Handler(void)
{
}

void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/**Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE()
	;
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 216;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 2;

	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/**Activate the Over-Drive mode */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK |
	RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}

