#ifndef __COMMAND_H_
#define __COMMAND_H_

#include "ti_msp_dl_config.h"
#include <string.h>

#define BUFFER_SIZE 256
#define COMMAND_MIN_LENGTH 8
typedef  struct 
{
    uint8_t buffer[BUFFER_SIZE];
    // 循环缓冲区读索引
    uint8_t readIndex;
    // 循环缓冲区写索引
    uint8_t writeIndex;
}Command_Typedef;

uint8_t Command_Write(Command_Typedef *command,uint8_t *data, uint8_t length);
uint8_t Command_GetCommand(Command_Typedef *command,uint8_t *buffer);
void Command_Init(Command_Typedef *command);

#endif