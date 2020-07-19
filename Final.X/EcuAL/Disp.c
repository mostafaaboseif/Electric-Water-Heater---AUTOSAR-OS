/***************************************************************
*
* Module: Disp
*
* File Name: Disp.c
*
* Description: Source file for Disp Module,
*              implementation is based on AUTOSAR specfications.
*
* Author: Mostafa Amgad
*
* Date:  July 17, 2020
****************************************************************/

/*=================================================================
                            INCLUDES
*================================================================*/
#include "Disp.h"

/*=================================================================
                    GLOBAL STATIC VARIABLES
*================================================================*/
static uint16_t BlinkingPeriod;

/*=================================================================
                    GLOBAL EXTERN VARIABLES
*================================================================*/
extern Port_ConfigType Disp_PinsConfiguration[3];

/*=================================================================
                LOCAL FUNCTIONS PROTOTYPE
*================================================================*/
static uint8_t Disp_GetDislayValue(unsigned char v);

/*=================================================================
                     APIs IMPLEMENTATION
*================================================================*/
void Disp_Init(Disp_ConfigType* ConfigPtr)
{
 
    Disp_PinsConfiguration[0].Port = ConfigPtr->DisplayPort;
    Port_InitPort(&Disp_PinsConfiguration[0]);
    for(int i=0 ; i<ConfigPtr->NbDigits;i++)
    {
      Disp_PinsConfiguration[i+1].Port = ConfigPtr->EnablePort;   
      Disp_PinsConfiguration[i+1].Pin = ConfigPtr->EnablePins[i];  
      Port_Init(&Disp_PinsConfiguration[i+1]);
    }
     BlinkingPeriod = ConfigPtr->BlinkingPeriod;
}

void Disp_DisplayNb(uint8_t var, Disp_ModeType Mode)
{
    static uint16_t blinkFlag=0;
    if(Mode == FIXED)
    {
        Dio_WritePort(PortA, 0x20);
        Dio_WritePort(PortD, Disp_GetDislayValue(var%10));
        __delay_ms(DISPLAY_INNER_DELAY);
        Dio_WritePort(PortA, 0x10);
        Dio_WritePort(PortD, Disp_GetDislayValue(var/10));
        __delay_ms(DISPLAY_INNER_DELAY);
    }
    else if(Mode == BLINKING)
    {
        if(blinkFlag < (BlinkingPeriod/(DISPLAY_INNER_DELAY*2)))
        {
           Dio_WritePort(PortA, 0x20);
           Dio_WritePort(PortD, Disp_GetDislayValue(var%10));
           __delay_ms(DISPLAY_INNER_DELAY);	
           Dio_WritePort(PortA, 0x10);
           Dio_WritePort(PortD, Disp_GetDislayValue(var/10));
           __delay_ms(DISPLAY_INNER_DELAY);	
        }
        else
        {
           Dio_WritePort(PortA, 0x20);
           Dio_WritePort(PortD, 0x00);
           __delay_ms(DISPLAY_INNER_DELAY);	
           Dio_WritePort(PortA, 0x10);
           Dio_WritePort(PortD, 0x00);
           __delay_ms(DISPLAY_INNER_DELAY);	
        }
        blinkFlag = (blinkFlag+1)%(BlinkingPeriod/DISPLAY_INNER_DELAY);
    }
}

void Disp_Close()
{
    Dio_WritePort(PortA, 0x00);
    Dio_WritePort(PortD, 0x00);
}

static uint8_t Disp_GetDislayValue(unsigned char v)
{
  switch(v)
  {
    case 0: return 0x3F;
    case 1: return 0x06;
    case 2: return 0x5B;
    case 3: return 0x4F;
    case 4: return 0x66;
    case 5: return 0x6D;
    case 6: return 0x7D;
    case 7: return 0x07;
    case 8: return 0x7F;
    case 9: return 0x6F;
    case 10: return 0x77;
    case 11: return 0x7c;
    case 12: return 0x58;
    case 13: return 0x5E;
    case 14: return 0x79;
    case 15: return 0x71;
    default:
    return 0;
  }
}

