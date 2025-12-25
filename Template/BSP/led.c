#include "led.h"

/**
 * @brief  Initialize LED
 * @note   GPIO initialization is usually done in main.c -> MX_GPIO_Init
 *         This function can be used for specific LED setup if needed.
 */
void LED_Init(void)
{
    // GPIO Initialization is handled in gpio.c / MX_GPIO_Init
    // We can ensure the LED is in a known state here
    LED_Off();
}

/**
 * @brief  Turn LED On
 * @note   Assumes Active Low (Common for PC13 on BluePill)
 */
void LED_On(void)
{
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
}

/**
 * @brief  Turn LED Off
 */
void LED_Off(void)
{
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
}

/**
 * @brief  Toggle LED
 */
void LED_Toggle(void)
{
    HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
}
