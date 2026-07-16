/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Application
 * File       : Application.cpp
 *
 * Version    : 1.0.0
 *
 * Description:
 *      Firmware application layer.
 *
 ******************************************************************************/

#include "Application.h"

#include "Model.h"
#include "Sensor.h"
#include "Calibration.h"
#include "Filter.h"
#include "Statistics.h"
#include "Display.h"
#include "Protocol.h"
#include "Scheduler.h"

/*=============================================================================
    Global Instance
=============================================================================*/

Application application;

/*=============================================================================
    Constructor
=============================================================================*/

Application::Application()
{
}

/*=============================================================================
    Initialization
=============================================================================*/
bool Application::begin()
{
    Serial.begin(115200);

    Serial.println("Model");
    if (!model.begin())
        return false;

    Serial.println("Sensor");
    bool ok = sensor.begin();

    Serial.println(ok);
    if (!ok)
    {
        return false;
    }

    //Serial.println("Sensor");
    //if (!sensor.begin())
    //    return false;

    Serial.println("Calibration");
    if (!calibration.begin())
        return false;

    Serial.println("Filter");
    if (!filter.begin())
        return false;

    Serial.println("Statistics");
    if (!statistics.begin())
        return false;

    Serial.println("Display");
    if (!display.begin())
        return false;

    Serial.println("Protocol");
    if (!protocol.begin())
        return false;

    Serial.println("Scheduler");
    if (!scheduler.begin())
        return false;

    model.status().firmware = FirmwareState::Ready;

    Serial.println("Application OK");

    return true;
}
/*=============================================================================
    Run
=============================================================================*/

void Application::run()
{
    scheduler.run();
}