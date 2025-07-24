// 在 app_encoder.h 中添加以下宏定义
#ifndef APP_ENCODER_H
#define APP_ENCODER_H

#include <stdint.h>
#include <stdbool.h>
#include <math.h>

// 添加数学常数定义（如果没有的话）
#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

// 编码器物理参数配置
#define ENCODER_LINES           11.0f       // 编码器线数
#define MOTOR_GEAR_RATIO        20.41f      // 电机减速比
#define ENCODER_LINES_AFTER_GEAR 224.51f    // 减速后编码器线数 (11 * 20.41)
#define ENCODER_SAMPLE_FREQ     50.0f     // 编码器采样频率 Hz (请根据你的定时器频率修改)

// 转换系数计算
// 四倍频解码：每线4个脉冲，所以减速后每转总脉冲数 = 224.51 * 4
#define PULSES_PER_OUTPUT_REV   (ENCODER_LINES_AFTER_GEAR * 4.0f)  // 输出轴每转的脉冲数
#define RAD_PER_PULSE          (2.0f * M_PI / PULSES_PER_OUTPUT_REV)     // 每个脉冲对应的弧度
#define RAD_PER_SEC_PER_PULSE  (RAD_PER_PULSE * ENCODER_SAMPLE_FREQ)     // 速度转换系数

// 函数声明
void Encoder_Init(void);
int32_t Encoder_Get_L_Speed_Raw(void);
int32_t Encoder_Get_R_Speed_Raw(void);
int32_t Encoder_Get_L_Integral_Raw(void);
int32_t Encoder_Get_R_Integral_Raw(void);

// 新增的物理单位函数
float Encoder_Get_L_Speed_RadPerSec(void);
float Encoder_Get_R_Speed_RadPerSec(void);
float Encoder_Get_L_Position_Rad(void);
float Encoder_Get_R_Position_Rad(void);
void Encoder_Reset_Position(void);

// 调试和配置函数
int32_t Encoder_Get_L_Count(void);
int32_t Encoder_Get_R_Count(void);
void Encoder_Print_Config(void);

#endif
