/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Display
 * File       : DisplayPrivate.h
 *
 * Version    : 1.0.0
 *
 * Description:
 *      Private objects for Display module.
 *
 ******************************************************************************/

 #ifndef DISPLAY_PRIVATE_H
 #define DISPLAY_PRIVATE_H
 
 #include <Arduino.h>
 
 #include "DisplayConfig.h"
 
 /*=============================================================================
     LCD Cache
 =============================================================================*/
 
 struct DisplayCache
 {
     char line[4][kLcdColumns + 1];
 };
 
 /*=============================================================================
     Display Runtime
 =============================================================================*/
 
 struct DisplayRuntime
 {
 
     bool initialized;
 
     uint32_t refreshCounter;
 };
 
 #endif // DISPLAY_PRIVATE_H