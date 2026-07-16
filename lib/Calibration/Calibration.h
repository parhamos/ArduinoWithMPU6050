/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Calibration
 * File       : Calibration.h
 *
 * Version    : 1.0.0
 *
 * Description:
 *      Zero-offset calibration module.
 *
 ******************************************************************************/

#ifndef CALIBRATION_H
#define CALIBRATION_H

#include <Arduino.h>

#include "Model.h"

class Calibration
{
public:

    Calibration();

    bool begin();

    bool start();

    bool update(Model& model);

    bool isRunning() const;

    bool isFinished() const;

private:

    bool running_;

    bool finished_;

    uint16_t sampleCount_;

    Vector3f accumulator_;
};

extern Calibration calibration;

#endif // CALIBRATION_H