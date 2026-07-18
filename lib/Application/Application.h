/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Application
 * File       : Application.h
 *
 * Version    : 1.0.0
 *
 * Description:
 *      Firmware application layer.
 *
 ******************************************************************************/

#ifndef APPLICATION_H
#define APPLICATION_H

#include <Arduino.h>

class Application
{
public:

    Application();

    bool begin();

    void run();

private:

};

extern Application application;

#endif // APPLICATION_H