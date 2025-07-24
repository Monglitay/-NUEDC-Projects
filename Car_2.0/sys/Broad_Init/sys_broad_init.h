#ifndef __SYS_BROAD_INIT_H_
#define __SYS_BROAD_INIT_H_
#include "main.h"

#define PID_MotorSpeed_L_KP_Addr    0
#define PID_MotorSpeed_L_KI_Addr    4
#define PID_MotorSpeed_L_KD_Addr    8
#define PID_MotorSpeed_R_KP_Addr    12
#define PID_MotorSpeed_R_KI_Addr    16
#define PID_MotorSpeed_R_KD_Addr    20
#define PID_Turning_KP_Addr         24
#define PID_Turning_KI_Addr         28
#define PID_Turning_KD_Addr         32
#define PID_Tracking_KP_Addr        36
#define PID_Tracking_KI_Addr        40
#define PID_Tracking_KD_Addr        44
#define Camera_threshold_Addr       48
#define Camera_brightness_Addr      52

PID_Typedef PID_MotorSpeed_L;
PID_Typedef PID_MotorSpeed_R;
PID_Typedef PID_Turning;
PID_Typedef PID_Tracking;
float Camera_threshold;
float Camera_brightness;
void Broad_Init();
void Data_Init();
#endif