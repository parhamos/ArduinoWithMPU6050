/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Display
 * File       : DisplayPrivate.h
 *
 * Version    : 2.0.0
 *
 * Description:
 *      Private runtime objects for Display module.
 *
 ******************************************************************************/

 #ifndef DISPLAY_PRIVATE_H
 #define DISPLAY_PRIVATE_H
 
 #include <Arduino.h>
 
 #include "DisplayConfig.h"
 #include "ModelTypes.h"
 /*=============================================================================
     Display Runtime
 =============================================================================*/
 
 struct DisplayRuntime
 {
     bool initialized;
 
     bool autoPageEnabled;
 
     DisplayPage currentPage;
 
     uint32_t lastRefresh;
 
     uint32_t lastPageChange;
 };
 
 /*=============================================================================
     LCD Cache
 =============================================================================*/
 
 struct DisplayCache
 {
     char line1[kLcdColumns + 1];
 
     char line2[kLcdColumns + 1];
 };
 
 #endif // DISPLAY_PRIVATE_H