#include "sys_debug_proc.h"
#include "stdio.h"

void Save_All_Data() {
    Flash_Data_t flash_data = {
        .motor_l_kp = PID_MotorSpeed_L.kp,
        .motor_l_ki = PID_MotorSpeed_L.ki,
        .motor_l_kd = PID_MotorSpeed_L.kd,
        .motor_r_kp = PID_MotorSpeed_R.kp,
        .motor_r_ki = PID_MotorSpeed_R.ki,
        .motor_r_kd = PID_MotorSpeed_R.kd,
        .turning_kp = PID_Turning.kp,
        .turning_ki = PID_Turning.ki,
        .turning_kd = PID_Turning.kd,
        .tracking_kp = PID_Tracking.kp,
        .tracking_ki = PID_Tracking.ki,
        .tracking_kd = PID_Tracking.kd,
    };
    W25Q128_Write((uint8_t*)(&flash_data), 0, sizeof(Flash_Data_t));
}

void Debug_Proc()
{
    Data_Init();
    
    // 初始化显示所有PID参数
    USART_Printf(&CKP, "MOTOR_R.t0.txt=\"%f\"\xff\xff\xff", PID_MotorSpeed_R.kp);
    USART_Printf(&CKP, "MOTOR_R.t1.txt=\"%f\"\xff\xff\xff", PID_MotorSpeed_R.ki);
    USART_Printf(&CKP, "MOTOR_R.t2.txt=\"%f\"\xff\xff\xff", PID_MotorSpeed_R.kd);
    USART_Printf(&CKP, "MOTOR_L.t0.txt=\"%f\"\xff\xff\xff", PID_MotorSpeed_L.kp);
    USART_Printf(&CKP, "MOTOR_L.t1.txt=\"%f\"\xff\xff\xff", PID_MotorSpeed_L.ki);
    USART_Printf(&CKP, "MOTOR_L.t2.txt=\"%f\"\xff\xff\xff", PID_MotorSpeed_L.kd);
    USART_Printf(&CKP, "Turn.t0.txt=\"%f\"\xff\xff\xff", PID_Turning.kp);
    USART_Printf(&CKP, "Turn.t1.txt=\"%f\"\xff\xff\xff", PID_Turning.ki);
    USART_Printf(&CKP, "Turn.t2.txt=\"%f\"\xff\xff\xff", PID_Turning.kd);
    USART_Printf(&CKP, "Track.t0.txt=\"%f\"\xff\xff\xff", PID_Tracking.kp);
    USART_Printf(&CKP, "Track.t1.txt=\"%f\"\xff\xff\xff", PID_Tracking.ki);
    USART_Printf(&CKP, "Track.t2.txt=\"%f\"\xff\xff\xff", PID_Tracking.kd);
    
    // 切换到MOTOR_R页面
    USART_Printf(&CKP,"page MOTOR_R\xff\xff\xff");
    
    BLE05_Init();
    
    while(1)
    {
        char buffer[20];
        uint8_t ret = CKP_Read_Command((uint8_t*)(buffer));
        if(buffer[0]==0xff)break;
        if(ret != 0)
        {
            float data;
            char index;
            int parsed = sscanf(buffer, "%f%c", &data, &index);
            
            if(parsed == 2)  // 确保解析成功
            {
                Command_Clear(&CKP_received);
                
                switch (index)
                {
                    // 右电机PID参数 (A, B, C)
                    case 'A':
                        PID_MotorSpeed_R.kp = data;
                        Save_All_Data();
                        delay_ms(10);
                        USART_Printf(&CKP, "MOTOR_R.t0.txt=\"%f\"\xff\xff\xff", PID_MotorSpeed_R.kp);
                        break;
                    case 'B':
                        PID_MotorSpeed_R.ki = data;
                        Save_All_Data();
                        delay_ms(10);
                        USART_Printf(&CKP, "MOTOR_R.t1.txt=\"%f\"\xff\xff\xff", PID_MotorSpeed_R.ki);
                        break; 
                    case 'C':
                        PID_MotorSpeed_R.kd = data;
                        Save_All_Data();
                        delay_ms(10);
                        USART_Printf(&CKP, "MOTOR_R.t2.txt=\"%f\"\xff\xff\xff", PID_MotorSpeed_R.kd);
                        break;
                    
                    // 左电机PID参数 (D, E, F)
                    case 'D':
                        //USART_Printf(&BLE05, "Enter case D\xff\xff\xff");
                        PID_MotorSpeed_L.kp = data;
                        Save_All_Data();
                        delay_ms(10);
                        USART_Printf(&CKP, "MOTOR_L.t0.txt=\"%f\"\xff\xff\xff", PID_MotorSpeed_L.kp);
                        break;
                    case 'M':
                        //USART_Printf(&BLE05, "Enter case E\xff\xff\xff");
                        PID_MotorSpeed_L.ki = data;
                        Save_All_Data();
                        delay_ms(10);
                        USART_Printf(&CKP, "MOTOR_L.t1.txt=\"%f\"\xff\xff\xff", PID_MotorSpeed_L.ki);

                        break;
                    case 'F':
                        PID_MotorSpeed_L.kd = data;
                        Save_All_Data();
                        delay_ms(10);
                        USART_Printf(&CKP, "MOTOR_L.t2.txt=\"%f\"\xff\xff\xff", PID_MotorSpeed_L.kd);
                        break;
                    
                    // 转向PID参数 (G, H, I)
                    case 'G':
                        PID_Turning.kp = data;
                        Save_All_Data();
                        delay_ms(10);
                        USART_Printf(&CKP, "Turn.t0.txt=\"%f\"\xff\xff\xff", PID_Turning.kp);
                        break;
                    case 'H':
                        PID_Turning.ki = data;
                        Save_All_Data();
                        delay_ms(10);
                        USART_Printf(&CKP, "Turn.t1.txt=\"%f\"\xff\xff\xff", PID_Turning.ki);
                        break;
                    case 'I':
                        PID_Turning.kd = data;
                        Save_All_Data();
                        delay_ms(10);
                        USART_Printf(&CKP, "Turn.t2.txt=\"%f\"\xff\xff\xff", PID_Turning.kd);
                        break;
                    
                    // 循迹PID参数 (J, K, L)
                    case 'J':
                        PID_Tracking.kp = data;
                        Save_All_Data();
                        delay_ms(10);
                        USART_Printf(&CKP, "Track.t0.txt=\"%f\"\xff\xff\xff", PID_Tracking.kp);
                        break;
                    case 'K':
                        PID_Tracking.ki = data;
                        Save_All_Data();
                        delay_ms(10);
                        USART_Printf(&CKP, "Track.t1.txt=\"%f\"\xff\xff\xff", PID_Tracking.ki);
                        break;
                    case 'L':
                        PID_Tracking.kd = data;
                        Save_All_Data();
                        delay_ms(10);
                        USART_Printf(&CKP, "Track.t2.txt=\"%f\"\xff\xff\xff", PID_Tracking.kd);
                        break;
                    
                    default:
                        // 无效的索引，可以添加错误处理
                        break;
                }
            }
            else
            {
                Command_Clear(&CKP_received);
            }
        }
        
        delay_ms(1); 
    }
}
