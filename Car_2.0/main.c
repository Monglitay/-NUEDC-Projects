#include "ti_msp_dl_config.h"
#include "main.h"
int main(void)
{
    Broad_Init();
    int32_t start_tick = get_ticks();
    USART_Printf(&BLE05, "hello");
    while (1) {
        uint8_t buffer[10] = {0};
        CKP_Read_Command(buffer);
        if(buffer[0]==0xfe)
        {
            Command_Clear(&CKP_received);
            Debug_Proc();
        }
        else if(buffer[0]==0xff)
        {
            while(1)
            {
                float speed = (((get_ticks()-start_tick)/3000)%7)*7;
                Motor_SetSpeed_R(speed);
                Motor_SetSpeed_L(speed);
                float speed_r = Encoder_Get_R_Speed_RadPerSec();
                float speed_l = Encoder_Get_L_Speed_RadPerSec();
                USART_Printf(&BLE05, "%f,%f,%f\n", speed_l,speed_r,speed);
                
            }
        }
        
    }
}
