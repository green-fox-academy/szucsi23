#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"
#include <stdio.h>

static void Error_Handler(void);
static void SystemClock_Config(void);

volatile uint32_t counter = 0;
volatile uint8_t counter_changed = 0;


void PB_init()
{
	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_EXTI);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 8, 0);
}

void LCD_init()
{
	BSP_LCD_Init();
	BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS);
	BSP_LCD_SelectLayer(1);
	BSP_LCD_Clear(0x00000000);
	BSP_LCD_SetBackColor(0x00000000);
	BSP_LCD_SetFont(&Font24);
	BSP_LCD_SetTextColor(LCD_COLOR_RED);
}

void TS_init()
{
	BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());
}

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	__HAL_RCC_RNG_CLK_ENABLE();

	LCD_init();
	TS_init();
	PB_init();

	RNG_HandleTypeDef rng_handle;
	rng_handle.Instance = RNG;
	HAL_RNG_Init(&rng_handle);



	uint16_t char_buffer[32];


	TS_StateTypeDef ts_state;


	while (1) {

		uint32_t rand = HAL_RNG_GetRandomNumber(&rng_handle) % 10;

		BSP_TS_GetState(&ts_state);
		if (ts_state.touchDetected) {
			counter_changed = 0;
			BSP_LCD_Clear(0x00000000);

			sprintf(char_buffer, "%lu", rand);
			BSP_LCD_DisplayStringAt(ts_state.touchX[0], ts_state.touchY[0], (uint8_t*)char_buffer, LEFT_MODE);
		}
	}
}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	counter++;
	counter_changed = 1;
}


static void Error_Handler(void)
{
}

static void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct =
	{ 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct =
	{ 0 };

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
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}
