/***************************************************************
*
* Module: TempSensor
*
* File Name: TempSensor.c
*
* Description: Source file for TempSensor Module,
*              implementation is based on AUTOSAR specfications.
*
* Author: Mostafa Amgad
*
* Date:  July 17, 2020
****************************************************************/


/*=================================================================
                            INCLUDES
*================================================================*/
#include "TempSensor.h"


/*=================================================================
                     APIs IMPLEMENTATION
*================================================================*/
void TempSensor_Init(Adc_ConfigType* ConfigPtr)
{  
    Adc_Init(ConfigPtr);
}

void TempSensor_GetTemp(uint8_t* a)
{
    while(Adc_ReadGroup(0,a) != E_OK);
    //if(*a == 28 | *a==14) return E_NOT_OK;
    return E_OK;
}

void TempSensor_DeInit(void)
{
    Adc_DeInit();
}