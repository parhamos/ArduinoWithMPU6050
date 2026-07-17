/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Filter
 * File       : Filter.cpp
 *
 * Version    : 2.0.0
 *
 * Description:
 *      Signal processing and filtering framework.
 *
 ******************************************************************************/

#include "Filter.h"

#include <string.h>

/*=============================================================================
    Global Instance
=============================================================================*/

Filter filter;

/*=============================================================================
    Constructor
=============================================================================*/

Filter::Filter()
    :
    bufferIndex_(0U),
    bufferFilled_(false)
{
}

/*=============================================================================
    Initialization
=============================================================================*/

bool Filter::begin()
{
    previousOutput_ = {0.0f, 0.0f, 0.0f};

    memset(bufferX_, 0, sizeof(bufferX_));
    memset(bufferY_, 0, sizeof(bufferY_));
    memset(bufferZ_, 0, sizeof(bufferZ_));

    bufferIndex_ = 0U;

    bufferFilled_ = false;

    kalmanEstimate_ = {0.0f, 0.0f, 0.0f};

    kalmanGain_ = {0.0f, 0.0f, 0.0f};

    estimationError_.x = kKalmanInitialError;
    estimationError_.y = kKalmanInitialError;
    estimationError_.z = kKalmanInitialError;

    return true;
}

/*=============================================================================
    Update
=============================================================================*/

bool Filter::update(Model& model)
{
    selectFilter(model);

    return true;
}

/*=============================================================================
    Filter Dispatcher
=============================================================================*/

void Filter::selectFilter(Model& model)
{
    switch (model.configuration().filterType)
    {
        case FilterType::None:

            processNone(model);

            break;

        case FilterType::IIR:

            processIIR(model);

            break;

        case FilterType::MovingAverage:

            processMovingAverage(model);

            break;

        case FilterType::Median:

            processMedian(model);

            break;

        case FilterType::Kalman:

            processKalman(model);

            break;

        default:

            processIIR(model);

            break;
    }
}
/*=============================================================================
    No Filter
=============================================================================*/

void Filter::processNone(Model& model)
{
    MeasurementFrame& m = model.measurement();

    m.filtered = m.calibrated;
}

/*=============================================================================
    IIR Filter
=============================================================================*/

void Filter::processIIR(Model& model)
{
    MeasurementFrame& m = model.measurement();

    previousOutput_.x =
        kIirAlpha * m.calibrated.x +
        (1.0f - kIirAlpha) * previousOutput_.x;

    previousOutput_.y =
        kIirAlpha * m.calibrated.y +
        (1.0f - kIirAlpha) * previousOutput_.y;

    previousOutput_.z =
        kIirAlpha * m.calibrated.z +
        (1.0f - kIirAlpha) * previousOutput_.z;

    /*-------------------------------------------------------------
        Store filtered values
    -------------------------------------------------------------*/

    m.filtered = previousOutput_;

    /*-------------------------------------------------------------
        Magnitude
    -------------------------------------------------------------*/

    m.magnitude =
        sqrtf(
            m.filtered.x * m.filtered.x +
            m.filtered.y * m.filtered.y +
            m.filtered.z * m.filtered.z);
}
/*=============================================================================
    Moving Average Filter
=============================================================================*/

void Filter::processMovingAverage(Model& model)
{
    MeasurementFrame& m = model.measurement();

    bufferX_[bufferIndex_] = m.calibrated.x;
    bufferY_[bufferIndex_] = m.calibrated.y;
    bufferZ_[bufferIndex_] = m.calibrated.z;

    bufferIndex_++;

    if (bufferIndex_ >= kMovingAverageWindow)
    {
        bufferIndex_ = 0U;
        bufferFilled_ = true;
    }

    uint8_t count =
        bufferFilled_
        ? kMovingAverageWindow
        : bufferIndex_;

    if (count == 0U)
    {
        m.filtered = m.calibrated;
        return;
    }

    float sumX = 0.0f;
    float sumY = 0.0f;
    float sumZ = 0.0f;

    for (uint8_t i = 0; i < count; i++)
    {
        sumX += bufferX_[i];
        sumY += bufferY_[i];
        sumZ += bufferZ_[i];
    }

    m.filtered.x = sumX / count;
    m.filtered.y = sumY / count;
    m.filtered.z = sumZ / count;
}
/*=============================================================================
    Median Filter
=============================================================================*/

void Filter::processMedian(Model& model)
{
    MeasurementFrame& m = model.measurement();

    m.filtered.x = median3(
        m.raw.x,
        m.calibrated.x,
        previousOutput_.x);

    m.filtered.y = median3(
        m.raw.y,
        m.calibrated.y,
        previousOutput_.y);

    m.filtered.z = median3(
        m.raw.z,
        m.calibrated.z,
        previousOutput_.z);

    previousOutput_ = m.filtered;
}

/*=============================================================================
    Kalman Filter
=============================================================================*/

void Filter::processKalman(Model& model)
{
    MeasurementFrame& m = model.measurement();

    m.filtered.x = updateKalman(
        m.calibrated.x,
        kalmanEstimate_.x,
        estimationError_.x,
        kalmanGain_.x);

    m.filtered.y = updateKalman(
        m.calibrated.y,
        kalmanEstimate_.y,
        estimationError_.y,
        kalmanGain_.y);

    m.filtered.z = updateKalman(
        m.calibrated.z,
        kalmanEstimate_.z,
        estimationError_.z,
        kalmanGain_.z);
}

/*=============================================================================
    Median of Three
=============================================================================*/

float Filter::median3(
    float a,
    float b,
    float c) const
{
    if (a > b)
    {
        float t = a;
        a = b;
        b = t;
    }

    if (b > c)
    {
        float t = b;
        b = c;
        c = t;
    }

    if (a > b)
    {
        float t = a;
        a = b;
        b = t;
    }

    return b;
}

/*=============================================================================
    Kalman Update
=============================================================================*/

float Filter::updateKalman(
    float measurement,
    float& estimate,
    float& error,
    float& gain)
{
    error += kKalmanProcessNoise;

    gain =
        error /
        (error + kKalmanMeasurementNoise);

    estimate =
        estimate +
        gain *
        (measurement - estimate);

    error =
        (1.0f - gain) *
        error;

    return estimate;
}