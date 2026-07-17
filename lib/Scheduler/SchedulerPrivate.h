/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Scheduler
 * File       : SchedulerPrivate.h
 *
 * Version    : 2.0.0
 *
 * Description:
 *      Internal scheduler task objects.
 *
 ******************************************************************************/

 #ifndef SCHEDULER_PRIVATE_H
 #define SCHEDULER_PRIVATE_H
 
 #include "SchedulerTypes.h"
 
 /*=============================================================================
     Internal Tasks
 =============================================================================*/
 
 extern Task sensorTask;
 
 extern Task calibrationTask;
 
 extern Task filterTask;
 
 extern Task statisticsTask;
 
 extern Task displayTask;
 
 extern Task protocolTask;

 extern Task buttonsTask;
 
 #endif // SCHEDULER_PRIVATE_H