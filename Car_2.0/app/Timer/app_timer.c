#include "app_timer.h"

void Timer_Init()
{
    //NVIC_EnableIRQ(TIMER_Sensor_Update_INST_INT_IRQN);
    //DL_Timer_startCounter(TIMER_Sensor_Update_INST);
    NVIC_EnableIRQ(TIMER_Encoder_Update_INST_INT_IRQN);
    DL_Timer_startCounter(TIMER_Encoder_Update_INST);
    NVIC_EnableIRQ(TIMER_Control_INST_INT_IRQN);
    DL_Timer_startCounter(TIMER_Control_INST);
}

/*void TIMER_Sensor_Update_INST_IRQHandler(void)
{
    switch (DL_TimerG_getPendingInterrupt(TIMER_Sensor_Update_INST)){
        case DL_TIMER_IIDX_ZERO:
            JY61P_Update_Angles();
            break;
        default:
            break;
    }
}*/

void TIMER_Control_INST_IRQHandler(void)
{
    switch (DL_TimerG_getPendingInterrupt(TIMER_Control_INST)){
        case DL_TIMER_IIDX_ZERO:
            Motor_Proc();
            Servos_Proc();
            break;
        default:
            break;
    }
}