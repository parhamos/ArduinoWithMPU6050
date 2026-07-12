/******************************************************************************
 * Project : AccelMeter
 * Module  : Scheduler
 * File    : Scheduler.cpp
 * Version : 1.0.0
 ******************************************************************************/

#include "Scheduler.h"

Scheduler scheduler;

bool Scheduler::elapsed(uint32_t &timer, uint32_t period)
{
    uint32_t now = millis();

    if ((now - timer) >= period)
    {
        timer = now;
        return true;
    }

    return false;
}