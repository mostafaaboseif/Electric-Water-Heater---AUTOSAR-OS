#ifndef PORT_H
#define PORT_H

#include "../common_macros.h"
#include "../std_types.h"
#include "../micro_config.h"
#include "../PreCompileConfig.h"
#include "Dio.h"
#include "interrupt.h"
#include "../Det.h"

/* Port Module Id */
#define PORT_MODULE_ID    0x124
/* Port Instance Id */
#define PORT_INSTANCE_ID  0x00

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for Port INIT */
#define PORT_INIT_SID           			  0x00
/*Service ID for Port Set Pin Direction*/
#define PORT_SET_PIN_DIRECTION_SID            0x01
/*Service ID for Port Set Pin Direction*/
#define PORT_Refresh_PORT_DIRECTION_SID       0x02
/*Service ID for Set Pin Mode*/
#define PORT_SET_PIN_MODE_SID           	  0x04

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
//Invalid Port Pin ID requested
#define PORT_E_PARAM_PIN 0x0A
//Port Pin not configured as changeable
#define PORT_E_DIRECTION_UNCHANGEABLE 0x0B
//API Port_SetPinMode service called when mode is unchangeable.
#define PORT_E_MODE_UNCHANGEABLE 0x0E
//API service called without module initialization
#define PORT_E_UNINIT 0x0F
//APIs called with a Null Pointer
#define PORT_E_PARAM_POINTER 0x10

#define DDR_BASE    0x085
#define PORT_BASE   0x005
#define PINS_NUM  24

typedef uint8_t Port_PinType ;

typedef enum Port_PinDirectionType{
	PORT_PIN_IN ,
	PORT_PIN_OUT
}Port_PinDirectionType;

typedef enum Port_PortType{
    PortA, PortB, PortC, PortD, PortE
}Port_PortType;

#if(EXTRA_FEATURES==STD_ON)
typedef enum {
	PULL_UP ,
	PULL_DOWN,
    NO_PULL
}Port_PullConfigType ;

typedef enum{
	NOT_CHANGEABLE,
    CHANGEABLE
}Port_PinChangeableType;

typedef enum{
    DIO,AIN,AOUT,I2C
}Port_PinModeType;

typedef enum {
    PORT_NOT_INITIALIZED,
    PORT_INITIALIZED  
}Port_PortStatusType;
#endif

typedef struct {
    Port_PortType Port;
	Port_PinType Pin  ;
    Port_PinDirectionType PinDirection  ;
#if(EXTRA_FEATURES==STD_ON)
    uint8 PinIntitLevel;
    Port_PullConfigType PullConfig;
    Port_PinModeType PinMode;   
    Port_PinChangeableType PinDirChangeable;
    Port_PinChangeableType PinModeChangeable;
    Port_PortStatusType Port_PortStatus;
#endif
}Port_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

void Port_Init(Port_ConfigType* ConfigPtr);
void Port_InitPort(Port_ConfigType* ConfigPtr);

#if(EXTRA_FEATURES==STD_ON)
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);
void Port_RefreshPortDirection();
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);
#endif

#endif