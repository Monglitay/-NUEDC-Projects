#include "test_adc.h"
void Test_ADC()
{
    Broad_Init();
    NVIC_EnableIRQ(ADC_VOLTAGE_INST_INT_IRQN);
    while (1) {

        float v = 0;
        v = ADC_GetValue();
        USART_Printf(&BLE05,"%f\n",v);
    }
}
