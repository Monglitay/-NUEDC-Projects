#include "app_openmv.h"
#include "app_ble05.h"


uint8_t usart_ch;
uint8_t i;

void OpenMV_Init()
{
    Command_Init(&openmv_recvied);
    USART_InitTypedef USART_InitStruct;
    USART_InitStruct.usart_inst = OPENMV_INST;
    USART_InitStruct.usart_inst_int_irqn = OPENMV_INST_INT_IRQN;
    USART_Init(&OpenMV,&USART_InitStruct);
    i = 1;
}
void UART3_IRQHandler(void)
{
    switch(DL_UART_getPendingInterrupt(OpenMV.usart_inst))
    {
        case DL_UART_IIDX_RX:
            usart_ch = DL_UART_Main_receiveData(OpenMV.usart_inst);
            //USART_Printf(&BLE05, "%x\n",usart_ch);
            int ret = Command_Write(&openmv_recvied, &usart_ch, 1);
            //USART_Printf(&BLE05, "%x,%d,%d\n",Command_Read(&openmv_recvied,i),ret, Command_GetRemain(&openmv_recvied));
            //i++;
            break;
        default:
            break;
    }
}

uint8_t OpenMV_Read_Command(uint8_t *buffer)
{
    return Command_GetCommand(&openmv_recvied,buffer);
}