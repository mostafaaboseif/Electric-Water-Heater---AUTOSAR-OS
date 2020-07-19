/***************************************************************
*
* Module: Pwm
*
* File Name: Pwm.c
*
* Description: Source file for Pwm Module,
*              implementation is based on AUTOSAR specfications.
*
* Author: Mostafa Amgad
*
* Date:  July 17, 2020
****************************************************************/

/*=================================================================
                            INCLUDES
*================================================================*/
#include "Pwm.h"

/*=================================================================
                    GLOBAL STATIC VARIABLES
*================================================================*/
Pwm_ConfigType *Pwm_ThisConfiguration = NULL ;

Port_ConfigType Pwm_Channels[2] = 
{
    {PortC,Pin1,PORT_PIN_OUT}, 
    {PortC,Pin2,PORT_PIN_OUT}
};

/*=================================================================
                     APIs IMPLEMENTATION
*================================================================*/
void Pwm_Init(Pwm_ConfigType* ConfigPtr)
{
#if (DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (ConfigPtr == NULL) 
    {
		Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, 
        PWM_INIT_SID,PWM_E_INIT_FAILED);
    
	} 
    else if(ConfigPtr->Status != PWM_UNINIT)
    {
        Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, 
        PWM_INIT_SID,PWM_E_ALREADY_INITIALIZED);   
    }else
#endif
    {
        Pwm_ThisConfiguration = ConfigPtr;

        REG_VALUE_SHIFT(PWM_CTL_REG1,3,2);

        Port_Init(&Pwm_Channels[ConfigPtr->Channel]); 

        Gpt_ConfigType Gpt_Config2 = 
        {
            .Module = TIMER2,
            .Channel = ConfigPtr->Channel,
            .TickRate = 1000000/ConfigPtr->Period,
            .Mode = PWM_MODE,
            .ClkSource = GPT_INTERNAL
        };

        Gpt_Init(&Gpt_Config2);

        uint16_t DutyCycle;
        if(ConfigPtr->Polarity == POLARITY_HIGH)
            DutyCycle = (ConfigPtr->DutyCycle*255*2)/100;
        else if(ConfigPtr->Polarity == POLARITY_LOW)
            DutyCycle = ((100 - ConfigPtr->DutyCycle)*255*2)/100;

        Pwm_ThisConfiguration->Status = PWM_IDLE;

        REG_VALUE_SHIFT(PWM_CTL_REG1, DutyCycle & 0x3 , 4);
        CCPR1L = (DutyCycle >> 2);

        Pwm_ThisConfiguration->Status = PWM_BUSY;
    }
}

void Pwm_SetDutyCycle ( Pwm_ChannelType ChannelNumber, uint16_t DutyCycle )
{
#if (DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (ChannelNumber > 1 ) 
    {
		Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, 
        PWM_SET_DUTY_SID,PWM_E_PARAM_CHANNEL);
    
	} 
    else if(Pwm_ThisConfiguration->Status == PWM_UNINIT)
    {
        Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, 
        PWM_SET_DUTY_SID,PWM_E_UNINIT);   
    }else
#endif
    {
        DutyCycle = (DutyCycle*255*2)/100;
        REG_VALUE_SHIFT(PWM_CTL_REG1, DutyCycle & 0x3 , 4);
        CCPR1L = DutyCycle >> 2 ;
        Pwm_ThisConfiguration->Status = PWM_BUSY;
    }
   
}

#if(PWM_DEINIT_API==STD_ON)
void Pwm_DeInit()
{
#if (DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if(Pwm_ThisConfiguration->Status == PWM_UNINIT)
    {
        Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, 
        PWM_DEINIT_SID,PWM_E_UNINIT);   
    }else
#endif
    {
        CLEAR_REG(PWM_CTL_REG1);
        Gpt_DeInit(TIMER2);
        Pwm_ThisConfiguration->Status = PWM_UNINIT;
    }
}
#endif

void Pwm_SetPeriodAndDuty ( Pwm_ChannelType ChannelNumber,
                            Pwm_PeriodType Period, uint16 DutyCycle )
{
#if (DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (ChannelNumber > 1 ) 
    {
		Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, 
        PWM_SET_PERIOD_DUTY_SID,PWM_E_PARAM_CHANNEL);
    
	} 
    else if(Pwm_ThisConfiguration->Status == PWM_UNINIT)
    {
        Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, 
        PWM_SET_PERIOD_DUTY_SID,PWM_E_UNINIT);   
    }
    else if(Pwm_ThisConfiguration->Period != Period)
    {
        Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, 
        PWM_SET_PERIOD_DUTY_SID,PWM_E_PERIOD_UNCHANGEABLE);
    }else
#endif
    {
       Pwm_SetDutyCycle(ChannelNumber,DutyCycle);
       Gpt_ConfigType Gpt_Configg = 
       {
           .Module = TIMER2,
           .Channel = ChannelNumber,
           .TickRate = 1000000/Period,
           .Mode = PWM_MODE,
           .ClkSource = GPT_INTERNAL
       };
    
    Gpt_Init(&Gpt_Configg);
    
       Pwm_ThisConfiguration->Status = PWM_BUSY;
    }
}
void Pwm_SetOutputToIdle ( Pwm_ChannelType ChannelNumber )
{
#if (DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (ChannelNumber > 1 ) 
    {
		Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, 
        PWM_SET_OUT_IDLE_SID,PWM_E_PARAM_CHANNEL);
    
	} 
    else if(Pwm_ThisConfiguration->Status == PWM_UNINIT)
    {
        Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, 
        PWM_SET_OUT_IDLE_SID,PWM_E_UNINIT);   
    }else
#endif
    {
        CLEAR_BIT(PWM_CTL_REG1, 4);
        CLEAR_BIT(PWM_CTL_REG1, 5);
        CLEAR_REG(CCPR1L);
        Pwm_ThisConfiguration->Status = PWM_IDLE;
    }
}


#if(PWM_GET_STATUS_API==STD_ON)
Pwm_StatusType Pwm_GetStatus(void)
{
#if (DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
if(Pwm_ThisConfiguration->Status == PWM_UNINIT)
    {
        Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, 
        PWM_GET_STATUS_SID,PWM_E_UNINIT);   
    }else
#endif
    {
        return Pwm_ThisConfiguration->Status;
    }
    return E_NOT_OK;
}
#endif