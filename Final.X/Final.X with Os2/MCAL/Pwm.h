
#ifndef PWM_H
#define	PWM_H

#include "Port.h"
#include "../common_macros.h"
#include "Gpt.h"

/* Pwm Module Id */
#define PWM_MODULE_ID   0x121
/* Pwm Instance Id */
#define PWM_INSTANCE_ID 0x00
 
/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
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

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
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


#define PWM_CTL_REG1 CCP1CON 

typedef uint8_t Pwm_ChannelType;
typedef uint16_t Pwm_PeriodType;

typedef enum{
    POLARITY_LOW,POLARITY_HIGH
}Pwm_PolarityType;

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

typedef struct{
    Pwm_ChannelType Channel;
    Pwm_PeriodType Period;
    uint16_t DutyCycle;
    Pwm_PolarityType Polarity;
    Pwm_StatusType Status;
#if(EXTRA_FEATURES==STD_ON)
    Pwm_IdleStateType IdleState;
    Pwm_EdgeNotificationType Edge;
    Pwm_ChannelClassType ChannelClass;
#endif
}Pwm_ConfigType;


void Pwm_Init(Pwm_ConfigType*);
void Pwm_SetDutyCycle ( Pwm_ChannelType ChannelNumber, uint16_t DutyCycle );

#if(PWM_DEINIT_API==STD_ON)
void Pwm_DeInit();
#endif

void Pwm_SetPeriodAndDuty ( Pwm_ChannelType ChannelNumber,
                            Pwm_PeriodType Period, uint16 DutyCycle );
void Pwm_SetOutputToIdle ( Pwm_ChannelType ChannelNumber );


#if(PWM_GET_STATUS_API==STD_ON)
Pwm_StatusType Pwm_GetStatus(void);
#endif
#endif