/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * File       : main.cpp
 *
 ******************************************************************************/

#include <Arduino.h>

#include "Model.h"
#include "Sensor.h"
#include "Display.h"

/*=============================================================================
    Arduino Setup
=============================================================================*/

void setup()
{
    Serial.begin(115200);

    model.begin();

    sensor.begin();

    display.begin();

    display.splash();
}

/*=============================================================================
    Arduino Loop
=============================================================================*/

void loop()
{
    sensor.update(model);

    const MeasurementFrame& measurement =
        model.measurement();

    Serial.print(F("AX="));
    Serial.print(measurement.raw.x, 3);

    Serial.print(F(" AY="));
    Serial.print(measurement.raw.y, 3);

    Serial.print(F(" AZ="));
    Serial.println(measurement.raw.z, 3);

    display.update();

    delay(100);
}