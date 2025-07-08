#include "openmv.h"
#include "command.h"

Command_Typedef openmv_recvied;
uint8_t usart_ch;

void OpenMV_Init()
{
    Command_Init(&openmv_recvied);
    USART_InitTypedef USART_InitStruct;
    USART_InitStruct.usart_inst = OPENMV_INST;
    USART_InitStruct.usart_inst_int_irqn = OPENMV_INST_INT_IRQN;
    USART_Init(&OpenMV,&USART_InitStruct);
}
void UART3_IRQHandler(void)
{
    switch(DL_UART_getPendingInterrupt(OpenMV.usart_inst))
    {
        case DL_UART_IIDX_RX:
            usart_ch = DL_UART_Main_receiveData(OpenMV.usart_inst);
            Command_Write(&openmv_recvied, &usart_ch, 1);
            break;
        default:
            break;
    }
}

void OpenMV_Read_Command(uint8_t *buffer)
{
    Command_GetCommand(&openmv_recvied,buffer);
}