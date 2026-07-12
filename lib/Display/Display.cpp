#include "Display.h"
#include "DisplayPrivate.h"
#include "DisplayConfig.h"
#include "Config.h"

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLS, LCD_ROWS);

Display display;

bool Display::begin()
{
    lcd.init();
    lcd.backlight();

    return true;
}

void Display::splash()
{
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print(PROJECT_NAME);

    lcd.setCursor(0,1);
    lcd.print("Version ");
    lcd.print(PROJECT_VERSION);
}

void Display::update()
{

}

void Display::showError(const char* message)
{
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print(message);
}