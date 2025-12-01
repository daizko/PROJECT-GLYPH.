#include "drivers/leds/leds.h"

namespace leds
{
    const int led1 = 1; // case led
    const int led2 = 6; // error led

    static bool ledState1 = false;
    static bool ledState2 = false;

    static unsigned long int currentMillis1 = 0;
    static unsigned long int currentMillis2 = 0;

    static bool active1 = false;
    static bool active2 = false;

    static int remaining_blinks1 = 0;
    static int remaining_blinks2 = 0;

    static int length1 = 500; // Initialize with default
    static int length2 = 500; // Initialize with default (FIXED typo)

    void begin()
    {
        pinMode(led1, OUTPUT);
        pinMode(led2, OUTPUT);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        currentMillis1 = 0;
        currentMillis2 = 0;
    }

    void start_blink_led1(int blink_length, int times)
    {
        if (times <= 0)
            return;

        length1 = blink_length; // Store the parameter in class variable
        remaining_blinks1 = times * 2;
        ledState1 = false;
        digitalWrite(led1, LOW);
        currentMillis1 = millis();
        active1 = true;
    }

    void start_blink_led2(int blink_length, int times)
    {
        if (times <= 0)
            return;

        length2 = blink_length; // Store the parameter in class variable
        remaining_blinks2 = times * 2;
        ledState2 = false;
        digitalWrite(led2, LOW);
        currentMillis2 = millis();
        active2 = true;
    }

    void led1_blink()
    {
        if (!active1)
            return;

        if (remaining_blinks1 <= 0)
        {
            active1 = false;
            digitalWrite(led1, LOW);
            return;
        }

        if (millis() - currentMillis1 >= length1)
        {
            ledState1 = !ledState1;
            digitalWrite(led1, ledState1 ? HIGH : LOW);
            currentMillis1 = millis();
            remaining_blinks1--;
        }
    }

    void led2_blink()
    {
        if (!active2)
            return;

        if (remaining_blinks2 <= 0)
        {
            active2 = false;
            digitalWrite(led2, LOW);
            return;
        }

        if (millis() - currentMillis2 >= length2) // FIXED: was length1
        {
            ledState2 = !ledState2;
            digitalWrite(led2, ledState2 ? HIGH : LOW);
            currentMillis2 = millis();
            remaining_blinks2--;
        }
    }
};