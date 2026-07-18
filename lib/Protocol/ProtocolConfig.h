/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Protocol
 * File       : ProtocolConfig.h
 *
 * Version    : 2.0.0
 *
 * Description:
 *      Protocol configuration.
 *
 ******************************************************************************/

#ifndef PROTOCOL_CONFIG_H
#define PROTOCOL_CONFIG_H

#include <Arduino.h>

/*=============================================================================
    Serial Communication
=============================================================================*/

constexpr uint32_t kProtocolBaudRate = 115200UL;

/*=============================================================================
    Output Format
=============================================================================*/

constexpr uint8_t kProtocolPrecision = 3U;

/*=============================================================================
    Output Control
=============================================================================*/

constexpr bool kSendHeader      = true;

constexpr bool kSendRawData     = true;

constexpr bool kSendCalibrated  = true;

constexpr bool kSendFiltered    = true;

constexpr bool kSendStatistics  = true;

constexpr bool kSendStatus      = true;

/*=============================================================================
    Telemetry Period
=============================================================================*/

constexpr uint16_t kProtocolPeriod = 50U;      // ms (20 Hz)

#endif // PROTOCOL_CONFIG_H