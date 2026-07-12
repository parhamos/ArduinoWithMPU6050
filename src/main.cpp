#include <Arduino.h>

#include "Config.h"

#include "Display.h"
#include "Sensor.h"

void setup()
{
    Serial.begin(SERIAL_BAUD);

    display.begin();
    display.splash();

    delay(1500);

    if(sensor.begin())
    {
        display.showError("Sensor OK");
    }
    else
    {
        display.showError("Sensor ERROR");

        while(true);
    }
}

void loop()
{
    sensor.update();

    Serial.print("AX=");
    Serial.print(sensor.ax(),3);

    Serial.print(" AY=");
    Serial.print(sensor.ay(),3);

    Serial.print(" AZ=");
    Serial.println(sensor.az(),3);

    delay(100);
}