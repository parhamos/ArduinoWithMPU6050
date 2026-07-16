/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Display
 * File       : Display.cpp
 *
 * Version    : 1.0.0
 *
 * Description:
 *      LCD display management module.
 *
 ******************************************************************************/

#include "Display.h"
#include "DisplayConfig.h"
#include "Config.h"

#include <LiquidCrystal_I2C.h>

/*=============================================================================
    Private Objects
=============================================================================*/

LiquidCrystal_I2C lcd(
    LCD_ADDRESS,
    LCD_COLS,
    LCD_ROWS);

/*=============================================================================
    Global Instance
=============================================================================*/

Display display;

/*=============================================================================
    Constructor
=============================================================================*/

Display::Display()
{
}

/*=============================================================================
    Initialization
=============================================================================*/

bool Display::begin()
{
    lcd.init();
    lcd.backlight();

    return true;
}

/*=============================================================================
    Splash Screen
=============================================================================*/

void Display::splash()
{
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print(PROJECT_NAME);

    lcd.setCursor(0, 1);
    lcd.print("Version ");
    lcd.print(PROJECT_VERSION);
}

/*=============================================================================
    Update Display
=============================================================================*/

bool Display::update(Model& model)
{
    (void)model;

    /*
        Display pages will be implemented
        in the next development phase.
    */

    return true;
}

/*=============================================================================
    Show Error
=============================================================================*/

void Display::showError(const char* message)
{
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print(message);
}