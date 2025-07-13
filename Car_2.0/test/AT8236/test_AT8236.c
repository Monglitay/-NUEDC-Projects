#include "test_AT8236.h"

void Test_AT8236()
{
    SYSCFG_DL_init();
    BLE05_Init();
    OpenMV_Init();
    USART_Printf(&BLE05,"HELLO\n");
    
    AT8236_AOUT_FD(500);
    AT8236_BOUT_FD(500);
    delay_ms(5000);
    AT8236_AOUT_FD(-500);
    AT8236_BOUT_FD(-500);
    delay_ms(5000);
    AT8236_BOUT_Stop();
    AT8236_AOUT_Stop();
}