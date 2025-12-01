#ifndef EINK_H
#define EINK_H

#include <Arduino.h>

#include <SPI.h>
#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h> //eink libraries
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
// extern GxEPD2_BW<GxEPD2_420, GxEPD2_420::HEIGHT> display;

namespace eink
{
    void begin();
    void test();
};

#endif