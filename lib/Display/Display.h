/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Display
 * File       : Display.h
 *
 * Version    : 1.0.0
 *
 * Description:
 *      LCD display management module.
 *
 ******************************************************************************/

#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>

#include "Model.h"

class Display
{
public:

    Display();

    bool begin();

    bool update(Model& model);

    void splash();

    void showError(const char* message);

private:

};

extern Display display;

#endif // DISPLAY_H