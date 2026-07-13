/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Sensor
 * File       : Sensor.h
 *
 * Version    : 0.3.0
 *
 * Description:
 *      MPU6050 sensor driver.
 *
 ******************************************************************************/

#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

#include "Model.h"

class Sensor
{
public:

    Sensor();

    bool begin();

    bool update(Model& model);

    bool isConnected() const;

    float temperature() const;

    uint16_t sampleRate() const;

private:

    bool connected_;

    float temperature_;

    uint16_t sampleRate_;
};

extern Sensor sensor;

#endif // SENSOR_H