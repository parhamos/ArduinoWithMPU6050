/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Calibration
 * File       : Calibration.cpp
 *
 * Version    : 1.0.0
 *
 * Description:
 *      Zero-offset calibration implementation.
 *
 ******************************************************************************/

#include "Calibration.h"
#include "CalibrationConfig.h"

/*=============================================================================
    Global Instance
=============================================================================*/

Calibration calibration;

/*=============================================================================
    Constructor
=============================================================================*/

Calibration::Calibration()
    :
    running_(false),
    finished_(false),
    sampleCount_(0U)
{
    accumulator_.x = 0.0f;
    accumulator_.y = 0.0f;
    accumulator_.z = 0.0f;
}

/*=============================================================================
    Initialization
=============================================================================*/

bool Calibration::begin()
{
    running_ = false;
    finished_ = false;
    sampleCount_ = 0U;

    accumulator_.x = 0.0f;
    accumulator_.y = 0.0f;
    accumulator_.z = 0.0f;

    return true;
}

/*=============================================================================
    Start Calibration
=============================================================================*/

bool Calibration::start()
{
    running_ = true;
    finished_ = false;
    sampleCount_ = 0U;

    accumulator_.x = 0.0f;
    accumulator_.y = 0.0f;
    accumulator_.z = 0.0f;

    return true;
}

/*=============================================================================
    Update
=============================================================================*/

bool Calibration::update(Model& model)
{
    if (!running_)
    {
        return false;
    }

    const Vector3f& raw = model.measurement().raw;

    accumulator_.x += raw.x;
    accumulator_.y += raw.y;
    accumulator_.z += raw.z;

    sampleCount_++;

    if (sampleCount_ < kCalibrationSampleCount)
    {
        return false;
    }

    CalibrationData& calibrationData = model.calibration();

    calibrationData.offset.x =
        accumulator_.x / kCalibrationSampleCount;

    calibrationData.offset.y =
        accumulator_.y / kCalibrationSampleCount;

    calibrationData.offset.z =
        accumulator_.z / kCalibrationSampleCount;

    calibrationData.state = CalibrationState::Completed;

    model.status().calibration = CalibrationState::Completed;

    running_ = false;
    finished_ = true;

    return true;
}

/*=============================================================================
    Status
=============================================================================*/

bool Calibration::isRunning() const
{
    return running_;
}

/*=============================================================================
    Status
=============================================================================*/

bool Calibration::isFinished() const
{
    return finished_;
}