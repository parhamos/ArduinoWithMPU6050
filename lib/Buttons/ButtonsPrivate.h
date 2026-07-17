/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Buttons
 * File       : ButtonsPrivate.h
 *
 ******************************************************************************/

 #ifndef BUTTONS_PRIVATE_H
 #define BUTTONS_PRIVATE_H
 
 #include <Arduino.h>
 
 struct ButtonRuntime
 {
     bool state;
 
     bool previous;
 
     bool pressed;
 
     uint32_t timer;
 };
 
 #endif