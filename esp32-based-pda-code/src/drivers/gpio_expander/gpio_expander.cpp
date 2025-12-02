#include "drivers/gpio_expander/gpio_expander.h"

namespace gpioexpander
{

    gpio_expander gpio_exp_1 = {0x40 >> 1, 15, 16, 40}; // i need to shift to 7bit bc manufacter uses 8bit (uint8_t adress; int INTA; int INTB; int RESPIN);
    gpio_expander gpio_exp_2 = {0x41 >> 1, 17, 18, 41}; // not sure about what adress does changing a0 to high make

    MCP23017 mcp1;
    MCP23017 mcp2;

    buttons expander1 = {
        0, 1, 2, 3,    // rowA1-4: pins 0-3
        4, 5, 6, 7,    // columnA1-4: pins 4-7
        8, 9, 10, 11,  // rowB1-4: pins 8-11
        12, 13, 14, 15 // columnB1-4: pins 12-15
    };

    buttons expander2 = {
        0, 1, 2, 3,     // rowA1-4: pins 0-3
        4, 5, 6, 7,     // columnA1-4: pins 4-7
        8, 9, 10, 255,  // rowB1-3: pins 8-10, rowB4: 255 = not used
        12, 13, 14, 255 // columnB1-3: pins 12-14, columnB4: 255 = not used
    };

    void settingPins()
    {
        mcp1.pinMode(expander1.rowA1, INPUT);
        mcp1.pinMode(expander1.rowA2, INPUT);
        mcp1.pinMode(expander1.rowA3, INPUT);
        mcp1.pinMode(expander1.rowA4, INPUT);
        mcp1.pinMode(expander1.columnA1, OUTPUT);
        mcp1.pinMode(expander1.columnA2, OUTPUT);
        mcp1.pinMode(expander1.columnA3, OUTPUT);
        mcp1.pinMode(expander1.columnA4, OUTPUT);

        mcp1.pinMode(expander1.rowB1, INPUT);
        mcp1.pinMode(expander1.rowB2, INPUT);
        mcp1.pinMode(expander1.rowB3, INPUT);
        mcp1.pinMode(expander1.rowB4, INPUT);
        mcp1.pinMode(expander1.columnB1, OUTPUT);
        mcp1.pinMode(expander1.columnB2, OUTPUT);
        mcp1.pinMode(expander1.columnB3, OUTPUT);
        mcp1.pinMode(expander1.columnB4, OUTPUT);

        mcp2.pinMode(expander2.rowA1, INPUT);
        mcp2.pinMode(expander2.rowA2, INPUT);
        mcp2.pinMode(expander2.rowA3, INPUT);
        mcp2.pinMode(expander2.rowA4, INPUT);
        mcp2.pinMode(expander2.columnA1, OUTPUT);
        mcp2.pinMode(expander2.columnA2, OUTPUT);
        mcp2.pinMode(expander2.columnA3, OUTPUT);
        mcp2.pinMode(expander2.columnA4, OUTPUT);

        mcp2.pinMode(expander2.rowB1, INPUT);
        mcp2.pinMode(expander2.rowB2, INPUT);
        mcp2.pinMode(expander2.rowB3, INPUT);
        // left out 4 i dont use
        mcp2.pinMode(expander2.columnB1, OUTPUT);
        mcp2.pinMode(expander2.columnB2, OUTPUT);
        mcp2.pinMode(expander2.columnB3, OUTPUT);
        // left out 4 i dont use
    }

    void begin()
    {
        // Initialize I2C first
        Wire.begin();

        // Initialize mcp1 WITH address
        if (!mcp1.begin_I2C(gpio_exp_1.address))
        {
            Serial.println("Error initializing MCP23017 #1.");
            while (1)
                ;
        }

        // Configure pins AFTER initialization
        settingPins();

        // Initialize mcp2 WITH address
        if (!mcp2.begin_I2C(gpio_exp_2.address))
        {
            Serial.println("Error initializing MCP23017 #2.");
            while (1)
                ;
        }
    }
};