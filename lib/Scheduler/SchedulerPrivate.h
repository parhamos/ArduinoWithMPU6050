/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Scheduler
 * File       : SchedulerPrivate.h
 *
 * Version    : 3.0.0
 *
 * Description:
 *      Internal scheduler task objects.
 *
 ******************************************************************************/

#ifndef SCHEDULER_PRIVATE_H
#define SCHEDULER_PRIVATE_H

#include "SchedulerTypes.h"

/*=============================================================================
    Scheduler Tasks
=============================================================================*/

extern Task buttonsTask;

extern Task measurementTask;

extern Task sensorTask;

extern Task calibrationTask;

extern Task filterTask;

extern Task statisticsTask;

extern Task displayTask;

extern Task protocolTask;

#endif