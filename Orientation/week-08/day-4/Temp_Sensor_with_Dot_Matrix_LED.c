#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

#define MATRIX_ADDRESS (0b1110000 << 1)
#define TEMP_SENSOR_ADDRESS (0b1001000 << 1)

void init_MATRIX();
void gpoi_init();
void i2c_init();
void light_up(uint8_t number);


I2C_HandleTypeDef I2C_handle;
GPIO_InitTypeDef gpio_init;

uint8_t read_temp_reg = 0;
uint8_t read_temp_val;

const uint8_t digits[][8] = {
			{ 0x0e, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e },    //0
	        { 0x04, 0x06, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0e },    //1
	        { 0x0e, 0x11, 0x10, 0x10, 0x08, 0x04, 0x02, 0x1f },    //2
	        { 0x0e, 0x11, 0x10, 0x0c, 0x10, 0x10, 0x11, 0x0e },    //3
	        { 0x10, 0x18, 0x14, 0x12, 0x11, 0x1f, 0x10, 0x10 },    //4
	        { 0x1f, 0x01, 0x01, 0x0f, 0x10, 0x10, 0x11, 0x0e },    //5
	        { 0x0e, 0x11, 0x01, 0x0f, 0x11, 0x11, 0x11, 0x0e },    //6
	        { 0x1f, 0x10, 0x10, 0x08, 0x04, 0x02, 0x02, 0x02 },    //7
	        { 0x0e, 0x11, 0x11, 0x0e, 0x11, 0x11, 0x11, 0x0e },    //8
	        { 0x0e, 0x11, 0x11, 0x11, 0x1e, 0x10, 0x11, 0x0e },    //9
			{ 0x60, 0x60, 0x1e, 0x33, 0x81, 0x81, 0x33, 0x1e },    //C
			{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }     //empty
	};

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	i2c_init();
	gpoi_init();
	init_MATRIX();

	while (1) {

		HAL_I2C_Master_Transmit(&I2C_handle, TEMP_SENSOR_ADDRESS, &read_temp_reg, sizeof(read_temp_reg), 100);
		HAL_I2C_Master_Receive(&I2C_handle, TEMP_SENSOR_ADDRESS, &read_temp_val, sizeof(read_temp_val), 100);

		light_up(read_temp_val / 10);
		HAL_Delay(1000);


		light_up(read_temp_val % 10);
		HAL_Delay(1000);

		for (int j = 0; j < 8; j++) {
			HAL_I2C_Mem_Write(&I2C_handle, MATRIX_ADDRESS, j * 2, I2C_MEMADD_SIZE_8BIT, &digits[10][j], 1, 100);
		}
		HAL_Delay(1000);

		for (int j = 0; j < 8; j++) {
			HAL_I2C_Mem_Write(&I2C_handle, MATRIX_ADDRESS, j * 2, I2C_MEMADD_SIZE_8BIT, &digits[11][j], 1, 100);
		}
		HAL_Delay(1000);
	}


}

void init_MATRIX()
{
	uint8_t osc_reg = 0b00100001;   //system clock on
	uint8_t rowint_reg = 0b10100000;   //  ROW/INT register set to ROW
	uint8_t disp_reg = 0b10000001;  // display on, blinking off

	HAL_I2C_Master_Transmit(&I2C_handle, MATRIX_ADDRESS, &osc_reg, sizeof(osc_reg), 100);
	HAL_I2C_Master_Transmit(&I2C_handle, MATRIX_ADDRESS, &rowint_reg, sizeof(rowint_reg), 100);
	HAL_I2C_Master_Transmit(&I2C_handle, MATRIX_ADDRESS, &disp_reg, sizeof(disp_reg), 100);
}

void gpoi_init()
{
	__HAL_RCC_GPIOB_CLK_ENABLE();

	gpio_init.Pin = GPIO_PIN_8 | GPIO_PIN_9;
	gpio_init.Pull = GPIO_PULLUP;
	gpio_init.Mode = GPIO_MODE_AF_OD;
	gpio_init.Alternate = GPIO_AF4_I2C1;
	HAL_GPIO_Init(GPIOB, &gpio_init);
}

void i2c_init()
{
	__HAL_RCC_I2C1_CLK_ENABLE();

	I2C_handle.Instance = I2C1;
	I2C_handle.Init.Timing = 0x40912732;
	I2C_handle.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	HAL_I2C_Init(&I2C_handle);
}

void light_up(uint8_t number)
{
	for (int j = 0; j < 8; j++) {
		HAL_I2C_Mem_Write(&I2C_handle, MATRIX_ADDRESS, j * 2, I2C_MEMADD_SIZE_8BIT, &digits[number][j], 1, 100);
	}
}


//------------------------------------------------------------------------------------------------------------------------------------

static void Error_Handler(void)
{}

void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /**Configure the main internal regulator output voltage */
    __HAL_RCC_PWR_CLK_ENABLE();
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
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
        Error_Handler();
    }
}
