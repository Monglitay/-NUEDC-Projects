#include "i2c.h"
#include "delay.h"

void I2C_Init(I2C_Typedef *I2CX, I2C_InitTypedef *I2C_InitStruct)
{
    // 检查参数有效性
    if (I2CX == NULL || I2C_InitStruct == NULL) {
        return;
    }
    
    I2CX->system_i2c_init = I2C_InitStruct->system_i2c_init;
    I2CX->gpio_i2c_iomux_scl = I2C_InitStruct->gpio_i2c_iomux_scl;
    I2CX->gpio_i2c_iomux_scl_func = I2C_InitStruct->gpio_i2c_iomux_scl_func;
    I2CX->gpio_i2c_iomux_sda = I2C_InitStruct->gpio_i2c_iomux_sda;
    I2CX->gpio_i2c_iomux_sda_func = I2C_InitStruct->gpio_i2c_iomux_sda_func;
    I2CX->i2c_inst = I2C_InitStruct->i2c_inst;
    I2CX->gpio_i2c_scl_pin = I2C_InitStruct->gpio_i2c_scl_pin;
    I2CX->gpio_i2c_scl_port = I2C_InitStruct->gpio_i2c_scl_port;
    I2CX->gpio_i2c_sda_pin = I2C_InitStruct->gpio_i2c_sda_pin;
    I2CX->gpio_i2c_sda_port = I2C_InitStruct->gpio_i2c_sda_port;
}

static int I2C_Disable(I2C_Typedef *I2CX)
{
    if (I2CX == NULL) return -1;
    
    DL_I2C_reset(I2CX->i2c_inst);
    DL_GPIO_initDigitalOutput(I2CX->gpio_i2c_iomux_scl);
    DL_GPIO_initDigitalInputFeatures(I2CX->gpio_i2c_iomux_sda,
        DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_NONE,
        DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);
    DL_GPIO_clearPins(I2CX->gpio_i2c_scl_port, I2CX->gpio_i2c_scl_pin);
    DL_GPIO_enableOutput(I2CX->gpio_i2c_sda_port, I2CX->gpio_i2c_sda_pin);
    return 0;
}

static int I2C_Enable(I2C_Typedef *I2CX)
{
    if (I2CX == NULL) return -1;
    
    DL_I2C_reset(I2CX->i2c_inst);
    DL_GPIO_initPeripheralInputFunctionFeatures(I2CX->gpio_i2c_iomux_sda,
        I2CX->gpio_i2c_iomux_sda_func, DL_GPIO_INVERSION_DISABLE,
        DL_GPIO_RESISTOR_NONE, DL_GPIO_HYSTERESIS_DISABLE,
        DL_GPIO_WAKEUP_DISABLE);
    DL_GPIO_initPeripheralInputFunctionFeatures(I2CX->gpio_i2c_iomux_scl,
        I2CX->gpio_i2c_iomux_scl_func, DL_GPIO_INVERSION_DISABLE,
        DL_GPIO_RESISTOR_NONE, DL_GPIO_HYSTERESIS_DISABLE,
        DL_GPIO_WAKEUP_DISABLE);
    DL_GPIO_enableHiZ(I2CX->gpio_i2c_iomux_sda);
    DL_GPIO_enableHiZ(I2CX->gpio_i2c_iomux_scl);
    DL_I2C_enablePower(I2CX->i2c_inst);
    
    if (I2CX->system_i2c_init != NULL) {
        I2CX->system_i2c_init();
    }
    return 0;
}

void I2C_SDA_Unlock(I2C_Typedef *I2CX)
{
    if (I2CX == NULL) return;
    
    uint8_t cycleCnt = 0;
    I2C_Disable(I2CX);
    
    do
    {
        DL_GPIO_clearPins(I2CX->gpio_i2c_scl_port, I2CX->gpio_i2c_scl_pin);
        delay_ms(1);
        DL_GPIO_setPins(I2CX->gpio_i2c_scl_port, I2CX->gpio_i2c_scl_pin);
        delay_ms(1);

        if(DL_GPIO_readPins(I2CX->gpio_i2c_sda_port, I2CX->gpio_i2c_sda_pin))
            break;
    } while(++cycleCnt < 100);
    
    I2C_Enable(I2CX);
}

