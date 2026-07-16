/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Scheduler
 * File       : SchedulerTypes.h
 *
 * Version    : 2.0.0
 *
 * Description:
 *      Scheduler data types.
 *
 ******************************************************************************/

#ifndef SCHEDULER_TYPES_H
#define SCHEDULER_TYPES_H

#include <Arduino.h>

/*=============================================================================
    Task Object
=============================================================================*/

struct Task
{
    uint32_t period;

    uint32_t timer;

    uint32_t counter;

    bool enable;
};

#endif // SCHEDULER_TYPES_H