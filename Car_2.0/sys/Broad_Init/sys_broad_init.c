#include "sys_broad_init.h"

void Broad_Init()
{
    SYSCFG_DL_init();
    Data_Init();
    BLE05_Init();
    Buttons_Init();
    Encoder_Init();
    Servos_Init();
    CKP_Init();
    JY61P_Init();
    OpenMV_Init();
    Motor_Init();
    ADC_Init();
    Timer_Init();
}

void Data_Init()
{
    float buffer[14];
    W25Q128_Read((uint8_t*)buffer,0,56);
    PID_Init(&PID_MotorSpeed_L, buffer[0], buffer[1], buffer[2]);
    PID_Init(&PID_MotorSpeed_R, buffer[3], buffer[4], buffer[5]);
    PID_Init_Advanced(&PID_Turning, buffer[6], buffer[7], buffer[8],12,90,0.1,0.5);
    PID_Init_Advanced(&PID_Tracking, buffer[9], buffer[10], buffer[11],90,90,0.1,0.5);
    Camera_threshold = buffer[12];
    Camera_threshold = buffer[13];
}