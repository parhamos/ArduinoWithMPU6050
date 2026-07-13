/******************************************************************************
 * Project : AccelMeter
 * Module  : Common
 * File    : CommonTypes.h
 * Version : 1.0.0
 ******************************************************************************/

#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

#include <Arduino.h>

enum class Unit
{
    MS2,
    G
};

enum class SensorState
{
    Offline,
    Online,
    Error
};

enum class CalibrationState
{
    None,
    Running,
    Completed
};

enum class Page
{
    Main,
    Magnitude,
    Status
};

/***************************************************
 * Sensor Data
 **************************************************/

struct SensorData
{
    float ax = 0.0f;

    float ay = 0.0f;

    float az = 0.0f;

    float magnitude = 0.0f;

    float rms = 0.0f;

    float peak = 0.0f;

    float peakToPeak = 0.0f;

    float temperature = 0.0f;

    uint32_t timestamp = 0;

    SensorState state = SensorState::Offline;
};

#endif