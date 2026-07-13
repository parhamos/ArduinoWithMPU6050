/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Statistics
 * File       : StatisticsConfig.h
 *
 * Version    : 0.3.0
 *
 * Description:
 *      Global configuration for Statistics module.
 *
 ******************************************************************************/

#ifndef STATISTICS_CONFIG_H
#define STATISTICS_CONFIG_H

#include <Arduino.h>

/*=============================================================================
    Module Version
=============================================================================*/

constexpr uint8_t kStatisticsVersionMajor = 0;
constexpr uint8_t kStatisticsVersionMinor = 3;
constexpr uint8_t kStatisticsVersionPatch = 0;

/*=============================================================================
    Magnitude
=============================================================================*/

constexpr bool kEnableMagnitude = true;

/*=============================================================================
    RMS
=============================================================================*/

constexpr bool kEnableRMS = true;

/*
    Number of samples used for RMS calculation.
*/
constexpr uint16_t kRmsWindowSize = 100;

/*=============================================================================
    Peak
=============================================================================*/

constexpr bool kEnablePeak = true;

/*=============================================================================
    Mean
=============================================================================*/

constexpr bool kEnableMean = true;

/*=============================================================================
    Sample Rate
=============================================================================*/

constexpr bool kEnableSampleRate = true;

/*
    Update period for sample-rate estimation.
*/
constexpr uint16_t kSampleRatePeriodMs = 1000;

/*=============================================================================
    Future Features
=============================================================================*/

constexpr bool kEnableFFT = false;
constexpr bool kEnableTHD = false;
constexpr bool kEnablePSD = false;
constexpr bool kEnableKurtosis = false;
constexpr bool kEnableSkewness = false;

#endif