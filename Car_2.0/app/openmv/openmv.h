#ifndef _OPENMV_H_
#define _OPENMV_H_
#include "usart.h"
#include "ti_msp_dl_config.h"
USART_Typedef OpenMV;
void OpenMV_Init();
void OpenMV_Read_Command(uint8_t *buffer);
#endif