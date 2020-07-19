/***************************************************************
*
* Module: Pwm
*
* File Name: Pwm.h
*
* Description: Header file for Pwm Module,
*              implementation is based on AUTOSAR specfications.
*
* Author: Mostafa Amgad
*
* Date:  July 17, 2020
****************************************************************/


#ifndef PWM_H
#define	PWM_H


/* Pwm Module Id */
#define PWM_MODULE_ID   0x121
/* Pwm Instance Id */
#define PWM_INSTANCE_ID 0x00
 
/*=================================================================
                         INCLUDE FILES
==================================================================*/
/*needed interfaces from external units*/
#include "Port.h"
#include "Gpt.h"

/*=================================================================
                      API Service Id Macros
==================================================================*/
/* Service ID for Pwm INIT */
#define PWM_INIT_SID              	  0x00
/*Service ID for Pwm DeInit*/
#define PWM_DEINIT_SID                0x01
/*Service ID for Pwm SetDutyCycle*/
#define PWM_SET_DUTY_SID         	  0x02
/*Service ID for Pwm SetPeriodAndDuty*/
#define PWM_SET_PERIOD_DUTY_SID    	  0x03
/*Service ID for Pwm SetOutputToIdle*/
#define PWM_SET_OUT_IDLE_SID       	  0x04
/*Service ID for Pwm GetGroupStatus*/
#define PWM_GET_STATUS_SID            0x10

/*=================================================================
                        DET Error Codes 
==================================================================*/
//API Pwm_Init service called with wrong parameter(NULL_PTR)
#define PWM_E_INIT_FAILED 0x10
//API service used without module initialization
#define PWM_E_UNINIT 0x11
//API service used with an invalid channel Identifier
#define PWM_E_PARAM_CHANNEL 0x12
//Usage of unauthorized PWM service on PWM channel configured a fixed period
#define PWM_E_PERIOD_UNCHANGEABLE 0x13
//API Pwm_Init service called while the PWM driver has already been initialised
#define PWM_E_ALREADY_INITIALIZED 0x14

/*=================================================================
                           CONSTANTS
==================================================================*/
#define PWM_CTL_REG1 CCP1CON 

/*=================================================================
                       Module Data Types
==================================================================*/
//Numeric identifier of a PWM channel.
typedef uint8_t Pwm_ChannelType;

//Definition of the period of a PWM channel.
typedef uint16_t Pwm_PeriodType;

//Defines the polarity of a PWM channel
typedef enum{
    POLARITY_LOW,POLARITY_HIGH
}Pwm_PolarityType;

//Defines the state of a PWM channel
typedef enum{
    PWM_UNINIT,
    PWM_IDLE,
    PWM_BUSY
}Pwm_StatusType;

#if(EXTRA_FEATURES==STD_ON)
typedef enum{
    IDLE_LOW,IDLE_HIGH
}Pwm_IdleStateType;

typedef enum{
    PWM_LOW,PWM_HIGH
}Pwm_OutputStateType;

typedef enum{
    PWM_RISING_EDGE,PWM_FALLING_EDGE,PWM_BOTH_EDGES
}Pwm_EdgeNotificationType;

typedef enum{
    PWM_FIXED_PERIOD,PWM_VARIABLE_PERIOD,PWM_FIXED_PERIOD_SHIFTED
}Pwm_ChannelClassType;
#endif

//This is the type of data structure containing the initialization data for the PWM driver.
typedef struct{
    Pwm_ChannelType Channel;
    Pwm_PeriodType Period;
    uint16_t DutyCycle;
    Pwm_PolarityType Polarity;  //entered duty cycle is for the HIGH or LOW state
    Pwm_StatusType Status;  //used for error checking and handling
#if(EXTRA_FEATURES==STD_ON)
    Pwm_IdleStateType IdleState;
    Pwm_EdgeNotificationType Edge;
    Pwm_ChannelClassType ChannelClass;
#endif
}Pwm_ConfigType;


/*=================================================================
                      FUNCTION PROTOTYPES
==================================================================*/

/**
 * @brief   Initializes the Pwm Driver module.
 * @details The function Pwm_Init shall initialize all internals variables and the used PWM 
 *          structure of the MCU according to the parameters specified in ConfigPtr
 * 
 * @post    Pwm_Init() must be called before all other Pwm Driver module's 
 *          functions otherwise no operation can occur on the Pwm.
 *
 * @param[in] ConfigPtr     A pointer to the structure which contains
 *                          initialization parameters.
 */
 void Pwm_Init(Pwm_ConfigType*);



/**
 * @brief   Service sets the duty cycle of the PWM channel.
 * @details The function Pwm_SetDutyCycle shall set the duty cycle of the PWM channel
 * 
 * @pre     @p Pwm_Init() must have been called first.
 *
 * @param[in] ChannelNumber  Numeric identifier of the PWM  
 * @param[in] DutyCycle      0 - 100
 */
void Pwm_SetDutyCycle ( Pwm_ChannelType ChannelNumber, uint16_t DutyCycle );




/**
 * @brief   Service for PWM De-Initialization.
 * @details The function Pwm_DeInit shall de-initialize the PWM module.
 * 
 * @pre     @p Pwm_Init() must have been called first.
 */
#if(PWM_DEINIT_API==STD_ON)
void Pwm_DeInit();
#endif


/**
 * @brief   Service sets the duty cycle and period of the PWM channel.
 * @details The function Pwm_SetPeriodAndDuty shall set the duty cycle
 *          and the period of the PWM channel
 * 
 * @pre     @p Pwm_Init() must have been called first.
 *
 * @param[in] ChannelNumber  Numeric identifier of the PWM 
 * @param[in] Period         Desired Period 
 * @param[in] DutyCycle      0 - 100
 */
void Pwm_SetPeriodAndDuty ( Pwm_ChannelType ChannelNumber,
                            Pwm_PeriodType Period, uint16 DutyCycle );



/**
 * @brief   Service sets the PWM output to the configured Idle state.
 * @details The function Pwm_SetOutputToIdle shall set immediately the PWM 
 *          output to the configured Idle state
 * 
 * @pre     @p Pwm_Init() must have been called first.
 *
 * @param[in] ChannelNumber  Numeric identifier of the PWM  
 */
void Pwm_SetOutputToIdle ( Pwm_ChannelType ChannelNumber );



 /**
 * @brief   Returns the Pwm status
 * @details The function Pwm_GetStatus shall return the pwm status
 * 
 * @pre     @p Pwm_Init() must have been called first.
 *
 * @param[out] Pwm_StatusType    Conversion status for the requested group.
 */
#if(PWM_GET_STATUS_API==STD_ON)
Pwm_StatusType Pwm_GetStatus(void);
#endif


#endif    /*Pwm.h*/