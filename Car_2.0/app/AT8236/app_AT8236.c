#include "app_AT8236.h"
void AT8236_AOUT_Slip()
{
    AIN1_OUT(0);
    AIN2_OUT(0);
}

void AT8236_BOUT_Slip()
{
    BIN1_OUT(0);
    BIN2_OUT(0);
}
void AT8236_AOUT_Stop()
{
    AIN1_OUT(1000);
    AIN2_OUT(1000);
}
void AT8236_BOUT_Stop()
{
    BIN1_OUT(1000);
    BIN2_OUT(1000);
}
void AT8236_AOUT_FD(int ccr)
{
    if(ccr>0)
    {
        AIN1_OUT(ccr);
        AIN2_OUT(0);
    }
    else if(ccr==0) 
    {
            AT8236_AOUT_Slip();
    }
    else
    {
        AIN1_OUT(0);
        AIN2_OUT(-ccr);
    }
}
void AT8236_AOUT_SD(int ccr)
{
    if(ccr>0)
    {
        AIN1_OUT(1000);
        AIN2_OUT(ccr);
    }
    else if(ccr==0) 
    {
            AT8236_AOUT_Slip();
    }
    else
    {
        AIN1_OUT(-ccr);
        AIN2_OUT(1000);
    }
}
void AT8236_BOUT_FD(int ccr)
{
    if(ccr>0)
    {
        BIN1_OUT(ccr);
        BIN2_OUT(0);
    }
    else if(ccr==0) 
    {
            AT8236_BOUT_Slip();
    }
    else
    {
        BIN1_OUT(0);
        BIN2_OUT(-ccr);
    }
}
void AT8236_BOUT_SD(int ccr)
{
    if(ccr>0)
    {
        BIN1_OUT(1000);
        BIN2_OUT(ccr);
    }
    else if(ccr==0) 
    {
            AT8236_BOUT_Slip();
    }
    else
    {
        BIN1_OUT(-ccr);
        BIN2_OUT(1000);
    }
}