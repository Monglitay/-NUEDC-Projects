#ifndef _APP_BUTTON_H_
#define _APP_BUTTON_H_
#include "key.h"
#include "ti_msp_dl_config.h"
#include "app_openmv.h"
void Buttons_Init();
void Buttons_Proc();

Key_TypeDef Button_1;
Key_TypeDef Button_2;
Key_TypeDef Button_3;

#endif