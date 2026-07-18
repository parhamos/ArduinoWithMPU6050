/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Measurement
 * File       : MeasurementTypes.h
 *
 * Version    : 1.0.0
 *
 * Description:
 *      Measurement manager public types.
 *
 ******************************************************************************/

#ifndef MEASUREMENT_TYPES_H
#define MEASUREMENT_TYPES_H

#include <Arduino.h>

/*=============================================================================
    Measurement State
=============================================================================*/

enum class MeasurementState : uint8_t
{
    Idle = 0,

    Live,

    Measuring,

    Finished
};

/*=============================================================================
    Measurement Command
=============================================================================*/

enum class MeasurementCommand : uint8_t
{
    None = 0,

    Start,

    Stop,

    Zero,

    FactoryReset
};

#endif