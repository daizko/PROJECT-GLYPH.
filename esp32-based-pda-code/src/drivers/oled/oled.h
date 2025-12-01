#ifndef OLED_H
#define OLED_H

#include <Arduino.h>

#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h> //OLED libraries
#include <Adafruit_I2CDevice.h>
#include <Wire.h>

namespace oled
{
    extern const int SDA_PIN;
    extern const int SCL_PIN;
    extern const int SCREEN_HEIGHT;
    extern const int SCREEN_WIDTH;
    void begin();
    void test();
};
#endif