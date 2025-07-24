#include "test_ckp.h"
void Test_CKP()
{
    Broad_Init();

    while (1) 
    {
    uint8_t buffer[10] = {0};
    CKP_Read_Command(buffer);
    if(buffer[0]==0xfe)
    {
        Command_Clear(&CKP_received);
        Debug_Proc();
    }

    }


}