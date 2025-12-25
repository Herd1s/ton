#include "servo.h"

/**
 * @brief  Initialize Servo (Start PWM)
 */
void Servo_Init(void)
{
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
}

/**
 * @brief  Set Servo Angle
 * @param  Channel: TIM_CHANNEL_x (e.g., TIM_CHANNEL_1)
 * @param  Angle: 0.0 to 180.0 degrees
 */
void Servo_SetAngle(uint32_t Channel, float Angle)
{
    uint16_t pulse;

    if (Angle < 0) Angle = 0;
    if (Angle > 180) Angle = 180;

    // Map 0-180 to SERVO_MIN_PULSE-SERVO_MAX_PULSE
    pulse = SERVO_MIN_PULSE + (uint16_t)(Angle * (SERVO_MAX_PULSE - SERVO_MIN_PULSE) / 180.0);

    __HAL_TIM_SET_COMPARE(&htim2, Channel, pulse);
}
