
#ifndef TIMER_H
#define	TIMER_H

#include "Port.h"
#include "Dio.h"

/* Gpt Module Id */
#define GPT_MODULE_ID    0x100
/* Gpt Instance Id */
#define GPT_INSTANCE_ID  0x00

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for Timer INIT */
#define GPT_INIT_SID              	  0x01
/*Service ID for Timer DeInit*/
#define GPT_DEINIT_SID                0x02
/*Service ID for Adc GetGroupStatus*/
#define GPT_GET_STATUS_SID            0x10

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
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

#define GPT_CTL_REG1 T1CON
#define GPT_CTL_REG2 T2CON
#define GPT_RELO_REG TMR1

typedef uint8_t Gpt_ChannelType;
typedef uint16_t Gpt_ValueType;
typedef uint16_t Gpt_TickRateType;
typedef void (*Gpt_CallbackFn)(void);

typedef enum{
    TIMER0,TIMER1,TIMER2
}Gpt_ModuleType;

typedef enum{
    GPT_PRE_1,GPT_PRE_2,GPT_PRE_4,GPT_PRE_8,GPT_PRE_16
}Gpt_PrescalerType;

typedef enum {
    TIMER_MODE,COUNTER_MODE,PWM_MODE
}Gpt_ModeType; 

typedef enum{
    GPT_INTERNAL,GPT_EXTERNAL
}Gpt_ClockSource;

typedef enum{
    GPT_UNINIT,
    GPT_IDLE,
    GPT_BUSY
}Gpt_StatusType;

typedef struct{
    Gpt_ModuleType Module;
    Gpt_ChannelType Channel;   
    Gpt_TickRateType TickRate;
    Gpt_CallbackFn CallbackFn;
    Gpt_ModeType Mode;
    Gpt_ClockSource ClkSource;
    Gpt_StatusType Status;
}Gpt_ConfigType;

/////////////////////////////////////////////////////////

void Gpt_Init(Gpt_ConfigType*);

#if(GPT_DEINIT_API==STD_ON)
void Gpt_DeInit(Gpt_ModuleType Module);
#endif

#if(GPT_GET_STATUS_API==STD_ON)
Gpt_StatusType Gpt_GetStatus(Gpt_ModuleType Module);
#endif
#endif
