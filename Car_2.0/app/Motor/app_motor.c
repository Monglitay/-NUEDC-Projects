#include "app_motor.h"
#include "sys_broad_init.h"
#include "app_encoder.h"
#include "app_AT8236.h"
#include "app_adc.h"
#include "app_jy61p.h"
#define IF_SPEED_ZERO(speed) ((speed) >= -1 && (speed) <= 1)

static float target_speed_l;
static float target_speed_r;
static float omeg_l;
static float omeg_r;
static float voltage_l;
static float voltage_r;
static float duty_l;
static float duty_r;
uint8_t tracking_flag;
// 电机控制初始化
void Motor_Init(void)
{
    Encoder_Init();
    tracking_flag = 0;
    target_speed_l = 0;
    target_speed_r = 0;
    omeg_l = 0;
    omeg_r = 0;
}
void Motor_Control_L(float target_speed)
{
    if(IF_SPEED_ZERO(target_speed))
    {
        PID_Reset(&PID_MotorSpeed_L);
        AT8236_BOUT_Stop();
        return;
    }
        omeg_l = Encoder_Get_L_Speed_RadPerSec();
        PID_ChangeSP(&PID_MotorSpeed_L, target_speed);
        voltage_l = PID_Compute(&PID_MotorSpeed_L, omeg_l);
        duty_l = voltage_l/ADC_GetValue()*1000;
            AT8236_BOUT_FD(duty_l);
}

void Motor_Control_R(float target_speed)
{
    if(IF_SPEED_ZERO(target_speed))
    {
        PID_Reset(&PID_MotorSpeed_R);
        AT8236_AOUT_Stop();
        return;
    }
        omeg_r =  Encoder_Get_R_Speed_RadPerSec();
        PID_ChangeSP(&PID_MotorSpeed_R, target_speed);
        voltage_r = PID_Compute(&PID_MotorSpeed_R, omeg_r);
        duty_r = (voltage_r/ADC_GetValue())*1000;
            AT8236_AOUT_FD(duty_r);
}
// 设置左电机目标速度
void Motor_SetSpeed_L(float speed)
{
    target_speed_l = speed;
}

// 设置右电机目标速度
void Motor_SetSpeed_R(float speed)
{
    target_speed_r = speed;
}

// 电机周期性控制处理
void Motor_Proc(void)
{
    Motor_Control_L(target_speed_l);
    Motor_Control_R(target_speed_r);
}