int I2C_ReadByte(I2C_Typedef *I2CX, uint8_t devAddr, uint8_t regAddr, uint8_t *data)
{
    if (I2CX == NULL || data == NULL) return -1;
    
    unsigned long start, current;
    
    start = get_ticks();
    
    // 1. 发送寄存器地址
    DL_I2C_fillControllerTXFIFO(I2CX->i2c_inst, &regAddr, 1);
    
    while (!(DL_I2C_getControllerStatus(I2CX->i2c_inst) & DL_I2C_CONTROLLER_STATUS_IDLE)) {
        current = get_ticks();
        if (current >= (start + I2C_TIMEOUT_MS)) {
            I2C_SDA_Unlock(I2CX);
            return 1;
        }
    }
    
    DL_I2C_startControllerTransfer(I2CX->i2c_inst, devAddr, DL_I2C_CONTROLLER_DIRECTION_TX, 1);
    
    while (DL_I2C_getControllerStatus(I2CX->i2c_inst) & DL_I2C_CONTROLLER_STATUS_BUSY_BUS) {
        current = get_ticks();
        if (current >= (start + I2C_TIMEOUT_MS)) {
            I2C_SDA_Unlock(I2CX);
            return 1;
        }
    }
    
    while (!(DL_I2C_getControllerStatus(I2CX->i2c_inst) & DL_I2C_CONTROLLER_STATUS_IDLE)) {
        current = get_ticks();
        if (current >= (start + I2C_TIMEOUT_MS)) {
            I2C_SDA_Unlock(I2CX);
            return 1;
        }
    }
    
    DL_I2C_flushControllerTXFIFO(I2CX->i2c_inst);
    
    // 2. 启动读传输
    DL_I2C_startControllerTransfer(I2CX->i2c_inst, devAddr, DL_I2C_CONTROLLER_DIRECTION_RX, 1);
    
    while (DL_I2C_getControllerStatus(I2CX->i2c_inst) & DL_I2C_CONTROLLER_STATUS_BUSY_BUS) {
        current = get_ticks();
        if (current >= (start + I2C_TIMEOUT_MS)) {
            I2C_SDA_Unlock(I2CX);
            return 1;
        }
    }
    
    while (!(DL_I2C_getControllerStatus(I2CX->i2c_inst) & DL_I2C_CONTROLLER_STATUS_IDLE)) {
        current = get_ticks();
        if (current >= (start + I2C_TIMEOUT_MS)) {
            I2C_SDA_Unlock(I2CX);
            return 1;
        }
    }
    
    *data = DL_I2C_receiveControllerData(I2CX->i2c_inst);
    
    return 0;
}

