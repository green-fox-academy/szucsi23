/*
 * EXTERNAL BUTTON ON F10, F9
 * EXTERNAL LED ON F7, F6
 *
 */

#include "stm32746g_discovery.h"
#include "stm32f7xx.h"
#include "stm32f7xx_it.h"
#include <string.h>
#include <stdio.h>

static void SystemClock_Config(void);
#define UART_PUTCHAR int __io_putchar(int ch)

TIM_HandleTypeDef timer_handle;
UART_HandleTypeDef uart_handle;
GPIO_InitTypeDef gpio_adc_pin;
GPIO_InitTypeDef gpio_handle;
ADC_HandleTypeDef adc_handle;
ADC_ChannelConfTypeDef adc_channel_config;
TIM_HandleTypeDef timer_handle;
TIM_OC_InitTypeDef pwm_config;

volatile uint8_t buffer = 0;
volatile uint8_t *text;
volatile int fan_speed = 0;
volatile int flag = 0;

void init_UART()
{
	__HAL_RCC_USART1_CLK_ENABLE();

	uart_handle.Instance = USART1;
		uart_handle.Init.BaudRate = 115200;
		uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
		uart_handle.Init.Mode = UART_MODE_TX_RX;
		uart_handle.Init.Parity = UART_PARITY_NONE;
		uart_handle.Init.StopBits = UART_STOPBITS_1;
		uart_handle.Init.WordLength = UART_WORDLENGTH_8B;

		BSP_COM_Init(COM1, &uart_handle);


		HAL_NVIC_EnableIRQ(USART1_IRQn);
		HAL_NVIC_SetPriority(USART1_IRQn, 8, 0);
}

void init_adc()
{
    /* configuring A0 pin as analog input */
    __HAL_RCC_GPIOA_CLK_ENABLE();
	/* there is no need for setting the Alternate datafield like other peripherals*/
    gpio_adc_pin.Mode = GPIO_MODE_ANALOG;
    gpio_adc_pin.Pin = GPIO_PIN_0;
    gpio_adc_pin.Speed = GPIO_SPEED_FAST;
    gpio_adc_pin.Pull = GPIO_NOPULL;

    HAL_GPIO_Init(GPIOA, &gpio_adc_pin);

    /* configuring ADC3, as it is the only ADC wired out to the headers */
    __HAL_RCC_ADC3_CLK_ENABLE();
    adc_handle.Instance = ADC3;
    adc_handle.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
    adc_handle.Init.Resolution = ADC_RESOLUTION_12B;

    /* these 5 settings are closely related */
    adc_handle.Init.ScanConvMode = DISABLE;
    adc_handle.Init.ContinuousConvMode = DISABLE;
    adc_handle.Init.DiscontinuousConvMode = DISABLE;
    adc_handle.Init.EOCSelection = ADC_EOC_SEQ_CONV;
    adc_handle.Init.NbrOfDiscConversion = 1;

    HAL_ADC_Init(&adc_handle);

    /* configuring a channel belonging to ADC3 */
    adc_channel_config.Channel = ADC_CHANNEL_0;
    adc_channel_config.SamplingTime = ADC_SAMPLETIME_56CYCLES;

    HAL_ADC_ConfigChannel(&adc_handle, &adc_channel_config);
}

void init_timer()
{
    __HAL_RCC_TIM3_CLK_ENABLE();

    timer_handle.Instance = TIM3;
    timer_handle.Init.Prescaler = 108 - 1; // 108000000/108=1000000 -> speed of 1 count-up: 1/1000000 s = 0.001 ms
    timer_handle.Init.Period = 100 - 1; // 100 x 0.001 ms = 10 ms = 0.01 s period
    timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

    /* configuring the timer in PWM mode instead of calling HAL_TIM_Base_Init(&timer_handle) */
    HAL_TIM_PWM_Init(&timer_handle);
}

void init_PWM()
{

    pwm_config.Pulse = 50;
    pwm_config.OCMode = TIM_OCMODE_PWM1;
    pwm_config.OCPolarity = TIM_OCPOLARITY_HIGH;
    pwm_config.OCFastMode = TIM_OCFAST_ENABLE;

    HAL_TIM_PWM_ConfigChannel(&timer_handle, &pwm_config, TIM_CHANNEL_1);
}

void init_Digital_Pins()
{
	__HAL_RCC_GPIOB_CLK_ENABLE();

	gpio_handle.Pin = GPIO_PIN_4;
	gpio_handle.Mode = GPIO_MODE_AF_PP;
	gpio_handle.Pull = GPIO_NOPULL;
	gpio_handle.Speed = GPIO_SPEED_HIGH;
	gpio_handle.Alternate = GPIO_AF2_TIM3;

	HAL_GPIO_Init(GPIOB, &gpio_handle);
}

int main(void)
{
	SystemClock_Config();

	HAL_Init();
	init_UART();
	init_adc();
	init_timer();
	init_PWM();
	init_Digital_Pins();

	HAL_TIM_PWM_Start(&timer_handle, TIM_CHANNEL_1);
	HAL_UART_Receive_IT(&uart_handle, &buffer, 1);

	uint32_t prev_adc_val = 0;
	int uart_speed = 0;
	int prev_uart_speed = 0;
	text = calloc(1, 1);

	while (1) { /*-----------------------------INSERT MAIN MAGIC HERE---------------------------------*/    //just for me, to find main easily
		HAL_Delay(250);
		HAL_ADC_Start(&adc_handle);
		uart_speed = atoi(text);

		if (HAL_ADC_PollForConversion(&adc_handle, 10) == HAL_OK) {
			uint32_t adc_val = HAL_ADC_GetValue(&adc_handle);

			if(prev_adc_val < (adc_val - 100) || prev_adc_val > (adc_val + 100)) {
				prev_adc_val = adc_val;
				fan_speed = adc_val / 40.6;


				flag = 0;
			}
		}

		if(prev_uart_speed != uart_speed && flag) {

			prev_uart_speed = uart_speed;
			fan_speed = uart_speed;
			free(text);
			text = calloc(1, 1);

		}

		printf("Fan speed: %d.\n", fan_speed);
		__HAL_TIM_SET_COMPARE(&timer_handle, TIM_CHANNEL_1, fan_speed);
	}
}

void USART1_IRQHandler()
{
	HAL_UART_IRQHandler(&uart_handle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	uint32_t length = strlen(text);
	text = realloc(text, length + 2);
	text[length] = buffer;
	text[length + 1] = '\0';

	HAL_UART_Receive_IT(&uart_handle, &buffer, 1);
	flag = 1;
}

//-----------------------------------------------------------------------------------------------------------------------------------

UART_PUTCHAR
{
	HAL_UART_Transmit(&uart_handle, (uint8_t*) &ch, 1, 0xFFFF);
	return ch;
}

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

