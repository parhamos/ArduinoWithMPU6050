/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Scheduler
 * File       : Scheduler.cpp
 *
 * Version    : 3.0.0
 *
 * Description:
 *      Deterministic cyclic scheduler implementation.
 *
 ******************************************************************************/

#include "Scheduler.h"

#include "SchedulerConfig.h"
#include "SchedulerPrivate.h"

#include "Buttons.h"
#include "Measurement.h"
#include "Sensor.h"
#include "Calibration.h"
#include "Filter.h"
#include "Statistics.h"
#include "Display.h"
#include "Protocol.h"

/*=============================================================================
    Global Instance
=============================================================================*/

Scheduler scheduler;

/*=============================================================================
    Internal Tasks
=============================================================================*/

Task buttonsTask;

Task measurementTask;

Task sensorTask;

Task calibrationTask;

Task filterTask;

Task statisticsTask;

Task displayTask;

Task protocolTask;

/*=============================================================================
    Constructor
=============================================================================*/

Scheduler::Scheduler()
{
}

/*=============================================================================
    Initialization
=============================================================================*/

bool Scheduler::begin()
{
    /*
        Buttons
    */

    buttonsTask.timer   = millis();
    buttonsTask.counter = 0U;
    buttonsTask.enable  = true;
    buttonsTask.ready   = false;

    /*
        Measurement
    */

    measurementTask.timer   = millis();
    measurementTask.counter = 0U;
    measurementTask.enable  = true;
    measurementTask.ready   = false;

    /*
        Sensor
    */

    sensorTask.timer   = millis();
    sensorTask.counter = 0U;
    sensorTask.enable  = true;
    sensorTask.ready   = false;

    /*
        Calibration
    */

    calibrationTask.timer   = millis();
    calibrationTask.counter = 0U;
    calibrationTask.enable  = true;
    calibrationTask.ready   = false;

    /*
        Filter
    */

    filterTask.timer   = millis();
    filterTask.counter = 0U;
    filterTask.enable  = true;
    filterTask.ready   = false;

    /*
        Statistics
    */

    statisticsTask.timer   = millis();
    statisticsTask.counter = 0U;
    statisticsTask.enable  = true;
    statisticsTask.ready   = false;

    /*
        Display
    */

    displayTask.timer   = millis();
    displayTask.counter = 0U;
    displayTask.enable  = true;
    displayTask.ready   = false;

    /*
        Protocol
    */

    protocolTask.timer   = millis();
    protocolTask.counter = 0U;
    protocolTask.enable  = true;
    protocolTask.ready   = false;

    return true;
}

/*=============================================================================
    Update Task
=============================================================================*/

void Scheduler::updateTask(
    Task& task,
    uint32_t period)
{
    task.ready = false;

    if (!task.enable)
    {
        return;
    }

    const uint32_t now = millis();

    if ((now - task.timer) >= period)
    {
        task.timer = now;

        task.counter++;

        task.ready = true;
    }
}
/*=============================================================================
    Run
=============================================================================*/

void Scheduler::run()
{
    /*
        Update task timers
    */

    updateTask(buttonsTask,      kButtonsPeriod);

    updateTask(measurementTask,  kMeasurementPeriod);

    updateTask(sensorTask,       kSensorPeriod);

    updateTask(calibrationTask,  kCalibrationPeriod);

    updateTask(filterTask,       kFilterPeriod);

    updateTask(statisticsTask,   kStatisticsPeriod);

    updateTask(displayTask,      kDisplayPeriod);

    updateTask(protocolTask,     kProtocolPeriod);

    /*
        Execute tasks
        (execution order is deterministic)
    */

    if (buttonsTask.ready)
    {
        buttons.update();
    }

    if (measurementTask.ready)
    {
        measurement.update(model);
    }

    if (sensorTask.ready)
    {
        sensor.update(model);
    }

    if (calibrationTask.ready)
    {
        calibration.update(model);
    }

    if (filterTask.ready)
    {
        filter.update(model);
    }

    if (statisticsTask.ready)
    {
        statistics.update(model);
    }

    if (displayTask.ready)
    {
        display.update(model);
    }

    if (protocolTask.ready)
    {
        protocol.update(model);
    }
}