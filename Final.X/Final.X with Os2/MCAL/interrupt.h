
#ifndef INTERRUPT_H
#define	INTERRUPT_H

#include <xc.h>
#include "Port.h"

#define ENABLE_INTERRUPTS   GIE=1
#define DISABLE_INTERRUPTS   GIE=0

typedef enum {
    TIMER,    
    ADC,
    UART_TX,
    UART_RX,
    EXTERNAL_OR_SW
}Interrupt_SourceType;

void Interrupt_Enable(Interrupt_SourceType Interrupt_Source, void (*callback)());

void Interrupt_Disable(Interrupt_SourceType Interrupt_Source);

void Interrupt_SwTrigger();

#endif