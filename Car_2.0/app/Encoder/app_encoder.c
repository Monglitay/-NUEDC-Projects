#include "app_encoder.h"
#include "app_AT8236.h"
#include "app_jy61p.h"
// 编码器相关全局变量
volatile uint32_t Encoder_L_State, Encoder_R_State;      // 左右编码器端口状态
volatile int32_t Encoder_L_CNT, Encoder_R_CNT;         // 左右编码器计数值
volatile int32_t Encoder_L_VEL, Encoder_R_VEL;         // 左右马达速度
volatile int32_t Encoder_L_INT, Encoder_R_INT;          // 左右编码器积分
GPIO_Regs *Encoder_R_Port;
GPIO_Regs *Encoder_L_Port;

/**
 * @brief 初始化编码器
 * 
 * 该函数关闭所有电机输出，并使能编码器相关的中断
 */
void Encoder_Init(void)
{
    AT8236_AOUT_FD(0);
    AT8236_BOUT_FD(0);
    /* 使能编码器相关中断 */
    NVIC_EnableIRQ(Encoder_GPIOA_INT_IRQN);
    NVIC_EnableIRQ(Encoder_GPIOB_INT_IRQN);
    //NVIC_EnableIRQ(TIMER_Encoder_Update_INST_INT_IRQN);
    //DL_Timer_startCounter(TIMER_Encoder_Update_INST);
    Encoder_R_Port = GPIOA;
    Encoder_L_Port = GPIOB;
    Encoder_L_INT = 0;
    Encoder_R_INT = 0; 
    
}

/**
 * @brief 编码器读取中断服务函数
 * 
 * 该函数在定时器中断触发时调用，用于读取和重置编码器计数值
 */
void TIMER_Encoder_Update_INST_IRQHandler(void)
{
    switch (DL_TimerG_getPendingInterrupt(TIMER_Encoder_Update_INST)){
        case DL_TIMER_IIDX_ZERO:
            // 更新速度值并重置计数器
            Encoder_L_VEL = Encoder_L_CNT;
            Encoder_L_CNT = 0;
            Encoder_R_VEL = Encoder_R_CNT;
            Encoder_R_CNT = 0;
            break;
        default:
            break;
    }
}

/**
 * @brief 编码器GPIO中断处理函数
 * 
 * 该函数处理编码器A和B的GPIO中断，更新编码器计数值
 * 使用改进的四倍频解码算法
 */
void GROUP1_IRQHandler(void)
{
    // 获取左右编码器的中断状态
    Encoder_L_State = DL_GPIO_getEnabledInterruptStatus(Encoder_L_Port, Encoder_L_A_PIN | Encoder_L_B_PIN);
    Encoder_R_State = DL_GPIO_getEnabledInterruptStatus(Encoder_R_Port, Encoder_R_A_PIN | Encoder_R_B_PIN);
    
    /* 处理左编码器 - 改进的解码逻辑 */
    if(Encoder_L_State & Encoder_L_A_PIN)
    {
        // A相中断：读取当前A、B相状态
        bool A_state = DL_GPIO_readPins(Encoder_L_Port, Encoder_L_A_PIN);
        bool B_state = DL_GPIO_readPins(Encoder_L_Port, Encoder_L_B_PIN);
        
        if(A_state ^ B_state) {  // A和B状态不同 - 正转
            Encoder_L_CNT++; 
            Encoder_L_INT++;
        } else {  // A和B状态相同 - 反转
            Encoder_L_CNT--; 
            Encoder_L_INT--;
        }
    }
    
    if(Encoder_L_State & Encoder_L_B_PIN)
    {
        // B相中断：读取当前A、B相状态
        bool A_state = DL_GPIO_readPins(Encoder_L_Port, Encoder_L_A_PIN);
        bool B_state = DL_GPIO_readPins(Encoder_L_Port, Encoder_L_B_PIN);
        
        if(A_state ^ B_state) {  // A和B状态不同 - 反转
            Encoder_L_CNT--; 
            Encoder_L_INT--;
        } else {  // A和B状态相同 - 正转
            Encoder_L_CNT++; 
            Encoder_L_INT++;
        }
    }

    /* 处理右编码器 - 使用相同的改进解码逻辑 */
    if(Encoder_R_State & Encoder_R_A_PIN)
    {
        // A相中断：读取当前A、B相状态
        bool A_state = DL_GPIO_readPins(Encoder_R_Port, Encoder_R_A_PIN);
        bool B_state = DL_GPIO_readPins(Encoder_R_Port, Encoder_R_B_PIN);
        
        if(A_state ^ B_state) {  // A和B状态不同 - 正转
            Encoder_R_CNT++; 
            Encoder_R_INT++;
        } else {  // A和B状态相同 - 反转
            Encoder_R_CNT--; 
            Encoder_R_INT--;
        }
    }
    
    if(Encoder_R_State & Encoder_R_B_PIN)
    {
        // B相中断：读取当前A、B相状态
        bool A_state = DL_GPIO_readPins(Encoder_R_Port, Encoder_R_A_PIN);
        bool B_state = DL_GPIO_readPins(Encoder_R_Port, Encoder_R_B_PIN);
        
        if(A_state ^ B_state) {  // A和B状态不同 - 反转
            Encoder_R_CNT--; 
            Encoder_R_INT--;
        } else {  // A和B状态相同 - 正转
            Encoder_R_CNT++; 
            Encoder_R_INT++;
        }
    }
    
    // 清除左编码器中断标志
    DL_GPIO_clearInterruptStatus(Encoder_L_Port, Encoder_L_A_PIN | Encoder_L_B_PIN);
    // 清除右编码器中断标志
    DL_GPIO_clearInterruptStatus(Encoder_R_Port, Encoder_R_A_PIN | Encoder_R_B_PIN);
}

