#ifndef __SERVO_h_
#define __SERVO_h_
#include "ti_msp_dl_config.h"
#define PERIOD  1000
#define TIMERA 1
#define TIMERG 0
typedef struct
{
    GPTIMER_Regs *servo_inst;
    uint8_t gpio_servo_cx_idx;
    uint8_t timer;
    float angle;
    float min_count;
    float max_count;
    float range;
} Servo_Typedef;

typedef struct
{
    GPTIMER_Regs *servo_inst;
    uint8_t gpio_servo_cx_idx;
    uint8_t timer;
} Servo_InitTypedef;

void Servo_Init(Servo_Typedef *Servo,Servo_InitTypedef *Servo_InitStruct);
void Servo_Set_Angle(Servo_Typedef *Servo,float angle);
#endif