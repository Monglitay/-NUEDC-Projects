#ifndef __APP_SERVOS_H_
#define __APP_SERVOS_H_
#include "app_motor.h"
#include "servo.h"
Servo_Typedef UtrSnd_Servo;
Servo_Typedef Turning_Servo;
float Turning_Angle;
float UtrSnd_Angel;
void Turning_Servo_Set_Angle(float sp);

void Servos_Init();
void Servos_Proc();
#endif
