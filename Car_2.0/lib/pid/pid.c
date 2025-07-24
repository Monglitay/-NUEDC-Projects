#include "pid.h"
#include "math.h"
#include "stdio.h"

/**
 * @brief 基本PID初始化
 * @param PIDx PID控制器结构体指针
 * @param kp 比例系数
 * @param ki 积分系数
 * @param kd 微分系数
 */
void PID_Init(PID_Typedef *PIDx, float kp, float ki, float kd)
{
    // 基本参数
    PIDx->kp = kp;
    PIDx->ki = ki;
    PIDx->kd = kd;
    PIDx->sp = 0.0f;
    
    // 误差初始化
    PIDx->err = 0.0f;
    PIDx->last_err = 0.0f;
    PIDx->last2_err = 0.0f;
    PIDx->co = 0.0f;
    
    // 积分累积值初始化
    PIDx->integral_sum = 0.0f;
    
    // 默认限制参数
    PIDx->integral_max = INTEGRAL_LIMIT_DEFAULT;
    PIDx->integral_min = -INTEGRAL_LIMIT_DEFAULT;
    PIDx->max_output = OUTPUT_LIMIT_DEFAULT;
    PIDx->min_output = -OUTPUT_LIMIT_DEFAULT;
    
    // 默认死区参数
    PIDx->error_deadzone = ERROR_DEADZONE_DEFAULT;
    PIDx->output_deadzone = OUTPUT_DEADZONE_DEFAULT;
    
    // 默认使能状态
    PIDx->enable_integral_limit = 1;
    PIDx->enable_output_limit = 1;
    PIDx->enable_error_deadzone = 0;
    PIDx->enable_output_deadzone = 0;
}

/**
 * @brief 高级PID初始化
 * @param PIDx PID控制器结构体指针
 * @param kp 比例系数
 * @param ki 积分系数
 * @param kd 微分系数
 * @param integral_limit 积分限制
 * @param output_limit 输出限制
 * @param error_deadzone 误差死区
 * @param output_deadzone 输出死区
 */
void PID_Init_Advanced(PID_Typedef *PIDx, float kp, float ki, float kd, 
                      float integral_limit, float output_limit, 
                      float error_deadzone, float output_deadzone)
{
    PID_Init(PIDx, kp, ki, kd);
    
    PIDx->integral_max = integral_limit;
    PIDx->integral_min = -integral_limit;
    PIDx->max_output = output_limit;
    PIDx->min_output = -output_limit;
    PIDx->error_deadzone = error_deadzone;
    PIDx->output_deadzone = output_deadzone;
    
    // 高级初始化默认开启所有功能
    PIDx->enable_integral_limit = 1;
    PIDx->enable_output_limit = 1;
    PIDx->enable_error_deadzone = 1;
    PIDx->enable_output_deadzone = 1;
}

/**
 * @brief 标准PID计算（修正版）
 * @param PIDx PID控制器结构体指针
 * @param fb 反馈值
 * @return 控制输出
 */
float PID_Compute(PID_Typedef *PIDx, float fb)
{
    // 计算误差
    PIDx->err = PIDx->sp - fb;
    
    // 误差死区处理
    if(PIDx->enable_error_deadzone && fabs(PIDx->err) < PIDx->error_deadzone) {
        PIDx->err = 0.0f;
    }
    
    // 计算比例项增量
    float delta_p = PIDx->kp * (PIDx->err - PIDx->last_err);
    
    // 计算积分项增量（先不限幅）
    float delta_i = PIDx->ki * PIDx->err;
    
    // 积分限幅处理 - 正确的方式
    if(PIDx->enable_integral_limit) {
        float temp_integral = PIDx->integral_sum + delta_i;
        
        // 限制积分累积值
        if(temp_integral > PIDx->integral_max) {
            temp_integral = PIDx->integral_max;
            delta_i = temp_integral - PIDx->integral_sum;  // 重新计算delta_i
        } else if(temp_integral < PIDx->integral_min) {
            temp_integral = PIDx->integral_min;
            delta_i = temp_integral - PIDx->integral_sum;  // 重新计算delta_i
        }
        
        // 更新积分累积值
        PIDx->integral_sum = temp_integral;
    } else {
        // 不限幅时直接累积
        PIDx->integral_sum += delta_i;
    }
    
    // 计算微分项增量
    float delta_d = PIDx->kd * (PIDx->err - 2 * PIDx->last_err + PIDx->last2_err);
    
    // 更新控制输出
    PIDx->co += delta_p + delta_i + delta_d;
    
    // 输出限幅
    if(PIDx->enable_output_limit) {
        PID_Limit(&PIDx->co, PIDx->max_output, PIDx->min_output);
    }
    
    // 输出死区处理
    if(PIDx->enable_output_deadzone && fabs(PIDx->co) <= PIDx->output_deadzone) {
        PIDx->co = 0.0f;
    }
    
    // 更新误差历史
    PIDx->last2_err = PIDx->last_err;
    PIDx->last_err = PIDx->err;
    
    return PIDx->co;
}

