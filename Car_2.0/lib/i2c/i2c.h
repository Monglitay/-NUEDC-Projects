#ifndef __I2C_H_
#define __I2C_H_

#include "ti_msp_dl_config.h"

// I2C初始化结构体
typedef struct
{
    I2C_Regs *i2c_inst;
    uint32_t gpio_i2c_iomux_sda;        
    uint32_t gpio_i2c_iomux_sda_func;   
    uint32_t gpio_i2c_iomux_scl;        
    uint32_t gpio_i2c_iomux_scl_func;   
    GPIO_Regs *gpio_i2c_scl_port;
    uint32_t gpio_i2c_scl_pin;          
    GPIO_Regs *gpio_i2c_sda_port;
    uint32_t gpio_i2c_sda_pin;         
    void (*system_i2c_init)(void);     
} I2C_InitTypedef;

// I2C句柄结构体
typedef struct
{
    I2C_Regs *i2c_inst;
    uint32_t gpio_i2c_iomux_sda;
    uint32_t gpio_i2c_iomux_sda_func;
    uint32_t gpio_i2c_iomux_scl;
    uint32_t gpio_i2c_iomux_scl_func;
    GPIO_Regs *gpio_i2c_scl_port;
    uint32_t gpio_i2c_scl_pin;
    GPIO_Regs *gpio_i2c_sda_port;
    uint32_t gpio_i2c_sda_pin;
    void (*system_i2c_init)(void);
} I2C_Typedef;

// 常量定义
#define I2C_TIMEOUT_MS       2000
#define I2C_MAX_BUFFER_SIZE  256

// 错误代码定义
#define I2C_OK               0
#define I2C_ERROR            1
#define I2C_TIMEOUT          2
#define I2C_INVALID_PARAM    -1

// 基础函数声明
void I2C_Init(I2C_Typedef *I2CX, I2C_InitTypedef *I2C_InitStruct);
void I2C_SDA_Unlock(I2C_Typedef *I2CX);

// 单字节读写函数声明
int I2C_ReadByte(I2C_Typedef *I2CX, uint8_t devAddr, uint8_t regAddr, uint8_t *data);
int I2C_WriteByte(I2C_Typedef *I2CX, uint8_t devAddr, uint8_t regAddr, uint8_t data);

// 数组读写函数声明
int I2C_ReadArray(I2C_Typedef *I2CX, uint8_t devAddr, uint8_t regAddr, uint8_t *data, uint16_t length);
int I2C_WriteArray(I2C_Typedef *I2CX, uint8_t devAddr, uint8_t regAddr, uint8_t *data, uint16_t length);

// 仅数据传输函数声明（不带寄存器地址）
int I2C_WriteDataOnly(I2C_Typedef *I2CX, uint8_t devAddr, uint8_t *data, uint16_t length);
int I2C_ReadDataOnly(I2C_Typedef *I2CX, uint8_t devAddr, uint8_t *data, uint16_t length);

// 设备检测函数声明
int I2C_CheckDevice(I2C_Typedef *I2CX, uint8_t devAddr);

// 扫描总线函数声明
int I2C_ScanBus(I2C_Typedef *I2CX, uint8_t *deviceList, uint8_t maxDevices);





#endif /* __I2C_H_ */
