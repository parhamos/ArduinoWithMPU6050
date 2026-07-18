/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Sensor
 * File       : SensorConfig.h
 *
 * Version    : 1.0.0
 * Description:
    Configuration constants for the Sensor module.

 ******************************************************************************/

#ifndef SENSOR_CONFIG_H
#define SENSOR_CONFIG_H

#include <Arduino.h>

/*=============================================================================
    Module Version
=============================================================================*/

constexpr uint8_t kSensorVersionMajor = 1U;
constexpr uint8_t kSensorVersionMinor = 0U;
constexpr uint8_t kSensorVersionPatch = 0U;

/*=============================================================================
    MPU6050 I2C Address
=============================================================================*/

constexpr uint8_t kMpu6050Address = 0x68;

/*=============================================================================
    Accelerometer Range
=============================================================================*/

enum class AccelerometerRange : uint8_t
{
    Range2G = 0,
    Range4G,
    Range8G,
    Range16G
};

constexpr AccelerometerRange kDefaultAccelerometerRange =
    AccelerometerRange::Range2G;


/*=============================================================================
    Gyroscope Range
=============================================================================*/

enum class GyroscopeRange : uint8_t
{
    Range250DPS = 0,
    Range500DPS,
    Range1000DPS,
    Range2000DPS
};

constexpr GyroscopeRange kDefaultGyroscopeRange =
    GyroscopeRange::Range250DPS;


/*=============================================================================
    Digital Low Pass Filter
=============================================================================*/

enum class FilterBandwidth : uint8_t
{
    Hz260 = 0,
    Hz184,
    Hz94,
    Hz44,
    Hz21,
    Hz10,
    Hz5
};

constexpr FilterBandwidth kDefaultFilterBandwidth =
    FilterBandwidth::Hz44;


/*=============================================================================
    Features
=============================================================================*/

constexpr bool kEnableInternalFilter = true;


#endif // SENSOR_CONFIG_H