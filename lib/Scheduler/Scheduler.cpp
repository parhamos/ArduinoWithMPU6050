/******************************************************************************
 * Project : AccelMeter
 * Module  : Scheduler
 * File    : Scheduler.cpp
 * Version : 2.0.0
 ******************************************************************************/

#include "Scheduler.h"

Scheduler scheduler;

bool Scheduler::run(Task &task)
{
    if (!task.enable)
        return false;

    uint32_t now = millis();

    if ((now - task.timer) >= task.period)
    {
        task.timer = now;

        task.counter++;

        return true;
    }

    return false;
}