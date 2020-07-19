/***************************************************************
*
* Module: TempSystem
*
* File Name: TempSystem.h
*
* Description: Header file for TempSystem Module,
*              implementation is based on AUTOSAR specfications.
*
* Author: Mostafa Amgad
*
* Date:  July 17, 2020
****************************************************************/

#ifndef TEMPSYSTEM_H
#define	TEMPSYSTEM_H

/*=================================================================
                         INCLUDE FILES
==================================================================*/
/*needed interfaces from external units*/
#include "../MCAL/Pwm.h"

/*=================================================================
                      FUNCTION PROTOTYPES
==================================================================*/
void TempSystem_Init(Port_ConfigType*);
void TempSystem_OpenHeater(void);
void TempSystem_OpenCooler(void);
void TempSystem_SetCoolerPower(uint8_t);
void TempSystem_CloseHeater(void);
void TempSystem_CloseCooler(void);
void TempSystem_DeInit(void);

#endif   /*TempSystem*/