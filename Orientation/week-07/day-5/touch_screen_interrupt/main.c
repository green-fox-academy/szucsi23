#include "initializers.c"

#define WIDTH 480
#define HEIGHT 272

volatile int reset = 0;
volatile uint8_t counter_changed = 0;
RNG_HandleTypeDef rng_handle;

void init_all();
int setup();

int main(void)
{
	init_all();

	TS_StateTypeDef ts_state;


	char clock_buffer[3] = {0,0,0};

	while (1) {

		int clock = setup();
		BSP_LCD_DisplayStringAt(79, 10, "Touch the screen, when the timer reaches Zero!", LEFT_MODE);

		for (; clock > 0; clock--) {

		}


		BSP_TS_GetState(&ts_state);
		if (ts_state.touchDetected) {
			counter_changed = 0;
			//BSP_LCD_Clear(0x00000000);
			BSP_LCD_DrawCircle(ts_state.touchX[0], ts_state.touchY[0], 50);

		}
		while(reset != 1){}
	}
}

void init_all()
{;
	HAL_Init();
		SystemClock_Config();
		__HAL_RCC_RNG_CLK_ENABLE();

		LCD_init();
		TS_init();
		PB_init();
		rng_handle.Instance = RNG;
		HAL_RNG_Init(&rng_handle);

}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	reset = 1;

}

int setup()
{
	reset = 0;
	int wait = (HAL_RNG_GetRandomNumber(&rng_handle) % 25)+5;
	return wait;
}


