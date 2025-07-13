#include "app_button.h"


//*************** K1 回调函数 ***************//
static void K1_Clicked_cb(uint8_t clicks)
{

    
}
static void K1_Long_Pressed_cb(uint8_t ticks)
{
    //K1 长按函数
    
}
static void K1_Pressed_cb()
{
    USART_Printf(&OpenMV,"1\n");
}
static void K1_Released_cb()
{
    //K1 松开函数
}


//*************** K2 回调函数 ***************//
static void K2_Clicked_cb(uint8_t clicks)
{
    //K2 连击函数
    
}
static void K2_Long_Pressed_cb(uint8_t ticks)
{
    //K2 长按函数
}
static void K2_Pressed_cb()
{
    //K2 按下函数
    USART_Printf(&OpenMV,"2\n");
}
static void K2_Released_cb()
{
    //K2 松开函数
}

//*************** K3 回调函数 ***************//
static void K3_Clicked_cb(uint8_t clicks)
{
    //K3 连击函数
}
static void K3_Long_Pressed_cb(uint8_t ticks)
{
    //K3 长按函数
}
static void K3_Pressed_cb()
{
    //K3 按下函数
    USART_Printf(&OpenMV,"0\n");
}
static void K3_Released_cb()
{
    //K3 松开函数
}
void Buttons_Init()
{
    Key_InitTypedef Key_InitStruct;
    Key_InitStruct.key_port = BUTTONS_K1_PORT;
    Key_InitStruct.key_pin = BUTTONS_K1_PIN;
    Key_InitStruct.key_clicked_cb = K1_Clicked_cb;
    Key_InitStruct.key_long_pressed_cb = K1_Long_Pressed_cb;
    Key_InitStruct.key_pressed_cb = K1_Pressed_cb;
    Key_InitStruct.key_released_cb = K1_Released_cb;

    Key_Init(&Button_1, &Key_InitStruct);
    
    Key_InitStruct.key_port = BUTTONS_K2_PORT;
    Key_InitStruct.key_pin = BUTTONS_K2_PIN;
    Key_InitStruct.key_clicked_cb = K2_Clicked_cb;
    Key_InitStruct.key_long_pressed_cb = K2_Long_Pressed_cb;
    Key_InitStruct.key_pressed_cb = K2_Pressed_cb;
    Key_InitStruct.key_released_cb = K2_Released_cb;

    Key_Init(&Button_2, &Key_InitStruct);

    Key_InitStruct.key_port = BUTTONS_K3_PORT;
    Key_InitStruct.key_pin = BUTTONS_K3_PIN;
    Key_InitStruct.key_clicked_cb = K3_Clicked_cb;
    Key_InitStruct.key_long_pressed_cb = K3_Long_Pressed_cb;
    Key_InitStruct.key_pressed_cb = K3_Pressed_cb;
    Key_InitStruct.key_released_cb = K3_Released_cb;

    Key_Init(&Button_3, &Key_InitStruct);
}

void Buttons_Proc()
{
    Key_Proc(&Button_1);
    Key_Proc(&Button_2);
    Key_Proc(&Button_3);
}