/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Sensor
 * File       : Sensor.cpp
 *
 * Version    : 1.0.0
 *
 ******************************************************************************/

#include "Sensor.h"
#include "SensorConfig.h"

#include <Wire.h>

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

/*=============================================================================
    Private Objects
=============================================================================*/

namespace
{

Adafruit_MPU6050 mpu;

/*=============================================================================
    Accelerometer Range Mapping
=============================================================================*/

mpu6050_accel_range_t convertAccelRange(AccelerometerRange range)
{
    switch (range)
    {
        case AccelerometerRange::Range2G:
            return MPU6050_RANGE_2_G;

        case AccelerometerRange::Range4G:
            return MPU6050_RANGE_4_G;

        case AccelerometerRange::Range8G:
            return MPU6050_RANGE_8_G;

        case AccelerometerRange::Range16G:
            return MPU6050_RANGE_16_G;

        default:
            return MPU6050_RANGE_2_G;
    }
}

/*=============================================================================
    Gyroscope Range Mapping
=============================================================================*/

mpu6050_gyro_range_t convertGyroRange(GyroscopeRange range)
{
    switch (range)
    {
        case GyroscopeRange::Range250DPS:
            return MPU6050_RANGE_250_DEG;

        case GyroscopeRange::Range500DPS:
            return MPU6050_RANGE_500_DEG;

        case GyroscopeRange::Range1000DPS:
            return MPU6050_RANGE_1000_DEG;

        case GyroscopeRange::Range2000DPS:
            return MPU6050_RANGE_2000_DEG;

        default:
            return MPU6050_RANGE_250_DEG;
    }
}

/*=============================================================================
    Filter Bandwidth Mapping
=============================================================================*/

mpu6050_bandwidth_t convertFilterBandwidth(FilterBandwidth bandwidth)
{
    switch (bandwidth)
    {
        case FilterBandwidth::Hz260:
            return MPU6050_BAND_260_HZ;

        case FilterBandwidth::Hz184:
            return MPU6050_BAND_184_HZ;

        case FilterBandwidth::Hz94:
            return MPU6050_BAND_94_HZ;

        case FilterBandwidth::Hz44:
            return MPU6050_BAND_44_HZ;

        case FilterBandwidth::Hz21:
            return MPU6050_BAND_21_HZ;

        case FilterBandwidth::Hz10:
            return MPU6050_BAND_10_HZ;

        case FilterBandwidth::Hz5:
            return MPU6050_BAND_5_HZ;

        default:
            return MPU6050_BAND_44_HZ;
    }
}

} // namespace

/*=============================================================================
    Global Instance
=============================================================================*/

Sensor sensor;

/*=============================================================================
    Constructor
=============================================================================*/

Sensor::Sensor()
    :
    connected_(false),
    temperature_(0.0f),
    sampleRate_(kDefaultSampleRate)
{
}
/*=============================================================================
    Initialization
=============================================================================*/

bool Sensor::begin()
{
    Serial.println("S1");

    connected_ = false;

    Serial.println("S2");

    Wire.begin();

    Serial.println("S3");

    if (!mpu.begin(kMpu6050Address))
    {
        Serial.println("MPU FAIL");
        return false;
    }

    Serial.println("S4");

    mpu.setAccelerometerRange(
        convertAccelRange(kDefaultAccelerometerRange));

    Serial.println("S5");

    mpu.setGyroRange(
        convertGyroRange(kDefaultGyroscopeRange));

    Serial.println("S6");

    if (kEnableInternalFilter)
    {
        mpu.setFilterBandwidth(
            convertFilterBandwidth(kDefaultFilterBandwidth));
    }

    Serial.println("S7");

    temperature_ = 0.0f;
    sampleRate_ = kDefaultSampleRate;
    connected_ = true;

    Serial.println("S8");
    model.status().sensor = SensorState::Ready;
    return true;
}
/*=============================================================================
    Update Sensor Data
=============================================================================*/

bool Sensor::update(Model& model)
{
    if (!connected_)
    {
        return false;
    }

    sensors_event_t accel;
    sensors_event_t gyro;
    sensors_event_t temp;

    mpu.getEvent(&accel, &gyro, &temp);

    MeasurementFrame& measurement = model.measurement();

    /*-----------------------------------------------------------------------
        Raw acceleration (SI units: m/s²)
    -----------------------------------------------------------------------*/

    measurement.raw.x = accel.acceleration.x;
    measurement.raw.y = accel.acceleration.y;
    measurement.raw.z = accel.acceleration.z;

    /*-----------------------------------------------------------------------
        Timestamp
    -----------------------------------------------------------------------*/

    measurement.timestamp = millis();

    /*-----------------------------------------------------------------------
        Frame Counter
    -----------------------------------------------------------------------*/

    measurement.frameNumber++;

    /*-----------------------------------------------------------------------
        Temperature
    -----------------------------------------------------------------------*/

    temperature_ = temp.temperature;

    return true;
}

/*=============================================================================
    Connection Status
=============================================================================*/

bool Sensor::isConnected() const
{
    return connected_;
}

/*=============================================================================
    Temperature
=============================================================================*/

float Sensor::temperature() const
{
    return temperature_;
}