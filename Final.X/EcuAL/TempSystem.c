/***************************************************************
*
* Module: TempSystem
*
* File Name: TempSystem.c
*
* Description: Source file for TempSystem Module,
*              implementation is based on AUTOSAR specfications.
*
* Author: Mostafa Amgad
*
* Date:  July 17, 2020
****************************************************************/


/*=================================================================
                            INCLUDES
*================================================================*/
#include "TempSystem.h"

/*=================================================================
                    GLOBAL EXTERN VARIABLES
*================================================================*/
extern Pwm_ConfigType Pwm_Config;

/*=================================================================
                     APIs IMPLEMENTATION
*================================================================*/
void TempSystem_Init(Port_ConfigType* ConfigPtr)
{ 
   Pwm_Init(&Pwm_Config);
   Port_Init(&ConfigPtr[0]);
   Port_Init(&ConfigPtr[1]);      
}

void TempSystem_OpenHeater(void)
{
    Dio_WriteChannel(HEATER_CHANNEL,HIGH);
}

void TempSystem_OpenCooler(void)
{
    Dio_WriteChannel(COOLER_CHANNEL,HIGH);
}

void TempSystem_SetCoolerPower(uint8_t power)
{
    Pwm_SetDutyCycle(0,power);
    __delay_ms(10);
}

void TempSystem_CloseHeater(void)
{
    Dio_WriteChannel(HEATER_CHANNEL,LOW);
}

void TempSystem_CloseCooler(void)
{
    Pwm_SetDutyCycle(0,0);
    //Dio_WriteChannel(COOLER_CHANNEL,LOW);
}

void TempSystem_DeInit(void)
{
    Dio_WriteChannel(COOLER_CHANNEL,LOW);
    Dio_WriteChannel(HEATER_CHANNEL,LOW); 
}