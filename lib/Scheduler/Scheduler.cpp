/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Scheduler
 * File       : Scheduler.cpp
 *
 * Version    : 2.0.0
 *
 * Description:
 *      Cooperative firmware scheduler.
 *
 ******************************************************************************/

#include "Scheduler.h"

#include "SchedulerConfig.h"
#include "SchedulerPrivate.h"
#include "Buttons.h"
#include "Model.h"
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

Task sensorTask;
Task calibrationTask;
Task filterTask;
Task statisticsTask;
Task displayTask;
Task protocolTask;
Task buttonsTask;
/*=============================================================================
    Constructor
=============================================================================*/

Scheduler::Scheduler()
    :
    previousTick_(0U)
{
}

/*=============================================================================
    Initialization
=============================================================================*/

bool Scheduler::begin()
{
    previousTick_ = millis();

    sensorTask =
    {
        kSensorPeriod,
        0U,
        0U,
        true
    };

    calibrationTask =
    {
        kCalibrationPeriod,
        0U,
        0U,
        true
    };

    filterTask =
    {
        kFilterPeriod,
        0U,
        0U,
        true
    };

    statisticsTask =
    {
        kStatisticsPeriod,
        0U,
        0U,
        true
    };

    displayTask =
    {
        kDisplayPeriod,
        0U,
        0U,
        true
    };

    protocolTask =
    {
        kProtocolPeriod,
        0U,
        0U,
        true
    };

    buttonsTask   =
    {
        kButtonsPeriod,
        0U,
        0U,
        true
    };

    return true;
}

/*=============================================================================
    Task Scheduler
=============================================================================*/

bool Scheduler::run(Task& task)
{
    if (!task.enable)
    {
        return false;
    }

    const uint32_t now = millis();

    if ((now - task.timer) < task.period)
    {
        return false;
    }

    task.timer = now;

    task.counter++;

    return true;
}
/*=============================================================================
    Main Scheduler
=============================================================================*/

void Scheduler::run()
{
    /*
        Sensor
    */

    if (run(sensorTask))
    {
        sensor.update(model);
    }

    /*
        Calibration
    */

    if (run(calibrationTask))
    {
        calibration.update(model);
    }

    /*
        Filter
    */

    if (run(filterTask))
    {
        filter.update(model);
    }

    /*
        Statistics
    */

    if (run(statisticsTask))
    {
        statistics.update(model);
    }

    /*
        Buttons
    */


    /*
        Display
    */

    if (run(displayTask))
    {
        display.update(model);
    }

    /*
    Buttons
*/

    if (run(buttonsTask))
    {
        buttons.update();
    }

    /*
        Communication
    */

    if (run(protocolTask))
    {
        protocol.update(model);
    }
}