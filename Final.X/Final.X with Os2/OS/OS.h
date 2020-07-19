
#ifndef OS_H
#define	OS_H

#include <stdint.h>
#include "../MCAL/Port.h"
#include "../MCAL/Gpt.h"


#if(CONTEXT_SWITCH_CAPABILITY==STD_ON)
#define RETURN_ADDRESS ((PCLATH << 8) | PCL) + 23
#define GO_TO_ADDRESS(ADDR) PCLATH = ((ADDR) >> 8); PCL = ((uint8) (ADDR))
#define JUMP_AND_LINK(GO,RETURN) RETURN = RETURN_ADDRESS;GO_TO_ADDRESS(GO)

asm("W_TEMP equ 1F0h");
asm("STATUS_TEMP equ 1F1h");
asm("FSR_TEMP equ 1F2h");

volatile uint8_t W_TEMP __at(0x1F0);
volatile uint8_t STATUS_TEMP __at(0x1F1);
volatile uint8_t FSR_TEMP __at(0x1F2);

#define SAVE_CONTEXT(tcbId,pc){\
    asm(" MOVWF W_TEMP ");    \
    asm(" MOVF STATUS, W");    \
    asm(" CLRF STATUS ");     \
    asm(" MOVWF STATUS_TEMP");  \
    asm(" MOVF FSR, W");  \
    asm(" MOVWF FSR_TEMP");   \
    asm(" CLRF FSR");   \
    Tcb_Array[tcbId].stack[0] = W_TEMP;\
    Tcb_Array[tcbId].stack[1] = STATUS_TEMP;\
    Tcb_Array[tcbId].stack[2] = FSR_TEMP;\
    Tcb_Array[tcbId].stack[3] = pc>>8;\
    Tcb_Array[tcbId].stack[4] = (uint8_t)pc;\
}

#define RESTORE_CONTEXT(tcbId){\
    asm(" MOVF FSR_TEMP, W ");    \
    asm(" MOVWF FSR");    \
    asm(" MOVF STATUS_TEMP, W ");    \
    asm(" MOVWF STATUS");    \
    asm(" MOVF W_TEMP, W ");    \
    PCLATH = Tcb_Array[tcbId].stack[3];\
}
#endif

struct TCB{
  uint8_t Task_Id : 4 ;
  uint8_t State : 3;
  uint8_t StateChangeTrigger : 1;
  void (*Task) (void); // pointer to function
  struct TCB *Next_Task;    // linked-list pointer
  int8_t *Blocked_Sem;	   //pointer to blocked resource
#if(CONTEXT_SWITCH_CAPABILITY==STD_ON)
  uint8_t stack[5];  // WREG - STATUS - FSR -PCLATH - PCL
#endif
};

typedef void (*Task_Ptr)(void);
typedef struct TCB TcbType;

typedef struct{
    uint8_t NbOfStates;
    uint8_t NbOfTasks_Array[5];
    Task_Ptr TaskTable[TASKS_NB];
}Os_ConfigType;

TcbType Tcb_Array[TASKS_NB];

TcbType *CurrentThread;

void OS_Init(Os_ConfigType*);
void OS_Start(void);
void OS_Restart(void);
void OS_Scheduler(void);
uint8_t OS_Wait(int8_t*);
void OS_Signal(int8_t*);
void OS_ChangeState(uint8_t);

#endif	

