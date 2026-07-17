/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Buttons
 * File       : Buttons.h
 *
 ******************************************************************************/

 #ifndef BUTTONS_H
 #define BUTTONS_H
 
 #include <Arduino.h>
 
 #include "ButtonsPrivate.h"
 
 class Buttons
 {
 public:
 
     Buttons();
 
     bool begin();
 
     bool update();
 
     bool nextPressed();
 
     bool previousPressed();
 
     bool okPressed();
 
 private:
 
     void updateButton(ButtonRuntime& button,
                       uint8_t pin);
      
 private:
 
     ButtonRuntime next_;
 
     ButtonRuntime previous_;
 
     ButtonRuntime ok_;
 };
 
 extern Buttons buttons;
 
 #endif