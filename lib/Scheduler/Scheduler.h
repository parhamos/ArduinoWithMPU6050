/******************************************************************************
 * Project : AccelMeter
 * Module  : Scheduler
 * File    : Scheduler.h
 * Version : 1.0.0
 ******************************************************************************/

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <Arduino.h>

class Scheduler
{

public:

    bool elapsed(uint32_t &timer, uint32_t period);

};

extern Scheduler scheduler;

#endif