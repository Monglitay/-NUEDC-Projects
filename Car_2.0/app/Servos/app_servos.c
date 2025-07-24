
#include "app_servos.h"
#include "app_jy61p.h"
#include "sys_broad_init.h"
void Servos_Init()
{
    Servo_InitTypedef Servo_InitStruct;
    Servo_InitStruct.gpio_servo_cx_idx = GPIO_Servo_1_C0_IDX;
    Servo_InitStruct.servo_inst = Servo_1_INST;
    Servo_InitStruct.timer = TIMERA;
    Servo_InitStruct.max_angle = 140;
    Servo_InitStruct.min_angle = 40;

    Servo_Init(&Turning_Servo, &Servo_InitStruct);
    Servo_Set_Angle(&Turning_Servo, 99);
    Turning_Angle = 99;
    UtrSnd_Angel = 0;
}
void Turning_Servo_Control()
{
    float diff_angle = PID_Compute(&PID_Turning,Gyro_Structure.z);
    Turning_Angle = 99 - diff_angle;
    Servo_Set_Angle(&Turning_Servo, Turning_Angle);
}
void Turning_Servo_Set_Angle(float sp)
{
    PID_ChangeSP(&PID_Turning,sp);
}
void Servos_Proc()
{
    Turning_Servo_Control();
}