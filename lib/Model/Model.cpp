/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Model
 * File       : Model.cpp
 *
 * Version    : 3.0.0
 *
 * Description:
 *      Central runtime data model implementation.
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
    /*-------------------------------------------------------------------------
        Measurement
    -------------------------------------------------------------------------*/

    measurement_.raw = {0.0f, 0.0f, 0.0f};

    measurement_.calibrated = {0.0f, 0.0f, 0.0f};

    measurement_.filtered = {0.0f, 0.0f, 0.0f};

    measurement_.magnitude = 0.0f;

    measurement_.timestamp = 0U;

    measurement_.frameNumber = 0U;

    /*-------------------------------------------------------------------------
        Calibration
    -------------------------------------------------------------------------*/

    calibration_.state = CalibrationState::NotCalibrated;

    calibration_.factoryOffset = {0.0f, 0.0f, 0.0f};

    calibration_.zeroOffset = {0.0f, 0.0f, 0.0f};

    /*-------------------------------------------------------------------------
        Statistics
    -------------------------------------------------------------------------*/

    statistics_.mean = 0.0f;

    statistics_.rms = 0.0f;

    statistics_.peak = 0.0f;

    statistics_.sampleRate = kDefaultSampleRate;

    /*-------------------------------------------------------------------------
        Display
    -------------------------------------------------------------------------*/

    display_.page = DisplayPage::Acceleration;

    display_.refresh = DisplayRefresh::Full;

    display_.pageChanged = true;

    display_.enabled = true;

    /*-------------------------------------------------------------------------
        Configuration
    -------------------------------------------------------------------------*/

    configuration_.sampleRate = kDefaultSampleRate;

    configuration_.unit = AccelerationUnit::MeterPerSecondSquared;

    configuration_.filterType = FilterType::IIR;

    /*-------------------------------------------------------------------------
        Status
    -------------------------------------------------------------------------*/

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
    Display
=============================================================================*/

DisplayData& Model::display()
{
    return display_;
}

const DisplayData& Model::display() const
{
    return display_;
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