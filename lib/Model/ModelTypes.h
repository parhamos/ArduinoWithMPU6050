/******************************************************************************
 * Project : AccelMeter
 * Module  : Model
 * File    : ModelTypes.h
 * Version : 1.0.0
 ******************************************************************************/

#ifndef MODEL_TYPES_H
#define MODEL_TYPES_H

#include <Arduino.h>

/*=============================================================================
    Enumerations
=============================================================================*/

enum class Unit : uint8_t
{
    MS2 = 0,
    G
};

enum class SensorState : uint8_t
{
    Offline = 0,
    Online,
    Error
};

enum class CalibrationState : uint8_t
{
    None = 0,
    Running,
    Completed
};

enum class FilterType : uint8_t
{
    None = 0,
    LowPass,
    Kalman
};

enum class LCDPage : uint8_t
{
    Main = 0,
    Statistics,
    System
};

/*=============================================================================
    Basic Types
=============================================================================*/

struct Vector3f
{
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};

struct TemperatureData
{
    float value = 0.0f;
};

struct TimeData
{
    uint32_t millis = 0;
};

/*=============================================================================
    Measurement
=============================================================================*/

struct MeasurementData
{
    Vector3f raw;

    Vector3f calibrated;

    Vector3f filtered;
};

/*=============================================================================
    Statistics
=============================================================================*/

struct StatisticsData
{
    float magnitude = 0.0f;

    float rms = 0.0f;

    float peak = 0.0f;

    float peakToPeak = 0.0f;

    float mean = 0.0f;

    float variance = 0.0f;
};

/*=============================================================================
    Communication
=============================================================================*/

struct CommunicationData
{
    uint32_t frames = 0;

    uint32_t lostFrames = 0;

    bool serialConnected = false;

    uint32_t baudRate = 115200UL;
};

/*=============================================================================
    Device Settings
=============================================================================*/

struct DeviceSettings
{
    Unit unit = Unit::MS2;

    FilterType filter = FilterType::LowPass;

    LCDPage lcdPage = LCDPage::Main;

    uint16_t sampleRate = 100;
};

/*=============================================================================
    System Status
=============================================================================*/

struct SystemStatus
{
    SensorState sensor = SensorState::Offline;

    CalibrationState calibration = CalibrationState::None;

    uint32_t uptime = 0;
};

/*=============================================================================
    Root Object
=============================================================================*/

struct SystemData
{
    MeasurementData measurement;

    TemperatureData temperature;

    StatisticsData statistics;

    CommunicationData communication;

    DeviceSettings settings;

    SystemStatus status;

    TimeData time;
};

#endif