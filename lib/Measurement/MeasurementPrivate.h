/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Measurement
 * File       : MeasurementPrivate.h
 *
 * Version    : 1.0.0
 *
 ******************************************************************************/

#ifndef MEASUREMENT_PRIVATE_H
#define MEASUREMENT_PRIVATE_H

#include "MeasurementTypes.h"

struct MeasurementRuntime
{
    MeasurementState state;

    MeasurementCommand command;

    uint32_t startTime;

    uint32_t stopTime;
};

#endif