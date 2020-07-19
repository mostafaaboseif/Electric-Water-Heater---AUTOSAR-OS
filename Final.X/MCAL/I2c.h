/***************************************************************
*
* Module: I2c
*
* File Name: I2c.h
*
* Description: Header file for I2c Module,
*              implementation is based on AUTOSAR specfications.
*
* Author: Mostafa Amgad
*
* Date:  July 17, 2020
****************************************************************/


#ifndef I2C_H
#define I2C_H


/* I2c Module Id */
#define I2C_MODULE_ID    0x083
/* I2c Instance Id */
#define I2C_INSTANCE_ID  0x00
/*=================================================================
                         INCLUDE FILES
==================================================================*/
/*needed interfaces from external units*/
#include "Port.h"


/*=================================================================
                      API Service Id Macros
==================================================================*/
/* Service ID for I2c INIT */
#define I2C_INIT_SID              	  0x00
/*Service ID for I2c DeInit*/
#define I2C_DEINIT_SID                0x01
/*Service ID for I2c WriteIB*/
#define I2C_WRITE_SID                 0x02
/*Service ID for I2c ReadIB*/
#define I2C_READ_SID             	  0x03
/*Service ID for I2c GetStatus*/
#define I2C_GET_STATUS_SID            0x07

/*=================================================================
                        DET Error Codes 
==================================================================*/
//API service called without module initialization
#define I2C_E_UNINIT 0x1A
//A function has been called with incorrect parameter(pointer is NULL_PTR)
#define I2C_E_PARAM_POINTER 0x10
//I2cInit has been called while I2C is already initialized
#define I2C_E_ALREADY_INITIALIZED 0x4A
//API service called with wrong channel as parameter
#define I2C_E_PARAM 0x0A

/*=================================================================
                           CONSTANTS
==================================================================*/
#define I2C_CTL_REG1 SSPCON
#define I2C_CTL_REG2 SSPCON2
#define I2C_STAT_REG SSPSTAT
#define I2C_BUFF_REG SSPBUF
#define I2C_ADDR_REG SSPADD
#define I2C_BUSY_BIT SSPIF

#define EEPROM_Address_R 0xA1
#define EEPROM_Address_W 0xA0

enum{
    SEN_BIT,RSEN_BIT,PEN_BIT,RCEN_BIT,
    ACKEN_BIT,ACKDT_BIT,ACKSTAT_BIT
};

/*=================================================================
                       Module Data Types
==================================================================*/
//Type for I2c Baudrate
typedef uint32_t I2c_BaudRateType;

//Specifies the identification (ID) for a Channel.
typedef uint8_t I2c_ChannelType;

//Type for defining the number of data elements of the type 
//I2c_DataBufferType to send and / or receive by Channel
typedef uint16_t I2c_NumberOfDataType;

//Type of application data buffer elements.
typedef uint8_t I2c_DataBufferType;

//Type for the I2c mode
typedef enum{
    I2C_SLAVE_7BIT =      0b0110,
    I2C_SLAVE_10BIT =     0b0111,
    I2C_MASTER =          0b1000,
    I2C_MASTER_FRIMWARE=  0b1001,
    I2C_SLAVE_7BIT_INT_EN=0b1010,
    I2C_SLAVE_10BIT_INT_EN=0b1011
}I2c_ModeType;

//Type for the I2c module
typedef enum{
    I2C0
}I2c_ModuleType;

//Type for the I2c status
typedef enum{
    I2C_UNINIT,
    I2C_IDLE,
    I2C_BUSY
}I2c_StatusType;

//Type for the I2c buffer source
typedef enum{
    INTERNAL_BUFFER,EXTERNAL_BUFFER
}I2c_BufferSourceType;

//Type for the I2c transfer start
typedef enum{
    MSB_FIRST,LSB_FIRST
}I2c_TransferStartType;

//Type for the I2c data waidth
typedef enum{
    BITS_8,BITS_16,BITS_32
}I2c_DataWidthType;

