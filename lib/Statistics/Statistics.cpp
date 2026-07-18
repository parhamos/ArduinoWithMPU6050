/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Statistics
 * File       : Statistics.cpp
 *
 * Version    : 2.0.0
 *
 * Description:
 *      Statistical processing module.
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
 }
 
 /*=============================================================================
     Initialization
 =============================================================================*/
 
 bool Statistics::begin()
 {
     runtime_.sum               = 0.0f;
     runtime_.squareSum         = 0.0f;
     runtime_.peak              = 0.0f;
 
     runtime_.sampleCount       = 0U;
 
     runtime_.previousTimestamp = millis();
     runtime_.sampleRate        = 0.0f;
 
     return true;
 }
 
 /*=============================================================================
     Update
 =============================================================================*/
 
 bool Statistics::update(Model& model)
 {
 #if (1)
     runtime_.sampleCount++;
     if (kEnableMagnitude)
     {
         updateMagnitude(model);
     }
 
     if (kEnableMean)
     {
         updateMean(model);
     }
 
     if (kEnableRms)
     {
         updateRms(model);
     }
 
     if (kEnablePeak)
     {
         updatePeak(model);
     }
 
     if (kEnableSampleRate)
     {
         updateSampleRate(model);
     }
 
 #endif
 
     return true;
 }
 /*=============================================================================
    Magnitude
=============================================================================*/

void Statistics::updateMagnitude(Model& model)
{
    MeasurementFrame& m = model.measurement();

    const Vector3f* source;

    if (kMagnitudeUseFilteredData)
    {
        source = &m.filtered;
    }
    else
    {
        source = &m.calibrated;
    }

    m.magnitude =
        sqrtf(
            source->x * source->x +
            source->y * source->y +
            source->z * source->z);
}

/*=============================================================================
    Mean
=============================================================================*/

void Statistics::updateMean(Model& model)
{
    StatisticsData& statistics = model.statistics();

    runtime_.sum += model.measurement().magnitude;


    if (runtime_.sampleCount == 0U)
    {
        return;
    }

    statistics.mean =
        runtime_.sum /
        static_cast<float>(runtime_.sampleCount);
}

/*=============================================================================
    Peak
=============================================================================*/

void Statistics::updatePeak(Model& model)
{
    StatisticsData& statistics = model.statistics();

    float value = model.measurement().magnitude;

    if (kPeakUseAbsoluteValue)
    {
        value = fabsf(value);
    }

    if (value > runtime_.peak)
    {
        runtime_.peak = value;
    }

    statistics.peak = runtime_.peak;
}
/*=============================================================================
    RMS
=============================================================================*/

void Statistics::updateRms(Model& model)
{
    StatisticsData& statistics = model.statistics();

    /*
        No sample available
    */

    if(runtime_.sampleCount == 0U)
    {
        statistics.rms = 0.0f;

        return;
    }

    /*
        Current Sample
    */

    const float value = model.measurement().magnitude;

    runtime_.squareSum += value * value;

    /*
        RMS
    */

    statistics.rms =
        sqrtf(
            runtime_.squareSum /
            static_cast<float>(runtime_.sampleCount));
}

/*=============================================================================
    Sample Rate
=============================================================================*/

void Statistics::updateSampleRate(Model& model)
{
    StatisticsData& statistics = model.statistics();

    const uint32_t now = millis();

    const uint32_t dt = now - runtime_.previousTimestamp;

    runtime_.previousTimestamp = now;

    if (dt == 0U)
    {
        return;
    }

    runtime_.sampleRate =
        1000.0f /
        static_cast<float>(dt);

    statistics.sampleRate =
        runtime_.sampleRate;
}
/*=============================================================================
    Reset Statistics
=============================================================================*/

void Statistics::reset(Model& model)
{
    /*
        Runtime
    */

    runtime_.sum               = 0.0f;

    runtime_.squareSum         = 0.0f;

    runtime_.peak              = 0.0f;

    runtime_.sampleCount       = 0U;

    runtime_.previousTimestamp = millis();

    runtime_.sampleRate        = 0.0f;

    /*
        Model
    */

    StatisticsData& statistics = model.statistics();

    statistics.mean       = 0.0f;

    statistics.rms        = 0.0f;

    statistics.peak       = 0.0f;

    statistics.sampleRate = 0.0f;

    /*
        Measurement
    */

    MeasurementFrame& measurement = model.measurement();

    measurement.magnitude   = 0.0f;

    measurement.timestamp   = 0U;

    measurement.frameNumber = 0U;
}