/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Statistics
 * File       : Statistics.cpp
 *
 * Version    : 1.0.0
 *
 ******************************************************************************/

#include "Statistics.h"

#include <math.h>

/*=============================================================================
    Global Instance
=============================================================================*/

Statistics statistics;

/*=============================================================================
    Constructor
=============================================================================*/

Statistics::Statistics()
{
    previousSampleTime_ = 0UL;
}

/*=============================================================================
    Initialization
=============================================================================*/

bool Statistics::begin()
{
    previousSampleTime_ = millis();

    return true;
}

/*=============================================================================
    Update
=============================================================================*/

bool Statistics::update(Model& model)
{
    MeasurementFrame& m = model.measurement();

    StatisticsData& s = model.statistics();

    s.sampleRate = calculateSampleRate(
        m.timestamp,
        previousSampleTime_);

    previousSampleTime_ = m.timestamp;

    s.mean = calculateMean(m.filtered);

    s.peak = calculatePeak(m.filtered);

    m.magnitude = calculateMagnitude(m.filtered);

    s.rms = calculateRms(m.filtered);

    return true;
}



/*=============================================================================
    Magnitude
=============================================================================*/

float Statistics::calculateMagnitude(
    const Vector3f& value) const
{
    return sqrt(
        value.x * value.x +
        value.y * value.y +
        value.z * value.z);
}

/*=============================================================================
    Peak
=============================================================================*/

float Statistics::calculatePeak(
    const Vector3f& value) const
{
    float peak = fabs(value.x);

    if (fabs(value.y) > peak)
        peak = fabs(value.y);

    if (fabs(value.z) > peak)
        peak = fabs(value.z);

    return peak;
}

/*=============================================================================
    Mean
=============================================================================*/

float Statistics::calculateMean(
    const Vector3f& value) const
{
    return
        (value.x +
         value.y +
         value.z) / 3.0f;
}

/*=============================================================================
    Sample Rate
=============================================================================*/

float Statistics::calculateSampleRate(
    uint32_t currentTime,
    uint32_t previousTime) const
{
    uint32_t dt = currentTime - previousTime;

    if (dt == 0UL)
        return 0.0f;

    return 1000.0f / dt;
}

/*=============================================================================
    Calculate RMS
=============================================================================*/

float Statistics::calculateRms(
    const Vector3f& value) const
{
    return sqrt(
        (value.x * value.x +
         value.y * value.y +
         value.z * value.z) / 3.0f);
}