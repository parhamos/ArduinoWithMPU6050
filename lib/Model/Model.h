/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Model
 * File       : Model.h
 *
 * Version    : 3.0.0
 *
 * Description:
 *      Central Runtime Data Model.
 *      Single source of truth for all firmware modules.
 *
 ******************************************************************************/

#ifndef MODEL_H
#define MODEL_H

#include <Arduino.h>

#include "ModelObjects.h"

/*=============================================================================
    Model
=============================================================================*/

class Model
{
public:

    Model();

    bool begin();

    void reset();

    /*=========================================================================
        Measurement
    =========================================================================*/

    MeasurementFrame& measurement();

    const MeasurementFrame& measurement() const;

    /*=========================================================================
        Calibration
    =========================================================================*/

    CalibrationData& calibration();

    const CalibrationData& calibration() const;

    /*=========================================================================
        Statistics
    =========================================================================*/

    StatisticsData& statistics();

    const StatisticsData& statistics() const;

    /*=========================================================================
        Display
    =========================================================================*/

    DisplayData& display();

    const DisplayData& display() const;

    /*=========================================================================
        Configuration
    =========================================================================*/

    DeviceConfiguration& configuration();

    const DeviceConfiguration& configuration() const;

    /*=========================================================================
        Status
    =========================================================================*/

    DeviceStatus& status();

    const DeviceStatus& status() const;

private:

    /*
        Runtime Objects
    */

    MeasurementFrame measurement_;

    CalibrationData calibration_;

    StatisticsData statistics_;

    DisplayData display_;

    DeviceConfiguration configuration_;

    DeviceStatus status_;
};

/*=============================================================================
    Global Instance
=============================================================================*/

extern Model model;

#endif // MODEL_H