#include "TempSensor.h"


void TempSensor_Init(Adc_ConfigType* ConfigPtr)
{  
    Adc_Init(ConfigPtr);
}

Std_ReturnType TempSensor_GetTemp(uint8_t* a)
{
    while(Adc_ReadGroup(0,a) != E_OK);
    //if(*a == 28 | *a==14) return E_NOT_OK;
    return E_OK;
}

#if(EXTRA_FEATURES==STD_ON)
void TempSensor_DeInit(void)
{
    Adc_DeInit();
}
#endif