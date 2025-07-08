#include "app_ble05.h"

void BLE05_Init()
{
    USART_InitTypedef BLE05_InitStruct;
    BLE05_InitStruct.usart_inst = BLE05_INST;
    BLE05_InitStruct.usart_inst_int_irqn = BLE05_INST_INT_IRQN;
    USART_Init(&BLE05,&BLE05_InitStruct);
}