/***************************************************************
*
* Module: Gpt
*
* File Name: Gpt.c
*
* Description: Source file for Gpt Module,
*              implementation is based on AUTOSAR specfications.
*
* Author: Mostafa Amgad
*
* Date:  July 17, 2020
****************************************************************/

/*=================================================================
                            INCLUDES
*================================================================*/
#include "Gpt.h"


/*=================================================================
                    GLOBAL STATIC VARIABLES
*================================================================*/
Gpt_ConfigType* Gpt_ThisConfiguration_1 = NULL ;
Gpt_ConfigType* Gpt_ThisConfiguration_2 = NULL ;
Gpt_ValueType Gpt_ReloadValue ;
 

/*=================================================================
                LOCAL FUNCTIONS IMPLEMENTATION
*================================================================*/
void Interrupt_TimerCallbackFn()
{
    GPT_RELO_REG=Gpt_ReloadValue;
    TMR1IF = 0;
    Gpt_ThisConfiguration_1->CallbackFn();
}

/*=================================================================
                     APIs IMPLEMENTATION
*================================================================*/
void Gpt_Init(Gpt_ConfigType* ConfigPtr)
{   
#if (DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (ConfigPtr == NULL) 
    {
		Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, 
        GPT_INIT_SID,GPT_E_PARAM_POINTER);
	} 
    else if(ConfigPtr->Mode != TIMER_MODE && ConfigPtr->Mode != PWM_MODE)
    {
       Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, 
        GPT_INIT_SID,GPT_E_PARAM_MODE);
    }
    else if(ConfigPtr->Module != TIMER1 && ConfigPtr->Module != TIMER2)
    {
       Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, 
        GPT_INIT_SID,GPT_E_PARAM_PREDEF_TIMER);
    }
    else if(ConfigPtr->Channel >2)
    {
       Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, 
        GPT_INIT_SID,GPT_E_PARAM_CHANNEL);
    }else
#endif        
    {
      if(ConfigPtr->Module == TIMER1 && ConfigPtr->Channel == 0 
            && ConfigPtr->Mode == TIMER_MODE) 
      {
       GPT_CTL_REG1 |= (ConfigPtr->ClkSource<<1);

      if(ConfigPtr->TickRate>39)
      {
          GPT_CTL_REG1 = (GPT_PRE_1 <<4);
          //Gpt_ReloadValue=(65535-(_XTAL_FREQ/(ConfigPtr->TickRate*4*(pow(2,GPT_PRE_1)))));        
          Gpt_ReloadValue=(65535-(_XTAL_FREQ/(ConfigPtr->TickRate*4*1)));
      }
      else if(ConfigPtr->TickRate>20)
      {
          GPT_CTL_REG1 = (GPT_PRE_2 <<4);
          //Gpt_ReloadValue=(65535-(_XTAL_FREQ/(ConfigPtr->TickRate*4*(pow(2,GPT_PRE_2)))));
          Gpt_ReloadValue=(65535-(_XTAL_FREQ/(ConfigPtr->TickRate*4*2)));
      }
      else if(ConfigPtr->TickRate>10)
      {
          GPT_CTL_REG1 = (GPT_PRE_4 <<4);
          //Gpt_ReloadValue=(65535-(_XTAL_FREQ/(ConfigPtr->TickRate*4*(pow(2,GPT_PRE_4)))));
          Gpt_ReloadValue=(65535-(_XTAL_FREQ/(ConfigPtr->TickRate*4*4)));
      }
      else if(ConfigPtr->TickRate>5)
      {
          GPT_CTL_REG1 = (GPT_PRE_8 <<4);
          //Gpt_ReloadValue=(65535-(_XTAL_FREQ/(ConfigPtr->TickRate*4*(pow(2,GPT_PRE_8)))));
          Gpt_ReloadValue=(65535-(_XTAL_FREQ/(ConfigPtr->TickRate*4*8)));
      }
#if (DEV_ERROR_DETECT == STD_ON)
      else 
      {
           Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, 
           GPT_INIT_SID,GPT_E_PARAM_VALUE);
      }  
#endif      
      
      if(ConfigPtr->Mode==TIMER_MODE && ConfigPtr->ClkSource==GPT_INTERNAL)
          CLEAR_BIT(GPT_CTL_REG1,1);
      else if(ConfigPtr->Mode==COUNTER_MODE && ConfigPtr->ClkSource==GPT_EXTERNAL)
          SET_BIT(GPT_CTL_REG1,1);

      Gpt_ThisConfiguration_1 = ConfigPtr ;
      Gpt_ThisConfiguration_1->Status = GPT_IDLE;

      GPT_RELO_REG = Gpt_ReloadValue; 
      SET_BIT(GPT_CTL_REG1,0);
      Interrupt_Enable(TIMER,Interrupt_TimerCallbackFn);

      Gpt_ThisConfiguration_1->Status = GPT_BUSY;

    }   
    else if(ConfigPtr->Module == TIMER2 && ConfigPtr->Mode == PWM_MODE)
    {
        if(ConfigPtr->TickRate>10000)
      {
          GPT_CTL_REG2 = ((GPT_PRE_1/2) <<0);
          //PR2 = _XTAL_FREQ/(ConfigPtr->TickRate*4*pow(2,GPT_PRE_1))-1;
          PR2 = _XTAL_FREQ/(ConfigPtr->TickRate*4*1)-1;
      }
      else if(ConfigPtr->TickRate>2500)
      {
          GPT_CTL_REG2 = ((GPT_PRE_4/2) <<0);
          //PR2 = _XTAL_FREQ/(ConfigPtr->TickRate*4*pow(2,GPT_PRE_4))-1;
          PR2 = _XTAL_FREQ/(ConfigPtr->TickRate*4*4)-1;
      }
      else if(ConfigPtr->TickRate>600)
      {
          GPT_CTL_REG2 = ((GPT_PRE_16/2) <<0);
          //PR2 = _XTAL_FREQ/(ConfigPtr->TickRate*4*pow(2,GPT_PRE_16))-1;
          PR2 = _XTAL_FREQ/(ConfigPtr->TickRate*4*16)-1;
      }
#if (DEV_ERROR_DETECT == STD_ON)
      else 
      {
           Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, 
           GPT_INIT_SID,GPT_E_PARAM_VALUE);
      }  
