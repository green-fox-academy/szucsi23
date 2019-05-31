#include "initializers.h"

#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"
#include <stdio.h>

#define MATRIX_ADDRESS (0b1110000 << 1)

//Handles---------------------------------------------------------------------------------------------------
GPIO_InitTypeDef user_Button_handle;
GPIO_InitTypeDef gpio_handle;
GPIO_InitTypeDef external_Button_handle;
RNG_HandleTypeDef rng_handle;
TIM_HandleTypeDef timer_handle;
TIM_OC_InitTypeDef pwm_handle;
UART_HandleTypeDef uart_handle;
I2C_HandleTypeDef I2C_handle;

// One Function to rule them all----------------------------------------------------------------------------
void init_ALL()								//Uncomment only the needed initializer function calls!
{
	HAL_Init();

	//init_User_Button();
	//init_User_LED();
	//init_LCD();
	//init_Touchscreen();
	//init_RNG();
	//init_Timer();
	//init_PWM();
	//init_UART();
	//init_I2C();

	//init_Analog_Pins();
	//init_Digital_Pins();
	//init_External_Button();
	//init_LED_Matrix();

	//init_User_Button_as_Interrupt();
	//init_External_Button_as_Interrupt();
	//init_Touchscreen_as_Interrupt();
	//init_Timer_as_Interrupt();
	//init_UART_as_Interrupt();
}
// Internal initializers------------------------------------------------------------------------------------
void init_User_Button()
{
	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
}

void init_User_LED()
{
	BSP_LED_Init(LED1);
}

void init_LCD()
{
	BSP_LCD_Init();
	BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS);
	BSP_LCD_SelectLayer(1);
	BSP_LCD_Clear(0x00000000);
	BSP_LCD_SetBackColor(0x00000000);
	BSP_LCD_SetFont(&Font12);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
}

void init_Touchscreen()
{
	BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());
}

void init_RNG()
{
	rng_handle.Instance = RNG;
	HAL_RNG_Init(&rng_handle);
}

void init_Timer()
{
	__HAL_RCC_TIM2_CLK_ENABLE();

	timer_handle.Instance = TIM2;
	timer_handle.Init.Prescaler = 108 - 1;
	timer_handle.Init.Period = 100 - 1;
	timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_PWM_Init(&timer_handle); //TODO: ez okozhat gondot itt?
}

void init_PWM()
{
	pwm_handle.Pulse = 0;
	pwm_handle.OCMode = TIM_OCMODE_PWM1;
	pwm_handle.OCPolarity = TIM_OCPOLARITY_HIGH;
	pwm_handle.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&timer_handle, &pwm_handle, TIM_CHANNEL_1);
}

void init_UART()
{
	__HAL_RCC_USART1_CLK_ENABLE();

	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);
}

void init_I2C()
{
	__HAL_RCC_I2C1_CLK_ENABLE();

	I2C_handle.Instance = I2C1;
	I2C_handle.Init.Timing = 0x40912732;
	I2C_handle.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;

	HAL_I2C_Init(&I2C_handle);

	HAL_TIM_PWM_Start(&timer_handle, TIM_CHANNEL_1); //TODO: ez j� itt?
}

// External initializers------------------------------------------------------------------------------------
void init_Analog_Pins()
{
	__HAL_RCC_GPIOF_CLK_ENABLE();

	gpio_handle.Pin = GPIO_PIN_10 | GPIO_PIN_9 | GPIO_PIN_8 | GPIO_PIN_7 | GPIO_PIN_6;
	gpio_handle.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_handle.Pull = GPIO_NOPULL;
	gpio_handle.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOF, &gpio_handle);
}

void init_Digital_Pins()
{
	__HAL_RCC_GPIOA_CLK_ENABLE();

	gpio_handle.Pin = GPIO_PIN_15;
	gpio_handle.Mode = GPIO_MODE_AF_PP;
	gpio_handle.Pull = GPIO_NOPULL;
	gpio_handle.Speed = GPIO_SPEED_HIGH;
	gpio_handle.Alternate = GPIO_AF1_TIM2;

	HAL_GPIO_Init(GPIOA, &gpio_handle);
}

void init_External_Button()
{
	__HAL_RCC_GPIOD_CLK_ENABLE();

	external_Button_Handle.Pin = GPIO_PIN_4;
	external_Button_Handle.Mode = GPIO_MODE_INPUT;
	external_Button_Handle.Pull = GPIO_NOPULL;
	external_Button_Handle.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOD, &external_Button_handle);
}

void init_LED_Matrix()
{
	uint8_t osc_reg = 0b00100001;
	uint8_t rowint_reg = 0b10100000;
	uint8_t disp_reg = 0b10000001;

	HAL_I2C_Master_Transmit(&I2C_handle, MATRIX_ADDRESS, &osc_reg, sizeof(osc_reg), 100);
	HAL_I2C_Master_Transmit(&I2C_handle, MATRIX_ADDRESS, &rowint_reg, sizeof(rowint_reg), 100);
	HAL_I2C_Master_Transmit(&I2C_handle, MATRIX_ADDRESS, &disp_reg, sizeof(disp_reg), 100);
}

// Interrupt initializers-----------------------------------------------------------------------------------
void init_User_Button_as_Interrupt()
{
	__HAL_RCC_GPIOI_CLK_ENABLE();

	user_Button_handle.Pin = GPIO_PIN_11;
	user_Button_handle.Pull = GPIO_NOPULL;
	user_Button_handle.Speed = GPIO_SPEED_FAST;
    user_Button_handle.Mode = GPIO_MODE_IT_RISING;
    HAL_GPIO_Init(GPIOI, &user_Button_handle);

    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void init_External_Button_as_Interrupt()
{

	__HAL_RCC_GPIOB_CLK_ENABLE();

	external_Button_handle.Pin = GPIO_PIN_4;
	external_Button_handle.Mode = GPIO_MODE_IT_RISING;
	external_Button_handle.Pull = GPIO_NOPULL;
	external_Button_handle.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOB, &external_Button_handle);

	HAL_NVIC_SetPriority(EXTI4_IRQn, 4, 1);
	HAL_NVIC_EnableIRQ(EXTI4_IRQn);
}

void init_Touchscreen_as_Interrupt()
{
	BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());

	TS_INT_GPIO_CLK_ENABLE();
	BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());
	BSP_TS_ITConfig();
}

void init_Timer_as_Interrupt()
{
	__HAL_RCC_TIM2_CLK_ENABLE();

	timer_handle.Instance = TIM2;
	timer_handle.Init.Prescaler = 54000 - 1;
	timer_handle.Init.Period = 2000 - 1;
	timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&timer_handle);

	HAL_NVIC_SetPriority(TIM2_IRQn, 1, 0);

	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

void init_UART_as_Interrupt()
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

// Interrupt Handles----------------------------------------------------------------------------------------

void EXTI4_IRQHandler()
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);	//for external button
    										//(GPIO_PIN_11) for internal button
}


void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(TS_INT_PIN); 	//for touch screen
}

void TIM2_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&timer_handle);
}

void USART1_IRQHandler()
{
	HAL_UART_IRQHandler(&uart_handle);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2) {

    }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{

}

// Other necessities----------------------------------------------------------------------------------------

static void Error_Handler(void)
{

}

static void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

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

	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}