/**
 * @brief 方向PID计算（处理角度环绕）
 * @param PIDx PID控制器结构体指针
 * @param fb 反馈角度值
 * @return 控制输出
 */
float PID_Compute_Direction(PID_Typedef *PIDx, float fb)
{
    // 计算原始误差
    float raw_error = PIDx->sp - fb;
    
    // 角度误差规范化到[-180°, 180°]
    while(raw_error > 180.0f) raw_error -= 360.0f;
    while(raw_error <= -180.0f) raw_error += 360.0f;
    
    PIDx->err = raw_error;
    
    // 误差死区处理
    if(PIDx->enable_error_deadzone && fabs(PIDx->err) < PIDx->error_deadzone) {
        PIDx->err = 0.0f;
    }
    
    // 计算比例项增量
    float delta_p = PIDx->kp * (PIDx->err - PIDx->last_err);
    
    // 计算积分项增量
    float delta_i = PIDx->ki * PIDx->err;
    
    // 积分限幅处理
    if(PIDx->enable_integral_limit) {
        float temp_integral = PIDx->integral_sum + delta_i;
        
        if(temp_integral > PIDx->integral_max) {
            temp_integral = PIDx->integral_max;
            delta_i = temp_integral - PIDx->integral_sum;
        } else if(temp_integral < PIDx->integral_min) {
            temp_integral = PIDx->integral_min;
            delta_i = temp_integral - PIDx->integral_sum;
        }
        
        PIDx->integral_sum = temp_integral;
    } else {
        PIDx->integral_sum += delta_i;
    }
    
    // 计算微分项增量
    float delta_d = PIDx->kd * (PIDx->err - 2 * PIDx->last_err + PIDx->last2_err);
    
    // 更新控制输出
    PIDx->co += delta_p + delta_i + delta_d;
    
    // 输出限幅
    if(PIDx->enable_output_limit) {
        PID_Limit(&PIDx->co, PIDx->max_output, PIDx->min_output);
    }
    
    // 输出死区处理
    if(PIDx->enable_output_deadzone && fabs(PIDx->co) <= PIDx->output_deadzone) {
        PIDx->co = 0.0f;
    }
    
    // 更新误差历史
    PIDx->last2_err = PIDx->last_err;
    PIDx->last_err = PIDx->err;
    
    return PIDx->co;
}

/**
 * @brief 抗积分饱和PID计算
 * @param PIDx PID控制器结构体指针
 * @param fb 反馈值
 * @return 控制输出
 */
float PID_Compute_AntiWindup(PID_Typedef *PIDx, float fb)
{
    // 计算误差
    PIDx->err = PIDx->sp - fb;
    
    // 误差死区处理
    if(PIDx->enable_error_deadzone && fabs(PIDx->err) < PIDx->error_deadzone) {
        PIDx->err = 0.0f;
    }
    
    // 计算各项增量
    float delta_p = PIDx->kp * (PIDx->err - PIDx->last_err);
    float delta_i = PIDx->ki * PIDx->err;
    float delta_d = PIDx->kd * (PIDx->err - 2 * PIDx->last_err + PIDx->last2_err);
    
    // 计算未限幅的输出
    float temp_output = PIDx->co + delta_p + delta_i + delta_d;
    
    // 抗积分饱和处理
    if(PIDx->enable_output_limit) {
        if(temp_output > PIDx->max_output || temp_output < PIDx->min_output) {
            // 输出饱和时，减少或停止积分累积
            if((PIDx->err > 0 && temp_output > PIDx->max_output) ||
               (PIDx->err < 0 && temp_output < PIDx->min_output)) {
                delta_i = 0;  // 停止积分累积
            }
        }
    }
    
    // 积分限幅处理
    if(PIDx->enable_integral_limit) {
        float temp_integral = PIDx->integral_sum + delta_i;
        
        if(temp_integral > PIDx->integral_max) {
            temp_integral = PIDx->integral_max;
            delta_i = temp_integral - PIDx->integral_sum;
        } else if(temp_integral < PIDx->integral_min) {
            temp_integral = PIDx->integral_min;
            delta_i = temp_integral - PIDx->integral_sum;
        }
        
        PIDx->integral_sum = temp_integral;
    } else {
        PIDx->integral_sum += delta_i;
    }
    
    // 更新控制输出
    PIDx->co += delta_p + delta_i + delta_d;
    
    // 输出限幅
    if(PIDx->enable_output_limit) {
        PID_Limit(&PIDx->co, PIDx->max_output, PIDx->min_output);
    }
    
    // 输出死区处理
    if(PIDx->enable_output_deadzone && fabs(PIDx->co) <= PIDx->output_deadzone) {
        PIDx->co = 0.0f;
    }
    
    // 更新误差历史
    PIDx->last2_err = PIDx->last_err;
    PIDx->last_err = PIDx->err;
    
    return PIDx->co;
}

