//#include <pic.h>
//#include "OS/OS.h"
//#include "MCAL/Port.h"
//#include "EcuAL/Disp.h"
//#include "EcuAL/Eeprom.h"
//#include "EcuAL/TempSensor.h"
//#include "EcuAL/TempSystem.h"
//#include "MCAL/Pwm.h"
//
//uint8_t CurrentTemp[ADC_SAMPLES_NB] = {0} ;
//uint8_t CurrentTempAverage=0;
//uint8_t SetTemp;
//int8_t SetTemp_Semaphore=1;
//int8_t CurrentTemp_Semaphore=1;
//uint16_t SettingTempTime=0;
//uint8_t Eeprom_Address=0x00;
//typedef struct{
//uint8_t OnOffStateIndicator : 1 ;  //0:OFF - 1:ON
//uint8_t TempChangedFlag :1 ;
//uint8_t HeaterOpenedFlag : 1 ;
//uint8_t BlinkLedCounter : 4;
//}FlagsStruct;
//
//FlagsStruct flags = {0,0,0,0}; 
//
//extern Disp_ConfigType Disp_Config;
//extern Eep_ConfigType Eep_Config ;
//extern Port_ConfigType Port_ButtonsConfig[4] ;
//extern Gpt_ConfigType Gpt_Config ;
//extern Adc_ConfigType TempSensor_Config ;
//extern Os_ConfigType Os_Config;
//extern Port_ConfigType TempSystem_Configurations[2];
//
//void TickHandler()  //This function is called every 100ms
//{
//    SettingTempTime++;
//    if(!Dio_ReadChannel(ONOFF_BUTTON_CHANNEL) && flags.OnOffStateIndicator == 1)
//    {
//        while(!Dio_ReadChannel(ONOFF_BUTTON_CHANNEL));
//        Disp_Close();
//        TempSystem_CloseHeater();
//        TempSystem_CloseCooler();
//        Dio_WriteChannel(HEATING_LED_CHANNEL,LOW);
//        flags.OnOffStateIndicator = 0;
//        flags.TempChangedFlag = 0;
//        flags.HeaterOpenedFlag = 0;
//        flags.BlinkLedCounter = 0;
//        while(1)
//        {
//            if(!Dio_ReadChannel(ONOFF_BUTTON_CHANNEL))
//            {
//                while(!Dio_ReadChannel(ONOFF_BUTTON_CHANNEL));
//                flags.OnOffStateIndicator = 1; 
//                OS_Restart();                    
//            }
//        }
//    }
//    else
//        OS_Scheduler();
//}
//
//void Task_OffState(void);void Task_ReadEeprom(void);
//void Task_UpDownFirstTime(void);void Task_SetTemp(void);
//void Task_DispSetTemp(void);void Task_WriteEeprom(void);
//void Task_MeasureTemp(void);void Task_HeatOrCool(void);
//void Task_DispCurrentTemp(void);
//
//void main(void) {
//    for(int i = 0 ; i<4 ; i++)
//        Port_Init(&Port_ButtonsConfig[i]);
//    OS_Init(&Os_Config);
//    Disp_Init(&Disp_Config);
//    Eep_Init(&Eep_Config);
//    TempSensor_Init(&TempSensor_Config); 
//    TempSystem_Init(TempSystem_Configurations);
//    Gpt_Init(&Gpt_Config);
//    TRISB &= ~(0x70);
//    OS_Start();
//    while(1)
//    {  
//        Task_OffState();Task_ReadEeprom();Task_UpDownFirstTime();
//        Task_SetTemp();Task_DispSetTemp();Task_WriteEeprom();
//        Task_MeasureTemp();Task_HeatOrCool();Task_DispCurrentTemp();
//    }
//}
//
////State 0
//void Task_OffState(void)
//{ 
//    while(1)
//    {
//       DISABLE_INTERRUPTS;
//       if(!Dio_ReadChannel(ONOFF_BUTTON_CHANNEL))
//       {
//           while(!Dio_ReadChannel(ONOFF_BUTTON_CHANNEL));
//           OS_ChangeState(0);
//           flags.OnOffStateIndicator = 1;
//       }
//       ENABLE_INTERRUPTS;
//    }
//}
//
////State 1
//void Task_ReadEeprom(void)
//{ 
//    while(1)
//    {
//       DISABLE_INTERRUPTS;
//       Eep_Read (Eeprom_Address,&SetTemp,1);
//       if(SetTemp == 0)
//           SetTemp = 60 ;
//       OS_ChangeState(1);
//       ENABLE_INTERRUPTS;
//    }
//}
//
////State 2
//void Task_UpDownFirstTime(void)
//{ 
//    while(1)
//    {
//       DISABLE_INTERRUPTS;
//       if(!Dio_ReadChannel(DOWN_BUTTON_CHANNEL) || !Dio_ReadChannel(UP_BUTTON_CHANNEL))
//       {
//           while(!Dio_ReadChannel(DOWN_BUTTON_CHANNEL) || !Dio_ReadChannel(UP_BUTTON_CHANNEL));
//           OS_ChangeState(2);
//       }
//       ENABLE_INTERRUPTS;
//    }
//}
//
////State 3
//void Task_SetTemp(void)
//{ 
//    while(1)
//    {
//       DISABLE_INTERRUPTS;     
//       if(!OS_Wait(&SetTemp_Semaphore))
//       {
//           if(!Dio_ReadChannel(DOWN_BUTTON_CHANNEL) && SetTemp>=40) 
//           {
//               while(!Dio_ReadChannel(DOWN_BUTTON_CHANNEL)){}
//                    SetTemp-=5;
//                    SettingTempTime = 0;
//                    flags.TempChangedFlag=1;
//           }
//           else if(!Dio_ReadChannel(UP_BUTTON_CHANNEL) && SetTemp<=70) 
//           {
//               while(!Dio_ReadChannel(UP_BUTTON_CHANNEL)){}
//                    SetTemp+=5;
//                    SettingTempTime = 0;
//                    flags.TempChangedFlag=1;
//           }
//           else
//                OS_Signal(&SetTemp_Semaphore);
//       }
//       ENABLE_INTERRUPTS;
//    }
//}
//void Task_DispSetTemp(void)
//{
//    while(1)
//    {       
//       DISABLE_INTERRUPTS;  
//       if(!OS_Wait(&SetTemp_Semaphore))
//            Disp_DisplayNb(SetTemp,BLINKING);
//       OS_Signal(&SetTemp_Semaphore);
//       ENABLE_INTERRUPTS; 
//    }
//}
//void Task_WriteEeprom(void)
//{
//   while(1)
//    {
//      DISABLE_INTERRUPTS;  
//      if(!OS_Wait(&SetTemp_Semaphore))
//      {
//          if(SettingTempTime >= 150 && flags.TempChangedFlag==1) 
//          {
//              Eep_Write(Eeprom_Address,&SetTemp,1);
//              __delay_ms(10);
//              OS_ChangeState(5);
//          }
//          else
//              OS_Signal(&SetTemp_Semaphore);
//      }
//      ENABLE_INTERRUPTS; 
//    }
//}
//
////State 4
//void Task_MeasureTemp(void)
//{
//   while(1)
//    {
//      DISABLE_INTERRUPTS;  
//      if(!OS_Wait(&CurrentTemp_Semaphore))
//      {     
//            while(TempSensor_GetTemp(CurrentTemp) != E_OK){}
//            GET_AVERAGE(CurrentTempAverage,CurrentTemp,ADC_SAMPLES_NB);
//            OS_Signal(&CurrentTemp_Semaphore);              
//      }
//      ENABLE_INTERRUPTS; 
//    }
//}
//void Task_HeatOrCool(void)
//{
//   while(1)
//    {
//      DISABLE_INTERRUPTS;
//      if(!OS_Wait(&CurrentTemp_Semaphore))  
//      {
//        if(CurrentTempAverage<(SetTemp-5))
//        {
//          TempSystem_OpenHeater();
//          TempSystem_CloseCooler();
//          flags.HeaterOpenedFlag = 1;
//        }        
//        if(CurrentTempAverage>(SetTemp+5))
//        {
//          TempSystem_SetCoolerPower(((CurrentTempAverage - SetTemp)+15)*5);
//          TempSystem_CloseHeater();            
//          flags.HeaterOpenedFlag = 0;
//        }        
//        OS_Signal(&CurrentTemp_Semaphore);
//      }
//        ENABLE_INTERRUPTS; 
//    }
//}
//void Task_DispCurrentTemp(void)
//{
//   while(1)
//    {
//      DISABLE_INTERRUPTS;   
//      if(!OS_Wait(&CurrentTemp_Semaphore))
//           Disp_DisplayNb(CurrentTempAverage,FIXED);
//      OS_Signal(&CurrentTemp_Semaphore);
//      
//      if(flags.HeaterOpenedFlag == 1)
//      {
//          flags.BlinkLedCounter++;
//          if(flags.BlinkLedCounter == 10)
//          {              
//              Dio_ToggleChannel(HEATING_LED_CHANNEL);
//              flags.BlinkLedCounter = 0;
//          }          
//      } 
//      else
//      {
//          Dio_WriteChannel(HEATING_LED_CHANNEL, HIGH);          
//          TempSystem_SetCoolerPower(((CurrentTempAverage - SetTemp)+15)*5);
//      }
//      ENABLE_INTERRUPTS; 
//    }
//}

