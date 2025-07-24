#include "app_adc.h"
volatile bool gCheckADC; 
void ADC_Init()
{
    NVIC_EnableIRQ(ADC_VOLTAGE_INST_INT_IRQN);
}
float ADC_GetValue(void)
{
        unsigned int gAdcResult = 0;
        gCheckADC = false;
        //软件触发ADC开始转换
        DL_ADC12_startConversion(ADC_VOLTAGE_INST);
        //如果当前状态为正在转换中则等待转换结束
        while (false == gCheckADC) {

        }
        //获取数据
        gAdcResult = DL_ADC12_getMemResult(ADC_VOLTAGE_INST, ADC_VOLTAGE_ADCMEM_ADC_CH4);

        //清除标志位
        DL_ADC12_enableConversions(ADC_VOLTAGE_INST);
    
    float voltage_value = gAdcResult/3983.0*7.4;
    return voltage_value;
}

void ADC_VOLTAGE_INST_IRQHandler(void)
{
    //查询并清除ADC中断
    switch (DL_ADC12_getPendingInterrupt(ADC_VOLTAGE_INST))
    {
        //检查是否完成数据采集
        case DL_ADC12_IIDX_MEM0_RESULT_LOADED:
            gCheckADC = true;//将标志位置1
            break;
        default:
            break;
    }
}