/**
 * @brief 设置PID参数
 * @param PIDx PID控制器结构体指针
 * @param kp 比例系数
 * @param ki 积分系数
 * @param kd 微分系数
 */
void PID_SetParams(PID_Typedef *PIDx, float kp, float ki, float kd)
{
    PIDx->kp = kp;
    PIDx->ki = ki;
    PIDx->kd = kd;
}

/**
 * @brief 设置积分限制
 * @param PIDx PID控制器结构体指针
 * @param limit 积分限制值
 */
void PID_SetIntegralLimit(PID_Typedef *PIDx, float limit)
{
    PIDx->integral_max = limit;
    PIDx->integral_min = -limit;
}

/**
 * @brief 设置输出限制
 * @param PIDx PID控制器结构体指针
 * @param max_out 最大输出值
 * @param min_out 最小输出值
 */
void PID_SetOutputLimit(PID_Typedef *PIDx, float max_out, float min_out)
{
    PIDx->max_output = max_out;
    PIDx->min_output = min_out;
}

/**
 * @brief 设置误差死区
 * @param PIDx PID控制器结构体指针
 * @param deadzone 误差死区值
 */
void PID_SetErrorDeadzone(PID_Typedef *PIDx, float deadzone)
{
    PIDx->error_deadzone = deadzone;
}

/**
 * @brief 设置输出死区
 * @param PIDx PID控制器结构体指针
 * @param deadzone 输出死区值
 */
void PID_SetOutputDeadzone(PID_Typedef *PIDx, float deadzone)
{
    PIDx->output_deadzone = deadzone;
}

/**
 * @brief 改变设定值
 * @param PIDx PID控制器结构体指针
 * @param sp 新设定值
 */
void PID_ChangeSP(PID_Typedef *PIDx, float sp)
{
    PIDx->sp = sp;
}

/**
 * @brief 重置PID控制器
 * @param PIDx PID控制器结构体指针
 */
void PID_Reset(PID_Typedef *PIDx)
{
    PIDx->integral_sum = 0.0f;
    PIDx->co = 0.0f;
    PIDx->last_err = 0.0f;
    PIDx->last2_err = 0.0f;
}

/**
 * @brief 限制输出值
 * @param value 指向需要限制的值的指针
 * @param upper 上限
 * @param lower 下限
 */
void PID_Limit(float *value, float upper, float lower)
{
    if(*value > upper) {
        *value = upper;
    } else if(*value < lower) {
        *value = lower;
    }
}

/**
 * @brief 使能积分限制
 * @param PIDx PID控制器结构体指针
 * @param enable 使能状态
 */
void PID_EnableIntegralLimit(PID_Typedef *PIDx, uint8_t enable)
{
    PIDx->enable_integral_limit = enable;
}

/**
 * @brief 使能输出限制
 * @param PIDx PID控制器结构体指针
 * @param enable 使能状态
 */
void PID_EnableOutputLimit(PID_Typedef *PIDx, uint8_t enable)
{
    PIDx->enable_output_limit = enable;
}

/**
 * @brief 使能误差死区
 * @param PIDx PID控制器结构体指针
 * @param enable 使能状态
 */
void PID_EnableErrorDeadzone(PID_Typedef *PIDx, uint8_t enable)
{
    PIDx->enable_error_deadzone = enable;
}

/**
 * @brief 使能输出死区
 * @param PIDx PID控制器结构体指针
 * @param enable 使能状态
 */
void PID_EnableOutputDeadzone(PID_Typedef *PIDx, uint8_t enable)
{
    PIDx->enable_output_deadzone = enable;
}

/**
 * @brief 获取当前误差
 * @param PIDx PID控制器结构体指针
 * @return 当前误差
 */
float PID_GetError(PID_Typedef *PIDx)
{
    return PIDx->err;
}

/**
 * @brief 获取当前输出
 * @param PIDx PID控制器结构体指针
 * @return 当前控制输出
 */
float PID_GetOutput(PID_Typedef *PIDx)
{
    return PIDx->co;
}

/**
 * @brief 获取设定值
 * @param PIDx PID控制器结构体指针
 * @return 当前设定值
 */
float PID_GetSetpoint(PID_Typedef *PIDx)
{
    return PIDx->sp;
}

/**
 * @brief 获取积分累积值
 * @param PIDx PID控制器结构体指针
 * @return 积分累积值
 */
float PID_GetIntegralSum(PID_Typedef *PIDx)
{
    return PIDx->integral_sum;
}

/**
 * @brief 设置积分累积值
 * @param PIDx PID控制器结构体指针
 * @param integral_value 积分值
 */
void PID_SetIntegralSum(PID_Typedef *PIDx, float integral_value)
{
    PIDx->integral_sum = integral_value;
}

/**
 * @brief 清除积分
 * @param PIDx PID控制器结构体指针
 */
void PID_ClearIntegral(PID_Typedef *PIDx)
{
    PIDx->integral_sum = 0.0f;
}

/**
 * @brief 调试信息输出
 * @param PIDx PID控制器结构体指针
 * @param name 控制器名称
 */

