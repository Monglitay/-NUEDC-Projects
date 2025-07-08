#include "app_jy61p.h"
#include "delay.h"
#include <string.h> 

void JY61P_Init()
{
    I2C_InitTypedef I2C_InitStruct;
    I2C_InitStruct.system_i2c_init = SYSCFG_DL_JY61P_init;
    I2C_InitStruct.gpio_i2c_iomux_scl = GPIO_JY61P_IOMUX_SCL;
    I2C_InitStruct.gpio_i2c_iomux_scl_func = GPIO_JY61P_IOMUX_SCL_FUNC;
    I2C_InitStruct.gpio_i2c_iomux_sda = GPIO_JY61P_IOMUX_SDA;
    I2C_InitStruct.gpio_i2c_iomux_sda_func = GPIO_JY61P_IOMUX_SDA_FUNC;
    I2C_InitStruct.gpio_i2c_scl_pin = GPIO_JY61P_SCL_PIN;
    I2C_InitStruct.gpio_i2c_scl_port = GPIO_JY61P_SCL_PORT;
    I2C_InitStruct.gpio_i2c_sda_pin = GPIO_JY61P_SDA_PIN;
    I2C_InitStruct.gpio_i2c_sda_port = GPIO_JY61P_SDA_PORT;
    I2C_InitStruct.i2c_inst = JY61P_INST;

    I2C_Init(&JY61P, &I2C_InitStruct);
    
    //**************z轴归零**************//
    // 寄存器解锁
    uint8_t unlock_reg1[2] = {0x88,0xB5};
    I2C_WriteArray(&JY61P, 0x50, 0x69, unlock_reg1, 2);
    delay_ms(200);
    // z轴归零
    uint8_t z_axis_reg[2] = {0x04,0x00};
    I2C_WriteArray(&JY61P, 0x50, 0x01, z_axis_reg, 2);
    delay_ms(200);


    // 保存
	uint8_t save_reg1[2] = {0x00,0x00};
	I2C_WriteArray(&JY61P, 0x50, 0x00, save_reg1, 2);
	delay_ms(200);
}

//数据缓存

Gyro_Struct *JY61P_Update_Angles(void)
{
    uint8_t sda_angle[6] = {0};
	int ret = 0;

	// 清空数据缓存
	memset((void *)sda_angle,0,sizeof(sda_angle));

	// 读取寄存器数据

	ret = I2C_ReadArray(&JY61P, 0x50, 0x3D, sda_angle,6);


    // 计算 RollX, PitchY 和 YawZ 并确保它们在 -180 到 180 的范围内
    float RollX = (float)(((sda_angle[1] << 8) | sda_angle[0]) / 32768.0 * 180.0);
    if (RollX > 180.0)
    {
        RollX -= 360.0;
    }
    else if (RollX < -180.0)
    {
        RollX += 360.0;
    }

    float PitchY = (float)(((sda_angle[3] << 8) | sda_angle[2]) / 32768.0 * 180.0);
    if (PitchY > 180.0)
    {
        PitchY -= 360.0;
    }
    else if (PitchY < -180.0)
    {
        PitchY += 360.0;
    }

    float YawZ = (float)(((sda_angle[5] << 8) | sda_angle[4]) / 32768.0 * 180.0);
    if (YawZ > 180.0)
    {
        YawZ -= 360.0;
    }
    else if (YawZ < -180.0)
    {
        YawZ += 360.0;
    }

    // 将计算结果保存到结构体中
    Gyro_Structure.x = RollX;
    Gyro_Structure.y = PitchY;
    Gyro_Structure.z = YawZ;

	// 返回角度数据
	return &Gyro_Structure;
}
