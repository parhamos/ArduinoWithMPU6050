/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Display
 * File       : Display.h
 *
 * Version    : 3.0.0
 *
 * Description:
 *      Display manager.
 *
 ******************************************************************************/

#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
#include "DisplayTypes.h"
#include "Model.h"

#include "DisplayConfig.h"
#include "DisplayPrivate.h"

/*=============================================================================
    Display
=============================================================================*/

class Display
{
public:

    Display();

    bool begin();

    bool update(Model& model);

    /*=========================================================================
        Pages
    =========================================================================*/

    void nextPage();

    void previousPage();

    DisplayPage currentPage() const;

    void setPage(DisplayPage page);

private:

    /*=========================================================================
        Refresh
    =========================================================================*/

    void refresh(Model& model);

    /*=========================================================================
        Cache
    =========================================================================*/

    void clearCache();

    void printLine(
        uint8_t row,
        const char* text);

    void printValue(
        uint8_t row,
        const char* label,
        float value,
        uint8_t precision = kFloatPrecision);

    void printStatus(
        uint8_t row,
        const char* label,
        const char* value);

    /*=========================================================================
        Pages
    =========================================================================*/

    void pageAcceleration(const Model& model);

    void pageMagnitude(const Model& model);

    void pageStatistics(const Model& model);

    void pageSystem(const Model& model);

    void pageSettings(const Model& model);

private:

    hd44780_I2Cexp lcd_;

    DisplayRuntime runtime_;

    DisplayCache cache_;


};

/*=============================================================================
    Global Instance
=============================================================================*/

extern Display display;

#endif // DISPLAY_H