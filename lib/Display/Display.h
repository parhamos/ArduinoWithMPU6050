#include <Arduino.h>
#ifndef DISPLAY_H
#define DISPLAY_H



class Display
{
public:

    bool begin();

    void splash();

    void update();

    void showError(const char* message);

};

extern Display display;

#endif