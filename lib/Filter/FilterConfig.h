/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Filter
 * File       : FilterConfig.h
 *
 * Version    : 2.0.0
 *
 * Description:
 *      Configuration parameters for the Filter module.
 *
 ******************************************************************************/

#ifndef FILTER_CONFIG_H
#define FILTER_CONFIG_H

#include <Arduino.h>
#include "ModelTypes.h"
/*=============================================================================
    Module Version
=============================================================================*/

constexpr uint8_t kFilterVersionMajor = 2U;
constexpr uint8_t kFilterVersionMinor = 0U;
constexpr uint8_t kFilterVersionPatch = 0U;



/*=============================================================================
    Default Configuration
=============================================================================*/

constexpr FilterType kDefaultFilterType =
    FilterType::IIR;

/*=============================================================================
    IIR Low Pass
=============================================================================*/

constexpr float kIirAlpha = 0.15f;

/*=============================================================================
    Moving Average
=============================================================================*/

constexpr uint8_t kMovingAverageWindow = 8U;

/*=============================================================================
    Median Filter
=============================================================================*/

constexpr uint8_t kMedianWindow = 5U;

/*=============================================================================
    Kalman Filter
=============================================================================*/

constexpr float kKalmanProcessNoise = 0.001f;

constexpr float kKalmanMeasurementNoise = 0.10f;

constexpr float kKalmanInitialError = 1.0f;

#endif // FILTER_CONFIG_H