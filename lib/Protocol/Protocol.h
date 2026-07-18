/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Protocol
 * File       : Protocol.h
 *
 * Version    : 2.0.0
 *
 * Description:
 *      Firmware communication protocol.
 *
 ******************************************************************************/

#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <Arduino.h>

#include "Model.h"

class Protocol
{
public:

    /*=========================================================================
        Construction
    =========================================================================*/

    Protocol();

    /*=========================================================================
        Initialization
    =========================================================================*/

    bool begin();

    /*=========================================================================
        Update
    =========================================================================*/

    bool update(Model& model);

private:

    /*=========================================================================
        Internal Transmission
    =========================================================================*/

    void sendHeader();

    void sendMeasurement(const Model& model);

    void sendStatistics(const Model& model);

    void sendStatus(const Model& model);

    void sendLine();

    bool headerSent_;
};

extern Protocol protocol;

#endif // PROTOCOL_H