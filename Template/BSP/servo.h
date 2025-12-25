#ifndef __SERVO_H
#define __SERVO_H

#include "main.h"
#include "tim.h"

// Servo parameters
#define SERVO_MIN_PULSE 500  // 0.5ms = 0 degrees
#define SERVO_MAX_PULSE 2500 // 2.5ms = 180 degrees

void Servo_Init(void);
void Servo_SetAngle(uint32_t Channel, float Angle);

#endif
