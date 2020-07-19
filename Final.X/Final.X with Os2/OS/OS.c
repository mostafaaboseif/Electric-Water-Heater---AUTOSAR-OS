#include <stdint.h>
#include <pic.h>
#include "OS.h"

uint8_t Base_Tasks [MAX_NB_STATES];  //index to 1st task in each state

void OS_Init(Os_ConfigType* ConfigPtr)
{    
    uint8_t tcbid;
    for(int i=0 ; i<ConfigPtr->NbOfStates ; i++)
    {
       for(int j=0 ; j<ConfigPtr->NbOfTasks_Array[i] ; j++)
       {
           Tcb_Array[tcbid+j].Next_Task = &Tcb_Array[tcbid+(j+1)%ConfigPtr->NbOfTasks_Array[i]];
           Tcb_Array[tcbid+j].State = i;
       }
      Base_Tasks[i] = tcbid;
      tcbid += ConfigPtr->NbOfTasks_Array[i];    
    }
    for(int i = 0 ; i<TASKS_NB ; i++)
    {
         Tcb_Array[i].Task_Id = i;
         Tcb_Array[i].Task = ConfigPtr->TaskTable[i];      
    } 
}

//******** OS_Launch ***************
// Starts the very first function;
// Afterwards, scheduler will call the remaining functions.
void OS_Start(void)
{
    CurrentThread = &Tcb_Array[0];
    CurrentThread->Task();
}

void OS_Restart(void)
{
    CurrentThread = &Tcb_Array[1];
    CurrentThread->Task();
 }

//******** OS_Scheduler ***************
// This will be the only function in the main while{} code
// This runs each thread in a cooperative tail chain.
// If thread is blocked, will skip to the next thread.
// If all threads are blocked, will then send the processor to sleep;
// Thread will be blocked from running if OS_Pass{} returns a (0) a fail; 
// Interrupt will be the only event that will wake the processor to sleep, 
// and resume the OS_Scheduler.
void OS_Scheduler(void)
{          
	if(CurrentThread->StateChangeTrigger == 1)
    {
        CurrentThread->StateChangeTrigger = 0;
        CurrentThread = &Tcb_Array[Base_Tasks[CurrentThread->State + 1]];       
    }
    else
        CurrentThread = CurrentThread->Next_Task;     //get the next run pointer;
 
#if(EXTRA_FEATURES==STD_ON)    
    TcbType *PreviousThread;  
    uint8_t SleepFlag = 0;    
    PreviousThread = CurrentThread;        //save previous run pointer;
    
    while(CurrentThread->Blocked_Sem)    
    {
        CurrentThread = CurrentThread->Next_Task;   //skip if blocked;
        
        if (CurrentThread == PreviousThread)  //everyone is blocked;
        {
            if (CurrentThread->Blocked_Sem) //check if the first element was also blocked;
            {
                SLEEP();
            }
            break;
        }
    }    
#endif
    
    CurrentThread->Task();  //run next function;

}

// ******** OS_Wait ************
// - Purpose: to tell the currently running thread to claim 
// control of resource and make it wait if it's not available
// - Decrements semaphore. If s is now less than zero, 
// the current process is blocked and pushed into q. 
// - Inputs:  pointer to a counting semaphore
// - Outputs: 0 if thread is allowed to proceed;
//            1 if waiting for a semaphore;
uint8_t OS_Wait(int8_t *Ptr_Semaphore)
{
    uint8_t Accessible;
    
    if( CurrentThread->Blocked_Sem != Ptr_Semaphore)
        (*Ptr_Semaphore)--;   
    
    if (*Ptr_Semaphore >= 0)   //accessible
        Accessible = 0;
    else
    {
        CurrentThread->Blocked_Sem = Ptr_Semaphore;
        Accessible = 1;
    }        
    
    return(Accessible);
	
}

// ******** OS_Signal ************
// - Purpose: for one process to tell other process that it has 
// finished using the resource, it's become available for blocked threads
// - Increment semaphore. If s<=0, then the next blocked 
// process in q is dequeued and becomes unblocked
// wakeup blocked thread if appropriate
// - Inputs:  pointer to a counting semaphore
// - Outputs: none
void OS_Signal(int8_t *Ptr_Semaphore)
{
	TcbType *Thread_X;
    int8_t *Ptr_BlockedResource;
        
	if(*Ptr_Semaphore < 0)
	{
  		Thread_X = CurrentThread->Next_Task;  //search for thread blocked on this semaphore
        Ptr_BlockedResource = Thread_X->Blocked_Sem;    
        
		while(!(Thread_X->Blocked_Sem == Ptr_Semaphore))
		{
			Thread_X= Thread_X->Next_Task; 
		}
		Thread_X->Blocked_Sem = 0;  //wakeup this thread
	}
    
    *Ptr_Semaphore = 1;
     
}

void OS_ChangeState(uint8_t Task_Id)
{
    Tcb_Array[Task_Id].StateChangeTrigger = 1;
}