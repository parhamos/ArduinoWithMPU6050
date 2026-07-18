/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Display
 * File       : Display.cpp
 *
 * Version    : 3.0.0
 *
 * Description:
 *      Display manager implementation.
 *
 ******************************************************************************/

#include "Display.h"

#include "Buttons.h"

#include <stdio.h>
#include <string.h>

/*=============================================================================
    Global Instance
=============================================================================*/

Display display;

/*=============================================================================
    Constructor
=============================================================================*/

Display::Display() :

    lcd_(kLcdAddress,
         kLcdColumns,
         kLcdRows)
{
    runtime_.currentPage = DisplayPage::Acceleration;

    runtime_.initialized = false;

    runtime_.refreshCounter = 0U;

    clearCache();
}

/*=============================================================================
    Initialization
=============================================================================*/

bool Display::begin()
{
    int status =
        lcd_.begin(
            kLcdColumns,
            kLcdRows);

    if (status)
    {
        return false;
    }

    lcd_.backlight();

    lcd_.clear();

    runtime_.initialized = true;

    lcd_.setCursor(0,0);
    lcd_.print(" Robonix");

    lcd_.setCursor(0,1);
    lcd_.print("AccelMeter");

    delay(1000);

    lcd_.clear();

    clearCache();

    return true;
}

/*=============================================================================
    Update
=============================================================================*/

bool Display::update(Model& model)
{
    if (!runtime_.initialized)
    {
        return false;
    }

    /*
        Button Events
    */

    ButtonEvent event;

    if (buttons.getEvent(event))
    {
        switch(event.id)
        {
            case ButtonId::Next:

                nextPage();

                break;

            case ButtonId::Previous:

                previousPage();

                break;

            default:

                break;
        }
    }

    /*
        Refresh LCD
    */

    refresh(model);

    runtime_.refreshCounter++;

    return true;
}

/*=============================================================================
    Refresh Dispatcher
=============================================================================*/

void Display::refresh(Model& model)
{
    switch(runtime_.currentPage)
    {
        case DisplayPage::Acceleration:

            pageAcceleration(model);

            break;

        case DisplayPage::Magnitude:

            pageMagnitude(model);

            break;

        case DisplayPage::Statistics:

            pageStatistics(model);

            break;

        case DisplayPage::System:

            pageSystem(model);

            break;

        case DisplayPage::Settings:

            pageSettings(model);

            break;

        default:

            pageAcceleration(model);

            break;
    }
}

/*=============================================================================
    Next Page
=============================================================================*/

void Display::nextPage()
{
    runtime_.currentPage =
        static_cast<DisplayPage>(
            (static_cast<uint8_t>(runtime_.currentPage) + 1U) % 5U);

    lcd_.clear();

    clearCache();
}

/*=============================================================================
    Previous Page
=============================================================================*/

void Display::previousPage()
{
    if(runtime_.currentPage == DisplayPage::Acceleration)
    {
        runtime_.currentPage = DisplayPage::Settings;
    }
    else
    {
        runtime_.currentPage =
            static_cast<DisplayPage>(
                static_cast<uint8_t>(runtime_.currentPage) - 1U);
    }

    lcd_.clear();

    clearCache();
}

/*=============================================================================
    Current Page
=============================================================================*/

DisplayPage Display::currentPage() const
{
    return runtime_.currentPage;
}

/*=============================================================================
    Set Page
=============================================================================*/

void Display::setPage(DisplayPage page)
{
    if(page == runtime_.currentPage)
    {
        return;
    }

    runtime_.currentPage = page;

    lcd_.clear();

    clearCache();
}
/*=============================================================================
    Clear Cache
=============================================================================*/

void Display::clearCache()
{
    for(uint8_t row = 0U;
        row < kLcdRows;
        row++)
    {
        memset(
            cache_.line[row],
            ' ',
            kLcdColumns);

        cache_.line[row][kLcdColumns] = '\0';
    }
}

/*=============================================================================
    Print LCD Line
=============================================================================*/

void Display::printLine(
    uint8_t row,
    const char* text)
{
    if(row >= kLcdRows)
    {
        return;
    }

    char buffer[kLcdColumns + 1];

    snprintf(
        buffer,
        sizeof(buffer),
        "%-*s",
        kLcdColumns,
        text);

    /*
        No Change
    */

    if(strcmp(buffer, cache_.line[row]) == 0)
    {
        return;
    }

    /*
        Update Cache
    */

    strcpy(
        cache_.line[row],
        buffer);

    /*
        Update LCD
    */

    lcd_.setCursor(0, row);

    lcd_.print(buffer);
}

/*=============================================================================
    Print Float Value
=============================================================================*/