int I2C_ReadArray(I2C_Typedef *I2CX, uint8_t devAddr, uint8_t regAddr, uint8_t *data, uint16_t length)
{
    if (I2CX == NULL || data == NULL || length == 0) return -1;
    
    unsigned long start, current;
    
    start = get_ticks();
    
    // 清空FIFO
    DL_I2C_flushControllerTXFIFO(I2CX->i2c_inst);
    DL_I2C_flushControllerRXFIFO(I2CX->i2c_inst);
    
    // 1. 写阶段：发送寄存器地址
    DL_I2C_fillControllerTXFIFO(I2CX->i2c_inst, &regAddr, 1);
    DL_I2C_startControllerTransfer(I2CX->i2c_inst, devAddr, DL_I2C_CONTROLLER_DIRECTION_TX, 1);
    
    // 等待写传输完成
    do {
        current = get_ticks();
        if (current >= (start + I2C_TIMEOUT_MS)) {
            I2C_SDA_Unlock(I2CX);
            return 1;
        }
    } while (DL_I2C_getControllerStatus(I2CX->i2c_inst) & DL_I2C_CONTROLLER_STATUS_BUSY_BUS);
    
    // 确保控制器完全空闲
    do {
        current = get_ticks();
        if (current >= (start + I2C_TIMEOUT_MS)) {
            I2C_SDA_Unlock(I2CX);
            return 1;
        }
    } while (!(DL_I2C_getControllerStatus(I2CX->i2c_inst) & DL_I2C_CONTROLLER_STATUS_IDLE));
    
    // 2. 读阶段：启动读传输
    DL_I2C_startControllerTransfer(I2CX->i2c_inst, devAddr, DL_I2C_CONTROLLER_DIRECTION_RX, length);
    
    // 3. 逐字节读取数据
    for (uint16_t i = 0; i < length; i++) {
        // 等待RX FIFO中有数据可读
        do {
            current = get_ticks();
            if (current >= (start + I2C_TIMEOUT_MS)) {
                I2C_SDA_Unlock(I2CX);
                return 1;
            }
        } while (DL_I2C_isControllerRXFIFOEmpty(I2CX->i2c_inst));
        
        // 读取一个字节
        data[i] = DL_I2C_receiveControllerData(I2CX->i2c_inst);
    }
    
    // 等待传输完全结束
    do {
        current = get_ticks();
        if (current >= (start + I2C_TIMEOUT_MS)) {
            I2C_SDA_Unlock(I2CX);
            return 1;
        }
    } while (DL_I2C_getControllerStatus(I2CX->i2c_inst) & DL_I2C_CONTROLLER_STATUS_BUSY_BUS);
    
    return 0;
}


int I2C_WriteArray(I2C_Typedef *I2CX, uint8_t devAddr, uint8_t regAddr, uint8_t *data, uint16_t length)
{
    if (I2CX == NULL || data == NULL || length == 0) return -1;
    
    static uint8_t txBuffer[I2C_MAX_BUFFER_SIZE]; // 使用静态缓冲区
    unsigned long start, current;
    uint16_t totalLength = length + 1; // 寄存器地址 + 数据长度
    
    // 检查缓冲区大小
    if (totalLength > I2C_MAX_BUFFER_SIZE) {
        return -1; // 数据长度超出缓冲区大小
    }
    
    // 构造发送缓冲区：寄存器地址 + 数据数组
    txBuffer[0] = regAddr;
    for (uint16_t i = 0; i < length; i++) {
        txBuffer[i + 1] = data[i];
    }
    
    start = get_ticks();
    
    // 填充TX FIFO
    DL_I2C_fillControllerTXFIFO(I2CX->i2c_inst, txBuffer, totalLength);
    
    // 等待控制器空闲
    while (!(DL_I2C_getControllerStatus(I2CX->i2c_inst) & DL_I2C_CONTROLLER_STATUS_IDLE)) {
        current = get_ticks();
        if (current >= (start + I2C_TIMEOUT_MS)) {
            I2C_SDA_Unlock(I2CX);
            return 1;
        }
    }
    
    // 启动传输
    DL_I2C_startControllerTransfer(I2CX->i2c_inst, devAddr, DL_I2C_CONTROLLER_DIRECTION_TX, totalLength);
    
    // 等待总线不忙
    while (DL_I2C_getControllerStatus(I2CX->i2c_inst) & DL_I2C_CONTROLLER_STATUS_BUSY_BUS) {
        current = get_ticks();
        if (current >= (start + I2C_TIMEOUT_MS)) {
            I2C_SDA_Unlock(I2CX);
            return 1;
        }
    }
    
    // 等待控制器空闲
    while (!(DL_I2C_getControllerStatus(I2CX->i2c_inst) & DL_I2C_CONTROLLER_STATUS_IDLE)) {
        current = get_ticks();
        if (current >= (start + I2C_TIMEOUT_MS)) {
            I2C_SDA_Unlock(I2CX);
            return 1;
        }
    }
    
    return 0;
}