#endif 

       SET_BIT(GPT_CTL_REG2,2);
    }
    }
}


#if(GPT_DEINIT_API==STD_ON)
void Gpt_DeInit(Gpt_ModuleType Module)
{
#if (DEV_ERROR_DETECT == STD_ON)
    if(Gpt_ThisConfiguration_1->Status == GPT_UNINIT && Gpt_ThisConfiguration_2->Status == GPT_UNINIT)
    {
       Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, 
        GPT_DEINIT_SID,GPT_E_UNINIT);
    }
    else if(Gpt_ThisConfiguration_1->Module != TIMER1 && Gpt_ThisConfiguration_2->Module != TIMER2)
    {
       Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, 
        GPT_DEINIT_SID,GPT_E_PARAM_PREDEF_TIMER);
    }else
#endif  
    {
        if(Module == TIMER1)
        {
            CLEAR_REG(GPT_CTL_REG1);
            CLEAR_REG(GPT_RELO_REG);
            Interrupt_Disable(TIMER);
        }
        else if(Module == TIMER2)
        {  
            CLEAR_REG(T2CON);
        }
    }
    
}
#endif


#if(GPT_GET_STATUS_API==STD_ON)
Gpt_StatusType Gpt_GetStatus(Gpt_ModuleType Module)
{
#if (DEV_ERROR_DETECT == STD_ON)
    if(Gpt_ThisConfiguration_1->Status == GPT_UNINIT && Gpt_ThisConfiguration_2->Status == GPT_UNINIT)
    {
       Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, 
        GPT_GET_STATUS_SID,GPT_E_UNINIT);
    }
    else if(Gpt_ThisConfiguration_1->Module != TIMER1 && Gpt_ThisConfiguration_2->Module != TIMER2)
    {
       Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, 
        GPT_GET_STATUS_SID,GPT_E_PARAM_PREDEF_TIMER);
    }else
#endif  
    {
        if(Module == TIMER1)
        {
             return Gpt_ThisConfiguration_1->Status;
        }
        else if(Module == TIMER2)
        {  
            return Gpt_ThisConfiguration_2->Status;
        }
    }
    return E_NOT_OK;
}
#endif