#ifndef DIO_H
#define DIO_H

#include "../common_macros.h"
#include "../std_types.h"
#include "../micro_config.h"
#include "Port.h"

/* Dio Module Id */
#define DIO_MODULE_ID    0x120
/* Dio Instance Id */
#define DIO_INSTANCE_ID  0x00

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for DIO read Channel */
#define DIO_READ_CHANNEL_SID            0x00
/* Service ID for DIO write Channel */
#define DIO_WRITE_CHANNEL_SID           0x01
/* Service ID for DIO toggle Channel */
#define DIO_TOGGLE_CHANNEL_SID           0x01

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* DET code to report Invalid Channel */
#define DIO_E_PARAM_INVALID_CHANNEL_ID  0x0A
/* Dio_Init API service called with NULL pointer parameter */
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Type definition for Dio_ChannelType used by the DIO APIs */
typedef uint8_t Dio_ChannelType;

/* Type definition for Dio_PortType used by the DIO APIs */
typedef uint8_t Dio_PortType;

/* Type definition for Dio_LevelType used by the DIO APIs */
typedef uint8_t Dio_PortLevelType;

typedef uint8_t Dio_StateType;

typedef enum{
    LOW,HIGH
}Dio_LevelType;

enum{
    DOWN_BUTTON_CHANNEL,
    ONOFF_BUTTON_CHANNEL,
    UP_BUTTON_CHANNEL,
    HEATING_LED_CHANNEL,
    COOLER_CHANNEL,
    HEATER_CHANNEL
}Dio_Channels;

typedef struct {
    /* Member contains the ID of the Port that this channel belongs to */
    Dio_PortType Port;
    /* Member contains the ID of the Channel*/
    Dio_ChannelType Channel;
} Dio_ConfigChannelType;

/* Data Structure required for initializing the Dio Driver */
typedef struct {
    Dio_ConfigChannelType Channels[DIO_CONFIGURED_CHANNLES];
} Dio_ConfigGroupChannelType;

/*******************************************************************************
 *                           Functions Prototype                               *
 *******************************************************************************/

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
void Dio_ToggleChannel(Dio_ChannelType ChannelId);
void Dio_WritePort ( Dio_PortType PortId, Dio_PortLevelType Level );
Dio_PortLevelType Dio_ReadPort ( Dio_PortType PortId );

#endif
