#include "stm32746g_discovery.h"
#include "stm32f7xx.h"
#include "stm32f7xx_it.h"
#include <math.h>

static void SystemClock_Config(void);

GPIO_InitTypeDef led1_handle;
GPIO_InitTypeDef led2_handle;
GPIO_InitTypeDef led3_handle;

TIM_HandleTypeDef timer1_handle;
TIM_HandleTypeDef timer2_handle;
TIM_HandleTypeDef timer3_handle;
TIM_HandleTypeDef timer_interrupt_handle;

TIM_OC_InitTypeDef pwm_config;

GPIO_InitTypeDef gpio_adc_pin;
ADC_HandleTypeDef adc_handle;
ADC_ChannelConfTypeDef adc_channel_config;

volatile uint8_t counter = 1;
volatile uint8_t done_x = 0;
volatile uint8_t done_y = 0;

volatile int adc_val_x;
volatile int adc_val_y;

int distR;
int distG;
int distB;

int intensity_R;
int intensity_G;
int intensity_B;

void init_adc();

void init_led()
{
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	__HAL_RCC_GPIOB_CLK_ENABLE()
	;

	led1_handle.Pin = GPIO_PIN_15;
	led1_handle.Mode = GPIO_MODE_AF_PP;
	led1_handle.Pull = GPIO_NOPULL;
	led1_handle.Speed = GPIO_SPEED_FAST;
	led1_handle.Alternate = GPIO_AF1_TIM1;

	HAL_GPIO_Init(GPIOA, &led1_handle);

	led2_handle.Pin = GPIO_PIN_8;
	led2_handle.Mode = GPIO_MODE_AF_PP;
	led2_handle.Pull = GPIO_NOPULL;
	led2_handle.Speed = GPIO_SPEED_FAST;
	led2_handle.Alternate = GPIO_AF1_TIM2;

	HAL_GPIO_Init(GPIOA, &led2_handle);

	led3_handle.Pin = GPIO_PIN_4;
	led3_handle.Mode = GPIO_MODE_AF_PP;
	led3_handle.Pull = GPIO_NOPULL;
	led3_handle.Speed = GPIO_SPEED_FAST;
	led3_handle.Alternate = GPIO_AF2_TIM3;

	HAL_GPIO_Init(GPIOB, &led3_handle);
}

void init_timers()
{
	__HAL_RCC_TIM1_CLK_ENABLE()
	;

	timer1_handle.Instance = TIM1;
	timer1_handle.Init.Prescaler = 108 - 1;
	timer1_handle.Init.Period = 100 - 1;
	timer1_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer1_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_PWM_Init(&timer1_handle);

	__HAL_RCC_TIM2_CLK_ENABLE()
	;

	timer2_handle.Instance = TIM2;
	timer2_handle.Init.Prescaler = 108 - 1;
	timer2_handle.Init.Period = 100 - 1;
	timer2_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer2_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_PWM_Init(&timer2_handle);

	__HAL_RCC_TIM3_CLK_ENABLE()
	;

	timer3_handle.Instance = TIM3;
	timer3_handle.Init.Prescaler = 108 - 1;
	timer3_handle.Init.Period = 100 - 1;
	timer3_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer3_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_PWM_Init(&timer3_handle);
}

void init_Timer_as_Interrupt()
{
	__HAL_RCC_TIM4_CLK_ENABLE()
	;

	timer_interrupt_handle.Instance = TIM4;
	timer_interrupt_handle.Init.Prescaler = 1800 - 1;
	timer_interrupt_handle.Init.Period = 100 - 1;
	timer_interrupt_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_interrupt_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&timer_interrupt_handle);

	HAL_NVIC_SetPriority(TIM4_IRQn, 1, 0);

	HAL_NVIC_EnableIRQ(TIM4_IRQn);
}

void init_PWM()
{
	pwm_config.Pulse = 100;
	pwm_config.OCMode = TIM_OCMODE_PWM1;
	pwm_config.OCPolarity = TIM_OCPOLARITY_LOW;
	pwm_config.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&timer1_handle, &pwm_config, TIM_CHANNEL_1);
	HAL_TIM_PWM_ConfigChannel(&timer2_handle, &pwm_config, TIM_CHANNEL_1);
	HAL_TIM_PWM_ConfigChannel(&timer3_handle, &pwm_config, TIM_CHANNEL_1);
}

