#include "app_ble05.h"
#include "delay.h"
void BLE05_Init()
{
    USART_InitTypedef BLE05_InitStruct;
    BLE05_InitStruct.usart_inst = BLE05_INST;
    BLE05_InitStruct.usart_inst_int_irqn = BLE05_INST_INT_IRQN;
    USART_Init(&BLE05,&BLE05_InitStruct);
    DL_GPIO_clearPins(W25Q128_CS_PORT,W25Q128_CS_PIN_PIN);
    delay_ms(30);
    DL_GPIO_setPins(W25Q128_CS_PORT,W25Q128_CS_PIN_PIN);
}