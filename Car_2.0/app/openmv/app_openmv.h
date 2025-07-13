#ifndef _OPENMV_H_
#define _OPENMV_H_
#include "usart.h"
#include "ti_msp_dl_config.h"
#include "command.h"
USART_Typedef OpenMV;
Command_Typedef openmv_recvied;
void OpenMV_Init();
uint8_t OpenMV_Read_Command(uint8_t *buffer);
#endif