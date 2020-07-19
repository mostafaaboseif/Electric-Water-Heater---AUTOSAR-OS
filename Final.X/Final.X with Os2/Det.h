
#ifndef DET_H
#define DET_H

#include "MCAL/Uart.h"

void Det_Init();

void Det_ReportError(uint16_t ModuleId,uint8_t InstanceId,uint8_t ApiId,uint8_t ErrorId);


#endif