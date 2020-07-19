
#include "Det.h"

extern Uart_ConfigType Uart_Config;

void Det_Init()
{
    Uart_Init(&Uart_Config);
}

void Det_ReportError(uint16_t ModuleId,uint8_t InstanceId,uint8_t ApiId,uint8_t ErrorId)
{
    DISABLE_INTERRUPTS;
    while(Uart_WriteString("\nDEVELOPMENT_ERROR")!=E_OK){}
    while(Uart_WriteString("\nModuleId: 0x")!=E_OK){} 
    Uart_WriteInt((uint8_t)ModuleId);
    Uart_WriteInt(ModuleId<<8); 
    while(Uart_WriteString("\nInstanceId: 0x")!=E_OK){}    
    Uart_WriteInt(InstanceId);
    while(Uart_WriteString("\nApiId: 0x")!=E_OK){}    
    Uart_WriteInt(ApiId);
    while(Uart_WriteString("\nErrorId: 0x")!=E_OK){}    
    Uart_WriteInt(ErrorId);
    
    while(1)
	{

	}
}