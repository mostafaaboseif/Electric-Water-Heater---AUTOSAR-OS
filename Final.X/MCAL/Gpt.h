/***************************************************************
*
* Module: Gpt
*
* File Name: Gpt.h
*
* Description: Header file for Gpt Module,
*              implementation is based on AUTOSAR specfications.
*
* Author: Mostafa Amgad
*
* Date:  July 17, 2020
****************************************************************/


#ifndef TIMER_H
#define	TIMER_H


/* Gpt Module Id */
#define GPT_MODULE_ID    0x100
/* Gpt Instance Id */
#define GPT_INSTANCE_ID  0x00


/*=================================================================
                         INCLUDE FILES
==================================================================*/
/*needed interfaces from external units*/
#include "Port.h"


/*=================================================================
                      API Service Id Macros
==================================================================*/
/* Service ID for Timer INIT */
#define GPT_INIT_SID              	  0x01
/*Service ID for Timer DeInit*/
#define GPT_DEINIT_SID                0x02
/*Service ID for Gpt GetGroupStatus*/
#define GPT_GET_STATUS_SID            0x10

/*=================================================================
                        DET Error Codes 
==================================================================*/
//API service called without module initialization
#define GPT_E_UNINIT 0x0A
//API service for initialization called when already initialized
#define GPT_E_ALREADY_INITIALIZED 0x0D
//API parameter checking: invalid channel
#define GPT_E_PARAM_CHANNEL 0x14
//API parameter checking: invalid value
#define GPT_E_PARAM_VALUE 0x15
//API parameter checking: invalid pointer
#define GPT_E_PARAM_POINTER 0x16
//API parameter checking: invalid Predef Timer
#define GPT_E_PARAM_PREDEF_TIMER 0x17
//API parameter checking: invalid mode
#define GPT_E_PARAM_MODE 0x1F

/*=================================================================
                           CONSTANTS
==================================================================*/
#define GPT_CTL_REG1 T1CON
#define GPT_CTL_REG2 T2CON
#define GPT_RELO_REG TMR1

/*=================================================================
                       Module Data Types
==================================================================*/
//Numeric ID of a GPT channel.
typedef uint8_t Gpt_ChannelType;

//Type for reading and setting the timer values (in number of ticks).
typedef uint16_t Gpt_ValueType;

//Type for the Tick Rate of timer
typedef uint16_t Gpt_TickRateType;

//Type for the callback function of the timer
typedef void (*Gpt_CallbackFn)(void);

//Type for the timer module
typedef enum{
    TIMER0,TIMER1,TIMER2
}Gpt_ModuleType;

//type fot the timer prescaler
typedef enum{
    GPT_PRE_1,GPT_PRE_2,GPT_PRE_4,GPT_PRE_8,GPT_PRE_16
}Gpt_PrescalerType;

//type fot the timer mode
typedef enum {
    TIMER_MODE,COUNTER_MODE,PWM_MODE
}Gpt_ModeType; 

//type fot the timer clock source
typedef enum{
    GPT_INTERNAL,GPT_EXTERNAL
}Gpt_ClockSource;

//type fot the timer status
typedef enum{
    GPT_UNINIT,
    GPT_IDLE,
    GPT_BUSY
}Gpt_StatusType;

//This is the type of the data structure including 
//the configuration set required for initializing the GPT timer unit.
typedef struct{
    Gpt_ModuleType Module;  //timer0, timer1, or timer2
    Gpt_ChannelType Channel;  //Channel Id
    Gpt_TickRateType TickRate;  //rate at which the counter increments
    Gpt_CallbackFn CallbackFn;  //function to be called at every overflow
    Gpt_ModeType Mode;  //timer, counter or pwm
    Gpt_ClockSource ClkSource;  //internal or external
    Gpt_StatusType Status;  //used for error checking and handling
}Gpt_ConfigType;


/*=================================================================
                      FUNCTION PROTOTYPES
==================================================================*/
/**
 * @brief   Initializes the Gpt Driver module.
 * @details The function Gpt_Init shall initialize the hardware timer module 
 *          according to a configuration set referenced by ConfigPtr
 * 
 * @post    Gpt_Init() must be called before all other Gpt Driver module's 
 *          functions otherwise no operation can occur on the Gpt.
 *
 * @param[in] ConfigPtr     A pointer to the structure which contains
 *                          initialization parameters.
 */
void Gpt_Init(Gpt_ConfigType*);


/**
 * @brief   Deinitializes the GPT driver.
 * @details The function Gpt_DeInit shall deinitialize the hardware used by 
 *          the GPT driver (depending on configuration) to the power on reset state
 * 
 * @pre     @p Gpt_Init() must have been called first.
 *
 * @param[in] module     Id of the timer module to deInit
 */
#if(GPT_DEINIT_API==STD_ON)
void Gpt_DeInit(Gpt_ModuleType Module);
#endif



 /**
 * @brief   Returns the conversion status of the requested ADC Channel group.
 * @details The function Gpt_GetGroupStatus shall return the conversion status
 *          of the requested ADC Channel group.
 * 
 * @pre     @p Gpt_Init() must have been called first.
 *
 * @param[out] Gpt_StatusType    Conversion status for the requested group.
 */
#if(GPT_GET_STATUS_API==STD_ON)
Gpt_StatusType Gpt_GetStatus(Gpt_ModuleType Module);
#endif


#endif  /*Gpt.h*/
