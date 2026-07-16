/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Statistics
 * File       : Statistics.h
 *
 * Version    : 1.0.0
 *
 * Description:
 *      Statistical calculations for acceleration measurements.
 *
 ******************************************************************************/

#ifndef STATISTICS_H
#define STATISTICS_H

#include <Arduino.h>

#include "Model.h"

class Statistics
{
public:

    Statistics();

    bool begin();

    bool update(Model& model);

    /*======================================================================
        Statistical Functions
    ======================================================================*/

    float calculateMagnitude(const Vector3f& value) const;

    float calculateRms(const Vector3f& value) const;

    float calculatePeak(const Vector3f& value) const;

    float calculateMean(const Vector3f& value) const;

    float calculateSampleRate(
        uint32_t currentTime,
        uint32_t previousTime) const;

private:

    uint32_t previousSampleTime_;
};

extern Statistics statistics;

#endif // STATISTICS_H
