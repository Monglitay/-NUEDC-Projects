#ifndef _APP_W25Q128_H_
#define _APP_W25Q128_H_
#include "ti_msp_dl_config.h"

#define SPI_CS(x)  ( (x) ? DL_GPIO_setPins(W25Q128_CS_PORT,W25Q128_CS_PIN_PIN) : DL_GPIO_clearPins(W25Q128_CS_PORT,W25Q128_CS_PIN_PIN) )

uint16_t W25Q128_ReadID(void);//读取W25Q128的ID
void W25Q128_Write(uint8_t* buffer, uint32_t addr, uint16_t numbyte);      //W25Q128写数据
void W25Q128_Read(uint8_t* buffer,uint32_t read_addr,uint16_t read_length);//W25Q128读数据
#endif