
#ifndef EEPROM_H
#define	EEPROM_H

#include "../MCAL/I2c.h"

/* Eep Module Id */
#define EEP_MODULE_ID    0x090
/* Eep Instance Id */
#define EEP_INSTANCE_ID  0x00

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for Eep INIT */
#define EEP_INIT_SID              	  0x00
/*Service ID for Eep DeInit*/
#define EEP_DEINIT_SID                0x01
/*Service ID for Eep Read*/
#define EEP_READ_SID                  0x02
/*Service ID for Eep Write*/
#define EEP_WRITE_SID             	  0x03
/*Service ID for Eep Erase*/
#define EEP_ERASE_SID            	  0x04
/*Service ID for Eep Compare*/
#define EEP_COMPARE_SID               0x05
/*Service ID for Eep GetStatus*/
#define EEP_GET_STATUS_SID            0x07

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
//API service called without module initialization
#define EEP_E_UNINIT 0x20
//A function has been called with incorrect parameter(pointer is NULL_PTR)
#define EEP_E_PARAM_POINTER 0x23
//EepInit has been called while ADC is already initialized
#define EEP_E_ALREADY_INITIALIZED 0x10
//Invalid address sent as a parameter
#define EEP_E_PARAM_ADDRESS 0x11
//Invalid address sent as a parameter
#define EEP_E_PARAM_DATA 0x12
//Invalid address sent as a parameter
#define EEP_E_PARAM_LENGTH 0x13


typedef uint8_t Eep_AddressType;
typedef uint8_t Eep_LengthType;

typedef enum{
    SIZE_1KB,
    SIZE_2KB,
    SIZE_4KB,
    SIZE_8KB,
    SIZE_16KB,
    SIZE_32KB,
    SIZE_64KB
}Eep_SizeType;

typedef enum{
    EEP_UNINIT,
    EEP_IDLE,
    EEP_BUSY
}Eep_StatusType;

typedef struct {
    Eep_AddressType Eep_SlaveAddress;
    Eep_SizeType Eep_Size;
    Eep_StatusType Eep_Status;
}Eep_ConfigType;

void Eep_Init(Eep_ConfigType* ConfigPtr);
Std_ReturnType Eep_Write(Eep_AddressType EepromAddress, uint8* DataBufferPtr, Eep_LengthType Length);
Std_ReturnType Eep_Read (Eep_AddressType EepromAddress, uint8* DataBufferPtr, Eep_LengthType Length);


#if(EEP_DEINIT_API==STD_ON)
void Eep_DeInit();
#endif

#if(EEP_ERASE_API==STD_ON)
Std_ReturnType Eep_Erase ( Eep_AddressType EepromAddress, 
        Eep_LengthType Length );
#endif

#if(EEP_COMPARE_API==STD_ON)
Std_ReturnType Eep_Compare ( Eep_AddressType EepromAddress,
        uint8* DataBufferPtr, Eep_LengthType Length );
#endif

#if(EEP_GET_STATUS_API==STD_ON)
Eep_StatusType Eep_GetStatus ( void );
#endif

#endif