#ifndef __SYS_DEBUG_PROC_H_
#define __SYS_DEBUG_PROC_H_
#include "main.h"
typedef struct {
    float motor_l_kp, motor_l_ki, motor_l_kd;
    float motor_r_kp, motor_r_ki, motor_r_kd;
    float turning_kp, turning_ki, turning_kd;
    float tracking_kp, tracking_ki, tracking_kd;
    float camera_threshold, camera_brightness;
} Flash_Data_t;
void Debug_Proc();
#endif