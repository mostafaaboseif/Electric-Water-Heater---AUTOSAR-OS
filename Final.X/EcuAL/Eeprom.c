/***************************************************************
*
* Module: Eeprom
*
* File Name: Eeprom.c
*
* Description: Source file for Eeprom Module,
*              implementation is based on AUTOSAR specfications.
*
* Author: Mostafa Amgad
*
* Date:  July 17, 2020
****************************************************************/


/*=================================================================
                            INCLUDES
*================================================================*/
#include "Eeprom.h"

/*=================================================================
                    GLOBAL STATIC VARIABLES
*================================================================*/
Eep_AddressType* Eep_SlaveAddress;

Eep_ConfigType* Eep_ThisConfiguration = NULL;

/*=================================================================
                    GLOBAL EXTERN VARIABLES
*================================================================*/
extern I2c_ConfigType I2c_Config;

/*=================================================================
                     APIs IMPLEMENTATION
*================================================================*/
void Eep_Init(Eep_ConfigType* ConfigPtr)
{    
#if (DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (ConfigPtr == NULL) 
    {
		Det_ReportError(EEP_MODULE_ID, EEP_INSTANCE_ID, 
        EEP_INIT_SID,EEP_E_PARAM_POINTER);
	} 
    else if(ConfigPtr->Eep_Status != EEP_UNINIT)
    {
        Det_ReportError(EEP_MODULE_ID, EEP_INSTANCE_ID, 
        EEP_INIT_SID,EEP_E_ALREADY_INITIALIZED);   
    }else
#endif
    {
        I2c_Init(&I2c_Config);
        *Eep_SlaveAddress = ConfigPtr->Eep_SlaveAddress;
        Eep_ThisConfiguration = ConfigPtr;
        Eep_ThisConfiguration->Eep_Status =  EEP_IDLE;  
    }
}

Std_ReturnType Eep_Write(Eep_AddressType EepromAddress, uint8* DataBufferPtr, Eep_LengthType Length)
{
#if (DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */	
    if(Eep_ThisConfiguration->Eep_Status == EEP_UNINIT)
    {
        Det_ReportError(EEP_MODULE_ID, EEP_INSTANCE_ID, 
        EEP_WRITE_SID,EEP_E_UNINIT);   
    }
    else if(EepromAddress > 0xFF /*1024*pow(2,Eep_Size)/8*/)
    {
        Det_ReportError(EEP_MODULE_ID, EEP_INSTANCE_ID, 
        EEP_WRITE_SID,EEP_E_PARAM_ADDRESS);   
    }
    else if(DataBufferPtr == NULL)
    {
        Det_ReportError(EEP_MODULE_ID, EEP_INSTANCE_ID, 
        EEP_WRITE_SID,EEP_E_PARAM_DATA);   
    }
    else if(Length > 0xF)
    {
        Det_ReportError(EEP_MODULE_ID, EEP_INSTANCE_ID, 
        EEP_WRITE_SID,EEP_E_PARAM_LENGTH);   
    }else
#endif
    {
       I2C_Master_Start();
       // Wait Until EEPROM Is IDLE
       while(I2c_WriteSlaveAddress(EEPROM_Address_W))
       I2C_Master_RepeatedStart();
       I2c_WriteIB(0,&EepromAddress);
       for(unsigned int i=0; i<Length; i++)
            I2c_WriteIB(0,DataBufferPtr++);
       I2C_Master_Stop();
    }
    
  return E_OK;  
}

Std_ReturnType Eep_Read (Eep_AddressType EepromAddress,uint8* DataBufferPtr, Eep_LengthType Length)
{
#if (DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */	
    if(Eep_ThisConfiguration->Eep_Status == EEP_UNINIT)
    {
        Det_ReportError(EEP_MODULE_ID, EEP_INSTANCE_ID, 
        EEP_READ_SID,EEP_E_UNINIT);   
    }
    else if(EepromAddress > 0xFF /*1024*pow(2,Eep_Size)/8*/)
    {
        Det_ReportError(EEP_MODULE_ID, EEP_INSTANCE_ID, 
        EEP_READ_SID,EEP_E_PARAM_ADDRESS);   
    }
    else if(DataBufferPtr == NULL)
    {
        Det_ReportError(EEP_MODULE_ID, EEP_INSTANCE_ID, 
        EEP_READ_SID,EEP_E_PARAM_DATA);   
    }
    else if(Length > 0xF)
    {
        Det_ReportError(EEP_MODULE_ID, EEP_INSTANCE_ID, 
        EEP_READ_SID,EEP_E_PARAM_LENGTH);   
    }else
#endif
    {
        I2C_Master_Start();
        // Wait Until EEPROM Is IDLE
        while(I2c_WriteSlaveAddress(EEPROM_Address_W))
          I2C_Master_RepeatedStart();
        I2c_WriteIB(0,&EepromAddress);
        I2C_Master_RepeatedStart();
        I2c_WriteSlaveAddress(EEPROM_Address_R);
        for(unsigned int i=0; i<Length; i++)
        {
          I2c_ReadIB(0,DataBufferPtr++);
          I2C_ACK();
        }
      //  I2c_ReadIB(0,DataBufferPtr);
      //  I2C_NACK();
        I2C_Master_Stop();        
    }
    return E_OK;
}

