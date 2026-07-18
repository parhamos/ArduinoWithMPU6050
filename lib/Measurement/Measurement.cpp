/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Measurement
 * File       : Measurement.cpp
 *
 * Version    : 1.0.0
 *
 * Description:
 *      Measurement manager implementation.
 *
 ******************************************************************************/

#include "Measurement.h"

#include "Calibration.h"
#include "Statistics.h"

/*=============================================================================
    Global Instance
=============================================================================*/

Measurement measurement;

/*=============================================================================
    Constructor
=============================================================================*/

Measurement::Measurement()
{
}

/*=============================================================================
    Initialization
=============================================================================*/

bool Measurement::begin()
{
    runtime_.state = MeasurementState::Idle;

    runtime_.command = MeasurementCommand::None;

    runtime_.startTime = 0U;

    runtime_.stopTime = 0U;

    return true;
}

/*=============================================================================
    Update
=============================================================================*/

bool Measurement::update(Model& model)
{
    processRequests(model);

    return true;
}

/*=============================================================================
    Request
=============================================================================*/

void Measurement::request(MeasurementCommand command)
{
    runtime_.command = command;
}

/*=============================================================================
    State
=============================================================================*/

MeasurementState Measurement::state() const
{
    return runtime_.state;
}

/*=============================================================================
    Measuring
=============================================================================*/

bool Measurement::isMeasuring() const
{
    return (runtime_.state == MeasurementState::Measuring);
}

/*=============================================================================
    Set State
=============================================================================*/

void Measurement::setState(MeasurementState state)
{
    runtime_.state = state;
}

/*=============================================================================
    Process Requests
=============================================================================*/

void Measurement::processRequests(Model& model)
{
    switch(runtime_.command)
    {
        case MeasurementCommand::Start:

            processStart(model);

            break;

        case MeasurementCommand::Stop:

            processStop(model);

            break;

        case MeasurementCommand::Zero:

            processZero(model);

            break;

        case MeasurementCommand::FactoryReset:

            processFactoryReset(model);

            break;

        default:

            break;
    }

    runtime_.command = MeasurementCommand::None;
}

/*=============================================================================
    Start
=============================================================================*/

void Measurement::processStart(Model& model)
{
    runtime_.startTime = millis();

    calibration.captureOffset(model);

    statistics.reset(model);

    setState(MeasurementState::Measuring);
}

/*=============================================================================
    Stop
=============================================================================*/

void Measurement::processStop(Model& model)
{
    (void)model;

    runtime_.stopTime = millis();

    setState(MeasurementState::Finished);
}

/*=============================================================================
    Zero Statistics
=============================================================================*/

void Measurement::processZero(Model& model)
{
    calibration.captureOffset(model);

    statistics.reset(model);
}

/*=============================================================================
    Factory Reset
=============================================================================*/

void Measurement::processFactoryReset(Model& model)
{
    calibration.factoryReset(model);

    statistics.reset(model);

    setState(MeasurementState::Idle);
}