#include <pic.h>
#include "OS/OS2.h"
#include "MCAL/Port.h"
#include "EcuAL/Disp.h"
#include "EcuAL/Eeprom.h"
#include "EcuAL/TempSensor.h"
#include "EcuAL/TempSystem.h"
#include "MCAL/Pwm.h"

uint8_t CurrentTemp[ADC_SAMPLES_NB] = {0} ;
uint8_t CurrentTempAverage=0;
uint8_t SetTemp;
int8_t SetTemp_Semaphore=1;
int8_t CurrentTemp_Semaphore=1;
uint16_t SettingTempTime=0;
uint8_t Eeprom_Address=0x00;
typedef struct{
uint8_t OnOffStateIndicator : 1 ;  //0:OFF - 1:ON
uint8_t TempChangedFlag :1 ;
uint8_t HeaterOpenedFlag : 1 ;
uint8_t BlinkLedCounter : 4;
}FlagsStruct;

FlagsStruct flags = {0,0,0,0}; 

uint8_t State = 0;

extern Disp_ConfigType Disp_Config;
extern Eep_ConfigType Eep_Config ;
extern Port_ConfigType Port_ButtonsConfig[4] ;
extern Gpt_ConfigType Gpt_Config ;
extern Adc_ConfigType TempSensor_Config ;
extern Port_ConfigType TempSystem_Configurations[2];


