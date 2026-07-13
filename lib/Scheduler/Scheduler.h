/******************************************************************************
 * Project : AccelMeter
 * Module  : Scheduler
 * File    : Scheduler.h
 * Version : 2.0.0
 ******************************************************************************/

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <Arduino.h>

/**************************************************
 * Task
 **************************************************/

struct Task
{
    uint32_t timer = 0;

    uint16_t period = 100;

    bool enable = true;

    uint32_t counter = 0;

    Task() {}

    Task(uint16_t p)
    {
        period = p;
    }
};

/**************************************************
 * Scheduler
 **************************************************/

class Scheduler
{

public:

    bool run(Task &task);

};

extern Scheduler scheduler;

#endif