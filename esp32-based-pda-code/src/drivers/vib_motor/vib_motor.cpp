#include "drivers/vib_motor/vib_motor.h"

namespace vib_motor
{
    const int pin = 21;
    void begin()
    {
        pinMode(vib_motor::pin, OUTPUT);
        digitalWrite(vib_motor::pin, LOW);
    }
};