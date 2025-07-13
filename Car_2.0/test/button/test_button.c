#include "test_button.h"
void Test_Buttons()
{
    SYSCFG_DL_init();
    BLE05_Init();
    OpenMV_Init();
    Buttons_Init();
    USART_Printf(&BLE05,"HELLO\n");

    while (1) 
    {
        Buttons_Proc();
    }
}