//void Task_OffState(void);void Task_ReadEeprom(void);
//void Task_UpDownFirstTime(void);void Task_SetTemp(void);
//void Task_DispSetTemp(void);void Task_WriteEeprom(void);
//void Task_MeasureTemp(void);void Task_HeatOrCool(void);
//void Task_DispCurrentTemp(void);

void TickHandler()
{
    Os2_scheduler();
}
void task1();
void task2();
void task3();
void task4();
void task5();
void (*Tasks[TASKS_NB]) (void) = 
{
    task1,task2,task3,task4,task5
};
volatile int ii = 0;

CounterType EndTimes[TASKS_NB] = {1,3,5,7,9};


void Init_Task();
int main(void)
{
    Os2_Init(EndTimes);
    Os2_AddThreads(Tasks);
	Os2_start();
    while(1)
    {
        task1();task2();task3();task4();task5();
    }
}

void Init_Task()
{
    for(int i = 0 ; i<4 ; i++)
        Port_Init(&Port_ButtonsConfig[i]);
    Disp_Init(&Disp_Config);
    Eep_Init(&Eep_Config);
    TempSensor_Init(&TempSensor_Config); 
    TempSystem_Init(TempSystem_Configurations);
    Gpt_Init(&Gpt_Config);
}

//State 0
void task1(void)
{ 
    while(1)
    {
       DISABLE_INTERRUPTS;
       if(State == 0)
       {
           if(!Dio_ReadChannel(ONOFF_BUTTON_CHANNEL))
            {
                while(!Dio_ReadChannel(ONOFF_BUTTON_CHANNEL));
                State = 1;
                flags.OnOffStateIndicator = 1;
            }
        }
       
       ENABLE_INTERRUPTS;
    }
}

//State 1
void task2(void)
{ 
    while(1)
    {
        DISABLE_INTERRUPTS;
        if(State == 1)
        {
            Eep_Read (Eeprom_Address,&SetTemp,1);
            if(SetTemp == 0)
                SetTemp = 60 ;
            State = 2;
        }
        ENABLE_INTERRUPTS;
    }
}

