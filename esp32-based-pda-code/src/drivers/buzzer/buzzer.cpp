#include "drivers/buzzer/buzzer.h"

namespace buzzer
{
    extern const int pin = 7;

    void begin()
    {
        pinMode(buzzer::pin, OUTPUT);
        digitalWrite(buzzer::pin, LOW);
    }
};