/**
 * @brief 获取左轮速度（带数据保护）
 * @return 左轮速度值
 */
int32_t Encoder_Get_L_Speed()
{
    __disable_irq();
    int32_t speed = -Encoder_L_VEL;  // 统一取反处理
    __enable_irq();
    return speed;
}

/**
 * @brief 获取右轮速度（带数据保护）
 * @return 右轮速度值
 */
int32_t Encoder_Get_R_Speed()
{
    __disable_irq();
    int32_t speed = Encoder_R_VEL;  // 统一取反处理
    __enable_irq();
    return speed;
}

/**
 * @brief 获取左轮积分值（带数据保护）
 * @return 左轮积分值
 */
int32_t Encoder_Get_L_Integral()
{
    __disable_irq();
    int32_t integral = -Encoder_L_INT;  // 统一取反处理，保持一致性
    __enable_irq();
    return integral;
}

/**
 * @brief 获取右轮积分值（带数据保护）
 * @return 右轮积分值
 */
int32_t Encoder_Get_R_Integral()
{
    __disable_irq();
    int32_t integral = Encoder_R_INT;  // 统一取反处理，保持一致性
    __enable_irq();
    return integral;
}

/**
 * @brief 重置编码器积分值
 */
void Encoder_Reset_Integral(void)
{
    __disable_irq();
    Encoder_L_INT = 0;
    Encoder_R_INT = 0;
    __enable_irq();
}

/**
 * @brief 获取左轮原始计数值（调试用）
 * @return 左轮原始计数值
 */
int32_t Encoder_Get_L_Count(void)
{
    __disable_irq();
    int32_t count = Encoder_L_CNT;
    __enable_irq();
    return count;
}

/**
 * @brief 获取右轮原始计数值（调试用）
 * @return 右轮原始计数值
 */
int32_t Encoder_Get_R_Count(void)
{
    __disable_irq();
    int32_t count = Encoder_R_CNT;
    __enable_irq();
    return count;
}


/**
 * @brief 获取左轮速度（弧度每秒）
 * @return 左轮角速度 (rad/s)
 */
float Encoder_Get_L_Speed_RadPerSec(void)
{
    int32_t raw_speed = Encoder_Get_L_Speed();
    return (float)raw_speed * RAD_PER_SEC_PER_PULSE;
}
/**
 * @brief 获取右轮速度（弧度每秒）
 * @return 右轮角速度 (rad/s)
 */
float Encoder_Get_R_Speed_RadPerSec(void)
{
    int32_t raw_speed = Encoder_Get_R_Speed();
    return (float)raw_speed * RAD_PER_SEC_PER_PULSE;
}
/**
 * @brief 获取左轮位置（弧度）
 * @return 左轮角位置 (rad)
 */
float Encoder_Get_L_Position_Rad(void)
{
    int32_t raw_integral = Encoder_Get_L_Integral();
    return (float)raw_integral * RAD_PER_PULSE;
}
/**
 * @brief 获取右轮位置（弧度）
 * @return 右轮角位置 (rad)
 */
float Encoder_Get_R_Position_Rad(void)
{
    int32_t raw_integral = Encoder_Get_R_Integral();
    return (float)raw_integral * RAD_PER_PULSE;
}
/**
 * @brief 重置编码器位置
 */
void Encoder_Reset_Position(void)
{
    Encoder_Reset_Integral();
}
/**
 * @brief 获取左轮原始速度值（保持向后兼容）
 * @return 左轮原始速度值
 */
int32_t Encoder_Get_L_Speed_Raw(void)
{
    return Encoder_Get_L_Speed();
}
/**
 * @brief 获取右轮原始速度值（保持向后兼容）
 * @return 右轮原始速度值
 */
int32_t Encoder_Get_R_Speed_Raw(void)
{
    return Encoder_Get_R_Speed();
}
/**
 * @brief 获取编码器配置信息（调试用）
 * 可以通过串口或调试器查看配置参数
 */
void Encoder_Print_Config(void)
{
    // 计算一些有用的调试信息
    float pulses_per_rev = PULSES_PER_OUTPUT_REV;
    float rad_per_pulse = RAD_PER_PULSE;
    float deg_per_pulse = rad_per_pulse * 180.0f / M_PI;
    
    // 如果你有串口输出功能，可以取消注释以下代码
    /*
    printf("=== 编码器配置信息 ===\n");
    printf("编码器线数: %.0f\n", ENCODER_LINES);
    printf("减速比: %.2f\n", MOTOR_GEAR_RATIO);
    printf("减速后线数: %.2f\n", ENCODER_LINES_AFTER_GEAR);
    printf("采样频率: %.0f Hz\n", ENCODER_SAMPLE_FREQ);
    printf("输出轴每转脉冲数: %.2f\n", pulses_per_rev);
    printf("角度分辨率: %.6f rad/pulse (%.6f deg/pulse)\n", rad_per_pulse, deg_per_pulse);
    printf("速度转换系数: %.6f (rad/s)/pulse\n", RAD_PER_SEC_PER_PULSE);
    printf("========================\n");
    */
}
/**
 * @brief 获取编码器分辨率信息
 * @param rad_resolution 输出角度分辨率(弧度)
 * @param deg_resolution 输出角度分辨率(度)
 */
void Encoder_Get_Resolution(float *rad_resolution, float *deg_resolution)
{
    if(rad_resolution != NULL) {
        *rad_resolution = RAD_PER_PULSE;
    }
    if(deg_resolution != NULL) {
        *deg_resolution = RAD_PER_PULSE * 180.0f / M_PI;
    }
}