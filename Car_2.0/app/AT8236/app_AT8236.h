#ifndef __AT8236_H_
#define __AT8236_H_
#include "ti_msp_dl_config.h"

#define AIN1_OUT(x) (DL_TimerG_setCaptureCompareValue(AIN_INST,x,GPIO_AIN_C0_IDX))
#define AIN2_OUT(x) (DL_TimerG_setCaptureCompareValue(AIN_INST,x,GPIO_AIN_C1_IDX))
#define BIN1_OUT(x) (DL_TimerG_setCaptureCompareValue(BIN_INST,x,GPIO_BIN_C0_IDX))
#define BIN2_OUT(x) (DL_TimerG_setCaptureCompareValue(BIN_INST,x,GPIO_BIN_C1_IDX))

void AT8236_AOUT_Slip();
void AT8236_BOUT_Slip();
void AT8236_AOUT_Stop();
void AT8236_BOUT_Stop();
void AT8236_AOUT_FD(int ccr);
void AT8236_BOUT_FD(int ccr);
void AT8236_AOUT_SD(int ccr);
void AT8236_BOUT_SD(int ccr);

#endif