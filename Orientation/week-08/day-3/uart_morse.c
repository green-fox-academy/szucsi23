#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

UART_HandleTypeDef uart_handle;

volatile uint8_t buffer = 0;
volatile uint8_t *text;

void text_to_morse(char* text);
void reset_text();

void init_uart()
{
	__HAL_RCC_USART1_CLK_ENABLE()
	;

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

int main(void)
{
	HAL_Init();
	init_uart();
	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
	BSP_LED_Init(LED1);

	char code[100];

	text = calloc(1, 1);

	HAL_UART_Receive_IT(&uart_handle, &buffer, 1);

	while (1) {

			if (BSP_PB_GetState(BUTTON_KEY) == 1) {
				uint32_t time = HAL_GetTick();
				while(BSP_PB_GetState(BUTTON_KEY) == 1) {
					uint32_t elapsed = (HAL_GetTick() - time);
					if (elapsed > 3000) {
						reset_text();
						code[0] = '\0';
					}
				}

				text_to_morse(code);

				for (int i = 0; code[i] != '\0'; ++i) {

					if (code[i] == '.') {
						BSP_LED_On(LED1);
						HAL_Delay(200);
						BSP_LED_Off(LED1);
						HAL_Delay(400);
					} else if (code[i] == '-') {
						BSP_LED_On(LED1);
						HAL_Delay(800);
						BSP_LED_Off(LED1);
						HAL_Delay(400);
					} else if (code[i] == ' ') {
						HAL_Delay(600);
					}
				}
			}

		}

	free(text);
	return 0;
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
}

void text_to_morse(char* code)
{
	char letters[37] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
			'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
			'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' ' };

	char morse[37][10] = { { ".- " }, { "-... " }, { "-.-. " }, { "-.. " }, {
			". " }, { "..-. " }, { "--. " }, { ".... " }, { ".. " },
			{ ".--- " }, { "-.- " }, { ".-.. " }, { "-- " }, { "-. " },
			{ "--- " }, { ".--. " }, { "--.- " }, { ".-. " }, { "... " },
			{ "- " }, { "..- " }, { "...- " }, { ".-- " }, { "-..- " }, {
					"-.-- " }, { "--.. " }, { ".---- " }, { "..--- " }, {
					"...-- " }, { "....- " }, { "..... " }, { "-.... " }, {
					"--... " }, { "---.. " }, { "---. " }, { "----- " },
			{ "// " } };


	strcpy(code, " ");

	for (int i = 0; text[i] != '\0'; i++) {
		for (int j = 0; j < 37; j++) {
			if (text[i] == letters[j]) {
				strcat(code, morse[j]);
			}
		}
	}
	strcat(code, "\0");
}

void reset_text()
{
	free(text);
	text = calloc(1, 1);

	for (int i = 0; i < 5; ++i) {
		BSP_LED_On(LED1);
		HAL_Delay(100);
		BSP_LED_Off(LED1);
		HAL_Delay(100);
	}
}

