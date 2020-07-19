/***************************************************************
*
* Module: Disp
*
* File Name: Disp.h
*
* Description: Header file for Disp Module,
*              implementation is based on AUTOSAR specfications.
*
* Author: Mostafa Amgad
*
* Date:  July 17, 2020
****************************************************************/


#ifndef DISP_H
#define	DISP_H

/*=================================================================
                         INCLUDE FILES
==================================================================*/
/*needed interfaces from external units*/
#include "../MCAL/Dio.h"
#include "../MCAL/Gpt.h"

/*=================================================================
                       Module Data Types
==================================================================*/
typedef enum{
    FIXED,BLINKING
}Disp_ModeType;

typedef struct {
    Port_PortType DisplayPort;  //port to put the displayed data
    Port_PortType EnablePort;  //which port to be used to enable the 7 segment display
    Port_PinType EnablePins[2];  //enable pins
    uint8_t NbDigits;  //number of digits used
    uint16_t BlinkingPeriod;  
}Disp_ConfigType;


/*=================================================================
                      FUNCTION PROTOTYPES
==================================================================*/
void Disp_Init(Disp_ConfigType*);

void Disp_DisplayNb(uint8_t var, Disp_ModeType Mode);

void Disp_Close();


#endif   /*Disp.h*/