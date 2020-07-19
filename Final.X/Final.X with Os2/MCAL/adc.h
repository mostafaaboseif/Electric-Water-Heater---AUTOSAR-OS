
#ifndef ADC_H
#define	ADC_H

#include <xc.h>
#include <stdint.h>
#include "Port.h"

/* ADC Module Id */
#define ADC_MODULE_ID    0x123
/* ADC Instance Id */
#define ADC_INSTANCE_ID  0x00
 
/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for Adc INIT */
#define ADC_INIT_SID              	  0x00
/*Service ID for Adc DeInit*/
#define ADC_DEINIT_SID                0x01
/*Service ID for Adc StartGroupConversion*/
#define ADC_START_GROUP_SID       	  0x02
/*Service ID for Adc StopGroupConversion*/
#define ADC_STOP_GROUP_SID        	  0x03
/*Service ID for Adc ReadGroup*/
#define ADC_READ_GP_SID          	  0x04
/*Service ID for Adc EnableGroupNotification*/
#define ADC_EN_GRP_NOTIF_SID          0x07
/*Service ID for Adc DisableGroupNotification*/
#define ADC_DIS_GRP_NOTIF_SID         0x08
/*Service ID for Adc GetGroupStatus*/
#define ADC_GET_STATUS_SID            0x09
/*Service ID for Adc SetupResultBuffer*/
#define ADC_SETUP_BUFF_SID            0x0c

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
//API service called without module initialization
#define ADC_E_UNINIT 0x0A
//Adc_Init has been called while ADC is already initialized
#define ADC_E_ALREADY_INITIALIZED 0x0D
//A function has been called with incorrect parameter(pointer is NULL_PTR)
#define ADC_E_PARAM_POINTER 0x0E
//Invalid group ID requested
#define ADC_E_PARAM_GROUP 0x15
//Adc_EnableHardwareTrigger or Adc_DisableHardwareTrigger called on a 
//group with conversion mode configured as continuous
#define ADC_E_WRONG_CONV_MODE 0x16
//Enable/disable notification fn for group with configuration is polling
#define ADC_E_NOTIF_CAPABILITY 0x18

/* ---------------------------------- CONSTANTS ---------------------------------- */

#define ADC_CTL_REG1 ADCON0
#define ADC_CTL_REG2 ADCON1
#define ADC_BUFF_REG_H ADRESH
#define ADC_BUFF_REG_L ADRESL
#define ADC_BUSY_BIT Pin2

/* ---------------------------------- PRIMITIVE TYPES ---------------------------------- */

typedef uint8_t Adc_ChannelType;
typedef uint8_t Adc_GroupType; //group index in array (0 - 7)
typedef uint8_t Adc_ValueGroupType;
typedef uint8_t Adc_StreamNumSampleType;
typedef uint8_t Adc_ConversionTimeType; 
typedef void (*Adc_CallbackFnType)(Adc_ValueGroupType);
#if(EXTRA_FEATURES==STD_ON)
typedef uint8_t Adc_SamplingTimeType;
typedef uint8_t Adc_ResolutionType;
typedef uint8_t Adc_GroupPriorityType; 
#endif
/* ---------------------------------- ENUMS ---------------------------------- */
typedef enum AdcChannel{
    PA0,PA1,PA2,PA3
}AdcChannel;
typedef enum Adc_PrescalerType{
    ADC_PRE_2,ADC_PRE_8,ADC_PRE_32,ADC_RC,ADC_PRE_4,ADC_PRE_16,ADC_PRE_64
}Adc_PrescalerType;
typedef enum Adc_GroupAccessModeType{  
ADC_ACCESS_MODE_SINGLE,
ADC_ACCESS_MODE_STREAMING
}Adc_GroupAccessModeType;
typedef enum Adc_StreamBufferModeType{ 
ADC_STREAM_BUFFER_LINEAR,
ADC_STREAM_BUFFER_CIRCULAR
}Adc_StreamBufferModeType;
typedef enum Adc_GroupConvModeType{  
ADC_CONV_MODE_ONESHOT_POLLING,
ADC_CONV_MODE_CONTINUOUS_INTERRUPT
}Adc_GroupConvModeType;
typedef enum Adc_ResultAlignmentType{
ADC_ALIGN_LEFT,
ADC_ALIGN_RIGHT
}Adc_ResultAlignmentType;
typedef enum Adc_StatusType{
	ADC_UNINIT,
    ADC_IDLE,
	ADC_BUSY,
	ADC_COMPLETED,
	ADC_STREAM_COMPLETED
}Adc_StatusType;
#if(EXTRA_FEATURES==STD_ON)
typedef enum Adc_TriggerSourceType{
ADC_TRIG_SRC_SW, 
ADC_TRIG_SRC_HW
}Adc_TriggerSourceType;
typedef enum Adc_HwTriggerSourceType{
ADC_TRIG_EXTERNAL,
ADC_TRIG_TIMER,
NO_HW_TRIG
}Adc_HwTriggerSourceType;
typedef enum Adc_HwTriggerSignalType{
ADC_HW_TRIG_RISING_EDGE, 
ADC_HW_TRIG_FALLING_EDGE, 
ADC_HW_TRIG_BOTH_EDGES
}Adc_HwTriggerSignalType;
#endif
/* ---------------------------------- STRUCTS ---------------------------------- */

typedef struct{
Adc_ChannelType Adc_NbChannels;
AdcChannel ArrayOfAdcChannels[MAX_NB_ADC_CHANNELS];
Adc_GroupAccessModeType Adc_GroupAccessMode;
Adc_StreamNumSampleType Adc_NbSamples;
Adc_GroupConvModeType Adc_GroupConvMode;
Adc_ResultAlignmentType Adc_ResultAlignment;
Adc_PrescalerType Adc_Prescale;
Adc_CallbackFnType CallbackFn;
Adc_StatusType Adc_Status;
#if(EXTRA_FEATURES==STD_ON)
Adc_GroupType Adc_Group;  //Group Id
Adc_TriggerSourceType Adc_TriggerSource;
Adc_HwTriggerSourceType Adc_HwTriggerSource;
Adc_HwTriggerSignalType Adc_HwTriggerSignal;
Adc_StreamBufferModeType Adc_StreamBufferMode;
Adc_GroupPriorityType GroupPriority;
#endif
}Adc_ConfigType;

/* ---------------------------------- FUNCTION DECLARATIONS ---------------------------------- */

void Adc_Init(Adc_ConfigType*);

#if (ADC_READ_GP_CAPABILITY==STD_ON)
Std_ReturnType Adc_ReadGroup ( Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr );
#endif

#if (ADC_ENABLE_START_STOP_GROUP_API==STD_ON)		
void Adc_StartGroupConversion ( Adc_GroupType groupId );
void Adc_StopGroupConversion ( Adc_GroupType groupId );
#endif

#if (ADC_DEINIT_API==STD_ON)		
void Adc_DeInit (void);
#endif

#if (ADC_GET_STATUS_API==STD_ON)
Adc_StatusType Adc_GetStatus();
#endif

#if (ADC_SETUP_BUFF_API==STD_ON)
Std_ReturnType Adc_SetupResultBuffer( Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr ); 
#endif

#if (ADC_GRP_NOTIF_CAPABILITY==STD_ON)		
void Adc_EnableGroupNotification(Adc_GroupType groupId);
void Adc_DisableGroupNotification(Adc_GroupType groupId);
#endif



#endif
