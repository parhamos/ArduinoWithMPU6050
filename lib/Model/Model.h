/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Model
 * File       : Model.h
 *
 * Version    : 1.0.0
 *
 * Description:
 *      Central runtime data storage for all firmware modules.
 *
 ******************************************************************************/

#ifndef MODEL_H
#define MODEL_H

#include <Arduino.h>

#include "ModelObjects.h"

class Model
{
public:

    Model();

    bool begin();

    void reset();

    /*======================================================================
        Measurement
    ======================================================================*/

    MeasurementFrame& measurement();

    const MeasurementFrame& measurement() const;

  /*======================================================================
        Calibration
    ======================================================================*/

    CalibrationData& calibration();

    const CalibrationData& calibration() const;


    /*======================================================================
        Statistics
    ======================================================================*/

    StatisticsData& statistics();

    const StatisticsData& statistics() const;

  
    /*======================================================================
        Configuration
    ======================================================================*/

    DeviceConfiguration& configuration();

    const DeviceConfiguration& configuration() const;

    /*======================================================================
        Status
    ======================================================================*/

    DeviceStatus& status();

    const DeviceStatus& status() const;

private:

    MeasurementFrame measurement_;

    StatisticsData statistics_;

    CalibrationData calibration_;

    DeviceConfiguration configuration_;

    DeviceStatus status_;
};

extern Model model;

#endif // MODEL_H