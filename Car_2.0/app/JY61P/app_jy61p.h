#ifndef _APP_JY61P_H_
#define _APP_JY61P_H_
#include "i2c.h"
#include "ti_msp_dl_config.h"

typedef struct {
    float x;
    float y;
    float z;
} Gyro_Struct;

I2C_Typedef JY61P;
Gyro_Struct Gyro_Structure;

Gyro_Struct *JY61P_Update_Angles(void);
void JY61P_Init();

#endif