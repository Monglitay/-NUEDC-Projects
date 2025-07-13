#include "command.h"

void Command_Init(Command_Typedef *command)
{
    command->readIndex = 0;
    command->writeIndex = 1;
}
/**
* @brief 增加读索引
* @param length 要增加的长度
*/
void Command_AddReadIndex(Command_Typedef *command,uint8_t length) {
    command->readIndex += length;
    command->readIndex %= BUFFER_SIZE;
}

/**
* @brief 读取第i位数据 超过缓存区长度自动循环
* @param i 要读取的数据索引
*/

uint8_t Command_Read(Command_Typedef *command,uint8_t i) {
    uint8_t index = i % BUFFER_SIZE;
    return command->buffer[index];
}

/**
* @brief 计算未处理的数据长度
* @return 未处理的数据长度
* @retval 0 缓冲区为空
* @retval 1~BUFFER_SIZE-1 未处理的数据长度
* @retval BUFFER_SIZE 缓冲区已满
*/

uint8_t Command_GetLength(Command_Typedef *command) {
    return (command->writeIndex + BUFFER_SIZE - command->readIndex) % BUFFER_SIZE;
}


/**
* @brief 计算缓冲区剩余空间
* @return 剩余空间
* @retval 0 缓冲区已满
* @retval 1~BUFFER_SIZE-1 剩余空间
* @retval BUFFER_SIZE 缓冲区为空
*/
uint8_t Command_GetRemain(Command_Typedef *command) {
    return BUFFER_SIZE - Command_GetLength(command);
}

uint8_t Command_Write(Command_Typedef *command, uint8_t *data, uint8_t length) {
    // 如果缓冲区不足 则不写入数据 返回0
    if (Command_GetRemain(command) < length) {
        return 0;
    }
    
    // 使用memcpy函数将数据写入缓冲区
    if (command->writeIndex + length < BUFFER_SIZE) {
        // 数据可以一次性写入
        memcpy(command->buffer + command->writeIndex, data, length);
        command->writeIndex += length ; // 更新写指针并取模
    } else {
        // 数据需要分两次写入
        uint8_t firstLength = BUFFER_SIZE - command->writeIndex;
        // 写入第一部分
        memcpy(command->buffer + command->writeIndex, data, firstLength);
        // 写入第二部分
        memcpy(command->buffer, data + firstLength, length - firstLength);
        command->writeIndex = length - firstLength;  // 这种情况下不需要取模，因为必然小于BUFFER_SIZE
    }
    
    return length;
}
/**
* @brief 尝试获取一条指令
* @param command 指令存放指针
* @return 获取的指令长度
* @retval 0 没有获取到指令
*/
uint8_t Command_GetCommand(Command_Typedef *command,uint8_t *buffer) {
    // 寻找完整指令
    while (1) {
        // 如果缓冲区长度小于COMMAND_MIN_LENGTH 则不可能有完整的指令
        if (Command_GetLength(command) < COMMAND_MIN_LENGTH) {
        return 0;
        }
        // 如果不是包头 则跳过 重新开始寻找
        if (Command_Read(command,command->readIndex) != 0xAA) {
        Command_AddReadIndex(command,1);
        continue;
        }
        // 如果缓冲区长度小于指令长度 则不可能有完整的指令
        uint8_t length = Command_Read(command,command->readIndex + 1);
        if (Command_GetLength(command) < length) {
        return 0;
        }
        // 如果校验和不正确 则跳过 重新开始寻找
        uint8_t sum = 0;
        for (uint8_t i = 0; i < length - 1; i++) {
        sum += Command_Read(command,command->readIndex + i);
        }
        if (sum != Command_Read(command,command->readIndex + length - 1)) {
        Command_AddReadIndex(command,1);
        continue;
        }
        // 如果找到完整指令 则将指令写入command 返回指令长度
        for (uint8_t i = 0; i < length; i++) {
        buffer[i] = Command_Read(command,command->readIndex + i);
        }
        Command_AddReadIndex(command,length);
        return length;
    }
}