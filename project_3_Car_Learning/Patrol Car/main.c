#include "control.h"

int main(void)
{
    // 系统级配置初始化
    SYSCFG_DL_init();
    
    Modules_Init();
    Disable_TB6612();
    // 进入主循环，执行任务
    while (1) 
    {   
        JY62_UpdateAngles();
        USART_Printf(&HC_06,"%f\n", JY62_Get_Yaw());
    }
}