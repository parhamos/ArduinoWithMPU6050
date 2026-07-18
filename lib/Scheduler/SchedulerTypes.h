/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Scheduler
 * File       : SchedulerTypes.h
 *
 * Version    : 3.0.0
 *
 * Description:
 *      Scheduler data types.
 *
 ******************************************************************************/

#ifndef SCHEDULER_TYPES_H
#define SCHEDULER_TYPES_H

#include <Arduino.h>

/*=============================================================================
    Task
=============================================================================*/

struct Task
{
    uint32_t period;

    uint32_t timer;

    uint32_t counter;

    bool enable;

    bool ready;
};

#endif