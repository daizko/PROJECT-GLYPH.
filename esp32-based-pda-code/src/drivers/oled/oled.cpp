#include "drivers/oled/oled.h"

namespace oled
{
    const int SDA_PIN = 8;
    const int SCL_PIN = 9;
    const int SCREEN_HEIGHT = 32;
    const int SCREEN_WIDTH = 128;
    Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);
    void begin()
    {

        Wire.begin(SDA_PIN, SCL_PIN); // i2c inicialisation
        if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
        {
            Serial.println(F("SSD1306 allocation failed"));
            for (;;)
                ;
        }
        display.setTextColor(SSD1306_WHITE);
        display.setTextSize(1);
        display.clearDisplay(); // clear garbage RAM
        display.display();      // pushes buffer
    };
    void test()
    {
        display.setCursor(0, 0);
        display.println("OLED Works");
        display.display();
    }
}