#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MCP23X17.h>
using MCP23017 = Adafruit_MCP23X17;
namespace gpioexpander
{

    struct gpio_expander
    {
        uint8_t address; // Fixed spelling
        int INTA;
        int INTB;
        int RESPIN;
    };

    struct buttons
    {
        int rowA1, rowA2, rowA3, rowA4;
        int columnA1, columnA2, columnA3, columnA4;
        int rowB1, rowB2, rowB3, rowB4;
        int columnB1, columnB2, columnB3, columnB4;
    };

    // Declare extern variables
    extern gpio_expander gpio_exp_1;
    extern gpio_expander gpio_exp_2;
    extern MCP23017 mcp1;
    extern MCP23017 mcp2;
    extern buttons expander1;
    extern buttons expander2;

    void settingPins();
    void begin();
}