
#ifndef INITIALIZERS_H
#define INITIALIZERS_H

#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"

// Handles---------------------------------------------------------------------------------------------------
extern GPIO_InitTypeDef user_Button_Handle;
extern GPIO_InitTypeDef external_Button_Handle;
extern GPIO_InitTypeDef gpio_handle;
extern RNG_HandleTypeDef rng_handle;
extern TIM_HandleTypeDef timer_handle;
extern TIM_OC_InitTypeDef pwm_handle;
extern UART_HandleTypeDef uart_handle;
extern I2C_HandleTypeDef I2C_handle;

// Calls all non-commented initializers----------------------------------------------------------------------
void init_ALL();

// Internal initializers-------------------------------------------------------------------------------------
void init_User_Button();
void init_User_LED();
void init_LCD();
void init_Touchscreen();
void init_RNG();
void init_Timer();
void init_PWM();
void init_UART();
void init_I2C();

// External initializers-------------------------------------------------------------------------------------
void init_Analog_Pins();
void init_Digital_Pins();
void init_External_Button();
void init_LED_Matrix();

// Interrupt initializers------------------------------------------------------------------------------------
void init_User_Button_as_Interrupt();
void init_External_Button_as_Interrupt();
void init_Touchscreen_as_Interrupt();
void init_Timer_as_Interrupt();
void init_UART_as_Interrupt();

// Interrupt Handles-----------------------------------------------------------------------------------------
void EXTI4_IRQHandler();
void EXTI15_10_IRQHandler();
void TIM2_IRQHandler(void);

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

// Other necessities-----------------------------------------------------------------------------------------
static void Error_Handler();
static void SystemClock_Config();

#endif