int I2C_WriteDataOnly(I2C_Typedef *I2CX, uint8_t devAddr, uint8_t *data, uint16_t length)
{
    if (I2CX == NULL || data == NULL || length == 0) return -1;
    
    // 检查缓冲区大小
    if (length > I2C_MAX_BUFFER_SIZE) {
        return -1; // 数据长度超出缓冲区大小
    }
    
    unsigned long start, current;
    
    start = get_ticks();
    
    // 直接填充数据到TX FIFO
    DL_I2C_fillControllerTXFIFO(I2CX->i2c_inst, data, length);
    
    // 等待控制器空闲
    while (!(DL_I2C_getControllerStatus(I2CX->i2c_inst) & DL_I2C_CONTROLLER_STATUS_IDLE)) {
        current = get_ticks();
        if (current >= (start + I2C_TIMEOUT_MS)) {
            I2C_SDA_Unlock(I2CX);
            return 1;
        }
    }
    
    // 启动传输
    DL_I2C_startControllerTransfer(I2CX->i2c_inst, devAddr, DL_I2C_CONTROLLER_DIRECTION_TX, length);
    
    // 等待总线不忙
    while (DL_I2C_getControllerStatus(I2CX->i2c_inst) & DL_I2C_CONTROLLER_STATUS_BUSY_BUS) {
        current = get_ticks();
        if (current >= (start + I2C_TIMEOUT_MS)) {
            I2C_SDA_Unlock(I2CX);
            return 1;
        }
    }
    
    // 等待控制器空闲
    while (!(DL_I2C_getControllerStatus(I2CX->i2c_inst) & DL_I2C_CONTROLLER_STATUS_IDLE)) {
        current = get_ticks();
        if (current >= (start + I2C_TIMEOUT_MS)) {
            I2C_SDA_Unlock(I2CX);
            return 1;
        }
    }
    
    return 0;
}

int I2C_WriteByte(I2C_Typedef *I2CX, uint8_t devAddr, uint8_t regAddr, uint8_t data)
{
    // 调用数组写入函数，长度为1，保持向后兼容性
    return I2C_WriteArray(I2CX, devAddr, regAddr, &data, 1);
}

int I2C_CheckDevice(I2C_Typedef *I2CX, uint8_t devAddr)
{
    if (I2CX == NULL) return -1;
    
    unsigned long start, current;
    
    start = get_ticks();
    
    // 等待控制器空闲
    while (!(DL_I2C_getControllerStatus(I2CX->i2c_inst) & DL_I2C_CONTROLLER_STATUS_IDLE)) {
        current = get_ticks();
        if (current >= (start + I2C_TIMEOUT_MS)) {
            return 1; // 超时
        }
    }
    
    // 启动0字节传输以检查设备是否存在
    DL_I2C_startControllerTransfer(I2CX->i2c_inst, devAddr, DL_I2C_CONTROLLER_DIRECTION_TX, 0);
    
    // 等待总线不忙
    while (DL_I2C_getControllerStatus(I2CX->i2c_inst) & DL_I2C_CONTROLLER_STATUS_BUSY_BUS) {
        current = get_ticks();
        if (current >= (start + I2C_TIMEOUT_MS)) {
            return 1; // 超时
        }
    }
    
    // 等待控制器空闲
    while (!(DL_I2C_getControllerStatus(I2CX->i2c_inst) & DL_I2C_CONTROLLER_STATUS_IDLE)) {
        current = get_ticks();
        if (current >= (start + I2C_TIMEOUT_MS)) {
            return 1; // 超时
        }
    }
    
    // 检查是否有NACK错误
    if (DL_I2C_getControllerStatus(I2CX->i2c_inst) & DL_I2C_CONTROLLER_STATUS_ERROR) {
        DL_I2C_clearInterruptStatus(I2CX->i2c_inst, DL_I2C_INTERRUPT_CONTROLLER_NACK);
        return 1; // 设备不存在或无响应
    }
    
    return 0; // 设备存在且响应正常
}

