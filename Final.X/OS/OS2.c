 /******************************************************************************
 *
 * Module: Os2
 *
 * File Name: Os.c
 *
 * Description: Source file for Os Scheduler.
 *
 * Author: Mostafa Amgad
 ******************************************************************************/

#include "OS2.h"

static void (*TaskTable[TASKS_NB]) (void);
static uint8_t States_EndTime[TASKS_NB];
void Init_Task();
/* Global variable store the Os Time */
static CounterType TickCount = 0;

void Os2_Init(CounterType *EndTimes)
{
    for(int i = 0 ; i<TASKS_NB ; i++)
        States_EndTime[i] = EndTimes[i];
}
/*********************************************************************************************/
void Os2_start(void)
{
	/* Execute the Init Task */
	Init_Task();

	/* Start the Os Scheduler */
	Os2_scheduler();
}
/*********************************************************************************************/
void Os2_AddThreads(void (**Tasks) (void))
{
    for(int i = 0 ; i<TASKS_NB ; i++)
        TaskTable[i] = Tasks[i];   
}
/*********************************************************************************************/
void Os2_scheduler(void)
{
    TickCount   += OS_BASE_TIME;
    
    if(TickCount<=States_EndTime[0])
    {
        TaskTable[0]();
    }
    else if(TickCount<=States_EndTime[1])
    {
        TaskTable[1]();
    }
    else if(TickCount<=States_EndTime[2])
    {
        TaskTable[2]();
    }
    else if(TickCount<=States_EndTime[3])
    {
        TaskTable[3]();
    }
    else if(TickCount<=States_EndTime[4])
    {
        TaskTable[4]();
    }
    else
    {
        TickCount = 0;
    }
		
}
/*********************************************************************************************/
