#include "app_ckp.h"
#include "app_ble05.h"
uint8_t usart_ch;
void CKP_Init()
{
    USART_InitTypedef USART_InitStruct;
    USART_InitStruct.usart_inst = CKP_INST;
    USART_InitStruct.usart_inst_int_irqn = CKP_INST_INT_IRQN;
    USART_Init(&CKP,&USART_InitStruct);

    Command_Init(&CKP_received);
}

void UART0_IRQHandler(void)
{
    switch(DL_UART_getPendingInterrupt(CKP.usart_inst))
    {
        case DL_UART_IIDX_RX:
            usart_ch = DL_UART_Main_receiveData(CKP.usart_inst);
            Command_Write(&CKP_received, &usart_ch, 1);
            USART_Printf(&BLE05,"%c",usart_ch);
            break;
        default:
            break;
    }
}

uint8_t CKP_Read_Command(uint8_t *buffer)
{
    uint8_t data_length = 0;  // 改名更清晰，表示数据部分长度
    
    while(1)
    {
        // 如果不是包头 则跳过 重新开始寻找
        if (Command_Read(&CKP_received, CKP_received.readIndex) != 0xFA) 
        {
            Command_AddReadIndex(&CKP_received, 1);
            continue;
        }
        
        // 找到包头，开始读取数据部分
        uint8_t current_byte;
        uint8_t read_offset = 1;  // 从包头后开始读取
        data_length = 0;
        
        while((current_byte = Command_Read(&CKP_received, CKP_received.readIndex + read_offset)) != 0x0A)
        {
            buffer[data_length] = current_byte;
            data_length++;
            read_offset++;
            
            if(data_length >= 20) {  // 防止缓冲区溢出
                // 数据过长，跳过这个包头，重新寻找
                Command_AddReadIndex(&CKP_received, 1);
                data_length = 0;
                break;
            }
        }
        
        // 如果是因为数据过长而跳出，继续寻找下一个包头
        if(data_length >= 20) {
            continue;
        }
        
        // 找到完整指令，移动读索引到包尾之后
        // 总长度 = 包头(1) + 数据长度(data_length) + 包尾(1)
        Command_AddReadIndex(&CKP_received, 1 + data_length + 2);
        
        return data_length;  // 返回实际数据长度
    }
}