//This type of the external data structure 
//shall contain the initialization data for the I2C Handler/Driver.
typedef struct{ 
    I2c_ChannelType I2c_Channel;
    I2c_ModuleType I2c_Module;
    I2c_BaudRateType I2c_Baudrate;    
    I2c_ModeType I2c_Mode;
    I2c_DataWidthType I2c_DataWidth;
    I2c_BufferSourceType I2c_BufferSource;
    I2c_TransferStartType I2c_TransferStart;
    I2c_DataBufferType I2c_DefaultTransmitValue;
    I2c_StatusType I2c_Status;    
}I2c_ConfigType;

/*=================================================================
                      FUNCTION PROTOTYPES
==================================================================*/

/**
 * @brief   Initializes the I2c Driver module.
 * @details The function @p I2c_Init() shall initialize all I2c relevant registers 
 *          with the values of the structure referenced by the parameter Config-Ptr.
 * 
 * @post    I2c_Init() must be called before all other I2c Driver module's 
 *          functions otherwise no operation can occur on the I2c.
 *
 * @param[in] ConfigPtr     A pointer to the structure which contains
 *                          initialization parameters.
 */

void I2c_Init(I2c_ConfigType *Config_Ptr);



 /**
 * @brief   Service for writing one or more data to an IB I2C Handler/Driver
  *         Channel specified by parameter.
 * @details The function I2c_WriteIB provides the service for writing one or more 
  *         data to an IB I2C Handler/Driver Channel by the respective parameter
 * @pre     @p Port_Init() must have been called first.
 *
 * @param[in] Channel             Channel ID.
 * @param[in] DataBufferPtr       Pointer to source data buffer
 * @param[out] Std_ReturnType     E_OK: write command has been accepted 
  *                               E_NOT_OK: write command has not been accepted
 */
Std_ReturnType I2c_WriteIB ( I2c_ChannelType Channel, I2c_DataBufferType* DataBufferPtr );



 /**
 * @brief   Service for reading one or more data to an IB I2C Handler/Driver
  *         Channel specified by parameter.
 * @details The function I2c_WriteIB provides the service for reading one or more 
  *         data to an IB I2C Handler/Driver Channel by the respective parameter
 * @pre     @p Port_Init() must have been called first.
 *
 * @param[in] Channel             Channel ID.
 * @param[in] DataBufferPtr       Pointer to destination data buffer in RAM
 * @param[out] Std_ReturnType     E_OK: write command has been accepted 
  *                               E_NOT_OK: write command has not been accepted
 */
Std_ReturnType I2c_ReadIB ( I2c_ChannelType Channel, I2c_DataBufferType* DataBufferPtr );


 
/**
 * @brief   Service for writing the slave address to an IB I2C Handler/Driver
 * @details The function I2c_WriteSlaveAddress provides the service for writing the 
 *          slave address to an IB I2C Handler/Driver
 * @pre     @p Port_Init() must have been called first.
 *
 * @param[in]  uint8_t            slave address
 * @param[out] uint8_t            ACKSTAT
 */
uint8_t I2c_WriteSlaveAddress(uint8_t);


/*
 * @brief   Returns all I2C HW Units to a state comparable to their power on reset state.
 * @details The function I2c_DeInit shall return all I2C HW Units to a state
 *         comparable to their power on reset state
 * 
 * @pre     @p I2c_Init() must have been called first.
 *
 */
#if(I2C_DEINIT_API==STD_ON)
void I2c_DeInit();
#endif

 /**
 * @brief   Returns the conversion status of the I2c module
 * @details The function I2c_GetStatus shall return the conversion status
  *          of the I2c module
 * 
 * @pre     @p i2c_Init() must have been called first.
 *
 * @param[out] I2c_StatusType    Conversion status for the I2c module.
 */
#if(I2C_GET_STATUS_API==STD_ON)
I2c_StatusType I2c_GetStatus ( void );
#endif



/**
 * @brief   Set of function to send specific bits on the I2c bus
 * @details The Set of function to send specific bits on the I2c bus used 
 *          in the communication by I2c devices
 * 
 * @pre     @p I2c_Init() must have been called first.
 */
void I2C_Master_Wait();
void I2C_Master_Start();
void I2C_Master_RepeatedStart();
void I2C_Master_Stop();
void I2C_ACK();
void I2C_NACK();


#endif   /*I2c.h*/