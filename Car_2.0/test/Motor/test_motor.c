#include "test_motor.h"
void Test_Motor()
{
    Broad_Init();
    int32_t start_tick = get_ticks();
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
                float speed = (((get_ticks()-start_tick)/3000)%7)*50;
                Motor_SetSpeed_L(speed);     
                Motor_SetSpeed_R(speed);      // 先设置目标速度
                Motor_Proc();                    // 再执行电机控制
                float speed_l = Encoder_Get_L_Speed_RadPerSec();
                if(!((get_ticks()-start_tick)%10))
                USART_Printf(&BLE05, "w:%f,%f\r\n", speed_l,speed);
                
            }
        }
        
    }
    
}