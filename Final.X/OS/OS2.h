 /******************************************************************************
 *
 * Module: Os
 *
 * File Name: Os.h
 *
 * Description: Header file for Os Scheduler.
 *
 * Author: Mostafa Amgad
 ******************************************************************************/

#ifndef OS2_H_
#define OS2_H_

#include "../MCAL/Port.h"

/* Timer counting time in ms */
#define OS_BASE_TIME 1

/* Function responsible for:
 * 1. Initialize the Os
 * 2. Execute the Init Task
 * 3. Start the Scheduler to run the tasks
 */
typedef uint8_t CounterType;
void Os2_Init(CounterType*);
void Os2_start(void);

void Os2_AddThreads(void (**Tasks) (void));
/* The Engine of the Os Scheduler used for switch between different tasks */
void Os2_scheduler(void);

#endif /* OS_H_ */
