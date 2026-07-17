/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Buttons
 * File       : Buttons.cpp
 *
 * Version    : 1.0.0
 *
 ******************************************************************************/

 #include "Buttons.h"

 #include "ButtonsConfig.h"
 
 /*=============================================================================
     Global Instance
 =============================================================================*/
 
 Buttons buttons;
 
 /*=============================================================================
     Constructor
 =============================================================================*/
 
 Buttons::Buttons()
 {
 }
 
 /*=============================================================================
     Initialization
 =============================================================================*/
 
 bool Buttons::begin()
 {
     pinMode(kButtonNextPin, INPUT_PULLUP);
 
     pinMode(kButtonPreviousPin, INPUT_PULLUP);
 
     pinMode(kButtonOkPin, INPUT_PULLUP);
 
     next_.state = false;
     next_.previous = false;
     next_.pressed = false;
     next_.timer = 0U;
 
     previous_.state = false;
     previous_.previous = false;
     previous_.pressed = false;
     previous_.timer = 0U;
 
     ok_.state = false;
     ok_.previous = false;
     ok_.pressed = false;
     ok_.timer = 0U;
     pinMode(kButtonNextPin, INPUT_PULLUP);
    pinMode(kButtonPreviousPin, INPUT_PULLUP);
    pinMode(kButtonOkPin, INPUT_PULLUP);
 
     return true;
 }
 
 /*=============================================================================
     Update
 =============================================================================*/
 
 bool Buttons::update()
 {
     updateButton(next_, kButtonNextPin);
 
     updateButton(previous_, kButtonPreviousPin);
 
     updateButton(ok_, kButtonOkPin);
 
     return true;
 }
 /*=============================================================================
     Button Update
 =============================================================================*/
 
 void Buttons::updateButton(
     ButtonRuntime& button,
     uint8_t pin)
 {
     bool level =
         (digitalRead(pin) == kButtonActiveLevel);
 
     /*
         State changed
     */
 
     if (level != button.previous)
     {
         button.timer = millis();
 
         button.previous = level;
     }
 
     /*
         Debounce
     */
 
     if ((millis() - button.timer) >= kDebounceTime)
     {
         /*
             Rising edge
         */
 
         if ((level == true) &&
             (button.state == false))
         {
             button.pressed = true;
         }
 
         button.state = level;
     }
 }
 
 /*=============================================================================
     Next Button Event
 =============================================================================*/
 
 bool Buttons::nextPressed()
 {
     if(next_.pressed)
     {
         next_.pressed = false;
         return true;
     }
 
     return false;
 }
 
 /*=============================================================================
     Previous Button Event
 =============================================================================*/
 
 bool Buttons::previousPressed()
 {
     if(previous_.pressed)
     {
         previous_.pressed = false;
         return true;
     }
 
     return false;
 }
 
 /*=============================================================================
     OK Button Event
 =============================================================================*/
 
 bool Buttons::okPressed()
 {
     if(ok_.pressed)
     {
         ok_.pressed = false;
         return true;
     }
 
     return false;
 }