void Display::printValue(
    uint8_t row,
    const char* label,
    float value,
    uint8_t precision)
{
    char number[16];

    dtostrf(
        value,
        0,
        precision,
        number);

    char text[kLcdColumns + 1];

    snprintf(
        text,
        sizeof(text),
        "%s:%s",
        label,
        number);

    printLine(
        row,
        text);
}

/*=============================================================================
    Print Status
=============================================================================*/

void Display::printStatus(
    uint8_t row,
    const char* label,
    const char* value)
{
    char text[kLcdColumns + 1];

    snprintf(
        text,
        sizeof(text),
        "%s:%s",
        label,
        value);

    printLine(
        row,
        text);
}
/*=============================================================================
    Page : Acceleration
=============================================================================*/

void Display::pageAcceleration(const Model& model)
{
    const MeasurementFrame& measurement =
        model.measurement();

    printValue(
        0,
        "AX",
        measurement.filtered.x);

    printValue(
        1,
        "AY",
        measurement.filtered.y);

    printValue(
        2,
        "AZ",
        measurement.filtered.z);

    char text[kLcdColumns + 1];

    snprintf(
        text,
        sizeof(text),
        "PAGE %u",
        static_cast<uint8_t>(runtime_.currentPage) + 1U);

    printLine(
        3,
        text);
}

/*=============================================================================
    Page : Magnitude
=============================================================================*/

void Display::pageMagnitude(const Model& model)
{
    const MeasurementFrame& measurement =
        model.measurement();

    const StatisticsData& statistics =
        model.statistics();

    printValue(
        0,
        "MAG",
        measurement.magnitude);

    printValue(
        1,
        "RMS",
        statistics.rms);

    printValue(
        2,
        "PEAK",
        statistics.peak);

    char text[kLcdColumns + 1];

    snprintf(
        text,
        sizeof(text),
        "PAGE %u",
        static_cast<uint8_t>(runtime_.currentPage) + 1U);

    printLine(
        3,
        text);
}
/*=============================================================================
    Page : Statistics
=============================================================================*/

void Display::pageStatistics(const Model& model)
{
    const StatisticsData& statistics =
        model.statistics();

    printValue(
        0,
        "MEAN",
        statistics.mean);

    printValue(
        1,
        "RMS",
        statistics.rms);

    printValue(
        2,
        "RATE",
        statistics.sampleRate,
        0);

    printLine(
        3,
        "STATISTICS");
}

/*=============================================================================
    Page : System
=============================================================================*/

void Display::pageSystem(const Model& model)
{
    const DeviceStatus& status =
        model.status();

    switch(status.sensor)
    {
        case SensorState::Ready:

            printStatus(
                0,
                "SENSOR",
                "READY");

            break;

        case SensorState::Initializing:

            printStatus(
                0,
                "SENSOR",
                "INIT");

            break;

        case SensorState::Offline:

            printStatus(
                0,
                "SENSOR",
                "OFF");

            break;

        default:

            printStatus(
                0,
                "SENSOR",
                "ERROR");

            break;
    }

    switch(status.calibration)
    {
        case CalibrationState::Completed:

            printStatus(
                1,
                "CAL",
                "OK");

            break;

        case CalibrationState::Running:

            printStatus(
                1,
                "CAL",
                "RUN");

            break;

        default:

            printStatus(
                1,
                "CAL",
                "NO");

            break;
    }

    printValue(
        2,
        "FRAME",
        static_cast<float>(
            model.measurement().frameNumber),
        0);

    printLine(
        3,
        "SYSTEM");
}

/*=============================================================================
    Page : Settings
=============================================================================*/

void Display::pageSettings(const Model& model)
{
    const DeviceConfiguration& configuration =
        model.configuration();

    printValue(
        0,
        "RATE",
        configuration.sampleRate,
        0);

    switch(configuration.filterType)
    {
        case FilterType::None:

            printStatus(
                1,
                "FILTER",
                "NONE");

            break;

        case FilterType::IIR:

            printStatus(
                1,
                "FILTER",
                "IIR");

            break;

        case FilterType::MovingAverage:

            printStatus(
                1,
                "FILTER",
                "AVG");

            break;

        case FilterType::Median:

            printStatus(
                1,
                "FILTER",
                "MED");

            break;

        case FilterType::Kalman:

            printStatus(
                1,
                "FILTER",
                "KAL");

            break;
    }

    switch(configuration.unit)
    {
        case AccelerationUnit::MeterPerSecondSquared:

            printStatus(
                2,
                "UNIT",
                "M/S2");

            break;

        case AccelerationUnit::G:

            printStatus(
                2,
                "UNIT",
                "G");

            break;
    }

    printLine(
        3,
        "SETTINGS");
}