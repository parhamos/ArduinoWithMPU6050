/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Scheduler
 * File       : SchedulerConfig.h
 *
 * Version    : 3.0.0
 *
 * Description:
 *      Scheduler timing configuration.
 *
 ******************************************************************************/

#ifndef SCHEDULER_CONFIG_H
#define SCHEDULER_CONFIG_H

#include <Arduino.h>

/*=============================================================================
    Scheduler Tick
=============================================================================*/

constexpr uint16_t kSchedulerTick = 1U;

/*=============================================================================
    Task Periods
=============================================================================*/

constexpr uint16_t kButtonsPeriod       = 10U;

constexpr uint16_t kMeasurementPeriod   = 10U;

constexpr uint16_t kSensorPeriod        = 10U;

constexpr uint16_t kCalibrationPeriod   = 10U;

constexpr uint16_t kFilterPeriod        = 10U;

constexpr uint16_t kStatisticsPeriod    = 10U;

constexpr uint16_t kDisplayPeriod       = 100U;

constexpr uint16_t kProtocolPeriod      = 50U;

#endif