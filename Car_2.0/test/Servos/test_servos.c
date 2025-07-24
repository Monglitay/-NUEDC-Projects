#include "test_servos.h"

void Test_Servos()
{
    SYSCFG_DL_init();
    BLE05_Init();
    Servos_Init();
    USART_Printf(&BLE05,"Hello\n");
    Servo_Set_Angle(&Turning_Servo, 0);
    delay_ms(5000);
    Servo_Set_Angle(&Turning_Servo, 45);
    delay_ms(5000);
    Servo_Set_Angle(&Turning_Servo, 90);
    delay_ms(5000);
    Servo_Set_Angle(&Turning_Servo, 135);
    delay_ms(5000);
    Servo_Set_Angle(&Turning_Servo, 180);

}