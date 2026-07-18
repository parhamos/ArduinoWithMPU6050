/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Scheduler
 * File       : Scheduler.h
 *
 * Version    : 3.0.0
 *
 * Description:
 *      Deterministic cyclic scheduler.
 *
 ******************************************************************************/

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <Arduino.h>

#include "Model.h"
#include "SchedulerTypes.h"

/*=============================================================================
    Scheduler
=============================================================================*/

class Scheduler
{
public:

    Scheduler();

    bool begin();

    void run();

private:

    void updateTask(
        Task& task,
        uint32_t period);

};

extern Scheduler scheduler;

#endif