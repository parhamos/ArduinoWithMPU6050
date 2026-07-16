/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * File       : main.cpp
 *
 * Version    : 1.0.0
 *
 * Description:
 *      Application entry point.
 *
 ******************************************************************************/

#include <Arduino.h>
#include "Application.h"
#include "Model.h"
#include "Sensor.h"
#include "Calibration.h"
#include "Filter.h"
#include "Statistics.h"
#include "Display.h"
#include "Protocol.h"

/*=============================================================================
    Arduino Setup
=============================================================================*/

void setup()
{
    application.begin();
}


/*=============================================================================
    Arduino Loop
=============================================================================*/

void loop()
{
    application.run();
}