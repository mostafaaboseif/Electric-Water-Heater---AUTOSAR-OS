#include "I2c.h"

extern Port_ConfigType I2c_ConfigPins[2];

I2c_ConfigType *I2c_ThisConfiguration = NULL ;

void I2c_Init(I2c_ConfigType *Config_Ptr)
{
#if (DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (Config_Ptr == NULL) 
    {
		Det_ReportError(I2C_MODULE_ID, I2C_INSTANCE_ID, 
        I2C_INIT_SID,I2C_E_PARAM_POINTER);
    
	} 
    else if(Config_Ptr->I2c_Status != I2C_UNINIT)
    {
        Det_ReportError(I2C_MODULE_ID, I2C_INSTANCE_ID, 
        I2C_INIT_SID,I2C_E_ALREADY_INITIALIZED);   
    }else
#endif
    {
        Port_Init(&I2c_ConfigPins[0]);
        Port_Init(&I2c_ConfigPins[1]);
    
        I2C_CTL_REG1 |= 0x0F & Config_Ptr->I2c_Mode;
        SET_BIT(I2C_CTL_REG1,5);
        I2C_CTL_REG2 = 0;
        I2C_ADDR_REG = (_XTAL_FREQ/(4*Config_Ptr->I2c_Baudrate))-1;
        I2C_STAT_REG = 0;

        I2c_ThisConfiguration = Config_Ptr;
        I2c_ThisConfiguration->I2c_Status = I2C_IDLE;
    }
}

#if(I2C_DEINIT_API==STD_ON)
void I2c_DeInit()
{
#if (DEV_ERROR_DETECT == STD_ON)
    if(I2c_ThisConfiguration->I2c_Status == I2C_UNINIT)
    {
        Det_ReportError(I2C_MODULE_ID, I2C_INSTANCE_ID, 
        I2C_DEINIT_SID,I2C_E_UNINIT);   
    }
#endif
    {
        CLEAR_REG(I2C_CTL_REG1);
        CLEAR_REG(I2C_CTL_REG2);
        CLEAR_REG(I2C_STAT_REG);
        CLEAR_REG(I2C_ADDR_REG);
    }
}
#endif

uint8_t I2c_WriteSlaveAddress(uint8_t data)
{
  I2C_Master_Wait();
  I2C_BUFF_REG = data;
  while(!I2C_BUSY_BIT);
  I2C_BUSY_BIT = 0;
  return ACKSTAT;
}

Std_ReturnType I2c_WriteIB(I2c_ChannelType Channel, I2c_DataBufferType* DataBufferPtr)
{
#if (DEV_ERROR_DETECT == STD_ON)
    if(I2c_ThisConfiguration->I2c_Status == I2C_UNINIT)
    {
        Det_ReportError(I2C_MODULE_ID, I2C_INSTANCE_ID, 
        I2C_WRITE_SID,I2C_E_UNINIT);   
    }
    else if(DataBufferPtr == NULL)
    {
        Det_ReportError(I2C_MODULE_ID, I2C_INSTANCE_ID, 
        I2C_WRITE_SID,I2C_E_PARAM);   
    }
    else if(Channel != 0)
    {
        Det_ReportError(I2C_MODULE_ID, I2C_INSTANCE_ID, 
        I2C_WRITE_SID,I2C_E_PARAM);   
    }else
#endif
    {
        I2C_Master_Wait();
        I2C_BUFF_REG = *DataBufferPtr;
        while(!I2C_BUSY_BIT);
        I2C_BUSY_BIT = 0;
        return ACKSTAT;
    }
    
    return E_OK;
}
Std_ReturnType I2c_ReadIB ( I2c_ChannelType Channel, I2c_DataBufferType* DataBufferPtr )
{
#if (DEV_ERROR_DETECT == STD_ON)
    if(I2c_ThisConfiguration->I2c_Status == I2C_UNINIT)
    {
        Det_ReportError(I2C_MODULE_ID, I2C_INSTANCE_ID, 
        I2C_READ_SID,I2C_E_UNINIT);   
    }
    else if(DataBufferPtr == NULL)
    {
        Det_ReportError(I2C_MODULE_ID, I2C_INSTANCE_ID, 
        I2C_READ_SID,I2C_E_PARAM);   
    }
    else if(Channel != 0)
    {
        Det_ReportError(I2C_MODULE_ID, I2C_INSTANCE_ID, 
        I2C_READ_SID,I2C_E_PARAM);   
    }else
#endif
    {
        I2C_Master_Wait();
        SET_BIT(I2C_CTL_REG2,RCEN_BIT); // Enable & Start Reception
        while(!I2C_BUSY_BIT); // Wait Until Completion
        I2C_BUSY_BIT = 0; // Clear The Interrupt Flag Bit
        I2C_Master_Wait();
        *DataBufferPtr = I2C_BUFF_REG; // Return The Received Byte
    } 
    return E_OK;
}

#if(I2C_GET_STATUS_API==STD_ON)
I2c_StatusType I2c_GetStatus ( void )
{
    return I2c_ThisConfiguration->I2c_Status;
}
#endif

void I2C_Master_Wait()
{
  while ((I2C_STAT_REG & 0x04) || (I2C_CTL_REG2 & 0x1F));
}
void I2C_Master_Start()
{
  I2C_Master_Wait();
  SET_BIT(I2C_CTL_REG2,SEN_BIT);
}
void I2C_Master_RepeatedStart()
{
  I2C_Master_Wait();
  SET_BIT(I2C_CTL_REG2,RSEN_BIT);
}
void I2C_Master_Stop()
{
  I2C_Master_Wait();
  SET_BIT(I2C_CTL_REG2,PEN_BIT);
}

void I2C_ACK(void)
{
  CLEAR_BIT(I2C_CTL_REG2,ACKDT_BIT);// 0 -> ACK
  I2C_Master_Wait();
  SET_BIT(I2C_CTL_REG2,ACKEN_BIT);// Send ACK
}
void I2C_NACK(void)
{
  SET_BIT(I2C_CTL_REG2,ACKDT_BIT); // 1 -> NACK
  I2C_Master_Wait();
  SET_BIT(I2C_CTL_REG2,ACKEN_BIT);
  ACKEN = 1; // Send NACK
}

