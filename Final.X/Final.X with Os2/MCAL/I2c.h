#include <xc.h>
#include "Port.h"

/* I2c Module Id */
#define I2C_MODULE_ID    0x083
/* I2c Instance Id */
#define I2C_INSTANCE_ID  0x00

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
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

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
//API service called without module initialization
#define I2C_E_UNINIT 0x1A
//A function has been called with incorrect parameter(pointer is NULL_PTR)
#define I2C_E_PARAM_POINTER 0x10
//I2cInit has been called while I2C is already initialized
#define I2C_E_ALREADY_INITIALIZED 0x4A
//API service called with wrong channel as parameter
#define I2C_E_PARAM 0x0A


#define EEPROM_Address_R 0xA1
#define EEPROM_Address_W 0xA0

#define I2C_CTL_REG1 SSPCON
#define I2C_CTL_REG2 SSPCON2
#define I2C_STAT_REG SSPSTAT
#define I2C_BUFF_REG SSPBUF
#define I2C_ADDR_REG SSPADD
#define I2C_BUSY_BIT SSPIF

enum{
    SEN_BIT,RSEN_BIT,PEN_BIT,RCEN_BIT,
    ACKEN_BIT,ACKDT_BIT,ACKSTAT_BIT
};

typedef uint32_t I2c_BaudRateType;
typedef uint8_t I2c_ChannelType;
typedef uint16_t I2c_NumberOfDataType;
typedef uint8_t I2c_DataBufferType;

typedef enum{
    I2C_SLAVE_7BIT =      0b0110,
    I2C_SLAVE_10BIT =     0b0111,
    I2C_MASTER =          0b1000,
    I2C_MASTER_FRIMWARE=  0b1001,
    I2C_SLAVE_7BIT_INT_EN=0b1010,
    I2C_SLAVE_10BIT_INT_EN=0b1011
}I2c_ModeType;

typedef enum{
    I2C0
}I2c_ModuleType;

typedef enum{
    I2C_UNINIT,
    I2C_IDLE,
    I2C_BUSY
}I2c_StatusType;

typedef enum{
    INTERNAL_BUFFER,EXTERNAL_BUFFER
}I2c_BufferSourceType;

typedef enum{
    MSB_FIRST,LSB_FIRST
}I2c_TransferStartType;
typedef enum{
    BITS_8,BITS_16,BITS_32
}I2c_DataWidthType;

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

void I2c_Init(I2c_ConfigType *Config_Ptr);
Std_ReturnType I2c_WriteIB ( I2c_ChannelType Channel, I2c_DataBufferType* DataBufferPtr );
Std_ReturnType I2c_ReadIB ( I2c_ChannelType Channel, I2c_DataBufferType* DataBufferPtr );
uint8_t I2c_WriteSlaveAddress(uint8_t data);

#if(I2C_DEINIT_API==STD_ON)
void I2c_DeInit();
#endif

#if(I2C_GET_STATUS_API==STD_ON)
I2c_StatusType I2c_GetStatus ( void );
#endif

void I2C_Master_Wait();
void I2C_Master_Start();
void I2C_Master_RepeatedStart();
void I2C_Master_Stop();
void I2C_ACK();
void I2C_NACK();