int main(void)
{
	HAL_Init();
	SystemClock_Config();

	init_led();
	init_timers();
	init_Timer_as_Interrupt();
	init_PWM();
	init_adc();

	HAL_TIM_PWM_Start(&timer1_handle, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&timer2_handle, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&timer3_handle, TIM_CHANNEL_1);
	HAL_TIM_Base_Start_IT(&timer_interrupt_handle);

	HAL_NVIC_SetPriority(ADC_IRQn, 2, 0);
	HAL_NVIC_EnableIRQ(ADC_IRQn);
	HAL_ADC_Start_IT(&adc_handle);

	while (1) {

		/*-----------------------------INSERT MAGIC HERE---------------------------------*/

		int x = adc_val_x;
		int y = adc_val_y;

		distR = sqrt((pow((x - 2000), 2)) + (pow((y - 4000), 2)));
		distG = sqrt((pow((x - 4000), 2)) + (pow((y - 0), 2)));
		distB = sqrt((pow((x - 0), 2)) + (pow((y - 0), 2)));

		intensity_R = 0;
		if (distR >= 2000) {
			intensity_R = 100;
		} else {
			intensity_R = distR / 20;
		}

		intensity_G = 0;
		if (distG >= 2000) {
			intensity_G = 100;
		} else {
			intensity_G = distG / 20;
		}

		intensity_B = 0;
		if (distB >= 2000) {
			intensity_B = 100;
		} else {
			intensity_B = distB / 20;
		}

		__HAL_TIM_SET_COMPARE(&timer1_handle, TIM_CHANNEL_1, intensity_R);
		__HAL_TIM_SET_COMPARE(&timer2_handle, TIM_CHANNEL_1, intensity_G);
		__HAL_TIM_SET_COMPARE(&timer3_handle, TIM_CHANNEL_1, intensity_B);

	}
}

void init_adc()
{/* configuring A0 and A1 pins (A0 and F10) as analog input */
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	gpio_adc_pin.Mode = GPIO_MODE_ANALOG;
	gpio_adc_pin.Pin = GPIO_PIN_0;
	gpio_adc_pin.Speed = GPIO_SPEED_FAST;
	gpio_adc_pin.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &gpio_adc_pin);

	__HAL_RCC_GPIOF_CLK_ENABLE()
	;
	gpio_adc_pin.Pin = GPIO_PIN_10;
	HAL_GPIO_Init(GPIOF, &gpio_adc_pin);

	/* configuring ADC3, as it is the only ADC wired out to the headers */
	__HAL_RCC_ADC3_CLK_ENABLE()
	;
	adc_handle.Instance = ADC3;
	adc_handle.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
	adc_handle.Init.Resolution = ADC_RESOLUTION_12B;
	adc_handle.Init.ScanConvMode = ENABLE;
	adc_handle.Init.ContinuousConvMode = ENABLE;
	adc_handle.Init.DiscontinuousConvMode = DISABLE;
	adc_handle.Init.EOCSelection = ADC_EOC_SEQ_CONV;
	adc_handle.Init.NbrOfConversion = 2;
	HAL_ADC_Init(&adc_handle);

	/* configuring a channel belonging to ADC3 */
	adc_channel_config.Rank = 1;
	adc_channel_config.Channel = ADC_CHANNEL_0; /* ADC3_IN0 */
	adc_channel_config.SamplingTime = ADC_SAMPLETIME_56CYCLES;
	HAL_ADC_ConfigChannel(&adc_handle, &adc_channel_config);

	adc_channel_config.Rank = 2;
	adc_channel_config.Channel = ADC_CHANNEL_8; /* ADC3_IN8 */
	adc_channel_config.SamplingTime = ADC_SAMPLETIME_56CYCLES;
	HAL_ADC_ConfigChannel(&adc_handle, &adc_channel_config);
}

void ADC_IRQHandler(void)
{
	HAL_ADC_IRQHandler(&adc_handle);
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	int value = HAL_ADC_GetValue(&adc_handle);
	if (counter) {
		adc_val_x = value;
		counter--;
		done_x = 1;
	} else {
		adc_val_y = value;
		counter++;
		done_y = 1;
	}

	if (done_x && done_y) {
		HAL_ADC_Stop_IT(&adc_handle);
	}

}

void TIM4_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&timer_interrupt_handle);									//for timer
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)				//Timer callback
{
	if (htim->Instance == TIM4) {
		done_x = 0;
		done_y = 0;
		HAL_ADC_Start_IT(&adc_handle);
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

