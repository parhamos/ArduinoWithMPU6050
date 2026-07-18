/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Measurement
 * File       : Measurement.h
 *
 * Version    : 1.0.0
 *
 * Description:
 *      Measurement manager.
 *
 ******************************************************************************/

#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <Arduino.h>

#include "Model.h"
#include "MeasurementPrivate.h"

class Measurement
{
public:

    Measurement();

    bool begin();

    bool update(Model& model);

    void request(MeasurementCommand command);

    MeasurementState state() const;

    bool isMeasuring() const;

private:

    void processRequests(Model& model);

    void processStart(Model& model);

    void processStop(Model& model);

    void processZero(Model& model);

    void processFactoryReset(Model& model);

    void setState(MeasurementState state);

private:

    MeasurementRuntime runtime_;
};

extern Measurement measurement;

#endif