#include "Dio.h"

Dio_ConfigGroupChannelType Dio_ConfigGroupChannel = 
{
    PortB,  Pin4,
    PortB,  Pin1,
    PortB,  Pin3,
    PortB,  Pin7,
    PortC,  Pin2,
    PortC,  Pin5
};

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level) {
#if (DEV_ERROR_DETECT == STD_ON)
	/* Check if the used channel is within the valid range */
	if (DIO_CONFIGURED_CHANNLES <= ChannelId)
	{

		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_WRITE_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
	}
    else       
#endif
    {
        volatile Dio_PortType * Port_Ptr = NULL;   
        Port_Ptr = &HWREG(PORT_BASE, Dio_ConfigGroupChannel.Channels[ChannelId].Port);

        if (Level == HIGH) 
            SET_BIT(*Port_Ptr, Dio_ConfigGroupChannel.Channels[ChannelId].Channel);
        else if (Level == LOW)
            CLEAR_BIT(*Port_Ptr, Dio_ConfigGroupChannel.Channels[ChannelId].Channel);
    }  
}

void Dio_ToggleChannel(Dio_ChannelType ChannelId) 
{
#if (DEV_ERROR_DETECT == STD_ON)
	/* Check if the used channel is within the valid range */
	if (DIO_CONFIGURED_CHANNLES <= ChannelId)
	{

		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_TOGGLE_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
	}
    else       
#endif
    {    
        volatile Dio_PortType * Port_Ptr = NULL;   
        Port_Ptr = &HWREG(PORT_BASE, Dio_ConfigGroupChannel.Channels[ChannelId].Port);
        TOGGLE_BIT(*Port_Ptr, Dio_ConfigGroupChannel.Channels[ChannelId].Channel);      
    }
}

/************************************************************************************
 * Name: Dio_ReadChannel
 * Parameters (in): ChannelId - ID of DIO channel.
 * Return value: Dio_LevelType
 * Description: Function to return the value of the specified DIO channel.
 ************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId) 
{
    #if (DEV_ERROR_DETECT == STD_ON)
	/* Check if the used channel is within the valid range */
	if (DIO_CONFIGURED_CHANNLES <= ChannelId)
	{

		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_READ_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
	}
    else       
#endif
    {
        volatile Dio_PortType * Pin_Ptr = NULL;
        Dio_LevelType output = LOW;
        Pin_Ptr = &HWREG(PORT_BASE, Dio_ConfigGroupChannel.Channels[ChannelId].Port);
        uint8_t x = Dio_ConfigGroupChannel.Channels[ChannelId].Channel;
        if (BIT_IS_SET(*Pin_Ptr, x)) 
            output = HIGH;
        else 
            output = LOW;
        return output;
    }
    return E_NOT_OK ;
}

void Dio_WritePort ( Dio_PortType PortId, Dio_PortLevelType Level )
{
    volatile uint8_t * Port_Ptr = NULL;   
    Port_Ptr = &HWREG(PORT_BASE, PortId); 
        SET_REG(*Port_Ptr, Level);     
}