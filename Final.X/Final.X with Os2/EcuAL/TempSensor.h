
#ifndef TEMPSENSOR_H
#define	TEMPSENSOR_H

#include "../MCAL/Port.h"
#include "../MCAL/adc.h"

void TempSensor_Init(Adc_ConfigType*);
Std_ReturnType TempSensor_GetTemp(uint8_t*);

#if(EXTRA_FEATURES==STD_ON)
void TempSensor_DeInit(void);
#endif

#endif