#if(EEP_DEINIT_API==STD_ON)
void Eep_DeInit()
{
#if (DEV_ERROR_DETECT == STD_ON)
    if(Eep_ThisConfiguration->Eep_Status != EEP_UNINIT)
    {
        Det_ReportError(EEP_MODULE_ID, EEP_INSTANCE_ID, 
        EEP_INIT_SID,EEP_E_ALREADY_INITIALIZED);   
    }else
#endif
    {
        Eep_SlaveAddress = 0x00;
        I2c_DeInit();
    }
}
#endif

#if(EEP_ERASE_API==STD_ON)
Std_ReturnType Eep_Erase ( Eep_AddressType EepromAddress, Eep_LengthType Length )
{
#if (DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */	
    if(Eep_ThisConfiguration->Eep_Status == EEP_UNINIT)
    {
        Det_ReportError(EEP_MODULE_ID, EEP_INSTANCE_ID, 
        EEP_ERASE_SID,EEP_E_UNINIT);   
    }
    else if(EepromAddress > 0xFF /*1024*pow(2,Eep_Size)/8*/)
    {
        Det_ReportError(EEP_MODULE_ID, EEP_INSTANCE_ID, 
        EEP_ERASE_SID,EEP_E_PARAM_ADDRESS);   
    }
    else if(Length > 0xF)
    {
        Det_ReportError(EEP_MODULE_ID, EEP_INSTANCE_ID, 
        EEP_ERASE_SID,EEP_E_PARAM_LENGTH);   
    }else
#endif
    {
        uint8_t x = 0xFF;
        while(Eep_Write(EepromAddress,&x,Length) != E_OK);
    }
    return E_OK;
}
#endif

#if(EEP_COMPARE_API==STD_ON)
Std_ReturnType Eep_Compare ( Eep_AddressType EepromAddress, uint8* DataBufferPtr, Eep_LengthType Length )
{
#if (DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */	
    if(Eep_ThisConfiguration->Eep_Status == EEP_UNINIT)
    {
        Det_ReportError(EEP_MODULE_ID, EEP_INSTANCE_ID, 
        EEP_COMPARE_SID,EEP_E_UNINIT);   
    }
    else if(EepromAddress > 0xFF /*1024*pow(2,Eep_Size)/8*/)
    {
        Det_ReportError(EEP_MODULE_ID, EEP_INSTANCE_ID, 
        EEP_COMPARE_SID,EEP_E_PARAM_ADDRESS);   
    }
    else if(DataBufferPtr == NULL)
    {
        Det_ReportError(EEP_MODULE_ID, EEP_INSTANCE_ID, 
        EEP_COMPARE_SID,EEP_E_PARAM_DATA);   
    }
    else if(Length > 0xF)
    {
        Det_ReportError(EEP_MODULE_ID, EEP_INSTANCE_ID, 
        EEP_COMPARE_SID,EEP_E_PARAM_LENGTH);   
    }else
#endif
    {
        uint8_t x;
        while(Eep_Read(EepromAddress,&x,Length) != E_OK);
        if(x == *DataBufferPtr)
            return E_OK;
        else 
            return E_NOT_OK;
    }
    return E_NOT_OK;
}
#endif

#if(EEP_GET_STATUS_API==STD_ON)
Eep_StatusType Eep_GetStatus ( void )
{
#if (DEV_ERROR_DETECT == STD_ON)
    if(Eep_ThisConfiguration->Eep_Status != EEP_UNINIT)
    {
        Det_ReportError(EEP_MODULE_ID, EEP_INSTANCE_ID, 
        EEP_INIT_SID,EEP_E_ALREADY_INITIALIZED);   
    }else
#endif
    {
    return Eep_ThisConfiguration->Eep_Status;
    }
    return E_NOT_OK;
}
#endif

