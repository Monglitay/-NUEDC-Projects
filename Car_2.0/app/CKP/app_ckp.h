#ifndef __APP_CKP_H_
#define __APP_CKP_H_

#include "ti_msp_dl_config.h"
#include "usart.h"
#include "command.h"

USART_Typedef CKP;
Command_Typedef CKP_received;

void CKP_Init();
uint8_t CKP_Read_Command(uint8_t* buffer);
#endif

