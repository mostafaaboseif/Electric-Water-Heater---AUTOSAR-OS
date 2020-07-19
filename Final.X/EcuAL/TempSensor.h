/***************************************************************
*
* Module: TempSensor
*
* File Name: TempSensor.h
*
* Description: Header file for TempSensor Module,
*              implementation is based on AUTOSAR specfications.
*
* Author: Mostafa Amgad
*
* Date:  July 17, 2020
****************************************************************/


#ifndef TEMPSENSOR_H
#define	TEMPSENSOR_H

/*=================================================================
                         INCLUDE FILES
==================================================================*/
/*needed interfaces from external units*/
#include "../MCAL/adc.h"


/*=================================================================
                      FUNCTION PROTOTYPES
==================================================================*/
void TempSensor_Init(Adc_ConfigType*);
Std_ReturnType TempSensor_GetTemp(uint8_t*);

void TempSensor_DeInit(void);

#endif