//State 2
void task3(void)
{ 
    while(1)
    {
       DISABLE_INTERRUPTS;
       if(State == 2)
       {
            if(!Dio_ReadChannel(DOWN_BUTTON_CHANNEL) || !Dio_ReadChannel(UP_BUTTON_CHANNEL))
            {
                while(!Dio_ReadChannel(DOWN_BUTTON_CHANNEL) || !Dio_ReadChannel(UP_BUTTON_CHANNEL));
                State = 3;
            }
       }
       ENABLE_INTERRUPTS;
    }
}

//State 3
void task4(void)
{ 
    while(1)
    {
       DISABLE_INTERRUPTS;     
       if(State == 3)
       {
           if(!Dio_ReadChannel(DOWN_BUTTON_CHANNEL) && SetTemp>=40) 
           {
               while(!Dio_ReadChannel(DOWN_BUTTON_CHANNEL)){}
                    SetTemp-=5;
                    SettingTempTime = 0;
                    flags.TempChangedFlag=1;
           }
           else if(!Dio_ReadChannel(UP_BUTTON_CHANNEL) && SetTemp<=70) 
           {
               while(!Dio_ReadChannel(UP_BUTTON_CHANNEL)){}
                    SetTemp+=5;
                    SettingTempTime = 0;
                    flags.TempChangedFlag=1;
           }           
       }
       ENABLE_INTERRUPTS;
    }
}
void task5(void)
{
    while(1)
    {       
       DISABLE_INTERRUPTS;  
       if(State == 3)
            Disp_DisplayNb(SetTemp,BLINKING);
       ENABLE_INTERRUPTS; 
    }
}

//void Task_WriteEeprom(void)
//{
//   while(1)
//    {
//      DISABLE_INTERRUPTS;  
//      if(!OS_Wait(&SetTemp_Semaphore))
//      {
//          if(SettingTempTime >= 150 && flags.TempChangedFlag==1) 
//          {
//              Eep_Write(Eeprom_Address,&SetTemp,1);
//              __delay_ms(10);
//              OS_ChangeState(5);
//          }
//          else
//              OS_Signal(&SetTemp_Semaphore);
//      }
//      ENABLE_INTERRUPTS; 
//    }
//}




//os2 + 10 readings
//context switch
//commenting


//#include "MCAL/Pwm.h"
//extern Pwm_ConfigType Pwm_Config;
//void main(void) 
//{
//  Pwm_Init(&Pwm_Config);
//  uint8_t x ;
//  while(1)
//  {
//      Pwm_SetDutyCycle(0,x++);
//      __delay_ms(5);
//  }
//}


//#include "EcuAL/Eeprom.h"
//Eep_ConfigType Eep_Config = {0xA0};
//void main(void) {
//  Eep_Init(&Eep_Config);
//  unsigned int Address=0x00;
//  uint8_t xx[2] = {0x2A,0x31};
//  uint8_t aa[2];
//  Eep_Write(Address,xx,2);
//  __delay_ms(10);
//  TRISD = 0x00;
//  TRISB = 0x00;
//  Eep_Read (Address,aa,2);
//  PORTD = aa[0];
//  PORTB = aa[1];
//}




//#include "EcuAL/TempSensor.h"
//#include "EcuAL/TempSystem.h"
//#include "MCAL/Gpt.h"
//#include "EcuAL/lcd.h"
//#include "MCAL/adc.h"
//uint8_t a[3] ;
//extern Adc_ConfigType TempSensor_Config ;
//extern Port_ConfigType TempSystem_Configurations[2];
//void main(void) 
//{   
//    LCD_init();
//    TempSensor_Init(&TempSensor_Config); 
//    TempSystem_Init(TempSystem_Configurations);
//    TRISB = 0x00;
//    TRISD = 0x00;
//    TempSystem_OpenHeater();
//    TempSystem_OpenCooler();
//    while(1)
//  {  
//    while(TempSensor_GetTemp(a) != E_OK);
//    LCD_clearScreen();
//    LCD_intgerToString(a[0]); //1st sample
//    LCD_goToRowColumn(0,6);
//    LCD_intgerToString(a[1]); //2nd sample
//    LCD_goToRowColumn(1,0);
//    LCD_intgerToString(a[2]); //3rd sample
//    __delay_ms(1000);
//  }
//}


//#include "Det.h"
//#include "MCAL/Pwm.h"
//
//
//void main(void) 
//{
//    uint8_t a = 0;
//    Det_Init();
//    while(1)  
//    {
//        Pwm_SetDutyCycle(0,10); //calling this API without initializing the PWM module
//    }
//}

