#include "drivers/eink/eink.h"

struct Eink_Display
{
    int CS_PIN;
    int BUSY_PIN;
    int RES_PIN;
    int DC_PIN;
    int CLK_PIN;
    int MOSI_PIN;

    Eink_Display() : CS_PIN(10),
                     BUSY_PIN(14),
                     RES_PIN(46),
                     DC_PIN(13),
                     CLK_PIN(12),
                     MOSI_PIN(11)
    {
    }
};

Eink_Display eInk;

SPIClass *hspi = NULL;

// 4.2'' EPD Module
GxEPD2_BW<GxEPD2_420_GDEY042T81, GxEPD2_420_GDEY042T81::HEIGHT> display(GxEPD2_420_GDEY042T81(/*CS=5*/ eInk.CS_PIN, /*DC=*/eInk.DC_PIN, /*RES=*/eInk.RES_PIN, /*BUSY=*/eInk.BUSY_PIN)); // 400x300, SSD1683

namespace eink
{
    void begin()
    {
        hspi = new SPIClass(HSPI);

        hspi->begin(eInk.CLK_PIN, -1, eInk.MOSI_PIN, eInk.CS_PIN);
        display.epd2.selectSPI(*hspi, SPISettings(4000000, MSBFIRST, SPI_MODE0));
        display.init(115200, true, 50, false);
        pinMode(hspi->pinSS(), OUTPUT); // HSPI SS
        digitalWrite(hspi->pinSS(), HIGH);

        display.setRotation(0);              // 1 - probably landscape
        display.setFont(&FreeMonoBold9pt7b); // default font size
        display.setTextColor(GxEPD_BLACK);   // display parametres
    }
    void test()
{
    display.setFullWindow();
    display.firstPage();
    do
    {
        display.fillScreen(GxEPD_WHITE);  // Clear to white
        display.setCursor(0, 30);         // Set cursor position
        display.println("EINK Works");    // Draw text
    } while (display.nextPage());         // This updates everything at once
    
    // No need for display.display() - nextPage() already handles it
}
};