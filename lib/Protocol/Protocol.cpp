/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Protocol
 * File       : Protocol.cpp
 *
 * Version    : 2.0.0
 *
 ******************************************************************************/

#include "Protocol.h"

#include "ProtocolConfig.h"
#include "ProtocolPrivate.h"

/*=============================================================================
    Global Instance
=============================================================================*/

Protocol protocol;

/*=============================================================================
    Constructor
=============================================================================*/

Protocol::Protocol()
    :
    headerSent_(false)
{
}

/*=============================================================================
    Initialization
=============================================================================*/

bool Protocol::begin()
{
    Serial.begin(kProtocolBaudRate);

    headerSent_ = false;

    return true;
}

/*=============================================================================
    Update
=============================================================================*/

bool Protocol::update(Model& model)
{
    if (!headerSent_)
    {
        sendHeader();

        headerSent_ = true;
    }

    sendMeasurement(model);

    sendStatistics(model);

    sendStatus(model);

    sendLine();

    return true;
}
/*=============================================================================
    Header
=============================================================================*/

void Protocol::sendHeader()
{
    if (kSendHeader)
    {
        Serial.println(
            F("TIME,"
              "RAW_X,RAW_Y,RAW_Z,"
              "CAL_X,CAL_Y,CAL_Z,"
              "FIL_X,FIL_Y,FIL_Z,"
              "MAG,RMS,PEAK,MEAN,RATE"));
    }
}

/*=============================================================================
    Measurement
=============================================================================*/

void Protocol::sendMeasurement(const Model& model)
{
    const MeasurementFrame& m = model.measurement();

    Serial.print(m.timestamp);

    if (kSendRawData)
    {
        Serial.print(',');

        Serial.print(m.raw.x, kProtocolPrecision);
        Serial.print(',');

        Serial.print(m.raw.y, kProtocolPrecision);
        Serial.print(',');

        Serial.print(m.raw.z, kProtocolPrecision);
    }

    if (kSendCalibrated)
    {
        Serial.print(',');

        Serial.print(m.calibrated.x, kProtocolPrecision);
        Serial.print(',');

        Serial.print(m.calibrated.y, kProtocolPrecision);
        Serial.print(',');

        Serial.print(m.calibrated.z, kProtocolPrecision);
    }

    if (kSendFiltered)
    {
        Serial.print(',');

        Serial.print(m.filtered.x, kProtocolPrecision);
        Serial.print(',');

        Serial.print(m.filtered.y, kProtocolPrecision);
        Serial.print(',');

        Serial.print(m.filtered.z, kProtocolPrecision);
    }

    Serial.print(',');

    Serial.print(m.magnitude, kProtocolPrecision);
}
/*=============================================================================
    Statistics
=============================================================================*/

void Protocol::sendStatistics(const Model& model)
{
    if (!kSendStatistics)
    {
        return;
    }

    const StatisticsData& s = model.statistics();

    Serial.print(',');

    Serial.print(s.rms, kProtocolPrecision);

    Serial.print(',');

    Serial.print(s.peak, kProtocolPrecision);

    Serial.print(',');

    Serial.print(s.mean, kProtocolPrecision);

    Serial.print(',');

    Serial.print(s.sampleRate, kProtocolPrecision);
}

/*=============================================================================
    Status
=============================================================================*/

void Protocol::sendStatus(const Model& model)
{
    if (!kSendStatus)
    {
        return;
    }

    const DeviceStatus& status = model.status();

    Serial.print(',');

    Serial.print(static_cast<uint8_t>(status.firmware));

    Serial.print(',');

    Serial.print(static_cast<uint8_t>(status.sensor));

    Serial.print(',');

    Serial.print(static_cast<uint8_t>(status.calibration));

    Serial.print(',');

    Serial.print(static_cast<uint8_t>(status.serial));
}

/*=============================================================================
    End Of Line
=============================================================================*/

void Protocol::sendLine()
{
    Serial.println();
}