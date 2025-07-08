#include "ti_msp_dl_config.h"
#include "app_ble05.h"
#include "app_jy61p.h"
#include "openmv.h"
#include "delay.h"
int main(void)
{
    SYSCFG_DL_init();
    BLE05_Init();
    JY61P_Init();
    char ptr[256] = {0};
    USART_Printf(&BLE05,"HELLO");
    uint8_t read = 0;
    while (1) {
        read = USART_ReceieveByte(&OpenMV);
        USART_Printf(&BLE05, "%d\n", read);
        delay_ms(200);
    }
}
