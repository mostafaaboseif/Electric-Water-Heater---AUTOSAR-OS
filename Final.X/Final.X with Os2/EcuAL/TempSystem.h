
#ifndef TEMPSYSTEM_H
#define	TEMPSYSTEM_H

#include "../MCAL/Port.h"
#include "../MCAL/Pwm.h"

void TempSystem_Init(Port_ConfigType*);
void TempSystem_OpenHeater(void);
void TempSystem_OpenCooler(void);
void TempSystem_SetCoolerPower(uint8_t);
void TempSystem_CloseHeater(void);
void TempSystem_CloseCooler(void);

#if(EXTRA_FEATURES==STD_ON)
void TempSystem_DeInit(void);
#endif

#endif