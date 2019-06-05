#include "stm32746g_discovery.h"
#include "stm32f7xx.h"
#include "stm32f7xx_it.h"
#include <math.h>

static void SystemClock_Config(void);

TIM_HandleTypeDef timer_interrupt_handle;

volatile uint16_t counter = 0;
volatile uint8_t flag = 0;
volatile uint8_t state = 0;



void init_Timer_as_Interrupt()
{
	__HAL_RCC_TIM4_CLK_ENABLE()
	;

	timer_interrupt_handle.Instance = TIM4;
	timer_interrupt_handle.Init.Prescaler = 108 - 1;
	timer_interrupt_handle.Init.Period = 1000 - 1;
	timer_interrupt_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_interrupt_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&timer_interrupt_handle);

	HAL_NVIC_SetPriority(TIM4_IRQn, 1, 0);

	HAL_NVIC_EnableIRQ(TIM4_IRQn);
}



int main(void)
{
	HAL_Init();
	SystemClock_Config();


	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
	BSP_LED_Init(LED1);

	init_Timer_as_Interrupt();

	HAL_TIM_Base_Start_IT(&timer_interrupt_handle);

	while (1) {

		/*-----------------------------INSERT MAGIC HERE---------------------------------*/
		if(state) {
			 BSP_LED_On(LED_GREEN);
		} else {
			BSP_LED_Off(LED_GREEN);
		}



	}
}


void TIM4_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&timer_interrupt_handle);									//for timer
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)							//Timer callback
{
	if (htim->Instance == TIM4) {
		if (BSP_PB_GetState(BUTTON_KEY) == 1) {
			counter++;
			flag = 1;
			if(counter >= 2000) {
				state = 1;
				flag = 0;
			}
		} else {
			counter = 0;
		}

		if((flag == 1) && (BSP_PB_GetState(BUTTON_KEY) == 0)) {
			state = 0;
		}
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

