/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Display
 * File       : Display.cpp
 *
 * Version    : 1.0.0
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
        lcd_.begin(kLcdColumns,
                   kLcdRows);

    if(status)
    {
        return false;
    }

    lcd_.backlight();

    lcd_.clear();

    runtime_.initialized = true;

    lcd_.setCursor(0,0);
    lcd_.print(" Safe Co ");

    lcd_.setCursor(0,1);
    lcd_.print("AccelMeter");

    delay(1000);

    lcd_.clear();

    clearCache();

    return true;
}
// while(1)
// {
//     lcd_.setCursor(0,0);
//     lcd_.print("AAAA");

//     delay(1000);

//     lcd_.clear();

//     lcd_.setCursor(0,0);
//     lcd_.print("BBBB");

//     delay(1000);
// }
//     Serial.println("D9");
    
//     return true;
//  }
 
 /*=============================================================================
     Update
 =============================================================================*/
 
 bool Display::update(Model& model)
 {
     if (!runtime_.initialized)
     {
         return false;
     }
 
     Serial.println("Display Update");
 
     refresh(model);
 
     if (buttons.nextPressed())
     {
         nextPage();
     }
 
     if (buttons.previousPressed())
     {
         previousPage();
     }
 
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
    switch(runtime_.currentPage)
    {
        case DisplayPage::Acceleration:

            runtime_.currentPage = DisplayPage::Magnitude;

            break;

        case DisplayPage::Magnitude:

            runtime_.currentPage = DisplayPage::System;

            break;

        default:

            runtime_.currentPage = DisplayPage::Acceleration;

            break;
    }

    lcd_.clear();

    clearCache();
}
/*=============================================================================
    Previous Page
=============================================================================*/
void Display::previousPage()
{
    switch(runtime_.currentPage)
    {
        case DisplayPage::Acceleration:

            runtime_.currentPage = DisplayPage::System;

            break;

        case DisplayPage::Magnitude:

            runtime_.currentPage = DisplayPage::Acceleration;

            break;

        default:

            runtime_.currentPage = DisplayPage::Magnitude;

            break;
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
    if (page == runtime_.currentPage)
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
    for (uint8_t row = 0; row < kLcdRows; row++)
    {
        memset(cache_.line[row], ' ', kLcdColumns);

        cache_.line[row][kLcdColumns] = '\0';
    }
}

/*=============================================================================
    Print One LCD Line
=============================================================================*/
void Display::printLine(uint8_t row,const char* text)
{
    Serial.println("printLine");

    lcd_.setCursor(0,row);

    lcd_.print(text);
}
// void Display::printLine(
//     uint8_t row,
//     const char* text)
// {
//     if (row >= kLcdRows)
//     {
//         return;
//     }

//     char buffer[kLcdColumns + 1];

//     snprintf(
//         buffer,
//         sizeof(buffer),
//         "%-*s",
//         kLcdColumns,
//         text);

//     if (strcmp(buffer, cache_.line[row]) == 0)
//     {
//         return;
//     }

//     strcpy(cache_.line[row], buffer);

//     lcd_.setCursor(0, row);

//     lcd_.print(buffer);
// }

/*=============================================================================
    Print Float Value
=============================================================================*/

void Display::printValue(
    uint8_t row,
    const char* label,
    float value,
    uint8_t precision)
{
    char number[12];

    dtostrf(value,0,precision,number);

    char text[kLcdColumns + 1];

    snprintf(
        text,
        sizeof(text),
        "%s:%s",
        label,
        number);

    printLine(row,text);
}

/*=============================================================================
    Print Text Status
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

    printLine(row, text);
}
/*=============================================================================
    Page : Acceleration
=============================================================================*/
// void Display::pageAcceleration(const Model& model)
// {
//     lcd_.clear();

//     lcd_.setCursor(0,0);
//     lcd_.print("HELLO");

//     delay(1000);
// }
void Display::pageAcceleration(const Model& model)
{
    Serial.println("Page Acc");
    printLine(0,"AX");
    printLine(1,"AY");
    printLine(2,"AZ");
    //printLine(3,"TEST");
    const MeasurementFrame& m = model.measurement();

    printValue(0, "AX", m.filtered.x);
    printValue(1, "AY", m.filtered.y);
    printValue(2, "AZ", m.filtered.z);

    char text[kLcdColumns + 1];

    snprintf(
        text,
        sizeof(text),
        "Page:%u",
        static_cast<uint8_t>(runtime_.currentPage) + 1U);

    printLine(3, text);
}

/*=============================================================================
    Page : Magnitude
=============================================================================*/

void Display::pageMagnitude(const Model& model)
{
    const MeasurementFrame& m = model.measurement();

    printValue(0, "MAG", m.magnitude);

    printValue(1, "RMS", model.statistics().rms);

    printValue(2, "PEAK", model.statistics().peak);

    char text[kLcdColumns + 1];

    snprintf(
        text,
        sizeof(text),
        "Page:%u",
        static_cast<uint8_t>(runtime_.currentPage) + 1U);

    printLine(3, text);
}
