#include "test_openmv.h"
#include "app_ble05.h"
void Test_OpenMV(void)
{
    SYSCFG_DL_init();
    BLE05_Init();

    OpenMV_Init();
    
    
    uint8_t cmd_buffer[4] = {0};  // 4字节：0xAA + 长度 + 数据 + 校验
    uint8_t cmd_len = 0;
    
    while (1) {
        cmd_len = OpenMV_Read_Command(cmd_buffer);

        if (cmd_len == 4) {  // 确保是完整的4字节命令
            uint8_t data = cmd_buffer[2];  // 数据在第3个位置
            USART_Printf(&BLE05, "%d\n", data);
        } else if (cmd_len > 0) {
            USART_Printf(&BLE05, "Invalid cmd len: %d\n", cmd_len);
        }
        
    
    }
}