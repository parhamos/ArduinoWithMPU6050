/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Model
 * File       : Model.cpp
 *
 * Version    : 0.2.1
 *
 * Description:
 *      Implementation of the central firmware data model.
 *
 ******************************************************************************/

#include "Model.h"
#include "ModelConfig.h"

/*=============================================================================
    Global Instance
=============================================================================*/

Model model;

/*=============================================================================
    Constructor
=============================================================================*/

Model::Model()
{
    reset();
}

/*=============================================================================
    Initialization
=============================================================================*/

bool Model::begin()
{
    reset();

    status_.firmware = FirmwareState::Ready;

    return true;
}

/*=============================================================================
    Reset
=============================================================================*/

void Model::reset()
{
    /*-----------------------------------------------------------------------
        Measurement
    -----------------------------------------------------------------------*/

    measurement_.raw.x = 0.0f;
    measurement_.raw.y = 0.0f;
    measurement_.raw.z = 0.0f;

    measurement_.calibrated.x = 0.0f;
    measurement_.calibrated.y = 0.0f;
    measurement_.calibrated.z = 0.0f;

    measurement_.filtered.x = 0.0f;
    measurement_.filtered.y = 0.0f;
    measurement_.filtered.z = 0.0f;

    measurement_.magnitude = 0.0f;

    measurement_.timestamp = 0UL;

    measurement_.frameNumber = 0UL;

    /*-----------------------------------------------------------------------
        Statistics
    -----------------------------------------------------------------------*/

    statistics_.rms = 0.0f;

    statistics_.peak = 0.0f;

    statistics_.mean = 0.0f;

    statistics_.sampleRate = kDefaultSampleRate;

    /*-----------------------------------------------------------------------
        Calibration
    -----------------------------------------------------------------------*/

    calibration_.state = CalibrationState::NotCalibrated;

    calibration_.offset.x = 0.0f;
    calibration_.offset.y = 0.0f;
    calibration_.offset.z = 0.0f;

    /*-----------------------------------------------------------------------
        Configuration
    -----------------------------------------------------------------------*/

    configuration_.sampleRate = kDefaultSampleRate;

    configuration_.unit = AccelerationUnit::MeterPerSecondSquared;

    /*-----------------------------------------------------------------------
        Device Status
    -----------------------------------------------------------------------*/

    status_.firmware = FirmwareState::Boot;

    status_.sensor = SensorState::Offline;

    status_.serial = CommunicationState::Disconnected;

    status_.calibration = CalibrationState::NotCalibrated;
}

/*=============================================================================
    Measurement
=============================================================================*/

MeasurementFrame& Model::measurement()
{
    return measurement_;
}

const MeasurementFrame& Model::measurement() const
{
    return measurement_;
}

/*=============================================================================
    Statistics
=============================================================================*/

StatisticsData& Model::statistics()
{
    return statistics_;
}

const StatisticsData& Model::statistics() const
{
    return statistics_;
}

/*=============================================================================
    Calibration
=============================================================================*/

CalibrationData& Model::calibration()
{
    return calibration_;
}

const CalibrationData& Model::calibration() const
{
    return calibration_;
}

/*=============================================================================
    Configuration
=============================================================================*/

DeviceConfiguration& Model::configuration()
{
    return configuration_;
}

const DeviceConfiguration& Model::configuration() const
{
    return configuration_;
}

/*=============================================================================
    Status
=============================================================================*/

DeviceStatus& Model::status()
{
    return status_;
}

const DeviceStatus& Model::status() const
{
    return status_;
}