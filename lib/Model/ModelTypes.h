/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Model
 * File       : ModelTypes.h
 *
 * Version    : 1.0.0
 *
 * Description:
 *      Common firmware data types.
 *
 ******************************************************************************/

#ifndef MODEL_TYPES_H
#define MODEL_TYPES_H

#include <Arduino.h>

/*=============================================================================
    Basic Types
=============================================================================*/

struct Vector3f
{
    float x;
    float y;
    float z;
};

using Timestamp = uint32_t;

/*=============================================================================
    Units
=============================================================================*/

enum class AccelerationUnit : uint8_t
{
    MeterPerSecondSquared = 0,
    G
};

/*=============================================================================
    Firmware State
=============================================================================*/

enum class FirmwareState : uint8_t
{
    Boot = 0,
    Initializing,
    Ready,
    Warning,
    Error
};

/*=============================================================================
    Sensor State
=============================================================================*/

enum class SensorState : uint8_t
{
    Offline = 0,
    Initializing,
    Ready,
    Error
};

/*=============================================================================
    Calibration State
=============================================================================*/

enum class CalibrationState : uint8_t
{
    NotCalibrated = 0,
    Running,
    Completed
};

// /*=============================================================================
//     Measurement State
// =============================================================================*/

// enum class MeasurementState : uint8_t
// {
//     Idle = 0,

//     Running,

//     Finished
// };

/*=============================================================================
    Communication State
=============================================================================*/

enum class CommunicationState : uint8_t
{
    Disconnected = 0,
    Connected
};

/*=============================================================================
    Display Pages
=============================================================================*/

enum class DisplayPage : uint8_t
{
    Acceleration = 0,
    Magnitude,
    System
};

/*=============================================================================
    Filter Type
=============================================================================*/

enum class FilterType : uint8_t
{
    None = 0,

    IIR,

    MovingAverage,

    Median,

    Kalman
};

#endif // MODEL_TYPES_H