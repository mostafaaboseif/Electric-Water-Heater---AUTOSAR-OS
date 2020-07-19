/***************************************************************
*
* Module: Eeprom
*
* File Name: Eeprom.h
*
* Description: Header file for Eeprom Module,
*              implementation is based on AUTOSAR specfications.
*
* Author: Mostafa Amgad
*
* Date:  July 17, 2020
****************************************************************/


#ifndef EEPROM_H
#define	EEPROM_H

/* Eep Module Id */
#define EEP_MODULE_ID    0x090
/* Eep Instance Id */
#define EEP_INSTANCE_ID  0x00

/*=================================================================
                         INCLUDE FILES
==================================================================*/
/*needed interfaces from external units*/
#include "../MCAL/I2c.h"

/*=================================================================
                      API Service Id Macros
==================================================================*/
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

/*=================================================================
                        DET Error Codes 
==================================================================*/
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

/*=================================================================
                       Module Data Types
==================================================================*/
//Used as address offset from the configured EEPROM base address 
//to access a certain EEPROM memory area.
typedef uint8_t Eep_AddressType;

//Specifies the number of bytes to read/write/erase/compare.
typedef uint8_t Eep_LengthType;

//Type for the Eep Size of the used eeprom
typedef enum{
    SIZE_1KB,
    SIZE_2KB,
    SIZE_4KB,
    SIZE_8KB,
    SIZE_16KB,
    SIZE_32KB,
    SIZE_64KB
}Eep_SizeType;

//Type for the Eep Status
typedef enum{
    EEP_UNINIT,
    EEP_IDLE,
    EEP_BUSY
}Eep_StatusType;

//This is the type of the external data structure containing the 
//initialization data for the EEPROM driver.
typedef struct {
    Eep_AddressType Eep_SlaveAddress;
    Eep_SizeType Eep_Size;
    Eep_StatusType Eep_Status;
}Eep_ConfigType;

/*=================================================================
                      FUNCTION PROTOTYPES
==================================================================*/

/**
 * @brief   Initializes the Eeprom Driver module.
 * @details The function Eep_Init shall initialize all EEPROM relevant registers
 *          with the values of the structure referenced by the parameter ConfigPtr
 * 
 * @post    Eep_Init() must be called before all other Eeprom Driver module's 
 *          functions otherwise no operation can occur on the Eeprom.
 *
 * @param[in] ConfigPtr     A pointer to the structure which contains
 *                          initialization parameters.
 */
void Eep_Init(Eep_ConfigType* ConfigPtr);
 
 
 /**
 * @brief   Reads from EEPROM.
 * @details The function Eep_Read shall read the eeprom from the given address
 *
 * @pre     @p Eep_Init() must have been called first.
 *
 * @param[in] EepromAddress   Address offset in EEPROM (will be added to the EEPROM base address).
 * @param[in] Length          Number of bytes to read
 * @param[in] DataBufferPtr   Pointer to source data
 * @param[out] Std_ReturnType E_OK: write command has been accepted
 *                            E_NOT_OK: write command has not been accepted
 */
Std_ReturnType Eep_Write(Eep_AddressType EepromAddress, uint8* DataBufferPtr, Eep_LengthType Length);



/**
 * @brief   Reads from EEPROM.
 * @details The function Eep_Read shall read the eeprom from the given address
 *
 * @pre     @p Eep_Init() must have been called first.
 *
 * @param[in] EepromAddress   Address offset in EEPROM (will be added to the EEPROM base address).
 * @param[in] Length          Number of bytes to read
 * @param[out] DataBufferPtr  Pointer to destination data buffer in RAM
 * @param[out] Std_ReturnType E_OK: read command has been accepted
 *                            E_NOT_OK: read command has not been accepted
 */
Std_ReturnType Eep_Read (Eep_AddressType EepromAddress, uint8* DataBufferPtr, Eep_LengthType Length);




/**
 * @brief   Erases from EEPROM.
 * @details The function Eep_Read shall erases the eeprom from the given address
 *
 * @pre     @p Eep_Init() must have been called first.
 *
 * @param[in] EepromAddress   Address offset in EEPROM (will be added to the EEPROM base address).
 * @param[in] Length          Number of bytes to erase
 * @param[out] Std_ReturnType E_OK: erase command has been accepted
 *                            E_NOT_OK: erase command has not been accepted
 */
#if(EEP_ERASE_API==STD_ON)
Std_ReturnType Eep_Erase ( Eep_AddressType EepromAddress, Eep_LengthType Length );
#endif



/**
 * @brief   Compares a data block in EEPROM with an EEPROM block in the memory.
 * @details The function Eep_Read shall compares  the eeprom from the given address
 *
 * @pre     @p Eep_Init() must have been called first.
 *
 * @param[in] EepromAddress   Address offset in EEPROM (will be added to the EEPROM base address).
 * @param[in] Length          Number of bytes to read
 * @param[in] DataBufferPtr Pointer to data buffer (compare data)
 * @param[out] Std_ReturnType E_OK: compare command has been accepted
 *                            E_NOT_OK: compare command has not been accepted
 */
#if(EEP_COMPARE_API==STD_ON)
Std_ReturnType Eep_Compare(Eep_AddressType EepromAddress,uint8* DataBufferPtr,Eep_LengthType Length);
#endif



/*
 * @brief   Returns all Eep HW Units to a state comparable to their power on reset state.
 * @details The function Eep_DeInit shall return all Eep HW Units to a state
 *         comparable to their power on reset state
 * 
 * @pre     @p Eep_Init() must have been called first.
 *
 */
#if(EEP_DEINIT_API==STD_ON)
void Eep_DeInit();
#endif




/**
 * @brief   Returns the conversion status of the Eep module
 * @details The function Eep_GetStatus shall return the conversion status
  *          of the Eep module
 * 
 * @pre     @p Eep_Init() must have been called first.
 *
 * @param[out] Eep_StatusType    status for the Eep module.
 */
#if(EEP_GET_STATUS_API==STD_ON)
Eep_StatusType Eep_GetStatus ( void );
#endif



#endif   /*Eeprom.h*/