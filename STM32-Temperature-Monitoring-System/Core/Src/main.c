#include "main.h"
#include <stdio.h>
#include <string.h>

ADC_HandleTypeDef hadc1;
UART_HandleTypeDef huart2;

uint32_t adc_value;
char msg[100];

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_USART2_UART_Init(void);

int main(void)
{
  HAL_Init();
  SystemClock_Config();

  MX_GPIO_Init();
  MX_ADC1_Init(); // Configured for PA0
  MX_USART2_UART_Init(); // Configured for PA2 (TX)

  while (1)
  {
    // 1. Start ADC conversion on PA0
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    adc_value = HAL_ADC_GetValue(&hadc1);

    // 2. Conversion Logic: 12-bit ADC (4095) with 3.3V Vref
    float voltage = (adc_value * 3.3f) / 4095.0f;
    float temperature = voltage * 100.0f; // 10mV/C scaling for LM35

    // 3. Control LED (PA5) and Format Message
    if (temperature > 30.0f) {
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
      sprintf(msg, "Temp: %.2f C -> LED ON\r\n", temperature);
    } else {
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
      sprintf(msg, "Temp: %.2f C\r\n", temperature);
    }

    // 4. Transmit via UART2 (PA2)
    HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

    HAL_Delay(1000); // 1-second sampling rate
  }
}
