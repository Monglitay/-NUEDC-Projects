#ifndef __PID_H_
#define __PID_H_

#include "stdint.h"

// 默认参数定义
#define INTEGRAL_LIMIT_DEFAULT 7.4f
#define OUTPUT_LIMIT_DEFAULT 7.4f
#define ERROR_DEADZONE_DEFAULT 0.01f
#define OUTPUT_DEADZONE_DEFAULT 0.05f

typedef struct {
    // 基本PID参数
    float kp;           // 比例系数
    float ki;           // 积分系数
    float kd;           // 微分系数
    float sp;           // 设定值
    
    // 误差相关
    float err;          // 当前误差
    float last_err;     // 上一次误差
    float last2_err;    // 上上次误差
    
    // 输出
    float co;           // 控制输出
    
    // 积分累积值跟踪
    float integral_sum; // 积分累积值
    
    // 限制参数
    float integral_max; // 积分上限
    float integral_min; // 积分下限
    float max_output;   // 输出上限
    float min_output;   // 输出下限
    
    // 死区参数
    float error_deadzone;   // 误差死区
    float output_deadzone;  // 输出死区
    
    // 控制标志
    uint8_t enable_integral_limit;  // 积分限幅使能
    uint8_t enable_output_limit;    // 输出限幅使能
    uint8_t enable_error_deadzone;  // 误差死区使能
    uint8_t enable_output_deadzone; // 输出死区使能
    
} PID_Typedef;

// 基本函数
void PID_Init(PID_Typedef *PIDx, float kp, float ki, float kd);
void PID_Init_Advanced(PID_Typedef *PIDx, float kp, float ki, float kd, 
                      float integral_limit, float output_limit, 
                      float error_deadzone, float output_deadzone);

// PID计算函数
float PID_Compute(PID_Typedef *PIDx, float fb);
float PID_Compute_Direction(PID_Typedef *PIDx, float fb);
float PID_Compute_AntiWindup(PID_Typedef *PIDx, float fb);

// 参数设置函数
void PID_SetParams(PID_Typedef *PIDx, float kp, float ki, float kd);
void PID_SetIntegralLimit(PID_Typedef *PIDx, float limit);
void PID_SetOutputLimit(PID_Typedef *PIDx, float max_out, float min_out);
void PID_SetErrorDeadzone(PID_Typedef *PIDx, float deadzone);
void PID_SetOutputDeadzone(PID_Typedef *PIDx, float deadzone);

// 控制函数
void PID_ChangeSP(PID_Typedef *PIDx, float sp);
void PID_Reset(PID_Typedef *PIDx);
void PID_Limit(float *value, float upper, float lower);

// 使能控制函数
void PID_EnableIntegralLimit(PID_Typedef *PIDx, uint8_t enable);
void PID_EnableOutputLimit(PID_Typedef *PIDx, uint8_t enable);
void PID_EnableErrorDeadzone(PID_Typedef *PIDx, uint8_t enable);
void PID_EnableOutputDeadzone(PID_Typedef *PIDx, uint8_t enable);

// 获取状态函数
float PID_GetError(PID_Typedef *PIDx);
float PID_GetOutput(PID_Typedef *PIDx);
float PID_GetSetpoint(PID_Typedef *PIDx);
float PID_GetIntegralSum(PID_Typedef *PIDx);

// 积分控制函数
void PID_SetIntegralSum(PID_Typedef *PIDx, float integral_value);
void PID_ClearIntegral(PID_Typedef *PIDx);

#endif
