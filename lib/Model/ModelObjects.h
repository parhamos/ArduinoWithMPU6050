/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Model
 * File       : ModelObjects.h
 *
 * Version    : 0.2.0
 *
 * Description:
 *      Firmware Data Objects
 *
 ******************************************************************************/

#ifndef MODEL_OBJECTS_H
#define MODEL_OBJECTS_H

#include <Arduino.h>

#include "ModelConfig.h"
#include "ModelTypes.h"

/*=============================================================================
    Raw Acceleration Sample
=============================================================================*/

struct AccelerationSample
{
    Vector3f value;          // m/s²
    Timestamp timestamp;     // ms
};

/*=============================================================================
    Measurement Frame
=============================================================================*/

struct MeasurementFrame
{
    Vector3f raw;

    Vector3f calibrated;

    Vector3f filtered;

    float magnitude;

    Timestamp timestamp;

    uint32_t frameNumber;
};
/*=============================================================================
    Statistics
=============================================================================*/

struct StatisticsData
{
    float rms;

    float peak;

    float mean;

    float sampleRate;
};

/*=============================================================================
    Calibration
=============================================================================*/

struct CalibrationData
{
    CalibrationState state;

    Vector3f offset;
};

/*=============================================================================
    Device Configuration
=============================================================================*/

struct DeviceConfiguration
{
    uint16_t sampleRate;

    AccelerationUnit unit;
};

/*=============================================================================
    Device Status
=============================================================================*/

struct DeviceStatus
{
    FirmwareState firmware;

    SensorState sensor;

    CommunicationState serial;

    CalibrationState calibration;
};
#endif // MODEL_OBJECTS_H