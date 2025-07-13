#include "servo.h"

void Servo_Init(Servo_Typedef *Servo,Servo_InitTypedef *Servo_InitStruct)
{
    Servo->servo_inst = Servo_InitStruct->servo_inst;
    Servo->gpio_servo_cx_idx = Servo_InitStruct->gpio_servo_cx_idx;
    Servo->timer = Servo_InitStruct->timer;
    Servo->angle = 0;
    Servo->min_count = PERIOD*(0.5/20);
    Servo->max_count = PERIOD*(10/20);
    Servo->range = Servo->max_count - Servo->min_count;
}

void Servo_Set_Angle(Servo_Typedef *Servo,float angle)
{
    if(angle > 180) angle = 180;
    if(angle < 0 ) angle = 0;
    float ServoAngle = Servo->min_count + (((float)angle / 180.0f) * Servo->range);
    if(Servo->timer == TIMERG)
        DL_TimerG_setCaptureCompareValue(Servo->servo_inst,(unsigned int)(ServoAngle + 0.5f),Servo->gpio_servo_cx_idx);
    else if(Servo->timer == TIMERA)
        DL_TimerA_setCaptureCompareValue(Servo->servo_inst,(unsigned int)(ServoAngle + 0.5f),Servo->gpio_servo_cx_idx);
}