
#ifndef DISP_H
#define	DISP_H

#include <xc.h>
#include <stdint.h>
#include "../MCAL/Port.h"
#include "../MCAL/Dio.h"
#include "../MCAL/Gpt.h"

typedef enum{
    FIXED,BLINKING
}Disp_ModeType;

typedef struct {
    Port_PortType DisplayPort; 
    Port_PortType EnablePort;
    Port_PinType EnablePins[2];
    uint8_t NbDigits;
    uint16_t BlinkingPeriod;
}Disp_ConfigType;


void Disp_Init(Disp_ConfigType*);

void Disp_DisplayNb(uint8_t var, Disp_ModeType Mode);

void Disp_Close();

static uint8_t Disp_GetDislayValue(uint8_t v);



#endif