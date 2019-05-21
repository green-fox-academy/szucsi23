/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <string.h>

int main(void)
{
	HAL_Init();

	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

	BSP_LED_Init(LED1);

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

	char text[] = "sos";
	char code[100];
	strcpy(code, " ");

	for (int i = 0; text[i] != '\0'; i++) {
		for (int j = 0; j < 37; j++) {
			if (text[i] == letters[j]) {
				strcat(code, morse[j]);
			}
		}
	}
	strcat(code, "\0");

	while (1) {

		if (BSP_PB_GetState(BUTTON_KEY) == 1) {

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
}

