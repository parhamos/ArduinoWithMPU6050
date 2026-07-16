/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Filter
 * File       : Filter.h
 *
 * Version    : 2.0.0
 *
 * Description:
 *      Signal processing and filtering framework.
 *
 ******************************************************************************/

#ifndef FILTER_H
#define FILTER_H

#include <Arduino.h>

#include "Model.h"
#include "FilterConfig.h"

class Filter
{
public:

    Filter();

    bool begin();

    bool update(Model& model);

private:

    /*=========================================================================
        Filter Dispatcher
    =========================================================================*/

    void selectFilter(Model& model);

    /*=========================================================================
        Filter Algorithms
    =========================================================================*/

    void processNone(Model& model);

    void processIIR(Model& model);

    void processMovingAverage(Model& model);

    void processMedian(Model& model);
    void processKalman(Model& model);
    float median3(float a, float b, float c) const;
    float updateKalman(float measurement,
                    float& estimate,
                    float& error,
                    float& gain);

    /*=========================================================================
        IIR Runtime Data
    =========================================================================*/

    Vector3f previousOutput_;

    /*=========================================================================
        Moving Average Runtime Data
    =========================================================================*/

    float bufferX_[kMovingAverageWindow];

    float bufferY_[kMovingAverageWindow];

    float bufferZ_[kMovingAverageWindow];

    uint8_t bufferIndex_;

    bool bufferFilled_;

    /*=========================================================================
        Kalman Runtime Data
    =========================================================================*/

    Vector3f kalmanEstimate_;

    Vector3f kalmanGain_;

    Vector3f estimationError_;
};

extern Filter filter;

#endif // FILTER_H